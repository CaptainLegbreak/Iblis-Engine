#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Unicode.h"

struct D2ClientItemSlotStrc
{
    unsigned short wId;
    char unk0x02[0x02];
    int nSeed;
    int nUnitId;
    char unk0x0C[0x04];
};

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags);                         // 0x00413020

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
        return SMemAlloc(nSize, "new", -1, 0);
    }

    virtual ~UIWidget();
    virtual void Draw() = 0;
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int GetValue() = 0;

    int unk0x04;
};

class ListBoxImplementation;

class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nArg1C,
        int nArg20);                                                                                        // 0x004BF8F0
    virtual ~ListBoxWrapper();
    virtual void Draw();
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg);
    virtual int GetValue();
    virtual void AddItem(const Unicode* wszText, const Unicode* wszHover, int nArg8, int nArgC, int nArg10,
        int nArg14, int nData, int nArg1C, int nArg20, int nArg24);
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();

    ListBoxImplementation* pImpl;
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);          // 0x006CC468

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0
D2UnitStrc* __fastcall sub_00463DD0();                                                             // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                               // 0x00625480
const Unicode* __fastcall MONSTERS_GetHirelingDescString(int nId); // 0x00663720
void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80
int __cdecl NPCMENU_HireMercHandler();                                                                // 0x004B3660
void __cdecl NPCMENU_BuildNpcMenu();                                                                        // 0x004B4830
int __cdecl NPCMENU_CloseHireDialog();                                                                    // 0x004B5C20
void __fastcall DIALOG_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC);   // 0x004B7C00
// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28);                                            // 0x004B7EB0
void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex);                               // 0x004B82F0
void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc* pDialog, int nValue);                           // 0x004B8370
// build: symbol ?DIALOG_AddTextLine@* 0x004B85F0
void __fastcall DIALOG_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nArg8, int nArgC,
    int nArg10, int nArg14, int (__cdecl* pfnCallback)(), int nArg1C);                                      // 0x004B85F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);              // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20

extern int gnScreenWidth;                                                                               // 0x0071146C
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern D2ClientItemSlotStrc gaNpcItemSlots[10];                                                       // 0x007C0C85
extern ListBoxWrapper* gpListBox_007C0D83;                                                                  // 0x007C0D83

