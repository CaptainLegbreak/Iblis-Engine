#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Primitives.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2ClientQuestLog.h"
#include "D2QuestLookupEntry.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2ClientUi.h"
#include "D2ClientQuestText.h"
#include "D2MonsterIds.h"
#include "D2WinSplitText.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2CMPApi.h"
#include "D2WinApi2.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags();                                                           // 0x004B32D0
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc);                   // 0x00526700
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);            // 0x005267E0
int __fastcall UNICODE_StrLen(const Unicode* pString);                                               // 0x00526800

extern const char gszFormatD[];                                                                    // 0x006D57BC
extern D2QuestTextsStrc gtQuestTextsSevenTombs;                                                              // 0x00723A64
extern D2QuestTextsStrc gtQuestTextsFallenAngel;                                                              // 0x00723C64
extern D2QuestTextsStrc gtQuestTextsSiege;                                                              // 0x00723D24
extern D2QuestPageRangeStrc gaQuestPageRanges[];                                                   // 0x00723F08
extern D2QuestTableStrc gaQuestTable[41];                                                            // 0x00723F30




static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg);                                          // 0x004A1950



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
extern D2QuestPosStrc gaQuestPos[];                                                                // 0x00723EA8




static inline int sub_004A1950_GetActNumber(const D2QuestTextsStrc* pTexts)
{
    if (pTexts->awIds[0] == 0xE82)
    {
        return gtQuestLog.nQuestAct;
    }
    return 0;
}

static void TEXT_SetQuestPage(int nPageArg); // 0x004A2220


extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0



#define SOUND_ID 4



void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990

extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820

void __cdecl INV_ChainCinematic(); // 0x00483340


void __cdecl INV_StopCinematic(); // 0x00483300




struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nId;
    unsigned char nFlags;
    unsigned char nValue;
    short nParam;
};

struct SMSGHANDLER_PARAMS;
















bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970




// 0x004A18E0
static inline void TEXT_SetQuestIndex(int nIndex)
{
    gtQuestLog.nSelectedSlot = nIndex;
}

// 0x004A18F0
void __cdecl sub_004A18F0()
{
    gaQuestPageDefault[0] = -1;
    gaQuestPageDefault[1] = -1;
    gaQuestPageDefault[2] = -1;
    gaQuestPageDefault[3] = -1;
    gaQuestPageDefault[4] = -1;
}

// 0x004A1910
static inline int TEXT_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaQuestTable[i].nCondition == nKey)
            return i;
    }
    return -1;
}

// 0x004A1930
static inline int TEXT_FindEntryIndex(int nId)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaQuestTable[i].nQuestId == nId)
            return i;
    }
    return -1;
}

int __fastcall sub_M115_Emit_004A18E0(int nIndex, int nId)
{
    TEXT_SetQuestIndex(nIndex);
    return TEXT_FindEntryIndex(nId);
}

// 0x004A1950
static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg)
{
    pMsg->wTitle = 0xE8C;
    pMsg->wDesc = 0xE8C;
    pMsg->wszText[0] = 0;
    pMsg->bStepChanged = 0;
    pMsg->bValid = 0;

    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable[i].nQuestId == pMsg->nQuestId)
        {
            nIndex = i;
            break;
        }
    }

    if (nIndex == -1)
    {
        pMsg->nState = 2;
        return;
    }

    pMsg->nCelId = gaQuestTable[nIndex].nCelId2;
    pMsg->nCelId2 = gaQuestTable[nIndex].nCelId;
    D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
    D2BitBufferStrc* pQuestHistory = sub_004B32E0_GetQuestHistory();
    unsigned char nStep = gtQuestLog.abQuestStepsA[nIndex];
    pMsg->nStep = nStep;
    if (!gaQuestTable[nIndex].pTexts)
    {
        pMsg->nState = 2;
        return;
    }

    const int bState0 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0);
    const int bState13 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xD);
    const int bState1 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1);
    D2QuestTextsStrc* pTexts = gaQuestTable[nIndex].pTexts;

    if (pTexts == &gtQuestTextsSiege && bState1)
    {
        if (!nStep)
        {
            nStep = 4;
        }
    }
    else if (pTexts == &gtQuestTextsSevenTombs && !bState0 && !bState13
        && (QUESTRECORD_GetQuestState(pQuestInfo, 0xC, 0) || QUESTRECORD_GetQuestState(pQuestInfo, 0xC, 0xD)) && nStep == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[7 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 7;
        gtQuestLog.abQuestStepsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[7 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (pTexts == &gtQuestTextsSevenTombs && !bState0 && !bState13 && QUESTRECORD_GetQuestState(pQuestInfo, 0xE, 3) == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[5 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 5;
        gtQuestLog.abQuestStepsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[5 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (pTexts == &gtQuestTextsSevenTombs && !bState0 && !bState13 && QUESTRECORD_GetQuestState(pQuestInfo, 0xE, 4) == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[6 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 6;
        gtQuestLog.abQuestStepsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[6 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (bState13 && !bState0 && pTexts->awIds[2] != 0xFFFF && bState1 && pTexts != &gtQuestTextsFallenAngel)
    {
        nStep = (unsigned char)pTexts->awIds[2] + 1;
        pMsg->wTitle = pTexts->awIds[0];
        const unsigned short* pIds = &pTexts->awIds[nStep * 2];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pIds[1]), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->bStepChanged = nStep != gtQuestLog.abQuestStepsB[nIndex];
        const unsigned short wDesc = pIds[2];
        gtQuestLog.abQuestStepsB[nIndex] = nStep;
        pMsg->wDesc = wDesc;
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (bState0)
    {
        unsigned short nString;
        if (bState13)
        {
            nString = 0xE8E;
            nStep = 0xD;
        }
        else
        {
            nString = 0xE90;
            nStep = 0xB;
        }

        pMsg->nStep = nStep;
        if (!pTexts)
        {
            pMsg->nState = 2;
            return;
        }

        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->wDesc = pTexts->awIds[1];
        gtQuestLog.abQuestStepsB[nIndex] = nStep;
        pMsg->bValid = 1;
        pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xC) != 0;
        return;
    }
    else if (bState1 && QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xF))
    {
        unsigned char nNewStep = 0xA;
        if (pMsg->nQuestId == 0x25)
        {
            if (QUESTRECORD_GetQuestState(pQuestInfo, 0x25, 8) && !QUESTRECORD_GetQuestState(pQuestInfo, 0x25, 9))
            {
                nNewStep = 6;
            }
            else if (!QUESTRECORD_GetQuestState(pQuestInfo, 0x25, 8))
            {
                nNewStep = 5;
            }
        }

        if (pMsg->nQuestId == 0x26)
        {
            nNewStep = (QUESTRECORD_GetQuestState(pQuestInfo, 0x26, 4) != 0) + 4;
        }

        pMsg->nStep = nNewStep;
        if (!pTexts)
        {
            pMsg->nState = 2;
            return;
        }

        const unsigned short* pIds = &pTexts->awIds[nNewStep * 2];
        if (pIds[1] == 0xE8D)
        {
            pMsg->nState = 2;
            return;
        }

        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pIds[1]), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->wDesc = pIds[2];
        gtQuestLog.abQuestStepsB[nIndex] = nNewStep;
        pMsg->bValid = 1;
        pMsg->nState = (pMsg->nQuestId != 0x1B) ? 3 : 1;
        return;
    }

    if (nStep)
    {
        if (!gaQuestTable[nIndex].pTexts)
        {
            pMsg->nState = 2;
            return;
        }

        if (pTexts->awIds[0] == 0xE82)
        {
            const int nStepIndex = nStep;
            const Unicode* pString = D2LANG_GetStringFromTblIndex(pTexts->awIds[nStepIndex * 2 + 1]);
            if (nStepIndex - 1 != 2 && nStepIndex - 1 != 3)
            {
                sub_00526790(pMsg->wszText, pString, 300);
                pMsg->wszText[300 - 1] = 0;
            }
            else if (pTexts->awIds[0] == 0xE82 && gtQuestLog.nQuestAct > 1)
            {
                Unicode wszNumber[10];
                char szNumber[6];
                sprintf(szNumber, gszFormatD, sub_004A1950_GetActNumber(pTexts));
                sub_00526320_ToUnicode(wszNumber, szNumber, 9);
                sub_005267E0(pMsg->wszText, pString);
                D2_ASSERT(UNICODE_StrLen(pString) < 0x118, 0x4FA);
                sub_00526700(pMsg->wszText, wszNumber);
            }
            else
            {
                pString = D2LANG_GetStringFromTblIndex(0xE9B);
                sub_00526790(pMsg->wszText, pString, 300);
                pMsg->wszText[300 - 1] = 0;
            }

            pMsg->wTitle = pTexts->awIds[0];
            pMsg->bStepChanged = 0;
            if (nStep != gtQuestLog.abQuestStepsB[nIndex])
            {
                pMsg->bStepChanged = 1;
            }
            gtQuestLog.abQuestStepsB[nIndex] = nStep;
            pMsg->wDesc = pTexts->awIds[nStepIndex * 2 + 2];
            pMsg->nState = 3;
            pMsg->bValid = 1;
            pMsg->nStep = nStep;
            if (nStep == 0xD)
            {
                pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xC) != 0;
            }
            return;
        }

        pMsg->wTitle = pTexts->awIds[0];
        int nString;
        if ((!bState0 && !bState13 && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1)
            && pQuestHistory && QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable[nIndex].nQuestId, 0xD) && pMsg->nQuestId != 0x13)
            || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xE))
        {
            nString = gnGameType ? 0xE92 : 0xE91;
        }
        else
        {
            nString = pTexts->awIds[nStep * 2 + 1];
            if ((unsigned short)nString == 0xE8F && !gnGameType)
            {
                nString = 0xE91;
            }
        }

        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        if (pTexts->awIds[0] == 0x585E && (unsigned short)nString == 0x5860)
        {
            if (!gtQuestLog.nQuestParam)
            {
                sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(0xE91), 300);
            }
            else
            {
                sub_005269D0_FormatText(300, pMsg->wszText, D2LANG_GetStringFromTblIndex(0x5860), gtQuestLog.nQuestParam);
            }
        }

        pMsg->wszText[300 - 1] = 0;
        pMsg->bStepChanged = 0;
        if (nStep != gtQuestLog.abQuestStepsB[nIndex] && gaQuestTable[nIndex].pTexts)
        {
            pMsg->bStepChanged = 1;
        }
        const unsigned short wDesc = pTexts->awIds[nStep * 2 + 2];
        gtQuestLog.abQuestStepsB[nIndex] = nStep;
        pMsg->wDesc = wDesc;
        pMsg->nState = 3;
        pMsg->bValid = 1;
        if (nStep == 0xD)
        {
            pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xC) != 0;
        }
        return;
    }

    unsigned short nString;
    if (QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable[nIndex].nQuestId, 0xD))
    {
        if (pMsg->nQuestId == 0x15 && !QUESTRECORD_GetQuestState(pQuestInfo, 0x15, 0) && QUESTRECORD_GetQuestState(pQuestInfo, 0x15, 4) == 1)
        {
            nString = 0x3DD;
            goto lPrint;
        }

        if (!bState13 && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1))
        {
            unsigned short nNoneString = 0xE92;
            if (!gnGameType)
            {
                nNoneString = 0xE91;
            }
            sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nNoneString), 300);
            pMsg->wszText[300 - 1] = 0;
            pMsg->wDesc = 0xE8D;
            pMsg->bValid = 1;
            pMsg->nState = 3;
            return;
        }
    }
    else if (QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable[nIndex].nQuestId, 0xF) && !bState13
        && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1))
    {
        nString = 0xE92;
        if (!gnGameType)
        {
            nString = 0xE91;
        }
lPrint:
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->wDesc = 0xE8D;
        pMsg->bValid = 1;
        pMsg->nState = 3;
        return;
    }

    pMsg->nState = 2;
}

