#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x007310D0


struct D2Game5347F0Strc
{
    char unk0x00[0x0C];
    int nValue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
void __cdecl QUESTS_DisableSequences();                                                                      // 0x005449D0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

// 0x00534650
D2UnitStrc* __stdcall DEBUG_GetUnitFromTypeAndGUID(int nUnitType, int nUnitGUID)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    if (!pGame)
    {
        return 0;
    }

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    sub_0052DF40_UnlockFirstGame();
    return pUnit;
}

// 0x00534680
D2DrlgActStrc* __stdcall DEBUG_GetAct(int nAct)
{
    D2GameStrc* ptGame = sub_0052F6E0_LockFirstGame();
    D2_ASSERT(ptGame, 105);

    D2DrlgActStrc* pAct = ptGame->pAct[nAct];
    sub_0052DF40_UnlockFirstGame();
    return pAct;
}

// 0x005346C0
int __stdcall DEBUG_GetMonsterCount()
{
    D2GameStrc* ptGame = sub_0052F6E0_LockFirstGame();

    D2_ASSERT(ptGame, 0x7B);

    int nIndex = 0;
    for (int i = 0; i < 128; ++i)
    {
        for (D2UnitStrc* pUnit = ptGame->pUnitList[1][i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
        {
            ++nIndex;
        }
    }

    sub_0052DF40_UnlockFirstGame();
    return nIndex;
}

struct D2DrlgActStrc;

// 0x00534730
void* __stdcall DEBUG_GetRoomBySubtileCoordinates(unsigned char bAct, int nX, int nY)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    D2_ASSERT(bAct < 5, 141);

    void* pResult = DUNGEON_FindRoomBySubtileCoordinates(pGame->pAct[bAct], nX, nY);
    sub_0052DF40_UnlockFirstGame();
    return pResult;
}

// 0x00534790
void __cdecl DEBUG_DisableQuestSequences()
{
    QUESTS_DisableSequences();
}

// 0x005347A0
char* __fastcall DEBUG_ClearText(int nUnused, char* szText)
{
    *szText = 0;
    return szText;
}

// 0x005347B0
void __fastcall sub_005347B0_Stub5(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5)
{
}

// 0x005347C0
void __fastcall DEBUG_Stub6(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5, int nUnused6)
{
}

// 0x005347D0
void __fastcall DEBUG_Stub9(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5, int nUnused6, int nUnused7, int nUnused8, int nUnused9)
{
}

// 0x005347E0
void __fastcall sub_005347E0_Stub5(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5)
{
}

// 0x005347F0
void __fastcall DEBUG_SetRecordValue(D2Game5347F0Strc* pRecord, int nValue)
{
    if (pRecord)
    {
        pRecord->nValue = nValue;
    }
}

