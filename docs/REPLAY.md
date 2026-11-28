# Replay tests (M2)

How the engine proves it plays like 1.14d: the same inputs, run through stock 1.14d and through the engine, give
the same results. This is the design and the state of `tools/replay/`, a developer tool. The engine never needs
it, and it needs neither Iblis Codex nor its tools at run time: only a developer's own 1.14d install.

## The two runners

Every test is a **case**: a function that takes fixed inputs (seeds, an act, a level, a script), calls the game's
own code, and writes what came out as text, one fact per line, in a canonical order. The same case runs twice:

- **The oracle**, `replay_oracle.exe`, runs the case against **stock 1.14d**. It maps the player's own `Game.exe`
  into its process (sections, relocations, imports from the DLLs next to it), without running the game's entry
  point, and calls the game's functions at their 1.14d addresses. The addresses, calling conventions and
  signatures are listed in `tools/replay/entry_points.h`: facts about 1.14d (from Iblis Codex, copied once),
  not bytes of it. Nothing of Game.exe is stored.
- **The engine runner**, `replay_engine.exe`, runs the same case against the **engine's** code, calling the same
  functions by name.

`tools/replay/compare.py` diffs the two outputs. A case passes when they are identical.

Why in-process rather than driving the game: a test then needs no window, no input and no timing. It runs in a
second, it runs in CI on Windows (and under wine), and when it fails the first differing line points at the
function. Whole-game scenarios (a scripted save, a TCP/IP session) come later, on top of the same cases.

## What a case may touch

The game's code expects its process to be set up: the C runtime of Game.exe initialised (heap, locks, `_cinit`),
Fog's memory pools, Storm's archives, and the data tables. Cases are ordered by how much of that they need, and
each level of setup is one shared function on each side:

| Level | Setup on both sides | Cases |
|---|---|---|
| 0 | none | the random number generator |
| 1 | the game's C runtime and Fog (memory pools, the error handler) | string and bit-buffer helpers |
| 2 | Storm with the player's MPQs, D2Lang, the data tables (`DATATBLS_LoadAllTxts`) | table lookups, item and monster stats |
| 3 | a drlg act (`DUNGEON_AllocAct(act, seed, ...)`, 0x006194A0, as map tools do with 1.13c's D2Common) | map generation for a seed |
| 4 | a server game (`D2Game`) in single-player mode, no client | the drops of a seeded kill, a scripted save (`.d2s` bytes) |

## The cases, in order

1. **`rng` (level 0, passing).** For a list of low seeds, `SEED_InitLowSeed`, then a run
   of `SEED_RollRandomNumber` and of `SEED_RollLimitedRandomNumber` with several limits (powers of two and
   not, 0 and negative). Every drop, map and combat roll goes through these. Pure arithmetic: no setup at all,
   so it proves the runners themselves (mapping, calling conventions, 64-bit returns).
2. **`bitbuf` (level 0, passing).** The bit buffer every save, item and packet is written and read through
   (Fog's `BITMANIP_*`), over runs of 200 fields of 1 to 32 bits with byte alignments, one run written past its
   end; then reading back, signed reads, and `FOG_ComputeChecksum`, the `.d2s` checksum, over each buffer.
3. **`startup` (level 1, passing).** Game.exe's own C runtime started as at a stock start, then `rng` and
   `bitbuf` again: proves the level 1 setup.
4. **`drlg` (level 3).** For each seed, each act and difficulty: allocate the act and its levels, initialise
   every level, and dump per level its id, size and position, its rooms (position, size, type, preset and file
   index) in a fixed order, and its exits. Map generation is where a wrong roll or a different
   evaluation order shows first.
5. **`drops` (level 4).** A server game on a fixed seed, a monster of a given class killed by a player of a given
   level and magic find: the item list (codes, qualities, affixes, sockets, the seeds of each item). Repeated
   for unique and champion monsters and for chests.
6. **`save` (level 4).** Create a character of each class, run a fixed script (move, pick up, equip, level up),
   save; compare the `.d2s` bytes, and load the stock save in the engine and save it again.

The roadmap's M2 check (map generation, drops, combat, saves) is these four, plus combat (a seeded hit table)
once `drops` stands.

## What is compared

Text, not memory: each case prints what the game computed (numbers, ids, codes) and never pointers, addresses
or uninitialised padding. A pointer field is printed as what it points at (a room as its position), or left out.
Where the original reads memory it doesn't own (a known 1.14d bug), the case says so and prints the result as the
original computes it: the engine must match the bug.

## Running

On Windows with the build configured with `-DIBLIS_REPLAY=ON`:

    replay_oracle.exe --game "C:\Games\Diablo II\Game.exe" --case rng > oracle.txt
    replay_engine.exe --case rng > engine.txt
    python tools\replay\compare.py oracle.txt engine.txt

Under Linux the same with wine. The oracle checks that Game.exe is 1.14d (its size and a SHA-256) before it
maps it.

## Level 1 in the oracle

The oracle doesn't call the C runtime's init functions one by one: it runs Game.exe's own entry point, with
`WinMain` (0x004066E0) replaced in its in-memory copy by a jump to the case. The game's runtime starts exactly as
at a stock start (heap, locks, I/O, the static constructors of every module) and the case runs where the game
would begin. The case then leaves with `ExitProcess`, never returning into the game.

## The engine runner until the engine links

`replay_engine` links only the game files its cases call (`IBLIS_REPLAY_GAME_SOURCES` in CMakeLists.txt) with
`/FORCE:UNRESOLVED`. Two rules keep that honest:

- Every function and global a case reaches must be bound to its definition. Those files still name some of
  them differently from the definitions (docs/PORT_LINK.md); `tools/replay/engine_links.cpp` binds those names
  to the definition at the address their declaration gives, taken once from Codex's `LINK_DEBT.json` for these
  files. When a case or a file is added, extend it the same way.
- What stays unresolved must be code no case reaches. An unresolved global becomes address 0: under wine a read
  of it gives zeros instead of a crash, which is how the first `bitbuf` run differed (Fog's mask table,
  `gadwLowMasks`, is defined as `gData_006CE368`). So a new case that differs is first checked for this: link
  the runner by hand without `/FORCE:UNRESOLVED` and look for its globals in the list.

Once the engine links as a whole, the runner links the engine's libraries instead and both rules go.

## State

- `rng`, `bitbuf`, `startup`: identical between stock 1.14d and the engine (2,169, 1,993 and 4,163 lines; MSVC
  19.44 under wine, the user's 1.14d install).
- Next: level 2 (Storm with the player's MPQs, D2Lang, the data tables), toward `drlg`.
- `drlg`, `drops` and `save`: designed above, not written.
