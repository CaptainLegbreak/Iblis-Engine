#include "D2Client.h"
#include "D2Records.h"
#include "D2ClientSound.h"
#include "D2SoundEnvironTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BinFileStrc;

struct D2BinFieldStrc;

struct D2SoundEnvironTxtStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall ITEM_QueryCacheAddress(D2SoundsTxt* pEntry); // 0x004DF630

void __fastcall SOUNDHDR_TouchCacheEntry(int nIndex); // 0x00482860

int __stdcall INV_FreeCacheEntries(unsigned int nFree, int bTwoPasses, int bCheckAge); // 0x004824A0

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

void __cdecl sub_004DF800(); // 0x004DF800

void __cdecl SOUNDINST_FreeAllSounds(); // 0x004B9D20

void __cdecl sub_004E00C0_CloseSoundChannels(); // 0x004E00C0

void __cdecl SOUNDHDR_ReleaseSoundTables(); // 0x004828B0

extern int gdwSoundTick; // 0x007BC9BC

unsigned int gnCacheMax; // 0x007BC9CC

unsigned int gdwCacheUsed; // 0x007BC9D0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079

void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0

int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0

D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize); // 0x006BD640

void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780

unsigned int gnCacheLastTick; // 0x007BC9C0

unsigned int gnCacheLastLoadTick; // 0x007BC9C4

unsigned int gnCacheLoading; // 0x007BC9C8

void __fastcall SOUNDHDR_LoadCacheEntry(int nIndex, int bDirect, int nArg); // 0x00482970

struct D2SlotStrc;

#define OFFSET(T, M) ((unsigned int)&(((T*)0)->M))

struct D2ClientCacheNodeStrc;

struct PlayerNode;

struct PlayerListHead;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" unsigned int __cdecl strlen(const char* szString);

void __cdecl SOUNDHDR_LoadSoundTables(); // 0x00481950

void __fastcall sub_004E0050_RestartSound(int nArg); // 0x004E0050

extern "C" void __cdecl SOUNDINST_ResetSoundState(); // 0x004B9D00

void __cdecl SKILLS_ResetLevelSpeech(); // 0x004CA280

D2SlotStrc* __fastcall SoundChannelFind(int nOwner); // 0x004DF9D0

void __fastcall D2SOUNDUTIL_ListRemove(D2ClientCacheNodeStrc** ppList, int nId); // 0x00516980

void __fastcall D2SOUNDUTIL_ListAddTail(D2ClientCacheNodeStrc** ppList, int nId); // 0x00516A70

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

typedef char NodeFlags[(OFFSET(PlayerNode, flags) == 4) ? 1 : -1];

typedef char NodeNext[(OFFSET(PlayerNode, next) == 8) ? 1 : -1];

extern const char gPlayerListFile[];

extern int gTextY;

extern int gTextRight;

PlayerListHead* __fastcall ROSTER_GetRosterInfoList(int playerId); // 0x0047A310

void* __fastcall Allocate(unsigned int bytes, const char* file, int line, unsigned int flags);

void __fastcall SOUNDHDR_ReleaseCacheEntry(int nIndex); // 0x004823E0

void* __cdecl sub_004646A0();

int __stdcall DUNGEON_GetLevelIdFromRoom(void* room);

const unsigned short* __fastcall UI_GetLevelName(int levelId); // 0x00453E70

int __fastcall D2Win_10121_GetTextWidth(const unsigned short* text); // 0x00501820

void __fastcall D2Win_10117_DrawText(const unsigned short* text, int x, int y, int color, int mode); // 0x00502320

D2ClientCacheNodeStrc* gpCacheList; // 0x007BC9B8

static int gnClientSoundsTxtRecordCount; // 0x007BC9A4

int* gpSongTable; // 0x007BC99C

static D2SoundsTxt* sgptSoundHeaderTable; // 0x007BC9A0

