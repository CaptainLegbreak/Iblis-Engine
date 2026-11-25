#!/usr/bin/env python3
import struct, collections

SCN_CODE, SCN_COMDAT, SCN_REMOVE, SCN_ALIGN_MASK = 0x20, 0x1000, 0x800, 0x00F00000
ALIGN_1 = 0x00100000
REL32, DIR32, DIR32NB, SECTION, SECREL = 0x14, 0x06, 0x07, 0x0A, 0x0B
IMPORT_SIG = b"\0\0\xff\xff"
IMPORT_CODE, IMPORT_DATA = 0, 1
NAME_ORDINAL, NAME_NAME, NAME_NOPREFIX, NAME_UNDECORATE = 0, 1, 2, 3


def ar_members(data):
    if data[:8] != b"!<arch>\n":
        raise ValueError("not an archive")
    pos = 8; longnames = b""; idx = 0; out = []
    while pos + 60 <= len(data):
        hdr = data[pos:pos + 60]; name = hdr[:16].decode("latin-1").rstrip(); size = int(hdr[48:58].decode().strip())
        body_at = pos + 60; body = data[body_at:body_at + size]
        if name == "//":
            longnames = body
        elif name not in ("/", "/SYM64/"):
            if name.startswith("/") and name[1:].isdigit():
                o = int(name[1:]); name = longnames[o:longnames.index(b"\0", o)].decode("latin-1") if b"\0" in longnames[o:] else longnames[o:].decode("latin-1")
            elif name.endswith("/"):
                name = name[:-1]
            out.append((idx, name, body_at, body))
        idx += 1; pos = body_at + size + (size & 1)
    return out


def ar_write(members):
    def syms_of(body):
        if body[:4] == IMPORT_SIG:
            s = body[20:].split(b"\0")[0].decode("latin-1"); return [s, "__imp_" + s]
        out = []; nsym = struct.unpack_from("<I", body, 12)[0]; symptr = struct.unpack_from("<I", body, 8)[0]
        strtab = symptr + 18 * nsym; i = 0
        while i < nsym:
            o = symptr + 18 * i; raw = body[o:o + 8]; val, scn, typ, cls, naux = struct.unpack_from("<IhHBB", body, o + 8)
            nm = (body[strtab + struct.unpack_from("<I", raw, 4)[0]:body.index(b"\0", strtab + struct.unpack_from("<I", raw, 4)[0])]
                  if raw[:4] == b"\0\0\0\0" else raw.rstrip(b"\0")).decode("latin-1")
            if cls == 2 and scn != 0:
                out.append(nm)
            i += 1 + naux
        return out
    def hdr(name, size):
        return (name.ljust(16) + "0".ljust(12) + "0".ljust(6) + "0".ljust(6) + "0".ljust(8) + str(size).ljust(10) + "`\n").encode("latin-1")
    table = [(s, k) for k, (_, b) in enumerate(members) for s in syms_of(b)]
    first_size = 4 + 4 * len(table) + sum(len(s) + 1 for s, _ in table)
    offs = []; pos = 8 + 60 + first_size + (first_size & 1)
    for name, body in members:
        offs.append(pos); pos += 60 + len(body) + (len(body) & 1)
    first = struct.pack(">I", len(table)) + b"".join(struct.pack(">I", offs[k]) for _, k in table) + b"".join(s.encode("latin-1") + b"\0" for s, _ in table)
    out = bytearray(b"!<arch>\n" + hdr("/", len(first)) + first + (b"\n" if len(first) & 1 else b""))
    for name, body in members:
        out += hdr(name[:15] + "/", len(body)) + body + (b"\n" if len(body) & 1 else b"")
    return bytes(out)


def short_import(body):
    if body[:4] != IMPORT_SIG:
        return None
    ver, mach, ts, size, hint, typ = struct.unpack_from("<HHIIHH", body, 4)
    parts = body[20:20 + size].split(b"\0")
    return dict(sym=parts[0].decode("latin-1"), dll=parts[1].decode("latin-1"), hint=hint, type=typ & 3, name_type=(typ >> 2) & 7)


