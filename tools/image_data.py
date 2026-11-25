#!/usr/bin/env python3
import struct, collections, bisect

SCN_CODE, SCN_INIT, SCN_UNINIT, SCN_INFO, SCN_REMOVE, SCN_COMDAT = 0x20, 0x40, 0x80, 0x200, 0x800, 0x1000
SCN_WRITE, SCN_ALIGN_MASK, ALIGN_1, ALIGN_4 = 0x80000000, 0x00F00000, 0x00100000, 0x00300000
CH_RDATA, CH_DATA, CH_BSS = 0x40000040 | ALIGN_1, 0xC0000040 | ALIGN_1, 0xC0000080 | ALIGN_1
REL32, DIR32, DIR32NB = 0x14, 0x06, 0x07
IMAGE_BASE_SYM = "___ImageBase"


def headers(pe):
    d = pe.data; p = struct.unpack_from("<I", d, 0x3C)[0]
    return p, p + 24, struct.unpack_from("<H", d, p + 6)[0], struct.unpack_from("<H", d, p + 20)[0]


def directory(pe, i):
    p, opt, n, osz = headers(pe)
    return struct.unpack_from("<II", pe.data, opt + 96 + 8 * i)


def section_table(pe):
    p, opt, n, osz = headers(pe); out = []
    for i in range(n):
        o = opt + osz + 40 * i
        vs, va, rs, rp = struct.unpack_from("<IIII", pe.data, o + 8)
        out.append(dict(name=pe.data[o:o + 8].rstrip(b"\0").decode("latin-1"), va=va, vsize=vs, rawsize=rs, rawptr=rp,
                        ch=struct.unpack_from("<I", pe.data, o + 36)[0]))
    return out


def vread(pe, va, n):
    rva = va - pe.image_base
    secs = getattr(pe, "_d2secs", None)
    if secs is None:
        secs = section_table(pe)
        try:
            pe._d2secs = secs
        except AttributeError:
            pass
    for s in secs:
        end = s["va"] + max(s["vsize"], s["rawsize"])
        if s["va"] <= rva and rva + n <= end:
            o = rva - s["va"]; raw = pe.data[s["rawptr"]:s["rawptr"] + s["rawsize"]]
            b = raw[o:o + n]
            return b + b"\0" * (n - len(b))
    return None


def image_layout(pe):
    B = pe.image_base; secs = {s["name"]: s for s in section_table(pe)}
    iat = directory(pe, 12); imp = directory(pe, 1); exp = directory(pe, 0)
    rd = secs[".rdata"]; da = secs[".data"]
    split = initialised_end(pe, da)
    out = dict(sections=section_table(pe), iat=(B + iat[0], B + iat[0] + iat[1]), import_dir=B + imp[0],
               export=(B + exp[0], B + exp[0] + exp[1]) if exp[0] else None,
               rdata=(B + iat[0] + iat[1], B + imp[0]),
               data_init=(B + da["va"], split),
               data_bss=(split, B + da["va"] + da["vsize"]),
               data_raw_end=B + da["va"] + min(da["rawsize"], da["vsize"]),
               rdata_section=(B + rd["va"], B + rd["va"] + rd["vsize"]))
    return out


def file_alignment(pe):
    p, opt, n, osz = headers(pe)
    return struct.unpack_from("<I", pe.data, opt + 36)[0]


def initialised_end(pe, sec, fa=None, relocs=None):
    B = pe.image_base
    lo = B + sec["va"]; hi = lo + min(sec["rawsize"], sec["vsize"])
    raw = vread(pe, lo, hi - lo)
    if raw is None:
        return hi
    end = lo + len(raw.rstrip(b"\0"))
    if fa is None:
        try:
            fa = file_alignment(pe)
        except struct.error:
            return hi
    if not fa or end <= hi - fa or end >= hi:
        return hi
    rl = sorted(relocs) if relocs is not None else base_relocations(pe)
    i = bisect.bisect_left(rl, end - 3)
    if i < len(rl) and rl[i] < hi:
        return hi
    return end


def region_of(layout, va, n):
    for k in ("rdata", "data_init", "data_bss"):
        lo, hi = layout[k]
        if lo <= va and va + n <= hi:
            return k
    return None


def group_name(region, va):
    return {"rdata": ".rdata$d2", "data_init": ".data$d2", "data_bss": ".bss$d2"}[region] + "%08X" % va


