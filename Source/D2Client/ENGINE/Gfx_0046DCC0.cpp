#include "D2StateIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientGfx.h"
#include "D2ClientGfxState.h"
struct D2GfxListNodeStrc;
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2HashedFileEntryStrc;
struct D2HashedFileStrc;
struct D2StateNodeStrc;
struct D2StateOwnerStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);
extern "C" char* __cdecl _strlwr(char* szString);
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine);
extern int gnCofMemoryUsed; // 0x007A8918
// build: symbol ?gtGlobalHashedFile@* 0x007A78F0
extern D2HashedFileStrc gtGlobalHashedFile;
void __stdcall sub_M274_EmitBuildPath(char* szPath, int nMode);

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2StateOwnerStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0
static void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2StateNodeStrc* pOverlay); // 0x0046E040

int __cdecl sub_0045AE90(); // 0x0045AE90
extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void* __fastcall GFX_GetNodeValue(D2UnitStrc* pUnit, int nMode); // 0x0046E570
D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80
int __fastcall GFX_IsUnitOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0
int __stdcall PARTICLE_GetGfxOffsetX(D2UnitStrc* pUnit); // 0x004DA0B0
int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit); // 0x004DA0D0
int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit); // 0x004DA0F0
int __stdcall GFXUTIL_GetMotionRawAZ(D2UnitStrc* pUnit); // 0x004DA1B0
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040
int __fastcall GFXUTIL_GetCofLayerShadow(void* pGfx, int nLayer); // 0x004DB090
int __fastcall GFXUTIL_IsPlayerMonsterOrObject(D2UnitStrc* pUnit); // 0x004DB180
void __fastcall GFXUTIL_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, unsigned char nArg7, int nArg8); // 0x004DBB50
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
void __stdcall TEXTURE_CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY); // 0x004F6540
int __stdcall SCALE_CheckPerspectivePosition(int nX, int nY); // 0x004F66E0
void __stdcall SCALE_AdjustPerspectivePosition(int nX, int nY, int nBias, int* pX, int* pY); // 0x004F6760
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

// build: symbol ?GFX_HashName@* 0x0046DB90
static unsigned int GFX_HashName(const char* szName)
{
    D2_ASSERT(strlen(szName) < 8, 0x79);
    const unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nBucket = (nHash >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    return nBucket & 0x1FF;
}

// 0x0046DBF0
static void __fastcall GFX_GetBaseName(const char* szPath, char* szDest)
{
    const int nPathLength = strlen(szPath);
    if (szPath[nPathLength - 4] == 0x2E)
    {
        const char* pExt = szPath + nPathLength - 4;
        int nLength = 0;
        while (*pExt != 0x5C)
        {
            --pExt;
            ++nLength;
        }
        --nLength;
        strncpy(szDest, pExt + 1, nLength);
        szDest[nLength] = 0;
    }
}

D2HashedFileEntryStrc* __stdcall GFX_FindHashedEntry(D2HashedFileStrc* pTable, const char* szPath); // 0x0046DC40

// 0x0046DCC0
static D2HashedFileEntryStrc* __stdcall GFX_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    char* pName = szName;
    GFX_GetBaseName(szPath, pName);
    _strlwr(pName);
    if (!GFX_FindHashedEntry(pTable, pName))
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)FOG_Alloc(sizeof(D2HashedFileEntryStrc), ".\\ENGINE\\Gfx.cpp", 0xDC, 0);
        memset(pEntry, 0, sizeof(D2HashedFileEntryStrc));
        pEntry->nFlags |= 1;
        strcpy(pEntry->szName, szName);
        pEntry->pData = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPath, (unsigned int*)&pEntry->nSize, ".\\ENGINE\\Gfx.cpp", 0xE0);
        if (!pEntry->pData)
        {
            return 0;
        }

        D2_ASSERT(pEntry->pData[2] <= 0x40, 0xEC);
        const unsigned int nBucket = GFX_HashName(szName);
        pEntry->pNext = pTable->pEntries[nBucket];
        pTable->pEntries[nBucket] = pEntry;
        gnCofMemoryUsed += pEntry->nSize + sizeof(D2HashedFileEntryStrc);
        return pEntry;
    }
    return 0;
}