def short_import_obj(sym, dll, hint, name_type, typ=0):
    names = sym.encode("latin-1") + b"\0" + dll.encode("latin-1") + b"\0"
    return IMPORT_SIG + struct.pack("<HHIIHH", 0, 0x14C, 0, len(names), hint, (typ & 3) | ((name_type & 7) << 2)) + names


def patch_import_lib(data, want):
    out = bytearray(data); n = 0
    for idx, name, at, body in ar_members(data):
        si = short_import(body)
        if si and si["sym"] in want:
            hint, nt = want[si["sym"]]
            typ = struct.unpack_from("<H", body, 18)[0]
            struct.pack_into("<HH", out, at + 16, hint & 0xFFFF, (typ & ~(7 << 2)) | ((nt & 7) << 2)); n += 1
    return bytes(out), n


def reloc_width(ty):
    return 2 if ty == SECTION else 4


def masked(raw, rels):
    mask = bytearray(b"\xff" * len(raw))
    for off, ty in rels:
        for k in range(reloc_width(ty)):
            if off + k < len(mask):
                mask[off + k] = 0
    return bytes(raw), bytes(mask)


def code_sections(members, Obj):
    out = []
    for idx, mname, at, body in members:
        if body[:4] == IMPORT_SIG or len(body) < 20 or struct.unpack_from("<H", body, 0)[0] != 0x14C:
            continue
        o = Obj(body)
        for i, s in enumerate(o.secs):
            scn = i + 1
            if not (s["ch"] & SCN_CODE) or not s["raw"] or s["ch"] & SCN_REMOVE:
                continue
            rels = [(r["offset"], r["ty"], r["sym"]["name"], r["sym"]["cls"], r["sym"]["scn"]) for r in o.relocs(scn)]
            raw, mask = masked(s["raw"], [(a, b) for a, b, _, _, _ in rels])
            in_sec = [y for y in o.syms if y["scn"] == scn and not (y["cls"] == 3 and y["name"] == s["name"] and y["naux"])]
            key = next((dict(name=y["name"], cls=y["cls"], idx=y["idx"], value=y["value"]) for y in in_sec), None)
            al = (s["ch"] & SCN_ALIGN_MASK) >> 20
            out.append(dict(member=idx, mname=mname.split("\\")[-1], scn=scn, raw=raw, mask=mask, fixed=sum(1 for m in mask if m),
                            comdat=bool(s["ch"] & SCN_COMDAT), align=(1 << (al - 1)) if al else 16,
                            defs=[(y["name"], y["value"]) for y in in_sec if y["cls"] == 2], key=key, rels=rels))
    return out


def anchor(mask):
    best = (0, 0); i = 0; n = len(mask)
    while i < n:
        if mask[i]:
            j = i
            while j < n and mask[j]:
                j += 1
            if j - i > best[1]:
                best = (i, j - i)
            i = j
        else:
            i += 1
    return best


def find_placements(sections, window, wlo):
    out = []
    for s in sections:
        off, ln = anchor(s["mask"])
        if not ln:
            continue
        key = s["raw"][off:off + min(ln, 24)]; raw, mask = s["raw"], s["mask"]; n = len(raw)
        p = window.find(key)
        while p != -1:
            st = p - off
            if st >= 0 and st + n <= len(window):
                seg = window[st:st + n]
                if all(seg[k] == raw[k] for k in range(n) if mask[k]):
                    out.append(dict(sec=s, va=wlo + st))
            p = window.find(key, p + 1)
    return out


def _targets(c, window, wlo):
    out = []
    for off, ty, nm, cls, scn in c["sec"]["rels"]:
        if cls != 2 or ty not in (REL32, DIR32):
            continue
        a = c["va"] + off
        if not (wlo <= a and a + 4 <= wlo + len(window)):
            continue
        v = struct.unpack_from("<I", window, a - wlo)[0]; add = struct.unpack_from("<I", c["sec"]["raw"], off)[0]
        out.append((nm, ((a + 4 + v - add) if ty == REL32 else (v - add)) & 0xFFFFFFFF))
    return out


