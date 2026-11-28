#include "D2BNClient.h"
#include "FogApi.h"
#include "StormApi.h"
#include "StormApi.h"
#include "StormApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

class BNGatewayAccess;

struct D2SystemTimeStrc;

struct D2TimeZoneInformationStrc;

struct Table;


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern "C" unsigned int __cdecl strlen(const char* szString);


void __cdecl BNDOWNLOAD_LogPrintf(const char* szFormat, ...); // 0x00518D40

char* __stdcall BNETGW_LoadGatewayFile(unsigned int* pSize); // 0x00518300

class BNGatewayAccess
{
public:
    BNGatewayAccess& operator=(const BNGatewayAccess& source);
    void __stdcall Unload();                                                                         // 0x00517ED0
    int __stdcall GMT(int nGateway);                                                                        // 0x00518060
    const char* __stdcall Name(int nGateway);
    const char* __stdcall Realm(int nGateway);
    const char* __stdcall DNS(int nGateway);
    void __stdcall SetCurGateway(int nGateway);
    void __stdcall Load();                                                                                  // 0x005186D0
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850

private:
    int GetSystemTimeZone();                                                                                // 0x00517E60
    const char* sub_00517FD0_GetGatewayEntry(int nGateway);                                                 // 0x00517FD0
    const char* Nth(int nGateway);
    void GetGatewayList(const char* szValueName);                                                           // 0x00518190
    void GetBattlenetGatewayList();
    void GetBattlenetRealmsList();                                                                          // 0x005182B0
    void WriteDefaultGatewayList();
    char* SkipToEOL(char* pText, char* pEnd);                                                               // 0x00518390
    char* SkipEOL(char* pText, char* pEnd);                                                                 // 0x005183C0
    char* FindSection(char* pText, const char* szSection);                                                  // 0x005183F0
    char* FindKey(char* pSection, const char* szKey);                                                       // 0x005184C0
    void PickClosestZone(int nTimeZone);                                                                    // 0x00518580

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
    char* m_pGatewayList;
    int m_nGatewayListSize;
    unsigned int m_nVersion;
    int m_bOverride;
    void* m_pRealms;
};


struct Table { char pad0[8]; int count; char padC[4]; const char* data; int length; const char* Nth(int n); };

extern "C" int __cdecl abs(int nValue);

extern "C" long __cdecl strtol(const char* szString, char** ppEnd, int nRadix); // 0x0068676E

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

extern "C" const char gszGatewayIsClosest[]; // 0x006DED44

extern "C" const char gszFindClosestGateway[]; // 0x006DED78

extern "C" const char gszAutoPickGateway[]; // 0x006DED9C

extern "C" const char gszObsoleteGatewayList[]; // 0x006DEDC0

int __cdecl BNDOWNLOAD_ConfigureLog(int nChannel, int nIndent); // 0x00518C70

extern "C" const char gszBNetGWFile[];                                                              // 0x006DEC6C

extern "C" const char gszZero[];                                                                    // 0x006D5D64

// build: symbol ??4BNGatewayAccess@@QAEAAV0@ABV0@@Z 0x00517E40
// 0x00517E40
BNGatewayAccess& BNGatewayAccess::operator=(const BNGatewayAccess& source)
{
    memcpy(this, &source, sizeof(BNGatewayAccess));
    return *this;
}

// 0x00517E60
int BNGatewayAccess::GetSystemTimeZone()
{
    D2TimeZoneInformationStrc tTimeZone;
    SMemZero(&tTimeZone, sizeof(tTimeZone));
    GetTimeZoneInformation(&tTimeZone);
    const unsigned short nLangId = GetUserDefaultLangID();
    if ((nLangId & 0x3FF) == 9 && (nLangId >> 10) == 3)
        return 480;
    return tTimeZone.nBias;
}

