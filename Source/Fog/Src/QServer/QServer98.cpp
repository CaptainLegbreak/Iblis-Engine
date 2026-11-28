#include "Fog.h"
#include "D2QServer.h"

struct D2CriticalSectionStrc;
struct D2SocketSetStrc;
struct D2TimevalStrc;
struct D2SocketAddressStrc;

D2QClientStrc* __fastcall QSrvAddClient(D2QueueServerStrc* pServer, unsigned int s, unsigned int nAddress); // 0x006BFB70

static void __stdcall QSERVER98_AddClient(D2QueueServerStrc* pServer, unsigned int s, D2InAddrStrc tAddress); // 0x006C3440

#include "D2SysTypes.h"
#include "D2NetTypes.h"
#include "FogApi.h"


struct D2SocketSetStrc { unsigned int count; int sockets[64]; };



struct D2SocketAddressStrc { unsigned int familyPort; unsigned int address; unsigned int rest[2]; };

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char*);
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitThread(unsigned int);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);
void __fastcall QSERVER_AddReference(D2QueueServerStrc*,D2QClientStrc*); // 0x006BE640
D2QClientStrc* __fastcall QSERVER_FindNodeInAnyBucket(D2QueueServerStrc*,int); // 0x006BE5B0
int __fastcall QSERVER_CheckRecordThreshold(D2QueueServerStrc*,unsigned int*); // 0x006BE9F0
int __fastcall QSERVER_BanAddress(D2QueueServerStrc*,unsigned int*,const char*,int); // 0x006C0800
void __fastcall QSERVER_HackListAddress(D2QueueServerStrc*,const char*,unsigned int,int); // 0x006BFEA0
D2QClientStrc* __fastcall QSrvAddClient(D2QueueServerStrc*,int,unsigned int); // 0x006BFB70
void __fastcall QSERVER_ProcessReceived(D2QueueServerStrc*,D2QClientStrc*); // 0x006C08A0
void __fastcall ERRORMANAGER_UnregisterThread(unsigned int nId); // 0x00407F90
int __stdcall sub_006B0186_Select(int,D2SocketSetStrc*,void*,D2SocketSetStrc*,D2TimevalStrc*); // 0x006B0186
int __stdcall sub_006B0180_IsSocketSet(int,D2SocketSetStrc*); // 0x006B0180
int __stdcall sub_006B0174_Receive(int,char*,int,int); // 0x006B0174
int __stdcall sub_006B0168_GetLastSocketError(); // 0x006B0168
int __stdcall sub_006B017A_Send(int nSocket, const void* pBuffer, int nLength, int nFlags); // 0x006B017A
unsigned int __stdcall sub_006B016E_Socket(int nFamily, int nType, int nProtocol); // 0x006B016E
int __stdcall sub_006B0162_SetOption(unsigned int nSocket, int nLevel, int nOption, const char* pValue, int nSize); // 0x006B0162
int __stdcall sub_006B015C_Ioctl(unsigned int nSocket, unsigned int nCommand, unsigned long* pArgument); // 0x006B015C
unsigned short __stdcall sub_006B0156_Htons(unsigned short nValue); // 0x006B0156
int __stdcall sub_006C9B76_Bind(unsigned int nSocket, const D2SockAddrInStrc* pAddress, int nSize); // 0x006C9B76
int __stdcall sub_006C9B70_Listen(unsigned int nSocket, int nBacklog); // 0x006C9B70
void __fastcall ERRORMANAGER_RegisterThread(unsigned int nId, void* hThread); // 0x00407F80
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __stdcall sub_006C9B6A_Accept(int,D2SocketAddressStrc*,int*); // 0x006C9B6A
void __stdcall sub_006C9B7C_SetLastSocketError(int); // 0x006C9B7C
int __cdecl sub_006823FD_Format(char*,const char*,...); // 0x006823FD
void __cdecl LOGMANAGER_LogWritePrefixedLine(const char*,const char*,...); // 0x00410660
extern const char gszSource[]; // 0x006FCB1C
extern const char gszHack[]; // 0x006FC4A8
extern const char gszReconnect[]; // 0x006FCB6C
extern const char gszAcceptError[]; // 0x006FCB50
extern const char gszFatal[]; // 0x006FCB38
extern const char gszStopped[]; // 0x006FCBA8

// 0x006C33D0
void __fastcall QSERVER98_Stop(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tLock);
    pServer->bStop = 1;
    LeaveCriticalSection(&pServer->tLock);
    WaitForSingleObject(pServer->hAcceptThreads[0], 2000);
}

// 0x006C3410
int __fastcall QSERVER98_Send(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize)
{
    if (sub_006B017A_Send(pClient->iSocket, pData, nSize, 0) == -1)
    {
        sub_006B0168_GetLastSocketError();
        return 0;
    }
    return 1;
}