def keyed_targets(c, window, wlo):
    out = []
    for off, ty, nm, cls, scn in c["sec"]["rels"]:
        if ty not in (REL32, DIR32):
            continue
        if cls == 2:
            k = nm
        elif cls == 3 and scn > 0 and scn != c["sec"]["scn"] and not nm.startswith(("$", ".")):
            k = (c["sec"]["member"], nm)
        else:
            continue
        a = c["va"] + off
        if not (wlo <= a and a + 4 <= wlo + len(window)):
            continue
        v = struct.unpack_from("<I", window, a - wlo)[0]; add = struct.unpack_from("<I", c["sec"]["raw"], off)[0]
        out.append((k, ((a + 4 + v - add) if ty == REL32 else (v - add)) & 0xFFFFFFFF))
    return out


def own_data_fit(c, o, read):
    ok = bad = 0; raw = c["sec"]["raw"]
    for r in o.relocs(c["sec"]["scn"]):
        y = r["sym"]
        if r["ty"] != DIR32 or y["scn"] <= 0 or o.secs[y["scn"] - 1]["ch"] & SCN_CODE or not o.secs[y["scn"] - 1]["raw"]:
            continue
        v = read(c["va"] + r["offset"], 4)
        if not v or len(v) < 4:
            bad += 1; continue
        base = (struct.unpack("<I", v)[0] - struct.unpack_from("<I", raw, r["offset"])[0] - y["value"]) & 0xFFFFFFFF
        ds = o.secs[y["scn"] - 1]; dr, dm = masked(ds["raw"], [(x["offset"], x["ty"]) for x in o.relocs(y["scn"])])
        img = read(base, len(dr))
        if img is not None and len(img) == len(dr) and all(img[k] == dr[k] for k in range(len(dr)) if dm[k]):
            ok += 1
        else:
            bad += 1
    return ok, bad


def own_keys(c):
    out = [(nm, c["va"] + v) for nm, v in c["sec"]["defs"]]
    k = c["sec"]["key"]
    if k and k["cls"] == 3:
        out.append(((c["sec"]["member"], k["name"]), c["va"] + k.get("value", 0)))
    return out


def choose_placements(cands, window, wlo, rounds=8):
    sid = lambda c: (c["sec"]["member"], c["sec"]["scn"])
    for c in cands:
        c["targets"] = _targets(c, window, wlo); c["keyed"] = keyed_targets(c, window, wlo)
    cnt = collections.Counter(sid(c) for c in cands)

    def evidence(pieces):
        d = {}; votes = collections.defaultdict(collections.Counter)
        for c in pieces:
            for k, a in own_keys(c):
                d.setdefault(k, a)
        for c in pieces:
            for k, a in c["keyed"]:
                votes[k][a] += 1
        for k, v in votes.items():
            if k not in d:
                d[k] = max(v.items(), key=lambda kv: (kv[1], -kv[0]))[0]
        return d

    def trusted(pieces):
        return [c for c in pieces if (c["sec"]["fixed"] >= 16 and cnt[sid(c)] == 1) or c.get("confirmed")]
    defs = evidence(trusted(cands))

    def score(c):
        ok = bad = 0
        for k, t in c["keyed"]:
            if k in defs:
                ok, bad = (ok + 1, bad) if defs[k] == t else (ok, bad + 1)
        for k, a in own_keys(c):
            if k in defs:
                ok, bad = (ok + 1, bad) if defs[k] == a else (ok, bad + 1)
        c["tgt_ok"], c["tgt_bad"] = ok, bad

    def greedy():
        taken = bytearray(len(window)); used = set(); names = set(); chosen = []; size = collections.Counter()
        order = sorted(cands, key=lambda c: (-c["sec"]["fixed"], c["tgt_bad"] - c["tgt_ok"], c["va"], len(c["sec"]["raw"]), sid(c)))
        i = 0
        while i < len(order):
            g = order[i]; tie = lambda x: (x["sec"]["fixed"], x["tgt_bad"] - x["tgt_ok"], x["va"], len(x["sec"]["raw"]))
            j = i
            while j < len(order) and tie(order[j]) == tie(g):
                j += 1
            group = order[i:j]; i = j
            a, b = g["va"] - wlo, g["va"] - wlo + len(g["sec"]["raw"])
            if any(taken[a:b]):
                continue
            ok = [c for c in group if sid(c) not in used and not any(nm in names for nm, _ in c["sec"]["defs"])]
            if not ok:
                continue
            c = max(ok, key=lambda c: (size[c["sec"]["member"]], -c["sec"]["member"], -c["sec"]["scn"]))
            taken[a:b] = b"\1" * (b - a); used.add(sid(c)); names.update(nm for nm, _ in c["sec"]["defs"]); chosen.append(c)
            size[c["sec"]["member"]] += len(c["sec"]["raw"])
        return chosen
    chosen = []
    for _ in range(rounds):
        for c in cands:
            score(c)
        chosen = greedy()
        for c in cands:
            c["confirmed"] = False
        for c in chosen:
            c["confirmed"] = c["tgt_ok"] >= 1 and c["tgt_bad"] == 0
        nd = evidence(trusted(chosen))
        if nd == defs:
            break
        defs = nd
    votes = collections.defaultdict(collections.Counter)
    for c in trusted(chosen):
        for k, t in c["keyed"]:
            votes[k][t] += 1
    implied = {k: v.most_common(1)[0][0] for k, v in votes.items()}
    byspot = collections.defaultdict(list)
    for c in cands:
        byspot[(c["va"], len(c["sec"]["raw"]))].append(c)
    used = {sid(c) for c in chosen}

    def fit(x):
        return sum((1 if implied[k] == a else -1) for k, a in own_keys(x) if k in implied)
    for i, c in enumerate(chosen):
        best = max(byspot[(c["va"], len(c["sec"]["raw"]))], key=lambda x: (fit(x), x is c))
        if best is not c and fit(best) > fit(c) and sid(best) not in used:
            used.discard(sid(c)); used.add(sid(best)); chosen[i] = best
    defs = evidence(trusted(chosen))
    for c in chosen:
        score(c); c["n_targets"] = len(c["targets"])
        c["strong"] = c["sec"]["fixed"] >= 8 or (c["tgt_ok"] >= 1 and c["tgt_bad"] == 0)
    return sorted(chosen, key=lambda c: c["va"])


