#include "D2Sound.h"
#include "D2SysTypes.h"

#include "D2GfxTypes.h"

#include "D2Win32Base.h"

#include "D2DDrawTypes.h"

#include "D2GlideTypes.h"

#include "D2GameTypes.h"

#include "D2SoundTypes.h"

struct D2SoundStrc;

int __cdecl D2SOUNDSMP_GetMasterVolume();                                                                  // 0x00515D60

int __fastcall D2SOUNDSMP_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30

void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound);                                                // 0x00516140

void __fastcall D2SOUNDSMP_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0

int __fastcall D2SOUNDSMP_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70

void __fastcall D2SOUNDSMP_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0

D2SoundStrc* gpSoundChannel;                                                                       // 0x00881794

extern int gnMasterVolume;                                                                              // 0x008817B0

extern int gnPositionalBias;                                                                              // 0x008817B8

D2SoundStrc* gapWaveSlots[8]; // 0x008817DC

int gbWaveSlotsInit; // 0x008817FC

struct D2DSoundBufferStrc;

struct D2DSound3DBufferStrc;

struct D2KsPropertySetStrc;

struct D2ComObjectStrc;

struct D2WaveFormatStrc;

struct D2SoundWaveStrc;

struct D2WaveStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl D2SOUND_ReleaseSoundObjects(); // 0x00513AF0

int __cdecl D2SOUND_GetDirectSound(); // 0x00513B50

void __cdecl D2SOUND_DestroyStreamChannel(); // 0x005147B0

void __cdecl D2SOUND_ClearChannelTable(); // 0x00514860

void __cdecl D2SOUNDSMP_StopSoundThread(); // 0x00515120

D2SoundStrc* __fastcall D2SOUNDSMP_CreateSound(unsigned int nFlags, int nValue); // 0x00515530

int __fastcall D2SOUNDSMP_GetSoundPlayingFlag(D2SoundStrc* pSound); // 0x00515710

void __fastcall D2SOUNDSMP_StartSoundFade(D2SoundStrc* pFade, int nTarget, int nDuration); // 0x00515C60

void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern D2ComObjectStrc* gpSoundObject; // 0x00881748

extern D2CriticalSectionStrc gtSoundLock; // 0x0088174C

extern D2ComObjectStrc* gpDirectSound; // 0x00881768

extern int gbSoundLockInit; // 0x0088177C

D2CriticalSectionStrc gtWaveLock; // 0x008817C4

