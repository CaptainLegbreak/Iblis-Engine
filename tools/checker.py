import re, struct, hashlib, difflib

KEYWORDS = {"void", "char", "short", "int", "long", "float", "double", "bool", "signed", "unsigned", "const", "volatile",
            "struct", "class", "union", "enum", "__int8", "__int16", "__int32", "__int64", "wchar_t", "static", "extern",
            "inline", "__inline", "__forceinline", "__declspec", "__cdecl", "__stdcall", "__fastcall", "__thiscall",
            "virtual", "__w64", "__unaligned", "__restrict", "sizeof", "throw", "return", "if", "while", "for", "switch"}
CALLCONV = r"(?:__cdecl|__stdcall|__fastcall|__thiscall)"


def strip_declspec(code):
    out = code
    while True:
        m = re.search(r"\b__declspec\s*\(", out)
        if not m:
            return out
        depth, i = 0, m.end() - 1
        while i < len(out):
            if out[i] == "(":
                depth += 1
            elif out[i] == ")":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        out = out[:m.start()] + " " + out[i + 1:]


def decl_name(code, function_only=False):
    code = strip_declspec(code)
    fn = next((m for m in re.finditer(r"([A-Za-z_~]\w*)\s*\(", code) if m.group(1) not in KEYWORDS), None)
    fp = re.search(r"\(\s*(?:" + CALLCONV + r"\s*)?\*+\s*(?:const\s+)?([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*\)\s*\(", code)
    if fp and (fn is None or fp.start() < fn.start()):
        return None if function_only else fp.group(1)
    if fn:
        return fn.group(1)
    if function_only:
        return None
    decl = re.sub(r'"(?:\\.|[^"\\])*"', '""', code)
    decl = re.sub(r"=[^,;]*", "=", decl)
    ids = [w for w in re.findall(r"\b([A-Za-z_]\w*)\s*(?:\[|;|=)", decl) if w not in KEYWORDS]
    return ids[-1] if ids else None


SYMBOL_DIRECTIVE = re.compile(r"^//\s*build:\s*symbol\s+(\S+)\s+(0x[0-9A-Fa-f]{8})\s*$")
CONTEXT_DIRECTIVE = re.compile(r"^//\s*build:\s*context\s+(\S+)\s*$")


def parse_context(src):
    return [m.group(1) for m in (CONTEXT_DIRECTIVE.match(ln.strip()) for ln in src.splitlines()) if m]


def context_named(sym_name, names):
    for nm in names:
        if nm.endswith("*"):
            hit = sym_name.startswith(nm[:-1])
        elif nm == sym_name or nm.startswith("?"):
            hit = nm == sym_name
        elif "::" in nm:
            cls, meth = nm.rsplit("::", 1)
            last, cls_dec = cls.split("::")[-1], "@".join(reversed(cls.split("::")))
            pre = "??0%s@@" % cls_dec if meth == last else "??1%s@@" % cls_dec if meth == "~" + last else "?%s@%s@@" % (meth, cls_dec)
            hit = sym_name.startswith(pre)
        else:
            hit = not sym_name.startswith("??_") and undec(sym_name) == nm
        if hit:
            return True
    return False


class _Ambiguous(object):
    def __repr__(self):
        return "AMBIGUOUS"


AMBIGUOUS = _Ambiguous()


def _put(d, k, v):
    d[k] = AMBIGUOUS if k in d and d[k] != v else v