// 0x006C3440
static void __stdcall QSERVER98_AddClient(D2QueueServerStrc* pServer, unsigned int s, D2InAddrStrc tAddress)
{
    D2QClientStrc* pClient = QSrvAddClient(pServer, s, tAddress.s_addr);
    if (pServer->pfnOnAccept)
        pServer->pfnOnAccept(pServer, pClient->nId, ".\\Src\\QServer\\QServer98.cpp", 0x91);
}

void __fastcall sub_Emit_006C3440(D2QueueServerStrc* pServer, unsigned int s, unsigned int nAddress)
{
    D2InAddrStrc tAddress;
    tAddress.s_addr = nAddress;
    QSERVER98_AddClient(pServer, s, tAddress);
    QSERVER98_AddClient(pServer, s + 1, tAddress);
}

// 0x006C3470
void __cdecl QSERVER98_ServerThread(D2QueueServerStrc* server)
{
    D2QClientStrc* nodes[64];
    D2SocketSetStrc readSet, errorSet;
    D2TimevalStrc timeout;
    int addressLength;
    int bucket = 0, skip = 0;
    struct { D2SocketAddressStrc address; char discard[0x5b4]; char errorText[100]; } buffers;
    for (;;)
    {
        int count = 0;
        server->ExpireEntries();
        EnterCriticalSection(&server->tLock);
        readSet.count = 0; errorSet.count = 0;
        D2QClientStrc* node = server->ppClients[bucket];
        while (node && skip--) node = node->pNext;
        for (int i=0; i<64; ++i)
        {
            if(i>=server->nClients) break;
            if (!node)
            {
                skip=0;
                do {
                    node=server->ppClients[bucket];
                    if (++bucket==server->nBucketCount) bucket=0;
                } while (!node);
            }
            D2CriticalSectionStrc* lock=&node->tLock;
            EnterCriticalSection(lock);
            if (node->iSocket != -1)
            {
                QSERVER_AddReference(server,node);
                nodes[count++]=node;
                if(readSet.count<64) readSet.sockets[readSet.count++]=node->iSocket;
                if(errorSet.count<64) errorSet.sockets[errorSet.count++]=node->iSocket;
                ++skip;
            }
            node=node->pNext;
            LeaveCriticalSection(lock);
        }
        timeout.tv_sec=0; timeout.tv_usec=100000/(server->nClients/64+1);
        LeaveCriticalSection(&server->tLock);
        for(int j=0;j<count;++j)
        {
            node=nodes[j];
            EnterCriticalSection(&node->tLock);
            if(node->iSocket==-1)
            {
                unsigned int k;
                for(k=0;k<readSet.count;++k) {
                    if(readSet.sockets[k]==node->iSocket) {
                        for(;k<readSet.count-1;++k) readSet.sockets[k]=readSet.sockets[k+1];
                        --readSet.count; break;
                    }
                }
                for(k=0;k<errorSet.count;++k) {
                    if(errorSet.sockets[k]==node->iSocket) {
                        for(;k<errorSet.count-1;++k) errorSet.sockets[k]=errorSet.sockets[k+1];
                        --errorSet.count; break;
                    }
                }
            }
        }
        if(server->nListener!=-1) {
            if(readSet.count<64) readSet.sockets[readSet.count++]=server->nListener;
            if(errorSet.count<64) errorSet.sockets[errorSet.count++]=server->nListener;
        }
        int selected=sub_006B0186_Select(64,&readSet,0,&errorSet,&timeout);
        for(int j=0;j<count;++j) {
            node=nodes[j]; LeaveCriticalSection(&node->tLock);
            QSERVER_ReleaseClient(server,node);
        }
        if(!selected) {
            EnterCriticalSection(&server->tLock);
            int stop=server->bStop; server->bStop=0;
            LeaveCriticalSection(&server->tLock);
            if(stop) { OutputDebugStringA(gszStopped); ERRORMANAGER_UnregisterThread(0); ExitThread(0); }
            continue;
        }
        if(selected==-1) continue;
        for(int j=-1;j<count;++j)
        {
            int socket=j==-1 ? server->nListener : nodes[j]->iSocket;
            if(sub_006B0180_IsSocketSet(socket,&errorSet) || !sub_006B0180_IsSocketSet(socket,&readSet)) continue;
            if(socket==server->nListener)
            {
                addressLength=16; buffers.address.familyPort=0; buffers.address.address=0; buffers.address.rest[0]=0; buffers.address.rest[1]=0;
                unsigned int retries=0;
                int bDone=0;
                while(!bDone)
                {

                    sub_006C9B7C_SetLastSocketError(0);
                    EnterCriticalSection(&server->tLock);
                    int accepted=sub_006C9B6A_Accept(socket,&buffers.address,&addressLength);
                    if(accepted==-1) {
                        int error=sub_006B0168_GetLastSocketError();
                        if(error!=0x2733) {
                            sub_006823FD_Format(buffers.errorText,gszAcceptError,error);
                            OutputDebugStringA(gszFatal);
                            LeaveCriticalSection(&server->tLock); ExitThread(0);
                        }
                        if(++retries>100) {
                            LeaveCriticalSection(&server->tLock);
                            break;
                        }
                        LeaveCriticalSection(&server->tLock);
                        continue;
                    }
// build: symbol ?RefreshRecord@* 0x006BE980
                    if(server->RefreshRecord(buffers.address.address)) FOG_SOCKET_CloseSocket(accepted);
                    else if(QSERVER_CheckRecordThreshold(server,&buffers.address.address)) {
                        QSERVER_BanAddress(server,&buffers.address.address,gszSource,0x138);
                        FOG_SOCKET_CloseSocket(accepted);
                    }
                    else if(!QSERVER_CheckReconnectFlood(server,(const int*)&buffers.address.address)) {
                        LOGMANAGER_LogWritePrefixedLine(gszHack,gszReconnect);
                        QSERVER_HackListAddress(server,gszSource,buffers.address.address,0x142);
                        FOG_SOCKET_CloseSocket(accepted);
                    }
                    else {
                        node=QSrvAddClient(server,accepted,buffers.address.address);
                        if(server->pfnOnNewClient) server->pfnOnNewClient(server,node->iId,gszSource,0x91);
                    }
                    LeaveCriticalSection(&server->tLock);
                    bDone=1;
                }
            }
            else {
                EnterCriticalSection(&server->tLock);
                node=QSERVER_FindNodeInAnyBucket(server,socket);
                if(node) {
                    EnterCriticalSection(&node->tLock);
                    int received=0;
                    if(node->nReadBytes<=0x5b4) received=sub_006B0174_Receive(socket,(char*)node->pBuffer+node->nReadBytes,0x5b4-node->nReadBytes,0);
                    LeaveCriticalSection(&node->tLock);
                    if(received!=-1) {
                        if(received) {
                            EnterCriticalSection(&node->tLock); node->nReadBytes+=received; LeaveCriticalSection(&node->tLock);
                            QSERVER_ProcessReceived(server,node); SetEvent(server->hEvent);
                        }
                        else QSrvCloseRemoteConnection(server,node->iId,gszSource,0x192);
                    }
                    else QSrvCloseRemoteConnection(server,node->iId,gszSource,0x192);
                }
                else sub_006B0174_Receive(socket,buffers.discard,0x5b4,0);
                LeaveCriticalSection(&server->tLock);
            }
        }
    }
}