// 0x004A2220
static void TEXT_SetQuestPage(int nPageArg)
{
    int nPage = nPageArg;
    if (nPage >= 5)
    {
        nPage = 0;
    }
    switch (nPage)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1A, 0)) nPage = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0)) nPage = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0)) nPage = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0)) nPage = 0;
    }
    gtQuestLog.nSelectedSlot = -1;
    gtQuestLog.nPressedSlot = -1;
    for (int i = 0; i < 6; ++i)
    {
        gtQuestLog.anAnim[i] = 0;
        gtQuestLog.anTick[i] = 0;
    }
    gtQuestLog.nPage = nPage;
}








// The same page selection as TEXT_SetQuestPage, in the statement order that 0x004A2300 inlines
// for its call with page 0.
static void TEXT_SetQuestPage_Inline(int nPage)
{
    if (nPage >= 5)
    {
        nPage = 0;
    }
    switch (nPage)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1A, 0)) nPage = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0)) nPage = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0)) nPage = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0)) nPage = 0;
    }
    gtQuestLog.nPage = nPage;
    for (int i = 0; i < 6; ++i)
    {
        gtQuestLog.anAnim[i] = 0;
        gtQuestLog.anTick[i] = 0;
    }
    gtQuestLog.nSelectedSlot = -1;
    gtQuestLog.nPressedSlot = -1;
}

// 0x004A2300
void __cdecl QUESTLOG_UpdateQuestPage()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                TEXT_SetQuestPage(DRLG_GetActNoFromLevelId(nLevelId));
                return;
            }
        }
    }
    TEXT_SetQuestPage_Inline(0);
}










// 0x004A2390
extern "C" void __cdecl QUESTLOG_ResetQuestGlobals(void)
{
    gtQuestLog.bQuestSlotDown = 0;
    gtQuestLog.bCloseButtonDown = 0;
    gtQuestLog.bQuestButtonDown = 0;
    gtQuestLog.nPressedSlot = -1;
    gtQuestLog.bDescButtonDown = 0;
    gtQuestLog.bDurielCofsLoaded = 0;
    gtQuestLog.bAncientsCofsLoaded = 0;
    gtQuestLog.bHasQuestPacketValue = 0;
    gtQuestLog.bQuestUnitsSpawned = 0;
}

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
    virtual void AddName(const char* szName, int nSize);
};

// 0x004A23D0
void __cdecl QUESTLOG_LoadQuestPanelCels()
{
    char szPath[0x104];
    if (INV_IsCinematicBusy())
    {
        return;
    }
    if (!gtQuestLog.pBackgroundCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questbackground", gszDataGlobal);
        gtQuestLog.pBackgroundCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gtQuestLog.pTabsCel)
    {
        if (FOG_IsExpansion() && GAME_IsExpansion())
        {
            sprintf(szPath, "%s\\ui\\menu\\expquesttabs", gszDataGlobal);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\questtabs", gszDataGlobal);
        }
        gtQuestLog.pTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gtQuestLog.pSocketsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questsockets", gszDataGlobal);
        gtQuestLog.pSocketsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gtQuestLog.pDoneCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questdone", gszDataGlobal);
        gtQuestLog.pDoneCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gtQuestLog.pInvPsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\invps", gszDataGlobal);
        gtQuestLog.pInvPsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gtQuestLog.pLastCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questlast", gszDataGlobal);
        gtQuestLog.pLastCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

// 0x004A2550
void __cdecl QUESTLOG_FreeQuestCels()
{
    if (gtQuestLog.pBackgroundCel)
    {
        ARCHIVE_FreeClientCellFile(gtQuestLog.pBackgroundCel);
        gtQuestLog.pBackgroundCel = 0;
    }
    if (gtQuestLog.pTabsCel)
    {
        ARCHIVE_FreeClientCellFile(gtQuestLog.pTabsCel);
        gtQuestLog.pTabsCel = 0;
    }
    if (gtQuestLog.pLastCel)
    {
        ARCHIVE_FreeClientCellFile(gtQuestLog.pLastCel);
        gtQuestLog.pLastCel = 0;
    }
    if (gtQuestLog.pSocketsCel)
    {
        ARCHIVE_FreeClientCellFile(gtQuestLog.pSocketsCel);
        gtQuestLog.pSocketsCel = 0;
    }
    if (gtQuestLog.pDoneCel)
    {
        ARCHIVE_FreeClientCellFile(gtQuestLog.pDoneCel);
        gtQuestLog.pDoneCel = 0;
    }
    if (gtQuestLog.pInvPsCel)
    {
        ARCHIVE_FreeClientCellFile(gtQuestLog.pInvPsCel);
        gtQuestLog.pInvPsCel = 0;
    }
    for (int i = 0; i < 27; ++i)
    {
        if (gtQuestLog.apIconCels[i])
        {
            ARCHIVE_FreeClientCellFile(gtQuestLog.apIconCels[i]);
            gtQuestLog.apIconCels[i] = 0;
        }
    }
}

// 0x004A2600
void __cdecl QUESTLOG_FreeQuestPanel()
{
    QUESTLOG_FreeQuestCels();
}

// 0x004A2610
static unsigned char TEXT_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}

// 0x004A2630
static int TEXT_GetQuestSlotAtPoint(int nX, int nY)
{
    int nCount = gtQuestLog.nMsgCount;
    D2_ASSERT((unsigned int)nCount <= 6, 0x738);
    for (int i = 0; i < nCount; ++i)
    {
        if (nX >= gaQuestSlots[i].nX && nX < gaQuestSlots[i].nX + 0x38 && nY >= gaQuestSlots[i].nY && nY < gaQuestSlots[i].nY + 0x34)
        {
            return i;
        }
    }
    return -1;
}

// 0x004A2690
static unsigned char TEXT_HitTestQuestCloseButton(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}





// 0x004A26B0
int __stdcall QUESTLOG_OpenQuestPanel(int nArg)
{
    if (gtQuestLog.nState == 2)
    {
        gtQuestLog.nState = 0;
        gtQuestLog.bQuestButtonDown = 0;
        gtQuestLog.bDescriptionOpen = 0;
    }

    QUESTLOG_FreeQuestCels();
    UI_SetUIVar(15, 1, nArg);
    return 1;
}

// 0x004A26F0
static int __stdcall TEXT_GetQuestTabAtPoint(int nY, int nX)
{
    if (nY < 0 || nY > 0x1B || nX < 0 || nX > 0x13F)
    {
        return -1;
    }
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        int i = 0;
        for (int n = 0; n < 0x140; n += 0x40, ++i)
        {
            if (nX >= n && nX <= n + 0x40) return i;
        }
        return -1;
    }
    int i = 0;
    for (int n = 0; n < 0x140; n += 0x50, ++i)
    {
        if (nX >= n && nX <= n + 0x50) return i;
    }
    return -1;
}


void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0






// 0x004A2760
void __cdecl QUESTLOG_SendQuestUpdates()
{
    for (int i = 0; i < gtQuestLog.nMsgCount; ++i)
    {
        if (!gtQuestLog.aMsgs[i].nState)
        {
            D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
            QUESTRECORD_SetQuestState(pQuestInfo, gtQuestLog.aMsgs[i].nQuestId, 0xC);
            MSG_SendWord(0x58, (unsigned short)gtQuestLog.aMsgs[i].nQuestId);
        }
    }
}

// 0x004A27B0
int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue)
{
    gtQuestLog.bDescriptionOpen = 0;
    TEXT_SetTextCallback(0, pContext);
    return 0;
}

// 0x004A27D0
static void TEXT_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gtQuestLog.nMsgCount; ++i)
    {
        if (gtQuestLog.aMsgs[i].nCelId == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gtQuestLog.aMsgs[nIndex].wDesc;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    WARDENCLIENT_OpenTextPanel(wTextId, 1, 0);
    TEXT_SetTextCallback(QUESTLOG_CloseQuestText, 0);
    gtQuestLog.bDescriptionOpen = 1;
}

// 0x004A2840
void __stdcall TEXT_CloseQuestPanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gtQuestLog.nState == 2)
    {
        gtQuestLog.nState = 0;
        gtQuestLog.bQuestButtonDown = 0;
        gtQuestLog.bDescriptionOpen = 0;
    }

    QUESTLOG_FreeQuestCels();
    UI_SetUIVar(15, 1, 1);
    gtQuestLog.dwToggleTick = GetTickCount();
}


