#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2MonsterIds.h"
#include "D2LanguageNames.h"

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0

// 0x00586B50
void __fastcall ACT5Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass1 = 7;
    int nSpecialIntroClass2 = 7;
    switch (nNpcId)
    {
    case 513:
        nSpecialIntroClass1 = 4;
        nSpecialIntroClass2 = 1;
        break;
    case 514:
        nSpecialIntroClass1 = 6;
        nSpecialIntroClass2 = 2;
        break;
    case 515:
        nSpecialIntroClass1 = 5;
        nSpecialIntroClass2 = 3;
        break;
    case 512:
    case 520:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else if (nPlayerClass == nSpecialIntroClass2)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x00586C40
bool __fastcall sub_00586C40_StatusFilterCallback(D2QuestDataStrc* quest, D2UnitStrc* player, D2BitBufferStrc* globalFlags, D2BitBufferStrc* flags, unsigned char* status)
{
    *status = 0;
    return false;
}

// 0x00586C50
bool __fastcall ACT5Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_MALAH))
    {
        return true;
    }

    return false;
}

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall ACT5Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058E990

// 0x0058E990
void __fastcall ACT5Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const short nMessageIndex = pQuestArg->nMessageIndex;

    switch (pQuestArg->nOldLevel)
    {
    case 520:
    {
        if (nMessageIndex == 20003)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nOldLevel);
        }
        return;
    }
    case 512:
    {
        if (nMessageIndex == 20014)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nOldLevel);
        }
        return;
    }
    case 513:
    {
        if (nMessageIndex == 20039 || nMessageIndex == 20038 || nMessageIndex == 20037)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nOldLevel);

            D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestArg->pGame, 31);
            if (!pQuest || pQuest->fState)
            {
                return;
            }

            if (!pQuest->bNotIntro)
            {
                return;
            }

            pQuest->fState = 1;
        }
        return;
    }
    case 514:
    {
        if (nMessageIndex == 20054 || nMessageIndex == 20053 || nMessageIndex == 20055)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nOldLevel);
        }
        return;
    }
    case 515:
    {
        if (nMessageIndex == 20067 || nMessageIndex == 20066 || nMessageIndex == 20065)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, pQuestArg->nOldLevel);
        }
        return;
    }
    default:
        break;
    }
}

struct D2QuestCallbacks0058EA50Strc;

struct D2QuestData0058EA50Strc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2QuestCallbacks0058EA50Strc
{
    void* pfCallbackA0;
    unsigned char unk_A4[0x28];
    void* pfCallbackCC;
    unsigned char unk_D0[0x3C - 0x30];
};

struct D2QuestData0058EA50Strc
{
    unsigned char unk_00[0x0A];
    unsigned char nA;
    unsigned char nB;
    unsigned char nC;
    unsigned char unk_0D[0x18 - 0x0D];
    int n18;
    unsigned char unk_1C[0xA0 - 0x1C];
    D2QuestCallbacks0058EA50Strc tCallbacks;
    void* pRecordDC;
    int nE0;
    unsigned char unk_E4[4];
    void* pfStatusFilterE8;
    void* pfActiveFilterEC;
};

extern unsigned char gaAct5IntroNpcMessages[]; // 0x00732FF8

// 0x0058EA50
void __fastcall sub_0058EA50_InitQuestCallbacks(D2QuestData0058EA50Strc* pQuestData)
{
    memset(&pQuestData->tCallbacks, 0, sizeof(pQuestData->tCallbacks));
    pQuestData->tCallbacks.pfCallbackA0 = (void*)ACT5Intro_Callback00_NpcActivate;
    pQuestData->tCallbacks.pfCallbackCC = (void*)ACT5Intro_Callback11_ScrollMessage;
    pQuestData->pRecordDC = gaAct5IntroNpcMessages;
    pQuestData->nA = 1;
    pQuestData->nC = 0;
    pQuestData->nB = 0;
    pQuestData->n18 = 0;
    pQuestData->nE0 = 0x2A;
    pQuestData->pfStatusFilterE8 = (void*)sub_00586C40_StatusFilterCallback;
    pQuestData->pfActiveFilterEC = (void*)ACT5Intro_ActiveFilterCallback;
}

#include "gen/data/Source/D2Game/Unknown_00586B50.inc"
