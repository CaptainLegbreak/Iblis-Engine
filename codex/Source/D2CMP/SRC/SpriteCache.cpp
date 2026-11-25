#include "D2CMP.h"

#include "D2CmpTiles.h"

#include "D2CmpCelFile.h"

#include "D2GameTypes.h"

#include "D2WinTypes.h"

#include "D2CmpTypes.h"

#include "D2CmpCache.h"

#include "D2SpriteCache.h"

#include "D2FogSystemInfo.h"

#pragma intrinsic(strcpy)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2CMP_BITCOUNT_BX(x) ((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))

#define D2CMP_BITCOUNT(x) (((D2CMP_BITCOUNT_BX(x) + (D2CMP_BITCOUNT_BX(x) >> 4)) & 0x0F0F0F0F) % 255)

#define APPEND_CODE(q, dw) \
    if ((char)(dw) != 0x20) { *q++ = (char)(dw); \
        if ((char)((dw) >> 8) != 0x20) { *q++ = (char)((dw) >> 8); \
            if ((char)((dw) >> 16) != 0x20) { *q++ = (char)((dw) >> 16); } } }

struct D2SpriteCacheNodeStrc;

struct D2TileLibraryHeaderStrc;

struct D2CriticalSectionStrc;

struct D2SpriteCacheStrc;

struct D2CmpCacheKeyStrc;

struct D2CmpCacheListEntryStrc;

struct D2CmpCelContextStrc;

struct D2TileListHeaderStrc;

struct D2CmpTileStrc;

struct D2CmpTileBlockStrc;

struct D2CmpTileLibraryStrc;

struct D2CmpBlockTableAStrc;

struct D2CmpValueObjStrc;

struct D2SpriteCacheLockStrc;

struct D2SpriteFileStrc;

struct D2SpriteEntryStrc;

struct D2SpriteLoadRequestStrc;

struct D2FogSystemInfoStrc;

struct D2CelBlockStrc;

struct AsyncData;

struct D2CmpPoolStrc;

struct D2CmpSpriteContextStrc;

struct D2CmpSpriteFileStrc;

struct D2CmpDC6CelStrc;

struct D2CmpSpriteEntryStrc;

struct D2CmpDC6FrameStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask); // 0x00517ABB

extern D2CmpPoolStrc gCmpPool; // 0x0088CAE0

extern void* gpfnTileFreeCallback; // 0x0088CB1C

D2SpriteCacheStrc gCmpTileCache;                                                                            // 0x0089DB60

D2SpriteCacheNodeStrc* __fastcall D2CMPSpriteCacheEvict(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0

extern D2CmpCacheListEntryStrc* gpCmpCacheEntries; // 0x0089DB7C

void __fastcall sub_0040AB00_FreeAsyncData(AsyncData* pAsync); // 0x0040AB00

void __fastcall CelDrawRleShadow(D2CelStrc* pCel, unsigned char* pDst, int nX, int nClipLeft, int nClipRight, int nPitch, int nSkip, int nLines, int nTable, int nColor); // 0x00608D60

void __fastcall FindTileAddTile(D2TileLibraryHashStrc* pHash, D2CmpTileBlockStrc* pTile); // 0x0060CFA0

struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];
    void sub_0060B130_Destroy();                                                                            // 0x0060B130
};

struct D2CmpValueObjStrc
{
    char unk0x00[0x2C];
    int nValue;
};

extern D2CmpBlockTableAStrc gCmpBlockTableA; // 0x0088CB20

D2CmpBlockTableBStrc gCmpBlockTableB; // 0x0088DB58

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SpriteFileStrc
{
    unsigned char nFlags;
    char unk0x01[0x9F];
    char pData[4];
};

struct D2SpriteEntryStrc
{
    unsigned char nFlags;
    char unk0x01[0x93];
    D2SpriteCacheNodeStrc* pNode;
};

struct D2SpriteLoadRequestStrc
{
    int unk0x00;
    D2SpriteFileStrc* pFile;
    D2SpriteEntryStrc* f_8;
    int nArg0C;
    int nArg10;
    int nResult;
    int nSize;
};

int __fastcall CodecDecodeDccData(void* hArg, void* pMemPool, int nArg, D2SpriteFileStrc* pFile, D2SpriteEntryStrc* pEntry, int nArg0C, int nArg10, int* pSize, char* pData); // 0x0060BFF0

void __fastcall D2CMPSpriteCacheResize(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int nDelta, int nArg); // 0x005FF630

extern D2CmpPoolStrc gCmpTilePool; // 0x0088DB20

extern int gnCmpTilePoolBlocks; // 0x00741EF8

void __cdecl CodecInitLock(); // 0x0060CD30

D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo(); // 0x00407360

void __fastcall CelDataHashInit(D2CmpBlockTableAStrc* pTable); // 0x0060AEE0

void __fastcall GfxHashInit(D2CmpBlockTableBStrc* pTable); // 0x0060AAF0

void __fastcall D2CMPTileFreePoolEntry(void* pEntry); // 0x005FE1D0

struct D2CelDataHashStrc;

struct D2CelDataHashEntryStrc;

struct D2TilePoolEntryStrc
{
    char unk0x00[0x08];
    D2CelDataHashEntryStrc* pCelData;
};

struct D2CelDataViewStrc
{
    char unk0x00[0x24];
    int nRef;
};

void __fastcall CelDataHashRemove(void* pMemPool, D2CelDataHashStrc* pHash, D2CelDataHashEntryStrc* pEntry); // 0x0060B0B0

void __fastcall D2CMPSpriteCacheFreeAll(D2SpriteCacheStrc* pCache); // 0x005FFBE0

void __fastcall D2CMPSpriteCacheCreate(D2SpriteCacheStrc* pCache, void* pMemPool, unsigned int nMaxSize, int nArg); // 0x005FEE90

void __fastcall sub_005FE170_SpriteCacheFreeCallback(void* pNode); // 0x005FE170

extern int gaDirectionIndex64A[8][64]; // 0x006E4DA0

extern int gaDirectionIndex64B[8][64]; // 0x006E55A0

void __fastcall CelIterateRgbPixels(D2CelStrc* pCel, int nArg, int nTermination); // 0x0060D110

typedef void(__fastcall* CELFILECELLOPFN)(D2CelStrc* pCel, int nArg);

extern CELFILECELLOPFN gpfnCelFileCellOp[]; // 0x006E3698

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);

extern CELDRAWFN gpfnCelDraw[]; // 0x006E3688

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);

void __stdcall D2CMPLoadProjectRecord(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath); // 0x00600790

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590

void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsync); // 0x0040A9E0

// build: symbol _gszFmtDcc4 0x006E3618
extern "C" const char gszFmtDcc4[];

// build: symbol _gszFmtDc64 0x006E3608
extern "C" const char gszFmtDc64[];

// build: symbol _gszOverlaysDir 0x006E35F0
extern "C" const char gszOverlaysDir[];

// build: symbol _gszFmtDc62 0x006E35E4
extern "C" const char gszFmtDc62[];

extern "C" const char gszFmtItemsDc6[]; // 0x006E35D4

// build: symbol _gszMissilesDir 0x006E35BC
extern "C" const char gszMissilesDir[];

// build: symbol _gszFmtDcc2 0x006E35B0
extern "C" const char gszFmtDcc2[];

// build: symbol _gszObjectsDir 0x006E3628
extern "C" const char gszObjectsDir[];

// build: symbol _gszNoCompressName 0x006E363C
extern "C" const char gszNoCompressName[];

extern "C" const char gszDataGlobal[]; // 0x006D4118

struct D2CmpDC6CelStrc { char unk0x00[0x2C]; };

int gdwGlobal_0089DB64; // 0x0089DB64

int gdwGlobal_0088DB28; // 0x0088DB28

int gdwGlobal_0088DB24; // 0x0088DB24

struct D2CmpCelFileViewStrc;

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2CmpCelFileViewStrc
{
    int nVersion;
    char unk0x04[0x10];
    unsigned int nFrames;
};

static D2SpriteCacheNodeStrc* __stdcall D2CMPSpriteCacheTakeNode(unsigned int nSize, int bLocked, D2SpriteCacheStrc* pCache);

struct D2CmpGfxHashEntryStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

extern int gbCmpCompressedDataMode;                                                                         // 0x00741EFC

extern "C" const char gszMonstersDir[];                                                            // 0x006D6CAC

extern "C" const char gszCharsDir[];                                                               // 0x006DCC34

extern "C" const char gszSpriteCacheSourceFile[];                                                           // 0x006E364C

static int D2CMPSpriteBuildName(D2CmpSpriteContextStrc* pContext, char* szOut); // 0x005FE2B0

void __stdcall D2CMPSpriteInitFrames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);

D2SpriteCacheNodeStrc* __fastcall D2CMPSpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked); // 0x005FFC40

