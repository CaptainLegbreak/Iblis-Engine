#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);

extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
// build: symbol _gszFormatD 0x006D57BC
extern "C" const char gszFormatD[];
// build: symbol ?gnScreenWidth@* 0x0071146C
extern int gnScreenWidth;
// build: symbol ?gnPanelOffsetX@* 0x007A2858
extern int gnPanelOffsetX;
// build: symbol ?gnPanelOffsetY@* 0x007A285C
extern int gnPanelOffsetY;
// build: symbol ?gnSkillPage@* 0x00724BEC
extern int gnSkillPage;
// build: symbol ?gnTabSelection@* 0x00724CE0
extern int gnTabSelection;
// build: symbol ?gbSkillTabPressed@* 0x007C0C38
extern int gbSkillTabPressed;
// build: symbol _gbSkillPointsHighlight 0x007C0C3C
extern "C" int gbSkillPointsHighlight;
// build: symbol ?gbInSkillPanelDraw@* 0x007C0C44
extern int gbInSkillPanelDraw;
// build: symbol ?gbSkillPanelDrawn@* 0x007C0C4C
extern int gbSkillPanelDrawn;
// build: symbol ?gaSkillButtonFrame@* 0x007C0838
extern int gaSkillButtonFrame[];
// build: symbol ?gaSkillButtonState@* 0x007C0A38
extern int gaSkillButtonState[];

int __cdecl sub_00468730();
int __cdecl sub_00468740();
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
void __fastcall UI_SetUIVar(int nUIVar, int nState, int nArg); // 0x00455F20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);
D2UnitStrc* __cdecl sub_00463DD0();
void __stdcall CURSOR_HandleButtonDown(SMSGHANDLER_PARAMS* pMsg); // 0x00467F20
void __stdcall CURSOR_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0
void __fastcall MSG_SendTwoDwords(char nHeader, int nArg1, int nArg2); // 0x004786A0
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg);
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);
void* __fastcall SPELLSEL_GetSkillIconCel(D2SkillsTxt* pSkillsTxt); // 0x004A8C80
int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __cdecl sub_004AA900_IsStateOrValue();
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
void __fastcall SKILLDESC_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY);
void __fastcall SKILLDESC_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY);
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift);
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId);
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel);

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

static inline D2SkillsTxt* SKILLTREE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2SkillDescTxt* SKILLTREE_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }
    return 0;
}

static inline D2SkillDescTxt* SKILLTREE_GetSkillDescRec(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = SKILLTREE_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        return SKILLTREE_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    }
    return 0;
}

static int sub_004AA9C0_GetSkillRowY(unsigned char nRow)
{
    if (nRow == 1)
        return gnScreenHeight + gnPanelOffsetY - 0x1A2;
    if (nRow == 2)
        return gnScreenHeight + gnPanelOffsetY - 0x15E;
    if (nRow == 3)
        return gnScreenHeight + gnPanelOffsetY - 0x11A;
    if (nRow == 4)
        return gnScreenHeight + gnPanelOffsetY - 0xD6;
    if (nRow == 5)
        return gnScreenHeight + gnPanelOffsetY - 0x91;
    if (nRow == 6)
        return gnScreenHeight + gnPanelOffsetY - 0x4D;
    return 0;
}

int sub_004AAA50_GetSkillColumnX(unsigned char nColumn); // 0x004AAA50

// 0x0045FB80
static int __stdcall sub_004AB5F0_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

void __cdecl sub_004AB630_DrawTabHint()
{
    if (gnTabSelection == 1)
    {
        if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0x95, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
            sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnScreenWidth - gnPanelOffsetX - 0x86, gnScreenHeight + gnPanelOffsetY - 0x62, 0, 1);
    }
    else if (gnTabSelection == 2)
    {
        if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0xDC, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
            sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnScreenWidth - gnPanelOffsetX - 0xCD, gnScreenHeight + gnPanelOffsetY - 0x62, 0, 1);
    }
    else if (gnTabSelection == 3)
    {
        if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0x131, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
            sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnScreenWidth - gnPanelOffsetX - 0x122, gnScreenHeight + gnPanelOffsetY - 0x62, 0, 1);
    }
}

