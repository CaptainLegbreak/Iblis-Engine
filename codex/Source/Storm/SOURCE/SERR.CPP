#include "Storm.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "stpl.h"

struct D2CriticalSectionStrc;
struct D2StormListStrc;
struct D2IdentityView;
struct PairStrc_0041C390;
struct HANDLER;

typedef int (__stdcall* SERRHANDLERPROC)(unsigned int nErrorCode, const char* szError, const char* szName, int nLine, const char* szDescription);
typedef void (__fastcall* D2ErrorReportFn)(const char*, const char*, void*, void*, int, int);

extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned long dwBytes); // 0x006CC318
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem); // 0x006CC320
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode); // 0x006CC2E4
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall LoadStringA(void* hInstance, unsigned int uId, char* buffer, int length); // 0x006CC46C
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long, unsigned long, char*, unsigned long, void*);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void*,char*,unsigned long); // 0x006CC1BC
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*,void*); // 0x006CC1CC
extern "C" __declspec(dllimport) int __stdcall FindClose(void*); // 0x006CC1C4
extern "C" __declspec(dllimport) int __stdcall IsWindow(void*); // 0x006CC474
extern "C" __declspec(dllimport) int __stdcall IsWindowVisible(void*); // 0x006CC470
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int); // 0x006CC464
extern "C" __declspec(dllimport) unsigned long __stdcall GetVersion(); // 0x006CC138
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall GetExitCodeProcess(void*,unsigned long*); // 0x006CC324
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void*,unsigned int); // 0x006CC274
extern "C" void __cdecl __debugbreak();
extern "C" int __cdecl vsprintf(char* buffer, const char* format, char* args); // 0x00682DA1
extern "C" char* __cdecl strpbrk(const char* szString, const char* szCharSet);                              // 0x00686990
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

void* __fastcall StormGetInstance();                                                                           // 0x0041BEF0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
char* __stdcall SStrChrR(const char*,char); // 0x004134D0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void* __cdecl SMsgGetDefaultWindow(); // 0x00420310

void __cdecl LockErrorState(); // 0x0041C1A0
void __cdecl UnlockErrorState(); // 0x0041C1E0
void __stdcall AddMessageSource(unsigned short wFacility); // 0x0041C0F0
void __cdecl AddDefaultMessageSources(); // 0x0041C140
void __cdecl BreakIntoDebugger(); // 0x0041C160
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void __stdcall SErrSuppressErrors(int bSuppress); // 0x0041C360
int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size);
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode);
void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail);
static const char* GetMessageText(int nIndex); // 0x0041C170
static int __stdcall FormatTypeName(const char* szName, char* szOut, unsigned int nSize); // 0x0041C1F0

extern "C" const char gszCloseParen_006CF324[]; // 0x006CF324
extern "C" const char gszFormatName[]; // 0x006FFC58
extern const char* gpszMessageFallback_006CF2F4[]; // 0x006CF2F4
extern const char gszEmptyAssertText; // 0x006CC837
extern const char gszDiagnosticFormat_006CF330[]; // 0x006CF330
extern const char gszErrorFormat_006CF33C[]; // 0x006CF33C
extern const char gszLineFormat_006CF34C[]; // 0x006CF34C
extern int gnErrorOutputMode_0077909C; // 0x0077909C

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2IdentityView
{
    D2StormLinkStrc link;
};

struct PairStrc_0041C390
{
    int nFirst;
    int nSecond;
};

struct HANDLER : TSLinkedNode<HANDLER>
{
    SERRHANDLERPROC pfnHandler;                             // 0x08

