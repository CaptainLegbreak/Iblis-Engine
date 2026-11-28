#include "Storm.h"
#include "D2StormTypes.h"
#include "SValidate.h"
#include "stpl.h"
#include "StormApi.h"

struct D2SCmdLink006C43A0Strc;
struct PairStrc_006C4030;
struct D2SCompLinkStrc;
struct D2FogUnlinkStrc;
struct D2FogUnlinkBStrc;
struct CMDDEF;
struct OptionInfoStrc;
struct OptionContextStrc;

typedef int (__stdcall* OptionCallback)(OptionInfoStrc* pInfo, const char* szString);
typedef int (__stdcall* OptionCallbackToken)(const char* szToken);

struct D2SCmdLink006C43A0Strc
{
    D2SCmdLink006C43A0Strc* m_prevlink;
    char* m_next;

    D2SCmdLink006C43A0Strc();
};

struct PairStrc_006C4030
{
    int nFirst;
    int nSecond;
};

struct sub_006C40B0_Link
{
    sub_006C40B0_Link* pPrev;
    unsigned int dwNext;
};

struct sub_006C40B0_List
{
    int unk_00;
    sub_006C40B0_Link tLink;
};

struct sub_006C40D0_Link
{
    sub_006C40D0_Link* m_prevlink;
    char* m_next;
};

struct sub_006C4140_Link
{
    sub_006C4140_Link* m_prevlink;
    char* m_next;
};

struct sub_006C4140_List
{
    int m_linkoffset;
    sub_006C4140_Link m_terminator;
};

struct sub_006C4470_Pair
{
    int nFirst;
    int nSecond;
};

struct D2ScmdLinkStrc
{
    D2ScmdLinkStrc* m_prevlink;
    int m_next;

    D2ScmdLinkStrc() { m_prevlink = 0; m_next = 0; }
};

struct D2ScmdListStrc
{
    int m_linkoffset;
    D2ScmdLinkStrc m_terminator;

    D2ScmdListStrc();
};

struct D2FogUnlinkStrc
{
    D2SCompLinkStrc tLink;
    void sub_006C4100_Unlink();
    void sub_006C4480_Unlink();
};

struct D2FogUnlinkBStrc { D2SCompLinkStrc tLink; void sub_006C43B0_Unlink(); };

struct OptionInfoStrc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pTarget;
    int nParam24;
    int nParam28;
    int nValue;
};

struct CMDDEF : TSLinkedNode<CMDDEF>
{
    unsigned int dwFlags;                                   // 0x08
    unsigned int dwId;                                      // 0x0C
    char szName[0x10];                                      // 0x10
    int nNameLength;                                        // 0x20
    int nParam24;                                           // 0x24
    int nParam28;                                           // 0x28
    void* pTarget;                                          // 0x2C
    unsigned int nTargetSize;                               // 0x30
    OptionCallback pfnCallback;                             // 0x34
    int bSet;                                               // 0x38
    union
    {
        int nValue;                                         // 0x3C
        char* szValue;
    };

    ~CMDDEF()
    {
    }
    static void operator delete(void* pMemory);
};

struct OptionContextStrc
{
    CMDDEF* pCurrent;
    char szBuffer[0x10];
    int nMinLength;
};

struct D2CmdArg006C4E50Strc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pParam;
};

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetFileSize(void*, unsigned int*);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void*, void*, unsigned int, unsigned int*, void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) int __stdcall LoadStringA(void*, unsigned int, char*, int);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...);
extern "C" __declspec(dllimport) char* __stdcall GetCommandLineA(); // 0x006CC3AC
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, unsigned int nCount); // 0x00682591
extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040
extern "C" long __cdecl strtol(const char* szString, char** ppEnd, int nRadix); // 0x0068676E
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
void __stdcall SMemZero(void* pDst, unsigned int nSize); // 0x0041D300
void* __cdecl StormGetInstance(); // 0x0041BEF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340

extern "C" const char gszDelete[]; // 0x006CC824
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern const char gszEmptyString[]; // 0x006CC837
extern const char* gszErrorDefaults_006FCC24[]; // 0x006FCC24
extern const char gszSCmdFile_006FCC30[]; // 0x006FCC30
extern "C" const char gszCmdWhitespace_006FCC4C[];                                                         // 0x006FCC4C
extern const char gszPercentS_006FFC58[]; // 0x006FFC58
extern const char gszNewline[]; // 0x006FFCB0

