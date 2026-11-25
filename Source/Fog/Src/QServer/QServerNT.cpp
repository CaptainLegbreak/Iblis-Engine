#include "Fog.h"
#include "D2QServer.h"
#include "D2SysTypes.h"
#include "D2NetTypes.h"

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2QOverlappedStrc;

struct D2QWriteNodeStrc;




struct D2SockAddrInStrc;




extern "C" __declspec(dllimport) int __stdcall GetQueuedCompletionStatus(void* hPort, unsigned long* pBytes, unsigned long* pKey, D2QOverlappedStrc** ppOverlapped, unsigned long nTimeout);

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nBytes, unsigned long* pWritten, D2QOverlappedStrc* pOverlapped);

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nBytes, unsigned long* pRead, D2QOverlappedStrc* pOverlapped);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl sub_006BE2F0_Nop(const char* szText, const char* szFormat, ...); // 0x006BE2F0


D2QClientStrc* __fastcall QSERVER_FindClient(D2QueueServerStrc* pServer, unsigned int nKey); // 0x006BE540

long __fastcall QSERVER_AddReference(D2QueueServerStrc* pServer, D2QClientStrc* pClient); // 0x006BE640

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pCounter);

extern "C" __declspec(dllimport) void* __stdcall CreateIoCompletionPort(unsigned int hFile, void* hPort, unsigned int nKey, unsigned int nThreads);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __stdcall ioctlsocket(unsigned int s, long nCommand, unsigned long* pArg); // 0x006B015C

extern "C" int __stdcall WSAGetLastError(void); // 0x006B0168

extern "C" char* __stdcall inet_ntoa(unsigned int nAddress); // 0x006B013E

int __fastcall FOG_SOCKET_CloseSocket(unsigned int s); // 0x0040D880

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szChannel, const char* szFormat, ...); // 0x00410660

int __fastcall QSERVER_CheckRecordThreshold(D2QueueServerStrc* pServer, const unsigned long* pAddress); // 0x006BE9F0

int __fastcall QSERVER_BanAddress(D2QueueServerStrc* pServer, unsigned long* pAddress, const char* szFile, int nLine); // 0x006C0800

void __fastcall QSERVER_HackListAddress(D2QueueServerStrc* pServer, const char* szFile, unsigned int nAddress, int nLine); // 0x006BFEA0

D2QClientStrc* __fastcall QSrvAddClient(D2QueueServerStrc* pServer, unsigned int s, unsigned int nAddress); // 0x006BFB70

extern "C" const char gszHack[]; // 0x006FC4A8

static int QSERVERNT_PostRead(D2QueueServerStrc* pServer, D2QClientStrc* pClient); // 0x006C2280

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

static void __stdcall QSERVERNT_QueueMessage(D2QClientStrc* pConn, const void* pData, unsigned int nSize); // 0x006C23B0

void __fastcall ERRORMANAGER_UnregisterThread(unsigned int nId); // 0x00407F90


static unsigned int __stdcall sQSNTAccept(int nSlot, int* pAddrLen, D2QueueServerStrc* pServer, D2SockAddrInStrc* pAddr);

long __cdecl SYSTEM_GetSyncTime(); // 0x00410A80


static int sQSNTWriteFromQueue(D2QueueServerStrc* pServer, D2QClientStrc* pClient);

struct D2HashNode006BE540Strc;

struct D2HashTable006BE540Strc;

struct D2FdSetStrc;

struct D2TimevalStrc;

union D2QTickStrc;

static int QSERVERNT_PopWrite(D2QClientStrc* pClient); // 0x006C2810

void __cdecl sub_006BE2F0_Nop(const char* unused1, const char* unused2, int unused3); // 0x006BE2F0


D2HashNode006BE540Strc* __fastcall QSERVER_FindClient(D2HashTable006BE540Strc* pTable, unsigned int nKey); // 0x006BE540

union D2QTickStrc
{
    struct
    {
        unsigned int nFraction;
        unsigned int nTick;
    };
    unsigned __int64 nQuad;
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds);

extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);

extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186

void __cdecl sub_006BF750_Nop(); // 0x006BF750

extern "C" int __cdecl abs(int n);

