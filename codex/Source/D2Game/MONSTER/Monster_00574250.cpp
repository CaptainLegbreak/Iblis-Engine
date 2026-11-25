#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameStrc.h"
struct D2MonsterInteractStrc;
struct D2MonsterModeDataStrc;

struct D2MonRegDataStrc;

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
    char unk_04[0x24];
    D2AiControlStrc* pAiControl;
    void* pAiParam;
    void* pMonInteract;
    char unk_34[0x24];
    int dwTxtLevelNo;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30
D2AiControlStrc* __fastcall AIGENERAL_AllocAiControl(D2GameStrc* pGame); // 0x0058EBC0
D2MonsterModeDataStrc* __fastcall MONSTERMODE_AllocParams(D2GameStrc* pGame); // 0x005A6490
D2MonsterInteractStrc* __fastcall MONSTERAI_AllocMonsterInteract(D2GameStrc* pGame); // 0x00572BA0
D2MonRegDataStrc* __fastcall MONSTERREGION_GetMonsterComponentData(void* pMonReg, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit); // 0x00547BC0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nSpecialState); // 0x005B0E00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bQuestMonster); // 0x00545CD0
void __fastcall SUNIT_InitializeAnimation(D2UnitStrc* pUnit); // 0x005533D0
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
void __stdcall shim_1(void* p1, void* p2);

static void __stdcall sub_00573CB0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, D2MonRegDataStrc* pMonRegData)
{

    shim_1(&pGame, &pRoom);
    shim_1(pUnit, &pMonRegData);
    shim_1(pUnit, 0);
}

static inline D2MonsterDataStrc* MONSTER_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

static inline D2MonStatsTxt* MONSTER_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

static inline D2AiControlStrc* MONSTER_GetAiControl(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterData(pUnit);
    if (pMonsterData)
    {
        return pMonsterData->pAiControl;
    }
    return 0;
}

// 0x00574250
void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster, int nUnitGUID)
{
    if (pMonster)
    {
        pMonster->dwUnitId = nUnitGUID;
        pMonster->dwFlags |= 0x0A;
    }

    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pMonster);

    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterData(pMonster);
    pMonsterData->pAiControl = AIGENERAL_AllocAiControl(pGame);
    pMonsterData->pAiParam = MONSTERMODE_AllocParams(pGame);
    pMonsterData->pMonInteract = MONSTERAI_AllocMonsterInteract(pGame);
    pMonsterData->pMonstatsTxt = MONSTER_GetMonStatsTxtRecord(pMonster);

    sub_00573CB0(pGame, pRoom, pMonster, MONSTERREGION_GetMonsterComponentData(pGame->pMonReg, pRoom, pMonster));
    AITHINK_ExecuteAiFn(pGame, pMonster, MONSTER_GetAiControl(pMonster), 0);

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nAnimMode;
    if (pMonster)
    {
        D2MonsterDataStrc* pData = MONSTER_GetMonsterData(pMonster);
        if (pData)
        {
            pData->dwTxtLevelNo = nLevelId;
        }

        nAnimMode = pMonster->dwAnimMode;
        if (nAnimMode != 0 && nAnimMode != 12)
        {
            QUESTS_AttachLevelChainRecord(pGame, pMonster, pRoom, 1);
            SUNIT_InitializeAnimation(pMonster);
            return;
        }
    }
    else
    {
        nAnimMode = 0;
    }

    SUNIT_SetCombatMode(pGame, pMonster, nAnimMode);
    SUNIT_InitializeAnimation(pMonster);
}
