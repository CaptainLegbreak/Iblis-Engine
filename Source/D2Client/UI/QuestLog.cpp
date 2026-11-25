#include "D2Client.h"
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags();                                                           // 0x004B32D0
int __stdcall INV_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                       // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc);                   // 0x00526700
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);            // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                               // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...);  // 0x005269D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

extern const char gszFormatD[];                                                                    // 0x006D57BC
extern D2QuestTextsStrc gtQuestTextsSevenTombs;                                                              // 0x00723A64
extern D2QuestTextsStrc gtQuestTextsFallenAngel;                                                              // 0x00723C64
extern D2QuestTextsStrc gtQuestTextsSiege;                                                              // 0x00723D24
extern D2QuestPageRangeStrc gaQuestPageRanges[];                                                   // 0x00723F08
extern D2QuestTableStrc gaQuestTable[];                                                            // 0x00723F30
extern int gaQuestPageDefault[5];                                                                    // 0x007BF280
extern int gnQuestAct;                                                                               // 0x007BF2A4
extern int gnQuestParam;                                                                               // 0x007BF2AC
extern void* gapQuestIconCels[27];                                                                        // 0x007BF2E1
extern unsigned char gabQuestFlagsA[];                                                             // 0x007BF356
extern unsigned char gabQuestFlagsB[];                                                             // 0x007BF380




void __stdcall TEXT_LoadQuestPage(int nPage, int bReset);                                           // 0x004A3220
static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg);                                          // 0x004A1950



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __cdecl CUNIT_IsPlayerDeadOrMissing();                                                                                 // 0x00463DF0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
void __cdecl QUESTLOG_LoadQuestPanelCels();                                                                  // 0x004A23D0
int __stdcall QUESTLOG_OpenQuestPanel(int nArg);                                                             // 0x004A26B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                      // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320
D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970
int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
extern D2QuestPosStrc gaQuestPos[];                                                                // 0x00723EA8
extern int gnPanelOffsetX;                                                                               // 0x007A2858
extern int gnPanelOffsetY;                                                                               // 0x007A285C


extern D2QuestLogStateStrc gtQuestLog_007BF298;                                                             // 0x007BF298

extern D2UiEntry10Strc gaQuestLookup[41]; // 0x00723F38

static inline int sub_004A1950_GetActNumber(const D2QuestTextsStrc* pTexts)
{
    if (pTexts->awIds[0] == 0xE82)
    {
        return gnQuestAct;
    }
    return 0;
}

static void TEXT_SetQuestPage(int nPageArg); // 0x004A2220


extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0

void __fastcall WARDENCLIENT_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

#define SOUND_ID 4

void __cdecl GAME_RequestExit(); // 0x0044D520

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990

extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820

void __cdecl INV_ChainCinematic(); // 0x00483340

void __cdecl GAME_SetDifficultyFlags(); // 0x0044EC80

void __cdecl INV_StopCinematic(); // 0x00483300

void __fastcall GAME_SetPlayCinematic(int nValue); // 0x0044D530

void __fastcall sub_0046BFD0_StartTimer(int nDelay); // 0x0046BFD0

extern D2QuestUiFlagsStrc gtQuestUiFlags_007BF2B3; // 0x007BF2B3

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nId;
    unsigned char nFlags;
    unsigned char nValue;
    short nParam;
};

struct SMSGHANDLER_PARAMS;


int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

void __stdcall TEXT_LoadQuestPage(int nPage, int nArg); // 0x004A3220

extern char gbGlobal_007BF2B2; // 0x007BF2B2

extern char gbGlobal_007BF2B4; // 0x007BF2B4

extern int gnIndex_007BF2BD; // 0x007BF2BD

extern int gnIndex_007BF2C1; // 0x007BF2C1

extern int gnIndex_007BF2C5; // 0x007BF2C5

extern int gnIndex_007BF2C9; // 0x007BF2C9

extern int gnIndex_007BF2CD; // 0x007BF2CD


extern char gbGlobal_007C025D; // 0x007C025D

extern char gbGlobal_007C025E; // 0x007C025E

extern char gbGlobal_007C025F; // 0x007C025F

extern char gbGlobal_007C0260; // 0x007C0260

bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970

struct D2QuestTextLineStrc
{
    unsigned short wLead[9];
    Unicode wszText[300];
};

struct D2QuestTextBufferStrc
{
    unsigned char pHead[0x106];
    D2QuestTextLineStrc pLines[6];

    D2QuestTextBufferStrc();
};


extern int gnQuestCount; // 0x007BF2A0

// 0x004A18E0
static inline void TEXT_SetQuestIndex(int nIndex)
{
// build: symbol ?gnQuestSelectedSlot@* 0x007BF2B9
    gnQuestSelectedSlot = nIndex;
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
        if (gaQuestLookup[i].nKey == nKey)
            return i;
    }
    return -1;
}

