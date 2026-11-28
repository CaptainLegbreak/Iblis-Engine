// An open implementation of the PKWARE Data Compression Library (DCL) "implode" format, with the library's
// interface: explode() and implode() read and write through the caller's functions and keep their state in
// the caller's work buffer. Storm uses it for MPQ sectors and SComp's PKWARE mode.
//
// The format (as described by Ben Rudiak-Gould, and as zlib's contrib/blast decodes it, see NOTICE-ZLIB.txt):
// a byte with the literal mode (0 binary, 1 ASCII), a byte with log2(dictionary size) - 6 (4, 5 or 6), then
// bits from the low bit of each byte up: a 0 bit and a literal (8 raw bits, or a Huffman code in ASCII mode),
// or a 1 bit, a coded length (2..518) and a coded distance; length 519 ends the stream.
//
// implode() writes a valid stream that explode() and the original library both read back to the same bytes;
// its bytes can differ from the original library's (docs/DIFFERENCES.md).
#pragma once

#define CMP_BINARY 0
#define CMP_ASCII 1

#define CMP_NO_ERROR 0
#define CMP_INVALID_DICTSIZE 1
#define CMP_INVALID_MODE 2
#define CMP_BAD_DATA 3
#define CMP_ABORT 4

// The work buffer sizes the original library asks for (and Storm allocates).
#define CMP_BUFFER_SIZE 0x8DD8
#define EXP_BUFFER_SIZE 0x3134

typedef unsigned int(__cdecl* PKReadFn)(char* pBuffer, unsigned int* pSize, void* pParam);
typedef void(__cdecl* PKWriteFn)(char* pBuffer, unsigned int* pSize, void* pParam);

extern "C" unsigned int __cdecl explode(PKReadFn pfnRead, PKWriteFn pfnWrite, char* pWork, void* pParam);
extern "C" unsigned int __cdecl implode(PKReadFn pfnRead, PKWriteFn pfnWrite, char* pWork, void* pParam,
                                        unsigned int* pType, unsigned int* pDictSize);

namespace pklib
{
enum
{
    MAXBITS = 13,       // longest code
    LIT_SYMBOLS = 256,
    LEN_SYMBOLS = 16,
    DIST_SYMBOLS = 64,
    MIN_MATCH = 2,
    MAX_MATCH = 518,
    END_LENGTH = 519,
    MAX_DICT = 4096,
};

// Code lengths, run-length packed: each byte is (repeat - 1) << 4 | length.
extern const unsigned char kLitLengths[98];
extern const unsigned char kLenLengths[6];
extern const unsigned char kDistLengths[7];
// Length symbol s covers lengths kLenBase[s] .. kLenBase[s] + (1 << kLenExtra[s]) - 1.
extern const short kLenBase[LEN_SYMBOLS];
extern const unsigned char kLenExtra[LEN_SYMBOLS];

// Unpacks a length table; returns the number of symbols.
int UnpackLengths(const unsigned char* pPacked, int nPacked, unsigned char* pLengths);
}
