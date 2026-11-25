import hashlib, json, os, shutil, subprocess, sys, tempfile, time, urllib.parse, urllib.request

ARCHIVE = "https://archive.org/download/"

PACKAGES = {
    "disc1": dict(
        title="Visual Studio 2005 Professional disc 1 (RTM)",
        cache_name="vs2005_disc1.iso",
        url=ARCHIVE + "microsoft-visual-studio-2005-professional-edition-disc-1/"
        + urllib.parse.quote("Microsoft Visual Studio 2005 Professional Edition - Disc 1.iso"),
        size=627132416,
        sha256="493fa3ffc495c8911a58c161a7e38ddfede426d79a6767be895b5f08f18ca656"),
    "kb971090": dict(
        title="Visual Studio 2005 SP1 ATL security update (KB971090, 8.0.50727.4053)",
        cache_name="vs80sp1-kb971090-x86-intl_3fa2f130662a9ef7d5ecd49f8ede5217a56bb765.exe",
        url=ARCHIVE + "vs80sp1-all-langs/sp1-updates/vs80sp1-kb971090-x86-intl_3fa2f130662a9ef7d5ecd49f8ede5217a56bb765.exe",
        size=261191608,
        sha256="6a3f706391989ffd6b16e23c78bdff49bccd939e02d549d38ad1deab01763d03",
        msp="VS80sp1-KB971090-X86-INTL.msp",
        msp_sha256="64826db38c375cca7c890a72bee993e01a69072e76146b947b5993f7cf6b3d65"),
}

CRT_TOP = "kb971090-50727.4053"
CRT_DIRS = {"vc/lib": "lib", "vc/platformsdk/lib": "PlatformSDK/Lib"}
CRT_RTM = "disc1"
CRT_PATCHES = ["kb971090"]
CRT_ABSENT = {"lib/kernel32.lib", "lib/uuid.lib", "lib/opends60.lib"}


TOOLS = {
    "7z": ("p7zip-full", "p7zip"),
    "msiinfo": ("msitools", "msitools"),
    "cabextract": ("cabextract", "cabextract"),
}


class SourceError(Exception):
    pass


def default_cache_dir():
    return os.path.expanduser("~/.cache/iblis-codex")