def member_rewrite(d, placed, k, Obj, rewrite_obj, extra=None):
    o = Obj(d); sym_changes = {}; sec_flags = {}; sec_names = {}; keys = {}; notes = collections.Counter(); aux_sel = {}
    for scn, va in placed.items():
        s = o.secs[scn - 1]; ch = s["ch"]
        secsym = next((y for y in o.syms if y["scn"] == scn and y["cls"] == 3 and y["name"] == s["name"] and y["naux"]), None)
        key = next((y for y in o.syms if y["scn"] == scn and y is not secsym and (secsym is None or y["idx"] > secsym["idx"])), None)
        if key is None or secsym is None:
            notes["unkeyed"] += 1; continue
        if not ch & SCN_COMDAT:
            ch |= SCN_COMDAT; aux_sel[secsym["idx"]] = 2; notes["comdatized"] += 1
        elif d[o.symptr + 18 * (secsym["idx"] + 1) + 14] == 5:
            aux_sel[secsym["idx"]] = 2; notes["associative_made_any"] += 1
        if key["cls"] != 2:
            nn = "%s%s$c%d" % ("" if key["name"][:1] in ("_", "?", "@") else "_", key["name"], k); sym_changes[key["idx"]] = dict(name=nn, cls=2); keys[scn] = nn; notes["static_key_renamed"] += 1
        else:
            keys[scn] = key["name"]
        al = (ch & SCN_ALIGN_MASK) >> 20; align = (1 << (al - 1)) if al else 16
        if va % align:
            ch = (ch & ~SCN_ALIGN_MASK) | ALIGN_1; notes["unaligned_start"] += 1
        if ch != s["ch"]:
            sec_flags[scn] = ch
        if s["name"] != ".text" and s["name"].startswith(".text"):
            sec_names[scn] = ".text"; notes["grouped_section_renamed"] += 1
    sec_data = None; new_defs = ()
    if extra:
        sec_names.update(extra.get("sec_names", {})); sec_flags.update(extra.get("sec_flags", {}))
        sym_changes.update(extra.get("sym_changes", {})); sec_data = extra.get("sec_data"); new_defs = extra.get("new_defs", ())
    out = bytearray(rewrite_obj(d, sym_changes, sec_flags, sec_names=sec_names, sec_data=sec_data, new_defs=new_defs))
    for idx, sel in aux_sel.items():
        out[o.symptr + 18 * (idx + 1) + 14] = sel
    return bytes(out), keys, notes