AsyncData* __fastcall sub_0040A620(void* pMemPool, const char* szFileName, int bAllowAsync, long nFileOffset, int nFileSize, void* pBuffer, D2CmpLoadDescStrc* pAsyncOpDesc, int nPriority, const char* szFile, int nLine); // 0x0040A620

unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData); // 0x0040AA40

int __stdcall D2CMPSpriteAsyncLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest);    // 0x005FF6E0

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections);                   // 0x00600C90

D2CmpGfxHashEntryStrc* __fastcall GfxHashAdd(void* pMemPool, D2CmpBlockTableBStrc* pHash, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile); // 0x0060ADC0

static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);

static int __stdcall D2CMPSpriteReadFrames(D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteEntryStrc* pEntry);

struct D2CmpGfxHashStrc;

int __stdcall D2CMPSpriteCanConvertDirections(int nDirections, int nNewDirections); // 0x00600D30

void* __fastcall GfxHashFind(D2CmpBlockTableBStrc* pHash, D2CmpSpriteContextStrc* pContext, int* pDirection, unsigned int* pFrames, D2CmpSpriteFileStrc* pFile); // 0x0060ACE0

extern int gbCmpDisableConvert;                                                                    // 0x0089DB58

static int __stdcall D2CMPSpriteReadFramesAsync(D2CmpSpriteFileStrc* pFile, int nDirection, const char* szName, int nFrames, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext);

struct SpriteFile
{
    unsigned int flags;
    unsigned int version;
    unsigned int compression;
    unsigned int format;
    unsigned int reserved;
    unsigned int directions;
    unsigned int frames;
    unsigned int offsets[33];
    char name[32];
};

struct HashNode { char pad00[0x20]; D2CmpSpriteEntryStrc* entry; void* link; };

struct HashTable { int unused; };

struct SpriteCache { int unused; };

extern HashTable gtHash; // 0x0088DB58

extern SpriteCache gCache_0089DB60; // 0x0089DB60

extern int gnWarn; // 0x008ADBB0

extern int __fastcall FOG_AsyncDataTestLoaded(AsyncData*); // 0x0040A7F0

extern void* __stdcall CelGetHandle(D2CmpSpriteContextStrc*); // 0x00601840

void __fastcall D2CMPSpriteCacheTouch(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode); // 0x005FF5B0

int __stdcall CelConvertDir(unsigned int nDirection, unsigned int nDirections, int nNewDirections, int bAlt); // 0x00600CB0

#define SPRITE_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern HashTable gtFileHash; // 0x0088CB20

extern SpriteCache gtFileCache; // 0x0088DB20

extern unsigned int gaFileOffsets[]; // 0x0089DBB0

HashNode* __fastcall CelDataHashFind(HashTable*, const char*); // 0x0060AF90

HashNode* __fastcall CelDataHashAdd(void*, HashTable*, int, const char*); // 0x0060B010

void __fastcall LRUCacheTouch(SpriteCache*, void*); // 0x00609380

void* __fastcall LRUCacheAlloc(SpriteCache*, unsigned int, HashNode*); // 0x00609420

int __fastcall CodecLoadTileHeader(const char*, SpriteFile*); // 0x0060BF20

int __fastcall FOG_FOpenFile(const char*, char**); // 0x004068E0

int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

static SpriteFile* __stdcall D2CMPSpriteLoadFile(D2CmpSpriteContextStrc*, char*, char*); // 0x005FE990

static D2SpriteCacheNodeStrc* __stdcall D2CMPSpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache); // 0x005FF0F0

static void D2CMPSpriteCacheUnlink(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode); // 0x005FF1B0

int gbCmpSmallCelCache; // 0x0089DB58

static int __stdcall D2CMPSpriteLoadDc6CacheEntry(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext); // 0x005FFFA0

int __stdcall D2CMPSpriteBuildPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut); // 0x005FE610

static int __stdcall D2CMPSpriteBuildPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut); // 0x005FE610

static void __stdcall D2CMPSpriteInitFrames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);

static int __stdcall D2CMPSpriteLoadDc6Entry(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext); // 0x005FFE90

static void __stdcall D2CMPSpriteLoadConvertedEntry(int nDirection, unsigned int nFrames, char* szName, int bDC6, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile, char* szPath); // 0x006000B0

// 0x005FE000
void __fastcall D2CMPTileCacheSetFreeCallback(void* pfnCallback)
{
    gpfnTileFreeCallback = pfnCallback;
}

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_long_width[(sizeof(long) == 4) ? 1 : -1];

typedef char check_uchar_width[(sizeof(unsigned char) == 1) ? 1 : -1];

// build: symbol _gnPendingCount 0x00881D5C
extern "C" long gnPendingCount;

extern "C" int gnFlag_00882528;

// build: symbol _ganSlotArrayA 0x00882128
extern "C" int ganSlotArrayA[94];

// build: symbol _ganSlotArrayB 0x008822A8
extern "C" int ganSlotArrayB[94];

extern "C" int gnValue_00882744;

extern "C" int gnValue_0088274C;

extern "C" int gnValue_0088CB0C; // 0x0088CB0C

extern "C" int gnValue_0088CB10; // 0x0088CB10

extern "C" int __cdecl BNDOWNLOAD_HasPendingDownloads(); // 0x0051E5E0

extern "C" int __cdecl BNDOWNLOAD_SetDisconnected(); // 0x00520AD0

extern "C" void __fastcall BNDOWNLOAD_ClearReply(unsigned char nSlot); // 0x00520C00

extern "C" int __fastcall BNDOWNLOAD_GetReplyValue(unsigned char nSlot); // 0x00520C20

extern "C" int __fastcall GRID_GetCDKey(int bSecond); // 0x00523AB0

static int gnCmpPoolArg;                                                                           // 0x0088CB18

// 0x005FE010
void __stdcall D2CMPGetTileCacheHits(int* pnArg, int* pnCountB, int* pnCountA, int* pnHitPercent)
{
    *pnArg = gnCmpPoolArg;
    *pnCountA = gnValue_0088CB10;
    *pnCountB = gnValue_0088CB0C;
    if (gCmpPool.nTotal)
    {
        *pnHitPercent = gCmpPool.nHits * 100 / gCmpPool.nTotal;
    }
    else
    {
        *pnHitPercent = -1;
    }
}

// 0x005FE060
extern "C" void __cdecl D2CMPResetTileCacheHits()
{
    gnValue_0088CB10 = 0;
    gnValue_0088CB0C = 0;
}

// 0x005FE070
void __cdecl D2CMPTileFreeAsyncLoads()
{
    sub_006093E0_PoolFreeAll(&gCmpPool);
}

// 0x005FE0E0
void __cdecl D2CMPTileCacheGroupTileLoads()
{
}

// 0x005FE0F0
void __cdecl D2CMPTileCacheIndividualTileLoads()
{
}

// 0x005FE100
void __stdcall D2CMPTileCacheMarkTileForPreLoad(int nUnused1, int nUnused2)
{
}

// 0x005FE110
void __cdecl D2CMPTileCachePreLoadMarkedTiles()
{
}

static __forceinline int SpriteCache_FlatPath(char* szOut, const char* szDir, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    if (gbCmpCompressedDataMode)
    {
        wsprintfA(szOut, "%s\\%s.dcc", szDir, szName);
        pContext->dwGfxFlags |= 1;
    }
    else
    {
        wsprintfA(szOut, "%s\\%s.dc6", szDir, szName);
    }
    return 1;
}

struct D2SpriteKeyStrc
{
    int nKeyA;
    int nKeyB;
    int nKeyC;
};
struct D2SpriteFreeNodeStrc
{
    char unk0x00[0x20];
    D2SpriteKeyStrc* pKey;
};
void (__fastcall* gpfnCmpFreeCallback)(int nKeyA, int nKeyC, int nKeyB);                           // 0x0089DB5C
void __fastcall GfxHashRemove(void* pMemPool, D2CmpGfxHashStrc* pHash, D2CmpGfxHashEntryStrc* pEntry); // 0x0060AB10

// 0x005FE170
void __fastcall sub_005FE170_SpriteCacheFreeCallback(void* pNode)
{
    D2SpriteFreeNodeStrc* pFreeNode = (D2SpriteFreeNodeStrc*)pNode;
    if (gpfnCmpFreeCallback)
    {
        D2SpriteKeyStrc* pKey = pFreeNode->pKey;
        D2_ASSERT(pKey, 0xB5);
        gpfnCmpFreeCallback(pKey->nKeyA, pKey->nKeyC, pKey->nKeyB);
    }
    GfxHashRemove(gCmpTileCache.pMemPool, (D2CmpGfxHashStrc*)&gCmpBlockTableB, (D2CmpGfxHashEntryStrc*)pNode);
}

