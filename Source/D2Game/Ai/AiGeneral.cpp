#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x00736160

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

struct D2MonsterDataStrc;

struct D2AiCmdStrc;

struct D2MinionListStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

#include "D2GameFuncs.h"


void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

D2AiCmdStrc* __fastcall AIGENERAL_AllocAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                     // 0x0058EC90


extern const char gszAiGeneralSourceFile[]; // 0x006E1B24


extern const char gszAiGeneralSourceFile[]; // 0x006E1B24

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C


static inline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return UNIT_INVALID;
    return pUnit->dwUnitType;
}

static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit || sub_GetUnitTypeOrInvalid(pUnit) != UNIT_MONSTER)
        return 0;
    if (!pUnit->pMonsterData)
        return 0;
    return pUnit->pMonsterData->pAiControl;
}

__forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitByType(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EBC0
D2AiControlStrc* __fastcall AIGENERAL_AllocAiControl(D2GameStrc* pGame)
{
    D2AiControlStrc* pAiControl = (D2AiControlStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2AiControlStrc), ".\\Ai\\AiGeneral.cpp", 0x1B, 0);
    memset(pAiControl, 0, sizeof(D2AiControlStrc));
    pAiControl->dwOwnerGUIDEx = -1;
    pAiControl->dwOwnerTypeEx = UNIT_MONSTER;
    pAiControl->dwOwnerGUID = -1;
    pAiControl->dwOwnerType = UNIT_MONSTER;

    return pAiControl;
}

// 0x0058EC00
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pMonster);
    if (!pAiControl)
    {
        return;
    }

    switch (nIndex)
    {
    case 1:
        pAiControl->dwAiParam[0] = nParamValue;
        break;

    case 2:
        pAiControl->dwAiParam[1] = nParamValue;
        break;

    case 3:
        pAiControl->dwAiParam[2] = nParamValue;
        break;

    default:
        break;
    }
}

// 0x0058EC50
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (pAiControl)
    {
        switch (nIndex)
        {
        case 1:
            return pAiControl->dwAiParam[0];

        case 2:
            return pAiControl->dwAiParam[1];

        case 3:
            return pAiControl->dwAiParam[2];

        default:
            break;
        }
    }

    return 0;
}

// 0x0058EC90
D2AiCmdStrc* __fastcall AIGENERAL_AllocAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    D2AiCmdStrc* pAiCmd = (D2AiCmdStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2AiCmdStrc), ".\\Ai\\AiGeneral.cpp", 0x65, 0);
    memset(pAiCmd, 0, sizeof(D2AiCmdStrc));
    D2AiCmdStrc* pLastCmd = pAiControl->pLastCmd;
    if (!pLastCmd)
    {
        pAiControl->pLastCmd = pAiCmd;
        pAiControl->pCurrentCmd = pAiCmd;
        pAiCmd->pNextCmd = pAiCmd;
        pAiCmd->pPrevCmd = pAiCmd;
    }
    else
    {
        D2AiCmdStrc* pCurrentCmd = pAiControl->pCurrentCmd;
        if (pLastCmd == pCurrentCmd)
        {
            pAiControl->pLastCmd = pAiCmd;
        }

        pAiCmd->pNextCmd = pCurrentCmd;
        pAiCmd->pPrevCmd = pAiControl->pCurrentCmd->pPrevCmd;
        pAiControl->pCurrentCmd->pPrevCmd = pAiCmd;
        pAiCmd->pPrevCmd->pNextCmd = pAiCmd;
    }

    return pAiCmd;
}

// 0x0058ED10
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return;
    }

    D2AiCmdStrc* pCurrentCmd = pAiControl->pCurrentCmd;
    if (!pCurrentCmd)
    {
        return;
    }

    if (pCurrentCmd != pCurrentCmd->pNextCmd)
    {
        if (pAiControl->pLastCmd == pCurrentCmd)
        {
            pAiControl->pLastCmd = pCurrentCmd->pNextCmd;
        }

        pAiControl->pCurrentCmd = pCurrentCmd->pNextCmd;
        pCurrentCmd->pPrevCmd->pNextCmd = pCurrentCmd->pNextCmd;
        pCurrentCmd->pNextCmd->pPrevCmd = pCurrentCmd->pPrevCmd;
    }
    else
    {
        pAiControl->pLastCmd = 0;
        pAiControl->pCurrentCmd = 0;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentCmd, ".\\Ai\\AiGeneral.cpp", 0xA1, 0);
}

