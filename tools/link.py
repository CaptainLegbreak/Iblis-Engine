#!/usr/bin/env python3
"""Link the sources into an ordinary Game.exe.

  python tools/link.py [--out DIR] [-j N] [--no-compile]

This is the second build. tools/build.py places every function at its original address and proves that the result is
byte-identical with the original. This one links the same objects as an ordinary program: the linker lays out code
and data itself, nothing is placed at an original address, and the image is relocatable.

1. compiles every unit of build/units.json with its recorded options (the compile step of tools/build.py, sharing
   its object cache) and the functional replacements in Source/StandIns/;
2. keeps one definition of every function: the verified one for the 14,916 verified functions, the replacement for
   the functions that are not reconstructed yet; other copies of a function in the objects (calling-convention
   shims, bodies that only give a call site, duplicate copies) are left out of the link;
3. connects every reference to the definition at the address it means, because the names of one function or global
   do not always agree from file to file: in verified code that address is the one the original's bytes hold there,
   elsewhere the one the source's `// 0x<address>` marker gives;
4. generates into gen/link/ (git-ignored) what no source defines yet, from your Game.exe: the data no source
   defines, the runs of globals the code treats as one object (it reaches from one into the next, so their original
   layout is kept), the PKWARE compression routines Storm links as a prebuilt library, the import libraries for the
   DLLs Game.exe imports, the export table and the resources;
5. links everything with the MSVC 2005 SP1 linker and the static C runtime (libcmt.lib) into
   <out>/ordinary/Game.exe (copied to <out>/Game.ordinary.exe), and checks the result without running it: a valid
   PE image, the same imports as the original, each an export of its DLL, the entry point the C runtime's
   WinMainCRTStartup, and every verified function and initialised global read back from the image equal to the
   original's once addresses are mapped. The findings are in <out>/ordinary/LINK_REPORT.json.

The result is not byte-identical with the original (its layout is the linker's own) and is not meant to be.
Do not run it: it is a build check. Settings come from local.json (tools/setup.py).
"""
import os, re, sys, json, glob, struct, bisect, shutil, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, CFG, GEN, settings, check_image, cl_command, compile_env, unit_env, expand_gen_includes, load_json, PE, die
import checker
from link_exe import Obj, rewrite_obj, coff_write, secaux, section_symbol, find_function, REL32, DIR32, SCN_CODE, SCN_COMDAT, SCN_REMOVE
import image_libs as L
import image_data as D

STANDINS = os.path.join(ROOT, "Source", "StandIns")
GEN_LINK = os.path.join(GEN, "link")
TEXT = (0x00401000, 0x006CB5A1)
IAT = (0x006CC000, 0x006CC614)
SCN_UNINIT = 0x80
SEL_ASSOCIATIVE = 5
SUB_VA = re.compile(r"sub_([0-9A-Fa-f]{8})(?:_|@|$)")
CRT_ENTRY = "_WinMainCRTStartup"
IMAGE = (0x00401000, 0x00995000)
COMPILER_PREFIXES = ("$", "__ehhandler$", "__sehtable$", "__unwindfunclet$", "__catch$", "__ehfuncinfo$", "__tryblocktable$",
                     "__unwindtable$", "__catchsym$", "__catchtable$", "__CT", "__TI", "__CTA", "__real@", "__xmm@", "??_C@")


def opt(args, name, default=None):
    return args[args.index(name) + 1] if name in args else default


def put(path, data):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "wb" if isinstance(data, bytes) else "w") as f:
        f.write(data)


def is_code(s):
    return bool(s["ch"] & SCN_CODE)


def is_debug(s):
    return s["name"].startswith(".debug$")


class Unit(object):
    """One object file with the address markers of its source."""

    def __init__(self, k, rel, objp, rank, standin=False):
        self.k = k; self.rel = rel; self.path = objp; self.rank = rank; self.standin = standin
        self.data = open(objp, "rb").read(); self.o = Obj(self.data)
        self.raw = open(os.path.join(ROOT, rel), encoding="latin-1").read()
        self.defs, self.decls, self.symbols = checker.parse_markers(expand_gen_includes(self.raw, rel))
        self.addr = {}
        for y in self.o.syms:
            if y["name"].startswith(".") and y["cls"] == 3 or y["name"].startswith(COMPILER_PREFIXES):
                continue                     # sections, exception-handling tables and handlers carry no address
            a, _ = checker.resolve(y["name"], self.defs, self.decls, self.symbols)
            if a is checker.AMBIGUOUS:
                a = None
            if a is None:
                m = SUB_VA.search(checker.undec(y["name"]))
                a = int(m.group(1), 16) if m else None
                if a is not None and not IMAGE[0] <= a < IMAGE[1]:
                    a = None
            if a is not None:
                self.addr[y["idx"]] = a
        self.assoc = {}
        for i, s in enumerate(self.o.secs):
            y = section_symbol(self.o, i + 1)
            if y is not None and s["ch"] & SCN_COMDAT:
                p = self.o.symptr + 18 * (y["idx"] + 1)
                num, sel = struct.unpack_from("<H", self.data, p + 12)[0], self.data[p + 14]
                if sel == SEL_ASSOCIATIVE:
                    self.assoc[i + 1] = num

    def sec(self, scn):
        return self.o.secs[scn - 1]


