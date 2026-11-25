#!/usr/bin/env python3
import os, sys, json, struct, glob, hashlib, subprocess, array, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, records, load_json
import image_data as D

KIND_ORDER = ("not_function", "crt", "pkware", "thunk", "unmatched", "verified")
STATE_NAME = {"not_function": "inside another function", "crt": "C runtime (not placed by identity)",
              "pkware": "PKWARE DCL (not placed by identity)", "thunk": "import thunk",
              "unmatched": "unmatched function", "verified": "verified function (no object)", None: "no record"}
CLASSES = ("built_from_game_source", "generated_data", "runtime_library", "imports", "linker_output", "padding",
           "borrowed_code", "borrowed_data", "resource", "stamp", "signature")
BUILT_CLASSES = CLASSES[:6]
BORROWED_CLASSES = ("borrowed_code", "borrowed_data", "resource", "stamp", "signature")
DIR_EXPORT, DIR_RESOURCE, DIR_SECURITY, DIR_DEBUG, DIR_IAT = 0, 2, 4, 6, 12


def e_lfanew(d):
    return struct.unpack_from("<I", d, 0x3C)[0]


def sections(d):
    p = e_lfanew(d); n = struct.unpack_from("<H", d, p + 6)[0]; osz = struct.unpack_from("<H", d, p + 20)[0]; out = []
    for i in range(n):
        o = p + 24 + osz + 40 * i
        vs, va, rs, rp = struct.unpack_from("<IIII", d, o + 8)
        out.append(dict(name=d[o:o + 8].rstrip(b"\0").decode("latin-1"), va=va, vsize=vs, rawsize=rs, rawptr=rp))
    return out


def image_base(d):
    return struct.unpack_from("<I", d, e_lfanew(d) + 24 + 28)[0]


def size_of_headers(d):
    return struct.unpack_from("<I", d, e_lfanew(d) + 24 + 60)[0]


def directory(d, i):
    return struct.unpack_from("<II", d, e_lfanew(d) + 24 + 96 + 8 * i)


def headers_end(d):
    p = e_lfanew(d); n = struct.unpack_from("<H", d, p + 6)[0]; osz = struct.unpack_from("<H", d, p + 20)[0]
    return p + 24 + osz + 40 * n


def rva_to_off(d, rva):
    for s in sections(d):
        if s["va"] <= rva < s["va"] + s["rawsize"]:
            return s["rawptr"] + rva - s["va"]
    return None


def sections_end(d):
    return max(s["rawptr"] + s["rawsize"] for s in sections(d))


def rich_start(d):
    p = e_lfanew(d); r = d.find(b"Rich", 0x40, p)
    if r < 0:
        return None
    key = struct.unpack_from("<I", d, r + 4)[0]
    for o in range(r - 4, 0x3F, -4):
        if struct.unpack_from("<I", d, o)[0] ^ key == 0x536E6144:
            return o
    return None


def pe_checksum(d, field):
    b = bytearray(d); b[field:field + 4] = b"\0\0\0\0"
    if len(b) % 2:
        b += b"\0"
    a = array.array("H"); a.frombytes(bytes(b))
    if sys.byteorder != "little":
        a.byteswap()
    s = sum(a)
    while s >> 16:
        s = (s & 0xFFFF) + (s >> 16)
    return (s + len(d)) & 0xFFFFFFFF


def pad_mask(orig_pe, fillers=None):
    import text_map as V
    start, end, cls = V.classify(orig_pe)
    d = ord("d")
    mask = bytearray(1 if c == d else 0 for c in cls)
    pieces = []
    for run in load_json("linker_pieces.json")["runs"]:
        a, b = int(run["start"], 16), int(run["end"], 16); pieces.append((a, b - a))
    return start, layout_int3(start, orig_pe.read(start, end - start) or b"", address_records(), mask, pieces, fillers)


def layout_int3(start, body, records, mask, pieces=(), fillers=None):
    n = len(body); out = bytearray(mask)
    fn = bytearray(n); nf = bytearray(n); starts = set()
    def paint(arr, va, ln):
        a, b = max(va, start), min(va + ln, start + n)
        if a < b:
            arr[a - start:b - start] = b"\1" * (b - a)
    for va, ln, st in records:
        paint(nf if st == "not_function" else fn, va, ln)
        if start <= va < start + n:
            starts.add(va - start)
    for va, ln in pieces:
        paint(fn, va, ln)
    fl = bytearray(n)
    for va, ln in (fillers or ()):
        paint(fl, va, ln)
    def part(i):
        return fl[i] and not fn[i] and (body[i] == 0xCC or mask[i])
    def built_unrecorded(i):
        return fillers is not None and not nf[i] and not fl[i]
    i = 0
    while i < n:
        if not part(i):
            i += 1; continue
        j = i
        while j < n and part(j):
            j += 1
        left_ok = i == 0 or fn[i - 1] or built_unrecorded(i - 1)
        right_ok = j == n or j in starts or fn[j] or built_unrecorded(j)
        if left_ok and right_ok:
            for k in range(i, j):
                if body[k] == 0xCC:
                    out[k] = 1
        i = j
    return out