// 0x0058ED80
static void AIGENERAL_FreeAiControlCommands(D2GameStrc* pGame, D2AiControlStrc* pAiControl)
{
    while (pAiControl->pLastCmd)
    {
        D2AiCmdStrc* pCurrentCmd = pAiControl->pCurrentCmd;
        if (!pCurrentCmd)
        {
            break;
        }

        if (pCurrentCmd != pCurrentCmd->pNextCmd)
        {
            if (pAiControl->pLastCmd == pCurrentCmd)
            {
                pAiControl->pLastCmd = pCurrentCmd->pNextCmd;
            }

            pAiControl->pCurrentCmd = pCurrentCmd->pNextCmd;
            pCurrentCmd->pPrevCmd->pNextCmd = pCurrentCmd->pNextCmd;
            pCurrentCmd->pNextCmd->pPrevCmd = pCurrentCmd->pPrevCmd;
        }
        else
        {
            pAiControl->pLastCmd = 0;
            pAiControl->pCurrentCmd = 0;
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentCmd, ".\\Ai\\AiGeneral.cpp", 196, 0);
    }
}

// 0x0058EDE0
void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1 || !pUnit->pMonsterData)
    {
        return;
    }

    D2AiControlStrc* pAiControl = pUnit->pMonsterData->pAiControl;
    if (!pAiControl || !pAiControl->pLastCmd)
    {
        return;
    }

    do
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            D2AiControlStrc* pCurrentAiControl = pUnit->pMonsterData->pAiControl;
            if (pCurrentAiControl)
            {
                D2AiCmdStrc* pCurrentCmd = pCurrentAiControl->pCurrentCmd;
                if (pCurrentCmd)
                {
                    if (pCurrentCmd != pCurrentCmd->pNextCmd)
                    {
                        if (pCurrentAiControl->pLastCmd == pCurrentCmd)
                        {
                            pCurrentAiControl->pLastCmd = pCurrentCmd->pNextCmd;
                        }

                        pCurrentAiControl->pCurrentCmd = pCurrentCmd->pNextCmd;
                        pCurrentCmd->pPrevCmd->pNextCmd = pCurrentCmd->pNextCmd;
                        pCurrentCmd->pNextCmd->pPrevCmd = pCurrentCmd->pPrevCmd;
                    }
                    else
                    {
                        pCurrentAiControl->pLastCmd = 0;
                        pCurrentAiControl->pCurrentCmd = 0;
                    }

                    FOG_FreePool(pGame->pMemoryPool, pCurrentCmd, ".\\Ai\\AiGeneral.cpp", 0xA1, 0);
                }
            }
        }
    }
    while (pAiControl->pLastCmd);
}

// 0x0058EE80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0058EE80(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    D2AiControlStrc* pAiControl = pData ? pData->pAiControl : 0;
    if (!pAiControl) {
        return 0;
    }
    return (unsigned int)pAiControl->pCurrentCmd;
}

// 0x0058EEA0
void __fastcall AIGENERAL_StepCurrentAiCommand(D2UnitStrc* pUnit, int nSteps, D2AiCmdStrc* pAiCmd)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return;
    }

    if (!pAiCmd)
    {
        pAiCmd = pAiControl->pCurrentCmd;
        if (!pAiCmd)
        {
            return;
        }

        if (nSteps < 0)
        {
            for (int i = nSteps; i < 0; ++i)
            {
                pAiCmd = pAiCmd->pPrevCmd;
            }
        }
        else
        {
            while (nSteps)
            {
                --nSteps;
                pAiCmd = pAiCmd->pNextCmd;
            }
        }
    }

    pAiControl->pCurrentCmd = pAiCmd;
}

// 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    D2AiCmdStrc* pCurrentAiCmd = pAiControl->pCurrentCmd;
    if (!pCurrentAiCmd)
    {
        return 0;
    }

    D2AiCmdStrc* pAiCmd = pCurrentAiCmd->pNextCmd;
    while (pAiCmd->nCmdParam[0] != nCmdParam)
    {
        if (pAiCmd == pCurrentAiCmd)
        {
            break;
        }

        pAiCmd = pAiCmd->pNextCmd;
    }

    if (pAiCmd->nCmdParam[0] != nCmdParam)
    {
        return 0;
    }

    if (bSet)
    {
        pAiControl->pCurrentCmd = pAiCmd;
    }

    return pAiCmd;
}