extern "C" int __stdcall send(unsigned int socket, const char* bytes, int size, int flags);          // 0x006B017A

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

struct D2QWorkerArgStrc
{
    D2QueueServerStrc* pServer;
    int nSlot;
};

extern "C" unsigned int __stdcall socket(int af, int type, int protocol);                                   // 0x006B016E

extern "C" int __stdcall setsockopt(unsigned int s, int level, int optname, const char* optval, int optlen); // 0x006B0162

extern "C" unsigned short __stdcall htons(unsigned short hostshort);                                         // 0x006B0156

extern "C" int __stdcall bind(unsigned int s, const D2SockAddrInStrc* name, int namelen);                   // 0x006C9B76

extern "C" int __stdcall listen(unsigned int s, int backlog);                                               // 0x006C9B70

void __cdecl LOGMANAGER_WriteLogLine(const char* format, ...);                                                             // 0x00410610

void __fastcall ERRORMANAGER_RegisterThread(unsigned int nId, void* hThread); // 0x00407F80

unsigned long __stdcall QSERVERNT_AcceptThread(void* pParam);                                              // 0x006C2860

unsigned long __stdcall QSERVERNT_ReleaseSlot(void* pParam);                                              // 0x006C3030

// 0x006C2280
static int QSERVERNT_PostRead(D2QueueServerStrc* pServer, D2QClientStrc* ptClient)
{
    D2CriticalSectionStrc* pLock = &ptClient->tLock;
    EnterCriticalSection(pLock);
    unsigned char* pBuffer = &ptClient->pBuffer[ptClient->nReadBytes];
    unsigned long nRoom = sizeof(ptClient->pBuffer) - ptClient->nReadBytes;
    if (!nRoom)
    {
// build: symbol ?gszQServerNTFile@* 0x006FC8A0
        QSrvCloseRemoteConnection(pServer, ptClient->nId, gszQServerNTFile, 0x3ED);
        LeaveCriticalSection(pLock);
        return 0;
    }
    D2_ASSERT(!(ptClient->tRead.nFlags & 4), 0x3F5);
    ptClient->tRead.nFlags |= 4;
    D2_ASSERT(!ptClient->tRead.hEvent, 0x3F8);
    if (ptClient->hSocket == (void*)-1)
    {
        unsigned int nId = ptClient->nId;
        LeaveCriticalSection(pLock);
        QSrvCloseRemoteConnection(pServer, nId, gszQServerNTFile, 0x408);
        QSERVER_ReleaseClient(pServer, ptClient);
        return 0;
    }
    QSERVER_AddReference(pServer, ptClient);
    int bOk = ReadFile(ptClient->hSocket, pBuffer, nRoom, &ptClient->nBytesRead, &ptClient->tRead);
    if (!bOk)
    {
        if (GetLastError() == 0x3E5)
        {
            bOk = 1;
        }
        else
        {
            QSERVER_ReleaseClient(pServer, ptClient);
            QSrvCloseRemoteConnection(pServer, ptClient->nId, gszQServerNTFile, 0x430);
            return 0;
        }
    }
    LeaveCriticalSection(pLock);
    return bOk;
}

unsigned int __fastcall sub_Emit_006C2420(D2QueueServerStrc* pServer, int nSlot)
{
    D2SockAddrInStrc tAddr;
    int nAddrLen;
    return sQSNTAccept(nSlot, &nAddrLen, pServer, &tAddr);
}

// 0x006C23B0
static void __stdcall QSERVERNT_QueueMessage(D2QClientStrc* pConn, const void* pData, unsigned int nSize)
{
    D2QWriteNodeStrc* pMsg = (D2QWriteNodeStrc*)FOG_Alloc(nSize + 8, ".\\Src\\QServer\\QServerNT.cpp", 0x440, 0);
    memcpy(pMsg->pData, pData, nSize);
    pMsg->nSize = nSize;
    pMsg->pNext = 0;
    if (!pConn->pWriteQueue)
    {
        pConn->pWriteQueue = pMsg;
        return;
    }
    D2QWriteNodeStrc* pLast = pConn->pWriteQueue;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pMsg;
}