def filler_bytes(read, g0, n, pads, fill=0xCC):
    b = bytearray(read(g0, n) or b"")
    if len(b) != n:
        raise ValueError("the image has no bytes for the filler 0x%08X+%d" % (g0, n))
    if pads:
        t0, m = pads
        for i in range(n):
            j = g0 + i - t0
            if 0 <= j < len(m) and m[j]:
                b[i] = fill
    return bytes(b)


def finish(orig, linked):
    problems = []; regions = []
    po, pn = e_lfanew(orig), e_lfanew(linked)
    hs = size_of_headers(linked)
    if hs != size_of_headers(orig):
        problems.append("SizeOfHeaders differs: original 0x%X, linked 0x%X" % (size_of_headers(orig), hs))
    hs = min(hs, size_of_headers(orig))
    so, sn = sections(orig), sections(linked)
    if [(s["va"], s["rawptr"], s["rawsize"]) for s in so] != [(s["va"], s["rawptr"], s["rawsize"]) for s in sn]:
        problems.append("the section layout differs (VA, raw pointer or raw size)")
    end_o, end_n = sections_end(orig), sections_end(linked)
    if end_o != end_n or len(linked) not in (end_n, len(orig)):
        problems.append("the file length up to the last section differs: original %d, linked %d (file %d)" % (end_o, end_n, len(linked)))
    out = bytearray(linked[:end_n])
    ro, rn = rich_start(orig), rich_start(linked)
    ro = po if ro is None else ro; rn = pn if rn is None else rn
    if rn != ro:
        problems.append("the DOS stub ends at 0x%X in the original and 0x%X in the link" % (ro, rn))
    h = bytearray(hs)
    h[:min(rn, hs)] = linked[:min(rn, hs)]
    h[ro:po] = orig[ro:po]; regions.append((ro, po - ro, "stamp", "Rich block"))
    h[0x3C:0x40] = struct.pack("<I", po); regions.append((0x3C, 4, "stamp", "e_lfanew (follows the Rich block)"))
    move = hs - po
    h[po:hs] = linked[pn:pn + move]
    dropped = linked[pn + move:hs]
    if any(dropped):
        problems.append("moving the PE header from 0x%X to 0x%X would drop %d non-zero header bytes" % (pn, po, sum(1 for x in dropped if x)))
    out[:hs] = h
    def take(off, n, cls, what):
        out[off:off + n] = orig[off:off + n]; regions.append((off, n, cls, what))
    take(po + 8, 4, "stamp", "file header timestamp")
    take(po + 24 + 96 + 8 * DIR_DEBUG, 8, "stamp", "debug directory entry")
    take(po + 24 + 96 + 8 * DIR_SECURITY, 8, "signature", "security directory entry")
    erva, esz = directory(orig, DIR_EXPORT)
    if erva and esz:
        eo = rva_to_off(orig, erva)
        if eo is not None and rva_to_off(linked, directory(linked, DIR_EXPORT)[0]) == eo:
            take(eo + 4, 4, "stamp", "export directory timestamp")
        else:
            problems.append("the export directory is not at the original's place")
    pr = D.resource_padding_range(bytes(out))
    if pr is not None:
        out[pr[0]:pr[0] + pr[1]] = D.resource_update_fill(pr[1])
    if len(orig) > end_o:
        sig_off, sig_len = directory(orig, DIR_SECURITY)
        if (sig_off, sig_len) not in ((end_o, len(orig) - end_o), (0, 0)):
            problems.append("the security directory does not point at the bytes after the last section")
        out += orig[end_o:]; regions.append((end_o, len(orig) - end_o, "signature", "Authenticode signature"))
    ck = po + 24 + 64
    struct.pack_into("<I", out, ck, pe_checksum(bytes(out), ck))
    return bytes(out), regions, problems


CODE = {c: i for i, c in enumerate(CLASSES)}


def address_records():
    return records()


def plan_definitions():
    plan = load_json("data_plan.json"); files = plan.get("files", {})
    return [(int(x["va"], 16), int(x["size"])) for x in plan.get("definitions", ())
            if (files.get(x.get("file")) or {}).get("state") == "included"]


