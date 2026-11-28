#!/usr/bin/env python3
"""Calling convention, argument bytes and return register of a symbol, for tools/link_aliases.py.

A C++ name is read through MSVC's undname (the toolchain's own demangler: `undname` on PATH, or under wine on other
systems, where IBLIS_UNDNAME gives its path). A C name says less: `_f@N` is __stdcall with N bytes, `@f@N` __fastcall
with N bytes, `_f` __cdecl or data; for those the declaration's source text gives the parameters.
"""
import os, re, subprocess, shutil

SLOT8 = ("__int64", "long long", "double")
SMALL = ("char", "bool", "short", "wchar_t", "int", "long", "float", "enum ", "unsigned", "signed", "BOOL", "DWORD",
         "WORD", "BYTE", "UINT", "ULONG", "LONG", "HANDLE", "HWND", "HINSTANCE", "HMODULE", "size_t", "LPARAM", "WPARAM")
CONVS = ("__cdecl", "__stdcall", "__fastcall", "__thiscall")


class Sig:
    """kind: 'func' or 'data'; conv; params: list of slot sizes (4, 8, or 'S:<type>' for a struct by value) or
    None when unknown; nbytes for stdcall/fastcall when known; variadic; ret: 'void', 'eax', 'edx:eax', 'st0',
    'struct' or None."""

    def __init__(self, kind, conv=None, params=None, nbytes=None, variadic=False, ret=None, text=""):
        self.kind, self.conv, self.params, self.nbytes, self.variadic, self.ret, self.text = \
            kind, conv, params, nbytes, variadic, ret, text

    def bytes(self):
        if self.nbytes is not None:
            return self.nbytes
        if self.params is None or any(not isinstance(p, int) for p in self.params):
            return None
        return sum(self.params)


def split_params(s):
    out = []; depth = 0; cur = ""
    for c in s:
        if c in "(<[":
            depth += 1
        elif c in ")>]":
            depth -= 1
        if c == "," and depth == 0:
            out.append(cur.strip()); cur = ""
        else:
            cur += c
    if cur.strip():
        out.append(cur.strip())
    return out


TYPE_WORDS = {"unsigned", "signed", "char", "short", "int", "long", "float", "double", "bool", "wchar_t", "__int8",
              "__int16", "__int32", "__int64", "void", "struct", "union", "class", "enum", "const", "volatile"}


def slot(t):
    """The stack bytes one parameter takes: 4, 8, or 'S:<type>' for a struct by value (size not known here)."""
    t = re.sub(r"=.*$", "", t).strip()                          # a default argument
    if "*" in t or "&" in t or "[" in t or "(" in t:
        return 4
    words = re.sub(r"\b(const|volatile)\b", " ", t).split()
    if len(words) >= 2 and words[-1] not in TYPE_WORDS and re.match(r"^[A-Za-z_]\w*$", words[-1]):
        words = words[:-1]                                      # the parameter's name, in source text
    words = [w for w in words if w not in ("struct", "union", "class")]
    t = " ".join(words)
    if any(k in t for k in SLOT8):
        return 8
    if t.startswith("enum") or any(re.search(r"\b%s\b" % re.escape(k.strip()), t) for k in SMALL):
        return 4
    return "S:" + t if t else None


def ret_class(t):
    t = re.sub(r"\b(const|volatile|static|virtual|extern|inline|__declspec\(\w+\)|public:|private:|protected:)\s*", "", t).strip()
    if t in ("void", ""):
        return "void"
    if "*" in t or "&" in t:
        return "eax"
    if any(k in t for k in ("float", "double")):
        return "st0"
    if any(k in t for k in SLOT8):
        return "edx:eax"
    if re.match(r"^(struct|union|class)\s", t):
        return "struct"
    return "eax"


def parse_text(text):
    """A demangled name or a source declaration -> Sig."""
    s = text.strip().rstrip(";{").strip()
    s = re.sub(r"//.*$", "", s).strip()
    s = re.sub(r"^(extern\s+\"C\"\s+|extern\s+|static\s+|inline\s+|__declspec\(\w+\)\s+)+", "", s)
    s = re.sub(r"^(public|private|protected):\s*", "", s)
    s = re.sub(r"^(static|virtual)\s+", "", s)
    m = re.search(r"\b(__cdecl|__stdcall|__fastcall|__thiscall)\b", s)
    p = s.find("(") if not m else s.find("(", m.end())
    if p < 0 or (m is None and not re.search(r"\w\s*\(", s)):
        return Sig("data", text=text)
    conv = m.group(1) if m else "__cdecl"
    ret = ret_class(s[:m.start()] if m else s[:p].rsplit(None, 1)[0] if " " in s[:p].strip() else "")
    depth = 0; q = p
    for i in range(p, len(s)):
        if s[i] == "(":
            depth += 1
        elif s[i] == ")":
            depth -= 1
            if depth == 0:
                q = i; break
    inner = s[p + 1:q].strip()
    params = [] if inner in ("", "void") else split_params(inner)
    variadic = bool(params) and params[-1] == "..."
    if variadic:
        params = params[:-1]
    return Sig("func", conv, [slot(x) for x in params], None, variadic, ret, text)


def c_name(sym):
    """What a C symbol's name tells: (kind, conv, nbytes) or None for a C++ name."""
    if sym.startswith("?"):
        return None
    m = re.match(r"^@\w+@(\d+)$", sym)
    if m:
        return ("func", "__fastcall", int(m.group(1)))
    m = re.match(r"^_\w+@(\d+)$", sym)
    if m:
        return ("func", "__stdcall", int(m.group(1)))
    return ("?", "__cdecl", None)


