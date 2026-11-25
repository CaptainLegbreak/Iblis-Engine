#!/usr/bin/env python3
"""Regenerate STATUS.md, docs/grid.svg and docs/shape.svg from the build data.

  python tools/status.py [--out DIR]

Reads build/functions.json, build/units.json, build/config.json, names.csv and the sources. With --out DIR (the
directory of a complete build, default out/) it also reads DIR/link/BUILD_REPORT.json for the byte tables and
DIR/obj/*.json for which functions are byte-identical without address fields; without them those parts keep the
values already in STATUS.md / grid.svg cannot tell raw from relocated and draws every verified function the same.
"""
import collections, glob, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = sys.argv[sys.argv.index('--out') + 1] if '--out' in sys.argv else os.path.join(ROOT, 'out')
rd = lambda p: open(os.path.join(ROOT, p), encoding='latin-1').read()

FUNCS = json.loads(rd('build/functions.json'))['functions']
UNITS = json.loads(rd('build/units.json'))['units']
CONFIG = json.loads(rd('build/config.json'))
DEFAULT = CONFIG['flags']
MODULE_FLAGS = CONFIG.get('module_flags', {})
NAMES = {}
for line in rd('names.csv').splitlines()[1:]:
    a, n, s = (line.split(',') + ['', '', ''])[:3]
    NAMES[int(a, 16)] = (n, s)

GAME = [f for f in FUNCS if f[2] in ('verified', 'unmatched')]
OWNER = {}
for u in sorted(UNITS, key=lambda u: u.get('rank', 0), reverse=True):
    for f in u['functions']:
        OWNER[int(f['va'], 16)] = u


# ---- per-function source and constructs ---------------------------------------------------------------------------
MARK = re.compile(r'^// (0x[0-9A-Fa-f]{8})\s*$', re.M)
BODY = {}
TEXT = {}
for u in UNITS:
    t = rd(u['file']); TEXT[u['file']] = t
    ms = list(MARK.finditer(t))
    for i, m in enumerate(ms):
        a = int(m.group(1), 16)
        if OWNER.get(a) is not u:
            continue
        seg = t[m.end(): ms[i + 1].start() if i + 1 < len(ms) else len(t)]
        end = re.search(r'^\}', seg, re.M)
        BODY[a] = seg[:end.end()] if end else seg

# A `#pragma optimize("", off)` above a function's marker covers it until the matching `on`: the pragma sits outside the
# function's body, so it is found by position, not in BODY.
PRAGMA_OFF = set()
for u in UNITS:
    t = TEXT[u['file']]
    for m in re.finditer(r'#pragma\s+optimize\s*\(\s*"[^"]*"\s*,\s*off\s*\)', t):
        e = re.compile(r'#pragma\s+optimize\s*\(\s*"[^"]*"\s*,\s*on\s*\)').search(t, m.end())
        for mk in MARK.finditer(t, m.end(), e.start() if e else len(t)):
            a = int(mk.group(1), 16)
            if OWNER.get(a) is u:
                PRAGMA_OFF.add(a)


def _block_end(t, i):
    d = 0
    for j in range(i, len(t)):
        if t[j] == '{':
            d += 1
        elif t[j] == '}':
            d -= 1
            if d == 0:
                return j + 1
    return None


def _norm(x):
    return re.sub(r'\s+', ' ', re.sub(r'//[^\n]*', '', x)).strip()


def identical_arms(b):
    """True if the body has an if/else whose two arms are the same statement or block: a construct that only shapes
    code generation (the condition decides nothing)."""
    for m in re.finditer(r'\bif\s*\(', b):
        k, dep = m.end(), 1
        while k < len(b) and dep:
            dep += {'(': 1, ')': -1}.get(b[k], 0)
            k += 1
        rest = b[k:].lstrip(); off = len(b) - len(rest)
        if rest.startswith('{'):
            e = _block_end(b, off)
            if not e:
                continue
            arm1, after = b[off + 1:e - 1], b[e:].lstrip()
            if not after.startswith('else'):
                continue
            r2 = after[4:].lstrip()
            if r2.startswith('{'):
                q = len(b) - len(r2); e2 = _block_end(b, q)
                arm2 = b[q + 1:e2 - 1] if e2 else ''
            else:
                arm2 = r2[:r2.find(';') + 1]
        else:
            sc = rest.find(';'); arm1 = rest[:sc + 1]; after = rest[sc + 1:].lstrip()
            if not after.startswith('else') or after[4:].lstrip().startswith(('if', '{')):
                continue
            r2 = after[4:].lstrip(); arm2 = r2[:r2.find(';') + 1]
        if _norm(arm1) and _norm(arm1) == _norm(arm2):
            return True
    return False


