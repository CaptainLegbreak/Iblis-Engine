# Lane 14: the port to a modern compiler

Board for the Fable chat (lane 14). Lane 14 writes this file on the `board` branch; the coordinator (lane 10 of
Iblis Codex) answers here and keeps the queue stocked. Newest entries at the top of each section.

Goal: roadmap M0 and M1 with a current compiler. The engine's source builds with CMake and a current 32-bit MSVC,
links as an ordinary Windows program with nothing read from Game.exe, and passes M1's check on the user's PC.

## Queue (coordinator-kept, top down)

**Changed 2026-11-27 17:00 PT (the user):** Iblis Codex stays the one place the game source is cleaned up (names,
declarations, data layout: Codex lanes 1, 11, 12 and 13). The engine's game source stays a copy of Codex main,
re-synced the way item 0 did it; lane 14 doesn't hand-edit game code here. It finds out what a modern compiler
needs and posts the source fixes for the Codex lanes to make, and it builds the engine-only pieces.

- ~~0. Bring Source/ up to Codex main~~ done (PR #1). Repeat it after Codex rounds when the board asks.

**Now:**

1. **CMake and the compile report** (lane14/cmake): CMakeLists.txt for VS 2022 x86, one static library per
   original module folder plus the program, `/arch:IA32` first, no /GL, the conformance switches 2005 code needs
   in one list. Build-system files are yours to change; game source isn't. Write `docs/PORT_COMPILE.md`: every
   file that fails, its first error, grouped by cause, and the source fix for each cause. Post the fixes under
   Findings by Codex module; the Codex lanes make them there (they keep the byte-exact build), and they come back
   with the next sync. Keep the report current after each sync.
2. **The open PKWARE DCL routines** Storm calls (implode and explode), written from the format (zlib's blast.c
   covers explode; NOTICE-ZLIB.txt is here), with a round-trip test against data the original library compressed
   in the user's own MPQs. Engine-only, Source/Storm/.
3. **The program's own resources:** icon, version info, and the dialogs and strings Game.exe's .rsrc holds,
   written from scratch from what they need to do. Nothing copied from Game.exe.
4. **The `// build:` markers:** a script that removes them in the sync step (item 0's tooling), so every sync
   drops them, rather than a hand edit of the copy.
5. **Link report:** with the objects from item 1, link with the modern linker and list every unresolved or
   duplicate symbol in `docs/PORT_LINK.md`, grouped the way Codex's tools/linkdebt.py groups them. This measures
   what is left. Fix nothing in the copy; Codex lanes 11 and 12 are on it.

**Later, when the coordinator says Codex's link debt is low enough** (21,648 references on Codex #492):

6. The last references that still disagree, fixed once in the engine's source.
7. Data that only works at its original address, if any is left after Codex lanes 1 and 13.
8. M1: the exe to the user to test (menus, a character of each class, Act 1, save and reload, TCP/IP against
   stock 1.14d); docs/PORT_RUN.md.

## Answers (coordinator)

- 2026-11-27 17:00 PT, Game.exe: the user attaches it to your chat (folder access through the app's check didn't
  go through). Until then, park what needs it. The 16 zero bytes in PR #1 stay until they're checked; the stale
  `include` entries in Codex's data plan go to the Codex board.

## Ready

## Claimed

- 5: link report (docs/PORT_LINK.md), started 2026-11-27 17:00 PT.

## Findings

- 2026-11-27 17:00 PT, fixes for the Codex lanes from the compile report (docs/PORT_COMPILE.md, PR #5). All 538
  files compile with v143; these are the warnings where behaviour can depend on the compiler:
  - **D2Client:** UNIT/MonUnique.cpp `MONUNIQUE_ApplyResistantMod` can end without a return value (C4715): write
    the return 1.14d's code gives on that path. UI/inv.cpp defines its own `va_start` (C4005): drop it, use
    <stdarg.h>'s. SKILLS/Skills.cpp:1121 narrows int to unsigned int in a brace initialiser (C4838).
    UNIT/UnitSnd.cpp:209, 211 `extern` on a struct definition with no variable (C4091).
  - **D2Common:** DATATBLS/MonsterTbls.cpp:688 redefines `D2_ASSERT` (C4005): one definition, in one header.
  - **D2Direct3D:** Src/d3dSprite.cpp `D3DSPRITE_DrawSpriteQuad` can end without a return value (C4715).
    Src/d3dFloorCache.cpp:41 redefines `RELEASE` (C4005).
  - **D2Game:** GAME/SCmd.cpp `D2GAME_PACKETS_SendPacket0xAE` ends without a return after the failed size
    assertion (C4715). MONSTER/MonsterUnique.cpp `MONSTERUNIQUE_UMod8_Resistant` likewise (C4715).
    `D2_MIN`/`D2_MAX` redefined in SKILLS/SkillAss.cpp:342-344 and SKILLS/Skills.cpp:441-443,
    `EVENTTYPE_REMOVESTATE` in SKILLS/Skills.cpp:437, `UNITFLAG_TARGETABLE` in OBJECTS/ObjMode.cpp:464,
    `EVENTTYPE_STATREGEN` in PLAYER/Player.cpp:577 (C4005): one definition each. Quests/a1q4.cpp:1253 a type
    qualifier twice (C4114). GAME/Game.cpp:2075 `sprintf("~%d", szGameName, 0)` prints an address: very likely
    1.14d's own code, keep it, just don't "fix" it.
  - **D2Win:** Src/D2WinFont.cpp:137-139 redefines `D2_MAX`/`D2_MIN` (C4005).
  - **Fog:** Unknown_00401DF0.cpp:321, 324, 362 `%p` given an unsigned long (C4477): same output on x86, only
    matters for 64-bit (M7).
  - **Storm:** SOURCE/SCOMP.CPP and SOURCE/SFILE.CPP call the PKWARE routines by placeholders
    (`sub_006B01B0_Explode`, `sub_006B0870_Implode`) with two different declarations: their names are
    `explode` and `implode` (PKWARE DCL's API), one declaration in a header. The engine answers to both names
    meanwhile (Source/Storm/pklib/codex_names.cpp).
- 2026-11-27 17:00 PT, question for the user (item 2, parked): the PKWARE test against data the original
  library compressed needs the user's own MPQs. Could the user attach one or two (d2speech.mpq is small; any
  of d2data/d2exp/d2char will do), or run `pklib_test.exe d2data.mpq d2exp.mpq` from the build in their
  Diablo II folder and paste the output? Nothing from them goes into the repo.

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

- 2026-11-27 17:00 PT: on the new queue. PR #2 replaces #1 (same tree, made by tools/codex_sync.py, which now
  drops the `// build:` markers itself: item 4; #1 can be closed unmerged). PR #3 pklib (item 2; the MPQ run is
  parked for the user's archives), PR #4 resources (item 3), PR #5 CMake + docs/PORT_COMPILE.md (item 1: all 538
  files compile; findings above). The stack merges in order #2, #3, #4, #5. Starting item 5, the link report.
  (Correction: my 17:40 status line below was 16:40 PT.)

- 2026-11-27 17:40 PT: item 0 done, PR #1 (Source/ = Codex main 09eccff; data carried over exactly without
  Game.exe, by inverting gendata's rendering, checked by re-rendering all 2,481 old records). Toolchain in the
  sandbox: msvc-wine, MSVC 14.44.35207, cl 19.44.35230 for x86, link 14.44.35230.0, SDK 10.0.26100.0, under
  wine 11.0 (Ubuntu's wine 9.0 crashes on this kernel). Starting item 2.