// 0x004A1930
static inline int TEXT_FindEntryIndex(int nId)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaQuestLookup[i].nId == nId)
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
    unsigned char nStep = gabQuestFlagsA[nIndex];
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
        gabQuestFlagsB[nIndex] = nStep;
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
        gabQuestFlagsB[nIndex] = nStep;
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
        gabQuestFlagsB[nIndex] = nStep;
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
        pMsg->bStepChanged = nStep != gabQuestFlagsB[nIndex];
        const unsigned short wDesc = pIds[2];
        gabQuestFlagsB[nIndex] = nStep;
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
        gabQuestFlagsB[nIndex] = nStep;
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
        gabQuestFlagsB[nIndex] = nNewStep;
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
            else if (pTexts->awIds[0] == 0xE82 && gnQuestAct > 1)
            {
                Unicode wszNumber[10];
                char szNumber[6];
                sprintf(szNumber, gszFormatD, sub_004A1950_GetActNumber(pTexts));
                sub_00526320_ToUnicode(wszNumber, szNumber, 9);
                sub_005267E0(pMsg->wszText, pString);
                D2_ASSERT(sub_00526800(pString) < 0x118, 0x4FA);
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
            if (nStep != gabQuestFlagsB[nIndex])
            {
                pMsg->bStepChanged = 1;
            }
            gabQuestFlagsB[nIndex] = nStep;
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
            nString = gdwGlobal_007A0610 ? 0xE92 : 0xE91;
        }
        else
        {
            nString = pTexts->awIds[nStep * 2 + 1];
            if ((unsigned short)nString == 0xE8F && !gdwGlobal_007A0610)
            {
                nString = 0xE91;
            }
        }

        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        if (pTexts->awIds[0] == 0x585E && (unsigned short)nString == 0x5860)
        {
            if (!gnQuestParam)
            {
                sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(0xE91), 300);
            }
            else
            {
                sub_005269D0(300, pMsg->wszText, D2LANG_GetStringFromTblIndex(0x5860), gnQuestParam);
            }
        }

        pMsg->wszText[300 - 1] = 0;
        pMsg->bStepChanged = 0;
        if (nStep != gabQuestFlagsB[nIndex] && gaQuestTable[nIndex].pTexts)
        {
            pMsg->bStepChanged = 1;
        }
        const unsigned short wDesc = pTexts->awIds[nStep * 2 + 2];
        gabQuestFlagsB[nIndex] = nStep;
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
            if (!gdwGlobal_007A0610)
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
        if (!gdwGlobal_007A0610)
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
// build: symbol ?gnQuestSelectedSlot@* 0x007BF2B9
    gnQuestSelectedSlot = -1;
// build: symbol ?gnQuestPressedSlot@* 0x007BF2B5
    gnQuestPressedSlot = -1;
    for (int i = 0; i < 6; ++i)
    {
        ganGlobal_007C0225[i] = 0;
        ganGlobal_007C023D[i] = 0;
    }
// build: symbol ?gnPage@* 0x007C0255
    gnPage = nPage;
}



D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0


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
    gnPage = nPage;
    for (int i = 0; i < 6; ++i)
    {
        ganGlobal_007C0225[i] = 0;
        ganGlobal_007C023D[i] = 0;
    }
    gnQuestSelectedSlot = -1;
    gnQuestPressedSlot = -1;
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

extern "C" { unsigned char gByte_007BF2B1; } // 0x007BF2B1

extern "C" unsigned char gByte_007BF2B2; // 0x007BF2B2

extern "C" unsigned char gByte_007BF2B0; // 0x007BF2B0

extern "C" int gSentinel_007BF2B5; // 0x007BF2B5

extern "C" unsigned char gByte_007BF2B4; // 0x007BF2B4

extern "C" unsigned char gByte_007C025D; // 0x007C025D

extern "C" unsigned char gByte_007C025E; // 0x007C025E

extern "C" unsigned char gByte_007C025F; // 0x007C025F

extern "C" unsigned char gByte_007C0260; // 0x007C0260