SHIMS = collections.Counter()
for t in TEXT.values():
    for m in re.finditer(r'// build: context (\w+)\s*\n// calling-convention shim', t):
        h = re.search(r'_([0-9A-F]{8})_', m.group(1) + '_') or re.search(r'sub_([0-9A-F]{8})', m.group(1))
        if h:
            SHIMS[int(h.group(1), 16)] += 1


def flag_notes(u):
    base = MODULE_FLAGS.get(u['file'].split('/')[1]) or DEFAULT
    fl = u.get('flags') or base
    notes = ['compiler option %s' % x for x in fl if x not in base and x not in ('/GS-', '/EHsc')]
    notes += ['compiler option %s, without %s' % (x.replace('-', ''), x) for x in base if x not in fl and x.endswith('-')]
    if u.get('ltcg'):
        notes.append('link-time code generation (/GL /LTCG)')
    return notes


FORCING = ('volatile read or qualifier', '#pragma optimize', '__assume', 'identical if/else arms')
# `__assume` reached through a module header's macro (Storm.h SASSERT, Fog.h DEFAULT_UNREACHABLE): the original's own
# release-build asserts and unreachable switch defaults, used only where no plain C form gives the original's code.
# Listed for completeness, like cpuid/bsr inline assembly; not a forcing construct.
ASSUME_MACROS = ('SASSERT', 'DEFAULT_UNREACHABLE')
ASSUME_RE = re.compile(r'\b(%s)\b' % '|'.join(ASSUME_MACROS))


def constructs(a):
    u = OWNER.get(a)
    if not u:
        return []
    out = []
    if SHIMS.get(a):
        out.append('calling-convention shim')
    out += flag_notes(u)
    b = BODY.get(a, '')
    if re.search(r'\bvolatile\b', b):
        out.append(FORCING[0])
    if '#pragma optimize' in b or a in PRAGMA_OFF:
        out.append(FORCING[1])
    if '__assume' in b:
        out.append(FORCING[2])
    elif ASSUME_RE.search(b):
        out.append('__assume through a header macro (original)')
    if identical_arms(b):
        out.append(FORCING[3])
    if '__asm' in b:
        out.append('inline assembly')
    return out


CONS = {f: constructs(int(f[0], 16)) for f in map(tuple, GAME)}
forced = {int(f[0], 16) for f, c in CONS.items() if any(x in FORCING for x in c)}


# ---- file shape -------------------------------------------------------------------------------------------------
STEM = re.compile(r'^(.*/)([A-Za-z0-9]+?)(_[0-9A-F]{8})?\.(cpp|CPP|c)$')
groups = collections.defaultdict(list)
for u in UNITS:
    m = STEM.match(u['file'])
    if m and not m.group(2).startswith('Unknown') and not u['file'].startswith('Source/StandIns'):
        groups[(m.group(1) + m.group(2)).lower()].append(u['file'])


def shape(a):
    u = OWNER.get(a)
    if not u:
        return 'unmatched'
    if a in forced:
        return 'forced'
    m = STEM.match(u['file'])
    if not m or m.group(2).startswith('Unknown'):
        return 'placeholder'
    return 'pieces' if len(groups[(m.group(1) + m.group(2)).lower()]) > 1 else 'whole'


src = [u['file'] for u in UNITS if not u['file'].startswith('Source/StandIns')]
n_unknown = sum(1 for f in src if '/Unknown_' in f)
split = {k: v for k, v in groups.items() if len(v) > 1}
n_pieces = sum(len(v) for v in split.values())
whole_files = sum(1 for v in groups.values() if len(v) == 1)
cpp_all = [p for p in glob.glob(os.path.join(ROOT, 'Source/**/*'), recursive=True) if re.search(r'\.(cpp|c)$', p, re.I)]
private = sum(len(re.findall(r'^(?:struct|union) \w+\s*$', open(p, encoding='latin-1').read(), re.M)) for p in cpp_all)
hdrs = glob.glob(os.path.join(ROOT, 'Source/Include/*.h'))
unk_fields = sum(len(re.findall(r'\bunk_?0x[0-9A-Fa-f]+\b', open(p, encoding='latin-1').read())) for p in hdrs)
allsrc = '\n'.join(open(p, encoding='latin-1').read() for p in cpp_all + glob.glob(os.path.join(ROOT, 'Source/**/*.h'), recursive=True))
count = lambda pat: len(re.findall(pat, allsrc))
name_src = collections.Counter(s for a, (n, s) in NAMES.items() if a in {int(f[0], 16) for f in GAME})


