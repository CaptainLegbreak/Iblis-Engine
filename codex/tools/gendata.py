#!/usr/bin/env python3
import os, sys, re, json, glob, struct, bisect, difflib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))


LF_MODIFIER, LF_POINTER, LF_PROCEDURE, LF_MFUNCTION, LF_ARGLIST, LF_FIELDLIST, LF_BITFIELD = 0x1001, 0x1002, 0x1008, 0x1009, 0x1201, 0x1203, 0x1205
LF_ARRAY, LF_CLASS, LF_STRUCTURE, LF_UNION, LF_ENUM = 0x1503, 0x1504, 0x1505, 0x1506, 0x1507
LF_MEMBER, LF_BCLASS, LF_VFUNCTAB, LF_STMEMBER, LF_METHOD, LF_NESTTYPE, LF_ONEMETHOD, LF_ENUMERATE, LF_INDEX = 0x150D, 0x1400, 0x1409, 0x150E, 0x150F, 0x1510, 0x1511, 0x1502, 0x1404
FWDREF = 0x80

CV_PRIM = {0x03: ("void", 0, "v"), 0x70: ("char", 1, "c"), 0x10: ("signed char", 1, "s"), 0x20: ("unsigned char", 1, "u"),
           0x68: ("signed char", 1, "s"), 0x69: ("unsigned char", 1, "u"), 0x71: ("wchar_t", 2, "u"),
           0x11: ("short", 2, "s"), 0x21: ("unsigned short", 2, "u"), 0x72: ("short", 2, "s"), 0x73: ("unsigned short", 2, "u"),
           0x12: ("long", 4, "s"), 0x22: ("unsigned long", 4, "u"), 0x74: ("int", 4, "s"), 0x75: ("unsigned int", 4, "u"),
           0x13: ("__int64", 8, "s"), 0x23: ("unsigned __int64", 8, "u"), 0x76: ("__int64", 8, "s"), 0x77: ("unsigned __int64", 8, "u"),
           0x30: ("bool", 1, "b"), 0x40: ("float", 4, "f"), 0x41: ("double", 8, "f"), 0x42: ("double", 8, "f"), 0x08: ("long", 4, "s")}
CALLCONV = {0x00: "__cdecl", 0x04: "__fastcall", 0x07: "__stdcall", 0x0B: "__thiscall"}


PRIM_KIND = {"char": ("c", 1), "signed char": ("s", 1), "unsigned char": ("u", 1), "bool": ("b", 1), "BYTE": ("u", 1),
             "BOOL": ("s", 4), "short": ("s", 2), "unsigned short": ("u", 2), "wchar_t": ("u", 2), "WORD": ("u", 2),
             "int": ("s", 4), "unsigned int": ("u", 4), "unsigned": ("u", 4), "long": ("s", 4), "unsigned long": ("u", 4),
             "DWORD": ("u", 4), "float": ("f", 4), "double": ("f", 8), "__int64": ("s", 8), "unsigned __int64": ("u", 8),
             "long long": ("s", 8), "unsigned long long": ("u", 8), "__int8": ("s", 1), "unsigned __int8": ("u", 1),
             "__int16": ("s", 2), "unsigned __int16": ("u", 2), "__int32": ("s", 4), "unsigned __int32": ("u", 4),
             "LONG": ("s", 4), "ULONG": ("u", 4), "UINT": ("u", 4), "int8_t": ("s", 1), "uint8_t": ("u", 1),
             "int16_t": ("s", 2), "uint16_t": ("u", 2), "int32_t": ("s", 4), "uint32_t": ("u", 4), "size_t": ("u", 4),
             "WPARAM": ("u", 4), "LPARAM": ("s", 4)}
HANDLES = ("HANDLE", "HWND", "HINSTANCE", "HMODULE", "LPVOID", "LPSTR", "LPCSTR", "HDC", "HBITMAP", "HFONT", "HKEY",
           "HGLOBAL", "FARPROC", "SOCKET")


class Unresolved(Exception):
    pass


class NotRepresentable(Exception):
    pass