// 0x006C2420
static unsigned int __stdcall sQSNTAccept(int nSlot, int* pAddrLen, D2QueueServerStrc* pServer, D2SockAddrInStrc* pAddr)
{
    memset(&pServer->aStats[nSlot].aTimes[0], 0, sizeof(pServer->aStats[nSlot].aTimes));
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[0]);
    *pAddrLen = 0x10;
    memset(pAddr, 0, sizeof(D2SockAddrInStrc));

    D2CriticalSectionStrc* pLock = &pServer->tStatsLock;
    EnterCriticalSection(pLock);
    ++pServer->aStats[nSlot].nAcceptAttempts;
    LeaveCriticalSection(pLock);

    pAddrLen = (int*)accept(pServer->hListenSockets[nSlot], pAddr, pAddrLen);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[1]);
    if ((unsigned int)pAddrLen == (unsigned int)-1)
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nAcceptErrors;
        LeaveCriticalSection(pLock);
        WSAGetLastError();
        return (unsigned int)-1;
    }

    int nReason = 0;
// build: symbol ?RefreshRecord@* 0x006BE980
    if (pServer->RefreshRecord(pAddr->sin_addr.s_addr))
        nReason = 1;
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[2]);

    if (!nReason && QSERVER_CheckRecordThreshold(pServer, &pAddr->sin_addr.s_addr))
    {
        QSERVER_BanAddress(pServer, &pAddr->sin_addr.s_addr, gszQServerNTFile, 0x4A9);
        nReason = 2;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[3]);

    if (!nReason && !QSERVER_CheckReconnectFlood(pServer, (const int*)&pAddr->sin_addr.s_addr) && !pServer->HasMaskedKey(pAddr->sin_addr.s_addr))
    {
        QSERVER_HackListAddress(pServer, gszQServerNTFile, pAddr->sin_addr.s_addr, 0x4B2);
        nReason = 3;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[4]);

    if (nReason)
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nRejected;
        LeaveCriticalSection(pLock);
        const char* szReason = nReason == 1 ? "user on hack list" : (nReason == 2 ? "user logged on twice" : "user spamming with reconnects");
        LOGMANAGER_LogWritePrefixedLine(gszHack, "[sQSNTAccept]               *** Deleted socket %d (%s) - %s ***", (unsigned int)pAddrLen, inet_ntoa(pAddr->sin_addr.s_addr), szReason);
        FOG_SOCKET_CloseSocket((unsigned int)pAddrLen);
        return (unsigned int)-1;
    }

    D2QClientStrc* ptClient = QSrvAddClient(pServer, (unsigned int)pAddrLen, pAddr->sin_addr.s_addr);
    ptClient->nSlot = nSlot;
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[5]);

    unsigned long nNonBlocking = 1;
    ioctlsocket((unsigned int)pAddrLen, 0x8004667E, &nNonBlocking);
    nReason = 0x10;
    sub_006B018C_GetSockAddr((unsigned int)pAddrLen, &ptClient->tPeerAddr, &nReason);
    SMemZero(ptClient->tPeerAddr.sin_zero, 8);
    nReason = 0x10;
    sub_006B0144_GetSockAddr((unsigned int)pAddrLen, &ptClient->tLocalAddr, &nReason);
    SMemZero(ptClient->tLocalAddr.sin_zero, 8);
    D2_ASSERT((unsigned int)ptClient->hSocket == (unsigned int)pAddrLen, 0x4E4);
    CreateIoCompletionPort((unsigned int)pAddrLen, pServer->hPorts[nSlot], ptClient->nId, 0);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[6]);

    if (!QSERVERNT_PostRead(pServer, ptClient))
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nPostErrors;
        LeaveCriticalSection(pLock);
        return (unsigned int)-1;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[7]);

    if (pServer->pfnOnAccept)
        pServer->pfnOnAccept(pServer, ptClient->nId, gszQServerNTFile, 0x4F9);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[8]);

    EnterCriticalSection(pLock);
    ++pServer->aStats[nSlot].nAccepted;
    LeaveCriticalSection(pLock);
    return (unsigned int)pAddrLen;
}

