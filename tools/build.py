#!/usr/bin/env python3
"""Build Game.exe from the sources.

  python tools/build.py [--out DIR] [-j N] [--game PATH] [--cl PATH] [--crt-lib DIR] [--sdk-lib DIR]
                        [--compile-only] [--files Source/A.cpp,...] [--clean]

1. compiles every unit of build/units.json with the pinned MSVC 2005 SP1 compiler into <out>/obj
   (units marked ltcg are compiled with /GL and linked /LTCG, then lifted into an ordinary object);
2. checks every function each unit defines against the original's bytes;
3. links all verified functions at their original addresses; code and data no source defines yet are taken from
   your Game.exe;
4. writes <out>/Game.exe and checks that its SHA-256 equals the original's.

Settings come from local.json (written by tools/setup.py) unless given on the command line. Objects are cached in
<out>/obj and reused while the source, its generated data and its flags are unchanged.
"""
import os, re, sys, json, glob, shutil, subprocess, time, hashlib, threading, concurrent.futures as cf

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, CFG, default_flags, settings, check_image, check_toolchain, compile_env, unit_env, unit_headers, cl_command, \
    sha256, expand_gen_includes, missing_gen_includes, gen_includes, load_json, norm_va, PE, die
import checker

EQUAL = ("RAW_EQUAL", "RELOCATION_RESOLVED_EQUAL")


def opt(args, name, default=None):
    return args[args.index(name) + 1] if name in args else default


def gen_hash(text, rel=None):
    h = hashlib.sha256()
    for p in unit_headers(text, rel):
        h.update(p.encode() + b"\0" + open(p, "rb").read() + b"\0")
    for p in gen_includes(text):
        q = os.path.join(ROOT, p)
        h.update(p.encode() + b"\0" + (open(q, "rb").read() if os.path.exists(q) else b"<missing>") + b"\0")
    return h.hexdigest()


def unit_twins(res, src):
    if res.get("status") != "MULTI_FORM_REJECTED":
        return res
    defs, decls, symbols = checker.parse_markers(src)
    keep = []
    for name in res["extra_forms"]:
        h, kinds = checker.resolve(name, defs, decls, symbols)
        if h is checker.AMBIGUOUS or not (kinds & {"symbol", "def_", "wildcard"}):
            keep.append(name)
    res["extra_forms"] = keep
    if keep:
        return res
    equal_len = res["compiled_length"] == res["expected_length"]
    if equal_len and res["diff_bytes"] == 0:
        res["status"] = "RAW_EQUAL"
    elif equal_len and res["unmasked_diff_bytes"] == 0:
        res["status"] = "RELOCATION_RESOLVED_EQUAL" if not res["target_problems"] else "MASKED_EQUAL_BUT_TARGETS_DIFFER"
    else:
        res["status"] = "MISMATCH"
    return res


def body_by_name(ob, name, va, n, read):
    try:
        c = checker.Coff(ob)
        hits = [y for y in c.funcs() if checker.undec(y["name"]) == name]
        if not hits or len(set(y["scn"] for y in hits)) > 1:
            return False
        body = c.secs[hits[0]["scn"] - 1]["raw"]
        if len(body) != n:
            return False
        mask = bytearray(len(body))
        for r in c.relocs(hits[0]["scn"]):
            for k in range(4):
                mask[r["offset"] + k] = 1
        orig = read(va, n)
        return all(mask[i] or body[i] == orig[i] for i in range(n))
    except Exception:
        return False


