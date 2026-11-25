#!/usr/bin/env python3
import os, sys, re, json, glob, struct, bisect, subprocess, time, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import PE, ROOT, load_json, records, norm_va
import checker

BASE = 0x00400000
TEXT_START, TEXT_END = 0x00401000, 0x006CB5A1
ENTRY = 0x00682985
CRT_LO, CRT_HI = 0x00681A48, 0x006B00B4
TABLE_THUNK_RECORDS = (0x006C9B6A,)
SCN_CODE, SCN_COMDAT, SCN_REMOVE, SCN_ALIGN_MASK = 0x20, 0x1000, 0x800, 0x00F00000
ALIGN_1 = 0x00100000
FILL_CH = 0x60000000 | SCN_CODE | SCN_COMDAT | ALIGN_1
REL32, DIR32 = 0x14, 0x06


def _put(path, data):
    with open(path, "wb" if isinstance(data, bytes) else "w") as f:
        f.write(data)


def _get(path, binary=True):
    with open(path, "rb" if binary else "r", encoding=None if binary else "latin-1") as f:
        return f.read()


def coff_write(sections, symbols):
    strtab = bytearray(); offs = {}

    def soff(n):
        if n not in offs:
            offs[n] = 4 + len(strtab); strtab.extend(n.encode("latin-1") + b"\0")
        return offs[n]

    def nm(n):
        b = n.encode("latin-1")
        if len(b) <= 8:
            return b.ljust(8, b"\0")
        return struct.pack("<II", 0, soff(n))

    def snm(n):
        b = n.encode("latin-1")
        return b.ljust(8, b"\0") if len(b) <= 8 else ("/%d" % soff(n)).encode().ljust(8, b"\0")
    ptr = 20 + 40 * len(sections); blobs = bytearray(); sh = bytearray()
    for s in sections:
        data = s["data"]; rel = b"".join(struct.pack("<IIH", *r) for r in s.get("relocs", ()))
        dptr = ptr if data else 0; blobs += data; ptr += len(data)
        rptr = ptr if rel else 0; blobs += rel; ptr += len(rel)
        sh += snm(s["name"]) + struct.pack("<IIIIIIHHI", 0, 0, s.get("size", len(data)), dptr, rptr, 0, len(s.get("relocs", ())), 0, s["ch"])
    st = bytearray(); n = 0
    for y in symbols:
        aux = y.get("aux", [])
        st += nm(y["name"]) + struct.pack("<IhHBB", y["value"] & 0xFFFFFFFF, y["scn"], y.get("type", 0), y["cls"], len(aux))
        for a in aux:
            st += a.ljust(18, b"\0")
        n += 1 + len(aux)
    return bytes(struct.pack("<HHIIIHH", 0x14C, len(sections), 0, ptr, n, 0, 0) + sh + blobs + st + struct.pack("<I", 4 + len(strtab)) + strtab)


def secaux(length, nrel=0, sel=0):
    return struct.pack("<IHHIHB", length, nrel, 0, 0, 0, sel)


def filler_obj(name, size, extra=(), fill=0xCC, relocs=(), data=None):
    syms = [dict(name=".text", value=0, scn=1, cls=3, aux=[secaux(size, len(relocs), 2)]), dict(name=name, value=0, scn=1, type=0x20, cls=2)]
    syms += [dict(name=n, value=o, scn=1, type=0x20, cls=2) for n, o in extra if n != name]
    if data is not None and len(data) != size:
        raise ValueError("filler %s: %d bytes of content for %d" % (name, len(data), size))
    data = bytearray(data) if data is not None else bytearray([fill]) * size; rl = []
    if relocs:
        ib = len(syms) + 1
        syms.append(dict(name="___ImageBase", value=0, scn=0, cls=2))
        for off, v in relocs:
            struct.pack_into("<I", data, off, v); rl.append((off, ib, DIR32))
    return coff_write([dict(name=".text", data=bytes(data), ch=FILL_CH, relocs=rl)], syms)


def absolute_obj(syms):
    return coff_write([], [dict(name=n, value=v, scn=-1, cls=2) for n, v in sorted(syms.items())])


def weak_obj(aliases):
    syms = []
    for alias, target in sorted(aliases.items()):
        ti = sum(1 + len(y.get("aux", [])) for y in syms)
        syms.append(dict(name=target, value=0, scn=0, type=0x20, cls=2))
        syms.append(dict(name=alias, value=0, scn=0, type=0x20, cls=105, aux=[struct.pack("<II", ti, 3)]))
    return coff_write([], syms)


class Obj(checker.Coff):
    def __init__(self, d):
        checker.Coff.__init__(self, d)
        self.symptr = struct.unpack_from("<I", d, 8)[0]; self.nsym = struct.unpack_from("<I", d, 12)[0]
        for i, s in enumerate(self.secs):
            s["ch"] = struct.unpack_from("<I", d, 20 + 40 * i + 36)[0]
        self.strtab = self.symptr + 18 * self.nsym
        for y in self.syms:
            y["type"] = struct.unpack_from("<H", d, self.symptr + 18 * y["idx"] + 14)[0]


def rewrite_obj(d, sym_changes, sec_flags, reloc_changes=None, new_syms=(), sec_names=None, new_defs=(), sec_data=None, sec_aux=None):
    o = Obj(d); out = bytearray(d[:o.strtab])
    for scn, fl in sec_flags.items():
        struct.pack_into("<I", out, 20 + 40 * (scn - 1) + 36, fl)
    for scn, (num, sel) in (sec_aux or {}).items():
        y = section_symbol(o, scn)
        if y is None:
            raise ValueError("section %d has no section symbol" % scn)
        p = o.symptr + 18 * (y["idx"] + 1)
        struct.pack_into("<H", out, p + 12, num); out[p + 14] = sel
    for (scn, n), si in (reloc_changes or {}).items():
        struct.pack_into("<I", out, o.secs[scn - 1]["relptr"] + 10 * n + 4, si)
    oldlen = struct.unpack_from("<I", d, o.strtab)[0] if o.strtab + 4 <= len(d) else 4
    strtab = bytearray(d[o.strtab + 4:o.strtab + oldlen])
    for scn, nm in (sec_names or {}).items():
        b = nm.encode("latin-1")
        if len(b) > 8:
            b = ("/%d" % (4 + len(strtab))).encode(); strtab.extend(nm.encode("latin-1") + b"\0")
        out[20 + 40 * (scn - 1):20 + 40 * (scn - 1) + 8] = b.ljust(8, b"\0")

    def name_field(nm):
        b = nm.encode("latin-1")
        if len(b) <= 8:
            return b.ljust(8, b"\0")
        r = struct.pack("<II", 0, 4 + len(strtab)); strtab.extend(b + b"\0"); return r
    for idx, ch in sym_changes.items():
        p = o.symptr + 18 * idx
        if "name" in ch:
            out[p:p + 8] = name_field(ch["name"])
        val, scn, typ, cls, naux = struct.unpack_from("<IhHBB", out, p + 8)
        struct.pack_into("<IhHBB", out, p + 8, ch.get("value", val) & 0xFFFFFFFF, ch.get("scn", scn), typ, ch.get("cls", cls), naux)
    for nm in new_syms:
        out += name_field(nm) + struct.pack("<IhHBB", 0, 0, 0x20, 2, 0)
    for nm, scn, val in new_defs:
        out += name_field(nm) + struct.pack("<IhHBB", val & 0xFFFFFFFF, scn, 0, 2, 0)
    struct.pack_into("<I", out, 12, o.nsym + len(new_syms) + len(new_defs))
    res = bytearray(bytes(out) + struct.pack("<I", 4 + len(strtab)) + bytes(strtab))
    for scn, blob in (sec_data or {}).items():
        h = 20 + 40 * (scn - 1)
        struct.pack_into("<I", res, h + 20, len(res)); struct.pack_into("<I", res, h + 16, len(blob)); res += blob
    return bytes(res)


def split_object(d, splits):
    o = Obj(d); nsec = len(o.secs)
    rawsize = lambda i: struct.unpack_from("<I", d, 20 + 40 * i + 16)[0]
    secs = []; moved = {}; extra = []
    for i, s in enumerate(o.secs):
        scn = i + 1; name = s["name"]
        if name.startswith("/") and name[1:].isdigit():
            z = o.strtab + int(name[1:]); name = d[z:d.index(b"\0", z)].decode("latin-1")
        uninit = bool(s["ch"] & 0x80) and not s["ch"] & 0x40
        raw = b"" if uninit else s["raw"]; size = rawsize(i)
        rels = [struct.unpack_from("<IIH", d, s["relptr"] + 10 * k) for k in range(s["nrel"])]
        if scn not in splits:
            secs.append(dict(name=name, data=raw, size=size, ch=s["ch"], relocs=rels)); continue
        pieces = sorted(splits[scn])
        assert pieces[0][0] == 0, "the first piece starts the section"

        def cut(off, n):
            return dict(name=name, data=b"" if uninit else raw[off:off + n], size=n, ch=s["ch"],
                        relocs=[(r[0] - off, r[1], r[2]) for r in rels if off <= r[0] < off + n])
        secs.append(cut(*pieces[0]))
        for j, (off, n) in enumerate(pieces[1:]):
            extra.append(cut(off, n)); moved[(scn, off, n)] = nsec + len(extra)
    secs += extra
    by_scn = collections.defaultdict(list)
    for (scn, off, n), new in moved.items():
        by_scn[scn].append((off, n, new))
    syms = []
    for y in o.syms:
        p = o.symptr + 18 * y["idx"]
        aux = [d[p + 18 * (k + 1):p + 18 * (k + 2)] for k in range(y["naux"])]
        val, scn = y["value"], y["scn"]
        if scn in splits:
            if y["cls"] == 3 and y["naux"] and val == 0:
                first = sorted(splits[scn])[0]; a = bytearray(aux[0])
                nrel = sum(1 for r in secs[scn - 1]["relocs"])
                struct.pack_into("<IH", a, 0, first[1], nrel); aux[0] = bytes(a)
            else:
                for off, n, new in by_scn[scn]:
                    if off <= val < off + n:
                        scn, val = new, val - off; break
        syms.append(dict(name=y["name"], value=val, scn=scn, type=y["type"], cls=y["cls"], aux=aux))
    return coff_write(secs, syms)


def split_plan(ds, refs_to_section_symbol, trim=(), keep=None):
    if ds["comdat"]:
        return None
    offs = sorted({y["value"] for y in ds["defs"] if 0 <= y["value"] < max(ds["size"], 1)})
    if len(offs) < 2 and not (offs and offs[0] > 0):
        return None
    cuts = sorted(set([0] + offs)) + [ds["size"]]
    for off, _, _ in ds["rels"]:
        if any(off < c < off + 4 for c in cuts):
            return None
    if any(a >= cuts[1] for a in refs_to_section_symbol):
        return None
    raw = ds["raw"]; pieces = []
    for a, b in zip(cuts, cuts[1:]):
        n = b - a
        al = 1
        while al < ds["align"] and b % (al * 2) == 0:
            al *= 2
        k = 0
        floor = max(1, (keep or {}).get(a, 0))
        while a in trim and k < al - 1 and n - k > floor and (raw is None or (raw[a + n - k - 1] == 0 and ds["mask"][a + n - k - 1])):
            k += 1
        if keep and a in keep and n - k > keep[a] and (raw is None or not any(raw[a + keep[a]:a + n - k])):
            k = n - keep[a]                                     # zero padding past a planned size is never the global's
        pieces.append((a, n - k))
    return pieces


def va_symbol(S):
    return "_d2va_%08X" % S


def order_name(sym):
    return sym[1:] if sym.startswith("_") else sym


def module_runs():
    return []


def module_of(runs, va):
    i = bisect.bisect_right([r[0] for r in runs], va) - 1
    return runs[i][1] if i >= 0 else "?"


def verified_functions():
    out = []
    for r in load_json("functions.json")["functions"]:
        if r[2] == "verified":
            out.append(dict(va=int(r[0], 16), length=int(r[1]), name=r[3] if len(r) > 3 else None))
    return sorted(out, key=lambda f: f["va"])


def gaps(placed, start=TEXT_START, end=TEXT_END):
    out = []; cur = start
    for va, n in sorted(placed):
        if va > cur:
            out.append((cur, va - cur))
        cur = max(cur, va + n)
    if cur < end:
        out.append((cur, end - cur))
    return out


def drop_providers(drop, sources=None):
    prov = collections.defaultdict(list)
    res = json.load(open(os.path.join(drop, "results.json")))
    for u in res["units"]:
        objp = os.path.join(drop, u["obj"])
        if not os.path.exists(objp):
            continue
        src = os.path.join(ROOT, u["file"])
        if sources is not None:
            sources[objp] = os.path.splitext(u["file"])[0]
        for f in u["functions"]:
            if f.get("equal"):
                prov[int(f["va"], 16)].append((objp, src, "unit" if u["rank"] == 0 else "single"))
    return prov


def drop_data_only(drop):
    """(obj path, source path) of the units built with an empty function list: objects with data and no code, such
    as a header's tables that one source file defines. Their sections are placed from their plan entries alone."""
    out = []
    res = json.load(open(os.path.join(drop, "results.json")))
    for u in res["units"]:
        objp = os.path.join(drop, u["obj"])
        if not u["functions"] and os.path.exists(objp):
            out.append((objp, os.path.join(ROOT, u["file"])))
    return out


def find_function(o, src, va, length, name=None):
    defs, decls, symbols = checker.parse_markers(src)
    hits = []
    for y in o.funcs():
        h, kinds = checker.resolve(y["name"], defs, decls, symbols)
        if h == va and kinds & {"symbol", "def_", "wildcard"}:
            hits.append(y)
    if not hits and name:
        hits = [y for y in o.funcs() if checker.undec(y["name"]) == checker.undec(name) or y["name"] == name]
    hits = [y for y in hits if len(o.secs[y["scn"] - 1]["raw"]) == length and y["value"] == 0]
    return hits[0] if len(set(y["scn"] for y in hits)) == 1 else None


EH_SECTION = ".text$x"
SEL_ANY, SEL_ASSOCIATIVE = 2, 5


