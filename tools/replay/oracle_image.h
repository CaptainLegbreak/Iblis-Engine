// The oracle's loader (oracle_image.cpp): no game types here, and no Windows types.
#pragma once

namespace oracle
{
const unsigned int kImageBase = 0x00400000;     // 1.14d's preferred base

// Maps the 1.14d Game.exe at szPath (checked by SHA-256): sections, relocations, imports. Returns its base, or 0.
unsigned char* MapImage(const char* szPath);

// Runs the mapped game's entry point (its C runtime: heap, locks, I/O, static constructors) with WinMain, at
// nWinMain, replaced in this process's copy by a jump to pfnCase, then exits. Returns only on failure.
int StartGame(unsigned char* base, unsigned int nWinMain, void (*pfnCase)());
}