D2SoundEnvironTxtStrc* sgptSoundEnvironTable; // 0x007BC9A8

int gnSoundEnvironTxtRecordCount; // 0x007BC9AC

static int gnSongMax; // 0x007BC9B4

static int gnSongMin; // 0x007BC9B0

// 0x00481720
static void SOUNDHDR_FinishCacheLoad(D2SoundsTxt* pEntry)
{
    D2_ASSERT(pEntry->nState == 1, 0x40);
    pEntry->pData = sub_0040A9E0(pEntry->pAsync);
    pEntry->nSize = sub_0040AA40(pEntry->pAsync);
    pEntry->nState = 2;
    ITEM_QueryCacheAddress(pEntry);
    gnCacheLoading -= 1;
}

extern int gdwGlobal_007BC9B0; // 0x007BC9B0

extern int gdwGlobal_007BC9B4; // 0x007BC9B4

extern int gdwGlobal_007BC99C; // 0x007BC99C



// 0x004817D0
int __cdecl sub_004817D0()
{
    return gdwGlobal_007BC9A4;
}

// 0x004817E0
int __cdecl sub_004817E0()
{
    return gdwGlobal_007BC9AC;
}

// 0x004817F0
int __cdecl sub_004817F0()
{
    return gdwGlobal_007BC9B0;
}

// 0x00481800
int __cdecl sub_00481800()
{
    return gdwGlobal_007BC9B4;
}

// 0x00481810
int __cdecl sub_00481810()
{
    return gdwGlobal_007BC99C;
}

// 0x00481820
int __cdecl DLIGHTMAP_GetSoundTick()
{
    return gdwSoundTick;
}

// 0x00481860
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nIndex)
{
    if (sgptSoundHeaderTable && nIndex >= 0 && nIndex < gnClientSoundsTxtRecordCount)
        return &sgptSoundHeaderTable[nIndex];
    return 0;
}

// 0x00481890
int __fastcall SOUNDHDR_GetGroupStart(int nIndex)
{
    if (!sgptSoundHeaderTable)
        return 0;
    return SOUNDHDR_GetSoundRecord(nIndex)->nGroupStart;
}

// 0x004818C0
unsigned char __fastcall SOUNDHDR_GetGroupSize(int nIndex)
{
    if (!sgptSoundHeaderTable)
        return 0;
    return SOUNDHDR_GetSoundRecord(nIndex)->nGroupSize;
}

// 0x004818F0
int __fastcall SOUNDHDR_GetLoopFlag(int nIndex)
{
    if (!sgptSoundHeaderTable)
        return 0;
    return SOUNDHDR_GetSoundRecord(nIndex)->nLoop;
}


// 0x00481920
D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId)
{
    if (sgptSoundEnvironTable && nEnvironId >= 0 && nEnvironId < gdwGlobal_007BC9AC)
    {
        return &sgptSoundEnvironTable[nEnvironId];
    }
    return 0;
}


