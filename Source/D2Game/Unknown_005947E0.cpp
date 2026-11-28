#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2CommonApi.h"

struct D2Act1Quest5Strc;
struct D2PlayerDataStrc;


// 0x005947E0
static int __stdcall sub_005947E0_IsUnitGUIDInList(D2Act1Quest5Strc* pQuestDataEx, int nUnitGUID, int bSecondList)
{
    if (bSecondList)
    {
        const int nCount = pQuestDataEx->nUnitCount2;
        for (int i = 0; i < nCount; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs2[i] == nUnitGUID)
            {
                return 1;
            }
        }
        return 0;
    }

    const int nCount = pQuestDataEx->nUnitCount1;
    for (int i = 0; i < nCount; ++i)
    {
        if (pQuestDataEx->nUnitGUIDs1[i] == nUnitGUID)
        {
            return 1;
        }
    }
    return 0;
}

// 0x005952C0
bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuest->pQuestDataEx;
    int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (sub_005947E0_IsUnitGUIDInList(pQuestDataEx, nUnitId, 1))
    {
        if (nNpcId == 155 || nNpcId == 147)
        {
            return false;
        }

        return true;
    }

    return false;
}