def image_descriptors(pe):
    d = pe.data; p = struct.unpack_from("<I", d, 0x3C)[0]; opt = p + 24
    rva = struct.unpack_from("<I", d, opt + 96 + 8)[0]; out = []
    if not rva:
        return out
    off = pe.va_to_off(pe.image_base + rva)
    while True:
        oft, _, _, name_rva, ft = struct.unpack_from("<IIIII", d, off)
        if not ft:
            break
        no = pe.va_to_off(pe.image_base + name_rva)
        out.append(dict(dll=d[no:d.index(b"\0", no)].decode("latin-1"), name_va=pe.image_base + name_rva,
                        int_va=pe.image_base + oft if oft else None, iat_va=pe.image_base + ft))
        off += 20
    return out


def image_imports(pe):
    d = pe.data; out = []
    for desc in image_descriptors(pe):
        t = pe.va_to_off(desc["int_va"] or desc["iat_va"]); ft = desc["iat_va"]; k = 0
        while True:
            e = struct.unpack_from("<I", d, t + 4 * k)[0]
            if not e:
                break
            if e & 0x80000000:
                out.append(dict(slot=ft + 4 * k, dll=desc["dll"], name=None, ordinal=e & 0xFFFF, hint=e & 0xFFFF, name_va=None))
            else:
                ho = pe.va_to_off(pe.image_base + e); hint = struct.unpack_from("<H", d, ho)[0]
                out.append(dict(slot=ft + 4 * k, dll=desc["dll"], name=d[ho + 2:d.index(b"\0", ho + 2)].decode("latin-1"), ordinal=None,
                                hint=hint, name_va=pe.image_base + e))
            k += 1
    return sorted(out, key=lambda e: e["slot"])


def vc_qsort(a, key):
    cmp = lambda x, y: (key(x) > key(y)) - (key(x) < key(y))
    if len(a) < 2:
        return a
    stack = []; lo = 0; hi = len(a) - 1
    while True:
        size = hi - lo + 1
        if size <= 8:
            while hi > lo:
                mx = lo
                for p in range(lo + 1, hi + 1):
                    if cmp(a[p], a[mx]) > 0:
                        mx = p
                a[mx], a[hi] = a[hi], a[mx]; hi -= 1
        else:
            mid = lo + size // 2
            if cmp(a[lo], a[mid]) > 0:
                a[lo], a[mid] = a[mid], a[lo]
            if cmp(a[lo], a[hi]) > 0:
                a[lo], a[hi] = a[hi], a[lo]
            if cmp(a[mid], a[hi]) > 0:
                a[mid], a[hi] = a[hi], a[mid]
            loguy = lo; higuy = hi
            while True:
                if mid > loguy:
                    loguy += 1
                    while loguy < mid and cmp(a[loguy], a[mid]) <= 0:
                        loguy += 1
                if mid <= loguy:
                    loguy += 1
                    while loguy <= hi and cmp(a[loguy], a[mid]) <= 0:
                        loguy += 1
                higuy -= 1
                while higuy > mid and cmp(a[higuy], a[mid]) > 0:
                    higuy -= 1
                if higuy < loguy:
                    break
                a[loguy], a[higuy] = a[higuy], a[loguy]
                if mid == higuy:
                    mid = loguy
            higuy += 1
            if mid < higuy:
                higuy -= 1
                while higuy > mid and cmp(a[higuy], a[mid]) == 0:
                    higuy -= 1
            if mid >= higuy:
                higuy -= 1
                while higuy > lo and cmp(a[higuy], a[mid]) == 0:
                    higuy -= 1
            if higuy - lo >= hi - loguy:
                if lo < higuy:
                    stack.append((lo, higuy))
                if loguy < hi:
                    lo = loguy; continue
            else:
                if loguy < hi:
                    stack.append((loguy, hi))
                if lo < higuy:
                    hi = higuy; continue
        if not stack:
            break
        lo, hi = stack.pop()
    return a


