#include "Storm.h"
#include "D2StormSha1.h"

struct D2StormBigStrc;

void __stdcall SBigNew(D2StormBigStrc** ppBig);                                                             // 0x00423950
void __stdcall SBigDel(D2StormBigStrc* pBig);                                                               // 0x00424E40
int __stdcall sub_00423850(D2StormBigStrc* pBig, const void* pData, unsigned int nSize);                    // 0x00423850
void __stdcall SBigToBinaryBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pRead); // 0x00423B30
void __stdcall SBigPowMod(D2StormBigStrc* pResult, D2StormBigStrc* pBase, D2StormBigStrc* pExponent, D2StormBigStrc* pModulus); // 0x00425330

struct BigNum
{
    D2StormBigStrc* hHandle;

    BigNum()
    {
        SBigNew(&hHandle);
    }
    // 0x0041D330
    ~BigNum()
    {
        SBigDel(hHandle);
    }
    BigNum& sub_00425FE0_Apply(const BigNum& tBase, const BigNum& tExponent, const BigNum& tModulus);
    void* sub_00426010_ReadFill(void* pBuffer, unsigned int nSize);
    int sub_00426050_Call(const void* pData, unsigned int nSize);
};

namespace Crypt
{

struct RSA
{
    BigNum hExponent;
    BigNum hModulus;

    void Prepare(const void* pExponent, unsigned int nExponentSize, const void* pModulus, unsigned int nModulusSize);
    void Process(void* pBuffer, unsigned int nSize);
};

}

extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);
extern "C" const unsigned char gaSha1Padding[]; // 0x00708890

// 0x00425720
unsigned int __fastcall sub_00425720_Rotl(unsigned int nValue, int nShift)
{
    return _rotl(nValue, nShift);
}