def parse_markers(src):
    defs, decls, symbols, pending = {}, {}, {}, None
    for ln in src.splitlines():
        t = ln.strip()
        sd = SYMBOL_DIRECTIVE.match(t)
        if sd:
            _put(symbols, sd.group(1), int(sd.group(2), 16)); continue
        m = re.match(r"//\s*(0x[0-9A-Fa-f]{8})\s*$", t)
        if m:
            pending = int(m.group(1), 16); continue
        m2 = re.search(r"//\s*(0x[0-9A-Fa-f]{8})\s*$", t)
        code = re.sub(r'"(\\.|[^"\\])*"', '""', t).split("//")[0]
        if m2 and code.strip():
            nm = decl_name(code)
            if nm:
                _put(decls, nm, int(m2.group(1), 16))
        if pending is not None and code.strip():
            nm = decl_name(code, function_only=True)
            if nm:
                _put(defs, nm, pending)
            pending = None
    return defs, decls, symbols


def _one(vals):
    vals = [v for v in vals if v is not None]
    if not vals:
        return None
    if any(v is AMBIGUOUS for v in vals) or len(set(vals)) > 1:
        return AMBIGUOUS
    return vals[0]


def symbol_marker(name, symbols):
    if name in symbols and not name.endswith("*"):
        return symbols[name]
    return _one(va for pat, va in symbols.items() if pat.endswith("*") and name.startswith(pat[:-1]))


def _decl_lookup(name, decls):
    m = decls.get(undec(name))
    if m is None and name.startswith("_") and not name.startswith("__imp_") and "?" not in name:
        m = decls.get(name[1:].split("@")[0])
    return m


def _def_lookup(name, defs):
    return defs.get(undec(name)) or defs.get(name.lstrip("_").split("@")[0])


def resolve(name, defs, decls, symbols):
    exact = symbols[name] if name in symbols and not name.endswith("*") else None
    if exact is not None and exact is not AMBIGUOUS:
        return exact, {"symbol"}
    by = dict(symbol=exact, def_=_def_lookup(name, defs) if defs else None, decl=_decl_lookup(name, decls))
    va = _one(by.values())
    if va is not None:
        return va, {k for k, v in by.items() if v is not None}
    va = symbol_marker(name, {k: v for k, v in symbols.items() if k.endswith("*")})
    return va, ({"wildcard"} if va is not None else set())


def marker_for(name, decls, symbols, defs=None):
    return resolve(name, defs or {}, decls, symbols)[0]


def undec(n):
    m = re.match(r"^\?\?([01])([A-Za-z_0-9]+)@", n)
    if m: return ("~" if m.group(1) == "1" else "") + m.group(2)
    if n.startswith("??_") and not n.startswith("??__"): return n
    if n.startswith("@"): return n[1:].split("@")[0]
    return re.sub(r"^\?\??_?([A-Za-z_~0-9]+)@.*$", r"\1", n).lstrip("_").split("@")[0]


class Coff:
    def __init__(self, d):
        self.d = d
        nsec, symptr, nsym = struct.unpack_from("<H", d, 2)[0], struct.unpack_from("<I", d, 8)[0], struct.unpack_from("<I", d, 12)[0]
        strtab = symptr + 18 * nsym
        def symname(o):
            raw = d[o:o + 8]
            if raw[:4] == b"\0\0\0\0":
                z = strtab + struct.unpack_from("<I", raw, 4)[0]; return d[z:d.index(b"\0", z)].decode("latin-1")
            return raw.rstrip(b"\0").decode("latin-1")
        self.secs = []
        for i in range(nsec):
            o = 20 + 40 * i
            name, vsz, va_, rsz, rptr, relptr, _, nrel, _, fl = struct.unpack_from("<8sIIIIIIHHI", d, o)
            self.secs.append(dict(name=name.rstrip(b"\0").decode("latin-1"), raw=d[rptr:rptr + rsz], relptr=relptr, nrel=nrel))
        self.syms = []; i = 0
        while i < nsym:
            o = symptr + 18 * i; val, scn, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
            self.syms.append(dict(name=symname(o), value=val, scn=scn, cls=cls, naux=naux, idx=i)); i += 1 + naux
        self.by_idx = {y["idx"]: y for y in self.syms}

    def relocs(self, scn):
        sec = self.secs[scn - 1]; out = []
        for k in range(sec["nrel"]):
            off, si, ty = struct.unpack_from("<IIH", self.d, sec["relptr"] + 10 * k)
            out.append(dict(offset=off, sym=self.by_idx[si], ty=ty))
        return out

    def funcs(self):
        return [y for y in self.syms if y["scn"] > 0 and (y["cls"] == 2 or (y["cls"] == 3 and y["value"] == 0 and not y["name"].startswith((".", "$"))))
                and self.secs[y["scn"] - 1]["name"].startswith(".text")]