// 0x0058F810
void __fastcall AIGENERAL_FreeAiControl(D2GameStrc* pGame, D2AiControlStrc* pAiControl)
{
    if (!pAiControl)
    {
        return;
    }

    if (pAiControl->pMapAi)
    {
        DRLGPRESET_FreeMapAI(pGame->pMemoryPool, pAiControl->pMapAi);
    }

    D2MinionListStrc* pNext = 0;
    for (D2MinionListStrc* i = pAiControl->pMinionList; i; i = pNext)
    {
        pNext = i->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, i, ".\\Ai\\AiGeneral.cpp", 582, 0);
    }

    AIGENERAL_FreeAiControlCommands(pGame, pAiControl);
    FOG_FreeServerMemory(pGame->pMemoryPool, pAiControl, ".\\Ai\\AiGeneral.cpp", 413, 0);
}

// 0x0058EF40
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd)
{
    D2AiCmdStrc* pCopy = AIGENERAL_AllocAiCommand(pGame, pUnit);
    memcpy(pCopy->nCmdParam, pAiCmd->nCmdParam, sizeof(pCopy->nCmdParam));

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (pAiControl)
    {
        pAiControl->pCurrentCmd = pCopy;

        while (!pAiControl)
        {
        }
    }
}

// 0x0058EFA0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet)
{
    if (!AIGENERAL_GetAiCommandFromParam(pUnit, nCmdParam, bSet))
    {
        D2AiCmdStrc tAiCmd;
        tAiCmd.nCmdParam[0] = nCmdParam;
        tAiCmd.nCmdParam[1] = 0;
        tAiCmd.nCmdParam[2] = 0;
        tAiCmd.nCmdParam[3] = 0;
        tAiCmd.nCmdParam[4] = 0;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &tAiCmd);
    }

    return AIGENERAL_GetAiCommandFromParam(pUnit, nCmdParam, bSet);
}

// 0x0058F000
extern "C" __declspec(dllexport) unsigned int* __stdcall sub_0058F000(D2UnitStrc* pUnit) {
    D2AiControlStrc* pAiControl;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        pAiControl = pUnit->pMonsterData->pAiControl;
    } else {
        pAiControl = 0;
    }
    return (unsigned int*)&pAiControl->pMapAi;
}

// 0x0058F030
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    if (bSetFlag2)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 2, 1);
    }

    if (bSetFlag1)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 1, 1);
    }

    pAiControl->dwOwnerGUIDEx = nOwnerGUID;
    pAiControl->dwOwnerTypeEx = nOwnerType;
    pAiControl->pGame = pGame;
}

// 0x0058F090
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pUnitGUID, int* pUnitType)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        *pUnitGUID = -1;
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    if (!pAiControl->pGame)
    {
        *pUnitGUID = -1;
        return;
    }

    *pUnitGUID = pAiControl->dwOwnerGUIDEx;
    *pUnitType = pAiControl->dwOwnerTypeEx;
}

// 0x0058F0D0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    if (!pAiControl->pGame)
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
}

// noinline: AIGENERAL_TransferMinionsToNewLeader (0x0058F530) calls AIGENERAL_AllocMinionList (0x0058F100); the image calls it out of line there.
// 0x0058F100
__declspec(noinline) void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    D2MinionListStrc* pMinionList = (D2MinionListStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2MinionListStrc), ".\\Ai\\AiGeneral.cpp", 499, 0);
    memset(pMinionList, 0, sizeof(D2MinionListStrc));
    pMinionList->dwMinionGUID = !pMinion ? -1 : pMinion->dwUnitId;
    if (pAiControl->pMinionList)
    {
        pMinionList->pNext = pAiControl->pMinionList;
    }
    pAiControl->pMinionList = pMinionList;
}