    ~HANDLER()
    {
    }
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2FindDataStrc { unsigned int dwAttributes; unsigned int timesAndSize[10]; char szFileName[260]; char szAlternateName[16]; };

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

int (__stdcall* gpfnStormNotify_007790B8)(int nArg);                                                        // 0x007790B8
void* gpStormOwnerA_007790C0; // 0x007790C0
void* gpStormOwnerB_007790C4;                                                                               // 0x007790C4
unsigned long gdwStormOwnerThread_007790C8;                                                                 // 0x007790C8
D2CriticalSectionStrc gErrorStateLock_007790CC; // 0x007790CC
int gbErrorActive_007790E4; // 0x007790E4
D2StormMsgSourceStrc* gpStormMsgSources_007790E8;                                                           // 0x007790E8
int gnInitialized_007790EC; // 0x007790EC
int gbErrorSuppress_007790F0; // 0x007790F0
unsigned long gdwStormLastError_007790F4; // 0x007790F4
D2ErrorReportFn gpErrorReport_007790F8; // 0x007790F8
char gszMessageBuffer_00779100[256]; // 0x00779100
unsigned long gdwDebugMemory_00779200; // 0x00779200
int gbDebugMemoryLoaded_00779204; // 0x00779204

// build: symbol ??__EgHandlerList_00708420@@YAXXZ 0x006CA8A0
// build: symbol ??__FgHandlerList_00708420@@YAXXZ 0x006CB2A0
TSList<HANDLER> gHandlerList_00708420; // 0x00708420

// build: symbol ??_R0?AUHANDLER@@@8 0x0070842C
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol ?Next@?$TSLink@UHANDLER@@@@QAEPAUHANDLER@@XZ 0x0041C370
// build: symbol ?RawNext@?$TSLink@UHANDLER@@@@QAEPAUHANDLER@@XZ 0x0041C380
// build: symbol ?NextLink@?$TSLink@UHANDLER@@@@QAEPAU1@H@Z 0x0041C3A0
// build: symbol ?Unlink@?$TSLink@UHANDLER@@@@QAEXXZ 0x0041C3D0
// build: symbol ?Head@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEPAUHANDLER@@XZ 0x0041C4E0
// build: symbol ??0?$TSLink@UHANDLER@@@@QAE@XZ 0x0041C4F0
// build: symbol ?Link@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEPAU?$TSLink@UHANDLER@@@@PBUHANDLER@@@Z 0x0041C560
// build: symbol ?LinkNode@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEXPAUHANDLER@@I0@Z 0x0041C580
// build: symbol ?Next@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEPAUHANDLER@@PBU2@@Z 0x0041C630
// build: symbol ??1?$TSLink@UHANDLER@@@@QAE@XZ 0x0041C650
// build: symbol ?UnlinkNode@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEXPAUHANDLER@@@Z 0x0041C690
// build: symbol ?RawNext@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEPAUHANDLER@@PBU2@@Z 0x0041C700
// build: symbol ??0?$TSLinkedNode@UHANDLER@@@@QAE@XZ 0x0041C720
// build: symbol ??1?$TSLinkedNode@UHANDLER@@@@QAE@XZ 0x0041C730
// build: symbol ?UnlinkAll@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEXXZ 0x0041C770
// build: symbol ??1?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAE@XZ 0x0041C7B0
// build: symbol ??0HANDLER@@QAE@XZ 0x0041C7F0
// build: symbol ??1HANDLER@@QAE@XZ 0x0041C800
// build: symbol ?NewNode@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEPAUHANDLER@@III@Z 0x0041C840
// build: symbol ??_GHANDLER@@QAEPAXI@Z 0x0041C8A0
// build: symbol ?Clear@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEXXZ 0x0041C9C0
// build: symbol ?DeleteNode@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEPAUHANDLER@@PAU2@@Z 0x0041CA10
template HANDLER* TSLink<HANDLER>::Next();
template HANDLER* TSLink<HANDLER>::RawNext();
template TSLink<HANDLER>* TSLink<HANDLER>::NextLink(int);
template void TSLink<HANDLER>::Unlink();
template HANDLER* TSList<HANDLER>::Head();
template TSLink<HANDLER>::TSLink();
template TSLink<HANDLER>::~TSLink();
template TSLink<HANDLER>* TSList<HANDLER>::Link(const HANDLER*);
template void TSList<HANDLER>::LinkNode(HANDLER*, unsigned int, HANDLER*);
template HANDLER* TSList<HANDLER>::Next(const HANDLER*);
template void TSList<HANDLER>::UnlinkNode(HANDLER*);
template HANDLER* TSList<HANDLER>::RawNext(const HANDLER*);
template void TSList<HANDLER>::UnlinkAll();
template TSList<HANDLER>::~TSList();
template HANDLER* TSList<HANDLER>::NewNode(unsigned int, unsigned int, unsigned int);
template void TSList<HANDLER>::Clear();
template HANDLER* TSList<HANDLER>::DeleteNode(HANDLER*);

// A link-holding piece of the run that matches no stpl.h member.
struct sub_0041C500
{
    D2StormLinkStrc tLink;