def section_symbol(o, scn):
    return next((y for y in o.syms if y["scn"] == scn and y["cls"] == 3 and y["naux"] and y["value"] == 0 and y["name"].startswith(".")), None)


def section_aux(o, scn):
    y = section_symbol(o, scn)
    if y is None:
        return None
    ln, nrel, _, _, num, sel = struct.unpack_from("<IHHIHB", o.d, o.symptr + 18 * (y["idx"] + 1))
    return ln, nrel, num, sel


EH_CODE_PREFIXES = ("__ehhandler$", "__unwindfunclet$", "__catch$")


def eh_owner(name, parents):
    for pre in EH_CODE_PREFIXES:
        if name.startswith(pre):
            rest = name[len(pre):]
            if rest in parents:
                return parents[rest]
            m = re.match(r"^(.*)\$\d+$", rest)
            if m and m.group(1) in parents:
                return parents[m.group(1)]
    return None


def eh_sections(o, placed_scns):
    out = {}; by_name = {nm: scn for scn, nm in placed_scns.items()}
    for i, s in enumerate(o.secs):
        scn = i + 1
        if s["name"] != EH_SECTION or not s["ch"] & SCN_CODE:
            continue
        a = section_aux(o, scn)
        if a and a[3] == SEL_ASSOCIATIVE:
            if a[2] in placed_scns:
                out[scn] = a[2]
            continue
        owners = {eh_owner(y["name"], by_name) for y in o.syms if y["scn"] == scn and not (y["cls"] == 3 and y["naux"] and y["name"].startswith("."))}
        if len(owners) == 1 and None not in owners:
            out[scn] = owners.pop()
    return out


def comdat_key(o, scn):
    ss = section_symbol(o, scn)
    if ss is None:
        return None
    return next((y for y in o.syms if y["idx"] > ss["idx"] and y["scn"] == scn), None)


def reloc_target(body, orig, va, r):
    a = struct.unpack_from("<I", body, r["offset"])[0]; ov = struct.unpack_from("<I", orig, r["offset"])[0]
    return ((va + r["offset"] + 4 + ov - a) if r["ty"] == REL32 else (ov - a)) & 0xFFFFFFFF


def eh_piece_check(o, scn, va, orig):
    raw = o.secs[scn - 1]["raw"]
    if orig is None or len(orig) != len(raw):
        return "no_original_bytes"
    mask = bytearray(len(raw))
    for r in o.relocs(scn):
        if r["ty"] not in (REL32, DIR32):
            return "relocation_type"
        y = r["sym"]
        if y["scn"] != scn and y["cls"] == 3 and y["naux"] and y["name"].startswith("."):
            return "section_symbol_reference"
        for k in range(4):
            mask[r["offset"] + k] = 1
    if any(not mask[i] and raw[i] != orig[i] for i in range(len(raw))):
        return "bytes_differ"
    return None


