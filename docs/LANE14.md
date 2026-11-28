# Lane 14: the port to a modern compiler

Board for the Fable chat (lane 14). Lane 14 writes this file on the `board` branch; the coordinator (lane 10 of
Iblis Codex) answers here and keeps the queue stocked. Newest entries at the top of each section.

Goal: roadmap M0 and M1 with a current compiler. The engine's source builds with CMake and a current 32-bit MSVC,
links as an ordinary Windows program with nothing read from Game.exe, and passes M1's check on the user's PC.

## Queue (coordinator-kept, top down)

0. **Bring Source/ up to Iblis Codex main.** The engine was taken from Codex f835c02 (2026-11-25). Codex now has
   every function reconstructed (no borrowed code), so the 8 files in Source/StandIns/ are replaced by the real
   functions, and the cleanups since (names, struct fields, declarations, data layout) come over too. Keep what the
   engine changed (the data tables written into source, the standalone layout); list anything that conflicts.
1. **M0, the rest.** An open implementation of the PKWARE DCL routines Storm calls (implode/explode; zlib's
   blast.c covers explode, NOTICE-ZLIB.txt is already here); the program's own resources (icon, version info,
   dialogs, written from scratch, not copied from Game.exe); the Codex build markers (`// build:`, about 360 files)
   removed. Exit check: a fresh clone holds every line of code and data the program needs.
2. **CMake and a current compiler.** A CMakeLists.txt that builds the program with VS 2022 (v143), x86, `/arch:IA32`
   first. In the sandbox use mstorsjo/msvc-wine (Microsoft's download servers are reachable). Write
   `docs/PORT_COMPILE.md`: every file that fails, its first error, grouped by cause. Fix the causes in the source.
3. **Link by name.** The Codex links its objects with a tool that binds about 21,800 references by address because
   the names don't agree from file to file; the engine can't use that tool. Run Codex's `tools/linkdebt.py` once on
   Codex main for the map (LINK_DEBT.json), then fix the engine's source so every reference uses its definition's
   name and one declaration: type disagreements, other spellings, placeholder names, private copies. Write it as a
   script you run once, and keep the script out of the build.
4. **Data that only works at its original address** (M1's "globals the code reaches across"): the D2DataTablesStrc
   run at 0x0096BC30 (one struct), pointers into the middle of objects, globals declared shorter than the room the
   original gives them (Codex `tools/shortdata.py`, 363 candidates). Each becomes a declaration that is right on its
   own.
5. **M1.** Hand the user the exe to test on a clean 1.14d install, named Game.exe: menus, a new character of each
   class, Act 1, save and reload, a TCP/IP game against stock 1.14d. Log each result and each crash in
   `docs/PORT_RUN.md`, then fix and repeat. Old-compiler behaviour (uninitialised reads, float precision, evaluation
   order, packing) shows up here.

## Ready

## Claimed

- 2: CMake and VS 2022 x86 (lane14/cmake), started 2026-11-27.

## Findings

- 2026-11-27, question for the user (item 0, parked, not blocking): I need the user's 1.14d Game.exe in the
  sandbox for Codex's tools (linkdebt.py for item 3, shortdata.py for item 4) and to check 16 data bytes.
  My request for access to ~/Iblis-Codex and ~/Desktop/Diablo 2 archives on the PC was declined by the
  app's approval check, not by the user. Could the user attach Game.exe to the chat, or approve folder
  access to the folder that holds it? Nothing from it goes into the repo.
- 2026-11-27, item 0: 16 bytes of Codex main's data plan were in no record of the f835c02 plan, so the
  engine's data didn't have them; written as 0 in PR #1, to check against Game.exe:
  gaQuestTable[0] bytes 0-7 (0x00723F30) and gatControlTemplates[282], [284] .nFlags (0x0070C204,
  0x0070C264). In Codex main's plan, 35 files list an `include` that isn't the file's own
  (e.g. BnDownload.cpp lists BnDownload_00520B30.inc but includes BnDownload.inc) - stale plan
  entries after the file merges, worth a fix in Codex.

## Status

- 2026-11-27 17:40 PT: item 0 done, PR #1 (Source/ = Codex main 09eccff; data carried over exactly without
  Game.exe, by inverting gendata's rendering, checked by re-rendering all 2,481 old records). Toolchain in the
  sandbox: msvc-wine, MSVC 14.44.35207, cl 19.44.35230 for x86, link 14.44.35230.0, SDK 10.0.26100.0, under
  wine 11.0 (Ubuntu's wine 9.0 crashes on this kernel). Starting item 2.
