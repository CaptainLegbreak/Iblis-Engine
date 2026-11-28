#include "Fog.h"
#include "D2QServer.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"
#include "D2SysTypes.h"
#include "FogApi.h"
#include "StormApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2QServerConfigStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value); // 0x006CC208

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szChannel, const char* szFormat, ...); // 0x00410660

extern const char gszHack[]; // 0x006FC4A8

extern const char gszHackListSizeFormat[]; // 0x006FC4B0

extern unsigned long gdwLastHackListLog; // 0x00989C34

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0


extern "C" char* __stdcall inet_ntoa(D2InAddrStrc); // 0x006B013E

extern "C" int __stdcall getpeername(unsigned int, void*, int*); // 0x006B018C

char* __stdcall sub_006B013E_InetNtoa(unsigned long dwAddress); // 0x006B013E

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

int __cdecl SYSTEM_IsPlatformNT(); // 0x00410960

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132

int __fastcall QSERVERNT_Startup(D2QueueServerStrc* pServer, int nPort); // 0x006C3360

int __fastcall QSERVER98_StartServer(D2QueueServerStrc* pServer, int nPort); // 0x006C3B50

extern "C" const char gszQServerTag[]; // 0x006FC47C

extern "C" const char gszQServerAllocated[]; // 0x006FC548

void __stdcall QSERVER_LogHackListSize(int nSize); // 0x006BE6C0

const char* __stdcall sub_006B013E_FormatIP(unsigned int nIP); // 0x006B013E


void __fastcall QSERVER_HackListAddress(D2QueueServerStrc* table, const char* file, unsigned int address, int line); // 0x006BFEA0


int __fastcall QSERVER98_Send(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize); // 0x006C3410

struct D2QueueServerStrc;

typedef int (__fastcall *D2PacketParser)(const unsigned char*,int,int*,int*,int*,int*,int,int,int);

extern const char gszQServerSource[]; // 0x006FC460

void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0

extern const char gszQServerPrefix[]; // 0x006FC47C

long __cdecl SYSTEM_GetSyncTime(); // 0x00410A80



extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC1FC

extern "C" int __stdcall WSACleanup(void); // 0x006B0138



void __fastcall QSERVERNT_StopServerThreads(D2QueueServerStrc* pServer); // 0x006C2110

void __fastcall QSERVER98_Stop(D2QueueServerStrc* pServer); // 0x006C33D0

static void sub_006BF320_FreeChain(D2QueueServerStrc* pServer);

static void sub_006BF0F0_FreeBuckets(D2QueueServerStrc* pServer);

extern const char gszLogTag_006FC4A8[]; // 0x006FC4A8

static int QSERVER_SendToClientId(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize); // 0x006C0140

static int __fastcall QSERVER_SendToClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize); // 0x006BF500

static void QSERVER_StartServer(D2QueueServerStrc* pServer, int nValue); // 0x006BF520

const char* __stdcall sub_006B013E_FormatAddress(unsigned int nAddress); // 0x006B013E

void __stdcall QSERVER_BanClient(int nClient, const char* szFile, int nLine); // 0x006C0770

extern const char gszHack[]; // 0x006FC4A8

static int gnLockCount; // 0x0074C3E0

static int gnQServerClientCapacity; // 0x0074C3E4

static int gnQServerSlotCount; // 0x0074C3E8

static int gnQServerBucketCount; // 0x0074C3EC

static int gnGlobal_00989C28; // 0x00989C28

int __stdcall FOG_10157(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize); // 0x006C03A0

extern const char gszHackCategory_006FC4A8[]; // 0x006FC4A8

extern const char gszHackListSizeFormat[]; // 0x006FC4B0

extern unsigned long gdwLastHackListLog; // 0x00989C34

static int __cdecl QSERVER_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress); // 0x006BF180

static int QSERVER_DecrementPerIpConnCount(D2QueueServerStrc* pTable, unsigned int* pKey); // 0x006BF1F0

extern unsigned int gaMaskTable[]; // 0x0074C3F0

static int __stdcall QSERVER_AccountTraffic(D2QueueServerStrc* pTable, unsigned int nBytes, D2QClientStrc* pClient); // 0x006C00A0

static int QSERVER_ExpireNodes(D2QueueServerStrc* pServer); // 0x006BF260

static void QSERVER_FreePending(D2QueueServerStrc* pServer); // 0x006BF320

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

void __cdecl sub_006BE2F0_Nop(const char* szTag, const char* szFormat, ...); // 0x006BE2F0

static void __stdcall sRemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId);

static void QSERVER_DestroyClient(D2QClientStrc* pClient); // 0x006BE650

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840

extern const char gszQServerCppFile[]; // 0x006FC460

// A second view of 0x006C0770 for QSERVER_BanAddress, which calls it with three stack arguments and the table
// already in EDI, where the static definition below takes it.
void __stdcall QSERVER_BanClient(D2QueueServerStrc* table, int client, const char* file, int line); // 0x006C0770

unsigned int gnLastHackListLog_00989C34; // 0x00989C34


static void QSERVER_FreeRecords(D2QueueServerStrc* pServer); // 0x006BF0F0

extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168

struct D2QSrvAutoLock
{
    D2CriticalSectionStrc* m_pLock;

    // 0x006BE510
    D2QSrvAutoLock(D2CriticalSectionStrc* pLock)
    {
        m_pLock = pLock;
        EnterCriticalSection(m_pLock);
    }
    // 0x006BE530
    ~D2QSrvAutoLock()
    {
        LeaveCriticalSection(m_pLock);
    }
};

// 0x006BE310
void __stdcall FOG_SetServerConfig(D2QServerConfigStrc* pConfig)
{
    gnLockCount = pConfig->nClientCapacity;
    gnQServerClientCapacity = pConfig->nClientCapacity - 1;
    gnQServerSlotCount = pConfig->nValue04;
    gnQServerBucketCount = pConfig->nValue08;
    gnGlobal_00989C28 = pConfig->nValue0C;
}

// 0x006BE350
void __stdcall FOG_StartServer(D2QueueServerStrc* pServer, unsigned int nValue)
{
    if (pServer->bAltSend)
    {
// build: symbol ?QSERVERNT_Start@* 0x006C3120
        QSERVERNT_Start(pServer, nValue);
    }
    else
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 297);
        exit(-1);
    }
}

// 0x006BE390
int __stdcall FOG_10186(D2QueueServerStrc* pServer, int nIndex, int nValue)
{
    int nOld = pServer->aValues[nIndex];
    if (nValue)
        pServer->aValues[nIndex] = nValue;
    return nOld;
}

// 0x006BE3C0
int __stdcall QSERVER_FreeAllSlots(D2QueueServerStrc* pServer)
{
    for (int i = 0; i < pServer->nQueueCount; ++i)
    {
        EnterCriticalSection(&pServer->tLock);
        D2MessageStrc* pNode = pServer->ppMsgHeads[i];
        pServer->ppMsgHeads[i] = 0;
        pServer->ppMsgTails[i] = 0;
        LeaveCriticalSection(&pServer->tLock);
        while (pNode)
        {
            D2MessageStrc* pFree = pNode;
            pNode = pNode->pNext;
            FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x1B9, 0);
        }
    }
    return 1;
}

// 0x006BE450
unsigned int __stdcall FOG_10180(D2QueueServerStrc* pServer)
{
    if (!pServer)
    {
        return 0;
    }
    return pServer->nClients;
}

// 0x006BE470
int __stdcall QSERVER_IsActive(D2QueueServerStrc* pServer)
{
    if (!pServer)
        return 0;
    return pServer->nState == 1 || pServer->nState == 2;
}

// 0x006BE4A0
void __stdcall FOG_SetMaxClientsPerGame(D2QueueServerStrc* pServer, unsigned int nCount)
{
    if (pServer)
    {
        if (nCount <= 0)
            nCount = 1;
        EnterCriticalSection(&pServer->tLock);
        pServer->nLimit = nCount;
        LeaveCriticalSection(&pServer->tLock);
    }
}

