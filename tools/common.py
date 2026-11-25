import os, sys, json, hashlib, struct, time, re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BUILD = os.path.join(ROOT, "build")
CFG = json.load(open(os.path.join(BUILD, "config.json")))
LOCAL = os.path.join(ROOT, "local.json")
GEN = os.path.join(ROOT, "gen")
GEN_INCLUDE = re.compile(r'^[ \t]*#[ \t]*include[ \t]+"(gen/data/[^"\n]+\.inc)"[ \t]*$', re.M)


def die(msg, code=2):
    print("error: " + msg, file=sys.stderr)
    sys.exit(code)


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def load_json(name):
    return json.load(open(os.path.join(BUILD, name)))


def settings(overrides=None, need=("image", "cl")):
    s = json.load(open(LOCAL)) if os.path.exists(LOCAL) else {}
    for k, v in (overrides or {}).items():
        if v:
            s[k] = v
    for k in ("image", "cl"):
        if k not in need and not s.get(k):
            continue
        if not s.get(k):
            die("no %s: run `python tools/setup.py` or pass it on the command line" % ("Game.exe" if k == "image" else "cl.exe"))
        s[k] = os.path.abspath(os.path.expanduser(s[k]))
    for k in ("crt_lib", "sdk_lib", "link"):
        if s.get(k):
            s[k] = os.path.abspath(os.path.expanduser(s[k]))
    s.setdefault("runner", "native" if os.name == "nt" else "wine")
    return s


def check_image(path):
    h = sha256(path)
    if h != CFG["image"]["sha256"]:
        die("%s hashes to %s, expected %s: not the Diablo II 1.14d Game.exe" % (path, h[:16], CFG["image"]["sha256"][:16]))
    return h


def check_toolchain(cl):
    h = sha256(cl)
    if h != CFG["toolchain"]["cl_sha256"]:
        die("cl.exe hashes to %s, expected %s: install the MSVC 2005 SP1 compiler with tools/setup.py" % (h[:16], CFG["toolchain"]["cl_sha256"][:16]))
    return h


def norm_va(v):
    v = str(v).strip().lower().replace("0x", "")
    return "0x%08X" % int(v, 16)


def utc():
    return time.strftime("%Y%m%dT%H%M%SZ", time.gmtime())


ORDER = ("not_function", "crt", "pkware", "thunk", "unmatched", "verified")


def records(kinds=None):
    """[(va, length, kind)] of every address record in build/functions.json, in painting order."""
    rows = load_json("functions.json")["functions"]
    out = []
    for k in ORDER:
        if kinds and k not in kinds:
            continue
        out.extend((int(r[0], 16), int(r[1]), r[2]) for r in rows if r[2] == k)
    return out


class PE:
    def __init__(self, path):
        self.data = open(path, "rb").read()
        d = self.data
        pe = struct.unpack_from("<I", d, 0x3C)[0]
        assert d[pe:pe + 4] == b"PE\0\0"
        nsec = struct.unpack_from("<H", d, pe + 6)[0]
        opt = pe + 24
        self.image_base = struct.unpack_from("<I", d, opt + 28)[0]
        optsz = struct.unpack_from("<H", d, pe + 20)[0]
        self.sections = []
        for i in range(nsec):
            o = opt + optsz + 40 * i
            name = d[o:o + 8].rstrip(b"\0").decode("latin-1")
            vsize, va, rawsize, rawptr = struct.unpack_from("<IIII", d, o + 8)
            self.sections.append(dict(name=name, vsize=vsize, va=va, rawsize=rawsize, rawptr=rawptr))

    def sec(self, va):
        rva = va - self.image_base
        for s in self.sections:
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["rawsize"]):
                return s
        return None

    def va_to_off(self, va):
        s = self.sec(va)
        if not s:
            return None
        return s["rawptr"] + (va - self.image_base - s["va"])

    def read(self, va, n):
        o = self.va_to_off(va)
        if o is None:
            return None
        return self.data[o:o + n]

    def iat(self):
        d = self.data; pe = struct.unpack_from("<I", d, 0x3C)[0]; opt = pe + 24
        rva, size = struct.unpack_from("<II", d, opt + 96 + 8)
        out = {}
        if not rva:
            return out
        off = self.va_to_off(self.image_base + rva)
        while True:
            oft, _, _, name_rva, ft = struct.unpack_from("<IIIII", d, off)
            if not ft:
                break
            no = self.va_to_off(self.image_base + name_rva); dll = d[no:d.index(b"\0", no)].decode("latin-1")
            thunk = self.va_to_off(self.image_base + (oft or ft)); k = 0
            while True:
                e = struct.unpack_from("<I", d, thunk + 4 * k)[0]
                if not e:
                    break
                if e & 0x80000000:
                    nm = "#%d" % (e & 0xFFFF)
                else:
                    ho = self.va_to_off(self.image_base + e) + 2; nm = d[ho:d.index(b"\0", ho)].decode("latin-1")
                out[self.image_base + ft + 4 * k] = "%s!%s" % (dll, nm); k += 1
            off += 20
        return out

    def in_text(self, va):
        s = self.sec(va)
        return bool(s and s["name"] == ".text")


