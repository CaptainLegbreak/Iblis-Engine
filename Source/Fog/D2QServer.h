#pragma once
// Fog queue server (QServer*.cpp): the server and client records and their list nodes.

#include "D2SysTypes.h"
#include "D2NetTypes.h"
#include "Fog.h"

struct D2QueueServerStrc;
struct D2QClientStrc;
struct D2MessageStrc;
struct D2QWriteNodeStrc;

typedef void (__fastcall* D2AddressCallback)(unsigned int, const char*, int);
typedef int (__fastcall* D2MessageCallback)(const unsigned char*, int, int*, int*, int*, int*, int, int, unsigned int);
typedef void (__fastcall* D2NewClientFn)(D2QueueServerStrc*, int, const char*, int);
typedef int (__fastcall* D2QServerHandler)(D2QueueServerStrc* pServer, char* pData, int nSize);
typedef void (__fastcall* D2QAcceptCallback)(D2QueueServerStrc* pServer, unsigned int nId, const char* szFile, int nLine);
typedef void (__fastcall* D2QRemoveCallback)(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine);

// One per-bucket client lock (0x18 bytes).
struct D2QLockStrc
{
    char cs[0x18];
};

// Connection count per address (server buckets at 0x40).
struct D2QIpCountStrc
{
    union
    {
        unsigned int nKey;                                  // 0x00
        unsigned long nAddress;
    };
    union
    {
        int nRefCount;                                      // 0x04
        int nCount;
    };
    D2QIpCountStrc* pNext;                                  // 0x08
};

// Address entry of the server's lists at 0x84C, 0x88C (free list) and 0x8AC (buckets).
struct D2QServerNodeStrc
{
    union
    {
        unsigned int nKey;                                  // 0x00
        int iKey;
    };
    union
    {
        unsigned int dwTime;                                // 0x04
        int iTime;
    };
    union
    {
        unsigned int nCount;                                // 0x08
        int iCount;
    };
    D2QServerNodeStrc* pNext;                               // 0x0C
};

struct D2QClientStrc
{
    union
    {
        unsigned int nId;                                   // 0x000
        int iId;
        void* pKey;
    };
    D2QClientStrc* pNext;                                   // 0x004
    long nRefCount;                                         // 0x008
    int bClosing;                                           // 0x00C
    union
    {
        void* hSocket;                                      // 0x010
        unsigned int nSocket;
        int iSocket;
    };
    int nSlot;                                              // 0x014
    union
    {
        unsigned int nAddress;                              // 0x018
        D2InAddrStrc tAddress;
    };
    D2QClientStrc* pNextByAddress;                          // 0x01C
    int nContext;                                           // 0x020
    union
    {
        unsigned long nTick24;                              // 0x024
        int nPending24;
    };
    union
    {
        unsigned int nPending;                              // 0x028
        int nQueued;
    };
    union
    {
        struct
        {
            D2CriticalSectionStrc tLock;                    // 0x02C
            D2QOverlappedStrc tRead;                        // 0x044
            D2QOverlappedStrc tWrite;                       // 0x05C
        };
        char cs[0x48];                                      // 0x02C
    };
    D2QWriteNodeStrc* pWriteQueue;                          // 0x074
    D2SockAddrInStrc tLocalAddr;                            // 0x078
    D2SockAddrInStrc tPeerAddr;                             // 0x088
    unsigned int nCreateTime;                               // 0x098
    unsigned int nLastTick;                                 // 0x09C
    unsigned int nTick3;                                    // 0x0A0
    unsigned int nTick4;                                    // 0x0A4
    union
    {
        unsigned int nReadBytes;                            // 0x0A8
        int iReadBytes;
    };
    unsigned long nBytesRead;                               // 0x0AC
    union
    {
        unsigned char pBuffer[0x5B4];                       // 0x0B0
        struct
        {
            unsigned char unk0x0B0[0x50C];
            D2QClientStrc* pNextQueued;                     // 0x5BC
        };
    };
};

// Accept statistics of one listener (QServerNT; 0xB0 bytes, 4-byte packed).
#pragma pack(push, 4)
struct D2QAcceptStatsStrc
{
    __int64 tTotal;                                         // 0x00
    __int64 aStages[9];                                     // 0x08
    __int64 aTimes[9];                                      // 0x50
    int nAcceptAttempts;                                    // 0x98
    int nAcceptErrors;                                      // 0x9C
    int nRejected;                                          // 0xA0
    int nPostErrors;                                        // 0xA4
    int nAccepted;                                          // 0xA8
    int nActive;                                            // 0xAC
};
#pragma pack(pop)

// One queued message (0x5C0 bytes): the server's per-queue lists at 0x870/0x874 and the free list at 0x878.
struct D2MessageStrc
{
    union
    {
        int nClient;                                        // 0x000
        int nId;
    };
    unsigned char aData[0x5B0];                             // 0x004
    int nSize;                                              // 0x5B4
    union
    {
        unsigned int dwTick;                                // 0x5B8
        unsigned long nTick;
    };
    D2MessageStrc* pNext;                                   // 0x5BC
};

// A masked-address entry: an address matches when (address & gaMaskTable[nMaskIndex]) == tAddress.
struct D2QMaskEntryStrc
{
    D2InAddrStrc tAddress;                                  // 0x00
    int nMaskIndex;                                         // 0x04
};

