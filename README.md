# Iblis Engine

A source port of Diablo II: Lord of Destruction 1.14d for modern systems, and a moddable engine built on it, in the
spirit of [DevilutionX](https://github.com/diasurgical/devilutionx) and [OpenMW](https://github.com/OpenMW/openmw).

Iblis Engine plays like 1.14d. It adds only what a modern port needs, and leaves everything else as 1.14d has it:

- higher resolutions and widescreen;
- automatic gold pickup;
- controller support;
- realm-only content in single player: ladder-only runewords and cube recipes, the Pandemonium Event and Diablo Clone;
- **Crossroads**, in place of Battle.net: add servers to your server list by address, then join one to reach its lobby, chat and game list; anyone can host a server;
- mod support: data, Lua and native mods, loaded in a load order, each described by one manifest.

Everything else, including 1.14d's bugs, stays as it is. Gameplay changes belong in mods.

**Status: early development. There is nothing to play yet.** See [docs/ROADMAP.md](docs/ROADMAP.md).

## Playing

Iblis Engine is one program. Download a release, put it next to your Diablo II: Lord of Destruction game files, and
run it. There is nothing to build and nothing else to install.

It needs your own copy of the game: the MPQ archives of an installation of Diablo II: Lord of Destruction (any
retail or digital copy, patched to 1.14d). Iblis Engine ships no game data.

## Building from source

Only needed if you want to work on the engine. The source is a complete program: it builds with CMake and a current
C++ compiler, with no game files and no other project needed.

Build instructions are added with the first milestone that builds (see the roadmap).

## Repository layout

| Path | Contents |
|---|---|
| `Source/` | the engine's source, laid out like Blizzard's own source tree, one folder per original module |
| `docs/` | the roadmap and design notes |

The source started from [Iblis Codex](https://github.com/CaptainLegbreak/Iblis-Codex), the reconstructed source of the
1.14d `Game.exe`. Iblis Codex stays a separate project: it is the reference for how 1.14d behaves, and is not needed to
build or play Iblis Engine. Above each function, a `// 0x<address>` comment gives its address in the 1.14d `Game.exe`,
so any function can be compared with the original.

## Licence

GPL-3.0 (see [LICENSE](LICENSE)). The licence covers the engine. Mods can use any licence their authors choose.

Parts of the source are adapted from Iblis Codex (`NOTICE-IBLIS-CODEX.txt`, MIT), D2MOO by ThePhrozenKeep
(`NOTICE-D2MOO.txt`, MIT) and zlib (`NOTICE-ZLIB.txt`).

Diablo II and its data belong to Blizzard Entertainment. This project is not affiliated with or endorsed by Blizzard.

Developed with AI assistance.