    ~sub_0041C500();
};

// 0x0041C500
sub_0041C500::~sub_0041C500()
{
    tLink.Unlink();
}

// 0x0041C0D0
char* __cdecl sub_0041C0D0_StrPbrk(const char* szString, const char* szCharSet)
{
    return strpbrk(szString, szCharSet);
}

// 0x0041C0E0
void __fastcall SetErrorReportCallback(void* pCallback)
{
    gpErrorReport_007790F8 = (D2ErrorReportFn)pCallback;
}

// 0x0041C0F0
void __stdcall AddMessageSource(unsigned short wFacility)
{
    D2StormMsgSourceStrc** ppSource = &gpStormMsgSources_007790E8;
    while (*ppSource)
        ppSource = &(*ppSource)->pNext;
    *ppSource = (D2StormMsgSourceStrc*)HeapAlloc(GetProcessHeap(), 4, sizeof(D2StormMsgSourceStrc));
    (*ppSource)->wFacility = wFacility;
    (*ppSource)->hModule = StormGetInstance();
    (*ppSource)->pNext = 0;
}

// 0x0041C140
void __cdecl AddDefaultMessageSources()
{
    AddMessageSource(0x510);
    AddMessageSource(0x876);
    AddMessageSource(0x878);
}

// 0x0041C160
void __cdecl BreakIntoDebugger()
{
    __debugbreak();
}

// 0x0041C170
static const char* GetMessageText(int nIndex)
{
    if (LoadStringA(StormGetInstance(), nIndex + 0x5100, gszMessageBuffer_00779100, 256))
        return gszMessageBuffer_00779100;
    return gpszMessageFallback_006CF2F4[nIndex];
}

// 0x0041C1A0
void __cdecl LockErrorState()
{
    if (!InterlockedIncrement(&gnErrorLockUsers_0070841C))
        InitializeCriticalSection(&gErrorStateLock_007790CC);
    else
        InterlockedDecrement(&gnErrorLockUsers_0070841C);
    EnterCriticalSection(&gErrorStateLock_007790CC);
}

// 0x0041C1E0
void __cdecl UnlockErrorState()
{
    LeaveCriticalSection(&gErrorStateLock_007790CC);
}

// 0x0041C1F0
static int __stdcall FormatTypeName(const char* szName, char* szOut, unsigned int nSize)
{
    if (SStrLen(szName) < 6)
        return 0;
    if (szName[0] != '.' || szName[3] != 'U')
        return 0;
    const char* pName = szName + 4;
    if (!strpbrk(pName, "?@"))
        return 0;
    SStrCopy(szOut, pName, nSize);
    char* p = strpbrk(szOut, "?@");
    if (!p)
        return 0;
    *p = 0;
    for (p--; p >= szOut && *p == '_'; p--)
        *p = 0;
    SStrPack(szOut, " (", nSize);
    SStrPack(szOut, szName, nSize);
    SStrPack(szOut, gszCloseParen_006CF324, nSize);
    return 1;
}

// 0x0041C2A0
int __cdecl SErrGetLastError()
{
    return gdwStormLastError_007790F4;
}

// 0x0041C2B0
int __cdecl SErrIsDisplayingError()
{
    return gbErrorActive_007790E4;
}

// 0x0041C2C0
void __stdcall SErrPrepareAppFatal(void* pOwnerA, void* pOwnerB)
{
    LockErrorState();
    gpStormOwnerA_007790C0 = pOwnerA;
    gpStormOwnerB_007790C4 = pOwnerB;
    gdwStormOwnerThread_007790C8 = GetCurrentThreadId();
    UnlockErrorState();
}

// 0x0041C2F0
int __stdcall SErrRegisterMessageSource(unsigned short wFacility, void* hModule, void* pReserved)
{
    LockErrorState();
    D2StormMsgSourceStrc* pSource = (D2StormMsgSourceStrc*)HeapAlloc(GetProcessHeap(), 4, sizeof(D2StormMsgSourceStrc));
    pSource->wFacility = wFacility;
    pSource->hModule = hModule;
    pSource->pNext = gpStormMsgSources_007790E8;
    gpStormMsgSources_007790E8 = pSource;
    UnlockErrorState();
    return 1;
}

// 0x0041C340
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode)
{
    gdwStormLastError_007790F4 = dwErrCode;
    SetLastError(dwErrCode);
}

// 0x0041C360
void __stdcall SErrSuppressErrors(int bSuppress)
{
    gbErrorSuppress_007790F0 = bSuppress;
}

