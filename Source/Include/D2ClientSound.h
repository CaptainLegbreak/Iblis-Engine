#pragma once
// Client: sounds.txt records (compiled columns plus the sound cache's runtime fields), the SoundHdr API and the
// sound units' unit list node.

#include "D2Check.h"

struct AsyncData;

#pragma pack(push, 1)

struct D2SoundsTxt
{
    char szFilename[60]; // 0x00
    unsigned char nVolume; // 0x3C
    unsigned char nGroupSize; // 0x3D
    unsigned char nLoop; // 0x3E
    unsigned char nFadeIn; // 0x3F
    unsigned char nFadeOut; // 0x40
    unsigned char bDeferInst; // 0x41
    unsigned char bStopInst; // 0x42
    unsigned short nDuration; // 0x43
    short nCompound; // 0x45
    int nFalloff; // 0x47
    unsigned char bReverb; // 0x4B
    char bCache; // 0x4C
    unsigned char bAsyncOnly; // 0x4D
    unsigned char nPriority; // 0x4E
    unsigned char bStream; // 0x4F
    unsigned char bStereo; // 0x50
    unsigned char bTracking; // 0x51
    unsigned char bSolo; // 0x52
    unsigned char bMusicVol; // 0x53
    int nBlock[3]; // 0x54
    int nGroupStart; // 0x60
    int anRecent[2]; // 0x64
    void* pData; // 0x6C
    unsigned int nSize; // 0x70
    int unk0x74[2]; // 0x74
    int dwLastUse; // 0x7C
    unsigned char nBlocks; // 0x80
    char bFailed; // 0x81
    AsyncData* pAsync; // 0x82
    int nState; // 0x86
    unsigned int nRefCount; // 0x8A
};

#pragma pack(pop)

struct D2SoundUnitNodeStrc
{
    D2UnitStrc* pUnit; // 0x00
    D2SoundUnitNodeStrc* pNext; // 0x04
};

D2_CHECK_SIZE(D2SoundsTxt, 0x8E);

void __fastcall SOUNDHDR_SetCacheMax(unsigned int nMax); // 0x00481840
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nIndex); // 0x00481860
int __fastcall SOUNDHDR_GetGroupStart(int nIndex); // 0x00481890
unsigned char __fastcall SOUNDHDR_GetGroupSize(int nIndex); // 0x004818C0
int __fastcall SOUNDHDR_GetLoopFlag(int nIndex); // 0x004818F0
void __cdecl SOUNDHDR_LoadSoundTables(); // 0x00481950
void __fastcall SOUNDHDR_UpdateSoundSystem(int nArg); // 0x00482260
void __fastcall SOUNDHDR_AddVariantRefs(int nIndex, int nDelta); // 0x004822B0
void __fastcall SOUNDHDR_ClearVariantRefs(int nIndex); // 0x00482370
void __fastcall SOUNDHDR_ReleaseCacheEntry(int nIndex); // 0x004823E0
float __fastcall SOUNDHDR_GetFalloffVolume(int nIndex); // 0x004825B0
float __fastcall SOUNDHDR_GetFalloffRange(int nIndex); // 0x00482610
int __fastcall SOUNDHDR_PickVariant(int nIndex); // 0x00482680
void __fastcall SOUNDHDR_GetSoundPath(int nIndex, char* szPath); // 0x00482710
void __fastcall SOUNDHDR_TouchCacheEntry(int nIndex); // 0x00482860
void __cdecl SOUNDHDR_ReleaseSoundTables(); // 0x004828B0
void __cdecl SOUNDHDR_ShutdownSound(); // 0x00482940
void __fastcall SOUNDHDR_LoadCacheEntry(int nIndex, int bDirect, int nArg); // 0x00482970
void __fastcall SOUNDHDR_UpdateCache(unsigned int nTick); // 0x00482B40