// build: symbol ?Nth@BNGatewayAccess@@AAEPBDH@Z 0x00517FD0
// 0x00517ED0
void __stdcall BNGatewayAccess::Unload()
{
    if (m_bModified && m_pGatewayList)
    {
        BNDOWNLOAD_LogPrintf("Recording gateway list selection");
        char* pCurGateway = m_pGatewayList;
        pCurGateway += SStrLen(pCurGateway) + 1;
        pCurGateway[0] = m_nCurGateway / 10 + '0';
        pCurGateway[1] = m_nCurGateway % 10 + '0';
// build: symbol ?gszDiabloGateways@* 0x006DEC8C
// build: symbol ?gszOverrideGateways@* 0x006DECAC
        const char* szValueName = m_bOverride ? gszOverrideGateways : gszDiabloGateways;
        D2_ASSERT(!m_pGatewayList[m_nGatewayListSize - 1] && !m_pGatewayList[m_nGatewayListSize - 2], 0xB9);
// build: symbol ?gszConfiguration@* 0x006DEC7C
        SRegSaveData(gszConfiguration, szValueName, 0x82, m_pGatewayList, m_nGatewayListSize);
    }

    if (m_pGatewayList)
    {
        SMemFree(m_pGatewayList, ".\\BNetGW.cpp", 0xC6, 0);
        m_pGatewayList = 0;
        m_nGatewayListSize = 0;
    }

    if (m_pRealms)
    {
        SMemFree(m_pRealms, ".\\BNetGW.cpp", 0xCC, 0);
        m_pRealms = 0;
    }
}

// 0x00517FD0
const char* Table::Nth(int n)
{
    Table* self = this;
    const char* base = self->data;
    if (base == 0 || n < 1 || n > self->count)
        return (const char*)self;
    int i = 1;
    int target = n * 3;
    int offset = 0;
    const char* p = base;
    while (i < target && offset < self->length)
    {
        int len = SStrLen(p) + 1;
        offset += len;
        p += len;
        ++i;
    }
    if (offset < self->length && i <= target)
        return p;
    return (const char*)self;
}

// 0x00518040
const char* __stdcall BNGatewayAccess::DNS(int nGateway)
{
    return sub_00517FD0_GetGatewayEntry(nGateway);
}

// 0x00518060
int __stdcall BNGatewayAccess::GMT(int nGateway)
{
    const char* szEntry = Nth(nGateway);
    if (*szEntry)
    {
        szEntry += SStrLen(szEntry) + 1;
    }

    char* pEnd;
    return strtol(szEntry, &pEnd, 10);
}

// 0x00518150
void __stdcall BNGatewayAccess::SetCurGateway(int nGateway)
{
    if (m_pGatewayList && nGateway >= 1 && nGateway <= m_nNumGateways)
    {
        if (nGateway > 99)
            nGateway = 99;
        m_nCurGateway = nGateway;
        m_bModified = 1;
    }
}

// 0x00518190
void BNGatewayAccess::GetGatewayList(const char* szValueName)
{
    D2_ASSERT(!m_pGatewayList, 0x146);
    unsigned int nSize = 0;
    if (!SRegLoadData(gszConfiguration, szValueName, 0x82, 0, 0, &nSize) || !nSize)
        return;
    m_nGatewayListSize = nSize;
    m_pGatewayList = (char*)SMemAlloc(nSize, ".\\BNetGW.cpp", 0x156, 0);
    if (!SRegLoadData(gszConfiguration, szValueName, 0x82, m_pGatewayList, m_nGatewayListSize, 0))
    {
        SMemFree(m_pGatewayList, ".\\BNetGW.cpp", 0x15E, 0);
        m_pGatewayList = 0;
        m_nGatewayListSize = 0;
    }
    m_nVersion = 0;
    if (m_pGatewayList)
    {
        char* pEnd = m_pGatewayList;
        m_nVersion = strtoul(m_pGatewayList, &pEnd, 10);
        if (m_pGatewayList == pEnd)
            m_nVersion = 0;
    }
}

// 0x00518270
void BNGatewayAccess::GetBattlenetGatewayList()
{
    m_bOverride = 0;
    GetGatewayList(gszOverrideGateways);
    if (m_pGatewayList)
    {
        m_bOverride = 1;
        return;
    }
    GetGatewayList(gszDiabloGateways);
}