void __stdcall sub_004AB7E0_SkillTreeLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    int nMouseY = pMsg->nYpos;
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        return;

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;

    const int nClassId = pPlayer->dwClassId;
    if (nMouseY > gnScreenHeight - 0x30)
        return;

    if (!gbSkillPanelDrawn)
    {
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    if (nMouseX > gnScreenWidth - gnPanelOffsetX - 0x140 && nMouseX < gnScreenWidth - gnPanelOffsetX - 0x58)
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0) <= 0)
        {
            for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
            {
                const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
                D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (!pSkillsTxt)
                    continue;

                D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
                if (!pDesc)
                    continue;

                if (gnSkillPage == pDesc->nSkillPage)
                {
                    const int nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
                    if (nMouseY > nY - 0x30 && nMouseY < nY)
                    {
                        const int nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
                        if (nMouseX > nX && nMouseX < nX + 0x30 && !gaSkillButtonState[i] && !BITARRAY_CHECK(pSkillsTxt->nFlags, 4))
                        {
                            MSG_SendTwoDwords(0x3C, pSkillsTxt->nSkillId, -1);
                            UI_SetUIVar(4, 1, 0);
                            continue;
                        }
                    }
                }

                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
            }

            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
        }
    }

    if (nMouseX >= gnScreenWidth - gnPanelOffsetX - 0x58)
    {
        if (nMouseX <= gnScreenWidth - gnPanelOffsetX)
        {
            const int nOldPage = gnSkillPage;
            if (nMouseY > gnScreenHeight + gnPanelOffsetY - 0x174 && nMouseY < gnScreenHeight + gnPanelOffsetY - 0x109)
                gnSkillPage = 3;
            if (nMouseY > gnScreenHeight + gnPanelOffsetY - 0x108 && nMouseY < gnScreenHeight + gnPanelOffsetY - 0x9D)
                gnSkillPage = 2;
            if (nMouseY > gnScreenHeight + gnPanelOffsetY - 0x9C && nMouseY < gnScreenHeight - 0x31)
                gnSkillPage = 1;
            if (gnSkillPage != nOldPage)
                sub_004B9A00(6, 0, 0, 0, 0);
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }

    if (gnTabSelection == 1)
    {
        if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0x95, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
        {
            sub_004B9A00(4, 0, 0, 0, 0);
            gbSkillTabPressed = 1;
        }
    }
    else if (gnTabSelection == 2)
    {
        if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0xDC, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
        {
            sub_004B9A00(4, 0, 0, 0, 0);
            gbSkillTabPressed = 1;
        }
    }
    else if (gnTabSelection == 3)
    {
        if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0x131, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
        {
            sub_004B9A00(4, 0, 0, 0, 0);
            gbSkillTabPressed = 1;
        }
    }

    if (nMouseX > gnScreenWidth - gnPanelOffsetX - 0x140 && nMouseX < gnScreenWidth - gnPanelOffsetX - 0x58)
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0) > 0)
        {
            for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
            {
                const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
                if (!sub_0045C4B0_GetSkillsTxtRecord(nSkillId))
                    continue;

                D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
                if (!pDesc)
                    continue;

                if (gnSkillPage != pDesc->nSkillPage)
                    continue;

                const int nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
                if (nMouseY <= nY - 0x30 || nMouseY >= nY)
                    continue;

                const int nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
                if (nMouseX <= nX || nMouseX >= nX + 0x30 || gaSkillButtonState[i])
                    continue;

                gaSkillButtonState[i] = 1;
                gaSkillButtonFrame[i] = 3;
                CURSOR_HandleButtonDown(pMsg);
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_004B9A00(5, 0, 0, 0, 0);
                sub_00420290_HandleMsg(pMsg);
                return;
            }

            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    pMsg->bReturn = 0;
}

