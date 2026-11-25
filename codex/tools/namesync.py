#!/usr/bin/env python3
"""Bring a branch's function and global names up to date with names.csv.

names.csv lists the current name of every function by address. A branch made before a rename still uses the
old placeholder name (`sub_<address>...`, or a name ending in `_<address>`) at that address. This tool finds,
for each `// 0xADDR` marker or declaration comment in Source/, the name used there; where that name is a
placeholder spelling that differs from the name names.csv gives the address, it renames the old spelling to the
new one everywhere: in Source/, build/units.json, build/functions.json and build/data_plan.json.

Only names that no longer occur on origin/main (set NAMESYNC_BASE to use another ref) are renamed: those are
exactly the ones a rename on main replaced. Names main itself still uses are left alone.

Usage: python3 tools/namesync.py [--dry-run]     (after rebasing onto main)
"""
import csv, glob, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DRY = '--dry-run' in sys.argv
PLACEHOLDER = re.compile(r'^(sub_[0-9A-F]{8}\w*|\w+_[0-9A-F]{8})$')

names = {}
with open(os.path.join(ROOT, 'names.csv'), newline='') as f:
    for row in csv.reader(f):
        if row and row[0].startswith('0x'):
            names[int(row[0], 16)] = row[1]

files = [p for p in glob.glob(os.path.join(ROOT, 'Source', '**', '*'), recursive=True)
         if os.path.isfile(p) and p.lower().endswith(('.cpp', '.c', '.h', '.inl'))]
text = {p: open(p, encoding='latin-1').read() for p in files}

decl = re.compile(r'([A-Za-z_]\w*)\s*\([^;{}]*\)\s*(?:const\s*)?;\s*//\s*(0x[0-9A-Fa-f]{8})\b')
defn = re.compile(r'^//\s*(0x[0-9A-Fa-f]{8})\s*\n[^\n(]*?\b([A-Za-z_]\w*)\s*\(', re.M)
ren = {}
for t in text.values():
    u = re.sub(r'__declspec\s*\([^()]*(?:\([^()]*\)[^()]*)*\)', '', t)
    pairs = [(m.group(1), m.group(2)) for m in decl.finditer(u)] + [(m.group(2), m.group(1)) for m in defn.finditer(u)]
    for name, addr in pairs:
        new = names.get(int(addr, 16))
        if new and new != name and PLACEHOLDER.match(name) and not PLACEHOLDER.match(new) and '::' not in new:
            ren.setdefault(name, new)

# only names that main itself no longer uses: those are the ones a rename on main replaced
import subprocess
if ren:
    base = os.environ.get('NAMESYNC_BASE', 'origin/main')
    out = subprocess.run(['git', '-C', ROOT, 'grep', '-ohwF'] + sum((['-e', o] for o in ren), []) + [base, '--', 'Source'],
                         capture_output=True, text=True).stdout
    still = set(l.split(':', 1)[-1] for l in out.split())
    ren = {o: n for o, n in ren.items() if o not in still}
if not ren:
    print('namesync: nothing to rename'); sys.exit(0)
word = re.compile(r'\b(' + '|'.join(map(re.escape, ren)) + r')\b')
sym = re.compile(r'(?<![A-Za-z0-9])(' + '|'.join(map(re.escape, ren)) + r')(?![A-Za-z0-9_])')
changed = []
for p, t in text.items():
    u = word.sub(lambda m: ren[m.group(1)], t)
    if u != t:
        changed.append(p)
        if not DRY: open(p, 'w', encoding='latin-1', newline='').write(u)
for j in ('build/units.json', 'build/functions.json', 'build/data_plan.json'):
    p = os.path.join(ROOT, j)
    if not os.path.exists(p): continue
    t = open(p).read(); u = sym.sub(lambda m: ren[m.group(1)], t)
    if u != t:
        changed.append(p)
        if not DRY: open(p, 'w').write(u)
for o, n in sorted(ren.items()): print('  %s -> %s' % (o, n))
print('namesync: %d names, %d files%s' % (len(ren), len(changed), ' (dry run)' if DRY else ''))
