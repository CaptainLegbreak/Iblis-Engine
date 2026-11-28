// implode(): compresses to a PKWARE DCL stream (see pklib.h). Written for Iblis Engine: greedy matching over
// hash chains, with one step of lazy evaluation. The stream is valid DCL; its bytes can differ from the
// original library's.
#include "pklib.h"

#include <string.h>

namespace
{
using namespace pklib;

enum
{
    HASH_SIZE = 4096,
    BUF_SIZE = 2 * MAX_DICT + MAX_MATCH,
    OUT_SIZE = 0x200,
    NONE = 0xFFFF,
    MAX_CHAIN = 64,
};

struct Code
{
    unsigned short bits;    // as written, low bit first
    unsigned char len;
};

struct ImplodeState
{
    PKReadFn pfnRead;
    PKWriteFn pfnWrite;
    void* pParam;

    unsigned int nType;
    unsigned int nDictBits;     // log2(dictionary) - 6
    unsigned int nDict;

    unsigned int nPos;          // next byte to encode, in buf
    unsigned int nEnd;          // bytes in buf
    bool bInEnd;

    unsigned int nBitBuf;
    unsigned int nBitCnt;
    unsigned int nOut;

    unsigned short head[HASH_SIZE];
    unsigned short prev[BUF_SIZE];
    unsigned char buf[BUF_SIZE];
    unsigned char out[OUT_SIZE];

    Code lit[LIT_SYMBOLS];
    Code len[LEN_SYMBOLS];
    Code dist[DIST_SYMBOLS];
};

static_assert(sizeof(ImplodeState) <= CMP_BUFFER_SIZE, "implode state must fit the caller's work buffer");

// Canonical codes from code lengths, in the stream's order: bits inverted, first bit the highest (as
// explode reads them), then reversed so they can be written low bit first.
void MakeCodes(Code* pCodes, const unsigned char* pPacked, int nPacked)
{
    unsigned char lengths[LIT_SYMBOLS];
    const int n = UnpackLengths(pPacked, nPacked, lengths);
    int count[MAXBITS + 1] = {0};
    for (int i = 0; i < n; ++i)
        count[lengths[i]]++;
    count[0] = 0;
    int next[MAXBITS + 2];
    int code = 0;
    for (int len = 1; len <= MAXBITS; ++len)
    {
        next[len] = code;
        code = (code + count[len]) << 1;
    }
    for (int i = 0; i < n; ++i)
    {
        const int len = lengths[i];
        pCodes[i].len = (unsigned char)len;
        if (!len)
        {
            pCodes[i].bits = 0;
            continue;
        }
        const int value = ~next[len]++ & ((1 << len) - 1);
        int reversed = 0;
        for (int b = 0; b < len; ++b)
            reversed |= ((value >> (len - 1 - b)) & 1) << b;
        pCodes[i].bits = (unsigned short)reversed;
    }
}

void FlushOut(ImplodeState* s)
{
    if (s->nOut)
    {
        unsigned int nSize = s->nOut;
        s->pfnWrite((char*)s->out, &nSize, s->pParam);
        s->nOut = 0;
    }
}

void PutBits(ImplodeState* s, unsigned int value, unsigned int n)
{
    s->nBitBuf |= value << s->nBitCnt;
    s->nBitCnt += n;
    while (s->nBitCnt >= 8)
    {
        s->out[s->nOut++] = (unsigned char)s->nBitBuf;
        s->nBitBuf >>= 8;
        s->nBitCnt -= 8;
        if (s->nOut == OUT_SIZE)
            FlushOut(s);
    }
}

void PutCode(ImplodeState* s, const Code& c)
{
    PutBits(s, c.bits, c.len);
}

void PutLiteral(ImplodeState* s, unsigned char c)
{
    PutBits(s, 0, 1);
    if (s->nType == CMP_ASCII)
        PutCode(s, s->lit[c]);
    else
        PutBits(s, c, 8);
}

void PutLength(ImplodeState* s, unsigned int len)
{
    int symbol = LEN_SYMBOLS - 1;
    while (symbol > 0 && !(kLenBase[symbol] <= (int)len && (int)len < kLenBase[symbol] + (1 << kLenExtra[symbol])))
        --symbol;
    PutBits(s, 1, 1);
    PutCode(s, s->len[symbol]);
    PutBits(s, len - kLenBase[symbol], kLenExtra[symbol]);
}

void PutMatch(ImplodeState* s, unsigned int len, unsigned int distance)
{
    PutLength(s, len);
    const unsigned int d = distance - 1;
    const unsigned int low = len == 2 ? 2 : s->nDictBits;
    PutCode(s, s->dist[d >> low]);
    PutBits(s, d & ((1u << low) - 1), low);
}

unsigned int Hash(const unsigned char* p)
{
    return ((p[0] << 4) ^ p[1]) & (HASH_SIZE - 1);
}

void Insert(ImplodeState* s, unsigned int pos)
{
    if (pos + 1 >= s->nEnd)
        return;
    const unsigned int h = Hash(s->buf + pos);
    s->prev[pos] = s->head[h];
    s->head[h] = (unsigned short)pos;
}

// Reads input until the buffer holds MAX_MATCH bytes past nPos (or the input ends), sliding it when full.
void Fill(ImplodeState* s)
{
    while (!s->bInEnd && s->nEnd - s->nPos < MAX_MATCH)
    {
        if (s->nEnd == BUF_SIZE)
        {
            const unsigned int shift = s->nPos - s->nDict;
            memmove(s->buf, s->buf + shift, s->nEnd - shift);
            s->nEnd -= shift;
            s->nPos -= shift;
            for (int i = 0; i < HASH_SIZE; ++i)
                s->head[i] = s->head[i] != NONE && s->head[i] >= shift ? (unsigned short)(s->head[i] - shift) : NONE;
            for (unsigned int i = 0; i < s->nEnd; ++i)
            {
                const unsigned short p = s->prev[i + shift];
                s->prev[i] = p != NONE && p >= shift ? (unsigned short)(p - shift) : NONE;
            }
        }
        unsigned int nSize = BUF_SIZE - s->nEnd;
        const unsigned int nRead = s->pfnRead((char*)s->buf + s->nEnd, &nSize, s->pParam);
        if (nRead == 0)
            s->bInEnd = true;
        s->nEnd += nRead;
    }
}

// Longest match for nPos within the dictionary; returns its length (0 if none), its distance in *pDist.
unsigned int FindMatch(ImplodeState* s, unsigned int pos, unsigned int* pDist)
{
    const unsigned int nAvail = s->nEnd - pos;
    if (nAvail < MIN_MATCH)
        return 0;
    const unsigned int nMax = nAvail < MAX_MATCH ? nAvail : MAX_MATCH;
    unsigned int nBest = 0;
    unsigned int cand = s->head[Hash(s->buf + pos)];
    for (int chain = 0; cand != NONE && chain < MAX_CHAIN; ++chain, cand = s->prev[cand])
    {
        if (cand >= pos)
            continue;
        const unsigned int dist = pos - cand;
        if (dist > s->nDict)
            break;
        unsigned int n = 0;
        while (n < nMax && s->buf[cand + n] == s->buf[pos + n])
            ++n;
        if (n == 2 && dist > 256)
            continue;
        if (n > nBest)
        {
            nBest = n;
            *pDist = dist;
            if (n == nMax)
                break;
        }
    }
    return nBest >= MIN_MATCH ? nBest : 0;
}
}