# ---- byte tables ------------------------------------------------------------------------------------------------
old = rd('STATUS.md') if os.path.exists(os.path.join(ROOT, 'STATUS.md')) else ''
rep_p = os.path.join(OUT, 'link', 'BUILD_REPORT.json')
rep = json.load(open(rep_p)) if os.path.exists(rep_p) else None
verified = [f for f in GAME if f[2] == 'verified']; unmatched = [f for f in GAME if f[2] == 'unmatched']
vbytes = sum(f[1] for f in verified); ubytes = sum(f[1] for f in unmatched)
L = []
L.append('# Status\n\nGenerated by `tools/status.py` from the build data. Every address below is a virtual address in the 1.14d Game.exe.\n')
L.append('| | |\n|---|---|')
L.append('| Functions | %d |' % len(GAME))
L.append('| Verified (built from source) | %d (%s bytes) |' % (len(verified), format(vbytes, ',')))
L.append('| Unmatched (taken from your Game.exe) | %d (%s bytes) |' % (len(unmatched), format(ubytes, ',')))
L.append('| Function bytes verified | %.3f %% |' % (100.0 * vbytes / (vbytes + ubytes)))
if rep:
    bc = rep['bytes_by_class']
    built = rep['built']; total = rep['bytes_total']
    L.append('| Game.exe bytes built from source (code, generated data, runtime, imports, linker output, padding) | %s of %s (%.2f %%) |' % (format(built, ','), format(total, ','), 100.0 * built / total))
    L.append('| Game.exe bytes taken from your Game.exe (unmatched code, undefined data, resources, stamps, signature) | %s |' % format(rep['borrowed'], ','))
    L.append('| Output SHA-256 equals the original | %s |' % ('yes' if rep['identical'] else 'no'))
    L.append('| Names: blizzard / library / d2moo / inferred / placeholder | %d / %d / %d / %d / %d |' % (name_src['blizzard'], name_src['library'], name_src['d2moo'], name_src['inferred'], name_src['placeholder']))
    L.append('\nBytes of the built Game.exe by origin:\n\n| Origin | Bytes |\n|---|---:|')
    lab = [('built_from_game_source', 'game code and data compiled from Source/'), ('generated_data', 'initialised data generated from your Game.exe (build/data_plan.json)'),
           ('runtime_library', 'C runtime (libcmt.lib, placed by identity)'), ('imports', 'import thunks and the import address table'),
           ('linker_output', 'headers, import and export tables, relocations, checksum'), ('padding', 'alignment padding'),
           ('borrowed_code', 'code taken from your Game.exe (unmatched functions)'), ('borrowed_data', 'data no source defines yet, taken from your Game.exe'),
           ('resource', 'resources (from your Game.exe)'), ('stamp', 'link timestamps, Rich header, debug directory'), ('signature', 'Authenticode signature')]
    for k, t in lab:
        L.append('| %s | %s |' % (t, format(bc.get(k, 0), ',')))
else:
    m = re.search(r"\| Game\.exe bytes built.*?(?=\n## )", old, re.S)
    L.append(m.group(0).rstrip() if m else '')
two = re.search(r'## Two builds.*?(?=\n## )', old, re.S)
L.append('\n' + (two.group(0).rstrip() if two else ''))

L.append('\n## Source shape\n\nHow far the sources are from reading like the original source tree. Byte matching is complete for every verified function; these count what still differs in form.\n')
L.append('| | |\n|---|---|')
L.append('| Compilation units | %d |' % len(src))
L.append('| … in a file with its original name, whole | %d |' % whole_files)
L.append('| … pieces of an original file still split (in %d files) | %d |' % (len(split), n_pieces))
L.append('| … placeholder files (`Unknown_<address>.cpp`), original file not yet known | %d |' % n_unknown)
L.append('| Record definitions private to a source file (`struct`/`union` in a .cpp) | %d |' % private)
L.append('| Unnamed fields (`unk0x..`) in the shared headers | %d |' % unk_fields)
L.append('| Functions with a construct that only forces code generation (volatile tricks, `#pragma optimize`, `__assume`, identical `if`/`else` arms) | %d |' % len(forced))
L.append('| Calling-convention shims | %d |' % count(r'calling-convention shim'))
L.append('| Context copies kept only so the compiler inlines or emits as the original did (`// build: context`) | %d |' % count(r'// build: context'))
L.append('| `__declspec(noinline)` / `__forceinline` | %d / %d |' % (count(r'__declspec\(noinline\)'), count(r'__forceinline')))
L.append('| Function names: blizzard / library / d2moo / inferred / placeholder | %d / %d / %d / %d / %d |' % (name_src['blizzard'], name_src['library'], name_src['d2moo'], name_src['inferred'], name_src['placeholder']))
L.append('\n`docs/shape.svg` draws the same per function: whole original file, file still in pieces, placeholder file, forcing construct, not reconstructed.')