// 0x006C2760
static int sQSNTWriteFromQueue(D2QueueServerStrc* pServer, D2QClientStrc* ptClient)
{
    if (!ptClient->pWriteQueue)
    {
        return 1;
    }

    QSERVER_AddReference(pServer, ptClient);
    D2QWriteNodeStrc* pPacket = ptClient->pWriteQueue;
    D2_ASSERT(ptClient->nSocket != -1, 0x518);

    unsigned long nWritten;
    const int bWritten = WriteFile(ptClient->hSocket, pPacket->pData, pPacket->nSize, &nWritten, &ptClient->tWrite);
    const unsigned long nError = GetLastError();
    if (!bWritten && nError != 0x3E5)
    {
        QSERVER_ReleaseClient(pServer, ptClient);
        QSrvCloseRemoteConnection(pServer, ptClient->iId, gszQServerNT_006FC8A0, 0x527);
        return 0;
    }

    if (nError == 0x3E5)
    {
        ptClient->tWrite.nFlags |= 4;
    }
    return 1;
}


// 0x006C2810
static int QSERVERNT_PopWrite(D2QClientStrc* pClient)
{
    EnterCriticalSection(&pClient->tLock);
    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
    if (pNode)
        pClient->pWriteQueue = pNode->pNext;
    pClient->tWrite.nFlags &= ~4;
    LeaveCriticalSection(&pClient->tLock);
    if (pNode)
        FOG_Free(pNode, gszQServerNTFile, 0x578, 0);
    return 1;
}

void __fastcall sub_Emit_006C2810(D2QueueServerStrc* pServer, D2QClientStrc* pClient)
{
    QSERVERNT_PopWrite(pClient);
    EnterCriticalSection(&pClient->tLock);
    LeaveCriticalSection(&pClient->tLock);
    QSERVER_ReleaseClient(pServer, pClient);
}

// 0x006C2860
unsigned long __stdcall QSERVERNT_AcceptThread(void* pParam)
{
    D2QWorkerArgStrc* pArg = (D2QWorkerArgStrc*)pParam;
    D2QueueServerStrc* pServer = pArg->pServer;
    int nSlot = pArg->nSlot;
    FOG_Free(pArg, gszQServerNTFile, 0x10D, 0);

    D2QTickStrc tNext;
    tNext.nTick = GetTickCount();
    while (!pServer->bStopAccept[nSlot])
    {
        unsigned int nNow = GetTickCount();
        if (abs(tNext.nTick - nNow) > 2000)
        {
            tNext.nTick = nNow;
        }

        if ((int)(tNext.nTick - nNow) > 0)
        {
            Sleep(10);
        }
        else
        {
            pServer->ExpireEntries();
            if (!nSlot)
            {
                sub_006BF750_Nop();
            }

            D2FdSetStrc tRead;
            tRead.fd_array[0] = pServer->hListenSockets[nSlot];
            tRead.fd_count = 1;
            D2TimevalStrc tTimeout;
            tTimeout.tv_sec = 0;
            tTimeout.tv_usec = 0;
            int nResult = select(0x40, &tRead, 0, 0, &tTimeout);
            if (nResult == -1)
            {
                ERRORMANAGER_UnregisterThread(0);
                return 1;
            }

            if (nResult)
            {
                __int64 tStart;
                QueryPerformanceCounter(&tStart);
                int nPriority = GetThreadPriority(pServer->hAcceptThreads[nSlot]);
                if (nPriority != 0x7FFFFFFF)
                {
                    SetThreadPriority(pServer->hAcceptThreads[nSlot], nPriority);
                }

                D2SockAddrInStrc tAddr;
                int nAddrLen;
                sQSNTAccept(nSlot, &nAddrLen, pServer, &tAddr);

                __int64 tEnd;
                QueryPerformanceCounter(&tEnd);
                EnterCriticalSection(&pServer->tStatsLock);
                pServer->aStats[nSlot].tTotal += tEnd - tStart;
                __int64* pTimes = pServer->aStats[nSlot].aTimes;
                __int64* pStages = pServer->aStats[nSlot].aStages;
                for (int i = 1; i < 9; ++i)
                {
                    if (!pTimes[i])
                    {
                        pTimes[i] = pTimes[i - 1];
                    }
                }
                for (int i = 8; i > 0; --i)
                {
                    pStages[i] += pTimes[i] - pTimes[i - 1];
                }
                LeaveCriticalSection(&pServer->tStatsLock);

                tNext.nQuad += 0x8B21642C8ui64;
                Sleep(0);
            }
            else
            {
                Sleep(20);
            }
        }
    }

    EnterCriticalSection(&pServer->tLock);
    pServer->bStopAccept[nSlot] = 0;
    LeaveCriticalSection(&pServer->tLock);
    ERRORMANAGER_UnregisterThread(0);
    return 1;
}