def int_lit(v, size, kind):
    if kind in ("s", "c"):
        lim = 1 << (8 * size - 1)
        v = v - (1 << (8 * size)) if v >= lim else v
        if size == 4 and v == -(1 << 31):
            return "(-2147483647 - 1)"
        if size == 8:
            return ("(-9223372036854775807i64 - 1)" if v == -(1 << 63) else "%di64" % v)
        return "%d" % v
    if size == 8:
        return "0x%Xui64" % v
    return "0x%X" % v if v > 9 else "%d" % v


def float_lit(b):
    import math
    if len(b) == 4:
        v = struct.unpack("<f", b)[0]
        if math.isnan(v) or math.isinf(v):
            raise NotRepresentable("float_nan_or_infinity")
        for p in range(1, 10):
            s = "%.*g" % (p, v)
            try:
                if struct.pack("<f", float(s)) == b:
                    break
            except OverflowError:
                continue
        suf = "f"
    else:
        v = struct.unpack("<d", b)[0]
        if math.isnan(v) or math.isinf(v):
            raise NotRepresentable("float_nan_or_infinity")
        s = repr(v); suf = ""
    if "e" not in s and "." not in s and "inf" not in s:
        s += ".0"
    elif "e" in s and "." not in s.split("e")[0]:
        a, e = s.split("e"); s = a + ".0e" + e
    return s + suf


def c_literal(text, wide):
    out = ['L"' if wide else '"']; hexed = False; prev = None
    for ch in text:
        c = ord(ch) if wide else ch
        s = None
        if c == 0x22:
            s = '\\"'
        elif c == 0x5C:
            s = "\\\\"
        elif c == 0x0A:
            s = "\\n"
        elif c == 0x0D:
            s = "\\r"
        elif c == 0x09:
            s = "\\t"
        elif c == 0x3F and prev == 0x3F:
            s = "\\?"
        elif 0x20 <= c < 0x7F:
            s = chr(c)
            if hexed and s in "0123456789abcdefABCDEF":
                out.append('" ' + ('L"' if wide else '"'))
        else:
            out.append(("\\x%04X" if wide else "\\x%02X") % c); hexed = True; prev = c; continue
        out.append(s); hexed = False; prev = c
    out.append('"')
    return "".join(out)


def char_literal(raw):
    k = raw.find(b"\0")
    if k < 0 or any(raw[k:]):
        return None
    if k == 0 and len(raw) > 1:
        return None
    t = raw[:k]
    if any(c < 0x20 and c not in (9, 10, 13) for c in t):
        return None
    return c_literal(t, False)


class Ctx:

    def __init__(self, va, raw, relocs, sym):
        self.va, self.raw, self.relocs, self.sym = va, raw, relocs, sym
        self.used = set()