// 0x005FE1D0
void __fastcall D2CMPTileFreePoolEntry(void* pEntry)
{
    D2CelDataViewStrc* pCelData = (D2CelDataViewStrc*)((D2TilePoolEntryStrc*)pEntry)->pCelData;
    pCelData->nRef = 0;
    CelDataHashRemove(gCmpTilePool.pMemPool, (D2CelDataHashStrc*)&gCmpBlockTableA, (D2CelDataHashEntryStrc*)pCelData);
}

// 0x005FE610
static int __stdcall D2CMPSpriteBuildPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut)
{
    if (!*szName)
    {
        *szOut = 0;
        return 0;
    }

    switch (pContext->nType)
    {
    case 3:
        if (!pContext->pName)
        {
            break;
        }
        return SpriteCache_FlatPath(szOut, "DATA\\GLOBAL\\MISSILES", pContext->pName, pContext);

    case 4:
    {
        if (!pContext->pName)
        {
            break;
        }
        const int nMode = pContext->nMode;
        if (nMode == 4)
        {

            if (pContext->dwFlags & 2)
            {
                wsprintfA(szOut, gszFmtItemsDc6, "DATA\\GLOBAL", szName);
                return 1;
            }
            wsprintfA(szOut, gszFmtItemsDc6, "DATA\\GLOBAL", szName);
            return 1;
        }
        if (nMode == 3)
        {
            wsprintfA(szOut, "%s\\items\\%s.dc6", "DATA\\GLOBAL", szName);
            return 1;
        }
        break;
    }

    case 6:
        if (!(pContext->dwFlags & 2))
        {
            break;
        }
        if (pContext->nOverlay == 0x7A)
        {
            wsprintfA(szOut, "%s\\%s.dc6", "DATA\\GLOBAL\\OVERLAYS", szName);
            return 1;
        }
        return SpriteCache_FlatPath(szOut, "DATA\\GLOBAL\\OVERLAYS", szName, pContext);

    default:
    {
        int bDcc = gbCmpCompressedDataMode;
        if (bDcc && !SStrCmpI(szName, "OYTRlitTNhth", 0x7FFFFFFF))
        {
            bDcc = 0;
            pContext->dwGfxFlags &= ~1;
        }

        const char* szDir;
        switch (pContext->nType)
        {
        case 0:
            szDir = "DATA\\GLOBAL\\CHARS";
            break;

        case 1:
            szDir = "DATA\\GLOBAL\\MONSTERS";
            switch (pContext->nIndex)
            {
            case 0xF3: case 0x11C: case 0x14D: case 0x220: case 0x22F: case 0x23A: case 0x2C1: case 0x2C5:
                if (!pContext->nMode)
                {
                    bDcc = 0;
                }
                break;

            case 0xF2: case 0xFB: case 0x16F: case 0x209: case 0x2C0:
                bDcc = 0;
                break;
            }
            break;

        case 2:
            if (pContext->nIndex == 0x156 || pContext->nIndex == 0x233)
            {
                bDcc = 0;
            }
            szDir = "DATA\\GLOBAL\\OBJECTS";
            break;

        default:
            goto Fail;
        }

        char szToken[4];
        char szComponent[4];
        szToken[3] = 0;
        szComponent[3] = 0;
        szToken[0] = pContext->szToken[0] == ' ' ? 0 : pContext->szToken[0];
        szToken[1] = pContext->szToken[1] == ' ' ? 0 : pContext->szToken[1];
        szToken[2] = pContext->szToken[2] == ' ' ? 0 : pContext->szToken[2];
        szComponent[0] = pContext->szComponent[0] == ' ' ? 0 : pContext->szComponent[0];
        szComponent[1] = pContext->szComponent[1] == ' ' ? 0 : pContext->szComponent[1];
        szComponent[2] = pContext->szComponent[2] == ' ' ? 0 : pContext->szComponent[2];

        if (bDcc)
        {
            wsprintfA(szOut, "%s\\%s\\%s\\%s.dcc", szDir, szToken, szComponent, szName);
            pContext->dwGfxFlags |= 1;
        }
        else
        {
            wsprintfA(szOut, "%s\\%s\\%s\\%s.dc6", szDir, szToken, szComponent, szName);
        }
        return 1;
    }
    }

Fail:
    *szOut = 0;
    return 0;
}

static __forceinline int SpriteCache_IsCompressible(D2CmpSpriteContextStrc* pContext)
{
    switch (pContext->nType)
    {
    case 1:
        switch (pContext->nIndex)
        {
        case 0xF3: case 0x11C: case 0x14D: case 0x220: case 0x22F: case 0x23A: case 0x2C1: case 0x2C5:
            if (!pContext->nMode)
            {
                return 0;
            }
            break;

        case 0xF2: case 0xFB: case 0x16F: case 0x209: case 0x2C0:
            return 0;
        }
        break;

    case 2:
        if (pContext->nIndex == 0x156 || pContext->nIndex == 0x233)
        {
            return 0;
        }
        break;
    }

    return 1;
}