class Link(object):
    def __init__(self, s, out, log=print):
        self.s = s; self.out = out; self.log = log
        self.pe = PE(s["image"]); self.problems = collections.Counter(); self.examples = collections.defaultdict(list)
        self.records = sorted((int(r[0], 16), int(r[1]), r[2]) for r in load_json("functions.json")["functions"])
        self.rec_at = {va: (n, kind) for va, n, kind in self.records}
        self.rec_starts = [va for va, _, _ in self.records]
        self.base_relocs = D.base_relocations(self.pe)

    def note(self, kind, what=None):
        self.problems[kind] += 1
        if what is not None and len(self.examples[kind]) < 12:
            self.examples[kind].append(what)

    # ---- inputs -------------------------------------------------------------------------------------------------
    def load(self, drop, standin_objs):
        res = json.load(open(os.path.join(drop, "results.json")))["units"]
        self.units = []
        for u in res:
            self.units.append(Unit(len(self.units), u["file"], os.path.join(drop, u["obj"]), u.get("rank", 0)))
        for rel, objp in standin_objs:
            self.units.append(Unit(len(self.units), rel, objp, 0, standin=True))
        self.log("loaded %d objects (%d functional replacements)" % (len(self.units), len(standin_objs)))

    def libcmt_names(self):
        names = set()
        data = open(os.path.join(self.s["crt_lib"], "libcmt.lib"), "rb").read()
        for idx, name, at, body in L.ar_members(data):
            if body[:4] == L.IMPORT_SIG or len(body) < 20 or struct.unpack_from("<H", body, 0)[0] != 0x14C:
                continue
            for y in checker.Coff(body).syms:
                if y["cls"] == 2 and y["scn"] > 0:
                    names.add(y["name"])
        self.lib_names = names
        # where each runtime library function sits in the original (the same placement the byte-exact build uses)
        import link_exe
        plan = link_exe.Plan(self.pe, None, log=lambda *x: None, crt_lib=os.path.join(self.s["crt_lib"], "libcmt.lib"))
        self.crt_at = {}
        for c in plan.crt["placements"]:
            key = (c["sec"].get("key") or {}).get("name")
            for nm, v in sorted(c["sec"]["defs"], key=lambda d: d[0] != key):
                self.crt_at.setdefault(c["va"] + v, nm)

    # ---- one definition per address ----------------------------------------------------------------------------
    def choose_functions(self):
        """home[va] = (unit, section, symbol index) of the one definition of every function."""
        self.home = {}
        res_equal = collections.defaultdict(list)
        results = json.load(open(os.path.join(self.drop, "results.json")))["units"]
        for u, r in zip(self.units, results):
            for f in r["functions"]:
                if f.get("equal"):
                    res_equal[int(f["va"], 16)].append(u)
        for va, n, kind in self.records:
            if kind != "verified":
                continue
            got = None
            for u in sorted(res_equal.get(va, []), key=lambda u: u.rank != 0):
                y = find_function(u.o, u.raw, va, n)
                if y:
                    got = (u, y["scn"], y["idx"]); break
            if not got:
                self.note("verified_without_definition", "0x%08X" % va); continue
            self.home[va] = got
        for u in self.units:
            if not u.standin:
                continue
            for y in u.o.funcs():
                a = u.addr.get(y["idx"])
                if a is not None and self.rec_at.get(a, (0, ""))[1] == "unmatched" and y["value"] == 0:
                    if a in self.home:
                        self.note("replacement_twice", "0x%08X" % a)
                    self.home[a] = (u, y["scn"], y["idx"])
        missing = [va for va, n, kind in self.records if kind == "unmatched" and va not in self.home]
        for va in missing:
            self.note("unmatched_without_replacement", "0x%08X" % va)
        self.home_sec = {(u.k, scn): va for va, (u, scn, i) in self.home.items()}
        self.log("functions: %d verified, %d replacements" % (sum(1 for va in self.home if self.rec_at[va][1] == "verified"),
                                                            sum(1 for va in self.home if self.rec_at[va][1] == "unmatched")))

    def choose_data(self):
        """dhome[va] = (unit, symbol index) of the one definition of every global the sources define."""
        plan = load_json("data_plan.json")
        owner = {}; plan_size = {}
        for d in plan["definitions"]:
            if d.get("va") is not None or d.get("address") is not None:
                pass
        for d in plan["definitions"]:
            m = re.search(r"_([0-9A-F]{8})$", d.get("name") or "")
            if m:
                owner.setdefault(int(m.group(1), 16), d["file"])
                if d.get("model") and d["model"].get("size"):
                    plan_size[int(m.group(1), 16)] = d["model"]["size"]
        cands = collections.defaultdict(list)
        for u in self.units:
            for y in u.o.syms:
                a = u.addr.get(y["idx"])
                if a is None or TEXT[0] <= a < TEXT[1] or y["cls"] not in (2, 3):
                    continue
                if y["scn"] > 0:
                    s = u.sec(y["scn"])
                    if is_code(s) or is_debug(s) or s["name"] == ".drectve":
                        continue
                elif not (y["scn"] == 0 and y["cls"] == 2 and y["value"] > 0):
                    continue
                cands[a].append((u, y))
        def size_of(u, y, a):
            if y["scn"] == 0:
                return y["value"]
            size = struct.unpack_from("<I", u.data, 20 + 40 * (y["scn"] - 1) + 16)[0]
            nxt = [z["value"] for z in u.o.syms if z["scn"] == y["scn"] and z["value"] > y["value"]]
            n = (min(nxt) if nxt else size) - y["value"]
            if a in plan_size and u.rel == owner.get(a):
                return min(plan_size[a], n)
            return n
        self.dhome = {}
        def zero_in_source(u, y):
            return y["scn"] == 0 or bool(u.sec(y["scn"])["ch"] & SCN_UNINIT)
        for a in list(cands):
            cs = []
            for u, y in cands[a]:
                v = D.vread(self.pe, a, max(1, min(4, size_of(u, y, a)))) if zero_in_source(u, y) else None
                if v is not None and any(v):
                    # uninitialised in the source but not in the original: its value comes from your Game.exe
                    self.note("uninitialised_global_with_original_value", "0x%08X" % a); continue
                cs.append((u, y))
            if cs:
                cands[a] = cs
            else:
                del cands[a]
        for a, cs in cands.items():
            # the widest definition, so that every file's view of the global fits in it
            cs.sort(key=lambda c: (-size_of(c[0], c[1], a), c[0].rel != owner.get(a), c[0].rank != 0, c[0].k))
            u, y = cs[0]
            self.dhome[a] = (u, y["idx"])
            if len({c[0].k for c in cs}) > 1:
                self.note("data_defined_twice", "0x%08X" % a)
        # extents: the plan's size, else up to the next symbol of the section
        self.dext = {}
        for a, (u, i) in self.dhome.items():
            y = u.o.by_idx[i]
            self.dext[a] = max(size_of(u, y, a), 1)
        st = sorted(self.dext)
        for j, a in enumerate(st[:-1]):
            if a + self.dext[a] > st[j + 1]:
                self.dext[a] = st[j + 1] - a
        self.dstarts = st
        self.log("data: %d globals defined by the sources" % len(self.dhome))

    # ---- addresses ----------------------------------------------------------------------------------------------
    def record_of(self, va):
        i = bisect.bisect_right(self.rec_starts, va) - 1
        if i >= 0 and va < self.records[i][0] + self.records[i][1]:
            return self.records[i]
        return None

    def data_of(self, va):
        i = bisect.bisect_right(self.dstarts, va) - 1
        if i >= 0 and va < self.dstarts[i] + self.dext[self.dstarts[i]]:
            return self.dstarts[i]
        return None

    def target_of(self, u, scn, r, sec_va):
        """The address the original's bytes give a relocation's symbol, for a section known at sec_va."""
        body = u.sec(scn)["raw"]; off = r["offset"]
        if off + 4 > len(body):
            return None
        a = struct.unpack_from("<I", body, off)[0]
        orig = D.vread(self.pe, sec_va + off, 4) if not TEXT[0] <= sec_va < TEXT[1] else self.pe.read(sec_va + off, 4)
        if orig is None:
            return None
        ov = struct.unpack_from("<I", orig)[0]
        if r["ty"] == REL32:
            return (sec_va + off + 4 + ov - a) & 0xFFFFFFFF
        if r["ty"] == DIR32:
            return (ov - a) & 0xFFFFFFFF
        return None

    # ---- names --------------------------------------------------------------------------------------------------
    def plan_names(self):
        """Final names of every definition: a home keeps its own name where that is unique, other copies are private."""
        self.rename = collections.defaultdict(dict)   # k -> idx -> new name (and cls 2)
        self.canon = {}                                # va -> symbol name of its one definition
        home_syms = {}
        for va, (u, scn, i) in self.home.items():
            home_syms[(u.k, i)] = va
        for va, (u, i) in self.dhome.items():
            home_syms.setdefault((u.k, i), va)
        count = collections.Counter()
        for u in self.units:
            for y in u.o.syms:
                if y["cls"] == 2 and (y["scn"] > 0 or y["value"] > 0) and u.addr.get(y["idx"]) is None or (u.k, y["idx"]) in home_syms:
                    if y["cls"] == 2:
                        count[y["name"]] += 1
        for u in self.units:
            for y in u.o.syms:
                i = y["idx"]
                if y["cls"] not in (2, 3) or (y["scn"] <= 0 and not (y["scn"] == 0 and y["value"] > 0 and y["cls"] == 2)):
                    continue
                va = home_syms.get((u.k, i))
                if va is not None:
                    if y["cls"] == 3 or count[y["name"]] > 1 or y["name"] in self.lib_names:
                        nn = "%s$%08X" % (y["name"], va)
                        self.rename[u.k][i] = nn; self.canon[va] = nn
                        self.note("definition_renamed_to_address", nn)
                    else:
                        self.canon[va] = y["name"]
                elif y["cls"] == 2 and u.addr.get(i) is not None:
                    self.rename[u.k][i] = "%s$c%d" % (y["name"], u.k)      # a copy of a function or global defined elsewhere
                elif y["cls"] == 2 and y["scn"] > 0 and count[y["name"]] > 1 and not (u.sec(y["scn"])["ch"] & SCN_COMDAT):
                    self.rename[u.k][i] = "%s$c%d" % (y["name"], u.k)
                    self.note("unaddressed_definition_private", y["name"])
                elif y["cls"] == 2 and y["scn"] > 0 and y["name"] in self.lib_names and not (u.sec(y["scn"])["ch"] & SCN_COMDAT):
                    self.rename[u.k][i] = "%s$c%d" % (y["name"], u.k)
                    self.note("library_name_private", y["name"])

    def final_name(self, u, y):
        return self.rename[u.k].get(y["idx"], y["name"])

    # ---- binding ------------------------------------------------------------------------------------------------
    def setup_imports(self):
        self.thunks = {}
        for run in load_json("linker_pieces.json")["runs"]:
            for e in run["entries"]:
                self.thunks[int(e["va"], 16)] = int(e["iat_slot"], 16)
            for q in run.get("neighbours", []):
                q = int(q if isinstance(q, str) else q["va"], 16); b = self.pe.read(q, 6)
                if b[:2] == b"\xFF\x25":
                    self.thunks[q] = struct.unpack_from("<I", b, 2)[0]
        for va, n, kind in self.records:
            if kind == "thunk":
                b = self.pe.read(va, 6)
                if b[:2] == b"\xFF\x25":
                    self.thunks[va] = struct.unpack_from("<I", b, 2)[0]
        self.entries = L.image_imports(self.pe)
        self.slot_entry = {e["slot"]: e for e in self.entries}
        self.import_obs = collections.defaultdict(collections.Counter)

    def bind(self, S):
        """The symbol that defines address S in the ordinary link (recording labels and generated data as needed)."""
        if S in self.canon and (S in self.home or S in self.dhome):
            return self.canon[S]
        if S in self.home:
            return self.canon[S]
        if S in self.thunks:
            return ("thunk", self.thunks[S])
        if S in self.crt_at:
            return self.crt_at[S]
        if IAT[0] <= S < IAT[1]:
            return ("iat", S)
        rec = self.record_of(S)
        if TEXT[0] <= S < TEXT[1]:
            if rec and rec[2] in ("verified", "unmatched") and rec[0] in self.home:
                if rec[2] == "unmatched":
                    self.note("reference_inside_replacement", "0x%08X" % S); return None
                return self.label(S, rec[0])
            if rec and rec[2] == "pkware":
                return self.gen_label(S, "pkware")
            if self.pk_lo <= S < self.pk_hi:
                return self.gen_label(S, "pkware")
            self.note("text_address_unbound", "0x%08X %s" % (S, rec[2] if rec else "gap")); return None
        if S in self.dhome:
            return self.canon[S]
        a = self.data_of(S)
        if a is not None:
            u, i = self.dhome[a]; y = u.o.by_idx[i]
            if y["scn"] <= 0:
                self.note("reference_inside_common", "0x%08X" % S); return None
            return self.label(S, a, data=True)
        if D.vread(self.pe, S, 1) is None:
            self.note("address_outside_image", "0x%08X" % S); return None
        return self.gen_label(S, "data")

    def label(self, S, base, data=False):
        nm = "_d2va_%08X" % S
        if nm not in self.labels:
            if data:
                u, i = self.dhome[base]; y = u.o.by_idx[i]; scn, off = y["scn"], y["value"] + S - base
            else:
                u, scn, i = self.home[base]; off = S - base
            self.labels[nm] = (u.k, scn, off)
        return nm

    def gen_label(self, S, kind):
        nm = "_d2va_%08X" % S
        if nm not in self.gen_wanted:
            self.gen_wanted[nm] = (S, kind)
        return nm

    def resolve_binding(self, b):
        if isinstance(b, tuple):
            kind, slot = b
            sym = self.import_syms.get(slot)
            if sym is None:
                self.note("import_slot_unknown", "0x%08X" % slot); return None
            return sym if kind == "thunk" else "__imp_" + sym
        return b

    # ---- the plan -----------------------------------------------------------------------------------------------
    def plan(self):
        self.labels = {}; self.gen_wanted = {}; self.gen_reach_pre = {}
        pk = [(va, n) for va, n, kind in self.records if kind == "pkware"]
        self.pk_lo = min(va for va, n in pk); self.pk_hi = max(va + n for va, n in pk)
        self.keep = {}            # k -> set of kept sections
        self.retarget = {}        # k -> {(scn, n): name}
        pending = []; own = []
        # which sections take part
        for u in self.units:
            keep = set()
            fsyms = collections.defaultdict(list)
            for y in u.o.funcs():
                fsyms[y["scn"]].append(y)
            for i, s in enumerate(u.o.secs):
                scn = i + 1
                if is_debug(s) or s["name"] == ".drectve" or s["ch"] & SCN_REMOVE:
                    continue
                if is_code(s) and (u.k, scn) not in self.home_sec and any(u.addr.get(y["idx"]) is not None for y in fsyms.get(scn, ())):
                    continue                            # another copy of a function defined elsewhere
                keep.add(scn)                           # code without an address stays while something kept refers to it
            self.keep[u.k] = keep
        # data sections: where each one sits in the original, for reading pointer values
        for u in self.units:
            dva = {}
            for y in u.o.syms:
                a = u.addr.get(y["idx"])
                if a is None or y["scn"] <= 0 or a not in self.dhome or self.dhome[a][0] is not u:
                    continue
                dva.setdefault(y["scn"], []).append((y["value"], a))
            u.dva = {scn: sorted(v) for scn, v in dva.items()}
        for u in self.units:
            rt = {}
            for scn in sorted(self.keep[u.k]):
                s = u.sec(scn); home_va = self.home_sec.get((u.k, scn))
                for n, r in enumerate(u.o.relocs(scn)):
                    y = r["sym"]
                    if y["name"].startswith(".") and y["cls"] == 3:
                        continue
                    ay = u.addr.get(y["idx"])
                    defined_here = y["scn"] > 0 or (y["scn"] == 0 and y["value"] > 0)
                    if defined_here and ay is None:
                        # literals, tables and statics without an address stay this object's own, except a call
                        # the original makes to a verified function through a same-named inline copy
                        if not (home_va is not None and self.rec_at[home_va][1] == "verified" and y["scn"] > 0 and y["scn"] != scn
                                and is_code(u.sec(y["scn"])) and r["ty"] in (REL32, DIR32)):
                            continue
                        S = self.target_of(u, scn, r, home_va)
                        if S in self.home and self.rec_at[S][1] == "verified":
                            pending.append((u.k, scn, n, S))
                        continue
                    if defined_here and self.is_home(u, y, ay):
                        if not TEXT[0] <= ay < TEXT[1] and r["ty"] == DIR32:
                            own.append((u.k, scn, n, ay))         # bound again only if its global joins a block
                        continue
                    if y["scn"] == scn and home_va is not None and ay == home_va:
                        continue
                    S = None
                    if home_va is not None and self.rec_at[home_va][1] == "verified" and r["ty"] in (REL32, DIR32):
                        S = self.target_of(u, scn, r, home_va)
                        if ay is not None and S != ay:
                            self.note("marker_differs_from_bytes", "%s 0x%08X: %s marker 0x%08X bytes 0x%08X" % (u.rel, home_va, y["name"], ay, S or 0))
                    else:
                        S = ay
                        if scn in u.dva and r["ty"] == DIR32:     # a global placed in the original: its bytes decide
                            base = [p for p in u.dva[scn] if p[0] <= r["offset"]]
                            if base:
                                v, a = base[-1]
                                if r["offset"] - v < self.dext.get(a, 0):
                                    Sb = self.target_of(u, scn, r, a - v)
                                    if ay is not None and Sb != ay:
                                        self.note("marker_differs_from_bytes", "%s 0x%08X: %s marker 0x%08X bytes 0x%08X" % (u.rel, a, y["name"], ay, Sb or 0))
                                    S = Sb
                    if S is None:
                        continue                                        # bound by name (runtime library, imports)
                    if not defined_here and y["name"] in self.lib_names and S not in self.home and S not in self.dhome:
                        continue
                    if y["name"].startswith("__imp_") and IAT[0] <= S < IAT[1]:
                        self.import_obs[S][y["name"][6:]] += 1
                    elif S in self.thunks and not defined_here:
                        self.import_obs[self.thunks[S]][y["name"]] += 1
                    pending.append((u.k, scn, n, S))
            self.retarget[u.k] = rt
        self.choose_import_symbols()
        absorbed = self.cluster_data(pending, own)
        pending += [p for p in own if p[3] in absorbed]
        self.patch = collections.defaultdict(dict)    # k -> scn -> {offset: new addend}
        self.gen_reach = dict(self.gen_reach_pre); self.layout_refs = []
        for k, scn, n, S in pending:
            u = self.units[k]; r = u.o.relocs(scn)[n]; y = r["sym"]
            add = struct.unpack_from("<i", u.sec(scn)["raw"], r["offset"])[0] if r["offset"] + 4 <= len(u.sec(scn)["raw"]) else 0
            E = (S + add) & 0xFFFFFFFF
            if not TEXT[0] <= S < TEXT[1] and S in self.dhome and not 0 <= add <= self.dext[S]:
                # the original reaches past this global into what follows it there; an ordinary link does not
                # keep that layout, so this is recorded as a layout dependency of the sources
                self.layout_refs.append((u.rel, S, add))
            b = self.resolve_binding(self.bind(S))
            if b is None:
                continue
            if isinstance(b, str) and b in self.gen_wanted:
                lo_, hi_ = self.gen_reach.get(S, (S, S + 1))
                self.gen_reach[S] = (min(lo_, E), max(hi_, E + 4))
            if b == self.final_name(u, y) and not (y["scn"] > 0 and not self.is_home(u, y, u.addr.get(y["idx"]))):
                continue
            self.retarget[k][(scn, n)] = b
        self.problems["relocations_bound_by_address"] = sum(len(v) for v in self.retarget.values())
        self.drop_unreferenced_code()
        self.generate_data()

    def addend(self, k, scn, n):
        u = self.units[k]; r = u.o.relocs(scn)[n]; raw = u.sec(scn)["raw"]
        return struct.unpack_from("<i", raw, r["offset"])[0] if r["offset"] + 4 <= len(raw) else 0

    def cluster_data(self, pending, own):
        """Globals the code treats as one object keep their original layout.

        Where the original reaches from one global into its neighbours (a struct the sources split into several
        globals, an array that runs on into the next one, a table read past its declared end), those globals and
        the bytes between them become one block copied from your Game.exe, and every reference to any of them is
        bound into that block; their definitions in the sources are left unused."""
        iv = [(a, a + self.dext[a], a) for a in self.dstarts]
        for k, scn, n, S in list(pending) + list(own):
            if TEXT[0] <= S < TEXT[1] or IAT[0] <= S < IAT[1] or S in self.thunks:
                continue
            add = self.addend(k, scn, n); ext = self.dext.get(S, 1); E = S + add
            if 0 <= add < ext:
                continue
            iv.append((min(S, E), max(S + ext, E + 4), S))
        iv.sort()
        groups = []
        for lo, hi, S in iv:
            if groups and lo < groups[-1][1]:
                groups[-1][1] = max(groups[-1][1], hi); groups[-1][2].add(S)
            else:
                groups.append([lo, hi, {S}])
        init_end = {}
        for s in D.section_table(self.pe):
            lo = self.pe.image_base + s["va"]
            init_end[lo] = (lo + min(s["rawsize"], max(s["vsize"], 1)), lo + max(s["vsize"], s["rawsize"]))
        absorbed = set()
        for lo, hi, members in groups:
            homes = sorted(a for a in members if a in self.dhome)
            if not homes or (len(members) == 1 and hi == homes[0] + self.dext[homes[0]] and lo == homes[0]):
                continue
            sec = next(((a, b) for s0, (a, b) in init_end.items() if s0 <= lo < b), None)
            if sec is None or (lo < sec[0] < hi):
                self.note("data_cluster_crosses_sections", "0x%08X-0x%08X" % (lo, hi)); continue
            for a in homes:
                absorbed.add(a)
                self.gen_label(a, "data")
                self.gen_reach_pre[a] = (lo, hi)
            for S in members:
                if S not in self.dhome:
                    self.gen_reach_pre[S] = (lo, hi)
            self.problems["data_clusters"] += 1; self.problems["data_cluster_bytes"] += hi - lo
        for a in absorbed:
            del self.dhome[a]; self.canon.pop(a, None)
        self.dstarts = sorted(self.dhome)
        self.problems["globals_kept_in_original_layout"] = len(absorbed)
        return absorbed

    def is_home(self, u, y, ay):
        if ay is None:
            return False
        h = self.home.get(ay)
        if h is not None and h[0] is u and h[2] == y["idx"]:
            return True
        d = self.dhome.get(ay)
        return d is not None and d[0] is u and d[1] == y["idx"]

    def drop_unreferenced_code(self):
        """Unaddressed code (call-site context bodies, out-of-line copies) stays only while something kept calls it."""
        defs = collections.defaultdict(list)
        for u in self.units:
            for y in u.o.syms:
                if y["cls"] == 2 and y["scn"] > 0 and y["scn"] in self.keep[u.k]:
                    defs[self.final_name(u, y)].append((u.k, y["scn"]))
        for nm, (k, scn, off) in self.labels.items():
            defs[nm].append((k, scn))
        root = lambda u, scn: (not is_code(u.sec(scn)) and not u.sec(scn)["ch"] & SCN_COMDAT) or (u.k, scn) in self.home_sec
        live = set(); work = []
        for u in self.units:
            for scn in self.keep[u.k]:
                if root(u, scn) and scn not in u.assoc:
                    live.add((u.k, scn)); work.append((u.k, scn))
        children = collections.defaultdict(list)
        for u in self.units:
            for scn, parent in u.assoc.items():
                children[(u.k, parent)].append((u.k, scn))
        while work:
            k, scn = work.pop(); u = self.units[k]
            nxt = list(children.get((k, scn), ()))
            for n, r in enumerate(u.o.relocs(scn)):
                b = self.retarget[k].get((scn, n))
                y = r["sym"]
                if y["cls"] == 105 and b is None:
                    tag = struct.unpack_from("<I", u.data, u.o.symptr + 18 * (y["idx"] + 1))[0]
                    z = u.o.by_idx.get(tag)
                    if z is not None:
                        nxt += defs.get(self.final_name(u, z), []) + ([(k, z["scn"])] if z["scn"] > 0 else [])
                if b is not None:
                    nxt += defs.get(b, [])
                elif y["scn"] > 0:
                    nxt.append((k, y["scn"]))
                else:
                    nxt += defs.get(self.final_name(u, y), [])
            for t in nxt:
                if t not in live and t[1] in self.keep[t[0]]:
                    live.add(t); work.append(t)
        dropped = 0
        for u in self.units:
            for scn in list(self.keep[u.k]):
                if (u.k, scn) not in live:
                    self.keep[u.k].discard(scn); dropped += 1
        self.problems["unreferenced_sections_left_out"] = dropped
        self.live = live

    # ---- imports ------------------------------------------------------------------------------------------------
    def choose_import_symbols(self):
        sdk = sdk_import_index(self.s.get("sdk_lib"), sorted({e["dll"] for e in self.entries}))
        self.import_syms = {}; taken = set(); self.import_list = []
        for e in self.entries:
            valid = [x for x, _ in self.import_obs[e["slot"]].most_common() if L.import_name_type(x, e) is not None and x not in taken]
            sym = valid[0] if valid else None
            if sym is None and e["name"] is not None:
                sym = sdk.get((e["dll"].upper(), e["name"]))
                sym = sym if sym and sym not in taken else None
            if sym is None:
                if e["name"] is None:
                    sym = "_d2ord_%s_%d" % (re.sub(r"\W", "_", e["dll"].split(".")[0]), e["ordinal"])
                elif e["name"].startswith(("_", "?", "@")):
                    sym = e["name"]
                else:
                    sym = "_" + e["name"]
                self.note("import_symbol_undecorated", "%s!%s" % (e["dll"], e["name"] or "#%d" % e["ordinal"]))
            taken.add(sym); self.import_syms[e["slot"]] = sym
            self.import_list.append(dict(e, sym=sym, name_type=L.import_name_type(sym, e)))

    def write_import_libs(self, linker, runner):
        d = os.path.join(GEN_LINK, "imp"); os.makedirs(d, exist_ok=True)
        for f in glob.glob(os.path.join(d, "*")):
            os.remove(f)
        by_dll = collections.OrderedDict()
        for e in self.import_list:
            by_dll.setdefault(e["dll"], []).append(e)
        paths = []
        for dll, es in by_dll.items():
            base = re.sub(r"[^A-Za-z0-9_]", "_", dll)
            put(os.path.join(d, base + ".def"), L.def_text(dll, [(e["sym"], e) for e in es]))
            r = run_tool(runner, [linker, "/lib", "/NOLOGO", "/MACHINE:X86", "/DEF:%s.def" % base, "/OUT:%s.lib" % base], d)
            if r.returncode:
                die("building the import library for %s failed: %s" % (dll, (r.stdout + r.stderr)[-800:]))
            lp = os.path.join(d, base + ".lib")
            data, n = L.patch_import_lib(open(lp, "rb").read(), {e["sym"]: (e["hint"], e["name_type"]) for e in es})
            put(lp, data); paths.append(lp)
            for f in (base + ".exp",):
                if os.path.exists(os.path.join(d, f)):
                    os.remove(os.path.join(d, f))
        return paths

    # ---- data no source defines ---------------------------------------------------------------------------------
    def generate_data(self):
        """Blocks of the original image that no source defines, copied from your Game.exe with their pointers relinked.

        An object no source defines starts where something refers to it and ends where the next object starts (a
        global the sources define, another referenced address, or an address the original points to), and it is
        long enough for every offset the code uses from it; blocks that overlap are merged."""
        regions = []
        for s in D.section_table(self.pe):
            lo = self.pe.image_base + s["va"]; hi = lo + max(s["vsize"], s["rawsize"])
            init_hi = lo + min(s["rawsize"], max(s["vsize"], 1))
            regions.append((lo, init_hi, hi, s["name"]))
        cuts = set(self.dstarts) | {a + self.dext[a] for a in self.dstarts}
        for r in regions:
            cuts |= {r[0], r[1], r[2]}
        for site in self.base_relocs:
            v = D.vread(self.pe, site, 4)
            if v is not None:
                T = struct.unpack_from("<I", v)[0]
                if not TEXT[0] <= T < TEXT[1]:
                    cuts.add(T)
        while True:
            cuts_now = sorted(cuts | {S for S, k in self.gen_wanted.values()})
            iv = []
            for nm, (S, kind) in self.gen_wanted.items():
                if kind == "pkware":
                    iv.append((self.pk_lo, self.pk_hi, True, "pkware")); continue
                reg = next(r for r in regions if r[0] <= S < r[2])
                init = S < reg[1]; rlo, rhi = (reg[0], reg[1]) if init else (reg[1], reg[2])
                lo_, hi_ = self.gen_reach.get(S, (S, S + 1))
                lo = max(rlo, min(S, lo_)); hi = min(rhi, max(cuts_now[bisect.bisect_right(cuts_now, S)], hi_))
                iv.append((lo, hi, init, "data"))
            iv.sort()
            merged = []
            for lo, hi, init, kind in iv:
                if merged and lo < merged[-1]["hi"] and merged[-1]["init"] == init:
                    merged[-1]["hi"] = max(merged[-1]["hi"], hi)
                else:
                    merged.append(dict(lo=lo, hi=hi, init=init, kind=kind, relocs=[]))
            before = len(self.gen_wanted)
            for blk in merged:
                if not blk["init"]:
                    continue
                lo, hi = blk["lo"], blk["hi"]
                for site in self.base_relocs[bisect.bisect_left(self.base_relocs, lo):bisect.bisect_left(self.base_relocs, hi - 3)]:
                    T = struct.unpack_from("<I", D.vread(self.pe, site, 4))[0]
                    if lo <= T < hi:
                        blk["relocs"].append((site - lo, "_d2blk_%08X" % lo, T - lo)); continue
                    b = self.resolve_binding(self.bind(T))
                    if b is None:
                        self.note("generated_pointer_unbound", "0x%08X -> 0x%08X" % (site, T)); continue
                    blk["relocs"].append((site - lo, b, 0))
            if len(self.gen_wanted) == before:
                break
        self.blocks = {b["lo"]: b for b in merged}
        if any(b["kind"] == "pkware" for b in merged):
            self.check_pkware()
        for b in merged:
            self.problems["generated_%s_bytes" % ("pkware" if b["kind"] == "pkware" else "data" if b["init"] else "bss")] += b["hi"] - b["lo"]
        self.problems["generated_blocks"] = len(merged)

    def check_pkware(self):
        """The PKWARE routines are copied as one block: their relative calls must stay inside it."""
        body = self.pe.read(self.pk_lo, self.pk_hi - self.pk_lo)
        for va, n, kind in self.records:
            if kind != "pkware":
                continue
            o = va - self.pk_lo
            for j in range(o, o + n - 4):
                if body[j] in (0xE8, 0xE9):
                    t = (va + (j - o) + 5 + struct.unpack_from("<i", body, j + 1)[0]) & 0xFFFFFFFF
                    rec = self.record_of(t)
                    if rec and rec[2] == "pkware" and t == rec[0] and not self.pk_lo <= t < self.pk_hi:
                        self.note("pkware_call_leaves_block", "0x%08X" % (va + j - o))

    def write_generated(self):
        put(os.path.join(GEN_LINK, "README.txt"), "generated from your Game.exe by tools/link.py; do not commit\n")
        secs = []; syms = []
        for lo in sorted(self.blocks):
            b = self.blocks[lo]; n = b["hi"] - b["lo"]
            if b["kind"] == "pkware":
                name, ch = ".text", 0x60000020 | 0x00500000
            elif not b["init"]:
                name, ch = ".bss", 0xC0000080 | 0x00500000
            elif lo < 0x00705000:
                name, ch = ".rdata", 0x40000040 | 0x00500000
            else:
                name, ch = ".data", 0xC0000040 | 0x00500000
            data = b"" if not b["init"] else bytearray(D.vread(self.pe, lo, n))
            rl = []
            for off, target, add in b["relocs"]:
                struct.pack_into("<I", data, off, add)
                rl.append((off, target))
            secs.append(dict(name=name, data=bytes(data), size=n, ch=ch, rl=rl, lo=lo))
        # symbols: section symbols, block symbols, labels, then the undefined targets
        out_syms = []; idx = {}

        def add(y):
            idx[y["name"]] = sum(1 + len(z.get("aux", [])) for z in out_syms); out_syms.append(y)
        for j, s in enumerate(secs):
            add(dict(name="$blk%d" % j, value=0, scn=j + 1, cls=3, aux=[secaux(s["size"], len(s["rl"]))]))
        for j, s in enumerate(secs):
            add(dict(name="_d2blk_%08X" % s["lo"], value=0, scn=j + 1, cls=2))
        for nm, (S, kind) in sorted(self.gen_wanted.items()):
            j = next((j for j, s in enumerate(secs) if s["lo"] <= S < s["lo"] + s["size"]), None)
            if j is None:
                self.note("generated_label_outside_blocks", nm); continue
            if S != secs[j]["lo"]:
                add(dict(name=nm, value=S - secs[j]["lo"], scn=j + 1, cls=2))
            else:
                add(dict(name=nm, value=0, scn=j + 1, cls=2))
        for s in secs:
            for off, t in s["rl"]:
                if t not in idx:
                    add(dict(name=t, value=0, scn=0, cls=2))
        cs = []
        for s in secs:
            cs.append(dict(name=s["name"], data=s["data"], size=s["size"], ch=s["ch"], relocs=[(off, idx[t], DIR32) for off, t in s["rl"]]))
        p = os.path.join(GEN_LINK, "unsourced.obj"); put(p, coff_write(cs, out_syms))
        return p

    # ---- rewritten objects --------------------------------------------------------------------------------------
    def write_objects(self):
        d = os.path.join(self.out, "objs"); os.makedirs(d, exist_ok=True)
        for f in glob.glob(os.path.join(d, "*.obj")):
            os.remove(f)
        paths = []; local_abs = 0
        lab_by_k = collections.defaultdict(list)
        for nm, (k, scn, off) in self.labels.items():
            lab_by_k[k].append((nm, scn, off))
        for u in self.units:
            sc = {i: dict(name=nm, cls=2) for i, nm in self.rename[u.k].items()}
            sec_flags = {}
            for i, s in enumerate(u.o.secs):
                scn = i + 1
                if scn not in self.keep[u.k]:
                    sec_flags[scn] = (s["ch"] | SCN_REMOVE) & ~SCN_COMDAT
            for y in u.o.syms:
                if y["scn"] > 0 and y["scn"] not in self.keep[u.k] and y["cls"] == 2:
                    sc[y["idx"]] = dict(sc.get(y["idx"], {}), cls=3)      # defined only in a section left out
            names = sorted(set(self.retarget[u.k].values()))
            at = {nm: u.o.nsym + j for j, nm in enumerate(names)}
            rc = {key: at[nm] for key, nm in self.retarget[u.k].items()}
            # undefined names nothing kept refers to any more are not needed
            used = set()
            for scn in self.keep[u.k]:
                for n, r in enumerate(u.o.relocs(scn)):
                    if (scn, n) not in rc:
                        used.add(r["sym"]["idx"])
            for y in u.o.syms:
                if y["cls"] == 105 and y["idx"] in used:
                    used.add(struct.unpack_from("<I", u.data, u.o.symptr + 18 * (y["idx"] + 1))[0])
            for y in u.o.syms:
                if y["cls"] in (2, 105) and y["scn"] == 0 and y["value"] == 0 and y["idx"] not in used:
                    sc[y["idx"]] = dict(sc.get(y["idx"], {}), cls=3, scn=-1, value=0); local_abs += 1
            sec_names = {}
            for i, s in enumerate(u.o.secs):
                if s["name"] == ".drectve":
                    sec_names[i + 1] = ".d2rmdir"; sec_flags[i + 1] = (s["ch"] | SCN_REMOVE) & ~SCN_COMDAT
            sec_data = {}
            for scn, fields in self.patch.get(u.k, {}).items():
                raw = bytearray(u.sec(scn)["raw"])
                for off, v in fields.items():
                    struct.pack_into("<i", raw, off, v)
                sec_data[scn] = bytes(raw)
            p = os.path.join(d, "o%05d.obj" % u.k)
            put(p, rewrite_obj(u.data, sc, sec_flags, rc, names, sec_names, new_defs=lab_by_k.get(u.k, ()), sec_data=sec_data))
            paths.append(p)
        self.problems["unused_declarations_made_local"] = local_abs
        return paths

    def exports(self):
        ex = D.image_exports(self.pe)
        if not ex:
            return None
        internal = {}; data_names = set()
        for o, nm, va in ex["entries"]:
            b = self.resolve_binding(self.bind(va))
            if b is None:
                self.note("export_unbound", nm or "#%d" % o); continue
            internal[va] = b
            if not TEXT[0] <= va < TEXT[1]:
                data_names.add(nm)
        ents = [e for e in ex["entries"] if e[2] in internal]
        p = os.path.join(GEN_LINK, "exports.def"); put(p, D.exports_def(ex["name"], ents, internal, data_names))
        self.problems["exports"] = len(ents)
        return p

    def resources(self):
        r = D.image_resources(self.pe)
        if not r:
            return None
        data_of = lambda lf: self.pe.read(self.pe.image_base + lf["rva"], lf["size"])
        blob, fix, dat = D.rsrc_blob(r["leaves"], data_of, r["root"])
        p = os.path.join(GEN_LINK, "resources.obj"); put(p, D.rsrc_object(blob, fix, coff_write, secaux))
        self.problems["resources"] = len(r["leaves"])
        return p


