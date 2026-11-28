#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ClientParty.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
struct D2StoredUnitRecordStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2RosterButtonStrc;
struct D2PartyRowStrc;
struct D2HintString2AndUnusedStrc;
struct D2ClientNotifyStrc;



Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
int __fastcall ROSTER_IsMaleClass(D2StoredUnitRecordStrc* pEntry); // 0x0047A670
int __cdecl WINMAIN_IsHardcore(); // 0x0044B850
extern unsigned char gnBoxColor; // 0x007BF034
extern D2PartyRowStrc* gpRosterUnits; // 0x007BF014
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

struct D2HintString2AndUnusedStrc
{
    int nString2;
    int nUnused;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

int __fastcall ROSTER_GetPartyFlags(D2StoredUnitRecordStrc* pEntry); // 0x00479D20
extern int gbRosterMode; // 0x007BF038

static inline int GetCenteredStringXInline(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - D2Win_10121_GetTextWidth(wszText) / 2;
}

// 0x0049AAF0
static void __stdcall PARTY_DrawTextFrame(unsigned short nAltString, unsigned short nString, int nX, int bLarge)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    int nAltWidth = 0;
    if (nAltString)
    {
        Unicode wszAlt[100];
        sub_005267E0(wszAlt, D2LANG_GetStringFromTblIndex(nAltString));
        nAltWidth = D2Win_10121_GetTextWidth(wszAlt);
    }
    int nY = 0x23;
    int nHeight = 0x1E;
    if (!bLarge)
    {
        nY = 0x2A;
        nHeight = 0xF;
    }
    if (nWidth > nAltWidth)
        AUTOMAP_DrawFramedBox(gnPanelOffsetX - nWidth / 2 + nX - 5, nY - gnPanelOffsetY, nWidth + 0xA, nHeight, gnBoxColor, 2);
    else
        AUTOMAP_DrawFramedBox(gnPanelOffsetX - nAltWidth / 2 + nX - 5, nY - gnPanelOffsetY, nAltWidth + 0xA, nHeight, gnBoxColor, 2);
}

// build: symbol ?PARTY_DrawRosterHoverHints@* 0x0049ABD0
void __cdecl PARTY_DrawRosterHoverHints()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2StoredUnitRecordStrc* pFirst = ROSTER_GetNextStoredUnit(0);
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
    if (ROSTER_GetEntryIndex(pFirst) != 0xFFFF)
    {
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + 0xE3 && nMouseX <= gnPanelOffsetX + 0x118 && nMouseY >= 0x18 - gnPanelOffsetY && nMouseY <= 0x23 - gnPanelOffsetY)
        {
            PARTY_DrawTextFrame(0, 0x1018, 0xD5, 0);
            {
                const int nTextX = TEXT_GetCenteredStringX(0x1018, 0xD5);
                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1018), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 0, 0);
            }
        }
    }
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(pFirst);
    while (pRow)
    {
        const int nY = pRow->aSlots[0].nY;
        const int nX = pRow->aSlots[0].nX;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + nX && nMouseX <= gnPanelOffsetX + nX + 0x35 && nMouseY >= nY - gnPanelOffsetY - 0x14 && nMouseY <= nY - gnPanelOffsetY)
        {
            if (!pRow->aSlots[0].nType)
            {
                const int nState = pRow->aSlots[0].nState;
                if (nState == 0)
                {
                    PARTY_DrawTextFrame(0x1005, 0x1004, 0xDA, 1);
                    {
                        const int nTextX = GetCenteredStringXInline(0x1004, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1004), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = GetCenteredStringXInline(0x1005, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1005), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
                else if (nState == 2)
                {
                    PARTY_DrawTextFrame(0x1007, 0x1006, 0xDA, 1);
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1006, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1006), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1007, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1007), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
                else if (nState == 4)
                {
                    PARTY_DrawTextFrame(0x1009, 0x1008, 0xDA, 1);
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1008, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1008), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1009, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1009), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

// 0x0049AF60
static void __stdcall sub_0049AF60_DrawButtonHint(unsigned short nString1, D2HintString2AndUnusedStrc tString2, int nCenterX, int nY1, int nY2, int nColor)
{
    const unsigned short nString2 = (unsigned short)tString2.nString2;
    if (!nString2)
    {
        PARTY_DrawTextFrame(0, nString1, nCenterX, 0);
        {
            const int nTextX = TEXT_GetCenteredStringX(nString1, nCenterX);
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnPanelOffsetX, nY1 - gnPanelOffsetY, nColor, 0);
        }
        return;
    }
    PARTY_DrawTextFrame(nString2, nString1, nCenterX, 1);
    {
        const int nTextX = TEXT_GetCenteredStringX(nString1, nCenterX);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnPanelOffsetX, nY1 - gnPanelOffsetY, nColor, 0);
    }
    {
        const int nTextX = TEXT_GetCenteredStringX(nString2, nCenterX);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString2), nTextX + gnPanelOffsetX, nY2 - gnPanelOffsetY, nColor, 0);
    }
}

