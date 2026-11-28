#include "D2LanguageNames.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientUi.h"
#include "D2StatIds.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2CommonApi2.h"
#include "D2GfxApi.h"

struct Unicode;

struct D2PanelAnimEntryStrc
{
    void* pData;
    char unk0x04[0x18];
};

struct D2DialogTimerStrc
{
    unsigned int dwTick;
    char unk0x04[0x50];
    unsigned int nVersion;
    char unk0x58[8];
    void (__cdecl* pfnCallback)();
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0








void __fastcall ROSTERPETS_RemoveHirelingEntries(int nUnused, int nKey);                                            // 0x00478AB0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080


int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480




extern D2PanelAnimEntryStrc gaPanelAnim[];                                                         // 0x00712020



extern int gbPopupOkPressed;                                                                               // 0x007A524C

extern int gnGlobal_007BB5DC;                                                                               // 0x007BB5DC

extern unsigned char gbGlobal_007BB5E0;                                                                     // 0x007BB5E0

extern D2InvRectStrc gtPlayerInvRect;                                                                     // 0x007BCAA0

#define gnGlobal_007BCAA0 (gtPlayerInvRect.nLeft)

#define gnGlobal_007BCAA4 (gtPlayerInvRect.nRight)

#define gnGlobal_007BCAA8 (gtPlayerInvRect.nTop)

#define gnGlobal_007BCAAC (gtPlayerInvRect.nBottom)

int gbPanelButtonDown;                                                                                      // 0x007BCE90

extern void* gpHelpYellowBulletCel;                                                                             // 0x007BEEF4


static int gbPopupMouseDown;                                                                               // 0x007A5248

static int gbPopupDismissed;                                                                               // 0x007A5254


static int gbPulseDone;                                                                               // 0x007A745C

static D2RosterPetStrc* gpRosterPets;                                                          // 0x007BB5BC

static int gnImeState;                                                                               // 0x007BB5F0

static int gnInvMouseX;                                                                               // 0x007BCA4C

static int gnInvMouseY;                                                                               // 0x007BCBD8


static int gbRedraw;                                                                               // 0x007C0280

static D2DialogTimerStrc* gpTimer_007C0E54;                                                                 // 0x007C0E54


struct D2RosterPetStrc;

struct D2Packet81ArgsStrc;

struct D2HirelingInfoStrc;


struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
    int unk0x08[2];
};






struct D2ClientEntryStrc;

enum D2C_RosterPetsConstants
{
    PET_TYPE_LIFE = 7,
};




// 0x00478A50
void __cdecl ROSTERPETS_FreeRosterPets()
{
    D2RosterPetStrc* pPet = gpRosterPets;
    while (pPet)
    {
        D2RosterPetStrc* pNext = pPet->pNext;
        FOG_Free(pPet, ".\\GAME\\RosterPets.cpp", 0x2F, 0);
        pPet = pNext;
    }
    gpRosterPets = 0;
}

// 0x00478A90
D2RosterPetStrc* __fastcall ROSTERPETS_FindRosterPet(int nKey)
{
    for (D2RosterPetStrc* pNode = gpRosterPets; pNode; pNode = pNode->pNext)
    {
        if (pNode->dwUnitId == nKey)
        {
            return pNode;
        }
    }
    return 0;
}