// 0x005FE2B0
static int D2CMPSpriteBuildName(D2CmpSpriteContextStrc* pContext, char* szOut)
{
    switch (pContext->nType)
    {
    case 4:
    {
        if (!pContext->pName)
        {
            *szOut = 0;
            return 0;
        }
        strcpy(szOut, pContext->pName);
        return 1;
    }

    case 3:
    {
        if (!pContext->pName)
        {
            *szOut = 0;
            return 0;
        }
        if (gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        strcpy(szOut, pContext->pName);
        return 1;
    }

    case 6:
    {
        if (!(pContext->dwFlags & 2))
        {
            *szOut = 0;
            return 0;
        }
        if (!pContext->pName)
        {
            *szOut = 0;
            return 0;
        }
        if (pContext->nOverlay != 0x7A && gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        strcpy(szOut, pContext->pName);
        return 1;
    }

    case 0:
    case 1:
    case 2:
    {
        char* p = szOut;
        unsigned int dw;
        dw = pContext->dwName[0]; APPEND_CODE(p, dw);
        dw = pContext->dwName[1]; APPEND_CODE(p, dw);
        dw = pContext->dwName[2]; APPEND_CODE(p, dw);
        dw = pContext->dwName[3]; APPEND_CODE(p, dw);
        dw = pContext->dwName[4]; APPEND_CODE(p, dw);
        *p = 0;

        if (SpriteCache_IsCompressible(pContext) && gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        return 1;
    }
    }

    *szOut = 0;
    return 0;
}

static inline int SpriteCache_CopyName(char* szDst, const char* szSrc)
{
    strcpy(szDst, szSrc);
    return 1;
}

static inline int SpriteCache_BuildDccOrDc6Path(char* szOut, const char* szDir, const char* szName, D2CmpSpriteContextStrc* pContext, int bAllowDcc)
{
    if (bAllowDcc)
    {
        if (gbCmpCompressedDataMode)
        {
            wsprintfA(szOut, gszFmtDcc2, szDir, szName);
            pContext->dwGfxFlags |= 1;
            return 1;
        }
        wsprintfA(szOut, gszFmtDc62, szDir, szName);
        return 1;
    }
    wsprintfA(szOut, gszFmtDc62, szDir, szName);
    return 1;
}

// 0x005FEC90
static void __stdcall D2CMPSpriteInitFrames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    char szName[0x104];
    char szPath[0x104];

    D2_ASSERT(pContext, 0x50D);
    D2_ASSERT(pEntry, 0x50E);
    D2_ASSERT(!(pFile->dwFlags & 1), 0x50F);
    D2_ASSERT(!pEntry->bFramesInitialized, 0x512);

    const int nSize = pEntry->nFrames * pEntry->nFramesPerDirection * sizeof(D2CmpDC6CelStrc);
    D2CmpDC6CelStrc* pCels = (D2CmpDC6CelStrc*)FOG_AllocPool(gCmpTileCache.pMemPool, nSize, ".\\SRC\\SpriteCache.cpp", 0x517, 0);
    memset(pCels, 0, nSize);

    char* pData = (char*)FOG_AsyncDataGetBuffer(pEntry->pAsync);
    D2_ASSERT(pData, 0x524);

    int nOffset = pEntry->aOffsets[pEntry->nFirstFrame];
    D2CmpDC6FrameStrc* pFrame;
    for (unsigned int i = 0; i < (unsigned int)(pEntry->nFrames * pEntry->nFramesPerDirection); ++i, nOffset += pFrame->nLength + pFrame->nOffsetY_14 + 0x23)
    {
        pFrame = (D2CmpDC6FrameStrc*)(pData + nOffset);
        if (pFrame->nFlip != 0 || pFrame->nWidth > 0x100 || pFrame->nHeight > 0x100)
        {
            D2CMPSpriteBuildName(pContext, szName);
            D2CMPSpriteBuildPath(szName, pContext, szPath);
            D2_ASSERT(0, 0x58C);
        }

        pFrame->pCel = &pCels[i];
    }

    pEntry->bFramesInitialized = 1;
}

// 0x005FEE00
void __cdecl D2CMPSpriteCacheDumpHashTableStats()
{
    gCmpBlockTableB.sub_0060AB70_Destroy();
}

// 0x005FEE10
unsigned int __cdecl D2CMPSpriteCacheGetUsedMemory()
{
    EnterCriticalSection(&gCmpTileCache.tLock);
    const unsigned int nTotalSize = gCmpTileCache.nTotalSize;
    LeaveCriticalSection(&gCmpTileCache.tLock);
    return nTotalSize;
}

// 0x005FEE40
int __cdecl D2CMPSpriteCacheGetMaxMemory()
{
    return gdwGlobal_0089DB64;
}

// 0x005FEE50
void __cdecl D2CMPCelDataCacheDumpHashTableStats()
{
    gCmpBlockTableA.sub_0060B130_Destroy();
}

// 0x005FEE60
int __cdecl D2CMPCelDataCacheGetUsedMemory()
{
    return gdwGlobal_0088DB28;
}

// 0x005FEE70
int __cdecl D2CMPCelDataCacheGetMaxMemory()
{
    return gdwGlobal_0088DB24;
}

// 0x005FEE80
int __fastcall D2CMPSpriteCacheIsInitialized(D2CmpValueObjStrc* pObject)
{
    return pObject->nValue != 0;
}

// 0x005FEE90
void __fastcall D2CMPSpriteCacheCreate(D2SpriteCacheStrc* pCache, void* pMemPool, unsigned int nMaxSize, int nArg)
{
    pCache->nMaxSize = nMaxSize;
    pCache->nArg = nArg;
    pCache->pMemPool = pMemPool;
    pCache->nTotalSize = 0;
    pCache->pNodes = (D2SpriteCacheNodeStrc*)sub_0040B430(pMemPool, sizeof(D2SpriteCacheNodeStrc) * 0x1400, ".\\SRC\\SpriteCache.cpp", 2273, 0);
    memset(pCache->pNodes, 0, sizeof(D2SpriteCacheNodeStrc) * 0x1400);

    for (int i = 0; i < 0x1400; ++i)
    {
        D2SpriteCacheNodeStrc* pNode = &pCache->pNodes[i];
        if (i < 0x1400 - 1)
        {
            pNode->pNext = &pCache->pNodes[i + 1];
        }

        if (i > 0)
        {
            pNode->pPrev = &pCache->pNodes[i - 1];
        }

        pNode->pData = 0;
        pNode->nSize = 0;
        pNode->nKey = 0;
    }

    pCache->pFreeHead = pCache->pNodes;
    pCache->nCount = 0;
    pCache->pHeadA = 0;
    pCache->pTailA = 0;
    pCache->pHeadB = 0;
    pCache->pTailB = 0;
    pCache->pFreeTail = &pCache->pNodes[0x1400 - 1];
    pCache->nHits = 0;
    pCache->nRequests = 0;
    InitializeCriticalSection(&pCache->tLock);
}

// 0x005FF060
static void __stdcall D2CMPSpriteCacheLinkTail(int bLocked, D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (bLocked)
    {
        if (!pCache->pTailB)
        {
            pCache->pHeadB = pNode;
            pCache->pTailB = pNode;
        }
        else
        {
            pCache->pTailB->pNext = pNode;
            pNode->pPrev = pCache->pTailB;
            pCache->pTailB = pNode;
        }
    }
    else
    {
        if (!pCache->pTailA)
        {
            pCache->pHeadA = pNode;
            pCache->pTailA = pNode;
        }
        else
        {
            pCache->pTailA->pNext = pNode;
            pNode->pPrev = pCache->pTailA;
            pCache->pTailA = pNode;
        }
    }
    pNode->dwTick = GetTickCount();
}

// 0x005FF0D0
static inline void D2CMPSpriteCachePushFree(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (!pCache->pFreeTail)
    {
        pCache->pFreeHead = pNode;
        pCache->pFreeTail = pNode;
    }
    else
    {
        pCache->pFreeTail->pNext = pNode;
        pNode->pPrev = pCache->pFreeTail;
        pCache->pFreeTail = pNode;
    }
}

// 0x005FF0F0
static D2SpriteCacheNodeStrc* __stdcall D2CMPSpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = 0;
    if (bLocked)
    {
        if (!pCache->pHeadB)
            return 0;
        pNode = pCache->pHeadB;
        if (pNode->dwFlags & 2)
            return 0;
        pCache->pHeadB = pCache->pHeadB->pNext;
        if (pCache->pHeadB)
            pCache->pHeadB->pPrev = 0;
        else
            pCache->pTailB = 0;
    }
    else
    {
        if (!pCache->pHeadA)
            return 0;
        pNode = pCache->pHeadA;
        if (pNode->dwFlags & 2)
            return 0;
        pCache->pHeadA = pCache->pHeadA->pNext;
        if (pCache->pHeadA)
            pCache->pHeadA->pPrev = 0;
        else
            pCache->pTailA = 0;
    }
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x005FF170
static inline D2SpriteCacheNodeStrc* D2CMPSpriteCachePopFree(D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = pCache->pFreeHead;
    if (!pNode)
        return 0;
    if (pNode->dwFlags & 2)
        return 0;
    D2SpriteCacheNodeStrc* pNext = pNode->pNext;
    pCache->pFreeHead = pNext;
    if (pNext)
        pNext->pPrev = 0;
    else
        pCache->pFreeTail = 0;
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x005FF1B0
static void D2CMPSpriteCacheUnlink(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* ptBlock)
{
    D2_ASSERT(ptBlock, 0xAFC);
    if (ptBlock->dwFlags & 1)
    {
        if (!pCache->pHeadB)
        {
            return;
        }
        if (ptBlock == pCache->pHeadB)
        {
            D2CMPSpriteCachePopHead(1, pCache);
            return;
        }
        if (ptBlock == pCache->pTailB)
        {
            pCache->pTailB = pCache->pTailB->pPrev;
            pCache->pTailB->pNext = 0;
        }
        else
        {
            if (!ptBlock->pPrev && !ptBlock->pNext)
            {
                return;
            }
            ptBlock->pPrev->pNext = ptBlock->pNext;
            ptBlock->pNext->pPrev = ptBlock->pPrev;
        }
    }
    else
    {
        if (!pCache->pHeadA)
        {
            return;
        }
        if (ptBlock == pCache->pHeadA)
        {
            D2CMPSpriteCachePopHead(0, pCache);
            return;
        }
        if (ptBlock == pCache->pTailA)
        {
            pCache->pTailA = pCache->pTailA->pPrev;
            pCache->pTailA->pNext = 0;
        }
        else
        {
            if (!ptBlock->pPrev && !ptBlock->pNext)
            {
                return;
            }
            ptBlock->pPrev->pNext = ptBlock->pNext;
            ptBlock->pNext->pPrev = ptBlock->pPrev;
        }
    }
    ptBlock->pNext = 0;
    ptBlock->pPrev = 0;
}

int __cdecl D2CMPSpriteNumAsyncLoads()
{
    int nCount = 0;
    for (D2CmpCacheListEntryStrc* pEntry = gpCmpCacheEntries; pEntry; pEntry = pEntry->pNext)
    {
        D2CmpCacheKeyStrc* pKey = pEntry->pKey;
        if (pKey && !(pKey->nFlags & 1))
        {
            D2_ASSERT(pKey->pAsyncData, 0xB5B);
            if (!sub_0040A7F0_AsyncDataCheck(pKey->pAsyncData))
            {
                nCount += 1;
            }
        }
    }

    return nCount;
}

// 0x005FF390
void __cdecl sub_005FF390_Nop()
{
}

// 0x005FF3F0
static D2SpriteCacheNodeStrc* __stdcall D2CMPSpriteCacheTakeNode(unsigned int nSize, int bLocked, D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = 0;
    EnterCriticalSection(&pCache->tLock);
    if (pCache->nCount != 0x1400 && pCache->nTotalSize + nSize <= pCache->nMaxSize)
    {
        pNode = pCache->pFreeHead;
        if (!pNode)
        {
            pNode = 0;
        }
        else if (pNode->dwFlags & 2)
        {
            pNode = 0;
        }
        else
        {
            D2SpriteCacheNodeStrc* pNext = pNode->pNext;
            pCache->pFreeHead = pNext;
            if (pNext)
            {
                pNext->pPrev = 0;
            }
            else
            {
                pCache->pFreeTail = 0;
            }
            pNode->pNext = 0;
            pNode->pPrev = 0;
        }
        D2CMPSpriteCacheLinkTail(bLocked, pCache, pNode);
        D2_ASSERT(pNode, 0x993);
        pCache->nCount += 1;
        pCache->nTotalSize += nSize;
    }
    LeaveCriticalSection(&pCache->tLock);
    return pNode;
}

// 0x005FF4A0
D2SpriteCacheNodeStrc* __fastcall D2CMPSpriteCacheEvict(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked)
{
    if (!pCache->nCount)
    {
        return 0;
    }
    if (!pNode)
    {
        if (!pCache->pHeadB)
        {
            pNode = D2CMPSpriteCachePopHead(0, pCache);
        }
        else
        {
            if (!pCache->pHeadA)
            {
                pNode = D2CMPSpriteCachePopHead(bLocked, pCache);
            }
            else if (bLocked)
            {
                pNode = D2CMPSpriteCachePopHead(pCache->pHeadB->dwTick < pCache->pHeadA->dwTick, pCache);
            }
            else
            {
                pNode = D2CMPSpriteCachePopHead(0, pCache);
            }
        }
        if (!pNode)
        {
            return 0;
        }
        if (pNode->dwFlags & 2)
        {
            return 0;
        }
    }
    else
    {
        if (pNode->dwFlags & 2)
        {
            return 0;
        }
        D2CMPSpriteCacheUnlink(pCache, pNode);
    }
    EnterCriticalSection(&pCache->tLock);
    pCache->nTotalSize -= pNode->nSize;
    LeaveCriticalSection(&pCache->tLock);
    if (pNode->nKey)
    {
        ((D2SpriteCacheFreeFn)pCache->nArg)(pNode->nKey);
        pNode->nKey = 0;
    }
    if (pNode->pData)
    {
        FOG_FreePool(pCache->pMemPool, pNode->pData, gszSpriteCacheSourceFile, 0x9E8, 0);
        pNode->pData = 0;
    }
    if (!pCache->pFreeTail)
    {
        pCache->nCount -= 1;
        pCache->pFreeHead = pNode;
        pCache->pFreeTail = pNode;
    }
    else
    {
        pCache->pFreeTail->pNext = pNode;
        pNode->pPrev = pCache->pFreeTail;
        pCache->nCount -= 1;
        pCache->pFreeTail = pNode;
    }
    return pNode;
}

// 0x005FF5B0
void __fastcall D2CMPSpriteCacheTouch(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (!pCache->nCount)
    {
        return;
    }
    pCache->nRequests += 1;
    EnterCriticalSection(&pCache->tLock);
    D2_ASSERT(pNode, 0xA10);
    D2CMPSpriteCacheUnlink(pCache, pNode);
    pNode->dwFlags &= ~1;
    if (!pCache->pTailA)
    {
        pCache->pHeadA = pNode;
    }
    else
    {
        pCache->pTailA->pNext = pNode;
        pNode->pPrev = pCache->pTailA;
    }
    pCache->pTailA = pNode;
    pNode->dwTick = GetTickCount();
    LeaveCriticalSection(&pCache->tLock);
}

void __cdecl D2CMPSpriteFreeAsyncLoads()
{
    for (D2CmpCacheListEntryStrc* pEntry = gpCmpCacheEntries; pEntry; pEntry = pEntry->pNext)
    {
        D2CmpCacheKeyStrc* pKey = pEntry->pKey;
        if (pKey)
        {
            AsyncData* pAsyncData = pKey->pAsyncData;
            if (pAsyncData && !sub_0040A7F0_AsyncDataCheck(pAsyncData))
            {
                sub_0040AB00_FreeAsyncData(pAsyncData);
                pKey->pAsyncData = 0;
            }
        }
    }
}

D2SpriteCacheNodeStrc* __fastcall sub_M110_Emit_005FF0D0(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    D2CMPSpriteCachePushFree(pCache, pNode);
    return D2CMPSpriteCachePopFree(pCache);
}

// 0x005FFD40
void __stdcall D2CMPSpriteCacheInit(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize)
{
    CodecInitLock();
    if (!nCacheSize)
    {
        D2FogSystemInfoStrc* pInfo = FOG_GetSystemInfo();
        D2_ASSERT(pInfo, 0x10B);
        nCacheSize = pInfo->dwTotalPhys - 0xB00000;
    }
    gbCmpSmallCelCache = nCacheSize < 0x4000000;
    CelDataHashInit(&gCmpBlockTableA);
    sub_006093E0_PoolFreeAll(&gCmpTilePool);
    memset(&gCmpTilePool, 0, sizeof(gCmpTilePool));
    sub_00609020_PoolInit(&gCmpTilePool, pMemPool, nArg, D2CMPTileFreePoolEntry, gnCmpTilePoolBlocks);
    memset(&gCmpBlockTableB, 0, sizeof(gCmpBlockTableB));
    GfxHashInit(&gCmpBlockTableB);
    if (gCmpTileCache.nArg)
    {
        D2CMPSpriteCacheFreeAll(&gCmpTileCache);
        memset(&gCmpTileCache, 0, sizeof(gCmpTileCache));
    }
    D2CMPSpriteCacheCreate(&gCmpTileCache, pMemPool, nMaxSize, (int)sub_005FE170_SpriteCacheFreeCallback);
}

// 0x005FEB80
static void* __stdcall sub_005FEB80_FindDC6Frame(void* pData, D2CmpSpriteContextStrc* pContext, D2CmpDC6HeaderStrc* pHeader)
{
    if (!pData)
        return 0;
    if (!pHeader)
        return 0;
    if ((unsigned int)pContext->nFrame >= pHeader->nFrames)
        return 0;

    int nIndex;
    D2CmpDC6FrameStrc* pFrame = (D2CmpDC6FrameStrc*)pData;
    if (pContext->nType == 6 && (pContext->dwFlags & 2))
        nIndex = CelGameDirToFileDir(pContext->nDirection, pHeader->nDirections - 1);
    else if (pContext->nType == 2)
        nIndex = 0;
    else if (pContext->nType == 4)
        nIndex = pContext->nDirection;
    else
        nIndex = CelGameDirToFileDir(pContext->nDirection, pHeader->nDirections - 1);

    if (nIndex >= pHeader->nDirections - 1)
        return 0;

    int nOffset = pHeader->aOffsets[nIndex];
    if (nOffset < 0)
        return 0;

    const int nFrame = pContext->nFrame;
    for (int i = 0; i <= nFrame; ++i)
    {
        pFrame = (D2CmpDC6FrameStrc*)((char*)pData + nOffset);
        if (pFrame->nFlip != 0)
            return 0;
        if (pFrame->nWidth > 0x100)
            return 0;
        if (pFrame->nHeight > 0x100)
            return 0;
        nOffset += pFrame->nLength + pFrame->nOffsetY_14 + 0x23;
        if (nOffset < 0)
            return 0;
    }

    return pFrame;
}

// 0x005FEC50
static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    if (pEntry && pEntry->pAsync)
    {
        D2CmpDC6HeaderStrc* pHeader = (D2CmpDC6HeaderStrc*)&pEntry->nFlags;
        void* pData = FOG_AsyncDataGetBuffer(pHeader->pAsync);
        if (pData)
        {
            pContext->nFrames = pHeader->nFrames;
            return sub_005FEB80_FindDC6Frame(pData, pContext, pHeader);
        }

        return 0;
    }

    return 0;
}

// 0x005FFE90
static int __stdcall D2CMPSpriteLoadDc6Entry(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    if (!pFile)
        return 0;

    D2SpriteCacheNodeStrc* pHolder = D2CMPSpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 0);
    if (!pHolder)
        return 0;

    D2CmpSpriteEntryStrc* pEntry = pHolder->pEntry;
    memset(pEntry, 0, sizeof(D2CmpSpriteEntryStrc));
    pEntry->nType = pContext->nType;
    pEntry->nArg0C = pContext->dwName[0];
    pEntry->nArg18 = pContext->dwName[3];
    pEntry->nArg10 = pContext->dwName[1];
    pEntry->nArg14 = pContext->dwName[2];
    pEntry->nArg1C = pContext->dwName[4];
    pEntry->pHolder = pHolder;
    if (!(pFile->dwFlags & 1))
    {
        pEntry->nArg08 = pContext->nIndex;
        pEntry->nArg04 = pContext->nMode;
        D2CMPSpriteReadFrames(pContext, nArg2, nArg3, szName, pFile, pEntry);
    }

    D2CmpGfxHashEntryStrc* pRecord = GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->pEntry, pContext, pFile);
    D2_ASSERT(pRecord, 0x5D1);
    pHolder->pRecord = pRecord;
    pRecord->pHolder = pHolder;
    if (pFile->dwFlags & 1)
    {
        pEntry->nFlags |= 1;
        return 0;
    }

    if (!pEntry->bFramesInitialized)
        D2CMPSpriteInitFrames(pFile, pContext, pEntry);

    pContext->pFrame = sub_005FEC50_GetCachedDC6Frame(pContext, pEntry);
    return pContext->pFrame != 0;
}