extern "C" const char gData_006FCB38[24] = "Server thread close #2\n"; // 0x006FCB38
#pragma comment(linker, "/alternatename:?gszFatal@@3QBDB=_gData_006FCB38")

extern "C" const char gData_006FCB50[28] = "Accept failed.  Error %d"; // 0x006FCB50
#pragma comment(linker, "/alternatename:?gszAcceptError@@3QBDB=_gData_006FCB50")

extern "C" const char gData_006FCB6C[60] = "[HACKLIST] sServerThread(spamming server with reconnects)"; // 0x006FCB6C
#pragma comment(linker, "/alternatename:?gszReconnect@@3QBDB=_gData_006FCB6C")

extern "C" const char gData_006FCBA8[24] = "Server thread close #1\n"; // 0x006FCBA8
#pragma comment(linker, "/alternatename:?gszStopped@@3QBDB=_gData_006FCBA8")

// 0x006C3B50
int __fastcall QSERVER98_StartServer(D2QueueServerStrc* pServer, int nPort)
{
    pServer->bRunning = 1;
    unsigned int s = sub_006B016E_Socket(2, 1, 0);
    if (s == (unsigned int)-1)
        return 0;
    pServer->hListenSockets[0] = s;
    int bNoDelay = 1;
    sub_006B0162_SetOption(s, 6, 1, (const char*)&bNoDelay, 4);
    int bKeepAlive = 1;
    sub_006B0162_SetOption(s, 0xFFFF, 8, (const char*)&bKeepAlive, 4);
    int bReuse = 1;
    sub_006B0162_SetOption(pServer->hListenSockets[0], 0xFFFF, 4, (const char*)&bReuse, 4);
    unsigned long bNonBlocking = 1;
    sub_006B015C_Ioctl(s, 0x8004667E, &bNonBlocking);
    D2SockAddrInStrc tAddress;
    memset(&tAddress, 0, sizeof(tAddress));
    tAddress.sin_family = 2;
    tAddress.sin_port = sub_006B0156_Htons((unsigned short)nPort);
    pServer->aPorts[0] = (unsigned short)nPort;
    if (sub_006C9B76_Bind(pServer->hListenSockets[0], &tAddress, sizeof(tAddress)) == -1)
    {
        FOG_SOCKET_CloseSocket(s);
        return 0;
    }
    if (sub_006C9B70_Listen(s, 25) == -1)
        FOG_SOCKET_CloseSocket(s);
    pServer->hEvent = CreateEventA(0, 0, 0, 0);
    pServer->hAcceptThreads[0] = CreateThread(0, 0, (unsigned long (__stdcall*)(void*))QSERVER98_ServerThread, pServer, 0, &pServer->aThreadIds[0]);
    ERRORMANAGER_RegisterThread(pServer->aThreadIds[0], pServer->hAcceptThreads[0]);
    return 1;
}
