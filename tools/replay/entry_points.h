// The 1.14d functions the replay cases call: their addresses in the stock Game.exe and their signatures.
// Facts about 1.14d (from Iblis Codex's build/functions.json, copied here), not bytes of it. The engine runner
// calls the same functions by name.
#pragma once

#include "../../Source/Include/D2Structs.h"
#include "../../Source/Include/D2Primitives.h"

namespace replay
{
// A function of the game: its 1.14d address and its type, for both runners.
#define REPLAY_FUNCTIONS(X)                                                                                   \
    X(SEED_InitLowSeed, 0x00650E40, void(__fastcall*)(D2SeedStrc*, unsigned int))                             \
    X(SEED_RollRandomNumber, 0x0045C370, unsigned __int64(__fastcall*)(D2SeedStrc*))                          \
    X(SEED_RollLimitedRandomNumber, 0x0045C390, unsigned int(__fastcall*)(D2SeedStrc*, int))                  \
    X(BITMANIP_Initialize, 0x00410E40, void(__stdcall*)(D2BitBufferStrc*, unsigned char*, int))               \
    X(BITMANIP_GetSize, 0x00410E90, int(__stdcall*)(D2BitBufferStrc*))                                        \
    X(BITMANIP_Write, 0x00410EB0, void(__stdcall*)(D2BitBufferStrc*, int, int))                               \
    X(sub_00410F60_ReadBits, 0x00410F60, unsigned int(__stdcall*)(D2BitBufferStrc*, int))                     \
    X(BITMANIP_ReadSigned, 0x00411030, int(__stdcall*)(D2BitBufferStrc*, int))                                \
    X(BITMANIP_GoToNextByte, 0x00411070, void(__stdcall*)(D2BitBufferStrc*))                                  \
    X(FOG_ComputeChecksum, 0x00411130, int(__stdcall*)(unsigned char*, int))                                 \
    X(SFileOpenArchive, 0x0041BA60, int(__stdcall*)(const char*, int, unsigned int, void**))                  \
    X(SFileOpenFileEx, 0x004192F0, int(__stdcall*)(void*, const char*, unsigned int, void**))                 \
    X(SFileGetFileSize, 0x00416370, int(__stdcall*)(void*, unsigned int*))                                    \
    X(SFileReadFile, 0x0041B050, int(__stdcall*)(void*, void*, int, int*, void*))                             \
    X(SFileCloseFile, 0x004198D0, int(__stdcall*)(void*))

template <class T> using Type = T;     // lets a function-pointer type be written before its name

struct Functions
{
#define REPLAY_MEMBER(name, va, type) Type<type> name;
    REPLAY_FUNCTIONS(REPLAY_MEMBER)
#undef REPLAY_MEMBER
};

// The address of WinMain in 1.14d: the oracle's startup stops there (see Start).
const unsigned int kWinMain = 0x004066E0;

// Fills f for the runner this is compiled into; returns false (with a message on stderr) if it can't.
bool Bind(Functions* f, int argc, char** argv);

// Runs pfnCase with the game's process set up to nLevel (docs/REPLAY.md). Level 0: nothing. Level 1: the game's
// C runtime started as at a stock start (the oracle runs Game.exe's entry point and takes over at WinMain;
// the engine runner has its own runtime). Returns the exit code.
int Start(int nLevel, void (*pfnCase)());
}