// 0x00481950
void __cdecl SOUNDHDR_LoadSoundTables()
{
    D2BinFieldStrc pTbl2[] =
    {
        { "Filename", 1, 59, 0, 0 },
        { "Volume", 4, 0, 60, 0 },
        { "Group Size", 4, 0, 61, 0 },
        { "Loop", 4, 0, 62, 0 },
        { "Fade In", 4, 0, 63, 0 },
        { "Fade Out", 4, 0, 64, 0 },
        { "Defer Inst", 4, 0, 65, 0 },
        { "Stop Inst", 4, 0, 66, 0 },
        { "Duration", 3, 0, 67, 0 },
        { "Compound", 3, 0, 69, 0 },
        { "Falloff", 2, 0, 71, 0 },
        { "Reverb", 4, 0, 75, 0 },
        { "Cache", 4, 0, 76, 0 },
        { "Async Only", 4, 0, 77, 0 },
        { "Priority", 4, 0, 78, 0 },
        { "Stream", 4, 0, 79, 0 },
        { "Stereo", 4, 0, 80, 0 },
        { "Tracking", 4, 0, 81, 0 },
        { "Solo", 4, 0, 82, 0 },
        { "Music Vol", 4, 0, 83, 0 },
        { "Block 1", 2, 0, 84, 0 },
        { "Block 2", 2, 0, 88, 0 },
        { "Block 3", 2, 0, 92, 0 },
        { "end", 0, 0, 0, 0 },
    };

    D2BinFieldStrc pTbl[] =
    {
        { "Song", 2, 0, 0, 0 },
        { "Day Ambience", 2, 0, 4, 0 },
        { "Night Ambience", 2, 0, 8, 0 },
        { "Day Event", 2, 0, 12, 0 },
        { "Night Event", 2, 0, 16, 0 },
        { "Event Delay", 2, 0, 20, 0 },
        { "Indoors", 4, 0, 24, 0 },
        { "Material 1", 2, 0, 28, 0 },
        { "Material 2", 2, 0, 32, 0 },
        { "EAX Environ", 2, 0, 36, 0 },
        { "EAX Env Size", 2, 0, 40, 0 },
        { "EAX Env Diff", 2, 0, 44, 0 },
        { "EAX Room Vol", 2, 0, 48, 0 },
        { "EAX Room HF", 2, 0, 52, 0 },
        { "EAX Decay Time", 2, 0, 56, 0 },
        { "EAX Decay HF", 2, 0, 60, 0 },
        { "EAX Reflect", 2, 0, 64, 0 },
        { "EAX Reflect Delay", 2, 0, 68, 0 },
        { "EAX Reverb", 2, 0, 72, 0 },
        { "EAX Rev Delay", 2, 0, 76, 0 },
        { "EAX Room Roll", 2, 0, 80, 0 },
        { "EAX Air Absorb", 2, 0, 84, 0 },
        { "end", 0, 0, 0, 0 },
    };

    D2_ASSERT(!sgptSoundHeaderTable, 0xFC);
    D2_ASSERT(!sgptSoundEnvironTable, 0xFD);

    char szPath[260];
    int nSize;
    wsprintfA(szPath, "%s\\sounds.txt", "DATA\\GLOBAL\\EXCEL");
    void* pData = sub_00517079(D2Win_GetArchive(), szPath, &nSize, ".\\Sound\\SoundHdr.cpp", 0x101);
    D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nSize);
    gnClientSoundsTxtRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
    D2SoundsTxt* pSounds = (D2SoundsTxt*)FOG_Alloc(gnClientSoundsTxtRecordCount * sizeof(D2SoundsTxt), ".\\Sound\\SoundHdr.cpp", 0x106, 0);
    sgptSoundHeaderTable = pSounds;
    memset(pSounds, 0, gnClientSoundsTxtRecordCount * sizeof(D2SoundsTxt));
    FOG_10207(pBinFile, pTbl2, pSounds, gnClientSoundsTxtRecordCount, sizeof(D2SoundsTxt));
    FOG_FreeBinFile(pBinFile);

    wsprintfA(szPath, "%s\\soundenviron.txt", "DATA\\GLOBAL\\EXCEL");
    pData = sub_00517079(D2Win_GetArchive(), szPath, &nSize, ".\\Sound\\SoundHdr.cpp", 0x10D);
    pBinFile = FOG_CreateBinFile(pData, nSize);
    gnSoundEnvironTxtRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
    D2SoundEnvironTxtStrc* pSoundEnviron = (D2SoundEnvironTxtStrc*)FOG_Alloc(gnSoundEnvironTxtRecordCount * sizeof(D2SoundEnvironTxtStrc), ".\\Sound\\SoundHdr.cpp", 0x112, 0);
    sgptSoundEnvironTable = pSoundEnviron;
    memset(pSoundEnviron, 0, gnSoundEnvironTxtRecordCount * sizeof(D2SoundEnvironTxtStrc));
    FOG_10207(pBinFile, pTbl, pSoundEnviron, gnSoundEnvironTxtRecordCount, sizeof(D2SoundEnvironTxtStrc));
    FOG_FreeBinFile(pBinFile);

    int nGroupStart = 0;
    int nGroupSize = 1;
    for (int i = 1; i < gnClientSoundsTxtRecordCount; ++i)
    {
        D2SoundsTxt* pSound = &sgptSoundHeaderTable[i];
        if (nGroupStart && i >= nGroupStart && i < nGroupSize + nGroupStart)
            pSound->nGroupStart = nGroupStart;
        else
            pSound->nGroupStart = i;

        if (pSound->nGroupSize)
        {
            nGroupStart = i;
            nGroupSize = pSound->nGroupSize;
        }
        else
        {
            pSound->nGroupSize = 1;
        }

        unsigned char nBlocks;
        for (nBlocks = 0; nBlocks < 3; ++nBlocks)
        {
            if (pSound->nBlock[nBlocks] == -1)
                break;
        }
        pSound->nBlocks = nBlocks;
    }

    D2SoundEnvironTxtStrc* pEnv = sgptSoundEnvironTable;
    gnSongMin = gnClientSoundsTxtRecordCount;
    gnSongMax = 0;
    for (int j = 0; j < gnSoundEnvironTxtRecordCount; ++j, ++pEnv)
    {
        const int nSong = pEnv->nSong;
        if (nSong > 0)
        {
            if (nSong < gnSongMin)
                gnSongMin = nSong;
            int nNewMax = gnSongMax;
            if (nSong > nNewMax)
                nNewMax = nSong;
            gnSongMax = nNewMax;
        }
    }

    const int nSongCount = gnSongMax - gnSongMin + 1;
    gpSongTable = (int*)FOG_Alloc(nSongCount * sizeof(int), ".\\Sound\\SoundHdr.cpp", 0x147, 0);
    memset(gpSongTable, 0, nSongCount * sizeof(int));
}