// 0x005FFFA0
static int __stdcall D2CMPSpriteLoadDc6CacheEntry(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    D2SpriteCacheNodeStrc* pHolder = D2CMPSpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 1);
    if (pHolder)
    {
        D2CmpSpriteEntryStrc* pEntry = pHolder->pEntry;
        memset(pEntry, 0, sizeof(D2CmpSpriteEntryStrc));
        pEntry->nArg0C = pContext->dwName[0];
        pEntry->nArg18 = pContext->dwName[3];
        pEntry->nArg10 = pContext->dwName[1];
        pEntry->nArg14 = pContext->dwName[2];
        pEntry->nArg1C = pContext->dwName[4];
        pEntry->pHolder = pHolder;
        int nSize = 0;
        if (!(pFile->dwFlags & 1))
        {
            pEntry->nArg08 = pContext->nIndex;
            pEntry->nArg04 = pContext->nMode;
            nSize = D2CMPSpriteReadFramesAsync(pFile, nDirection, szName, nFrames, pEntry, pContext);
            if (nSize != -1)
            {
                D2CMPSpriteCacheResize(&gCmpTileCache, pHolder, nSize, 1);
            }
        }

        if (nSize != -1)
        {
            D2CmpGfxHashEntryStrc* pRecord = GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->pEntry, pContext, pFile);
            D2_ASSERT(pRecord, 0x630);
            pHolder->pRecord = pRecord;
            pRecord->pHolder = pHolder;
            if (pFile->dwFlags & 1)
            {
                pEntry->nFlags |= 1;
                return 0;
            }

            pEntry->nFlags |= 2;
            return 1;
        }

        D2CMPSpriteCacheEvict(&gCmpTileCache, pHolder, 1);
        return 0;
    }

    return 0;
}

