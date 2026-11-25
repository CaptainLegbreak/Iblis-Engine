#include "D2Client.h"
#include "D2Unicode.h"
#include "D2Structs.h"

struct D2TextRowStrc { void* pText; D2TextRowStrc* pNext; };
#pragma pack(push, 2)
struct D2TextBlockStrc { D2TextRowStrc* pLines; unsigned char unknown04[0x12]; int unknown16; };
#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall GAME_ResetMouseState(); // 0x0044DA40
D2SoundStrc* __fastcall sub_004B9610(int nSound); // 0x004B9610
void __fastcall SOUNDINST_ArmHint(D2SoundStrc* pSound, int nZero, int nZero2, int nMode); // 0x004B9EF0
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nId, int nType); // 0x00463990
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int nType, unsigned int nId); // 0x004786A0
extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830
void __fastcall SELECT_SetSelectionRect(D2RectStrc* pRect); // 0x00467430
void __cdecl SELECT_ClearSelection(); // 0x00466FE0
int __fastcall D2Win_10127_SetFont(int nFont); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
D2TextBlockStrc* __fastcall TEXT_CreateTextBox(const Unicode* pText, int nMode); // 0x004A05E0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_004E0650_GetStringSound(unsigned short nString); // 0x004E0650
void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit); // 0x004CB190
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_004B9A00(int nSound, D2UnitStrc* pUnit, int nMode, int nZero, int nZero2); // 0x004B9A00
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void* __stdcall WINDOW_GetWindow(); // 0x004F59A0
void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, void* pHandlers, int nCount); // 0x00451DB0

extern const char gszTextSourceFile[]; // 0x006DA13C
extern int gnTextTop_007225FC; // 0x007225FC
extern unsigned char gaHandlers_00722600[]; // 0x00722600
extern D2TextBlockStrc* gpTextBox; // 0x007BF0A4
extern D2TextBlockStrc* gpPreviousTextBox_007BF1A8; // 0x007BF1A8
extern int gnTextState_007BF1BC; // 0x007BF1BC
extern int gnTextActive_007BF1C0; // 0x007BF1C0
extern int gnPreviousTextActive_007BF1C4; // 0x007BF1C4
extern unsigned int gnNpcId_007BF202; // 0x007BF202
extern int gnHasNpc_007BF20A; // 0x007BF20A
extern unsigned short gwMessage_007BF212; // 0x007BF212
extern unsigned long gnStartTick_007BF22C; // 0x007BF22C
extern int gnGlobal_007BF230; // 0x007BF230
extern int gnGlobal_007BF236; // 0x007BF236
extern int gnSoundPlaying_007BF24B; // 0x007BF24B
extern int gnSound_007BF260; // 0x007BF260
extern int gnTextLeft_007BF278; // 0x007BF278
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
    gnGlobal_007BF236 = 0;
    gnTextTop_007225FC = 12;
    gnTextLeft_007BF278 = (gnScreenWidth_0071146C - 325) / 2;
    gnGlobal_007BF230 = 0;
    GAME_ResetMouseState();
    if (gnSound_007BF260)
    {
        D2SoundStrc* pSound = sub_004B9610(gnSound_007BF260);
        if (pSound)
            SOUNDINST_ArmHint(pSound, 0, 0, 4);
        gnSound_007BF260 = 0;
    }
    gnSoundPlaying_007BF24B = 0;
    if (!pUnit)
    {
        if (gnPreviousTextActive_007BF1C4)
        {
            if (gpPreviousTextBox_007BF1A8)
            {
                TEXT_FreeTextBox(gpPreviousTextBox_007BF1A8);
                gpPreviousTextBox_007BF1A8 = 0;
            }
            gnPreviousTextActive_007BF1C4 = 0;
        }
        gnHasNpc_007BF20A = 0;
        gnNpcId_007BF202 = 0;
    }
    else
    {
        if (gnHasNpc_007BF20A)
        {
            D2UnitStrc* pPreviousNpc = CUNIT_FindClientUnit(gnNpcId_007BF202, 1);
            if (pPreviousNpc && pPreviousNpc != pUnit)
            {
                MSG_SendTwoDwords(0x30, 1, gnNpcId_007BF202);
                NPCMENU_ClearNpcInventoryAndSound(gnNpcId_007BF202);
            }
        }
        gnHasNpc_007BF20A = 1;
        gnNpcId_007BF202 = pUnit->dwUnitId;
    }
    D2RectStrc tRect;
    tRect.nTop = gnTextTop_007225FC;
    tRect.nBottom = (gnTextTop_007225FC + 182 < gnScreenHeight - 53)
        ? gnTextTop_007225FC + 182 : gnScreenHeight - 53;
    tRect.nLeft = gnTextLeft_007BF278 - 10;
    tRect.nRight = gnTextLeft_007BF278 + 335;
    SELECT_SetSelectionRect(&tRect);
    SELECT_ClearSelection();
    gwMessage_007BF212 = nMessage;
    if (!gpTextBox)
    {
        gnTextState_007BF1BC = 0;
        int nPreviousFont = D2Win_10127_SetFont(8);
        gpTextBox = TEXT_CreateTextBox(D2LANG_GetStringFromTblIndex(nMessage), 2);
        if (!gpTextBox)
        {
// build: symbol ?gszEmptyString@* 0x006CC837
            FOG_DisplayHalt(gszEmptyString, sub_00408090(), 0x1024);
            exit(-1);
        }
        D2Win_10127_SetFont(nPreviousFont);
// build: symbol ?SOUNDINST_LockSpeechSounds@* 0x004BAA50
        SOUNDINST_LockSpeechSounds();
        gnSoundPlaying_007BF24B = 0;
        int nSound = sub_004E0650_GetStringSound(nMessage);
        if (nSound)
        {
            UNITSND_ReleaseSkillSfx(pUnit);
            gnSoundPlaying_007BF24B = sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 5, 0, 0);
            gnSound_007BF260 = nSound;
        }
        gpTextBox->unknown16 = 0;
        gnTextActive_007BF1C0 = 1;
        if (!gnHandlersSet_007BF27C)
        {
            gnHandlersSet_007BF27C = 1;
            gnStartTick_007BF22C = GetTickCount();
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHandlers_00722600, 7);
        }
    }
}