class Builder:
    def __init__(self, s, out):
        self.s = s; self.out = out; self.env = compile_env(s)
        self.pe = PE(s["image"]); self.cl_sha = check_toolchain(s["cl"])
        self.base = CFG["flags"]
        self._ltcg = None; self._lock = threading.Lock()
        fl = {}
        for r in load_json("functions.json")["functions"]:
            fl[int(r[0], 16)] = int(r[1])
        self.lengths = fl

    def known_length(self, va):
        return self.lengths.get(va)

    def flags(self, u):
        return list(u.get("flags") or default_flags(u["file"]))

    def ltcg_env(self):
        with self._lock:
            if self._ltcg is None:
                import ltcg as G
                lp, runner, lsha = G.linker(self.s, CFG)
                crt_lib = os.path.join(self.s.get("crt_lib") or "", "libcmt.lib")
                if not os.path.exists(crt_lib):
                    die("the ltcg units need libcmt.lib (tools/setup.py --crt)")
                crt = G.crt_table(self.pe, crt_lib, os.path.join(self.out, "cache"))
                self._ltcg = dict(G=G, link=lp, runner=runner, crt=crt, iat=self.pe.iat())
            return self._ltcg

    def crt_names(self):
        """CRT symbol -> its address in the original (None without libcmt.lib); used to check unmarked CRT calls."""
        with self._lock:
            if not hasattr(self, "_crt_names"):
                crt_lib = os.path.join(self.s.get("crt_lib") or "", "libcmt.lib")
                self._crt_names = None
                if os.path.exists(crt_lib):
                    import ltcg as G
                    self._crt_names = G.crt_table(self.pe, crt_lib, os.path.join(self.out, "cache"))
            return self._crt_names

    def check_crt_targets(self, res):
        """An unmarked CRT name is allowed, but it must still be the routine the original calls there."""
        crt = self.crt_names()
        if not crt:
            return res
        for rl in res.get("relocations") or []:
            nm = rl.get("symbol")
            if rl.get("declared") is None and nm in crt and rl.get("original_target"):
                if int(rl["original_target"], 16) != crt[nm]:
                    res.setdefault("target_problems", []).append("%s: CRT %s is 0x%08X but original encodes %s"
                                                                 % (rl.get("offset"), nm, crt[nm], rl["original_target"]))
                    if res.get("status") in ("RAW_EQUAL", "RELOCATION_RESOLVED_EQUAL"):
                        res["status"] = "MASKED_EQUAL_BUT_TARGETS_DIFFER"
        return res

    def unit(self, idx, u):
        rel = u["file"]; src_path = os.path.join(ROOT, rel)
        od = os.path.join(self.out, "obj"); os.makedirs(od, exist_ok=True)
        base = re.sub(r"[^A-Za-z0-9_.-]", "_", os.path.splitext(rel)[0]); obj = os.path.join(od, base + ".obj"); rp = os.path.join(od, base + ".json")
        text = open(src_path, encoding="latin-1").read()
        key = hashlib.sha256(json.dumps([rel, sha256(src_path), gen_hash(text, rel), self.flags(u), u.get("ltcg"), u.get("link"),
                                         self.cl_sha, u["functions"]]).encode()).hexdigest()
        if os.path.exists(rp) and os.path.exists(obj):
            try:
                old = json.load(open(rp))
                if old.get("key") == key:
                    return old, True
            except ValueError:
                pass
        rec = dict(file=rel, obj="obj/" + base + ".obj", rank=u.get("rank", 0), key=key, functions=[])
        if missing_gen_includes(text):
            rec.update(status="MISSING_GEN"); json.dump(rec, open(rp, "w"), indent=1); return rec, False
        if os.path.exists(obj):
            os.remove(obj)
        t0 = time.time()
        if u.get("ltcg"):
            res = self.compile_ltcg(u, text, od, base, obj, rec)
        else:
            wd = os.path.join(od, base + ".d"); shutil.rmtree(wd, ignore_errors=True); os.makedirs(wd)
            shutil.copy(src_path, os.path.join(wd, "unit.cpp"))
            r = subprocess.run(cl_command(self.s, self.flags(u), "unit.obj", "unit.cpp"), capture_output=True, text=True, env=unit_env(self.s, self.env, rel), cwd=wd)
            if r.returncode or not os.path.exists(os.path.join(wd, "unit.obj")):
                rec.update(status="COMPILE_ERROR", output=(r.stdout + r.stderr)[-3000:])
                shutil.rmtree(wd, ignore_errors=True)
                json.dump(rec, open(rp, "w"), indent=1); return rec, False
            shutil.move(os.path.join(wd, "unit.obj"), obj); shutil.rmtree(wd, ignore_errors=True)
            exp = expand_gen_includes(text, rel); ob = open(obj, "rb").read(); res = {}
            for f in u["functions"]:
                va = int(f["va"], 16)
                res[va] = unit_twins(self.check_crt_targets(checker.compare(ob, exp, va, f["length"], self.pe.read, self.known_length)), exp)
        ok = True
        for f in u["functions"]:
            va = int(f["va"], 16); n = f["length"]; r = res.get(va) or {}
            st = r.get("status", rec.get("status", "NOT_COMPILED"))
            masked = (st in EQUAL or (r.get("compiled_length") == n and r.get("unmasked_diff_bytes") == 0)) and not r.get("target_problems")
            if u.get("rank", 0) == 0 and not masked and st in ("NO_MARKER", "NO_SYMBOL") and f.get("name") and os.path.exists(obj):
                masked = body_by_name(open(obj, "rb").read(), f["name"], va, n, self.pe.read)
            rec["functions"].append(dict(va=norm_va(f["va"]), status=st, equal=bool(masked)))
            ok = ok and masked
        rec.setdefault("status", "EQUAL" if ok else "NOT_ALL_EQUAL")
        rec["seconds"] = round(time.time() - t0, 2)
        json.dump(rec, open(rp, "w"), indent=1)
        return rec, False

    def compile_ltcg(self, u, text, od, base, obj, rec):
        g = self.ltcg_env(); G = g["G"]
        wd = os.path.join(od, base + ".ltcg"); shutil.rmtree(wd, ignore_errors=True); os.makedirs(wd)
        shutil.copy(os.path.join(ROOT, u["file"]), os.path.join(wd, "unit.cpp"))
        r = subprocess.run(cl_command(self.s, self.flags(u) + ["/GL"], "unit.gl.obj", "unit.cpp"), capture_output=True, text=True, env=unit_env(self.s, self.env, u["file"]), cwd=wd)
        if r.returncode or not os.path.exists(os.path.join(wd, "unit.gl.obj")):
            rec.update(status="COMPILE_ERROR", output=(r.stdout + r.stderr)[-3000:]); return {}
        exp = expand_gen_includes(text, u["file"])
        targets = {int(f["va"], 16): f["length"] for f in u["functions"]}
        R = G.Resolver(exp, g["iat"], g["crt"]); L = G.Linker(g["link"], g["runner"])
        lflags = list(u.get("link") or G.UNIT_LINK_FLAGS)
        try:
            out = G.run(wd, ["unit.gl.obj"], exp, R, L, lflags, targets, self.pe.read, self.known_length)
        except G.GLError as e:
            rec.update(status="LTCG_" + e.code, output=e.msg[-3000:]); return {}
        shutil.copy(out["lifted"], obj); shutil.rmtree(wd, ignore_errors=True)
        res = out["results"]
        if u.get("rank", 0) == 0:
            res = {va: unit_twins(v, exp) for va, v in res.items()}
        return res


