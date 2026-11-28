#pragma once
// D2Net's exports that the other modules call; included only by the units that use it.

struct D2QueueServerStrc;

int __cdecl CLIENT_IsConnected(); // 0x0052A640
int __stdcall CLIENT_Send(int nSize, int nFlags, void* pData); // 0x0052AE50
int __stdcall SERVER_SetClientGameGUID(int nClientId, int dwGameGuid); // 0x0052B5E0
int __stdcall SERVER_GetClientGameGUID(int nClientId); // 0x0052B610
int __fastcall NET_IsLocalConnection(); // 0x0052B7E0
extern D2QueueServerStrc* gpServer; // 0x00882D08
