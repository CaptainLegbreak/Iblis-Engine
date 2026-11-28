#include "Fog.h"
#include "FogApi.h"
#include "D2FogSafeSock.h"
#include "StormApi.h"

#define D2_ASSERT(x,line) do { if (!(x)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); } } while (0)

struct FSafeSock;
struct D2ThreadRecord006BC5A0Strc;

typedef int (__fastcall* D2QSPacketHandlerFn)(unsigned char* pData, int nLength, void* pArg);

// A queued-socket record (0x194 bytes): its receive thread, the connection and the packet queue.
struct D2ThreadRecord006BC5A0Strc
{
    void* hThread;                          // 0x000
    unsigned long nThreadId;                // 0x004
    char szName[0x104];                     // 0x008
    int nPort;                              // 0x10C
    FSafeSock* pSafeSock;                   // 0x110
    void* hEvent;                           // 0x114
    int nHeaderSize;                        // 0x118
    int nLengthOffset;                      // 0x11C
    int nValue120;                          // 0x120
    int bStop;                              // 0x124
    char szLabel[0x40];                     // 0x128
    D2QSPacketHandlerFn pfnHandler;         // 0x168
    void* pHandlerArg;                      // 0x16C
    char tQueue[0x24];                      // 0x170
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszAssert_006CC837[]; // 0x006CC837
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void __fastcall D2QSQUEUE_InitQueue(void* pList); // 0x006C1F60
void __fastcall Destroy(void* pQueue); // 0x006C1F80
void __fastcall D2QSQUEUE_Push(void* pQueue, unsigned char* pData, unsigned short nLength); // 0x006C1FF0
extern const char gszSocketFile[]; // 0x006FC418
extern const char gszUnknownUpper[]; // 0x006CCED8

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C

void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock); // 0x0040DBD0
unsigned int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, unsigned char* pData, unsigned int nLength); // 0x0040DC60
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock); // 0x0040DDF0
void __fastcall FOG_SOCKET_GetError(FSafeSock* pSafeSock, int* pnError, int* pnStatus); // 0x0040E0B0
FSafeSock* __fastcall FOG_SOCKET_Connect(void* pSocket, int nPort, void (__stdcall* pfnCallback)(void*), void* pContext, void* pAddress); // 0x0040E230

struct D2PacketHeaderStrc { unsigned char id, command; unsigned short size; };

