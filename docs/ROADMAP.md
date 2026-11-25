# Roadmap

Each step has an exit check. A step is done when its check passes, not when its code is written.

## What "plays like 1.14d" means

The engine's gameplay must match 1.14d: rules, formulas, AI, map generation, the random number generator, drops,
balance, quests, and its bugs. The reference for original behaviour is Iblis Codex, which builds the original
`Game.exe` from source, byte for byte.

While the engine still compiles to the same machine code as the codex, "the same bytes" is the proof. Once the
platform layer is replaced and modern compilers are used, the proof is tests: the same inputs and seeds, run through
the engine and through the original, must give the same results. Every intended difference (the additions in the
README) is listed in `docs/DIFFERENCES.md` with its test, once the first one lands.

Realm-only content stays off in single player and in Crossroads games, as in 1.14d outside Battle.net realms:
ladder-only runewords and cube recipes, the Pandemonium Event and Diablo Clone. The Iblis: Resurrected mod brings them
offline.

## Gates before engine work builds on the codex

| | Gate | Check |
|---|---|---|
| G1 | The codex links as an ordinary program (`codex/tools/link.py`) and that program runs | Menus, a new character of each class, Act 1, save and reload, a TCP/IP game against stock 1.14d, in an unmodded install |
| G2 | No stand-ins: the last 8 functions of the codex are reconstructed | `codex/STATUS.md` lists no stand-ins |
| G3 | Behaviour test harness | Fixed-seed runs of map generation, item drops, item requirements and combat formulas give the same results in the codex build as in the original |

## Port milestones

| # | Milestone | Check |
|---|---|---|
| M0 | Engine build. CMake project over the codex sources; compiles with current MSVC as 32-bit Windows, original platform code still in place | The whole source compiles and links with a modern compiler |
| M1 | Modern-compiler Windows build plays | Boots and plays on Windows 10/11; G3's tests pass |
| M2 | SDL 3 platform layer: window, rendering output, audio, input, file and MPQ access, timing, threads, sockets; settings in a config file instead of the registry | Same game, no DirectX or Win32 UI calls; original `.d2s` characters load and save |
| M3 | Linux (32-bit x86) | Plays on Linux without Wine; G3's tests pass |
| M4 | The additions: resolutions and widescreen, automatic gold pickup, controller support | Each addition has a test and an entry in `docs/DIFFERENCES.md`; with them turned off, G3's tests still pass |
| M5 | Crossroads: host a headless server or join one through the game browser | Host and join across Windows and Linux with no desyncs in a scripted session |
| M6 | 64-bit, then macOS and ARM Linux | M1–M5 checks on 64-bit builds; saves identical to what 32-bit builds write |
| M7 | Release packaging | Installers or archives that find the player's game files and say clearly what is missing |

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