// build: symbol ?PARTY_DrawRosterTooltip@* 0x0049B030
static void PARTY_DrawRosterTooltip(D2StoredUnitRecordStrc* pEntry)
{
    Unicode wszLine1[0x80];
    Unicode wszLine2[0x80];
    Unicode wszName[0x80];
    int nColor1 = 0;
    int nColor2 = 0;
    int nHeight = 0x10;
    char szDefault[0x80];
    const char* szName = ROSTER_GetEntryName(pEntry);
    if (!szName)
    {
        strcpy(szDefault, "ERROR PLAYER NAME");
        szName = szDefault;
    }
    sub_00526320_ToUnicode(wszName, szName, 0x80);
    const int nA = ROSTER_IsPlayerHostile(pEntry);
    const int nB = ROSTER_PlayerAllowsLoot(pEntry);
    const int nC = ROSTER_IsHostileToPlayer(pEntry);
    const int nD = ROSTER_AllowsPlayerLoot(pEntry);
    const int bE = ROSTER_IsMaleClass(pEntry);
    if (nA == nC)
    {
        if (bE)
// build: symbol ?gawRosterHostileMale@* 0x00722450
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileMale[nA][nC]));
        else
// build: symbol ?gawRosterHostileFemale@* 0x00722458
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileFemale[nA][nC]));
    }
    else
    {
        const unsigned short nFormat = bE ? gawRosterHostileMale[nA][nC] : gawRosterHostileFemale[nA][nC];
        sub_005269D0_FormatText(0x80, wszLine1, D2LANG_GetStringFromTblIndex(nFormat), wszName);
    }
    if (WINMAIN_IsHardcore())
    {
        nHeight = 0x1E;
        if (nB == nD)
        {
            if (ROSTER_IsMaleClass(pEntry))
// build: symbol ?gawRosterLootMale@* 0x00722460
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootMale[nB][nD]));
            else
// build: symbol ?gawRosterLootFemale@* 0x00722468
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootFemale[nB][nD]));
        }
        else
        {
            if (ROSTER_IsMaleClass(pEntry))
                sub_005269D0_FormatText(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootMale[nB][nD]), wszName);
            else
                sub_005269D0_FormatText(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootFemale[nB][nD]), wszName);
        }
    }
    if (nA)
        nColor1 = 8;
    if (nC)
        nColor1 = 1;
    if (nB)
        nColor2 = 9;
    if (nD)
        nColor2 = 4;
    const int nWidth1 = D2Win_10121_GetTextWidth(wszLine1) + 0xA;
    const int nWidth2 = D2Win_10121_GetTextWidth(wszLine2) + 0xA;
    AUTOMAP_DrawFramedBox(gnPanelOffsetX + 0x24, 0x23 - gnPanelOffsetY, nWidth1 > nWidth2 ? nWidth1 : nWidth2, nHeight, gnBoxColor, 2);
    D2Win_10117_DrawText(wszLine1, gnPanelOffsetX + 0x29, 0x32 - gnPanelOffsetY, nColor1, 0);
    D2Win_10117_DrawText(wszLine2, gnPanelOffsetX + 0x29, 0x41 - gnPanelOffsetY, nColor2, 0);
}