// 0x00478B10
void __fastcall ROSTERPETS_SetRosterEntry(int nKey, int nArg, int nType, int nValue)
{
    if (nType == 7)
    {
        ROSTERPETS_RemoveHirelingEntries(nKey, nKey);
    }
    for (D2RosterPetStrc* pNode = gpRosterPets; pNode; pNode = pNode->pNext)
    {
        if (pNode->dwUnitId == nKey)
        {
            pNode->nType = nType;
            pNode->dwOwnerId = nArg;
            pNode->nClassId = nValue;
            pNode->bDead = 0;
            return;
        }
    }
    D2RosterPetStrc* pNew = (D2RosterPetStrc*)FOG_Alloc(sizeof(D2RosterPetStrc), ".\\GAME\\RosterPets.cpp", 0x7A, 0);
    memset(pNew, 0, sizeof(D2RosterPetStrc));
    D2RosterPetStrc* pHead = gpRosterPets;
    pNew->dwUnitId = nKey;
    pNew->dwOwnerId = nArg;
    pNew->nType = nType;
    pNew->nClassId = nValue;
    pNew->nLifePercent = 0x64;
    pNew->pNext = pHead;
    gpRosterPets = pNew;
}

// 0x00478AB0
void __fastcall ROSTERPETS_RemoveHirelingEntries(int nUnused, int nKey)
{
    D2RosterPetStrc* pPrev = 0;
    for (D2RosterPetStrc* pNode = gpRosterPets; pNode; pNode = pNode->pNext)
    {
        if (pNode->nType == 7 && pNode->dwUnitId == nKey)
        {
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0x59, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x00478BB0
void __fastcall ROSTERPETS_AssignMercEntry(int nKey, int nArg, int nType, int nValue, D2Packet81ArgsStrc* pArgs)
{
    if (nType == 7)
        ROSTERPETS_RemoveHirelingEntries(nKey, nKey);

    D2RosterPetStrc* pNode;
    for (pNode = gpRosterPets; pNode && pNode->dwUnitId != nKey; pNode = pNode->pNext)
        ;

    ROSTERPETS_SetRosterEntry(nKey, nArg, nType, nValue);

    for (pNode = gpRosterPets; pNode && pNode->dwUnitId != nKey; pNode = pNode->pNext)
        ;
    D2_ASSERT(pNode, 0x95);

    pNode->dwUnitId = nKey;
    pNode->dwOwnerId = nArg;
    pNode->nType = nType;
    pNode->tEntry = *(D2ClientEntryStrc*)pArgs;

    if (nType == 7)
    {
        D2HirelingInfoStrc tInfo;
        tInfo.nSeed = pArgs->nArg0C;
        tInfo.f_0 = (unsigned short)pArgs->nArg10;
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nKey, 1);
        if (pUnit)
        {
            MONSTER_InitHireling(pUnit, &tInfo);
            CUNIT_UpdateAttackableFlag(pUnit);
            MONSTER_SetMonsterLight(pUnit);
            UNITS_ChangeAnimMode(pUnit, 1);
        }
    }
}

// 0x00478C90
void __fastcall ROSTERPETS_DropPetEntry(int nKey)
{
    D2RosterPetStrc* pPrev = 0;
    for (D2RosterPetStrc* pNode = gpRosterPets; pNode; pNode = pNode->pNext)
    {
        if (pNode->dwUnitId == nKey)
        {
            if (pNode->nType == 7)
            {
                D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
                if (pNode->dwOwnerId == (!pPlayer ? -1 : pPlayer->dwUnitId))
                {
                    pNode->bDead = 1;
                    return;
                }
            }
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0xD1, 0);
            return;
        }
        pPrev = pNode;
    }
}

#define PETTYPE_FLAG_PARTY 4

struct D2PetTypeTxt;



extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

inline D2PetTypeTxt* PETTXT_GetRecordInl(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x00478D10
int __fastcall ROSTERPETS_GetPetOwnerRelation(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
            const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
            if (pPet->dwOwnerId == nPlayerId)
            {
                return 1;
            }

            const unsigned short nPartyId = ROSTER_GetEntryIndex(ROSTER_FindRosterUnitById(nPlayerId));
            if (nPartyId == 0xFFFF || nPartyId != ROSTER_GetEntryIndex(ROSTER_FindRosterUnitById(pPet->dwOwnerId)))
            {
                break;
            }
            return 2;
        }
    }
    return 0;
}

