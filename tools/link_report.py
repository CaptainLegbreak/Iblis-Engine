#!/usr/bin/env python3
"""Measures what keeps the engine from linking: every unresolved and duplicate symbol of a link, sorted the way
Iblis Codex's tools/linkdebt.py sorts its link debt.

    python tools/link_report.py BUILD_DIR LINK_LOG CODEX_DIR [--json OUT.json] [--md OUT.md]

BUILD_DIR is the CMake build folder (its objects are read for what each defines), LINK_LOG the linker's output of
a failed link of Game.exe, CODEX_DIR a checkout of Iblis Codex at the synced commit (tools/CODEX_SYNC), for
build/functions.json and build/data_plan.json: where 1.14d's functions and data are. A developer tool; the build
never runs it.

A reference is the symbol a file asks for. Its declaration in the file (or a header it includes) carries the
address it means (`// 0x<VA>`); the definition at that address, if a source defines it, is what it should bind to.
The categories (Codex's, with what can be told without Game.exe):

  import                an import declared under another name or type than its import library's
  runtime_library       a C runtime routine declared under another name or type
  type_disagreement     the same identifier as the definition, another decorated name (type, signature, C vs C++)
  different_identifier  another identifier than the definition (a method vs a free function, an older name)
  placeholder           another identifier, and one of the two is still a placeholder (gData_<VA>, sub_<VA>_...)
  renamed_definition    the declaration agrees, but no object defines the symbol externally (static, or inline)
  interior              an address inside a function or global a source defines
  unsourced_data        an address in data that no source defines
  no_address            no declaration with an address in reach: the reference can't be placed without Game.exe
  duplicate_data        a global defined by more than one file (linker error LNK2005)
  local_copy            a function defined by more than one file: a copy kept for a call site (LNK2005)

Codex's data_cluster category (runs of globals the code treats as one object) needs the image; those references
show up here as interior, placeholder or type_disagreement.
"""
import sys, os, re, json, struct, bisect, collections

ENGINE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CATEGORIES = ("import", "runtime_library", "type_disagreement", "different_identifier", "placeholder",
              "renamed_definition", "interior", "unsourced_data", "no_address", "duplicate_data", "local_copy")
PLACEHOLDER = re.compile(r"^(?:gData_|sub_|dword_|byte_|word_|unk_|off_|stru_)|(?:^|_)[0-9A-F]{8}(?:_|$)")
MARK = re.compile(r"//\s*(0x[0-9A-Fa-f]{8})\b")
LINE = re.compile(r'^(?:(\w+)\.lib\()?([^()]+\.obj)\)? : error (LNK20(?:01|19|05)): (.*)$')
CRT = set("""abs atof atoi atol bsearch calloc ceil cos exit _exit fabs fclose feof fflush fgetc fgets floor fmod fopen
fprintf fputc fputs fread free fscanf fseek ftell fwrite getenv isalnum isalpha isdigit islower isspace isupper
isxdigit labs ldexp localtime log log10 longjmp malloc memchr memcmp memcpy memmove memset modf pow printf qsort
rand realloc remove rename rewind setjmp sin sprintf sqrt srand sscanf strcat strchr strcmp strcpy strcspn
strerror strftime stricmp strlen strncat strncmp strncpy strnicmp strpbrk strrchr strspn strstr strtod strtok
strtol strtoul tan time tolower toupper ungetc vfprintf vsprintf _snprintf _vsnprintf _snprintf_s _stricmp
_strnicmp _strdup _itoa _ltoa _ultoa _splitpath _makepath _ftol _ftol2 _ftol2_sse _CIpow _CIsqrt _CIfmod
_alloca_probe _chkstk _aullrem _aulldiv _allmul _alldiv _allrem _allshl _allshr _aullshr _purecall _onexit atexit
_beginthreadex _endthreadex _beginthread _endthread _errno _getcwd _chdir _access _mkdir _rmdir _unlink _findfirst
_findnext _findclose _stat _fstat _open _close _read _write _lseek _isatty _setmode _fileno _time64 _localtime64
_mktime64 mktime gmtime asctime ctime clock signal raise _except_handler3 _local_unwind2 _global_unwind2
_CxxThrowException __CxxFrameHandler3 _initterm _amsg_exit _cexit _XcptFilter _controlfp _control87 _clearfp
_fpreset _isnan _finite _hypot _copysign _ecvt _fcvt _gcvt wcslen wcscpy wcscmp wcsncpy wcscat _wcsicmp mbstowcs
wcstombs _mbscpy _mbslen _mbsnbcpy _vsnprintf_s sprintf_s strcpy_s strcat_s strncpy_s memcpy_s _CRT_RTC_INIT""".split())


