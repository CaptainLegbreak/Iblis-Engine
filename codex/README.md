# Iblis Codex

Reconstructed C++ source code of the Diablo II 1.14d `Game.exe`. The sources compile, with the original compiler, into
the same machine code the game shipped with, and the build links them into a `Game.exe` whose SHA-256 is that of the
original file.

![Function grid: one cell per function of Game.exe in address order. Bright green is byte-identical with no address fields, green is byte-identical once linked at its original address, purple matches only with a non-original construct, red is not reconstructed yet, grey is runtime library code placed by identity](docs/grid.svg)

**[Open the interactive grid](https://raw.githack.com/CaptainLegbreak/Iblis-Codex/main/docs/index.html)**: hover or tap a cell to see the
function, search by address or name, filter by module or state, and click through to its source file. The same page is
`docs/index.html` in this repository and works offline.

![Source shape: one cell per function in address order. Green sits in a whole file with its original name, blue in an original file still in pieces, amber in a placeholder file whose original is not known yet, purple needs a construct that forces code generation, red is not reconstructed yet, grey is runtime library code](docs/shape.svg)

The second grid tracks how close the sources are to the original tree in form, not bytes. `tools/status.py` regenerates both grids and `STATUS.md` from the build data.

## Names

Structs and most game-logic names come from D2MOO by ThePhrozenKeep (https://github.com/ThePhrozenKeep/D2MOO, MIT; see NOTICE-D2MOO.txt). Only names marked `blizzard` in names.csv are Blizzard's own (from exports, symbols or the game's diagnostics); `library` names are those of a library the code comes from (zlib, ATL); `d2moo` names are community names; `inferred` names were given here, in Blizzard's naming format for their file, from what the function does; `placeholder` names are addresses or export ordinals awaiting a name.

## What is here

| Path | Contents |
|---|---|
| `Source/<Module>/` | 618 compilation units, laid out like Blizzard's own source tree, defining 14,919 functions |
| `Source/<Module>/<Module>.h` | the declarations several files of a module share |
| `Source/StandIns/` | functional replacements for the 8 functions that are not reconstructed yet, used only by the ordinary build (see Building) |
| `CMakeLists.txt` | the sources as an ordinary CMake project (compiles the objects; see Building) |
| `build/` | the data the build needs: the unit list with per-unit compiler options (`units.json`), every address record (`functions.json`), the layout of initialised data (`data_plan.json`), import thunk runs, file-layout plans, toolchain pins |
| `docs/` | the function grid (`grid.svg`), the source shape grid (`shape.svg`) and the interactive viewer (`index.html`) |
| `tools/` | setup, build and status scripts (Python 3.9+, standard library only) |
| `names.csv` | every function's address, name and where the name comes from |
| `STATUS.md` | what is verified, what is not yet, and which functions need non-original constructs |

Functions sit in files named after Blizzard's original source files, as the game's own diagnostics name them (for
example `Source/D2Common/ITEMS/Items.cpp`). A run of functions whose original file is not known is in
`Unknown_<address>.cpp`, named after its first function. Functions of one original file that cannot share its
compilation unit yet (another compiler option, or declarations that do not agree) are in `<File>_<address>.cpp` beside
it.

Above every function definition, a line `// 0x<address>` gives the address of the function in the original
`Game.exe`; a trailing `// 0x<address>` on a declaration gives the address of that callee or global. Lines starting
with `// build:` are instructions to the build tools (for example `// build: symbol <name> 0x<address>` for a
compiler-generated function). The build uses all of these, so keep them when you edit a file.

The repository contains no part of the game. The layouts of the game's initialised data tables come from the same
D2MOO structs as the code (`build/data_plan.json` holds only their addresses, sizes, types and names); their values, the
code of the 8 functions that are not reconstructed yet, the resources and the file's signature are read from
your own copy of `Game.exe` at build time and written to the git-ignored `gen/` and `out/` folders.

## Requirements

- your own Diablo II 1.14d `Game.exe` (SHA-256 `631066c1649c4ea9ffe48bf97e24c00bca1f7a6759c21150f1a79982589adaaf`);
- Python 3.9 or later and git;
- the Microsoft Visual C++ 2005 SP1 compiler, cl 14.00.50727.762 (`tools/setup.py` fetches it from a pinned public
  repository and checks every file by hash);
- the Visual C++ 2005 SP1 runtime libraries (libcmt 8.0.50727.4053, from the KB971090 update), for linking
  (`tools/setup.py --crt` rebuilds them from Microsoft's public packages on archive.org: about 890 MB of downloads,
  and it needs `7z`, `msiinfo` and `cabextract`);
- on Linux or macOS, Wine 9.

The compiler and libraries are Microsoft software under Microsoft's licence terms; this repository does not include
them.

## Building

There are two builds of the same sources. Both start with:

```
python tools/setup.py --game /path/to/Game.exe --crt
```

`setup.py` checks your `Game.exe`, fetches and verifies the toolchain into `toolchain/`, generates `gen/` from your
`Game.exe` and records the paths in `local.json`.

### The byte-exact build

```
python tools/build.py
```

compiles every unit (in parallel, `-j N`), checks each function's bytes against the original, links all of them at
their original addresses and writes `out/Game.exe`, whose SHA-256 must equal the original's. This proves that the
sources are the game's code: every verified function compiles to exactly the bytes the game shipped with. A full
build takes about a quarter of an hour on two cores; later builds reuse the objects of unchanged units. The 8
functions that are not reconstructed yet are taken from your `Game.exe` here.

### The ordinary build

```
python tools/link.py
```

compiles the same units with the same options (it runs the compile step of `build.py` and shares its objects), and
links them with the Visual C++ 2005 SP1 linker and its static C runtime the way any program is linked: the linker
lays out code and data itself, nothing is placed at an original address, and the result,
`out/Game.ordinary.exe`, is relocatable. It is not byte-identical with the original and is not meant to be. This
proves that the sources form a complete program: every reference has exactly one definition, with no unresolved
or duplicate symbols.

What it does beyond an ordinary link, and why:

- The 8 functions that are not reconstructed yet come from `Source/StandIns/`, one file each, written to do what
  the original function does; they are not the original code, and `build.py` never uses them.
- Some files declare a callee or global under a different name than the file that defines it, and some files
  carry a copy of a function for its calling convention or a call site. `link.py` keeps one definition per
  function and global and binds every reference to the definition at the address it means: in verified code the
  address the original's bytes hold there, elsewhere the address of the declaration's `// 0x<address>` marker.
- Data no source defines yet, the PKWARE compression routines that Storm links as a prebuilt library, and runs
  of globals that the code treats as one object (it reaches from one into the next, so their original layout must
  be kept) are copied from your `Game.exe` into `gen/link/` at build time, with every pointer in them relinked.
  So are the import libraries for the DLLs `Game.exe` imports, its export table and its resources.

`link.py` then checks the linked file without running it: a valid PE image whose entry point is the C runtime's
`WinMainCRTStartup`, the same imports as the original, each one an export of its DLL, and every verified function
and initialised global read back from the image equal to the original's once addresses are mapped.
`out/ordinary/LINK_REPORT.json` has the details, including the size of everything taken from your `Game.exe`.

### CMake

`CMakeLists.txt` describes the same sources as an ordinary project. From a Visual C++ 2005 SP1 command prompt, after
`tools/setup.py`:

```
cmake -G "NMake Makefiles" -S . -B out/cmake
cmake --build out/cmake
```

compiles every source file into an object with its recorded compiler options. It does not link them;
`tools/build.py` and `tools/link.py` are the builds that do.

## Verifying

`build.py` ends by printing the SHA-256 of `out/Game.exe` and whether it equals the original's. To check it yourself:

```
sha256sum out/Game.exe
```

It must print `631066c1649c4ea9ffe48bf97e24c00bca1f7a6759c21150f1a79982589adaaf`. `out/link/BUILD_REPORT.json` counts every byte of the file by origin (built from source,
runtime library, linker, or taken from your `Game.exe`).

## What needs work

`STATUS.md` lists the functions that have no source yet, the functions that only match with a non-original
construct (a per-file compiler option, link-time code generation, a calling-convention shim, inline assembly), and how
many names are still placeholders.

## Credits

- Esk
- slurpeestraw
- roachzNgutz
- a contributor from the High Heavens

### Sources and thanks

- D2MOO by ThePhrozenKeep (https://github.com/ThePhrozenKeep/D2MOO, MIT): structs and most names
- zlib by Jean-loup Gailly and Mark Adler: Game.exe links zlib 1.2.8's decompression code (used by Storm for compressed archive data); the matching files follow its source (see NOTICE-ZLIB.txt)
- d2bs (https://github.com/noah-/d2bs) and D2LootFilter (https://github.com/dschu012/D2LootFilter): their 1.14d address tables were early hints for what functions do
- Jarcho's Diablo-II-Address-Table (https://github.com/Jarcho/Diablo-II-Address-Table): used to pair 1.14d functions with their 1.13d counterparts
- The Phrozen Keep community, home of D2MOO and of the archived game builds used as evidence
- fearedbliss, for the Bliss Version Switcher collection of every Windows build from 1.00 to 1.14d (https://github.com/fearedbliss/Cactus is its successor)
- BNfan and vweyler, for the Japanese retail Diablo II Complete collection (1.03–1.14d)
- chickenbuckets (BetaArchive), for preserving the Diablo II beta disc
- Drahsid/ffxiv_msvc8.0sp1 (https://github.com/Drahsid/ffxiv_msvc8.0sp1), which hosts the Visual C++ 2005 SP1 compiler files that tools/setup.py fetches
- the Internet Archive, for the Visual Studio 2005 packages that setup.py --crt rebuilds the runtime libraries from
- the devilution team (diasurgical, https://github.com/diasurgical/devilution): the model for this project's reconstruction approach and layout
- the Wine project (https://www.winehq.org): runs the 2005 compiler on Linux and macOS
- the Blizzard team behind the 2016 1.14 patches, which brought the game to modern Windows
- Blizzard North, for Diablo II

Reconstructed with AI assistance.

## Licence

MIT (`LICENSE`). Parts of the sources are adapted from D2MOO (`NOTICE-D2MOO.txt`) and from zlib (`NOTICE-ZLIB.txt`).
Diablo II is a trademark of Blizzard Entertainment; this project is not affiliated with or endorsed by Blizzard.