int __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                                       // 0x004DF9D0

// 0x004824A0
int __stdcall INV_FreeCacheEntries(unsigned int nFree, int bTwoPasses, int bCheckAge)
{
    const unsigned int nTarget = gdwCacheUsed - nFree;
    const unsigned int dwNow = gdwSoundTick;
    while (gdwCacheUsed > nTarget)
    {
        int bFreed = 0;
        int nPass = 0;
        do
        {
            for (D2ClientCacheNodeStrc* pNode = gpCacheList; pNode; pNode = pNode->pNext)
            {
                const int nId = pNode->nId;
                D2SoundsTxt* pEntry = (sgptSoundHeaderTable && nId >= 0 && nId < gnClientSoundsTxtRecordCount) ? &sgptSoundHeaderTable[nId] : 0;
                if (nPass == 0 && (pEntry->nRefCount || pEntry->bCache))
                {
                    continue;
                }
                if (bCheckAge && dwNow - (unsigned int)pEntry->dwLastUse < 750)
                {
                    continue;
                }
                if (!sub_004DF9D0_CheckCacheEntry(nId))
                {
                    SOUNDHDR_ReleaseCacheEntry(nId);
                    bFreed = 1;
                    break;
                }
            }
            if (!bTwoPasses)
            {
                break;
            }
            ++nPass;
        }
        while (nPass <= 1);

        if (!bFreed)
        {
            return 0;
        }
    }
    return 1;
}