def render(m, off, ctx, top=False):
    raw = ctx.raw; k = m["k"]; n = m["size"]
    for r in ctx.relocs:
        if off <= r < off + n and k not in ("arr", "struct", "union") and not (r == off and n == 4 and k in ("ptr", "prim", "enum")):
            raise NotRepresentable("relocation_inside_" + k)
    if k == "prim":
        b = raw[off:off + n]
        if off in ctx.relocs:
            if m["kind"] == "f":
                raise NotRepresentable("relocation_in_float")
            ctx.used.add(off); return ctx.sym(ctx.relocs[off], m["name"], False)
        if m["kind"] == "f":
            return float_lit(b)
        v = int.from_bytes(b, "little")
        if m["kind"] == "b":
            if v > 1:
                raise NotRepresentable("bool_not_0_or_1")
            return "true" if v else "false"
        return int_lit(v, n, m["kind"])
    if k == "enum":
        if off in ctx.relocs:
            raise NotRepresentable("relocation_in_enum")
        v = int.from_bytes(raw[off:off + n], "little")
        return "(%s)%s" % (m["name"], int_lit(v, n, m["kind"]))
    if k == "ptr":
        if off in ctx.relocs:
            ctx.used.add(off); return ctx.sym(ctx.relocs[off], m["spell"], m.get("fn"))
        v = struct.unpack_from("<I", raw, off)[0]
        if v == 0:
            return "0"
        if not m.get("spell"):
            raise NotRepresentable("pointer_unspellable")
        return "(%s)0x%X" % (m["spell"], v)
    if k == "arr":
        em = m["elem"]; es = em["size"]
        if em["k"] == "prim" and em["kind"] == "c" and not any(off <= r < off + n for r in ctx.relocs):
            lit = char_literal(raw[off:off + n])
            if lit:
                return lit
        items = [render(em, off + i * es, ctx) for i in range(m["n"])]
        return brace(items, em, top)
    if k in ("struct", "union"):
        mem = m["members"]
        if k == "union":
            nm, mo, mm = mem[0]
            cover = set(range(mo, mo + mm["size"]))
            if any(raw[off + i] for i in range(n) if i not in cover) or any(off <= r < off + n and (r - off) not in cover for r in ctx.relocs):
                raise NotRepresentable("union_tail_not_zero")
            return "{ %s }" % render(mm, off + mo, ctx)
        cover = bytearray(n); items = []; last = -1
        for nm, mo, mm in mem:
            if mo < last:
                raise NotRepresentable("members_out_of_order")
            last = mo + mm["size"]
            for i in range(mo, min(mo + mm["size"], n)):
                cover[i] = 1
            items.append(render(mm, off + mo, ctx))
        for i in range(n):
            if not cover[i] and (raw[off + i] or any(r <= off + i < r + 4 for r in ctx.relocs)):
                raise NotRepresentable("padding_not_zero")
        while len(items) > 1 and is_zero(items[-1]):
            items.pop()
        return "{ " + ", ".join(items) + " }"
    raise NotRepresentable(m.get("why", "type"))


def is_zero(s):
    return s in ("0", "0.0f", "0.0", "false", '""') or re.fullmatch(r"\{ (0|0\.0f?|false)(, (0|0\.0f?|false))* \}", s or "") is not None or s == "{ 0 }"


def brace(items, em, top):
    while items and is_zero(items[-1]):
        items.pop()
    if not items:
        return "{ 0 }"
    if em["k"] in ("prim", "ptr", "enum") and len(items) > 16:
        rows = [", ".join(items[i:i + 16]) for i in range(0, len(items), 16)]
        return "{\n    " + ",\n    ".join(rows) + "\n}"
    if len(items) > 1 and em["k"] in ("struct", "union", "arr"):
        return "{\n    " + ",\n    ".join(items) + "\n}"
    return "{ " + ", ".join(items) + " }"


def bytes_form(va, raw, relocs, ctx_sym, region):
    fields = []; init = []; pos = 0; k = 0; n = len(raw)
    for r in sorted(relocs):
        if r < pos:
            raise NotRepresentable("overlapping_relocations")
        if r > pos:
            fields.append("    unsigned char b%d[%d];" % (k, r - pos)); init.append(byte_list(raw[pos:r])); k += 1
        fields.append("    const void* p%d;" % k); init.append(ctx_sym(relocs[r], "const void*")); k += 1
        pos = r + 4
    if pos < n:
        fields.append("    unsigned char b%d[%d];" % (k, n - pos)); init.append(byte_list(raw[pos:])); k += 1
    tname = "d2data_%08X_t" % va
    sdef = "#pragma pack(push, 1)\nstruct %s\n{\n%s\n};\n#pragma pack(pop)" % (tname, "\n".join(fields))
    return tname, sdef, "{\n    " + ",\n    ".join(init) + "\n}"


def byte_list(b):
    while len(b) > 1 and b[-1] == 0:
        b = b[:-1]
    items = ["0x%02X" % c for c in b] or ["0"]
    if len(items) <= 16:
        return "{ " + ", ".join(items) + " }"
    return "{\n        " + ",\n        ".join(", ".join(items[i:i + 16]) for i in range(0, len(items), 16)) + "\n    }"


