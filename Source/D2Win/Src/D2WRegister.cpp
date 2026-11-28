#include "D2Win32Types.h"
#include "D2Win.h"
#include "FogApi.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
struct SMSGHANDLER_PARAMS;
typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

int __stdcall SMsgRegisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420BF0
int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C10
int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C30
int __stdcall SMsgRegisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C50
int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C70
int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C90
int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420CB0
int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420CD0

struct D2WinCommandRegisterStrc
{
    int nType;
    int nId;
    D2WinMsgHandler pCallback;
};

// 0x00506C40
void __fastcall WREGISTER_RegisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback)
{
    D2_ASSERT(hWnd, 0x13);
    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x17);
        D2_ASSERT(nId != 0x101, 0x18);
        D2_ASSERT(nId != 0x100, 0x19);
        SMsgRegisterMessage(hWnd, nId, pCallback);
        break;
    case 1:
        SMsgRegisterCommand(hWnd, nId, pCallback);
        break;
    case 2:
        SMsgRegisterKeyUp(hWnd, nId, pCallback);
        break;
    case 3:
        SMsgRegisterKeyDown(hWnd, nId, pCallback);
        break;
    default:
        return;
    }
}

// 0x00506CF0
void __fastcall WREGISTER_UnregisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback)
{
    D2_ASSERT(hWnd, 0x30);
    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x34);
        D2_ASSERT(nId != 0x101, 0x35);
        D2_ASSERT(nId != 0x100, 0x36);
        SMsgUnregisterMessage(hWnd, nId, pCallback);
        break;
    case 1:
        SMsgUnregisterCommand(hWnd, nId, pCallback);
        break;
    case 2:
        SMsgUnregisterKeyUp(hWnd, nId, pCallback);
        break;
    case 3:
        SMsgUnregisterKeyDown(hWnd, nId, pCallback);
        break;
    default:
        return;
    }
}

// 0x00506DA0
void __fastcall WREGISTER_RegisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands)
{
    D2_ASSERT(hWnd, 0x4D);

    for (unsigned int i = 0; i < nCommands; ++i)
    {
        WREGISTER_RegisterCommand(hWnd, pCommandRegister[i].nType, pCommandRegister[i].nId, pCommandRegister[i].pCallback);
    }
}

// 0x00506E00
void __fastcall WREGISTER_UnregisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands)
{
    D2_ASSERT(hWnd, 0x5A);

    for (unsigned int i = 0; i < nCommands; ++i)
    {
        WREGISTER_UnregisterCommand(hWnd, pCommandRegister[i].nType, pCommandRegister[i].nId, pCommandRegister[i].pCallback);
    }
}
