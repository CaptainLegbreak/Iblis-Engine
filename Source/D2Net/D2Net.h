#pragma once

struct D2CriticalSectionStrc;
struct D2QueueServerStrc;
struct D2PacketBufferStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" int __stdcall WSAGetLastError(); // 0x006B0168
extern D2QueueServerStrc* gpServer; // 0x00882D08
extern int gClientSocket; // 0x00730AE0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall FOG_10175(D2QueueServerStrc* server,const unsigned char* buffer,int size,int id); // 0x006BF370
void __fastcall NET_SetConnectionMode(int nArg); // 0x0052B810
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize); // 0x0052AEB0
int __fastcall SERVER_GetClientPacketSize(unsigned char* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052BC20

typedef void (__fastcall* D2NetAddressCallback)(unsigned int nAddress, const char* szFile, int nLine);
typedef int (__fastcall* D2NetMessageCallback)(const unsigned char* pData, int nSize, int* pPacketSize, int* pFlags, int* pType, int* pPriority, int nUnused1, int nUnused2, unsigned int nClientId);
typedef void (__fastcall* D2NetClientCallback)(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine);
typedef int (__fastcall* D2NetHandlerCallback)(D2QueueServerStrc* pServer, char* pData, int nSize);
D2QueueServerStrc* __stdcall QSInit(int nState, int nSlots, int nPort, int bDisableNt, D2NetMessageCallback pfnProcess, D2NetClientCallback pfnOnNewClient, D2NetClientCallback pfnOnRemove, D2NetHandlerCallback pfnHandler); // 0x006BF760
void __stdcall FOG_10170(D2QueueServerStrc* pServer, D2NetAddressCallback pfnCallback); // 0x006BF040

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }
#define MAX_MSG_SIZE 516

struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};

#include "D2SysTypes.h"

int __fastcall NET_IsLocalConnection(); // 0x0052B7E0
