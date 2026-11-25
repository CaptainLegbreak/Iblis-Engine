#include "D2BnCryptTypes.h"

#define HASH_ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// 0x00523AF0
void __stdcall sub_00523AF0_HashTransform(D2BnHashCtxStrc* pCtx)
{
    int W[80];
    int i;
    int a, b, c, d, e, t;

    for (i = 0; i < 16; i++)
        W[i] = pCtx->aBlock[i];

    for (i = 16; i < 80; i++)
        W[i] = W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16];

    a = pCtx->aState[0];
    b = pCtx->aState[1];
    c = pCtx->aState[2];
    d = pCtx->aState[3];
    e = pCtx->aState[4];

    for (i = 0; i < 20; i++)
    {
        t = HASH_ROL(a, 5) + ((b & c) | (~b & d)) + e + W[i] + 0x5A827999;
        e = d;
        d = c;
        c = HASH_ROL(b, 30);
        b = a;
        a = t;
    }

    for (i = 20; i < 40; i++)
    {
        t = HASH_ROL(a, 5) + (b ^ c ^ d) + e + W[i] + 0x6ED9EBA1;
        e = d;
        d = c;
        c = HASH_ROL(b, 30);
        b = a;
        a = t;
    }

    for (i = 40; i < 60; i++)
    {
        t = HASH_ROL(a, 5) + ((b & c) | (b & d) | (c & d)) + e + W[i] + 0x8F1BBCDC;
        e = d;
        d = c;
        c = HASH_ROL(b, 30);
        b = a;
        a = t;
    }

    for (i = 60; i < 80; i++)
    {
        t = HASH_ROL(a, 5) + (b ^ c ^ d) + e + W[i] + 0xCA62C1D6;
        e = d;
        d = c;
        c = HASH_ROL(b, 30);
        b = a;
        a = t;
    }

    pCtx->aState[0] += a;
    pCtx->aState[1] += b;
    pCtx->aState[2] += c;
    pCtx->aState[3] += d;
    pCtx->aState[4] += e;
}