def signed32(v):
    return v - (1 << 32) if v >= (1 << 31) else v


CONTENT_TABLES = ("__sehtable$",)


def resolve_table(coff, sym, addr, read, start, length, tgt_scn, marker_of):
    if sym["scn"] <= 0:
        return ["%s is not defined in this object" % sym["name"]]
    sec = coff.secs[sym["scn"] - 1]; lo = sym["value"]
    hi = min([y["value"] for y in coff.syms if y["scn"] == sym["scn"] and y["value"] > lo and y["name"].startswith(CONTENT_TABLES)]
             + [len(sec["raw"])])
    data = sec["raw"][lo:hi]
    orig = read(addr, len(data)) if data else None
    if not data or orig is None or len(orig) != len(data):
        return ["%s: no original bytes at 0x%08X for its %d bytes" % (sym["name"], addr, len(data))]
    size = len(data)
    if size % 12 == 0:
        header = 0
    elif size >= 28 and (size - 16) % 12 == 0:
        header = 16
    else:
        return ["%s: %d bytes are not whole scope entries; its entries cannot be checked" % (sym["name"], size)]
    filter_slots = set(range(header + 4, size, 12)); handler_slots = set(range(header + 8, size, 12))
    mask = bytearray(size); problems = []; seen = set()
    for r in coff.relocs(sym["scn"]):
        if not lo <= r["offset"] < hi:
            continue
        o = r["offset"] - lo
        if o not in filter_slots and o not in handler_slots:
            problems.append("%s+0x%x: relocation outside a filter or handler slot" % (sym["name"], o)); continue
        if r["ty"] != 6:
            problems.append("%s+0x%x: relocation type 0x%x is not resolved by content" % (sym["name"], o, r["ty"])); continue
        if o in seen:
            problems.append("%s+0x%x: two relocations on one slot" % (sym["name"], o)); continue
        seen.add(o)
        for k in range(4): mask[o + k] = 1
        add = signed32(struct.unpack_from("<I", data, o)[0]); rs = r["sym"]
        if rs["scn"] == tgt_scn:
            want = (start + rs["value"] + add) & 0xFFFFFFFF
            if not start <= want < start + length:
                problems.append("%s+0x%x: points outside the target (0x%08X)" % (sym["name"], o, want)); continue
        else:
            m = marker_of(rs["name"])
            if m is AMBIGUOUS:
                problems.append("%s+0x%x: %s is mapped to different addresses" % (sym["name"], o, rs["name"])); continue
            if m is None:
                problems.append("%s+0x%x: %s is neither code of the target nor marked" % (sym["name"], o, rs["name"])); continue
            want = (m + add) & 0xFFFFFFFF
        got = struct.unpack_from("<I", orig, o)[0]
        if got != want:
            problems.append("%s+0x%x: compiled points at 0x%08X, original holds 0x%08X" % (sym["name"], o, want, got))
    for o in sorted(handler_slots - seen):
        problems.append("%s+0x%x: handler entry has no relocation and cannot be verified" % (sym["name"], o))
    for o in sorted(filter_slots - seen):
        if data[o:o + 4] != b"\0\0\0\0":
            problems.append("%s+0x%x: filter entry is neither 0 nor a relocation and cannot be verified" % (sym["name"], o))
    bad = [i for i in range(size) if not mask[i] and data[i] != orig[i]]
    if bad:
        problems.append("%s: %d byte(s) differ from the original at 0x%08X (first +0x%x)" % (sym["name"], len(bad), addr, bad[0]))
    return problems


