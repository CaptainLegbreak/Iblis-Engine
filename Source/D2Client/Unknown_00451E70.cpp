#include "D2Client.h"
#include "D2StormTypes.h"
#include "D2Win32Message.h"
#include "D2ClientTypes.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2TxtTables.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MsgHandlerEntryStrc;
struct Pad40_00451F30;
struct Obj00451F30;
struct Obj00451F70;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct Unicode;
struct D2StatesTxt;
struct D2MonLvlTxt;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2PetTypeTxt;
struct D2ItemTypesTxt;

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2MsgHandlerEntryStrc gaWindowMsgHandlers[4]; // 0x0070F7E4
void __fastcall SCMD_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451D10
void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

struct Pad40_00451F30 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00451F30 {
    Pad40_00451F30 tPad000;
    Pad40_00451F30 tPad040;
    Pad40_00451F30 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwFlagsC4;
};

struct Obj00451F70 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwValue10;
};




extern D2DataTablesStrc* sgptDataTables; // 0x00744304

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];


struct D2MonLvlTxt
{
    char unk0x00[0x78];
};





typedef char check_states_size[(sizeof(D2StatesTxt) == 0x3C) ? 1 : -1];

typedef char check_monlvl_size[(sizeof(D2MonLvlTxt) == 0x78) ? 1 : -1];

typedef char check_skills_size[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];

typedef char check_charstats_size[(sizeof(D2CharStatsTxt) == 0xC4) ? 1 : -1];

typedef char check_pettype_size[(sizeof(D2PetTypeTxt) == 0xE0) ? 1 : -1];

typedef char check_itemtypes_size[(sizeof(D2ItemTypesTxt) == 0xE4) ? 1 : -1];


struct D2WinMsgStrc;

extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode); // 0x006CC4A4

extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC488

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480

extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484

extern "C" __declspec(dllimport) int __stdcall TranslateAcceleratorA(void* hWnd, void* hAccTable, D2WinMsgStrc* pMsg); // 0x006CC4A8

extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg); // 0x006CC47C

extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg); // 0x006CC478

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned int nMilliseconds); // 0x006CC258

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

int __stdcall SMsgRegisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420BF0

int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C10

int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C30

int __stdcall SMsgRegisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C50

int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C70

int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C90

int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420CB0

int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420CD0

extern void* ghAccelerators; // 0x007A0708

enum { USE_RESULT = 0 };

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00

int __cdecl RECORD_IsReplayActive(); // 0x00451990

void __fastcall RECORD_RecordInputMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x004514B0

// 0x00451A90
void __stdcall SCMD_HandleQuitMessage(SMSGHANDLER_PARAMS* pMsg)
{
    PostQuitMessage(0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x00451AB0
void __stdcall SCMD_OnActivateApp(SMSGHANDLER_PARAMS* msg)
{
// build: symbol ?gbClientAppActive@* 0x0070F7E0
    gbClientAppActive = msg->wParam != 0;
    msg->bReturn = USE_RESULT;
}

// 0x00451AD0
void __stdcall SCMD_HandleDefaultMessage(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = DefWindowProcA(pMsg->hWnd, pMsg->uMessage, pMsg->wParam, pMsg->lParam);
}

// 0x00451B00
void __stdcall SCMD_HandleCloseMessage(SMSGHANDLER_PARAMS* pMsg)
{
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x00451B30
int __stdcall SCMD_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam)
{
    int bUseResult = 0;
    int lResult = 0;
    RECORD_RecordInputMessage(uMessage, wParam, lParam);
    if (!RECORD_IsReplayActive() || uMessage == 0x10)
    {
        if (SMsgDispatchMessage(hWnd, uMessage, wParam, lParam, &bUseResult, &lResult) && bUseResult)
            return lResult;
    }
    return DefWindowProcA(hWnd, uMessage, wParam, lParam);
}

// 0x00451BB0
int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int))
{
    int nCount = 0;
    int bContinue = 1;
    int nResult;
    D2WinMsgStrc msg;

    while (bContinue)
    {
        if (PeekMessageA(&msg, 0, 0, 0, 0))
        {
            bContinue = GetMessageA(&msg, 0, 0, 0);
            if (bContinue && ghAccelerators)
            {
                TranslateAcceleratorA((void*)WINDOW_GetWindow(), ghAccelerators, &msg);
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        else
        {
            if (pfnIdle)
            {
                nResult = pfnIdle(nCount++);
                if (nResult)
                {
                    break;
                }
            }

// build: symbol ?gbClientAppActive@* 0x0070F7E0
            if (!gbClientAppActive && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 8)
            {
                Sleep(10);
            }
        }
    }

    return bContinue ? nResult : 1;
}

// 0x00451C70
void __fastcall SCMD_RegisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler)
{
    D2_ASSERT(hWnd, 0x110);

    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x114);
        SMsgRegisterMessage(hWnd, nId, pfnHandler);
        return;
    case 1:
        SMsgRegisterCommand(hWnd, nId, pfnHandler);
        return;
    case 2:
        SMsgRegisterKeyUp(hWnd, nId, pfnHandler);
        return;
    case 3:
        SMsgRegisterKeyDown(hWnd, nId, pfnHandler);
        return;
    }
}