void __fastcall FOG_SOCKET_Lock(FSafeSock* pSafeSock); // 0x0040DDD0
void __fastcall FOG_SOCKET_Unlock(FSafeSock* pSafeSock); // 0x0040DDE0
int __fastcall FOG_SOCKET_SendNoLock(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DD80
int __fastcall D2QSQUEUE_Pop(void* pQueue, void* pDest, unsigned short nMaxLength); // 0x006C2090
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A
extern "C" int __stdcall WSAGetLastError(); // 0x006B0168

static int __stdcall D2QSSOCKET_SplitPackets(unsigned char* pBuffer, int nLength, D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC150
static void D2QSSOCKET_SetClosing(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC2C0
static void D2QSSOCKET_CloseSocket(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC310
static void __stdcall D2QSSOCKET_FreeSafeSock(D2ThreadRecord006BC5A0Strc* pRecord); // 0x006BC370

// 0x006BBF20
int __stdcall FOG_Decode14BitsFromString(const unsigned char* pBuffer)
{
    return ((pBuffer[1] & 0x7F) << 7) + (pBuffer[0] & 0x7F);
}

// 0x006BBF40
void __stdcall FOG_Encode14BitsToString(unsigned char* pBuffer, unsigned int nValue)
{
    pBuffer[0] = (unsigned char)(nValue | 0x80);
    pBuffer[1] = (unsigned char)((nValue >> 7) | 0x80);
}

// 0x006BBF60
int __stdcall FOG_Decode32BitsFromString(const unsigned char* pBytes)
{
    return (((pBytes[3] - 1) * 255 + (pBytes[2] - 1)) * 255 + (pBytes[1] - 1)) * 255 + (pBytes[0] - 1);
}

// 0x006BBFA0
void __stdcall FOG_Encode32BitsToString(unsigned char* pOut, unsigned int nValue)
{
    pOut[0] = (unsigned char)(nValue % 255 + 1);
    pOut[1] = (unsigned char)(nValue / 255 % 255 + 1);
    pOut[2] = (unsigned char)(nValue / (255 * 255) % 255 + 1);
    pOut[3] = (unsigned char)(nValue / (255 * 255 * 255) % 255 + 1);
}

// 0x006BC010
extern "C" void __stdcall D2QSSOCKET_SetPacketHandler(D2ThreadRecord006BC5A0Strc* pRecord, D2QSPacketHandlerFn pfnHandler, void* pHandlerArg)
{
    if (pRecord)
    {
        pRecord->pfnHandler = pfnHandler;
        pRecord->pHandlerArg = pHandlerArg;
    }
}

// 0x006BC030
extern "C" int __fastcall D2QSSOCKET_SafeSockSend(FSafeSock* pSafeSock, const char* pBuffer, unsigned int nSize)
{
    if (!pSafeSock || pSafeSock->bStopping)
        return -1;
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    int nResult;
    const int nSent = send(pSafeSock->nSocket, pBuffer, nSize, 0);
    if (nSent == -1)
    {
        const int nError = WSAGetLastError();
        pSafeSock->nWSALastError = nError;
        if (nError == 0x2733)
        {
            nResult = 0;
        }
        else
        {
            pSafeSock->nFogErrorCode = 4;
            return -1;
        }
    }
    else
    {
        nResult = nSent;
    }
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    return nResult;
}

// 0x006BC0B0
extern "C" int __stdcall FOG_ConnectionSend(D2ThreadRecord006BC5A0Strc* pRecord, const char* pData, unsigned short nLength)
{
    if (pRecord && pRecord->pSafeSock && pRecord->pSafeSock->bConnected != 0)
    {
        int nSent = 0;
        FOG_SOCKET_Lock(pRecord->pSafeSock);
        if (pData && nLength)
            nSent = FOG_SOCKET_SendNoLock(pRecord->pSafeSock, (char*)pData, nLength);
        FOG_SOCKET_Unlock(pRecord->pSafeSock);
        return nLength == (unsigned short)nSent;
    }
    return 0;
}

// 0x006BC120
extern "C" unsigned int __stdcall FOG_ConnectionReceive(D2ThreadRecord006BC5A0Strc* pRecord, char* pBuffer, int nCapacity)
{
    if (!pRecord)
        return 0;
    return D2QSQUEUE_Pop(pRecord->tQueue, pBuffer, (unsigned short)nCapacity);
}

// 0x006BC150
static int __stdcall D2QSSOCKET_SplitPackets(unsigned char* pBuffer, int nLength, D2ThreadRecord006BC5A0Strc* pRecord)
{
    unsigned char* pCursor = pBuffer;
    int nPacketSize, nHeaderSize, nRemaining;
    while (nRemaining = pBuffer - pCursor + nLength, nPacketSize = *(unsigned short*)(pCursor + pRecord->nLengthOffset),
           nHeaderSize = pRecord->nHeaderSize, nRemaining >= nHeaderSize ? nRemaining >= nPacketSize : false)
    {

        D2_ASSERT(nPacketSize < 0x2064, 0xFB);

        unsigned char* pPayload = pCursor + nHeaderSize;
        const unsigned short nPayloadSize = (unsigned short)(nPacketSize - nHeaderSize);
        if (pRecord->pfnHandler)
        {
            D2_ASSERT(!IsBadCodePtr((void*)pRecord->pfnHandler), 0x101);

            int bHandled;
            if (pRecord->nLengthOffset > 0)
                bHandled = pRecord->pfnHandler(pCursor, nPacketSize, pRecord->pHandlerArg);
            else
                bHandled = pRecord->pfnHandler(pPayload, nPayloadSize, pRecord->pHandlerArg);

            if (!bHandled)
            {
                if (pRecord->nLengthOffset > 0)
                    D2QSQUEUE_Push(pRecord->tQueue, pCursor, nPacketSize);
                else
                    D2QSQUEUE_Push(pRecord->tQueue, pPayload, nPayloadSize);
                SetEvent(pRecord->hEvent);
            }
        }
        else
        {
            D2QSQUEUE_Push(pRecord->tQueue, pPayload, nPayloadSize);
            SetEvent(pRecord->hEvent);
        }

        pCursor += nPacketSize;
    }

    const int nLeft = pBuffer - pCursor + nLength;
    memcpy(pBuffer, pCursor, nLeft);
    return nLeft;
}

// 0x006BC290
void __stdcall D2QSSOCKET_SetPacketFormat(D2ThreadRecord006BC5A0Strc* pRecord, int nA, int nB, int nC)
{
    if (pRecord)
    {
        pRecord->nHeaderSize = nA;
        pRecord->nLengthOffset = nB;
        pRecord->nValue120 = nC;
    }
}

// 0x006BC2C0
static void D2QSSOCKET_SetClosing(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && pRecord->pSafeSock && pRecord->pSafeSock->hThread)
    {
        pRecord->bStop = 1;
        EnterCriticalSection(&pRecord->pSafeSock->tCriticalSection);
        pRecord->pSafeSock->bStopping = 1;
        LeaveCriticalSection(&pRecord->pSafeSock->tCriticalSection);
    }
}

// 0x006BC310
static void D2QSSOCKET_CloseSocket(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && pRecord->pSafeSock && pRecord->pSafeSock->bConnected && pRecord->pSafeSock->nSocket)
    {
        EnterCriticalSection(&pRecord->pSafeSock->tCriticalSection);
        FOG_SOCKET_CloseSocket(pRecord->pSafeSock->nSocket);
        pRecord->pSafeSock->nSocket = (unsigned int)-1;
        pRecord->pSafeSock->bConnected = 0;
        LeaveCriticalSection(&pRecord->pSafeSock->tCriticalSection);
    }
}

// 0x006BC370
static void __stdcall D2QSSOCKET_FreeSafeSock(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (!pRecord)
        return;
    FSafeSock* pSafeSock = pRecord->pSafeSock;
    if (!(pSafeSock && pSafeSock->hThread))
        return;
    FOG_SOCKET_Destroy(pSafeSock);
    pRecord->pSafeSock = 0;
}

void __stdcall FreeNetContext(D2ThreadRecord006BC5A0Strc* pRecord)
{
    D2QSSOCKET_FreeSafeSock(pRecord);
}

// 0x006BC3A0
unsigned long __stdcall D2QSSOCKET_ReceiveLoop(D2ThreadRecord006BC5A0Strc* pRecord)
{
    unsigned char buffer[0x2068];
    unsigned int nLeft = 0;
    while (!pRecord->pSafeSock)
    {
        if (pRecord->bStop)
            goto done;
        Sleep(0);
    }
    while (!pRecord->bStop)
    {
        FSafeSock* pSafeSock = pRecord->pSafeSock;
        if (!pSafeSock || !pSafeSock->bConnected || pSafeSock->bStopping || pSafeSock->nFogErrorCode)
            break;
        int bReady = FOG_SOCKET_Select(pSafeSock);
        if (!pRecord->pSafeSock || pRecord->pSafeSock->bStopping)
            break;
        if (bReady)
        {
            while (!pRecord->bStop)
            {
                unsigned int nAvailable = 0x2064 - nLeft;
                unsigned int nReceived = FOG_SOCKET_Receive(pRecord->pSafeSock, buffer + nLeft, nAvailable);
                int nError, nStatus;
                FOG_SOCKET_GetError(pRecord->pSafeSock, &nError, &nStatus);
                if (nError || nReceived == 0 || nReceived == (unsigned int)-1)
                {
                    FSafeSock* pSock = pRecord->pSafeSock;
                    if (pSock && pSock->bConnected && pSock->nSocket)
                    {
                        EnterCriticalSection(&pSock->tCriticalSection);
                        FOG_SOCKET_CloseSocket(pRecord->pSafeSock->nSocket);
                        pRecord->pSafeSock->nSocket = (unsigned int)-1;
                        pRecord->pSafeSock->bConnected = 0;
                        LeaveCriticalSection(&pRecord->pSafeSock->tCriticalSection);
                    }
                    return 0;
                }
                nLeft = D2QSSOCKET_SplitPackets(buffer, nReceived + nLeft, pRecord);
                if (nReceived < nAvailable)
                    break;
            }
        }
    }
done:
    D2QSSOCKET_CloseSocket(pRecord);
    return 0;
}

// 0x006BC560
int __stdcall D2QSSOCKET_ConnectThreadProc(D2ThreadRecord006BC5A0Strc* pRecord)
{
    pRecord->pSafeSock = FOG_SOCKET_Connect(pRecord->szName, pRecord->nPort, (void (__stdcall*)(void*))D2QSSOCKET_ReceiveLoop, pRecord, pRecord->szLabel);
    return 1;
}

// 0x006BC5A0
void __stdcall D2QSSOCKET_ConnectAndWait(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord && !pRecord->hThread)
    {
        pRecord->bStop = 0;
        pRecord->hEvent = CreateEventA(0, 0, 0, 0);
        pRecord->hThread = CreateThread(0, 0, (unsigned long (__stdcall*)(void*))D2QSSOCKET_ConnectThreadProc, pRecord, 0, &pRecord->nThreadId);
        while (WaitForSingleObject(pRecord->hThread, 0))
        {
            Sleep(10);
        }
    }
}

// 0x006BC620
void* __stdcall D2QSSOCKET_StartConnect(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (!pRecord)
        return 0;
    if (pRecord->hThread)
        return 0;
    pRecord->bStop = 0;
    pRecord->hEvent = CreateEventA(0, 0, 0, 0);
    pRecord->hThread = CreateThread(0, 0, (unsigned long (__stdcall*)(void*))D2QSSOCKET_ConnectThreadProc, pRecord, 0, &pRecord->nThreadId);
    return pRecord->hThread;
}

// 0x006BC680
void __stdcall D2QSSOCKET_Close(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord)
        D2QSSOCKET_SetClosing(pRecord);
}