class Plan(object):
    crt = None; imports = None; lib_def = {}; lib_all = frozenset(); pinned = {}; lib_at = {}; lib_pieces = ()
    eh = True; eh_pieces = (); eh_at = {}

    def __init__(self, image, drop, modules=None, log=print, crt_lib=None, imports=False, sdk_lib=None):
        self.pe = image; self.log = log; self.drop = drop
        self.runs = module_runs()
        self.funcs = verified_functions()
        self.modules = modules
        self.obj_source = {}
        self.prov = drop_providers(drop, self.obj_source) if drop else {}
        self.data_only = drop_data_only(drop) if drop else []
        self.problems = collections.Counter(); self.examples = collections.defaultdict(list)
        self.crt = None; self.imports = None; self.sdk_lib = sdk_lib
        self.lib_def = {}; self.lib_all = set(); self.pinned = {}; self.lib_at = {}; self.lib_pieces = []
        if crt_lib:
            self.setup_crt(crt_lib)
        if imports:
            self.setup_thunks()


    def setup_crt(self, lib_path):
        import image_libs as L
        data = _get(lib_path); mem = L.ar_members(data)
        secs = L.code_sections(mem, Obj)
        win = self.pe.read(CRT_LO, CRT_HI - CRT_LO)
        cands = L.find_placements(secs, win, CRT_LO)
        chosen = L.choose_placements(cands, win, CRT_LO)
        bodies = {idx: (name, body) for idx, name, at, body in mem}
        info = {}; defs_of = {}; undef_of = {}
        for idx, (name, body) in bodies.items():
            if body[:4] == L.IMPORT_SIG or len(body) < 20 or struct.unpack_from("<H", body, 0)[0] != 0x14C:
                continue
            o = Obj(body); strict = set(); alld = set()
            for y in o.syms:
                if y["cls"] != 2 or y["scn"] <= 0:
                    continue
                alld.add(y["name"]); ch = o.secs[y["scn"] - 1]["ch"]
                sec_sym = next((z for z in o.syms if z["scn"] == y["scn"] and z["naux"] and z["cls"] == 3), None)
                sel = body[o.symptr + 18 * (sec_sym["idx"] + 1) + 14] if sec_sym else 0
                if not ch & SCN_COMDAT and not ch & SCN_CODE or ch & SCN_COMDAT and sel == 1:
                    strict.add(y["name"])
            info[idx] = dict(strict_defs=strict, all_defs=alld); defs_of[idx] = alld
            undef_of[idx] = {y["name"] for y in o.syms if y["cls"] == 2 and y["scn"] == 0 and y["value"] == 0}
        chosen, notes = L.settle_members(chosen, cands, info)
        for k_, v in notes.items():
            self.problems["crt_" + k_] += v
        lib_all = set()
        for idx, (name, body) in bodies.items():
            if body[:4] == L.IMPORT_SIG or len(body) < 20 or struct.unpack_from("<H", body, 0)[0] != 0x14C:
                continue
            for y in checker.Coff(body).syms:
                if y["cls"] == 2 and y["scn"] > 0:
                    lib_all.add(y["name"])
        self.crt = dict(path=lib_path, chosen=chosen, placements=[c for c in chosen if c["strong"]], bodies=bodies, lib_all=lib_all,
                        defs_of=defs_of, undef_of=undef_of, sections=secs, cands=cands)

    def crt_finish(self):
        import image_libs as L
        c_ = self.crt; defs_of, undef_of = c_["defs_of"], c_["undef_of"]
        strong = [c for c in c_["chosen"] if c["strong"]]
        explicit = {c["sec"]["member"] for c in strong}
        game = {p["sym"]["name"] for p in self.placed.values() if p["sym"]["cls"] == 2}
        explicit_defs = set().union(*[defs_of[m] for m in explicit]) if explicit else set()
        game_keeps = (game & c_["lib_all"]) - explicit_defs
        undef2 = {m: u - game_keeps for m, u in undef_of.items()}
        pulled, _ = L.pull_closure(sorted(explicit), defs_of, undef2)
        def covered(va, n):
            return any(a < va + n and va < a + p["length"] for a, p in self.placed.items() if va - 0x10000 < a < va + n)
        keep = list(strong); sid = lambda c: (c["sec"]["member"], c["sec"]["scn"]); used = {sid(c) for c in strong}
        byspot = collections.defaultdict(list)
        for x in c_["cands"]:
            byspot[(x["va"], len(x["sec"]["raw"]))].append(x)
        for c in c_["chosen"]:
            if c["strong"]:
                continue
            n = len(c["sec"]["raw"])
            alts = [c] + [x for x in byspot[(c["va"], n)] if x is not c]
            got = next((x for x in alts if x["sec"]["member"] in pulled and sid(x) not in used), None)
            if got is not None and covered(c["va"], n) and CRT_LO <= c["va"] < CRT_HI:
                for va in [va for va, p in self.placed.items() if va < c["va"] + n and c["va"] < va + p["length"]]:
                    self.note("library_replaces_verified", "0x%08X" % va); del self.placed[va]
            if got is not None and not covered(c["va"], n):
                for k in ("tgt_ok", "tgt_bad", "n_targets", "strong"):
                    got.setdefault(k, c.get(k))
                keep.append(got); used.add(sid(got))
                if got is not c:
                    self.problems["crt_tiny_moved_to_member_in_link"] += 1
            else:
                self.note("crt_tiny_left_as_filler", "0x%08X %d %s" % (c["va"], n, c["sec"]["mname"]))
        keep.sort(key=lambda c: c["va"])
        size = collections.Counter()
        for c in keep:
            size[c["sec"]["member"]] += len(c["sec"]["raw"])
        for i, c in enumerate(keep):
            if not c["sec"]["key"] or c["sec"]["key"]["cls"] != 3:
                continue
            n = len(c["sec"]["raw"])
            if c.get("tgt_ok", 0) >= 1 and not c.get("tgt_bad", 0):
                continue
            alts = [x for x in byspot[(c["va"], n)] if x["sec"]["key"] and x["sec"]["key"]["cls"] == 3 and sid(x) not in used
                    and not x.get("tgt_bad", 0)]
            best = max(alts, key=lambda x: size[x["sec"]["member"]] - (n if x["sec"]["member"] == c["sec"]["member"] else 0), default=None)
            if best is not None and size[best["sec"]["member"]] > size[c["sec"]["member"]] - n:
                for k in ("tgt_ok", "tgt_bad", "n_targets", "strong"):
                    best.setdefault(k, c.get(k))
                used.discard(sid(c)); used.add(sid(best)); size[c["sec"]["member"]] -= n; size[best["sec"]["member"]] += n
                keep[i] = best; self.problems["crt_static_moved_to_its_member"] += 1
        keep += self.crt_second_pass(keep, pulled)
        keep.sort(key=lambda c: c["va"])
        members = sorted({c["sec"]["member"] for c in keep})
        pulled, member_undef = L.pull_closure(members, defs_of, undef2)
        self.problems["crt_members_pulled_from_lib"] = len(pulled) - len(members)
        member_defs = set().union(*[defs_of[m] for m in pulled])
        placed_def = {}
        for c in keep:
            for nm, v in c["sec"]["defs"]:
                placed_def[nm] = c["va"] + v
        refs = collections.defaultdict(lambda: collections.defaultdict(set))
        for c in keep:
            for nm, t in c["targets"]:
                if nm not in c_["lib_all"] or nm in game_keeps:
                    ty = next(r[1] for r in c["sec"]["rels"] if r[2] == nm)
                    refs[nm][t].add(ty)
        c_.update(placements=keep, members=members, member_defs=member_defs, member_undef=member_undef, placed_def=placed_def,
                  refs=refs, game_keeps=game_keeps, linked=sorted(pulled))
        self.lib_all |= c_["lib_all"] - game_keeps
        for nm in member_defs:
            self.lib_def[nm] = placed_def.get(nm)
        for c in keep:
            for nm, v in c["sec"]["defs"]:
                self.lib_at.setdefault(c["va"] + v, nm)
        for nm, m in refs.items():
            S, n = max(((S, len(t)) for S, t in m.items()), key=lambda x: x[1])
            if len(m) > 1:
                self.note("crt_ref_two_addresses", "%s: %s" % (nm, ", ".join("0x%08X" % x for x in sorted(m))))
            self.pinned[nm] = (S, set().union(*m.values()))
        self.problems["crt_placements"] = len(keep); self.problems["crt_members"] = len(members)
        self.problems["crt_placed_bytes"] = sum(len(c["sec"]["raw"]) for c in keep)
        self.problems["crt_game_definitions_kept"] = len(game_keeps)
        for n in sorted(game_keeps):
            self.note("crt_game_definition_kept", n)

    def crt_second_pass(self, keep, pulled):
        import image_libs as L
        sid = lambda c: (c["sec"]["member"], c["sec"]["scn"])
        have = {sid(c) for c in keep}
        todo = [x for x in self.crt["sections"] if x["member"] in pulled and (x["member"], x["scn"]) not in have and x["fixed"] >= 3]
        if not todo:
            return []
        text = self.pe.read(TEXT_START, TEXT_END - TEXT_START)
        import image_data as D
        read = lambda va, n: D.vread(self.pe, va, n)
        occ = sorted([(va, p["length"]) for va, p in self.placed.items()] + [(c["va"], len(c["sec"]["raw"])) for c in keep])
        os_ = [a for a, _ in occ]
        def free(va, n):
            i = bisect.bisect_right(os_, va + n - 1) - 1
            return not (i >= 0 and occ[i][0] + occ[i][1] > va)
        by = collections.defaultdict(list)
        for c in L.find_placements(todo, text, TEXT_START):
            n = len(c["sec"]["raw"])
            if free(c["va"], n) and (c["sec"]["fixed"] >= 8 or CRT_LO <= c["va"] < CRT_HI):
                by[sid(c)].append(c)
        out = []; taken = []
        for k in sorted(by, key=lambda k: -by[k][0]["sec"]["fixed"]):
            spots = by[k]
            if len(spots) > 1:
                o = Obj(self.crt["bodies"][spots[0]["sec"]["member"]][1])
                fits_ = [(c, L.own_data_fit(c, o, read)) for c in spots]
                fit = [c for c, (ok, bad) in fits_ if ok and not bad]
                inrun = [c for c in spots if CRT_LO <= c["va"] < CRT_HI]
                if len(fit) == 1:
                    self.note("crt_second_pass_by_own_data", "0x%08X %s of %d spots" % (fit[0]["va"], spots[0]["sec"]["mname"], len(spots)))
                    spots = fit
                elif len(inrun) == 1:
                    spots = inrun
                else:
                    self.note("crt_second_pass_ambiguous", "%s %d spots" % (spots[0]["sec"]["mname"], len(spots))); continue
            c = spots[0]; n = len(c["sec"]["raw"])
            if any(a < c["va"] + n and c["va"] < a + m for a, m in taken):
                continue
            c["targets"] = L._targets(c, text, TEXT_START); c["strong"] = c["sec"]["fixed"] >= 8
            c.update(tgt_ok=0, tgt_bad=0, n_targets=len(c["targets"]), second_pass=True)
            out.append(c); taken.append((c["va"], n))
        self.problems["crt_second_pass_placed"] = len(out)
        for c in out:
            self.note("crt_second_pass", "0x%08X %d %s" % (c["va"], len(c["sec"]["raw"]), c["sec"]["mname"]))
        return out


    def place_data_split(self, rounds=3):
        import image_data as D
        snap = (collections.Counter(self.problems), {k: list(v) for k, v in self.examples.items()})
        self.place_data()
        self.obj_bytes = getattr(self, "obj_bytes", {}); orig_bytes = {}; srcs = {}
        splits = collections.defaultdict(dict); trims = collections.defaultdict(set)
        origin = {}
        for rnd in range(rounds):
            changed = set()
            for key in sorted((k for k in self._data_secs if isinstance(k[0], str) and k not in self.data_scn), key=str):
                objp, scn = key
                if key in origin:
                    oscn, off = origin[key]
                    if (key in self._data_rejected or self._data_refused.get(key) == "bytes_differ") and off not in trims[(objp, oscn)]:
                        trims[(objp, oscn)].add(off); changed.add(objp)
                    if key in self._data_rejected and (objp, oscn) in srcs:
                        prev = [a for a, _ in splits[objp][oscn] if a < off]
                        keep = self._keep(objp, srcs[(objp, oscn)][0])
                        if prev and prev[-1] in keep and prev[-1] not in trims[(objp, oscn)]:
                            trims[(objp, oscn)].add(prev[-1]); changed.add(objp)
                    continue
                if scn in splits.get(objp, {}) or not (key in self._data_rejected or key in self._data_refused):
                    continue
                o = self.cache[objp][0]; ds = self._data_secs[key]
                refs = []
                for i, sc in enumerate(o.secs):
                    if not sc["nrel"] or sc["ch"] & 0x80 and not sc["ch"] & 0x40:
                        continue
                    for r in o.relocs(i + 1):
                        y = r["sym"]
                        if y["scn"] == scn and y["cls"] == 3 and y["naux"] and y["value"] == 0:
                            refs.append(struct.unpack_from("<I", sc["raw"], r["offset"])[0] if r["ty"] == DIR32 else 1 << 32)
                pcs = split_plan(ds, refs)
                if pcs and len(pcs) > 1:
                    srcs[(objp, scn)] = (ds, refs); splits[objp][scn] = pcs; changed.add(objp)
            if not changed:
                break
            for objp in changed:
                if objp not in orig_bytes:
                    orig_bytes[objp] = _get(objp)
                for scn in list(splits[objp]):
                    ds, refs = srcs[(objp, scn)]
                    splits[objp][scn] = split_plan(ds, refs, trims[(objp, scn)], self._keep(objp, ds))
                nsec = len(Obj(orig_bytes[objp]).secs); b = split_object(orig_bytes[objp], splits[objp])
                no = Obj(b); self.obj_bytes[objp] = b; self.cache[objp] = (no, self.cache[objp][1])
                for p in self.placed.values():
                    if p["obj"] == objp:
                        p["sym"] = no.by_idx[p["sym"]["idx"]]
                for k in [k for k in origin if k[0] == objp]:
                    del origin[k]
                n = nsec
                for scn in sorted(splits[objp]):
                    pcs = sorted(splits[objp][scn])
                    origin[(objp, scn)] = (scn, 0)
                    for off, _ in pcs[1:]:
                        n += 1; origin[(objp, n)] = (scn, off)
            self.problems = collections.Counter(snap[0]); self.examples = collections.defaultdict(list, {k: list(v) for k, v in snap[1].items()})
            self.place_data()
        self.split_origin = origin
        self.problems["data_split_sections"] = sum(len(v) for v in splits.values())
        self.problems["data_split_pieces"] = len(origin)
        placed = [self.data_scn[k] for k in origin if k in self.data_scn]
        self.problems["data_split_pieces_placed"] = len(placed)
        self.problems["data_split_bytes_placed"] = sum(c["size"] for c in placed)
        self.problems["data_split_pieces_trimmed"] = sum(len(v) for v in trims.values())
        return self.data_pieces

    def _keep(self, objp, ds):
        sz = (getattr(self, "data_sizes", None) or {}).get(objp) or {}
        return {y["value"]: sz[checker.undec(y["name"])] for y in ds["defs"] if y["cls"] == 2 and checker.undec(y["name"]) in sz}

    data_plan_path = None

    def owner_objs(self):
        """Objects whose data sections are placed: those with placed functions, and the data-only units."""
        return {p["obj"] for p in self.placed.values()} | {objp for objp, _ in self.data_only if objp in self.cache}

    def data_markers(self):
        if getattr(self, "_data_markers", None) is not None:
            return self._data_markers
        path = self.data_plan_path if self.data_plan_path is not None else os.path.join(ROOT, "build", "data_plan.json")
        self._data_markers = {}; self.data_sizes = {}
        if not path or not os.path.exists(path) or not getattr(self, "drop", None):
            return self._data_markers
        by_file = collections.defaultdict(dict); size_of = collections.defaultdict(dict)
        for d in json.load(open(path)).get("definitions", ()):
            for nm in {d.get("name"), d.get("cname")} - {None}:
                by_file[os.path.splitext(d["file"])[0]][nm] = int(d["va"], 16)
                if d.get("size"):
                    size_of[os.path.splitext(d["file"])[0]][nm] = int(d["size"])
        objs = self.owner_objs()
        for objp in objs:
            stem = self.obj_source.get(objp)
            if stem is None:
                continue
            if stem in by_file:
                self._data_markers[objp] = by_file[stem]; self.data_sizes[objp] = size_of[stem]
        return self._data_markers

    def static_data_markers(self):
        """objp -> {symbol name: va} from the unit's `// build: symbol <name> 0xVA` lines (exact names only), so a
        data section that nothing references and the plan does not hold (a static such as a header's table) has an
        address hint. The bytes must still match."""
        if getattr(self, "_static_markers", None) is not None:
            return self._static_markers
        self._static_markers = {}
        for objp in self.owner_objs():
            stem = self.obj_source.get(objp)
            if stem is None:
                continue
            for ext in (".cpp", ".CPP", ".c", ".C"):
                p = os.path.join(ROOT, stem + ext)
                if os.path.exists(p):
                    break
            else:
                continue
            marks = {}
            for ln in open(p, encoding="latin-1"):
                m = checker.SYMBOL_DIRECTIVE.match(ln.strip())
                if m and not m.group(1).endswith("*"):
                    marks[m.group(1)] = int(m.group(2), 16)
            if marks:
                self._static_markers[objp] = marks
        return self._static_markers

    def place_data(self):
        import image_data as D
        pe = self.pe; lay = self.layout = D.image_layout(pe)
        secs = {}; objs = {}; defs_by_name = collections.defaultdict(list)
        owners = sorted(self.owner_objs())
        crt_members = list(self.crt["linked"]) if self.crt else []
        for objp in owners:
            objs[objp] = self.cache[objp][0]
        for m in crt_members:
            objs[("crt", m)] = Obj(self.crt["bodies"][m][1])
        for own, o in objs.items():
            for ds in D.data_sections(o):
                key = (own, ds["scn"]); secs[key] = ds
                for y in ds["defs"]:
                    if y["cls"] == 2:
                        defs_by_name[y["name"]].append((key, y["value"]))
        for own, o in objs.items():
            if isinstance(own, str):
                for al, tg in D.alternatenames(o):
                    defs_by_name[al].extend((key, val) for key, val in defs_by_name.get(tg, ()) if key[0] == own)
        anchors = collections.defaultdict(collections.Counter); names_S = collections.defaultdict(collections.Counter)
        sym_S = self._sym_S = collections.defaultdict(collections.Counter)
        self._names_S = names_S

        def take(own, o, scn, va, raw, rels):
            for r in rels:
                y = r["sym"]; ty = r["ty"]
                if ty not in (REL32, DIR32, 0x07):
                    continue
                add = struct.unpack_from("<I", raw, r["offset"])[0] if raw and r["offset"] + 4 <= len(raw) else 0
                S = D.reloc_target(pe, va + r["offset"], ty, add)
                if S is None:
                    continue
                if y["scn"] > 0 and (own, y["scn"]) in secs:
                    anchors[(own, y["scn"])][(S - y["value"]) & 0xFFFFFFFF] += 1
                    if not (y["cls"] == 3 and y["naux"]):
                        sym_S[(own, y["scn"], y["idx"])][S] += 1
                elif y["cls"] == 2:
                    names_S[y["name"]][S] += 1
        for p in self.placed.values():
            o = objs[p["obj"]]; scn = p["sym"]["scn"]
            take(p["obj"], o, scn, p["va"], o.secs[scn - 1]["raw"], o.relocs(scn))
        self._eh_code_va = self._eh_data_anchors(objs, secs, take) if self.eh else {}
        marks = self.data_markers()
        for key, ds in secs.items():
            m = marks.get(key[0]) if isinstance(key[0], str) else None
            if not m:
                continue
            for y in ds["defs"]:
                va = m.get(checker.undec(y["name"])) if y["cls"] == 2 else None
                if va is not None and 0 <= y["value"] < max(ds["size"], 1):
                    anchors[key][(va - y["value"]) & 0xFFFFFFFF] += 1; self.problems["data_marker_anchors"] += 1
        smarks = self.static_data_markers()
        for key, ds in secs.items():
            sm = smarks.get(key[0]) if isinstance(key[0], str) else None
            if not sm or not ds["ch"] & 0x80000000 or ds["raw"] is None:
                continue                     # initialised writable data only; .bss, literals and .rdata have their own placement
            for y in ds["defs"]:
                va = sm.get(y["name"]) if y["cls"] in (2, 3) and not y["name"].startswith("$") else None
                if va is None or not 0 <= y["value"] < max(ds["size"], 1):
                    continue
                base = (va - y["value"]) & 0xFFFFFFFF
                others = [a_ for a_ in anchors.get(key, {}) if a_ != base]
                if others:
                    self.problems["static_data_marker_disagrees"] += 1
                    raise RuntimeError("static data marker %s 0x%08X disagrees with the section's other anchors (%s) in %s"
                                       % (y["name"], va, ", ".join("0x%08X" % a_ for a_ in sorted(others)), key[0]))
                anchors[key][base] += 1; self.problems["static_data_marker_anchors"] += 1
        self._crt_table_anchors(secs, anchors, lay)
        if self.crt:
            for c in self.crt["placements"]:
                own = ("crt", c["sec"]["member"]); o = objs[own]; scn = c["sec"]["scn"]
                take(own, o, scn, c["va"], o.secs[scn - 1]["raw"], o.relocs(scn))
        accepted = {}; refused = {}; self._dbg = {}; self._anchors = anchors
        for rnd in range(12):
            for nm, Ss in names_S.items():
                for S, n_ in Ss.items():
                    for key, val in defs_by_name.get(nm, ()):
                        a_ = (S - val) & 0xFFFFFFFF
                        if anchors[key].get(a_, 0) < n_:
                            anchors[key][a_] = n_
            new = []
            for key, cnt in list(anchors.items()):
                if key in accepted or key in refused or key not in secs:
                    continue
                ds = secs[key]; why = None
                for va, _ in sorted(cnt.items(), key=lambda kv: (-kv[1], kv[0])):
                    why = self._data_check(ds, va, key)
                    if not why:
                        break
                if why:
                    refused[key] = why; self._dbg[key] = (why, dict(cnt)); continue
                mk = marks.get(key[0]) if isinstance(key[0], str) else None
                if mk and len(cnt) > 1 and any(y["cls"] == 2 and mk.get(checker.undec(y["name"]), va + y["value"]) != va + y["value"] for y in ds["defs"]):
                    refused[key] = "markers_disagree"; continue
                if len(cnt) > 1 and len([y for y in ds["defs"] if not y["name"].startswith("$")]) > 1 and 3 * cnt[va] < 2 * sum(cnt.values()):
                    refused[key] = "anchors_disagree"; continue
                if len(cnt) > 1 and ds["raw"] is None and isinstance(key[0], str) and len({y["value"] for y in ds["defs"] if not y["name"].startswith("$")}) > 1:
                    refused[key] = "anchors_disagree"; continue
                if len(cnt) > 1:
                    self.note("data_anchors_disagree_first_fit", "%s %s 0x%08X of %d" % (ds["name"], key[1], va, len(cnt)))
                alts = [x for x, _ in sorted(cnt.items(), key=lambda kv: (-kv[1], kv[0])) if x != va and not self._data_check(ds, x, key)]
                accepted[key] = dict(key=key, va=va, size=ds["size"], region=D.region_of(lay, va, max(ds["size"], 1)), sec=ds,
                                     anchors=sum(cnt.values()), how="reference", alts=alts); new.append(key)
            if not new:
                break
            for key in new:
                own, scn = key; ds = secs[key]
                if ds["raw"] is not None and ds["rels"]:
                    take(own, objs[own], scn, accepted[key]["va"], ds["raw"], objs[own].relocs(scn))
        if self.crt:
            for key, ds in sorted(secs.items(), key=lambda kv: str(kv[0])):
                if key in accepted or not isinstance(key[0], tuple) or ds["raw"] is None or ds["size"] < 4:
                    continue
                hits = self._data_search(ds, self._expected(key, ds, objs[key[0]], accepted))
                if len(hits) == 1 and not self._data_check(ds, hits[0], key):
                    accepted[key] = dict(key=key, va=hits[0], size=ds["size"], region=D.region_of(lay, hits[0], ds["size"]), sec=ds,
                                         anchors=0, how="content"); refused.pop(key, None)
                else:
                    self.note("crt_data_not_found" if not hits else "crt_data_ambiguous", "%s %s %d B" % (self.crt["bodies"][key[0][1]][0].split("\\")[-1], ds["name"], ds["size"]))
        chosen, rejected = D.choose_data(list(accepted.values()))
        for c in chosen:
            c["region"] = D.region_of(lay, c["va"], max(c["size"], 1))
            if c.get("moved"):
                self.note("data_moved_to_other_reference", "%s 0x%08X" % (c["sec"]["name"], c["va"]))
        seen = {}; final = []
        for c in sorted(chosen, key=lambda c: (isinstance(c["key"][0], str), c["va"])):
            names = [y["name"] for y in c["sec"]["defs"] if y["cls"] == 2]
            if any(n in seen for n in names):
                self.note("data_duplicate_definition", "%s 0x%08X" % (names[0], c["va"])); continue
            for n in names:
                seen[n] = c["va"] + next(y["value"] for y in c["sec"]["defs"] if y["name"] == n)
            final.append(c)
        for c in rejected:
            self.note("data_overlap_dropped", "0x%08X %d %s" % (c["va"], c["size"], c["sec"]["name"]))
        for key, why in refused.items():
            self.note("data_refused_" + why, "%s %s" % (secs[key]["name"], key[1]))
        kept = {c["key"] for c in final}; self.data_unplaced_game = []
        def unplaced(key, why, va=None):
            ds = secs[key]; cnt = anchors.get(key) or {}
            va = va if va is not None else (max(cnt.items(), key=lambda kv: (kv[1], -kv[0]))[0] if cnt else None)
            self.data_unplaced_game.append(dict(object=os.path.relpath(key[0], getattr(self, "drop", None)) if getattr(self, "drop", None) else key[0], section=ds["name"],
                                                scn=key[1], size=ds["size"], va=("0x%08X" % va) if va is not None else None, reason=why,
                                                symbols=[y["name"] for y in ds["defs"] if y["cls"] == 2][:8]))
        for key, why in sorted(refused.items(), key=lambda kv: str(kv[0])):
            if isinstance(key[0], str):
                unplaced(key, why)
        for c in rejected:
            if isinstance(c["key"][0], str) and c["key"] not in kept:
                unplaced(c["key"], "overlap", c["va"])
        for c in chosen:
            if isinstance(c["key"][0], str) and c["key"] not in kept:
                unplaced(c["key"], "duplicate_definition", c["va"])
        final.sort(key=lambda c: c["va"])
        self._data_secs = secs; self._data_refused = dict(refused); self._data_rejected = {c["key"] for c in rejected} | ({c["key"] for c in chosen} - kept)
        self.data_pieces = final; self.data_scn = {c["key"]: c for c in final}
        self.data_def_at = dict(seen)
        self.problems["data_sections_placed"] = len(final)
        self.problems["data_sections_placed_game"] = sum(1 for c in final if isinstance(c["key"][0], str))
        self.problems["data_sections_placed_crt"] = sum(1 for c in final if not isinstance(c["key"][0], str))
        self.problems["data_bytes_placed_game"] = sum(c["size"] for c in final if isinstance(c["key"][0], str))
        self.problems["data_bytes_placed_crt"] = sum(c["size"] for c in final if not isinstance(c["key"][0], str))
        self.problems["data_crt_by_content"] = sum(1 for c in final if c["how"] == "content")
        eh_data = [c for c in final if isinstance(c["key"][0], str) and c["sec"]["name"].startswith(".xdata$x")]
        self.problems["eh_data_sections_placed"] = len(eh_data)
        self.problems["eh_data_bytes_placed"] = sum(c["size"] for c in eh_data)
        self.problems["eh_data_sections_refused"] = sum(1 for key in refused if isinstance(key[0], str) and secs[key]["name"].startswith(".xdata$x"))
        unplaced = [k for k in secs if isinstance(k[0], tuple) and k not in self.data_scn]
        self.problems["data_crt_sections_unplaced"] = len(unplaced)
        self.crt_data_unplaced = unplaced
        self.crt_data_fate = self._crt_data_fate(objs, secs, unplaced, names_S) if self.crt else {}
        defined_any = {y["name"] for own, o in objs.items() for y in o.syms if y["cls"] == 2 and y["scn"] > 0}
        self.commons = {y["name"] for own, o in objs.items() for y in o.syms if y["cls"] == 2 and y["scn"] == 0 and y["value"]} - defined_any
        self.problems["data_common_symbols"] = len(self.commons)
        for key in unplaced:
            ds = secs[key]
            if self.crt_data_fate.get(key) == "comdat" and any(y["cls"] == 2 and y["name"] in seen for y in ds["defs"]):
                self.crt_data_fate[key] = "duplicate"; self.problems["crt_data_fate_duplicate"] += 1; self.problems["crt_data_fate_comdat"] -= 1
        for c in final:
            if not isinstance(c["key"][0], str):
                for y in c["sec"]["defs"]:
                    if y["cls"] == 2:
                        self.lib_def[y["name"]] = c["va"] + y["value"]
                        self.lib_at.setdefault(c["va"] + y["value"], y["name"])
        return final

    def _crt_table_anchors(self, secs, anchors, lay):
        """Initializer-table pieces (.CRT$XC*, .CRT$XI*) in game objects hold pointers to the unit's own dynamic
        initializers (.text$yc). Nothing references the pieces themselves, so anchor each at the original table slot
        that holds the same initializer address."""
        import image_data as D
        code_at = {(p["obj"], p["sym"]["scn"]): p["va"] - p["sym"]["value"] for p in self.placed.values()}
        lo, hi = lay["rdata"]; raw = D.vread(self.pe, lo, hi - lo) or b""
        slots = collections.defaultdict(list)
        for i in range(0, len(raw) - 3, 4):
            slots[struct.unpack_from("<I", raw, i)[0]].append(lo + i)
        n = 0
        for key, ds in secs.items():
            if not isinstance(key[0], str) or ds["raw"] is None or not ds["name"].startswith((".CRT$XC", ".CRT$XI")):
                continue
            for off, ty, y in ds["rels"]:
                base = code_at.get((key[0], y["scn"])) if ty == DIR32 and y["scn"] > 0 else None
                if base is None:
                    self.note("crt_table_target_unplaced", "%s %s" % (ds["name"], y["name"])); continue
                target = (base + y["value"] + struct.unpack_from("<I", ds["raw"], off)[0]) & 0xFFFFFFFF
                hits = slots.get(target, [])
                if len(hits) == 1:
                    anchors[key][(hits[0] - off) & 0xFFFFFFFF] += 1000; n += 1
                else:
                    self.note("crt_table_slot_" + ("missing" if not hits else "ambiguous"), "%s 0x%08X" % (ds["name"], target))
        self.problems["crt_table_slots_anchored"] = n

    def _crt_data_fate(self, objs, secs, unplaced, names_S):
        first = {}
        for (own, scn), ds in secs.items():
            if isinstance(own, tuple):
                for y in ds["defs"]:
                    if y["cls"] == 2:
                        first.setdefault(y["name"], (own, scn))
        for own, o in objs.items():
            if isinstance(own, tuple):
                for y in o.syms:
                    if y["cls"] == 2 and y["scn"] > 0:
                        first.setdefault(y["name"], (own, y["scn"]))
        roots = [(("crt", c["sec"]["member"]), c["sec"]["scn"]) for c in self.crt["placements"]]
        roots += [c["key"] for c in self.data_pieces if isinstance(c["key"][0], tuple)]
        roots += [first[n] for n in names_S if n in first]
        for own, o in objs.items():
            if isinstance(own, tuple):
                for i, sc in enumerate(o.secs):
                    if sc["ch"] & SCN_CODE and not sc["ch"] & (SCN_COMDAT | SCN_REMOVE):
                        roots.append((own, i + 1))
        seen = set(roots); todo = list(roots)
        while todo:
            own, scn = todo.pop(); o = objs[own]
            if scn - 1 >= len(o.secs) or not o.secs[scn - 1]["nrel"]:
                continue
            for r in o.relocs(scn):
                y = r["sym"]; t = (own, y["scn"]) if y["scn"] > 0 else first.get(y["name"])
                if t and t not in seen:
                    seen.add(t); todo.append(t)
        self.crt_definers = collections.Counter(n for own, o in objs.items() if isinstance(own, tuple) for n in
                                                {y["name"] for y in o.syms if y["cls"] == 2 and y["scn"] > 0})
        fate = {}; self.crt_pinned = {}
        for key in unplaced:
            ds = secs[key]
            if not ds["size"] and not ds["defs"]:
                fate[key] = "empty"
            elif self._anchors.get(key):
                fate[key] = "pinned"; own, scn = key
                for y in ds["defs"]:
                    cnt = self._sym_S.get((own, scn, y["idx"])) or (names_S.get(y["name"]) if y["cls"] == 2 else None)
                    if cnt:
                        nn = y["name"] if y["cls"] == 2 else "%s$c%dd" % (y["name"], own[1])
                        self.crt_pinned[nn] = cnt.most_common(1)[0][0]
                self.note("crt_data_pinned_by_symbol", "%s %s %d B" % (self.crt["bodies"][key[0][1]][0].split("\\")[-1], ds["name"], ds["size"]))
            elif ds["comdat"]:
                fate[key] = "comdat"
            else:
                fate[key] = "drop"; self.note("crt_data_unreachable_dropped", "%s %s %d B" % (self.crt["bodies"][key[0][1]][0].split("\\")[-1], ds["name"], ds["size"]))
        for v in fate.values():
            self.problems["crt_data_fate_" + v] += 1
        return fate

    def _eh_data_anchors(self, objs, secs, take):
        out = collections.defaultdict(dict)
        by_obj = collections.defaultdict(dict)
        for p in self.placed.values():
            by_obj[p["obj"]][p["sym"]["scn"]] = p
        for own in sorted(by_obj):
            o = objs[own]; placed_scn = by_obj[own]
            cand = eh_sections(o, {scn: p["sym"]["name"] for scn, p in placed_scn.items()})
            if not cand:
                continue
            anchors = collections.defaultdict(collections.Counter)
            for scn, p in placed_scn.items():
                body = o.secs[scn - 1]["raw"]; orig = self.pe.read(p["va"], len(body))
                if not orig or len(orig) != len(body):
                    continue
                for r in o.relocs(scn):
                    if r["ty"] in (REL32, DIR32) and r["sym"]["scn"] in cand:
                        anchors[r["sym"]["scn"]][(reloc_target(body, orig, p["va"], r) - r["sym"]["value"]) & 0xFFFFFFFF] += 1
            for xscn in sorted(cand):
                cnt = anchors.get(xscn)
                raw = o.secs[xscn - 1]["raw"]; n = len(raw)
                if not cnt or len(cnt) != 1:
                    self.problems["eh_data_code_unanchored"] += 1; continue
                va = next(iter(cnt))
                if not (TEXT_START <= va and va + n <= TEXT_END) or eh_piece_check(o, xscn, va, self.pe.read(va, n)):
                    self.problems["eh_data_code_unanchored"] += 1; continue
                out[own][xscn] = va; self.problems["eh_data_code_anchored"] += 1
                take(own, o, xscn, va, raw, [r for r in o.relocs(xscn) if r["sym"]["scn"] > 0 and (own, r["sym"]["scn"]) in secs])
        return dict(out)

    def _eh_target_check(self, ds, va, key):
        import image_data as D
        code = (getattr(self, "_eh_code_va", None) or {}).get(key[0]) if isinstance(key[0], str) else None
        if not code or ds["raw"] is None:
            return None
        for off, ty, y in ds["rels"]:
            if y["scn"] in code and ty in (REL32, DIR32):
                add = struct.unpack_from("<I", ds["raw"], off)[0]
                if D.reloc_target(self.pe, va + off, ty, add) != (code[y["scn"]] + y["value"]) & 0xFFFFFFFF:
                    return "eh_target_differs"
        return None

    def _data_check(self, ds, va, key):
        import image_data as D
        reg = D.region_of(self.layout, va, max(ds["size"], 1))
        if reg is None:
            return "outside_regions"
        if reg == "rdata" and ds["ch"] & D.SCN_WRITE and not ds["name"].startswith((".CRT", ".rtc")):
            return "writable_in_rdata"
        if reg == "data_init" and ds["raw"] is None:
            return "uninitialised_in_initialised_data"
        if reg == "data_bss" and ds["raw"] is not None:
            return "initialised_in_bss"
        if isinstance(key[0], str) and any(y["cls"] == 2 and y["name"] in self.lib_all and not self._literal_free(y["name"]) for y in ds["defs"]):
            return "defines_library_name"
        if not D.fits(ds, va, self.pe):
            return "bytes_differ"
        return self._eh_target_check(ds, va, key)

    LITERAL_PREFIXES = ("??_C@", "__real@", "__xmm@", "__mask@")

    def _literal_free(self, name):
        return name.startswith(self.LITERAL_PREFIXES) and name not in ((self.crt or {}).get("member_defs") or ())

    def _expected(self, key, ds, o, accepted):
        own = key[0]; raw = bytearray(ds["raw"]); mask = bytearray(ds["mask"])
        code_at = {}
        if isinstance(own, tuple):
            for c in self.crt["placements"]:
                if c["sec"]["member"] == own[1]:
                    code_at[c["sec"]["scn"]] = c["va"]
        else:
            for p in self.placed.values():
                if p["obj"] == own:
                    code_at[p["sym"]["scn"]] = p["va"]
        for k2, c in accepted.items():
            if k2[0] == own:
                code_at[k2[1]] = c["va"]
        placed_at = {p["sym"]["name"]: va for va, p in self.placed.items()}
        for off, ty, y in ds["rels"]:
            if ty != DIR32 or off + 4 > len(raw):
                continue
            t = None
            if y["scn"] > 0 and y["scn"] in code_at:
                t = code_at[y["scn"]] + y["value"]
            elif y["cls"] == 2:
                t = self.lib_def.get(y["name"]) if self.lib_def.get(y["name"]) is not None else placed_at.get(y["name"])
            if t is None:
                continue
            add = struct.unpack_from("<I", raw, off)[0]
            struct.pack_into("<I", raw, off, (t + add) & 0xFFFFFFFF)
            for k in range(4):
                mask[off + k] = 0xFF
        return dict(ds, raw=bytes(raw), mask=bytes(mask), rels=[])

    def _data_search(self, ds, exp=None):
        import image_data as D
        if not hasattr(self, "_data_windows"):
            self._data_windows = [(lo, D.vread(self.pe, lo, hi - lo)) for lo, hi in (self.layout["rdata"], self.layout["data_init"])]
        ds = exp or ds
        best = (0, 0); i = 0; m = ds["mask"]
        while i < len(m):
            if m[i]:
                j = i
                while j < len(m) and m[j]:
                    j += 1
                if j - i > best[1]:
                    best = (i, j - i)
                i = j
            else:
                i += 1
        off, ln = best
        if ln < 4:
            return []
        keyb = ds["raw"][off:off + min(ln, 32)]; out = []
        for lo, win in self._data_windows:
            p = win.find(keyb)
            while p != -1 and len(out) < 4:
                st = p - off
                if st >= 0 and st + ds["size"] <= len(win) and D.fits(ds, lo + st, self.pe):
                    out.append(lo + st)
                p = win.find(keyb, p + 1)
        return sorted(set(out))


    def setup_thunks(self):
        import image_libs as L
        lp = load_json("linker_pieces.json")
        thunks = {}
        for run in lp["runs"]:
            for e in run["entries"]:
                thunks[int(e["va"], 16)] = int(e["iat_slot"], 16)
            for q in run.get("neighbours", []):
                q = int(q if isinstance(q, str) else q["va"], 16); b = self.pe.read(q, 6)
                if b[:2] == b"\xFF\x25":
                    thunks[q] = struct.unpack_from("<I", b, 2)[0]
        for q in TABLE_THUNK_RECORDS:
            b = self.pe.read(q, 6)
            if b[:2] == b"\xFF\x25":
                thunks[q] = struct.unpack_from("<I", b, 2)[0]
        self.imports = dict(thunks=thunks, entries=L.image_imports(self.pe))
        self.problems["thunks_in_tables"] = len(thunks)

    def note(self, kind, what):
        self.problems[kind] += 1
        if len(self.examples[kind]) < 12:
            self.examples[kind].append(what)

    def choose(self):
        cache = {}; placed = {}
        for f in sorted(self.funcs, key=lambda f: f["va"]):
            va = f["va"]; mod = module_of(self.runs, va)
            if self.modules and mod not in self.modules:
                continue
            if not TEXT_START <= va < TEXT_END:
                self.note("outside_text", "0x%08X" % va); continue
            got = None
            for objp, srcp, kind in sorted(self.prov.get(va, []), key=lambda p: p[2] != "unit"):
                if objp not in cache:
                    cache[objp] = (Obj(_get(objp)), _get(srcp, False))
                o, src = cache[objp]
                y = find_function(o, src, va, f["length"], f.get("name"))
                if y:
                    got = dict(va=va, length=f["length"], obj=objp, sym=y, kind=kind, module=mod); break
            if not got:
                self.note("no_provider" if not self.prov.get(va) else "symbol_not_found", "0x%08X" % va); continue
            placed[va] = got
        lib = sorted([(c["va"], len(c["sec"]["raw"])) for c in (self.crt["placements"] if self.crt else [])]
                     + [(t, 6) for t in (self.imports["thunks"] if self.imports else {})])
        if lib:
            ls = [a for a, _ in lib]
            for va in sorted(placed):
                n = placed[va]["length"]; i = bisect.bisect_right(ls, va + n - 1) - 1
                if i >= 0 and lib[i][0] + lib[i][1] > va:
                    self.note("library_replaces_verified", "0x%08X" % va); del placed[va]
        last_end = 0
        for va in sorted(placed):
            if va < last_end:
                self.note("overlap_dropped", "0x%08X" % va); del placed[va]; continue
            last_end = va + placed[va]["length"]
        for objp, srcp in self.data_only:
            if objp not in cache:
                cache[objp] = (Obj(_get(objp)), _get(srcp, False))
        self.placed = placed; self.cache = cache
        if self.crt:
            self.crt_finish()
        return placed

    def analyse(self):
        by_obj = collections.defaultdict(list)
        for va, p in self.placed.items():
            by_obj[p["obj"]].append(p)
        self.objs = []; self.rels = []
        defs = collections.Counter(p["sym"]["name"] for p in self.placed.values() if p["sym"]["cls"] == 2)
        k = 0
        dscn_of = collections.defaultdict(dict)
        for (own, scn), dp in getattr(self, "data_scn", {}).items():
            if isinstance(own, str):
                dscn_of[own][scn] = dp
        for objp, _ in self.data_only:
            if objp in dscn_of:
                by_obj[objp]
        self.data_k = {}
        self.eh_pieces = []; self.eh_at = {}
        self._eh_taken = sorted([(va, p["length"]) for va, p in self.placed.items()]
                                + [(c["va"], len(c["sec"]["raw"])) for c in (self.crt["placements"] if self.crt else [])]
                                + [(t, 6) for t in (self.imports["thunks"] if self.imports else {})]
                                + [(a, n) for a, n, _ in self.lib_pieces])
        for objp in sorted(by_obj):
            o, src = self.cache[objp]; k += 1
            data_scn = dscn_of.get(objp, {}); self.data_k[k] = objp
            for dp in data_scn.values():
                dp["k"] = k
            placed_scn = {}; sym_changes = {}; sec_flags = {}; sec_names = {}; sec_aux = {}
            for p in by_obj[objp]:
                if p["sym"]["scn"] in placed_scn:
                    self.note("two_vas_one_section", "0x%08X" % p["va"]); continue
                placed_scn[p["sym"]["scn"]] = p
            final = {}
            eh = self.place_eh(o, k, objp, placed_scn, data_scn) if self.eh else {}
            referenced = {r["sym"]["idx"] for scn in list(placed_scn) + list(eh) + [s_ for s_, dp in data_scn.items() if dp["sec"]["rels"]] for r in o.relocs(scn)}
            for y in o.syms:
                if y["scn"] <= 0 or y["name"].startswith("."):
                    continue
                if y["scn"] in eh:
                    e = eh[y["scn"]]
                    if y["idx"] == e["key"]["idx"]:
                        nn = "_d2eh_%08X" % e["va"]
                    elif y["idx"] in referenced:
                        nn = y["name"] if y["cls"] == 2 else "%s$r%d" % (y["name"], k)
                    else:
                        continue
                    sym_changes[y["idx"]] = dict(name=nn, cls=2); final[y["idx"]] = nn; e["defs"][nn] = e["va"] + y["value"]
                    continue
                if y["scn"] in data_scn:
                    if y["cls"] == 2:
                        final[y["idx"]] = y["name"]
                    continue
                if y["scn"] in placed_scn:
                    if y is placed_scn[y["scn"]]["sym"] and (y["cls"] == 3 or defs[y["name"]] > 1 or y["name"] in self.lib_all):
                        if y["name"] in self.lib_all:
                            self.note("placed_name_is_library_name", y["name"])
                        if y["cls"] == 2:
                            self.note("placed_twice_renamed", y["name"])
                        nn = "%s$r%d" % (y["name"], k); sym_changes[y["idx"]] = dict(name=nn, cls=2); final[y["idx"]] = nn
                    elif y["cls"] == 2:
                        final[y["idx"]] = y["name"]
                    continue
                if (y["cls"] == 2 or (y["cls"] == 3 and y["idx"] in referenced)) and (y["idx"] in referenced or not y["name"].startswith("$")):
                    nn = y["name"] if y["cls"] == 2 else "%s$r%d" % (y["name"], k)
                    sym_changes[y["idx"]] = dict(name=nn, cls=2, scn=0, value=0); final[y["idx"]] = nn
            if self.data_mode:
                for y in o.syms:
                    if y["cls"] == 2 and y["scn"] == 0 and y["value"]:
                        sym_changes[y["idx"]] = dict(value=0, scn=0)
            for i, s in enumerate(o.secs):
                scn = i + 1
                if scn in placed_scn:
                    p = placed_scn[scn]; al = (s["ch"] & SCN_ALIGN_MASK) >> 20
                    if s["name"] != ".text":
                        sec_names[scn] = ".text"; self.note("grouped_section_renamed", "0x%08X %s" % (p["va"], s["name"]))
                    align = 1 << (al - 1) if al else 16
                    if p["va"] % align:
                        sec_flags[scn] = (s["ch"] & ~SCN_ALIGN_MASK) | ALIGN_1; self.note("unaligned_start", "0x%08X" % p["va"])
                elif scn in eh:
                    e = eh[scn]; al = (s["ch"] & SCN_ALIGN_MASK) >> 20; align = 1 << (al - 1) if al else 16
                    sec_names[scn] = ".text"; sec_aux[scn] = (0, SEL_ANY)
                    sec_flags[scn] = ((s["ch"] & ~SCN_ALIGN_MASK) | ALIGN_1 if e["va"] % align else s["ch"]) | SCN_COMDAT
                elif scn in data_scn:
                    import image_data as D
                    dp = data_scn[scn]
                    sec_names[scn] = D.group_name(dp["region"], dp["va"]); sec_flags[scn] = D.group_ch(dp["region"], s["ch"] & ~SCN_COMDAT)
                else:
                    if s["name"] == ".drectve":
                        self.problems["exports_dropped"] += s["raw"].count(b"/EXPORT:"); sec_names[scn] = ".d2rmdir"
                    sec_flags[scn] = (s["ch"] | SCN_REMOVE) & ~SCN_COMDAT
            import image_data as D
            walk = [(scn, p["va"], o.secs[scn - 1]["raw"], p, True) for scn, p in placed_scn.items()]
            walk += [(scn, e["va"], o.secs[scn - 1]["raw"], None, True) for scn, e in eh.items()]
            walk += [(scn, dp["va"], dp["sec"]["raw"], None, False) for scn, dp in data_scn.items() if dp["sec"]["raw"] is not None and dp["sec"]["rels"]]
            for scn, va, body, p, code in walk:
                orig = self.pe.read(va, len(body)) if code else D.vread(self.pe, va, len(body))
                if p is not None:
                    p["final"] = final.get(p["sym"]["idx"], p["sym"]["name"]); p["k"] = k
                for n, r in enumerate(o.relocs(scn)):
                    y = r["sym"]
                    if y["scn"] == scn:
                        continue
                    if r["ty"] not in (REL32, DIR32):
                        self.note("reloc_type", "0x%08X+0x%x type 0x%x" % (va, r["offset"], r["ty"])); continue
                    a = struct.unpack_from("<I", body, r["offset"])[0]; ov = struct.unpack_from("<I", orig, r["offset"])[0]
                    S = ((va + r["offset"] + 4 + ov - a) if r["ty"] == REL32 else (ov - a)) & 0xFFFFFFFF
                    if y["scn"] > 0 and y["scn"] in data_scn:
                        if S == (data_scn[y["scn"]]["va"] + y["value"]) & 0xFFFFFFFF:
                            continue
                        self.note("data_local_reference_elsewhere", "0x%08X+0x%x %s" % (va, r["offset"], y["name"]))
                        self.rels.append((k, scn, n, y["name"] + "$d2local", S, r["ty"], True)); continue
                    if y["name"].startswith(".") and y["cls"] == 3:
                        self.note("section_symbol_ref", "0x%08X+0x%x %s" % (va, r["offset"], y["name"])); continue
                    nm = final.get(y["idx"], y["name"])
                    local = y["scn"] > 0 and (y["scn"] in placed_scn or y["scn"] in eh)
                    self.rels.append((k, scn, n, nm, S, r["ty"], local))
            undef_idx = collections.defaultdict(list)
            for y in o.syms:
                if (y["scn"] == 0 and y["cls"] == 2 and y["idx"] not in sym_changes) or sym_changes.get(y["idx"], {}).get("scn") == 0:
                    undef_idx[final.get(y["idx"], y["name"])].append(y["idx"])
            undef = set(undef_idx)
            self.objs.append(dict(path=objp, k=k, sym_changes=sym_changes, sec_flags=sec_flags, sec_names=sec_names, placed=list(placed_scn.values()), src=src,
                                  undef=undef, undef_idx=dict(undef_idx), nsym=o.nsym, sec_aux=sec_aux))
            for scn, e in sorted(eh.items()):
                e["order"] = final[e["key"]["idx"]]; self.eh_pieces.append(e); self.eh_at[e["va"]] = e
        self.problems["eh_pieces_placed"] = len(self.eh_pieces)
        self.problems["eh_piece_bytes_placed"] = sum(e["length"] for e in self.eh_pieces)
        return self.rels

    def place_eh(self, o, k, objp, placed_scn, data_scn):
        import image_data as D
        cand = eh_sections(o, {scn: p["sym"]["name"] for scn, p in placed_scn.items()})
        if not cand:
            return {}
        known = {scn: (p["va"], o.secs[scn - 1]["raw"], True) for scn, p in placed_scn.items()}
        known.update({scn: (dp["va"], dp["sec"]["raw"], False) for scn, dp in data_scn.items() if dp["sec"]["raw"] is not None})
        dsecs = {ds["scn"]: ds for ds in D.data_sections(o) if ds["scn"] not in data_scn and ds["raw"] is not None}
        out = {}; refused = set()
        tv = [a for a, _ in self._eh_taken]
        for rnd in range(8):
            anchors = collections.defaultdict(collections.Counter)
            for scn, (va, body, code) in known.items():
                rels = [r for r in o.relocs(scn) if r["sym"]["scn"] in cand or r["sym"]["scn"] in dsecs] if o.secs[scn - 1]["nrel"] else []
                rels = [r for r in rels if r["ty"] in (REL32, DIR32) and r["sym"]["scn"] != scn]
                if not rels:
                    continue
                orig = self.pe.read(va, len(body)) if code else D.vread(self.pe, va, len(body))
                if not orig or len(orig) != len(body):
                    continue
                for r in rels:
                    anchors[r["sym"]["scn"]][(reloc_target(body, orig, va, r) - r["sym"]["value"]) & 0xFFFFFFFF] += 1
            new = False
            for scn, cnt in sorted(anchors.items()):
                if scn in known or scn in refused or len(cnt) != 1:
                    continue
                va = next(iter(cnt))
                if scn in dsecs:
                    if D.fits(dsecs[scn], va, self.pe):
                        known[scn] = (va, dsecs[scn]["raw"], False); new = True
                    else:
                        refused.add(scn)
                    continue
                n = len(o.secs[scn - 1]["raw"]); pva = placed_scn[cand[scn]]["va"]; why = None
                i = bisect.bisect_right(tv, va + n - 1) - 1
                if not (TEXT_START <= va and va + n <= TEXT_END):
                    why = "outside_text"
                elif (i >= 0 and self._eh_taken[i][0] + self._eh_taken[i][1] > va) or any(e["va"] < va + n and va < e["va"] + e["length"] for e in list(self.eh_pieces) + list(out.values())):
                    why = "overlap"
                else:
                    key = comdat_key(o, scn)
                    why = "no_comdat_symbol" if key is None else eh_piece_check(o, scn, va, self.pe.read(va, n))
                if why:
                    self.note("eh_" + why, "0x%08X -> 0x%08X" % (pva, va)); refused.add(scn); continue
                out[scn] = dict(va=va, length=n, scn=scn, k=k, obj=objp, parent=pva, key=key, defs={})
                known[scn] = (va, o.secs[scn - 1]["raw"], True); new = True
            if not new:
                for scn, cnt in anchors.items():
                    if scn in cand and scn not in known and scn not in refused and len(cnt) > 1:
                        self.note("eh_anchors_disagree", "0x%08X: %s" % (placed_scn[cand[scn]]["va"], ", ".join("0x%08X" % x for x in sorted(cnt))))
                        refused.add(scn)
                break
        for scn in sorted(set(cand) - set(out) - refused):
            self.note("eh_unanchored", "0x%08X .text$x %d B" % (placed_scn[cand[scn]]["va"], len(o.secs[scn - 1]["raw"])))
        return out

    def choose_import_symbols(self, sdk_index=None):
        import image_libs as L
        entries = L.image_imports(self.pe); slot_of_thunk = (self.imports or {}).get("thunks", {})
        if not slot_of_thunk:
            lp = load_json("linker_pieces.json")
            slot_of_thunk = {int(e["va"], 16): int(e["iat_slot"], 16) for r in lp["runs"] for e in r["entries"]}
        obs = collections.defaultdict(collections.Counter)
        for k, scn, n, nm, S, ty, local in self.rels:
            if nm.startswith("__imp_"):
                obs[S][nm[6:]] += 1
            elif ty == REL32 and S in slot_of_thunk:
                obs[slot_of_thunk[S]][nm] += 1
        if self.crt:
            for nm, (S, tys) in list(self.pinned.items()):
                if nm.startswith("__imp_"):
                    obs[S][nm[6:]] += 1
        taken = set(); out = []
        for e in entries:
            valid = [x for x, _ in obs[e["slot"]].most_common() if L.import_name_type(x, e) is not None and x not in taken]
            sym = valid[0] if valid else None
            if sym is None and sdk_index and e["name"] is not None:
                sym = sdk_index.get((e["dll"].upper(), e["name"]))
                sym = sym if sym and sym not in taken else None
            if sym is None:
                if e["name"] is None:
                    sym = "_d2ord_%s_%d" % (e["dll"].split(".")[0], e["ordinal"])
                elif e["name"].startswith(("_", "?", "@")):
                    sym = e["name"]
                else:
                    sym = "_" + e["name"]
                self.note("import_symbol_guessed", "%s!%s -> %s" % (e["dll"], e["name"] or "#%d" % e["ordinal"], sym))
            taken.add(sym); out.append(dict(e, sym=sym, name_type=L.import_name_type(sym, e)))
        self.import_syms = out
        return out

    def set_library_names(self, imports_linked):
        thunk_of_slot = {s: t for t, s in (self.imports or {}).get("thunks", {}).items()}
        for e in self.import_syms:
            imp = "__imp_" + e["sym"]
            if imports_linked:
                self.lib_all |= {imp, e["sym"]}; self.lib_def[imp] = e["slot"]; self.lib_at[e["slot"]] = imp
                t = thunk_of_slot.get(e["slot"])
                self.lib_def[e["sym"]] = t
                if t is not None:
                    self.lib_at[t] = e["sym"]; self.lib_pieces.append((t, 6, e["sym"]))
                for nm in (imp, e["sym"]):
                    old = self.pinned.pop(nm, None)
                    if old and old[0] != self.lib_def[nm]:
                        self.note("pinned_import_elsewhere", "%s 0x%08X" % (nm, old[0]))
            else:
                old = self.pinned.get(imp)
                self.pinned[imp] = (e["slot"], old[1] if old else {DIR32})

    def resolve(self):
        placed_at = {p["final"]: va for va, p in self.placed.items()}
        for c in getattr(self, "data_pieces", ()):
            if isinstance(c["key"][0], str):
                for y in c["sec"]["defs"]:
                    if y["cls"] == 2:
                        placed_at[y["name"]] = c["va"] + y["value"]
        for e in self.eh_pieces:
            placed_at.update(e["defs"])
        starts = {va: p["final"] for va, p in self.placed.items()}
        bodies = sorted([(va, p["length"]) for va, p in self.placed.items()] + [(a, n) for a, n, _ in self.lib_pieces]
                        + [(e["va"], e["length"]) for e in self.eh_pieces])
        bv = [a for a, _ in bodies]; self.addr = {}
        self.in_filler = collections.defaultdict(set); self.alias = {}; self.absolute = {}
        self.inside_defs = collections.defaultdict(list); self.inside_names = set(); self.data_names_at = collections.defaultdict(set)
        self.crt_inside_defs = collections.defaultdict(list)
        self._dv = [c["va"] for c in getattr(self, "data_pieces", ())]
        by_name = collections.defaultdict(lambda: collections.defaultdict(set))
        for k, scn, n, nm, S, ty, local in self.rels:
            by_name[nm][S].add(ty)
        self.addr_bound = collections.defaultdict(list)
        need = collections.defaultdict(set)
        target = {}
        for k, scn, n, nm, S, ty, local in self.rels:
            m = by_name[nm]
            if local and placed_at.get(nm) == S:
                continue
            if nm in self.lib_all or nm in self.pinned:
                want = self.lib_def.get(nm) if nm in self.lib_all else self.pinned[nm][0]
                if want == S:
                    self.addr[nm] = S
                    if nm in self.pinned:
                        need[nm].add(ty); target[nm] = S
                    continue
                self.addr_bound[k].append((scn, n, S)); vn = va_symbol(S)
                need[vn].add(ty); target[vn] = S
                self.problems["bound_library_name"] += 1
                continue
            if len(m) > 1 or (nm in placed_at and placed_at[nm] != S) or (local and placed_at.get(nm) != S):
                self.addr_bound[k].append((scn, n, S)); vn = va_symbol(S)
                need[vn].add(ty); target[vn] = S
                continue
            self.addr[nm] = S
            if nm in placed_at:
                continue
            need[nm].add(ty); target[nm] = S
        for nm, (S, tys) in self.pinned.items():
            need[nm] |= tys; target[nm] = S
        for nm, S in getattr(self, "extra_names", {}).items():
            need[nm].add(DIR32); target[nm] = S
        for nm, m in by_name.items():
            if len(m) > 1:
                self.note("address_conflict", "%s: %s" % (nm, ", ".join("0x%08X" % x for x in sorted(m))))
            elif nm in placed_at and placed_at[nm] not in m:
                self.note("placed_elsewhere", "%s placed 0x%08X, referenced as 0x%08X" % (nm, placed_at[nm], list(m)[0]))
        for nm in (getattr(self, "commons", ()) if self.data_mode else ()):
            cnt = self._names_S.get(nm)
            if cnt and nm not in need:
                need[nm].add(DIR32); target[nm] = cnt.most_common(1)[0][0]
        for nm, S in (getattr(self, "crt_pinned", {}) if self.data_mode else {}).items():
            if nm not in need and getattr(self, "crt_definers", {}).get(nm, 0) <= 1:
                need[nm].add(DIR32); target[nm] = S
        self.problems["address_bound_relocations"] = sum(len(v) for v in self.addr_bound.values())
        self.export_homes = {}
        for nm, S in getattr(self, "export_strong", {}).items():
            need.pop(nm, None); self.export_homes[nm] = S
        need.pop("___ImageBase", None)
        commons = getattr(self, "commons", set()) if self.data_mode else set()
        self.common_defs = {}
        for nm, tys in sorted(need.items()):
            S = target[nm]
            if nm in commons:
                if self.place_common(nm, S):
                    continue
            if S in self.lib_at and self.lib_at[S] != nm and nm not in self.lib_all:
                self.alias[nm] = self.lib_at[S]; continue
            if TEXT_START <= S < TEXT_END:
                if S in starts:
                    if starts[S] != nm:
                        self.alias[nm] = starts[S]
                    continue
                i = bisect.bisect_right(bv, S) - 1
                if i >= 0 and S < bv[i] + bodies[i][1]:
                    pb = self.placed.get(bv[i]) or self.eh_at.get(bv[i])
                    if self.data_mode and pb is not None and "k" in pb:
                        self.define_inside(pb["k"], pb["scn"] if "scn" in pb else pb["sym"]["scn"], S - pb["va"], nm, S); continue
                    if REL32 in tys and DIR32 in tys:
                        self.note("mixed_ref_inside_body", nm)
                    self.absolute[nm] = S - BASE if tys == {REL32} else S
                    self.note("ref_inside_placed_body", "%s 0x%08X" % (nm, S)); continue
                self.in_filler[S].add(nm)
            elif self.data_mode and self.data_home(nm, S):
                continue
            else:
                if REL32 in tys:
                    self.note("rel32_outside_text", "%s 0x%08X" % (nm, S))
                if self.data_mode:
                    self.note("absolute_kept", "%s 0x%08X" % (nm, S))
                self.absolute[nm] = S - BASE if tys == {REL32} else S
        defined = set(placed_at) | set(self.alias) | set(self.absolute) | {n for v in self.in_filler.values() for n in v} | set(self.addr)
        defined |= {n for v in self.data_names_at.values() for n in v} | self.inside_names
        sink = sorted(set().union(*[ob["undef"] for ob in self.objs]) - defined) if self.objs else []
        if self.crt:
            extra = sorted(self.crt["member_undef"] - self.lib_all - defined - set(self.pinned) - set(sink))
            for n in extra:
                self.note("crt_external_sunk", n)
            sink = sorted(set(sink) | set(extra))
        if self.data_mode:
            have = set(self.alias) | {n for v in self.data_names_at.values() for n in v} | self.inside_names | {n for v in self.in_filler.values() for n in v}
            for n in sorted(getattr(self, "commons", set()) - set(self.common_defs) - have):
                self.absolute.pop(n, None)
                if n not in sink:
                    sink.append(n)
                self.note("common_to_sink", n)
            sink = sorted(set(sink))
        self.sink_rename = {n for n in sink if n in self.lib_all and not (self.data_mode and n in getattr(self, "commons", ()))}
        self.sink = sorted((set(sink) - self.sink_rename) | {n + "$d2sink" for n in self.sink_rename})
        for nm, S in self.export_homes.items():
            if self.place_strong(nm, S, starts, bodies, bv) and nm in self.sink:
                self.sink.remove(nm)
        self.problems["sink_names"] = len(self.sink); self.problems["sink_library_names_renamed"] = len(self.sink_rename)

    data_mode = False

    def define_inside(self, k, scn, off, nm, S):
        vn = va_symbol(S)
        if vn not in self.inside_names:
            self.inside_defs[k].append((vn, scn, off)); self.inside_names.add(vn); self.problems["inside_definitions"] += 1
        if nm != vn:
            self.alias[nm] = vn

    def place_strong(self, nm, S, starts, bodies, bv):
        self.alias.pop(nm, None); self.absolute.pop(nm, None)
        if TEXT_START <= S < TEXT_END:
            i = bisect.bisect_right(bv, S) - 1
            if i >= 0 and S < bv[i] + bodies[i][1]:
                pb = self.placed.get(bv[i]) or self.eh_at.get(bv[i])
                if pb is not None and "k" in pb:
                    self.inside_defs[pb["k"]].append((nm, pb["scn"] if "scn" in pb else pb["sym"]["scn"], S - pb["va"])); self.inside_names.add(nm); return True
                self.note("export_not_placeable", nm); return False
            self.in_filler[S].add(nm); return True
        if not self.place_common(nm, S):
            self.note("export_not_placeable", nm); return False
        return True

    def place_common(self, nm, S):
        import image_data as D
        dv = self._dv; i = bisect.bisect_right(dv, S) - 1
        if i >= 0 and S < dv[i] + max(self.data_pieces[i]["size"], 1):
            c = self.data_pieces[i]
            if isinstance(c["key"][0], str):
                self.inside_defs[c["k"]].append((nm, c["key"][1], S - c["va"])); self.inside_names.add(nm); self.common_defs[nm] = S; return True
            self.crt_inside_defs[c["key"][0][1]].append((nm, c["key"][1], S - c["va"])); self.inside_names.add(nm); self.common_defs[nm] = S
            return True
        if D.region_of(self.layout, S, 1):
            self.data_names_at[S].add(nm); self.common_defs[nm] = S; return True
        return False

    def data_home(self, nm, S):
        import image_data as D
        dv = self._dv
        i = bisect.bisect_right(dv, S) - 1
        if i >= 0 and S < dv[i] + max(self.data_pieces[i]["size"], 1):
            c = self.data_pieces[i]
            if isinstance(c["key"][0], str):
                self.define_inside(c["k"], c["key"][1], S - c["va"], nm, S); return True
            if S in self.lib_at and self.lib_at[S] != nm:
                self.alias[nm] = self.lib_at[S]; return True
            vn = va_symbol(S)
            if vn not in self.inside_names:
                self.crt_inside_defs[c["key"][0][1]].append((vn, c["key"][1], S - c["va"])); self.inside_names.add(vn)
                self.problems["inside_library_definitions"] += 1
            if nm != vn:
                self.alias[nm] = vn
            return True
        if D.region_of(self.layout, S, 1):
            self.data_names_at[S].add(nm); return True
        return False