// 0x006BE4E0
unsigned long __stdcall FOG_WaitForSingleObject(D2QueueServerStrc* pServer, unsigned long dwMilliseconds)
{
    if (pServer->bAltSend)
        return 0;
    return WaitForSingleObject(pServer->hEvent, dwMilliseconds);
}

// 0x006BE540
D2QClientStrc* __fastcall QSERVER_FindClient(D2QueueServerStrc* pTable, unsigned int nKey)
{
    if (!pTable)
    {
        return 0;
    }
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2QClientStrc* pNode;
    for (pNode = pTable->ppClients[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nKey)
        {
            break;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return pNode;
}

// 0x006BE5B0
D2QClientStrc* __fastcall QSERVER_FindNodeInAnyBucket(D2QueueServerStrc* pTable, int nSocket)
{
	D2QClientStrc* pResult;
	D2QClientStrc* pNode = 0;
	for (unsigned int i = 0; i < pTable->nBuckets; ++i)
	{
		EnterCriticalSection(&pTable->pLocks[i]);
		for (pNode = pTable->ppClients[i]; pNode; pNode = pNode->pNext)
		{
			if (pNode->iSocket == nSocket)
			{
				LeaveCriticalSection(&pTable->pLocks[i]);
				pResult = pNode;
				goto Done;
			}
		}
		LeaveCriticalSection(&pTable->pLocks[i]);
	}

	pResult = pNode;
Done:
	return pResult;
}

// 0x006BE640
long __fastcall QSERVER_AddReference(D2QueueServerStrc* pServer, D2QClientStrc* pClient)
{
    return InterlockedIncrement(&pClient->nRefCount);
}

// 0x006BE650
static void QSERVER_DestroyClient(D2QClientStrc* pClient)
{
    if (pClient->pNext)
    {
        sub_006BE300_Nop("QSRV", "  ptClient->ptNextClient =  %08X", pClient->pNext);
    }
    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
    while (pNode)
    {
        D2QWriteNodeStrc* pFree = pNode;
        pNode = pNode->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x3A7, 0);
    }
    pClient->pWriteQueue = 0;
    DeleteCriticalSection((D2CriticalSectionStrc*)pClient->cs);
    FOG_Free(pClient, ".\\Src\\QServer\\QServer.cpp", 0x3AE, 0);
}

// 0x006BE6C0
void __stdcall QSERVER_LogHackListSize(int nSize)
{
    const unsigned long dwNow = GetTickCount();
    if (dwNow - gdwLastHackListLog > 2000)
    {
        LOGMANAGER_LogWritePrefixedLine(gszHack, gszHackListSizeFormat, nSize);
        gdwLastHackListLog = dwNow;
    }
}

// 0x006BE700
void D2QueueServerStrc::ExpireEntries()
{
    if (dwLastExpireTick == ~0u)
        dwLastExpireTick = GetTickCount();

    unsigned int now = GetTickCount();
    unsigned int elapsed = now - dwLastExpireTick;
    if (elapsed >= 1000)
    {
        unsigned int seconds = elapsed / 1000;
        int changed = 0;
        EnterCriticalSection(&tRecordLock);
        dwLastExpireTick = now;
        for (unsigned int i = 0; i < nRecordBuckets; ++i)
        {
            D2QServerNodeStrc* current = ppRecords[i];
            D2QServerNodeStrc* previous = 0;
            while (current)
            {
                D2QServerNodeStrc* next = current->pNext;
                if (current->nCount)
                {
                    if (current->nCount > seconds)
                        current->nCount -= seconds;
                    else
                    {
                        current->nCount = 0;
                        if (seconds < 120)
                            current->dwTime = 120 - seconds;
                        else
                            current->dwTime = 0;
                        current->dwTime += seconds;
                    }
                }
                if (current->dwTime)
                {
                    if (current->dwTime > seconds)
                        current->dwTime -= seconds;
                    else
                    {
                        if (previous)
                        {
                            previous->pNext = next;
                            current->pNext = pFreeRecords;
                            pFreeRecords = current;
                            current = previous;
                        }
                        else
                        {
                            ppRecords[i] = ppRecords[i]->pNext;
                            current->pNext = pFreeRecords;
                            pFreeRecords = current;
                            current = 0;
                        }
                        --nRecordCount;
                        changed = 1;
                    }
                }
                previous = current;
                current = next;
            }
        }
        LeaveCriticalSection(&tRecordLock);
        if (changed)
        {
            unsigned int count = nRecordCount;
            unsigned int logTick = GetTickCount();
            if (logTick - gnLastHackListLog_00989C34 > 2000)
            {
                LOGMANAGER_LogWritePrefixedLine(gszHackCategory_006FC4A8, gszHackListSizeFormat, count);
                gnLastHackListLog_00989C34 = logTick;
            }
        }
    }
}

// 0x006BE890
void __fastcall QSERVER_UnlistIP(D2QueueServerStrc* pServer, const char* szFile, unsigned int dwAddress, int nLine)
{
    if (!pServer->bEnabled)
        return;

    EnterCriticalSection(&pServer->tRecordLock);
    unsigned int nBucket = dwAddress % pServer->nRecordBuckets;
    D2QServerNodeStrc* pPrev = 0;
    D2QServerNodeStrc* pNode = pServer->ppRecords[nBucket];
    while (pNode)
    {
        D2QServerNodeStrc* pNext = pNode->pNext;
        if (pNode->nKey == dwAddress)
        {
            if (pPrev)
            {
                pPrev->pNext = pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x4D0, 0);
                pNode = pPrev;
            }
            else
            {
                pServer->ppRecords[nBucket] = pServer->ppRecords[nBucket]->pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x4D7, 0);
                pNode = 0;
            }
            --pServer->nRecordCount;
        }
        pPrev = pNode;
        pNode = pNext;
    }
    LeaveCriticalSection(&pServer->tRecordLock);

    int nSize = pServer->nRecordCount;
    unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastHackListLog > 2000)
    {
        LOGMANAGER_LogWritePrefixedLine("HACK", "[HACKLIST]  Hacklist size is %d", nSize);
        gdwLastHackListLog = dwTick;
    }
}

// 0x006BE980
int D2QueueServerStrc::RefreshRecord(unsigned int nKey)
{
    EnterCriticalSection(&tRecordLock);
    for (D2QServerNodeStrc* pNode = ppRecords[nKey % nRecordBuckets]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (pNode->iCount)
            {
                pNode->iCount = 120;
                LeaveCriticalSection(&tRecordLock);
                return 1;
            }
            LeaveCriticalSection(&tRecordLock);
            return 0;
        }
    }
    LeaveCriticalSection(&tRecordLock);
    return 0;
}