// 0x005182B0
void BNGatewayAccess::GetBattlenetRealmsList()
{
    unsigned int nSize = 0;
    D2_ASSERT(SFileLoadFile("Data\\Global\\Realms.bin", &m_pRealms, &nSize, 0, 0), 0x188);
}

// 0x00518300
char* __stdcall BNETGW_LoadGatewayFile(unsigned int* pSize)
{
    void* pBuffer;
    unsigned int nSize = 0;
    D2_ASSERT(SFileLoadFile("DATA\\GLOBAL\\gateways.txt", &pBuffer, &nSize, 0, 0), 0x1F9);
    // stands for the original reading the out-pointer before the loaded size; a plain *pSize = nSize loads them
    // the other way round and also moves Load's (0x5186D0) register choice.
    unsigned int* const pOut = *(unsigned int* volatile*)&pSize;
    *pOut = nSize;
    return (char*)pBuffer;
}

// 0x00518360
void BNGatewayAccess::WriteDefaultGatewayList()
{
    unsigned int nSize;
// build: symbol ?gszWritingDefaultGateways@* 0x006DED24
    BNDOWNLOAD_LogPrintf(gszWritingDefaultGateways);
    char* szText = BNETGW_LoadGatewayFile(&nSize);
    if (szText)
        UpdateGatewaysFromIni(szText);
}

// 0x00518390
extern "C" __declspec(dllexport) const char* __stdcall SkipToEOL(const char* pText, const char* pEnd) {
    while (pText < pEnd && *pText && *pText != '\r' && *pText != '\n') {
        pText++;
    }
    return pText;
}

// 0x005183C0
extern "C" __declspec(dllexport) const char* __stdcall SkipEOL(const char* pText, const char* pEnd) {
    while (pText < pEnd && *pText && (*pText == '\r' || *pText == '\n')) {
        pText++;
    }
    return pText;
}

// 0x005183F0
char* BNGatewayAccess::FindSection(char* pText, const char* szSection)
{
    const int nTextLength = strlen(pText);
    const int nSectionLength = strlen(szSection);
    char* p = pText;
    while (*p)
    {
        while (*p && *p != '[')
            ++p;
        D2_ASSERT(*p, 0x246);
        if (!_strnicmp(p + 1, szSection, nSectionLength))
            return SkipEOL(SkipToEOL(p + nSectionLength + 2, pText + nTextLength), pText + nTextLength);
        p += nSectionLength;
    }
    return 0;
}

// 0x00518580
void BNGatewayAccess::PickClosestZone(int nTimeZone)
{
    BNDOWNLOAD_ConfigureLog(2, 4);
    BNDOWNLOAD_LogPrintf("Find gateway closest to %02d.%02d", nTimeZone / 60, nTimeZone % 60);

    int nBest = 1;
    int nBestDistance = 0x564;
    for (int i = 1; i <= m_nNumGateways; ++i)
    {
        const int nDistance = abs(GMT(i) * 60 - nTimeZone);
        if (nDistance < nBestDistance)
        {
            nBest = i;
            nBestDistance = nDistance;
        }
    }

    const int nGMT = GMT(nBest);
    const char* szName = Nth(nBest);
    BNDOWNLOAD_LogPrintf("Gateway %d (%s at GMT %02d) is closest to %02d.%02d", nBest, szName, nGMT, nTimeZone / 60, nTimeZone % 60);
    BNDOWNLOAD_ConfigureLog(2, -4);

    if (m_pGatewayList && nBest >= 1 && nBest <= m_nNumGateways)
    {
        if (nBest > 99)
        {
            nBest = 99;
        }
        m_nCurGateway = nBest;
        m_bModified = 1;
    }
}

// 0x005180A0
const char* __stdcall BNGatewayAccess::Name(int nGateway)
{
    const char* szEntry = Nth(nGateway);
    if (*szEntry)
    {
        szEntry += SStrLen(szEntry) + 1;
        if (*szEntry)
        {
            szEntry += SStrLen(szEntry) + 1;
        }
    }

    return szEntry;
}

