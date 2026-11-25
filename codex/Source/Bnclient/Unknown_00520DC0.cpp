#include "Bnclient.h"

struct D2BigPowModStrc;

struct D2BigPairStrc;

struct D2BnHashCtxStrc;

struct D2IdeaUserKeyStrc;

struct D2IdeaKeyScheduleStrc;

extern int gnLastStatus_0072FFA8; // 0x0072FFA8

int __fastcall BNMESSQUEUE_SetError(int nError); // 0x005204A0

int __fastcall BNSEND_SetErrorText(int nError, const char* szText); // 0x005204D0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern const unsigned char gabSrpData1[]; // 0x00730164

extern int gnSrpSize1; // 0x00730168

extern const unsigned char gabSrpData2[]; // 0x0073016C

extern int gnSrpSize2; // 0x0073018C

extern D2BigPairStrc gtBigPair; // 0x0088273C

extern "C" long __cdecl _time32(long* pTime);

extern "C" int __cdecl tolower(int nChar);

// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2BnHashCtxStrc gatBnHashCtx[]; // 0x00882760

extern D2IdeaKeyScheduleStrc gaIdeaKeySchedules[]; // 0x00882878

void __fastcall BNDOWNLOAD_FillRandomBytes(unsigned char* pBuffer, int nSize); // 0x00522BC0

unsigned int __fastcall BNDOWNLOAD_DecryptData(unsigned char* pBuffer, unsigned int nSize, unsigned char* pKey); // 0x00522E10

static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize);

// 0x00521B50
void __cdecl sub_00521B50_ReseedLogin()
{
    gtBigPair.sub_005285A0_Init(gnSrpSize1, gabSrpData1, gnSrpSize2, gabSrpData2);
    gtBigPair.sub_00528620_InitRandom(GetTickCount());
}

// 0x00521B90
void __cdecl sub_00521B90_ClearSrpState()
{
    gtBigPair.sub_00528630_Release();
}

#include "gen/data/Source/Bnclient/Unknown_00520DC0.inc"

#include "D2BnCryptTypes.h"

// 0x00522BB0
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// build: symbol ?BNSEND_NibbleToHex@* 0x0051DD10
static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

// build: symbol ?BNSEND_HexToNibble@* 0x0051DD20
static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// build: symbol ?BNSEND_MapKeyChar@* 0x0051DD40
static int BNSEND_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return BNSEND_NibbleToHex(tolower(n)) + BNSEND_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return BNSEND_HexToNibble((char)tolower(n)) * 16 + BNSEND_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return BNSEND_MapKeyChar((unsigned char)tolower(n)) * 24 + BNSEND_MapKeyChar((unsigned char)tolower(n + 1));
}

// 0x00523020
char* __fastcall sub_00523020_GetAlignedData(char* pBuffer)
{
    D2_ASSERT(pBuffer, 0xF2);
    const unsigned int nMisalign = (unsigned int)pBuffer & 0x3F;
    if (nMisalign)
        pBuffer += 0x40 - nMisalign;
    return pBuffer + 8;
}

// 0x005242F0
unsigned int __fastcall sub_005242F0_MulInv(unsigned int x)
{
    if (x <= 1)
        return x;
    unsigned int t1 = 0x10001 / x;
    unsigned int y = 0x10001 % x;
    if (y == 1)
        return (1 - t1) & 0xFFFF;
    unsigned int t0 = 1;
    do
    {
        unsigned int q = x / y;
        x = x % y;
        t0 += q * t1;
        if (x == 1)
            return t0;
        q = y / x;
        y = y % x;
        t1 += q * t0;
    }
    while (y != 1);
    return (1 - t1) & 0xFFFF;
}

// 0x00524360
void __fastcall sub_00524360_ExpandKey(const D2IdeaUserKeyStrc* pUserKey, D2IdeaKeyScheduleStrc* pSchedule)
{
    const unsigned short* pKey = (const unsigned short*)pUserKey->aKey;
    unsigned short* pEK = pSchedule->aKey;
    int i, j;
    for (j = 0; j < 8; ++j)
        pEK[j] = pKey[j];
    for (i = 0; j < 52; ++j)
    {
        i += 1;
        pEK[i + 7] = (unsigned short)((pEK[i & 7] << 9) | (pEK[(i + 1) & 7] >> 7));
        pEK += i & 8;
        i &= 7;
    }
}

// 0x00524740
void __cdecl sub_00524740_ClearKeySchedules()
{
    memset(gaIdeaKeySchedules, 0, sizeof(D2IdeaKeyScheduleStrc) * 3);
}

static inline unsigned int sub_GetTerminatedLength(const unsigned char* pString, unsigned int nSize)
{
    unsigned int nMax = 0x80;
    unsigned int nLength = 0;
    if (nSize <= nMax)
    {
        nMax = nSize;
    }

    if (!nMax)
    {
        return 0;
    }

    do
    {
        --nMax;
        ++nLength;
        if (!*pString++)
        {
            return nLength;
        }
    }
    while (nMax);

    return 0;
}

// 0x005232B0
static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize)
{
    unsigned char aKey[20];
    BNDOWNLOAD_FillRandomBytes(aKey, sizeof(aKey));
    unsigned int nLength = BNDOWNLOAD_DecryptData(pBuffer, nSize, aKey);
    if (!nLength)
    {
        return 0;
    }

    if (nLength >= nSize)
    {
        return 0;
    }

    pBuffer[nLength] = 0;
    ++nLength;
    if (!sub_GetTerminatedLength(pBuffer, nLength))
    {
        return 0;
    }

    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_005232B0_Shim(unsigned char* pBuffer, unsigned int nSize)
{
    return sub_005232B0_DecodeAndValidate(pBuffer, nSize);
}
