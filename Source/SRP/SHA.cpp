#include "SRP.h"

struct FindSignatureTag
{
    unsigned int state[5];
    unsigned int count[2];
    unsigned char buffer[64];
};

extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);

#define rol(value, bits) _rotl(value, bits)

#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00)|(rol(block->l[i],8)&0x00FF00FF))

#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15]^block->l[(i+2)&15]^block->l[i&15],1))

#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);

#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);

#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);

#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);

#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);

struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char aBuffer[64];
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags);         // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                 // 0x00412650

void __fastcall sub_00529F80_SHA1Update(FindSignatureTag* context, unsigned char* data, unsigned int len); // 0x00529F80

void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext);            // 0x0052A040

// 0x00528C90
static void sub_00528C90_SHA1Transform(unsigned int state[5], unsigned char buffer[64])
{
    unsigned long a, b, c, d, e;
    typedef union {
        unsigned char c[64];
        unsigned long l[16];
    } CHAR64LONG16;
    CHAR64LONG16* block;
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    block = (CHAR64LONG16*)buffer;
    R0(a,b,c,d,e,0); R0(e,a,b,c,d,1); R0(d,e,a,b,c,2); R0(c,d,e,a,b,3);
    R0(b,c,d,e,a,4); R0(a,b,c,d,e,5); R0(e,a,b,c,d,6); R0(d,e,a,b,c,7);
    R0(c,d,e,a,b,8); R0(b,c,d,e,a,9); R0(a,b,c,d,e,10); R0(e,a,b,c,d,11);
    R0(d,e,a,b,c,12); R0(c,d,e,a,b,13); R0(b,c,d,e,a,14); R0(a,b,c,d,e,15);
    R1(e,a,b,c,d,16); R1(d,e,a,b,c,17); R1(c,d,e,a,b,18); R1(b,c,d,e,a,19);
    R2(a,b,c,d,e,20); R2(e,a,b,c,d,21); R2(d,e,a,b,c,22); R2(c,d,e,a,b,23);
    R2(b,c,d,e,a,24); R2(a,b,c,d,e,25); R2(e,a,b,c,d,26); R2(d,e,a,b,c,27);
    R2(c,d,e,a,b,28); R2(b,c,d,e,a,29); R2(a,b,c,d,e,30); R2(e,a,b,c,d,31);
    R2(d,e,a,b,c,32); R2(c,d,e,a,b,33); R2(b,c,d,e,a,34); R2(a,b,c,d,e,35);
    R2(e,a,b,c,d,36); R2(d,e,a,b,c,37); R2(c,d,e,a,b,38); R2(b,c,d,e,a,39);
    R3(a,b,c,d,e,40); R3(e,a,b,c,d,41); R3(d,e,a,b,c,42); R3(c,d,e,a,b,43);
    R3(b,c,d,e,a,44); R3(a,b,c,d,e,45); R3(e,a,b,c,d,46); R3(d,e,a,b,c,47);
    R3(c,d,e,a,b,48); R3(b,c,d,e,a,49); R3(a,b,c,d,e,50); R3(e,a,b,c,d,51);
    R3(d,e,a,b,c,52); R3(c,d,e,a,b,53); R3(b,c,d,e,a,54); R3(a,b,c,d,e,55);
    R3(e,a,b,c,d,56); R3(d,e,a,b,c,57); R3(c,d,e,a,b,58); R3(b,c,d,e,a,59);
    R4(a,b,c,d,e,60); R4(e,a,b,c,d,61); R4(d,e,a,b,c,62); R4(c,d,e,a,b,63);
    R4(b,c,d,e,a,64); R4(a,b,c,d,e,65); R4(e,a,b,c,d,66); R4(d,e,a,b,c,67);
    R4(c,d,e,a,b,68); R4(b,c,d,e,a,69); R4(a,b,c,d,e,70); R4(e,a,b,c,d,71);
    R4(d,e,a,b,c,72); R4(c,d,e,a,b,73); R4(b,c,d,e,a,74); R4(a,b,c,d,e,75);
    R4(e,a,b,c,d,76); R4(d,e,a,b,c,77); R4(c,d,e,a,b,78); R4(b,c,d,e,a,79);
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    a = b = c = d = e = 0;
}

