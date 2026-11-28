# Compiling with a current compiler

The state of the engine's source under Visual Studio 2022. Kept current after each sync from Iblis Codex
(`tools/codex_sync.py`); the source fixes go to the Codex lanes, which make them in Codex and keep the byte-exact
build, and they come back with the next sync.

Last measured: 2026-11-27, Source/ at Codex 0bf13c4 (#494).

## Toolchain

| | |
|---|---|
| Compiler | MSVC 14.44.35207 (v143), `cl` 19.44.35230 for x86 |
| Linker | `link` 14.44.35230.0 |
| Windows SDK | 10.0.26100.0 |
| Where | Visual Studio 2022 on Windows; measured here with the same compiler under Linux, through [msvc-wine](https://github.com/mstorsjo/msvc-wine) and wine 11.0 |

Building on Windows:

    cmake -G "Visual Studio 17 2022" -A Win32 -S . -B build
    cmake --build build --config Release

With msvc-wine (its `bin/x86` first in `PATH`):

    CC=cl CXX=cl cmake -G Ninja -S . -B build -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_BUILD_TYPE=Release
    ninja -C build -k 0

## The build

- One static library per original module folder (Bnclient, D2BNClient, D2CMP, D2Client, D2Common, D2DDraw,
  D2Direct3D, D2Game, D2Gdi, D2Gfx, D2Glide, D2Hell, D2Lang, D2Launch, D2MCPClient, D2Multi, D2Net, D2Sound,
  D2Win, Fog, SRP, Storm), and the program from `Source/Main`, linked with `/WHOLEARCHIVE` so every object is in
  the program, as in the original link.
- Each file keeps the compiler options it was originally built with (`cmake/Sources.cmake`, written by
  `tools/cmake_sources.py` from Codex's `build/units.json`): `/O2 /Oy- /Ob2 /Gd` and the file's own `/GS-`,
  `/EHsc`, `/EHa`, `/Ob1`, `/Oy`, `/O1`, `/Od`, `/TC`. No `/GL`.
- The switches that make v143 treat the code as Visual C++ 2005 did are one list, `IBLIS_MSVC2005_COMPAT` in
  `CMakeLists.txt`: `/arch:IA32` (x87 floating point, no SSE2 code), `/permissive`, `/Zc:threadSafeInit-`,
  `/Zc:sizedDealloc-`, `/Zc:wchar_t`, `/Zc:forScope`.

## Result

**Every file compiles: 538 of 538 game source files**, plus the engine-only files (`Source/Storm/pklib`,
`Source/Main/res/Game.rc`). There are no failing files, so there are no causes to fix for compiling.

The link is the next step: `docs/PORT_LINK.md`.

## Warnings worth a source fix

At `/W1`, 59 warnings. None stops the build; the ones below point at code whose behaviour can depend on the
compiler. Each is posted on the lane 14 board under Findings, by Codex module.

### A value-returning function that can end without `return` (C4715): 4 functions

The 2005 compiler returned whatever was in `eax` at that point, and the game's callers may read it; v143 can
leave something else there. The fix is to write the `return` with the value 1.14d's code returns on that path
(Codex's byte-exact build shows it).

| Module | File | Function |
|---|---|---|
| D2Client | `UNIT/MonUnique.cpp` | `MONUNIQUE_ApplyResistantMod` |
| D2Direct3D | `Src/d3dSprite.cpp` | `D3DSPRITE_DrawSpriteQuad` |
| D2Game | `GAME/SCmd.cpp` | `D2GAME_PACKETS_SendPacket0xAE` (after the failed size assertion) |
| D2Game | `MONSTER/MonsterUnique.cpp` | `MONSTERUNIQUE_UMod8_Resistant` |

### A macro defined twice with different text (C4005): 12 sites

A later definition replaces an earlier one, so which text a use gets depends on include order. The fix is one
definition, in one header.

| Module | File | Macro |
|---|---|---|
| D2Client | `UI/inv.cpp` | `va_start` (the file defines its own) |
| D2Common | `DATATBLS/MonsterTbls.cpp` | `D2_ASSERT` |
| D2Direct3D | `Src/d3dFloorCache.cpp` | `RELEASE` |
| D2Game | `OBJECTS/ObjMode.cpp` | `UNITFLAG_TARGETABLE` |
| D2Game | `PLAYER/Player.cpp` | `EVENTTYPE_STATREGEN` |
| D2Game | `SKILLS/SkillAss.cpp` | `D2_MAX`, `D2_MIN` |
| D2Game | `SKILLS/Skills.cpp` | `EVENTTYPE_REMOVESTATE`, `D2_MIN`, `D2_MAX` |
| D2Win | `Src/D2WinFont.cpp` | `D2_MAX`, `D2_MIN` |

### Format strings that disagree with their arguments (C4477): 4 sites

| Module | File | What |
|---|---|---|
| D2Game | `GAME/Game.cpp` line 2075 | `sprintf("~%d", szGameName, 0)` prints the name's address. Very likely 1.14d's own code, kept as is; listed so nobody "fixes" it by accident |
| Fog | `Unknown_00401DF0.cpp` (3) | `%p` given an `unsigned long`. Same output on x86; matters only for a 64-bit build (M7) |

### Declarations the compiler ignores or doubts: 4 sites

| Module | File | What |
|---|---|---|
| D2Client | `SKILLS/Skills.cpp` line 1121 | an `int` narrowed to `unsigned int` in a brace initialiser (C4838; ok in 2005, an error under `/permissive-`) |
| D2Client | `UNIT/UnitSnd.cpp` lines 209, 211 | `extern` on a struct definition with no variable (C4091) |
| D2Game | `Quests/a1q4.cpp` line 1253 | a type qualifier written twice (C4114) |

### Intrinsics declared without their header (C4164): 35 sites

`memset`, `memcpy`, `strlen`, `strcpy`, `strcmp` and `_ReadWriteBarrier` named in `#pragma intrinsic` before any
declaration. Harmless here; the source declares these functions itself instead of including the C headers.
Listed for completeness, no fix needed for the port.