// build: symbol ?PARTY_DrawRosterButtonHints@* 0x0049B330
void __cdecl PARTY_DrawRosterButtonHints()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2StoredUnitRecordStrc* pFirst = ROSTER_GetNextStoredUnit(0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
    int bInTown = 0;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(pFirst);
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        bInTown = 1;
    while (pRow)
    {
        const int nRowY = pRow->nY;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + 0x24 && nMouseX <= gnPanelOffsetX + 0x8C && nMouseY >= nRowY - gnPanelOffsetY - 0x1A && nMouseY <= nRowY - gnPanelOffsetY)
            PARTY_DrawRosterTooltip(pEntry);
        else
        {
            for (int k = 1; k < 5; ++k)
            {
                const int nY = pRow->aSlots[k].nY;
                const int nX = pRow->aSlots[k].nX;
                const int nBX = sub_00468730();
                const int nBY = sub_00468740();
                if (nBX >= gnPanelOffsetX + nX && nBX <= gnPanelOffsetX + nX + 0x14 && nBY >= nY - gnPanelOffsetY - 0x14 && nBY <= nY - gnPanelOffsetY)
                {
                    if (pRow->aSlots[k].nType == 1)
                    {
                        if (ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) >= 9)
                        {
                            if (pRow->nLevel >= 9)
                            {
                                if (!bInTown)
                                {
                                    PARTY_DrawTextFrame(0, 0x1019, 0x6E, 0);
                                    {
                                        const int nTextX = TEXT_GetCenteredStringX(0x1019, 0x6E);
                                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1019), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 1, 0);
                                    }
                                    return;
                                }
                                if (ROSTER_TestHostileFlag(pEntry))
                                    { D2HintString2AndUnusedStrc tArg; tArg.nString2 = 0x100D; tArg.nUnused = 0; sub_0049AF60_DrawButtonHint(0x100C, tArg, 0x6E, 0x32, 0x41, 0); }
                                else
                                    { D2HintString2AndUnusedStrc tArg; tArg.nString2 = 0x100B; tArg.nUnused = 0; sub_0049AF60_DrawButtonHint(0x100A, tArg, 0x6E, 0x32, 0x41, 0); }
                                return;
                            }
                            PARTY_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x101A, 0xA0);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x101B, 0xA0);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        PARTY_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                        {
                            const int nTextX = GetCenteredStringXInline(0x101A, 0xA0);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                        }
                        {
                            const int nTextX = GetCenteredStringXInline(0x101B, 0xA0);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aSlots[k].nType == 2)
                    {
                        if (WINMAIN_IsHardcore())
                        {
                            if (ROSTER_TestLootFlag(pEntry))
                            {
                                PARTY_DrawTextFrame(0x1011, 0x1010, 0xFF, 1);
                                {
                                    const int nTextX = TEXT_GetCenteredStringX(0x1010, 0xFF);
                                    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1010), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                                }
                                {
                                    const int nTextX = TEXT_GetCenteredStringX(0x1011, 0xFF);
                                    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1011), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                                }
                                return;
                            }
                            PARTY_DrawTextFrame(0x100F, 0x100E, 0xFF, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x100E, 0xFF);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x100E), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x100F, 0xFF);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x100F), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                    }
                    else if (pRow->aSlots[k].nType == 3)
                    {
                        if (ROSTER_TestMuteFlag(pEntry))
                        {
                            PARTY_DrawTextFrame(0x1013, 0x1012, 0x114, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1012, 0x114);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1012), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1013, 0x114);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1013), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        PARTY_DrawTextFrame(0x1015, 0x1014, 0x114, 1);
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1014, 0x114);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1014), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                        }
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1015, 0x114);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1015), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aSlots[k].nType == 4)
                    {
                        if (ROSTER_TestSquelchFlag(pEntry))
                        {
                            PARTY_DrawTextFrame(0, 0x1017, 0x128, 0);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1017, 0x128);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1017), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        PARTY_DrawTextFrame(0, 0x1016, 0x128, 0);
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1016, 0x128);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1016), gnPanelOffsetX + nTextX, 0x37 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

// 0x0049B990
static int PARTY_DoRosterButtonAction(D2StoredUnitRecordStrc* pEntry, int nType)
{
    int nResult = 0;
    switch (nType)
    {
    case 1:
// build: symbol ?ROSTER_ToggleHostile@* 0x00479FE0
        ROSTER_ToggleHostile(pEntry);
        nResult = ROSTER_TestHostileFlag(pEntry);
        break;
    case 2:
        if (!WINMAIN_IsHardcore())
            break;
// build: symbol ?ROSTER_ToggleLoot@* 0x00479DA0
        ROSTER_ToggleLoot(pEntry);
        nResult = ROSTER_TestLootFlag(pEntry);
        break;
    case 3:
// build: symbol ?ROSTER_ToggleMute@* 0x00479DE0
        ROSTER_ToggleMute(pEntry);
        nResult = ROSTER_TestMuteFlag(pEntry);
        break;
    case 4:
    {
// build: symbol ?ROSTER_ToggleSquelch@* 0x00479E20
        ROSTER_ToggleSquelch(pEntry);
        nResult = ROSTER_TestSquelchFlag(pEntry);
        D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
        if (pNotify)
        {
            char szText[0x200];
            if (nResult)
                strcpy(szText, "/squelch ");
            else
                strcpy(szText, "/unsquelch ");
            strcat(szText, ROSTER_GetEntryName(pEntry));
            pNotify->pfnResign(szText);
        }
        break;
    }
    }
    return nResult;
}