def wine_path(p):
    return "Z:" + os.path.abspath(p).replace("/", "\\")


def write_crt_members(plan, out):
    import image_libs as L
    d = os.path.join(out, "crt"); os.makedirs(d, exist_ok=True)
    for f in glob.glob(os.path.join(d, "*.obj")):
        os.remove(f)
    by_member = collections.defaultdict(dict)
    for c in plan.crt["placements"]:
        by_member[c["sec"]["member"]][c["sec"]["scn"]] = c
    paths = []; pieces = []; notes = collections.Counter()
    for m in (plan.crt["linked"] if plan.data_mode else plan.crt["members"]):
        name, body = plan.crt["bodies"][m]
        extra = crt_data_changes(plan, m, body) if plan.data_mode else None
        data, keys, nt = L.member_rewrite(body, {scn: c["va"] for scn, c in by_member[m].items()}, m, Obj, rewrite_obj, extra)
        notes.update(nt)
        for scn, c in by_member[m].items():
            if scn in keys:
                pieces.append((c["va"], len(c["sec"]["raw"]), keys[scn]))
                if c["sec"]["key"] and c["sec"]["key"]["value"]:
                    plan.key_offset[keys[scn]] = c["sec"]["key"]["value"]
            else:
                plan.note("crt_section_unkeyed", "0x%08X %s" % (c["va"], c["sec"]["mname"]))
        p = os.path.join(d, "m%04d_%s" % (m, name.split("\\")[-1])); _put(p, data); paths.append(p)
    return paths, pieces, notes