LITERALS = ("??_C@", "__real@", "__xmm@", "__mask@")
EH_PIECES = ("__ehhandler$", "__ehfuncinfo$", "__unwindfunclet$", "__unwindtable$", "__tryblocktable$", "__catchsym$")
CRT_C = set("""
memset memcpy memmove memcmp memchr strlen strcpy strncpy strcat strncat strcmp strncmp strchr strrchr strstr strpbrk
strspn strcspn strtok _stricmp _strnicmp _strcmpi _stricoll _strlwr _strupr _strdup _strrev _mbscpy _mbslen
sprintf _snprintf _snprintf_s sprintf_s vsprintf _vsnprintf _vsnprintf_s sscanf printf fprintf vfprintf
_itoa _ltoa _ultoa _i64toa _ui64toa _itoa_s atoi atol atof strtol strtoul strtod
toupper tolower _toupper _tolower isalpha isdigit isspace isalnum isupper islower isprint isxdigit ispunct iscntrl
abs labs rand srand time _time32 _time64 clock exit _exit atexit _onexit _cexit abort
malloc free calloc realloc _msize _expand qsort bsearch
fopen fclose fread fwrite fseek ftell fgets fputs fgetc fputc fflush _access _unlink remove rename getenv
_splitpath _makepath _fullpath _filelength _fileno _open _close _read _write _lseek
wcslen wcscpy wcsncpy wcscmp wcsncmp _wcsicmp mbstowcs wcstombs swprintf _snwprintf _vsnwprintf _wtoi
localtime _localtime32 gmtime mktime _mktime32 strftime
sqrt sin cos tan asin acos atan atan2 pow log log10 exp floor ceil fabs fmod modf frexp ldexp _hypot
_CIsqrt _CIsin _CIcos _CItan _CIasin _CIacos _CIatan _CIatan2 _CIpow _CIlog _CIlog10 _CIexp _CIfmod
_ftol _ftol2 _ftol2_sse _chkstk _alloca_probe _alloca_probe_8 _alloca_probe_16
_alldiv _allmul _allrem _aulldiv _aullrem _aulldvrm _alldvrm _allshl _allshr _aullshr
_except_handler3 _except_handler4 _local_unwind2 _local_unwind4 _EH_prolog _CxxThrowException
__CxxFrameHandler __CxxFrameHandler3 _purecall _setjmp _setjmp3 longjmp __security_cookie __security_check_cookie
_beginthread _beginthreadex _endthread _endthreadex _errno __iob_func _iob
""".split())
CRT_CPP = {"??2@YAPAXI@Z", "??3@YAXPAX@Z", "??_U@YAPAXI@Z", "??_V@YAXPAX@Z"}
CRT_CPP_PREFIX = ("??_H@", "??_I@", "??_L@", "??_M@")
SUB_VA = re.compile(r"^sub_([0-9A-Fa-f]{8})(?:_|$)")


def c_source_name(name):
    if name.startswith("?"):
        return None
    m = re.match(r"^@(.+)@\d+$", name)
    if m:
        return m.group(1)
    if name.startswith("_"):
        return re.sub(r"@\d+$", "", name[1:])
    return None


def allowed_unmarked(sym):
    if sym["scn"] != 0:
        return None
    nm = sym["name"]
    if nm.startswith("__imp_"):
        return "import"
    if nm in CRT_CPP or nm.startswith(CRT_CPP_PREFIX) or c_source_name(nm) in CRT_C:
        return "CRT"
    return None


def sub_va_of(name):
    m = SUB_VA.match(undec(name))
    return int(m.group(1), 16) if m else None