int __stdcall sub_M274_Emit_0046DCC0(int nMode, int nUnused)
{
    char szPath[0x110];
    sub_M274_EmitBuildPath(szPath, nMode);
    D2HashedFileStrc* const pTable = &gtGlobalHashedFile;
    if (!GFX_FindHashedEntry(pTable, szPath))
    {
        if (!GFX_LoadHashedEntry(pTable, szPath))
            return 0;
    }
    return 3;
}

// 0x0046DF40
static void __stdcall GFX_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode)
{
    const int nStateId = pNode->nStateId;
    const int bHasState = STATES_CheckState(pUnit, nStateId);
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 0);
    }
    if (!sub_0063A250(pUnit))
    {
        pNode->nCurrent = 0;
        if (bHasState)
        {
            STATES_ToggleState(pUnit, nStateId, 1);
        }
    }
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 1);
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nStateId && pEntry->dwType == 8)
        {
            pEntry->bSelected = 0;
            pEntry->nCurrent = -1;
        }
    }

    int nNext = 0;
    int nLowest = 0;
    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwType == 8)
        {
            if ((!nNext || pEntry->nStateId < nNext) && pEntry->nStateId > nStateId)
            {
                nNext = pEntry->nStateId;
            }
            if (!nLowest || pEntry->nStateId < nLowest)
            {
                nLowest = pEntry->nStateId;
            }
        }
    }
    if (!nNext)
    {
        nNext = nLowest;
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nNext && pEntry->dwType == 8)
        {
            pEntry->bSelected = 1;
            pEntry->nCurrent = 0;
        }
    }
}

// 0x0046E040
static void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2StateNodeStrc* pOverlay)
{
    D2StateOwnerStrc* ptGfxInfo = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(ptGfxInfo, 0x1BF);

    D2StateNodeStrc* pPrevious = 0;
    D2StateNodeStrc* pNode = ptGfxInfo->pFirst;
AdvanceToNextNode:
    if (pNode && pNode != pOverlay)
    {
        pPrevious = pNode;
        pNode = pNode->pNext;
        goto AdvanceToNextNode;
    }

    if (!pNode)
    {
        return;
    }

    if (pNode->pResource)
    {
        DLIGHTMAP_ReleaseLight(pNode->pResource);
        pNode->pResource = 0;
    }

    if (pPrevious)
    {
        pPrevious->pNext = pNode->pNext;
    }
    else
    {
        ptGfxInfo->pFirst = pNode->pNext;
    }

    if (pNode->dwType == 8)
    {
        GFX_RecalcStateOverlays(ptGfxInfo, pUnit, pNode);
    }

// build: symbol ?gszGfxFile@* 0x006D6C1C
    FOG_Free(pNode, gszGfxFile, 0x1E1, 0);
}

// calling-convention shim (not game code)
void __stdcall sub_0046E040_Shim(D2UnitStrc* pUnit, D2StateNodeStrc* pOverlay)
{
    GFX_RemoveStateOverlay(pUnit, pOverlay);
}

inline int UNITS_IsFlag5SetInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 5) & 1;
}

static inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit) bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