def crt_data_changes(plan, m, body):
    import image_data as D
    o = Obj(body); out = dict(sec_names={}, sec_flags={}, sym_changes={}, new_defs=list(plan.crt_inside_defs.get(m, ())))
    for y in o.syms:
        if y["cls"] == 2 and y["scn"] == 0 and y["value"]:
            out["sym_changes"][y["idx"]] = dict(value=0)
    for ds in D.data_sections(o):
        key = (("crt", m), ds["scn"]); scn = ds["scn"]
        dp = plan.data_scn.get(key)
        if dp is not None:
            out["sec_names"][scn] = D.group_name(dp["region"], dp["va"]); out["sec_flags"][scn] = D.group_ch(dp["region"], ds["ch"] & ~SCN_COMDAT)
            continue
        fate = plan.crt_data_fate.get(key)
        grp = ".bss" if ds["raw"] is None else ".data" if ds["ch"] & D.SCN_WRITE and not ds["name"].startswith((".CRT", ".rtc")) else ".rdata"
        if fate in ("empty", "drop", "duplicate", "pinned"):
            out["sec_flags"][scn] = (ds["ch"] | SCN_REMOVE) & ~SCN_COMDAT
            for y in o.syms:
                if y["scn"] == scn and not (y["naux"] and y["cls"] == 3):
                    nn = y["name"] if y["cls"] == 2 else "%s$c%dd" % (y["name"], m)
                    out["sym_changes"][y["idx"]] = dict(name=nn, cls=2, scn=0, value=0)
                    if fate != "duplicate" and nn not in plan.crt_pinned and (y["cls"] != 2 or plan.crt_definers.get(nn, 0) <= 1):
                        plan.crt_sunk.add(nn)
        else:
            out["sec_names"][scn] = grp + "$zzzz"; out["sec_flags"][scn] = (ds["ch"] & ~D.SCN_ALIGN_MASK) | D.ALIGN_1
    return out


