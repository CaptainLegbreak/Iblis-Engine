#!/usr/bin/env python3
"""Writes Source/Main/link_aliases.cpp: links each reference that names its target differently from the target's
definition to that definition, the way Iblis Codex's linker binds it by address.

    python tools/link_aliases.py BUILD_DIR LINK_LOG CODEX_DIR [--report OUT.json]

Run after a sync, on the log of a link without the aliases (an empty link_aliases.cpp). A developer tool, like
tools/codex_sync.py: the build compiles its output and never runs it.

The game source is a copy of Codex, whose files often declare a function or global another way than its definition
does (another type, an older name, a placeholder name). Codex's linker binds those references by the address their
declaration names. Codex's byte-exact build shows each call site is right for the code at that address, so binding the
reference's name to the definition at that address (/ALTERNATENAME) gives the program the original's binding.
The fix for the source, one name and one declaration, belongs in Codex; when it lands, the alias goes away on its
own at the next run.

Aliased: references sorted as type_disagreement, different_identifier or placeholder by tools/link_report.py,
whose definition one object defines externally under one symbol, and only where the reference and the definition
agree on calling convention, argument bytes and return register (tools/abi.py): for __stdcall, __fastcall and
__thiscall the bytes of arguments (and for __fastcall the order of register arguments), for __cdecl the parameter
count with each parameter the same size; a return type may differ when the definition returns in eax or the
reference ignores the value. A reference that fails that check is a real disagreement of the calling interface,
listed in --report for Codex, never aliased. Not aliased (listed in the output's comments as
counts): a reference whose name is bound to different definitions in different files, a definition several
symbols share, and every other category (interior, unsourced data, no address, static definitions, duplicates).
"""
import sys, os, json, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import link_report as LR
import abi

ENGINE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ENGINE, "Source", "Main", "link_aliases.cpp")
ALIASED = ("type_disagreement", "different_identifier", "placeholder")


def main():
    build, log, codex = sys.argv[1:4]
    report = sys.argv[sys.argv.index("--report") + 1] if "--report" in sys.argv else None
    items, defined_ids = LR.analyse(build, log, codex)
    want = collections.defaultdict(set)          # reference symbol -> definition symbols it means
    meta = {}
    units_of = collections.defaultdict(set)
    why = collections.Counter()
    for it in items:
        if it["category"] not in ALIASED:
            why[it["category"]] += 1
            continue
        d = it.get("definition") or ""
        syms = defined_ids.get(d) or defined_ids.get(LR.bare(d)) or set()
        if len(syms) != 1:
            why["definition_not_one_symbol"] += 1
            continue
        dsym = next(iter(syms))
        want[it["symbol"]].add(dsym)
        meta.setdefault(it["symbol"], it)
        units_of[it["symbol"]].add(it["unit"])
    abi.undname(sorted({s for r, ds in want.items() for s in [r] + list(ds)}))
    objects = {}                                  # source path -> its object file
    for dp, _, fs in os.walk(os.path.join(build, "CMakeFiles")):
        for f in fs:
            if f.endswith(".obj") and ".dir" + os.sep in os.path.join(dp, f):
                objects[os.path.join(dp, f).split(".dir" + os.sep, 1)[1][:-4].replace(os.sep, "/")] = os.path.join(dp, f)
    called = {}                                   # source path -> symbols its code refers to

    def from_code(sym):
        """Whether any file that asks for sym does so from code (a call, or its address taken in code)."""
        for unit in units_of[sym]:
            if unit not in called:
                called[unit] = abi.code_references(objects[unit]) if unit in objects else None
            if called[unit] is None or sym in called[unit]:
                return True
        return False
    aliases = {}; refused = []; why_address_only = [0]
    for ref, defs in sorted(want.items()):
        if len(defs) != 1:
            why["bound_differently_by_file"] += 1
            continue
        dsym = next(iter(defs))
        it = meta[ref]
        rline = LR.SOURCE.lines.get(it["unit"], {}).get(it["identifier"]) or \
            LR.SOURCE.lines.get(it["unit"], {}).get(LR.bare(it["identifier"]))
        va = int(it["address"], 16) if it.get("address") else None
        dline = LR.DEF_HEADERS.get(va)
        if not from_code(ref):
            aliases[ref] = dsym                   # address only (a table entry): the table's type makes the call
            why_address_only[0] += 1
            continue
        bad = abi.compatible(abi.sig_of(ref, rline), abi.sig_of(dsym, dline))
        if bad:
            refused.append(dict(reference=ref, definition=dsym, address=it.get("address"), unit=it["unit"],
                                reason=bad, category=it["category"]))
            why["abi: " + bad.split(" ")[0] + (" " + bad.split(" ")[1] if bad.startswith(("argument", "parameter", "calling", "return")) else "")] += 1
            continue
        aliases[ref] = dsym
    lines = ["// Generated by tools/link_aliases.py; do not edit. Engine-only.",
             "//",
             "// Binds references the game source names differently from their definitions to the definition at the",
             "// address the reference's declaration names, as Iblis Codex's linker does, where the two agree on",
             "// calling convention, argument bytes and return register (tools/abi.py). Each one is a fix that belongs",
             "// in Codex's source (one name, one declaration); it drops out of this file when that fix arrives with a",
             "// sync.",
             "//",
             "// %d aliases. Not aliased, by reason: %s" % (len(aliases), ", ".join("%s %d" % kv for kv in sorted(why.items()))),
             ""]
    for ref in sorted(aliases):
        lines.append('#pragma comment(linker, "/alternatename:%s=%s")' % (ref, aliases[ref]))
    open(OUT, "w", newline="\n").write("\n".join(lines) + "\n")
    if report:
        json.dump(dict(aliases=aliases, address_only=why_address_only[0], refused=refused, not_aliased=dict(why)),
                  open(report, "w"), indent=1)
    print("%d aliases (%d of them address-only); not aliased: %s" % (len(aliases), why_address_only[0], dict(why)))


if __name__ == "__main__":
    main()
