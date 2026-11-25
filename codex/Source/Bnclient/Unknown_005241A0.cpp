#include "D2BnCryptTypes.h"
#include "Bnclient.h"

#define IDEA_MUL(x, y) (x = IdeaMul((x) & 0xFFFF, y))

struct D2BnHashCtxStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2BnHashCtxStrc gatBnHashCtx[]; // 0x00882760

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __stdcall sub_00523AF0_HashTransform(D2BnHashCtxStrc* pCtx); // 0x00523AF0

typedef unsigned int D2IdeaUInt16;

typedef unsigned short D2IdeaWord16;

unsigned int __fastcall sub_005242F0_MulInv(unsigned int x); // 0x005242F0

static inline D2IdeaUInt16 IdeaMul(D2IdeaUInt16 a, D2IdeaUInt16 b);

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
