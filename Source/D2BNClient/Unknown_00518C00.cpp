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

extern "C" void __cdecl sub_00518BC0_Field00(); // 0x00518BC0
extern "C" void __cdecl BNDOWNLOAD_ConfigureLog(); // 0x00518C70
extern "C" void __cdecl BNDOWNLOAD_LogPrintf(); // 0x00518D40
extern "C" void __cdecl CACHE_FreeCachedFile(); // 0x005193C0
extern "C" void __cdecl CACHE_LoadCachedFile(); // 0x00519920
extern "C" void __cdecl sub_00519DB0_HandOnDownload(); // 0x00519DB0
extern "C" void __cdecl BNSEND_QueryAdUrl(); // 0x0051ABB0
extern "C" void __cdecl BNSEND_QueryRealms(); // 0x0051ABF0
extern "C" void __cdecl BNSEND_GetChannelList(); // 0x0051AC50
extern "C" void __cdecl BNSEND_JoinChannel(); // 0x0051ACA0
extern "C" void __cdecl BNSEND_ChatCommand(); // 0x0051AF40
extern "C" void __cdecl BNSEND_CheckAd(); // 0x0051B010
extern "C" void __cdecl BNSEND_SendStartAdvex(); // 0x0051B0E0
extern "C" void __cdecl BNSEND_SendStopAdv(); // 0x0051B1B0
extern "C" void __cdecl BNSEND_LeaveGame(); // 0x0051B1D0
extern "C" void __cdecl BNSEND_GetStartAdvResult(); // 0x0051B1F0
extern "C" void __cdecl BNSEND_GetGamesList(); // 0x0051B240
extern "C" void __cdecl BNSEND_SendNotifyJoin(); // 0x0051B320
extern "C" void __cdecl BNSEND_LogonRealm(); // 0x0051B460
extern "C" void __cdecl BNSEND_SendAdClick(); // 0x0051B6C0
extern "C" void __cdecl BNSEND_SendWriteUserData(); // 0x0051B6F0
extern "C" void __cdecl BNSEND_SendReadUserData(); // 0x0051B870
extern "C" void __cdecl BNSEND_GetReadUserDataReply(); // 0x0051B960
extern "C" void __cdecl BNSEND_SetEmail(); // 0x0051BA00
extern "C" void __cdecl BNSEND_ResetPassword(); // 0x0051BAA0
extern "C" void __cdecl BNSEND_ChangeEmail(); // 0x0051BB90
extern "C" void __cdecl BNSEND_GetGatewayAccess(); // 0x0051C180
extern "C" void __cdecl BNSEND_GetDnsPending(); // 0x0051C210
extern "C" void __cdecl BNSEND_Logon(); // 0x0051C240
extern "C" void __cdecl BNSEND_GetLogonResult(); // 0x0051C290
extern "C" void __cdecl BNSEND_CreateAccount(); // 0x0051C2D0
extern "C" void __cdecl BNSEND_GetCreateAccountResult(); // 0x0051C320
extern "C" void __cdecl BNSEND_ChangePassword(); // 0x0051C350
extern "C" void __cdecl BNSEND_GetChangePasswordResult(); // 0x0051C3B0
extern "C" void __cdecl BNDOWNLOAD_EnterChat(); // 0x0051C3E0
extern "C" void __cdecl BNSEND_LeaveChat(); // 0x0051C460
extern "C" void __cdecl sub_0051CA10(); // 0x0051CA10
extern "C" void __cdecl BNSEND_GetGatewayLetter(); // 0x0051CA20
extern "C" void __cdecl BNDOWNLOAD_IsReady(); // 0x0051CA30
extern "C" void __cdecl BNCLIENT_IsSetEmailRequested(); // 0x0051CA70
extern "C" void __cdecl BNSEND_OpenBNetConnection(); // 0x0051D1C0
extern "C" void __cdecl BNNEWS_UnloadBNetNews(); // 0x0051D750
extern "C" void __cdecl BNSEND_LoadBNetNews(); // 0x0051DBF0
extern "C" void __cdecl BNSEND_CheckCDKeys(); // 0x0051E270
extern "C" void __cdecl BNDOWNLOAD_SendGetFileTime(); // 0x0051E3D0
extern "C" void __cdecl BNCLIENT_GetDownloadPercent(); // 0x0051EA70
extern "C" void __cdecl BNSEND_GetPatchResult(); // 0x0051F2D0
extern "C" void __cdecl BNDOWNLOAD_RequestNamedFile(); // 0x00520020
extern "C" void __cdecl BNMESSQUEUE_TakeMessage(); // 0x005203B0
extern "C" void __cdecl BNMESSQUEUE_TakeState(); // 0x00520580
extern "C" void __cdecl sub_00520650(); // 0x00520650

#pragma pack(push, 1)
struct d2data_0072FAA0_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
    const void* p15;
    const void* p16;
    const void* p17;
    const void* p18;
    const void* p19;
    const void* p20;
    const void* p21;
    const void* p22;
    const void* p23;
    const void* p24;
    const void* p25;
    const void* p26;
    const void* p27;
    const void* p28;
    const void* p29;
    const void* p30;
    const void* p31;
    const void* p32;
    const void* p33;
    const void* p34;
    const void* p35;
    const void* p36;
    const void* p37;
    const void* p38;
    const void* p39;
    const void* p40;
    const void* p41;
    const void* p42;
    const void* p43;
    const void* p44;
    const void* p45;
    const void* p46;
    const void* p47;
    const void* p48;
    const void* p49;
    const void* p50;
    const void* p51;
    const void* p52;
    unsigned char b53[4];
};
#pragma pack(pop)