// 0x006BC6A0
D2ThreadRecord006BC5A0Strc* __stdcall D2QSSOCKET_CreateRecord(const char* szName, int nPort, const char* szLabel)
{
    D2_ASSERT(szName, 0x242);
    D2_ASSERT(strlen(szName) < 0x103, 0x243);
    D2ThreadRecord006BC5A0Strc* pRecord = (D2ThreadRecord006BC5A0Strc*)FOG_Alloc(sizeof(D2ThreadRecord006BC5A0Strc), gszSocketFile, 0x245, 0);
    if (pRecord)
    {
        memset(pRecord, 0, sizeof(D2ThreadRecord006BC5A0Strc));
        SStrCopy(pRecord->szName, szName, 0x104);
        if (szLabel)
            SStrCopy(pRecord->szLabel, szLabel, 4);
        else
            SStrCopy(pRecord->szLabel, gszUnknownUpper, 0x40);
        pRecord->nPort = nPort;
        D2QSQUEUE_InitQueue(pRecord->tQueue);
        pRecord->nHeaderSize = 2;
        pRecord->nLengthOffset = 0;
    }
    return pRecord;
}

// 0x006BC780
void __stdcall D2QSSOCKET_DestroyRecord(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord)
    {
        D2QSSOCKET_SetClosing(pRecord);
        Destroy(pRecord->tQueue);
        if (pRecord->pSafeSock && pRecord->pSafeSock->hThread)
        {
            FOG_SOCKET_Destroy(pRecord->pSafeSock);
            pRecord->pSafeSock = 0;
        }
        FOG_Free(pRecord, ".\\Src\\D2QSSocket.cpp", 636, 0);
    }
}