def _piece_extent(coff, sym, prefixes):
    sec = coff.secs[sym["scn"] - 1]; lo = sym["value"]
    hi = min([y["value"] for y in coff.syms if y["scn"] == sym["scn"] and y["value"] > lo and y["name"].startswith(prefixes)]
             + [len(sec["raw"])])
    return sec, lo, hi


class _Refs(object):
    def __init__(self, coff, tgt_scn, start, length, read, marker_of):
        self.c, self.tgt_scn, self.start, self.n, self.read, self.marker_of = coff, tgt_scn, start, length, read, marker_of
        self.active = set()

    def check(self, sy, ty, addend, pva, ov, where):
        nm = sy["name"]
        if ty not in (6, 0x14):
            return None, ["%s: relocation type 0x%x to %s cannot be checked" % (where, ty, nm)]
        ot = (pva + 4 + signed32(ov)) & 0xFFFFFFFF if ty == 0x14 else ov
        s = (ot - addend) & 0xFFFFFFFF
        exp = self.marker_of(nm)
        if exp is AMBIGUOUS:
            return None, ["%s: %s is mapped to different addresses by markers of the same precedence" % (where, nm)]
        if sy["scn"] == self.tgt_scn:
            want = (self.start + sy["value"] + addend) & 0xFFFFFFFF
            p = []
            if not self.start <= want < self.start + self.n:
                p.append("%s: %s%+d points outside the function (0x%08X)" % (where, nm, addend, want))
            elif ot != want:
                p.append("%s: compiled points at +0x%x in the function, original at 0x%08X" % (where, want - self.start, ot))
            if exp is not None and exp != (self.start + sy["value"]) & 0xFFFFFFFF:
                p.append("%s: %s is marked 0x%08X but is at +0x%x of the function" % (where, nm, exp, sy["value"]))
            return "offset", p
        if sy["scn"] > 0 and nm.startswith(LITERALS):
            if ty != 6:
                return None, ["%s: constant %s referenced by REL32" % (where, nm)]
            sec, lo, hi = _piece_extent(self.c, sy, LITERALS)
            if not sec["name"].startswith((".rdata", ".data")):
                return None, ["%s: constant %s is not in a data section (%s)" % (where, nm, sec["name"])]
            lit = sec["raw"][lo:hi]
            got = self.read(s, len(lit)) if lit else None
            if not lit or got != lit:
                return None, ["%s: constant %s does not equal the original's data at 0x%08X (operand 0x%08X less addend %d)"
                              % (where, nm, s, ot, addend)]
            if exp is not None and exp != s:
                return None, ["%s: %s is marked 0x%08X but the original uses 0x%08X" % (where, nm, exp, s)]
            return "content", []
        if sy["scn"] > 0 and nm.startswith(EH_PIECES):
            p = self.piece(sy, s, where)
            if not p and exp is not None and exp != s:
                p = ["%s: %s is marked 0x%08X but the original uses 0x%08X" % (where, nm, exp, s)]
            return "content", p
        if exp is not None:
            return "marker", ([] if exp == s else ["%s: %s declared 0x%08X but original encodes 0x%08X" % (where, nm, exp, s)])
        cat = allowed_unmarked(sy)
        if cat:
            return cat, []
        sv = sub_va_of(nm)
        if sv is not None and (sy["scn"] == 0 or self.c.secs[sy["scn"] - 1]["name"].startswith(".text")):
            return "name", ([] if sv == s else ["%s: %s names 0x%08X but original encodes 0x%08X" % (where, nm, sv, s)])
        return None, ["%s: %s is unmarked and cannot be verified (needs a // 0xVA marker or a `// build: symbol` line)"
                      % (where, nm)]

    def piece(self, sy, addr, where):
        key = (sy["scn"], sy["value"], addr)
        if key in self.active:
            return []
        self.active.add(key)
        sec, lo, hi = _piece_extent(self.c, sy, EH_PIECES)
        data = sec["raw"][lo:hi]
        orig = self.read(addr, len(data)) if data else None
        if not data or orig is None or len(orig) != len(data):
            return ["%s: %s has no original bytes at 0x%08X for its %d bytes" % (where, sy["name"], addr, len(data))]
        mask = bytearray(len(data)); problems = []
        sn = sy["scn"]
        for r in self.c.relocs(sn):
            if not lo <= r["offset"] < hi:
                continue
            o = r["offset"] - lo
            if o + 4 > len(data) or any(mask[o:o + 4]):
                problems.append("%s+0x%x: relocation overlaps another or the piece's end" % (sy["name"], o)); continue
            for k in range(4): mask[o + k] = 1
            a = signed32(struct.unpack_from("<I", data, o)[0]); ov = struct.unpack_from("<I", orig, o)[0]
            _, p = self.check(r["sym"], r["ty"], a, addr + o, ov, "%s+0x%x" % (sy["name"], o))
            problems += p
        bad = [i for i in range(len(data)) if not mask[i] and data[i] != orig[i]]
        if bad:
            problems.append("%s: %d byte(s) differ from the original at 0x%08X (first +0x%x)" % (sy["name"], len(bad), addr, bad[0]))
        return problems