def read_map(path):
    out = {}
    for ln in open(path, encoding="latin-1"):
        m = re.match(r"\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s", ln)
        if m:
            out.setdefault(m.group(1), int(m.group(2), 16))
    return out


def verify(K, exe, mapfile):
    """Every verified function and every global the sources define, read back from the linked image: each byte that
    is not an address must equal the original's, and each address must point to the counterpart of what the
    original's points to (the same function, global, import or library routine, or a constant with the same bytes)."""
    new = PE(exe); orig = K.pe; at = read_map(mapfile)
    known = {}                                       # original start -> (new start, length)
    for va, (u, scn, i) in K.home.items():
        nm = K.canon.get(va)
        if nm in at:
            known[va] = (at[nm], K.rec_at[va][0])
    for a, (u, i) in K.dhome.items():
        nm = K.canon.get(a)
        if nm in at:
            known[a] = (at[nm], K.dext[a])
    for b in K.blocks.values():
        nm = "_d2blk_%08X" % b["lo"]
        if nm in at:
            known[b["lo"]] = (at[nm], b["hi"] - b["lo"])
    for va, nm in K.crt_at.items():
        if nm in at:
            known.setdefault(va, (at[nm], 1))
    for slot, sym in K.import_syms.items():
        if "__imp_" + sym in at:
            known[slot] = (at["__imp_" + sym], 4)
    for t_, slot in K.thunks.items():
        sym = K.import_syms.get(slot)
        if sym in at:
            known[t_] = (at[sym], 6)
    starts = sorted(known)

    def f(T):
        if T in known:
            return known[T][0]
        i = bisect.bisect_right(starts, T) - 1
        if i >= 0 and T < starts[i] + known[starts[i]][1]:
            return known[starts[i]][0] + T - starts[i]
        return None

    st = collections.Counter(); bad = []

    memo = {}
    rev = {nm: va for va, nm in K.canon.items()}

    def extent(u, y):
        """Bytes of a constant of an object: up to the next symbol of its section."""
        s = u.sec(y["scn"]); nxt = [z["value"] for z in u.o.syms if z["scn"] == y["scn"] and z["value"] > y["value"]]
        return (min(nxt) if nxt else len(s["raw"])) - y["value"]

    def same(u, scn, lo, n, Vo, Vn, top, code=False):
        """The bytes [lo, lo+n) of an object section, at Vo in the original and Vn in the linked image."""
        key = (u.k, scn, lo, Vo, Vn)
        if key in memo:
            return memo[key]
        memo[key] = True
        body_o = D.vread(orig, Vo, n); body_n = D.vread(new, Vn, n)
        if body_o is None or body_n is None:
            memo[key] = False; return False
        ok = True; mask = bytearray(n)
        for k_, r in enumerate(u.o.relocs(scn)):
            o = r["offset"] - lo
            if not 0 <= o <= n - 4:
                continue
            if r["ty"] not in (REL32, DIR32):
                continue
            for j in range(4):
                mask[o + j] = 1
            ov = struct.unpack_from("<I", body_o, o)[0]; nv = struct.unpack_from("<I", body_n, o)[0]
            To = (Vo + o + 4 + ov) & 0xFFFFFFFF if r["ty"] == REL32 else ov
            Tn = (Vn + o + 4 + nv) & 0xFFFFFFFF if r["ty"] == REL32 else nv
            y = r["sym"]; add = struct.unpack_from("<i", u.sec(scn)["raw"], r["offset"])[0]
            if r["ty"] == REL32:
                add += 0
            if y["scn"] == scn and lo <= y["value"] < lo + n and code:
                good = Tn - Vn == To - Vo; st["inside"] += top
            else:
                ft = f(To)
                bound = K.retarget[u.k].get((scn, k_))
                if bound is None and y["scn"] <= 0 and y["name"] in K.lib_names:
                    ft = None
                if ft is not None and (bound is not None or y["scn"] <= 0 or u.addr.get(y["idx"]) is not None or y["cls"] == 105):
                    good = ft == Tn; st["addresses_mapped"] += top
                    S = rev.get(bound or K.final_name(u, y))
                    if not good and S in K.dhome and not 0 <= To - S <= K.dext[S] and at.get(K.canon[S], -1) + To - S == Tn:
                        good = True; st["layout_dependent"] += top
                elif y["scn"] > 0 and bound is None:   # a constant or table of this object: the same bytes, recursively
                    m = extent(u, y)
                    good = m > 0 and same(u, y["scn"], y["value"], min(m, 0x4000), To - add, Tn - add, 0); st["local_by_content"] += top
                else:                                 # bound by name: the runtime library
                    nm = bound or K.final_name(u, y)
                    good = nm in at and Tn == (at[nm] + add) & 0xFFFFFFFF; st["library_by_name"] += top
            if not good:
                ok = False
                if top and len(bad) < 30:
                    bad.append("0x%08X+0x%X -> 0x%08X (%s)" % (Vo, o, To, y["name"]))
        diff = [j for j in range(n) if not mask[j] and body_o[j] != body_n[j]]
        if diff and not code:
            # alignment padding after a global: the tail the object leaves zero, which the original fills with its neighbour
            raw = u.sec(scn)["raw"][lo:lo + n]
            used = max([j + 1 for j in range(len(raw)) if raw[j] or mask[j]] or [0])
            if min(diff) >= used and n - used < 8:
                st["padding_tails"] += top; diff = []
        if diff:
            ok = False
            if top and len(bad) < 30:
                bad.append("0x%08X: %d bytes differ" % (Vo, len(diff)))
        memo[key] = ok
        return ok

    def check(u, scn, va, n, N, code):
        lo = u.o.by_idx[u.home_sym[(scn, va)]]["value"] if not code else 0
        return same(u, scn, lo, n, va, N, 1, code)
    for va, (u, scn, i) in sorted(K.home.items(), key=lambda kv: kv[0]):
        if K.rec_at[va][1] != "verified" or va not in known:
            continue
        u.home_sym = {}
        st["functions_ok" if check(u, scn, va, K.rec_at[va][0], known[va][0], True) else "functions_bad"] += 1
    for a, (u, i) in sorted(K.dhome.items()):
        y = u.o.by_idx[i]
        if y["scn"] <= 0 or a not in known or not u.sec(y["scn"])["raw"] or a >= orig.image_base + 0x34D000:
            continue
        if not hasattr(u, "home_sym"):
            u.home_sym = {}
        u.home_sym[(y["scn"], a)] = i
        n = min(K.dext[a], len(u.sec(y["scn"])["raw"]) - y["value"])
        st["globals_ok" if check(u, y["scn"], a, n, known[a][0], False) else "globals_bad"] += 1
    return dict(st), bad


