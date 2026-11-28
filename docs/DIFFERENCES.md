# Differences from 1.14d

Every way the engine is meant to differ from the 1.14d `Game.exe`, with the test that shows it. Anything not
listed here behaves as 1.14d does, bugs included; a difference found that isn't listed is a bug in the engine.

| Area | Difference | Effect on play | Test |
|---|---|---|---|
| Storm, PKWARE DCL | `implode()` and `explode()` are an open implementation (`Source/Storm/pklib/`), not PKWARE's library. `explode()` reads every valid DCL stream to the same bytes. `implode()` writes a valid DCL stream whose bytes can differ from the original library's. Corrupt input: `explode()` stops with `CMP_BAD_DATA` where the original may read on | None: the game only decompresses (MPQ sectors). Nothing in the game calls `SCompCompress`, the only route to `implode()` | `tests/pklib_test.cpp`: round trips of both literal modes and all three dictionary sizes; the published DCL test stream; with the player's MPQs as arguments, every file the original library compressed is exploded, each sector to its exact size, checked by format where `(listfile)` names it (and by `(attributes)` CRC32 where an archive has one), and one in fifty round-tripped. On the 1.14d d2data.mpq and Patch_D2.mpq: 8,497 files (330 MB) explode, 1,339 checked by format, all pass |
| Resources | The program's icon, version information and manifest are the engine's own (`Source/Main/res/`, the icon drawn by `tools/make_icon.py`). 1.14d's `.rsrc` holds only icons, version information and a manifest (no dialogs or string tables), so this is the whole set | The window and Explorer show the engine's icon; the file's version information names Iblis Engine | — |