// 0x0058F160
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || sub_GetUnitTypeOrInvalid(pOwner) != UNIT_MONSTER)
        return;

    D2AiControlStrc* pOwnerControl = AIGENERAL_GetAiControlFromUnit(pOwner);
    D2MinionListStrc* pList = pOwnerControl->pMinionList;
    D2MinionListStrc* pPrevious = 0;
    const int nUnitGUID = pUnit->dwUnitId;
    D2GameStrc* pGame = pOwnerControl->pGame;
    for (; pList; pList = pList->pNext)
    {
        if (pList->dwMinionGUID == nUnitGUID)
        {
            D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pList->dwMinionGUID);
            if (sub_GetUnitTypeOrInvalid(pMinion) == UNIT_MONSTER)
            {
                D2AiControlStrc* pMinionControl = AIGENERAL_GetAiControlFromUnit(pMinion);
                pMinionControl->dwOwnerGUIDEx = -1;
                pMinionControl->dwOwnerTypeEx = UNIT_MONSTER;
                pMinionControl->pGame = pGame;
            }

            if (pPrevious)
                pPrevious->pNext = pList->pNext;
            else
                pOwnerControl->pMinionList = pList->pNext;

            FOG_FreePool(pGame->pMemoryPool, pList, gszAiGeneralSourceFile, 0x217, 0);
            return;
        }

        pPrevious = pList;
    }
}

// 0x0058F260
void __fastcall AIGENERAL_DetachOwnedMinions(D2UnitStrc* pUnit)
{
 D2AiControlStrc* control=AIGENERAL_GetAiControlFromUnit(pUnit);
 if(!control || !control->pGame) return;
 D2UnitStrc* owner=SUNIT_GetServerUnit(control->pGame,control->dwOwnerTypeEx,control->dwOwnerGUIDEx);
 if(!owner || owner!=pUnit) return;
 const int ownerType=sub_GetUnitTypeOrInvalid(owner);
 if(ownerType!=UNIT_MONSTER) return;
 D2AiControlStrc* ownerControl=AIGENERAL_GetAiControlFromUnit(owner);
 D2MinionListStrc* node=ownerControl->pMinionList;
 D2GameStrc* game=ownerControl->pGame;
 while(node) {
  D2MinionListStrc* next=node->pNext;
  D2UnitStrc* minion=SUNIT_GetServerUnit(game,UNIT_MONSTER,node->dwMinionGUID);
  const int type=sub_GetUnitTypeOrInvalid(minion);
  if(type==UNIT_MONSTER) {
   D2AiControlStrc* minionControl=AIGENERAL_GetAiControlFromUnit(minion);
   minionControl->dwOwnerGUIDEx=-1;
   minionControl->dwOwnerTypeEx=1;
   minionControl->pGame=game;
  }
  FOG_FreePool(game->pMemoryPool,node,gszAiGeneralSourceFile,567,0);
  node=next;
 }
 ownerControl->pMinionList=0;
}

// 0x0058F350
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList)
{
    while (pMinionList)
    {
        D2MinionListStrc* pNext = pMinionList->pNext;
        FOG_FreePool(pGame->pMemoryPool, pMinionList, ".\\Ai\\AiGeneral.cpp", 582, 0);
        pMinionList = pNext;
    }
}

// 0x0058F380
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* pCallbackArg1, void* pCallbackArg2, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*))
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)pfnParty), 590);

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    if (!pAiControl || !pAiControl->pGame)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pOwnerAiControl = AIGENERAL_GetAiControlFromUnitByType(pOwner);
    D2GameStrc* pGame = pOwnerAiControl->pGame;
    D2MinionListStrc* pMinionList = pOwnerAiControl->pMinionList;
    while (pMinionList)
    {
        D2MinionListStrc* pNext = pMinionList->pNext;
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            pfnParty(pMinion, pCallbackArg1, pCallbackArg2);
        }
        pMinionList = pNext;
    }
}

// 0x0058F440
void __fastcall AIGENERAL_GetAiControlInfo(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType, int* pAiControlFlag1, int* pAiControlFlag2, D2MinionListStrc** ppMinionList)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        *pOwnerGUID = -1;
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    if (pAiControl->dwOwnerTypeEx != UNIT_MONSTER)
    {
        *pOwnerGUID = -1;
        return;
    }

    *pOwnerGUID = pAiControl->dwOwnerGUIDEx;
    *pOwnerType = pAiControl->dwOwnerTypeEx;
    *pAiControlFlag1 = AIUTIL_CheckAiControlFlag(pAiControl, 1);
    *pAiControlFlag2 = AIUTIL_CheckAiControlFlag(pAiControl, 2);
    *ppMinionList = pAiControl->pMinionList;
    pAiControl->dwOwnerGUIDEx = -1;
    pAiControl->pMinionList = 0;
}

