#include "D2Net.h"

#include "D2NetTypes.h"
#include "StormApi.h"
#include "FogApi.h"
#include "FogApi2.h"


struct D2NetPacketRecStrc;

struct D2CriticalSectionStrc;

unsigned long __stdcall CLIENT_ConnectToHost(void* szIpAddress); // 0x0052A680


extern D2CriticalSectionStrc gCriticalSection; // 0x00882CE8

extern int gbConnected; // 0x00882D04

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230


int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList); // 0x0052B8B0

extern D2PacketBufferStrc* gpPacketBuffer; // 0x00882B34

extern D2NetPacketRecStrc* gpSystemPacketList; // 0x00882CDC

extern D2NetPacketRecStrc* gpGamePacketList; // 0x00882CE4

extern int gbConnectFinished; // 0x00882D00

int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052B820

int __fastcall SERVER_EnqueueLocalClientPacket(const unsigned char* pBuffer, unsigned short nSize); // 0x0052B690

extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132

extern "C" int __stdcall socket(int nFamily, int nType, int nProtocol); // 0x006B016E

extern "C" unsigned short __stdcall htons(unsigned short nValue); // 0x006B0156

extern "C" unsigned long __stdcall inet_addr(const char* szAddress); // 0x006B0150

extern "C" int __stdcall connect(int nSocket, const D2SockAddrInStrc* pName, int nNameLen); // 0x006B014A

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall SERVER_SendConnectionInfo(); // 0x0052B780

extern void* ghClientConnectToHostThreadHandle; // 0x00882CE0

extern unsigned long gdwThreadId; // 0x00882B30

int __stdcall sub_006BE390(void* pObject, int nArg1, int nArg2); // 0x006BE390

int __fastcall sub_006BF610(void* pObject, int nArg1, int nArg2); // 0x006BF610

int __stdcall sub_006C0170(void* pObject, const unsigned char* pData, int nSize); // 0x006C0170

int __stdcall sub_006BEAD0(void* pObject, int nMode, int nArg1, int nArg2); // 0x006BEAD0

int __stdcall sub_006BED90(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006BED90

int __stdcall sub_006BEE20(void* pObject, int nArg1); // 0x006BEE20

int __stdcall sub_006BEF40(void* pObject, int nArg1); // 0x006BEF40

static inline void CLIENT_StartConnectThread(const char* szIpAddress); // 0x0052A730

void __cdecl CLIENT_ClearConnected(); // 0x0052AAD0

typedef unsigned int size_t;

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize); // 0x006829C0

extern "C" void* __cdecl memmove(void* pDest, const void* pSource, size_t nSize); // 0x00683840

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

int __fastcall FOG_10219(unsigned char* pData); // 0x0040ADB0

int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, int nBufferSize, int* pSize); // 0x0052B920

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags); // 0x006B0174

extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet); // 0x006B0180

extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186

int __stdcall CLIENT_ParseReceiveBuffer(); // 0x0052A8D0

unsigned long gdwThreadId; // 0x00882B30

void* ghClientConnectToHostThreadHandle; // 0x00882CE0

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264

// 0x0052A610
void __fastcall CLIENT_SetConnected(int bConnected)
{
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected = bConnected;
        LeaveCriticalSection(&gCriticalSection);
    }
}

void* ghReceiveThread; // 0x00882CD8

// 0x0052A640
int __cdecl CLIENT_IsConnected()
{
    if (NET_IsLocalConnection())
    {
        return 1;
    }

    if (!gpPacketBuffer)
    {
        return 0;
    }

    EnterCriticalSection(&gCriticalSection);
    const int bConnected = gbConnected;
    LeaveCriticalSection(&gCriticalSection);

    return bConnected;
}

D2WSADataStrc gWSAData; // 0x00882B48

D2SockAddrInStrc gHostSockAddr; // 0x00882B38

D2QueueServerStrc* gpServer; // 0x00882D08

// 0x0052A680
unsigned long __stdcall CLIENT_ConnectToHost(void* szIpAddress)
{
    gbConnectFinished = 0;
    WSAStartup(0x101, &gWSAData);
    gClientSocket = socket(2, 1, 0);
    if (gClientSocket == -1)
        WSAGetLastError();
    memset(&gHostSockAddr, 0, sizeof(gHostSockAddr));
    gHostSockAddr.sin_family = 2;
    gHostSockAddr.sin_port = htons(4000);
    gHostSockAddr.sin_addr.s_addr = inet_addr(FOG_ResolveHostIPAddress((const char*)szIpAddress));
    if (connect(gClientSocket, &gHostSockAddr, sizeof(D2SockAddrInStrc)) == -1)
        gClientSocket = -1;
    return 1;
}