// 0x00478D90
int __fastcall ROSTERPETS_GetPetRelation(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = PETTXT_GetRecordInl(pPet->nType);
            if (!pPetTypeTxtRecord)
            {
                return 3;
            }

            if (!(pPetTypeTxtRecord->nPetFlags[PETTYPE_FLAG_PARTY >> 3] & gdwBitMasks[PETTYPE_FLAG_PARTY & 7]))
            {
                return 3;
            }

            D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
            const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
            if (pPet->dwOwnerId == nPlayerId)
            {
                return 1;
            }

            const unsigned short nPartyId = ROSTER_GetEntryIndex(ROSTER_FindRosterUnitById(nPlayerId));
            if (nPartyId == 0xFFFF || nPartyId != ROSTER_GetEntryIndex(ROSTER_FindRosterUnitById(pPet->dwOwnerId)))
            {
                break;
            }
            return 2;
        }
    }
    return 0;
}


// 0x00478E40
D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nKey)
            return &pPet->tEntry;
    }
    return 0;
}




static inline D2RosterPetStrc* PETS_FindRosterPetInl(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet;
        }
    }

    return 0;
}

// 0x00478E70
int __fastcall ROSTERPETS_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    D2RosterPetStrc* pPet = PETS_FindRosterPetInl(!pUnit ? -1 : pUnit->dwUnitId);
    if (!pUnit || !pPlayer)
    {
        return 1;
    }

    const int nPlayerId = pPlayer->dwUnitId;
    if (!pPet)
    {
        const int nType = pPlayer->dwUnitType;
        if (nType == 1 && pUnit->dwUnitType == nType && STATLIST_AreUnitsAligned(pPlayer, pUnit))
        {
            return 0;
        }

        return 1;
    }

    const int nOwnerId = pPet->dwOwnerId;
    if (nOwnerId == nPlayerId)
    {
        return 0;
    }

    return ROSTER_IsHostileRelation(nPlayerId, nOwnerId);
}

// 0x00478EE0
int __fastcall ROSTERPETS_CountPets(D2UnitStrc* pOwner, int nType)
{
    D2RosterPetStrc* pPet = gpRosterPets;
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    int nCount = 0;
    for (; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == nType && pPet->dwOwnerId == nOwnerId)
            ++nCount;
    }
    return nCount;
}

// 0x00478F20
int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny)
{
    if (!pUnit)
        return -1;

    const int nUnitId = pUnit->dwUnitId;
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == nType && pPet->dwOwnerId == nUnitId && (bAny || !pPet->bDead))
            return pPet->dwUnitId;
    }

    return -1;
}

// 0x00478F70
int __fastcall ROSTERPETS_HasPets(D2UnitStrc* pOwner)
{
    D2RosterPetStrc* pPet = gpRosterPets;
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    for (; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwOwnerId == nOwnerId)
            return 1;
    }
    return 0;
}

struct D2GfxLightStrc;


// 0x00478FA0
void __cdecl GFX_UpdatePetFlags()
{
    D2RosterPetStrc* pPet = gpRosterPets;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    for (; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == 4)
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPet->dwUnitId, 1);
            if (pUnit)
            {
                int bSet = !ROSTERPETS_IsPetFriendly(pPlayer, pUnit);
                CUNIT_SetBasePalShiftIndex(pUnit, bSet);
                CUNIT_SetPalShiftIndex(pUnit, bSet);
            }
        }
    }
}





// 0x00479010
void __fastcall VIEW_UpdatePetLife(int nUnitId, int nLifePercent, unsigned short nArg)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            pPet->nLifePercent = nLifePercent;
            pPet->nArg10 = nArg;
            if (pPet->nType == PET_TYPE_LIFE)
            {
                D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, UNIT_MONSTER);
                if (pUnit)
                    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pUnit) * nLifePercent / 100, 0);
            }
            return;
        }
    }
}

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
};

