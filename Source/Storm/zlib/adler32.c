// Altered from the original zlib source.
#define BASE 65521
#define NMAX 5552
#define DO1(buf, i) { adler += (buf)[i]; sum2 += adler; }
#define DO2(buf, i) DO1(buf, i); DO1(buf, i + 1);
#define DO4(buf, i) DO2(buf, i); DO2(buf, i + 2);
#define DO8(buf, i) DO4(buf, i); DO4(buf, i + 4);
#define DO16(buf) DO8(buf, 0); DO8(buf, 8);

typedef long z_off_t;
typedef __int64 z_off64_t;

static unsigned long __stdcall adler32_combine_(unsigned long adler1, unsigned long adler2, z_off64_t len2);

// 0x0042B660
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len)
{
    unsigned long sum2;
    unsigned n;

    sum2 = (adler >> 16) & 0xffff;
    adler &= 0xffff;

    if (len == 1)
    {
        adler += buf[0];
        if (adler >= BASE)
            adler -= BASE;
        sum2 += adler;
        if (sum2 >= BASE)
            sum2 -= BASE;
        return adler | (sum2 << 16);
    }

    if (buf == 0)
        return 1L;

    if (len < 16)
    {
        while (len--)
        {
            adler += *buf++;
            sum2 += adler;
        }
        if (adler >= BASE)
            adler -= BASE;
        sum2 %= BASE;
        return adler | (sum2 << 16);
    }

    while (len >= NMAX)
    {
        len -= NMAX;
        n = NMAX / 16;
        do
        {
            DO16(buf);
            buf += 16;
        } while (--n);
        adler %= BASE;
        sum2 %= BASE;
    }

    if (len)
    {
        while (len >= 16)
        {
            len -= 16;
            DO16(buf);
            buf += 16;
        }
        while (len--)
        {
            adler += *buf++;
            sum2 += adler;
        }
        adler %= BASE;
        sum2 %= BASE;
    }

    return adler | (sum2 << 16);
}

// 0x0042B8E0
static unsigned long __stdcall adler32_combine_(unsigned long adler1, unsigned long adler2, z_off64_t len2)
{
    unsigned long sum1;
    unsigned long sum2;
    unsigned rem;

    if (len2 < 0)
        return 0xffffffffUL;
    len2 %= BASE;
    rem = (unsigned)len2;
    sum1 = adler1 & 0xffff;
    sum2 = rem * sum1;
    sum2 %= BASE;
    sum1 += (adler2 & 0xffff) + BASE - 1;
    sum2 += ((adler1 >> 16) & 0xffff) + ((adler2 >> 16) & 0xffff) + BASE - rem;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum2 >= (BASE << 1)) sum2 -= (BASE << 1);
    if (sum2 >= BASE) sum2 -= BASE;
    return sum1 | (sum2 << 16);
}

// 0x0042B990
unsigned long __fastcall adler32_combine(unsigned long adler1, unsigned long adler2, z_off_t len2)
{
    return adler32_combine_(adler1, adler2, len2);
}

// 0x0042B9B0
unsigned long __fastcall adler32_combine64(unsigned long adler1, unsigned long adler2, z_off64_t len2)
{
    return adler32_combine_(adler1, adler2, len2);
}