// 0x006BE9F0
int __fastcall QSERVER_CheckRecordThreshold(D2QueueServerStrc* table, const unsigned int* keyPointer)
{
    if (table->nLimit < 0) return 0;
    unsigned int key = *keyPointer;
    unsigned int index = key % table->nIpBuckets;
    EnterCriticalSection(&table->tLock);
    D2QIpCountStrc* node = table->ppIpCounts[index];
    while (node) {
        if (node->nKey == key) {
            int value = node->nRefCount;
            LeaveCriticalSection(&table->tLock);
            return value >= table->nLimit;
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->tLock);
    return 0;
}

// 0x006BEA70
int __stdcall QSERVER_CountQueuedMessages(D2QueueServerStrc* pServer, int nBucket)
{
    if (nBucket >= pServer->nQueueCount)
        return -1;

    int nCount = 0;
    EnterCriticalSection(&pServer->tLock);
    for (D2MessageStrc* pMessage = pServer->ppMsgHeads[nBucket]; pMessage; pMessage = pMessage->pNext)
        ++nCount;
    LeaveCriticalSection(&pServer->tLock);
    return nCount;
}

// 0x006BEAD0
int __stdcall FOG_10156(D2QueueServerStrc* pQueue, int nIndex, void* pDst, unsigned int nMax)
{
    if (!pQueue)
    {
        return -1;
    }
    if (nIndex >= pQueue->nQueueCount)
    {
        return -1;
    }
    if (nMax > 0x5B4)
    {
        nMax = 0x5B4;
    }

    EnterCriticalSection(&pQueue->tLock);
    D2MessageStrc* pPacket = pQueue->ppMsgHeads[nIndex];
    if (!pPacket)
    {
        LeaveCriticalSection(&pQueue->tLock);
        return -1;
    }
    pQueue->ppMsgHeads[nIndex] = pPacket->pNext;
    if (pQueue->ppMsgTails[nIndex] == pPacket)
    {
        pQueue->ppMsgTails[nIndex] = 0;
    }
    LeaveCriticalSection(&pQueue->tLock);

    const int nCopy = (pPacket->nSize + 4 > (int)nMax) ? nMax : pPacket->nSize + 4;
    memcpy(pDst, pPacket, nCopy);
    int nResult = pPacket->nSize;
    memset(pPacket, 0, sizeof(D2MessageStrc));

    EnterCriticalSection(&pQueue->tLock);
    pPacket->pNext = pQueue->pFreeMessages;
    pQueue->pFreeMessages = pPacket;
    LeaveCriticalSection(&pQueue->tLock);
    return nResult;
}

static inline int sub_006BEBC0_WaitHandle(D2QueueServerStrc* pServer, unsigned long dwMilliseconds)
{
    if (!pServer->bAltSend)
        return WaitForSingleObject(pServer->hEvent, dwMilliseconds);
    return 0;
}

// 0x006BEBC0
int __stdcall FOG_10177(D2QueueServerStrc* pServer, unsigned long dwMilliseconds)
{
    if (pServer->bAltSend)
// build: symbol ?QSERVERNT_ServiceSlots@* 0x006C30D0
        return QSERVERNT_ServiceSlots(pServer, dwMilliseconds);
    return !sub_006BEBC0_WaitHandle(pServer, dwMilliseconds);
}

// 0x006BEC00
D2QClientStrc* __fastcall QSERVER_FindClientLocked(D2QueueServerStrc* pTable, unsigned int nKey, D2CriticalSectionStrc** ppLock)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2QClientStrc* pNode = pTable->ppClients[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nKey)
        {
            *ppLock = &pTable->pLocks[nBucket];
            return pNode;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return 0;
}

// 0x006BEC70
unsigned int __stdcall QSERVER_GetClientLocalAddress(D2QueueServerStrc* pServer, unsigned int nToken)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = QSERVER_FindClientLocked(pServer, nToken, &pLock);
    unsigned int nIp = 0;
    if (pClient)
    {
        nIp = pClient->tLocalAddr.sin_addr.s_addr;
    }
    if (pLock)
    {
        LeaveCriticalSection(pLock);
    }
    return nIp;
}

// 0x006BECB0
unsigned short __stdcall QSERVER_GetClientLocalPort(D2QueueServerStrc* pServer, unsigned int nId)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = QSERVER_FindClientLocked(pServer, nId, &pLock);
    unsigned short nPort = 0;
    if (pClient)
        nPort = sub_006B019E(pClient->tLocalAddr.sin_port);
    if (pLock)
        LeaveCriticalSection(pLock);
    return nPort;
}

// 0x006BED00
int __stdcall QSERVER_GetClientPeerAddress(D2QueueServerStrc* pServer, unsigned int nId)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = QSERVER_FindClientLocked(pServer, nId, &pLock);
    int nValue = 0;
    if (pClient)
        nValue = pClient->tPeerAddr.sin_addr.s_addr;
    if (pLock)
        LeaveCriticalSection(pLock);
    return nValue;
}

// 0x006BED40
unsigned short __stdcall QSERVER_GetClientPeerPort(D2QueueServerStrc* pServer, unsigned int nId)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QClientStrc* pClient = QSERVER_FindClientLocked(pServer, nId, &pLock);
    unsigned short nPort = 0;
    if (pClient)
        nPort = sub_006B019E(pClient->tPeerAddr.sin_port);
    if (pLock)
        LeaveCriticalSection(pLock);
    return nPort;
}

// 0x006BED90
void __stdcall FOG_10159(D2QueueServerStrc* table, unsigned int key, char* output, unsigned int size)
{
    unsigned int index = table->nMask & key;
    EnterCriticalSection(&table->pLocks[index]);
    D2QClientStrc* node = table->ppClients[index];
    while (node) {
        if (node->nId == key) {
            const char* text = inet_ntoa(node->tAddress);
            SStrCopy(output, text, size);
            LeaveCriticalSection(&table->pLocks[index]);
            return;
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->pLocks[index]);
    *output = 0;
}

// 0x006BEE20
unsigned int __stdcall FOG_10158(D2QueueServerStrc* table, unsigned int key)
{
    unsigned int index = key & table->nMask;
    EnterCriticalSection(&table->pLocks[index]);
    D2QClientStrc* node = table->ppClients[index];
    while (node) {
        if (node->nId == key) {
            unsigned int value = node->nAddress;
            LeaveCriticalSection(&table->pLocks[index]);
            return value;
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->pLocks[index]);
    return 0;
}

// 0x006BEE90
unsigned int __stdcall QSERVER_GetSocketPeerAddress(D2QueueServerStrc* table, void* key)
{
    const unsigned int index = table->nMask & (unsigned int)key;
    EnterCriticalSection(&table->pLocks[index]);
    D2QClientStrc* node = table->ppClients[index];
    while (node)
    {
        if (node->pKey == key)
        {
            const unsigned int socket = node->nSocket;
            LeaveCriticalSection(&table->pLocks[index]);
            char address[16];
            int length = sizeof(address);
            getpeername(socket, address, &length);
            return *(unsigned int*)(address + 4);
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->pLocks[index]);
    return 0;
}

// 0x006BEF40
int __stdcall FOG_10161(D2QueueServerStrc* pTable, unsigned int nKey)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2QClientStrc* pNode = pTable->ppClients[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nKey)
        {
            const int nValue = pNode->iSocket;
            LeaveCriticalSection(&pTable->pLocks[nBucket]);
            return nValue;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return -1;
}

// 0x006BEFB0
void __stdcall QSERVER_HackUnlistIP(D2QueueServerStrc* pServer, unsigned long dwAddress, const char* szFile, int nLine)
{
    if (pServer->bEnabled)
    {
        LOGMANAGER_LogWritePrefixedLine(gszHack, "[HACKLIST]  IP:%s  QSHackUnlistIP() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(dwAddress), szFile, nLine);
        QSERVER_UnlistIP(pServer, szFile, dwAddress, nLine);
    }
}

// 0x006BF000
void __stdcall QSERVER_HackListSize(D2QueueServerStrc* pServer, unsigned int nFile, unsigned int nLine)
{
    if (pServer->bEnabled)
    {
        LOGMANAGER_LogWritePrefixedLine("HACK", "[HACKLIST]  Size:%s  QSHackListSize() from FILE:%s  LINE:%d", pServer->nRecordCount, nFile, nLine);
    }
}

// 0x006BF040
void __stdcall FOG_10170(D2QueueServerStrc* pServer, D2AddressCallback pfnCallback)
{
    D2_ASSERT(pServer, 0x842);
    pServer->pfnAddressCallback = pfnCallback;
}

// 0x006BF080
void __stdcall FOG_10171(D2QueueServerStrc* pServer, void* pfnCallback)
{
    pServer->pfnRemoveClient = pfnCallback;
}

// 0x006BF0A0
void __stdcall FOG_10172(void* pContainer, int nKey, int nValue)
{
    if (nKey)
    {
        D2QClientStrc* pClient = QSERVER_FindClient((D2QueueServerStrc*)pContainer, nKey);
        if (pClient)
            pClient->nContext = nValue;
    }
}

// 0x006BF0C0
int __stdcall FOG_10173(void* pContainer, int nKey)
{
    if (!nKey)
        return 0;
    D2QClientStrc* pClient = QSERVER_FindClient((D2QueueServerStrc*)pContainer, nKey);
    if (!pClient)
        return 0;
    return pClient->nContext;
}

// 0x006BF0F0
static void QSERVER_FreeRecords(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tRecordLock);
    for (unsigned int i = 0; i < pServer->nRecordBuckets; ++i)
    {
        D2QServerNodeStrc* pEntry = pServer->ppRecords[i];
        while (pEntry)
        {
            D2QServerNodeStrc* pFree = pEntry;
            pEntry = pEntry->pNext;
            FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x8BE, 0);
        }
        pServer->ppRecords[i] = 0;
    }
    pServer->nRecordCount = 0;
    LeaveCriticalSection(&pServer->tRecordLock);
}

// 0x006BF170
void __fastcall QSERVER_StopThreads(D2QueueServerStrc* pServer)
{
    if (pServer->bAltSend)
        QSERVERNT_StopServerThreads(pServer);
    else
        QSERVER98_Stop(pServer);
}

// 0x006BF180
static int __cdecl QSERVER_IncrementPerIpConnCount(D2QueueServerStrc* pServer, D2InAddrStrc* pAddress)
{
    const unsigned long nAddress = pAddress->s_addr;
    const unsigned int nBucket = nAddress % pServer->nIpBuckets;

    for (D2QIpCountStrc* pNode = pServer->ppIpCounts[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nAddress == nAddress)
        {
            ++pNode->nCount;
            return 1;
        }
    }

    D2QIpCountStrc* pNew = (D2QIpCountStrc*)FOG_Alloc(sizeof(D2QIpCountStrc), ".\\Src\\QServer\\QServer.cpp", 0x919, 0);
    pNew->nAddress = nAddress;
    pNew->nCount = 1;
    pNew->pNext = pServer->ppIpCounts[nBucket];
    pServer->ppIpCounts[nBucket] = pNew;
    return 1;
}

// 0x006BF1F0
static int QSERVER_DecrementPerIpConnCount(D2QueueServerStrc* pTable, unsigned int* pKey)
{
    const unsigned int nKey = *pKey;
    const unsigned int nBucket = nKey % pTable->nIpBuckets;
    D2QIpCountStrc* pPrev = 0;
    for (D2QIpCountStrc* pNode = pTable->ppIpCounts[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            --pNode->nRefCount;
            if (pNode->nRefCount <= 0)
            {
                if (pPrev)
                {
                    pPrev->pNext = pNode->pNext;
                }
                else
                {
                    pTable->ppIpCounts[nBucket] = pNode->pNext;
                }
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x940, 0);
            }
            return 1;
        }
        pPrev = pNode;
    }
    return 0;
}

// 0x006BF250
void __stdcall sub_006BF250_Nop(int, int, int)
{
}

// 0x006BF260
static int QSERVER_ExpireNodes(D2QueueServerStrc* pServer)
{
    const unsigned int dwTickCount = GetTickCount();
    EnterCriticalSection(&pServer->tLock);

    while (pServer->pHead)
    {
        D2QServerNodeStrc* pNode = pServer->pHead;
        if (dwTickCount - pNode->dwTime <= 15000)
        {
            break;
        }

        pServer->pHead = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x980, 0);
    }

    D2QServerNodeStrc* pPrevious = pServer->pHead;
    if (pPrevious)
    {
        for (D2QServerNodeStrc* pNode = pPrevious->pNext; pNode; )
        {
            if (dwTickCount - pNode->dwTime > 15000)
            {
                pPrevious->pNext = pNode->pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x993, 0);
                pNode = pPrevious->pNext;
            }
            else
            {
                pPrevious = pNode;
                pNode = pNode->pNext;
            }
        }
    }

    LeaveCriticalSection(&pServer->tLock);
    return 1;
}