struct PacketShorts;

#pragma pack(push, 1)
struct PacketShorts
{
    char prefix[1];
    unsigned short kind;
    unsigned short a;
    unsigned short b;
    unsigned short c;
};
#pragma pack(pop)




// 0x004A28A0
extern "C" void __fastcall QUESTLOG_AcceptShortPacket(const PacketShorts* packet)
{
    switch (packet->kind)
    {
    case 1:
        gtQuestLog.nQuestAct = packet->a;
        gtQuestLog.nA8 = packet->b;
        gtQuestLog.nQuestParam = packet->c;
        break;
    }
}

// 0x004A28D0
void __cdecl QUESTLOG_ResetQuestButton()
{
    if (gtQuestLog.nPage < 5)
        QUESTLOG_SendQuestUpdates(gtQuestLog.nPage);
    gtQuestLog.bQuestButtonDown = 0;
    gtQuestLog.nState = 0;
    gtQuestLog.bDescriptionOpen = 0;
    QUESTLOG_FreeQuestCels();
}



struct D2ButtonLayoutStrc;



D2ButtonLayoutStrc gaButtonLayouts[4] = // 0x007241C0
{
    { 40, 75, gnScreenHeight - 140, gnScreenHeight - 105, gnScreenHeight - 143 },
    { gnScreenWidth / 2 + 40, gnScreenWidth / 2 + 75, gnScreenHeight - 140, gnScreenHeight - 105, gnScreenHeight - 143 },
    { 40, 75, gnScreenHeight - 195, gnScreenHeight - 160, gnScreenHeight - 198 },
    { gnScreenWidth / 2 + 40, gnScreenWidth / 2 + 75, gnScreenHeight - 195, gnScreenHeight - 160, gnScreenHeight - 198 },
};

static int sub_E10_GetButtonLayoutCopy(int nMode)
{
    if (GAME_GetUIVarState(6) && !GAME_GetUIVarState(2))
    {
        const int nResolution = D2GFX_GetResolutionMode();
        if (nMode == 2)
            return nResolution == 2 ? 1 : 3;
        return nResolution == 2 ? 0 : 2;
    }

    const int nResolution = D2GFX_GetResolutionMode();
    if (nMode == 2)
    {
        if (nResolution == 2 || GAME_GetUIVarState(2))
            return 1;
        return 3;
    }
    return nResolution == 2 ? 0 : 2;
}

// 0x004A2900

// 0x004A2970
int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY)
{
    const int nMode = sub_0045AE90_GetPanelSlideMode();
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nLeft = gaButtonLayouts[nIndex].nTextX + (nMode == 2 ? (gnScreenWidth - 0x280) / 2 : 0);
    const int nTop = gaButtonLayouts[nIndex].nTop + gnScreenHeight - 0x1E0;
    const int nRight = gaButtonLayouts[nIndex].nRight + (nMode == 2 ? (gnScreenWidth - 0x280) / 2 : 0);
    if (nX > nLeft && nX < nRight && nY > nTop && nY < gaButtonLayouts[nIndex].nBottom + gnScreenHeight - 0x1E0)
        return 1;
    return 0;
}

// 0x004A2A20
void __stdcall TEXT_QuestButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if ((unsigned char)QUESTLOG_IsMouseOnQuestButton(nX, nY))
    {
        gtQuestLog.bQuestButtonDown = 1;
        sub_004B9A00(SOUND_ID, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gtQuestLog.bQuestButtonDown = 0;
        pMsg->bReturn = 0;
    }
}


D2CelStrc* __stdcall CelGetHandle(D2GfxDataStrc* pContext); // 0x00601840



// 0x004A2A80
void __cdecl QUESTLOG_DrawQuestButton()
{
    if (CUNIT_IsPlayerDeadOrMissing())
    {
        UI_SetUIVar(0x11, 1, 0);
        if (gtQuestLog.nState == 1)
        {
            gtQuestLog.bQuestButtonDown = 0;
            gtQuestLog.nState = 0;
        }
        return;
    }

    const int nMode = sub_0045AE90_GetPanelSlideMode();
    if (nMode == 3)
        return;
    if (GAME_GetUIVarState(0x0F))
        return;

    D2GfxDataStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.nDirection = 0;
    tCel.pCelFile = gpLevelSocketCel;
    tCel.nFrame = 0;
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nCelWidth = CelGetWidth(CelGetHandle(&tCel));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF58));
    int nTextX = nCelWidth / 2 - nTextWidth / 2 + gaButtonLayouts[nIndex].nTextX + 1;
    const int nTextY = gaButtonLayouts[nIndex].nTextY + gnScreenHeight - 0x1E0;
    if (sub_0045AE90_GetPanelSlideMode() == 2)
        nTextX += (gnScreenWidth - 0x280) / 2;
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF58), nTextX, nTextY, 0, 0);

    int nCelX = gaButtonLayouts[nIndex].nTextX;
    const int nCelY = gaButtonLayouts[nIndex].nBottom + gnScreenHeight - 0x1E0;
    if (sub_0045AE90_GetPanelSlideMode() == 2)
        nCelX += (gnScreenWidth - 0x280) / 2;
    sub_004F6480(&tCel, nCelX, nCelY, -1, 5, 0);

    tCel.pCelFile = gpLevelCel;
    tCel.nFrame = gtQuestLog.bQuestButtonDown && (unsigned char)QUESTLOG_IsMouseOnQuestButton(sub_00468730(), sub_00468740());
    sub_004F6480(&tCel, nCelX + 3, nCelY - 4, -1, 5, 0);
}

// 0x004A2C30
void __fastcall QUESTLOG_SelectQuestPage(int nCondition)
{
    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable[i].nCondition == nCondition)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex != -1)
        gaQuestPageDefault[gaQuestTable[nIndex].nPage] = gaQuestTable[nIndex].nCelId2;
}

// 0x004A2C70
void __fastcall QUESTLOG_ClearCainFlag(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x92)
        pUnit->dwFlags &= ~2u;
}

// 0x004A2C90
void __fastcall QUESTLOG_ClearNihlathakFlag(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x20F)
        pUnit->dwFlags &= ~2u;
}

// 0x004A2CB0
void __fastcall TEXT_HandleQuestEvent(int nArg, D2PacketRecord6Strc* pPacket)
{
    if (pPacket)
    {
        unsigned char nFlags = pPacket->nFlags;
        if (nFlags & 1)
        {
            switch (pPacket->nId)
            {
            case 13:
                GFX_LoadMonsterCofs(MONSTER_DURIEL, 1);
                return;
            case 23:
                GAME_RequestExit();
                return;
            case 3:
                TEXT_PrintChatLine(D2LANG_GetStringFromTblIndex(3708), 0);
                return;
            case 4:
                CUNIT_ForEachMonster(QUESTLOG_ClearCainFlag);
                return;
            case 15:
                TEXT_PrintChatLine(D2LANG_GetStringFromTblIndex(3710), 0);
                return;
            case 10:
                GAME_ConfigureEnvironmentOrDefer();
                return;
            case 33:
                sub_004B9A00(237, 0, 0, 0, 0);
                return;
            }
            return;
        }

        if (nFlags & 2)
        {
            switch (pPacket->nId)
            {
            case 23:
                if (GAME_IsExpansion())
                {
                    INV_ChainCinematic();
                    return;
                }
                GAME_SetDifficultyFlags();
                INV_StopCinematic();
                return;
            case 4:
                sub_004B9A00(241, 0, 0, 0, 0);
                return;
            case 32:
                sub_004B9A00(217, 0, 0, 0, 0);
                return;
            case 33:
                sub_004B9A00(243, 0, 0, 0, 0);
                return;
            case 8:
            case 15:
            case 18:
            case 22:
            case 35:
                sub_004B9A00(7, 0, 0, 0, 0);
                return;
            case 36:
                GAME_SetPlayCinematic(1);
                return;
            }
            return;
        }

        if (nFlags == 0x10)
        {
            unsigned char nId = pPacket->nId;
            if (nId == 10)
            {
                sub_004B9A00(2456, 0, 0, 0, 0);
                sub_004B9A00(2474, 0, 0, 0, 0);
            }
            else if (nId == 33)
            {
                sub_004B9A00(pPacket->nParam, 0, 0, 0, 0);
            }
            return;
        }

        if (nFlags & 0x20)
        {
            unsigned char nId = pPacket->nId;
            if (nId == 32)
            {
                gtQuestLog.nQuestParam = pPacket->nParam;
            }
            else if (nId == 33)
            {
                CUNIT_ForEachMonster(QUESTLOG_ClearNihlathakFlag);
                return;
            }
            else
            {
                D2BitBufferStrc* pQuestFlags = MONSTER_GetQuestFlags();
                if (pQuestFlags && QUESTRECORD_GetQuestState(pQuestFlags, 1, 0))
                {
                    return;
                }

                if (QUESTRECORD_GetQuestState(pQuestFlags, 1, 1))
                {
                    return;
                }

                gtQuestLog.nQuestAct = pPacket->nParam;
                if (gtQuestLog.nQuestAct > 5 || gtQuestLog.nQuestAct < 0)
                {
                    gtQuestLog.nQuestAct = 666;
                }

                if (gtQuestLog.nQuestAct != 5)
                {
                    gtQuestLog.abQuestStepsA[TEXT_FindQuestIndex(1)] = pPacket->nValue;
                    return;
                }

                if (pPacket->nId == 23)
                {
                    short nDelay = pPacket->nParam;
                    sub_0046BFD0_StartTimer(nDelay < 1 ? 1 : nDelay);
                    return;
                }
            }
        }
    }

refresh:
    if (!gtQuestLog.nState)
    {
        if (UI_SetUIVar(17, 0, 0) == 1)
        {
            QUESTLOG_SelectQuestPage(pPacket->nId);
            gtQuestLog.nState = 1;
        }
        return;
    }

    if (GAME_GetUIVarState(15))
    {
        int nIndex = TEXT_FindQuestIndex(pPacket->nId);
        if (nIndex != -1)
        {
            gtQuestLog.abQuestStepsA[nIndex] = pPacket->nValue;
            if (!gtQuestLog.bDescriptionOpen)
            {
                D2QuestTableStrc* pEntry = &gaQuestTable[nIndex];
                if (pEntry->nPage == gtQuestLog.nPage)
                {
                    gtQuestLog.nSelectedSlot = pEntry->nCelId2;
                }
            }
        }
    }
}