// 0x0041C390
void __fastcall sub_0041C390(PairStrc_0041C390* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0041C410
void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0041C420
D2StormLinkStrc* __fastcall sub_0041C420_Identity(D2IdentityView* value) {return &value->link;}

// 0x0041C430
int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size)
{
    VALIDATEBEGIN;
    VALIDATE(buffer);
    VALIDATE(size);
    VALIDATEEND;
    LockErrorState();
    if (!gnInitialized_007790EC) { gnInitialized_007790EC = 1; AddDefaultMessageSources(); }
    D2StormMsgSourceStrc* const head = gpStormMsgSources_007790E8;
    unsigned int facility = (error >> 16) & 0xfff;
    void* module = 0;
    if (head) {
        D2StormMsgSourceStrc* source = head;
        do {
            if (source->wFacility == (unsigned short)facility) { module = source->hModule; break; }
            source = source->pNext;
        } while (source);
    }
    UnlockErrorState();
    buffer[0] = 0;
    return FormatMessageA(module ? 0x800 : 0x1000, module, error, 0x400, buffer, size, 0) != 0;
}

char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

// 0x0041C540
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0041C6E0
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0041C900
void __stdcall SErrRegisterHandler(SERRHANDLERPROC pfnHandler)
{
    LockErrorState();
    HANDLER* pNode = gHandlerList_00708420.NewNode(1, 0, 0x8000000);
    pNode->pfnHandler = pfnHandler;
    UnlockErrorState();
}

// 0x0041CA80
int __cdecl SErrDestroy()
{
    gHandlerList_00708420.Clear();
    gnInitialized_007790EC = 0;
    while (gpStormMsgSources_007790E8)
    {
        D2StormMsgSourceStrc* pNext = gpStormMsgSources_007790E8->pNext;
        HeapFree(GetProcessHeap(), 0, gpStormMsgSources_007790E8);
        gpStormMsgSources_007790E8 = pNext;
    }
    if (gnErrorLockUsers_0070841C != -1)
    {
        DeleteCriticalSection(&gErrorStateLock_007790CC);
        gnErrorLockUsers_0070841C = -1;
    }
    return 1;
}

// 0x0041CAF0
int __stdcall SErrDisplayError(unsigned int nErrorCode,const char* szFile,int nLine,const char* szDescription,int bRecoverable,unsigned int nExitCode)
{
    if(gbErrorSuppress_007790F0) return 0;
    if(gbErrorActive_007790E4) return 0;
    gbErrorActive_007790E4=1;
    LockErrorState();
    char szModulePath[0x104];
    char szModuleName[0x104];
    szModulePath[0]=0;
    szModuleName[0]=0;
    GetModuleFileNameA(0,szModulePath,0x104);
    {
    D2FindDataStrc findData;
    SMemZero(&findData,sizeof(findData));
    void* hFind=FindFirstFileA(szModulePath,&findData);
    if(hFind) FindClose(hFind);
    SStrCopy(szModuleName,findData.szFileName,0x104);
    }
    if(SStrChrR(szModuleName,'.')) *SStrChrR(szModuleName,'.')=0;
    char szError[0x100];
    szError[0]=0;
    SErrGetErrorStr(nErrorCode,szError,0x100);
    if(!szError[0]) wsprintfA(szError,GetMessageText(0),(unsigned short)nErrorCode,nErrorCode);
    const char* szName=szFile;
    char szTypeName[0x100];
    if(szName && *szName && (nLine==-2 || nLine==-3) && FormatTypeName(szName,szTypeName,0x100)) szName=szTypeName;
    char szMessage[0x400];
    char* p=szMessage;
    if(szName) p+=SStrCopy(p,szName,0x7fffffff);
    if(nLine>0) { wsprintfA(p,gszLineFormat_006CF34C,nLine);p+=SStrLen(p); }
    wsprintfA(p,gszErrorFormat_006CF33C,(unsigned short)nErrorCode);p+=SStrLen(p);
    SStrCopy(p,szError,0x7fffffff);
    OutputDebugStringA(szMessage);
    wsprintfA(szMessage,GetMessageText(1),szError);
    p=szMessage+SStrLen(szMessage);
    wsprintfA(p,GetMessageText(2),szModulePath);p+=SStrLen(p);
    if(szName && *szName)
    {
        switch(nLine)
        {
        case -1: wsprintfA(p,GetMessageText(4),szName);break;
        case -2: wsprintfA(p,GetMessageText(5),szName);break;
        case -3: wsprintfA(p,GetMessageText(6),szName);break;
        case -4: wsprintfA(p,GetMessageText(11),szName);break;
        default: wsprintfA(p,GetMessageText(3),szName,nLine);break;
        }
        p+=SStrLen(p);
    }
    if(nErrorCode==0x85100000) wsprintfA(p,GetMessageText(7),szDescription?szDescription:&gszEmptyAssertText);
    else wsprintfA(p,GetMessageText(8),szDescription?szDescription:&gszEmptyAssertText);
    p+=SStrLen(p);
    if(bRecoverable) SStrCopy(p,GetMessageText(10),0x7fffffff);
    else SStrCopy(p,GetMessageText(9),0x7fffffff);
    if(gpErrorReport_007790F8)
    {
        char szDiagnostic[0x104];
        SStrPrintf(szDiagnostic,0x104,gszDiagnosticFormat_006CF330,szError,szName?szName:&gszEmptyAssertText,nLine);
        gpErrorReport_007790F8(szDiagnostic,szMessage,0,0,nLine,0);
    }
    unsigned long nFlags=(bRecoverable?3:1)|0x52010;
    int nChoice=7;
    HANDLER* pHandler=(int)gHandlerList_00708420.m_terminator.m_next<=0?0:gHandlerList_00708420.m_terminator.m_next;
    while((int)pHandler>0)
    {
        if(!pHandler->pfnHandler(nErrorCode,szError,szName,nLine,szDescription?szDescription:&gszEmptyAssertText)) goto DialogDone;
        pHandler=pHandler->m_link.m_next;
    }
    if(!gpErrorReport_007790F8)
    {
        void* hWindow=SMsgGetDefaultWindow();
        if(!IsWindow(hWindow) || !IsWindowVisible(hWindow)) hWindow=0;
        nChoice=MessageBoxA(hWindow,szMessage,szModuleName,nFlags);
    }
DialogDone:
    UnlockErrorState();
    if(bRecoverable && nChoice==7)
    {
        gbErrorActive_007790E4=0;
        return 1;
    }
    if(nChoice==2) BreakIntoDebugger();
    SErrSuppressErrors(1);
    {
        unsigned long dwProcessExitCode;
        if(!(GetVersion()&0x80000000) || !GetExitCodeProcess(GetCurrentProcess(),&dwProcessExitCode) || dwProcessExitCode==0x103)
            TerminateProcess(GetCurrentProcess(),nExitCode);
    }
    gbErrorActive_007790E4=0;
    return 0;
}