IMPORT, NAME, GHOST = "import", "name", "ghost"


def import_tables_of(sequence):
    arr = list(sequence)
    vc_qsort(arr, lambda x: x[0])
    out = collections.OrderedDict()
    for dll, kind, key in arr:
        if kind == IMPORT:
            out.setdefault(dll, []).append(key)
    return out


def import_pull_sequence(pe, max_ghosts=12, max_insertions=6):
    entries = image_imports(pe); descs = image_descriptors(pe)
    iat = collections.OrderedDict()
    for e in entries:
        iat.setdefault(e["dll"], []).append(e["name"] if e["name"] is not None else "#%d" % e["ordinal"])
    by_va = [(e["name_va"], e["dll"], IMPORT, e["name"]) for e in entries if e["name_va"]] + [(d["name_va"], d["dll"], NAME, None) for d in descs]
    seq = []
    for va, dll, kind, key in sorted(by_va):
        if kind == NAME:
            seq += [(dll, IMPORT, k) for k in iat[dll] if k.startswith("#")]
        seq.append((dll, kind, key))
    named = {dll for dll, ks in iat.items() if not all(k.startswith("#") for k in ks)}
    total_named = sum(len(ks) for dll, ks in iat.items() if dll in named)

    def correct(s, dlls):
        got = import_tables_of(s)
        return sum(1 for dll in dlls for i, k in enumerate(got.get(dll, [])) if i < len(iat[dll]) and iat[dll][i] == k)
    best = correct(seq, named); dlls = list(iat); ghosts = 0
    for _ in range(max_insertions):
        if best == total_named:
            break
        found = None
        for g in range(len(seq) + 1):
            for dll in dlls:
                for n in range(1, max_ghosts + 1):
                    c = correct(seq[:g] + [(dll, GHOST, None)] * n + seq[g:], named)
                    if c > best:
                        best = c; found = (g, dll, n)
        if not found:
            break
        g, dll, n = found; seq = seq[:g] + [(dll, GHOST, None)] * n + seq[g:]; ghosts += n
    tagged = [(dll, kind, key, i) for i, (dll, kind, key) in enumerate(seq)]
    vc_qsort(tagged, lambda x: x[0])
    for dll in iat:
        if dll in named:
            continue
        pos = [i for d, kind, key, i in tagged if d == dll and kind == IMPORT]
        for slot, i in enumerate(pos):
            seq[i] = (dll, IMPORT, iat[dll][slot])
    got = import_tables_of(seq)
    n_ok = sum(1 for dll in iat for i, k in enumerate(got.get(dll, [])) if i < len(iat[dll]) and iat[dll][i] == k)
    order = []
    for dll, kind, key in seq:
        if dll not in order:
            order.append(dll)
    return dict(sequence=seq, ghosts=ghosts, slots=len(entries), correct=n_ok,
                descriptors_in_order=order == [d["dll"] for d in descs])


def ghost_symbol(dll, n):
    return "_d2ghost_%s_%d@0" % ("".join(c if c.isalnum() else "_" for c in dll.split(".")[0]), n)


def split_import_libs(sequence, member_of, headers, ghost_sym=ghost_symbol):
    runs = []
    for dll, kind, key in sequence:
        is_ghost = kind == GHOST
        if runs and runs[-1][0] == dll and runs[-1][1] == is_ghost:
            runs[-1][2].append((kind, key))
        else:
            runs.append((dll, is_ghost, [(kind, key)]))
    out = []; nghost = collections.Counter()
    for i, (dll, is_ghost, items) in enumerate(runs):
        members = []; syms = []
        for kind, key in items:
            if kind == NAME:
                members += [(dll, body) for _, body in headers[dll]]
            elif kind == GHOST:
                nghost[dll] += 1; s = ghost_sym(dll, nghost[dll])
                members.append((dll, short_import_obj(s, dll, 0, NAME_UNDECORATE, IMPORT_DATA))); syms.append("__imp_" + s)
            else:
                s, body = member_of[(dll, key)]; members.append((dll, body)); syms.append("__imp_" + s)
        out.append(("%03d_%s%s" % (i, dll.split(".")[0], "_ghost" if is_ghost else ""), ar_write(members), syms))
    return out