def ident(n):
    """The identifier of a decorated name, with its class: `D2Foo::Bar`, `gnBaz`."""
    if n.startswith("??"):
        m = re.match(r"^\?\?([01])([A-Za-z_0-9]+)@", n)
        if m:
            return "%s::%s%s" % (m.group(2), "~" if m.group(1) == "1" else "", m.group(2))
        return n
    if n.startswith("?"):
        m = re.match(r"^\?([A-Za-z_0-9]+)@((?:[A-Za-z_0-9]+@)*)@", n)
        if m:
            scopes = [x for x in m.group(2).split("@") if x]
            return "::".join(list(reversed(scopes)) + [m.group(1)])
        return n
    if n.startswith("@"):
        return n[1:].split("@")[0]
    return n[1:].split("@")[0] if n.startswith("_") else n.split("@")[0]


def bare(i):
    return i.split("::")[-1]


# ---------------------------------------------------------------- objects

def coff_symbols(path):
    """{name: 'ext'|'static'} for the symbols an object defines (section number > 0)."""
    d = open(path, "rb").read()
    if d[:2] == b"\0\0":                       # /bigobj header
        nsym = struct.unpack_from("<I", d, 52)[0]; symptr = struct.unpack_from("<I", d, 48)[0]; size = 20
        secfmt = "<i"
    else:
        symptr = struct.unpack_from("<I", d, 8)[0]; nsym = struct.unpack_from("<I", d, 12)[0]; size = 18
        secfmt = "<h"
    strtab = symptr + size * nsym
    out = {}; i = 0
    while i < nsym:
        o = symptr + i * size
        raw = d[o:o + 8]
        if raw[:4] == b"\0\0\0\0":
            k = struct.unpack_from("<I", raw, 4)[0]
            name = d[strtab + k:d.index(b"\0", strtab + k)].decode("latin-1")
        else:
            name = raw.rstrip(b"\0").decode("latin-1")
        sec = struct.unpack_from(secfmt, d, o + 12)[0]
        cls = d[o + size - 2]; naux = d[o + size - 1]
        if sec > 0 and cls in (2, 3) and not name.startswith((".", "$", "??_C@", "__real@", "__xmm@")):
            if cls == 2 or name not in out:
                out[name] = "ext" if cls == 2 else "static"
        i += 1 + naux
    return out


def object_paths(build):
    """{(module, object basename): source path}, and every object path."""
    found = {}
    objs = []
    for dp, _, fs in os.walk(os.path.join(build, "CMakeFiles")):
        for f in fs:
            if not f.endswith(".obj"):
                continue
            p = os.path.join(dp, f)
            objs.append(p)
            rel = p.split(".dir" + os.sep, 1)[-1][:-4].replace(os.sep, "/")
            mod = os.path.basename(p.split(".dir" + os.sep, 1)[0])
            found[(mod, f)] = rel
    return found, objs


# ---------------------------------------------------------------- addresses in the source