// 0x004828B0
void __cdecl SOUNDHDR_ReleaseSoundTables()
{
    if (sgptSoundEnvironTable)
    {
        FOG_Free(sgptSoundEnvironTable, ".\\Sound\\SoundHdr.cpp", 385, 0);
        sgptSoundEnvironTable = 0;
        gnSoundEnvironTxtRecordCount = 0;
    }
    if (sgptSoundHeaderTable)
    {
        for (int index = 1; index < gnClientSoundsTxtRecordCount; index += 1)
            SOUNDHDR_ReleaseCacheEntry(index);
        FOG_Free(sgptSoundHeaderTable, ".\\Sound\\SoundHdr.cpp", 398, 0);
        sgptSoundHeaderTable = 0;
        gnClientSoundsTxtRecordCount = 0;
    }
    gnSongMin = 0;
    gnSongMax = 0;
}

// 0x00482710
void __fastcall SOUNDHDR_GetSoundPath(int nIndex, char* szPath)
{
    D2SoundsTxt* pEntry = SOUNDHDR_GetSoundRecord(nIndex);
    if (nIndex >= 0xB76 && nIndex <= 0xB76 + 0x6BA)
        strcpy(szPath, "DATA\\LOCAL");
    else
        strcpy(szPath, "DATA\\GLOBAL");

    if (nIndex >= 0x1231 && nIndex <= 0x1231 + 0x29)
        strcat(szPath, "\\MUSIC\\");
    else
        strcat(szPath, "\\SFX\\");

    D2_ASSERT(strlen(szPath) + strlen(pEntry->szFilename) < 0x50, 0x3AB);
    strcat(szPath, pEntry->szFilename);
}

// 0x00482260
void __fastcall SOUNDHDR_UpdateSoundSystem(int nArg)
{
// build: symbol ?D2SOUND_GetDirectSound@* 0x00513B50
    if (!D2SOUND_GetDirectSound())
        return;
    SOUNDHDR_LoadSoundTables();
    sub_004E0050_RestartSound(nArg);
    SOUNDINST_ResetSoundState();
    sub_004DCA30();
    SKILLS_ResetLevelSpeech();
// build: symbol ?D2SOUNDSMP_SetMasterVolume@* 0x00515CE0
    D2SOUNDSMP_SetMasterVolume(0xFF);
    gdwSoundTick = 0;
    gnCacheLastTick = 0;
    gnCacheLastLoadTick = 0;
    gnCacheLoading = 0;
}

// 0x00482940
void __cdecl SOUNDHDR_ShutdownSound()
{
    if (!D2SOUND_GetDirectSound())
        return;
    sub_004DF800();
    sub_004BAAB0();
    SOUNDINST_FreeAllSounds();
    sub_004E00C0_CloseSoundChannels();
    SOUNDHDR_ReleaseSoundTables();
}

// 0x004822B0
void __fastcall SOUNDHDR_AddVariantRefs(int nIndex, int nDelta)
{
    if (!nIndex)
        return;
    D2SoundsTxt* pEntry = SOUNDHDR_GetSoundRecord(nIndex);
    if (!pEntry)
        return;
    if (!pEntry->nRefCount && nDelta == -1)
        return;
    for (int i = pEntry->nGroupStart; i < pEntry->nGroupStart + pEntry->nGroupSize; i++)
    {
        D2SoundsTxt* pVariant = SOUNDHDR_GetSoundRecord(i);
        D2_ASSERT(pVariant->nRefCount > 0 || nDelta != -1, 0x1DC);
        pVariant->nRefCount += nDelta;
    }
}

// 0x00482370
void __fastcall SOUNDHDR_ClearVariantRefs(int nIndex)
{
    if (!nIndex)
        return;
    D2SoundsTxt* pEntry = SOUNDHDR_GetSoundRecord(nIndex);
    if (!pEntry)
        return;
    for (int i = pEntry->nGroupStart; i < pEntry->nGroupStart + pEntry->nGroupSize; i++)
        SOUNDHDR_GetSoundRecord(i)->nRefCount = 0;
}