// 0x0052A730
static inline void CLIENT_StartConnectThread(const char* szIpAddress)
{
    ghClientConnectToHostThreadHandle = CreateThread(0, 0, CLIENT_ConnectToHost, (void*)szIpAddress, 0, &gdwThreadId);
}

// 0x0052AB00
unsigned long __stdcall CLIENT_ReceiveThreadProc(void* pArg)
{
    int bPacketAE = 0;
    unsigned int nUsed = 0;
    unsigned char pBuffer[2496];

    for (;;)
    {
        if (gbConnectFinished)
        {
            OutputDebugStringA("Client thread close #2\n");
            return 0;
        }

        D2FdSetStrc tRead;
        tRead.fd_array[0] = gClientSocket;
        tRead.fd_count = 1;

        D2TimevalStrc tTimeout;
        tTimeout.tv_sec = 0;
        tTimeout.tv_usec = 100000;

        int nResult = select(0x40, &tRead, 0, 0, &tTimeout);
        if (nResult)
        {
            if (nResult == -1)
            {
                WSAGetLastError();
                if (!NET_IsLocalConnection())
                {
                    EnterCriticalSection(&gCriticalSection);
                    gbConnected = 0;
                    LeaveCriticalSection(&gCriticalSection);
                }
            }
            else if (__WSAFDIsSet(gClientSocket, &tRead))
            {
                if (gbConnectFinished)
                {
                    OutputDebugStringA("Client thread close #3\n");
                    return 0;
                }

                EnterCriticalSection(&gCriticalSection);
                if (bPacketAE)
                {
                    nResult = recv(gClientSocket, (char*)&pBuffer[nUsed], 1460, 0);
                    if (nResult > 0)
                    {
                        nUsed += nResult;

                        int nOffset = 0;
                        while (nUsed >= 2)
                        {
                            unsigned char nFirst = pBuffer[nOffset];
                            unsigned int nSize;
                            if (nFirst < 0xF0u)
                                nSize = nFirst;
                            else
                                nSize = pBuffer[nOffset + 1] + ((nFirst & 0xF) << 8);

                            if (nUsed < nSize)
                                break;

                            const int nHeader = nSize < 0xF0 ? 1 : 2;
                            const int nBufUsed = gpPacketBuffer->nUsedBytes;
                            nResult = FOG_DecompressPacket(&gpPacketBuffer->data[nBufUsed], int(sizeof(gpPacketBuffer->data) - nBufUsed), &pBuffer[nHeader + nOffset], nSize - nHeader);
                            nUsed -= nSize;
                            nOffset += nSize;
                            if (nResult > 0)
                            {
                                gpPacketBuffer->nUsedBytes += nResult;
                                CLIENT_ParseReceiveBuffer();
                            }
                        }

                        if (nUsed && nOffset)
                            memmove(pBuffer, &pBuffer[nOffset], nUsed);
                    }
                }
                else
                {
                    nResult = recv(gClientSocket, (char*)&gpPacketBuffer->data[gpPacketBuffer->nUsedBytes], 1460, 0);
                    if (nResult > 0)
                    {
                        gpPacketBuffer->nUsedBytes += nResult;
                        bPacketAE = CLIENT_ParseReceiveBuffer();
                    }
                }
                LeaveCriticalSection(&gCriticalSection);

                if (nResult == -1)
                {
                    WSAGetLastError();
                    if (!NET_IsLocalConnection())
                    {
                        EnterCriticalSection(&gCriticalSection);
                        gbConnected = 0;
                        LeaveCriticalSection(&gCriticalSection);
                    }
                    OutputDebugStringA("Client thread close #5\n");
                    return 0;
                }

                if (!nResult)
                {
                    if (!NET_IsLocalConnection())
                    {
                        EnterCriticalSection(&gCriticalSection);
                        gbConnected = 0;
                        LeaveCriticalSection(&gCriticalSection);
                    }
                    OutputDebugStringA("Client thread close #6\n");
                    return 0;
                }
            }
        }
    }
}

// 0x0052ADC0
int __fastcall CLIENT_SendToLocalServer(void* pUnused, unsigned short nSize, const unsigned char* pBuffer)
{
    D2_ASSERT(nSize <= 0x204, 0x1C6);
    return SERVER_EnqueueLocalClientPacket(pBuffer, nSize);
}