// 0x00425730
void __fastcall sub_00425730_Sha1Round0(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + ((*b & c) | (~*b & d)) + *w + 0x5A827999;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x00425770
void __fastcall sub_00425770_Sha1Round1(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + (*b ^ c ^ d) + *w + 0x6ED9EBA1;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x004257B0
void __fastcall sub_004257B0_Sha1Round2(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + ((*b & c) | (*b & d) | (c & d)) + *w + 0x8F1BBCDC;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x004257F0
void __fastcall sub_004257F0_Sha1Round3(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + (*b ^ c ^ d) + *w + 0xCA62C1D6;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x00425830
void __fastcall sub_00425830_LoadBE32(unsigned int* pOut, const unsigned char* pIn)
{
    *pOut = ((((pIn[0] << 8) | pIn[1]) << 8 | pIn[2]) << 8) | pIn[3];
}

// 0x00425850
void __fastcall sub_00425850_Sha1Transform(unsigned int* pState, const unsigned char* pBlock)
{
    unsigned int W[80];
    int i;

    for (i = 0; i < 16; i++)
    {
        sub_00425830_LoadBE32(&W[i], pBlock);
        pBlock += 4;
    }

    do
    {
        W[i] = sub_00425720_Rotl(W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16], 1);
    } while (++i < 80);

    unsigned int a = pState[0];
    unsigned int b = pState[1];
    unsigned int c = pState[2];
    unsigned int d = pState[3];
    unsigned int e = pState[4];

    i = 0;
    do
    {
        sub_00425730_Sha1Round0(a, &b, c, d, &e, &W[i]);
        sub_00425730_Sha1Round0(e, &a, b, c, &d, &W[i + 1]);
        sub_00425730_Sha1Round0(d, &e, a, b, &c, &W[i + 2]);
        sub_00425730_Sha1Round0(c, &d, e, a, &b, &W[i + 3]);
        sub_00425730_Sha1Round0(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 20);

    do
    {
        sub_00425770_Sha1Round1(a, &b, c, d, &e, &W[i]);
        sub_00425770_Sha1Round1(e, &a, b, c, &d, &W[i + 1]);
        sub_00425770_Sha1Round1(d, &e, a, b, &c, &W[i + 2]);
        sub_00425770_Sha1Round1(c, &d, e, a, &b, &W[i + 3]);
        sub_00425770_Sha1Round1(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 40);

    do
    {
        sub_004257B0_Sha1Round2(a, &b, c, d, &e, &W[i]);
        sub_004257B0_Sha1Round2(e, &a, b, c, &d, &W[i + 1]);
        sub_004257B0_Sha1Round2(d, &e, a, b, &c, &W[i + 2]);
        sub_004257B0_Sha1Round2(c, &d, e, a, &b, &W[i + 3]);
        sub_004257B0_Sha1Round2(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 60);

    do
    {
        sub_004257F0_Sha1Round3(a, &b, c, d, &e, &W[i]);
        sub_004257F0_Sha1Round3(e, &a, b, c, &d, &W[i + 1]);
        sub_004257F0_Sha1Round3(d, &e, a, b, &c, &W[i + 2]);
        sub_004257F0_Sha1Round3(c, &d, e, a, &b, &W[i + 3]);
        sub_004257F0_Sha1Round3(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 80);

    pState[0] += a;
    pState[1] += b;
    pState[2] += c;
    pState[3] += d;
    pState[4] += e;
}

// 0x00425D90
void Sha1::Initialize()
{
    nBitCount = 0;
    aState[0] = 0x67452301;
    aState[1] = 0xEFCDAB89;
    aState[2] = 0x98BADCFE;
    aState[3] = 0x10325476;
    aState[4] = 0xC3D2E1F0;
}

// 0x00425DD0
void Sha1::Append(const unsigned char* pData, unsigned int nLen)
{
    unsigned int nUsed = (unsigned int)nBitCount >> 3 & 0x3F;
    nBitCount += (unsigned __int64)nLen * 8;
    if (nUsed)
    {
        nLen += nUsed;
        pData -= nUsed;
        if (nLen >= 64)
        {
            for (; nUsed < 64; nUsed++)
                aBlock[nUsed] = pData[nUsed];
            sub_00425850_Sha1Transform(aState, aBlock);
            nLen -= 64;
            pData += 64;
            nUsed = 0;
        }
    }
    while (nLen >= 64)
    {
        sub_00425850_Sha1Transform(aState, pData);
        nLen -= 64;
        pData += 64;
    }
    for (; nUsed < nLen; nUsed++)
        aBlock[nUsed] = pData[nUsed];
}

// 0x00425E80
void __fastcall sub_00425E80_PutBE64(unsigned char* pOut, unsigned __int64 nValue)
{
    pOut[7] = (unsigned char)nValue; nValue >>= 8;
    pOut[6] = (unsigned char)nValue; nValue >>= 8;
    pOut[5] = (unsigned char)nValue; nValue >>= 8;
    pOut[4] = (unsigned char)nValue; nValue >>= 8;
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}

// 0x00425EE0
void __fastcall sub_00425EE0_PutBE32(unsigned int nValue, unsigned char* pOut)
{
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}

static inline void sub_PutBE64(unsigned char* p, unsigned __int64 v)
{
    p[7] = (unsigned char)v; v >>= 8;
    p[6] = (unsigned char)v; v >>= 8;
    p[5] = (unsigned char)v; v >>= 8;
    p[4] = (unsigned char)v; v >>= 8;
    p[3] = (unsigned char)v; v >>= 8;
    p[2] = (unsigned char)v; v >>= 8;
    p[1] = (unsigned char)v; v >>= 8;
    p[0] = (unsigned char)v;
}

// 0x00425F00
void Sha1::sub_00425F00_Final(unsigned char* pDigest)
{
    unsigned char aCount[8];
    sub_PutBE64(aCount, nBitCount);
    Append(gaSha1Padding, ((0xFFFFFFF7 - ((unsigned int)nBitCount >> 3)) & 0x3F) + 1);
    Append(aCount, 8);
    for (int i = 0; i < 5; i++)
    {
        unsigned int v = aState[i];
        for (int j = 3; j >= 0; j--)
        {
            pDigest[i * 4 + j] = (unsigned char)v;
            v >>= 8;
        }
    }
}

// 0x00425FE0
BigNum& BigNum::sub_00425FE0_Apply(const BigNum& tBase, const BigNum& tExponent, const BigNum& tModulus)
{
    SBigPowMod(hHandle, tBase.hHandle, tExponent.hHandle, tModulus.hHandle);
    return *this;
}

// 0x00426010
void* BigNum::sub_00426010_ReadFill(void* pBuffer, unsigned int nSize)
{
    unsigned int nRead;
    SBigToBinaryBuffer(hHandle, pBuffer, nSize, &nRead);
    if (nRead < nSize)
// build: symbol ?SMemZero@* 0x0041D300
        SMemZero((char*)pBuffer + nRead, nSize - nRead);
    return pBuffer;
}

// 0x00426050
int BigNum::sub_00426050_Call(const void* pData, unsigned int nSize)
{
    return sub_00423850(hHandle, pData, nSize);
}

// 0x00426070
void Crypt::RSA::Prepare(const void* pExponent, unsigned int nExponentSize, const void* pModulus, unsigned int nModulusSize)
{
    hExponent.sub_00426050_Call(pExponent, nExponentSize);
    hModulus.sub_00426050_Call(pModulus, nModulusSize);
}

// 0x004260A0
void Crypt::RSA::Process(void* pBuffer, unsigned int nSize)
{
    BigNum tInput;
    tInput.sub_00426050_Call(pBuffer, nSize);
    BigNum tOutput;
    tOutput.sub_00425FE0_Apply(tInput, hModulus, hExponent);
    tOutput.sub_00426010_ReadFill(pBuffer, nSize);
}

extern "C" unsigned char gData_00708890[64] = { 0x80 }; // 0x00708890
#pragma comment(linker, "/alternatename:_gaSha1Padding_00708890=_gData_00708890")
