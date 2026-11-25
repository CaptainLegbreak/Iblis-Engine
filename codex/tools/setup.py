#!/usr/bin/env python3
"""Prepare a checkout for building.

  python tools/setup.py --game PATH/TO/Game.exe [--crt] [--cache-dir DIR]

1. checks your Game.exe (Diablo II 1.14d, SHA-256 in build/config.json);
2. fetches the MSVC 2005 SP1 compiler from the pinned public repository into toolchain/ and checks every file
   against build/toolchain.sha256;
3. with --crt, rebuilds the Visual C++ 2005 SP1 (KB971090) runtime libraries from the public Microsoft packages on
   archive.org into toolchain/lib (about 890 MB of downloads, cached; needs 7z, msiinfo and cabextract) and checks
   every file against build/crt_libs.sha256; the link step needs them;
4. renders the game's initialised data and the other build parameters from your Game.exe into gen/;
5. writes local.json with the paths.

toolchain/, gen/ and local.json are git-ignored. The toolchain is Microsoft software under Microsoft's EULA; nothing
of it, and nothing of Game.exe, is part of this repository.
"""
import os, sys, json, shutil, subprocess

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, BUILD, CFG, LOCAL, sha256, check_image, die
import fetch

TC_DIR = os.path.join(ROOT, "toolchain")


def opt(args, name, default=None):
    return args[args.index(name) + 1] if name in args else default


def verify_dir(d, sums):
    return [rel for rel, sha in sums.items() if not os.path.exists(os.path.join(d, *rel.split("/"))) or sha256(os.path.join(d, *rel.split("/"))) != sha]


def fetch_toolchain():
    sums = fetch.read_sums(os.path.join(BUILD, "toolchain.sha256"))
    if os.path.exists(os.path.join(TC_DIR, "bin", "cl.exe")) and not verify_dir(TC_DIR, sums):
        print("  toolchain/ verified")
        return os.path.join(TC_DIR, "bin", "cl.exe")
    tc = CFG["toolchain"]
    print("  cloning %s @ %s (Microsoft software under its EULA) ..." % (tc["repository"], tc["commit"][:12]))
    if os.path.exists(TC_DIR):
        shutil.rmtree(TC_DIR)
    r = subprocess.run(["git", "clone", "--quiet", "--filter=blob:none", "--no-checkout", tc["repository"], TC_DIR], capture_output=True, text=True)
    if r.returncode:
        die("clone failed:\n" + r.stderr[-800:])
    r = subprocess.run(["git", "-C", TC_DIR, "checkout", "--quiet", tc["commit"], "--", "bin", "EULA.txt"], capture_output=True, text=True)
    if r.returncode:
        r = subprocess.run(["git", "-C", TC_DIR, "checkout", "--quiet", tc["commit"], "--", "bin"], capture_output=True, text=True)
    if r.returncode:
        die("checkout of the pinned commit failed:\n" + r.stderr[-800:])
    bad = verify_dir(TC_DIR, sums)
    if bad:
        die("toolchain files do not match build/toolchain.sha256: %s" % ", ".join(bad))
    print("  %d files verified" % len(sums))
    return os.path.join(TC_DIR, "bin", "cl.exe")


def main():
    a = sys.argv[1:]
    if "-h" in a or "--help" in a:
        print(__doc__); return 0
    s = json.load(open(LOCAL)) if os.path.exists(LOCAL) else {}
    game = opt(a, "--game") or s.get("image")
    if not game or not os.path.exists(game):
        die("pass --game with the path to your Diablo II 1.14d Game.exe")
    game = os.path.abspath(os.path.expanduser(game))
    print("[1] Game.exe"); check_image(game); print("  %s: sha256 ok" % game)
    s["image"] = game
    print("[2] MSVC 2005 SP1 compiler")
    s["cl"] = fetch_toolchain()
    s["runner"] = "native" if os.name == "nt" else "wine"
    if s["runner"] == "wine" and not shutil.which("wine"):
        print("  note: wine is not installed; the build needs Wine 9 on Linux and macOS")
    if "--crt" in a:
        print("[3] C runtime libraries")
        cache = os.path.abspath(os.path.expanduser(opt(a, "--cache-dir") or fetch.default_cache_dir()))
        sums = fetch.read_sums(os.path.join(BUILD, "crt_libs.sha256"))
        try:
            root = fetch.build_crt_libs(cache, os.path.join(TC_DIR, "lib"), sums)
        except fetch.SourceError as e:
            die(str(e))
        bad = fetch.verify_tree(root, sums)
        if bad:
            die("%d library files do not match build/crt_libs.sha256: %s" % (len(bad), ", ".join(bad[:8])))
        if sha256(os.path.join(root, "lib", "libcmt.lib")) != CFG["crt"]["libcmt_sha256"]:
            die("libcmt.lib is not the %s build" % CFG["crt"]["version"])
        print("  %d files verified" % len(sums))
        s["crt_lib"] = os.path.join(root, "lib"); s["sdk_lib"] = os.path.join(root, "PlatformSDK", "Lib")
    print("[4] data from your Game.exe into gen/")
    import gendata, identity
    print("  " + gendata.render_all(game))
    print("  " + identity.ensure(game))
    json.dump(s, open(LOCAL, "w"), indent=1)
    print("[5] wrote local.json")
    if not s.get("crt_lib"):
        print("\nnext: python tools/setup.py --crt   (the link step needs the runtime libraries)")
    else:
        print("\nnext: python tools/build.py")
    return 0


if __name__ == "__main__":
    sys.exit(main())
