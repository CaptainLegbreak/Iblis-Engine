// The fixed codes of the PKWARE DCL format (see pklib.h).
#include "pklib.h"

namespace pklib
{
const unsigned char kLitLengths[98] = {
    11, 124, 8, 7, 28, 7, 188, 13, 76, 4, 10, 8, 12, 10, 12, 10, 8, 23, 8,
    9, 7, 6, 7, 8, 7, 6, 55, 8, 23, 24, 12, 11, 7, 9, 11, 12, 6, 7, 22, 5,
    7, 24, 6, 11, 9, 6, 7, 22, 7, 11, 38, 7, 9, 8, 25, 11, 8, 11, 9, 12,
    8, 12, 5, 38, 5, 38, 5, 11, 7, 5, 6, 21, 6, 10, 53, 8, 7, 24, 10, 27,
    44, 253, 253, 253, 252, 252, 252, 13, 12, 45, 12, 45, 12, 61, 12, 45,
    44, 173};

const unsigned char kLenLengths[6] = {2, 35, 36, 53, 38, 23};

const unsigned char kDistLengths[7] = {2, 20, 53, 230, 247, 151, 248};

const short kLenBase[LEN_SYMBOLS] = {3, 2, 4, 5, 6, 7, 8, 9, 10, 12, 16, 24, 40, 72, 136, 264};

const unsigned char kLenExtra[LEN_SYMBOLS] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8};

int UnpackLengths(const unsigned char* pPacked, int nPacked, unsigned char* pLengths)
{
    int n = 0;
    for (int i = 0; i < nPacked; ++i)
    {
        const int nRepeat = (pPacked[i] >> 4) + 1;
        for (int k = 0; k < nRepeat; ++k)
            pLengths[n++] = pPacked[i] & 15;
    }
    return n;
}
}