um = re.search(r'## Unmatched functions.*?(?=\n## )', old, re.S)
L.append('\n' + (um.group(0).rstrip() if um else ''))

L.append('\n## Non-original constructs\n\nFunctions whose source needs something the original source very likely did not have: a per-file compiler option other than its module\'s default (`build/config.json`: `flags`, or `module_flags` for a module built with other options), link-time code generation, a calling-convention shim for a register-argument function, inline assembly, or a construct that only shapes code generation (a `volatile` read or qualifier, `#pragma optimize`, `__assume`, an `if`/`else` whose two arms are identical). Inline assembly that the original very likely had too (`cpuid`, `bsr`) and `__assume` reached through a module header macro (`SASSERT`, `DEFAULT_UNREACHABLE`: the original\'s release-build asserts and unreachable switch defaults) are listed for completeness.\n')
gs = sum(len(u['functions']) for u in UNITS if '/GS-' in (u.get('flags') or []))
eh = sum(len(u['functions']) for u in UNITS if '/EHsc' in (u.get('flags') or []))
L.append('Not listed one by one: %d functions are compiled with `/GS-` and %d with `/EHsc` (see `build/units.json`); the sources use `__declspec(noinline)` %d times and `__declspec(dllexport)` %d times to keep a body out of line or emitted.\n' % (gs, eh, count(r'__declspec\(noinline\)'), count(r'__declspec\(dllexport\)')))
L.append('| Address | Name | File | Construct |\n|---|---|---|---|')
for f in sorted(GAME, key=lambda f: int(f[0], 16)):
    c = CONS[tuple(f)]
    if c:
        a = int(f[0], 16)
        L.append('| 0x%08X | %s | `%s` | %s |' % (a, NAMES.get(a, ('sub_%08X' % a, ''))[0], OWNER[a]['file'].replace('Source/', ''), ', '.join(c)))
L.append('\n## Names\n\n`names.csv` gives the source of every function name: %d `blizzard` (Blizzard\'s own name, from exports, symbols or diagnostics), %d `library` (the name in the library the code comes from: zlib, ATL), %d `d2moo`, %d `inferred` (named here in Blizzard\'s format for its file), %d `placeholder`. Placeholder names (mostly `sub_<address>_<Verb>`) are waiting for a real name.' % (name_src['blizzard'], name_src['library'], name_src['d2moo'], name_src['inferred'], name_src['placeholder']))
open(os.path.join(ROOT, 'STATUS.md'), 'w').write('\n'.join(L).rstrip() + '\n')


# ---- grids ------------------------------------------------------------------------------------------------------
raw = set()
for p in glob.glob(os.path.join(OUT, 'obj', '*.json')):
    try:
        d = json.load(open(p))
    except Exception:
        continue
    for f in d.get('functions', []):
        if f.get('status') == 'RAW_EQUAL':
            raw.add(int(f['va'], 16))
cells = sorted((int(f[0], 16), f[2]) for f in FUNCS if f[2] in ('verified', 'unmatched', 'crt', 'pkware', 'thunk'))