_cache = {}


def undname(syms):
    """{decorated: demangled} through MSVC's undname."""
    todo = [s for s in syms if s.startswith("?") and s not in _cache]
    exe = os.environ.get("IBLIS_UNDNAME") or "undname"
    wine = [] if os.name == "nt" else ["wine"]
    for i in range(0, len(todo), 200):
        chunk = todo[i:i + 200]
        out = subprocess.run(wine + [exe] + chunk, capture_output=True, text=True, errors="replace",
                             env=dict(os.environ, WINEDEBUG="-all")).stdout
        got = re.findall(r'is :- "(.*)"', out)
        for s, d in zip(chunk, got):
            _cache[s] = d
    return {s: _cache.get(s) for s in syms if s.startswith("?")}


def sig_of(sym, source_text=None):
    """The Sig of a decorated symbol; source_text (its declaration in the source) fills in a C name's parameters."""
    c = c_name(sym)
    if c is None:
        d = _cache.get(sym) or undname([sym]).get(sym)
        if not d:
            return None
        if "`" in d or re.match(r"^\?[A-Za-z_0-9]+(?:@[A-Za-z_0-9]+)*@@[23]", sym):   # @@3 global, @@2 static member
            return Sig("data", text=d)
        sg = parse_text(d)
        if sg.kind == "func" and re.search(r"\b(public|private|protected):", d) and "__thiscall" not in d and "static" not in d:
            sg.conv = "__thiscall"
        return sg
    kind, conv, nbytes = c
    if source_text:
        sg = parse_text(source_text)
        if kind == "func":
            sg.kind, sg.conv, sg.nbytes = "func", conv, nbytes
        return sg
    return Sig(kind, conv, None, nbytes)


def compatible(ref, dfn):
    """'' when an alias ref -> dfn keeps the call right, else why not."""
    if ref is None or dfn is None:
        return "signature unknown"
    if ref.kind == "data" and dfn.kind == "data":
        return ""
    if ref.kind == "?" or dfn.kind == "?":
        return "" if "data" in (ref.kind, dfn.kind) and "func" not in (ref.kind, dfn.kind) else \
            ("signature unknown" if ref.params is None and dfn.params is None else "")
    if ref.kind != dfn.kind:
        return "function and data"
    if ref.conv != dfn.conv:
        return "calling convention %s vs %s" % (ref.conv, dfn.conv)
    if ref.conv in ("__stdcall", "__fastcall", "__thiscall"):
        a, b = ref.bytes(), dfn.bytes()
        if a is None or b is None:
            if ref.params is not None and dfn.params is not None and ref.params == dfn.params:
                pass
            else:
                return "argument bytes unknown"
        elif a != b:
            return "argument bytes %d vs %d" % (a, b)
        known = lambda sg: sg.params is not None and all(isinstance(x, int) for x in sg.params)
        if ref.conv == "__fastcall" and known(ref) and known(dfn):
            # ECX and EDX take the first two arguments of 4 bytes or less: the same sequence of slots
            if [p if p in (4, 8) else "S" for p in ref.params] != [p if p in (4, 8) else "S" for p in dfn.params]:
                return "fastcall argument order differs"
    else:
        if ref.params is None or dfn.params is None:
            return "parameters unknown"
        if ref.variadic != dfn.variadic:
            return "variadic vs not"
        if len(ref.params) != len(dfn.params):
            return "parameter count %d vs %d" % (len(ref.params), len(dfn.params))
        for x, y in zip(ref.params, dfn.params):
            if x != y and not (x == 4 and y == 4):
                return "parameter size %s vs %s" % (x, y)
    r, d = ref.ret, dfn.ret
    if r == d or r == "void" or r is None or d is None:
        return ""
    if r == "eax" and d == "eax":
        return ""
    return "return %s vs %s" % (r, d)


def code_references(obj_path):
    """The symbols an object file refers to from code (relocations in sections marked as code). A symbol referred to
    only from data (a table of function pointers, an initialiser) is used for its address, never called through
    this object's declaration of it."""
    import struct
    d = open(obj_path, "rb").read()
    if d[:2] == b"\0\0":                                     # /bigobj
        nsec = struct.unpack_from("<I", d, 44)[0]; symptr = struct.unpack_from("<I", d, 48)[0]
        nsym = struct.unpack_from("<I", d, 52)[0]; sechdr = 56; size = 20
    else:
        nsec = struct.unpack_from("<H", d, 2)[0]; symptr = struct.unpack_from("<I", d, 8)[0]
        nsym = struct.unpack_from("<I", d, 12)[0]; sechdr = 20 + struct.unpack_from("<H", d, 16)[0]; size = 18
    strtab = symptr + size * nsym

    def name(i):
        o = symptr + i * size
        raw = d[o:o + 8]
        if raw[:4] == b"\0\0\0\0":
            k = struct.unpack_from("<I", raw, 4)[0]
            return d[strtab + k:d.index(b"\0", strtab + k)].decode("latin-1")
        return raw.rstrip(b"\0").decode("latin-1")
    out = set()
    for k in range(nsec):
        h = sechdr + 40 * k
        flags = struct.unpack_from("<I", d, h + 36)[0]
        if not flags & 0x20:                                    # IMAGE_SCN_CNT_CODE
            continue
        rel = struct.unpack_from("<I", d, h + 24)[0]; nrel = struct.unpack_from("<H", d, h + 32)[0]
        for r in range(nrel):
            out.add(name(struct.unpack_from("<I", d, rel + 10 * r + 4)[0]))
    return out
