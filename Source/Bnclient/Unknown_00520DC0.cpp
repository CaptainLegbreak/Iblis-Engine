#include "Bnclient.h"
#include "D2BNClientApi.h"

struct D2BigPowModStrc;

struct D2BigPairStrc;

struct D2BnHashCtxStrc;

struct D2IdeaUserKeyStrc;

struct D2IdeaKeyScheduleStrc;

extern int gnLastStatus_0072FFA8; // 0x0072FFA8

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern const unsigned char gabSrpData1[]; // 0x00730164

extern int gnSrpSize1; // 0x00730168

extern const unsigned char gabSrpData2[]; // 0x0073016C

extern int gnSrpSize2; // 0x0073018C

extern D2BigPairStrc gtBigPair; // 0x0088273C

extern "C" long __cdecl _time32(long* pTime);

extern "C" int __cdecl tolower(int nChar);




extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2BnHashCtxStrc gatBnHashCtx[]; // 0x00882760

extern D2IdeaKeyScheduleStrc gaIdeaKeySchedules[]; // 0x00882878

#define IDEA_MUL(x, y) (x = IdeaMul((x) & 0xFFFF, y))

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __stdcall sub_00523AF0_HashTransform(D2BnHashCtxStrc* pCtx); // 0x00523AF0

typedef unsigned int D2IdeaUInt16;

typedef unsigned short D2IdeaWord16;

static inline D2IdeaUInt16 IdeaMul(D2IdeaUInt16 a, D2IdeaUInt16 b);

static inline D2IdeaUInt16 IdeaMul(D2IdeaUInt16 a, D2IdeaUInt16 b)
{
    if (a)
    {
        if (b)
        {
            const unsigned int p = (unsigned int)a * b;
            b = p & 0xFFFF;
            a = p >> 16;
            return b - a + (b < a);
        }
        return 1 - a;
    }
    return 1 - b;
}

void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey); // 0x00524780

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

extern "C" const unsigned char gData_00730164[4]; // 0x00730164
extern "C" const unsigned char gData_0073016C[32]; // 0x0073016C

extern "C" const unsigned char gData_00730164[4] = { 0x2F }; // 0x00730164
#pragma comment(linker, "/alternatename:?gabSrpData1@@3QBEB=_gData_00730164")

extern int gnSrpSize1 = 1; // 0x00730168

extern "C" const unsigned char gData_0073016C[32] = {
    0x87, 0xC7, 0x23, 0x85, 0x65, 0xF6, 0x16, 0x12, 0xD9, 0x12, 0x32, 0xC7, 0x78, 0x6C, 0x97, 0x7E,
    0x55, 0xB5, 0x92, 0xA0, 0x8C, 0xB6, 0x86, 0x21, 3, 0x18, 0x99, 0x61, 0x8B, 0x1A, 0xFF, 0xF8
}; // 0x0073016C
#pragma comment(linker, "/alternatename:?gabSrpData2@@3QBEB=_gData_0073016C")

extern int gnSrpSize2 = 32; // 0x0073018C

#include "D2BnCryptTypes.h"
#include "FogApi.h"

// 0x00522BB0
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

// 0x005241A0
void __cdecl sub_005241A0_ClearHashContexts()
{
    memset(gatBnHashCtx, 0, sizeof(D2BnHashCtxStrc) * 3);
}

// 0x005241C0
void __fastcall sub_005241C0_GetDigest(int nIndex, unsigned int* pDigest)
{
    if (pDigest)
    {
        for (int i = 0; i < 5; ++i)
            pDigest[i] = gatBnHashCtx[nIndex].aState[i];
    }
}

// 0x00524200
void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest)
{
    D2BnHashCtxStrc* pCtx = &gatBnHashCtx[nIndex];
    const int nOld = pCtx->nBitCountLo;
    const int nNew = nOld + 0x200;
    if (nNew < nOld)
        ++pCtx->nBitCountHi;
    pCtx->nBitCountLo = nNew;
    memcpy(pCtx->aBlock, pBlock, sizeof(pCtx->aBlock));
    sub_00523AF0_HashTransform(pCtx);
    if (pDigest)
    {
        for (int i = 0; i < 5; ++i)
            pDigest[i] = gatBnHashCtx[nIndex].aState[i];
    }
}