// 0x006BF320
static void QSERVER_FreePending(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tLock);
    D2QServerNodeStrc* pNode = pServer->pHead;
    while (pNode)
    {
        D2QServerNodeStrc* pFree = pNode;
        pNode = pNode->pNext;
        FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 2480, 0);
    }
    pServer->pHead = 0;
    LeaveCriticalSection(&pServer->tLock);
}

// 0x006BF370
int __stdcall FOG_10175(D2QueueServerStrc* server,const unsigned char* buffer,int size,int id)
{
 int consumed=0;
 int unknown1=0;
 int channel=0;
 int unknown2=0;
 int result=server->pfnProcess(buffer,size,&unknown1,&consumed,&channel,&unknown2,0,0,0);
 if(result!=2 && result!=1) return 0;
 D2MessageStrc* packet;
 if(server->pFreeMessages) {
  EnterCriticalSection(&server->tLock);
  packet=server->pFreeMessages;
  if(packet) server->pFreeMessages=packet->pNext;
  else packet=(D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc),gszQServerSource,2569,0);
  LeaveCriticalSection(&server->tLock);
 } else packet=(D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc),gszQServerSource,2578,0);
 sub_006829C0_Copy(packet->aData,buffer+consumed,size-consumed);
 packet->nSize=size-consumed;
 packet->dwTick=GetTickCount();
 packet->pNext=0;
 packet->nId=id;
 if(channel<server->nQueueCount) {
  EnterCriticalSection(&server->tLock);
  D2MessageStrc* last=server->ppMsgTails[channel];
  if(!last) server->ppMsgHeads[channel]=packet;
  else last->pNext=packet;
  server->ppMsgTails[channel]=packet;
  LeaveCriticalSection(&server->tLock);
 }
 return 1;
}

// 0x006BF4E0
void __stdcall FOG_SetHackListEnabled(D2QueueServerStrc* pServer, int bEnabled)
{
    pServer->bEnabled = bEnabled;
}

// 0x006BF500
static int __fastcall QSERVER_SendToClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize)
{
    if (!pClient || pClient->bClosing) return 0;
// build: symbol ?QSERVERNT_SendLocal@* 0x006C2C70
    if (pServer->bAltSend) return QSERVERNT_SendLocal(pServer, pClient, pData, nSize);
    return QSERVER98_Send(pServer, pClient, pData, nSize);
}

// build: context sub_Emit_006BF500
// calling-convention shim (not game code)
int __stdcall sub_Emit_006BF500(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    if (!pServer)
    {
        return 0;
    }
    if ((pServer->nState == 1 || pServer->nState == 2) && pServer->pfnHandler)
    {
        return pServer->pfnHandler(pServer, pData, nSize);
    }
    D2QClientStrc* pClient = QSERVER_FindClient(pServer, nKey);
    return QSERVER_SendToClient(pServer, pClient, pData, nSize);
}

// 0x006BF520
static void QSERVER_StartServer(D2QueueServerStrc* pServer, int nValue)
{
    D2WSADataStrc tWsaData;
    if (WSAStartup(0x101, &tWsaData))
    {
        return;
    }

    if (pServer->bAltSend)
    {
        QSERVERNT_Startup(pServer, nValue);
    }
    else
    {
        QSERVER98_StartServer(pServer, nValue);
    }
}

void __fastcall sub_Emit_006BF520(D2QueueServerStrc* pServer, int nValue)
{
    QSERVER_StartServer(pServer, nValue);
    QSERVER_StartServer(pServer, nValue);
}

// 0x006BF580
int __stdcall QSERVER_CountEntries(D2QueueServerStrc* pServer)
{
    int nCount = 0;
    if (!pServer)
    {
        return 0;
    }
    EnterCriticalSection(&pServer->tLock);
    for (int i = 0; i < pServer->nQueueCount; ++i)
    {
        for (D2MessageStrc* pEntry = pServer->ppMsgHeads[i]; pEntry; pEntry = pEntry->pNext)
        {
            ++nCount;
        }
    }
    LeaveCriticalSection(&pServer->tLock);
    return nCount;
}

// 0x006BF5F0
void __stdcall FOG_10182_Return(int nUnused1)
{
}

// 0x006BF600
void __stdcall FOG_10183_Return(int nUnused1, int nUnused2)
{
}

// 0x006BF610
void __fastcall FOG_10187(D2QueueServerStrc* pServer, int nMaskIndex, unsigned int nKey)
{
    if (pServer->nMasks < 256)
    {
        for (int i = 0; i < pServer->nMasks; ++i)
        {
            if (pServer->aMasks[i].tAddress.s_addr == nKey)
            {
                return;
            }
        }
        pServer->aMasks[pServer->nMasks].tAddress.s_addr = nKey;
        pServer->aMasks[pServer->nMasks].nMaskIndex = nMaskIndex;
        ++pServer->nMasks;
    }
}