// 0x00479080
int __fastcall ROSTER_GetPetLife(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet->nLifePercent;
        }
    }

    return 0;
}

struct D2ClientNodeStrc;

struct D2ClientNodeStrc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x08];
    int nValueA;
    int nValueB;
    char unk0x1C[0x14];
    D2ClientNodeStrc* pNext;
};


extern D2ClientNodeStrc* gpNodeList_007BB5BC; // 0x007BB5BC


// 0x004790B0
void __fastcall INV_FindNodeValues(int nId, int* pValueA, int* pValueB)
{
    for (D2ClientNodeStrc* pNode = gpNodeList_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
        {
            *pValueA = pNode->nValueA;
            *pValueB = pNode->nValueB;
            return;
        }
    }
    *pValueA = 0;
    *pValueB = 0;
}

// 0x004790F0
int __fastcall sub_004790F0(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet->nArg10;
        }
    }
    return 0;
}

// 0x00479120
int __fastcall ROSTERPETS_GetHirelingClassId(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
            return pPet->nClassId;
    }
    return 0;
}

// 0x00479150
int __fastcall ROSTERPETS_FindRosterIndex(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
            return pPet->dwOwnerId;
    }
    return -1;
}

// 0x00479180
int __fastcall ROSTER_GetPetType(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet->nType;
        }
    }

    return 0;
}

// 0x004791B0
int __fastcall ROSTERPETS_IsOwnedByPlayer(D2UnitStrc* pUnit)
{
    const int nOwnerId = ROSTERPETS_FindRosterIndex(!pUnit ? -1 : pUnit->dwUnitId);
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    const int nPlayerId = pPlayer ? pPlayer->dwUnitId : -1;
    D2_ASSERT(nPlayerId != -1, 0x225);
    if (nOwnerId != -1)
        return GFXUTIL_TestRelationFlags(nOwnerId, nPlayerId, 8);

    return 1;
}





// 0x00479230
void __fastcall WARDENCLIENT_UpdateOwnerPetFlags(int nOwnerId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwOwnerId == nOwnerId)
        {
            switch (pPet->nClassId)
            {
            case 0x16B:
            case 0x16C:
            {
                D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPet->dwUnitId, UNIT_MONSTER);
                if (pUnit)
                {
                    int nFlagB = CUNIT_GetPalShiftIndex(pUnit);
                    int bSet = !ROSTERPETS_IsOwnedByPlayer(pUnit);
                    if (nFlagB == CUNIT_GetBasePalShiftIndex(pUnit))
                    {
                        CUNIT_SetPalShiftIndex(pUnit, bSet);
                    }
                    CUNIT_SetBasePalShiftIndex(pUnit, bSet);
                }
                break;
            }
            }
        }
    }
}

// 0x004890B0
int __stdcall ROSTERPETS_HandleRectClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (nX < gnGlobal_007BCAA0 || nX >= gnGlobal_007BCAA4 || nY < gnGlobal_007BCAA8 || nY > gnGlobal_007BCAAC)
    {
        gbPanelButtonDown = 0;
        return 0;
    }
    if (nX >= gnScreenWidth - gnPanelOffsetX - 0x12E && nX <= gnScreenWidth - gnPanelOffsetX - 0x10E
        && nY >= gnScreenHeight + gnPanelOffsetY - 0x60 && nY <= gnScreenHeight + gnPanelOffsetY - 0x40
        && gbPanelButtonDown)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        sub_004C0440();
    }
    gbPanelButtonDown = 0;
    return 1;
}



// 0x004A5980
void __stdcall ROSTERPETS_HandlePanelButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    gbRedraw = 1;
    sub_004A4AD0_Press(pMsg->nXpos, pMsg->nYpos);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

extern "C" void __cdecl CURSOR_DrawDefaultCursor(); // 0x004683C0
extern "C" void __cdecl CURSOR_DrawCursorCel(); // 0x00468460