def undecorate(sym):
    s = sym[1:] if sym[:1] in ("_", "@") else sym
    return s.split("@")[0] if "@" in s else s


def import_name_type(sym, entry):
    if entry["name"] is None:
        return NAME_ORDINAL
    if entry["name"] == sym:
        return NAME_NAME
    if sym[:1] in ("_", "@", "?") and entry["name"] == sym[1:]:
        return NAME_NOPREFIX
    if entry["name"] == undecorate(sym):
        return NAME_UNDECORATE
    return None


def def_text(dll, entries):
    lines = ["LIBRARY \"%s\"" % dll, "EXPORTS"]
    for sym, e in entries:
        nm = sym[1:] if sym.startswith("_") else sym
        lines.append("  %s @%d NONAME" % (nm, e["ordinal"]) if e["name"] is None else "  %s" % nm)
    return "\n".join(lines) + "\n"


def driver_obj(names, coff_write, secaux):
    syms = [dict(name=".d2drv", value=0, scn=1, cls=3, aux=[secaux(4 * len(names), len(names))])]
    rel = []
    for i, n in enumerate(names):
        rel.append((4 * i, 2 + i, DIR32)); syms.append(dict(name=n, value=0, scn=0, cls=2))
    return coff_write([dict(name=".d2drv", data=b"\0" * (4 * len(names)), ch=0x40300040 | SCN_REMOVE, relocs=rel)], syms)


def settle_members(chosen, cands, member_info):
    sid = lambda c: (c["sec"]["member"], c["sec"]["scn"])
    byspot = collections.defaultdict(list)
    for c in cands:
        byspot[(c["va"], len(c["sec"]["raw"]))].append(c)
    refused = set(); notes = collections.Counter(); cur = list(chosen)
    for _ in range(8):
        size = collections.Counter()
        for c in cur:
            size[c["sec"]["member"]] += len(c["sec"]["raw"])
        seen_all = set(); seen_strict = set()
        for m in sorted(size, key=lambda m: (-size[m], m)):
            if m in refused:
                continue
            i = member_info.get(m, dict(strict_defs=set(), all_defs=set()))
            if (i["strict_defs"] & seen_all) or (i["all_defs"] & seen_strict):
                refused.add(m); notes["refused_duplicate_definition"] += 1; continue
            seen_all |= i["all_defs"]; seen_strict |= i["strict_defs"]
        if not any(c["sec"]["member"] in refused for c in cur):
            break
        used = {sid(c) for c in cur if c["sec"]["member"] not in refused}
        keep_members = {c["sec"]["member"] for c in cur if c["sec"]["member"] not in refused}
        nxt = []
        for c in cur:
            if c["sec"]["member"] not in refused:
                nxt.append(c); continue
            alts = [x for x in byspot[(c["va"], len(c["sec"]["raw"]))] if x["sec"]["member"] not in refused and sid(x) not in used]
            alts.sort(key=lambda x: (x["sec"]["member"] not in keep_members, x["sec"]["member"]))
            if alts:
                a = alts[0]
                for k in ("tgt_ok", "tgt_bad", "n_targets", "strong"):
                    a.setdefault(k, c.get(k))
                nxt.append(a); used.add(sid(a)); notes["moved_to_alternative"] += 1
            else:
                notes["dropped"] += 1
        cur = nxt
    return sorted(cur, key=lambda c: c["va"]), notes


def pull_closure(members, defs_of, undef_of):
    first = {}
    for m in sorted(defs_of):
        for n in defs_of[m]:
            first.setdefault(n, m)
    have = set(members); todo = list(members); defined = set().union(*[defs_of.get(m, set()) for m in members]) if members else set()
    missing = set()
    while todo:
        m = todo.pop()
        for n in undef_of.get(m, ()):
            if n in defined:
                continue
            o = first.get(n)
            if o is None:
                missing.add(n)
            elif o not in have:
                have.add(o); todo.append(o); defined |= defs_of[o]
    return have, missing - defined