// 0x006BF660
int D2QueueServerStrc::HasMaskedKey(unsigned int nMask)
{
    const int n = nMasks;
    for (int i = 0; i < n; ++i)
    {
        const D2InAddrStrc tAddress = aMasks[i].tAddress;
        if ((gaMaskTable[aMasks[i].nMaskIndex] & nMask) == tAddress.s_addr)
            return 1;
    }
    return 0;
}

// 0x006BF6C0
int __fastcall QSERVER_CheckClientMask(D2QueueServerStrc* server, int clientId)
{
    return server->HasMaskedKey(clientId);
}

// 0x006BF6D0
void __fastcall QSERVER_CopyRecords(D2QueueServerStrc* server,D2QAcceptStatsStrc* destination,int count)
{
 EnterCriticalSection(&server->tClientLock);
 memcpy(destination,server->aStats,count*sizeof(D2QAcceptStatsStrc));
 LeaveCriticalSection(&server->tClientLock);
 for (int i=0;i<count;++i) destination[i].nActive=server->aActive[i];
}

// 0x006BF740
void __cdecl sub_006BF740_Nop()
{
}

// 0x006BF750
void __cdecl sub_006BF750_Nop()
{
}

// 0x006BF760
D2QueueServerStrc* __stdcall QSInit(int nState, int nSlots, int nPort, int bDisableNt, D2MessageCallback pfnProcess, D2NewClientFn pfnOnNewClient, D2QRemoveCallback pfnOnRemove, D2QServerHandler pfnHandler)
{
    D2WSADataStrc tWsaData;
// build: symbol ?gszQServerCppFile@* 0x006FC460
    D2QueueServerStrc* pServer = (D2QueueServerStrc*)FOG_Alloc(sizeof(D2QueueServerStrc), gszQServerCppFile, 148, 0);
    memset(pServer, 0, sizeof(D2QueueServerStrc));
    pServer->nBuckets = gnLockCount;
    pServer->nMask = gnQServerClientCapacity;
    pServer->nIpBuckets = gnQServerSlotCount;
    pServer->bInitialized = gnGlobal_00989C28;
    pServer->nBucketCount = gnLockCount;
    pServer->ppClients = (D2QClientStrc**)FOG_Alloc(gnLockCount * sizeof(D2QClientStrc*), gszQServerCppFile, 159, 0);
    memset(pServer->ppClients, 0, gnLockCount * sizeof(D2QClientStrc*));
    pServer->pLocks = (D2CriticalSectionStrc*)FOG_Alloc(gnLockCount * sizeof(D2CriticalSectionStrc), gszQServerCppFile, 162, 0);
    memset(pServer->pLocks, 0, gnLockCount * sizeof(D2CriticalSectionStrc));
    for (int i = 0; i < gnLockCount; ++i)
        InitializeCriticalSection(&pServer->pLocks[i]);
    pServer->nAddressBuckets = gnLockCount;
    pServer->ppAddressBuckets = (D2QClientStrc**)FOG_Alloc(gnLockCount * sizeof(D2QClientStrc*), gszQServerCppFile, 169, 0);
    memset(pServer->ppAddressBuckets, 0, gnLockCount * sizeof(D2QClientStrc*));
    InitializeCriticalSection(&pServer->tAddressLock);
    pServer->nIpCountBuckets = gnQServerSlotCount;
    pServer->ppIpCounts = (D2QIpCountStrc**)FOG_Alloc(gnQServerSlotCount * sizeof(D2QIpCountStrc*), gszQServerCppFile, 175, 0);
    memset(pServer->ppIpCounts, 0, gnQServerSlotCount * sizeof(D2QIpCountStrc*));
    pServer->nRecordBuckets = gnQServerBucketCount;
    pServer->ppRecords = (D2QServerNodeStrc**)FOG_Alloc(gnQServerBucketCount * sizeof(D2QServerNodeStrc*), gszQServerCppFile, 180, 0);
    memset(pServer->ppRecords, 0, gnQServerBucketCount * sizeof(D2QServerNodeStrc*));
    sub_006BE300_Nop(gszQServerTag, gszQServerAllocated, pServer);
    pServer->nClients = 0;
    pServer->pHead = 0;
    pServer->pTail = 0;
    pServer->pfnProcess = pfnProcess;
    pServer->pfnOnNewClient = pfnOnNewClient;
    pServer->pfnOnRemove = pfnOnRemove;
    pServer->pfnHandler = pfnHandler;
    pServer->dwLastExpireTick = -1;
    pServer->nRecordCount = 0;
    pServer->bEnabled = 1;
    InitializeCriticalSection(&pServer->tRecordLock);
    InitializeCriticalSection(&pServer->tClientLock);
    pServer->hListenSockets[0] = -1;
    pServer->hListenSockets[1] = -1;
    pServer->hListenSockets[2] = -1;
    pServer->hListenSockets[3] = -1;
    pServer->ppMsgHeads = (D2MessageStrc**)FOG_Alloc(nSlots * sizeof(D2MessageStrc*), gszQServerCppFile, 218, 0);
    for (int i = 0; i < nSlots; ++i)
        pServer->ppMsgHeads[i] = 0;
    pServer->ppMsgTails = (D2MessageStrc**)FOG_Alloc(nSlots * sizeof(D2MessageStrc*), gszQServerCppFile, 222, 0);
    for (int i = 0; i < nSlots; ++i)
        pServer->ppMsgTails[i] = 0;
    pServer->nQueueCount = nSlots;
    pServer->pFreeClients = 0;
    pServer->pFreeRecords = 0;
    InitializeCriticalSection(&pServer->tLock);
    if (SYSTEM_IsPlatformNT() && !bDisableNt)
        pServer->bAltSend = 1;
    else
        pServer->bAltSend = 0;
    pServer->nState = nState;
    if (nState != 1 && nState != 2)
    {
        if (!WSAStartup(0x101, &tWsaData))
        {
            if (pServer->bAltSend)
                QSERVERNT_Startup(pServer, nPort);
            else
                QSERVER98_StartServer(pServer, nPort);
        }
    }
    return pServer;
}

static
// 0x006C0770
void __stdcall QSERVER_BanClient(D2QueueServerStrc* table, int client, const char* file, int line)
{
    if (!table->bEnabled)
        return;
    unsigned int bucket = table->nMask & client;
    EnterCriticalSection(&table->pLocks[bucket]);
    D2QClientStrc* node = table->ppClients[bucket];
    unsigned int address = 0;
    while (node)
    {
        if (node->iId == client)
        {
            address = node->nAddress;
            break;
        }
        node = node->pNext;
    }
    LeaveCriticalSection(&table->pLocks[bucket]);
    QSrvCloseRemoteConnection(table, client, file, line);
    if (address)
        QSERVER_HackListAddress(table, file, address, line);
}

void __fastcall EmitBanClient(D2QueueServerStrc* table, int client, const char* file, int line)
{
    QSERVER_BanClient(table + 1, client, file, line);
}

// 0x006BFAD0
int __stdcall QSERVER_BroadcastToAllClients(D2QueueServerStrc* pServer, char* pData, int nSize)
{
    for (unsigned int i = 0; i < pServer->nBuckets; ++i)
    {
        EnterCriticalSection(&pServer->pLocks[i]);
        D2QClientStrc* pClient = pServer->ppClients[i];
        do
        {
            if (!pClient)
            {
                break;
            }

            if (!pClient->bClosing)
            {
                if (pServer->bAltSend)
                {
                    QSERVERNT_SendLocal(pServer, pClient, pData, nSize);
                }
                else
                {
                    QSERVER98_Send(pServer, pClient, pData, nSize);
                }
            }

            pClient = pClient->pNext;
        }
        while (pClient);
        LeaveCriticalSection(&pServer->pLocks[i]);
    }

    return 1;
}

// calling-convention shim (not game code)
void __fastcall sub_006BF320_Shim(D2QueueServerStrc* pServer)
{
    QSERVER_FreePending(pServer);
    FOG_Free(pServer, ".\\Src\\QServer\\QServer.cpp", 0, 0);
}