// 0x006C3120
unsigned int __fastcall QSERVERNT_Start(D2QueueServerStrc* pServer, int nPort)
{
    void* hPort = CreateIoCompletionPort((unsigned int)-1, 0, 0, 0);
    D2_ASSERT(hPort, 0x4E);

    unsigned int s = socket(2, 1, 0);
    if (s == (unsigned int)-1)
    {
        LOGMANAGER_WriteLogLine("[SERVER]  QSNTInit failed on socket() - err=%d", WSAGetLastError());
        return 0;
    }

    int bNoDelay = 1;
    setsockopt(s, 6, 1, (const char*)&bNoDelay, 4);
    int bKeepAlive = 1;
    setsockopt(s, 0xFFFF, 8, (const char*)&bKeepAlive, 4);
    int bReuseAddr = 1;
    setsockopt(s, 0xFFFF, 4, (const char*)&bReuseAddr, 4);
    unsigned long nNonBlocking = 1;
    ioctlsocket(s, 0x8004667E, &nNonBlocking);

    D2SockAddrInStrc tAddr;
    memset(&tAddr, 0, sizeof(tAddr));
    tAddr.sin_family = 2;
    tAddr.sin_port = htons(nPort);
    if (bind(s, &tAddr, sizeof(tAddr)) == -1)
    {
        LOGMANAGER_WriteLogLine("[SERVER]  QSNTInit failed on bind() - err=%d", WSAGetLastError());
        FOG_SOCKET_CloseSocket(s);
        return 0;
    }

    if (listen(s, 0xFA) == -1)
    {
        LOGMANAGER_WriteLogLine("[SERVER]  QSNTInit failed on listen() - err=%d", WSAGetLastError());
        FOG_SOCKET_CloseSocket(s);
        return 0;
    }

    const int nSlot = pServer->nListeners++;
    pServer->hPorts[nSlot] = hPort;
    pServer->aPorts[nSlot] = nPort;
    pServer->hListenSockets[nSlot] = s;
    pServer->aActive[nSlot] = 1;

    D2QWorkerArgStrc* pArg = (D2QWorkerArgStrc*)FOG_Alloc(sizeof(D2QWorkerArgStrc), ".\\Src\\QServer\\QServerNT.cpp", 0xA2, 0);
    pArg->pServer = pServer;
    pArg->nSlot = nSlot;
    pServer->hAcceptThreads[nSlot] = CreateThread(0, 0, QSERVERNT_AcceptThread, pArg, 0, &pServer->aThreadIds[nSlot]);
    ERRORMANAGER_RegisterThread(pServer->aThreadIds[nSlot], pServer->hAcceptThreads[nSlot]);

    if (pServer->bSecondWorker)
    {
        D2QWorkerArgStrc* pArg2 = (D2QWorkerArgStrc*)FOG_Alloc(sizeof(D2QWorkerArgStrc), ".\\Src\\QServer\\QServerNT.cpp", 0xB5, 0);
        pArg2->pServer = pServer;
        pArg2->nSlot = nSlot;
        unsigned long* pThreadId = &pServer->aThreadIds2[nSlot];
        pServer->aThreads2[nSlot] = CreateThread(0, 0, QSERVERNT_ReleaseSlot, pArg2, 0, pThreadId);
        ERRORMANAGER_RegisterThread(*pThreadId, pServer->aThreads2[nSlot]);
    }

    return s;
}