// 0x004823E0
void __fastcall SOUNDHDR_ReleaseCacheEntry(int nIndex)
{
    D2SoundsTxt* pEntry = SOUNDHDR_GetSoundRecord(nIndex);
    if (!pEntry->nState)
        return;
    if (SoundChannelFind(nIndex))
    {
        FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), 0x259);
        exit(-1);
    }
    gdwCacheUsed -= pEntry->nSize;
    D2SOUNDUTIL_ListRemove(&gpCacheList, nIndex);
    pEntry->dwLastUse = 0;
    if (pEntry->pAsync)
    {
        sub_0040AB00_FreeAsyncData(pEntry->pAsync);
        pEntry->pAsync = 0;
        pEntry->nState = 0;
        pEntry->pData = 0;
        return;
    }
    FOG_Free(pEntry->pData, ".\\Sound\\SoundHdr.cpp", 0x272, 0);
    pEntry->nState = 0;
    pEntry->pData = 0;
}

// 0x004825B0
float __fastcall SOUNDHDR_GetFalloffVolume(int nIndex)
{
    switch (SOUNDHDR_GetSoundRecord(nIndex)->nFalloff)
    {
    case 0:
        return 60.0f;
    case 1:
        return 60.0f;
    case 2:
        return 200.0f;
    case 3:
        return 400.0f;
    case 4:
        return 2000.0f;
    }
    return 60.0f;
}

// 0x00482610
float __fastcall SOUNDHDR_GetFalloffRange(int nIndex)
{
    switch (SOUNDHDR_GetSoundRecord(nIndex)->nFalloff)
    {
    case 0:
        return 400.0f;
    case 2:
        return 1000.0f;
    case 3:
        return 1500.0f;
    case 4:
        return 2000.0f;
    default:
        return 700.0f;
    }
}

// 0x00482680
int __fastcall SOUNDHDR_PickVariant(int nIndex)
{
    if (!sgptSoundHeaderTable)
        return nIndex;
    D2SoundsTxt* pEntry = SOUNDHDR_GetSoundRecord(nIndex);
    const unsigned char nVariants = pEntry->nGroupSize;
    if (nVariants <= 1)
        return nIndex;

    int nRecent = nVariants - 1 < 2 ? nVariants - 1 : 2;
    if (nVariants <= 3 && !sub_004E40A0(nVariants + 1))
        --nRecent;

    for (;;)
    {
        const int nResult = sub_004E40A0(pEntry->nGroupSize) + nIndex;
        bool bFound = false;
        for (int i = 0; i < nRecent; i++)
        {
            if (nResult == pEntry->anRecent[i])
            {
                bFound = true;
                break;
            }
        }
        if (!bFound)
            return nResult;
    }
}

// 0x00482860
void __fastcall SOUNDHDR_TouchCacheEntry(int nIndex)
{
    SOUNDHDR_GetSoundRecord(nIndex)->dwLastUse = gdwSoundTick;
    D2SOUNDUTIL_ListRemove(&gpCacheList, nIndex);
    D2SOUNDUTIL_ListAddTail(&gpCacheList, nIndex);
}

// 0x00481840
void __fastcall SOUNDHDR_SetCacheMax(unsigned int nMax)
{
    gnCacheMax = nMax;
}

// 0x00481850
void __cdecl sub_00481850()
{
}