// 0x004A3000
extern "C" void __cdecl QUESTLOG_ResetQuestButtonState()
{
    if (gtQuestLog.nState == 1)
        gtQuestLog.nState = 0;
}

// 0x004A3020
void __cdecl TEXT_ClearQuestFlags()
{
    for (int i = 0; i < 41; ++i)
    {
        gtQuestLog.abQuestStepsA[i] = 0;
        gtQuestLog.abQuestStepsB[i] = 0;
    }
}

// 0x004A3050
void __cdecl sub_004A3050_ResetQuestPages()
{
    gaQuestPageDefault[0] = -1;
    gaQuestPageDefault[1] = -1;
    gaQuestPageDefault[2] = -1;
    gaQuestPageDefault[3] = -1;
    gaQuestPageDefault[4] = -1;
}





struct D2QuestLookupEntryStrc;

struct D2QuestPanelValuesStrc;


#pragma pack(push, 1)
struct D2QuestPanelValuesStrc
{
    char unk0x00[0x7];
    int nValues[0x96];
};
#pragma pack(pop)


// 0x004A3070
int __fastcall QUESTLOG_LookupQuestValue(int nUnused, int nKey)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        if (gaQuestTable[i].nCondition == nKey)
        {
            return gaQuestTable[i].nQuestId;
        }
    }
    return 0x2A;
}

// 0x004A30A0
void __cdecl QUESTLOG_LoadDurielCofsOnce()
{
    if (!gtQuestLog.bDurielCofsLoaded)
    {
        gtQuestLog.bDurielCofsLoaded = 1;
        GFX_LoadMonsterCofs(0xD3, 1);
    }
}


// 0x004A30C0
void __cdecl QUESTLOG_LoadAncientsCofsOnce()
{
    if (!gtQuestLog.bAncientsCofsLoaded)
    {
        gtQuestLog.bAncientsCofsLoaded = 1;
        GFX_LoadMonsterCofs(0x219, 0);
        GFX_LoadMonsterCofs(0x21A, 0);
        GFX_LoadMonsterCofs(0x21B, 0);
    }
}



// 0x004A3100
extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value)
{
    gtQuestLog.bHasQuestPacketValue = 1;
    gtQuestLog.nQuestPacketValue = value;
}


// 0x004A3110
char __cdecl QUESTLOG_HasQuestPacketValue()
{
    return gtQuestLog.bHasQuestPacketValue;
}




// 0x004A3120
char __cdecl QUESTLOG_IsQuestUnitPresent()
{
    if (gtQuestLog.bQuestUnitsSpawned && CUNIT_FindServerSideUnit(gtQuestLog.nQuestUnitId, 1))
    {
        return 1;
    }
    return 0;
}

union D2SeedStrc;


static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

// 0x004A3150
void __fastcall QUESTLOG_SpawnQuestUnits(int nX, int nY)
{
    if (gtQuestLog.bHasQuestPacketValue)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nCount = SEED_RollLimitedRandomNumber(&pPlayer->pSeed, 3) + 2;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pUnit = CUNIT_SpawnPresetUnit(0x95, nX + i % 2, nY + i % 2, 1, 1);
            gtQuestLog.nQuestUnitId = UNITS_GetUnitId(pUnit);
            gtQuestLog.bQuestUnitsSpawned = 1;
        }
    }
}

// 0x004A3200
D2QuestPanelValuesStrc* __fastcall QUESTLOG_ClearQuestPanelValues(D2QuestPanelValuesStrc* pValues)
{
    for (int i = 0; i < 0x96; ++i)
    {
        pValues->nValues[i] = 0;
    }
    return pValues;
}