FUNC_DECL = re.compile(r"^\s*(?:extern\s+(?:\"C\"\s+)?)?(?:[\w:<>\*&\s]+?)\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*;\s*//\s*(0x[0-9A-Fa-f]{8})\b")
DEF_MARK = re.compile(r"^\s*//\s*(0x[0-9A-Fa-f]{8})\s*$")
FUNC_HEAD = re.compile(r"^[^;{}()]*?\b([A-Za-z_]\w*(?:::~?[A-Za-z_]\w*)?)\s*\(")
IDENT = re.compile(r"^[A-Za-z_]\w*$")


STATIC_HEAD = "// generated from your Game.exe by tools/gendata.py; do not commit"
MARK_EOL = re.compile(r"//\s*(0x[0-9A-Fa-f]{8})\s*$")


def static_include_path(f, name):
    return "/".join([GEN_DIR, "data", os.path.splitext(f)[0], name + ".inc"])


def one_line(init):
    return re.sub(r"\s*\n\s*", " ", init).replace("{ }", "{ 0 }")


class Image:

    def __init__(self, pe):
        import image_data as D
        self.pe = pe; self.D = D
        self.relocs = D.base_relocations(pe); self.lay = D.image_layout(pe)
        B = pe.image_base
        self.text = next(((B + s["va"], B + s["va"] + s["vsize"]) for s in self.lay["sections"] if s["name"] == ".text"), (0, 0))

    def read(self, va, n):
        return self.D.vread(self.pe, va, n)

    def relocs_in(self, va, n):
        i = bisect.bisect_left(self.relocs, va); out = []
        while i < len(self.relocs) and self.relocs[i] < va + n:
            out.append(self.relocs[i]); i += 1
        return out

    def region(self, va):
        if self.text[0] <= va < self.text[1]:
            return "text"
        lo, hi = self.lay["rdata_section"]
        if lo <= va < hi:
            return "rdata"
        lo, hi = self.lay["data_init"][0], self.lay["data_bss"][1]
        if lo <= va < hi:
            return "data"
        return None

    def ptr(self, va):
        return struct.unpack("<I", self.read(va, 4))[0]


def sym_expr(res, spell, fn=None):
    how, nm, off, kind = res
    fp = fn if fn is not None else "(" in spell
    if how == "literal":
        e = c_literal(nm, False)
        if spell in ("const char*", "char const*"):
            return e
        e = "(void*)" + e if fp else e
    else:
        e = "&" + nm
        if off:
            e = "((char*)%s + %d)" % (e, off)
        if kind == "func" and not fp:
            e = "(unsigned int)" + e
        elif kind != "func" and fp:
            e = "(void*)" + e
    if spell in ("void*", "const void*") and e.startswith("(void*)"):
        e = e[len("(void*)"):]
    return "(%s)%s" % (spell, e)


def escape_parens(text):
    out = []; q = None; i = 0
    while i < len(text):
        c = text[i]
        if q:
            if c == "\\":
                out.append(text[i:i + 2]); i += 2; continue
            if c == q:
                q = None
            elif c == "(":
                out.append("\\050"); i += 1; continue
        elif c in "\"'":
            q = c
        out.append(c); i += 1
    return "".join(out)


ESCAPE_PAREN = "paren"


def def_text(d, raw, sym, ec, decorated=None, f=None, on_fallback=None, fixed=False):
    fwd, sdef, head, init, tail = _def_text(d, raw, sym, ec, decorated, f, on_fallback, fixed)
    if d.get("escape") == ESCAPE_PAREN:
        init = escape_parens(init)
    elif d.get("escape"):
        raise NotRepresentable("unknown_literal_escape")
    return fwd, sdef, head, init, tail