def sdk_import_index(sdk_dir, dlls):
    import image_libs as L
    out = {}; files = {os.path.basename(f).lower(): f for f in glob.glob(os.path.join(sdk_dir, "*"))}
    for dll in dlls:
        f = files.get(dll.lower().rsplit(".", 1)[0] + ".lib")
        if not f:
            continue
        for idx, name, at, body in L.ar_members(_get(f)):
            si = L.short_import(body)
            if not si or si["name_type"] == L.NAME_ORDINAL:
                continue
            e = dict(name=None)
            for nt, fn in ((L.NAME_NAME, lambda s: s), (L.NAME_NOPREFIX, lambda s: s[1:]), (L.NAME_UNDECORATE, L.undecorate)):
                if si["name_type"] == nt:
                    out.setdefault((si["dll"].upper(), fn(si["sym"])), si["sym"])
    return out


def write_import_libs(plan, out, linker, runner):
    import image_libs as L
    d = os.path.join(out, "imp"); os.makedirs(os.path.join(d, "seq"), exist_ok=True)
    for f in glob.glob(os.path.join(d, "seq", "*.lib")):
        os.remove(f)
    by_dll = collections.OrderedDict()
    for e in plan.import_syms:
        by_dll.setdefault(e["dll"], []).append(e)
    env = dict(os.environ, WINEDEBUG="-all"); member_of = {}; headers = {}
    for dll, es in by_dll.items():
        base = re.sub(r"[^A-Za-z0-9_]", "_", dll)
        _put(os.path.join(d, base + ".def"), L.def_text(dll, [(e["sym"], e) for e in es]))
        r = subprocess.run(([runner] if runner != "native" else []) + [linker, "/lib", "/NOLOGO", "/MACHINE:X86", "/DEF:%s.def" % base, "/OUT:%s.lib" % base],
                           cwd=d, capture_output=True, text=True, env=env)
        if r.returncode:
            raise RuntimeError("lib /DEF %s failed: %s" % (dll, (r.stdout + r.stderr)[-800:]))
        lp = os.path.join(d, base + ".lib")
        data, n = L.patch_import_lib(_get(lp), {e["sym"]: (e["hint"], e["name_type"]) for e in es})
        if n != len(es):
            plan.note("import_members_unpatched", "%s %d of %d" % (dll, n, len(es)))
        _put(lp, data)
        key_of = {e["sym"]: import_key(e) for e in es}
        for idx, name, at, body in L.ar_members(data):
            si = L.short_import(body)
            if si is None:
                headers.setdefault(dll, []).append((name, body))
            elif si["sym"] in key_of:
                member_of[(dll, key_of[si["sym"]])] = (si["sym"], body)
    paths = []
    for label, data, syms in L.split_import_libs(plan.import_seq["sequence"], member_of, headers, L.ghost_symbol):
        lp = os.path.join(d, "seq", label + ".lib"); _put(lp, data); paths.append(lp)
    plan.import_libs = paths
    return paths