// 0x0052AE00
static int CLIENT_SendToSocket(const unsigned char* pBuffer, int nSize)
{
    const int nSent = send(gClientSocket, (const char*)pBuffer, nSize, 0);
    if (nSent != -1)
    {
        return nSent;
    }

    WSAGetLastError();
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected = 0;
        LeaveCriticalSection(&gCriticalSection);
    }
    return 0;
}

// 0x0052A750
void __stdcall CLIENT_Initialize(int nArg, const char* szIpAddress)
{
    gpGamePacketList = 0;
    gpSystemPacketList = 0;
    InitializeCriticalSection(&gCriticalSection);
    gpPacketBuffer = (D2PacketBufferStrc*)FOG_Alloc(0x7BC, ".\\SRC\\Client.cpp", 200, 0);
    memset(gpPacketBuffer, 0, 0x7BC);
    NET_SetConnectionMode(nArg);
    if (NET_IsLocalConnection())
    {
        SERVER_SendConnectionInfo();
        return;
    }
    CLIENT_StartConnectThread(szIpAddress);
}

// 0x0052A7E0
void __cdecl CLIENT_Release()
{
    EnterCriticalSection(&gCriticalSection);

    if (gpPacketBuffer)
    {
        FOG_Free(gpPacketBuffer, ".\\SRC\\Client.cpp", 0xDA, 0);
    }

    gpPacketBuffer = 0;
    gbConnectFinished = 1;

    LeaveCriticalSection(&gCriticalSection);

    WaitForSingleObject(ghReceiveThread, 6000);

    NET_FreePacketList(&gCriticalSection, &gpSystemPacketList);
    NET_FreePacketList(&gCriticalSection, &gpGamePacketList);

    DeleteCriticalSection(&gCriticalSection);

    if (NET_IsLocalConnection())
    {
        return;
    }

    const int nResult = FOG_SOCKET_CloseSocket(gClientSocket);
    gClientSocket = -1;
    if (nResult == -1)
    {
        WSAGetLastError();
    }
}

// 0x0052A890
int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpGamePacketList, pBuffer, nBufferSize);
}

// 0x0052A8B0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpSystemPacketList, pBuffer, nBufferSize);
}

D2PacketBufferStrc* gpPacketBuffer; // 0x00882B34

D2CriticalSectionStrc gCriticalSection; // 0x00882CE8

int gbConnectFinished; // 0x00882D00

int gbConnected; // 0x00882D04

// 0x0052A8D0
int __stdcall CLIENT_ParseReceiveBuffer()
{
    int nUsedBytes = gpPacketBuffer->nUsedBytes;
    D2PacketBufferStrc* pPacketBuffer = gpPacketBuffer;
    int bResult = 0;

    if (nUsedBytes >= 1u)
    {
    do
    {
        int nSize;
        if (!SERVER_GetServerPacketSize(pPacketBuffer, nUsedBytes, &nSize))
        {
            break;
        }

        D2_ASSERT((unsigned int)nSize <= MAX_MSG_SIZE, 0x129);

        if (nSize > nUsedBytes)
        {
            break;
        }

        D2NetPacketRecStrc* pPacket = (D2NetPacketRecStrc*)FOG_Alloc(sizeof(D2NetPacketRecStrc), ".\\SRC\\Client.cpp", 0x12C, 0);
        pPacket->nPacketSize = nSize;
        pPacket->dwTickCount = 0;
        pPacket->pNext = 0;

        memcpy(pPacket->data, pPacketBuffer->data, nSize);

        if (pPacketBuffer->data[0] == 0xAF && pPacketBuffer->data[1])
        {
            bResult = 1;

            if (pPacketBuffer->data[1] == 0x81)
            {
                unsigned char abProcessed[0x100];

                const unsigned char* pSource = &pPacketBuffer->data[1];
                unsigned char* pDest = &abProcessed[1];
                int nCount = 0x80;
                do
                {
                    const unsigned char nElement = *pSource;
                    pDest[-1] = (nElement & 0xF) + 1;
                    pDest[0] = (nElement >> 4) + 1;
                    ++pSource;
                    pDest += 2;
                } while (--nCount);

                FOG_10219(abProcessed);
            }
        }
        else if (pPacketBuffer->data[0] == 0x8F)
        {
            *(unsigned long*)&pPacket->data[13] = GetTickCount();
        }

        D2NetPacketRecStrc** ppLast;
        if (pPacketBuffer->data[0] < 0xAF)
        {
            ppLast = &gpGamePacketList;
        }
        else
        {
            ppLast = &gpSystemPacketList;
        }

        while (*ppLast)
        {
            ppLast = &(*ppLast)->pNext;
        }
        *ppLast = pPacket;

        pPacketBuffer = (D2PacketBufferStrc*)((char*)pPacketBuffer + nSize);
        nUsedBytes -= nSize;
    } while (nUsedBytes >= 1u);
    }

    D2PacketBufferStrc* pEnd = gpPacketBuffer;
    pEnd->nUsedBytes = nUsedBytes;

    if (nUsedBytes && pPacketBuffer != pEnd)
    {
        memmove(pEnd, pPacketBuffer, nUsedBytes);
    }

    return bResult;
}