// 0x004A3220
void __stdcall TEXT_LoadQuestPage(int nPage, int bReset)
{
    int nFirst;
    int nCount = 0;
    int nFound = 0;
    nFirst = -1;
    char szPath[260];

    gtQuestLog.nSelectedSlot = -1;
    if ((!FOG_IsExpansion() || !GAME_IsExpansion()) && nPage == 4)
    {
        return;
    }

    for (int i = gaQuestPageRanges[nPage].nFirst; i <= gaQuestPageRanges[nPage].nLast; ++i)
    {
        if (!gtQuestLog.apIconCels[i])
        {
            sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal_006D4118, gaszQuestCelNames[i]);
            gtQuestLog.apIconCels[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }

    if (gaQuestPageDefault[nPage] != -1)
    {
        gtQuestLog.nSelectedSlot = gaQuestPageDefault[nPage];
        if (bReset)
        {
            for (int j = 0; j < 5; ++j)
            {
                gaQuestPageDefault[j] = -1;
            }
        }
        return;
    }

    D2QuestTableStrc* pQuest = gaQuestTable;
    for (;;)
    {
        if (pQuest->nPage == nPage && pQuest->bEnabled && pQuest->nCelId < 0x1B && gtQuestLog.apIconCels[pQuest->nCelId])
        {
            D2QuestTextMsgStrc tMsg;
            tMsg.nQuestId = pQuest->nQuestId;
            TEXT_BuildQuestText(&tMsg);
            if (tMsg.bStepChanged || !tMsg.nState)
            {
                nCount = 41;
                gtQuestLog.nSelectedSlot = tMsg.nCelId;
            }

            if (tMsg.nState == 1 || tMsg.nState == 2 || tMsg.nState == 3)
            {
                if (tMsg.nState != 2 && tMsg.nState != 1 && nFirst == -1)
                {
                    nFirst = tMsg.nCelId;
                }
                ++nFound;
            }
        }

        if (++nCount >= 41)
        {
            break;
        }
        ++pQuest;
    }

    if (nFound && gtQuestLog.nSelectedSlot == -1)
    {
        int nSelection = gtQuestLog.anPageSelection[nPage];
        if (nSelection != -1 || (nSelection = nFirst) != -1)
        {
            gtQuestLog.nSelectedSlot = nSelection;
        }
    }

    if (bReset)
    {
        for (int j = 0; j < 5; ++j)
        {
            gaQuestPageDefault[j] = -1;
        }
    }
}

// 0x004A3410
void __cdecl TEXT_ResetQuestPanel()
{
    SRegSaveValue("Diablo II", "GAMEOVER", 0, 0);
    gtQuestLog.nState = 0;
    gtQuestLog.pBackgroundCel = 0;
    gtQuestLog.pTabsCel = 0;
    gtQuestLog.pSocketsCel = 0;
    gtQuestLog.pDoneCel = 0;
    gtQuestLog.pInvPsCel = 0;
    gtQuestLog.pLastCel = 0;
    memset(gtQuestLog.apIconCels, 0, sizeof(gtQuestLog.apIconCels));
    gtQuestLog.nQuestAct = 0;
    gtQuestLog.nQuestParam = 0;
    gtQuestLog.dwToggleTick = 0;
    for (int i = 0; i < 41; ++i)
    {
        gtQuestLog.abQuestStepsA[i] = 0;
        gtQuestLog.abQuestStepsB[i] = 0;
    }
    gtQuestLog.bQuestSlotDown = 0;
    gtQuestLog.bCloseButtonDown = 0;
    gtQuestLog.bQuestButtonDown = 0;
    gtQuestLog.bDescButtonDown = 0;
    gtQuestLog.bDurielCofsLoaded = 0;
    gtQuestLog.bAncientsCofsLoaded = 0;
    gtQuestLog.bHasQuestPacketValue = 0;
    gtQuestLog.bQuestUnitsSpawned = 0;
    gtQuestLog.bDescriptionOpen = 0;
    gtQuestLog.nPressedSlot = -1;
    gtQuestLog.anPageSelection[0] = -1;
    gtQuestLog.anPageSelection[1] = -1;
    gtQuestLog.anPageSelection[2] = -1;
    gtQuestLog.anPageSelection[3] = -1;
    gtQuestLog.anPageSelection[4] = -1;
}



// 0x004A34F0
void __cdecl QUESTLOG_DrawQuestPage()
{
    int i = 0;
    D2GfxDataStrc tDraw;
    memset(&tDraw, 0, sizeof(tDraw));
    tDraw.nDirection = 0;

    if (CUNIT_IsPlayerDeadOrMissing())
    {
        if (gtQuestLog.nState == 2)
        {
            gtQuestLog.nState = 0;
            gtQuestLog.bQuestButtonDown = 0;
            gtQuestLog.bDescriptionOpen = 0;
        }
        QUESTLOG_FreeQuestCels();
        UI_SetUIVar(0xF, 1, 0);
        return;
    }

    if (GAME_GetUIVarState(0x12))
    {
        QUESTLOG_OpenQuestPanel(0);
        return;
    }

    if (INV_IsCinematicBusy())
    {
        QUESTLOG_OpenQuestPanel(0);
        return;
    }

    if (!gtQuestLog.pBackgroundCel)
    {
        QUESTLOG_LoadQuestPanelCels();
        TEXT_LoadQuestPage(0, 1);
    }

    if (gtQuestLog.pBackgroundCel)
    {
        tDraw.pCelFile = gtQuestLog.pBackgroundCel;
        tDraw.nFrame = 0;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 1;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 2;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
        tDraw.nFrame = 3;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    }

    if (gtQuestLog.pTabsCel)
    {
        tDraw.pCelFile = gtQuestLog.pTabsCel;
        for (; i < 5; ++i)
        {
            int bExpansion = 0;
            int aX[5];
            if (FOG_IsExpansion() && GAME_IsExpansion())
            {
                bExpansion = 1;
                aX[0] = 5;
                aX[1] = 0x43;
                aX[2] = 0x81;
                aX[3] = 0xBF;
                aX[4] = 0xFD;
            }
            else
            {
                aX[0] = 5;
                aX[1] = 0x52;
                aX[2] = 0x9F;
                aX[3] = 0xEC;
                if (i > 3)
                    break;
            }

            if (i == gtQuestLog.nPage)
            {
                tDraw.nFrame = 2 * i;
                sub_004F6480(&tDraw, aX[i] + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + bExpansion - 0x1C0, -1, 5, 0);
                continue;
            }

            unsigned char bShow = 1;
            switch (i)
            {
            case 1:
                if (QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0))
                    break;
                continue;
            case 2:
                if (QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0))
                    break;
                continue;
            case 3:
                if (QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0))
                    break;
                continue;
            case 4:
                if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1A, 0))
                    bShow = 0;
                if (!FOG_IsExpansion() || !GAME_IsExpansion() || !bShow)
                    continue;
                break;
            }

            tDraw.nFrame = 2 * i + 1;
            sub_004F6480(&tDraw, aX[i] + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + bExpansion - 0x1C0, -1, 5, 0);
        }
    }

    for (int k = 0; k < 6; ++k)
        memset(gtQuestLog.aMsgs, 0, sizeof(gtQuestLog.aMsgs));

    unsigned char bSpecial = 0;
    if (gtQuestLog.nPage < 5)
    {
        gtQuestLog.nMsgCount = 0;
        int nRow = 0;
        unsigned char bDone = 0;
        D2QuestTableStrc* pEntry = gaQuestTable;
        do
        {
            int nSlot = -1;
            if (pEntry->nPage == gtQuestLog.nPage && pEntry->bEnabled && pEntry->nCelId < 0x1B && gtQuestLog.apIconCels[pEntry->nCelId] && gtQuestLog.nMsgCount < 6)
            {
                gtQuestLog.aMsgs[gtQuestLog.nMsgCount].nQuestId = pEntry->nQuestId;
                TEXT_BuildQuestText(&gtQuestLog.aMsgs[gtQuestLog.nMsgCount]);
                int nFrame;
                switch (gtQuestLog.aMsgs[gtQuestLog.nMsgCount].nState)
                {
                case 0:
                    gtQuestLog.aMsgs[gtQuestLog.nMsgCount].bShown = 1;
                    nFrame = gtQuestLog.anAnim[gtQuestLog.nMsgCount];
                    if (nFrame >= 0x19)
                    {
                        nFrame = 0x18;
                        D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
                        QUESTRECORD_SetQuestState(pQuestInfo, pEntry->nQuestId, 0xC);
                        MSG_SendWord(0x58, (unsigned short)pEntry->nQuestId);
                    }
                    tDraw.pCelFile = gtQuestLog.apIconCels[pEntry->nCelId];
                    tDraw.nFrame = nFrame;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    {
                        const unsigned int dwTick = GetTickCount();
                        if (!gtQuestLog.anTick[gtQuestLog.nMsgCount])
                            gtQuestLog.anTick[gtQuestLog.nMsgCount] = dwTick;
                        if (dwTick - gtQuestLog.anTick[gtQuestLog.nMsgCount] > 100)
                        {
                            gtQuestLog.anTick[gtQuestLog.nMsgCount] = dwTick;
                            gtQuestLog.anAnim[gtQuestLog.nMsgCount] += 1;
                            if (gtQuestLog.anAnim[gtQuestLog.nMsgCount] == 1 && FOG_IsExpansion())
                                sub_004B9A00(0xE, 0, 0, 0, 0);
                        }
                    }
                    nSlot = pEntry->nCelId2;
                    gtQuestLog.nMsgCount += 1;
                    break;
                case 1:
                    gtQuestLog.aMsgs[gtQuestLog.nMsgCount].bShown = 1;
                    if (gtQuestLog.nPressedSlot == pEntry->nCelId2)
                    {
                        tDraw.pCelFile = gtQuestLog.pDoneCel;
                        tDraw.nFrame = pEntry->nCelId;
                        sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gtQuestLog.n270 + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gnQuestAnimOffsetY, -1, 5, 0);
                    }
                    else
                    {
                        tDraw.nFrame = 0x18;
                        tDraw.pCelFile = gtQuestLog.apIconCels[pEntry->nCelId];
                        sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    }
                    nSlot = pEntry->nCelId2;
                    gtQuestLog.nMsgCount += 1;
                    break;
                case 2:
                    gtQuestLog.aMsgs[gtQuestLog.nMsgCount].bShown = 1;
                    tDraw.nFrame = 0x1A;
                    tDraw.pCelFile = gtQuestLog.apIconCels[pEntry->nCelId];
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    nSlot = pEntry->nCelId2;
                    gtQuestLog.nMsgCount += 1;
                    break;
                case 3:
                    if (gtQuestLog.aMsgs[gtQuestLog.nMsgCount].wTitle == 0x3A0 && gtQuestLog.aMsgs[gtQuestLog.nMsgCount].nStep == 7)
                        bSpecial = 1;
                    gtQuestLog.aMsgs[gtQuestLog.nMsgCount].bShown = 1;
                    tDraw.pCelFile = gtQuestLog.apIconCels[pEntry->nCelId];
                    tDraw.nFrame = (gtQuestLog.nPressedSlot == pEntry->nCelId2) ? 0x19 : 0;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    nSlot = pEntry->nCelId2;
                    gtQuestLog.nMsgCount += 1;
                    break;
                }

                tDraw.pCelFile = gtQuestLog.pSocketsCel;
                if (nSlot == gtQuestLog.nSelectedSlot)
                {
                    tDraw.nFrame = 1;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX - 4, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gnQuestIconOffsetY + 5, -1, 5, 0);
                }
                else
                {
                    tDraw.nFrame = 0;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX - 4, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gtQuestLog.n26C + 5, -1, 5, 0);
                }
            }

            ++nRow;
            if (nRow > 0x29 || gtQuestLog.nMsgCount >= 6)
                bDone = 1;
            ++pEntry;
        }
        while (!bDone);

        if (bSpecial && gtQuestLog.nSelectedSlot == 5)
        {
            tDraw.pCelFile = gtQuestLog.pInvPsCel;
            tDraw.nFrame = gtQuestLog.nA8;
            if (tDraw.nFrame < 0 || tDraw.nFrame > 6)
                tDraw.nFrame = 0;
            sub_004F6480(&tDraw, gnPanelOffsetX + 0x6E, gnScreenHeight + gnPanelOffsetY - 0x6E, -1, 3, 0);
        }
    }

    D2Win_10127_SetFont(8);
    const int nSelected = gtQuestLog.nSelectedSlot;
    if (nSelected != -1 && nSelected < 6 && nSelected < gtQuestLog.nMsgCount)
    {
        int nFound = -1;
        for (int k = 0; k < gtQuestLog.nMsgCount; ++k)
        {
            if (gtQuestLog.aMsgs[k].nCelId == nSelected)
            {
                nFound = k;
                break;
            }
        }

        if (nFound != -1 && gtQuestLog.aMsgs[nFound].bShown)
        {
            if (gtQuestLog.aMsgs[nFound].wTitle != 0xE8C)
            {
                const Unicode* pTitle = D2LANG_GetStringFromTblIndex(gtQuestLog.aMsgs[nFound].wTitle);
                D2Win_10117_DrawText(pTitle, gnPanelOffsetX - D2Win_10121_GetTextWidth(pTitle) / 2 + 0xA0, gnQuestTitleY - gnPanelOffsetY, 0, 0);
            }

            if (!gtQuestLog.bDescriptionOpen && gtQuestLog.aMsgs[nFound].wszText[0].wChar)
            {
                int nLines;
                D2SplittedTextStrc* pLine = D2WINFONT_SplitText(gtQuestLog.aMsgs[nFound].wszText, &nLines, 0x10E);
                if (pLine)
                {
                    int nLine = 0;
                    do
                    {
                        D2Win_10117_DrawText(pLine->wszLine, gnPanelOffsetX + gnQuestTextLeft, nLine * 0x14 - gnPanelOffsetY + gnQuestTextTop, 0, 0);
                        D2SplittedTextStrc* pNext = pLine->pNextLine;
                        FOG_Free(pLine->wszLine, ".\\UI\\QuestLog.cpp", 0x8D1, 0);
                        FOG_Free(pLine, ".\\UI\\QuestLog.cpp", 0x8D2, 0);
                        ++nLine;
                        pLine = pNext;
                    }
                    while (pLine);
                }
            }
        }
    }

    tDraw.pCelFile = sub_00454600();
    tDraw.nFrame = (gtQuestLog.bCloseButtonDown != 0) + 0xA;
    sub_004F6480(&tDraw, gnPanelOffsetX + 0x116, gnScreenHeight + gnPanelOffsetY - 0x3A, -1, 5, 0);

    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    nMouseX -= gnPanelOffsetX;
    nMouseY += gnPanelOffsetY;
    if (nMouseX >= 0x116 && nMouseX <= 0x139 && nMouseY >= 0x188 && nMouseY <= 0x1A9)
    {
        D2Win_10127_SetFont(9);
        const Unicode* pHelp = D2LANG_GetStringFromTblIndex(0x1030);
        sub_00502280_SetPopUpText(pHelp, gnPanelOffsetX + 0x128, gnScreenHeight + gnPanelOffsetY - 0x5F, 0, 1);
    }

    tDraw.pCelFile = gtQuestLog.pLastCel;
    tDraw.nFrame = gtQuestLog.bDescButtonDown != 0;
    sub_004F6480(&tDraw, gnPanelOffsetX + 0xE2, gnPanelOffsetY + gnScreenHeight - 0x3A, -1, 5, 0);
    if (nMouseX >= 0xE6 && nMouseX <= 0x103 && nMouseY >= 0x187 && nMouseY <= 0x1A7)
    {
        const Unicode* pText = D2LANG_GetStringFromTblIndex(0xE88);
        D2Win_10127_SetFont(9);
        sub_00502280_SetPopUpText(pText, gnPanelOffsetX + 0xF1, gnScreenHeight + gnPanelOffsetY - 0x5F, 0, 1);
    }
}