def import_key(e):
    return e["name"] if e["name"] is not None else "#%d" % e["ordinal"]


def write_provenance(plan, out):
    complete = getattr(plan, "complete", False)
    runs = [(a, n, "borrowed" if complete else "placeholder") for a, n in plan.text_fillers]
    runs += [(va, p["length"], "source") for va, p in plan.placed.items()]
    runs += [(e["va"], e["length"], "source") for e in plan.eh_pieces]
    runs += [(c["va"], c["size"], "source" if isinstance(c["key"][0], str) else "library") for c in plan.data_pieces if c["size"]]
    if plan.crt:
        runs += [(c["va"], len(c["sec"]["raw"]), "library") for c in plan.crt["placements"]]
    runs += [(a, n, "linker") for a, n, _ in plan.lib_pieces]
    runs += [(a, n, "copied") for r in ("rdata", "data_init") for a, n in plan.data_fillers.get(r, ())]
    runs += [(a, n, "padding") for r in ("rdata", "data_init") for a, n in getattr(plan, "data_pads", {}).get(r, ())]
    raw_end = (getattr(plan, "layout", None) or {}).get("data_raw_end")
    if raw_end:
        for a, n in getattr(plan, "data_fillers", {}).get("data_bss", ()):
            if a < raw_end:
                runs.append((a, min(a + n, raw_end) - a, "padding"))
    runs += [(a, n, "borrowed" if complete else "copied") for a, n in plan.copied_fields]
    if getattr(plan, "resources", None):
        cls = "resource" if plan.resources.get("from_gen") else "copied"
        runs += [(a, n, cls) for a, n in plan.resources["data_ranges"]]
    ident = getattr(plan, "identity", None)
    file_runs = []
    if ident:
        runs += [(a, n, "library") for a, n in getattr(plan, "pkware_placed", ())]
        runs += [(it["at"], it["length"], it["cls"]) for it, _ in ident.va_items()]
        po = int(ident.params["e_lfanew"], 16)
        for it, _ in ident.items.values():
            if it["where"] == "file_offset":
                file_runs.append((it["at"], it["length"], it["cls"]))
            elif it["where"] == "pe_offset":
                file_runs.append((po + it["at"], it["length"], it["cls"]))
        if "rich_block" in ident.items:
            file_runs.append((0x3C, 4, "stamp"))
    json.dump(dict(note="VA runs [va, length, class], painted in order; bytes no run covers are linker output. file_runs: "
                        "[file offset, length, class] of the headers and the bytes after the last section",
                   runs=[["0x%08X" % a, n, c] for a, n, c in runs], file_runs=[["0x%X" % a, n, c] for a, n, c in file_runs]),
              open(os.path.join(out, "PROVENANCE.json"), "w"))
    if getattr(plan, "data_unplaced_game", None) is not None:
        json.dump(dict(note="game data sections that were not placed, where their references expect them and why", game_unplaced=plan.data_unplaced_game),
                  open(os.path.join(out, "DATA_SECTIONS.json"), "w"), indent=0)


def write_data_fillers(plan, out):
    import image_data as D
    paths = []; plan.data_fillers = {}; plan.data_pads = {}
    origin = getattr(plan, "split_origin", None) or {}
    def start_align(c):
        al = c["sec"].get("align", 1) if isinstance(c.get("sec"), dict) else 1
        off = origin.get(c["key"], (None, 0))[1]
        return min(al, off & -off) if off else al
    for region in ("rdata", "data_init", "data_bss"):
        lo, hi = plan.layout[region]
        pieces = [(c["va"], c["size"]) for c in plan.data_pieces if c["region"] == region and c["size"]]
        g = D.gaps(pieces, lo, hi)
        names = {S: n for S, n in plan.data_names_at.items() if lo <= S < hi}
        pads = set() if region == "data_bss" or getattr(plan, "no_data_pads", False) else D.alignment_pads(
            g, [(c["va"], c["size"], start_align(c)) for c in plan.data_pieces if c["region"] == region and c["size"]],
            plan.pe, plan.base_relocs, names)
        plan.data_fillers[region] = [x for x in g if x not in pads]; plan.data_pads[region] = sorted(pads)
        secs, syms, st = D.filler_sections(region, g, plan.pe, plan.base_relocs, names, zero=pads)
        for k, v in st.items():
            plan.problems["%s_%s" % (region, k)] += v
        if not secs:
            continue
        p = os.path.join(out, "gen", "data_%s.obj" % region); _put(p, coff_write(secs, syms)); paths.append(p)
    return paths


def driver_names(plan):
    import image_libs as L
    sym_of = {(e["dll"], import_key(e)): e["sym"] for e in plan.import_syms}
    out = []; nghost = collections.Counter()
    for dll, kind, key in plan.import_seq["sequence"]:
        if kind == L.GHOST:
            nghost[dll] += 1; out.append("__imp_" + L.ghost_symbol(dll, nghost[dll]))
        elif kind == L.IMPORT:
            out.append("__imp_" + sym_of[(dll, key)])
    return out


