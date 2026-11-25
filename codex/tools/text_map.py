import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import records, load_json

CRT_RANGE = (0x00681A48, 0x006B00B4)
PAD = (0xCC, 0x00, 0x90)
CLASS = {"verified": b"m", "unmatched": b"p", "not_function": b"n", "crt": b"c", "pkware": b"c", "thunk": b"t"}


def text_range(pe):
    t = [s for s in pe.sections if s["name"] == ".text"][0]
    start = pe.image_base + t["va"]
    return start, start + t["rawsize"], t


def classify(orig):
    """One class letter per .text byte of the original; 'd' marks padding no record covers."""
    start, end, _ = text_range(orig)
    n = end - start
    cls = bytearray(b"o" * n)
    for va, ln, c in records():
        if start <= va < end:
            cls[va - start:min(va + ln, end) - start] = CLASS[c] * (min(va + ln, end) - va)
    for run in load_json("linker_pieces.json")["runs"]:
        a, b = int(run["start"], 16), int(run["end"], 16)
        cls[a - start:b - start] = b"t" * (b - a)
    a, b = CRT_RANGE
    for i in range(a - start, b - start):
        if cls[i] == ord("o"):
            cls[i] = ord("c")
    body = orig.read(start, n)
    for i in range(n):
        if cls[i] == ord("o") and body[i] in PAD:
            cls[i] = ord("d")
    return start, end, cls