// build: symbol ??0ListBoxWrapper@@QAE@HHHHHHHHH@Z 0x004BF8F0
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004B5C60
int __cdecl NPCMENU_ShowMainMenu()
{
// build: symbol ?gpNpcMainMenuDialog@* 0x007C0D6B
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

// build: symbol ?gpNpcHireDialog@* 0x007C0D77
    if (gpNpcHireDialog)
    {
        DIALOG_DestroyDialog(gpNpcHireDialog);
        delete gpListBox_007C0D83;
        gpListBox_007C0D83 = 0;
        gpNpcHireDialog = 0;
        NPCMENU_BuildNpcMenu();
        return 0;
    }

    gpNpcHireDialog = DIALOG_CreateDialog((gnScreenWidth - 0x1EA) / 2, gnAutomapHeight_007A521C / 2 - 0xC3,
        (int)NPCMENU_CloseHireDialog, 0, 0, 0, 0, 0x1EA, 0x15E, 0, 1);
    sub_004B8370_SetField5C(gpNpcHireDialog, 1);

    Unicode wszGold[300];
    sub_005269D0(300, wszGold, D2LANG_GetStringFromTblIndex(0xD24),
        STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLDBANK, 0) + STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLD, 0));
    DIALOG_AddTextLine(gpNpcHireDialog, wszGold, 0x15, 0, 4, 1, 0, 0);
    DIALOG_AddTextLine(gpNpcHireDialog, D2LANG_GetStringFromTblIndex(0xD48), 0x13B, 0, 0, 1, NPCMENU_CloseHireDialog, 1);

    gpListBox_007C0D83 = new ListBoxWrapper((gnScreenWidth - 0x1EA) / 2, gnAutomapHeight_007A521C / 2 - 0xA0, 0x1EA,
        0x118, 6, 0, 1, (int)NPCMENU_HireMercHandler, 0);
    if (!gpListBox_007C0D83)
    {
        NPCMENU_CloseHireDialog();
        return 0;
    }

    DIALOG_AddWidget(gpNpcHireDialog, gpListBox_007C0D83, 0x23, 0x1E);

    D2ClientItemSlotStrc* pSlot = gaNpcItemSlots;
    int nCount = 0;
    int i;
    for (i = 0; i < 10; ++i)
    {
        if (pSlot->nUnitId)
        {
            D2HirelingInitStrc hirelingInit;
            const int nAct = MONSTERS_GetActFromHirelingTxt(GAME_IsExpansion(), 0, pSlot->wId);
            const int nDifficulty = GAME_GetDifficulty();
            if (!MONSTERS_HirelingInit(GAME_IsExpansion(), sub_00463DD0(), pSlot->nSeed, nAct, nDifficulty,
                &hirelingInit))
            {
                return 0;
            }

            const int nLevel = hirelingInit.nLevel;
            const int nHitpoints = hirelingInit.nHitpoints;
            const int nDefense = hirelingInit.nDefense;
            const int nGold = hirelingInit.nGold;
            const int nHireDesc = hirelingInit.nHireDesc;

            Unicode wszText[150];
            Unicode wszHover[150];

            unsigned short wNameId = pSlot->wId;
            if (wNameId == 0x421)
            {
                wNameId = 0x2B0D;
            }
            sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(wNameId));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9C));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));

            Unicode wszLabel[20];
            Unicode wszNumber[10];
            char szNumber[10];

            sub_00526790(wszLabel, D2LANG_GetStringFromTblIndex(0xD28), 20);
            sub_00526700(wszText, wszLabel);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            wsprintfA(szNumber, "%2u", nLevel);
            sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
            sub_00526700(wszText, wszNumber);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));

            sub_00526790(wszLabel, D2LANG_GetStringFromTblIndex(0xD26), 20);
            sub_00526700(wszText, wszLabel);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            wsprintfA(szNumber, "%2u", nHitpoints);
            sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
            sub_00526700(wszText, wszNumber);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));

            sub_00526790(wszLabel, D2LANG_GetStringFromTblIndex(0xD27), 20);
            sub_00526700(wszText, wszLabel);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            wsprintfA(szNumber, "%2u", nDefense);
            sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
            sub_00526700(wszText, wszNumber);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));

            sub_00526790(wszLabel, D2LANG_GetStringFromTblIndex(0xD29), 20);
            sub_00526700(wszText, wszLabel);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
            wsprintfA(szNumber, "%2u", nGold);
            sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
            sub_00526700(wszText, wszNumber);
            sub_00526700(wszHover, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszHover, D2LANG_GetStringFromTblIndex(0xF9B));

            if (MONSTERS_GetHirelingDescString(nHireDesc))
            {
                Unicode wszDesc[150];
                Unicode wszFormat[6] = { 'a', '0', ':', '%', '0', 0 };
                INV_FormatArgs(wszDesc, wszFormat, MONSTERS_GetHirelingDescString(nHireDesc), 0);
                sub_00526700(wszHover, wszDesc);
            }

            gpListBox_007C0D83->AddItem(wszText, wszHover, 0, 0, 0, 0, i, 0, 1, 0xE);
            ++nCount;
        }
        ++pSlot;
    }

    if (!nCount)
    {
        gpListBox_007C0D83->AddItem(D2LANG_GetStringFromTblIndex(0xD25), 0, 0, 0, 0, 0, 10, 0, 1, 0xE);
    }

    sub_004B82F0_Select(gpNpcHireDialog, -1);
    return 1;
}