// 0x0041CFB0
int __cdecl SErrDisplayErrorFmt(int code, const char* file, int line, int recoverable, int exitCode, const char* format, ...)
{
    char buffer[0x400];
    char* args = (char*)(&format + 1);
    vsprintf(buffer, format, args);
    return SErrDisplayError(code, file, line, buffer, recoverable, exitCode);
}

// 0x0041D010
void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail)
{
    if (!gbDebugMemoryLoaded_00779204)
    {
        gbDebugMemoryLoaded_00779204 = 1;
        SRegLoadValue("Internal", "Debug Memory", 0, &gdwDebugMemory_00779200);
    }
    if (!gdwDebugMemory_00779200)
        return;
    char szText[0x100];
    if (szDetail && *szDetail)
        SStrPrintf(szText, 0x100, "%s (%s)", szName, szDetail);
    else
        SStrPrintf(szText, 0x100, gszFormatName, szName);
    if (!gnErrorOutputMode_0077909C)
    {
        SErrDisplayError(0x8510007F, szText, -3, 0, 1, 1);
    }
    else
    {
        char szOutput[0xC8];
        wsprintfA(szOutput, "Storm Error : handle never released -- %s\n", szText);
        OutputDebugStringA(szOutput);
    }
}

// 0x0041D110
void __stdcall SErrUnregisterHandler(SERRHANDLERPROC pfnHandler)
{
    LockErrorState();
    HANDLER* pHead = gHandlerList_00708420.Head();
    HANDLER* pNode = pHead;
    while ((int)pNode > 0)
    {
        if (pNode->pfnHandler == pfnHandler)
            pNode = gHandlerList_00708420.DeleteNode(pNode);
        else
            pNode = pNode->m_link.m_next;
    }
    UnlockErrorState();
}

// 0x0041D160
void __cdecl SErrDisplayAppFatal(const char* szFormat, ...)
{
    const char* szFile = 0;
    int nLine = 0;
    LockErrorState();
    if (gdwStormOwnerThread_007790C8 == GetCurrentThreadId())
    {
        szFile = (const char*)gpStormOwnerA_007790C0;
        nLine = (int)gpStormOwnerB_007790C4;
        SMemZero(&gpStormOwnerA_007790C0, 12);
    }
    UnlockErrorState();
    char szText[0x400];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    SErrDisplayError(0x85100084, szFile, nLine, szText, 0, 1);
    ExitProcess(1);
}

// 0x0041D1E0
void __stdcall SErrReportResourceLeak(const char* szName)
{
    SErrReportNamedResourceLeak(szName, 0);
}

#include "gen/data/Source/Storm/SOURCE/SERR.inc"