// 0x004A2390
extern "C" void __cdecl QUESTLOG_ResetQuestGlobals(void)
{
    gByte_007BF2B1 = 0;
    gByte_007BF2B2 = 0;
    gByte_007BF2B0 = 0;
    gSentinel_007BF2B5 = -1;
    gByte_007BF2B4 = 0;
    gByte_007C025D = 0;
    gByte_007C025E = 0;
    gByte_007C025F = 0;
    gByte_007C0260 = 0;
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
    if (sub_00483350())
    {
        return;
    }
// build: symbol ?gpQuestBackgroundCel@* 0x007BF2D5
    if (!gpQuestBackgroundCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questbackground", gszDataGlobal);
        gpQuestBackgroundCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestTabsCel@* 0x007BF2D9
    if (!gpQuestTabsCel)
    {
        if (FOG_IsExpansion() && GAME_IsExpansion())
        {
            sprintf(szPath, "%s\\ui\\menu\\expquesttabs", gszDataGlobal);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\questtabs", gszDataGlobal);
        }
        gpQuestTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestSocketsCel@* 0x007BF2D1
    if (!gpQuestSocketsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questsockets", gszDataGlobal);
        gpQuestSocketsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestDoneCel@* 0x007BF2DD
    if (!gpQuestDoneCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questdone", gszDataGlobal);
        gpQuestDoneCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpInvPsCel@* 0x007BF351
    if (!gpInvPsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\invps", gszDataGlobal);
        gpInvPsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestLastCel@* 0x007BF34D
    if (!gpQuestLastCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questlast", gszDataGlobal);
        gpQuestLastCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

// 0x004A2550
void __cdecl QUESTLOG_FreeQuestCels()
{
    if (gpQuestBackgroundCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestBackgroundCel);
        gpQuestBackgroundCel = 0;
    }
    if (gpQuestTabsCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestTabsCel);
        gpQuestTabsCel = 0;
    }
    if (gpQuestLastCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestLastCel);
        gpQuestLastCel = 0;
    }
    if (gpQuestSocketsCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestSocketsCel);
        gpQuestSocketsCel = 0;
    }
    if (gpQuestDoneCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestDoneCel);
        gpQuestDoneCel = 0;
    }
    if (gpInvPsCel)
    {
        ARCHIVE_FreeClientCellFile(gpInvPsCel);
        gpInvPsCel = 0;
    }
    for (int i = 0; i < 27; ++i)
    {
        if (gapQuestIconCels[i])
        {
            ARCHIVE_FreeClientCellFile(gapQuestIconCels[i]);
            gapQuestIconCels[i] = 0;
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
    int nCount = gnQuestCount;
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


extern int gtQuestLog; // 0x007BF298

char gbGlobal_007BF2B0; // 0x007BF2B0

char gbQuestDescriptionOpen; // 0x007BF2B3

// 0x004A26B0
int __stdcall QUESTLOG_OpenQuestPanel(int nArg)
{
    if (gtQuestLog == 2)
    {
        gtQuestLog = 0;
        gbGlobal_007BF2B0 = 0;
        gbQuestDescriptionOpen = 0;
    }

    sub_004A2550();
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

int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

struct D2QuestPanelEntryStrc;


int gnQuestCount; // 0x007BF2A0

extern D2QuestPanelEntryStrc gaQuestEntries[]; // 0x007BF3AA

// 0x004A2760
void __cdecl QUESTLOG_SendQuestUpdates()
{
    for (int i = 0; i < gnQuestCount; ++i)
    {
        if (!gaQuestEntries[i].bDone)
        {
            D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
            QUESTRECORD_SetQuestState(pQuestInfo, gaQuestEntries[i].nQuestId, 0xC);
            MSG_SendWord(0x58, (unsigned short)gaQuestEntries[i].nQuestId);
        }
    }
}

// 0x004A27B0
int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue)
{
    gbQuestDescriptionOpen = 0;
    TEXT_SetTextCallback(0, pContext);
    return 0;
}

// 0x004A27D0
static void TEXT_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gnQuestCount; ++i)
    {
        if (gaQuestEntries[i].nSlot == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gaQuestEntries[nIndex].wTextId;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    WARDENCLIENT_OpenTextPanel(wTextId, 1, 0);
    TEXT_SetTextCallback(QUESTLOG_CloseQuestText, 0);
    gbQuestDescriptionOpen = 1;
}

// 0x004A2840
void __stdcall TEXT_CloseQuestPanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gtQuestLog == 2)
    {
        gtQuestLog = 0;
        gbGlobal_007BF2B0 = 0;
        gbQuestDescriptionOpen = 0;
    }

    sub_004A2550();
    UI_SetUIVar(15, 1, 1);
    gdwQuestLogToggleTick = GetTickCount();
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

extern "C" unsigned int gValue_007BF2A4; // 0x007BF2A4

extern "C" unsigned int gValue_007BF2AC; // 0x007BF2AC

extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8

// 0x004A28A0
extern "C" void __fastcall QUESTLOG_AcceptShortPacket(const PacketShorts* packet)
{
    switch (packet->kind)
    {
    case 1:
        gValue_007BF2A4 = packet->a;
        gValue_007BF2A8 = packet->b;
        gValue_007BF2AC = packet->c;
        break;
    }
}

// 0x004A28D0
void __cdecl QUESTLOG_ResetQuestButton()
{
    if (gnPage < 5)
        sub_004A2760(gnPage);
    gbGlobal_007BF2B0 = 0;
    gtQuestLog = 0;
    gbQuestDescriptionOpen = 0;
    sub_004A2550();
}

extern int gnScreenWidth; // 0x0071146C

int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY); // 0x004A2970

struct D2ButtonLayoutStrc;

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160


int __cdecl sub_0045AE90(); // 0x0045AE90

// build: symbol ??__EgaButtonLayouts@@YAXXZ 0x006CAC30
D2ButtonLayoutStrc gaButtonLayouts[4] = // 0x007241C0
{
    { 40, 75, gnScreenHeight - 140, gnScreenHeight - 105, gnScreenHeight - 143 },
    { gnScreenWidth / 2 + 40, gnScreenWidth / 2 + 75, gnScreenHeight - 140, gnScreenHeight - 105, gnScreenHeight - 143 },
    { 40, 75, gnScreenHeight - 195, gnScreenHeight - 160, gnScreenHeight - 198 },
    { gnScreenWidth / 2 + 40, gnScreenWidth / 2 + 75, gnScreenHeight - 195, gnScreenHeight - 160, gnScreenHeight - 198 },
};

// build: symbol ?sub_E10_GetButtonLayoutCopy@@YAHH@Z 0x004A2900
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
static int QUESTLOG_GetButtonLayout(int nMode)
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

// 0x004A2970
int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY)
{
    const int nMode = sub_0045AE90();
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
        gbGlobal_007BF2B0 = 1;
        sub_004B9A00(SOUND_ID, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gbGlobal_007BF2B0 = 0;
        pMsg->bReturn = 0;
    }
}


D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

extern void* gpLevelCel; // 0x007C02DC

extern void* gpLevelSocketCel; // 0x007C02E0

// 0x004A2A80
void __cdecl QUESTLOG_DrawQuestButton()
{
    if (CUNIT_IsPlayerDeadOrMissing())
    {
        UI_SetUIVar(0x11, 1, 0);
        if (gtQuestLog == 1)
        {
            gbGlobal_007BF2B0 = 0;
            gtQuestLog = 0;
        }
        return;
    }

    const int nMode = sub_0045AE90();
    if (nMode == 3)
        return;
    if (GAME_GetUIVarState(0x0F))
        return;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.nDirection = 0;
    tCel.pCellFile = gpLevelSocketCel;
    tCel.nFrame = 0;
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nCelWidth = CelGetWidth(CelGetHandle(&tCel));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF58));
    int nTextX = nCelWidth / 2 - nTextWidth / 2 + gaButtonLayouts[nIndex].nTextX + 1;
    const int nTextY = gaButtonLayouts[nIndex].nTextY + gnScreenHeight - 0x1E0;
    if (sub_0045AE90() == 2)
        nTextX += (gnScreenWidth - 0x280) / 2;
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF58), nTextX, nTextY, 0, 0);

    int nCelX = gaButtonLayouts[nIndex].nTextX;
    const int nCelY = gaButtonLayouts[nIndex].nBottom + gnScreenHeight - 0x1E0;
    if (sub_0045AE90() == 2)
        nCelX += (gnScreenWidth - 0x280) / 2;
    sub_004F6480(&tCel, nCelX, nCelY, -1, 5, 0);

    tCel.pCellFile = gpLevelCel;
    tCel.nFrame = gbGlobal_007BF2B0 && (unsigned char)QUESTLOG_IsMouseOnQuestButton(sub_00468730(), sub_00468740());
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
                gnQuestParam = pPacket->nParam;
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

                gnQuestAct = pPacket->nParam;
                if (gnQuestAct > 5 || gnQuestAct < 0)
                {
                    gnQuestAct = 666;
                }

                if (gnQuestAct != 5)
                {
                    gtQuestUiFlags_007BF2B3.abFlags[TEXT_FindQuestIndex(1)] = pPacket->nValue;
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
    if (!gnState_007BF298)
    {
        if (UI_SetUIVar(17, 0, 0) == 1)
        {
            QUESTLOG_SelectQuestPage(pPacket->nId);
            gnState_007BF298 = 1;
        }
        return;
    }

    if (GAME_GetUIVarState(15))
    {
        int nIndex = TEXT_FindQuestIndex(pPacket->nId);
        if (nIndex != -1)
        {
            gtQuestUiFlags_007BF2B3.abFlags[nIndex] = pPacket->nValue;
            if (!gtQuestUiFlags_007BF2B3.bLocked)
            {
                D2QuestTableStrc* pEntry = &gaQuestTable[nIndex];
// build: symbol ?gnPage@* 0x007C0255
                if (pEntry->nPage == gnPage)
                {
// build: symbol ?gnQuestSelectedSlot@* 0x007BF2B9
                    gnQuestSelectedSlot = pEntry->nCelId2;
                }
            }
        }
    }
}


