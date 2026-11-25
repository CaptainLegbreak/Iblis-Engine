#include "D2CMP.h"
#include "D2SpriteCache.h"
#include "D2CmpCelFile.h"
#include "D2GameTypes.h"
#include "D2CmpTypes.h"
#include "D2CmpStormList.h"
#include "CELLIST.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SpriteCacheNodeStrc;
struct D2CriticalSectionStrc;
struct D2CmpCacheKeyStrc;
struct D2CmpCacheListEntryStrc;
struct D2CmpCelContextStrc;
struct D2TileListHeaderStrc;
struct D2CmpTileStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask); // 0x00517ABB
extern D2CmpPoolStrc gCmpPool; // 0x0088CAE0
extern void* gpfnTileFreeCallback; // 0x0088CB1C

extern D2SpriteCacheStrc gCmpTileCache; // 0x0089DB60
D2SpriteCacheNodeStrc* __fastcall D2CMPSpriteCacheEvict(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0
void __fastcall sub_0040AB00_FreeAsyncData(AsyncData* pAsync); // 0x0040AB00

void __fastcall CelDrawRleShadow(D2CelStrc* pCel, unsigned char* pDst, int nX, int nClipLeft, int nClipRight, int nPitch, int nSkip, int nLines, int nTable, int nColor); // 0x00608D60

void __fastcall FindTileAddTile(D2TileLibraryHashStrc* pHash, D2CmpTileBlockStrc* pTile); // 0x0060CFA0

typedef void (__stdcall* PixelDataFreeCallback)(void* pData);

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];


D2CmpCacheListEntryStrc* gpCmpCacheEntries; // 0x0089DB7C

// 0x005FF2A0
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

// 0x005FF3A0
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


// 0x00600C90
int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections)
{
// build: symbol ?gaDirectionIndex64@* 0x006E45A0
    return gaDirectionIndex64[sub_00517ABB_FindLowestSetBit(nDirections)][nDirection];
}

// 0x00600D30
int __stdcall D2CMPSpriteCanConvertDirections(int nDirections, int nNewDirections)
{
    if (nDirections == 4)
    {
        return 0;
    }

    if (nDirections == 8 && nNewDirections == 16)
    {
        return 1;
    }

    return 0;
}

// 0x00601730
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

// 0x006018F0
int __stdcall CelGetHeight(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x589);

    return pCel->nHeight;
}

// 0x00601920
int __stdcall CelGetOffsetX(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x597);

    return pCel->nXOffset;
}

// 0x00601950
int __stdcall CelGetOffsetY(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x5A5);

    return pCel->nYOffset;
}

// 0x00606D10
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



// 0x0060A440
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

#include "gen/data/Source/D2CMP/SRC/CelCmp_005FF2A0.inc"

PixelDataFreeCallback gpfnPixelDataFree; // 0x008E8CB8

// 0x006018C0
int __stdcall CelGetWidth(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1403);

    return pCel->nWidth;
}

// 0x006019F0
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pFile)
{
    D2_ASSERT(pFile->dwVersion == 6, 1489);

    return pFile->nCelsPerDirection;
}

// 0x00601A30
void __stdcall CelSetHardwareFreeCallback(PixelDataFreeCallback pfnCallback)
{
    gpfnPixelDataFree = pfnCallback;
}

// 0x00601A40
PixelDataFreeCallback __stdcall CelGetHardwareFreeCallback()
{
    return gpfnPixelDataFree;
}

// 0x00601B10
void* __stdcall CelGetHardwareData(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1578);

    return pCel->pBlockPixelData;
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return m_key;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// The cel list table's handle generator. It calls InternalFind out of line and keeps the table in esi across
// the call, so it was compiled without InternalFind's body in view: it stays in this file, apart from
// CelCmp.cpp's table members.
template<>
CELLIST* TSHashTable<CELLIST, HASHKEY_NONE>::InternalFind(unsigned int hashval, const HASHKEY_NONE& key);   // 0x006030E0

// build: symbol ?GenerateHandle@?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAEPAUHCELLIST__@@XZ 0x00603280
template<>
HCELLIST__* TSExportTableSimple<CELLIST, HCELLIST__*, 0>::GenerateHandle()
{
    for (;;)
    {
        ++m_sequence;
        if (!m_sequence)
        {
            m_wrapped = 1;
            continue;
        }
        if (!m_wrapped || !InternalFind(m_sequence, m_key))
            break;
    }
    return (HCELLIST__*)m_sequence;
}
