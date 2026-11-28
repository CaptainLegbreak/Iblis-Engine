// A piece of text.cpp, kept as its own file because its declarations disagree with text.cpp's: SOUNDINST_ArmHint
// and sub_004B9A00 take an int here where text.cpp's prototypes take D2SoundStrc* and D2UnitStrc*, and it reads a
// D2TextBoxStrc field (unknown16) the shared struct doesn't have. It joins once those agree.
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2ClientTextState.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "FogApi.h"
#include "D2LangApi.h"

struct D2TextRowStrc { void* pText; D2TextRowStrc* pNext; };
#pragma pack(push, 2)
struct D2TextBlockStrc { D2TextRowStrc* pLines; unsigned char unknown04[0x12]; int unknown16; };
#pragma pack(pop)

void __fastcall GAME_ResetMouseState(); // 0x0044DA40
D2SoundStrc* __fastcall sub_004B9610_GetSoundHandle(int nSound); // 0x004B9610
void __fastcall SOUNDINST_ArmHint(D2SoundStrc* pSound, int nZero, int nZero2, int nMode); // 0x004B9EF0
extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830
void __fastcall SELECT_SetSelectionRect(D2RectStrc* pRect); // 0x00467430
D2TextBlockStrc* __fastcall TEXT_CreateTextBox(const Unicode* pText, int nMode); // 0x004A05E0
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_004B9A00(int nSound, D2UnitStrc* pUnit, int nMode, int nZero, int nZero2); // 0x004B9A00
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void* __cdecl WINDOW_GetWindow(); // 0x004F59A0
void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, void* pHandlers, int nCount); // 0x00451DB0

extern const char gszTextSourceFile[]; // 0x006DA13C
extern unsigned char gaHandlers_00722600[]; // 0x00722600
extern D2TextBlockStrc* gpTextBox; // 0x007BF0A4
extern D2TextBlockStrc* gpMainTextBox; // 0x007BF1A8
extern int gbTextBoxDone; // 0x007BF1BC
extern int gnPreviousTextActive_007BF1C4; // 0x007BF1C4
static int gnHandlersSet_007BF27C; // 0x007BF27C

// 0x0049D370
static void TEXT_FreeTextLines(D2TextRowStrc* pLine)
{
    while (pLine)
    {
        D2TextRowStrc* pNext = pLine->pNext;
        FOG_Free(pLine->pText, gszTextSourceFile, 0x60F, 0);
        FOG_Free(pLine, gszTextSourceFile, 0x610, 0);
        pLine = pNext;
    }
}

// 0x0049D410
__forceinline void __stdcall TEXT_FreeTextBox(D2TextBlockStrc* pBox)
{
    if (pBox)
    {
        TEXT_FreeTextLines(pBox->pLines);
        FOG_Free(pBox, gszTextSourceFile, 0x68E, 0);
    }
}

// 0x004A10E0
void __fastcall TEXT_ShowNpcMessage(D2UnitStrc* pUnit, unsigned short nMessage, int nUnused)
{
    gtTextState.bTextSide = 0;
    gnTextTop = 12;
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
    gtTextState.bTextSound = 0;
    GAME_ResetMouseState();
    if (gnHintId)
    {
        D2SoundStrc* pSound = sub_004B9610_GetSoundHandle(gnHintId);
        if (pSound)
            SOUNDINST_ArmHint(pSound, 0, 0, 4);
        gnHintId = 0;
    }
    gtTextState.hHintSound = 0;
    if (!pUnit)
    {
        if (gnPreviousTextActive_007BF1C4)
        {
            if (gpMainTextBox)
            {
                TEXT_FreeTextBox(gpMainTextBox);
                gpMainTextBox = 0;
            }
            gnPreviousTextActive_007BF1C4 = 0;
        }
        gtTextState.bTextFromObject = 0;
        gtTextState.nTextNpcId = 0;
    }
    else
    {
        if (gtTextState.bTextFromObject)
        {
            D2UnitStrc* pPreviousNpc = CUNIT_FindClientUnit(gtTextState.nTextNpcId, 1);
            if (pPreviousNpc && pPreviousNpc != pUnit)
            {
                MSG_SendTwoDwords(0x30, 1, gtTextState.nTextNpcId);
                NPCMENU_ClearNpcInventoryAndSound(gtTextState.nTextNpcId);
            }
        }
        gtTextState.bTextFromObject = 1;
        gtTextState.nTextNpcId = pUnit->dwUnitId;
    }
    D2RectStrc tRect;
    tRect.nTop = gnTextTop;
    tRect.nBottom = (gnTextTop + 182 < gnScreenHeight - 53)
        ? gnTextTop + 182 : gnScreenHeight - 53;
    tRect.nLeft = gnTextLeft - 10;
    tRect.nRight = gnTextLeft + 335;
    SELECT_SetSelectionRect(&tRect);
    SELECT_ClearSelection();
    gtTextState.wTextStringId = nMessage;
    if (!gpTextBox)
    {
        gbTextBoxDone = 0;
        int nPreviousFont = D2Win_10127_SetFont(8);
        gpTextBox = TEXT_CreateTextBox(D2LANG_GetStringFromTblIndex(nMessage), 2);
        if (!gpTextBox)
        {
            FOG_DisplayHalt(gszEmptyString, sub_00408090(), 0x1024);
            exit(-1);
        }
        D2Win_10127_SetFont(nPreviousFont);
        SOUNDINST_LockSpeechSounds();
        gtTextState.hHintSound = 0;
        int nSound = sub_004E0650_GetStringSound(nMessage);
        if (nSound)
        {
            UNITSND_ReleaseSkillSfx(pUnit);
            gtTextState.hHintSound = sub_004B9A00(nSound, CUNIT_GetPlayerUnit(), 5, 0, 0);
            gnHintId = nSound;
        }
        gpTextBox->unknown16 = 0;
        gnTextActive = 1;
        if (!gnHandlersSet_007BF27C)
        {
            gnHandlersSet_007BF27C = 1;
            gtTextState.nStartTick = GetTickCount();
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHandlers_00722600, 7);
        }
    }
}