def group_ch(region, ch=0, align1=True):
    base = {"rdata": CH_RDATA, "data_init": CH_DATA, "data_bss": CH_BSS}[region] & ~SCN_ALIGN_MASK
    al = ALIGN_1 if align1 or not ch & SCN_ALIGN_MASK else ch & SCN_ALIGN_MASK
    return base | (ch & SCN_COMDAT) | al


PAGE = 0x1000


def reloc_vsize(n_fixups, pages):
    return 2 * n_fixups + 10 * pages


def pages_before_reloc(secs):
    return sum((max(s["vsize"], 1) + PAGE - 1) // PAGE for s in secs if s["name"] != ".reloc")


def fixups_counted(secs):
    r = next((s for s in secs if s["name"] == ".reloc"), None)
    if r is None:
        return None
    return (r["vsize"] - 10 * pages_before_reloc(secs)) // 2


def init_data_size(secs):
    return sum(s["rawsize"] for s in secs if s["ch"] & SCN_INIT)


RESOURCE_UPDATE_FILL = b"PADDINGXXPADDING"


def resource_update_fill(n):
    return (RESOURCE_UPDATE_FILL * (n // len(RESOURCE_UPDATE_FILL) + 1))[:n]


def resource_padding_range(data):
    p = struct.unpack_from("<I", data, 0x3C)[0]; n = struct.unpack_from("<H", data, p + 6)[0]
    osz = struct.unpack_from("<H", data, p + 20)[0]
    rrva = struct.unpack_from("<I", data, p + 24 + 96 + 8 * 2)[0]
    if not rrva:
        return None
    for i in range(n):
        o = p + 24 + osz + 40 * i
        vs, va, rs, rp = struct.unpack_from("<IIII", data, o + 8)
        if va <= rrva < va + max(vs, rs):
            return (rp + vs, rs - vs) if rs > vs else None
    return None


def resource_update_padding(data):
    r = resource_padding_range(data)
    if r is None:
        return data, None
    d = bytearray(data); d[r[0]:r[0] + r[1]] = resource_update_fill(r[1])
    return bytes(d), r


def resource_update_header(data):
    d = bytearray(data); p = struct.unpack_from("<I", d, 0x3C)[0]; n = struct.unpack_from("<H", d, p + 6)[0]
    osz = struct.unpack_from("<H", d, p + 20)[0]; secs = []
    for i in range(n):
        o = p + 24 + osz + 40 * i
        secs.append(dict(rawsize=struct.unpack_from("<I", d, o + 16)[0], ch=struct.unpack_from("<I", d, o + 36)[0]))
    old = struct.unpack_from("<I", d, p + 24 + 8)[0]; new = init_data_size(secs)
    struct.pack_into("<I", d, p + 24 + 8, new)
    return bytes(d), old, new


def section_name(o, i):
    raw = o.d[20 + 40 * i:20 + 40 * i + 8]
    if raw[:1] == b"/" and raw[1:2].isdigit():
        z = o.symptr + 18 * o.nsym + int(raw[1:].rstrip(b"\0"))
        return o.d[z:o.d.index(b"\0", z)].decode("latin-1")
    return raw.rstrip(b"\0").decode("latin-1")


def is_data(name, ch):
    return bool(ch & (SCN_INIT | SCN_UNINIT)) and not ch & (SCN_CODE | SCN_INFO | SCN_REMOVE) and not name.startswith((".debug", ".drectve"))


def data_sections(o):
    out = []
    rawsize = lambda i: struct.unpack_from("<I", o.d, 20 + 40 * i + 16)[0]
    by_scn = collections.defaultdict(list)
    for y in o.syms:
        if y["scn"] > 0:
            by_scn[y["scn"]].append(y)
    for i, s in enumerate(o.secs):
        name = section_name(o, i); ch = s["ch"]
        if not is_data(name, ch):
            continue
        scn = i + 1; size = rawsize(i)
        uninit = bool(ch & SCN_UNINIT) and not ch & SCN_INIT
        rels = [(r["offset"], r["ty"], r["sym"]) for r in o.relocs(scn)] if s["nrel"] else []
        raw = None if uninit else s["raw"]
        mask = bytearray(b"\xff" * size)
        for off, ty, _ in rels:
            for k in range(4):
                if off + k < size:
                    mask[off + k] = 0
        al = (ch & SCN_ALIGN_MASK) >> 20
        defs = [y for y in by_scn[scn] if not (y["cls"] == 3 and y["name"] == s["name"] and y["naux"]) and not (y["naux"] and y["name"] == name)]
        out.append(dict(scn=scn, name=name, ch=ch, size=size, raw=raw, mask=bytes(mask), rels=rels, defs=defs,
                        comdat=bool(ch & SCN_COMDAT), align=(1 << (al - 1)) if al else 16))
    return out


def alternatenames(o):
    out = []
    for i, s in enumerate(o.secs):
        if section_name(o, i) != ".drectve" or not s["raw"]:
            continue
        for tok in s["raw"].decode("latin-1").replace("\0", " ").split():
            tok = tok.strip('"')
            if tok.lower().startswith(("/alternatename:", "-alternatename:")) and "=" in tok:
                a, _, b = tok.split(":", 1)[1].partition("=")
                if a and b:
                    out.append((a, b))
    return out


def fits(sec, va, pe):
    img = vread(pe, va, sec["size"])
    if img is None:
        return False
    if sec["raw"] is None:
        return not any(img)
    raw, mask = sec["raw"], sec["mask"]
    if len(raw) != sec["size"]:
        return False
    if raw == img:
        return True
    return all(img[k] == raw[k] for k in range(sec["size"]) if mask[k])


def reloc_target(pe, va, ty, addend):
    b = vread(pe, va, 4)
    if b is None:
        return None
    v = struct.unpack("<I", b)[0]
    if ty == REL32:
        return (va + 4 + v - addend) & 0xFFFFFFFF
    if ty == DIR32NB:
        return (pe.image_base + v - addend) & 0xFFFFFFFF
    return (v - addend) & 0xFFFFFFFF


def choose_data(cands):
    order = sorted(range(len(cands)), key=lambda i: (-cands[i].get("anchors", 1), -cands[i]["size"], i))
    taken = []; starts = []; chosen = []; rejected = []

    def free(a, n):
        j = bisect.bisect_right(starts, a + n - 1) - 1
        return not (j >= 0 and taken[j][0] + taken[j][1] > a)
    for i in order:
        c = cands[i]; a, n = c["va"], c["size"]
        if n == 0:
            chosen.append(c); continue
        if not free(a, n):
            a = next((x for x in c.get("alts", ()) if free(x, n)), None)
            if a is None:
                rejected.append(c); continue
            c = dict(c, va=a, moved=True)
        bisect.insort(starts, a); taken.insert(starts.index(a), (a, n)); chosen.append(c)
    chosen.sort(key=lambda c: (c["va"], c["size"]))
    return chosen, rejected


def gaps(pieces, lo, hi):
    out = []; cur = lo
    for va, n in sorted(pieces):
        if va > cur:
            out.append((cur, min(va, hi) - cur))
        cur = max(cur, va + n)
    if cur < hi:
        out.append((cur, hi - cur))
    return [g for g in out if g[1] > 0]


def filler_sections(region, gaps_, pe, base_relocs, names_at, zero=()):
    syms = [dict(name=IMAGE_BASE_SYM, value=0, scn=0, cls=2)]
    secs = []; rl = sorted(base_relocs); na = sorted(names_at)
    st = collections.Counter()
    for a, n in gaps_:
        scn = len(secs) + 1
        sec = dict(name=group_name(region, a), ch=group_ch(region))
        if region == "data_bss":
            sec.update(data=b"", size=n)
        elif (a, n) in zero:
            sec.update(data=bytes(n), relocs=[]); st["filler_alignment_pads"] += 1; st["filler_alignment_pad_bytes"] += n
        else:
            data = bytearray(vread(pe, a, n)); rels = []
            i = bisect.bisect_left(rl, a)
            while i < len(rl) and rl[i] < a + n:
                r = rl[i]; i += 1
                if r + 4 > a + n:
                    st["reloc_crosses_filler_end"] += 1; continue
                v = struct.unpack_from("<I", data, r - a)[0]
                struct.pack_into("<I", data, r - a, (v - pe.image_base) & 0xFFFFFFFF)
                rels.append((r - a, 0, DIR32)); st["filler_relocations"] += 1
            sec.update(data=bytes(data), relocs=rels)
        secs.append(sec); st["fillers"] += 1; st["filler_bytes"] += n
        j = bisect.bisect_left(na, a)
        while j < len(na) and na[j] < a + n:
            for nm in sorted(names_at[na[j]]):
                syms.append(dict(name=nm, value=na[j] - a, scn=scn, cls=2)); st["filler_symbols"] += 1
            j += 1
    return secs, syms, st


def alignment_pads(gaps_, pieces, pe, base_relocs, names_at):
    starts = {}; ends = set()
    for va, n, al in pieces:
        if n:
            starts[va] = max(starts.get(va, 1), al); ends.add(va + n)
    rl = sorted(base_relocs); na = sorted(names_at); out = set()
    for a, n in gaps_:
        al = starts.get(a + n)
        if not al or a not in ends or n >= al or (a + n) % al or (a + al - 1) // al * al != a + n:
            continue
        i = bisect.bisect_left(rl, a - 3)
        if i < len(rl) and rl[i] < a + n:
            continue
        j = bisect.bisect_left(na, a)
        if j < len(na) and na[j] < a + n:
            continue
        if vread(pe, a, n) != bytes(n):
            continue
        out.add((a, n))
    return out


def text_filler_relocs(a, n, base_relocs_sorted, pe):
    out = []; i = bisect.bisect_left(base_relocs_sorted, a)
    while i < len(base_relocs_sorted) and base_relocs_sorted[i] + 4 <= a + n:
        r = base_relocs_sorted[i]; i += 1
        v = struct.unpack("<I", vread(pe, r, 4))[0]
        out.append((r - a, (v - pe.image_base) & 0xFFFFFFFF))
    return out


def base_relocations(pe):
    rva, size = directory(pe, 5)
    if not rva:
        return []
    d = pe.data; off = pe.va_to_off(pe.image_base + rva); stop = off + size; out = []
    while off + 8 <= stop:
        page, blk = struct.unpack_from("<II", d, off)
        if blk < 8:
            break
        for k in range((blk - 8) // 2):
            e = struct.unpack_from("<H", d, off + 8 + 2 * k)[0]
            if e >> 12 == 3:
                out.append(pe.image_base + page + (e & 0xFFF))
        off += blk
    return sorted(out)


def _cstr(pe, va):
    o = pe.va_to_off(va)
    return pe.data[o:pe.data.index(b"\0", o)].decode("latin-1")


def image_exports(pe):
    rva, size = directory(pe, 0)
    if not rva:
        return None
    B = pe.image_base
    ch, ts, ma, mi, nrva, base, nf, nn, af, an, ao = struct.unpack("<IIHHIIIIIII", pe.read(B + rva, 40))
    funcs = struct.unpack("<%dI" % nf, pe.read(B + af, 4 * nf)) if nf else ()
    names = struct.unpack("<%dI" % nn, pe.read(B + an, 4 * nn)) if nn else ()
    ords = struct.unpack("<%dH" % nn, pe.read(B + ao, 2 * nn)) if nn else ()
    name_of = {ords[i]: _cstr(pe, B + names[i]) for i in range(nn)}
    ents = [(base + i, name_of.get(i), B + f) for i, f in enumerate(funcs) if f]
    return dict(name=_cstr(pe, B + nrva), base=base, timestamp=ts, entries=ents)


def exports_def(module, entries, internal, data_names=()):
    lines = ["NAME \"%s\"" % module, "EXPORTS"]
    for o, nm, va in entries:
        sym = internal[va]; sym = sym[1:] if sym.startswith("_") and "@" not in sym else sym
        tail = " DATA" if (nm in data_names) else ""
        if nm is None:
            lines.append("  d2noname_%d=%s @%d NONAME%s" % (o, sym, o, tail))
        else:
            lines.append("  %s=%s @%d%s" % (nm, sym, o, tail) if nm != sym else "  %s @%d%s" % (nm, o, tail))
    return "\n".join(lines) + "\n"


def image_resources(pe):
    rva, size = directory(pe, 2)
    if not rva:
        return None
    B = pe.image_base; base = B + rva; leaves = []; tables = []
    def rd(off, n):
        return pe.read(base + off, n)
    def name_of(n):
        if n & 0x80000000:
            o = n & 0x7FFFFFFF; ln = struct.unpack("<H", rd(o, 2))[0]
            return rd(o + 2, 2 * ln).decode("utf-16-le")
        return n
    def walk(off, path):
        ch, ts, ma, mi, nn, ni = struct.unpack("<IIHHHH", rd(off, 16)); tables.append((ch, ts, ma, mi))
        for i in range(nn + ni):
            n, o = struct.unpack("<II", rd(off + 16 + 8 * i, 8))
            if o & 0x80000000:
                walk(o & 0x7FFFFFFF, path + [name_of(n)])
            else:
                drva, sz, cp, _ = struct.unpack("<IIII", rd(o, 16))
                leaves.append(dict(path=path + [name_of(n)], codepage=cp, rva=drva, size=sz))
    walk(0, [])
    return dict(root=tables[0], tables=tables, leaves=leaves, rva=rva, size=size)


def _res_id(v):
    if isinstance(v, int):
        return b"\xff\xff" + struct.pack("<H", v)
    return v.encode("utf-16-le") + b"\0\0"


def res_file(leaves, data_of):
    def entry(typ, name, lang, data, memflags=0x1030):
        hdr = _res_id(typ) + _res_id(name)
        if len(hdr) % 4:
            hdr += b"\0" * (4 - len(hdr) % 4)
        hdr += struct.pack("<IHHII", 0, memflags, lang, 0, 0)
        out = struct.pack("<II", len(data), 8 + len(hdr)) + hdr + data
        return out + b"\0" * (-len(out) % 4)
    out = entry(0, 0, 0, b"", 0)
    for lf in leaves:
        t, n, l = lf["path"]
        out += entry(t, n, l, data_of(lf))
    return out


def _sort_key(v):
    return (0, v.upper(), v) if isinstance(v, str) else (1, v, "")


def rsrc_blob(leaves, data_of, root=(0, 0, 4, 0), align=4, fill=None):
    ch, ts, ma, mi = root
    tree = collections.OrderedDict()
    for lf in leaves:
        t, n, l = lf["path"]
        tree.setdefault(t, collections.OrderedDict()).setdefault(n, collections.OrderedDict())[l] = lf
    levels = [[("root", sorted(tree, key=_sort_key))]]
    levels.append([((t,), sorted(tree[t], key=_sort_key)) for t in levels[0][0][1]])
    levels.append([((t, n), sorted(tree[t][n], key=_sort_key)) for (t,), names in levels[1] for n in names])
    off = 0; table_at = {}
    for lv in levels:
        for key, ents in lv:
            table_at[key] = off; off += 16 + 8 * len(ents)
    strings = collections.OrderedDict()
    for lv in levels:
        for key, ents in lv:
            for e in ents:
                if isinstance(e, str) and e not in strings:
                    strings[e] = None
    for s in strings:
        strings[s] = off; off += 2 + 2 * len(s)
    off += -off % 4
    leaf_list = [tree[t][n][l] for (t, n), ls in levels[2] for l in ls]
    entry_at = {}
    for lf in leaf_list:
        entry_at[id(lf)] = off; off += 16
    data_at = {}
    for lf in leaf_list:
        off += -off % align; data_at[id(lf)] = off; off += lf["size"]
    off += -off % align
    out = bytearray(off)
    def put_table(key, ents, child):
        o = table_at[key]; nn = sum(1 for e in ents if isinstance(e, str))
        struct.pack_into("<IIHHHH", out, o, ch, ts, ma, mi, nn, len(ents) - nn)
        for i, e in enumerate(ents):
            nm = (0x80000000 | strings[e]) if isinstance(e, str) else e
            struct.pack_into("<II", out, o + 16 + 8 * i, nm, child(e))
    put_table("root", levels[0][0][1], lambda t: 0x80000000 | table_at[(t,)])
    for (t,), names in levels[1]:
        put_table((t,), names, lambda n, t=t: 0x80000000 | table_at[(t, n)])
    for (t, n), ls in levels[2]:
        put_table((t, n), ls, lambda l, t=t, n=n: entry_at[id(tree[t][n][l])])
    for s, o in strings.items():
        struct.pack_into("<H", out, o, len(s)); out[o + 2:o + 2 + 2 * len(s)] = s.encode("utf-16-le")
    fix = []; dat = []
    for lf in leaf_list:
        e = entry_at[id(lf)]; d = data_at[id(lf)]
        struct.pack_into("<IIII", out, e, d, lf["size"], lf["codepage"], 0)
        out[d:d + lf["size"]] = data_of(lf); fix.append(e); dat.append(d)
    if fill:
        ends = sorted((data_at[id(lf)] + lf["size"]) for lf in leaf_list); starts = sorted(data_at.values())[1:] + [len(out)]
        for a, b in zip(ends, starts):
            if b > a:
                out[a:b] = fill(a, b - a)
    return bytes(out), fix, dat


def rsrc_object(blob, fixups, coff_write, secaux):
    syms = [dict(name=".rsrc$01", value=0, scn=1, cls=3, aux=[secaux(len(blob), len(fixups))])]
    rels = [(o, 0, DIR32NB) for o in fixups]
    return coff_write([dict(name=".rsrc$01", data=blob, ch=0x40000040 | ALIGN_4, relocs=rels)], syms)