// 0x006BC7E0
unsigned long __stdcall D2QSSOCKET_WaitEvent(D2ThreadRecord006BC5A0Strc* pRecord, unsigned long dwMilliseconds)
{
    if (!pRecord)
        return 0;
    return WaitForSingleObject(pRecord->hEvent, dwMilliseconds);
}

// 0x006BC810
FSafeSock* __stdcall D2QSSOCKET_GetSafeSock(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (!pRecord)
        return 0;
    return pRecord->pSafeSock;
}

// 0x006BC830
void __stdcall D2QSSOCKET_SignalEvent(D2ThreadRecord006BC5A0Strc* pRecord)
{
    if (pRecord)
        SetEvent(pRecord->hEvent);
}

// 0x006BC850
void __stdcall sub_006BC850(int nUnused1)
{
}

// 0x006BC860
extern "C" int __stdcall D2QSSOCKET_Send(D2ThreadRecord006BC5A0Strc* pRecord, const char* pBuffer, int nSize)
{
    if (pRecord && pRecord->pSafeSock && pRecord->pSafeSock->bConnected != 0)
        return D2QSSOCKET_SafeSockSend(pRecord->pSafeSock, pBuffer, (unsigned short)nSize);
    return -1;
}

// 0x006BC8A0
int __stdcall D2QSSOCKET_SendPacket(D2ThreadRecord006BC5A0Strc* pRecord, const unsigned char* pData, int nSize)
{
    unsigned char buffer[0x2064];
    D2PacketHeaderStrc tHeader;
    if (!pRecord || !pRecord->pSafeSock || !pRecord->pSafeSock->bConnected)
        return -1;
    unsigned int nPayload, nTotal;
    if (pRecord->nHeaderSize == 4 && pRecord->nLengthOffset == 2)
    {
        if (!pData || (unsigned short)(nSize - 1) > 0x205E)
        {
            FOG_DisplayHalt("", sub_00408090(), 93);
            exit(-1);
        }
        nPayload = (unsigned short)nSize;
        SMemCopy(buffer + 3, pData, nPayload - 1);
        tHeader.size = (unsigned short)(nSize + 3);
        tHeader.command = *pData;
        tHeader.id = (unsigned char)pRecord->nValue120;
        SMemCopy(buffer, &tHeader, 4);
        nTotal = nPayload + 3;
    }
    else
    {
        *(unsigned short*)&tHeader = (unsigned short)(nSize + 2);
        if (*(unsigned short*)&tHeader >= 0x2064)
        {
            FOG_DisplayHalt("", sub_00408090(), 113);
            exit(-1);
        }
        SMemCopy(buffer, &tHeader, 2);
        if (!pData)
            nSize = 0;
        nPayload = (unsigned short)nSize;
        nTotal = nPayload + 2;
        if (pData && nTotal < 0x2064)
            SMemCopy(buffer + 2, pData, nPayload);
    }
    return D2QSSOCKET_Send(pRecord, (const char*)buffer, nTotal) + (nPayload - nTotal);
}