// build: symbol ??__EgOptionList_0074C48C@@YAXXZ 0x006CB030
// build: symbol ??__FgOptionList_0074C48C@@YAXXZ 0x006CB4F0
TSList<CMDDEF> gOptionList_0074C48C; // 0x0074C48C
// build: symbol ??__EgOptionList_0074C498@@YAXXZ 0x006CB050
// build: symbol ??__FgOptionList_0074C498@@YAXXZ 0x006CB550
TSList<CMDDEF> gOptionList_0074C498; // 0x0074C498
int gnGlobal_00989C38; // 0x00989C38

#define OPTION_MAX(a, b) ((a) < (b) ? (b) : (a))

static void __stdcall GenerateError(D2ErrorCallback callback, unsigned int error, const char* context);
static int __stdcall ProcessFlags(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError);
static int __stdcall ProcessToken(const char* szToken, OptionContextStrc* pContext, CMDDEF** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError);
static int __stdcall ProcessFile(const char* file, OptionContextStrc* arg1, CMDDEF** arg2, OptionCallbackToken arg3, D2ErrorCallback callback); // 0x006C3F50
int __fastcall ProcessCommandLine(const char** ppszCmdLine, OptionContextStrc* pContext, CMDDEF** ppOption, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError); // 0x006C4EC0
int __stdcall SCmdGetNum(int nId); // 0x006C4D70
int __stdcall SCmdProcess(const char* szCommandLine, int bSkipFirst, OptionCallbackToken pfnExtra, D2ErrorCallback pfnError);
int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int nSetValue, int nSetMask, OptionCallback pfnCallback);

inline void* operator new(unsigned int, void* pMemory) throw() { return pMemory; }

inline void CMDDEF::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, gszDelete, -1, 0);
}

static inline CMDDEF* OPTION_Next(CMDDEF* pLink)
{
    return (int)pLink > 0 ? pLink : 0;
}

// build: symbol ??_R0?AUCMDDEF@@@8 0x0074C474
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol ?Next@?$TSLink@UCMDDEF@@@@QAEPAUCMDDEF@@XZ 0x006C4010
// build: symbol ?RawNext@?$TSLink@UCMDDEF@@@@QAEPAUCMDDEF@@XZ 0x006C4020
// build: symbol ?NextLink@?$TSLink@UCMDDEF@@@@QAEPAU1@H@Z 0x006C4040
// build: symbol ?Unlink@?$TSLink@UCMDDEF@@@@QAEXXZ 0x006C4070
// build: symbol ??0?$TSLink@UCMDDEF@@@@QAE@XZ 0x006C40F0
// build: symbol ?Head@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEPAUCMDDEF@@XZ 0x006C40E0
// build: symbol ?Link@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEPAU?$TSLink@UCMDDEF@@@@PBUCMDDEF@@@Z 0x006C4160
// build: symbol ?LinkNode@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEXPAUCMDDEF@@I0@Z 0x006C4180
// build: symbol ?Next@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEPAUCMDDEF@@PBU2@@Z 0x006C4230
// build: symbol ??1?$TSLink@UCMDDEF@@@@QAE@XZ 0x006C4250
// build: symbol ?UnlinkNode@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEXPAUCMDDEF@@@Z 0x006C4290
// build: symbol ?RawNext@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEPAUCMDDEF@@PBU2@@Z 0x006C4380
// build: symbol ?UnlinkAll@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEXXZ 0x006C43F0
// build: symbol ??1?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAE@XZ 0x006C4430
// build: symbol ?NewNode@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEPAUCMDDEF@@III@Z 0x006C44C0
// build: symbol ??_GCMDDEF@@QAEPAXI@Z 0x006C4520
// build: symbol ?Clear@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEXXZ 0x006C4760
// build: symbol ?DeleteNode@?$TSList@UCMDDEF@@U?$TSGetLink@UCMDDEF@@@@@@QAEPAUCMDDEF@@PAU2@@Z 0x006C47B0
template CMDDEF* TSLink<CMDDEF>::Next();
template CMDDEF* TSLink<CMDDEF>::RawNext();
template TSLink<CMDDEF>* TSLink<CMDDEF>::NextLink(int);
template void TSLink<CMDDEF>::Unlink();
template TSLink<CMDDEF>::TSLink();
template CMDDEF* TSList<CMDDEF>::Head();
template TSLink<CMDDEF>* TSList<CMDDEF>::Link(const CMDDEF*);
template void TSList<CMDDEF>::LinkNode(CMDDEF*, unsigned int, CMDDEF*);
template CMDDEF* TSList<CMDDEF>::Next(const CMDDEF*);
template TSLink<CMDDEF>::~TSLink();
template void TSList<CMDDEF>::UnlinkNode(CMDDEF*);
template CMDDEF* TSList<CMDDEF>::RawNext(const CMDDEF*);
template void TSList<CMDDEF>::UnlinkAll();
template TSList<CMDDEF>::~TSList();
template CMDDEF* TSList<CMDDEF>::NewNode(unsigned int, unsigned int, unsigned int);
template void TSList<CMDDEF>::Clear();
template CMDDEF* TSList<CMDDEF>::DeleteNode(CMDDEF*);