extern "C" int gB27_007BF298; // 0x007BF298

// 0x004A3000
extern "C" void __cdecl QUESTLOG_ResetQuestButtonState()
{
    if (gB27_007BF298 == 1)
        gB27_007BF298 = 0;
}

// 0x004A3020
void __cdecl TEXT_ClearQuestFlags()
{
    for (int i = 0; i < 41; ++i)
    {
        gtQuestUiFlags_007BF2B3.abFlags[i] = 0;
        gtQuestUiFlags_007BF2B3.abFlagsB[i] = 0;
    }
}

// 0x004A3050
void __cdecl sub_004A3050()
{
    gaQuestPageDefault[0] = -1;
    gaQuestPageDefault[1] = -1;
    gaQuestPageDefault[2] = -1;
    gaQuestPageDefault[3] = -1;
    gaQuestPageDefault[4] = -1;
}



char gbGlobal_007C025D; // 0x007C025D


struct D2QuestLookupEntryStrc;

struct D2QuestPanelValuesStrc;


#pragma pack(push, 1)
struct D2QuestPanelValuesStrc
{
    char unk0x00[0x7];
    int nValues[0x96];
};
#pragma pack(pop)

extern D2QuestLookupEntryStrc gaQuestLookup_00723F38[0x29]; // 0x00723F38