extern "C" unsigned int __cdecl implode(PKReadFn pfnRead, PKWriteFn pfnWrite, char* pWork, void* pParam,
                                        unsigned int* pType, unsigned int* pDictSize)
{
    ImplodeState* s = (ImplodeState*)pWork;
    if (*pType != CMP_BINARY && *pType != CMP_ASCII)
        return CMP_INVALID_MODE;
    switch (*pDictSize)
    {
    case 0x400: s->nDictBits = 4; break;
    case 0x800: s->nDictBits = 5; break;
    case 0x1000: s->nDictBits = 6; break;
    default: return CMP_INVALID_DICTSIZE;
    }
    s->pfnRead = pfnRead;
    s->pfnWrite = pfnWrite;
    s->pParam = pParam;
    s->nType = *pType;
    s->nDict = *pDictSize;
    s->nPos = s->nEnd = 0;
    s->bInEnd = false;
    s->nBitBuf = s->nBitCnt = 0;
    s->nOut = 0;
    memset(s->head, 0xFF, sizeof(s->head));
    MakeCodes(s->lit, kLitLengths, sizeof(kLitLengths));
    MakeCodes(s->len, kLenLengths, sizeof(kLenLengths));
    MakeCodes(s->dist, kDistLengths, sizeof(kDistLengths));

    PutBits(s, s->nType, 8);
    PutBits(s, s->nDictBits, 8);

    for (;;)
    {
        Fill(s);
        if (s->nPos >= s->nEnd)
            break;
        unsigned int dist = 0;
        unsigned int len = FindMatch(s, s->nPos, &dist);
        if (len >= MIN_MATCH && len < MAX_MATCH)
        {
            // Lazy step: if the next byte starts a longer match, this byte goes out as a literal.
            unsigned int dist2 = 0;
            Insert(s, s->nPos);
            const unsigned int len2 = FindMatch(s, s->nPos + 1, &dist2);
            bool bInserted = true;
            if (len2 > len + 1)
            {
                bInserted = false;
                PutLiteral(s, s->buf[s->nPos]);
                s->nPos++;
                len = len2;
                dist = dist2;
            }
            PutMatch(s, len, dist);
            for (unsigned int i = 0; i < len; ++i)
            {
                if (i || !bInserted)
                    Insert(s, s->nPos);
                s->nPos++;
            }
        }
        else if (len >= MIN_MATCH)
        {
            PutMatch(s, len, dist);
            for (unsigned int i = 0; i < len; ++i)
                Insert(s, s->nPos++);
        }
        else
        {
            Insert(s, s->nPos);
            PutLiteral(s, s->buf[s->nPos]);
            s->nPos++;
        }
    }

    PutLength(s, END_LENGTH);
    if (s->nBitCnt)
        PutBits(s, 0, 8 - s->nBitCnt);
    FlushOut(s);
    return CMP_NO_ERROR;
}