// 0x00529F80
void __fastcall sub_00529F80_SHA1Update(FindSignatureTag* context, unsigned char* data, unsigned int len)
{
    unsigned int i, j;
    j = (context->count[0] >> 3) & 63;
    if ((context->count[0] += len << 3) < (len << 3)) context->count[1]++;
    context->count[1] += (len >> 29);
    if ((j + len) > 63) {
        memcpy(&context->buffer[j], data, (i = 64 - j));
        sub_00528C90_SHA1Transform(context->state, context->buffer);
        for ( ; i + 63 < len; i += 64) {
            sub_00528C90_SHA1Transform(context->state, &data[i]);
        }
        j = 0;
    }
    else i = 0;
    memcpy(&context->buffer[j], &data[i], len - i);
}

// 0x00529F50
void __fastcall sub_00529F50_Sha1Init(FindSignatureTag* context)
{
    context->state[0] = 0x67452301;
    context->state[1] = 0xEFCDAB89;
    context->state[2] = 0x98BADCFE;
    context->state[3] = 0x10325476;
    context->state[4] = 0xC3D2E1F0;
    context->count[0] = context->count[1] = 0;
}

// 0x0052A120
unsigned char* __fastcall SHA_Interleave(unsigned char* key, const unsigned char* sk, unsigned int sklen)
{
    unsigned int i;
    unsigned int klen;
    unsigned char* hbuf;
    unsigned char hout[20];
    FindSignatureTag ctxt;

    do
    {
        if (*sk != 0)
            break;
        ++sk;
    } while (--sklen);

    if (sklen & 1)
    {
        ++sk;
        --sklen;
    }

    klen = sklen >> 1;
    hbuf = (unsigned char*)SMemAlloc(klen, ".\\SHA.cpp", 0xC8, 0);
    if (!hbuf)
        return 0;

    for (i = 0; i < klen; ++i)
        hbuf[i] = sk[i * 2];
    sub_00529F50_Sha1Init(&ctxt);
    sub_00529F80_SHA1Update(&ctxt, hbuf, klen);
    sub_0052A040_Sha1Final(hout, (D2SrpSha1ContextStrc*)&ctxt);
    for (i = 0; i < sizeof(hout); ++i)
        key[i * 2] = hout[i];

    for (i = 0; i < klen; ++i)
        hbuf[i] = sk[i * 2 + 1];
    sub_00529F50_Sha1Init(&ctxt);
    sub_00529F80_SHA1Update(&ctxt, hbuf, klen);
    sub_0052A040_Sha1Final(hout, (D2SrpSha1ContextStrc*)&ctxt);
    for (i = 0; i < sizeof(hout); ++i)
        key[i * 2 + 1] = hout[i];

    SMemFree(hbuf, ".\\SHA.cpp", 0xEF, 0);
    return key;
}

extern "C" const unsigned char gabSha1Pad80[]; // 0x006E03F0
extern "C" const unsigned char gabSha1Pad00[]; // 0x006DEF80

// 0x0052A040
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext)
{
    unsigned int i;
    unsigned char abFinalCount[8];

    for (i = 0; i < 8; i++)
    {
        abFinalCount[i] = (unsigned char)((pContext->aCount[(i >= 4 ? 0 : 1)] >> ((3 - (i & 3)) * 8)) & 255);
    }
    sub_00529F80_SHA1Update((FindSignatureTag*)pContext, (unsigned char*)gabSha1Pad80, 1);
    while ((pContext->aCount[0] & 504) != 448)
    {
        sub_00529F80_SHA1Update((FindSignatureTag*)pContext, (unsigned char*)gabSha1Pad00, 1);
    }
    sub_00529F80_SHA1Update((FindSignatureTag*)pContext, abFinalCount, 8);
    for (i = 0; i < 20; i++)
    {
        pDigest[i] = (unsigned char)((pContext->aState[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
    }
}
