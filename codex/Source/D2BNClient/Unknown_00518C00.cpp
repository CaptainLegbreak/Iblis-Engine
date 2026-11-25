#include "D2BNClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct BnClientInterface;

struct D2CacheHeaderStrc;

struct D2CacheHashEntryStrc;

struct D2CacheBlockEntryStrc;

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0

int __fastcall FOG_SOCKET_GetSockName(FSafeSock* pSafeSock, void* pAddress, int* pnLength); // 0x0040DF20

void __cdecl CACHE_FreeCache(); // 0x00519300

void __cdecl BNSEND_FreeChannelList(); // 0x0051AC20

void __cdecl BNSEND_FreeGamesList(); // 0x0051B210

void __cdecl BNDOWNLOAD_StopDownloads(); // 0x0051E5D0

extern "C" int __cdecl BNDOWNLOAD_HasPendingDownloads(); // 0x0051E5E0

void __cdecl BNMESSQUEUE_InitMessageQueue(); // 0x005201E0

int __cdecl BNMESSQUEUE_FreeAllMessages(); // 0x00520440

extern "C" int __cdecl BNDOWNLOAD_SetDisconnected(); // 0x00520AD0

void __cdecl sub_00521B90_ClearSrpState(); // 0x00521B90

extern BnClientInterface gtBnClientInterface; // 0x0072FAA0

extern int gdwGlobal_008818BC; // 0x008818BC

extern long volatile gnConnected; // 0x00881BF0

extern long volatile gnReceiveThreads; // 0x00881BF4

extern long volatile gnDnsDone; // 0x00881BFC

extern long volatile gnSendBusy; // 0x00881C00

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2CacheHeaderStrc
{
    char unk0x00[0x18];
    unsigned int nHashTableSize;
    unsigned int f_1C;
};

struct D2CacheBlockEntryStrc
{
    char unk0x00[0x08];
    unsigned int dwFieldA;
    unsigned int dwFieldB;
};

extern D2CacheHeaderStrc* gpCacheHeader; // 0x00881880

extern D2CacheBlockEntryStrc* gpCacheBlockTable; // 0x00881884

extern unsigned int* gpCacheTable_00881888; // 0x00881888

extern D2CacheHashEntryStrc* gpCacheHashTable; // 0x0088188C

extern const char gszH08EmitKey[];

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, void* pFileTime); // 0x006CC26C

int __cdecl sub_0051C470_CloseBNetConnection();

int gdwGlobal_008818C0; // 0x008818C0

// 0x00518C00
BnClientInterface* __cdecl sub_00518C00_GetInterface()
{
    BNMESSQUEUE_InitMessageQueue();
    return &gtBnClientInterface;
}

// 0x0051A480
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...)
{
}

// 0x0051A540
void __fastcall sub_0051A540_SetValue(int nValue)
{
    gdwGlobal_008818BC = nValue;
}

// 0x0051A550
int __cdecl BNCLIENT_GetServerToken()
{
    return gdwGlobal_008818BC;
}

// 0x0051A560
void __fastcall sub_0051A560_SetValue(int nValue)
{
    gdwGlobal_008818C0 = nValue;
}

// 0x0051BEC0
int __cdecl sub_0051BEC0_IsExpansion()
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    return FOG_IsExpansion();
}

// 0x0051C470
int __cdecl sub_0051C470_CloseBNetConnection()
{
    BNSEND_FreeChannelList();
    BNSEND_FreeGamesList();
    CACHE_FreeCache();
    BNMESSQUEUE_FreeAllMessages();
    sub_00521B90_ClearSrpState();
    InterlockedExchange(&gnDnsDone, 1);
    while (InterlockedCompareExchange(&gnReceiveThreads, 0, 0))
        Sleep(10);
    const long hSocket = InterlockedCompareExchange(&gnConnected, 0, 0);
    if (hSocket)
    {
        BNDOWNLOAD_SetDisconnected();
        while (InterlockedCompareExchange(&gnSendBusy, 0, 0))
            Sleep(10);
        if (InterlockedCompareExchange(&gnConnected, 0, hSocket) == hSocket)
            FOG_SOCKET_Destroy((FSafeSock*)hSocket);
    }
    BNDOWNLOAD_StopDownloads();
    while (BNDOWNLOAD_HasPendingDownloads())
        Sleep(10);
    if (InterlockedCompareExchange(&gnSendBusy, 0, 0))
    {
        int nWaited = 0;
        do
        {
            nWaited += 100;
            Sleep(10);
            if (nWaited > 60)
                return 0;
        }
        while (InterlockedCompareExchange(&gnSendBusy, 0, 0));
    }
    return 1;
}

// 0x0051C9B0
int __fastcall sub_0051C9B0_GetPeerName(void* pAddress, int* pnLength)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (pSocket)
        return FOG_SOCKET_GetPeerName(pSocket, pAddress, pnLength);
    return 0;
}

// 0x0051C9E0
int __fastcall sub_0051C9E0_GetSockName(void* pAddress, int* pnLength)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (pSocket)
        return FOG_SOCKET_GetSockName(pSocket, pAddress, pnLength);
    return 0;
}

#include "gen/data/Source/D2BNClient/Unknown_00518C00.inc"