extern "C" struct d2data_0072FAA0_t gData_0072FAA0; // 0x0072FAA0

extern "C" struct d2data_0072FAA0_t gData_0072FAA0 = {
    (const void*)(unsigned int)&sub_00518BC0_Field00,
    (const void*)(unsigned int)&BNSEND_OpenBNetConnection,
    (const void*)(unsigned int)&BNSEND_Logon,
    (const void*)(unsigned int)&BNSEND_GetLogonResult,
    (const void*)(unsigned int)&sub_0051C470_CloseBNetConnection,
    (const void*)(unsigned int)&BNSEND_ChatCommand,
    (const void*)(unsigned int)&sub_00520650,
    (const void*)(unsigned int)&BNSEND_JoinChannel,
    (const void*)(unsigned int)&BNSEND_GetChannelList,
    (const void*)(unsigned int)&BNMESSQUEUE_TakeMessage,
    (const void*)(unsigned int)&BNMESSQUEUE_TakeState,
    (const void*)(unsigned int)&BNDOWNLOAD_SendGetFileTime,
    (const void*)(unsigned int)&BNSEND_CheckAd,
    (const void*)(unsigned int)&BNSEND_SendStartAdvex,
    (const void*)(unsigned int)&BNSEND_GetGamesList,
    (const void*)(unsigned int)&BNSEND_SendNotifyJoin,
    (const void*)(unsigned int)&BNSEND_QueryRealms,
    (const void*)(unsigned int)&BNSEND_LogonRealm,
    (const void*)(unsigned int)&BNSEND_GetPatchResult,
    (const void*)(unsigned int)&BNCLIENT_GetDownloadPercent,
    (const void*)(unsigned int)&BNDOWNLOAD_RequestNamedFile,
    (const void*)(unsigned int)&BNDOWNLOAD_EnterChat,
    (const void*)(unsigned int)&BNSEND_LeaveChat,
    (const void*)(unsigned int)&sub_0051CA10,
    (const void*)(unsigned int)&BNSEND_CreateAccount,
    (const void*)(unsigned int)&BNSEND_GetCreateAccountResult,
    (const void*)(unsigned int)&BNDOWNLOAD_IsReady,
    (const void*)(unsigned int)&BNSEND_SendAdClick,
    (const void*)(unsigned int)&BNDOWNLOAD_StopDownloads,
    (const void*)(unsigned int)&BNSEND_SendWriteUserData,
    (const void*)(unsigned int)&BNSEND_SendReadUserData,
    (const void*)(unsigned int)&BNSEND_GetReadUserDataReply,
    (const void*)(unsigned int)&BNSEND_GetDnsPending,
    (const void*)(unsigned int)&BNDOWNLOAD_LogPrintf,
    (const void*)(unsigned int)&BNDOWNLOAD_ConfigureLog,
    (const void*)(unsigned int)&BNSEND_GetStartAdvResult,
    (const void*)(unsigned int)&BNSEND_SendStopAdv,
    (const void*)(unsigned int)&BNSEND_CheckCDKeys,
    (const void*)(unsigned int)&BNSEND_GetGatewayAccess,
    (const void*)(unsigned int)&BNSEND_ChangePassword,
    (const void*)(unsigned int)&BNSEND_GetChangePasswordResult,
    (const void*)(unsigned int)&BNSEND_QueryAdUrl,
    (const void*)(unsigned int)&BNSEND_LoadBNetNews,
    (const void*)(unsigned int)&BNNEWS_UnloadBNetNews,
    (const void*)(unsigned int)&BNSEND_GetGatewayLetter,
    (const void*)(unsigned int)&BNCLIENT_IsSetEmailRequested,
    (const void*)(unsigned int)&BNSEND_SetEmail,
    (const void*)(unsigned int)&BNSEND_ResetPassword,
    (const void*)(unsigned int)&BNSEND_ChangeEmail,
    (const void*)(unsigned int)&BNSEND_LeaveGame,
    (const void*)(unsigned int)&CACHE_FreeCachedFile,
    (const void*)(unsigned int)&CACHE_LoadCachedFile,
    (const void*)(unsigned int)&sub_00519DB0_HandOnDownload,
    { 0x00 }
}; // 0x0072FAA0
#pragma comment(linker, "/alternatename:?gtBnClientInterface@@3UBnClientInterface@@A=_gData_0072FAA0")

extern unsigned int gadwCacheCrcTable[256] = {
    0, 0x77073096, 0xEE0E612C, 0x990951BA, 0x76DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3, 0xEDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988, 0x9B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
    0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7, 0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
    0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B, 0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
    0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F, 0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924, 0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
    0x76DC4190, 0x1DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x6B6B51F, 0x9FBFE4A5, 0xE8B8D433, 0x7807C9A2, 0xF00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x86D3D2D, 0x91646C97, 0xE6635C01,
    0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457, 0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
    0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB, 0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
    0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F, 0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
    0xEDB88320, 0x9ABFB3B6, 0x3B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x4DB2615, 0x73DC1683, 0xE3630B12, 0x94643B84, 0xD6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0xA00AE27, 0x7D079EB1,
    0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7, 0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
    0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B, 0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
    0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236, 0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F, 0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
    0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x26D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x5005713, 0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0xCB61B38, 0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0xBDBDF21,
    0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777, 0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
    0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB, 0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
    0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF, 0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
}; // 0x0072FB80

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