// 0x0049BAD0
static void PARTY_SetRosterButtonState(D2PartyRowStrc* pRow, int nSlot, D2StoredUnitRecordStrc* pEntry)
{
    if (pRow->aSlots[nSlot].nState == 1)
        return;

    const int nId = pRow->nId;
    ROSTER_HandlePartyButton(pEntry);
    const int nState = ROSTER_GetPartyFlags(pEntry);
    D2PartyRowStrc* pFound = gpRosterUnits;
    while (pFound && pFound->nId != nId)
        pFound = pFound->pNext;
    D2_ASSERT(pFound, 0x4E3);
    pFound->aSlots[nSlot].nState = nState;
}

// 0x0049BDD0
void __stdcall sub_0049BDD0_OnRosterClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = sub_00468730();
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2PartyRowStrc* pRow = gpRosterUnits;
    gbRosterButtonDown = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nX < gnScreenWidth / 2)
    {
        nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= gnPanelOffsetX + 0x116 && nX <= gnPanelOffsetX + 0x136 && nY >= 0x185 - gnPanelOffsetY && nY <= 0x1A5 - gnPanelOffsetY)
        {
            UI_SetUIVar(0x16, 1, 0);
            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if (TEXT_IsMouseInRect(0xE3, 0x23, 0x35, 0xB) && ROSTER_GetEntryIndex(pEntry) != 0xFFFF)
        {
            ROSTER_SendLeaveParty();
        }
        else if (gbRosterMode)
        {
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
            if (pEntry)
            {
            do
            {
                if (!pRow)
                    break;
                for (int i = 0; i < 5; i++)
                {
                    D2RosterSlotStrc* pSlot = &pRow->aSlots[i];
                    if (!pSlot->bFlag)
                    {
                        const int nSlotX = pSlot->nX;
                        const int nSlotY = pSlot->nY;
                        nX = sub_00468730();
                        nY = sub_00468740();
                        if (nX >= gnPanelOffsetX + nSlotX && nX <= gnPanelOffsetX + nSlotX + 0x14 && nY >= nSlotY - gnPanelOffsetY - 0x14 && nY <= nSlotY - gnPanelOffsetY)
                        {
                            if (pSlot->nType == 1 && ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) < 9)
                            {
                                pMsg->bReturn = 1;
                                goto result;
                            }
                            if (pSlot->nType == 1)
                            {
                                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
                                if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
                                    continue;
                            }
                            const int bDone = PARTY_DoRosterButtonAction(pEntry, pSlot->nType);
                            int nCount = pSlot->nFrame;
                            if (bDone)
                            {
                                nCount += 2;
                                pSlot->nFrame = nCount;
                            }
                            else
                            {
                                pSlot->nFrame = nCount;
                            }
                        }
                    }
                    else
                    {
                        const int nSlotX = pSlot->nX;
                        const int nSlotY = pSlot->nY;
                        nX = sub_00468730();
                        nY = sub_00468740();
                        if (nX >= gnPanelOffsetX + nSlotX && nX <= gnPanelOffsetX + nSlotX + 0x35 && nY >= nSlotY - gnPanelOffsetY - 0x14 && nY <= nSlotY - gnPanelOffsetY)
                        {
                            PARTY_SetRosterButtonState(pRow, i, pEntry);
                            goto done;
                        }
                    }
                }
                pRow = pRow->pNext;
                pEntry = ROSTER_GetNextStoredUnit(pEntry);
            } while (pEntry);
            }
            gbRosterMode = 0;
        }
        else
        {
            for (; pRow; pRow = pRow->pNext)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (pRow->aSlots[i].bActive)
                    {
                        pRow->aSlots[i].nFrame--;
                        pRow->aSlots[i].bActive = 0;
                    }
                }
            }
        }
done:
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
result:
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 0;
}
