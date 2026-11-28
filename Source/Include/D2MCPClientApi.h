#pragma once
// D2MCPClient's exports that the other modules call.

struct D2LaunchRequestStrc;
struct D2LaunchThreadRecordStrc;
struct D2McpCreateGameStrc;

int __cdecl GAME_GetWaitHandle(); // 0x00449AC0
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
int __cdecl WINMAIN_PollMcpConnection(); // 0x00449B70
void* __cdecl GAME_GetMcpGameServerIP(); // 0x00449BC0
unsigned short __cdecl CHATDLG_GetRequestId(); // 0x00449BD0
int __cdecl GAME_IsMcpCharCreateReceived(); // 0x00449C10
void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20
int __cdecl GAME_IsMcpCharLogonReceived(); // 0x00449C30
void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
int __cdecl GAME_IsMcpCharDeleteReceived(); // 0x00449C50
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue); // 0x00449C60
int __cdecl GAME_IsMcpCharUpgradeReceived(); // 0x00449C70
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue); // 0x00449C80
void __stdcall sub_00449C90_SetValue(int nValue); // 0x00449C90
void __stdcall sub_00449CC0_SetValue(int nValue); // 0x00449CC0
void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2); // 0x00449D10
void* __cdecl GAME_GetMcpReply(); // 0x00449D50
void __cdecl CHATDLG_ClearReply(); // 0x00449D60
void __stdcall sub_00449D90_SetValue(int nValue); // 0x00449D90
void __stdcall sub_00449DB0_SetValue(int nValue); // 0x00449DB0
void __stdcall sub_00449DD0_SetValue(int nValue); // 0x00449DD0
int __cdecl GAME_GetMcpGameHash(); // 0x00449DE0
int __stdcall CHATDLG_RequestCharCreate(int nA, int nB, int nC); // 0x00449DF0
int __stdcall CHATDLG_RequestCharLogon(int nA); // 0x00449E10
int __cdecl GAME_GetMcpCharLevel(); // 0x00449E20
void __stdcall sub_00449E30_SetValue(int nValue); // 0x00449E30
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize); // 0x00449E70
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord); // 0x0044A130
int __fastcall WINMAIN_SendMcpCharCreate(const char* szText, int nValue, unsigned short wValue); // 0x0044A2E0
int __fastcall WINMAIN_SendMcpCharLogon(const char* szText); // 0x0044A380
int __fastcall WINMAIN_SendMcpCreateGame(D2McpCreateGameStrc* pRecord, unsigned short wRequestId); // 0x0044A400
void __fastcall WINMAIN_SendMcpGameListRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId); // 0x0044A590
int __fastcall WINMAIN_SendMcpGameInfoRequest(char* szText, unsigned short wRequestId); // 0x0044A610
void __fastcall WINMAIN_SendMcpCharDelete(const char* szText, unsigned short wRequestId); // 0x0044A7A0
void __fastcall WINMAIN_SendMcpCharUpgrade(const char* szText); // 0x0044A810
void __fastcall VIEW_SendMcpLadderRequest(unsigned char nArg1, unsigned short nArg2); // 0x0044AA10
void __cdecl VIEW_SendMcpMotdRequest(); // 0x0044AA50
void __cdecl VIEW_SendMcpCancelGameCreate(); // 0x0044AA80
int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC); // 0x0044AAE0
extern "C" void __fastcall sub_0044B210_StoreSlots(unsigned int first, unsigned int second); // 0x0044B210