def svg(path, title, sub, colour_of, legend, base):
    W, X0, Y0, P = 150, 12, 64, 6
    rows = (len(cells) + W - 1) // W
    gh = rows * P
    H = Y0 + gh + 24 + 18 * len(legend) + 8
    s = ['<svg xmlns="http://www.w3.org/2000/svg" width="923" height="%d" viewBox="0 0 923 %d" font-family="ui-monospace,SFMono-Regular,Menlo,Consolas,monospace" font-size="12">' % (H, H),
         '<defs><pattern id="g" x="%d" y="%d" width="%d" height="%d" patternUnits="userSpaceOnUse"><rect width="5" height="5" fill="%s"/></pattern></defs>' % (X0, Y0, P, P, base),
         '<rect width="100%" height="100%" rx="6" fill="#0d1117"/>',
         '<text x="12" y="24" fill="#e6edf3" font-size="14" font-weight="bold">%s</text>' % title,
         '<text x="12" y="44" fill="#8b949e">%s</text>' % sub]
    full = len(cells) // W
    s.append('<rect x="%d" y="%d" width="%d" height="%d" fill="url(#g)"/>' % (X0, Y0, W * P, full * P))
    if len(cells) % W:
        s.append('<rect x="%d" y="%d" width="%d" height="%d" fill="url(#g)"/>' % (X0, Y0 + full * P, (len(cells) % W) * P, P))
    for i, (a, k) in enumerate(cells):
        c = colour_of(a, k)
        if c != base:
            s.append('<rect x="%d" y="%d" width="5" height="5" fill="%s"/>' % (X0 + (i % W) * P, Y0 + (i // W) * P, c))
    y = Y0 + gh + 17
    for c, t in legend:
        s.append('<rect x="12" y="%d" width="10" height="10" fill="%s"/>' % (y, c))
        s.append('<text x="28" y="%d" fill="#c9d1d9">%s</text>' % (y + 9, t))
        y += 18
    open(os.path.join(ROOT, path), 'w').write('\n'.join(s) + '\n</svg>\n')


GREY, RED, PURPLE, BRIGHT, GREEN = '#6e7681', '#f85149', '#a371f7', '#39d353', '#1f8a3b'


def match_colour(a, k):
    if k in ('crt', 'pkware', 'thunk'): return GREY
    if k == 'unmatched': return RED
    if a in forced: return PURPLE
    return BRIGHT if a in raw else GREEN


cnt = collections.Counter(match_colour(a, k) for a, k in cells)
nv = len(verified)
svg('docs/grid.svg', 'Iblis Codex · Diablo II 1.14d Game.exe',
    '%s of %s game functions reconstructed (%.2f %%) · one cell per function, in address order' % (format(nv, ','), format(len(GAME), ','), 100.0 * nv / len(GAME)),
    match_colour,
    [(BRIGHT, 'byte-identical, no address fields · %s' % format(cnt[BRIGHT], ',')),
     (GREEN, 'byte-identical once linked at its original address · %s' % format(cnt[GREEN], ',')),
     (PURPLE, 'byte-identical, but only with a construct that forces code generation · %s' % format(cnt[PURPLE], ',')),
     (RED, 'not reconstructed yet (bytes taken from your Game.exe) · %s' % format(cnt[RED], ',')),
     (GREY, 'C runtime, PKWARE library or import thunk (placed by identity) · %s' % format(cnt[GREY], ','))], GREEN)

SC = {'whole': '#39d353', 'pieces': '#388bfd', 'placeholder': '#d29922', 'forced': PURPLE, 'unmatched': RED}


def shape_colour(a, k):
    if k in ('crt', 'pkware', 'thunk'): return GREY
    return SC[shape(a)]


sc = collections.Counter(shape_colour(a, k) for a, k in cells)
nw = sc[SC['whole']]
svg('docs/shape.svg', 'Iblis Codex · source shape',
    '%s of %s game functions sit in a whole file with its original name (%.1f %%) · one cell per function, in address order' % (format(nw, ','), format(len(GAME), ','), 100.0 * nw / len(GAME)),
    shape_colour,
    [(SC['whole'], 'in its original file, whole · %s' % format(sc[SC['whole']], ',')),
     (SC['pieces'], 'in its original file, but the file is still in pieces · %s' % format(sc[SC['pieces']], ',')),
     (SC['placeholder'], 'in a placeholder file (original file not yet known) · %s' % format(sc[SC['placeholder']], ',')),
     (PURPLE, 'needs a construct that forces code generation · %s' % format(sc[PURPLE], ',')),
     (RED, 'not reconstructed yet · %s' % format(sc[RED], ',')),
     (GREY, 'C runtime, PKWARE library or import thunk · %s' % format(sc[GREY], ','))], SC['whole'])

# README: the unit count in the layout table
rp = os.path.join(ROOT, 'README.md')
r = open(rp, encoding='utf-8').read()
r2 = re.sub(r'\| [\d,]+ compilation units,', '| %s compilation units,' % format(len(src), ','), r)
# ... and the function counts: verified functions the units define, and the ones not reconstructed yet
r2 = re.sub(r'defining [\d,]+ functions', 'defining %s functions' % format(len(verified), ','), r2)
r2 = re.sub(r'([Tt]he) [\d,]+(\s+)(functions\s+that\s+are\s+not\s+reconstructed\s+yet)',
            lambda m: '%s %s%s%s' % (m.group(1), format(len(unmatched), ','), m.group(2), m.group(3)), r2)
if r2 != r:
    open(rp, 'w', encoding='utf-8').write(r2)
print('STATUS.md, docs/grid.svg, docs/shape.svg written; %d units, %d whole-file functions, %d forced, %d split files' % (len(src), nw, len(forced), len(split)))