// 0x006C3CB0
static void __stdcall ConvertBool(int* pLength, CMDDEF* pOption, const char* szString)
{
    int bValue;
    if (*szString == '-')
    {
        bValue = 0;
        *pLength = 1;
    }
    else if (*szString == '+')
    {
        bValue = 1;
        *pLength = 1;
    }
    else
    {
        bValue = (unsigned char)((pOption->dwFlags & 1) - 1) != 0;
    }

    int nMask = ~pOption->nParam28;
    pOption->nValue &= nMask;
    if (bValue)
        pOption->nValue |= pOption->nParam24;

    if (pOption->pTarget)
    {
        *(int*)pOption->pTarget &= nMask;
        if (bValue)
            *(int*)pOption->pTarget |= pOption->nParam24;
    }
}

// 0x006C3D20
static void __stdcall ConvertInteger(CMDDEF* pOption, const char* szString, int* pLength)
{
    char* pEnd = 0;
    if (pOption->dwFlags & 1)
        pOption->nValue = strtol(szString, &pEnd, 0);
    else
        pOption->nValue = strtoul(szString, &pEnd, 0);

    if (pEnd)
        *pLength = pEnd - szString;
    else
        *pLength = SStrLen(szString);

    if (pOption->pTarget)
    {
        unsigned int nSize = pOption->nTargetSize;
        if (nSize > 4)
            nSize = 4;
        SMemCopy(pOption->pTarget, &pOption->nValue, nSize);
    }
}

// 0x006C3DA0
static void __stdcall ConvertString(CMDDEF* pOption, const char* szString, int* pLength)
{
    *pLength = SStrLen(szString);
    if (pOption->szValue)
        SMemFree(pOption->szValue, gszSCmdFile_006FCC30, 0x8B, 0);
    pOption->szValue = (char*)SMemAlloc(SStrLen(szString) + 1, gszSCmdFile_006FCC30, 0x8C, 0);
    SStrCopy(pOption->szValue, szString, 0x7FFFFFFF);
    if (pOption->pTarget)
        SStrCopy((char*)pOption->pTarget, szString, pOption->nTargetSize);
}

// 0x006C3E10
static void __stdcall GenerateError(D2ErrorCallback callback, unsigned int error, const char* context)
{
    D2ErrorReportStrc report;
    report.callback = callback;
    char format[256];
    char message[256];
    int index;
    unsigned int resource;
    switch (error)
    {
    case 0x85100065:
        index = 0;
        resource = 0x5201;
        break;
    case 0x8510006D:
        index = 1;
        resource = 0x5202;
        break;
    case 110:
        index = 2;
        resource = 0x5203;
        break;
    default:
        return;
    }
    format[0] = 0;
    LoadStringA(StormGetInstance(), resource, format, 256);
    if (!format[0])
        SStrCopy(format, gszErrorDefaults_006FCC24[index], 256);
    if (strstr(format, gszPercentS_006FFC58))
        wsprintfA(message, format, context);
    else
        SStrCopy(message, format, 256);
    if (message[0])
        SStrPack(message, gszNewline, 256);
    sub_0041C340_SetLastError(error);
    report.error = error;
    report.context = context;
    report.message = message;
    report.callback(&report);
}

