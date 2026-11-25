#!/usr/bin/env python3
import os, re, sys, json, struct, subprocess, hashlib, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import checker

METHOD = "gl-link-1"
UNIT_LINK_FLAGS = ["/OPT:NOREF", "/OPT:NOICF"]
BASE_LINK = ["/nologo", "/LTCG", "/NODEFAULTLIB", "/SUBSYSTEM:CONSOLE", "/SAFESEH:NO", "/FIXED", "/INCREMENTAL:NO"]
ENTRY = "_d2gl_entry"
SHIFT = 20
PADMIN = 32
DATA_PAD = 0x10000
EH_CODE = ("__ehhandler$", "__unwindfunclet$", "__catch$")
EH_DATA = ("__ehfuncinfo$", "__unwindtable$", "__tryblocktable$", "__catchsym$")
REL32, DIR32 = 0x14, 0x06
CODE_CH = 0x60501020
CODEX_CH = 0x60501020
DATA_CH = 0x40301040
XDATA_CH = 0x40300040


class GLError(Exception):
    def __init__(self, code, msg, detail=None):
        Exception.__init__(self, "%s: %s" % (code, msg)); self.code = code; self.msg = msg; self.detail = detail or {}


NOROOT_DIRECTIVE = re.compile(r"^//\s*build:\s*ltcg-noroot\s+(\S+)\s*$")


def parse_noroot(src):
    out = []
    for ln in src.splitlines():
        m = NOROOT_DIRECTIVE.match(ln.strip())
        if m and m.group(1) not in out:
            out.append(m.group(1))
    return out


def noroot_problems(src):
    defs, decls, symbols = checker.parse_markers(src)
    refs = ref_addresses(src)
    out = []
    for nm in parse_noroot(src):
        last = nm.split("::")[-1]
        if nm in defs or last in defs and "::" not in nm:
            why = "a `// 0x%08X` definition marker" % defs.get(nm, defs.get(last))
        elif nm in symbols:
            why = "a `// build: symbol` line (0x%08X)" % symbols[nm]
        elif checker.SUB_VA.match(last) or (nm.startswith("?") and checker.sub_va_of(nm) is not None):
            why = "a sub_<VA> name"
        elif nm in refs or last in refs:
            why = "a `// @ref` address"
        else:
            continue
        out.append("`// build: ltcg-noroot %s` names a function of the image (%s): only a context body or a body "
                   "with no address may be left out of the LTCG roots, never the target or a marked function" % (nm, why))
    return out


def _wb(path, data):
    with open(path, "wb" if isinstance(data, bytes) else "w") as f:
        f.write(data)


def _lines(path):
    with open(path, errors="replace") as f:
        return f.read().splitlines()