// 0x006C2D70
int __fastcall QSERVERNT_ServiceSlot(D2QueueServerStrc* pServer, int nSlot, unsigned long nTimeout)
{
    unsigned long nBytes;
    unsigned long nKey;
    D2QOverlappedStrc* pOverlapped;
    int nResult = 0;
    unsigned long nStart = GetTickCount();
    for (;; nTimeout = 0)
    {
        if (nStart - GetTickCount() > 100)
            break;
        D2QClientStrc* pClient = 0;
        int bOk = GetQueuedCompletionStatus(pServer->hPorts[nSlot], &nBytes, &nKey, &pOverlapped, nTimeout);
        int bRead = 0;
        int bWrite = 0;
        if (bOk || pOverlapped)
        {
            pClient = QSERVER_FindClient(pServer, nKey);
            if (!pClient)
                continue;

            D2QClientStrc* pOwner = 0;
            unsigned int nFlags = pOverlapped->nFlags;
            bRead = QS_IS_READ(nFlags);
            bWrite = QS_IS_WRITE(nFlags);
            if (bRead)
                pOwner = (D2QClientStrc*)((char*)pOverlapped - 0x44);
            else if (bWrite)
                pOwner = (D2QClientStrc*)((char*)pOverlapped - 0x5C);
            if (pClient != pOwner)
                sub_006BE2F0_Nop(&gszEmptyAssertText, "GQCS1b nClientId %d does not match overlapped ptClient 0x%08X %d", nKey, pClient, nFlags);
        }

        {
            unsigned long nError = GetLastError();
            if (bOk)
            {
                if (!nBytes)
                {
                    sub_006BE300_Nop("QSRV", "[NTRdQ]          0 bytes on client %d refcount=%d %s", pClient->nId, pClient->nRefCount,
                                     bRead ? "READ" : (bWrite ? "WRITE" : "*UNKNOWN*"));
                    if (pClient->hSocket != (void*)-1)
                        QSrvCloseRemoteConnection(pServer, pClient->nId, gszQServerNTFile, 0x35D);
                    QSERVER_ReleaseClient(pServer, pClient);
                }
                else if (bWrite)
                {
                    EnterCriticalSection(&pClient->tLock);
                    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
                    if (pNode)
                        pClient->pWriteQueue = pNode->pNext;
                    pClient->tWrite.nFlags &= ~4;
                    LeaveCriticalSection(&pClient->tLock);
                    if (pNode)
                        FOG_Free(pNode, gszQServerNTFile, 0x578, 0);
                    EnterCriticalSection(&pClient->tLock);
                    if (!pClient->bClosing)
                        sQSNTWriteFromQueue(pServer, pClient);
                    LeaveCriticalSection(&pClient->tLock);
                    QSERVER_ReleaseClient(pServer, pClient);
                }
                else if (bRead)
                {
                    EnterCriticalSection(&pClient->tLock);
                    pClient->tRead.nFlags &= ~4;
                    pClient->nReadBytes += nBytes;
                    pClient->nLastTick = sub_00410A80_GetTime();
                    LeaveCriticalSection(&pClient->tLock);
// build: symbol ?QSERVER_ProcessReceived@* 0x006C08A0
                    QSERVER_ProcessReceived(pServer, pClient);
                    nResult = 1;
                    if (!pClient->bClosing)
                        QSERVERNT_PostRead(pServer, pClient);
                    QSERVER_ReleaseClient(pServer, pClient);
                }
                else
                {
                    sub_006BE300_Nop("QSRV", "WARNING: IO Completion on unknown overlapped structure.");
                    sub_006BE300_Nop("QSRV", "  IOCP = 0x%08X/0x%08X, ptClient = 0x%08X/0x%08X.",
                                     (char*)pOverlapped - 0x44, pOverlapped, pClient, &pClient->tRead);
                }
            }
            else
            {
                if (pOverlapped && pClient)
                {
                    sub_006BE300_Nop("QSRV", "[NTRdQ]          I/O err %d on client %d refcount=%d", nError, pClient->nId, pClient->nRefCount);
                    QSrvCloseRemoteConnection(pServer, pClient->nId, gszQServerNTFile, 0x3BD);
                    QSERVER_ReleaseClient(pServer, pClient);
                }
                else
                {
                    if (nError == 0x102)
                        break;
                    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x3C8);
                    exit(-1);
                }
            }
        }
    }
    return nResult;
}