// 0x005FF6E0
int __stdcall D2CMPSpriteAsyncLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest)
{
    D2SpriteFileStrc* pFile = pRequest->pFile;
    D2SpriteEntryStrc* pEntry = pRequest->f_8;
    D2SpriteCacheNodeStrc* pNode = pEntry->pNode;
    pNode->dwFlags |= 2;
    pRequest->nResult = CodecDecodeDccData(hArg, gCmpTileCache.pMemPool, nArg, pFile, pEntry, pRequest->nArg0C, pRequest->nArg10, &pRequest->nSize, pFile->pData);
    pNode->dwFlags &= ~2;
    pEntry->nFlags &= ~4;
    D2CMPSpriteCacheResize(&gCmpTileCache, pNode, pRequest->nSize, 0);
    if (!pRequest->nResult)
    {
        pFile->nFlags |= 1;
    }
    return 1;
}

int __stdcall sub_R04_Emit_005FFFA0(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    return D2CMPSpriteLoadDc6CacheEntry(pFile, nDirection, nFrames, szName, pContext);
}

// 0x005FF760
static int __stdcall D2CMPSpriteReadFrames(D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteEntryStrc* pEntry)
{
    char szGfxName[0x104];
    char szGfxPath[0x104];

    if (!pFile || !pEntry || !pContext)
    {
        return 0;
    }

    int nStart;
    int nEnd;
    if ((pContext->nType == 6 && (pContext->dwFlags & 2)) || pContext->nType == 3)
    {
        if (nFrames != 1)
        {
            return 0;
        }

        nStart = CelGameDirToFileDir(pContext->nDirection, pFile->nDirections);
        nEnd = nStart + 1;
    }
    else if (pContext->nType == 2)
    {
        nStart = 0;
        nEnd = 1;
    }
    else if (pContext->nType == 4)
    {
        nStart = pContext->nDirection;
        nEnd = nStart + 1;
    }
    else
    {
        if (pContext->nType == 1 && nFrames == 1)
        {
            nStart = CelGameDirToFileDir(pContext->nDirection, pFile->nDirections);
        }
        else
        {
            nStart = nDirection * nFrames;
        }
        nEnd = nStart + nFrames;
    }

    int nSize = pFile->aOffsets[nEnd] - pFile->aOffsets[nStart];
    if (!nSize)
    {
        D2CMPSpriteBuildName(pContext, szGfxName);
        D2CMPSpriteBuildPath(szGfxName, pContext, szGfxPath);
        return 0;
    }

    if (pEntry->pAsync)
    {
        return 0;
    }

    unsigned char nFrameCount = (unsigned char)nFrames;
    unsigned char nFirstFrame = (unsigned char)nDirection;
    nFirstFrame *= nFrameCount;
    pEntry->nFrames = nFrameCount;
    pEntry->nFirstFrame = nFirstFrame;
    pEntry->nFramesPerDirection = (unsigned char)pFile->nFramesPerDirection;
    pEntry->nDirections = (unsigned char)pFile->nDirections + 1;

    const unsigned int nBase = pFile->aOffsets[nStart];
    for (unsigned int i = nStart; i <= (unsigned int)nEnd; ++i)
    {
        D2_ASSERT(i < 0x21, 0x34C);
        pEntry->aOffsets[i] = pFile->aOffsets[i] - nBase;
        D2_ASSERT(pEntry->aOffsets[i] >= 0, 0x34E);
    }

    if (pFile->dwFlags & 2)
    {
        D2CmpLoadDescStrc tDesc;
        memset(&tDesc, 0, sizeof(tDesc));
        tDesc.pfnCallback = (void*)D2CMPSpriteAsyncLoadCallback;
        tDesc.pFile = pFile;
        tDesc.pFlags = &pEntry->nFlags;
        tDesc.nFirstFrame = nDirection * nFrames;
        tDesc.nFrames = nFrames;
        pEntry->nFlags |= 4;
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 0, pFile->aOffsets[nStart], nSize, 0, &tDesc, -2, gszSpriteCacheSourceFile, 0x369);
        nSize = FOG_AsyncDataGetBufferSize(pEntry->pAsync);
    }
    else
    {
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 0, pFile->aOffsets[nStart], nSize, 0, 0, -2, gszSpriteCacheSourceFile, 0x379);
    }

    D2_ASSERT(pEntry->pAsync, 0x37D);
    return nSize;
}

// 0x005FFA20

static int __stdcall D2CMPSpriteReadFramesAsync(D2CmpSpriteFileStrc* pFile, int nDirection, const char* szName, int nFrames, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext)
{
    D2_ASSERT(pFile, 0x38F);
    D2_ASSERT(pEntry, 0x390);
    D2_ASSERT(pContext, 0x391);

    unsigned int nStart = 0;
    unsigned int nEnd = 0;
    if (pContext->nType == 1 || pContext->nType == 0)
    {
        if (pContext->nType == 1 && nFrames == 1 && pFile->nDirections != 1)
        {
            return -1;
        }

        nStart = nDirection * nFrames;
        nEnd = nStart + nFrames;
    }

    const int nSize = pFile->aOffsets[nEnd] - pFile->aOffsets[nStart];
    D2_ASSERT(nSize, 0x3A9);
    D2_ASSERT(!pEntry->pAsync, 0x3AA);

    pEntry->nFrames = (unsigned char)nFrames;
    pEntry->nFirstFrame = (unsigned char)(nDirection * nFrames);
    pEntry->nFramesPerDirection = (unsigned char)pFile->nFramesPerDirection;
    pEntry->nDirections = (unsigned char)pFile->nDirections + 1;

    const unsigned int nBase = pFile->aOffsets[nStart];
    for (unsigned int i = nStart; i <= nEnd; ++i)
    {
        D2_ASSERT(i < 0x21, 0x3C1);
        const int nOffset = pFile->aOffsets[i] - nBase;
        pEntry->aOffsets[i] = nOffset;
        D2_ASSERT(nOffset >= 0, 0x3C3);
    }

    if (pFile->dwFlags & 2)
    {
        D2CmpLoadDescStrc tDesc;
        memset(&tDesc, 0, sizeof(tDesc));
        tDesc.pfnCallback = (void*)D2CMPSpriteAsyncLoadCallback;
        tDesc.pFile = pFile;
        tDesc.pFlags = &pEntry->nFlags;
        tDesc.nFirstFrame = nDirection * nFrames;
        tDesc.nFrames = nFrames;
        pEntry->nFlags |= 4;
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 1, pFile->aOffsets[nStart], nSize, 0, (int)&tDesc, -2, gszSpriteCacheSourceFile, 0x3DA);
    }
    else
    {
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 1, pFile->aOffsets[nStart], nSize, 0, 0, -2, gszSpriteCacheSourceFile, 0x3E6);
    }

    if (!pEntry->pAsync)
    {
        return -1;
    }

    return nSize;
}

// 0x005FFBE0
void __fastcall D2CMPSpriteCacheFreeAll(D2SpriteCacheStrc* pCache)
{
    while (pCache->nCount)
    {
        if (!D2CMPSpriteCacheEvict(pCache, 0, 1))
        {
            break;
        }
    }

    if (pCache->pNodes)
    {
        sub_0040B480(pCache->pMemPool, pCache->pNodes, ".\\SRC\\SpriteCache.cpp", 0x921, 0);
        pCache->pNodes = 0;
    }

    DeleteCriticalSection(&pCache->tLock);
    pCache->nArg = 0;
}