def sha256_file(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def linker(settings, cfg):
    p = os.path.expanduser(settings.get("link") or os.path.join(os.path.dirname(settings["cl"]), "link.exe"))
    if not os.path.exists(p):
        raise GLError("TOOLCHAIN", "link.exe not found at %s" % p)
    h = sha256_file(p)
    want = cfg["toolchain"].get("link_sha256")
    if want and h != want:
        raise GLError("TOOLCHAIN", "link.exe hashes to %s, expected %s (config.json toolchain.link_sha256)" % (h[:16], want[:16]))
    return p, settings.get("runner", "native"), h


def _env():
    env = dict(os.environ); env.setdefault("WINEDEBUG", "-all")
    for k in ("LINK", "_LINK_", "LIB", "CL", "_CL_"):
        env.pop(k, None)
    return env


class Linker(object):
    def __init__(self, path, runner="wine", log=None):
        self.path, self.runner, self.log = path, runner, log or (lambda *a: None)
        self.count = 0

    def __call__(self, wd, args):
        cmd = ([self.path] if self.runner == "native" else [self.runner, self.path]) + list(args)
        self.count += 1
        r = subprocess.run(cmd, cwd=wd, capture_output=True, text=True, env=_env())
        return r.returncode, r.stdout + r.stderr


UNRESOLVED = re.compile(r"unresolved external symbol (?:\"[^\"]*\" \()?(\S+?)\)?\s*(?:referenced.*)?$", re.M)


def unresolved_of(txt):
    return sorted(set(n for n in UNRESOLVED.findall(txt) if n != ENTRY))


def _linker_module():
    import link_exe
    return link_exe


def entry_obj():
    R = _linker_module()
    return R.filler_obj(ENTRY, 16)


def pad_obj(size):
    R = _linker_module()
    secs = [dict(name=".rdata", data=b"\0" * size, ch=0x40100040), dict(name=".data", data=b"\0" * size, ch=0xC0100040),
            dict(name=".bss", data=b"", size=size, ch=0xC0100080)]
    syms = [dict(name=s["name"], value=0, scn=i + 1, cls=3, aux=[R.secaux(size)]) for i, s in enumerate(secs)]
    return R.coff_write(secs, syms)


MAP_LINE = re.compile(r"^\s+([0-9a-f]{4}):([0-9a-f]{8})\s+(\S+)\s+([0-9a-f]{8})\s+(f?)\s*(i?)\s*(.*)$")


def parse_map(path):
    out = []; static = False
    for ln in _lines(path):
        if ln.strip().startswith("Static symbols"):
            static = True; continue
        m = MAP_LINE.match(ln)
        if m:
            out.append(dict(scn=int(m.group(1), 16), va=int(m.group(4), 16), name=m.group(3), static=static,
                            func=m.group(5) == "f", obj=m.group(7).strip()))
    return out


CONTRIB_LINE = re.compile(r"^\s+([0-9a-f]{4}):([0-9a-f]{8})\s+([0-9a-f]{8})H\s+(\S+)\s+(CODE|DATA)\s*$")


def parse_contribs(path, img):
    out = []
    for ln in _lines(path):
        m = CONTRIB_LINE.match(ln)
        if m:
            k = int(m.group(1), 16)
            if 1 <= k <= len(img.secs):
                out.append((img.secs[k - 1][1] + int(m.group(2), 16), int(m.group(3), 16), m.group(4)))
    return sorted(out)


class Image(object):
    def __init__(self, path):
        with open(path, "rb") as f:
            d = self.d = f.read()
        pe = struct.unpack_from("<I", d, 0x3C)[0]
        nsec = struct.unpack_from("<H", d, pe + 6)[0]; opt = pe + 24; osz = struct.unpack_from("<H", d, pe + 20)[0]
        self.base = struct.unpack_from("<I", d, opt + 28)[0]; self.secs = []
        for i in range(nsec):
            o = opt + osz + 40 * i
            nm, vs, va, rs, rp = struct.unpack_from("<8sIIII", d, o)
            self.secs.append((nm.rstrip(b"\0").decode("latin-1"), self.base + va, max(vs, rs), rp, rs))

    def read(self, va, n):
        for nm, sva, size, rp, rs in self.secs:
            if sva <= va and va + n <= sva + size:
                o = va - sva; b = self.d[rp + o: rp + min(rs, o + n)]
                return b + b"\0" * (n - len(b))
        return None

    def section_of(self, va):
        for nm, sva, size, rp, rs in self.secs:
            if sva <= va < sva + size:
                return nm
        return None


def literal_size(n):
    m = re.match(r"^\?\?_C@_[01]([0-9]|[A-P]+@)", n)
    if m:
        t = m.group(1)
        return int(t) + 1 if t.isdigit() else int("".join("%x" % (ord(c) - 65) for c in t[:-1]), 16)
    m = re.match(r"^__(real|xmm|mask)@([0-9a-f]+)$", n)
    return len(m.group(2)) // 2 if m else None


class Resolver(object):
    def __init__(self, src, iat=None, crt=None, extra=None):
        self.defs, self.decls, self.symbols = checker.parse_markers(src)
        self.iat = iat or {}; self.crt = crt or {}; self.extra = extra or {}
        by = collections.defaultdict(set)
        for slot, nm in self.iat.items():
            by[nm.split("!", 1)[1]].add(slot)
        self.iat_by_name = by

    def resolve(self, name):
        if name in self.extra:
            return self.extra[name], "given"
        m = checker.marker_for(name, self.decls, self.symbols, self.defs)
        if m is checker.AMBIGUOUS:
            return None, "markers of the same precedence give %s different addresses" % name
        if m is not None:
            return m, "marker"
        sv = checker.sub_va_of(name)
        if sv is not None:
            return sv, "name"
        if name.startswith("__imp_"):
            c = checker.c_source_name(name[6:]) or name[6:]
            slots = self.iat_by_name.get(c, set())
            if len(slots) == 1:
                return next(iter(slots)), "import"
            return None, "%s: %s in the IAT" % (name, "no entry" if not slots else "%d entries" % len(slots))
        if name in self.crt:
            return self.crt[name], "crt"
        return None, "%s has no marker, no sub_<VA> name and is not a C runtime or import symbol" % name


def crt_table(pe, lib_path, cache_dir=None, log=None):
    key = hashlib.sha256((sha256_file(lib_path) + hashlib.sha256(pe.data).hexdigest()).encode()).hexdigest()[:24]
    cp = os.path.join(cache_dir, "gl_crt_%s.json" % key) if cache_dir else None
    if cp and os.path.exists(cp):
        with open(cp) as f:
            return json.load(f)
    R = _linker_module()
    p = R.Plan.__new__(R.Plan); p.pe = pe; p.problems = collections.Counter(); p.log = log or (lambda *a: None)
    p.setup_crt(lib_path)
    seen = collections.defaultdict(set)
    for c in p.crt["chosen"]:
        if not c["strong"]:
            continue
        for nm, v in c["sec"]["defs"]:
            seen[nm].add(c["va"] + v)
        for nm, a in c["targets"]:
            seen[nm].add(a)
    out = {k: next(iter(v)) for k, v in seen.items() if len(v) == 1}
    if cp:
        os.makedirs(cache_dir, exist_ok=True); _wb(cp, json.dumps(out, indent=0, sort_keys=True))
    return out


def source_externals(src):
    depth = 0; stmt = []; out = []; defined = set(); first = None
    lines = src.splitlines()
    for no, ln in enumerate(lines, 1):
        code = re.sub(r"//.*$", "", ln)
        code = re.sub(r'"(?:\\.|[^"\\])*"', '""', code)
        if code.strip().startswith("#"):
            continue
        mk = re.search(r"//\s*(0x[0-9A-Fa-f]{8})\s*$", ln)
        for ch in code:
            if depth == 0:
                stmt.append(ch)
            if ch == "{":
                if depth == 0:
                    head = "".join(stmt[:-1])
                    nm = checker.decl_name(head, function_only=True)
                    if nm and re.search(r"\)\s*(const\s*)?$", head.strip()):
                        defined.add(nm)
                    stmt = []
                depth += 1
            elif ch == "}":
                depth = max(0, depth - 1)
                if depth == 0:
                    stmt = []
            elif ch == ";" and depth == 0:
                text = "".join(stmt).strip(); stmt = []
                if not text or re.match(r"^(typedef|using|namespace|template|struct|class|union|enum)\b", text):
                    continue
                if "(" not in text and not re.match(r"^extern\b", text):
                    continue
                nm = checker.decl_name(text)
                if nm:
                    out.append((nm, int(mk.group(1), 16) if mk else None, no, "__declspec(dllimport)" in text))
    return [(n, v, l, imp) for n, v, l, imp in out if n not in defined], defined


def dry_resolve(src, crt, iat):
    ext, _ = source_externals(src)
    by_iat = collections.defaultdict(set)
    for slot, nm in (iat or {}).items():
        by_iat[nm.split("!", 1)[1]].add(slot)
    ok, bad = [], []
    for nm, va, line, imp in ext:
        if va is not None:
            ok.append((nm, va, "marker")); continue
        sv = checker.sub_va_of(nm)
        if sv is not None:
            ok.append((nm, sv, "name")); continue
        if imp:
            s = by_iat.get(nm, set())
            if len(s) == 1:
                ok.append((nm, next(iter(s)), "import")); continue
            bad.append((nm, line, "dllimport %s is %s in the IAT" % (nm, "missing" if not s else "ambiguous"))); continue
        cands = [k for k in (crt or {}) if (checker.c_source_name(k) == nm or checker.undec(k) == nm)]
        if nm in checker.CRT_C and cands:
            ok.append((nm, crt[cands[0]], "crt")); continue
        bad.append((nm, line, "no marker on its declaration and not a C runtime function the CRT table has"))
    return ok, bad


class Program(object):

    def __init__(self, wd, objs, resolver, link, link_flags, log=None, roots=None, noroot=None, src=""):
        self.wd, self.objs, self.R, self.link = wd, list(objs), resolver, link
        self.flags = list(link_flags); self.log = log or (lambda *a: None)
        self.extra_roots = list(roots or [])
        self.noroot = list(noroot or [])
        self.refs = ref_addresses(src) if src else {}
        self.noroot_symbols = []
        self.absolute = {}; self.how = {}; self.links = []

    def _link(self, tag, objs, extra, want_ok=True, inventory=False):
        flags = self.flags
        if inventory:
            flags = [f for f in flags if f.upper() not in ("/OPT:REF", "/OPT:NOREF")] + ["/OPT:NOREF"]
        args = BASE_LINK + flags + extra + ["/ENTRY:" + ENTRY[1:], "/MAP:%s.map" % tag, "/OUT:%s.exe" % tag] + objs
        rc, txt = self.link(self.wd, args)
        self.links.append(dict(tag=tag, args=[a for a in args], exit_code=rc))
        if want_ok and rc:
            raise GLError("LINK_ERROR", "link %s failed: %s" % (tag, txt.strip()[-1500:]))
        return rc, txt

    def _write(self, name, data):
        with open(os.path.join(self.wd, name), "wb") as f:
            f.write(data)
        return name

    def _abs_obj(self, tag, shift=False):
        R = _linker_module()
        names = sorted(self.absolute)
        if shift:
            self.shift_of = {n: ((i + 1) << SHIFT) for i, n in enumerate(names)}
        vals = {n: (self.absolute[n] + (self.shift_of[n] if shift else 0)) & 0xFFFFFFFF for n in names}
        return self._write("%s_abs.obj" % tag, R.absolute_obj(vals))

    def _resolve_more(self, names):
        bad = []
        for n in names:
            if n in self.absolute:
                continue
            va, how = self.R.resolve(n)
            if va is None:
                bad.append((n, how))
            else:
                self.absolute[n] = va; self.how[n] = how
        if bad:
            raise GLError("UNRESOLVED_EXTERNAL", "; ".join(w for _, w in bad), dict(unresolved=[n for n, _ in bad]))

    def build(self):
        self._write("entry.obj", entry_obj())
        base = self.objs + ["entry.obj"]
        roots = []
        for rnd in range(6):
            absobj = self._abs_obj("inv")
            rc, txt = self._link("inv%d" % rnd, base + [absobj], ["/INCLUDE:" + r for r in roots], want_ok=False, inventory=True)
            un = unresolved_of(txt)
            if un:
                self._resolve_more(un); continue
            if rc:
                raise GLError("LINK_ERROR", txt.strip()[-1500:])
            mp = parse_map(os.path.join(self.wd, "inv%d.map" % rnd))
            allpubs = {e["name"] for e in mp if e["scn"] == 1 and not e["static"] and e["obj"] != "entry.obj"
                       and not e["name"].startswith("_d2gl")}
            kept = self._noroot_of(allpubs)
            pubs = sorted((allpubs - set(kept)) | set(self.extra_roots))
            if pubs == roots:
                break
            roots = pubs
        else:
            raise GLError("LINK_ERROR", "the inventory did not settle")
        unused = [nm for nm in self.noroot if not any(checker.context_named(y, [nm]) for y in self.noroot_symbols)]
        if unused:
            raise GLError("NOROOT_REFUSED", "`// build: ltcg-noroot` names no public function of the program: %s" % ", ".join(unused),
                          dict(unused=unused))
        self.roots = roots
        inc = ["/INCLUDE:" + r for r in roots]
        absA = self._abs_obj("A"); absB = self._abs_obj("B", shift=True)
        self._write("pad.obj", pad_obj(DATA_PAD))
        self._link("A", base + [absA], inc)
        self._link("B", base + [absB], inc)
        self._link("C", base + [absA], inc + ["/FUNCTIONPADMIN:%d" % PADMIN])
        self._link("D", ["pad.obj"] + base + [absA], inc)
        self.img = {k: Image(os.path.join(self.wd, k + ".exe")) for k in "ABCD"}
        self.map = {k: parse_map(os.path.join(self.wd, k + ".map")) for k in "ABCD"}
        self.contribs = {k: parse_contribs(os.path.join(self.wd, k + ".map"), self.img[k]) for k in "ABCD"}
        self._index()
        return self

    def _noroot_of(self, pubs):
        if not self.noroot:
            return []
        kept = sorted(y for y in pubs if checker.context_named(y, self.noroot))
        bad = []
        for y in kept:
            va, how = self.R.resolve(y)
            if va is None and checker.undec(y) in self.refs:
                va, how = self.refs[checker.undec(y)], "@ref"
            if va is not None and how in ("marker", "name", "given", "@ref"):
                bad.append("%s (0x%08X by %s)" % (y, va, how))
        if bad:
            raise GLError("NOROOT_REFUSED", "`// build: ltcg-noroot` names a function of the image: %s; only a context body "
                          "or a body with no address may be left out of the LTCG roots" % "; ".join(bad), dict(refused=bad))
        self.noroot_symbols = sorted(set(self.noroot_symbols) | set(kept))
        return kept


    def _index(self):
        self.pos = {}
        for k, mp in self.map.items():
            self.pos[k] = {e["name"]: e["va"] for e in mp if e["scn"] > 0}
        A = self.map["A"]
        self.code_names = [e["name"] for e in A if e["scn"] == 1 and e["obj"] != "entry.obj"]
        self.static = {e["name"] for e in A if e["static"]}
        self.text_scn = 1
        allpos = sorted(set(e["va"] for e in A if e["scn"] > 0))
        self.starts = allpos
        by = collections.defaultdict(list)
        for e in A:
            if e["scn"] == 1 and e["obj"] != "entry.obj":
                by[e["va"]].append(e["name"])
        self.code_at = dict(by)
        self.data_syms = sorted((e["va"], e["name"]) for e in A if e["scn"] > 1)
        self.extent = {}
        for k in "ABCD":
            ps = sorted(set(v for v in self.pos[k].values()))
            img = self.img[k]
            ext = {}
            for e in self.map[k]:
                if e["scn"] != 1 or e["obj"] == "entry.obj":
                    continue
                a = e["va"]; i = ps.index(a); nxt = ps[i + 1] if i + 1 < len(ps) else a + 0x100000
                c = self.contrib_of(k, a)
                if c is None:
                    raise GLError("LAYOUT", "%s at 0x%08X is in no section contribution of image %s" % (e["name"], a, k))
                nxt = min(nxt, c[0] + c[1])
                raw = img.read(a, nxt - a) or b""
                ext[e["name"]] = len(raw.rstrip(b"\xcc"))
            self.extent[k] = ext
        for nm in self.code_names:
            sizes = {k: self.extent[k].get(nm) for k in "ABCD"}
            if len(set(sizes.values())) != 1:
                raise GLError("LAYOUT", "%s measures %s across the images (codegen or extent changed)" % (nm, sizes))
        self.moveC = {nm: (self.pos["C"][nm] - self.pos["A"][nm]) for nm in self.code_names}

    def contrib_of(self, k, va):
        for a, n, nm in self.contribs[k]:
            if a <= va < a + n:
                return (a, n, nm)
        return None

    def _eh_funcinfo(self, handler, st):
        F = handler[len("__ehhandler$"):]; fi = "__ehfuncinfo$" + F
        if fi in self.pos["A"]:
            return fi
        if not hasattr(self, "eh_size"):
            self.eh_size = {}; self.eh_children = {}
        kids = None
        for k in "ABCD":
            v = struct.unpack_from("<I", self.img[k].read(self.pos[k][handler] + st, 4), 0)[0]
            size, tabs = funcinfo_layout(self.img[k], v)
            self.pos[k][fi] = v; self.eh_size[fi] = size
            names = []; j = 0
            for pref, tva, tsize in tabs:
                nm = pref + F + ("$%d" % j if pref == "__catchsym$" else "")
                if pref == "__catchsym$":
                    j += 1
                self.pos[k][nm] = tva; self.eh_size[nm] = tsize; names.append(nm)
            kids = names
        self.eh_children[fi] = kids
        for nm in [fi] + kids:
            self.data_syms.append((self.pos["A"][nm], nm))
        self.data_syms.sort()
        return fi

    def canonical(self, names, prefer=None):
        for n in names:
            if prefer and n in prefer:
                return n
        for n in names:
            va, how = self.R.resolve(n)
            if va is not None and how == "marker":
                return n
        return names[0]

    def code_piece_at(self, T):
        best = None
        for a, names in self.code_at.items():
            n = names[0]
            if a <= T < a + max(self.extent["A"][n], 1):
                best = (a, names)
        if best is None:
            return None
        return best[1], T - best[0]

    def data_piece_at(self, T):
        lo = None
        for a, n in self.data_syms:
            if a <= T:
                lo = (a, n)
            else:
                break
        return lo


    def lift_code(self, name):
        A, B, C, D = (self.img[k] for k in "ABCD")
        pa = self.pos["A"][name]; n = self.extent["A"][name]
        ba = bytearray(A.read(pa, n)); bb = B.read(pa, n); bc = C.read(self.pos["C"][name], n); bd = D.read(self.pos["D"][name], n)
        if self.pos["B"].get(name) != pa:
            raise GLError("LAYOUT", "%s moved between images A and B" % name)
        mf = self.moveC[name]
        by_shift = {v: k for k, v in self.shift_of.items()}
        relocs = []; covered = 0; i = 0
        u32 = lambda b, o: struct.unpack_from("<I", b, o)[0]

        def classify(st):
            va_ = u32(ba, st); dB = (u32(bb, st) - va_) & 0xFFFFFFFF; dC = (u32(bc, st) - va_) & 0xFFFFFFFF; dD = (u32(bd, st) - va_) & 0xFFFFFFFF
            P = pa + st; out = []
            if dB:
                k = by_shift.get(dB)
                if k is None or dD:
                    return []
                S = self.absolute[k]
                if dC == 0:
                    out.append((st, DIR32, k, checker.signed32((va_ - S) & 0xFFFFFFFF), "abs"))
                if mf and dC == (-mf) & 0xFFFFFFFF:
                    rva_next = P + 4 - A.base
                    out.append((st, REL32, k, checker.signed32((va_ + rva_next - S) & 0xFFFFFFFF), "abs"))
                return out
            if dD:
                T = va_
                if name.startswith("__ehhandler$") and not any(a == T for a, _ in self.data_syms):
                    try:
                        self._eh_funcinfo(name, st)
                    except GLError:
                        return []
                lo = self.data_piece_at(T)
                if lo is None:
                    return []
                a, dn = lo
                ca, cb = self.contrib_of("A", a), self.contrib_of("A", T)
                if ca is None or ca != cb:
                    return []
                if self.pos["D"].get(dn, -1) - a != dD or (self.pos["C"].get(dn, -1) - a) & 0xFFFFFFFF != dC:
                    return []
                return [(st, DIR32, dn, T - a, "data")]
            if dC:
                T = va_; hit = self.code_piece_at(T)
                if hit:
                    names, off = hit; g = names[0]
                    if self.moveC[g] & 0xFFFFFFFF == dC:
                        out.append((st, DIR32, name if name in names else self.canonical(names), off, "code"))
                T2 = (P + 4 + va_) & 0xFFFFFFFF; hit = self.code_piece_at(T2)
                if hit:
                    names, off = hit; g = names[0]
                    if name not in names and (self.moveC[g] - mf) & 0xFFFFFFFF == dC:
                        out.append((st, REL32, self.canonical(names), off, "code"))
                return out
            return []

        while i < n:
            if ba[i] == bb[i] and ba[i] == bc[i] and ba[i] == bd[i]:
                i += 1; continue
            hits = []
            for st in range(max(covered, i - 3), i + 1):
                if st + 4 > n:
                    continue
                hits.extend(classify(st))
            hits = [h for h in hits if all(ba[j] == bb[j] == bc[j] == bd[j] for j in range(covered, h[0]))]
            if not hits:
                raise GLError("UNEXPLAINED_CHANGE", "%s+0x%x: a changed field none of the classes explains" % (name, i))
            if len(set((h[0], h[1], h[2]) for h in hits)) > 1:
                raise GLError("AMBIGUOUS_FIELD", "%s+0x%x: %d readings of one field" % (name, i, len(hits)))
            st, ty, sym, add, kind = hits[0]
            relocs.append((st, ty, sym, add, kind)); covered = st + 4; i = st + 4
        if mf == 0 and any(k == "abs" for _, _, _, _, k in relocs):
            raise GLError("LAYOUT", "%s did not move in image C; its REL32 / DIR32 readings are not proved" % name)
        return bytes(ba), relocs

    def lift_data(self, name, size):
        A, B, C, D = (self.img[k] for k in "ABCD")
        pa = self.pos["A"][name]
        ba = bytearray(A.read(pa, size)); bb = B.read(pa, size); bc = C.read(self.pos["C"][name], size); bd = D.read(self.pos["D"][name], size)
        by_shift = {v: k for k, v in self.shift_of.items()}
        relocs = []; i = 0; u32 = lambda b, o: struct.unpack_from("<I", b, o)[0]
        mD = self.pos["D"][name] - pa; mC = self.pos["C"][name] - pa
        while i + 4 <= size:
            va_ = u32(ba, i); dB = (u32(bb, i) - va_) & 0xFFFFFFFF; dC = (u32(bc, i) - va_) & 0xFFFFFFFF; dD = (u32(bd, i) - va_) & 0xFFFFFFFF
            if not (dB or dC or dD):
                i += 4; continue
            if dB:
                k = by_shift.get(dB)
                if k is None:
                    raise GLError("UNEXPLAINED_CHANGE", "%s+0x%x" % (name, i))
                relocs.append((i, DIR32, k, checker.signed32((va_ - self.absolute[k]) & 0xFFFFFFFF), "abs"))
            elif dD:
                lo = self.data_piece_at(va_)
                if lo is None or self.pos["D"][lo[1]] - lo[0] != dD:
                    raise GLError("UNEXPLAINED_CHANGE", "%s+0x%x" % (name, i))
                relocs.append((i, DIR32, lo[1], va_ - lo[0], "data"))
            else:
                hit = self.code_piece_at(va_)
                if not hit or self.moveC[hit[0][0]] & 0xFFFFFFFF != dC:
                    raise GLError("UNEXPLAINED_CHANGE", "%s+0x%x" % (name, i))
                relocs.append((i, DIR32, self.canonical(hit[0]), hit[1], "code"))
            i += 4
        return bytes(ba), relocs


def funcinfo_layout(img, va):
    h = img.read(va, 0x24)
    if h is None:
        raise GLError("UNSUPPORTED", "no FuncInfo at 0x%08X" % va)
    magic, max_state, p_unwind, n_try, p_try, n_ip, p_ip = struct.unpack_from("<7I", h, 0)
    if magic not in (0x19930520, 0x19930521, 0x19930522):
        raise GLError("UNSUPPORTED", "FuncInfo magic 0x%08X at 0x%08X" % (magic, va))
    size = {0x19930520: 0x1C, 0x19930521: 0x20, 0x19930522: 0x24}[magic]
    if magic >= 0x19930521 and struct.unpack_from("<I", h, 0x1C)[0]:
        raise GLError("UNSUPPORTED", "FuncInfo at 0x%08X has an ES type list" % va)
    if n_ip or p_ip:
        raise GLError("UNSUPPORTED", "FuncInfo at 0x%08X has an IP-to-state map" % va)
    out = []
    if max_state:
        out.append(("__unwindtable$", p_unwind, 8 * max_state))
    if n_try:
        out.append(("__tryblocktable$", p_try, 20 * n_try))
        tb = img.read(p_try, 20 * n_try)
        for j in range(n_try):
            n_c, p_c = struct.unpack_from("<II", tb, 20 * j + 12)
            if n_c:
                out.append(("__catchsym$", p_c, 16 * n_c))
    return size, out


def lift(prog, want=None, log=None):
    R = _linker_module()
    groups = collections.OrderedDict()
    for a in sorted(prog.code_at):
        names = prog.code_at[a]
        if all(n.startswith(EH_CODE) for n in names):
            continue
        c = prog.canonical(names)
        groups[c] = [c] + [n for n in names if n != c]
    todo = list(groups) if want is None else [g for g in groups if set(groups[g]) & set(want)]
    pieces = collections.OrderedDict()
    pending = list(todo)
    eh_code_names = {n for n in prog.code_names if n.startswith(EH_CODE)}
    while pending:
        nm = pending.pop(0)
        if nm in pieces:
            continue
        if nm in groups or nm in eh_code_names:
            data, rels = prog.lift_code(nm)
            kind = "ehcode" if nm.startswith(EH_CODE) else "func"
            pieces[nm] = dict(kind=kind, data=data, relocs=rels, aliases=groups.get(nm, [nm]))
        elif nm.startswith(EH_DATA):
            size = prog.eh_size[nm]
            data, rels = prog.lift_data(nm, size)
            pieces[nm] = dict(kind="ehdata", data=data, relocs=rels, aliases=[nm])
        elif nm.startswith(checker.LITERALS):
            size = literal_size(nm)
            if size is None:
                raise GLError("UNSUPPORTED", "literal %s has no size in its name" % nm)
            pieces[nm] = dict(kind="literal", data=prog.img["A"].read(prog.pos["A"][nm], size), relocs=[], aliases=[nm])
        else:
            continue
        for st, ty, sym, add, kind in pieces[nm]["relocs"]:
            if kind == "code" and sym not in pieces and (sym in groups or sym in eh_code_names):
                if sym.startswith(EH_CODE) or want is None:
                    pending.append(sym)
            elif kind == "data" and sym not in pieces:
                if sym.startswith("__ehfuncinfo$"):
                    _eh_tables(prog, sym)
                    pending.append(sym)
                    pending.extend(t for t in prog.eh_children.get(sym, []))
                elif sym.startswith(checker.LITERALS):
                    pending.append(sym)
    order = list(pieces)
    secs = []; syms = []; index = {}
    sec_of = {}
    for nm in order:
        p = pieces[nm]
        sname = {"func": ".text", "ehcode": ".text$x", "ehdata": ".xdata$x", "literal": ".rdata"}[p["kind"]]
        ch = {"func": CODE_CH, "ehcode": CODEX_CH, "ehdata": XDATA_CH, "literal": DATA_CH}[p["kind"]]
        secs.append(dict(name=sname, data=p["data"], ch=ch, relocs=[])); sec_of[nm] = len(secs)
    for nm in order:
        p = pieces[nm]; scn = sec_of[nm]
        sel = 2 if p["kind"] in ("func", "literal") else 0
        syms.append(dict(name=secs[scn - 1]["name"], value=0, scn=scn, cls=3, aux=[R.secaux(len(p["data"]), len(p["relocs"]), sel)]))
        for a in p["aliases"]:
            st = a in prog.static or p["kind"] in ("ehcode", "ehdata")
            index[a] = sum(1 + len(y.get("aux", [])) for y in syms)
            syms.append(dict(name=a, value=0, scn=scn, type=0x20 if p["kind"] in ("func", "ehcode") else 0, cls=3 if st else 2))
    undef = sorted({sym for p in pieces.values() for _, _, sym, _, _ in p["relocs"] if sym not in index})
    for u in undef:
        index[u] = sum(1 + len(y.get("aux", [])) for y in syms)
        syms.append(dict(name=u, value=0, scn=0, type=0x20 if prog.absolute.get(u) is not None and u not in dict((n, 1) for _, n in prog.data_syms) else 0, cls=2))
    for nm in order:
        p = pieces[nm]; sec = secs[sec_of[nm] - 1]; data = bytearray(p["data"])
        for st, ty, sym, add, kind in sorted(p["relocs"]):
            struct.pack_into("<i", data, st, add)
            sec["relocs"].append((st, index[sym], ty))
        sec["data"] = bytes(data)
    obj = R.coff_write(secs, syms)
    inv = dict(pieces={nm: dict(kind=p["kind"], size=len(p["data"]), aliases=p["aliases"], relocations=len(p["relocs"]),
                                static=nm in prog.static, image_a="0x%08X" % prog.pos["A"][nm])
                       for nm, p in pieces.items()},
               externals={n: "0x%08X" % v for n, v in sorted(prog.absolute.items())}, external_how=dict(sorted(prog.how.items())),
               roots=prog.roots)
    return obj, inv


def _eh_tables(prog, fi):
    if not hasattr(prog, "eh_size"):
        prog.eh_size = {}; prog.eh_children = {}
    if fi in prog.eh_size and fi in prog.eh_children:
        return
    A = prog.img["A"]; va = prog.pos["A"][fi]
    size, tabs = funcinfo_layout(A, va)
    prog.eh_size[fi] = size; kids = []
    names_at = collections.defaultdict(list)
    for a, n in prog.data_syms:
        names_at[a].append(n)
    for pref, tva, tsize in tabs:
        cand = [n for n in names_at.get(tva, []) if n.startswith(pref)]
        if len(cand) != 1:
            raise GLError("UNSUPPORTED", "%s of %s at 0x%08X has %d map names" % (pref, fi, tva, len(cand)))
        prog.eh_size[cand[0]] = tsize; kids.append(cand[0])
    prog.eh_children[fi] = kids


def place_exact(wd, lifted, place, externals, link, read_original, text_lo=0x00401000, tag="X"):
    R = _linker_module(); o = R.Obj(lifted)
    rename = {}; changes = {}; flags = {}
    for y in o.syms:
        if y["name"] in place and y["scn"] > 0:
            nm = y["name"]
            if y["cls"] == 3:
                new = "%s$p%d" % (nm, len(rename)); rename[nm] = new; changes[y["idx"]] = dict(name=new, cls=2)
            ch = o.secs[y["scn"] - 1]["ch"]; al = 1 << (((ch >> 20) & 0xF) - 1) if (ch >> 20) & 0xF else 16
            if place[nm] % al:
                flags[y["scn"]] = (ch & ~0x00F00000) | 0x00100000
    obj = R.rewrite_obj(lifted, changes, flags)
    _wb(os.path.join(wd, tag + "_lifted.obj"), obj)
    sizes = {y["name"]: len(o.secs[y["scn"] - 1]["raw"]) for y in o.syms if y["name"] in place and y["scn"] > 0}
    pieces = sorted((va, rename.get(n, n), n) for n, va in place.items())
    defined = {y["name"] for y in o.syms if y["scn"] > 0}
    code_ext = {n: v for n, v in externals.items() if n not in defined and text_lo <= v < 0x006CC000}
    data_ext = {n: v for n, v in externals.items() if n not in defined and n not in code_ext}
    hi = max([va + sizes[n] for va, _, n in pieces] + [v + 1 for v in code_ext.values()]) + 16
    cur = text_lo; order = []; objs = []; k = 0
    spans = [(va, va + sizes[n]) for va, _, n in pieces]
    def filler(lo, hi_):
        nonlocal k
        if hi_ <= lo:
            return
        nm = "_d2gl_x%d" % k; k += 1
        inside = [(e, v - lo) for e, v in code_ext.items() if lo <= v < hi_]
        p = "%s_f%d.obj" % (tag, k); _wb(os.path.join(wd, p), R.filler_obj(nm, hi_ - lo, inside)); objs.append(p); order.append(nm)
    overlapping = {}
    kept = []
    for (va, oname, n) in pieces:
        if va < cur:
            overlapping[n] = "overlaps the piece before it (which ends at 0x%08X)" % cur; continue
        nxt = [a for a, _, m in pieces if a > va]
        if nxt and va + sizes[n] > nxt[0]:
            overlapping[n] = "is %d B, the next placed piece starts %d B after it" % (sizes[n], nxt[0] - va); continue
        filler(cur, va); order.append(oname); cur = va + sizes[n]; kept.append((va, oname, n))
    filler(cur, hi)
    spans = [(va, va + sizes[n]) for va, _, n in kept]
    inside_bodies = {e: v for e, v in code_ext.items() if any(a <= v < b for a, b in spans)}
    for e in inside_bodies:
        data_ext[e] = code_ext.pop(e)
    _wb(os.path.join(wd, tag + "_abs.obj"), R.absolute_obj(data_ext)); objs.append(tag + "_abs.obj")
    _wb(os.path.join(wd, tag + "_order.txt"), "\n".join(R.order_name(x) for x in order) + "\n")
    args = ["/nologo", "/NODEFAULTLIB", "/SUBSYSTEM:CONSOLE", "/SAFESEH:NO", "/FIXED", "/INCREMENTAL:NO", "/BASE:0x400000",
            "/OPT:NOREF", "/OPT:NOICF", "/ENTRY:" + R.order_name(order[0]), "/ORDER:@%s_order.txt" % tag,
            "/MAP:%s.map" % tag, "/OUT:%s.exe" % tag] + ["/INCLUDE:" + x for x in order] + [tag + "_lifted.obj"] + objs
    rc, txt = link(wd, args)
    if rc:
        raise GLError("LINK_ERROR", "exact placement: " + txt.strip()[-1500:])
    mp = {e["name"]: e["va"] for e in parse_map(os.path.join(wd, tag + ".map"))}
    img = Image(os.path.join(wd, tag + ".exe")); res = {}
    o2 = R.Obj(obj)
    for n, why in overlapping.items():
        res[n] = dict(placed=False, va="0x%08X" % place[n], size=sizes[n], equal=False, error="not placed: %s" % why)
    for va, oname, n in kept:
        got = mp.get(oname)
        y = next(y for y in o2.syms if y["name"] == oname and y["scn"] > 0)
        floating = set()
        for r in o2.relocs(y["scn"]):
            if r["sym"]["scn"] > 0 and r["sym"]["name"] not in rename.values() and r["sym"]["name"] not in place:
                floating |= set(range(r["offset"], r["offset"] + 4))
        body = img.read(va, sizes[n]) if got == va else None
        orig = read_original(va, sizes[n])
        diff = [i for i in range(sizes[n]) if body is not None and orig is not None and body[i] != orig[i] and i not in floating]
        res[n] = dict(placed=got == va, va="0x%08X" % va, size=sizes[n], equal=got == va and not diff, differing=len(diff),
                      first_diff=("+0x%x" % diff[0]) if diff else None, floating_bytes=len(floating), unaligned=bool(va % 16))
    return res


def ref_addresses(src):
    out = {}; lines = src.splitlines()
    for i, ln in enumerate(lines):
        m = re.match(r"^\s*//\s*@ref\s+(0x[0-9A-Fa-f]{8})\b", ln)
        if not m:
            continue
        for nxt in lines[i + 1:i + 4]:
            nm = checker.decl_name(nxt.split("//")[0], function_only=True) if nxt.strip() and not nxt.strip().startswith("//") else None
            if nm:
                out[nm] = int(m.group(1), 16); break
    return out


def run(wd, objs, src, resolver, link, link_flags, targets, read_original, known_length=None, log=None, place=True):
    probs = noroot_problems(src)
    if probs:
        raise GLError("NOROOT_REFUSED", "; ".join(probs))
    noroot = parse_noroot(src)
    prog = Program(wd, objs, resolver, link, link_flags, log, noroot=noroot, src=src).build()
    obj, inv = lift(prog, None, log)
    lp = os.path.join(wd, "lifted.obj")
    _wb(lp, obj)
    results = {}
    placements = {}
    for va, n in targets.items():
        res = checker.compare(obj, src, va, n, read_original, known_length)
        for k in ("_body", "_orig", "_diffs"):
            res.pop(k, None)
        results[va] = res
        if res.get("symbol"):
            placements[res["symbol"]] = va
    if place and placements:
        known = dict(ref_addresses(src))
        spans = sorted((va, va + results[va]["compiled_length"]) for va in placements.values())
        for nm, pc in inv["pieces"].items():
            if pc["kind"] != "func" or nm in placements:
                continue
            va = None
            for a in pc["aliases"]:
                h, how = resolver.resolve(a)
                if h is None:
                    h = known.get(checker.undec(a))
                if h is not None:
                    va = h; break
            if va is None or not 0x00401000 <= va < 0x006CC000 or va in placements.values():
                continue
            if any(lo < va + pc["size"] and va < hi for lo, hi in spans):
                continue
            placements[nm] = va; spans.append((va, va + pc["size"])); spans.sort()
        try:
            pr = place_exact(wd, obj, placements, prog.absolute, link, read_original)
        except GLError as e:
            pr = {s: dict(placed=False, error=str(e)) for s in placements}
        for s, va in placements.items():
            if va in results and results[va].get("symbol") == s:
                results[va]["placement"] = pr.get(s)
    recipe = dict(mode="gl-link", method=METHOD, link_flags=BASE_LINK + list(link_flags), link_images="A B(+abs shift %d) C(/FUNCTIONPADMIN:%d) D(+data %d)" % (SHIFT, PADMIN, DATA_PAD),
                  roots=prog.roots, noroot=noroot, noroot_symbols=prog.noroot_symbols, externals=inv["externals"], externals_sha256=hashlib.sha256(json.dumps(inv["externals"], sort_keys=True).encode()).hexdigest(),
                  links=len(prog.links), lifted_sha256=hashlib.sha256(obj).hexdigest(),
                  pieces={k: dict((kk, vv) for kk, vv in v.items() if kk != "image_a") for k, v in inv["pieces"].items()})
    return dict(lifted=lp, inventory=inv, results=results, recipe=recipe, program=prog)