// 0x004A3070
int __fastcall QUESTLOG_LookupQuestValue(int nUnused, int nKey)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        if (gaQuestLookup_00723F38[i].nKey == nKey)
        {
            return gaQuestLookup_00723F38[i].nValue;
        }
    }
    return 0x2A;
}

// 0x004A30A0
void __cdecl QUESTLOG_LoadDurielCofsOnce()
{
    if (!gbGlobal_007C025D)
    {
        gbGlobal_007C025D = 1;
// build: symbol ?GFX_LoadMonsterCofs@* 0x0046F870
        GFX_LoadMonsterCofs(0xD3, 1);
    }
}

char gbGlobal_007C025E; // 0x007C025E

// 0x004A30C0
void __cdecl QUESTLOG_LoadAncientsCofsOnce()
{
    if (!gbGlobal_007C025E)
    {
        gbGlobal_007C025E = 1;
        GFX_LoadMonsterCofs(0x219, 0);
        GFX_LoadMonsterCofs(0x21A, 0);
        GFX_LoadMonsterCofs(0x21B, 0);
    }
}

extern "C" unsigned char gB27_007C025F; // 0x007C025F

extern "C" unsigned int gB27_007C0265; // 0x007C0265

// 0x004A3100
extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value)
{
    gB27_007C025F = 1;
    gB27_007C0265 = value;
}

char gbGlobal_007C025F; // 0x007C025F

// 0x004A3110
char __cdecl QUESTLOG_HasQuestPacketValue()
{
    return gbGlobal_007C025F;
}

char gbGlobal_007C0260; // 0x007C0260

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

extern unsigned int gnQuestUnitId; // 0x007C0261

// 0x004A3120
char __cdecl QUESTLOG_IsQuestUnitPresent()
{
    if (gbGlobal_007C0260 && CUNIT_FindServerSideUnit(gnQuestUnitId, 1))
    {
        return 1;
    }
    return 0;
}

