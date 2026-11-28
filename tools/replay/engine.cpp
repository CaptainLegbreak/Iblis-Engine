// The engine runner: binds the replay functions to the engine's own definitions. See docs/REPLAY.md.
#include "entry_points.h"

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);
unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed);
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);
extern "C" int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);
unsigned int __stdcall sub_00410F60_ReadBits(D2BitBufferStrc* pBuffer, int nBits);
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits);
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer);
int __stdcall FOG_ComputeChecksum(unsigned char* pData, int nSize);
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, unsigned int dwFlags, void** phFile);
int __stdcall SFileGetFileSize(void* hFile, unsigned int* pdwFileSizeHigh);
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped);
int __stdcall SFileCloseFile(void* hFile);

bool replay::Bind(Functions* f, int, char**)
{
#define REPLAY_BIND(name, va, type) f->name = &::name;
    REPLAY_FUNCTIONS(REPLAY_BIND)
#undef REPLAY_BIND
    return true;
}

int replay::Start(int, void (*pfnCase)())
{
    pfnCase();
    return 0;
}