// 0x006C3F50
static int __stdcall ProcessFile(const char* file, OptionContextStrc* arg1, CMDDEF** arg2, OptionCallbackToken arg3, D2ErrorCallback callback)
{
    void* handle = CreateFileA(file, 0x80000000, 1, 0, 3, 0x08000000, 0);
    if (handle == (void*)-1)
    {
        if (callback)
            GenerateError(callback, 110, file);
        return 0;
    }
    unsigned int size = GetFileSize(handle, 0);
    char* buffer = (char*)SMemAlloc(size + 1, gszSCmdFile_006FCC30, 339, 0);
    unsigned int read;
    ReadFile(handle, buffer, size, &read, 0);
    CloseHandle(handle);
    buffer[read] = 0;
    const char* cursor = buffer;
    int result = ProcessCommandLine(&cursor, arg1, arg2, arg3, callback);
    SMemFree(buffer, gszSCmdFile_006FCC30, 356, 0);
    return result;
}

// 0x006C4030
void __fastcall sub_006C4030(PairStrc_006C4030* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x006C40B0
void __fastcall sub_006C40B0_InitList(sub_006C40B0_List* pList)
{
    sub_006C40B0_Link* pLink = &pList->tLink;
    pLink->pPrev = pLink;
    pList->tLink.dwNext = ~(unsigned int)pLink;
}

// 0x006C40C0
void* __fastcall sub_006C40C0_Identity(void* p)
{
    return p;
}

// 0x006C40D0
char* __fastcall sub_006C40D0_Head(sub_006C40D0_Link* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x006C4100
void D2FogUnlinkStrc::sub_006C4100_Unlink() { tLink.Unlink(); }

// 0x006C4140
void __fastcall sub_006C4140_InitList(sub_006C4140_List* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_linkoffset = 0;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x006C42E0
static CMDDEF* __stdcall FindLongestPrefix(const char* szString, int nMinLength, CMDDEF* pHead)
{
    int nStringLength = SStrLen(szString);
    int nBestLength = nMinLength - 1;
    CMDDEF* pBest = 0;
    for (CMDDEF* pNode = pHead; pNode; pNode = (int)pNode->m_link.m_next > 0 ? pNode->m_link.m_next : 0)
    {
        if (pNode->nNameLength > nBestLength && pNode->nNameLength <= nStringLength)
        {
            int bMatch;
            if (pNode->dwFlags & 0x100)
                bMatch = !strncmp(pNode->szName, szString, pNode->nNameLength);
            else
                bMatch = !_strnicmp(pNode->szName, szString, pNode->nNameLength);

            if (bMatch)
            {
                nBestLength = pNode->nNameLength;
                pBest = pNode;
            }
        }
    }
    return pBest;
}

// 0x006C4360
D2ScmdListStrc::D2ScmdListStrc()
{
    D2ScmdLinkStrc* pLink = &m_terminator;
    pLink->m_prevlink = pLink;
    m_linkoffset = 0;
    m_terminator.m_next = ~(unsigned int)pLink;
}

// 0x006C43A0
D2SCmdLink006C43A0Strc::D2SCmdLink006C43A0Strc()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x006C43B0
void D2FogUnlinkBStrc::sub_006C43B0_Unlink() { tLink.Unlink(); }

// 0x006C4470
sub_006C4470_Pair* __fastcall sub_006C4470_Clear(sub_006C4470_Pair* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
    return pPair;
}

// 0x006C4480
void D2FogUnlinkStrc::sub_006C4480_Unlink() { tLink.Unlink(); }

// 0x006C4580
int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int nSetValue, int nSetMask, OptionCallback pfnCallback)
{
    if (!szName)
        szName = gszEmptyString;
    int nNameLength = SStrLen(szName);

    VALIDATEBEGIN;
    VALIDATE(nNameLength < 16);
    VALIDATE(!nBytes || pVariable);
    VALIDATE((dwFlags & 0x03000000) != 0x02000000 || !gnGlobal_00989C38);
    VALIDATE((dwFlags & 0x03000000) || nNameLength > 0);
    VALIDATE((dwFlags & 0x00030000) || !pVariable || nBytes == 4);
    VALIDATEEND;

    CMDDEF* pCommand;
    if (!(dwFlags & 0x03000000))
        pCommand = gOptionList_0074C498.NewNode(2, 0, 0);
    else
        pCommand = gOptionList_0074C48C.NewNode(2, 0, 0);
    SStrCopy(pCommand->szName, szName, sizeof(pCommand->szName));
    pCommand->dwId = dwId;
    pCommand->dwFlags = dwFlags;
    pCommand->nNameLength = nNameLength;
    pCommand->pTarget = pVariable;
    pCommand->nTargetSize = nBytes;
    pCommand->nParam28 = nSetMask;
    pCommand->nParam24 = nSetValue;
    pCommand->pfnCallback = pfnCallback;
    if (!(dwFlags & 0x00030000) && (dwFlags & 1))
        pCommand->nValue = nSetValue;
    else
        pCommand->nValue = 0;
    if ((dwFlags & 0x03000000) == 0x01000000)
        gnGlobal_00989C38 = 1;
    return nValid ? 1 : 0;
}

// 0x006C4820
static int __stdcall PerformConversion(const char* szString, int* pLength, CMDDEF* pOption)
{
    *pLength = 0;
    switch (pOption->dwFlags & 0x30000)
    {
    case 0:
        ConvertBool(pLength, pOption, szString);
        break;
    case 0x10000:
        ConvertInteger(pOption, szString, pLength);
        break;
    case 0x20000:
        ConvertString(pOption, szString, pLength);
        break;
    default:
        return 0;
    }

    pOption->bSet = 1;
    if (pOption->pfnCallback)
    {
        OptionInfoStrc info;
        info.dwFlags = pOption->dwFlags;
        info.dwId = pOption->dwId;
        info.szName = pOption->szName;
        info.pTarget = pOption->pTarget;
        info.nParam24 = pOption->nParam24;
        info.nParam28 = pOption->nParam28;
        info.nValue = pOption->nValue;
        if (!pOption->pfnCallback(&info, szString))
            return 0;
    }

    int nPass = 0;
    do
    {
        TSList<CMDDEF>* pList = nPass ? &gOptionList_0074C498 : &gOptionList_0074C48C;
        for (CMDDEF* pOther = pList->m_terminator.m_next; (int)pOther > 0; pOther = pOther->m_link.m_next)
        {
            if (pOther->dwId == pOption->dwId
                && (pOther->dwFlags & 0x30000) == (pOption->dwFlags & 0x30000)
                && pOther != pOption)
            {
                pOther->bSet = 1;
                if ((pOther->dwFlags & 0x30000) == 0x20000)
                {
                    if (pOther->szValue)
                        SMemFree(pOther->szValue, gszSCmdFile_006FCC30, 0x120, 0);
                    pOther->szValue = (char*)SMemAlloc(SStrLen(pOption->szValue) + 1, gszSCmdFile_006FCC30, 0x121, 0);
                    SStrCopy(pOther->szValue, pOption->szValue, 0x7FFFFFFF);
                }
                else
                {
                    pOther->nValue = pOption->nValue;
                }
            }
        }
        ++nPass;
    } while (nPass <= 1);
    return 1;
}

// 0x006C4980
static int __stdcall ConvertPendingOptions(OptionContextStrc* pContext, const char* szString, int* pLength)
{
    *pLength = 0;
    CMDDEF* pOption = pContext->pCurrent;
    pContext->pCurrent = 0;
    while (pOption)
    {
        int nLength;
        if (!PerformConversion(szString, &nLength, pOption))
            return 0;

        *pLength = *pLength > nLength ? *pLength : nLength;

        pOption = FindLongestPrefix(pContext->szBuffer, pContext->nMinLength, OPTION_Next(pOption->m_link.m_next));
    }
    return 1;
}

// 0x006C4A00
static int __stdcall ProcessFlags(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError)
{
    char szBuffer[0x100];
    szBuffer[0] = 0;
    while (*szString)
    {
        const int nStringLength = SStrLen(szString);
        unsigned int nPos = OPTION_MAX(SStrLen(szBuffer), 1);
        CMDDEF* pFound = 0;
        while (nPos--)
        {
            if ((int)(nPos + nStringLength) < 0x100)
            {
                SStrCopy(&szBuffer[nPos], szString, 0x100);
                pFound = FindLongestPrefix(szBuffer, 0, OPTION_Next(gOptionList_0074C498.m_terminator.m_next));
                if (pFound)
                {
                    nPos = pFound->nNameLength;
                    szBuffer[nPos] = 0;
                    break;
                }
            }
        }

        if (!pFound)
        {
            if (pfnError)
            {
                GenerateError(pfnError, 0x85100065, szString);
            }

            return 0;
        }

        szString += nPos;
        while (SStrChr("=:", *szString))
        {
            ++szString;
        }

        pContext->pCurrent = pFound;
        pContext->nMinLength = nPos;
        SStrCopy(pContext->szBuffer, szBuffer, 0x7FFFFFFF);
        if (!*szString && (pFound->dwFlags & 0x30000))
        {
            return 1;
        }

        int nLength;
        if (!ConvertPendingOptions(pContext, szString, &nLength))
        {
            return 0;
        }

        szString += nLength;
    }

    return 1;
}

// 0x006C4BC0
static int __stdcall ProcessToken(const char* szToken, OptionContextStrc* pContext, CMDDEF** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError)
{
    if (*szToken == '@' && !nQuoted)
    {
        return ProcessFile(szToken + 1, pContext, ppOption, pfnCallback, pfnError);
    }

    if (SStrChr("-/", *szToken) && !nQuoted)
    {
        pContext->pCurrent = 0;
        return ProcessFlags(szToken + 1, pContext, pfnError);
    }

    int nLength;
    if (pContext->pCurrent)
    {
        return ConvertPendingOptions(pContext, szToken, &nLength);
    }

    CMDDEF* pOption = *ppOption;
    if (pOption)
    {
        if (!PerformConversion(szToken, &nLength, pOption))
        {
            return 0;
        }

        *ppOption = (int)(*ppOption)->m_link.m_next <= 0 ? 0 : (*ppOption)->m_link.m_next;
        return 1;
    }

    if (pfnCallback)
    {
        return pfnCallback(szToken);
    }

    if (pfnError)
    {
        GenerateError(pfnError, 0x85100065, szToken);
    }

    return 0;
}

// 0x006C4CA0
int __stdcall SCmdIsArgumentSet(int nId)
{
    for (int i = 0; i <= 1; ++i)
    {
        TSList<CMDDEF>* pList = i ? &gOptionList_0074C498 : &gOptionList_0074C48C;
        for (CMDDEF* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->m_link.m_next)
        {
            if (pNode->dwId == nId)
                return pNode->bSet;
        }
    }
    return 0;
}

// 0x006C4CF0
int __cdecl SCmdDestroy()
{
    for (int i = 0; i <= 1; ++i)
    {
        TSList<CMDDEF>* pList = i ? &gOptionList_0074C498 : &gOptionList_0074C48C;
        for (CMDDEF* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->m_link.m_next)
        {
            if ((pNode->dwFlags & 0x30000) == 0x20000 && pNode->szValue)
            {
                SMemFree(pNode->szValue, ".\\SOURCE\\SCMD.CPP", 0x212, 0);
                pNode->szValue = 0;
            }
        }
    }
    gOptionList_0074C48C.Clear();
    gOptionList_0074C498.Clear();
    gnGlobal_00989C38 = 0;
    return 1;
}

// 0x006C4D70
int __stdcall SCmdGetNum(int nId)
{
    for (int i = 0; i <= 1; ++i)
    {
        TSList<CMDDEF>* pList = i ? &gOptionList_0074C498 : &gOptionList_0074C48C;
        for (CMDDEF* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->m_link.m_next)
        {
            if (pNode->dwId == nId)
            {
                return pNode->nValue;
            }
        }
    }
    return 0;
}

// 0x006C4DC0
int __stdcall SCmdGetString(int nId, char* szBuffer, unsigned int nBufferSize)
{
    if (szBuffer)
    {
        *szBuffer = 0;
    }

    VALIDATEBEGIN;
    VALIDATE(szBuffer);
    VALIDATE(nBufferSize);
    VALIDATEEND;

    for (int i = 0; i <= 1; ++i)
    {
        TSList<CMDDEF>* pList = i ? &gOptionList_0074C498 : &gOptionList_0074C48C;
        for (CMDDEF* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->m_link.m_next)
        {
            if (pNode->dwId == nId)
            {
                if (pNode->szValue)
                {
                    SStrCopy(szBuffer, pNode->szValue, nBufferSize);
                }
                return 1;
            }
        }
    }
    return 0;
}

// 0x006C4E50
int __stdcall SCmdRegisterArgList(D2CmdArg006C4E50Strc* pArgs, unsigned int nCount)
{
    VALIDATEBEGIN;
    VALIDATE(pArgs);
    VALIDATEEND;
    for (unsigned int i = 0; i < nCount; ++i, ++pArgs)
    {
        if (!SCmdRegisterArgument(pArgs->dwFlags, pArgs->dwId, pArgs->szName, 0, 0, 1, -1, (OptionCallback)pArgs->pParam))
        {
            return 0;
        }
    }
    return nValid ? 1 : 0;
}

// 0x006C4EC0
int __fastcall ProcessCommandLine(const char** ppszCmdLine, OptionContextStrc* pnState, CMDDEF** pnContext, OptionCallbackToken pfnCallback, D2ErrorCallback pUserData)
{
    while (**ppszCmdLine)
    {
        const char* pszNext = *ppszCmdLine;
        int nQuoted = 0;
        char szToken[0x100];
        SStrTokenize(&pszNext, szToken, 0x100, gszCmdWhitespace_006FCC4C, &nQuoted);
        if (szToken[0] && !ProcessToken(szToken, pnState, pnContext, nQuoted, pfnCallback, pUserData))
        {
            break;
        }
        *ppszCmdLine = pszNext;
    }
    return **ppszCmdLine == 0;
}

// 0x006C4F90
int __stdcall SCmdGetBool(int nKey)
{
    return SCmdGetNum(nKey) != 0;
}

// 0x006C4FB0
int __stdcall SCmdProcess(const char* szCommandLine, int bSkipFirst, OptionCallbackToken pfnExtra, D2ErrorCallback pfnError)
{
    VALIDATEBEGIN;
    VALIDATE(szCommandLine);
    VALIDATEEND;

    if (bSkipFirst)
    {
        SStrTokenize(&szCommandLine, 0, 0, gszCmdWhitespace_006FCC4C, 0);
    }

    OptionContextStrc tState;
    SMemZero(&tState, sizeof(tState));
    CMDDEF* pCmd = gOptionList_0074C48C.Head();
    if (!ProcessCommandLine(&szCommandLine, &tState, &pCmd, pfnExtra, pfnError))
    {
        return 0;
    }

    int bResult = 1;
    while (pCmd && bResult)
    {
        if ((pCmd->dwFlags & 0x3000000) == 0x2000000)
        {
            bResult = 0;
        }
        else if ((int)pCmd->m_link.m_next > 0)
        {
            pCmd = pCmd->m_link.m_next;
        }
        else
        {
            pCmd = 0;
        }
    }

    if (pfnError && !bResult)
    {
        GenerateError(pfnError, 0x8510006D, &gszEmptyAssertText);
    }

    return nValid ? bResult : 0;
}

// 0x006C50B0
int __stdcall SCmdProcessCommandLine(OptionCallbackToken extra, D2ErrorCallback error)
{
    return SCmdProcess(GetCommandLineA(), 1, extra, error);
}

extern "C" const char* const gData_006FCC24[3] = { // 0x006FCC24
    "Invalid argument: %s",
    "The syntax of the command is incorrect.",
    "Unable to open response file: %s"
};
#pragma comment(linker, "/alternatename:?gszErrorDefaults_006FCC24@@3PAPBDA=_gData_006FCC24")

extern "C" const char gData_006FCC4C[12] = " ,;\"\t\n\r\x1A"; // 0x006FCC4C
#pragma comment(linker, "/alternatename:_gszCmdWhitespace_006FCC4C=_gData_006FCC4C")
