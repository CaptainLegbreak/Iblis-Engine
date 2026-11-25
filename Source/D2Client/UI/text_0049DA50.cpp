#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2TextIdEntry.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientTextBoxStrc;

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2TextNodeStrc;

struct D2TextListStrc;

struct D2HoverClearPacketStrc;

struct D2TextIdEntryStrc;

struct D2ClientTextDataStrc;

class ListBoxWrapper;

#pragma pack(push, 2)

struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

#pragma pack(pop)

#pragma pack(push, 1)

struct D2HoverClearPacketStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
};

#pragma pack(pop)


class ListBoxWrapper
{
public:
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0C();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1C();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2C();
    virtual void AddTextLine(Unicode* pLine0, Unicode* pLine1, Unicode* pLine2, Unicode* pLine3, Unicode* pLine4,
                             Unicode* pLine5, int nArg6, int nColor, int nArg8, int nArg9);
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

void __stdcall TEXT_FreeTextBox(D2ClientTextBoxStrc* pTextBox); // 0x0049D410

void __stdcall TEXT_FreeTextList(D2TextListStrc* pList); // 0x0049D4D0

void __cdecl TEXT_ResetTextBox(); // 0x0049F960

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

extern D2MsgHandlerEntryStrc gaTextMsgHandlers[]; // 0x00722600

extern D2TextIdEntryStrc gaTextIds[]; // 0x00722678

extern int gnTextIdCount; // 0x00722EB4

extern D2ClientTextBoxStrc* gpMainTextBox; // 0x007BF1A8

extern ListBoxWrapper* gpListBox; // 0x007BF1B4

extern int gbTextBoxDone; // 0x007BF1BC

extern int gnTextActive; // 0x007BF1C0

extern D2TextListStrc gtMessageTextList; // 0x007BF1E4

D2TextListStrc gtTextHistory; // 0x007BF1F0

extern unsigned char gbTextHoverSet; // 0x007BF23A

extern int gbTextHandlersRegistered; // 0x007BF27C

D2TextNodeStrc* __fastcall TEXT_CloneStringList(D2TextNodeStrc* pSource); // 0x0049DB10

int gbTextBoxShown; // 0x007BF1C8

int gnGlobal_007BF1E0; // 0x007BF1E0

D2ClientTextDataStrc* gpTextData; // 0x007BF228

int gbTextDataOpen; // 0x007BF254

D2TextCallback gpfnTextCallback; // 0x007BF258

void* gpTextCallbackContext; // 0x007BF25C

struct D2TextBoxStrc;


extern D2TextBoxStrc* gpTextBox;                                                                   // 0x007BF0A4

extern D2ClientDialogStrc* gpListDialog;                                                           // 0x007BF1B0


struct D2UnitStrc;

// build: symbol ?TEXT_FreeTextNode@* 0x0049D490
static void TEXT_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}


// 0x0049E340
void __cdecl TEXT_FillListBox()
{
    for (D2TextNodeStrc* pNode = gtTextHistory.pFirst; pNode; pNode = pNode->pNext)
        gpListBox->AddTextLine(pNode->pLines[0], pNode->pLines[1], pNode->pLines[2], pNode->pLines[3],
                                        pNode->pLines[4], pNode->pLines[5], 0, pNode->nColor, 0, 0xD);
}



// 0x0049F8C0
void __fastcall TEXT_ClearHoverText(D2HoverClearPacketStrc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
    }
}




// 0x004A0000
int __cdecl TEXT_IsTextBoxOpen()
{
    return gpTextBox != 0;
}

// 0x004A0010
void __cdecl TEXT_FreeTextLists()
{
    TEXT_FreeTextList(&gtMessageTextList);
    TEXT_FreeTextList(&gtTextHistory);
}

// 0x004A01E0
void __cdecl TEXT_ClearListFlags()
{
    for (D2TextNodeStrc* pNode = gtMessageTextList.pFirst; pNode; pNode = pNode->pNext)
        pNode->dwEndTick = 0;
}

// 0x004A02F0
void __cdecl TEXT_ToggleListDialogUI()
{
    if (gpListDialog)
    {
        UI_SetUIVar(0x18, 1, 0);
        UI_SetUIVar(0x18, 0, 0);
    }
}

// 0x004A0880
void __cdecl TEXT_CloseTextUnit()
{
    if (gbTextFromObject)
        sub_004B3D10_ReleaseTextUnit(gnTextNpcId);
    else
        TEXT_ResetTextBox();
    UI_StartUIVarDelay();
    gbTextFromObject = 0;
}

// 0x004A08C0
int __cdecl TEXT_CloseText()
{
    int bResult = 0;
    gbTextBoxDone = 1;
    if (!gbTextFromObject && gnTextActive != 1)
    {
// build: symbol ?gbTextBoxPending@* 0x007BF1C4
        if (gbTextBoxPending == 1)
        {
            if (gbTextBoxShown == 1)
            {
// build: symbol ?gbTextCallbackAccepted@* 0x007BF23F
                gbTextCallbackAccepted = 0;
                return bResult;
            }
            D2_ASSERT(gpMainTextBox, 0x947);
            TEXT_FreeTextBox(gpMainTextBox);
            FOG_Free(gpMainTextBox, ".\\UI\\text.cpp", 0x949, 0);
            gpMainTextBox = 0;
            gbTextBoxPending = 0;
            gbTextBoxShown = 0;
            bResult = 1;
        }
    }
    else
    {
        if (gpfnTextCallback)
        {
            TEXT_ResetTextBox();
            UI_StartUIVarDelay();
            if (gpfnTextCallback(gpTextCallbackContext, 1, gbTextCallbackAccepted))
            {
                gbTextCallbackAccepted = 0;
                return 1;
            }
            if (gbTextFromObject)
                sub_004B3D10_ReleaseTextUnit(gnTextNpcId);
        }
        else
        {
            if (gbTextFromObject)
                sub_004B3D10_ReleaseTextUnit(gnTextNpcId);
            else
                TEXT_ResetTextBox();
            UI_StartUIVarDelay();
        }
        gbTextFromObject = 0;
        if (gbTextHandlersRegistered == 1)
        {
            gbTextHandlersRegistered = 0;
            sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
        }
        bResult = 1;
    }
    gbTextCallbackAccepted = 0;
    return bResult;
}

#include "gen/data/Source/D2Client/UI/text_0049DA50.inc"
