#include "Fog.h"
#include "D2GameTypes.h"
#include "D2Win32System.h"
#include "D2Win32OsVersion.h"
#include "FogApi.h"


struct D2TimeStampStrc
{
    long nTime;
    unsigned long nTick;
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);                            // 0x006CC268
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6

// 0x00410790
static __inline long __cdecl time(long* pTime)
{
    return _time32(pTime);
}
void __fastcall SYSTEM_AtomicStore64(void* pDest, const void* pSource);                               // 0x004107B0
void __fastcall SYSTEM_AtomicRead64(void* pDest, const void* pSource);                                // 0x004107D0
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC1FC
D2CriticalSectionStrc gtTimeLock;                                                                   // 0x0075E880
D2TimeStampStrc gtTimeBase;                                                                        // 0x0075E878

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270
extern "C" const char gszKernel32[]; // 0x006CD6E4
typedef int (__stdcall* D2GetDiskFreeSpaceExFn)(const char* szDirectory, unsigned __int64* pnFreeToCaller, unsigned __int64* pnTotal, unsigned __int64* pnTotalFree);

// 0x004109D0
void __cdecl SYSTEM_InitTimeBase()
{
    InitializeCriticalSection(&gtTimeLock);
    __int64 nShared = 0;
    __int64 nTest = 666;
    __int64 nRead = -1;
    SYSTEM_AtomicStore64(&nShared, &nTest);
    SYSTEM_AtomicRead64(&nRead, &nShared);
    D2_ASSERT(nRead == 666, 0x3C);
    D2TimeStampStrc tNow;
    tNow.nTime = time(0);
    tNow.nTick = GetTickCount();
    SYSTEM_AtomicStore64(&gtTimeBase, &tNow);
}

// 0x00410A80
long __cdecl SYSTEM_GetSyncTime()
{
    const unsigned long nTick = GetTickCount();
    D2TimeStampStrc tBase;
    SYSTEM_AtomicRead64(&tBase, &gtTimeBase);
    if (nTick - tBase.nTick > 30000)
    {
        const int nPriority = GetThreadPriority(GetCurrentThread());
        if (nPriority != 0x7FFFFFFF)
        {
            SetThreadPriority(GetCurrentThread(), nPriority);
        }
        D2TimeStampStrc tNow;
        tNow.nTime = time(0);
        tNow.nTick = GetTickCount();
        SYSTEM_AtomicStore64(&gtTimeBase, &tNow);
    }
    return (nTick - tBase.nTick) / 1000 + tBase.nTime;
}



extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus); // 0x006CC1F4
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo); // 0x006CC1F8
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

// 0x004107A0
void __cdecl SYSTEM_DeleteTimeLock()
{
    DeleteCriticalSection(&gtTimeLock);
}

// 0x004107B0
__declspec(naked) void __fastcall SYSTEM_AtomicStore64(void* pDest, const void* pSource)
{
    __asm
    {
        push ebx
        push edi
        mov edi, ecx
        mov ebx, [edx]
        mov ecx, [edx + 4]
        mov eax, [edi]
        mov edx, [edi + 4]
    retry:
        lock cmpxchg8b qword ptr [edi]
        jne retry
        pop edi
        pop ebx
        ret
    }
}

// 0x004107D0
__declspec(naked) void __fastcall SYSTEM_AtomicRead64(void* pDest, const void* pSource)
{
    __asm
    {
        push ebx
        push esi
        mov esi, edx
        mov eax, ebx
        mov edx, ecx
        lock cmpxchg8b qword ptr [esi]
        mov [ecx], eax
        mov [ecx + 4], edx
        pop esi
        pop ebx
        ret
    }
}

// 0x004107F0
unsigned __int64 __cdecl SYSTEM_GetSaveDiskFreeSpace()
{
    char szPath[0x400];
    FOG_GetSavePath(szPath, sizeof(szPath));
    void* hKernel = LoadLibraryA(gszKernel32);
    if (hKernel)
    {
        D2GetDiskFreeSpaceExFn pfnGetDiskFreeSpaceEx = (D2GetDiskFreeSpaceExFn)GetProcAddress(hKernel, "GetDiskFreeSpaceExA");
        if (pfnGetDiskFreeSpaceEx)
        {
            unsigned __int64 nTotalFree = 0;
            unsigned __int64 nTotal = 0;
            unsigned __int64 nFreeToCaller = 0;
            pfnGetDiskFreeSpaceEx(szPath, &nFreeToCaller, &nTotal, &nTotalFree);
            FreeLibrary(hKernel);
            return nFreeToCaller;
        }
    }
    for (unsigned int i = 0; i < sizeof(szPath); i++)
    {
        if (szPath[i] == '\\')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    unsigned long nSectorsPerCluster = 0;
    unsigned long nBytesPerSector = 0;
    unsigned long nFreeClusters = 0;
    unsigned long nTotalClusters = 0;
    GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
    return nFreeClusters * nBytesPerSector * nSectorsPerCluster;
}
// 0x00410930
void __cdecl SYSTEM_GetMemoryStatus(D2MemoryStatusStrc* pStatus)
{
    memset(pStatus, 0, sizeof(*pStatus));
    pStatus->dwLength = sizeof(*pStatus);
    GlobalMemoryStatus(pStatus);
}

// 0x00410960
int __cdecl SYSTEM_IsPlatformNT()
{
    D2OsVersionInfoStrc versionInfo;
    memset(&versionInfo, 0, sizeof(versionInfo));
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    if (!GetVersionExA(&versionInfo))
        return 0;
    return versionInfo.dwPlatformId == 2;
}