// 0x005FFC40
D2SpriteCacheNodeStrc* __fastcall D2CMPSpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked)
{
    D2_ASSERT(nSize < pCache->nMaxSize, 0x941);
    unsigned int dwOldest = 0;
    if (bLocked)
    {
        if (pCache->pHeadA)
        {
            dwOldest = pCache->pHeadA->dwTick;
        }
        if (pCache->pHeadB && dwOldest >= pCache->pHeadB->dwTick)
        {
            dwOldest = pCache->pHeadB->dwTick;
        }
    }
    D2SpriteCacheNodeStrc* pNode = D2CMPSpriteCacheTakeNode(nSize, bLocked, pCache);
    while (!pNode)
    {
        if (bLocked && GetTickCount() - dwOldest < 15000)
        {
            return 0;
        }
        if (!D2CMPSpriteCacheEvict(pCache, 0, 1))
        {
            return 0;
        }
        pNode = D2CMPSpriteCacheTakeNode(nSize, bLocked, pCache);
    }
    if (bLocked)
    {
        pNode->dwFlags |= 1;
    }
    else
    {
        pNode->dwFlags &= ~1;
    }
    pNode->pData = FOG_AllocPool(pCache->pMemPool, nSize, ".\\SRC\\SpriteCache.cpp", 0x96D, 0);
    pNode->nSize = nSize;
    pNode->nKey = nKey;
    pCache->nHits += 1;
    pCache->nRequests += 1;
    return pNode;
}

static __forceinline int SpriteCache_ShouldConvert(D2CmpSpriteContextStrc* pContext, int nDirection, unsigned int nFrames)
{
    unsigned int bConvert = 1;
    if (!(pContext->nType == 6 && (pContext->dwFlags & 2)))
    {
        if (!pContext->nType
            && (!(pContext->dwFlags & 8) || !pContext->nMode || pContext->nMode == 0x11 || gbCmpDisableConvert))
        {
            bConvert = 0;
        }
    }

    if (nDirection || nFrames <= 1 || !bConvert)
    {
        return 0;
    }

    return 1;
}

// 0x005FE990
static SpriteFile* __stdcall D2CMPSpriteLoadFile(D2CmpSpriteContextStrc* context, char* name, char* path)
{
    SpriteFile* file = 0;
    *path = 0;
    if (!D2CMPSpriteBuildName(context, name))
        return 0;
    HashNode* node = CelDataHashFind(&gtFileHash, name);
    if (node)
    {
        LRUCacheTouch(&gtFileCache, node->link);
        file = *(SpriteFile**)node->link;
    }
    else
    {
        if (!D2CMPSpriteBuildPath(name, context, path))
            return 0;
        node = CelDataHashAdd((void*)gtFileCache.unused, &gtFileHash, 0, name);
        SPRITE_ASSERT(node, 0x413);
        node->link = LRUCacheAlloc(&gtFileCache, 0xC0, node);
        SPRITE_ASSERT(node->link, 0x418);
        file = *(SpriteFile**)node->link;
        memset(file, 0, 0xC0);
        strcpy(file->name, name);
        if (*(unsigned char*)&context->dwGfxFlags & 1)
        {
            if (!CodecLoadTileHeader(path, file))
                *(unsigned char*)&file->flags |= 1;
        }
        else
        {
            FOG_FOpenFile(path, &path);
            if (path)
            {
                unsigned int header[7];
                memset(header, 0, sizeof(header));
                FOG_FReadFile(path, header, 0x18, 0, 0, 0, 0);
                unsigned int fileSize = FOG_FGetFileSize(path, 0);
                file->directions = header[4];
                file->frames = header[5];
                file->compression = header[1];
                file->version = header[0];
                file->format = header[2];
                unsigned int dwTotalCels = file->frames * file->directions;
                SPRITE_ASSERT(dwTotalCels < 0x4000, 0x444);
                unsigned int nBytes = dwTotalCels * 4;
                FOG_FReadFile(path, gaFileOffsets, nBytes, 0, 0, 0, 0);
                FOG_FCloseFile(path);
                SPRITE_ASSERT(file->directions < 0x21, 0x449);
                for (unsigned int i = 0; i < file->directions; ++i)
                {
                    unsigned int nIndex = i * file->frames;
                    file->offsets[i] = gaFileOffsets[nIndex];
                }
                file->offsets[file->directions] = fileSize;
            }
            else
                *(unsigned char*)&file->flags |= 1;
        }
    }
    SPRITE_ASSERT(file, 0x45C);
    return file;
}

// 0x006000B0
static void __stdcall D2CMPSpriteLoadConvertedEntry(int nDirection, unsigned int nFrames, char* szName, int bDC6, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile, char* szPath)
{
    if (!pFile || !pContext)
    {
        return;
    }

    if (!SpriteCache_ShouldConvert(pContext, nDirection, nFrames))
    {
        return;
    }

    unsigned int const tArg1 = nFrames * 2;
    const unsigned int nConverted = D2CMPSpriteCanConvertDirections(nFrames, tArg1);
    pContext->nDirection = (unsigned int)pFile->nDirections > 1 ? (nConverted << 6) / (unsigned int)pFile->nDirections : 1;

    if (GfxHashFind(&gCmpBlockTableB, pContext, &nDirection, &nFrames, pFile))
    {
        return;
    }

    D2_ASSERT(nDirection == 1, 0x686);
    D2_ASSERT(nFrames > 1, 0x687);

    if (!*szName && !D2CMPSpriteBuildName(pContext, szName))
    {
        return;
    }

    if (!*szPath && !D2CMPSpriteBuildPath(szName, pContext, szPath))
    {
        return;
    }

    if (bDC6)
    {
        D2CMPSpriteLoadDc6CacheEntry(pFile, nDirection, nFrames, szPath, pContext);
    }
    else
    {
        D2CMPSpriteLoadDc6Entry(pFile, nDirection, nFrames, szPath, pContext);
    }
}

// 0x006001F0
int __stdcall D2CMPSpriteValidate(D2CmpSpriteContextStrc* context, int async, int flags)
{
    if (!context)
        return 0;
    context->pFrame = 0;
    if (context->pCel)
    {
        context->pFrame = CelGetHandle(context);
        return 1;
    }
    char name[0x104];
    char path[0x104];
    SpriteFile* file = D2CMPSpriteLoadFile(context, name, path);
    unsigned int index = 0;
    unsigned int count = 0;
    HashNode* node = (HashNode*)GfxHashFind(&gCmpBlockTableB, context, (int*)&index, &count, (D2CmpSpriteFileStrc*)file);
    int result = 1;
    int loaded = 0;
    if (count > 1 && index > 0)
    {
        if (node)
        {
            if (!node->entry->pAsync)
                return 0;
            loaded = FOG_AsyncDataTestLoaded(node->entry->pAsync);
        }
        if (!node || !loaded)
        {
            if (!(file->flags & 1))
            {
                const unsigned int directions = file->directions;
                unsigned int frameDirection = (unsigned int)context->nDirection * directions;
                const int directionFlags = *(unsigned char*)&context->dwFlags & 4;
                frameDirection >>= 6;
                unsigned int direction = CelConvertDir(frameDirection, directions, count, directionFlags);
                if (file->directions > 1)
                    direction = (direction << 6) / file->directions;
                else
                    direction = 1;
                context->nDirection = direction;
                node = (HashNode*)GfxHashFind(&gCmpBlockTableB, context, (int*)&index, &count, (D2CmpSpriteFileStrc*)file);
            }
        }
    }
    if (node)
    {
        D2CmpSpriteEntryStrc* entry = node->entry;
        if (!entry || (*(unsigned char*)&entry->nFlags & 1) || !entry->pAsync)
            return 0;
        if (async)
            return FOG_AsyncDataTestLoaded(entry->pAsync) != 0;
        D2CMPSpriteCacheTouch(&gCmpTileCache, (D2SpriteCacheNodeStrc*)node->link);
        if (*(int*)((char*)entry + 0x28) == 0)
            D2CMPSpriteInitFrames((D2CmpSpriteFileStrc*)file, context, entry);
        context->pFrame = sub_005FEC50_GetCachedDC6Frame(context, entry);
        if (!context->pFrame)
        {
            if (!gnWarn)
                gnWarn = 1;
            return 0;
        }
        if (!loaded && !index && count > 1)
        {
            if (!path[0] && !D2CMPSpriteBuildPath(name, context, path))
                return 0;
            D2CMPSpriteLoadConvertedEntry(index, count, name, flags, context, (D2CmpSpriteFileStrc*)file, path);
        }
    }
    else
    {
        if (async)
            return 0;
        if (!path[0] && !D2CMPSpriteBuildPath(name, context, path))
            return 0;
        result = D2CMPSpriteLoadDc6Entry((D2CmpSpriteFileStrc*)file, index, count, path, context);
        if (result)
            D2CMPSpriteLoadConvertedEntry(index, count, name, flags, context, (D2CmpSpriteFileStrc*)file, path);
    }
    return result;
}