def sdk_import_index(sdk_dir, dlls):
    out = {}
    if not sdk_dir:
        return out
    files = {os.path.basename(f).lower(): f for f in glob.glob(os.path.join(sdk_dir, "*"))}
    for dll in dlls:
        f = files.get(dll.lower().rsplit(".", 1)[0] + ".lib")
        if not f:
            continue
        for idx, name, at, body in L.ar_members(open(f, "rb").read()):
            si = L.short_import(body)
            if not si or si["name_type"] == L.NAME_ORDINAL:
                continue
            for nt, fn in ((L.NAME_NAME, lambda s: s), (L.NAME_NOPREFIX, lambda s: s[1:]), (L.NAME_UNDECORATE, L.undecorate)):
                if si["name_type"] == nt:
                    out.setdefault((si["dll"].upper(), fn(si["sym"])), si["sym"])
    return out


WINE_DLLS = ("/usr/lib/wine/i386-windows", "/usr/lib/i386-linux-gnu/wine/i386-windows", "/opt/wine-stable/lib/wine/i386-windows")


def dll_exports(dlls, sdk_dir):
    """{dll: set of export names and '#ordinal's} for the DLLs an export list can be found for."""
    out = {}
    files = {os.path.basename(f).lower(): f for f in glob.glob(os.path.join(sdk_dir or "", "*"))}
    for dll in dlls:
        f = files.get(dll.rsplit(".", 1)[0] + ".lib")
        names = set()
        if f:
            for idx, name, at, body in L.ar_members(open(f, "rb").read()):
                si = L.short_import(body)
                if not si or si["dll"].lower() != dll:
                    continue
                if si["name_type"] == L.NAME_ORDINAL:
                    names.add("#%d" % si["hint"])
                elif si["name_type"] == L.NAME_NAME:
                    names.add(si["sym"])
                elif si["name_type"] == L.NAME_NOPREFIX:
                    names.add(si["sym"][1:])
                else:
                    names.add(L.undecorate(si["sym"]))
        if not names:
            w = next((os.path.join(d_, dll) for d_ in WINE_DLLS if os.path.exists(os.path.join(d_, dll))), None)
            if w:
                ex = D.image_exports(PE(w))
                if ex:
                    names = {nm for o, nm, va in ex["entries"] if nm} | {"#%d" % o for o, nm, va in ex["entries"]}
        if names:
            out[dll] = names
    return out


