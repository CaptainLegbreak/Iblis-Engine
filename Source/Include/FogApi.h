#pragma once
// Fog's exports that the other modules call: the error handler and the memory functions.

struct AsyncData;
struct D2BitBufferStrc;
struct D2FogSystemInfoStrc;
struct D2PoolSystemStrc;
struct D2TxtLinkStrc;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue); // 0x004111A0
int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0
int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0
int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930
unsigned long __fastcall FOG_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030
int __fastcall FOG_CreatePathHierarchy(const char* szPath); // 0x00406A10
int __fastcall EXCEPTIONS_ReleaseSymbols(int all); // 0x0040C720
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine); // 0x006BD040
void __fastcall EXCEL_BuildGammaTable(int gamma,void* table,double scale,int entrySize,int entries,int mask); // 0x006BE190
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsyncData); // 0x0040A9E0
void __fastcall FOG_AsyncDataFree(AsyncData* ptAsyncData); // 0x0040AB00
D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo(); // 0x00407360
const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
int __stdcall sub_00410B30(unsigned char* pBits, int nBit); // 0x00410B30
void __stdcall sub_00410B10(unsigned char* pBits, int nBit); // 0x00410B10
void __stdcall sub_00410B50(unsigned char* pBits, int nBit); // 0x00410B50
int __cdecl FOG_UseDirect(); // 0x00406D20
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString); // 0x004112C0
int __stdcall FOG_ComputeChecksum(unsigned char* pData, int nSize); // 0x00411130
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0
void __stdcall sub_00411320_CapitalizeWords(char* szText); // 0x00411320
char* __fastcall FOG_inet_ntoa(int nAddress); // 0x0040E080
int __fastcall FOG_SOCKET_CloseSocket(unsigned int s); // 0x0040D880
int __fastcall FOG_SOCKET_WSAStartup(); // 0x0040D890
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00411020
int __fastcall FOG_DeleteFileA(const char* szFileName); // 0x00406990
int __cdecl sub_00402A80_IsDbgHelpLoaded(); // 0x00402A80
int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLink, const char* szText, int bLogError); // 0x006BD3C0
void __stdcall FOG_10182_Return(int nUnused1); // 0x006BF5F0
