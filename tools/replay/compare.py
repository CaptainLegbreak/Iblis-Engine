#!/usr/bin/env python3
"""Compares the output of a replay case from the oracle (stock 1.14d) and from the engine.

    python tools/replay/compare.py ORACLE.txt ENGINE.txt

Exit code 0 when identical; otherwise prints the first differences and exits with 1.
"""
import sys


def main():
    a = open(sys.argv[1], encoding="latin-1").read().splitlines()
    b = open(sys.argv[2], encoding="latin-1").read().splitlines()
    if a == b:
        print("identical: %d lines" % len(a))
        return 0
    shown = 0
    for i in range(max(len(a), len(b))):
        x = a[i] if i < len(a) else "<end>"
        y = b[i] if i < len(b) else "<end>"
        if x != y:
            print("line %d\n  1.14d:  %s\n  engine: %s" % (i + 1, x, y))
            shown += 1
            if shown == 10:
                break
    print("%d lines from 1.14d, %d from the engine" % (len(a), len(b)))
    return 1


if __name__ == "__main__":
    sys.exit(main())