def _def_text(d, raw, sym, ec, decorated=None, f=None, on_fallback=None, fixed=False):
    va = d["va_int"]; init = None
    if d.get("linkage") == "static":
        init = render(d["model"], 0, Ctx(va, raw, d["relocs"], sym), top=True)
        return None, None, d["head"], one_line(init), d["tail"]
    if d["form"] in ("declared", "declared_owner"):
        try:
            init = render(d["model"], 0, Ctx(va, raw, d["relocs"], sym), top=True)
        except NotRepresentable as e:
            if fixed:
                raise
            d.update(form="bytes", why="value_" + str(e), cname="gData_%08X" % va, alias=True,
                     decorated=decorated(f, d["name"]) if decorated else None)
            if on_fallback:
                on_fallback()
    if d["form"] == "string":
        cst = "const " if d["region"] == "rdata" else ""
        init = char_literal(raw)
        if init is None:
            raise NotRepresentable("string_not_a_text")
        return ("%s%schar %s[%d]; // 0x%08X" % (ec, cst, d["cname"], d["size"], va), None,
                "%s%schar %s[%d] = " % (ec, cst, d["cname"], d["size"]), init, "; // 0x%08X" % va)
    if init is not None:
        if fixed and "head" in d:
            return d.get("fwd"), None, d["head"], init, d["tail"]
        raise NotRepresentable("no_declarators")
        return fwd, None, head, init, tail
    tname, sdef, init = bytes_form(va, raw, d["relocs"], sym, d["region"])
    cst = "const " if d["region"] == "rdata" else ""
    tail = "; // 0x%08X" % va
    if d.get("declared") and d.get("decorated"):
        tail += '\n#pragma comment(linker, "/alternatename:%s=_%s")' % (d["decorated"], d["cname"])
    return ("%s%sstruct %s %s; // 0x%08X" % (ec, cst, tname, d["cname"], va), sdef,
            "%s%sstruct %s %s = " % (ec, cst, tname, d["cname"]), init, tail)


PLAN_SCHEMA = 1
PLAN_PATH = os.path.join("build", "data_plan.json")
GEN_DIR = "gen"
GEN_STAMP = "DATA_GEN.json"
INC_HEAD = "// generated from your Game.exe by tools/gendata.py; do not commit"
GEN_STATES = ("included", "static")


def is_static(r):
    return r.get("linkage") == "static"


class PlanError(Exception):
    pass


def include_path(f):
    return "/".join([GEN_DIR, "data", os.path.splitext(f)[0] + ".inc"])


def image_key(img):
    k = getattr(img, "key", None)
    if k is None:
        import hashlib
        k = hashlib.sha256(b"d2data-plan\0" + img.pe.data).digest()
        img.key = k
    return k


def content_hash(img, text):
    import hmac, hashlib
    return hmac.new(image_key(img), text.encode("latin-1"), hashlib.sha256).hexdigest()


def inc_text(externs, types, decls, blocks):
    parts = [INC_HEAD + "\n" + "\n".join(externs)]
    if types:
        parts.append("\n\n".join(types))
    if decls:
        parts.append("\n".join(decls))
    parts.append("\n\n".join(blocks))
    return "\n\n".join(x.strip("\n") for x in parts if x.strip()) + "\n"


def static_inc_text(externs, line):
    return "\n".join([STATIC_HEAD] + list(externs) + [line]) + "\n"


def load_plan(path):
    plan = json.load(open(path, encoding="utf-8"))
    if plan.get("schema") != PLAN_SCHEMA:
        raise PlanError("%s: schema %r, this tool reads %d" % (path, plan.get("schema"), PLAN_SCHEMA))
    return plan


def plan_defs(plan):
    by = collections.defaultdict(list)
    for r in plan["definitions"]:
        by[r["file"]].append(r)
    for f in by:
        by[f].sort(key=lambda r: int(r["va"], 16))
    return by


def image_text(img, va, limit=4096):
    raw = img.read(va, limit) or b""
    k = raw.find(b"\0")
    if k < 0:
        raise PlanError("0x%08X: no terminated text for a literal pointer" % va)
    return raw[:k]


def check_record(r, img):
    va = int(r["va"], 16); n = r["size"]; bad = []
    reg = img.region(va)
    if reg != r["region"]:
        bad.append("region %s, plan %s" % (reg, r["region"]))
    rl = img.relocs_in(va - 3, n + 3)
    if any(x < va or x + 4 > va + n for x in rl):
        bad.append("a base relocation crosses the definition's ends")
    relocs = {x - va: img.ptr(x) for x in rl if va <= x and x + 4 <= va + n}
    want = {p[0]: int(p[1], 16) for p in r["pointers"]}
    if set(relocs) != set(want):
        bad.append("pointer offsets differ from the image's base relocations (%d planned, %d in the image)" % (len(want), len(relocs)))
    else:
        for off, t in relocs.items():
            if t != want[off]:
                bad.append("pointer at +%d: the image points elsewhere" % off); break
    for p in r["pointers"]:
        if p[2] == "literal" and img.region(int(p[1], 16)) != "rdata":
            bad.append("literal pointer at +%d: target not in .rdata" % p[0])
    return bad, relocs