HEADER = re.compile(r'^[ \t]*#[ \t]*include[ \t]+"([^"\n]+)"', re.M)
DECL_FN = re.compile(r"([A-Za-z_~][\w:~]*)\s*\(")
DECL_DATA = re.compile(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?:=|;|\{)")
CONV = {"__cdecl", "__stdcall", "__fastcall", "__thiscall", "extern", "static", "const", "struct", "unsigned",
        "signed", "int", "char", "void", "short", "long", "float", "double", "bool", "class", "union", "enum",
        "operator", "sizeof", "return", "if", "while", "for", "switch", "__declspec", "dllimport", "inline"}


def marked_names(line):
    """The identifiers a line with an address marker declares."""
    code = line.split("//")[0]
    names = []
    for m in DECL_FN.finditer(code):
        n = m.group(1)
        if bare(n) not in CONV:
            names.append(n); break
    for m in DECL_DATA.finditer(code):
        n = m.group(1)
        if n not in CONV:
            names.append(n)
    return names


class SourceIndex:
    def __init__(self):
        self.text = {}; self.marks = {}

    def read(self, path):
        if path not in self.text:
            p = os.path.join(ENGINE, path)
            self.text[path] = open(p, encoding="latin-1").read() if os.path.exists(p) else ""
        return self.text[path]

    def marks_of(self, path):
        """{identifier: VA} for the declarations with an address in a file and its headers (file first)."""
        if path in self.marks:
            return self.marks[path]
        mod = path.split("/")[1] if path.startswith("Source/") else None
        seen = []; order = [path]
        while order:
            f = order.pop(0)
            if f in seen:
                continue
            seen.append(f)
            for h in HEADER.findall(self.read(f)):
                for d in ([os.path.dirname(f)] + (["Source/" + mod] if mod else []) + ["Source/Include"]):
                    q = os.path.normpath(os.path.join(d, h)).replace(os.sep, "/")
                    if os.path.exists(os.path.join(ENGINE, q)):
                        order.append(q); break
        out = {}
        for f in seen:
            for line in self.read(f).split("\n"):
                m = MARK.search(line)
                if not m:
                    continue
                va = int(m.group(1), 16)
                for n in marked_names(line):
                    out.setdefault(n, va)
                    out.setdefault(bare(n), va)
        self.marks[path] = out
        return out


# ---------------------------------------------------------------- main

def main():
    a = sys.argv[1:]
    build, log, codex = a[:3]
    jout = a[a.index("--json") + 1] if "--json" in a else None
    mout = a[a.index("--md") + 1] if "--md" in a else None

    functions = json.load(open(os.path.join(codex, "build", "functions.json")))["functions"]
    plan = json.load(open(os.path.join(codex, "build", "data_plan.json")))
    starts = {}                                  # VA -> (identifier, size, kind)
    for f in functions:
        starts[int(f[0], 16)] = (ident(f[3]) if len(f) > 3 else None, f[1], "func")
    for d in plan["definitions"]:
        starts.setdefault(int(d["va"], 16), (d["name"], d["size"], "data"))
    # Globals and functions the source defines with an address (BSS and constants the data plan doesn't hold).
    for dp, _, fs in os.walk(os.path.join(ENGINE, "Source")):
        for f in fs:
            if not f.lower().endswith((".cpp", ".c")):
                continue
            lines = open(os.path.join(dp, f), encoding="latin-1").read().split("\n")
            for k, line in enumerate(lines):
                bm = re.match(r"^\s*//\s*(0x[0-9A-Fa-f]{8})\s*$", line)
                if bm and k + 1 < len(lines):      # a function definition, its address on the line above
                    va = int(bm.group(1), 16)
                    fm = DECL_FN.search(lines[k + 1].split("//")[0])
                    if fm and (va not in starts or starts[va][0] is None):
                        starts[va] = (fm.group(1), starts.get(va, (None, 1))[1], "func")
                    continue
                m = MARK.search(line)
                if not m or line.lstrip().startswith(("extern", "//")) or line.split("//")[0].rstrip().endswith(");"):
                    continue
                names = marked_names(line)
                if names:
                    starts.setdefault(int(m.group(1), 16), (names[-1] if "(" not in line.split("//")[0] else names[0], 1, "data"))
    sorted_vas = sorted(starts)

    objpaths, objs = object_paths(build)
    defined = collections.defaultdict(set)       # symbol -> {'ext', 'static'}
    defined_ids = collections.defaultdict(set)   # identifier -> symbols defined externally
    for p in objs:
        for name, how in coff_symbols(p).items():
            defined[name].add(how)
            if how == "ext":
                defined_ids[ident(name)].add(name)

    by_base = collections.defaultdict(set)
    for (mod, base), rel in objpaths.items():
        by_base[base].add(rel)
    src = SourceIndex()
    refs = {}                                    # (symbol, unit) -> item
    dups = {}
    for raw in open(log, encoding="latin-1"):
        m = LINE.match(raw.strip())
        if not m:
            continue
        lib, obj, code, rest = m.groups()
        unit = objpaths.get((lib or "Main", obj)) or objpaths.get(("Game", obj)) or obj
        sm = re.match(r'(?:unresolved external symbol )?(?:"[^"]*" \((\S+)\)|(\S+))', rest)
        sym = (sm.group(1) or sm.group(2)) if sm else rest
        if code == "LNK2005":
            other = re.search(r"already defined in (\S+)$", rest)
            o = other.group(1) if other else "?"
            lm = re.match(r"^(\w+)\.lib\((.+)\)$", o)
            if lm and (lm.group(1), lm.group(2)) in objpaths:
                o = objpaths[(lm.group(1), lm.group(2))]
            elif len(by_base.get(o, ())) == 1:
                o = next(iter(by_base[o]))
            d = dups.setdefault(sym, dict(units=set(), module=unit.split("/")[1] if unit.startswith("Source/") else "?"))
            d["units"].update({unit, o})
            continue
        refs.setdefault((sym, unit), dict(symbol=sym, unit=unit, refs=0))["refs"] += 1

    items = []
    for (sym, unit), it in refs.items():
        idn = ident(sym)
        it.update(identifier=idn, module=unit.split("/")[1] if unit.startswith("Source/") else "?")
        if sym.startswith("__imp_"):
            cat = "import"
        else:
            va = src.marks_of(unit).get(idn) if unit.startswith("Source/") else None
            if va is None:
                va = src.marks_of(unit).get(bare(idn)) if unit.startswith("Source/") else None
            it["address"] = "0x%08X" % va if va is not None else None
            if va is None:
                cat = "runtime_library" if bare(idn).lstrip("_") in CRT or bare(idn) in CRT else "no_address"
            elif va in starts:
                dname, size, kind = starts[va]
                it["definition"] = dname
                syms = defined_ids.get(dname or "", set()) | defined_ids.get(bare(dname or ""), set())
                if dname is None:
                    cat = "unsourced_data" if kind == "data" else "no_address"
                elif bare(dname) == bare(idn):
                    cat = "type_disagreement" if syms else "renamed_definition"
                elif PLACEHOLDER.search(bare(dname)) or PLACEHOLDER.search(bare(idn)):
                    cat = "placeholder"
                else:
                    cat = "different_identifier"
            else:
                j = bisect.bisect_right(sorted_vas, va) - 1
                if j >= 0 and va < sorted_vas[j] + starts[sorted_vas[j]][1]:
                    cat = "interior"; it["definition"] = "%s+0x%X" % (starts[sorted_vas[j]][0], va - sorted_vas[j])
                elif bare(idn).lstrip("_") in CRT:
                    cat = "runtime_library"
                else:
                    cat = "unsourced_data"
        it["category"] = cat
        items.append(it)
    for sym, d in dups.items():
        units = d["units"]
        kind = "local_copy" if re.match(r"^(\?[^@]+@@[YQAIEUS]|@|_\w+@\d+$)", sym) and "@@3" not in sym else "duplicate_data"
        units.discard("?")
        items.append(dict(symbol=sym, identifier=ident(sym), category=kind, units=sorted(units), refs=len(units),
                          module=d["module"]))

    report = summarise(items)
    if jout:
        json.dump(dict(report, items=items), open(jout, "w"), indent=1)
    if mout:
        open(mout, "w", newline="\n").write(markdown(report, items))
    print(json.dumps(report["totals"], indent=1))


def summarise(items):
    tot = collections.OrderedDict((c, dict(refs=0, symbols=set())) for c in CATEGORIES)
    mods = collections.defaultdict(lambda: collections.Counter())
    for it in items:
        tot[it["category"]]["refs"] += it["refs"]
        tot[it["category"]]["symbols"].add(it["symbol"])
        mods[it["module"]][it["category"]] += it["refs"]
    totals = {c: dict(refs=v["refs"], symbols=len(v["symbols"])) for c, v in tot.items()}
    totals["total"] = dict(refs=sum(v["refs"] for v in tot.values()),
                           symbols=len({it["symbol"] for it in items}))
    return dict(totals=totals, modules={m: dict(c) for m, c in mods.items()})


SHORT = {"import": "import", "runtime_library": "crt", "type_disagreement": "type", "different_identifier": "ident",
         "placeholder": "plchld", "renamed_definition": "renamed", "interior": "inter", "unsourced_data": "unsrc",
         "no_address": "noaddr", "duplicate_data": "dup", "local_copy": "copy"}


def markdown(rep, items):
    L = ["## Totals", "", "| Category | References | Symbols |", "|---|---:|---:|"]
    for c in CATEGORIES + ("total",):
        t = rep["totals"][c]
        L.append("| %s | %d | %d |" % ("**total**" if c == "total" else c, t["refs"], t["symbols"]))
    L += ["", "## By module (references)", "",
          "| Module | " + " | ".join(SHORT[c] for c in CATEGORIES) + " | total |",
          "|---|" + "---:|" * (len(CATEGORIES) + 1)]
    for m in sorted(rep["modules"], key=lambda m: -sum(rep["modules"][m].values())):
        c = rep["modules"][m]
        L.append("| %s | %s | %d |" % (m, " | ".join(str(c.get(k, 0)) for k in CATEGORIES), sum(c.values())))
    L += ["", "## Examples, per category", ""]
    for c in CATEGORIES:
        its = sorted((it for it in items if it["category"] == c), key=lambda it: (-it["refs"], it["symbol"]))
        if not its:
            continue
        L.append("**%s** (%d symbols)" % (c, len({it['symbol'] for it in its})))
        L.append("")
        for it in its[:8]:
            where = it.get("unit") or ", ".join(it.get("units", []))[:120]
            extra = (" -> `%s`" % it["definition"]) if it.get("definition") else ""
            addr = (" at %s" % it["address"]) if it.get("address") else ""
            L.append("- `%s`%s%s, in %s" % (it["identifier"], addr, extra, where))
        L.append("")
    return "\n".join(L) + "\n"


if __name__ == "__main__":
    main()
