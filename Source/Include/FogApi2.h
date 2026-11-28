#pragma once
// Fog's exports that the other modules call and FogApi.h doesn't declare; included only by the units that use it.

struct AsyncData;
struct AsyncDataLoadFileCallback;
struct D2BinFieldStrc;
struct D2BinFileStrc;
struct D2BitBufferStrc;
struct D2DataArrayStrc;
struct D2PoolSystemStrc;
struct D2QueueServerStrc;
struct D2ThreadRecord006BC5A0Strc;
struct D2TxtLinkStrc;
struct FSafeSock;

int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940
int __fastcall ERRORMANAGER_GetBlizzardDataPath(char* szOutPath, int nSize); // 0x00406C40
char* __cdecl ERRORMANAGER_Sprintf(char* szDest, const char* szFormat, ...); // 0x00407310
void __fastcall FOG_SetLogPrefix(const char* szLogPrefix); // 0x00407960
void __cdecl ERRORMANAGER_ForceCrash(); // 0x00407970
int __cdecl FOG_IsHandlingError(); // 0x00407FF0
void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile); // 0x00408CE0
int __cdecl FOG_IsExpansion(); // 0x00408F20
void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...); // 0x00409020
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem); // 0x00409C80
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc); // 0x00409FF0
int __cdecl FOG_GetMemoryUsage(D2PoolSystemStrc* pSystem); // 0x0040A040
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused); // 0x0040A390
void __cdecl FOG_AsyncDataDestroy(); // 0x0040A440
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* ptAsyncData); // 0x0040A7F0
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData); // 0x0040AA40
int __stdcall sub_0040ABE0(); // 0x0040ABE0
void __cdecl FOG_InitHuffman(); // 0x0040B0C0
void __fastcall FOG_AddHuffmanStats(const unsigned char* pData, unsigned int nSize); // 0x0040B130
int __fastcall FOG_CompressPacket(unsigned char* pOut, int nOutSize, const unsigned char* pIn, int nInSize); // 0x0040B1B0
int __fastcall FOG_DecompressPacket(unsigned char* pOut, int nOutSize, const unsigned char* pIn, unsigned int nInSize); // 0x0040B260
void __cdecl FOG_10082_Noop(); // 0x0040B320
void* __fastcall FOG_ReallocPool(D2PoolSystemStrc* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __fastcall EXCEPTIONS_ReadCrashDump(char* pBuffer, unsigned int* pnSize); // 0x0040D290
int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DCC0
int __fastcall FOG_SOCKET_GetPeerName(FSafeSock* pSafeSock, void* pAddress, int* pnLength); // 0x0040DEE0
int __fastcall FOG_SOCKET_GetSockName(FSafeSock* pSafeSock, void* pAddress, int* pnLength); // 0x0040DF20
int __fastcall FOG_SOCKET_GetError(FSafeSock* pSafeSock, unsigned long* pFogError, unsigned long* pWSALastError); // 0x0040E0B0
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName); // 0x0040E0D0
int __fastcall FOG_SOCKET_SetBlockingMode(FSafeSock* pSafeSock, int bNonBlocking); // 0x0040E1A0
void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660
int __stdcall BITMANIP_SumByteTable(unsigned char* pData, int nSize); // 0x00411170
char* __fastcall Int64ToString(char* szBuffer, unsigned int nBufferSize, __int64 nValue); // 0x00411540
void __stdcall FOG_Encode14BitsToString(unsigned char* pBuffer, unsigned int nValue); // 0x006BBF40
extern "C" int __stdcall FOG_ConnectionSend(D2ThreadRecord006BC5A0Strc* pRecord, const char* pData, unsigned short nLength); // 0x006BC0B0
extern "C" unsigned int __stdcall FOG_ConnectionReceive(D2ThreadRecord006BC5A0Strc* pRecord, char* pBuffer, int nCapacity); // 0x006BC120
void __stdcall D2QSSOCKET_ConnectAndWait(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC5A0
void __stdcall D2QSSOCKET_Close(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC680
D2ThreadRecord006BC5A0Strc* __stdcall D2QSSOCKET_CreateRecord(const char* szName, int nPort, const char* szLabel); // 0x006BC6A0
void __stdcall D2QSSOCKET_DestroyRecord(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC780
FSafeSock* __stdcall D2QSSOCKET_GetSafeSock(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC810
D2DataArrayStrc* __fastcall DATAARRAYS_Create(const char* name, int count, int stride); // 0x006BCA10
void __fastcall DATAARRAYS_Destroy(void* pBlock); // 0x006BCA90
unsigned int __fastcall DATAARRAYS_AllocateHandle(D2DataArrayStrc* pPool); // 0x006BCB40
void __fastcall DATAARRAYS_Initialize(D2DataArrayStrc* pOwner); // 0x006BCCC0
extern "C" void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0
extern "C" int __stdcall FOG_GetLinkIndexByCode(D2TxtLinkStrc* pLink, unsigned int nCode, int bLogError); // 0x006BD130
int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* linker, int index, char* text); // 0x006BD180
int __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szCode); // 0x006BD500
D2BinFileStrc* __stdcall FOG_CreateBinFile(char* pDataBuffer, int nBufferSize); // 0x006BD640
void __stdcall FOG_ParseBinFields(D2BinFileStrc* bin,D2BinFieldStrc* fields,char* output,unsigned records,unsigned stride); // 0x006BD780
int __stdcall FOG_SetServerValue(D2QueueServerStrc* pServer, int nIndex, int nValue); // 0x006BE390
unsigned int __stdcall FOG_GetClientCount(D2QueueServerStrc* pServer); // 0x006BE450
void __stdcall FOG_SetMaxClientsPerGame(D2QueueServerStrc* pServer, unsigned int nCount); // 0x006BE4A0
unsigned long __stdcall FOG_WaitForSingleObject(D2QueueServerStrc* pServer, unsigned long dwMilliseconds); // 0x006BE4E0
int __stdcall FOG_PopQueuedMessage(D2QueueServerStrc* pQueue, int nIndex, void* pDst, unsigned int nMax); // 0x006BEAD0
int __stdcall FOG_WaitForMessages(D2QueueServerStrc* pServer, unsigned long dwMilliseconds); // 0x006BEBC0
void __stdcall FOG_GetClientIPString(D2QueueServerStrc* table, unsigned int key, char* output, unsigned int size); // 0x006BED90
unsigned int __stdcall FOG_GetClientAddress(D2QueueServerStrc* table, unsigned int key); // 0x006BEE20
int __stdcall FOG_GetClientSocket(D2QueueServerStrc* pTable, unsigned int nKey); // 0x006BEF40
void __stdcall QSERVER_HackUnlistIP(D2QueueServerStrc* pServer, unsigned long dwAddress, const char* szFile, int nLine); // 0x006BEFB0
void __stdcall FOG_SetRemoveClientCallback(D2QueueServerStrc* pServer, void* pfnCallback); // 0x006BF080
void __stdcall FOG_SetClientContext(void* pContainer, int nKey, int nValue); // 0x006BF0A0
int __stdcall FOG_GetClientContext(void* pContainer, int nKey); // 0x006BF0C0
void __stdcall FOG_SetHackListEnabled(D2QueueServerStrc* pServer, int bEnabled); // 0x006BF4E0
void __stdcall FOG_10183_Return(int nUnused1, int nUnused2); // 0x006BF600
void __fastcall FOG_AddAddressMask(D2QueueServerStrc* pServer, int nMaskIndex, unsigned int nKey); // 0x006BF610
int __fastcall QSERVER_CheckClientMask(D2QueueServerStrc* server, int clientId); // 0x006BF6C0
int __stdcall FOG_ShutdownServer(D2QueueServerStrc* pServer, char* pData, int nSize); // 0x006C0170
int __stdcall FOG_SendToClient(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize); // 0x006C03A0
void __stdcall QSERVER_HackListClient(D2QueueServerStrc* pTable, int nClient, const char* szFile, int nLine); // 0x006C0530
void __stdcall QSERVER_HackListIP(D2QueueServerStrc* table, unsigned int ip, const char* file, int line); // 0x006C0600
void __stdcall FOG_CloseRemoteConnection(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine); // 0x006C06B0
void __stdcall QSERVER_DisconnectIP(D2QueueServerStrc* pServer, unsigned int nIP, const char* pFile, int nLine); // 0x006C06D0

bool __fastcall ERRORMANAGER_EnumLoadedModules(void* pContext); // 0x00404E60
int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0
void __cdecl ERRORMANAGER_FreeUnusedPoolBlocks(D2PoolSystemStrc* pArg); // 0x00409B80
float __stdcall FOG_10083_Cos_LUT(int nAngle); // 0x0040B330
float __stdcall FOG_10084_Sin_LUT(int nAngle); // 0x0040B350
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock); // 0x0040DBD0
int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DC60
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock); // 0x0040DDF0
long __cdecl SYSTEM_GetSyncTime(); // 0x00410A80
extern "C" int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer); // 0x00411070
int __stdcall FOG_Decode14BitsFromString(const unsigned char* pBuffer); // 0x006BBF20
extern "C" void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker); // 0x006BD0B0
int __stdcall FOG_QueueReceivedPacket(D2QueueServerStrc* server,const unsigned char* buffer,int size,int id); // 0x006BF370
extern int gbRunningAsService; // 0x0074C720
extern char szSRegReadBuf[260]; // 0x0074C728
extern void* ghDbgHelp; // 0x0098A680
extern bool gbSymInitialized; // 0x0098A6B0