def import_ranges(orig):
    out = []
    for run in load_json("linker_pieces.json")["runs"]:
        a, b = int(run["start"], 16), int(run["end"], 16); out.append((a, b - a))
    for va, ln, k in records(("thunk",)):
        out.append((va, ln))
    rva, n = directory(orig, DIR_IAT)
    if rva and n:
        out.append((image_base(orig) + rva, n))
    return out


def classify_file(orig, prov, regions, text_pads=None, definitions=(), imports=()):
    B = image_base(orig); lab = bytearray([CODE["linker_output"]]) * len(orig)
    m = {"source": "built_from_game_source", "library": "runtime_library", "linker": "linker_output", "padding": "padding",
         "borrowed": "borrowed_code", "placeholder": "borrowed_code", "copied": "borrowed_data", "resource": "resource",
         "stamp": "stamp", "signature": "signature"}
    secs = sections(orig)
    for s in secs:
        lo = B + s["va"]; n = min(s["vsize"], s["rawsize"])
        def paint(va, ln, code):
            x0, x1 = max(va, lo), min(va + ln, lo + n)
            if x0 < x1:
                lab[s["rawptr"] + x0 - lo:s["rawptr"] + x1 - lo] = bytes([code]) * (x1 - x0)
        for va, ln, c in prov:
            cc = m[c]
            if cc == "borrowed_data" and s["name"] == ".text":
                cc = "borrowed_code"
            paint(va, ln, CODE[cc])
        if text_pads and s["name"] == ".text":
            t0, mask = text_pads; bc = CODE["borrowed_code"]; pc = CODE["padding"]
            for i in range(n):
                j = lo + i - t0; o = s["rawptr"] + i
                if lab[o] == bc and 0 <= j < len(mask) and mask[j]:
                    lab[o] = pc
        def over(ranges, frm, to):
            for va, ln in ranges:
                x0, x1 = max(va, lo), min(va + ln, lo + n)
                for v in range(x0, x1):
                    o = s["rawptr"] + v - lo
                    if lab[o] == frm:
                        lab[o] = to
        over(definitions, CODE["built_from_game_source"], CODE["generated_data"])
        over(imports, CODE["linker_output"], CODE["imports"])
    for off, n, c, _ in regions:
        lab[off:off + n] = bytes([CODE[c]]) * n
    return lab


def class_counts(lab):
    c = collections.Counter(lab)
    return collections.OrderedDict((k, c.get(CODE[k], 0)) for k in CLASSES)


def text_states(orig, records):
    t = next(s for s in sections(orig) if s["name"] == ".text")
    lo = image_base(orig) + t["va"]; n = t["rawsize"]
    st = bytearray(n); rec = array.array("I", bytes(4 * n))
    code = {s: i + 1 for i, s in enumerate(KIND_ORDER)}
    for state in KIND_ORDER:
        for va, ln, s in records:
            if s != state:
                continue
            x0, x1 = max(va, lo), min(va + ln, lo + n)
            if x0 < x1:
                st[x0 - lo:x1 - lo] = bytes([code[s]]) * (x1 - x0)
                rec[x0 - lo:x1 - lo] = array.array("I", [va]) * (x1 - x0)
    return lo, st, rec


def borrowed_code(orig, lab, records):
    lo, st, rec = text_states(orig, records)
    t = next(s for s in sections(orig) if s["name"] == ".text")
    bc = CODE["borrowed_code"]; rp = t["rawptr"]
    by = collections.Counter(); fn = collections.defaultdict(set); regions = []; cur = None
    for i in range(len(st)):
        if lab[rp + i] != bc:
            cur = None; continue
        s = KIND_ORDER[st[i] - 1] if st[i] else None
        r = rec[i] if st[i] else None
        by[s] += 1
        if r is not None:
            fn[s].add(r)
        if cur is not None and cur[2] == s and cur[3] == r and cur[0] + cur[1] == lo + i:
            cur[1] += 1
        else:
            cur = [lo + i, 1, s, r]; regions.append(cur)
    order = [None] + list(KIND_ORDER)
    bytes_by = collections.OrderedDict((STATE_NAME[s], by[s]) for s in order if by.get(s))
    funcs_by = collections.OrderedDict((STATE_NAME[s], len(fn[s])) for s in order if fn.get(s))
    return bytes_by, funcs_by, [tuple(r) for r in regions]


def strict_diff(orig, out, lab, limit=200):
    runs = []; per = collections.Counter(); cur = None
    n = max(len(orig), len(out))
    for i in range(n):
        a = orig[i] if i < len(orig) else None; b = out[i] if i < len(out) else None
        if a == b:
            cur = None; continue
        c = CLASSES[lab[i]] if i < len(lab) else "beyond the original's end"
        per[c] += 1
        if cur and cur[2] == c and cur[0] + cur[1] == i:
            cur[1] += 1
        else:
            cur = [i, 1, c]; runs.append(cur)
    return [tuple(r) for r in runs], dict(per)