// 0x00451D10
void __fastcall SCMD_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler)
{
    D2_ASSERT(hWnd, 0x131);

    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x135);
        SMsgUnregisterMessage(hWnd, nId, pfnHandler);
        return;
    case 1:
        SMsgUnregisterCommand(hWnd, nId, pfnHandler);
        return;
    case 2:
        SMsgUnregisterKeyUp(hWnd, nId, pfnHandler);
        return;
    case 3:
        SMsgUnregisterKeyDown(hWnd, nId, pfnHandler);
        return;
    }
}

// 0x00451DB0
void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount)
{
    D2_ASSERT(hWnd, 0x153);
    for (unsigned int i = 0; i < nCount; i++)
    {
        SCMD_RegisterMsgHandler(hWnd, pTable[i].nType, pTable[i].nId, (SMSGHANDLER)pTable[i].pfnHandler);
    }
}

// 0x00451E10
void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < nCount; ++i)
    {
        SCMD_UnregisterMsgHandler(hWnd, pTable[i].nType, pTable[i].nId, (SMSGHANDLER)pTable[i].pfnHandler);
    }
}

// 0x00451E70
int __fastcall sub_00451E70_RegisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x178);
    SCMD_RegisterMsgHandlers((int)hWnd, gaWindowMsgHandlers, 4);
    SMsgPushRegisterState((int)hWnd);
    return 1;
}

// 0x00451EB0
void __fastcall sub_00451EB0_UnregisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < 4; ++i)
    {
        SCMD_UnregisterMsgHandler(hWnd, gaWindowMsgHandlers[i].nType, gaWindowMsgHandlers[i].nId, (SMSGHANDLER)gaWindowMsgHandlers[i].pfnHandler);
    }
// build: symbol ?SMsgPopRegisterState@* 0x00420320
    SMsgPopRegisterState(hWnd);
}

#include "gen/data/Source/D2Client/Unknown_00451E70.inc"

extern "C" __declspec(dllexport) int __fastcall sub_00451F30(Obj00451F30* pObj, unsigned int dwMask); // 0x00451F30

extern "C" __declspec(dllexport) unsigned int __fastcall sub_00451F70(Obj00451F70* pObj); // 0x00451F70



extern Unicode gwszHoverText[]; // 0x007A2A78

int gnHoverTextState; // 0x007A2C78





// 0x00452550
void __fastcall sub_00452550_SetHoverText(const Unicode* pText, int nState)
{
    if (!pText)
    {
        gwszHoverText[0].wChar = 0;
        return;
    }

    sub_005267E0(gwszHoverText, pText);
    gnHoverTextState = nState;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}


// 0x00478A20
extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }

    return 0;
}

// 0x004833E0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x005A0000
extern "C" D2MonLvlTxt* __fastcall MISSILES_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005C8BC0
extern "C" int __fastcall SKILLS_GetSkillsTxtParam7(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6];
}

// 0x00628440
extern "C" int __stdcall ITEMS_GetAmmoTypeFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wShoots;
}