def run_tool(runner, cmd, cwd):
    env = dict(os.environ, WINEDEBUG="-all")
    return subprocess.run(([runner] if runner != "native" else []) + cmd, cwd=cwd, capture_output=True, text=True, env=env)


def win(p, s):
    return "Z:" + p.replace("/", "\\") if s.get("runner", "native") != "native" else p


def compile_standins(s, out):
    """Source/StandIns/*.cpp with the default options into <out>/standins."""
    od = os.path.join(out, "standins"); os.makedirs(od, exist_ok=True)
    env = compile_env(s); res = []
    for src in sorted(glob.glob(os.path.join(STANDINS, "*.cpp"))):
        rel = os.path.relpath(src, ROOT).replace("\\", "/")
        base = os.path.splitext(os.path.basename(src))[0]; obj = os.path.join(od, base + ".obj")
        wd = os.path.join(od, base + ".d"); shutil.rmtree(wd, ignore_errors=True); os.makedirs(wd)
        shutil.copy(src, os.path.join(wd, "unit.cpp"))
        r = subprocess.run(cl_command(s, CFG["flags"], "unit.obj", "unit.cpp"), capture_output=True, text=True, env=unit_env(s, env, rel), cwd=wd)
        if r.returncode or not os.path.exists(os.path.join(wd, "unit.obj")):
            die("%s does not compile:\n%s" % (rel, (r.stdout + r.stderr)[-3000:]))
        shutil.move(os.path.join(wd, "unit.obj"), obj); shutil.rmtree(wd, ignore_errors=True)
        res.append((rel, obj))
    return res