// 0x00471620
int __fastcall GFX_DrawUnitShadow(D2UnitStrc* pUnit)
{
    if (UNITS_IsFlag5SetInl(pUnit) || STATES_CheckState(pUnit, STATE_INVIS))
        return 0;

    if (!GFXUTIL_IsPlayerMonsterOrObject(pUnit))
    {
        sub_00471450(pUnit);
        return 1;
    }

    int nWeaponClass;
    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    int nWeaponClassId;
    int nUnused;
    int nFrameCount;
    int nVisible;
    int nComponent;
    int nClass;
    int nType;
    int nDrawY;
    unsigned char* pOrder;
    int bPerspective;
    int nFrame;
    void* pGfx;
    int nDirection;
    int nMode;
    D2GfxLayerHeaderStrc* pHeader;
    int nDrawX;
    int nPrevMode;
    int bTownMode;
    int nX;
    int nY;

    bTownMode = 0;
// build: symbol ?D2GFX_CheckUnitPerspective@* 0x004F5170
    nPrevMode = D2GFX_CheckUnitPerspective();
    if (nPrevMode && D2GFX_CheckPerspective() && pUnit == sub_00463DD0_GetPlayerUnit() && !sub_0046D9F0_TestUnit(pUnit))
    {
// build: symbol ?D2GFX_SetTownMode@* 0x004F5190
        D2GFX_SetTownMode(0);
        bTownMode = 1;
    }

    bPerspective = D2GFX_CheckPerspective();
    if (bPerspective)
    {
        int nHalf = GFXUTIL_GetMotionRawAZ(pUnit) / 2;
        int nPrecX = UNITS_GetPrecisionX(pUnit) - nHalf;
        int nPrecY = UNITS_GetPrecisionY(pUnit) - nHalf;
        if (!SCALE_CheckPerspectivePosition(nPrecX, nPrecY))
        {
            if (bTownMode)
                D2GFX_SetTownMode(nPrevMode);
            return 0;
        }

        SCALE_AdjustPerspectivePosition(nPrecX, nPrecY, 0, &nX, &nY);
        nX += PLAYER_GetScreenOffsetX();
        nY += PLAYER_GetScreenOffsetY() + 16;
    }
    else
    {
        int nHalf = PARTICLE_GetGfxClientZ(pUnit) / 2;
        nX = UNITS_GetClientCoordX(pUnit) + nHalf;
        nY = UNITS_GetClientCoordY(pUnit) + nHalf;
    }

    if (bTownMode)
        nY -= 8;

    nX += PARTICLE_GetGfxOffsetX(pUnit);
    nY += PARTICLE_GetGfxClientY(pUnit);

    nDrawX = nX - PLAYER_GetScreenOffsetX() - 2;
    nDrawY = nY - PLAYER_GetScreenOffsetY();
    if (pUnit && pUnit->dwUnitType == UNIT_OBJECT)
    {
        const int nObjectId = pUnit->dwClassId;
        D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
        nDrawX += pObjectsTxt->nXOffset;
        nDrawY += pObjectsTxt->nYOffset;
    }

    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nDrawX += -(gnScreenWidth_0071146C / 4);
            break;
        case 2:
            nDrawX += gnScreenWidth_0071146C / 4;
            break;
        }
    }

    if (!GFX_IsUnitOnScreen(pUnit, nDrawX, nDrawY, 0, 1))
    {
        if (bTownMode)
            D2GFX_SetTownMode(nPrevMode);
        return 0;
    }

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x926);

    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;

    nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, nMode, 0);
    if (!GFXUTIL_FindGfxListNode(pUnit, nWeaponClass, -1) && !GFX_LoadUnitGfxNode(pUnit, nWeaponClass, -1))
        return 0;

    pGfx = GFX_GetNodeValue(pUnit, nMode);
    if (!pGfx)
        return 0;

    pHeader = sub_004DB040_GetLayerHeader(pGfx);
    nDirection = UNITS_GetDirection(pUnit);
    GFXUTIL_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nComponent, &nUnused, pHeader->nArg, 1);
    pOrder = sub_004DB110_GetLayerOrder(pGfx, nComponent, nFrame);
    D2_ASSERT(pOrder, 0x94E);

    nVisible = 0;
    if (sub_004DBD30_CountVisibleLayers(pUnit, pHeader, pOrder, &nVisible, nDirection, nFrame) <= 0)
    {
        if (bTownMode)
            D2GFX_SetTownMode(nPrevMode);
        return 0;
    }

    for (unsigned int i = 0; i < pHeader->nLayers; i++)
    {
        int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 16, 0x960);
        if (GFXUTIL_GetCofLayerShadow(pGfx, nLayer))
        {
            D2CelContextStrc tContext;
            int nOut;
            memset(&tContext, 0, sizeof(tContext));
            if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, nDirection, nFrame, &nOut, nLayer, -1))
                TEXTURE_CelDrawShadow(&tContext, nDrawX, nDrawY);
        }
    }

    if (bTownMode)
        D2GFX_SetTownMode(nPrevMode);
    return 1;
}