def sha256(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def read_sums(path):
    out = {}
    with open(path) as f:
        text = f.read()
    for n, line in enumerate(text.splitlines(), 1):
        if not line.strip():
            continue
        if "  " not in line:
            raise SourceError("%s:%d: not '<sha256>  <path>'" % (path, n))
        sha, rel = line.split("  ", 1)
        if len(sha) != 64 or any(c not in "0123456789abcdef" for c in sha):
            raise SourceError("%s:%d: bad sha256" % (path, n))
        if rel.startswith("/") or "\\" in rel or ".." in rel.split("/"):
            raise SourceError("%s:%d: unsafe path %s" % (path, n, rel))
        if rel in out:
            raise SourceError("%s:%d: duplicate path %s" % (path, n, rel))
        out[rel] = sha
    return out


def verify_tree(root, sums):
    bad = []
    for rel, sha in sums.items():
        p = os.path.join(root, *rel.split("/"))
        if not os.path.isfile(p) or sha256(p) != sha:
            bad.append(rel)
    return sorted(bad)


def missing_tools(which=shutil.which):
    return [t for t in TOOLS if not which(t)]


def tools_message(missing):
    apt = " ".join(sorted(set(TOOLS[t][0] for t in missing)))
    brew = " ".join(sorted(set(TOOLS[t][1] for t in missing)))
    return ("missing tools: %s\n     Debian/Ubuntu: sudo apt install %s\n     macOS (Homebrew): brew install %s\n"
            "     (on Windows, run this step under WSL; msitools has no native Windows build)" % (", ".join(missing), apt, brew))


def run(cmd, out=None):
    r = subprocess.run(cmd, stdout=out if out is not None else subprocess.PIPE, stderr=subprocess.PIPE)
    if r.returncode:
        raise SourceError("%s failed (%d): %s" % (cmd[0], r.returncode, r.stderr.decode("latin1")[-600:]))
    return r.stdout.decode("latin1") if out is None else ""


def _human(n):
    return "%.0f MB" % (n / 1e6)


def fetch(pkg, cache_dir, opener=None, log=print, retries=8):
    os.makedirs(cache_dir, exist_ok=True)
    dst = os.path.join(cache_dir, pkg["cache_name"])
    part = dst + ".part"
    if os.path.exists(dst):
        log("  %s: cached, checking sha256 ..." % pkg["cache_name"])
        _check(dst, pkg)
        return dst
    opener = opener or urllib.request.build_opener()
    tries = 0
    while True:
        have = os.path.getsize(part) if os.path.exists(part) else 0
        if have > pkg["size"]:
            os.replace(part, dst + ".bad")
            raise SourceError("%s: partial download is larger than the package (%d > %d); moved aside as %s.bad"
                              % (pkg["cache_name"], have, pkg["size"], pkg["cache_name"]))
        if have == pkg["size"]:
            break
        req = urllib.request.Request(pkg["url"], headers={"User-Agent": "iblis-codex-setup/1"})
        if have:
            req.add_header("Range", "bytes=%d-" % have)
        log("  %s: %s %s from %s" % (pkg["cache_name"], "resuming at %s of" % _human(have) if have else "downloading",
                                       _human(pkg["size"]), pkg["url"]))
        try:
            with opener.open(req, timeout=120) as r:
                status = getattr(r, "status", None) or r.getcode()
                if have and status != 206:
                    log("  server ignored the range request; starting over")
                    have = 0
                mode = "ab" if have else "wb"
                t0, last, got = time.time(), 0.0, have
                with open(part, mode) as f:
                    for b in iter(lambda: r.read(1 << 20), b""):
                        f.write(b)
                        got += len(b)
                        if got > pkg["size"]:
                            break
                        now = time.time()
                        if now - last > 30:
                            rate = (got - have) / max(now - t0, 1e-6)
                            log("    %s / %s (%.1f MB/s)" % (_human(got), _human(pkg["size"]), rate / 1e6))
                            last = now
            if got == have:
                tries += 1
                if tries > retries:
                    raise SourceError("%s: the server keeps sending no data" % pkg["cache_name"])
                log("  no data received; retrying (%d/%d)" % (tries, retries)); time.sleep(min(60, 5 * tries))
        except urllib.error.HTTPError as e:
            if e.code in (401, 403, 405, 407, 451):
                raise SourceError("%s: the download was refused (HTTP %d %s) for %s" % (pkg["cache_name"], e.code, e.reason, pkg["url"]))
            if e.code == 416 and have:
                os.replace(part, dst + ".bad")
                raise SourceError("%s: the server rejected resuming at %d bytes; moved aside as %s.bad" % (pkg["cache_name"], have, pkg["cache_name"]))
            tries += 1
            if tries > retries:
                raise SourceError("%s: download failed: HTTP %d %s" % (pkg["cache_name"], e.code, e.reason))
            log("  HTTP %d; retrying (%d/%d)" % (e.code, tries, retries)); time.sleep(min(60, 5 * tries))
        except (OSError, urllib.error.URLError) as e:
            tries += 1
            if tries > retries:
                raise SourceError("%s: download failed after %d retries: %s" % (pkg["cache_name"], retries, e))
            log("  transfer interrupted (%s); resuming (%d/%d)" % (e, tries, retries)); time.sleep(min(60, 5 * tries))
    _check(part, pkg)
    os.replace(part, dst)
    return dst


def _check(path, pkg):
    size = os.path.getsize(path)
    h = sha256(path) if size == pkg["size"] else None
    if h != pkg["sha256"]:
        bad = os.path.join(os.path.dirname(path), pkg["cache_name"] + ".bad")
        os.replace(path, bad)
        raise SourceError("%s does not match its pin (size %d, expected %d; sha256 %s, expected %s...). It is not the "
                          "package named in tools/fetch.py; moved aside as %s. Do not use it."
                          % (pkg["cache_name"], size, pkg["size"], (h or "not computed")[:16], pkg["sha256"][:16], bad))
    print("  %s sha256 ok (%s)" % (pkg["cache_name"], pkg["title"]))


def parse_idt(text):
    lines = text.replace("\r\n", "\n").split("\n")
    return [l.split("\t") for l in lines[3:] if l]


def msi_layout(tables):
    dirs = {}
    for r in parse_idt(tables["Directory"]):
        dirs[r[0]] = (r[1], r[2].split(":")[0].split("|")[-1])

    def dpath(d, depth=0):
        if d not in dirs or depth > 64:
            return d
        parent, name = dirs[d]
        if not parent or parent == d:
            return name
        p = dpath(parent, depth + 1)
        return p if name == "." else p + "/" + name

    comps = {r[0]: r[2] for r in parse_idt(tables["Component"])}
    media = sorted((int(r[1]), r[3]) for r in parse_idt(tables["Media"]))
    out = {}
    for r in parse_idt(tables["File"]):
        seq = int(r[7])
        cab = next((c for last, c in media if last >= seq), None)
        out[r[0]] = (dpath(comps.get(r[1], "?")).lower(), r[2].split("|")[-1], cab, r[4] if len(r) > 4 else "")
    return out


def crt_wanted(layout):
    want = {}
    for key, (d, name, cab, ver) in layout.items():
        for suffix, sub in CRT_DIRS.items():
            if d.endswith("/" + suffix):
                rel = sub + "/" + name
                if rel in want:
                    raise SourceError("two MSI files map to %s" % rel)
                want[rel] = (key, cab, ver)
    return want


class Work:

    def __init__(self, cache_dir):
        os.makedirs(cache_dir, exist_ok=True)
        self.dir = tempfile.mkdtemp(prefix="work-", dir=cache_dir)

    def path(self, *p):
        return os.path.join(self.dir, *p)

    def close(self):
        shutil.rmtree(self.dir, ignore_errors=True)


def iso_listing(iso):
    names = set()
    for line in run(["7z", "l", "-slt", iso]).splitlines():
        if line.startswith("Path = ") and line[7:] != iso:
            names.add(line[7:])
    return names


def seven_extract(archive, member, outdir):
    os.makedirs(outdir, exist_ok=True)
    run(["7z", "e", "-y", "-bd", "-o" + outdir, archive, member])
    p = os.path.join(outdir, os.path.basename(member))
    if not os.path.isfile(p):
        raise SourceError("%s has no %s" % (os.path.basename(archive), member))
    return p


def cab_extract(cab, keys, outdir):
    os.makedirs(outdir, exist_ok=True)
    keys = sorted(keys)
    for i in range(0, len(keys), 64):
        cmd = ["cabextract", "-q", "-d", outdir]
        for k in keys[i:i + 64]:
            cmd += ["-F", k]
        run(cmd + [cab])
    got = {k: os.path.join(outdir, k) for k in keys if os.path.isfile(os.path.join(outdir, k))}
    return got


def cab_names(cab):
    names = set()
    for line in run(["cabextract", "-l", cab]).splitlines():
        if "|" in line and line.count("|") >= 2:
            n = line.split("|", 2)[2].strip()
            if n and n != "Name":
                names.add(n)
    return names


def read_msi(iso, work):
    msi = seven_extract(iso, "vs_setup.msi", work.path("msi"))
    tables = {t: run(["msiinfo", "export", msi, t]) for t in ("File", "Component", "Directory", "Media")}
    return msi, msi_layout(tables)


def patch_files(exe, pkg, keys, work, log=print):
    d = work.path(pkg["cache_name"] + ".x")
    msp = seven_extract(exe, pkg["msp"], d)
    if sha256(msp) != pkg["msp_sha256"]:
        raise SourceError("%s inside %s does not hash to its pin" % (pkg["msp"], pkg["cache_name"]))
    log("  %s sha256 ok" % pkg["msp"])
    run(["7z", "e", "-y", "-bd", "-o" + d, msp, "PCW_CAB_VS_*"])
    os.unlink(msp)
    cabs = [os.path.join(d, n) for n in sorted(os.listdir(d)) if n.startswith("PCW_CAB_VS_")]
    if len(cabs) != 1:
        raise SourceError("%s: expected one PCW_CAB_VS_* stream, found %d" % (pkg["msp"], len(cabs)))
    present = cab_names(cabs[0]) & set(keys)
    got = cab_extract(cabs[0], present, os.path.join(d, "files"))
    os.unlink(cabs[0])
    return got


def rtm_files(isos, msi, layout, keys, work):
    by_cab = {}
    for k in keys:
        cab = layout[k][2]
        if not cab:
            raise SourceError("no Media row for %s" % k)
        by_cab.setdefault(cab, []).append(k)
    listings = {}
    got = {}
    for cab, ks in sorted(by_cab.items()):
        cdir = work.path("cab")
        os.makedirs(cdir, exist_ok=True)
        if cab.startswith("#"):
            p = os.path.join(cdir, "stream.cab")
            with open(p, "wb") as f:
                run(["msiinfo", "extract", msi, cab[1:]], out=f)
        else:
            iso = None
            for name, path in isos:
                if name not in listings:
                    listings[name] = iso_listing(path)
                if cab in listings[name]:
                    iso = path
                    break
            if iso is None:
                raise SourceError("cabinet %s is on none of: %s" % (cab, ", ".join(n for n, _ in isos)))
            p = seven_extract(iso, cab, cdir)
        got.update(cab_extract(p, ks, work.path("rtmfiles")))
        os.unlink(p)
    return got


def place(files, plan, root):
    for rel, key in sorted(plan.items()):
        dst = os.path.join(root, *rel.split("/"))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copyfile(files[key], dst)


def _start(cache_dir, names, log):
    miss = missing_tools()
    if miss:
        raise SourceError(tools_message(miss))
    log("  cache: %s" % cache_dir)
    log("  (Microsoft Visual Studio 2005 software; by downloading and installing it you accept Microsoft's EULA)")
    return {n: fetch(PACKAGES[n], cache_dir, log=log) for n in names}


def build_crt_libs(cache_dir, dest_parent, sums, log=print):
    paths = _start(cache_dir, [CRT_RTM] + CRT_PATCHES, log)
    work = Work(cache_dir)
    try:
        log("  reading vs_setup.msi from disc 1 ...")
        msi, layout = read_msi(paths[CRT_RTM], work)
        want = crt_wanted(layout)
        log("  %d files under VC\\lib and VC\\PlatformSDK\\Lib in the RTM MSI" % len(want))
        source = {}
        files = {}
        keys = {k for k, _, _ in want.values()}
        for name in CRT_PATCHES:
            log("  extracting from %s ..." % PACKAGES[name]["cache_name"])
            got = patch_files(paths[name], PACKAGES[name], keys, work, log)
            for k, p in got.items():
                files[k] = p; source[k] = name
            log("    %d files" % len(got))
        rest = [want[rel][0] for rel in want if want[rel][0] not in files and rel not in CRT_ABSENT]
        log("  extracting %d files from disc 1 ..." % len(rest))
        for k, p in rtm_files([(CRT_RTM, paths[CRT_RTM])], msi, layout, rest, work).items():
            files[k] = p; source[k] = "rtm"
        plan = {rel: v[0] for rel, v in want.items() if v[0] in files}
        absent = sorted(rel for rel in want if want[rel][0] not in files)
        if set(absent) != CRT_ABSENT:
            raise SourceError("files without a source: %s (expected exactly %s)" % (", ".join(absent) or "none", ", ".join(sorted(CRT_ABSENT))))
        unknown = sorted(set(plan) - set(sums))
        if unknown:
            raise SourceError("the packages yield files build/crt_libs.sha256 does not list: %s" % ", ".join(unknown[:8]))
        root = os.path.join(dest_parent, CRT_TOP)
        stage = root + ".building"
        shutil.rmtree(stage, ignore_errors=True)
        place(files, plan, stage)
        manifest = []
        for rel in sorted(want, key=lambda r: (r.rsplit("/", 1)[0], r.rsplit("/", 1)[1].lower())):
            key, _, ver = want[rel]
            if rel in plan:
                p = os.path.join(stage, *rel.split("/"))
                manifest.append(dict(path=rel, key=key, origin=source[key], size=os.path.getsize(p), sha256=sha256(p), msi_version=ver))
            else:
                manifest.append(dict(path=rel, key=key, origin="MISSING"))
        with open(os.path.join(stage, "MANIFEST.json"), "w") as f:
            json.dump(manifest, f, indent=1)
        shutil.rmtree(root, ignore_errors=True)
        os.replace(stage, root)
        return root
    finally:
        work.close()