inline void AIGENERAL_SetOwnerData_Inl(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (bSetFlag2)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 2, UNIT_MONSTER);
    }

    if (bSetFlag1)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, UNIT_MONSTER, UNIT_MONSTER);
    }

    pAiControl->dwOwnerGUIDEx = nOwnerGUID;
    pAiControl->dwOwnerTypeEx = nOwnerType;
    pAiControl->pGame = pGame;
}

// 0x0058F730
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitByType(pUnit);
    if (!pAiControl || !pAiControl->pGame)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerType != 1)
    {
        return;
    }

    D2AiControlStrc* pOwnerAiControl = AIGENERAL_GetAiControlFromUnitByType(pOwner);
    if (!pOwnerAiControl)
    {
        return;
    }

    for (D2MinionListStrc* pMinionList = pOwnerAiControl->pMinionList; pMinionList; pMinionList = pMinionList->pNext)
    {
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pOwnerAiControl->pGame, 1, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            D2AiCmdStrc* pCopy = AIGENERAL_AllocAiCommand(pGame, pMinion);
            if (pCopy)
            {
                memcpy(pCopy->nCmdParam, pAiCmd->nCmdParam, sizeof(pCopy->nCmdParam));
                D2AiControlStrc* pMinionAiControl = AIGENERAL_GetAiControlFromUnitByType(pMinion);
                if (pMinionAiControl)
                {
                    pMinionAiControl->pCurrentCmd = pCopy;
                }
            }
        }
    }
}

// 0x0058F4D0
void __fastcall AIGENERAL_SetAiControlInfo(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nOwnerGUID, unsigned int nOwnerType, int bSetFlag1, int bSetFlag2, D2MinionListStrc* pMinionList)
{
	const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
	if (nUnitType != 1)
	{
		return;
	}

	D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
	AIGENERAL_FreeAllMinionLists(pGame, pAiControl->pMinionList);
	AIGENERAL_SetOwnerData(pGame, pUnit, nOwnerGUID, nOwnerType, bSetFlag1, bSetFlag2);
	pAiControl->pMinionList = pMinionList;
}

// 0x0058F530
static void __stdcall AIGENERAL_TransferMinionsToNewLeader(D2UnitStrc* pUnit, D2AiControlStrc* pAiControl)
{
    D2MinionListStrc* pList = pAiControl->pMinionList;
    if (!pList)
    {
        return;
    }

    D2GameStrc* pGame = pAiControl->pGame;
    for (D2MinionListStrc* pMinionList = pList; pMinionList; pMinionList = pMinionList->pNext)
    {
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            AIGENERAL_SetOwnerData_Inl(pGame, pMinion, pMinionList->dwMinionGUID, UNIT_MONSTER, UNIT_MONSTER, UNIT_MONSTER);
            AIGENERAL_SetOwnerData_Inl(pGame, pUnit, pMinionList->dwMinionGUID, UNIT_MONSTER, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pMinion, pUnit);

            do
            {
                D2UnitStrc* pTemp = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pList->dwMinionGUID);
                if (pTemp && pTemp != pMinion)
                {
                    AIGENERAL_SetOwnerData_Inl(pGame, pTemp, pMinionList->dwMinionGUID, UNIT_MONSTER, 0, 0);
                    AIGENERAL_AllocMinionList(pGame, pMinion, pTemp);
                }
                pList = pList->pNext;
            }
            while (pList);
            return;
        }
    }
}

// 0x0058F660
static void AIGENERAL_ReleaseMinions(D2AiControlStrc* pAiControl)
{
    D2MinionListStrc* pMinionList = pAiControl->pMinionList;
    D2GameStrc* pGame = pAiControl->pGame;
    while (pMinionList)
    {
        AIGENERAL_SetOwnerData_Inl(pGame, SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID), -1, UNIT_MONSTER, 0, 0);
        pMinionList = pMinionList->pNext;
    }
}

// 0x0058F6C0
void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!AIUTIL_CheckAiControlFlag(pAiControl, UNIT_MONSTER))
    {
        return;
    }

    if (AIUTIL_CheckAiControlFlag(pAiControl, 2))
    {
        AIGENERAL_TransferMinionsToNewLeader(pUnit, pAiControl);
    }
    else
    {
        AIGENERAL_ReleaseMinions(pAiControl);
    }
}

// 0x0058F710
int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit)
{
    return AIGENERAL_GetAiControlFromUnitByType(pUnit)->nMinionSpawnClassId;
}