inline char* BnSkipToEOL(char* p, char* pEnd)
{
    while (p < pEnd && *p && *p != '\r' && *p != '\n')
        ++p;
    return p;
}

inline char* BnSkipEOL(char* p, char* pEnd)
{
    while (p < pEnd && *p && (*p == '\r' || *p == '\n'))
        ++p;
    return p;
}

// 0x005186D0
void __stdcall BNGatewayAccess::Load()
{
    if (m_pGatewayList)
    {
        return;
    }

    int nOffset;

    m_nNumGateways = 0;
    m_nCurGateway = 0;
    m_pRealms = 0;
    m_pGatewayList = 0;
    m_nGatewayListSize = 0;
    m_nVersion = 0;
    m_szEmpty[0] = 0;
    GetBattlenetRealmsList();
    m_bOverride = 0;
    GetGatewayList("Override Battle.net gateways");
    if (m_pGatewayList)
    {
        m_bOverride = 1;
    }
    else
    {
        GetGatewayList("Diablo II Battle.net gateways");
    }

    if (m_pGatewayList && m_nVersion < 1000)
    {
        BNDOWNLOAD_LogPrintf("Obsolete gateway list (%d) - autodeleting", m_nVersion);
        m_bModified = 0;
        Unload();
        SRegDeleteValue("Configuration", "Diablo II Battle.net gateways", 2);
    }

    if (!m_pGatewayList)
    {
        BNDOWNLOAD_LogPrintf("Writing default gateway list");
        char* szText = BNETGW_LoadGatewayFile((unsigned int*)&nOffset);
        if (szText)
        {
            UpdateGatewaysFromIni(szText);
        }
    }

    D2_ASSERT(m_nVersion >= 1000, 0x5B);

    const char* szEntry = m_pGatewayList;
    int nStrings = -2;
    for (nOffset = 0; nOffset < m_nGatewayListSize; ++nStrings)
    {
        const int nLength = SStrLen(szEntry) + 1;
        nOffset += nLength;
        szEntry += nLength;
    }

    --nStrings;
    D2_ASSERT(nStrings % 3 == 0, 0x6C);
    m_nNumGateways = nStrings / 3;

    char* pEnd;
    const char* szList = m_pGatewayList;
    szList += SStrLen(szList) + 1;
    m_nCurGateway = strtoul(szList, &pEnd, 10);
    m_bModified = 0;
    if (m_nCurGateway < 1 || m_nCurGateway > m_nNumGateways)
    {
        BNDOWNLOAD_LogPrintf("Auto-picking gateway based on GMT");
        PickClosestZone(GetSystemTimeZone());
    }
}