def check_image_file(path, linked_map, import_list, s, log):
    """Static checks of the linked image; it is never run."""
    pe = PE(path); d = pe.data; ok = True
    p = struct.unpack_from("<I", d, 0x3C)[0]
    machine, nsec = struct.unpack_from("<HH", d, p + 4)
    chars = struct.unpack_from("<H", d, p + 22)[0]
    magic = struct.unpack_from("<H", d, p + 24)[0]
    entry = struct.unpack_from("<I", d, p + 24 + 16)[0]
    msgs = []
    if d[:2] != b"MZ" or d[p:p + 4] != b"PE\0\0" or machine != 0x14C or magic != 0x10B:
        msgs.append("not a 32-bit x86 PE image"); ok = False
    if not chars & 0x2:
        msgs.append("not marked executable"); ok = False
    # entry point
    ent = None
    for ln in open(linked_map, encoding="latin-1"):
        m = re.match(r"\s*entry point at\s+([0-9a-fA-F]+):([0-9a-fA-F]+)", ln)
        if m:
            ent = m.group(0)
    sym_at = {}
    for ln in open(linked_map, encoding="latin-1"):
        m = re.match(r"\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s", ln)
        if m:
            sym_at.setdefault(int(m.group(2), 16), []).append(m.group(1))
    names_at_entry = sym_at.get(pe.image_base + entry, [])
    if CRT_ENTRY not in names_at_entry:
        msgs.append("entry point 0x%08X is %s, not %s" % (pe.image_base + entry, names_at_entry, CRT_ENTRY)); ok = False
    # imports: every one a real export of its DLL (the names of the original's import table)
    want = {(e["dll"].lower(), e["name"] if e["name"] is not None else "#%d" % e["ordinal"]) for e in import_list}
    got = set(); dlls = set()
    for e in L.image_imports(pe):
        got.add((e["dll"].lower(), e["name"] if e["name"] is not None else "#%d" % e["ordinal"])); dlls.add(e["dll"].lower())
    extra = sorted(got - want); missing = sorted(want - got)
    if extra:
        msgs.append("%d imports the original does not have: %s" % (len(extra), ", ".join("%s!%s" % x for x in extra[:20]))); ok = False
    # and each one a name (or ordinal) that its DLL exports: Microsoft's import libraries of the toolchain's Platform
    # SDK list the exports of the system DLLs; Wine's copies stand in for DLLs the SDK has no library for
    exported = dll_exports(sorted(dlls), s.get("sdk_lib"))
    unchecked = sorted(d_ for d_ in dlls if d_ not in exported)
    not_exported = sorted("%s!%s" % x for x in got if x[0] in exported and x[1] not in exported[x[0]])
    if not_exported:
        msgs.append("%d imports are not exports of their DLL: %s" % (len(not_exported), ", ".join(not_exported[:20]))); ok = False
    rep = dict(valid_pe=ok, imports_checked_against_dll_exports=sum(1 for x in got if x[0] in exported),
               import_dlls_without_export_list=unchecked, imports_not_exported=not_exported, sections=nsec, entry_point="0x%08X" % (pe.image_base + entry), entry_symbol=names_at_entry,
               imports=len(got), import_dlls=sorted(dlls), imports_not_in_original=["%s!%s" % x for x in extra],
               original_imports_not_used=["%s!%s" % x for x in missing], relocatable=not (chars & 0x1), problems=msgs)
    return ok, rep