def _win_path(p, s):
    return "Z:" + p.replace("/", "\\") if s.get("runner", "native") != "native" and p.startswith("/") else p


def compile_env(s):
    """INCLUDE carries the repository root, so `#include "gen/data/..."` finds the generated data."""
    env = dict(os.environ)
    parts = []
    if env.get("INCLUDE"):
        parts.append(env["INCLUDE"])
    parts.append(_win_path(ROOT, s))
    env["INCLUDE"] = ";".join(parts)
    env.setdefault("WINEDEBUG", "-all")
    return env


def unit_env(s, env, rel):
    """compile_env plus the unit's module folder, where its module header lives."""
    d = module_dir(rel)
    if not d:
        return env
    env = dict(env)
    env["INCLUDE"] = env["INCLUDE"] + ";" + _win_path(d, s) + ";" + _win_path(SHARED, s)
    return env


def gen_includes(text):
    return GEN_INCLUDE.findall(text)


def missing_gen_includes(text):
    return [p for p in gen_includes(text) if not os.path.exists(os.path.join(ROOT, p))]


HEADER_INCLUDE = re.compile(r'^[ \t]*#[ \t]*include[ \t]+"([^"\n/]+\.h)"[ \t]*$', re.M)


def default_flags(rel):
    """The compiler options of a unit that records none: its module's (config.json module_flags) or the base set."""
    parts = rel.replace("\\", "/").split("/")
    mod = parts[1] if len(parts) > 2 and parts[0] == "Source" else None
    return list(CFG.get("module_flags", {}).get(mod) or CFG["flags"])


def module_dir(rel):
    """Source/<Module>: the folder whose headers a unit includes by bare name."""
    parts = rel.replace("\\", "/").split("/")
    return os.path.join(ROOT, parts[0], parts[1]) if len(parts) > 2 and parts[0] == "Source" else None


SHARED = os.path.join(ROOT, "Source", "Include")


def find_header(name, rel):
    """A bare-name header: the unit's module folder first, then the shared Source/Include folder."""
    for d in (module_dir(rel) if rel else None, SHARED):
        if d and os.path.exists(os.path.join(d, name)):
            return os.path.join(d, name)
    return None


def unit_headers(text, rel):
    """Paths of the headers a unit includes, directly or through other headers (module and shared)."""
    out = []

    def walk(t):
        for h in HEADER_INCLUDE.findall(t):
            p = find_header(h, rel)
            if p and p not in out:
                out.append(p)
                walk(open(p, encoding="latin-1").read())
    walk(text)
    return out


def expand_gen_includes(text, rel=None):
    """The unit's text with its generated data and its headers written in place, each header once (what the checker
    reads)."""
    seen = set()

    def hdr(m):
        p = find_header(m.group(1), rel)
        if not p:
            return m.group(0)
        if p in seen:
            return ""
        seen.add(p)
        return HEADER_INCLUDE.sub(hdr, open(p, encoding="latin-1", newline="").read().rstrip("\n"))
    text = HEADER_INCLUDE.sub(hdr, text)

    def one(m):
        p = os.path.join(ROOT, m.group(1))
        if not os.path.exists(p):
            return m.group(0)
        return open(p, encoding="latin-1", newline="").read().rstrip("\n")
    return GEN_INCLUDE.sub(one, text)


def cl_command(s, flags, out, src):
    return ([s["cl"]] if s.get("runner", "native") == "native" else ["wine", s["cl"]]) + list(flags) + ["/Fo" + out, src]
