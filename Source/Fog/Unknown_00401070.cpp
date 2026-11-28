#include "D2Win32System.h"
#include "D2Win32SystemInfo.h"
#include "D2Win32OsVersion.h"
#include "FogApi.h"
#include "StormApi.h"
struct _iobuf;

extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC

namespace crashy
{
class Report
{
public:
    Report();
    virtual ~Report();
    bool sub_004011F0_Close();
    bool sub_00401210_IsOpen();
    int sub_00401380(const char* szFormat, ...);
    char* sub_004072A0_GetLine(int nIndex);
    int Printf(const char* szFormat, ...);
    char* sub_00407270_GetText08();
    char* sub_00407280_GetText408();
    int sub_00407290_GetLineCount();

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[1][0x400];
};
}

typedef char* va_list;

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

extern "C" int __cdecl vfprintf(_iobuf* pFile, const char* szFormat, va_list args);                         // 0x00685637


int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize);                                   // 0x0040C220





extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo); // 0x006CC1F8

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus); // 0x006CC1F4

extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(D2SystemInfoStrc* pInfo); // 0x006CC1F0

extern unsigned long gdwTotalPhys; // 0x0074D898

extern D2SystemInfoStrc gtSystemInfo; // 0x0074D8A0

int gnOsKind; // 0x0074D890

float gfOsVersion; // 0x0074D894

int gbSystemInfoCaptured; // 0x0074D88C

// build: symbol ??_7Report@crashy@@6B@ 0x006FF984
// 0x00401070
crashy::Report::Report()
{
    m_pFile = 0;
    m_nLineCount = 0;
    m_szText408[0] = 0;
    m_szText08[0] = 0;
}

// build: symbol ??_7Report@crashy@@6B@ 0x006FF984
// build: symbol ??_GReport@crashy@@UAEPAXI@Z 0x00401090
// 0x004010D0
crashy::Report::~Report()
{
    if (m_pFile)
    {
        fclose(m_pFile);
        m_pFile = 0;
    }
}

// 0x004011F0
bool crashy::Report::sub_004011F0_Close()
{
    if (m_pFile)
    {
        fclose(m_pFile);
        m_pFile = 0;
    }
    return true;
}

// 0x00401210
bool crashy::Report::sub_00401210_IsOpen()
{
    return m_pFile != 0;
}

// 0x00401380
int crashy::Report::sub_00401380(const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    return vfprintf(m_pFile, szFormat, args);
}

// 0x00407270
char* crashy::Report::sub_00407270_GetText08()
{
    return m_szText08;
}

// 0x00407280
char* crashy::Report::sub_00407280_GetText408()
{
    return m_szText408;
}

// 0x00407290
int crashy::Report::sub_00407290_GetLineCount()
{
    return m_nLineCount;
}

// 0x004072A0
char* crashy::Report::sub_004072A0_GetLine(int nIndex)
{
    return m_aszLines[nIndex];
}

// 0x004072C0
void __cdecl sub_004072C0_Empty()
{
}

// 0x004072D0
void __cdecl sub_004072D0_Empty()
{
}

// 0x004072E0
void __cdecl sub_004072E0_Empty()
{
}

// 0x004072F0
void __cdecl sub_004072F0_Empty()
{
}

// 0x00407300
void __cdecl sub_00407300_Empty()
{
}

// 0x00407540
static inline void sub_00407540_MakeAppSubdir(char* szPath, unsigned int nSize)
{
    *szPath = 0;
    if (EXCEPTIONS_GetAppPath(szPath, nSize))
    {
        SStrPack(szPath, "\\", nSize);
        FOG_CreatePathHierarchy(szPath);
    }
}

void __fastcall sub_M111_Emit_00407540(char* szPath, unsigned int nSize, int* pDone)
{
    sub_00407540_MakeAppSubdir(szPath, nSize);
    *pDone = 1;
}

// 0x00407DD0
bool __cdecl sub_00407DD0_AlwaysFalse()
{
    return false;
}

// 0x00407DE0
void __cdecl AUTOMAP_CaptureSystemInfo()
{
    D2OsVersionInfoStrc tVersion;
    D2MemoryStatusStrc tMemory;
    tVersion.dwOSVersionInfoSize = sizeof(tVersion);
    if (GetVersionExA(&tVersion))
    {
        float fMinor = (float)tVersion.dwMinorVersion;
        while (fMinor > 1.0)
        {
            fMinor = fMinor / 10.0;
        }
        gfOsVersion = (float)((float)tVersion.dwMajorVersion + fMinor / 100.0);
        switch (tVersion.dwPlatformId)
        {
        case 2:
            gnOsKind = 1;
            if (tVersion.dwMajorVersion >= 5)
            {
                if (tVersion.dwMinorVersion >= 2)
                {
                    gnOsKind = 4;
                }
                else
                {
                    gnOsKind = tVersion.dwMinorVersion < 1 ? 2 : 3;
                }
            }
            break;
        case 3:
            gnOsKind = 0;
            break;
        default:
            gnOsKind = 0;
            break;
        }
    }
    GlobalMemoryStatus(&tMemory);
    gdwTotalPhys = tMemory.dwTotalPhys;
    GetSystemInfo(&gtSystemInfo);
    gbSystemInfoCaptured = 1;
}

// 0x00407FA0
void __cdecl sub_00407FA0_Empty()
{
}

// 0x00407FB0
void __cdecl sub_00407FB0_Empty()
{
}
