#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CltUnitEventStrc;
struct D2RosterInfoStrc;


struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned short wPartyFlags;
    unsigned short wPartyFlagsHigh;
    D2RosterInfoStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
D2UnitGfxDataStrc* __cdecl GFX_AllocGfxData(); // 0x0046EBB0

// 0x004DC270
D2RosterInfoStrc** __cdecl PLAYERLIST_AllocRosterInfoList()
{
    D2RosterInfoStrc** ppRosterInfo = (D2RosterInfoStrc**)FOG_Alloc(sizeof(D2RosterInfoStrc*), ".\\UNIT\\PlayerList.cpp", 0x25, 0);
    D2_ASSERT(ppRosterInfo, 0x27);
    *ppRosterInfo = 0;
    return ppRosterInfo;
}

// 0x004DC2B0
void __fastcall PLAYERLIST_FreeRosterInfoList(D2RosterInfoStrc** ppRosterInfo)
{
    if (ppRosterInfo)
    {
        D2RosterInfoStrc* pRosterInfo = *ppRosterInfo;
        while (pRosterInfo)
        {
            D2RosterInfoStrc* pNext = pRosterInfo->pNext;
            FOG_Free(pRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x3C, 0);
            pRosterInfo = pNext;
        }
        FOG_Free(ppRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x40, 0);
    }
}

// 0x004DC2F0
static inline D2RosterInfoStrc* PLAYERLIST_FindRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo;
        }
    }
    return 0;
}

// 0x004DC320
void __fastcall PLAYERLIST_AddRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    D2RosterInfoStrc** ppSearch = ROSTER_GetRosterInfoList(nUnitId1);
    if (ppSearch)
    {
        for (D2RosterInfoStrc* pRosterInfo = *ppSearch; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
        {
            if (pRosterInfo->dwUnitId == nUnitId2)
            {
                return;
            }
        }
    }

    D2RosterInfoStrc* pNew = (D2RosterInfoStrc*)FOG_Alloc(sizeof(D2RosterInfoStrc), ".\\UNIT\\PlayerList.cpp", 0x74, 0);
    memset(pNew, 0, sizeof(D2RosterInfoStrc));
    pNew->dwUnitId = nUnitId2;
    pNew->pNext = *ppRosterInfo;
    *ppRosterInfo = pNew;
}

// 0x004DC510
void __fastcall PLAYERLIST_InitGfxData(D2UnitStrc* pUnit)
{
    pUnit->pGfxData = GFX_AllocGfxData();
    D2_ASSERT(pUnit->pGfxData, 0x16);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_OBJECT:
        GFX_RefreshUnitGfx(pUnit, 0);
        break;

    case UNIT_MONSTER:
        GFX_RefreshUnitGfx(pUnit, 1);
        break;

    case UNIT_MISSILE:
    case UNIT_ITEM:
        break;

    default:
        D2_ASSERT(0, 0x28);
        break;
    }
}

// 0x004DDDF0
void __cdecl sub_004DDDF0_Nop()
{
}

D2RosterInfoStrc* __stdcall sub_M121_Emit_004DC2F0(int nUnitId1, int nUnitId2) { return PLAYERLIST_FindRosterInfo(nUnitId1, nUnitId2); }

// 0x004DC380
void __fastcall PLAYERLIST_RemoveRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    D2RosterInfoStrc* pPrevious = 0;
    if (!ppRosterInfo)
    {
        return;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pRosterInfo->pNext;
            }
            else
            {
                *ppRosterInfo = pRosterInfo->pNext;
            }
            FOG_Free(pRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x97, 0);
            return;
        }
        pPrevious = pRosterInfo;
    }
}


// 0x004DCA20
int __fastcall PLAYERLIST_CallDrawSimpleShadow(D2UnitStrc* pUnit)
{
// build: symbol ?GFX_DrawSimpleUnitShadow@* 0x00471450
    return GFX_DrawSimpleUnitShadow(pUnit);
}