// 0x006BFB70
D2QClientStrc* __fastcall QSrvAddClient(D2QueueServerStrc* server,unsigned int socket,unsigned int address)
{
 D2QClientStrc* client=(D2QClientStrc*)FOG_Alloc(sizeof(D2QClientStrc),gszQServerSource,571,0);
 memset(client,0,sizeof(D2QClientStrc));
 EnterCriticalSection(&server->tLock);
 unsigned int id=++server->nNextId;
 LeaveCriticalSection(&server->tLock);
 client->nId=id;
 client->nSocket=socket;
 client->nAddress=address;
 client->nPending24=0;client->nQueued=0;client->pWriteQueue=0;
 client->tRead.nFlags=1;client->tWrite.nFlags=2;
 unsigned int tick=SYSTEM_GetSyncTime();
 client->nCreateTime=tick;client->nLastTick=tick;client->nTick3=tick;client->nTick4=tick;
 InitializeCriticalSection(&client->tLock);
 unsigned int bucket=id&server->nMask;
 EnterCriticalSection(&server->pLocks[bucket]);
 client->pNext=server->ppClients[bucket];
 server->ppClients[bucket]=client;
 LeaveCriticalSection(&server->pLocks[bucket]);
 EnterCriticalSection(&server->tAddressLock);
 unsigned int addressBucket=address&server->nMask;
 client->pNextByAddress=server->ppAddressBuckets[addressBucket];
 server->ppAddressBuckets[addressBucket]=client;
 LeaveCriticalSection(&server->tAddressLock);
 EnterCriticalSection(&server->tLock);
 QSERVER_IncrementPerIpConnCount(server,(D2InAddrStrc*)&address);
 InterlockedIncrement(&client->nRefCount);
 ++server->nClients;
 LeaveCriticalSection(&server->tLock);
 sub_006BE300_Nop(gszQServerPrefix,"[QSrvAddClient]  Added client %d %s on socket %d",client->nId,sub_006B013E_InetNtoa(client->nAddress),client->nSocket);
 return client;
}

// 0x006BFCD0
static void __stdcall sRemoveClient(D2QueueServerStrc* pServer, unsigned int nClientId)
{
    const unsigned int nBucket = nClientId & pServer->nMask;
    EnterCriticalSection((D2CriticalSectionStrc*)&pServer->pClientLocks[nBucket]);

    D2QClientStrc* pPrev = 0;
    D2QClientStrc* pClient = pServer->ppClients[nBucket];
    while (pClient)
    {
        if (pClient->nId == nClientId)
        {
            break;
        }
        pPrev = pClient;
        pClient = pClient->pNext;
    }

    if (!pClient)
    {
        sub_006BE2F0_Nop(&gszEmptyAssertText, "[sRemoveClient]  Couldn't remove TCLIENT id = %d", nClientId);
        sub_006BE300_Nop("QSRV", "[sRemoveClient]  Couldn't remove TCLIENT id = %d", nClientId);
        LeaveCriticalSection((D2CriticalSectionStrc*)&pServer->pClientLocks[nBucket]);
        return;
    }

    EnterCriticalSection((D2CriticalSectionStrc*)&pServer->tLock);
    --pServer->nClients;
    LeaveCriticalSection((D2CriticalSectionStrc*)&pServer->tLock);

    if (pClient != pServer->ppClients[nBucket])
    {
        pPrev->pNext = pClient->pNext;
    }
    else
    {
        pServer->ppClients[nBucket] = pClient->pNext;
    }
    pClient->pNext = 0;
    LeaveCriticalSection((D2CriticalSectionStrc*)&pServer->pClientLocks[nBucket]);

    D2_ASSERT(nClientId == pClient->nId, 0x3E0);

    unsigned int* pAddress = &pClient->nAddress;
    sub_006BE300_Nop("QSRV", "[sRemoveClient]  Remove client %d %s refcount=%d life=%d", nClientId,
        sub_006B013E_FormatAddress(*pAddress), pClient->nRefCount, SYSTEM_GetSyncTime() - pClient->nCreateTime);

    D2CriticalSectionStrc* pLock = (D2CriticalSectionStrc*)&pServer->tAddressLock;
    EnterCriticalSection(pLock);

    const unsigned int nAddressBucket = pClient->nAddress & pServer->nMask;
    D2QClientStrc** ppBucket = &pServer->ppAddressBuckets[nAddressBucket];
    D2QClientStrc* pFound = *ppBucket;
    pPrev = 0;
    while (pFound)
    {
        if (pFound->nId == nClientId)
        {
            break;
        }
        pPrev = pFound;
        pFound = pFound->pNextByAddress;
    }

    if (!pFound)
    {
        sub_006BE2F0_Nop(&gszEmptyAssertText, "[sRemoveClient]  Couldn't remove TCLIENT %d %s from IP-hash",
            nClientId, sub_006B013E_FormatAddress(*pAddress));
    }
    else
    {
        D2QClientStrc* pNext = pFound->pNextByAddress;
        if (pFound != pServer->ppAddressBuckets[nAddressBucket])
        {
            pPrev->pNextByAddress = pNext;
        }
        else
        {
            *ppBucket = pNext;
        }
    }
    LeaveCriticalSection(pLock);

    pLock = (D2CriticalSectionStrc*)&pServer->tLock;
    EnterCriticalSection(pLock);
    QSERVER_DecrementPerIpConnCount(pServer, pAddress);
    LeaveCriticalSection(pLock);
}

// 0x006BFEA0
void __fastcall QSERVER_HackListAddress(D2QueueServerStrc* pTable, const char* szFile, unsigned int nAddress, int nLine)
{
    if (!pTable->bEnabled)
        return;
    if (pTable->HasMaskedKey(nAddress))
        return;
    if (pTable->pfnAddressCallback)
        pTable->pfnAddressCallback(nAddress, szFile, nLine);
    D2CriticalSectionStrc* pLock = &pTable->tRecordLock;
    EnterCriticalSection(pLock);
    unsigned int nBucket = nAddress % pTable->nRecordBuckets;
    D2QServerNodeStrc* pRecord = pTable->ppRecords[nBucket];
    while (pRecord && pRecord->nKey != nAddress)
        pRecord = pRecord->pNext;
    if (pRecord)
    {
        pRecord->iCount = 120;
        LeaveCriticalSection(pLock);
        return;
    }
    pRecord = pTable->pFreeRecords;
    if (pRecord)
        pTable->pFreeRecords = pRecord->pNext;
    else
        pRecord = (D2QServerNodeStrc*)FOG_Alloc(sizeof(D2QServerNodeStrc), gszServerFile_006FC460, 0x4AA, 0);
    pRecord->nKey = nAddress;
    pRecord->iTime = 120;
    pRecord->iCount = 0;
    pRecord->pNext = pTable->ppRecords[nBucket];
    pTable->ppRecords[nBucket] = pRecord;
    ++pTable->nRecordCount;
    LeaveCriticalSection(pLock);
    QSERVER_LogHackListSize(pTable->nRecordCount);
}

// 0x006BFFA0
int __fastcall QSERVER_CheckReconnectFlood(D2QueueServerStrc* pServer, const int* pKey)
{
    if (pServer->nLimit < 1)
    {
        return 1;
    }

    const int nKey = *pKey;
    const unsigned int dwTickCount = GetTickCount();
    const unsigned int nMaxCount = 2 * pServer->nLimit + 3;
    QSERVER_ExpireNodes(pServer);
    EnterCriticalSection(&pServer->tLock);

    for (D2QServerNodeStrc* pNode = pServer->pHead; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (dwTickCount - pNode->dwTime < 15000)
            {
                ++pNode->nCount;
                if (pNode->nCount > nMaxCount)
                {
                    LeaveCriticalSection(&pServer->tLock);
                    return 0;
                }
            }
            else
            {
                pNode->dwTime = dwTickCount;
                pNode->nCount = 1;
            }
        }
    }

    D2QServerNodeStrc* pNew = (D2QServerNodeStrc*)FOG_Alloc(sizeof(D2QServerNodeStrc), ".\\Src\\QServer\\QServer.cpp", 0x553, 0);
    pNew->nKey = nKey;
    pNew->dwTime = dwTickCount;
    pNew->nCount = 1;
    pNew->pNext = 0;
    if (!pServer->pHead)
    {
        pServer->pHead = pNew;
    }
    else
    {
        pServer->pTail->pNext = pNew;
    }

    pServer->pTail = pNew;
    LeaveCriticalSection(&pServer->tLock);
    return 1;
}