// 0x00482970
void __fastcall SOUNDHDR_LoadCacheEntry(int nIndex, int bDirect, int nArg)
{
    D2SoundsTxt* pEntry;
    if (sgptSoundHeaderTable && nIndex >= 0 && nIndex < gnClientSoundsTxtRecordCount)
        pEntry = &sgptSoundHeaderTable[nIndex];
    else
        pEntry = 0;

    const int nSaved = gdwSoundTick;
    if (pEntry->bFailed)
        return;

    if (pEntry->nState == 2)
        return;
    if (pEntry->nState == 1 && !bDirect)
        return;
    if (pEntry->nState == 1 && bDirect)
    {
        SOUNDHDR_FinishCacheLoad(pEntry);
        return;
    }
    if (pEntry->nState)
        return;

    char szPath[0x50];
    void* hFile;
    sub_00482710(nIndex, szPath);
// build: symbol ?FOG_FOpenFile@* 0x004068E0
    if (!FOG_FOpenFile(szPath, &hFile))
    {
        pEntry->bFailed = 1;
        return;
    }

// build: symbol ?FOG_FGetFileSize@* 0x00406930
    const unsigned int nSize = FOG_FGetFileSize(hFile, 0);
// build: symbol ?FOG_FCloseFile@* 0x004068F0
    FOG_FCloseFile(hFile);
    if (gdwCacheUsed + nSize > gnCacheMax)
    {
        const unsigned int nFree = gdwCacheUsed - gnCacheMax + nSize;
        if (!INV_FreeCacheEntries(nFree, bDirect, nArg))
        {
            gnCacheLastLoadTick = nSaved;
            return;
        }
    }

    if (bDirect)
    {
        pEntry->pData = ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szPath, &pEntry->nSize, ".\\Sound\\SoundHdr.cpp", 0x301);
        D2_ASSERT(pEntry->pData && pEntry->nSize, 0x302);
        gdwCacheUsed += pEntry->nSize;
        SOUNDHDR_TouchCacheEntry(nIndex);
        pEntry->nState = 2;
        ITEM_QueryCacheAddress(pEntry);
        return;
    }

    pEntry->pAsync = sub_0040A620(0, szPath, 1, 0, -1, 0, 0, -2, ".\\Sound\\SoundHdr.cpp", 0x31B);
    if (pEntry->pAsync)
    {
        const unsigned int nAsyncSize = sub_0040AA40(pEntry->pAsync);
        gdwCacheUsed += nAsyncSize;
        pEntry->nSize = nAsyncSize;
        SOUNDHDR_TouchCacheEntry(nIndex);
        gnCacheLoading += 1;
        pEntry->nState = 1;
    }
}

// 0x00482B40
void __fastcall SOUNDHDR_UpdateCache(unsigned int nTick)
{
    if (!sgptSoundHeaderTable)
        return;

    const int bForce = nTick == 0;
    if (nTick && nTick - gnCacheLastTick < 0x19)
        return;

    for (int i = 1; i <= 0xB75; i++)
    {
        D2SoundsTxt* pEntry = &sgptSoundHeaderTable[i];
        if (!pEntry->nState && (pEntry->nRefCount || pEntry->bCache))
        {
            if (!bForce)
            {
                if (gnCacheLoading >= 0xF)
                    continue;
                if (nTick - gnCacheLastLoadTick < 0xFA)
                    continue;
            }
            SOUNDHDR_LoadCacheEntry(i, bForce, 1);
        }
        if (pEntry->nState == 1 && sub_0040A7F0_AsyncDataCheck(pEntry->pAsync))
            SOUNDHDR_FinishCacheLoad(pEntry);
    }
    gnCacheLastTick = nTick;
}


extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

void __fastcall sub_004BA020(unsigned int nTick); // 0x004BA020

void __fastcall sub_004DCAA0_UpdateLevelSong(unsigned int nTick); // 0x004DCAA0

int __cdecl sub_004DF870(); // 0x004DF870

void __cdecl sub_004DF890(); // 0x004DF890

void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int nTick); // 0x004E42E0


// 0x00482C20
void __cdecl SOUNDHDR_TickSound()
{
    if (sub_004DF870())
    {
        SKILLDESC_UpdateEnvironSounds(gdwSoundTick);
        sub_004DCAA0_UpdateLevelSong(gdwSoundTick);
        SOUNDHDR_UpdateCache(gdwSoundTick);
        sub_004BA020(gdwSoundTick);
        sub_004DF890();
        ++gdwSoundTick;
        Sleep(0);
    }
}

#include "gen/data/Source/D2Client/Sound/SoundHdr.inc"