def render_parts(f, ent, recs, img):
    types = []; decls = []; blocks = []; statics = {}
    ec = "extern " if ent.get("lang") == "c" else 'extern "C" '
    for r in recs:
        fn_types = (r.get("fn_types") if is_static(r) else ent.get("fn_types")) or {}
        bad, relocs = check_record(r, img)
        if bad:
            raise PlanError("%s %s %s: %s" % (f, r["va"], r["name"], "; ".join(bad)))
        va = int(r["va"], 16); raw = img.read(va, r["size"])
        by_target = {}
        for off, t, how, nm, o, kind in r["pointers"]:
            by_target.setdefault(int(t, 16), (how, nm, o, kind))

        def sym(t_va, spell, fn=None, by_target=by_target):
            res = by_target.get(t_va)
            if res is None:
                raise Unresolved("0x%08X" % t_va)
            how, nm, off, kind = res
            if how == "literal":
                return sym_expr(("literal", image_text(img, t_va), 0, "string"), spell, fn)
            if how == "owner" and kind == "func" and not (fn if fn is not None else "(" in spell):
                ft = fn_types.get(nm)
                if ft:
                    return "(%s)(unsigned int)(%s)&%s" % (spell, ft, nm)
            return sym_expr(res, spell, fn)
        d = dict(r, va_int=va, relocs=relocs)
        try:
            fwd, sdef, head, init, tail = def_text(d, raw, sym, ec, fixed=True)
        except (NotRepresentable, Unresolved) as e:
            raise PlanError("%s %s %s: the image's values do not fit the planned form (%s)" % (f, r["va"], r["name"], e))
        if (fwd, sdef, head, tail) != (r.get("fwd"), r.get("struct"), r["head"], r["tail"]):
            raise PlanError("%s %s %s: the rendered declarators differ from the plan's" % (f, r["va"], r["name"]))
        if is_static(r):
            if r.get("include") != static_include_path(f, r["name"]) or r["include"] in statics:
                raise PlanError("%s %s %s: the static include is not the plan's path" % (f, r["va"], r["name"]))
            statics[r["include"]] = static_inc_text(r.get("externs") or (), head + init + tail)
            if r.get("inc_hmac") and content_hash(img, statics[r["include"]]) != r["inc_hmac"]:
                raise PlanError("%s %s %s: the generated static include differs from the plan's (content hash)" % (f, r["va"], r["name"]))
            continue
        if sdef:
            types.append(sdef)
        if fwd:
            decls.append(fwd)
        blocks.append(head + init + tail)
    if not ent.get("include"):
        if blocks:
            raise PlanError("%s: definitions without an include in the plan" % f)
        return None, statics
    return inc_text(ent["externs"], types, decls, blocks), statics


def generation_files(plan, states=GEN_STATES, files=None):
    return [f for f, e in sorted(plan["files"].items()) if e["state"] in states and (not files or f in files)]


def gen_dst(out, path):
    return os.path.join(out, os.path.relpath(path, GEN_DIR))