void __stdcall sub_004ABC30_SkillTreeLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;

    const int nClassId = pPlayer->dwClassId;
    CURSOR_HandleButtonUp(pMsg);
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        return;

    if (!gbSkillPanelDrawn)
    {
LNotHandled:
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    if (gbSkillTabPressed)
    {
        gbSkillTabPressed = 0;
        if (gnTabSelection == 1)
        {
            if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0x95, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
                UI_SetUIVar(4, 2, 0);
        }
        else if (gnTabSelection == 2)
        {
            if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0xDC, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
                UI_SetUIVar(4, 2, 0);
        }
        else if (gnTabSelection == 3)
        {
            if (sub_004AB5F0_IsMouseInRect(gnScreenWidth - gnPanelOffsetX - 0x131, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x22, 0x22))
                UI_SetUIVar(4, 2, 0);
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    if (nMouseX > gnScreenWidth / 2)
    {
        const int nNewSkills = STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0);
        if (nNewSkills > 0)
        {
            for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
            {
                const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
                D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (!pSkillsTxt)
                    continue;

                D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
                if (!pDesc)
                    continue;

                if (gnSkillPage == pDesc->nSkillPage)
                {
                    const int nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
                    if (nMouseY > nY - 0x30 && nMouseY < nY)
                    {
                        const int nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
                        if (nMouseX > nX && nMouseX < nX + 0x30 && gaSkillButtonState[i] == 1)
                        {
                            if (pSkillsTxt->dwSkPoints != -1)
                            {
                                int nLevel = 0;
                                D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
                                if (pSkill)
                                    nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);

                                if (SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxt->dwSkPoints, nSkillId, nLevel) > nNewSkills)
                                    goto LDone;
                            }

                            {
                                int nLevel = 0;
                                D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
                                if (pSkill)
                                    nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);

                                if (nLevel <= SPELLSEL_GetSkillMaxLevel(pSkillsTxt->nSkillId) && !sub_004AA900_IsStateOrValue())
                                {
                                    MSG_SendWord(0x3B, nSkillId);
                                    gbSkillPointsHighlight = 0;
                                }
                            }

LDone:
                            gaSkillButtonState[i] = 0;
                            gaSkillButtonFrame[i] = 0;
                            pMsg->bReturn = 1;
                            pMsg->lResult = 0;
                            sub_00420290_HandleMsg(pMsg);
                            return;
                        }
                    }
                }

                if (gaSkillButtonState[i] != -1)
                {
                    gaSkillButtonState[i] = 0;
                    gaSkillButtonFrame[i] = 0;
                }
            }
        }

        goto LNotHandled;
    }

    pMsg->bReturn = 0;
}

void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode)
{
    D2SkillDescTxt* pDesc;
    int nFrame;
    int nY;
    int nX;
    int nMouseX;
    int nMouseY;
    void* pCellFile;

    pDesc = SKILLTREE_GetSkillDescRec(nSkillId);
    if (!pDesc)
        return;

    nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
    nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
    nMouseX = sub_00468730();
    nMouseY = sub_00468740();
    pCellFile = SPELLSEL_GetSkillIconCel(0);
    nFrame = pDesc->nIconCel;
    if (nState == 1)
        ++nFrame;

    if (nMouseX > nX && nMouseX < nX + 0x30 && nMouseY > nY - 0x30 && nMouseY < nY)
        nMode = 3;

    if (!BITARRAY_CHECK(pSkillsTxt->nFlags, 10))
        nMode = 1;

    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nBaseLevel = SKILLS_GetSkillLevel(pPlayer, SKILLS_GetSkillById(pPlayer, nSkillId, -1), 0);
    if (!nBaseLevel && SKILLS_GetBonusSkillLevelFromSkillId(pPlayer, nSkillId) && nState != -1)
        nMode = 3;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = pCellFile;
    tCel.nDirection = 0;
    tCel.nFrame = nFrame;
    TEXTURE_CelDrawColor(&tCel, nX, nY, -1, 5, nMode);

    if (nMouseX > nX && nMouseX < nX + 0x30 && nMouseY > nY - 0x30 && nMouseY < nY)
    {
        if (nState != -1)
            SKILLDESC_ShowSkillPopup(sub_00463DD0(), nSkillId, nSkillLevel, 0, nX, nY);
        else
            SKILLDESC_ShowSkillPopupB(sub_00463DD0(), nSkillId, nSkillLevel, 0, nX, nY);
    }

    if (nBaseLevel || nSkillLevel)
    {
        Unicode wszLevel[10];
        char szLevel[12];
        wsprintfA(szLevel, gszFormatD, nSkillLevel);
        sub_00526320_ToUnicode(wszLevel, szLevel, 9);
        if (nSkillLevel > 9)
        {
            D2Win_10127_SetFont(4);
            nX -= 4;
        }
        else
        {
            D2Win_10127_SetFont(1);
        }

        const int nBonusLevel = SKILLS_GetBonusSkillLevelFromSkillId(sub_00463DD0(), nSkillId);
        int nColor = 0;
        if (nBonusLevel > 0)
            nColor = 3;
        else if (nBonusLevel < 0)
            nColor = 1;

        D2Win_10117_DrawText(wszLevel, nX + 0x30, nY + 0xC, nColor, 0);
    }
}