def main():
    a = sys.argv[1:]
    if "-h" in a or "--help" in a:
        print(__doc__); return 0
    s = settings()
    check_image(s["image"])
    if not s.get("crt_lib"):
        die("linking needs the C runtime libraries: run `python tools/setup.py --crt`")
    out = os.path.abspath(os.path.expanduser(opt(a, "--out", os.path.join(ROOT, "out"))))
    lo = os.path.join(out, "ordinary"); os.makedirs(lo, exist_ok=True)
    if "--no-compile" not in a:
        cmd = [sys.executable, os.path.join(ROOT, "tools", "build.py"), "--compile-only", "--out", out]
        if opt(a, "-j"):
            cmd += ["-j", opt(a, "-j")]
        r = subprocess.run(cmd)
        if r.returncode:
            die("compiling the units failed")
    standins = compile_standins(s, lo)
    linker = s.get("link") or os.path.join(os.path.dirname(s["cl"]), "link.exe"); runner = s.get("runner", "wine")
    K = Link(s, lo)
    K.drop = out
    K.load(out, standins)
    K.libcmt_names()
    K.setup_imports()
    K.choose_functions()
    K.choose_data()
    K.plan_names()
    K.plan()
    objs = K.write_objects()
    gen = [K.write_generated()]
    res = K.resources()
    exp = K.exports()
    libs = K.write_import_libs(linker, runner)
    flags = ["/NOLOGO", "/NODEFAULTLIB", "/MACHINE:X86", "/SUBSYSTEM:WINDOWS,4.0", "/BASE:0x400000", "/FIXED:NO", "/INCREMENTAL:NO",
             "/OPT:NOREF", "/OPT:NOICF", "/SAFESEH:NO", "/ENTRY:" + CRT_ENTRY[1:], "/MAP:Game.map", "/OUT:Game.exe"]
    if exp:
        flags.append("/DEF:" + win(exp, s))
    rsp = flags + [win(p, s) for p in gen + ([res] if res else []) + objs] + [win(os.path.join(s["crt_lib"], "libcmt.lib"), s)] + [win(p, s) for p in libs]
    put(os.path.join(lo, "link.rsp"), "\n".join(rsp) + "\n")
    for f in ("Game.exe", "Game.map"):
        if os.path.exists(os.path.join(lo, f)):
            os.remove(os.path.join(lo, f))
    K.log("linking %d objects with link.exe ..." % len(objs)); sys.stdout.flush()
    r = run_tool(runner, [linker, "@link.rsp"], lo)
    txt = r.stdout + r.stderr; put(os.path.join(lo, "link.log"), txt)
    codes = collections.Counter(re.findall(r"\b(LNK\d{4})\b", txt))
    unresolved = sorted(set(re.findall(r"unresolved external symbol (\S+)", txt)))
    duplicates = sorted(set(re.findall(r"(\S+) already defined in", txt)))
    rep = dict(link_exit_code=r.returncode, messages=dict(codes), unresolved_externals=len(unresolved), duplicate_symbols=len(duplicates),
               unresolved=unresolved[:200], duplicates=duplicates[:200], problems=dict(K.problems), examples={k: v for k, v in K.examples.items()},
               layout_dependencies=len(K.layout_refs),
               layout_dependency_examples=["%s: 0x%08X%+d" % x for x in K.layout_refs[:60]],
               generated=["0x%08X %d %s" % (b["lo"], b["hi"] - b["lo"], b["kind"] if b["kind"] == "pkware" else "data" if b["init"] else "bss")
                          for b in sorted(K.blocks.values(), key=lambda b: b["lo"])],
               replacements=sorted("0x%08X %s" % (va, K.canon.get(va)) for va in K.home if K.rec_at[va][1] == "unmatched"))
    exe = os.path.join(lo, "Game.exe")
    if r.returncode == 0 and os.path.exists(exe):
        ok, chk = check_image_file(exe, os.path.join(lo, "Game.map"), K.import_list, s, K.log)
        rep["image"] = chk
        vs, vbad = verify(K, exe, os.path.join(lo, "Game.map"))
        rep["verify"] = dict(counts=vs, examples=vbad)
        K.log("read back: %d of %d verified functions and %d of %d initialised globals equal the original with addresses mapped"
              % (vs.get("functions_ok", 0), vs.get("functions_ok", 0) + vs.get("functions_bad", 0),
                 vs.get("globals_ok", 0), vs.get("globals_ok", 0) + vs.get("globals_bad", 0)))
        ok = ok and not vs.get("functions_bad") and not vs.get("globals_bad")
        shutil.copy(exe, os.path.join(out, "Game.ordinary.exe"))
    else:
        ok = False
    json.dump(rep, open(os.path.join(lo, "LINK_REPORT.json"), "w"), indent=1)
    K.log("link: exit %d; %d unresolved externals, %d duplicate symbols; %s" % (r.returncode, len(unresolved), len(duplicates),
          ", ".join("%s x%d" % kv for kv in sorted(codes.items())) or "no messages"))
    if r.returncode:
        K.log("\n".join(txt.splitlines()[:30]))
    if ok:
        K.log("image: valid PE, entry %s (%s), %d imports from %d DLLs, the same imports as the original, each an export of its DLL where an export list exists"
              % (chk["entry_point"], CRT_ENTRY, chk["imports"], len(chk["import_dlls"])))
        K.log("wrote %s" % os.path.join(out, "Game.ordinary.exe"))
    elif "image" in rep:
        K.log("image check failed: " + "; ".join(rep["image"]["problems"]))
    return 0 if ok and not unresolved and not duplicates else 1


if __name__ == "__main__":
    sys.exit(main())
