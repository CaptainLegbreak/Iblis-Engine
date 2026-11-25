# Iblis Engine

A source port of Diablo II: Lord of Destruction 1.14d for modern systems, and a moddable engine built on it, in the
spirit of [DevilutionX](https://github.com/diasurgical/devilutionx) and [OpenMW](https://github.com/OpenMW/openmw).

Iblis Engine plays like 1.14d. Its code comes from [Iblis Codex](https://github.com/CaptainLegbreak/Iblis-Codex), the
reconstructed source of the 1.14d `Game.exe`, which builds back into a file identical to the original. The engine adds
only what a modern port needs, and leaves everything else as 1.14d has it:

- higher resolutions and widescreen;
- automatic gold pickup;
- controller support;
- **Crossroads**, in place of Battle.net: host your own server, or join someone else's through the game browser;
- mod support: data, Lua and native mods, loaded in a load order, each described by one manifest.

Everything else, including 1.14d's bugs, stays as it is. Gameplay changes belong in mods.

**Status: early development. There is nothing to play yet.** See [docs/ROADMAP.md](docs/ROADMAP.md).

## You need your own copy of the game

Iblis Engine contains no game data. To build and play it you need your own installation of Diablo II: Lord of
Destruction, patched to 1.14d. The engine reads its MPQ archives. The build also reads some tables from its `Game.exe`
(SHA-256 `631066c1649c4ea9ffe48bf97e24c00bca1f7a6759c21150f1a79982589adaaf`) and writes them to the git-ignored
`gen/` folder. Nothing taken from the game is ever committed or shipped.

## Repository layout

| Path | Contents |
|---|---|
| `codex/` | the Iblis Codex sources and build data, imported as a git subtree (see below) |
| `docs/` | the roadmap and design notes |

The engine's own source tree, build files and platform layer are added as the roadmap's first milestones land.

### Updating the codex

`codex/` is a [git subtree](https://github.com/git/git/blob/master/contrib/subtree/git-subtree.txt) of Iblis Codex.
To bring in the latest codex:

```
git subtree pull --prefix=codex https://github.com/CaptainLegbreak/Iblis-Codex main --squash
```

The squash commit records which Iblis Codex commit was imported.

## Licence

See [LICENSE](LICENSE). The licence covers the contributors' own work only. Diablo II and its data belong to Blizzard
Entertainment; this project is not affiliated with or endorsed by Blizzard.