// 0x006C00A0
static int __stdcall QSERVER_AccountTraffic(D2QueueServerStrc* pTable, unsigned int nBytes, D2QClientStrc* pClient)
{
    const unsigned long dwTick = GetTickCount();
    D2CriticalSectionStrc* pLock = &pClient->tLock;
    EnterCriticalSection(pLock);
    pClient->nPending += nBytes;
    LeaveCriticalSection(pLock);
    if (pClient->nPending > 1000)
    {
        return pTable->HasMaskedKey(pClient->nAddress) != 0;
    }

    if (dwTick - pClient->nTick24 > 1000)
    {
        EnterCriticalSection(pLock);
        pClient->nTick24 = dwTick;
        if (pClient->nPending >= 200)
        {
            pClient->nPending -= 200;
        }
        else
        {
            pClient->nPending = 0;
        }

        LeaveCriticalSection(pLock);
    }

    return 1;
}

// 0x006C0140
static int QSERVER_SendToClientId(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    if (!pServer)
    {
        return 0;
    }
    D2QClientStrc* pConnection = QSERVER_FindClient(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bAltSend)
    {
        return QSERVERNT_SendLocal(pServer, pConnection, pData, nSize);
    }
    return QSERVER98_Send(pServer, pConnection, pData, nSize);
}

static void sub_006BF320_FreeChain(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tLock);
    D2QServerNodeStrc* pNode = pServer->pHead;
    while (pNode)
    {
        D2QServerNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, gszQServerCppFile, 0x9B0, 0);
        pNode = pNext;
    }
    pServer->pHead = 0;
    LeaveCriticalSection(&pServer->tLock);
}

static void sub_006BF0F0_FreeBuckets(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tRecordLock);
    for (unsigned int i = 0; i < pServer->nRecordBuckets; ++i)
    {
        D2QServerNodeStrc* pNode = pServer->ppRecords[i];
        while (pNode)
        {
            D2QServerNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, gszQServerCppFile, 0x8BE, 0);
            pNode = pNext;
        }
        pServer->ppRecords[i] = 0;
    }
    pServer->nRecordCount = 0;
    LeaveCriticalSection(&pServer->tRecordLock);
}

// 0x006C0170
int __stdcall FOG_10152(D2QueueServerStrc* pServer, char* pData, int nSize)
{
    if (!pServer)
        return 1;

    if (pData)
        QSERVER_BroadcastToAllClients(pServer, pData, nSize);

    if (pServer->nState != 1 && pServer->nState != 2)
    {
        if (pServer->bAltSend)
            QSERVERNT_StopServerThreads(pServer);
        else
            QSERVER98_Stop(pServer);
    }

    sub_006BF320_FreeChain(pServer);
    sub_006BF0F0_FreeBuckets(pServer);
    QSERVER_FreeAllSlots(pServer);

    for (int i = 0; i < 4; ++i)
    {
        if (pServer->aListenSockets[i] != -1)
        {
            FOG_SOCKET_CloseSocket(pServer->aListenSockets[i]);
            pServer->aListenSockets[i] = -1;
        }
    }

    WSACleanup();
    DeleteCriticalSection(&pServer->tLock);
    DeleteCriticalSection(&pServer->tRecordLock);
    DeleteCriticalSection(&pServer->tClientLock);

    while (pServer->pFreeClients)
    {
        D2QClientStrc* pNext = pServer->pFreeClients->pNextQueued;
        FOG_Free(pServer->pFreeClients, gszQServerCppFile, 0x183, 0);
        pServer->pFreeClients = pNext;
    }

    while (pServer->pFreeRecords)
    {
        D2QServerNodeStrc* pNext = pServer->pFreeRecords->pNext;
        FOG_Free(pServer->pFreeRecords, gszQServerCppFile, 0x189, 0);
        pServer->pFreeRecords = pNext;
    }

    FOG_Free(pServer->ppMsgHeads, gszQServerCppFile, 0x18D, 0);
    FOG_Free(pServer->ppMsgTails, gszQServerCppFile, 0x18E, 0);
    FOG_Free(pServer->ppIpCounts, gszQServerCppFile, 0x192, 0);
    FOG_Free(pServer->ppRecords, gszQServerCppFile, 0x193, 0);
    FOG_Free(pServer->ppAddressBuckets, gszQServerCppFile, 0x195, 0);
    DeleteCriticalSection(&pServer->tAddressLock);
    FOG_Free(pServer->ppClients, gszQServerCppFile, 0x198, 0);

    for (int i = 0; i < gnLockCount; ++i)
        DeleteCriticalSection(&pServer->pLocks[i]);

    FOG_Free(pServer->pLocks, gszQServerCppFile, 0x19C, 0);
    FOG_Free(pServer, gszQServerCppFile, 0x19F, 0);
    return 1;
}

// 0x006C0360
void __fastcall QSERVER_ReleaseClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient)
{
    if (InterlockedDecrement(&pClient->nRefCount) == 0)
    {
        if (pServer->pfnOnRemove)
            pServer->pfnOnRemove(pServer, pClient->nId, ".\\Src\\QServer\\QServer.cpp", 891);
        sRemoveClient(pServer, pClient->nId);
        QSERVER_DestroyClient(pClient);
    }
}

// 0x006C03A0
int __stdcall FOG_10157(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    if (!pServer)
    {
        return 0;
    }
    if ((pServer->nState == 1 || pServer->nState == 2) && pServer->pfnHandler)
    {
        return pServer->pfnHandler(pServer, pData, nSize);
    }
    D2QClientStrc* pConnection = QSERVER_FindClient(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bAltSend)
    {
        return QSERVERNT_SendLocal(pServer, pConnection, pData, nSize);
    }
    return QSERVER98_Send(pServer, pConnection, pData, nSize);
}

// 0x006C0420
void __fastcall QSrvCloseRemoteConnection(D2QueueServerStrc* pServer, int nKey, const char* szFile, int nLine)
{
    D2QSrvAutoLock tLock(&pServer->tLock);

    D2QClientStrc* pConnection = QSERVER_FindClient(pServer, nKey);
    if (!pConnection)
        return;

    EnterCriticalSection(&pConnection->tLock);
    if (pConnection->bClosing)
    {
        LeaveCriticalSection(&pConnection->tLock);
        return;
    }

    pConnection->bClosing = 1;
    int nResult = FOG_SOCKET_CloseSocket(pConnection->nSocket);
    pConnection->nSocket = (unsigned int)-1;
    LeaveCriticalSection(&pConnection->tLock);

    if (nResult)
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "[QSrvCloseRemoteConnection] *** closesocket() err = %d ***", WSAGetLastError());

    QSERVER_ReleaseClient(pServer, pConnection);
    if (nResult == -1)
        WSAGetLastError();
}

// 0x006C0530
void __stdcall QSERVER_HackListClient(D2QueueServerStrc* pTable, int nClient, const char* szFile, int nLine)
{
    if (!pTable->bEnabled) return;
    unsigned int nBucket = pTable->nMask & nClient;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2QClientStrc* pNode = pTable->ppClients[nBucket];
    while (pNode && pNode->iId != nClient)
        pNode = pNode->pNext;
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    if (!pNode)
    {
        LOGMANAGER_LogWritePrefixedLine(gszLogTag_006FC4A8, "[HACKLIST]  Couldn't hacklist client %d (closed) from FILE:%s  LINE:%d", nClient, szFile, nLine);
        return;
    }
    unsigned int nAddress = pNode->nAddress;
    LOGMANAGER_LogWritePrefixedLine(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackList() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(nAddress), szFile, nLine);
    QSrvCloseRemoteConnection(pTable, nClient, szFile, nLine);
    QSERVER_HackListAddress(pTable, szFile, nAddress, nLine);
}

