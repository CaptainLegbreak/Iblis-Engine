#!/usr/bin/env python3
"""Bring the engine's game source up to an Iblis Codex commit.

    python tools/codex_sync.py CODEX_DIR [--report FILE]

CODEX_DIR is a checkout of Iblis Codex at the commit to sync to. tools/CODEX_SYNC names the Codex commit the
engine's Source/ was last synced to. A developer tool: the engine's build never runs it and never needs Codex.

The engine's game source is a copy of Codex's Source/, with two differences the sync makes every time:

1. The game's initialised data is written into the files. Codex renders it from the user's Game.exe at build time
   (#include "gen/data/...", tools/gendata.py); the engine holds it as source. The sync needs no Game.exe: it
   rebuilds the bytes of every record from the engine's current data text (inverting gendata's rendering with the
   last synced plan's type models), checks the inversion by re-rendering every record and comparing with the
   engine's text, then renders the new plan with gendata's own renderer and writes it in place of the includes.
   Records Codex now defines in its own source stay as Codex wrote them.
2. The Codex build markers (`// build: ...` lines, directions for Codex's linker) are dropped.

Files under Source/ that the last synced Codex tree doesn't have are the engine's own (Source/Storm/pklib,
Source/Main/res, ...) and are left alone. Files Codex removed are removed.

Bytes the new plan needs that no old record held can't be known without Game.exe: they are written as 0 and
listed in the report (missing_bytes), to check against Game.exe.
"""
import sys, os, re, json, struct, shutil, subprocess, collections

ENGINE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SYNC_FILE = os.path.join(ENGINE, "tools", "CODEX_SYNC")
MARKER = re.compile(r"\s*// build:")


def git(codex, *args):
    return subprocess.run(["git", "-C", codex] + list(args), check=True, capture_output=True).stdout