def main():
    a = sys.argv[1:]
    if "-h" in a or "--help" in a:
        print(__doc__); return 0
    s = settings(dict(image=opt(a, "--game"), cl=opt(a, "--cl"), crt_lib=opt(a, "--crt-lib"), sdk_lib=opt(a, "--sdk-lib")))
    check_image(s["image"])
    out = os.path.abspath(os.path.expanduser(opt(a, "--out", os.path.join(ROOT, "out"))))
    jobs = int(opt(a, "-j", str(os.cpu_count() or 2)))
    if "--clean" in a and os.path.exists(out):
        shutil.rmtree(out)
    os.makedirs(out, exist_ok=True)
    import gendata, identity
    print(gendata.render_all(s["image"]))
    print(identity.ensure(s["image"]))
    units = load_json("units.json")["units"]
    only = set(x for x in (opt(a, "--files") or "").split(",") if x)
    b = Builder(s, out)
    todo = [(i, u) for i, u in enumerate(units) if not only or u["file"] in only]
    print("compiling %d units with %d jobs" % (len(todo), jobs)); sys.stdout.flush()
    t0 = time.time(); results = [None] * len(units); n = 0; cached = 0; bad = []
    with cf.ThreadPoolExecutor(jobs) as ex:
        for (i, u), (rec, hit) in zip(todo, ex.map(lambda p: b.unit(*p), todo)):
            results[i] = rec; n += 1; cached += hit
            if rec["status"] != "EQUAL":
                bad.append(rec)
                print("  %s: %s" % (rec["file"], rec["status"]))
            if n % 250 == 0:
                print("  ... %d/%d (%.0f s)" % (n, len(todo), time.time() - t0)); sys.stdout.flush()
    print("compiled %d units in %.0f s (%d cached); %d not all equal" % (n, time.time() - t0, cached, len(bad)))
    if only:
        return 0 if not bad else 1
    json.dump(dict(units=results), open(os.path.join(out, "results.json"), "w"), indent=0)
    if "--compile-only" in a:
        return 0
    if not s.get("crt_lib"):
        die("linking needs the C runtime libraries: run `python tools/setup.py --crt`")
    import link_exe
    rep = link_exe.build_image(s, out, os.path.join(out, "link"))
    if not rep:
        return 1
    gp = os.path.join(out, "link", "Game.exe")
    if rep.get("written"):
        shutil.copy(gp, os.path.join(out, "Game.exe"))
    h = rep["output_sha256"]
    want = CFG["image"]["sha256"]
    print("Game.exe sha256 %s: %s" % (h, "matches the original" if h == want else "DIFFERS from the original %s" % want))
    return 0 if h == want else 1


if __name__ == "__main__":
    sys.exit(main())