// 0x00518DE0
static unsigned int sub_00518DE0_Crc32(const void* pData, unsigned int nSize)
{
    VALIDATEBEGIN;
    VALIDATE(pData || !nSize);
    D2_ASSERT(pData || !nSize, 0x91);
    VALIDATEEND;

    const unsigned char* pBytes = (const unsigned char*)pData;
    unsigned int dwCrc;
    CACHE_CRC32(dwCrc, pBytes, nSize);
    return dwCrc;
}

unsigned int __cdecl sub_M294_Emit_00518DE0(const void* pData, unsigned int nSize)
{
    return sub_00518DE0_Crc32(pData, nSize);
}

// 0x00518E60
static void sub_00518E60_DecryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    nLength >>= 2;
    while (nLength-- != 0)
    {
        dwSeed += gpCacheTable_00881888[0x400 + (dwKey & 0xFF)];
        *pData ^= dwKey + dwSeed;
        unsigned int ch = *pData++;
        dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
        dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
    }
}

// 0x00518FA0
static unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int dwSeed1 = 0x7FED7FED;
    unsigned int dwSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        char ch = (char)toupper(*szString++);
        dwSeed1 = gpCacheTable_00881888[(nHashType << 8) + ch] ^ (dwSeed1 + dwSeed2);
        dwSeed2 = ch + dwSeed1 + dwSeed2 + (dwSeed2 << 5) + 3;
    }
    return dwSeed1;
}

// build: symbol ?CACHE_FindHashEntry@* 0x00519110
static int __stdcall CACHE_FindHashEntry(unsigned int dwLocale, const char* szName)
{
    unsigned int dwIndex = sub_00518FA0_HashString(0, szName);
    unsigned int dwNameA = sub_00518FA0_HashString(1, szName);
    unsigned int dwNameB = sub_00518FA0_HashString(2, szName);
    unsigned int dwMask = gpCacheHeader->nHashTableSize - 1;
    unsigned int i = dwIndex & dwMask;
    D2CacheHashEntryStrc* pTable = gpCacheHashTable;
    D2CacheHashEntryStrc* pEntry = &pTable[i];
    unsigned int dwBlock = pEntry->dwBlockIndex;
    unsigned int dwStart = i;
    int nFound = -1;
    while (dwBlock != (unsigned int)-1)
    {
        if (pEntry->dwNameA == dwNameA && pEntry->dwNameB == dwNameB && dwBlock != (unsigned int)-2)
        {
            unsigned int dwEntryLocale = pEntry->dwLocale;
            if (dwEntryLocale == dwLocale)
            {
                return i;
            }
            if (!dwEntryLocale)
            {
                nFound = i;
            }
        }
        i = (i + 1) & dwMask;
        if (i == dwStart)
        {
            break;
        }
        pEntry = &pTable[i];
        dwBlock = pEntry->dwBlockIndex;
    }
    return nFound;
}

static void sub_H08_ClearBlockEntry(D2CacheBlockEntryStrc* pBlockTable, unsigned int nBlock)
{
    pBlockTable[nBlock].dwFieldA = 0;
    pBlockTable[nBlock].dwFieldB = 0;
}

// 0x005191D0
static void sub_005191D0_DeleteHashEntries(const char* szName)
{
    int nIndex;
    while ((nIndex = CACHE_FindHashEntry(0, szName)) != -1)
    {
        unsigned int* pBlock = &gpCacheHashTable[nIndex].dwBlockIndex;
        if (*pBlock < gpCacheHeader->f_1C)
        {
            sub_H08_ClearBlockEntry(gpCacheBlockTable, *pBlock);
        }
        *pBlock = (unsigned int)-2;
    }
}

void __cdecl sub_H08_Emit_00518E60(unsigned int nSize)
{
    sub_00518E60_DecryptBlock((unsigned int*)gpCacheHashTable, nSize, sub_00518FA0_HashString(3, gszH08EmitKey));
}

void __cdecl sub_H08_Emit_005191D0(const char* szName)
{
    sub_005191D0_DeleteHashEntries(szName);
}

unsigned __int64 gqwCacheFileTime; // 0x008818AC

unsigned long gdwCacheTimeTick; // 0x008818B4

unsigned int gnCacheTimeSeconds; // 0x008818B8

// 0x00518F30
static unsigned __int64* sub_00518F30_GetCacheFileTime(unsigned int nSeconds)
{
    if (nSeconds != gnCacheTimeSeconds || GetTickCount() != gdwCacheTimeTick)
    {
        D2SystemTimeStrc tSystemTime;
        GetSystemTime(&tSystemTime);
        SystemTimeToFileTime(&tSystemTime, &gqwCacheFileTime);
        gqwCacheFileTime += (unsigned __int64)nSeconds * 10000000;
        gnCacheTimeSeconds = nSeconds;
        gdwCacheTimeTick = GetTickCount();
    }
    return &gqwCacheFileTime;
}

unsigned int __cdecl sub_B10_Emit_00518F30()
{
    return *(unsigned int*)sub_00518F30_GetCacheFileTime(0);
}

unsigned int __cdecl sub_B10_Emit_00518FA0(const char* szName)
{
    return sub_00518FA0_HashString(0, szName) ^ sub_00518FA0_HashString(1, szName) ^ sub_00518FA0_HashString(3, szName);
}