def write_inputs(plan, out, linker=None, runner="wine"):
    os.makedirs(os.path.join(out, "objs"), exist_ok=True); os.makedirs(os.path.join(out, "gen"), exist_ok=True)
    for f in glob.glob(os.path.join(out, "objs", "*.obj")) + glob.glob(os.path.join(out, "gen", "*.obj")):
        os.remove(f)
    inputs = []
    for ob in plan.objs:
        d = getattr(plan, "obj_bytes", {}).get(ob["path"]) or _get(ob["path"])
        p = os.path.join(out, "objs", "o%05d.obj" % ob["k"])
        nd = list(getattr(plan, "inside_defs", {}).get(ob["k"], ()))
        dn = [x[0] for x in nd]
        names = sorted({va_symbol(S) for _, _, S in plan.addr_bound.get(ob["k"], ())} - set(dn)); at = {nm: ob["nsym"] + i for i, nm in enumerate(names)}
        at.update({nm: ob["nsym"] + len(names) + j for j, nm in enumerate(dn)})
        rc = {(scn, n): at[va_symbol(S)] for scn, n, S in plan.addr_bound.get(ob["k"], ())}
        sc = {i: dict(v) for i, v in ob["sym_changes"].items()}
        for nm in getattr(plan, "sink_rename", ()):
            for i in ob.get("undef_idx", {}).get(nm, ()):
                sc.setdefault(i, {})["name"] = nm + "$d2sink"
        _put(p, rewrite_obj(d, sc, ob["sec_flags"], rc, names, ob["sec_names"], new_defs=nd, sec_aux=ob.get("sec_aux"))); inputs.append(p)
    pieces = [(va, p["length"], p["final"]) for va, p in plan.placed.items() if "final" in p]
    crt_inputs = []; stats_extra = {}; plan.key_offset = {}; plan.crt_sunk = set()
    for e in plan.eh_pieces:
        pieces.append((e["va"], e["length"], e["order"]))
        if e["key"]["value"]:
            plan.key_offset[e["order"]] = e["key"]["value"]
    if plan.crt:
        crt_inputs, crt_pieces, notes = write_crt_members(plan, out)
        pieces += crt_pieces; stats_extra.update(("crt_" + k, v) for k, v in notes.items())
        stats_extra["crt_member_objects"] = len(crt_inputs)
    pieces += [(t, n, nm) for t, n, nm in plan.lib_pieces]
    gl = gaps([(a, n) for a, n, _ in pieces])
    entry_name = "_d2link_entry"
    order = []; fills = []
    gstarts = [g[0] for g in gl]
    extra = collections.defaultdict(list)
    for S, names in plan.in_filler.items():
        i = bisect.bisect_right(gstarts, S) - 1; g0 = gl[i][0]
        for n in names:
            extra[g0].append((n, S - g0))
    ie = bisect.bisect_right(gstarts, ENTRY) - 1
    if ie >= 0 and gl[ie][0] <= ENTRY < gl[ie][0] + gl[ie][1]:
        extra[gl[ie][0]].append((entry_name, ENTRY - gl[ie][0]))
    else:
        entry_name = [nm for a, n_, nm in pieces if a == ENTRY][0] if any(a == ENTRY for a, _, _ in pieces) else entry_name
    import image_data as D
    plan.copied_fields = []; plan.text_fillers = list(gl)
    if plan.data_mode and not hasattr(plan, "base_relocs"):
        plan.base_relocs = D.base_relocations(plan.pe)
    complete = getattr(plan, "complete", False)
    if complete:
        import finish as C
        if not getattr(plan, "text_pads", None):
            plan.text_pads = C.pad_mask(plan.pe, gl)
    ident = getattr(plan, "identity", None)
    pk_all = sorted(ident.pkware().items()) if ident and plan.data_mode else []
    plan.pkware_placed = []
    for g0, n in gl:
        pk = [(va, b) for va, b in pk_all if va < g0 + n and va + len(b) > g0]
        fname = "_d2fill_%08X" % g0
        p = os.path.join(out, "gen", "fill_%08X.obj" % g0)
        rl = D.text_filler_relocs(g0, n, plan.base_relocs, plan.pe) if plan.data_mode else ()
        if rl:
            plan.copied_fields.extend((g0 + o, 4) for o, _ in rl)
        content = C.filler_bytes(plan.pe.read, g0, n, plan.text_pads) if complete else None
        if pk:
            for va, b in pk:
                if g0 <= va and va + len(b) <= g0 + n:
                    if content is None:
                        content = bytearray([0xCC]) * n
                    content = bytearray(content); content[va - g0:va - g0 + len(b)] = b
                    plan.pkware_placed.append((va, len(b)))
                elif va < g0 + n and va + len(b) > g0:
                    plan.note("pkware_record_split", "0x%08X" % va)
            content = bytes(content) if content is not None else None
        _put(p, filler_obj(fname, n, extra.get(g0, ()), relocs=rl, data=content)); fills.append(p)
    allp = sorted([(g0, "_d2fill_%08X" % g0) for g0, _ in gl] + [(a, nm) for a, _, nm in pieces])
    order = [order_name(nm) for _, nm in allp]
    _put(os.path.join(out, "order.txt"), "\n".join(order) + "\n")
    ko = getattr(plan, "key_offset", {})
    _put(os.path.join(out, "order_va.txt"), "".join("%08X %s\n" % (va + ko.get(nm, 0), nm) for va, nm in allp))
    lay = os.path.join(out, "gen", "layout.obj"); _put(lay, absolute_obj(plan.absolute))
    al = os.path.join(out, "gen", "alias.obj"); _put(al, weak_obj(plan.alias))
    sk = os.path.join(out, "gen", "sink.obj"); _put(sk, absolute_obj({n: 0 for n in set(plan.sink) | plan.crt_sunk}))
    data_objs = write_data_fillers(plan, out) if plan.data_mode else []
    extra_objs = []
    if getattr(plan, "exports", None):
        _put(os.path.join(out, "gen", "exports.def"), plan.exports_def)
    if getattr(plan, "resources", None):
        rp = os.path.join(out, "gen", "rsrc.obj"); _put(rp, plan.resources["obj"]); extra_objs.append(rp)
        _put(os.path.join(out, "gen", "resources.res"), plan.resources["res"])
    libs_linked = bool(plan.crt or plan.imports)
    flags = ["/NOLOGO", "/NODEFAULTLIB", "/SUBSYSTEM:WINDOWS,4.0", "/BASE:0x400000", "/FIXED:NO" if plan.data_mode else "/FIXED", "/FILEALIGN:0x1000",
             "/OPT:REF" if libs_linked else "/OPT:NOREF", "/OPT:NOICF",
             "/INCREMENTAL:NO", "/SAFESEH:NO", "/ORDER:@order.txt", "/ENTRY:" + order_name(entry_name),
             "/MAP:linked.map", "/OUT:linked.exe"] + (["/DEF:gen\\exports.def"] if getattr(plan, "exports", None) else [])
    if libs_linked:
        th = set(n for _, _, n in plan.lib_pieces)
        flags += ["/INCLUDE:" + x[6:] for x in (driver_names(plan) if plan.imports else []) if x[6:] in th]
        flags += ["/INCLUDE:" + nm for _, nm in allp if nm not in th]
    rel = lambda p: os.path.relpath(p, out).replace("/", "\\")
    head = []
    if plan.imports:
        drv = os.path.join(out, "gen", "imports_driver.obj")
        import image_libs as L
        _put(drv, L.driver_obj(driver_names(plan), coff_write, secaux)); head.append(drv)
    tail = list(crt_inputs)
    if plan.crt:
        tail.append(wine_path(plan.crt["path"]))
    if plan.imports:
        tail += write_import_libs(plan, out, linker, runner)
    head += data_objs + extra_objs
    _put(os.path.join(out, "link.rsp"), "\n".join(flags + [rel(p) for p in head] + [rel(lay), rel(al), rel(sk)] + [rel(p) for p in fills] + [rel(p) for p in inputs]
                                              + [p if p.startswith("Z:") else rel(p) for p in tail]) + "\n")
    if plan.data_mode:
        write_provenance(plan, out)
    st = dict(objects=len(inputs), fillers=len(gl), filler_bytes=sum(n for _, n in gl), order_entries=len(order),
              absolutes=len(plan.absolute), aliases=len(plan.alias), sink=len(plan.sink), filler_symbols=sum(len(v) for v in extra.values()),
              eh_pieces=len(plan.eh_pieces), eh_piece_bytes=sum(e["length"] for e in plan.eh_pieces))
    st.update(stats_extra)
    return st


def link(out, linker, runner="wine"):
    env = dict(os.environ, WINEDEBUG="-all")
    exe = os.path.join(out, "linked.exe")
    if os.path.exists(exe):
        os.remove(exe)
    t0 = time.time()
    r = subprocess.run(([runner] if runner != "native" else []) + [linker, "@link.rsp"], cwd=out, capture_output=True, text=True, env=env)
    txt = r.stdout + r.stderr
    _put(os.path.join(out, "link.log"), txt)
    return r.returncode, txt, round(time.time() - t0, 1)


def build_image(s, drop, out, log=print):
    orig = PE(s["image"]); t0 = time.time()
    os.makedirs(out, exist_ok=True)
    crt_lib = os.path.join(s["crt_lib"], "libcmt.lib")
    sdk = s.get("sdk_lib") or None
    linker = s.get("link") or os.path.join(os.path.dirname(s["cl"]), "link.exe"); runner = s.get("runner", "wine")
    plan = Plan(orig, drop, None, log=log, crt_lib=crt_lib, imports=True, sdk_lib=sdk)
    plan.complete = True; plan.eh = True; plan.no_data_pads = False
    plan.choose(); log("placed %d of %d verified functions" % (len(plan.placed), len(plan.funcs)))
    plan.data_mode = True; plan.place_data_split()
    log("data: %d sections placed (%d from game objects, %d from libcmt)" % (len(plan.data_pieces), plan.problems["data_sections_placed_game"], plan.problems["data_sections_placed_crt"]))
    snap = (collections.Counter(plan.problems), {k: list(v) for k, v in plan.examples.items()})
    plan.analyse()
    mid = (collections.Counter(plan.problems), {k: len(v) for k, v in plan.examples.items()})
    dlls = sorted({e["dll"] for e in L_image_imports(orig)})
    plan.choose_import_symbols(sdk_import_index(sdk, dlls) if sdk else None)
    plan.set_library_names(True)
    delta = plan.problems - mid[0]; dex = {k: v[mid[1].get(k, 0):] for k, v in plan.examples.items()}
    plan.problems = collections.Counter(snap[0]) + delta
    plan.examples = collections.defaultdict(list, {k: list(v) for k, v in snap[1].items()})
    for k, v in dex.items():
        plan.examples[k].extend(v)
    plan.analyse()
    import image_libs as L
    plan.import_seq = L.import_pull_sequence(orig)
    if plan.import_seq["correct"] != plan.import_seq["slots"]:
        plan.note("import_sequence_unsolved", "%d of %d" % (plan.import_seq["correct"], plan.import_seq["slots"]))
    import identity as FI
    log(FI.ensure(s["image"]))
    plan.identity = FI.load(orig.data)
    pieces = sorted((c["va"], c["size"]) for c in getattr(plan, "data_pieces", ()) if c["size"])
    for nm, (it, b) in list(plan.identity.items.items()):
        if not nm.startswith("pkware_data_"):
            continue
        a0, a1 = it["at"], it["at"] + it["length"]
        if any(va < a1 and va + n > a0 for va, n in pieces):
            del plan.identity.items[nm]; plan.note("pkware_data_overlaps_placed_data", "0x%08X" % a0)
        else:
            plan.problems["pkware_data_items"] += 1; plan.problems["pkware_data_bytes"] += it["length"]
    prepare_exports_and_resources(plan)
    plan.resolve()
    stats = write_inputs(plan, out, linker, runner)
    log("link inputs: " + ", ".join("%s %s" % kv for kv in sorted(stats.items())))
    rec = dict(drop=drop, placed=len(plan.placed), generated=stats)
    rc, txt, secs = link(out, linker, runner)
    warn = collections.Counter(re.findall(r"(LNK\d{4})", txt))
    rec["link"] = dict(exit_code=rc, seconds=secs, messages=dict(warn))
    log("link: exit %d in %.0f s; %s" % (rc, secs, ", ".join("%s x%d" % kv for kv in sorted(warn.items())) or "no messages"))
    if rc:
        log("\n".join(txt.splitlines()[:40]))
        json.dump(rec, open(os.path.join(out, "PLAN.json"), "w"), indent=1)
        return None
    import image_data as D
    import finish as C
    exe = os.path.join(out, "linked.exe")
    b, old_v, new_v = D.resource_update_header(_get(exe))
    b, pad = D.resource_update_padding(b); _put(exe, b)
    b, regions, probs, info = FI.apply(_get(exe), plan.identity)
    _put(exe, b)
    for x in probs:
        log("identity: problem: " + x)
    rec.update(problems=dict(plan.problems))
    nverified = len(plan.funcs)
    extra = dict(verified_functions=nverified, placed_functions=len(plan.placed), verified_not_placed=nverified - len(plan.placed),
                 eh_pieces_placed=len(plan.eh_pieces), eh_piece_bytes_placed=sum(e["length"] for e in plan.eh_pieces))
    build = C.complete(s["image"], exe, os.path.join(out, "PROVENANCE.json"), out, strict=True, text_pads=plan.text_pads, extra=extra, log=log)
    build["seconds_total"] = round(time.time() - t0, 1)
    json.dump(build, open(os.path.join(out, "BUILD_REPORT.json"), "w"), indent=1)
    rec["placed_from"] = {"0x%08X" % va: plan.obj_source.get(p["obj"]) for va, p in sorted(plan.placed.items())}
    json.dump(rec, open(os.path.join(out, "PLAN.json"), "w"), indent=1)
    return build


def prepare_exports_and_resources(plan):
    import image_data as D
    ex = D.image_exports(plan.pe)
    starts = {va: p["final"] for va, p in plan.placed.items() if "final" in p}
    internal = {}; data_names = set(); plan.extra_names = {}
    plan.export_strong = {}
    for o, nm, va in ex["entries"]:
        if va in starts:
            internal[va] = starts[va]
        elif va in plan.lib_at and not plan.lib_at[va].startswith("__imp_"):
            internal[va] = plan.lib_at[va]
        else:
            internal[va] = va_symbol(va); plan.extra_names[va_symbol(va)] = va
        if nm and "@" in nm and internal[va] != nm:
            internal[va] = nm; plan.export_strong[nm] = va; plan.extra_names.pop(va_symbol(va), None)
        if not (TEXT_START <= va < TEXT_END):
            data_names.add(nm)
    plan.exports = ex; plan.exports_def = D.exports_def(ex["name"], ex["entries"], internal, data_names)
    plan.problems["exports"] = len(ex["entries"])
    ident = getattr(plan, "identity", None)
    if ident and ident.resources:
        R = ident.resources
        if any(tuple(t) != tuple(R["tables"][0]) for t in R["tables"]):
            plan.note("resource_tables_differ", "the directory tables' header fields are not all the root's")
        leaves = [dict(path=[lf["type"], lf["id"], lf["language"]], codepage=lf["codepage"], rva=R["rva"] + lf["offset"],
                       size=lf["size"], data=lf["data"]) for lf in R["leaves"]]
        base = plan.pe.image_base + R["rva"]
        blob, fix, dat = D.rsrc_blob(leaves, lambda lf: lf["data"], tuple(R["tables"][0]), fill=lambda a, n: D.resource_update_fill(n))
        for lf, d_ in zip(sorted(leaves, key=lambda x: x["rva"]), sorted(dat)):
            if lf["rva"] - R["rva"] != d_:
                plan.note("resource_offset_differs", "%s at 0x%X, plan 0x%X" % (lf["path"], d_, lf["rva"] - R["rva"]))
        if len(blob) != R["size"]:
            plan.note("resource_size_differs", "%d B, plan %d B" % (len(blob), R["size"]))
        plan.resources = dict(obj=D.rsrc_object(blob, fix, coff_write, secaux), res=D.res_file(leaves, lambda lf: lf["data"]), size=len(blob),
                              leaves=len(leaves), data_bytes=sum(lf["size"] for lf in leaves), from_gen=True,
                              data_ranges=[(base + d, struct.unpack_from("<I", blob, e + 4)[0]) for e, d in zip(fix, dat)])
        plan.problems["resources"] = len(leaves)
        return
    r = D.image_resources(plan.pe)
    if r:
        base = plan.pe.image_base + r["rva"]
        data_of = lambda lf: plan.pe.read(plan.pe.image_base + lf["rva"], lf["size"])
        blob, fix, dat = D.rsrc_blob(r["leaves"], data_of, r["root"], fill=lambda a, n: D.resource_update_fill(n))
        plan.resources = dict(obj=D.rsrc_object(blob, fix, coff_write, secaux), res=D.res_file(r["leaves"], data_of), size=len(blob),
                              leaves=len(r["leaves"]), data_bytes=sum(lf["size"] for lf in r["leaves"]),
                              data_ranges=[(base + d, struct.unpack_from("<I", blob, e + 4)[0]) for e, d in zip(fix, dat)])
        plan.problems["resources"] = len(r["leaves"])


def L_image_imports(pe):
    import image_libs as L
    return L.image_imports(pe)


BUILT = ("source", "library", "linker", "padding")
BUILD_PARAMETERS = ("stamp", "resource", "signature")


