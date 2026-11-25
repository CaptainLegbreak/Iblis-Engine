# Roadmap

Each step has an exit check. A step is done when its check passes, not when its code is written.

## The goal

One program, like DevilutionX: a player downloads a release, points it at their own Diablo II: Lord of Destruction
game files (the MPQ archives), and plays. Players build nothing. Developers build the source with CMake and a current
compiler, without game files, without Iblis Codex and without any of its tools.

## What "plays like 1.14d" means

The engine's gameplay must match 1.14d: rules, formulas, AI, map generation, the random number generator, drops,
balance, quests, and its bugs. The reference for original behaviour is the 1.14d `Game.exe` itself, and Iblis Codex,
which rebuilds it from source byte for byte.

The proof is tests: the same inputs and seeds, run through the engine and through the original, must give the same
results. The test harness is a developer tool that runs against a developer's own 1.14d install; the engine never
needs it. Every intended difference (the additions in the README) is listed in `docs/DIFFERENCES.md` with its test,
once the first one lands.

Realm-only content is available in single player and in Crossroads games: ladder-only runewords and cube recipes, the
Pandemonium Event and Diablo Clone.

## Port milestones

| # | Milestone | Check |
|---|---|---|
| M0 | Self-contained source. The game's initialised data tables are written into the source as ordinary C++ definitions (347 files still read them from a generated folder); the 8 functions Iblis Codex has not reconstructed yet keep their functional rewrites; the PKWARE compression routines get an open implementation; the program gets its own resources; the Codex build markers (`// build:`) are removed | A fresh clone contains every line of code and data the program needs: nothing is read from `Game.exe`, and no file outside the repository is used |
| M1 | Modern Windows build. CMake project, current MSVC, 32-bit Windows, original platform code still in place | Builds from a fresh clone with CMake alone; the exe boots and plays on Windows 10/11 from a folder containing only the exe and the game's MPQs: menus, a new character of each class, Act 1, save and reload, a TCP/IP game against stock 1.14d |
| M2 | Behaviour test harness | Fixed-seed runs of map generation, item drops, item requirements and combat formulas give the same results in the engine as in the original |
| M3 | SDL 3 platform layer: window, rendering output, audio, input, file and MPQ access, timing, threads, sockets; settings in a config file instead of the registry | Same game, no DirectX or Win32 UI calls; original `.d2s` characters load and save; M2's tests pass |
| M4 | Linux (32-bit x86) | Plays on Linux without Wine; M2's tests pass |
| M5 | The additions: resolutions and widescreen, automatic gold pickup, controller support, realm-only content offline | Each addition has a test and an entry in `docs/DIFFERENCES.md`; with them turned off, M2's tests still pass |
| M6 | Crossroads: host a headless server or join one through the game browser | Host and join across Windows and Linux with no desyncs in a scripted session |
| M7 | 64-bit, then macOS and ARM Linux | M1–M6 checks on 64-bit builds; saves identical to what 32-bit builds write |
| M8 | Releases | One download per platform: the exe (or app bundle) and nothing else to install. On first run it finds the player's game files, or says clearly which ones are missing |

## Engine milestones

Built by refactoring the port, with the port's behaviour as the baseline every change is tested against.

| # | Milestone |
|---|---|
| E1 | Virtual filesystem: mod folders layered over the game's MPQs in a load order |
| E2 | Mod manifest (`manifest.json`) and mod manager, with a conflict checker that warns when two mods change the same thing |
| E3 | Data mods: table changes applied as keyed patches over the player's own tables |
| E4 | Lua 5.4 scripting, sandboxed |
| E5 | Native mods |
| E6 | Multiplayer content lock: every player in a Crossroads game runs the same mods, except server-only and visual-only mods |
| E7 | First mod through the whole pipeline: Iblis: Resurrected |

## Keeping up with Iblis Codex

Iblis Codex keeps improving after the engine's source was taken from it: better names, the last 8 functions,
original file names. Those improvements are brought over by hand, as ordinary commits, the way DevilutionX takes
fixes from devilution. Nothing in the engine depends on the Codex being present.
