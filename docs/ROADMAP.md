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

The order follows DevilutionX: first prove the reconstructed source runs as a whole program while it is still
Windows-only, then build the replay tests, then swap the Windows-only parts (DirectDraw, DirectSound, Win32 input,
Storm and Battle.net networking) for SDL 3.

| # | Milestone | Check |
|---|---|---|
| M0 | Self-contained source. The game's initialised data tables are ordinary C++ definitions in the source; the PKWARE compression routines get an open implementation; the program gets its own resources; the Codex build markers (`// build:`) are removed | A fresh clone contains every line of code and data the program needs: nothing is read from `Game.exe` |
| M1 | The relinked exe: the source linked as an ordinary Windows program, with the stand-ins for the 8 unreconstructed functions and the globals the code reaches across fixed so they work on their own | On a clean 1.14d install, with the exe in place of `Game.exe`: menus, a new character of each class, Act 1, save and reload, a TCP/IP game against stock 1.14d |
| M2 | Replay test harness, as DevilutionX does with recorded demos: fixed-seed replays checked against stock 1.14d | Map generation, item drops, combat and saves give identical results in the engine and in stock 1.14d |
| M3 | SDL 3 platform layer: video, audio, input, files and MPQ access, timing, threads, sockets; settings in a config file instead of the registry | Same game with no DirectX or Win32 calls; original `.d2s` characters load and save; M2's replays pass |
| M4 | Settings layer: resolutions and widescreen, automatic gold pickup, controller support, realm-only content offline. Every addition is an option that defaults to stock | With every option at its default, M2's replays pass; each option has its own test and an entry in `docs/DIFFERENCES.md` |
| M5 | Mod loading, the OpenMW way: data folders stacked over the game's MPQs in a load order, Lua for logic (see the engine milestones) | A test mod loads, and with no mods M2's replays pass |
| M6 | Crossroads: host a headless server or join one through the game browser, growing around the engine as TES3MP grew around OpenMW | Host and join across Windows and Linux with no desyncs in a scripted session |
| M7 | Linux, macOS, 64-bit and ARM builds | M2's replays pass on each; saves identical across platforms |
| M8 | Releases | One download per platform with the engine alone. On first run it finds the player's own 1.14d MPQs, or says clearly which ones are missing. No Blizzard data is ever shipped |

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

Iblis: Resurrected, Equilibrium, Unearthed, The Darkening and the other mods are content packs in this load order, not
separate programs.

## Keeping up with Iblis Codex

Iblis Codex keeps improving after the engine's source was taken from it: better names, the last 8 functions,
original file names. Those improvements are brought over by hand, as ordinary commits, the way DevilutionX takes
fixes from devilution. Nothing in the engine depends on the Codex being present.