// 0x006C30D0
int __fastcall QSERVERNT_ServiceSlots(D2QueueServerStrc* pServer, int nTimeout)
{
    if (!pServer->bInitialized)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (pServer->aListenSockets[i] != -1)
            {
                QSERVERNT_ServiceSlot(pServer, i, nTimeout);
            }
        }
    }
    return 1;
}

// 0x006C3030
unsigned long __stdcall QSERVERNT_ReleaseSlot(void* pParam)
{
    D2QWorkerArgStrc* pReq = (D2QWorkerArgStrc*)pParam;
    D2QueueServerStrc* pServer = pReq->pServer;
    int nSlot = pReq->nSlot;
    FOG_Free(pReq, ".\\Src\\QServer\\QServerNT.cpp", 686, 0);
    if (!pServer->bInitialized)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 687);
        exit(-1);
    }
    while (!pServer->nSlots[nSlot])
    {
        QSERVERNT_ServiceSlot(pServer, nSlot, 50);
    }
    EnterCriticalSection(&pServer->tLock);
    pServer->nSlots[nSlot] = 0;
    LeaveCriticalSection(&pServer->tLock);
    ERRORMANAGER_UnregisterThread(0);
    return 1;
}

// 0x006C2C70
int __fastcall QSERVERNT_SendLocal(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pBytes, int nSize)
{
    int nError;
    D2CriticalSectionStrc* pLock = &pClient->tLock;
    EnterCriticalSection(pLock);
    pClient->nTick3 = SYSTEM_GetSyncTime();
    if (pClient->pWriteQueue)
    {
        QSERVERNT_QueueMessage(pClient, pBytes, nSize);
    }
    else
    {
        if (pClient->nSocket == -1)
        {
            nError = pClient->iId;
            LeaveCriticalSection(pLock);
            QSrvCloseRemoteConnection(pServer, nError, gszQServerNT_006FC8A0, 0x220);
            QSERVER_ReleaseClient(pServer, pClient);
            return 0;
        }

        unsigned int nBytesSent = send(pClient->nSocket, pBytes, nSize, 0);
        if (nBytesSent == -1)
        {
            nError = WSAGetLastError();
            if (nError != 0x2733)
            {
                nError = pClient->iId;
                LeaveCriticalSection(pLock);
                QSrvCloseRemoteConnection(pServer, nError, gszQServerNT_006FC8A0, 0x234);
                return 0;
            }
            nBytesSent = 0;
        }
        if (nBytesSent < (unsigned int)nSize)
        {
            QSERVERNT_QueueMessage(pClient, pBytes + nBytesSent, nSize - nBytesSent);
            sQSNTWriteFromQueue(pServer, pClient);
        }
    }

    LeaveCriticalSection(pLock);
    return 1;
}

extern "C" __declspec(dllimport) unsigned int __stdcall WaitForMultipleObjects(unsigned int,void* const*,int,unsigned int);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

// 0x006C2110
void __fastcall QSERVERNT_StopServerThreads(D2QueueServerStrc* server)
{
 void* handles[8];
 EnterCriticalSection(&server->tLock);
 int count=0;
 for(int i=0;i<4;++i) {
  if(server->hAcceptThreads[i]) handles[count++]=server->hAcceptThreads[i];
  server->bStopAccept[i]=1;
  if(server->bSecondWorker && server->aThreads2[i]) handles[count++]=server->aThreads2[i];
  server->nSlots[i]=1;
 }
 LeaveCriticalSection(&server->tLock);
 if(count>0) WaitForMultipleObjects(count,handles,1,1000);
 for(int i=0;i<4;++i) {
  if(server->hAcceptThreads[i]) {
   CloseHandle(server->hAcceptThreads[i]);
   server->hAcceptThreads[i]=0;
   server->aThreadIds[i]=0;
  }
  if(server->bSecondWorker && server->aThreads2[i]) {
   CloseHandle(server->aThreads2[i]);
   server->aThreads2[i]=0;
   server->aThreadIds2[i]=0;
  }
 }
}

// 0x006C3360
int __fastcall QSERVERNT_Startup(D2QueueServerStrc* pServer, int nPort)
{
    D2WSADataStrc tWsaData;
    pServer->bRunning = 1;
    if (WSAStartup(0x101, &tWsaData))
    {
        return 0;
    }
    return QSERVERNT_Start(pServer, nPort);
}