def main():
    args = sys.argv[1:]
    if not args:
        sys.exit(__doc__)
    codex = os.path.abspath(args[0])
    report_path = args[args.index("--report") + 1] if "--report" in args else None
    prev = open(SYNC_FILE).read().split()[0]
    head = git(codex, "rev-parse", "HEAD").decode().strip()
    sys.path.insert(0, os.path.join(codex, "tools"))
    global G
    import gendata as G

    old = json.loads(git(codex, "show", prev + ":build/data_plan.json"))
    new = json.load(open(os.path.join(codex, "build", "data_plan.json")))
    old_tree = set(git(codex, "ls-tree", "-r", "--name-only", prev, "Source").decode().split("\n")) - {""}
    report = collections.defaultdict(list)

    image = SparseImage()
    invert_old(old, image, report)
    rendered = render_new(new, image, codex, report)

    # The new tree: Codex's Source/, rendered files in place, markers dropped; engine-only files kept.
    new_tree = []
    for dp, _, fs in os.walk(os.path.join(codex, "Source")):
        for f in fs:
            new_tree.append(os.path.relpath(os.path.join(dp, f), codex).replace(os.sep, "/"))
    for rel in old_tree - set(new_tree):
        p = os.path.join(ENGINE, rel)
        if os.path.exists(p):
            os.remove(p)
            report["removed"].append(rel)
    markers = 0
    for rel in new_tree:
        dst = os.path.join(ENGINE, rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        if rel in rendered:
            text = rendered[rel]
        else:
            raw = open(os.path.join(codex, rel), "rb").read()
            if not rel.lower().endswith((".cpp", ".c", ".h", ".inl")):
                open(dst, "wb").write(raw)
                continue
            text = raw.decode("latin-1")
        text, n = drop_markers(text)
        markers += n
        open(dst, "w", encoding="latin-1", newline="").write(text)
    left = [rel for rel in new_tree if rel.lower().endswith((".cpp", ".c", ".h"))
            and "gen/data/" in open(os.path.join(ENGINE, rel), encoding="latin-1").read()]
    report["include_left"] = left
    open(SYNC_FILE, "w").write(head + "\n")

    summary = {k: len(v) for k, v in report.items()}
    summary["markers_dropped"] = markers
    print("synced %s -> %s: %s" % (prev[:10], head[:10], json.dumps(summary)))
    if report_path:
        json.dump(dict(report, summary=summary), open(report_path, "w"), indent=1)
    if report["mismatch"] or report["render_error"] or left:
        sys.exit("the sync is incomplete: see mismatch, render_error and include_left")


def drop_markers(text):
    """Remove `// build:` lines; where a run of them stood between two blank lines, one blank line goes too."""
    if "// build:" not in text:
        return text, 0
    lines = text.split("\n"); out = []; i = 0; n = 0
    while i < len(lines):
        if MARKER.match(lines[i]):
            j = i
            while j < len(lines) and MARKER.match(lines[j]):
                j += 1
            n += j - i
            if out and out[-1].strip() == "" and j < len(lines) and lines[j].strip() == "":
                j += 1
            i = j
            continue
        out.append(lines[i]); i += 1
    return "\n".join(out), n


# ---------------------------------------------------------------- reading rendered initialisers

def split_top(s):
    """'{ a, b, ... }' -> ['a', 'b', ...]; a leaf -> None."""
    s = s.strip()
    if not s.startswith("{"):
        return None
    body = s[1:-1]
    items = []; depth = 0; q = False; cur = []; i = 0
    while i < len(body):
        c = body[i]
        if q:
            cur.append(c)
            if c == "\\":
                cur.append(body[i + 1]); i += 2; continue
            if c == '"':
                q = False
        elif c == '"':
            q = True; cur.append(c)
        elif c in "{(":
            depth += 1; cur.append(c)
        elif c in "})":
            depth -= 1; cur.append(c)
        elif c == "," and depth == 0:
            items.append("".join(cur).strip()); cur = []
        else:
            cur.append(c)
        i += 1
    last = "".join(cur).strip()
    if last or items:
        items.append(last)
    return items


ESC = {"n": 10, "r": 13, "t": 9, "\\": 92, '"': 34, "?": 63, "'": 39, "a": 7, "b": 8, "f": 12, "v": 11}


def unescape(lit):
    """C string literal(s), possibly concatenated or L-prefixed -> bytes."""
    out = []; wide = False
    for m in re.finditer(r'(L?)"((?:[^"\\]|\\.)*)"', lit):
        wide = wide or bool(m.group(1))
        s = m.group(2); i = 0
        while i < len(s):
            if s[i] != "\\":
                out.append(ord(s[i])); i += 1; continue
            e = s[i + 1]
            if e == "x":
                j = i + 2
                while j < len(s) and s[j] in "0123456789abcdefABCDEF":
                    j += 1
                out.append(int(s[i + 2:j], 16)); i = j
            elif e in "01234567":
                j = i + 1
                while j < len(s) and j < i + 4 and s[j] in "01234567":
                    j += 1
                out.append(int(s[i + 1:j], 8)); i = j
            else:
                out.append(ESC[e]); i += 2
    if wide:
        return b"".join(struct.pack("<H", c) for c in out)
    return bytes(out)


def parse_int(t, size):
    t = t.strip()
    if t == "(-2147483647 - 1)":
        v = -(1 << 31)
    elif t == "(-9223372036854775807i64 - 1)":
        v = -(1 << 63)
    else:
        t = re.sub(r"(ui64|i64|u|U|l|L)+$", "", t)
        v = int(t, 0) if not re.fullmatch(r"-?0\d+", t) else int(t, 10)
    return (v & ((1 << (8 * size)) - 1)).to_bytes(size, "little")


def strip_cast(t):
    t = t.strip()
    if t.startswith("("):
        d = 0
        for i, c in enumerate(t):
            d += c == "("; d -= c == ")"
            if d == 0:
                return t[1:i], t[i + 1:].strip()
    return None, t


def fill(m, off, text, raw, relocs):
    """Writes the bytes a rendered value stands for, by the plan's type model."""
    k = m["k"]; n = m["size"]
    if k in ("prim", "enum", "ptr") and off in relocs:
        return
    if k == "prim":
        if m["kind"] == "f":
            raw[off:off + n] = struct.pack("<f" if n == 4 else "<d", float(text.strip().rstrip("f")))
        elif m["kind"] == "b":
            raw[off] = 1 if text.strip() == "true" else 0
        else:
            raw[off:off + n] = parse_int(text, n)
    elif k == "enum":
        raw[off:off + n] = parse_int(strip_cast(text)[1], n)
    elif k == "ptr":
        if text.strip() != "0":
            raw[off:off + 4] = parse_int(strip_cast(text)[1], 4)
    elif k == "arr":
        em = m["elem"]; items = split_top(text)
        if items is None:
            b = unescape(text); raw[off:off + len(b)] = b
            return
        if items == ["0"] and em["k"] not in ("prim", "ptr", "enum"):
            return                           # "{ 0 }": every element zero
        for i, it in enumerate(items):
            fill(em, off + i * em["size"], it, raw, relocs)
    elif k in ("struct", "union"):
        mem = m["members"][:1] if k == "union" else m["members"]
        for (nm, mo, mm), it in zip(mem, split_top(text)):
            fill(mm, off + mo, it, raw, relocs)
    else:
        raise ValueError("model kind " + k)


def bytes_fields(sdef):
    return [(f, int(sz) if sz else 4) for f, sz in re.findall(r"    (?:unsigned char (b\d+)\[(\d+)\]|const void\* p\d+);", sdef)]


# ---------------------------------------------------------------- the sparse image

class SparseImage:
    def __init__(self):
        self.bytes = {}; self.texts = {}; self.missing = set()
        self.region_of = {}; self.reloc_vals = {}

    def read(self, va, n):
        if n == 4096 and va in self.texts:   # gendata.image_text: a literal's text, up to its NUL
            out = bytearray()
            while self.texts.get(va + len(out), 0) != 0:
                out.append(self.texts[va + len(out)])
            if va + len(out) not in self.texts:
                self.missing.add(va + len(out))
            return bytes(out) + b"\0"
        out = bytearray()
        for i in range(n):
            b = self.bytes.get(va + i)
            if b is None:
                self.missing.add(va + i); b = 0
            out.append(b)
        return bytes(out)

    def region(self, va):
        return self.region_of.get(va)

    def relocs_in(self, va, n):
        return sorted(x for x in self.reloc_vals if va <= x < va + n)

    def ptr(self, va):
        return self.reloc_vals[va]


engine_text = {}


def etext(rel):
    if rel not in engine_text:
        engine_text[rel] = open(os.path.join(ENGINE, rel), encoding="latin-1").read()
    return engine_text[rel]


def find_with(root, needle):
    for dp, _, fs in os.walk(os.path.join(root, "Source")):
        for f in fs:
            q = os.path.join(dp, f)
            if needle in open(q, encoding="latin-1").read():
                return os.path.relpath(q, root).replace(os.sep, "/")
    return None


def init_of(r):
    rel = r["file"]
    if not os.path.exists(os.path.join(ENGINE, rel)):
        rel = find_with(ENGINE, r["head"])
        if rel is None:
            return None
    t = etext(rel)
    i = t.find(r["head"])
    if i < 0:
        return None
    return t[i + len(r["head"]):t.find(r["tail"], i + len(r["head"]))]


def invert_old(old, image, report):
    for r in old["definitions"]:
        if r.get("sourced"):
            continue                         # Codex's own text, not gendata's rendering; Codex keeps it
        va = int(r["va"], 16)
        init = init_of(r)
        if init is None:
            report["old_not_found"].append(r["va"]); continue
        raw = bytearray(r["size"])
        relocs = {p[0]: int(p[1], 16) for p in r["pointers"]}
        try:
            if r["form"] == "string":
                b = unescape(init); raw[:len(b)] = b
            elif r["form"] == "bytes":
                pos = 0
                for (f, sz), it in zip(bytes_fields(r["struct"]), split_top(init)):
                    if f:
                        for k, x in enumerate(split_top(it) or [it]):
                            raw[pos + k] = int(x, 0)
                    pos += sz
            else:
                fill(r["model"], 0, init, raw, relocs)
        except Exception as e:
            report["parse_error"].append([r["va"], repr(e)[:200]]); continue
        for off, t in relocs.items():
            raw[off:off + 4] = struct.pack("<I", t)
        for i, b in enumerate(raw):
            image.bytes[va + i] = b
        check_and_take_literals(r, old, init, image, report)


def check_and_take_literals(r, plan, want, image, report):
    """Re-renders r from the image (literal pointers as placeholders) and compares with the engine's text; the
    literals' texts are read from the matching places."""
    va = int(r["va"], 16)
    raw = bytes(image.bytes.get(va + i, 0) for i in range(r["size"]))
    relocs = {p[0]: int(p[1], 16) for p in r["pointers"]}
    ent = plan["files"].get(r["file"], {})
    fn_types = (r.get("fn_types") if G.is_static(r) else ent.get("fn_types")) or {}
    by_target = {}
    for off, t, how, nm, o, kind in r["pointers"]:
        by_target.setdefault(int(t, 16), (how, nm, o, kind))

    def sym(t_va, spell, fn=None):
        how, nm, o, kind = by_target[t_va]
        if how == "literal":
            return G.sym_expr(("literal", b"@@LIT%08X@@" % t_va, 0, "string"), spell, fn)
        if how == "owner" and kind == "func" and not (fn if fn is not None else "(" in spell):
            ft = fn_types.get(nm)
            if ft:
                return "(%s)(unsigned int)(%s)&%s" % (spell, ft, nm)
        return G.sym_expr((how, nm, o, kind), spell, fn)
    try:
        _, _, _, txt, _ = G.def_text(dict(r, va_int=va, relocs=relocs), raw, sym, "", fixed=True)
    except Exception as e:
        report["rerender_error"].append([r["va"], repr(e)[:200]]); return
    if G.is_static(r):
        txt = G.one_line(txt)
    parts = re.split('"@@LIT([0-9A-F]{8})@@"', txt)
    rx = "".join(re.escape(p) if i % 2 == 0 else r'(L?"(?:[^"\\]|\\.)*"(?: L?"(?:[^"\\]|\\.)*")*)'
                 for i, p in enumerate(parts))
    m = re.fullmatch(rx, want, re.S)
    if not m:
        report["mismatch"].append([r["va"], r["file"]]); return
    for t_hex, lit in zip(parts[1::2], m.groups()):
        t_va = int(t_hex, 16)
        for i, c in enumerate(unescape(lit) + b"\0"):
            image.texts[t_va + i] = c


def render_new(new, image, codex, report):
    for r in new["definitions"]:
        va = int(r["va"], 16)
        image.region_of[va] = r["region"]
        for p in r["pointers"]:
            image.reloc_vals[va + p[0]] = int(p[1], 16)
            if p[2] == "literal":
                image.region_of[int(p[1], 16)] = "rdata"
    by_file = collections.defaultdict(list)
    for r in new["definitions"]:
        by_file[r["file"]].append(r)

    out = {}

    def source(rel):
        if rel not in out:
            out[rel] = open(os.path.join(codex, rel), encoding="latin-1").read()
        return out[rel]

    def put(rel, include, text):
        s = source(rel)
        line = '#include "%s"' % include
        if s.count(line) != 1:
            report["include_line_differs"].append([rel, include])
            line = '#include "%s"' % G.include_path(rel)
        if s.count(line) != 1:
            report["render_error"].append([rel, "no include line " + include]); return
        out[rel] = s.replace(line, "\n".join(text.split("\n")[1:]).strip("\n"))

    for f, ent in sorted(new["files"].items()):
        if ent["state"] not in G.GEN_STATES:
            continue
        image.missing.clear()
        try:
            inc, statics = G.render_parts(f, ent, by_file.get(f, []), image)
        except G.PlanError as e:
            report["render_error"].append([f, str(e)[:300]]); continue
        if image.missing:
            report["missing_bytes"].append([f, ["0x%08X" % x for x in sorted(image.missing)]])
        if ent.get("include"):
            put(f, ent["include"], inc)
        for path, text in statics.items():
            rel = f if os.path.exists(os.path.join(codex, f)) and '#include "%s"' % path in source(f) \
                else find_with(codex, '#include "%s"' % path)
            put(rel, path, text)
    return out


if __name__ == "__main__":
    main()