// 0x00524280
void __fastcall sub_00524280_InitHashContext(int nIndex)
{
    D2BnHashCtxStrc* pCtx = &gatBnHashCtx[nIndex];
    pCtx->aState[0] = 0x67452301;
    pCtx->aState[1] = 0xEFCDAB89;
    pCtx->aState[2] = 0x98BADCFE;
    pCtx->aState[3] = 0x10325476;
    pCtx->aState[4] = 0xC3D2E1F0;
    pCtx->nBitCountLo = 0;
    pCtx->nBitCountHi = 0;
}

// 0x005242C0
D2IdeaUInt16 __fastcall sub_005242C0_IdeaMul(D2IdeaUInt16 a, D2IdeaUInt16 b)
{
    if (a)
    {
        if (b)
        {
            const unsigned int p = (unsigned int)a * b;
            b = p & 0xFFFF;
            a = p >> 16;
            return b - a + (b < a);
        }
        return 1 - a;
    }
    return 1 - b;
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

// 0x005243E0
void __fastcall sub_005243E0_InvertKey(const D2IdeaWord16* pEK, D2IdeaWord16* pDK)
{
    D2IdeaUInt16 u1;
    D2IdeaUInt16 u2;
    D2IdeaUInt16 u3;
    D2IdeaWord16 aTemp[52];
    D2IdeaWord16* p = aTemp + 52;
    const D2IdeaUInt16 t1 = *pEK++;
    const D2IdeaUInt16 t2 = -*pEK++;
    const D2IdeaUInt16 t3 = -*pEK++;
    *--p = sub_005242F0_MulInv(*pEK++);
    *--p = t3;
    *--p = t2;
    *--p = sub_005242F0_MulInv(t1);
    for (int j = 1; j < 8; j++)
    {
        u1 = *pEK++;
        *--p = *pEK++;
        *--p = u1;
        u1 = *pEK++;
        u2 = -*pEK++;
        u3 = -*pEK++;
        *--p = sub_005242F0_MulInv(*pEK++);
        *--p = u2;
        *--p = u3;
        *--p = sub_005242F0_MulInv(u1);
    }
    u1 = *pEK++;
    *--p = *pEK++;
    *--p = u1;
    u1 = *pEK++;
    u2 = -*pEK++;
    *--p = sub_005242F0_MulInv(pEK[1]);
    *--p = -*pEK;
    *--p = u2;
    *--p = sub_005242F0_MulInv(u1);
    int j;
    for (j = 0, p = aTemp; j < 52; j++)
    {
        *pDK++ = *p;
        *p++ = 0;
    }
}

// 0x00524540
void __fastcall sub_00524540_Cipher(const D2IdeaWord16* pIn, D2IdeaWord16* pOut, const D2IdeaWord16* pKey)
{
    D2IdeaUInt16 x1, x2, x3, x4, t1, t2;
    int r = 8;
    x1 = *pIn++;
    x2 = *pIn++;
    x3 = *pIn++;
    x4 = *pIn;
    do
    {
        IDEA_MUL(x1, *pKey++);
        x2 += *pKey++;
        x3 += *pKey++;
        IDEA_MUL(x4, *pKey++);
        t2 = x1 ^ x3;
        IDEA_MUL(t2, *pKey++);
        t1 = t2 + (x2 ^ x4);
        IDEA_MUL(t1, *pKey++);
        t2 = t1 + t2;
        x1 ^= t1;
        x4 ^= t2;
        t2 ^= x2;
        x2 = x3 ^ t1;
        x3 = t2;
    }
    while (--r);
    IDEA_MUL(x1, *pKey++);
    *pOut++ = x1;
    *pOut++ = x3 + *pKey++;
    *pOut++ = x2 + *pKey++;
    IDEA_MUL(x4, *pKey);
    *pOut = x4;
}

// 0x00524740
void __cdecl sub_00524740_ClearKeySchedules()
{
    memset(gaIdeaKeySchedules, 0, sizeof(D2IdeaKeyScheduleStrc) * 3);
}


// 0x00524760
void __fastcall sub_00524760_CipherBlock(int nIndex, const unsigned short* pIn, unsigned short* pOut)
{
    sub_00524540_Cipher(pIn, pOut, gaIdeaKeySchedules[nIndex].aKey);
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

