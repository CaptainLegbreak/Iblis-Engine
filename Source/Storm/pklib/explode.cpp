// explode(): decompresses a PKWARE DCL stream (see pklib.h). The decoder follows zlib's contrib/blast
// (Mark Adler, see NOTICE-ZLIB.txt), rewritten for the library's read/write interface and work buffer.
#include "pklib.h"

#include <string.h>

namespace
{
using namespace pklib;

struct Huffman
{
    short count[MAXBITS + 1];   // number of codes of each length
    short symbol[LIT_SYMBOLS];  // symbols in canonical order
};

struct ExplodeState
{
    PKReadFn pfnRead;
    PKWriteFn pfnWrite;
    void* pParam;

    unsigned char in[0x800];
    unsigned int nInPos;
    unsigned int nInLen;
    bool bInEnd;
    int nBitBuf;
    int nBitCnt;

    unsigned int nOut;          // bytes in window
    bool bFirst;                // nothing written yet: distances are checked against nOut
    unsigned char window[MAX_DICT];

    Huffman lit, len, dist;
};

static_assert(sizeof(ExplodeState) <= EXP_BUFFER_SIZE, "explode state must fit the caller's work buffer");

// Next input byte, or -1 at the end of the input.
int NextByte(ExplodeState* s)
{
    if (s->nInPos == s->nInLen)
    {
        if (s->bInEnd)
            return -1;
        unsigned int nSize = sizeof(s->in);
        s->nInLen = s->pfnRead((char*)s->in, &nSize, s->pParam);
        s->nInPos = 0;
        if (s->nInLen == 0)
        {
            s->bInEnd = true;
            return -1;
        }
    }
    return s->in[s->nInPos++];
}

// need bits, low bit first; -1 at the end of the input.
int Bits(ExplodeState* s, int need)
{
    int val = s->nBitBuf;
    while (s->nBitCnt < need)
    {
        const int c = NextByte(s);
        if (c < 0)
            return -1;
        val |= c << s->nBitCnt;
        s->nBitCnt += 8;
    }
    s->nBitBuf = val >> need;
    s->nBitCnt -= need;
    return val & ((1 << need) - 1);
}

// The codes are stored with their bits inverted, first bit the highest (see blast.c).
int Decode(ExplodeState* s, const Huffman* h)
{
    int code = 0, first = 0, index = 0;
    for (int len = 1; len <= MAXBITS; ++len)
    {
        const int bit = Bits(s, 1);
        if (bit < 0)
            return -1;
        code |= bit ^ 1;
        const int count = h->count[len];
        if (code < first + count)
            return h->symbol[index + (code - first)];
        index += count;
        first += count;
        first <<= 1;
        code <<= 1;
    }
    return -1;
}

void Construct(Huffman* h, const unsigned char* pPacked, int nPacked)
{
    unsigned char lengths[LIT_SYMBOLS];
    const int n = UnpackLengths(pPacked, nPacked, lengths);
    short offs[MAXBITS + 1];
    memset(h->count, 0, sizeof(h->count));
    for (int i = 0; i < n; ++i)
        h->count[lengths[i]]++;
    offs[1] = 0;
    for (int len = 1; len < MAXBITS; ++len)
        offs[len + 1] = offs[len] + h->count[len];
    for (int i = 0; i < n; ++i)
        if (lengths[i])
            h->symbol[offs[lengths[i]]++] = (short)i;
}

void Flush(ExplodeState* s)
{
    unsigned int nSize = s->nOut;
    s->pfnWrite((char*)s->window, &nSize, s->pParam);
    s->nOut = 0;
    s->bFirst = false;
}

unsigned int Run(ExplodeState* s)
{
    const int lit = Bits(s, 8);
    const int dict = Bits(s, 8);
    if (lit < 0 || dict < 0)
        return CMP_BAD_DATA;
    if (lit > 1)
        return CMP_INVALID_MODE;
    if (dict < 4 || dict > 6)
        return CMP_INVALID_DICTSIZE;

    for (;;)
    {
        const int flag = Bits(s, 1);
        if (flag < 0)
            return CMP_BAD_DATA;
        if (flag)
        {
            int symbol = Decode(s, &s->len);
            if (symbol < 0)
                return CMP_BAD_DATA;
            const int extra = Bits(s, kLenExtra[symbol]);
            if (extra < 0)
                return CMP_BAD_DATA;
            int len = kLenBase[symbol] + extra;
            if (len == END_LENGTH)
                return CMP_NO_ERROR;

            const int low = len == 2 ? 2 : dict;
            symbol = Decode(s, &s->dist);
            const int lowBits = symbol < 0 ? -1 : Bits(s, low);
            if (lowBits < 0)
                return CMP_BAD_DATA;
            const unsigned int dist = ((unsigned int)symbol << low) + lowBits + 1;
            if (s->bFirst && dist > s->nOut)
                return CMP_BAD_DATA;

            while (len--)
            {
                const unsigned int from = (s->nOut + MAX_DICT - dist) % MAX_DICT;
                s->window[s->nOut++] = s->window[from];
                if (s->nOut == MAX_DICT)
                    Flush(s);
            }
        }
        else
        {
            const int symbol = lit ? Decode(s, &s->lit) : Bits(s, 8);
            if (symbol < 0)
                return CMP_BAD_DATA;
            s->window[s->nOut++] = (unsigned char)symbol;
            if (s->nOut == MAX_DICT)
                Flush(s);
        }
    }
}
}

extern "C" unsigned int __cdecl explode(PKReadFn pfnRead, PKWriteFn pfnWrite, char* pWork, void* pParam)
{
    ExplodeState* s = (ExplodeState*)pWork;
    s->pfnRead = pfnRead;
    s->pfnWrite = pfnWrite;
    s->pParam = pParam;
    s->nInPos = s->nInLen = 0;
    s->bInEnd = false;
    s->nBitBuf = s->nBitCnt = 0;
    s->nOut = 0;
    s->bFirst = true;
    Construct(&s->lit, kLitLengths, sizeof(kLitLengths));
    Construct(&s->len, kLenLengths, sizeof(kLenLengths));
    Construct(&s->dist, kDistLengths, sizeof(kDistLengths));

    const unsigned int nResult = Run(s);
    if (s->nOut)
        Flush(s);
    return nResult;
}