// 0x006C0600
void __stdcall QSERVER_HackListIP(D2QueueServerStrc* table, unsigned int ip, const char* file, int line)
{
    if (!table->bEnabled) return;
    unsigned int bucket = table->nMask & ip;
    EnterCriticalSection(&table->tAddressLock);
    D2QClientStrc* node = table->ppAddressBuckets[bucket];
    while (node && node->nAddress != ip) node = node->pNextByAddress;
    LeaveCriticalSection(&table->tAddressLock);
    if (node) QSrvCloseRemoteConnection(table, node->iId, file, line);
    else LOGMANAGER_LogWritePrefixedLine(gszLogTag_006FC4A8, "[HACKLIST]  Client %s is already closed", sub_006B013E_InetNtoa(ip));
    LOGMANAGER_LogWritePrefixedLine(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackListIP() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(ip), file, line);
    QSERVER_HackListAddress(table, file, ip, line);
}

// 0x006C06B0
void __stdcall FOG_10165(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine)
{
    QSrvCloseRemoteConnection(pServer, nClientId, szFile, nLine);
}

// 0x006C06D0
void __stdcall QSERVER_DisconnectIP(D2QueueServerStrc* pServer, unsigned int nIP, const char* pFile, int nLine)
{
    unsigned int nBucket = pServer->nMask & nIP;
    EnterCriticalSection(&pServer->tAddressLock);
    D2QClientStrc* pNode = pServer->ppAddressBuckets[nBucket];
    while (pNode)
    {
        if (pNode->nAddress == nIP)
            break;
        pNode = pNode->pNextByAddress;
    }
    LeaveCriticalSection(&pServer->tAddressLock);
    if (pNode)
        QSrvCloseRemoteConnection(pServer, pNode->iId, pFile, nLine);
    else
        LOGMANAGER_LogWritePrefixedLine(gszHack, "[HACKLIST]  Client %s is already closed", sub_006B013E_FormatIP(nIP));
    LOGMANAGER_LogWritePrefixedLine(gszHack, "[HACKLIST]  IP:%s  QSDisconnectIP() from FILE:%s  LINE:%d", sub_006B013E_FormatIP(nIP), pFile, nLine);
}

// calling-convention shim (not game code)
void __stdcall shim_9(D2QueueServerStrc* pServer)
{
    QSERVER_FreeRecords(pServer);
}

// build: context sub_CallSite_SendToKey
// calling-convention shim (not game code)
int __stdcall sub_CallSite_SendToKey(D2QueueServerStrc* pServer, unsigned int nKey, char* pData, int nSize)
{
    return QSERVER_SendToClientId(pServer, nKey, pData, nSize);
}

// 0x006C0800
int __fastcall QSERVER_BanAddress(D2QueueServerStrc* pServer, unsigned int* pAddress, const char* szFile, int nLine)
{
    unsigned int nAddress = *pAddress;
    unsigned int nBucket = pServer->nMask & nAddress;
    EnterCriticalSection(&pServer->tAddressLock);
    D2QClientStrc* pNode = pServer->ppAddressBuckets[nBucket];
    while (pNode && pNode->nAddress != nAddress)
        pNode = pNode->pNextByAddress;
    LeaveCriticalSection(&pServer->tAddressLock);
    if (pNode && !pServer->HasMaskedKey(pNode->nAddress))
    {
        LOGMANAGER_LogWritePrefixedLine(gszHack, "[HACKLIST]  Client %d at %s banned via QSBanByAddr()", pNode->iId, sub_006B013E_FormatAddress(*pAddress));
        QSERVER_BanClient(pNode->iId, gszServerFile_006FC460, 0x584);
    }
    return 1;
}

// 0x006C08A0
void __fastcall QSERVER_ProcessReceived(D2QueueServerStrc* server, D2QClientStrc* client)
{
    int start = 0, consumed = 0, queue = 0, charge = 0;
    while (server->pfnProcess) {
        EnterCriticalSection(&client->tLock);
        int count = client->iReadBytes;
        LeaveCriticalSection(&client->tLock);
        int result = server->pfnProcess(client->pBuffer, count, &consumed, &start, &queue, &charge, client->iId, client->nContext, client->nAddress);
        switch (result) {
        case 2:
            if (server->bEnabled && !QSERVER_AccountTraffic(server, charge, client)) {
                LOGMANAGER_LogWritePrefixedLine(gszHack, "[HACKLIST]  User at %s banned due to sQSSpamCheck in QSrvProcessMsg", sub_006B013E_InetNtoa(client->nAddress));
                QSERVER_BanClient(server, client->iId, gszQServerCppFile, 0x649);
                return;
            }
            break;
        case 3: return;
        case 4:
            LOGMANAGER_LogWritePrefixedLine(gszHack, "[HACKLIST]  User at %s banned due to PACKET_INVALID in QSrvProcessMsg", sub_006B013E_InetNtoa(client->nAddress));
            QSERVER_BanClient(server, client->iId, gszQServerCppFile, 0x635);
            return;
        }
        if (result != 5) {
            D2MessageStrc* message;
            if (server->pFreeMessages) {
                EnterCriticalSection(&server->tLock);
                message = server->pFreeMessages;
                if (message) server->pFreeMessages = message->pNext;
                else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszQServerCppFile, 0x664, 0);
                LeaveCriticalSection(&server->tLock);
            } else message = (D2MessageStrc*)FOG_Alloc(sizeof(D2MessageStrc), gszQServerCppFile, 0x66D, 0);
            int size = consumed - start;
            if (size > 0) {
                EnterCriticalSection(&client->tLock);
                memcpy(message->aData, client->pBuffer + start, size);
                LeaveCriticalSection(&client->tLock);
            } else *(unsigned char*)message = 0;
            message->nSize = size;
            message->nTick = GetTickCount();
            message->pNext = 0;
            message->nClient = client->iId;
            D2_ASSERT(queue < server->nQueueCount, 0x6A1);
            EnterCriticalSection(&server->tLock);
            D2MessageStrc* tail = server->ppMsgTails[queue];
            if (!tail) server->ppMsgHeads[queue] = message;
            else tail->pNext = message;
            server->ppMsgTails[queue] = message;
            LeaveCriticalSection(&server->tLock);
        }
        EnterCriticalSection(&client->tLock);
        client->iReadBytes -= consumed;
        D2_ASSERT(client->iReadBytes + consumed <= 0x5B4, 0x6AD);
        memmove(client->pBuffer, client->pBuffer + consumed, client->iReadBytes);
        LeaveCriticalSection(&client->tLock);
        start = 0; consumed = 0; queue = 0; charge = 0;
    }
}

extern "C" const char gData_006FC548[44] = "[QSInit]       Allocated TQSERVER = 0x%08X"; // 0x006FC548
#pragma comment(linker, "/alternatename:_gszQServerAllocated=_gData_006FC548")

extern int gnLockCount = 16; // 0x0074C3E0

extern int gnQServerClientCapacity = 15; // 0x0074C3E4

extern int gnQServerSlotCount = 17; // 0x0074C3E8

extern int gnQServerBucketCount = 1; // 0x0074C3EC

unsigned int gaMaskTable[33] = { // 0x0074C3F0
    0x00000000, 0x00000080, 0x000000C0, 0x000000E0, 0x000000F0, 0x000000F8, 0x000000FC, 0x000000FE,
    0x000000FF, 0x000080FF, 0x0000C0FF, 0x0000E0FF, 0x0000F0FF, 0x0000F8FF, 0x0000FCFF, 0x0000FEFF,
    0x0000FFFF, 0x0080FFFF, 0x00C0FFFF, 0x00E0FFFF, 0x00F0FFFF, 0x00F8FFFF, 0x00FCFFFF, 0x00FEFFFF,
    0x00FFFFFF, 0x80FFFFFF, 0xC0FFFFFF, 0xE0FFFFFF, 0xF0FFFFFF, 0xF8FFFFFF, 0xFCFFFFFF, 0xFEFFFFFF,
    0xFFFFFFFF
};