def compare(obj, src, va, length, read, known_length=None):
    start = va
    defs, decls, symbols = parse_markers(src)

    def marker_of(name):
        return marker_for(name, decls, symbols, defs)

    target_name = next((k for k, v in defs.items() if v == start), None)
    target_sym = next((k for k, v in symbols.items() if v == start), None)
    if not target_name and not target_sym:
        return dict(status="NO_MARKER", detail="no `// 0x%08X` marker above a function definition" % va)
    c = Coff(obj); funcs = c.funcs()

    def def_va(y):
        h, kinds = resolve(y["name"], defs, decls, symbols)
        return h if h is not AMBIGUOUS and kinds & {"symbol", "def_", "wildcard"} else None

    found = [y for y in funcs if def_va(y) == start]
    if len(found) > 1:
        return dict(status="NO_SYMBOL", detail="more than one function maps to 0x%08X: %s" % (start, [y["name"] for y in found][:8]))
    tgt = found[0] if found else None
    if not tgt:
        return dict(status="NO_SYMBOL", detail="symbol for %s not found in object (or mapped to another address); functions: %s"
                    % (target_name or target_sym, [y["name"] for y in funcs][:8]))
    sec = c.secs[tgt["scn"] - 1]; body = sec["raw"]
    twins = [y["name"] for y in funcs if y["scn"] != tgt["scn"] and len(body) >= 64 and abs(len(c.secs[y["scn"] - 1]["raw"]) - len(body)) <= len(body) // 10]
    rels = []
    for r in c.relocs(tgt["scn"]):
        rels.append(dict(offset=r["offset"], symbol=r["sym"]["name"], type={0x14: "REL32", 6: "DIR32"}.get(r["ty"], hex(r["ty"])),
                         inplace=struct.unpack_from("<I", body, r["offset"])[0], _sym=r["sym"]))
    n = length
    orig = read(start, max(n, len(body)))
    mask = bytearray(len(body))
    for rl in rels:
        for k in range(4): mask[rl["offset"] + k] = 1
    raw_equal = body == orig[:len(body)] and len(body) == n
    diffs = [i for i in range(min(len(body), len(orig))) if body[i] != orig[i] and not mask[i]]
    rawdiffs = [i for i in range(min(len(body), len(orig))) if body[i] != orig[i]]
    masked_equal = (len(body) == n) and not diffs
    problems = []
    refs = _Refs(c, tgt["scn"], start, n, read, marker_of)
    for rl in rels:
        sy = rl.pop("_sym")
        ov = struct.unpack_from("<I", orig, rl["offset"])[0]
        if rl["type"] == "REL32":
            ot = (start + rl["offset"] + 4 + signed32(ov)) & 0xFFFFFFFF
        else:
            ot = (ov - signed32(rl["inplace"])) & 0xFFFFFFFF
        exp = marker_of(rl["symbol"])
        rl.update(original_target="0x%08X" % ot,
                  declared="ambiguous" if exp is AMBIGUOUS else ("0x%08X" % exp if exp is not None else None))
        if exp is AMBIGUOUS:
            problems.append("%s: mapped to different addresses by markers of the same precedence" % rl["symbol"])
        elif rl["symbol"].startswith(CONTENT_TABLES):
            if rl["type"] != "DIR32":
                problems.append("%s: referenced by %s, not resolved by content" % (rl["symbol"], rl["type"])); continue
            if exp is not None and exp != ot:
                problems.append("%s: declared %s but original encodes %s" % (rl["symbol"], rl["declared"], rl["original_target"]))
            tp = resolve_table(c, sy, ot, read, start, n, tgt["scn"], marker_of)
            if tp:
                problems += tp
            elif exp is None or exp == ot:
                rl["resolved_by"] = "content"
        else:
            how, p = refs.check(sy, {"REL32": 0x14, "DIR32": 6}.get(rl["type"], -1), signed32(rl["inplace"]),
                                start + rl["offset"], ov, "+0x%x" % rl["offset"])
            problems += p
            if not p and how in ("CRT", "import"):
                rl["note"] = "unmarked %s (allowed without a marker)" % how
            elif not p and how in ("offset", "content", "name"):
                rl["resolved_by"] = how
    context = []
    for y in list(funcs):
        if y["name"] not in twins: continue
        hva = def_va(y)
        if not hva or hva == start or known_length is None: continue
        hlen = known_length(hva)
        if not hlen: continue
        hb = c.secs[y["scn"] - 1]["raw"]
        if abs(len(hb) - hlen) > hlen // 10: continue
        r_own = difflib.SequenceMatcher(None, hb, read(hva, hlen), autojunk=False).ratio()
        r_tgt = difflib.SequenceMatcher(None, hb, orig[:n], autojunk=False).ratio()
        if r_own > r_tgt:
            twins.remove(y["name"]); context.append(dict(symbol=y["name"], va="0x%08X" % hva, ratio_own=round(r_own, 3), ratio_target=round(r_tgt, 3)))
    cnames = parse_context(src)
    for y in [y for y in funcs if y["name"] in twins and cnames]:
        if not context_named(y["name"], cnames) or def_va(y) is not None:
            continue
        hb = c.secs[y["scn"] - 1]["raw"]
        hmask = bytearray(len(hb))
        for r in c.relocs(y["scn"]):
            for k in range(4): hmask[r["offset"] + k] = 1
        if len(hb) == n and all(hmask[i] or hb[i] == orig[i] for i in range(n)):
            continue
        twins.remove(y["name"]); context.append(dict(symbol=y["name"], va=None, by="directive"))
    status = "MULTI_FORM_REJECTED" if twins else "RAW_EQUAL" if raw_equal else ("RELOCATION_RESOLVED_EQUAL" if masked_equal and not problems else ("MASKED_EQUAL_BUT_TARGETS_DIFFER" if masked_equal else "MISMATCH"))
    after = orig[n:n + 1] if len(orig) > n else read(start + n, 1)
    return dict(status=status, extra_forms=twins, context_bodies=context, compiled_length=len(body), expected_length=n,
                compiled_body_sha256=hashlib.sha256(body).hexdigest(), original_body_sha256=hashlib.sha256(orig[:n]).hexdigest(),
                first_diff=("+0x%x" % rawdiffs[0]) if rawdiffs else None, diff_bytes=len(rawdiffs), unmasked_diff_bytes=len(diffs),
                extent_agrees=(len(body) == n), byte_after_end=(after or b"").hex().upper(), relocations=rels, target_problems=problems,
                symbol=tgt["name"], _body=body, _orig=orig, _diffs=diffs)