struct D2SoundWaveStrc
{
    char szName[0x50];
    void* pFile;
    unsigned int nFileSize;
    int f_58;
    D2SoundWaveStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

void* __fastcall D2SOUNDSMP_ReadWaveHeader(const void* pFile, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

extern D2SoundWaveStrc* gpSoundWaveList_00881800; // 0x00881800

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

int __fastcall D2SOUNDSMP_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize); // 0x005155D0

int __fastcall D2SOUNDSMP_PlaySound(D2SoundStrc* pSound); // 0x005156A0

extern D2WaveStrc* gpWaveList; // 0x00881800

int gnChannelValue; // 0x00881798

int gbChannelFlag; // 0x0088179C

void __fastcall D2SOUNDSMP_DestroySound(D2SoundStrc* pSound); // 0x005160D0

extern int gdwGlobal_00881798; // 0x00881798

// 0x00514DB0
void __cdecl D2SOUNDFAST_InitWaveSlots()
{
    if (D2SOUND_GetDirectSound() && !gbWaveSlotsInit)
    {
        InitializeCriticalSection(&gtWaveLock);
        D2SOUNDSMP_SetMasterVolume(0xFF);
        for (int i = 0; i < 8; ++i)
            gapWaveSlots[i] = D2SOUNDSMP_CreateSound(i < 4, 0);
        gbWaveSlotsInit = 1;
    }
}

extern int gdwGlobal_008817FC; // 0x008817FC

// 0x00515060
int __cdecl D2SOUNDFAST_AreWaveSlotsInitialized()
{
    return gdwGlobal_008817FC;
}

// 0x00515070
void __cdecl D2SOUNDFAST_FreeWaveSlots()
{
    if (!gbWaveSlotsInit)
        return;
    for (int i = 0; i < 8; ++i)
        D2SOUNDSMP_StopSound(gapWaveSlots[i]);
    for (int i = 0; i < 8; ++i)
    {
        D2SOUNDSMP_DestroySound(gapWaveSlots[i]);
        gapWaveSlots[i] = 0;
    }
    while (gpWaveList)
    {
        D2WaveStrc* pNext = gpWaveList->pNext;
        void* pData = gpWaveList->pData;
        if (pData)
            FOG_Free(pData, ".\\Src\\D2SoundFast.cpp", 0x62, 0);
        FOG_Free(gpWaveList, ".\\Src\\D2SoundFast.cpp", 0x63, 0);
        gpWaveList = pNext;
    }
    gbWaveSlotsInit = 0;
    DeleteCriticalSection(&gtWaveLock);
}

// 0x00514E10
void __fastcall D2SOUNDFAST_PreloadWave(const char* szName)
{
    if (!gbWaveSlotsInit)
        return;
    unsigned int nFileSize;
    void* pFile = ARCHIVE_AllocateBufferAndReadFile(0, szName, &nFileSize, ".\\Src\\D2SoundFast.cpp", 0x77);
    if (!pFile)
        return;
    unsigned int nWaveSize = nFileSize;
    D2WaveFormatStrc tFormat;
    D2SOUNDSMP_ReadWaveHeader(pFile, &nWaveSize, &tFormat);
    if (tFormat.nSamplesPerSec != 22050)
        return;
    D2SoundWaveStrc* pWave = (D2SoundWaveStrc*)FOG_Alloc(sizeof(D2SoundWaveStrc), ".\\Src\\D2SoundFast.cpp", 0x85, 0);
    pWave->pNext = gpSoundWaveList_00881800;
    pWave->pFile = pFile;
    pWave->nFileSize = nFileSize;
    gpSoundWaveList_00881800 = pWave;
    pWave->f_58 = tFormat.nChannels == 2;
    strcpy(pWave->szName, szName);
}

// 0x00514EC0
void __fastcall D2SOUND_10039(const char* szName)
{
    if (!gbWaveSlotsInit)
        return;

    EnterCriticalSection(&gtWaveLock);

    D2WaveStrc* pWave = gpWaveList;
    if (gpWaveList)
    {
        int bFound = 0;
        for (; pWave; pWave = pWave->pNext)
        {
            if (!strcmp(pWave->szName, szName))
            {
                bFound = 1;
                break;
            }
        }

        if (bFound)
        {
        int i;
        for (i = 0; i < 8; ++i)
        {
            if (gapWaveSlots[i]->dwFlags == pWave->nType && !D2SOUNDSMP_GetSoundPlayingFlag(gapWaveSlots[i]))
                break;
        }

        if (i < 8)
        {
            D2SoundStrc* pSound = gapWaveSlots[i];
            D2SOUNDSMP_ResetSound(pSound);
            D2SOUNDSMP_SetSoundData(pSound, pWave->pData, pWave->nSize);
            D2SOUNDSMP_SetSoundVolume(pSound, 0xFF);
            D2SOUNDSMP_PlaySound(pSound);
        }
        }
    }

    LeaveCriticalSection(&gtWaveLock);
}

// 0x00514FB0
int __cdecl D2SOUNDFAST_IsAnyWavePlaying()
{
    if (!gbWaveSlotsInit)
        return 0;
    for (int i = 0; i < 8; ++i)
    {
        if (D2SOUNDSMP_GetSoundPlayingFlag(gapWaveSlots[i]))
            return 1;
    }
    return 0;
}

// 0x00514FF0
void __cdecl D2SOUNDFAST_StopAllWaves()
{
    if (gbWaveSlotsInit)
    {
        for (int i = 0; i < 8; ++i)
        {
            D2SOUNDSMP_StopSound(gapWaveSlots[i]);
        }
    }
}

// 0x00515020
void __cdecl D2SOUNDFAST_FadeOutWaves()
{
    if (gbWaveSlotsInit)
    {
        for (int i = 0; i < 8; ++i)
        {
            if (D2SOUNDSMP_GetSoundPlayingFlag(gapWaveSlots[i]))
                D2SOUNDSMP_StartSoundFade(gapWaveSlots[i], 0, 200);
        }
    }
}

#include "gen/data/Source/D2Sound/Src/D2SoundFast.inc"