union D2SeedStrc;

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730

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
    if (gbGlobal_007C025F)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nCount = SEED_RollLimitedRandomNumber(&pPlayer->pSeed, 3) + 2;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pUnit = CUNIT_SpawnPresetUnit(0x95, nX + i % 2, nY + i % 2, 1, 1);
            gnQuestUnitId = UNITS_GetUnitId(pUnit);
            gbGlobal_007C0260 = 1;
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

    gnQuestSelectedSlot = -1;
    if ((!FOG_IsExpansion() || !GAME_IsExpansion()) && nPage == 4)
    {
        return;
    }

    for (int i = gaQuestPageRanges[nPage].nFirst; i <= gaQuestPageRanges[nPage].nLast; ++i)
    {
        if (!gapQuestIconCels[i])
        {
// build: symbol ?gaszQuestCelNames@* 0x006DA2C8
            sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal_006D4118, gaszQuestCelNames[i]);
            gapQuestIconCels[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }

    if (gaQuestPageDefault[nPage] != -1)
    {
        gnQuestSelectedSlot = gaQuestPageDefault[nPage];
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
        if (pQuest->nPage == nPage && pQuest->bEnabled && pQuest->nCelId < 0x1B && gapQuestIconCels[pQuest->nCelId])
        {
            D2QuestTextMsgStrc tMsg;
            tMsg.nQuestId = pQuest->nQuestId;
            TEXT_BuildQuestText(&tMsg);
            if (tMsg.bStepChanged || !tMsg.nState)
            {
                nCount = 41;
                gnQuestSelectedSlot = tMsg.nCelId;
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

    if (nFound && gnQuestSelectedSlot == -1)
    {
        int nSelection = gaQuestPageSelection[nPage];
        if (nSelection != -1 || (nSelection = nFirst) != -1)
        {
            gnQuestSelectedSlot = nSelection;
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
    gtQuestLog = 0;
// build: symbol ?gpQuestBackgroundCel@* 0x007BF2D5
    gpQuestBackgroundCel = 0;
// build: symbol ?gpQuestTabsCel@* 0x007BF2D9
    gpQuestTabsCel = 0;
// build: symbol ?gpQuestSocketsCel@* 0x007BF2D1
    gpQuestSocketsCel = 0;
// build: symbol ?gpQuestDoneCel@* 0x007BF2DD
    gpQuestDoneCel = 0;
// build: symbol ?gpInvPsCel@* 0x007BF351
    gpInvPsCel = 0;
// build: symbol ?gpQuestLastCel@* 0x007BF34D
    gpQuestLastCel = 0;
    memset(gapQuestIconCels, 0, sizeof(gapQuestIconCels));
    gnQuestAct = 0;
    gnQuestParam = 0;
// build: symbol ?gdwQuestLogToggleTick@* 0x007C0259
    gdwQuestLogToggleTick = 0;
    for (int i = 0; i < 41; ++i)
    {
        gtQuestUiFlags_007BF2B3.abFlags[i] = 0;
        gtQuestUiFlags_007BF2B3.abFlagsB[i] = 0;
    }
    gbQuestSlotDown = 0;
    gbGlobal_007BF2B2 = 0;
    gbGlobal_007BF2B0 = 0;
    gbGlobal_007BF2B4 = 0;
    gbGlobal_007C025D = 0;
    gbGlobal_007C025E = 0;
    gbGlobal_007C025F = 0;
    gbGlobal_007C0260 = 0;
    gbQuestDescriptionOpen = 0;
    gnQuestPressedSlot = -1;
    gnIndex_007BF2BD = -1;
    gnIndex_007BF2C1 = -1;
    gnIndex_007BF2C5 = -1;
    gnIndex_007BF2C9 = -1;
    gnIndex_007BF2CD = -1;
}



// 0x004A34F0
void __cdecl QUESTLOG_DrawQuestPage()
{
    int i = 0;
    D2CelContextStrc tDraw;
    memset(&tDraw, 0, sizeof(tDraw));
    tDraw.nDirection = 0;

    if (CUNIT_IsPlayerDeadOrMissing())
    {
        if (gtQuestLog_007BF298.nState == 2)
        {
            gtQuestLog_007BF298.nState = 0;
            gtQuestLog_007BF298.bB0 = 0;
            gtQuestLog_007BF298.bB3 = 0;
        }
        sub_004A2550();
        UI_SetUIVar(0xF, 1, 0);
        return;
    }

    if (GAME_GetUIVarState(0x12))
    {
        QUESTLOG_OpenQuestPanel(0);
        return;
    }

    if (sub_00483350())
    {
        QUESTLOG_OpenQuestPanel(0);
        return;
    }

    if (!gtQuestLog_007BF298.pCelD5)
    {
        QUESTLOG_LoadQuestPanelCels();
        TEXT_LoadQuestPage(0, 1);
    }

    if (gtQuestLog_007BF298.pCelD5)
    {
        tDraw.pCellFile = gtQuestLog_007BF298.pCelD5;
        tDraw.nFrame = 0;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 1;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 2;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
        tDraw.nFrame = 3;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    }

    if (gtQuestLog_007BF298.pCelD9)
    {
        tDraw.pCellFile = gtQuestLog_007BF298.pCelD9;
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

            if (i == gtQuestLog_007BF298.nPage)
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
        memset(gtQuestLog_007BF298.aMsgs, 0, sizeof(gtQuestLog_007BF298.aMsgs));

    unsigned char bSpecial = 0;
    if (gtQuestLog_007BF298.nPage < 5)
    {
        gtQuestLog_007BF298.f_8 = 0;
        int nRow = 0;
        unsigned char bDone = 0;
        D2QuestTableStrc* pEntry = gaQuestTable;
        do
        {
            int nSlot = -1;
            if (pEntry->nPage == gtQuestLog_007BF298.nPage && pEntry->bEnabled && pEntry->nCelId < 0x1B && gtQuestLog_007BF298.apCel[pEntry->nCelId] && gtQuestLog_007BF298.f_8 < 6)
            {
                gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].nQuestId = pEntry->nQuestId;
                TEXT_BuildQuestText(&gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8]);
                int nFrame;
                switch (gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].nState)
                {
                case 0:
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    nFrame = gtQuestLog_007BF298.anAnim[gtQuestLog_007BF298.f_8];
                    if (nFrame >= 0x19)
                    {
                        nFrame = 0x18;
                        D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
                        QUESTRECORD_SetQuestState(pQuestInfo, pEntry->nQuestId, 0xC);
                        MSG_SendWord(0x58, (unsigned short)pEntry->nQuestId);
                    }
                    tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                    tDraw.nFrame = nFrame;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    {
                        const unsigned int dwTick = GetTickCount();
                        if (!gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8])
                            gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8] = dwTick;
                        if (dwTick - gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8] > 100)
                        {
                            gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8] = dwTick;
                            gtQuestLog_007BF298.anAnim[gtQuestLog_007BF298.f_8] += 1;
                            if (gtQuestLog_007BF298.anAnim[gtQuestLog_007BF298.f_8] == 1 && FOG_IsExpansion())
                                sub_004B9A00(0xE, 0, 0, 0, 0);
                        }
                    }
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                case 1:
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    if (gtQuestLog_007BF298.nIndexB5 == pEntry->nCelId2)
                    {
                        tDraw.pCellFile = gtQuestLog_007BF298.pCelDD;
                        tDraw.nFrame = pEntry->nCelId;
// build: symbol ?gnQuestAnimOffsetY@* 0x00724220
                        sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gtQuestLog_007BF298.n270 + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gnQuestAnimOffsetY, -1, 5, 0);
                    }
                    else
                    {
                        tDraw.nFrame = 0x18;
                        tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                        sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    }
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                case 2:
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    tDraw.nFrame = 0x1A;
                    tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                case 3:
                    if (gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].wTitle == 0x3A0 && gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].nStep == 7)
                        bSpecial = 1;
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                    tDraw.nFrame = (gtQuestLog_007BF298.nIndexB5 == pEntry->nCelId2) ? 0x19 : 0;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                }

                tDraw.pCellFile = gtQuestLog_007BF298.pCelD1;
                if (nSlot == gtQuestLog_007BF298.nIndexB9)
                {
                    tDraw.nFrame = 1;
// build: symbol ?gnQuestIconOffsetY@* 0x0072421C
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX - 4, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gnQuestIconOffsetY + 5, -1, 5, 0);
                }
                else
                {
                    tDraw.nFrame = 0;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX - 4, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gtQuestLog_007BF298.n26C + 5, -1, 5, 0);
                }
            }

            ++nRow;
            if (nRow > 0x29 || gtQuestLog_007BF298.f_8 >= 6)
                bDone = 1;
            ++pEntry;
        }
        while (!bDone);

        if (bSpecial && gtQuestLog_007BF298.nIndexB9 == 5)
        {
            tDraw.pCellFile = gtQuestLog_007BF298.pCel351;
            tDraw.nFrame = gtQuestLog_007BF298.nA8;
            if (tDraw.nFrame < 0 || tDraw.nFrame > 6)
                tDraw.nFrame = 0;
            sub_004F6480(&tDraw, gnPanelOffsetX + 0x6E, gnScreenHeight + gnPanelOffsetY - 0x6E, -1, 3, 0);
        }
    }

    D2Win_10127_SetFont(8);
    const int nSelected = gtQuestLog_007BF298.nIndexB9;
    if (nSelected != -1 && nSelected < 6 && nSelected < gtQuestLog_007BF298.f_8)
    {
        int nFound = -1;
        for (int k = 0; k < gtQuestLog_007BF298.f_8; ++k)
        {
            if (gtQuestLog_007BF298.aMsgs[k].nCelId == nSelected)
            {
                nFound = k;
                break;
            }
        }

        if (nFound != -1 && gtQuestLog_007BF298.aMsgs[nFound].unk0x000[0])
        {
            if (gtQuestLog_007BF298.aMsgs[nFound].wTitle != 0xE8C)
            {
                const Unicode* pTitle = D2LANG_GetStringFromTblIndex(gtQuestLog_007BF298.aMsgs[nFound].wTitle);
// build: symbol ?gnQuestTitleY@* 0x00724218
                D2Win_10117_DrawText(pTitle, gnPanelOffsetX - D2Win_10121_GetTextWidth(pTitle) / 2 + 0xA0, gnQuestTitleY - gnPanelOffsetY, 0, 0);
            }

            if (!gtQuestLog_007BF298.bB3 && gtQuestLog_007BF298.aMsgs[nFound].wszText[0].wChar)
            {
                int nLines;
                D2SplittedTextStrc* pLine = D2WINFONT_SplitText(gtQuestLog_007BF298.aMsgs[nFound].wszText, &nLines, 0x10E);
                if (pLine)
                {
                    int nLine = 0;
                    do
                    {
// build: symbol ?gnQuestTextTop@* 0x00724210
// build: symbol ?gnQuestTextLeft@* 0x00724214
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

    tDraw.pCellFile = sub_00454600();
    tDraw.nFrame = (gtQuestLog_007BF298.bB2 != 0) + 0xA;
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

    tDraw.pCellFile = gtQuestLog_007BF298.pCel34D;
    tDraw.nFrame = gtQuestLog_007BF298.bB4 != 0;
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
// build: symbol ?gbQuestSlotDown@* 0x007BF2B1
    gbQuestSlotDown = 0;
    gbGlobal_007BF2B2 = 0;
    gbGlobal_007BF2B0 = 0;
    gnQuestPressedSlot = -1;
    gbGlobal_007BF2B4 = 0;
    gbGlobal_007C025D = 0;
    gbGlobal_007C025E = 0;
    gbGlobal_007C025F = 0;
    gbGlobal_007C0260 = 0;
}

static __forceinline void sub_004A3E40_ClickSlot_Inline(int nIndex)
{
    for (int i = 0; i < gnQuestCount; ++i)
    {
        if (nIndex == gaQuestEntries[i].nSlot && gaQuestEntries[i].bEnabled)
        {
            gbQuestSlotDown = 1;
            gnQuestPressedSlot = nIndex;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
    }
}

// 0x004A3E40
void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam);
    int nY = D2_HIWORD(pMsg->lParam);
    if (sub_00483350())
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
    if (!gbQuestDescriptionOpen)
    {
        nIndex = TEXT_GetQuestTabAtPoint(nY, nX);
        if (nIndex != -1)
        {
            if (nIndex < 5 && nIndex != gnPage && ((FOG_IsExpansion() && GAME_IsExpansion()) || nIndex != 4))
            {
                sub_004A2760(gnPage);
                TEXT_SetQuestPage(nIndex);
                TEXT_LoadQuestPage(gnPage, 1);
                sub_004A2390_ResetQuestSelection();
            }
        }
        else
        {
            nIndex = TEXT_GetQuestSlotAtPoint(nX, nY);
            if (nIndex != -1 && nIndex < gnQuestCount)
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
                    gbGlobal_007BF2B2 = 1;
                    sub_004B9A00(4, 0, 0, 0, 0);
                }
                else if (TEXT_HitTestButtonA(nX, nY))
                {
                    gbGlobal_007BF2B4 = 1;
                    sub_004B9A00(4, 0, 0, 0, 0);
                }
            }
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


unsigned char __cdecl INV_IsCinematicBusy(); // 0x00483350

int __cdecl TEXT_Forward(); // 0x004A1760

void __stdcall sub_004A3220(int nPage, int nArg);

void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A3FE0
void __fastcall QUESTLOG_ToggleQuestLog(int nMode)
{
    if (gtQuestLog == 0)
    {
// build: symbol ?gdwQuestLogToggleTick@* 0x007C0259
        if (GetTickCount() - gdwQuestLogToggleTick < 250)
            return;
        if (CUNIT_IsPlayerDeadOrMissing())
            return;
        if (INV_IsCinematicBusy())
            return;
        if (UI_SetUIVar(15, 0, nMode) != 1)
            return;
        QUESTLOG_LoadQuestPanelCels();
        gtQuestLog = 2;
        QUESTLOG_UpdateQuestPage();
// build: symbol ?gnPage@* 0x007C0255
        sub_004A3220(gnPage, 0);
        MSG_SendHeaderOnly(0x40);
        return;
    }

    if (gtQuestLog == 1)
    {
        gtQuestLog = 0;
        if (INV_IsCinematicBusy())
            return;
        if (UI_SetUIVar(15, 0, nMode) != 1)
            return;
        QUESTLOG_LoadQuestPanelCels();
        gtQuestLog = 2;
        QUESTLOG_UpdateQuestPage();
        sub_004A3220(gnPage, 0);
        MSG_SendHeaderOnly(0x40);
        return;
    }

    QUESTLOG_OpenQuestPanel(nMode);
    gdwQuestLogToggleTick = GetTickCount();
    TEXT_Forward();
}

struct D2Record42Strc;

#pragma pack(push, 2)
struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};
#pragma pack(pop)

extern unsigned char gbFlag_007BF2B0; // 0x007BF2B0

extern D2Record42Strc gtQuestRecord; // 0x007BF355

extern int gnPage_007C0255; // 0x007C0255

// 0x004A40D0
void __fastcall QUESTLOG_SetQuestRecord(const D2Record42Strc* pRecord)
{
    gtQuestRecord = *pRecord;
    gbFlag_007BF2B0 = 0;
    if (!sub_00483350())
    {
        if (gnState_007BF298 == 2)
        {
            QUESTLOG_LoadQuestPanelCels();
        }
        sub_004A3220(gnPage_007C0255, 1);
    }
}

// 0x004A4110
void __stdcall TEXT_QuestButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (sub_004A2970(nX, nY) && gbGlobal_007BF2B0)
    {
        UI_SetUIVar(17, 1, 0);
        QUESTLOG_ToggleQuestLog(0);
        gbGlobal_007BF2B0 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    gbGlobal_007BF2B0 = 0;
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
D2QuestTextBufferStrc::D2QuestTextBufferStrc()
{
}

// build: symbol ??__Edata_007BF298@@YAXXZ 0x006CACD0
D2QuestTextBufferStrc data_007BF298; // 0x007BF298

// 0x004A42A0
void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnPanelOffsetX;
    int nY = D2_HIWORD(pMsg->lParam) + gnPanelOffsetY;
    if (gbGlobal_007BF2B2)
    {
        if (TEXT_HitTestQuestCloseButton(nX, nY)) QUESTLOG_ToggleQuestLog(0);
    }
    else if (!gbQuestDescriptionOpen)
    {
// build: symbol ?gnQuestPressedSlot@* 0x007BF2B5
        if (gnQuestPressedSlot != -1)
        {
            int nSlot = TEXT_GetQuestSlotAtPoint(nX, nY);
            if (nSlot == gnQuestPressedSlot)
            {
// build: symbol ?gaQuestPageSelection@* 0x007BF2BD
                gaQuestPageSelection[gnPage] = nSlot;
// build: symbol ?gnQuestSelectedSlot@* 0x007BF2B9
                gnQuestSelectedSlot = nSlot;
            }
        }
        else if (gbGlobal_007BF2B4 == 1)
        {
            if (TEXT_HitTestButtonA(nX, nY) && gnQuestSelectedSlot != -1)
            {
                TEXT_OpenQuestDescription(gnQuestSelectedSlot);
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





#include "gen/data/Source/D2Client/UI/QuestLog.inc"
struct D2CelFileStrc;