def apply_plan(plan, img, out, states=GEN_STATES, files=None, plan_sha=None, tool_sha=None, image_sha=None):
    by = plan_defs(plan); written = {}; swritten = {}
    if image_sha and plan.get("image_sha256") and image_sha != plan["image_sha256"]:
        raise PlanError("the image is not the one the plan was made from (sha256 %s..., plan %s...)" % (image_sha[:16], plan["image_sha256"][:16]))
    todo = generation_files(plan, states, files)
    texts = {}; stexts = {}
    for f in todo:
        texts[f], st = render_parts(f, plan["files"][f], by.get(f, []), img)
        stexts.update(st)
    for f in todo:
        if texts[f] is None:
            continue
        dst = gen_dst(out, include_path(f))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w", encoding="latin-1", newline="") as fh:
            fh.write(texts[f])
        h = content_hash(img, texts[f]); written[f] = h
        want = plan["files"][f].get("inc_hmac")
        if want and want != h:
            raise PlanError("%s: the generated include differs from the plan's (content hash)" % f)
    for p, txt in sorted(stexts.items()):
        dst = gen_dst(out, p)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w", encoding="latin-1", newline="") as fh:
            fh.write(txt)
        swritten[p] = content_hash(img, txt)
    dd = os.path.join(out, "data")
    keep = {os.path.normpath(gen_dst(out, include_path(f))) for f in todo if texts[f] is not None}
    keep |= {os.path.normpath(gen_dst(out, p)) for p in stexts}
    for p in glob.glob(os.path.join(dd, "**", "*.inc"), recursive=True):
        if os.path.normpath(p) not in keep:
            os.remove(p)
    stamp = dict(note="gen/: generated at build time from your own Game.exe; git-ignored, never commit", schema=PLAN_SCHEMA,
                 plan_sha256=plan_sha, image_sha256=image_sha or plan.get("image_sha256"), tool_sha256=tool_sha,
                 states=list(states), files=written, definitions=sum(len(by.get(f, [])) for f in todo))
    if swritten:
        stamp["static_includes"] = swritten
    json.dump(stamp, open(os.path.join(out, GEN_STAMP), "w"), indent=1, sort_keys=True)
    return stamp


_EXT_NAME = re.compile(r"\b([A-Za-z_]\w*)\s*(\[\]|\(\))\s*;")


def file_sha(p):
    import hashlib
    return hashlib.sha256(open(p, "rb").read()).hexdigest()


def gen_state(root, gen=None, image_sha=None):
    gen = gen or os.path.join(root, GEN_DIR)
    pp = os.path.join(root, PLAN_PATH)
    if not os.path.exists(pp):
        return True, "no plan"
    sp = os.path.join(gen, GEN_STAMP)
    if not os.path.exists(sp):
        return False, "gen/ has not been generated"
    try:
        st = json.load(open(sp))
    except ValueError:
        return False, "gen/%s is unreadable" % GEN_STAMP
    if st.get("plan_sha256") != file_sha(pp):
        return False, "docs/DATA_PLAN.json changed since gen/ was generated"
    if st.get("tool_sha256") != file_sha(os.path.abspath(__file__)):
        return False, "tools/data_extract.py changed since gen/ was generated"
    if image_sha and st.get("image_sha256") != image_sha:
        return False, "gen/ was generated from another image"
    for f in st.get("files", {}):
        if not os.path.exists(os.path.join(gen, os.path.relpath(include_path(f), GEN_DIR))):
            return False, "%s is missing" % include_path(f)
    for p in st.get("static_includes", {}):
        if not os.path.exists(gen_dst(gen, p)):
            return False, "%s is missing" % p
    return True, "fresh"


def open_image(path):
    from common import PE
    import hashlib
    pe = PE(path); img = Image(pe)
    return pe, img, hashlib.sha256(pe.data).hexdigest()


def render_all(image, force=False):
    from common import ROOT, CFG
    pp = os.path.join(ROOT, PLAN_PATH)
    plan = load_plan(pp)
    pe, img, isha = open_image(image)
    if isha != CFG["image"]["sha256"]:
        raise SystemExit("%s hashes to %s..., not the Diablo II 1.14d Game.exe" % (image, isha[:16]))
    out = os.path.join(ROOT, GEN_DIR)
    fresh, why = gen_state(ROOT, out, isha)
    if fresh and not force:
        return "gen/data: up to date"
    try:
        st = apply_plan(plan, img, out, GEN_STATES, None, plan_sha=file_sha(pp), tool_sha=file_sha(os.path.abspath(__file__)), image_sha=isha)
    except PlanError as e:
        raise SystemExit("gendata: %s" % e)
    return "gen/data: %d definitions written into %d includes" % (st["definitions"], len(st["files"]) + len(st.get("static_includes", {})))

