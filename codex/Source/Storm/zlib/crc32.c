// Altered from the original zlib source.
#define ZSWAP32(q) ((((q) >> 24) & 0xff) + (((q) >> 8) & 0xff00) + \
                    (((q) & 0xff00) << 8) + (((q) & 0xff) << 24))
#define DOLIT4 c ^= *buf4++; \
        c = crc_table[3][c & 0xff] ^ crc_table[2][(c >> 8) & 0xff] ^ \
            crc_table[1][(c >> 16) & 0xff] ^ crc_table[0][c >> 24]
#define DOLIT32 DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4
#define DOBIG4 c ^= *++buf4; \
        c = crc_table[4][c & 0xff] ^ crc_table[5][(c >> 8) & 0xff] ^ \
            crc_table[6][(c >> 16) & 0xff] ^ crc_table[7][c >> 24]
#define DOBIG32 DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4
#define GF2_DIM 32

extern const unsigned long crc_table[8][256]; // 0x006D17C8

static unsigned long crc32_little(unsigned long crc, const unsigned char* buf, unsigned len);
static unsigned long __stdcall crc32_big(unsigned long crc, const unsigned char* buf, unsigned len);
static unsigned long gf2_matrix_times(unsigned long* mat, unsigned long vec);
static void gf2_matrix_square(unsigned long* square, unsigned long* mat);
static unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2);

// 0x0042D450
const unsigned long* __cdecl get_crc_table()
{
    return (const unsigned long*)crc_table;
}

// 0x0042DC00
unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len)
{
    if (buf == 0) return 0UL;
    {
        unsigned long endian;
        endian = 1;
        if (*((unsigned char*)(&endian)))
            return crc32_little(crc, buf, len);
        else
            return crc32_big(crc, buf, len);
    }
}

// 0x0042D460
static unsigned long crc32_little(unsigned long crc, const unsigned char* buf, unsigned len)
{
    register unsigned long c;
    register const unsigned long* buf4;

    c = (unsigned long)crc;
    c = ~c;
    while (len && ((int)buf & 3)) {
        c = crc_table[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
        len--;
    }

    buf4 = (const unsigned long*)(const void*)buf;
    while (len >= 32) {
        DOLIT32;
        len -= 32;
    }
    while (len >= 4) {
        DOLIT4;
        len -= 4;
    }
    buf = (const unsigned char*)buf4;

    if (len) do {
        c = crc_table[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
    } while (--len);
    c = ~c;
    return (unsigned long)c;
}

// 0x0042D700
static unsigned long __stdcall crc32_big(unsigned long crc, const unsigned char* buf, unsigned len)
{
    register unsigned long c;
    register const unsigned long* buf4;

    c = ZSWAP32((unsigned long)crc);
    c = ~c;
    while (len && ((int)buf & 3)) {
        c = crc_table[4][(c >> 24) ^ *buf++] ^ (c << 8);
        len--;
    }

    buf4 = (const unsigned long*)(const void*)buf;
    buf4--;
    while (len >= 32) {
        DOBIG32;
        len -= 32;
    }
    while (len >= 4) {
        DOBIG4;
        len -= 4;
    }
    buf4++;
    buf = (const unsigned char*)buf4;

    if (len) do {
        c = crc_table[4][(c >> 24) ^ *buf++] ^ (c << 8);
    } while (--len);
    c = ~c;
    return (unsigned long)(ZSWAP32(c));
}

// 0x0042D9F0
static unsigned long gf2_matrix_times(unsigned long* mat, unsigned long vec)
{
    unsigned long sum;

    sum = 0;
    while (vec) {
        if (vec & 1)
            sum ^= *mat;
        vec >>= 1;
        mat++;
    }
    return sum;
}

// 0x0042DA10
static void gf2_matrix_square(unsigned long* square, unsigned long* mat)
{
    int n;

    for (n = 0; n < GF2_DIM; n++)
        square[n] = gf2_matrix_times(mat, mat[n]);
}

// 0x0042DA50
static unsigned long __stdcall crc32_combine_(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    int n;
    unsigned long row;
    unsigned long even[GF2_DIM];
    unsigned long odd[GF2_DIM];

    if (len2 <= 0)
        return crc1;

    odd[0] = 0xedb88320UL;
    row = 1;
    for (n = 1; n < GF2_DIM; n++) {
        odd[n] = row;
        row <<= 1;
    }

    gf2_matrix_square(even, odd);

    gf2_matrix_square(odd, even);

    do {
        gf2_matrix_square(even, odd);
        if (len2 & 1)
            crc1 = gf2_matrix_times(even, crc1);
        len2 >>= 1;

        if (len2 == 0)
            break;

        gf2_matrix_square(odd, even);
        if (len2 & 1)
            crc1 = gf2_matrix_times(odd, crc1);
        len2 >>= 1;

    } while (len2 != 0);

    crc1 ^= crc2;
    return crc1;
}

// 0x0042DBC0
unsigned long __fastcall crc32_combine(unsigned long crc1, unsigned long crc2, long len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

// 0x0042DBE0
unsigned long __fastcall crc32_combine64(unsigned long crc1, unsigned long crc2, __int64 len2)
{
    return crc32_combine_(crc1, crc2, len2);
}

#include "gen/data/Source/Storm/zlib/crc32.inc"