def off_to_va(d, off):
    B = image_base(d)
    for s in sections(d):
        if s["rawptr"] <= off < s["rawptr"] + s["rawsize"]:
            return B + s["va"] + off - s["rawptr"]
    return None


def write_borrowed_tsv(path, regions):
    with open(path, "w") as f:
        f.write("# va\tlength\tkind\tfunction_va  (code regions taken from Game.exe; addresses and lengths only)\n")
        for va, n, s, r in regions:
            f.write("0x%08X\t%d\t%s\t%s\n" % (va, n, STATE_NAME[s], ("0x%08X" % r) if r is not None else "-"))


def report(orig, out, lab, regions, problems, records, extra=None):
    counts = class_counts(lab)
    bytes_by, funcs_by, bregions = borrowed_code(orig, lab, records)
    runs, per = strict_diff(orig, out, lab)
    built_diff = {k: v for k, v in per.items() if k in BUILT_CLASSES}
    rec = collections.OrderedDict(
        output_sha256=hashlib.sha256(out).hexdigest(), original_sha256=hashlib.sha256(orig).hexdigest(),
        identical=out == orig, output_size=len(out), original_size=len(orig),
        bytes_by_class=counts, bytes_total=sum(counts.values()),
        built=sum(counts[k] for k in BUILT_CLASSES), borrowed=sum(counts[k] for k in BORROWED_CLASSES),
        borrowed_code_by_state=bytes_by, borrowed_functions_by_state=funcs_by,
        borrowed_functions=sum(v for k, v in funcs_by.items() if k != STATE_NAME["not_function"]),
        borrowed_code_regions=len(bregions),
        taken_after_link=[dict(offset="0x%X" % o, length=n, cls=c, what=w) for o, n, c, w in regions],
        problems=list(problems), differing_bytes_by_class=per, differing_built_bytes=sum(built_diff.values()),
        differing_regions=[dict(offset="0x%X" % o, va=("0x%08X" % off_to_va(orig, o)) if off_to_va(orig, o) else None, length=n, cls=c) for o, n, c in runs[:200]],
        differing_region_count=len(runs))
    if extra:
        rec.update(extra)
    return rec, bregions


def complete(orig_path, linked_path, prov_path, out_dir, strict=True, text_pads=None, extra=None, log=print):
    orig = open(orig_path, "rb").read(); linked = open(linked_path, "rb").read()
    prov = [(int(v, 16), n, c) for v, n, c in json.load(open(prov_path))["runs"]]
    out, regions, problems = finish(orig, linked)
    if len(out) != len(orig):
        problems.append("the finished file is %d B, the original %d B" % (len(out), len(orig)))
    lab = classify_file(orig, prov, regions, text_pads, plan_definitions(), import_ranges(orig))
    rec, bregions = report(orig, out, lab, regions, problems, address_records(), extra)
    rec["strict"] = strict
    rec["note"] = "borrowed_functions counts the functions with bytes taken from Game.exe; byte classes partition the file"
    write_borrowed_tsv(os.path.join(out_dir, "BORROWED.tsv"), bregions)
    gp = os.path.join(out_dir, "Game.exe")
    if os.path.exists(gp):
        os.remove(gp)
    if rec["identical"] or not strict:
        with open(gp, "wb") as f:
            f.write(out)
        rec["written"] = "Game.exe"
    else:
        rec["written"] = None
    json.dump(rec, open(os.path.join(out_dir, "BUILD_REPORT.json"), "w"), indent=1)
    log(summary_line(rec))
    if not rec["identical"]:
        log("differing bytes by class: %s" % ", ".join("%s %d" % kv for kv in sorted(rec["differing_bytes_by_class"].items())))
        for r in rec["differing_regions"][:40]:
            log("  offset %s va %s %d B %s" % (r["offset"], r["va"], r["length"], r["cls"]))
        for p in problems:
            log("  problem: " + p)
        if strict:
            log("Game.exe not written: a built byte differs from the original")
    return rec


def summary_line(rec):
    c = rec["bytes_by_class"]
    return ("complete build: identical %s (sha256 %s, original %s); borrowed code %s B in %s functions; borrowed data %s B"
            % ("yes" if rec["identical"] else "NO", rec["output_sha256"][:16], rec["original_sha256"][:16],
               "{:,}".format(c["borrowed_code"]), "{:,}".format(rec["borrowed_functions"]), "{:,}".format(c["borrowed_data"])))


def provenance_fillers(path):
    return [(int(v, 16), n) for v, n, c in json.load(open(path))["runs"] if c == "borrowed"]