// 0x00518850
void __stdcall BNGatewayAccess::UpdateGatewaysFromIni(char* szText)
{
    int nIndex = 0;
    char szKey[16];
    struct { char* pLine; char* szTextCopy; } tLocals;
    tLocals.szTextCopy = szText;
    tLocals.pLine = 0;
    char* pEnd = strlen(tLocals.szTextCopy) + tLocals.szTextCopy;

    char* pVersionSection = FindSection(tLocals.szTextCopy, "Server List Version");
    D2_ASSERT(pVersionSection, 0x277);
    pVersionSection = FindKey(pVersionSection, "VER");
    D2_ASSERT(pVersionSection, 0x27C);

    char* pNumberEnd = pVersionSection;
    const unsigned int nVersion = strtoul(pVersionSection, (&pNumberEnd), 10);
    pVersionSection = 0;
    {
        char* pDest = 0;
        if (nVersion <= m_nVersion)
        {
            return;
        }
        else
        {
            char* pName = 0;
            {
                int nTimeZone = 0;

                BNDOWNLOAD_LogPrintf("Parsing new gateway list (version %d)", nVersion);
                if (m_pGatewayList)
                    {
                    nTimeZone = GMT(m_nCurGateway) * 60;
                }
                else
                {
                    nTimeZone = GetSystemTimeZone();
                }
                m_bModified = 0;

                Unload();
                m_nVersion = nVersion;
                m_bOverride = 0;
                m_bModified = 1;

                const int nSize = 2 * strlen(tLocals.szTextCopy);
                pVersionSection = (char*)SMemAlloc(nSize, gszBNetGWFile, 0x297, 0);
                sprintf(pVersionSection, "%d", nVersion);
                pDest = pVersionSection + SStrLen(pVersionSection) + 1;
                *pDest = '0';
                pDest++;
                *pDest++ = '0';
                *pDest = '\0';

                pDest++;
                char* pGateways = FindSection((tLocals.szTextCopy), "Server Gateways");
                nIndex = 1;
                sprintf(szKey, "%d", nIndex);
                tLocals.pLine = FindKey(pGateways, szKey);
                if (tLocals.pLine)
                {
                    while (1)
                    {
                        int nLen = SkipToEOL((tLocals.pLine), pEnd) - tLocals.pLine;
                        SStrCopy(pDest, (tLocals.pLine), nLen + 1);
                        pName = pDest;
                        char* pSection = FindSection(tLocals.szTextCopy, pName);
                        if (pSection)
                        {
                            pDest += 1;
                            pDest += nLen;

                            char* pZone = FindKey(pSection, "ZONE");
                            if (pZone)
                            {
                                nLen = SkipToEOL(pZone, pEnd) - pZone;
                                SStrCopy(pDest, pZone, nLen + 1);
                            }
                            else
                            {
                                nLen = 1;
                                SStrCopy(pDest, gszZero, 2);
                            }
                            pDest += nLen;
                            pDest = pDest + 1;

                            pZone = FindKey(pSection, "ENU");
                            if (pZone)
                            {
                                nLen = SkipToEOL(pZone, pEnd) - pZone;
                                SStrCopy(pDest, pZone, nLen + 1);
                            }
                            else
                            {
                                nLen = strlen(pName);
                                SStrCopy(pDest, pName, 1 + nLen);
                            }
                            pDest += nLen + 1;
                        }

                        nIndex = nIndex + 1;
                        sprintf(szKey, "%d", nIndex);
                        tLocals.pLine = FindKey(pGateways, szKey);
                        if (!tLocals.pLine)
                            break;
                    }

                }

                *pDest = '\0';
                pDest = 1 + pDest;
                nIndex = pDest - pVersionSection;
                D2_ASSERT(nIndex < nSize, 0x2E6);
                if (!pVersionSection[nIndex - 1] && !(nIndex - 2)[pVersionSection])
                {
                    m_pGatewayList = pVersionSection;
                    m_nGatewayListSize = pDest - pVersionSection;
                    PickClosestZone(nTimeZone);
                    Unload();
                    Load();
                }
                else
                {
                    FOG_DisplayHalt((&gszEmptyAssertText), sub_00408090(), 0x2E8); exit(-1);
                }
            }
        }
    }

}

// build: symbol ?PickClosestZone@BNGatewayAccess@@AAEXH@Z 0x00518580
// 0x005184C0
char* BNGatewayAccess::FindKey(char* pSection, const char* szKey)
{
    const int nSectionLength = strlen(pSection);
    const int nKeyLength = strlen(szKey);
    char* p = pSection;
    while (*p && *p != ']')
    {
        if (!_strnicmp(p, szKey, nKeyLength))
            return p + nKeyLength + 1;
        p = BnSkipEOL(BnSkipToEOL(p, pSection + nSectionLength), pSection + nSectionLength);
    }
    return 0;
}

// 0x005180E0
const char* __stdcall BNGatewayAccess::Realm(int nGateway)
{
    const char* szName = Nth(nGateway);
    const char* szRealm = (const char*)m_pRealms;
    while (*szRealm)
    {
        if (!SStrCmpI(szRealm, szName, 0x7FFFFFFF))
        {
            return szRealm + SStrLen(szRealm) + 1;
        }

        szRealm += SStrLen(szRealm) + 1;
        if (!*szRealm)
        {
            break;
        }

        szRealm += SStrLen(szRealm) + 1;
    }

    return &gszEmptyAssertText;
}
