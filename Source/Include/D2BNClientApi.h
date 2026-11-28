#pragma once
// D2BNClient's exports that the other modules call; included only by the units that use it.

struct D2FileTimeStrc;

void __cdecl sub_00518C20_DeleteQueueLock(); // 0x00518C20
int __cdecl BNSEND_SendCrashDump(); // 0x0051BCF0
int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
extern "C" int __cdecl BNDOWNLOAD_HasPendingDownloads(); // 0x0051E5E0
void __fastcall BNDOWNLOAD_RequestDownload(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910
int __fastcall BNMESSQUEUE_SetError(int nError); // 0x005204A0
int __fastcall BNSEND_SetErrorText(int nError, const char* szText); // 0x005204D0
int __fastcall BNMESSQUEUE_SetState(int nState); // 0x00520520
int __fastcall BNMESSQUEUE_SetStateArg(void* pArg); // 0x00520550
extern "C" int __cdecl BNDOWNLOAD_SetDisconnected(); // 0x00520AD0
extern "C" void __fastcall BNDOWNLOAD_ClearReply(unsigned char nSlot); // 0x00520C00
extern "C" int __fastcall BNDOWNLOAD_GetReplyValue(unsigned char nSlot); // 0x00520C20
void __fastcall BNDOWNLOAD_FillRandomBytes(char* szBuffer, int nSize); // 0x00522BC0
unsigned int __fastcall BNDOWNLOAD_DecryptData(unsigned char* data,unsigned int size,unsigned int key); // 0x00522E10
const char* __fastcall GRID_GetCDKey(int nSlot); // 0x00523AB0
extern int gnLastStatus; // 0x0072FFA8
extern int gdwGlobal_00730190; // 0x00730190
extern int gdwServerToken; // 0x008818BC
extern int gnLogonType; // 0x008818C0
extern void* gpReply; // 0x008818D0
extern int gfSetEmailRequested; // 0x00881C04
extern char gszInfoText[256]; // 0x00882028
extern int gnChangePasswordResult; // 0x008822A0
extern int gnCreateAccountResult; // 0x008822A4
extern char gszReplyText[256]; // 0x00882428
extern int gdwGlobal_00882528; // 0x00882528
extern int gnLoginRetryCount; // 0x00882538