static void sub_004A2390_ResetQuestSelection()
{
    gtQuestLog.bQuestSlotDown = 0;
    gtQuestLog.bCloseButtonDown = 0;
    gtQuestLog.bQuestButtonDown = 0;
    gtQuestLog.nPressedSlot = -1;
    gtQuestLog.bDescButtonDown = 0;
    gtQuestLog.bDurielCofsLoaded = 0;
    gtQuestLog.bAncientsCofsLoaded = 0;
    gtQuestLog.bHasQuestPacketValue = 0;
    gtQuestLog.bQuestUnitsSpawned = 0;
}

static __forceinline void sub_004A3E40_ClickSlot_Inline(int nIndex)
{
    for (int i = 0; i < gtQuestLog.nMsgCount; ++i)
    {
        if (nIndex == gtQuestLog.aMsgs[i].nCelId && gtQuestLog.aMsgs[i].bValid)
        {
            gtQuestLog.bQuestSlotDown = 1;
            gtQuestLog.nPressedSlot = nIndex;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
    }
}

// 0x004A3E40
void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam);
    int nY = D2_HIWORD(pMsg->lParam);
    if (INV_IsCinematicBusy())
    {
        return;
    }
    if (nX > gnScreenWidth / 2)
    {
        return;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (nY > gnScreenHeight - 0x2F) return;
    }
    else
    {
        if (nY > gnScreenHeight - 0x31) return;
    }
    nX -= gnPanelOffsetX;
    nY += gnPanelOffsetY;
    int nIndex;
    if (!gtQuestLog.bDescriptionOpen)
    {
        nIndex = TEXT_GetQuestTabAtPoint(nY, nX);
        if (nIndex != -1)
        {
            if (nIndex < 5 && nIndex != gtQuestLog.nPage && ((FOG_IsExpansion() && GAME_IsExpansion()) || nIndex != 4))
            {
                QUESTLOG_SendQuestUpdates(gtQuestLog.nPage);
                TEXT_SetQuestPage(nIndex);
                TEXT_LoadQuestPage(gtQuestLog.nPage, 1);
                sub_004A2390_ResetQuestSelection();
            }
        }
        else
        {
            nIndex = TEXT_GetQuestSlotAtPoint(nX, nY);
            if (nIndex != -1 && nIndex < gtQuestLog.nMsgCount)
            {
                sub_004A3E40_ClickSlot_Inline(nIndex);
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
            else
            {
                if (TEXT_HitTestQuestCloseButton(nX, nY))
                {
                    gtQuestLog.bCloseButtonDown = 1;
                    sub_004B9A00(4, 0, 0, 0, 0);
                }
                else if (TEXT_HitTestButtonA(nX, nY))
                {
                    gtQuestLog.bDescButtonDown = 1;
                    sub_004B9A00(4, 0, 0, 0, 0);
                }
            }
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}




void __stdcall TEXT_LoadQuestPage(int nPage, int nArg);



// 0x004A3FE0
void __fastcall QUESTLOG_ToggleQuestLog(int nMode)
{
    if (gtQuestLog.nState == 0)
    {
        if (GetTickCount() - gtQuestLog.dwToggleTick < 250)
            return;
        if (CUNIT_IsPlayerDeadOrMissing())
            return;
        if (INV_IsCinematicBusy())
            return;
        if (UI_SetUIVar(15, 0, nMode) != 1)
            return;
        QUESTLOG_LoadQuestPanelCels();
        gtQuestLog.nState = 2;
        QUESTLOG_UpdateQuestPage();
        TEXT_LoadQuestPage(gtQuestLog.nPage, 0);
        MSG_SendHeaderOnly(0x40);
        return;
    }

    if (gtQuestLog.nState == 1)
    {
        gtQuestLog.nState = 0;
        if (INV_IsCinematicBusy())
            return;
        if (UI_SetUIVar(15, 0, nMode) != 1)
            return;
        QUESTLOG_LoadQuestPanelCels();
        gtQuestLog.nState = 2;
        QUESTLOG_UpdateQuestPage();
        TEXT_LoadQuestPage(gtQuestLog.nPage, 0);
        MSG_SendHeaderOnly(0x40);
        return;
    }

    QUESTLOG_OpenQuestPanel(nMode);
    gtQuestLog.dwToggleTick = GetTickCount();
    TEXT_Forward();
}






// 0x004A40D0
void __fastcall QUESTLOG_SetQuestRecord(const D2Record42Strc* pRecord)
{
    gtQuestLog.tQuestRecord = *pRecord;
    gtQuestLog.bQuestButtonDown = 0;
    if (!INV_IsCinematicBusy())
    {
        if (gtQuestLog.nState == 2)
        {
            QUESTLOG_LoadQuestPanelCels();
        }
        TEXT_LoadQuestPage(gtQuestLog.nPage, 1);
    }
}

// 0x004A4110
void __stdcall TEXT_QuestButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (sub_004A2970(nX, nY) && gtQuestLog.bQuestButtonDown)
    {
        UI_SetUIVar(17, 1, 0);
        QUESTLOG_ToggleQuestLog(0);
        gtQuestLog.bQuestButtonDown = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    gtQuestLog.bQuestButtonDown = 0;
    pMsg->bReturn = 0;
}

// 0x004A4180
int __fastcall TEXT_TestQuestCondition(int nCondition)
{
    if (!INV_GetTableByte(0, nCondition))
    {
        return 0;
    }

    for (unsigned int i = 0; i < 41; ++i)
    {
        if (gaQuestTable[i].nCondition == nCondition)
        {
            const int nQuestId = gaQuestTable[i].nQuestId;
            if (nQuestId == 0x2A)
            {
                break;
            }

            if (!sub_004B32E0_GetQuestHistory() || QUESTRECORD_GetQuestState(sub_004B32E0_GetQuestHistory(), nQuestId, 0xD))
            {
                break;
            }

            if (!MONSTER_GetQuestFlags() || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), nQuestId, 1)
                || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), nQuestId, 0)
                || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), nQuestId, 0xE))
            {
                break;
            }

            if (nCondition == 1)
            {
                D2QuestTextMsgStrc tMsg;
                tMsg.nQuestId = nQuestId;
                TEXT_BuildQuestText(&tMsg);
                if (tMsg.nStep >= 5)
                {
                    break;
                }
            }

            return 1;
        }
    }

    return 0;
}

// 0x004A4260
D2QuestLogStateStrc::D2QuestLogStateStrc()
{
}

D2QuestLogStateStrc gtQuestLog; // 0x007BF298

// 0x004A42A0
void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnPanelOffsetX;
    int nY = D2_HIWORD(pMsg->lParam) + gnPanelOffsetY;
    if (gtQuestLog.bCloseButtonDown)
    {
        if (TEXT_HitTestQuestCloseButton(nX, nY)) QUESTLOG_ToggleQuestLog(0);
    }
    else if (!gtQuestLog.bDescriptionOpen)
    {
        if (gtQuestLog.nPressedSlot != -1)
        {
            int nSlot = TEXT_GetQuestSlotAtPoint(nX, nY);
            if (nSlot == gtQuestLog.nPressedSlot)
            {
                gtQuestLog.anPageSelection[gtQuestLog.nPage] = nSlot;
                gtQuestLog.nSelectedSlot = nSlot;
            }
        }
        else if (gtQuestLog.bDescButtonDown == 1)
        {
            if (TEXT_HitTestButtonA(nX, nY) && gtQuestLog.nSelectedSlot != -1)
            {
                TEXT_OpenQuestDescription(gtQuestLog.nSelectedSlot);
            }
        }
    }
    D2_RESET_QUEST_SELECTION();
    if (D2_LOWORD(pMsg->lParam) > gnScreenWidth / 2) return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if ((int)(pMsg->lParam >> 16) > gnScreenHeight - 0x2F) return;
    }
    else
    {
        if ((int)(pMsg->lParam >> 16) > gnScreenHeight - 0x31) return;
    }
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}





