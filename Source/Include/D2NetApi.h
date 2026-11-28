#pragma once
// D2Net's exports that the other modules call: the client and server packet queues.

struct D2PacketBufferStrc;

void __stdcall CLIENT_Initialize(int nArg, const char* szIpAddress); // 0x0052A750
void __cdecl CLIENT_Release(); // 0x0052A7E0
int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A890
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A8B0
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize); // 0x0052AEB0
int __cdecl CLIENT_GetConnectionStatus(); // 0x0052B050
void __stdcall SERVER_SetMaxClientsPerGame(int nArg1); // 0x0052B250
int __stdcall SERVER_SetHackListEnabled(int nArg1); // 0x0052B280
void __cdecl SERVER_Release(); // 0x0052B2A0
int __stdcall SERVER_ReadGamePacket(int nArg1, int nArg2); // 0x0052B2D0
int __stdcall SERVER_ReadSystemPacket(int nArg1, int nArg2); // 0x0052B2F0
int __stdcall SERVER_ReadAdminPacket(int nArg1, int nArg2); // 0x0052B310
unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize); // 0x0052B330
int __stdcall CLIENT_ObjectCall_6BED90(int nArg1, int nArg2, int nArg3); // 0x0052B490
int __stdcall SERVER_HackListClient(int nArg1, int nArg2, int nArg3); // 0x0052B4F0
void __stdcall D2NET_10016(int nClientId); // 0x0052B570
void __stdcall SERVER_Initialize(int nState, int bDisableNt); // 0x0052B7A0
int __cdecl sub_0052B910_GetLastError(); // 0x0052B910
int __fastcall SERVER_GetClientPacketSize(unsigned char* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052BC20
void __cdecl sub_0052BDA0_Empty(); // 0x0052BDA0
void __cdecl sub_0052BDB0_Empty(); // 0x0052BDB0