// 0x0052AAA0
void __cdecl CLIENT_HandleSocketError()
{
    WSAGetLastError();
    CLIENT_ClearConnected();
}

// 0x0052AAD0
void __cdecl CLIENT_ClearConnected()
{
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected = 0;
        LeaveCriticalSection(&gCriticalSection);
    }
}

// 0x0052AE50
int __stdcall CLIENT_Send(int nSize, int nFlags, void* pData)
{
    const unsigned char* pBuffer = (const unsigned char*)pData;
    if (!gpPacketBuffer)
    {
        return 0;
    }

    if (NET_IsLocalConnection())
    {
        const unsigned short nPacketSize = nSize;
        D2_ASSERT(nPacketSize <= MAX_MSG_SIZE, 0x1C6);
        return SERVER_EnqueueLocalClientPacket(pBuffer, nPacketSize);
    }

    return CLIENT_SendToSocket(pBuffer, nSize);
}

int gClientSocket = -1; // 0x00730AE0

D2NetPacketRecStrc* gpGamePacketList; // 0x00882CE4

D2NetPacketRecStrc* gpSystemPacketList; // 0x00882CDC

// 0x0052AEB0
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize)
{
    while (nBufferSize > 0)
    {
        D2NetPacketRecStrc* pPacket = (D2NetPacketRecStrc*)FOG_Alloc(sizeof(D2NetPacketRecStrc), ".\\SRC\\Client.cpp", 0x1FD, 0);

        int nSize;
        if (!SERVER_GetServerPacketSize(pBuffer, nBufferSize, &nSize))
        {
            break;
        }

        D2_ASSERT((unsigned int)nSize <= MAX_MSG_SIZE, 0x203);
        D2_ASSERT(nSize > 0, 0x204);

        memcpy(pPacket->data, pBuffer->data, nSize);

        pPacket->nPacketSize = nSize;
        pPacket->dwTickCount = GetTickCount();
        pPacket->pNext = 0;

        const unsigned char nHeader = pBuffer->data[0];
        D2NetPacketRecStrc* pLast;
        if (nHeader < 0xAF)
        {
            pLast = gpGamePacketList;
        }
        else if (nHeader < 0xB5)
        {
            pLast = gpSystemPacketList;
        }
        else
        {
            D2_ASSERT(0, 0x217);
        }

        if (!pLast)
        {
            if (nHeader < 0xAF)
            {
                gpGamePacketList = pPacket;
            }
            else if (nHeader < 0xB5)
            {
                gpSystemPacketList = pPacket;
            }
            else
            {
                D2_ASSERT(0, 0x21E);
            }
        }
        else
        {
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }
            pLast->pNext = pPacket;
        }

        pBuffer = (D2PacketBufferStrc*)((char*)pBuffer + nSize);
        nBufferSize -= nSize;
    }
}

extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E

extern "C" int __stdcall getsockname(unsigned int nSocket, void* pAddress, int* pnLength);                 // 0x006B0144



// 0x0052AFE0
void __stdcall CLIENT_GetLocalIpAddressString(char* szBuffer)
{
    D2SockAddrInStrc tAddress = {};
    int nLength = sizeof(tAddress);
    getsockname(gClientSocket, &tAddress, &nLength);
    const char* szLocalIpAddress = inet_ntoa(*(D2InAddrStrc*)&tAddress.sin_addr.s_addr);
    SStrCopy(szBuffer, szLocalIpAddress, 0x7FFFFFFF);
}

// 0x0052B050
int __cdecl CLIENT_GetConnectionStatus()
{
    if (NET_IsLocalConnection())
    {
        return 2;
    }

    if (!WaitForSingleObject(ghClientConnectToHostThreadHandle, 100))
    {
        if (gClientSocket != -1)
        {
            if (!NET_IsLocalConnection())
            {
                EnterCriticalSection(&gCriticalSection);
                gbConnected = 1;
                LeaveCriticalSection(&gCriticalSection);
            }

            ghReceiveThread = CreateThread(0, 0, CLIENT_ReceiveThreadProc, 0, 0, &gdwThreadId);
            SetThreadPriority(ghReceiveThread, 1);
            return 2;
        }
        return 0;
    }
    return 1;
}

