#!/usr/bin/env python3
import os, sys, json, struct, glob, bisect, hashlib, hmac, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, CFG, records

PARAMS_PLAN = os.path.join(ROOT, "build", "identity_plan.json")
RESOURCE_PLAN = os.path.join(ROOT, "build", "resource_plan.json")
GEN = os.path.join(ROOT, "gen")
STAMP = "IDENTITY.json"
SCHEMA = 1
PKWARE_LIBRARY = "PKWARE DCL"
DIR_EXPORT, DIR_RESOURCE, DIR_SECURITY, DIR_DEBUG = 0, 2, 4, 6
CLASSES = ("stamp", "resource", "library", "signature")


class IdentityError(Exception):
    pass


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


def dir_offset(i):
    return 24 + 96 + 8 * i


def directory(d, i):
    return struct.unpack_from("<II", d, e_lfanew(d) + dir_offset(i))


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
    import array
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


def image_key(data):
    return hashlib.sha256(b"d2identity-plan\0" + data).digest()


def mac(key, b):
    return hmac.new(key, b, hashlib.sha256).hexdigest()


def file_sha(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def pkware_records():
    return sorted((va, ln) for va, ln, k in records(("pkware",)))


def base_relocation_sites(d):
    rva, size = directory(d, 5); B = image_base(d); out = []
    o = rva_to_off(d, rva) if rva and size else None
    if o is None:
        return out
    end = o + size
    while o + 8 <= end:
        page, blk = struct.unpack_from("<II", d, o)
        if blk < 8:
            break
        for k in range((blk - 8) // 2):
            e = struct.unpack_from("<H", d, o + 8 + 2 * k)[0]
            if e >> 12 == 3:
                out.append(B + page + (e & 0xFFF))
        o += blk
    return sorted(out)


def pkware_data(d, pkware):
    if not pkware:
        return []
    B = image_base(d); secs = sections(d)
    text = next((s for s in secs if s["name"] == ".text"), None)
    def raw_sec(va):
        for s in secs:
            if s["va"] <= va - B < s["va"] + min(s["rawsize"], max(s["vsize"], 1)):
                return s
        return None
    in_rec = lambda va: any(a <= va < a + n for a, n in pkware)
    sites = base_relocation_sites(d)
    mine, other = set(), set()
    for s in sites:
        o = rva_to_off(d, s - B)
        if o is None or o + 4 > len(d):
            continue
        v = struct.unpack_from("<I", d, o)[0]
        sec = raw_sec(v)
        if sec is None or (text and sec is text):
            continue
        (mine if in_rec(s) and not in_rec(v) else other).add(v)
    stops = sorted(other | set(sites))
    out = []; t = sorted(mine)
    i = 0
    while i < len(t):
        lo = t[i]; sec = raw_sec(lo)
        sec_end = B + sec["va"] + min(sec["rawsize"], max(sec["vsize"], 1))
        k = bisect.bisect_right(stops, lo)
        hi = min(stops[k] if k < len(stops) else sec_end, sec_end)
        while i < len(t) and t[i] < hi:
            i += 1
        lo_k = bisect.bisect_left(stops, lo)
        if not (lo_k < len(stops) and stops[lo_k] == lo):
            out.append((lo, hi - lo))
    merged = []
    for a, n in out:
        if merged and merged[-1][0] + merged[-1][1] == a:
            merged[-1] = (merged[-1][0], merged[-1][1] + n)
        else:
            merged.append((a, n))
    return merged


def is_pkware_code(name):
    return name.startswith("pkware_") and not name.startswith("pkware_data_")


def image_items(d, pkware=()):
    p = e_lfanew(d); B = image_base(d); items = []
    def add(name, cls, where, at, length):
        items.append(collections.OrderedDict(name=name, cls=cls, where=where, at=at, length=length))
    rs = rich_start(d)
    if rs is not None:
        add("rich_block", "stamp", "file_offset", rs, p - rs)
    add("file_header_timestamp", "stamp", "pe_offset", 8, 4)
    add("checksum", "stamp", "pe_offset", 24 + 64, 4)
    add("debug_directory_entry", "stamp", "pe_offset", dir_offset(DIR_DEBUG), 8)
    erva, esz = directory(d, DIR_EXPORT)
    if erva and esz:
        add("export_directory_timestamp", "stamp", "va", B + erva + 4, 4)
    drva, dsz = directory(d, DIR_DEBUG)
    if drva and dsz:
        add("debug_directory", "stamp", "va", B + drva, dsz)
        doff = rva_to_off(d, drva)
        for k in range(dsz // 28):
            _, _, _, _, typ, size, addr, ptr = struct.unpack_from("<IIHHIIII", d, doff + 28 * k)
            if addr and size and rva_to_off(d, addr) is not None and rva_to_off(d, addr + size - 1) == rva_to_off(d, addr) + size - 1:
                add("debug_data_%d_type%d" % (k, typ), "stamp", "va", B + addr, size)
    for va, ln in pkware:
        add("pkware_%08X" % va, "library", "va", va, ln)
    for va, ln in pkware_data(d, pkware):
        add("pkware_data_%08X" % va, "library", "va", va, ln)
    end = sections_end(d)
    srva, ssz = directory(d, DIR_SECURITY)
    if ssz or len(d) > end:
        add("security_directory_entry", "signature", "pe_offset", dir_offset(DIR_SECURITY), 8)
        add("signature", "signature", "file_offset", end, len(d) - end)
    return items


def read(d, it):
    if it["where"] == "file_offset":
        o = it["at"]
    elif it["where"] == "pe_offset":
        o = e_lfanew(d) + it["at"]
    else:
        o = rva_to_off(d, it["at"] - image_base(d))
        if o is None:
            raise IdentityError("%s: VA 0x%08X has no file bytes" % (it["name"], it["at"]))
    b = d[o:o + it["length"]]
    if len(b) != it["length"]:
        raise IdentityError("%s: %d of %d bytes in the file" % (it["name"], len(b), it["length"]))
    return b


def image_resources(d):
    rva, size = directory(d, DIR_RESOURCE)
    if not rva:
        return None
    base = rva_to_off(d, rva); leaves = []; tables = []
    def name_of(n):
        if n & 0x80000000:
            raise IdentityError("named resource entries are not supported by the resource plan")
        return n
    def walk(off, path):
        ch, ts, ma, mi, nn, ni = struct.unpack_from("<IIHHHH", d, base + off); tables.append([ch, ts, ma, mi])
        for i in range(nn + ni):
            n, o = struct.unpack_from("<II", d, base + off + 16 + 8 * i)
            if o & 0x80000000:
                walk(o & 0x7FFFFFFF, path + [name_of(n)])
            else:
                drva, sz, cp, _ = struct.unpack_from("<IIII", d, base + o)
                t, nm = path
                leaves.append(collections.OrderedDict(type=t, id=nm, language=name_of(n), offset=drva - rva, size=sz, codepage=cp))
    walk(0, [])
    return rva, size, leaves, tables


def leaf_file(lf):
    return "%d_%d_%d.bin" % (lf["type"], lf["id"], lf["language"])


def _hx(it):
    out = collections.OrderedDict(it)
    out["at"] = "0x%X" % it["at"] if it["where"] != "va" else "0x%08X" % it["at"]
    return out


def load_plan(path):
    with open(path) as f:
        p = json.load(f)
    for it in p.get("items", ()):
        it["at"] = int(it["at"], 16)
    for lf in p.get("leaves", ()):
        lf["offset"] = int(lf["offset"], 16)
    return p


def plan_sha(path):
    return file_sha(path) if os.path.exists(path) else None


def tool_sha():
    return file_sha(os.path.abspath(__file__))


def stamp_of(out):
    p = os.path.join(out, "identity", STAMP)
    if not os.path.exists(p):
        return None
    with open(p) as f:
        return json.load(f)


def is_current(out, image_sha):
    st = stamp_of(out)
    return bool(st and st.get("image_sha256") == image_sha and st.get("params_plan_sha256") == plan_sha(PARAMS_PLAN)
                and st.get("resource_plan_sha256") == plan_sha(RESOURCE_PLAN) and st.get("tool_sha256") == tool_sha())


def extract(d, out=GEN, params_path=PARAMS_PLAN, resource_path=RESOURCE_PLAN):
    sha = hashlib.sha256(d).hexdigest()
    if sha != CFG["image"]["sha256"]:
        raise IdentityError("the image is not %s (sha256 %s...)" % (CFG["image"]["version"], sha[:16]))
    key = image_key(d)
    params = load_plan(params_path)
    if params.get("image_sha256") != sha:
        raise IdentityError("the image is not the one %s was made from" % os.path.relpath(params_path, ROOT))
    idir = os.path.join(out, "identity"); os.makedirs(idir, exist_ok=True)
    written = collections.OrderedDict()
    for it in params["items"]:
        b = read(d, it)
        if mac(key, b) != it["hmac"]:
            raise IdentityError("%s: the image's bytes do not hash to the plan's" % it["name"])
        with open(os.path.join(idir, it["name"] + ".bin"), "wb") as f:
            f.write(b)
        written[it["name"]] = it["hmac"]
    res_meta = None
    if os.path.exists(resource_path):
        rp = load_plan(resource_path)
        if rp.get("image_sha256") != sha:
            raise IdentityError("the image is not the one %s was made from" % os.path.relpath(resource_path, ROOT))
        r = image_resources(d)
        if not r:
            raise IdentityError("the image has no resource directory")
        rva, size, leaves, tables = r
        if (rva, size) != (int(rp["directory_rva"], 16), rp["directory_size"]):
            raise IdentityError("the resource directory is not where the plan has it")
        rdir = os.path.join(out, "rsrc"); os.makedirs(rdir, exist_ok=True)
        base = rva_to_off(d, rva); by = {(lf["type"], lf["id"], lf["language"]): lf for lf in leaves}
        cps = collections.OrderedDict()
        for lf in rp["leaves"]:
            il = by.get((lf["type"], lf["id"], lf["language"]))
            if not il or (il["offset"], il["size"]) != (lf["offset"], lf["size"]):
                raise IdentityError("resource %s: not in the image as planned" % leaf_file(lf))
            b = d[base + lf["offset"]:base + lf["offset"] + lf["size"]]
            if mac(key, b) != lf["hmac"]:
                raise IdentityError("resource %s: the image's bytes do not hash to the plan's" % leaf_file(lf))
            with open(os.path.join(rdir, leaf_file(lf)), "wb") as f:
                f.write(b)
            cps[leaf_file(lf)] = il["codepage"]
            written["rsrc/" + leaf_file(lf)] = lf["hmac"]
        res_meta = dict(tables=tables, codepages=cps)
        with open(os.path.join(rdir, "RESOURCES.json"), "w") as f:
            json.dump(res_meta, f, indent=1)
    st = collections.OrderedDict(note="generated from your own Game.exe; never commit", schema=SCHEMA, image_sha256=sha, params_plan_sha256=plan_sha(params_path),
                                 resource_plan_sha256=plan_sha(resource_path), tool_sha256=tool_sha(), items=written)
    with open(os.path.join(idir, STAMP), "w") as f:
        json.dump(st, f, indent=1)
    return st


def ensure(image_path, out=GEN, log=print):
    with open(image_path, "rb") as f:
        d = f.read()
    sha = hashlib.sha256(d).hexdigest()
    if is_current(out, sha):
        return "identity: current"
    st = extract(d, out)
    return "identity: %d items rendered from the image" % len(st["items"])


class Identity:

    def __init__(self, items, params, resources=None):
        self.items = items
        self.params = params
        self.resources = resources

    def get(self, name):
        x = self.items.get(name)
        return x[1] if x else None

    def by_class(self, cls):
        return [(it, b) for it, b in self.items.values() if it["cls"] == cls]

    def pkware(self):
        return {it["at"]: b for it, b in self.items.values() if is_pkware_code(it["name"])}

    def va_items(self, cls=None):
        return [(it, b) for it, b in self.items.values() if it["where"] == "va" and not is_pkware_code(it["name"])
                and (cls is None or it["cls"] == cls)]


def from_image(d, pkware=()):
    items = collections.OrderedDict((it["name"], (it, read(d, it))) for it in image_items(d, pkware))
    params = dict(e_lfanew="0x%X" % e_lfanew(d), size_of_headers="0x%X" % size_of_headers(d), sections_end="0x%X" % sections_end(d))
    res = None
    try:
        r = image_resources(d)
    except (IdentityError, struct.error, TypeError):
        r = None
    if r:
        rva, size, leaves, tables = r
        base = rva_to_off(d, rva)
        res = dict(rva=rva, size=size, tables=tables,
                   leaves=[dict(lf, data=d[base + lf["offset"]:base + lf["offset"] + lf["size"]]) for lf in leaves])
    return Identity(items, params, res)


def load(image_data=None, out=GEN, params_path=PARAMS_PLAN, resource_path=RESOURCE_PLAN):
    params = load_plan(params_path)
    key = image_key(image_data) if image_data is not None else None
    idir = os.path.join(out, "identity"); items = collections.OrderedDict()
    for it in params["items"]:
        p = os.path.join(idir, it["name"] + ".bin")
        if not os.path.exists(p):
            raise IdentityError("gen/identity/%s.bin is missing: run setup/setup.py (or tools/file_identity.py extract)" % it["name"])
        with open(p, "rb") as f:
            b = f.read()
        if len(b) != it["length"] or (key and mac(key, b) != it["hmac"]):
            raise IdentityError("gen/identity/%s.bin does not match the plan" % it["name"])
        items[it["name"]] = (it, b)
    res = None
    if os.path.exists(resource_path):
        rp = load_plan(resource_path); rdir = os.path.join(out, "rsrc")
        mp = os.path.join(rdir, "RESOURCES.json")
        if not os.path.exists(mp):
            raise IdentityError("gen/rsrc/RESOURCES.json is missing: run setup/setup.py (or tools/file_identity.py extract)")
        with open(mp) as f:
            meta = json.load(f)
        leaves = []
        for lf in rp["leaves"]:
            p = os.path.join(rdir, leaf_file(lf))
            if not os.path.exists(p):
                raise IdentityError("gen/rsrc/%s is missing" % leaf_file(lf))
            with open(p, "rb") as f:
                b = f.read()
            if len(b) != lf["size"] or (key and mac(key, b) != lf["hmac"]):
                raise IdentityError("gen/rsrc/%s does not match the plan" % leaf_file(lf))
            x = dict(lf); x["data"] = b; x["codepage"] = meta["codepages"][leaf_file(lf)]; leaves.append(x)
        res = dict(rva=int(rp["directory_rva"], 16), size=rp["directory_size"], tables=meta["tables"], leaves=leaves)
    return Identity(items, params, res)


def apply(linked, ident, checksum="stamp"):
    problems = []; regions = []; info = {}
    P = ident.params
    po = int(P["e_lfanew"], 16); pn = e_lfanew(linked)
    hs = size_of_headers(linked)
    if hs != int(P["size_of_headers"], 16):
        problems.append("SizeOfHeaders differs: plan %s, linked 0x%X" % (P["size_of_headers"], hs))
    end_n = sections_end(linked)
    out = bytearray(linked[:end_n])
    if len(linked) > end_n and any(linked[end_n:]):
        problems.append("the linked file has %d bytes after its last section" % (len(linked) - end_n))
    rich = ident.items.get("rich_block")
    if rich:
        it, rb = rich
        rn = rich_start(linked); rn = pn if rn is None else rn
        if rn != it["at"]:
            problems.append("the DOS stub ends at 0x%X in the plan and 0x%X in the link" % (it["at"], rn))
        if it["at"] + it["length"] != po:
            problems.append("the Rich block does not end at the plan's e_lfanew")
        h = bytearray(hs)
        h[:min(rn, hs)] = linked[:min(rn, hs)]
        h[it["at"]:it["at"] + it["length"]] = rb; regions.append((it["at"], it["length"], "stamp", "Rich block"))
        struct.pack_into("<I", h, 0x3C, po); regions.append((0x3C, 4, "stamp", "e_lfanew (follows the Rich block)"))
        move = hs - max(po, pn)
        h[po:po + move] = linked[pn:pn + move]
        if any(linked[pn + move:hs]):
            problems.append("moving the PE header from 0x%X to 0x%X would drop non-zero header bytes" % (pn, po))
        out[:hs] = h
        info["e_lfanew"] = dict(linked="0x%X" % pn, written="0x%X" % po)
    p = e_lfanew(out)
    for name, what in (("file_header_timestamp", "file header timestamp"), ("debug_directory_entry", "debug directory entry")):
        x = ident.items.get(name)
        if x:
            out[p + x[0]["at"]:p + x[0]["at"] + x[0]["length"]] = x[1]; regions.append((p + x[0]["at"], x[0]["length"], "stamp", what))
    B = image_base(out)
    for it, b in ident.va_items():
        o = rva_to_off(out, it["at"] - B)
        if o is None or rva_to_off(out, it["at"] - B + it["length"] - 1) != o + it["length"] - 1:
            problems.append("%s: VA 0x%08X has no file bytes in the link" % (it["name"], it["at"])); continue
        out[o:o + it["length"]] = b; regions.append((o, it["length"], it["cls"], it["name"]))
    sig = ident.items.get("signature")
    if sig:
        if end_n != sig[0]["at"]:
            problems.append("the last section ends at 0x%X in the link, the signature's plan offset is 0x%X" % (end_n, sig[0]["at"]))
        se = ident.items.get("security_directory_entry")
        if se:
            off, ln = struct.unpack("<II", se[1])
            if (off, ln) != (sig[0]["at"], sig[0]["length"]):
                problems.append("the security directory entry does not point at the signature")
            out[p + se[0]["at"]:p + se[0]["at"] + 8] = se[1]; regions.append((p + se[0]["at"], 8, "signature", "security directory entry"))
        regions.append((len(out), len(sig[1]), "signature", "Authenticode signature"))
        out += sig[1]
        info["signature_bytes"] = len(sig[1])
    ck = p + 24 + 64
    computed = pe_checksum(bytes(out), ck)
    x = ident.items.get("checksum")
    if checksum == "stamp" and x:
        out[ck:ck + 4] = x[1]; regions.append((ck, 4, "stamp", "checksum"))
        info["checksum"] = dict(written="stamp", valid=struct.unpack("<I", x[1])[0] == computed)
    else:
        struct.pack_into("<I", out, ck, computed)
        info["checksum"] = dict(written="computed", valid=True)
    return bytes(out), regions, problems, info