#pragma pack(push, 1)
struct d2data_007237A4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007237E4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723824_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723864_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007238A4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007238E4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723924_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723964_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007239A4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007239E4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723A24_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723AE4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723B24_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723B64_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723BA4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723BE4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723C24_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723C64_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723CA4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723CE4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723D24_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723D64_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723DA4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723DE4_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723E24_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723E64_t
{
    unsigned char b0[68];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723F00_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723EA8_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00724224_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723768_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_007237A4_t gData_007237A4; // 0x007237A4
extern "C" struct d2data_007237E4_t gData_007237E4; // 0x007237E4
extern "C" struct d2data_00723824_t gData_00723824; // 0x00723824
extern "C" struct d2data_00723864_t gData_00723864; // 0x00723864
extern "C" struct d2data_007238A4_t gData_007238A4; // 0x007238A4
extern "C" struct d2data_007238E4_t gData_007238E4; // 0x007238E4
extern "C" struct d2data_00723924_t gData_00723924; // 0x00723924
extern "C" struct d2data_00723964_t gData_00723964; // 0x00723964
extern "C" struct d2data_007239A4_t gData_007239A4; // 0x007239A4
extern "C" struct d2data_007239E4_t gData_007239E4; // 0x007239E4
extern "C" struct d2data_00723A24_t gData_00723A24; // 0x00723A24
extern "C" struct d2data_00723AE4_t gData_00723AE4; // 0x00723AE4
extern "C" struct d2data_00723B24_t gData_00723B24; // 0x00723B24
extern "C" struct d2data_00723B64_t gData_00723B64; // 0x00723B64
extern "C" struct d2data_00723BA4_t gData_00723BA4; // 0x00723BA4
extern "C" struct d2data_00723BE4_t gData_00723BE4; // 0x00723BE4
extern "C" struct d2data_00723C24_t gData_00723C24; // 0x00723C24
extern "C" struct d2data_00723C64_t gData_00723C64; // 0x00723C64
extern "C" struct d2data_00723CA4_t gData_00723CA4; // 0x00723CA4
extern "C" struct d2data_00723CE4_t gData_00723CE4; // 0x00723CE4
extern "C" struct d2data_00723D24_t gData_00723D24; // 0x00723D24
extern "C" struct d2data_00723D64_t gData_00723D64; // 0x00723D64
extern "C" struct d2data_00723DA4_t gData_00723DA4; // 0x00723DA4
extern "C" struct d2data_00723DE4_t gData_00723DE4; // 0x00723DE4
extern "C" struct d2data_00723E24_t gData_00723E24; // 0x00723E24
extern "C" struct d2data_00723E64_t gData_00723E64; // 0x00723E64
extern "C" struct d2data_00723F00_t gData_00723F00; // 0x00723F00
extern "C" struct d2data_00723EA8_t gData_00723EA8; // 0x00723EA8
extern "C" struct d2data_00724224_t gData_00724224; // 0x00724224
extern "C" struct d2data_00723768_t gData_00723768; // 0x00723768

extern D2QuestTableStrc gaQuestTable[41] = {
    { 0, 0, 0, 0, 0, 37 },
    { 1, 0, 0, 0, (D2QuestTextsStrc*)&gData_007237A4, 1, 1 },
    { 1, 1, 1, 0, (D2QuestTextsStrc*)&gData_007237E4, 2, 2 },
    { 1, 2, 4, 0, (D2QuestTextsStrc*)&gData_00723824, 3, 3 },
    { 1, 3, 2, 0, (D2QuestTextsStrc*)&gData_00723864, 4, 4 },
    { 1, 4, 3, 0, (D2QuestTextsStrc*)&gData_007238A4, 5, 5 },
    { 1, 5, 5, 0, (D2QuestTextsStrc*)&gData_007238E4, 6, 6 },
    { 0, 0, 0, 0, 0, 37, 7 },
    { 0, 0, 0, 1, 0, 37, 8 },
    { 1, 6, 0, 1, (D2QuestTextsStrc*)&gData_00723924, 8, 9 },
    { 1, 7, 1, 1, (D2QuestTextsStrc*)&gData_00723964, 9, 10 },
    { 1, 8, 2, 1, (D2QuestTextsStrc*)&gData_007239A4, 10, 11 },
    { 1, 9, 3, 1, (D2QuestTextsStrc*)&gData_007239E4, 11, 12 },
    { 1, 0xA, 4, 1, (D2QuestTextsStrc*)&gData_00723A24, 12, 13 },
    { 1, 0xB, 5, 1, (D2QuestTextsStrc*)&gtQuestTextsSevenTombs, 13, 14 },
    { 0, 0, 0, 1, 0, 37, 15 },
    { 0, 0, 0, 2, 0, 37, 16 },
    { 1, 0xC, 3, 2, (D2QuestTextsStrc*)&gData_00723AE4, 15, 17 },
    { 1, 0xD, 2, 2, (D2QuestTextsStrc*)&gData_00723B24, 16, 18 },
    { 1, 0xE, 1, 2, (D2QuestTextsStrc*)&gData_00723B64, 17, 19 },
    { 1, 0xF, 0, 2, (D2QuestTextsStrc*)&gData_00723BA4, 18, 20 },
    { 1, 0x10, 4, 2, (D2QuestTextsStrc*)&gData_00723BE4, 19, 21 },
    { 1, 0x11, 5, 2, (D2QuestTextsStrc*)&gData_00723C24, 20, 22 },
    { 0, 0, 0, 2, 0, 37, 23 },
    { 0, 0, 0, 3, 0, 37, 24 },
    { 1, 0x12, 0, 3, (D2QuestTextsStrc*)&gtQuestTextsFallenAngel, 22, 25 },
    { 1, 0x14, 2, 3, (D2QuestTextsStrc*)&gData_00723CA4, 23, 26 },
    { 1, 0x13, 1, 3, (D2QuestTextsStrc*)&gData_00723CE4, 24, 27 },
    { 0, 0, 0, 3, 0, 37, 28 },
    { 0, 0, 0, 9, 0, 37, 29 },
    { 0, 0, 0, 9, 0, 37, 30 },
    { 0, 0, 0, 9, 0, 37, 31 },
    { 0, 0, 0, 9, 0, 37, 32 },
    { 0, 0, 0, 9, 0, 37, 33 },
    { 0, 0, 0, 4, 0, 30, 34 },
    { 1, 0x15, 0, 4, (D2QuestTextsStrc*)&gtQuestTextsSiege, 31, 35 },
    { 1, 0x16, 1, 4, (D2QuestTextsStrc*)&gData_00723D64, 32, 36 },
    { 1, 0x17, 2, 4, (D2QuestTextsStrc*)&gData_00723DA4, 33, 37 },
    { 1, 0x18, 3, 4, (D2QuestTextsStrc*)&gData_00723DE4, 34, 38 },
    { 1, 0x19, 4, 4, (D2QuestTextsStrc*)&gData_00723E24, 35, 39 },
    { 1, 0x1A, 5, 4, (D2QuestTextsStrc*)&gData_00723E64, 36, 40 }
}; // 0x00723F30

extern "C" struct d2data_007237A4_t gData_007237A4 = {
    {
        0x82, 0x0E, 0x4C, 0x00, 0x04, 0x00, 0x97, 0x0E, 0x40, 0x00, 0x98, 0x0E, 0x40, 0x00, 0x99, 0x0E,
        0x40, 0x00, 0x9A, 0x0E, 0x40, 0x00, 0x9C, 0x0E, 0x40, 0x00, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x9C, 0x0E, 0x40, 0x00, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x40
    }
}; // 0x007237A4

extern "C" struct d2data_007237E4_t gData_007237E4 = {
    {
        0x83, 0x0E, 0x5C, 0x00, 0x02, 0x00, 0x9D, 0x0E, 0x51, 0x00, 0x9E, 0x0E, 0x51, 0x00, 0x9F, 0x0E,
        0x51, 0x00, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x9F, 0x0E, 0x51, 0x00, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x51
    }
}; // 0x007237E4

extern "C" struct d2data_00723824_t gData_00723824 = {
    {
        0x84, 0x0E, 0xA3, 0x00, 0xFF, 0xFF, 0xAB, 0x0E, 0x92, 0x00, 0xAC, 0x0E, 0x92, 0x00, 0x95, 0x0E,
        0x92, 0x00, 0x94, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xAD, 0x0E, 0xA3, 0x00, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x92
    }
}; // 0x00723824

extern "C" struct d2data_00723864_t gData_00723864 = {
    {
        0x85, 0x0E, 0x7B, 0x00, 0xFF, 0xFF, 0xA0, 0x0E, 0x61, 0x00, 0xA1, 0x0E, 0x61, 0x00, 0xA2, 0x0E,
        0x61, 0x00, 0xA3, 0x0E, 0x61, 0x00, 0xA4, 0x0E, 0x61, 0x00, 0xA5, 0x0E, 0x61, 0x00, 0x96, 0x0E,
        0x61, 0x00, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xA6, 0x0E, 0x61, 0x00, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x61
    }
}; // 0x00723864

extern "C" struct d2data_007238A4_t gData_007238A4 = {
    {
        0x86, 0x0E, 0x7F, 0x00, 0xFF, 0xFF, 0xA7, 0x0E, 0x7F, 0x00, 0xAA, 0x0E, 0x7F, 0x00, 0xA8, 0x0E,
        0x7F, 0x00, 0xA9, 0x0E, 0x7F, 0x00, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x7F
    }
}; // 0x007238A4

extern "C" struct d2data_007238E4_t gData_007238E4 = {
    {
        0x87, 0x0E, 0xB8, 0x00, 0x09, 0x00, 0xAE, 0x0E, 0xA6, 0x00, 0xAF, 0x0E, 0xA6, 0x00, 0xB1, 0x0E,
        0xA6, 0x00, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xB0, 0x0E, 0xA6, 0x00, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0xB8
    }
}; // 0x007238E4

extern "C" struct d2data_00723924_t gData_00723924 = {
    {
        0x9B, 0x03, 0x4E, 0x01, 0x02, 0x00, 0xAD, 0x03, 0x30, 0x01, 0xAE, 0x03, 0x30, 0x01, 0xAF, 0x03,
        0x30, 0x01, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xAF, 0x03, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x30, 0x01
    }
}; // 0x00723924

extern "C" struct d2data_00723964_t gData_00723964 = {
    {
        0x9C, 0x03, 0x53, 0x01, 0xFF, 0xFF, 0xB0, 0x03, 0x8D, 0x0E, 0xB1, 0x03, 0x4F, 0x01, 0xB2, 0x03,
        0x52, 0x01, 0xB4, 0x03, 0x8D, 0x0E, 0xB3, 0x03, 0x53, 0x01, 0xB3, 0x03, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x92, 0x0E, 0x8D, 0x0E, 0xB3, 0x03, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x53, 0x01
    }
}; // 0x00723964

extern "C" struct d2data_007239A4_t gData_007239A4 = {
    {
        0x9D, 0x03, 0x8D, 0x0E, 0xFF, 0xFF, 0xB6, 0x03, 0x8D, 0x0E, 0xB7, 0x03, 0x8D, 0x0E, 0xB8, 0x03,
        0x5C, 0x01, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xB8, 0x03, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x007239A4

extern "C" struct d2data_007239E4_t gData_007239E4 = {
    {
        0x9E, 0x03, 0x8D, 0x0E, 0xFF, 0xFF, 0xBA, 0x03, 0x8D, 0x0E, 0xB9, 0x03, 0x75, 0x01, 0xB9, 0x03,
        0x79, 0x01, 0xBB, 0x03, 0x79, 0x01, 0xBC, 0x03, 0x8C, 0x01, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xBC, 0x03, 0x8C, 0x01, 0x90, 0x0E,
        0x8C, 0x01, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8C, 0x01
    }
}; // 0x007239E4

extern "C" struct d2data_00723A24_t gData_00723A24 = {
    {
        0x9F, 0x03, 0x8D, 0x0E, 0xFF, 0xFF, 0xBD, 0x03, 0x8D, 0x0E, 0xBE, 0x03, 0x8D, 0x0E, 0x8E, 0x0E,
        0x8D, 0x0E, 0xBF, 0x03, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xBF, 0x03, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723A24

extern D2QuestTextsStrc gtQuestTextsSevenTombs = { {
    0x3A0, 0x1BA, 4, 0x3C0, 0x1AE, 0x3C2, 0x1AF, 0x2B16, 0x1AF, 0x3C4, 0x1AF, 0x3C5, 0x12E, 0x3C6, 0x1BA, 0x3C1,
    0x18C, 0xE91, 0xE8D, 0xE92, 0xE8D, 0x3C5, 0xE8D, 0xE90, 0xE8D, 0xE8F, 0xE8D, 0xE8E, 0x1BA, 0, 0, 0,
    0x3A1, 0xE8D, 0xFFFF, 0x3C7, 0x1D1, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D,
    0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D, 0xE8D
} }; // 0x00723A64

extern "C" struct d2data_00723AE4_t gData_00723AE4 = {
    {
        0xA2, 0x03, 0x34, 0x02, 0xFF, 0xFF, 0xC8, 0x03, 0x25, 0x02, 0xC9, 0x03, 0x25, 0x02, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x92, 0x0E, 0x8D, 0x0E, 0x91, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723AE4

extern "C" struct d2data_00723B24_t gData_00723B24 = {
    {
        0xA3, 0x03, 0x24, 0x02, 0xFF, 0xFF, 0xCA, 0x03, 0x1F, 0x02, 0xCB, 0x03, 0x1F, 0x02, 0xCC, 0x03,
        0x1F, 0x02, 0xCD, 0x03, 0x1F, 0x02, 0xCE, 0x03, 0x1F, 0x02, 0xCF, 0x03, 0x24, 0x02, 0xD0, 0x03,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723B24

extern "C" struct d2data_00723B64_t gData_00723B64 = {
    {
        0xA4, 0x03, 0x4B, 0x02, 0xFF, 0xFF, 0xE1, 0x03, 0x8D, 0x0E, 0xD1, 0x03, 0x3B, 0x02, 0xD2, 0x03,
        0x3B, 0x02, 0xD3, 0x03, 0x3B, 0x02, 0xD4, 0x03, 0x4B, 0x02, 0xD5, 0x03, 0x4B, 0x02, 0x92, 0x0E,
        0x8D, 0x0E, 0x91, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x90, 0x0E, 0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x4B, 0x02
    }
}; // 0x00723B64

extern "C" struct d2data_00723BA4_t gData_00723BA4 = {
    {
        0xA5, 0x03, 0x8D, 0x0E, 0x04, 0x00, 0xD6, 0x03, 0x8D, 0x0E, 0xD7, 0x03, 0x0F, 0x02, 0xD8, 0x03,
        0x11, 0x02, 0xD9, 0x03, 0x13, 0x02, 0xDA, 0x03, 0x16, 0x02, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xDA, 0x03, 0x16, 0x02, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723BA4

extern "C" struct d2data_00723BE4_t gData_00723BE4 = {
    {
        0xA6, 0x03, 0x8D, 0x0E, 0x03, 0x00, 0xE2, 0x03, 0x8D, 0x0E, 0xDB, 0x03, 0x52, 0x02, 0xDC, 0x03,
        0x52, 0x02, 0xDD, 0x03, 0x52, 0x02, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xDD, 0x03, 0x52, 0x02, 0x90, 0x0E,
        0x72, 0x02, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x72, 0x02
    }
}; // 0x00723BE4

extern "C" struct d2data_00723C24_t gData_00723C24 = {
    {
        0xA7, 0x03, 0x8D, 0x0E, 0x04, 0x00, 0xE3, 0x03, 0x8D, 0x0E, 0xDE, 0x03, 0x74, 0x02, 0xDF, 0x03,
        0x74, 0x02, 0xE0, 0x03, 0x74, 0x02, 0xA7, 0x03, 0x74, 0x02, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723C24

extern "C" struct d2data_00723C64_t gData_00723C64 = {
    {
        0xA9, 0x03, 0xA3, 0x02, 0xFF, 0xFF, 0xE4, 0x03, 0x9E, 0x02, 0xE5, 0x03, 0x9E, 0x02, 0xE6, 0x03,
        0x9E, 0x02, 0xE7, 0x03, 0xA3, 0x02, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0xE7, 0x03, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0xA4, 0x02
    }
}; // 0x00723C64
#pragma comment(linker, "/alternatename:?gtQuestTextsFallenAngel@@3UD2QuestTextsStrc@@A=_gData_00723C64")

extern "C" struct d2data_00723CA4_t gData_00723CA4 = {
    {
        0xAA, 0x03, 0x8D, 0x0E, 0xFF, 0xFF, 0xEC, 0x03, 0xA9, 0x02, 0xED, 0x03, 0xA9, 0x02, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723CA4

extern "C" struct d2data_00723CE4_t gData_00723CE4 = {
    {
        0xAB, 0x03, 0x8D, 0x0E, 0xFF, 0xFF, 0xE8, 0x03, 0xA6, 0x02, 0xE9, 0x03, 0xA6, 0x02, 0xEA, 0x03,
        0xA6, 0x02, 0xE8, 0x03, 0xA7, 0x02, 0x8D, 0x0E, 0x8D, 0x0E, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723CE4

extern "C" struct d2data_00723D24_t gData_00723D24 = {
    {
        0x5A, 0x58, 0x8D, 0x0E, 0xFF, 0xFF, 0x5B, 0x58, 0x6D, 0x4E, 0x5C, 0x58, 0x6D, 0x4E, 0x5D, 0x58,
        0x6D, 0x4E, 0x1A, 0x55, 0x7A, 0x4E, 0x8D, 0x0E, 0x8D, 0x0E, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x1A, 0x55, 0x7A, 0x4E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723D24
#pragma comment(linker, "/alternatename:?gtQuestTextsSiege@@3UD2QuestTextsStrc@@A=_gData_00723D24")

extern "C" struct d2data_00723D64_t gData_00723D64 = {
    {
        0x5E, 0x58, 0x8D, 0x0E, 0xFF, 0xFF, 0x5F, 0x58, 0x80, 0x4E, 0x60, 0x58, 0x88, 0x4E, 0x61, 0x58,
        0x80, 0x4E, 0x62, 0x58, 0x80, 0x4E, 0x1D, 0x55, 0x80, 0x4E, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x61, 0x58, 0x80, 0x4E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723D64

extern "C" struct d2data_00723DA4_t gData_00723DA4 = {
    {
        0x63, 0x58, 0x8D, 0x0E, 0xFF, 0xFF, 0x64, 0x58, 0x94, 0x4E, 0x1C, 0x55, 0x94, 0x4E, 0x65, 0x58,
        0x94, 0x4E, 0x66, 0x58, 0x94, 0x4E, 0x67, 0x58, 0x94, 0x4E, 0x68, 0x58, 0x94, 0x4E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x67, 0x58, 0x94, 0x4E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723DA4

extern "C" struct d2data_00723DE4_t gData_00723DE4 = {
    {
        0x69, 0x58, 0x8D, 0x0E, 0xFF, 0xFF, 0x6A, 0x58, 0xA9, 0x4E, 0x1B, 0x55, 0xA9, 0x4E, 0x6B, 0x58,
        0xA9, 0x4E, 0x6C, 0x58, 0xA9, 0x4E, 0x1E, 0x55, 0xB4, 0x4E, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x1E, 0x55, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723DE4

extern "C" struct d2data_00723E24_t gData_00723E24 = {
    {
        0x6D, 0x58, 0x8D, 0x0E, 0x03, 0x00, 0x6E, 0x58, 0xB9, 0x4E, 0x6F, 0x58, 0xB9, 0x4E, 0x70, 0x58,
        0x22, 0x4E, 0x6F, 0x58, 0x22, 0x4E, 0x8D, 0x0E, 0x8D, 0x0E, 0x91, 0x0E, 0x8D, 0x0E, 0x92, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x6F, 0x58, 0x22, 0x4E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723E24

extern "C" struct d2data_00723E64_t gData_00723E64 = {
    {
        0x71, 0x58, 0x8D, 0x0E, 0xFF, 0xFF, 0x20, 0x55, 0xC9, 0x4E, 0x79, 0x55, 0xC9, 0x4E, 0x73, 0x58,
        0xC9, 0x4E, 0x74, 0x58, 0xC9, 0x4E, 0x75, 0x58, 0xC9, 0x4E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E,
        0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x8D, 0x0E, 0x90, 0x0E, 0x8D, 0x0E, 0x90, 0x0E,
        0x8D, 0x0E, 0x8F, 0x0E, 0x8D, 0x0E, 0x8E, 0x0E, 0x8D, 0x0E
    }
}; // 0x00723E64

extern D2QuestPageRangeStrc gaQuestPageRanges[5] = {
    { 0, 5 },
    { 6, 11 },
    { 12, 17 },
    { 18, 20 },
    { 21, 26 }
}; // 0x00723F08

extern D2QuestSlotRectStrc gaQuestSlots[5] = {
    { 32, 65, 123, 121 },
    { 128, 65, 220, 121 },
    { 224, 65, 26, 218 },
    { 32, 163, 123, 218 },
    { 128, 163, 220, 218 }
}; // 0x00723EB0

extern "C" struct d2data_00723F00_t gData_00723F00 = {
    { 0xE0, 0x00, 0x00, 0x00, 0xA3 }
}; // 0x00723F00

extern "C" struct d2data_00723EA8_t gData_00723EA8 = {
    { 0x1A, 0x00, 0x00, 0x00, 0x79 }
}; // 0x00723EA8
#pragma comment(linker, "/alternatename:?gaQuestPos@@3PAUD2QuestPosStrc@@A=_gData_00723EA8")

extern int gnQuestTextTop = 270; // 0x00724210

extern int gnQuestTextLeft = 16; // 0x00724214

extern int gnQuestTitleY = 248; // 0x00724218

extern int gnQuestIconOffsetY = -1; // 0x0072421C

extern int gnQuestAnimOffsetY = -1; // 0x00724220

extern "C" struct d2data_00724224_t gData_00724224 = {
    { 0x00 }
}; // 0x00724224

extern "C" struct d2data_00723768_t gData_00723768 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00723768
struct D2CelFileStrc;
