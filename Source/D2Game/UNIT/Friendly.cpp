#include "D2Game.h"
#include "D2Structs.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x0073C538


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#include "D2GameFuncs.h"

#define UNIT_PLAYER 0
#define UNIT_INVALID 6

// 0x005A6080
int __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2)
{
    D2_ASSERT((hPlayer ? hPlayer->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 21);

    PLAYERLIST_AllocPlayerList(pGame, hPlayer, pPlayer2);
    PLAYERLIST_ToggleFlag(pGame, hPlayer, pPlayer2, PLAYERLIST_FLAG_HOSTILE, 0);
    return 1;
}

// 0x005A60E0
void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2)
{
    D2_ASSERT((hPlayer ? hPlayer->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 36);

    PLAYERLIST_AllocPlayerList(pGame, hPlayer, pPlayer2);
    PLAYERLIST_ToggleFlag(pGame, hPlayer, pPlayer2, PLAYERLIST_FLAG_HOSTILE, 1);
}


#define UNIT_MONSTER 1

// 0x005A6130
int __fastcall MONSTERUNIQUE_AreUnitsFriendly(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nType1 = UNIT_INVALID;
    if (pUnit1)
    {
        nType1 = pUnit1->dwUnitType;
    }

    switch (nType1)
    {
    case UNIT_PLAYER:
        return !PLAYERLIST_CheckFlag(pUnit1, pUnit2, PLAYERLIST_FLAG_HOSTILE);

    case UNIT_MONSTER:
    {
        int nType2 = UNIT_INVALID;
        if (pUnit2)
        {
            nType2 = pUnit2->dwUnitType;
        }

        switch (nType2)
        {
        case UNIT_PLAYER:
            return !PLAYERLIST_CheckFlag(pUnit2, pUnit1, PLAYERLIST_FLAG_HOSTILE);

        case UNIT_MONSTER:
            return STATLIST_AreUnitsAligned(pUnit1, pUnit2);
        }
        break;
    }
    }

    return 0;
}
