#pragma once
// D2MCPClient's exports that the other modules call; included only by the units that use it.

struct Unicode;

int __cdecl MCPCONNECT_QueryAddress(); // 0x00449B30
int __cdecl GAME_GetMcpGameToken(); // 0x00449BE0
void __stdcall CHATDLG_SetMcpResult(int nValue); // 0x00449BF0
int __cdecl GAME_GetConnectError(); // 0x00449C00
int __cdecl GAME_IsMcpCreateQueued(); // 0x00449E40
int __cdecl sub_00449E60_GetPacket(); // 0x00449E60
int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId); // 0x0044A4E0
int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId); // 0x0044A680
int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId); // 0x0044A710
int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2); // 0x0044A870
int __fastcall sub_0044A900_SendPacket0C(const char* szText); // 0x0044A900
int __fastcall GAME_DispatchMcpPacket(const unsigned char* pPacket, unsigned int nSize); // 0x0044B190
void __stdcall GAME_StripColorCodes(Unicode* pString); // 0x0044B230
extern int gnConnectError; // 0x0079929C
extern void* ghThread; // 0x007992A4
extern void* ghConnectEvent; // 0x007992EC
extern char* gpMcpPacket; // 0x007992F4