// 0x006004E0
int __stdcall D2CMPSpriteRequest(D2CmpSpriteContextStrc* context)
{
    SPRITE_ASSERT(context, 0x770);
    if (context->pCel)
    {
        context->pFrame = CelGetHandle(context);
        return 1;
    }
    char name[0x104];
    char path[0x104];
    SpriteFile* file = D2CMPSpriteLoadFile(context, name, path);
    if (!file)
        return 0;
    unsigned int index = 0;
    unsigned int count = 0;
    HashNode* node = (HashNode*)GfxHashFind((D2CmpBlockTableBStrc*)&gtHash, context, (int*)&index, &count, (D2CmpSpriteFileStrc*)file);
    if (node)
    {
        if (*(unsigned char*)&node->entry->nFlags & 1)
            context->dwGfxFlags |= 4;
        return 1;
    }
    if (count > 1 && index > 0 && !(file->flags & 1))
    {
        const unsigned int directions = file->directions;
        unsigned int frameDirection = (unsigned int)context->nDirection * directions;
        const int directionFlags = *(unsigned char*)&context->dwFlags & 4;
        frameDirection >>= 6;
        unsigned int direction = CelConvertDir(frameDirection, directions, count, directionFlags);
        if (file->directions > 1)
            direction = (direction << 6) / file->directions;
        else
            direction = 1;
        context->nDirection = direction;
        SPRITE_ASSERT((HashNode*)GfxHashFind((D2CmpBlockTableBStrc*)&gtHash, context, (int*)&index, &count, (D2CmpSpriteFileStrc*)file), 0x7AB);
        SPRITE_ASSERT(!index, 0x7AC);
    }
    if (!path[0] && !D2CMPSpriteBuildPath(name, context, path))
        return 0;
    return D2CMPSpriteLoadDc6CacheEntry((D2CmpSpriteFileStrc*)file, index, count, path, context);
}

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections)
{
// build: symbol ?gaDirectionIndex64@* 0x006E45A0
    return gaDirectionIndex64[sub_00517ABB_FindLowestSetBit(nDirections)][nDirection];
}

// 0x00600D60
int __stdcall CelGameDirToShadowGameDir(unsigned int nIndex, unsigned int nDirections)
{
    D2_ASSERT(nIndex < 64, 0x1DD);
    D2_ASSERT(sub_00517ABB_FindLowestSetBit(nDirections) < 8u, 0x1DE);
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1DF);
    return gaDirectionIndex64A[sub_00517ABB_FindLowestSetBit(nDirections)][nIndex];
}

// 0x00600E20
int __stdcall CelGameDirToNormalDir(unsigned int nIndex, unsigned int nDirections)
{
    D2_ASSERT(nIndex < 64, 0x1EC);
    D2_ASSERT(sub_00517ABB_FindLowestSetBit(nDirections) < 8u, 0x1ED);
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1EE);
    return gaDirectionIndex64B[sub_00517ABB_FindLowestSetBit(nDirections)][nIndex];
}

// 0x00601180
void __stdcall CelFileIteratePixels(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile->dwFlags & 4, 0x322);
    for (unsigned int nDirection = 0; nDirection < pCelFile->nDirections; nDirection++)
    {
        for (unsigned int nFrame = 0; nFrame < pCelFile->nCelsPerDirection; nFrame++)
        {
            CelIterateRgbPixels(pCelFile->pCels[nDirection * pCelFile->nCelsPerDirection + nFrame], nArg, pCelFile->nTermination);
        }
    }
}

// 0x00601450
void __stdcall CelFileTransform(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile, 0x431);
    for (unsigned int i = 0; i < pCelFile->nDirections * pCelFile->nCelsPerDirection; i++)
    {
        gpfnCelFileCellOp[pCelFile->nFormat](pCelFile->pCels[i], nArg);
    }
}

// 0x00601650
void __stdcall CelDrawEx(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nClipTop, int nClipRows, int nArg13)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->dwVersion == 6, 0x4C6);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x4C7);
    }
    D2_ASSERT(pBuffer, 0x4CA);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x4CD);
    nY += pCel->nYOffset;
    int nEnd = nY - nClipTop;
    nX += pCel->nXOffset;
    int nStart = nEnd - nClipRows;
    if (nEnd < 0 || nStart >= nHeight)
    {
        return;
    }
    if (nStart < 0)
    {
        nStart = 0;
    }
    if (nEnd >= nHeight)
    {
        nEnd = nHeight - 1;
    }
    const int nRows = nEnd - nStart;
    if (!nRows)
    {
        return;
    }
    CELDRAWFN pfnDraw = gpfnCelDraw[pCelFile->nFormat];
    D2_ASSERT(pfnDraw, 0x4E9);
    pfnDraw(pCel, &pBuffer[nEnd * nPitch + nX], nX, nArg4, nArg5, nPitch, nY - nEnd, nRows, nArg9, nArg10, nArg13);
}

// 0x00601810
int __stdcall CelValidateContext(D2CmpCelContextStrc* pContext)
{
    D2CmpCelFileViewStrc* pCelFile = (D2CmpCelFileViewStrc*)pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->nVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    return pContext->nFrame <= pCelFile->nFrames;
}

void __stdcall CelDrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->dwVersion == 6, 0x50D);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x50E);
    }

    D2_ASSERT(pBuffer, 0x511);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x514);

    nX += pCel->nXOffset + pCel->nYOffset / 2;
    nY += pCel->nYOffset / 2;
    int nLines = (unsigned int)pCel->nHeight / 2;
    int nSkip = 0;
    if (nY - pCel->nHeight / 2 < 0)
    {
        nLines = nY + 1;
    }

    if (nLines <= 0)
    {
        return;
    }

    if (nY >= nHeightLimit)
    {
        nSkip = nY - nHeightLimit + 1;
        nLines -= nSkip;
        if (nLines <= 0)
        {
            return;
        }
        nY = nHeightLimit - 1;
    }

    const int nStart = nX - nSkip;
    CelDrawRleShadow(pCel, pBuffer + nY * nPitch + nStart, nStart, nClipLeft, nClipRight, nPitch, nSkip, nLines, nTable, nColor);
}

int __stdcall CelGetHeight(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x589);

    return pCel->nHeight;
}

int __stdcall CelGetOffsetX(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x597);

    return pCel->nXOffset;
}

int __stdcall CelGetOffsetY(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x5A5);

    return pCel->nYOffset;
}

const char* __fastcall CelSkipRleLines(const char* pData, int nLines)
{
    if (!nLines)
    {
        return pData;
    }

    for (;;)
    {
        const char nRun = *pData++;
        if (nRun < 0)
        {
            if (!(nRun & 0x7F) && !--nLines)
            {
                break;
            }
        }
        else
        {
            pData += nRun;
        }
    }

    return pData;
}

D2TileListHeaderStrc* __cdecl TileAllocSubTile()
{
    D2TileListHeaderStrc* pHeader = (D2TileListHeaderStrc*)FOG_Alloc(sizeof(D2TileListHeaderStrc), ".\\SRC\\Tilecmp.cpp", 0x23, 0);
    D2_ASSERT(pHeader, 0x24);
    memset(pHeader, 0, sizeof(D2TileListHeaderStrc));
    return pHeader;
}

D2CmpTileStrc* __cdecl TileAlloc()
{
    D2CmpTileStrc* pTile = (D2CmpTileStrc*)FOG_Alloc(sizeof(D2CmpTileStrc), ".\\SRC\\Tilecmp.cpp", 0x45, 0);
    D2_ASSERT(pTile, 0x46);
    memset(pTile, 0, sizeof(D2CmpTileStrc));
    return pTile;
}

D2TileLibraryHashStrc* __fastcall TileProjectBuildFindTable(D2CmpTileLibraryStrc* pLibrary)
{
    D2TileLibraryHashStrc* pHash = sub_0060CDB0_AllocTileHash();
    D2_ASSERT(pHash, 0x3B9);
    D2_ASSERT(pLibrary, 0x3BA);

    for (int i = 0; i < pLibrary->nBlocks; ++i)
    {
        FindTileAddTile(pHash, &pLibrary->pBlocks[i]);
    }

    return pHash;
}

void __stdcall sub_M320_Emit_005FEC90(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    D2CMPSpriteInitFrames(pFile, pContext, pEntry);
}

int __stdcall sub_Emit_005FFE90(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    return D2CMPSpriteLoadDc6Entry(pFile, nArg2, nArg3, szName, pContext);
}

#include "gen/data/Source/D2CMP/SRC/SpriteCache.inc"