struct D2QueueServerStrc
{
    int bAltSend;                                           // 0x000
    unsigned int nNextId;                                   // 0x004
    unsigned int nBuckets;                                  // 0x008
    unsigned int nMask;                                     // 0x00C
    unsigned int nIpBuckets;                                // 0x010
    D2QClientStrc** ppClients;                              // 0x014
    int nBucketCount;                                       // 0x018
    union
    {
        D2CriticalSectionStrc* pLocks;                      // 0x01C
        D2QLockStrc* pClientLocks;
    };
    D2QClientStrc** ppAddressBuckets;                       // 0x020
    int nAddressBuckets;                                    // 0x024
    D2CriticalSectionStrc tAddressLock;                     // 0x028
    D2QIpCountStrc** ppIpCounts;                            // 0x040
    int nIpCountBuckets;                                    // 0x044
    D2QMaskEntryStrc aMasks[256];                           // 0x048
    int nMasks;                                             // 0x848
    D2QServerNodeStrc* pHead;                               // 0x84C
    D2QServerNodeStrc* pTail;                               // 0x850
    D2CriticalSectionStrc tLock;                            // 0x854
    int nState;                                             // 0x86C
    D2MessageStrc** ppMsgHeads;                             // 0x870
    D2MessageStrc** ppMsgTails;                             // 0x874
    union
    {
        D2MessageStrc* pFreeMessages;                       // 0x878
        D2QClientStrc* pFreeClients;
    };
    int nQueueCount;                                        // 0x87C
    int nClients;                                           // 0x880
    union
    {
        int nLimit;                                         // 0x884
        int bRunning;
    };
    unsigned int dwLastExpireTick;                          // 0x888
    D2QServerNodeStrc* pFreeRecords;                        // 0x88C
    int nRecordCount;                                       // 0x890
    D2CriticalSectionStrc tRecordLock;                      // 0x894
    D2QServerNodeStrc** ppRecords;                          // 0x8AC
    unsigned int nRecordBuckets;                            // 0x8B0
    union
    {
        D2CriticalSectionStrc tClientLock;                  // 0x8B4
        D2CriticalSectionStrc tStatsLock;
    };
    union
    {
        unsigned char aRecords[0x2DC];                      // 0x8CC
        struct
        {
            int unk0x8CC[0xB1];
            union
            {
                int nListener;                              // 0xB90
                int aListenSockets[4];
            };
        };
        struct
        {
            D2QAcceptStatsStrc aStats[3];                   // 0x8CC
            int unk0xADC[0x2C];                             // 0xADC
            int nListeners;                                 // 0xB8C
            unsigned int hListenSockets[4];                 // 0xB90
            unsigned short aPorts[4];                       // 0xBA0
        };
    };
    union
    {
        int aValues[4];                                     // 0xBA8
        int aActive[4];
    };
    D2AddressCallback pfnAddressCallback;                   // 0xBB8
    void* pfnRemoveClient;                                  // 0xBBC (FOG_10171 sets it; nothing in Fog calls it)
    D2MessageCallback pfnProcess;                           // 0xBC0
    union
    {
        D2NewClientFn pfnOnNewClient;                       // 0xBC4
        D2QAcceptCallback pfnOnAccept;
    };
    D2QRemoveCallback pfnOnRemove;                          // 0xBC8
    D2QServerHandler pfnHandler;                            // 0xBCC
    int bEnabled;                                           // 0xBD0
    void* hEvent;                                           // 0xBD4
    void* hAcceptThreads[4];                                // 0xBD8
    unsigned long aThreadIds[4];                            // 0xBE8
    union
    {
        struct
        {
            int bStop;                                      // 0xBF8
            int unk0xBFC[7];                                // 0xBFC
        };
        struct
        {
            int bStopAccept[4];                             // 0xBF8
            void* hPorts[4];                                // 0xC08
        };
    };
    union
    {
        int bInitialized;                                   // 0xC18
        int bSecondWorker;
    };
    void* aThreads2[4];                                     // 0xC1C
    unsigned long aThreadIds2[4];                           // 0xC2C
    int nSlots[4];                                          // 0xC3C

    void __thiscall ExpireEntries();                                                                 // 0x006BE700
    int __thiscall RefreshRecord(unsigned int nKey);                                                 // 0x006BE980
    int __thiscall HasMaskedKey(unsigned int nKey);                                                  // 0x006BF660
};

void __fastcall QSERVER_ReleaseClient(D2QueueServerStrc* pServer, D2QClientStrc* pClient);                    // 0x006C0360
void __fastcall QSrvCloseRemoteConnection(D2QueueServerStrc* pServer, int nKey, const char* szFile, int nLine); // 0x006C0420
int __fastcall QSERVER_CheckReconnectFlood(D2QueueServerStrc* pServer, const int* pKey);                      // 0x006BFFA0
int __fastcall QSERVERNT_SendLocal(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pBytes, int nSize); // 0x006C2C70
int __fastcall QSERVERNT_ServiceSlot(D2QueueServerStrc* pServer, int nSlot, unsigned long nTimeout);        // 0x006C2D70
int __fastcall QSERVERNT_ServiceSlots(D2QueueServerStrc* pServer, int nTimeout);                          // 0x006C30D0
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, ...);                                // 0x006BE300
unsigned int __fastcall QSERVERNT_Start(D2QueueServerStrc* pServer, int nPort);                          // 0x006C3120
