#include "Storm.h"
// Altered from the original zlib source.
#define ZLIB_VERSION    "1.2.8"
#define Z_VERSION_ERROR (-6)
#define Z_TREES         6
#define DEF_WBITS       MAX_WBITS
#define ENOUGH          1444
#define ZFREE(strm, addr) (*((strm)->zfree))((strm)->opaque, (void*)(addr))
#define UPDATEWINDOW updatewindow
#define UPDATE(check, buf, len) \
    (state->flags ? crc32(check, buf, len) : adler32(check, buf, len))
#define CRC2(check, word) \
    do { \
        hbuf[0] = (unsigned char)(word); \
        hbuf[1] = (unsigned char)((word) >> 8); \
        check = crc32(check, hbuf, 2); \
    } while (0)
#define CRC4(check, word) \
    do { \
        hbuf[0] = (unsigned char)(word); \
        hbuf[1] = (unsigned char)((word) >> 8); \
        hbuf[2] = (unsigned char)((word) >> 16); \
        hbuf[3] = (unsigned char)((word) >> 24); \
        check = crc32(check, hbuf, 4); \
    } while (0)
#define LOAD() \
    do { \
        put = strm->next_out; \
        left = strm->avail_out; \
        next = strm->next_in; \
        have = strm->avail_in; \
        hold = state->hold; \
        bits = state->bits; \
    } while (0)
#define RESTORE() \
    do { \
        strm->next_out = put; \
        strm->avail_out = left; \
        strm->next_in = next; \
        strm->avail_in = have; \
        state->hold = hold; \
        state->bits = bits; \
    } while (0)
#define INITBITS() \
    do { \
        hold = 0; \
        bits = 0; \
    } while (0)
#define PULLBYTE() \
    do { \
        if (have == 0) goto inf_leave; \
        have--; \
        hold += (unsigned long)(*next++) << bits; \
        bits += 8; \
    } while (0)
#define NEEDBITS(n) \
    do { \
        while (bits < (unsigned)(n)) \
            PULLBYTE(); \
    } while (0)
#define BITS(n) \
    ((unsigned)hold & ((1U << (n)) - 1))
#define DROPBITS(n) \
    do { \
        hold >>= (n); \
        bits -= (unsigned)(n); \
    } while (0)
#define BYTEBITS() \
    do { \
        hold >>= bits & 7; \
        bits -= bits & 7; \
    } while (0)

struct inflate_state;
struct code;
struct gz_header;

struct inflate_state
{
    int mode;
    int last;
    int wrap;
    int havedict;
    int flags;
    unsigned int dmax;
    unsigned long check;
    unsigned long total;
    gz_header* head;
    unsigned int wbits;
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
    unsigned long hold;
    unsigned int bits;
    unsigned int length;
    unsigned int offset;
    unsigned int extra;
    const code* lencode;
    const code* distcode;
    unsigned int lenbits;
    unsigned int distbits;
    unsigned int ncode;
    unsigned int nlen;
    unsigned int ndist;
    unsigned int have;
    code* next;
    unsigned short lens[320];
    unsigned short work[288];
    code codes[1444];
    int sane;
    int back;
    unsigned int was;
};

struct z_stream
{
    const unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char* msg;
    inflate_state* state;
    void* (__fastcall* zalloc)(void* opaque, unsigned int items, unsigned int size);
    void (__fastcall* zfree)(void* opaque, void* address);
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len); // 0x0042B660

typedef enum {
    HEAD,
    FLAGS,
    TIME,
    OS,
    EXLEN,
    EXTRA,
    NAME,
    COMMENT,
    HCRC,
    DICTID,
    DICT,
    TYPE,
    TYPEDO,
    STORED,
    COPY_,
    COPY,
    TABLE,
    LENLENS,
    CODELENS,
    LEN_,
    LEN,
    LENEXT,
    DIST,
    DISTEXT,
    MATCH,
    LIT,
    CHECK,
    LENGTH,
    DONE,
    BAD,
    MEM,
    SYNC
} inflate_mode;

typedef enum {
    CODES,
    LENS = 1,
    DISTS = 2
} codetype;

struct gz_header
{
    int text;
    unsigned long time;
    int xflags;
    int os;
    unsigned char* extra;
    unsigned int extra_len;
    unsigned int extra_max;
    unsigned char* name;
    unsigned int name_max;
    unsigned char* comment;
    unsigned int comm_max;
    int hcrc;
    int done;
};

unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len); // 0x0042DC00
void __fastcall inflate_fast(z_stream* strm, unsigned start); // 0x0042DCA0
int __fastcall inflate_table(codetype type, unsigned short* lens, unsigned codes, code** table, unsigned* bits, unsigned short* work); // 0x0042E120
extern const code lenfix[512]; // 0x006D0300
extern const code distfix[32]; // 0x006D0B00
extern const unsigned short order[19]; // 0x006D0B80

static int __stdcall updatewindow(z_stream* strm, const unsigned char* end, unsigned copy);
static unsigned __stdcall syncsearch(unsigned* have, const unsigned char* buf, unsigned len);
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size); // 0x0042DC70
void __fastcall zcfree(void* opaque, void* ptr); // 0x0042DC90

// 0x00429810
int __fastcall inflateResetKeep(z_stream* strm)
{
    inflate_state* state;

    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    strm->total_in = strm->total_out = state->total = 0;
    strm->msg = 0;
    if (state->wrap)
        strm->adler = state->wrap & 1;
    state->mode = 0;
    state->last = 0;
    state->havedict = 0;
    state->dmax = 32768U;
    state->head = 0;
    state->hold = 0;
    state->bits = 0;
    state->lencode = state->distcode = state->next = state->codes;
    state->sane = 1;
    state->back = -1;
    return 0;
}

// 0x00429880
int __fastcall inflateReset(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    state->wsize = 0;
    state->whave = 0;
    state->wnext = 0;
    return inflateResetKeep(strm);
}

// 0x004298B0
int __fastcall inflateReset2(z_stream* strm, int windowBits)
{
    int wrap;
    inflate_state* state;

    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;

    if (windowBits < 0)
    {
        wrap = 0;
        windowBits = -windowBits;
    }
    else
    {
        wrap = (windowBits >> 4) + 1;
        if (windowBits < 48)
            windowBits &= 15;
    }

    if (windowBits && (windowBits < 8 || windowBits > 15))
        return Z_STREAM_ERROR;
    if (state->window != 0 && state->wbits != (unsigned)windowBits)
    {
        (*strm->zfree)(strm->opaque, state->window);
        state->window = 0;
    }

    state->wrap = wrap;
    state->wbits = (unsigned)windowBits;
    return inflateReset(strm);
}

// 0x00429950
int __fastcall inflateInit2_(z_stream* strm, int windowBits, const char* version, int stream_size)
{
    int ret;
    inflate_state* state;

    if (version == Z_NULL || version[0] != ZLIB_VERSION[0] || stream_size != (int)(sizeof(z_stream)))
        return Z_VERSION_ERROR;
    if (strm == Z_NULL) return Z_STREAM_ERROR;
    strm->msg = Z_NULL;
    if (strm->zalloc == (alloc_func)0)
    {
        strm->zalloc = zcalloc;
        strm->opaque = (void*)0;
    }
    if (strm->zfree == (free_func)0) strm->zfree = zcfree;
    state = (inflate_state*)(*strm->zalloc)(strm->opaque, 1, sizeof(inflate_state));
    if (state == Z_NULL) return Z_MEM_ERROR;
    strm->state = state;
    state->window = Z_NULL;
    ret = inflateReset2(strm, windowBits);
    if (ret != Z_OK)
    {
        (*strm->zfree)(strm->opaque, state);
        strm->state = Z_NULL;
    }
    return ret;
}

// 0x00429A10
int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size)
{
    return inflateInit2_(strm, DEF_WBITS, version, stream_size);
}

// 0x00429A30
int __fastcall inflatePrime(z_stream* strm, int bits, int value)
{
    inflate_state* state;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (bits < 0) {
        state->hold = 0;
        state->bits = 0;
        return Z_OK;
    }
    if (bits > 16 || state->bits + bits > 32) return Z_STREAM_ERROR;
    value &= (1L << bits) - 1;
    state->hold += value << state->bits;
    state->bits += bits;
    return Z_OK;
}

// 0x00429AA0
static void fixedtables(inflate_state* state)
{
    state->lencode = lenfix;
    state->lenbits = 9;
    state->distcode = distfix;
    state->distbits = 5;
}

// 0x00429AC0
static int __stdcall updatewindow(z_stream* strm, const unsigned char* end, unsigned copy)
{
    inflate_state* state;
    unsigned dist;

    state = strm->state;
    if (state->window == 0) {
        state->window = (unsigned char*)(*strm->zalloc)(strm->opaque, 1U << state->wbits, sizeof(unsigned char));
        if (state->window == 0) return 1;
    }
    if (state->wsize == 0) {
        state->wsize = 1U << state->wbits;
        state->wnext = 0;
        state->whave = 0;
    }
    if (copy >= state->wsize) {
        memcpy(state->window, end - state->wsize, state->wsize);
        state->wnext = 0;
        state->whave = state->wsize;
    }
    else {
        dist = state->wsize - state->wnext;
        if (dist > copy) dist = copy;
        memcpy(state->window + state->wnext, end - copy, dist);
        copy -= dist;
        if (copy) {
            memcpy(state->window, end - copy, copy);
            state->wnext = copy;
            state->whave = state->wsize;
        }
        else {
            state->wnext += dist;
            if (state->wnext == state->wsize) state->wnext = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}

// 0x00429BB0
int __fastcall inflate(z_stream* strm, int flush)
{
    inflate_state* state;
    const unsigned char* next;
    unsigned char* put;
    unsigned have, left;
    unsigned long hold;
    unsigned bits;
    unsigned in, out;
    unsigned copy;
    unsigned char* from;
    code here;
    code last;
    unsigned len;
    int ret;
    unsigned char hbuf[4];

    if (strm == 0 || strm->state == 0 || strm->next_out == 0 ||
        (strm->next_in == 0 && strm->avail_in != 0))
        return Z_STREAM_ERROR;

    state = strm->state;
    if (state->mode == TYPE) state->mode = TYPEDO;
    LOAD();
    in = have;
    out = left;
    ret = Z_OK;
    for (;;)
        switch (state->mode) {
        case HEAD:
            if (state->wrap == 0) {
                state->mode = TYPEDO;
                break;
            }
            NEEDBITS(16);
            if ((state->wrap & 2) && hold == 0x8b1f) {
                state->check = crc32(0L, 0, 0);
                CRC2(state->check, hold);
                INITBITS();
                state->mode = FLAGS;
                break;
            }
            state->flags = 0;
            if (state->head != 0)
                state->head->done = -1;
            if (!(state->wrap & 1) ||
                ((BITS(8) << 8) + (hold >> 8)) % 31) {
                strm->msg = "incorrect header check";
                state->mode = BAD;
                break;
            }
            if (BITS(4) != Z_DEFLATED) {
                strm->msg = "unknown compression method";
                state->mode = BAD;
                break;
            }
            DROPBITS(4);
            len = BITS(4) + 8;
            if (state->wbits == 0)
                state->wbits = len;
            else if (len > state->wbits) {
                strm->msg = "invalid window size";
                state->mode = BAD;
                break;
            }
            state->dmax = 1U << len;
            strm->adler = state->check = adler32(0L, 0, 0);
            state->mode = hold & 0x200 ? DICTID : TYPE;
            INITBITS();
            break;
        case FLAGS:
            NEEDBITS(16);
            state->flags = (int)(hold);
            if ((state->flags & 0xff) != Z_DEFLATED) {
                strm->msg = "unknown compression method";
                state->mode = BAD;
                break;
            }
            if (state->flags & 0xe000) {
                strm->msg = "unknown header flags set";
                state->mode = BAD;
                break;
            }
            if (state->head != 0)
                state->head->text = (int)((hold >> 8) & 1);
            if (state->flags & 0x0200) CRC2(state->check, hold);
            INITBITS();
            state->mode = TIME;
        case TIME:
            NEEDBITS(32);
            if (state->head != 0)
                state->head->time = hold;
            if (state->flags & 0x0200) CRC4(state->check, hold);
            INITBITS();
            state->mode = OS;
        case OS:
            NEEDBITS(16);
            if (state->head != 0) {
                state->head->xflags = (int)(hold & 0xff);
                state->head->os = (int)(hold >> 8);
            }
            if (state->flags & 0x0200) CRC2(state->check, hold);
            INITBITS();
            state->mode = EXLEN;
        case EXLEN:
            if (state->flags & 0x0400) {
                NEEDBITS(16);
                state->length = (unsigned)(hold);
                if (state->head != 0)
                    state->head->extra_len = (unsigned)hold;
                if (state->flags & 0x0200) CRC2(state->check, hold);
                INITBITS();
            }
            else if (state->head != 0)
                state->head->extra = 0;
            state->mode = EXTRA;
        case EXTRA:
            if (state->flags & 0x0400) {
                copy = state->length;
                if (copy > have) copy = have;
                if (copy) {
                    if (state->head != 0 &&
                        state->head->extra != 0) {
                        len = state->head->extra_len - state->length;
                        memcpy(state->head->extra + len, next,
                                len + copy > state->head->extra_max ?
                                state->head->extra_max - len : copy);
                    }
                    if (state->flags & 0x0200)
                        state->check = crc32(state->check, next, copy);
                    have -= copy;
                    next += copy;
                    state->length -= copy;
                }
                if (state->length) goto inf_leave;
            }
            state->length = 0;
            state->mode = NAME;
        case NAME:
            if (state->flags & 0x0800) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                    if (state->head != 0 &&
                            state->head->name != 0 &&
                            state->length < state->head->name_max)
                        state->head->name[state->length++] = (unsigned char)len;
                } while (len && copy < have);
                if (state->flags & 0x0200)
                    state->check = crc32(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            }
            else if (state->head != 0)
                state->head->name = 0;
            state->length = 0;
            state->mode = COMMENT;
        case COMMENT:
            if (state->flags & 0x1000) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                    if (state->head != 0 &&
                            state->head->comment != 0 &&
                            state->length < state->head->comm_max)
                        state->head->comment[state->length++] = (unsigned char)len;
                } while (len && copy < have);
                if (state->flags & 0x0200)
                    state->check = crc32(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            }
            else if (state->head != 0)
                state->head->comment = 0;
            state->mode = HCRC;
        case HCRC:
            if (state->flags & 0x0200) {
                NEEDBITS(16);
                if (hold != (state->check & 0xffff)) {
                    strm->msg = "header crc mismatch";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            if (state->head != 0) {
                state->head->hcrc = (int)((state->flags >> 9) & 1);
                state->head->done = 1;
            }
            strm->adler = state->check = crc32(0L, 0, 0);
            state->mode = TYPE;
            break;
        case DICTID:
            NEEDBITS(32);
            strm->adler = state->check = ZSWAP32(hold);
            INITBITS();
            state->mode = DICT;
        case DICT:
            if (state->havedict == 0) {
                RESTORE();
                return Z_NEED_DICT;
            }
            strm->adler = state->check = adler32(0L, 0, 0);
            state->mode = TYPE;
        case TYPE:
            if (flush == Z_BLOCK || flush == Z_TREES) goto inf_leave;
        case TYPEDO:
            if (state->last) {
                BYTEBITS();
                state->mode = CHECK;
                break;
            }
            NEEDBITS(3);
            state->last = BITS(1);
            DROPBITS(1);
            switch (BITS(2)) {
            case 0:
                state->mode = STORED;
                break;
            case 1:
                fixedtables(state);
                state->mode = LEN_;
                if (flush == Z_TREES) {
                    DROPBITS(2);
                    goto inf_leave;
                }
                break;
            case 2:
                state->mode = TABLE;
                break;
            case 3:
                strm->msg = "invalid block type";
                state->mode = BAD;
            }
            DROPBITS(2);
            break;
        case STORED:
            BYTEBITS();
            NEEDBITS(32);
            if ((hold & 0xffff) != ((hold >> 16) ^ 0xffff)) {
                strm->msg = "invalid stored block lengths";
                state->mode = BAD;
                break;
            }
            state->length = (unsigned)hold & 0xffff;
            INITBITS();
            state->mode = COPY_;
            if (flush == Z_TREES) goto inf_leave;
        case COPY_:
            state->mode = COPY;
        case COPY:
            copy = state->length;
            if (copy) {
                if (copy > have) copy = have;
                if (copy > left) copy = left;
                if (copy == 0) goto inf_leave;
                memcpy(put, next, copy);
                have -= copy;
                next += copy;
                left -= copy;
                put += copy;
                state->length -= copy;
                break;
            }
            state->mode = TYPE;
            break;
        case TABLE:
            NEEDBITS(14);
            state->nlen = BITS(5) + 257;
            DROPBITS(5);
            state->ndist = BITS(5) + 1;
            DROPBITS(5);
            state->ncode = BITS(4) + 4;
            DROPBITS(4);
            if (state->nlen > 286 || state->ndist > 30) {
                strm->msg = "too many length or distance symbols";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = LENLENS;
        case LENLENS:
            while (state->have < state->ncode) {
                NEEDBITS(3);
                state->lens[order[state->have++]] = (unsigned short)BITS(3);
                DROPBITS(3);
            }
            while (state->have < 19)
                state->lens[order[state->have++]] = 0;
            state->next = state->codes;
            state->lencode = (const code*)(state->next);
            state->lenbits = 7;
            ret = inflate_table(CODES, state->lens, 19, &(state->next),
                                &(state->lenbits), state->work);
            if (ret) {
                strm->msg = "invalid code lengths set";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = CODELENS;
        case CODELENS:
            while (state->have < state->nlen + state->ndist) {
                for (;;) {
                    here = state->lencode[BITS(state->lenbits)];
                    if ((unsigned)(here.bits) <= bits) break;
                    PULLBYTE();
                }
                if (here.val < 16) {
                    DROPBITS(here.bits);
                    state->lens[state->have++] = here.val;
                }
                else {
                    if (here.val == 16) {
                        NEEDBITS(here.bits + 2);
                        DROPBITS(here.bits);
                        if (state->have == 0) {
                            strm->msg = "invalid bit length repeat";
                            state->mode = BAD;
                            break;
                        }
                        len = state->lens[state->have - 1];
                        copy = 3 + BITS(2);
                        DROPBITS(2);
                    }
                    else if (here.val == 17) {
                        NEEDBITS(here.bits + 3);
                        DROPBITS(here.bits);
                        len = 0;
                        copy = 3 + BITS(3);
                        DROPBITS(3);
                    }
                    else {
                        NEEDBITS(here.bits + 7);
                        DROPBITS(here.bits);
                        len = 0;
                        copy = 11 + BITS(7);
                        DROPBITS(7);
                    }
                    if (state->have + copy > state->nlen + state->ndist) {
                        strm->msg = "invalid bit length repeat";
                        state->mode = BAD;
                        break;
                    }
                    while (copy--)
                        state->lens[state->have++] = (unsigned short)len;
                }
            }

            if (state->mode == BAD) break;

            if (state->lens[256] == 0) {
                strm->msg = "invalid code -- missing end-of-block";
                state->mode = BAD;
                break;
            }

            state->next = state->codes;
            state->lencode = (const code*)(state->next);
            state->lenbits = 9;
            ret = inflate_table(LENS, state->lens, state->nlen, &(state->next),
                                &(state->lenbits), state->work);
            if (ret) {
                strm->msg = "invalid literal/lengths set";
                state->mode = BAD;
                break;
            }
            state->distcode = (const code*)(state->next);
            state->distbits = 6;
            ret = inflate_table(DISTS, state->lens + state->nlen, state->ndist,
                            &(state->next), &(state->distbits), state->work);
            if (ret) {
                strm->msg = "invalid distances set";
                state->mode = BAD;
                break;
            }
            state->mode = LEN_;
            if (flush == Z_TREES) goto inf_leave;
        case LEN_:
            state->mode = LEN;
        case LEN:
            if (have >= 6 && left >= 258) {
                RESTORE();
                inflate_fast(strm, out);
                LOAD();
                if (state->mode == TYPE)
                    state->back = -1;
                break;
            }
            state->back = 0;
            for (;;) {
                here = state->lencode[BITS(state->lenbits)];
                if ((unsigned)(here.bits) <= bits) break;
                PULLBYTE();
            }
            if (here.op && (here.op & 0xf0) == 0) {
                last = here;
                for (;;) {
                    here = state->lencode[last.val +
                            (BITS(last.bits + last.op) >> last.bits)];
                    if ((unsigned)(last.bits + here.bits) <= bits) break;
                    PULLBYTE();
                }
                DROPBITS(last.bits);
                state->back += last.bits;
            }
            DROPBITS(here.bits);
            state->back += here.bits;
            state->length = (unsigned)here.val;
            if ((int)(here.op) == 0) {
                state->mode = LIT;
                break;
            }
            if (here.op & 32) {
                state->back = -1;
                state->mode = TYPE;
                break;
            }
            if (here.op & 64) {
                strm->msg = "invalid literal/length code";
                state->mode = BAD;
                break;
            }
            state->extra = (unsigned)(here.op) & 15;
            state->mode = LENEXT;
        case LENEXT:
            if (state->extra) {
                NEEDBITS(state->extra);
                state->length += BITS(state->extra);
                DROPBITS(state->extra);
                state->back += state->extra;
            }
            state->was = state->length;
            state->mode = DIST;
        case DIST:
            for (;;) {
                here = state->distcode[BITS(state->distbits)];
                if ((unsigned)(here.bits) <= bits) break;
                PULLBYTE();
            }
            if ((here.op & 0xf0) == 0) {
                last = here;
                for (;;) {
                    here = state->distcode[last.val +
                            (BITS(last.bits + last.op) >> last.bits)];
                    if ((unsigned)(last.bits + here.bits) <= bits) break;
                    PULLBYTE();
                }
                DROPBITS(last.bits);
                state->back += last.bits;
            }
            DROPBITS(here.bits);
            state->back += here.bits;
            if (here.op & 64) {
                strm->msg = "invalid distance code";
                state->mode = BAD;
                break;
            }
            state->offset = (unsigned)here.val;
            state->extra = (unsigned)(here.op) & 15;
            state->mode = DISTEXT;
        case DISTEXT:
            if (state->extra) {
                NEEDBITS(state->extra);
                state->offset += BITS(state->extra);
                DROPBITS(state->extra);
                state->back += state->extra;
            }
            state->mode = MATCH;
        case MATCH:
            if (left == 0) goto inf_leave;
            copy = out - left;
            if (state->offset > copy) {
                copy = state->offset - copy;
                if (copy > state->whave) {
                    if (state->sane) {
                        strm->msg = "invalid distance too far back";
                        state->mode = BAD;
                        break;
                    }
                }
                if (copy > state->wnext) {
                    copy -= state->wnext;
                    from = state->window + (state->wsize - copy);
                }
                else
                    from = state->window + (state->wnext - copy);
                if (copy > state->length) copy = state->length;
            }
            else {
                from = put - state->offset;
                copy = state->length;
            }
            if (copy > left) copy = left;
            left -= copy;
            state->length -= copy;
            do {
                *put++ = *from++;
            } while (--copy);
            if (state->length == 0) state->mode = LEN;
            break;
        case LIT:
            if (left == 0) goto inf_leave;
            *put++ = (unsigned char)(state->length);
            left--;
            state->mode = LEN;
            break;
        case CHECK:
            if (state->wrap) {
                NEEDBITS(32);
                out -= left;
                strm->total_out += out;
                state->total += out;
                if (out)
                    strm->adler = state->check =
                        UPDATE(state->check, put - out, out);
                out = left;
                if ((
                     state->flags ? hold :
                     ZSWAP32(hold)) != state->check) {
                    strm->msg = "incorrect data check";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            state->mode = LENGTH;
        case LENGTH:
            if (state->wrap && state->flags) {
                NEEDBITS(32);
                if (hold != (state->total & 0xffffffffUL)) {
                    strm->msg = "incorrect length check";
                    state->mode = BAD;
                    break;
                }
                INITBITS();
            }
            state->mode = DONE;
        case DONE:
            ret = Z_STREAM_END;
            goto inf_leave;
        case BAD:
            ret = Z_DATA_ERROR;
            goto inf_leave;
        case MEM:
            return Z_MEM_ERROR;
        case SYNC:
        default:
            return Z_STREAM_ERROR;
        }

  inf_leave:
    RESTORE();
    if (state->wsize || (out != strm->avail_out && state->mode < BAD &&
            (state->mode < CHECK || flush != Z_FINISH)))
        if (UPDATEWINDOW(strm, strm->next_out, out - strm->avail_out)) {
            state->mode = MEM;
            return Z_MEM_ERROR;
        }
    in -= strm->avail_in;
    out -= strm->avail_out;
    strm->total_in += in;
    strm->total_out += out;
    state->total += out;
    if (state->wrap && out)
        strm->adler = state->check =
            UPDATE(state->check, strm->next_out - out, out);
    strm->data_type = state->bits + (state->last ? 64 : 0) +
                      (state->mode == TYPE ? 128 : 0) +
                      (state->mode == LEN_ || state->mode == COPY_ ? 256 : 0);
    if (((in == 0 && out == 0) || flush == Z_FINISH) && ret == Z_OK)
        ret = Z_BUF_ERROR;
    return ret;
}

// 0x0042B170
int __fastcall inflateEnd(z_stream* strm)
{
    inflate_state* state;
    if (strm == Z_NULL || strm->state == Z_NULL || strm->zfree == (free_func)0)
        return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (state->window != Z_NULL)
        ZFREE(strm, state->window);
    ZFREE(strm, strm->state);
    strm->state = Z_NULL;
    return Z_OK;
}

// 0x0042B1B0
int __fastcall inflateGetDictionary(z_stream* strm, unsigned char* dictionary, unsigned int* dictLength)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if (state->whave && dictionary != 0)
    {
        memcpy(dictionary, state->window + state->wnext, state->whave - state->wnext);
        memcpy(dictionary + state->whave - state->wnext, state->window, state->wnext);
    }
    if (dictLength != 0) *dictLength = state->whave;
    return Z_OK;
}

// 0x0042B220
int __fastcall inflateSetDictionary(z_stream* strm, const unsigned char* dictionary, unsigned dictLength)
{
    inflate_state* state;
    unsigned long dictid;
    int ret;

    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    if (state->wrap != 0 && state->mode != 10)
        return -2;
    if (state->mode == 10) {
        dictid = adler32(0L, 0, 0);
        dictid = adler32(dictid, dictionary, dictLength);
        if (dictid != state->check)
            return -3;
    }
    ret = updatewindow(strm, dictionary + dictLength, dictLength);
    if (ret) {
        state->mode = 30;
        return -4;
    }
    state->havedict = 1;
    return 0;
}

// 0x0042B2D0
int __fastcall inflateGetHeader(z_stream* strm, gz_header* head)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    if ((state->wrap & 2) == 0) return Z_STREAM_ERROR;
    state->head = head;
    head->done = 0;
    return Z_OK;
}

// 0x0042B300
static unsigned __stdcall syncsearch(unsigned* have, const unsigned char* buf, unsigned len)
{
    unsigned got;
    unsigned next;

    got = *have;
    next = 0;
    while (next < len && got < 4) {
        if ((int)(buf[next]) == (got < 2 ? 0 : 0xff))
            got++;
        else if (buf[next])
            got = 0;
        else
            got = 4 - got;
        next++;
    }
    *have = got;
    return next;
}

// 0x0042B360
int __fastcall inflateSync(z_stream* strm)
{
    unsigned len;
    unsigned long in, out;
    unsigned char buf[4];
    inflate_state* state;

    if (strm == 0 || strm->state == 0) return -2;
    state = strm->state;
    if (strm->avail_in == 0 && state->bits < 8) return -5;

    if (state->mode != 31) {
        state->mode = 31;
        state->hold <<= state->bits & 7;
        state->bits -= state->bits & 7;
        len = 0;
        while (state->bits >= 8) {
            buf[len++] = (unsigned char)(state->hold);
            state->hold >>= 8;
            state->bits -= 8;
        }
        state->have = 0;
        syncsearch(&(state->have), buf, len);
    }

    len = syncsearch(&(state->have), strm->next_in, strm->avail_in);
    strm->avail_in -= len;
    strm->next_in += len;
    strm->total_in += len;

    if (state->have != 4) return -3;
    in = strm->total_in;  out = strm->total_out;
    inflateReset(strm);
    strm->total_in = in;  strm->total_out = out;
    state->mode = 11;
    return 0;
}

// 0x0042B460
int __fastcall inflateSyncPoint(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    return state->mode == STORED && state->bits == 0;
}

// 0x0042B490
int __fastcall inflateCopy(z_stream* dest, z_stream* source)
{
    inflate_state* state;
    inflate_state* copy;
    unsigned char* window;
    unsigned int wsize;

    if (dest == Z_NULL || source == Z_NULL || source->state == Z_NULL || source->zalloc == 0 || source->zfree == 0)
        return Z_STREAM_ERROR;
    state = (inflate_state*)source->state;

    copy = (inflate_state*)source->zalloc(source->opaque, 1, sizeof(inflate_state));
    if (copy == Z_NULL) return Z_MEM_ERROR;
    window = Z_NULL;
    if (state->window != Z_NULL) {
        window = (unsigned char*)source->zalloc(source->opaque, 1U << state->wbits, sizeof(unsigned char));
        if (window == Z_NULL) {
            source->zfree(source->opaque, copy);
            return Z_MEM_ERROR;
        }
    }

    memcpy(dest, source, sizeof(z_stream));
    memcpy(copy, state, sizeof(inflate_state));
    if (state->lencode >= state->codes && state->lencode <= state->codes + ENOUGH - 1) {
        copy->lencode = copy->codes + (state->lencode - state->codes);
        copy->distcode = copy->codes + (state->distcode - state->codes);
    }
    copy->next = copy->codes + (state->next - state->codes);
    if (window != Z_NULL) {
        wsize = 1U << state->wbits;
        memcpy(window, state->window, wsize);
    }
    copy->window = window;
    dest->state = copy;
    return Z_OK;
}

// 0x0042B5E0
int __fastcall inflateUndermine(z_stream* strm, int subvert)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    state = (inflate_state*)strm->state;
    state->sane = 1;
    return Z_DATA_ERROR;
}

// 0x0042B610
long __fastcall inflateMark(z_stream* strm)
{
    inflate_state* state;
    if (strm == 0 || strm->state == 0) return -1L << 16;
    state = (inflate_state*)strm->state;
    return ((long)(state->back) << 16) +
        (state->mode == COPY ? state->length :
            (state->mode == MATCH ? state->was - state->length : 0));
}

extern "C" const code gData_006D0300[512] = { // 0x006D0300
    { 96, 0x7, 0 },
    { 0, 0x8, 80 },
    { 0, 0x8, 16 },
    { 20, 0x8, 115 },
    { 18, 0x7, 31 },
    { 0, 0x8, 112 },
    { 0, 0x8, 48 },
    { 0, 0x9, 192 },
    { 16, 0x7, 10 },
    { 0, 0x8, 96 },
    { 0, 0x8, 32 },
    { 0, 0x9, 160 },
    { 0, 0x8, 0 },
    { 0, 0x8, 128 },
    { 0, 0x8, 64 },
    { 0, 0x9, 224 },
    { 16, 0x7, 6 },
    { 0, 0x8, 88 },
    { 0, 0x8, 24 },
    { 0, 0x9, 144 },
    { 19, 0x7, 59 },
    { 0, 0x8, 120 },
    { 0, 0x8, 56 },
    { 0, 0x9, 208 },
    { 17, 0x7, 17 },
    { 0, 0x8, 104 },
    { 0, 0x8, 40 },
    { 0, 0x9, 176 },
    { 0, 0x8, 8 },
    { 0, 0x8, 136 },
    { 0, 0x8, 72 },
    { 0, 0x9, 240 },
    { 16, 0x7, 4 },
    { 0, 0x8, 84 },
    { 0, 0x8, 20 },
    { 21, 0x8, 227 },
    { 19, 0x7, 43 },
    { 0, 0x8, 116 },
    { 0, 0x8, 52 },
    { 0, 0x9, 200 },
    { 17, 0x7, 13 },
    { 0, 0x8, 100 },
    { 0, 0x8, 36 },
    { 0, 0x9, 168 },
    { 0, 0x8, 4 },
    { 0, 0x8, 132 },
    { 0, 0x8, 68 },
    { 0, 0x9, 232 },
    { 16, 0x7, 8 },
    { 0, 0x8, 92 },
    { 0, 0x8, 28 },
    { 0, 0x9, 152 },
    { 20, 0x7, 83 },
    { 0, 0x8, 124 },
    { 0, 0x8, 60 },
    { 0, 0x9, 216 },
    { 18, 0x7, 23 },
    { 0, 0x8, 108 },
    { 0, 0x8, 44 },
    { 0, 0x9, 184 },
    { 0, 0x8, 12 },
    { 0, 0x8, 140 },
    { 0, 0x8, 76 },
    { 0, 0x9, 248 },
    { 16, 0x7, 3 },
    { 0, 0x8, 82 },
    { 0, 0x8, 18 },
    { 21, 0x8, 163 },
    { 19, 0x7, 35 },
    { 0, 0x8, 114 },
    { 0, 0x8, 50 },
    { 0, 0x9, 196 },
    { 17, 0x7, 11 },
    { 0, 0x8, 98 },
    { 0, 0x8, 34 },
    { 0, 0x9, 164 },
    { 0, 0x8, 2 },
    { 0, 0x8, 130 },
    { 0, 0x8, 66 },
    { 0, 0x9, 228 },
    { 16, 0x7, 7 },
    { 0, 0x8, 90 },
    { 0, 0x8, 26 },
    { 0, 0x9, 148 },
    { 20, 0x7, 67 },
    { 0, 0x8, 122 },
    { 0, 0x8, 58 },
    { 0, 0x9, 212 },
    { 18, 0x7, 19 },
    { 0, 0x8, 106 },
    { 0, 0x8, 42 },
    { 0, 0x9, 180 },
    { 0, 0x8, 10 },
    { 0, 0x8, 138 },
    { 0, 0x8, 74 },
    { 0, 0x9, 244 },
    { 16, 0x7, 5 },
    { 0, 0x8, 86 },
    { 0, 0x8, 22 },
    { 64, 0x8, 0 },
    { 19, 0x7, 51 },
    { 0, 0x8, 118 },
    { 0, 0x8, 54 },
    { 0, 0x9, 204 },
    { 17, 0x7, 15 },
    { 0, 0x8, 102 },
    { 0, 0x8, 38 },
    { 0, 0x9, 172 },
    { 0, 0x8, 6 },
    { 0, 0x8, 134 },
    { 0, 0x8, 70 },
    { 0, 0x9, 236 },
    { 16, 0x7, 9 },
    { 0, 0x8, 94 },
    { 0, 0x8, 30 },
    { 0, 0x9, 156 },
    { 20, 0x7, 99 },
    { 0, 0x8, 126 },
    { 0, 0x8, 62 },
    { 0, 0x9, 220 },
    { 18, 0x7, 27 },
    { 0, 0x8, 110 },
    { 0, 0x8, 46 },
    { 0, 0x9, 188 },
    { 0, 0x8, 14 },
    { 0, 0x8, 142 },
    { 0, 0x8, 78 },
    { 0, 0x9, 252 },
    { 96, 0x7, 0 },
    { 0, 0x8, 81 },
    { 0, 0x8, 17 },
    { 21, 0x8, 131 },
    { 18, 0x7, 31 },
    { 0, 0x8, 113 },
    { 0, 0x8, 49 },
    { 0, 0x9, 194 },
    { 16, 0x7, 10 },
    { 0, 0x8, 97 },
    { 0, 0x8, 33 },
    { 0, 0x9, 162 },
    { 0, 0x8, 1 },
    { 0, 0x8, 129 },
    { 0, 0x8, 65 },
    { 0, 0x9, 226 },
    { 16, 0x7, 6 },
    { 0, 0x8, 89 },
    { 0, 0x8, 25 },
    { 0, 0x9, 146 },
    { 19, 0x7, 59 },
    { 0, 0x8, 121 },
    { 0, 0x8, 57 },
    { 0, 0x9, 210 },
    { 17, 0x7, 17 },
    { 0, 0x8, 105 },
    { 0, 0x8, 41 },
    { 0, 0x9, 178 },
    { 0, 0x8, 9 },
    { 0, 0x8, 137 },
    { 0, 0x8, 73 },
    { 0, 0x9, 242 },
    { 16, 0x7, 4 },
    { 0, 0x8, 85 },
    { 0, 0x8, 21 },
    { 16, 0x8, 258 },
    { 19, 0x7, 43 },
    { 0, 0x8, 117 },
    { 0, 0x8, 53 },
    { 0, 0x9, 202 },
    { 17, 0x7, 13 },
    { 0, 0x8, 101 },
    { 0, 0x8, 37 },
    { 0, 0x9, 170 },
    { 0, 0x8, 5 },
    { 0, 0x8, 133 },
    { 0, 0x8, 69 },
    { 0, 0x9, 234 },
    { 16, 0x7, 8 },
    { 0, 0x8, 93 },
    { 0, 0x8, 29 },
    { 0, 0x9, 154 },
    { 20, 0x7, 83 },
    { 0, 0x8, 125 },
    { 0, 0x8, 61 },
    { 0, 0x9, 218 },
    { 18, 0x7, 23 },
    { 0, 0x8, 109 },
    { 0, 0x8, 45 },
    { 0, 0x9, 186 },
    { 0, 0x8, 13 },
    { 0, 0x8, 141 },
    { 0, 0x8, 77 },
    { 0, 0x9, 250 },
    { 16, 0x7, 3 },
    { 0, 0x8, 83 },
    { 0, 0x8, 19 },
    { 21, 0x8, 195 },
    { 19, 0x7, 35 },
    { 0, 0x8, 115 },
    { 0, 0x8, 51 },
    { 0, 0x9, 198 },
    { 17, 0x7, 11 },
    { 0, 0x8, 99 },
    { 0, 0x8, 35 },
    { 0, 0x9, 166 },
    { 0, 0x8, 3 },
    { 0, 0x8, 131 },
    { 0, 0x8, 67 },
    { 0, 0x9, 230 },
    { 16, 0x7, 7 },
    { 0, 0x8, 91 },
    { 0, 0x8, 27 },
    { 0, 0x9, 150 },
    { 20, 0x7, 67 },
    { 0, 0x8, 123 },
    { 0, 0x8, 59 },
    { 0, 0x9, 214 },
    { 18, 0x7, 19 },
    { 0, 0x8, 107 },
    { 0, 0x8, 43 },
    { 0, 0x9, 182 },
    { 0, 0x8, 11 },
    { 0, 0x8, 139 },
    { 0, 0x8, 75 },
    { 0, 0x9, 246 },
    { 16, 0x7, 5 },
    { 0, 0x8, 87 },
    { 0, 0x8, 23 },
    { 64, 0x8, 0 },
    { 19, 0x7, 51 },
    { 0, 0x8, 119 },
    { 0, 0x8, 55 },
    { 0, 0x9, 206 },
    { 17, 0x7, 15 },
    { 0, 0x8, 103 },
    { 0, 0x8, 39 },
    { 0, 0x9, 174 },
    { 0, 0x8, 7 },
    { 0, 0x8, 135 },
    { 0, 0x8, 71 },
    { 0, 0x9, 238 },
    { 16, 0x7, 9 },
    { 0, 0x8, 95 },
    { 0, 0x8, 31 },
    { 0, 0x9, 158 },
    { 20, 0x7, 99 },
    { 0, 0x8, 127 },
    { 0, 0x8, 63 },
    { 0, 0x9, 222 },
    { 18, 0x7, 27 },
    { 0, 0x8, 111 },
    { 0, 0x8, 47 },
    { 0, 0x9, 190 },
    { 0, 0x8, 15 },
    { 0, 0x8, 143 },
    { 0, 0x8, 79 },
    { 0, 0x9, 254 },
    { 96, 0x7, 0 },
    { 0, 0x8, 80 },
    { 0, 0x8, 16 },
    { 20, 0x8, 115 },
    { 18, 0x7, 31 },
    { 0, 0x8, 112 },
    { 0, 0x8, 48 },
    { 0, 0x9, 193 },
    { 16, 0x7, 10 },
    { 0, 0x8, 96 },
    { 0, 0x8, 32 },
    { 0, 0x9, 161 },
    { 0, 0x8, 0 },
    { 0, 0x8, 128 },
    { 0, 0x8, 64 },
    { 0, 0x9, 225 },
    { 16, 0x7, 6 },
    { 0, 0x8, 88 },
    { 0, 0x8, 24 },
    { 0, 0x9, 145 },
    { 19, 0x7, 59 },
    { 0, 0x8, 120 },
    { 0, 0x8, 56 },
    { 0, 0x9, 209 },
    { 17, 0x7, 17 },
    { 0, 0x8, 104 },
    { 0, 0x8, 40 },
    { 0, 0x9, 177 },
    { 0, 0x8, 8 },
    { 0, 0x8, 136 },
    { 0, 0x8, 72 },
    { 0, 0x9, 241 },
    { 16, 0x7, 4 },
    { 0, 0x8, 84 },
    { 0, 0x8, 20 },
    { 21, 0x8, 227 },
    { 19, 0x7, 43 },
    { 0, 0x8, 116 },
    { 0, 0x8, 52 },
    { 0, 0x9, 201 },
    { 17, 0x7, 13 },
    { 0, 0x8, 100 },
    { 0, 0x8, 36 },
    { 0, 0x9, 169 },
    { 0, 0x8, 4 },
    { 0, 0x8, 132 },
    { 0, 0x8, 68 },
    { 0, 0x9, 233 },
    { 16, 0x7, 8 },
    { 0, 0x8, 92 },
    { 0, 0x8, 28 },
    { 0, 0x9, 153 },
    { 20, 0x7, 83 },
    { 0, 0x8, 124 },
    { 0, 0x8, 60 },
    { 0, 0x9, 217 },
    { 18, 0x7, 23 },
    { 0, 0x8, 108 },
    { 0, 0x8, 44 },
    { 0, 0x9, 185 },
    { 0, 0x8, 12 },
    { 0, 0x8, 140 },
    { 0, 0x8, 76 },
    { 0, 0x9, 249 },
    { 16, 0x7, 3 },
    { 0, 0x8, 82 },
    { 0, 0x8, 18 },
    { 21, 0x8, 163 },
    { 19, 0x7, 35 },
    { 0, 0x8, 114 },
    { 0, 0x8, 50 },
    { 0, 0x9, 197 },
    { 17, 0x7, 11 },
    { 0, 0x8, 98 },
    { 0, 0x8, 34 },
    { 0, 0x9, 165 },
    { 0, 0x8, 2 },
    { 0, 0x8, 130 },
    { 0, 0x8, 66 },
    { 0, 0x9, 229 },
    { 16, 0x7, 7 },
    { 0, 0x8, 90 },
    { 0, 0x8, 26 },
    { 0, 0x9, 149 },
    { 20, 0x7, 67 },
    { 0, 0x8, 122 },
    { 0, 0x8, 58 },
    { 0, 0x9, 213 },
    { 18, 0x7, 19 },
    { 0, 0x8, 106 },
    { 0, 0x8, 42 },
    { 0, 0x9, 181 },
    { 0, 0x8, 10 },
    { 0, 0x8, 138 },
    { 0, 0x8, 74 },
    { 0, 0x9, 245 },
    { 16, 0x7, 5 },
    { 0, 0x8, 86 },
    { 0, 0x8, 22 },
    { 64, 0x8, 0 },
    { 19, 0x7, 51 },
    { 0, 0x8, 118 },
    { 0, 0x8, 54 },
    { 0, 0x9, 205 },
    { 17, 0x7, 15 },
    { 0, 0x8, 102 },
    { 0, 0x8, 38 },
    { 0, 0x9, 173 },
    { 0, 0x8, 6 },
    { 0, 0x8, 134 },
    { 0, 0x8, 70 },
    { 0, 0x9, 237 },
    { 16, 0x7, 9 },
    { 0, 0x8, 94 },
    { 0, 0x8, 30 },
    { 0, 0x9, 157 },
    { 20, 0x7, 99 },
    { 0, 0x8, 126 },
    { 0, 0x8, 62 },
    { 0, 0x9, 221 },
    { 18, 0x7, 27 },
    { 0, 0x8, 110 },
    { 0, 0x8, 46 },
    { 0, 0x9, 189 },
    { 0, 0x8, 14 },
    { 0, 0x8, 142 },
    { 0, 0x8, 78 },
    { 0, 0x9, 253 },
    { 96, 0x7, 0 },
    { 0, 0x8, 81 },
    { 0, 0x8, 17 },
    { 21, 0x8, 131 },
    { 18, 0x7, 31 },
    { 0, 0x8, 113 },
    { 0, 0x8, 49 },
    { 0, 0x9, 195 },
    { 16, 0x7, 10 },
    { 0, 0x8, 97 },
    { 0, 0x8, 33 },
    { 0, 0x9, 163 },
    { 0, 0x8, 1 },
    { 0, 0x8, 129 },
    { 0, 0x8, 65 },
    { 0, 0x9, 227 },
    { 16, 0x7, 6 },
    { 0, 0x8, 89 },
    { 0, 0x8, 25 },
    { 0, 0x9, 147 },
    { 19, 0x7, 59 },
    { 0, 0x8, 121 },
    { 0, 0x8, 57 },
    { 0, 0x9, 211 },
    { 17, 0x7, 17 },
    { 0, 0x8, 105 },
    { 0, 0x8, 41 },
    { 0, 0x9, 179 },
    { 0, 0x8, 9 },
    { 0, 0x8, 137 },
    { 0, 0x8, 73 },
    { 0, 0x9, 243 },
    { 16, 0x7, 4 },
    { 0, 0x8, 85 },
    { 0, 0x8, 21 },
    { 16, 0x8, 258 },
    { 19, 0x7, 43 },
    { 0, 0x8, 117 },
    { 0, 0x8, 53 },
    { 0, 0x9, 203 },
    { 17, 0x7, 13 },
    { 0, 0x8, 101 },
    { 0, 0x8, 37 },
    { 0, 0x9, 171 },
    { 0, 0x8, 5 },
    { 0, 0x8, 133 },
    { 0, 0x8, 69 },
    { 0, 0x9, 235 },
    { 16, 0x7, 8 },
    { 0, 0x8, 93 },
    { 0, 0x8, 29 },
    { 0, 0x9, 155 },
    { 20, 0x7, 83 },
    { 0, 0x8, 125 },
    { 0, 0x8, 61 },
    { 0, 0x9, 219 },
    { 18, 0x7, 23 },
    { 0, 0x8, 109 },
    { 0, 0x8, 45 },
    { 0, 0x9, 187 },
    { 0, 0x8, 13 },
    { 0, 0x8, 141 },
    { 0, 0x8, 77 },
    { 0, 0x9, 251 },
    { 16, 0x7, 3 },
    { 0, 0x8, 83 },
    { 0, 0x8, 19 },
    { 21, 0x8, 195 },
    { 19, 0x7, 35 },
    { 0, 0x8, 115 },
    { 0, 0x8, 51 },
    { 0, 0x9, 199 },
    { 17, 0x7, 11 },
    { 0, 0x8, 99 },
    { 0, 0x8, 35 },
    { 0, 0x9, 167 },
    { 0, 0x8, 3 },
    { 0, 0x8, 131 },
    { 0, 0x8, 67 },
    { 0, 0x9, 231 },
    { 16, 0x7, 7 },
    { 0, 0x8, 91 },
    { 0, 0x8, 27 },
    { 0, 0x9, 151 },
    { 20, 0x7, 67 },
    { 0, 0x8, 123 },
    { 0, 0x8, 59 },
    { 0, 0x9, 215 },
    { 18, 0x7, 19 },
    { 0, 0x8, 107 },
    { 0, 0x8, 43 },
    { 0, 0x9, 183 },
    { 0, 0x8, 11 },
    { 0, 0x8, 139 },
    { 0, 0x8, 75 },
    { 0, 0x9, 247 },
    { 16, 0x7, 5 },
    { 0, 0x8, 87 },
    { 0, 0x8, 23 },
    { 64, 0x8, 0 },
    { 19, 0x7, 51 },
    { 0, 0x8, 119 },
    { 0, 0x8, 55 },
    { 0, 0x9, 207 },
    { 17, 0x7, 15 },
    { 0, 0x8, 103 },
    { 0, 0x8, 39 },
    { 0, 0x9, 175 },
    { 0, 0x8, 7 },
    { 0, 0x8, 135 },
    { 0, 0x8, 71 },
    { 0, 0x9, 239 },
    { 16, 0x7, 9 },
    { 0, 0x8, 95 },
    { 0, 0x8, 31 },
    { 0, 0x9, 159 },
    { 20, 0x7, 99 },
    { 0, 0x8, 127 },
    { 0, 0x8, 63 },
    { 0, 0x9, 223 },
    { 18, 0x7, 27 },
    { 0, 0x8, 111 },
    { 0, 0x8, 47 },
    { 0, 0x9, 191 },
    { 0, 0x8, 15 },
    { 0, 0x8, 143 },
    { 0, 0x8, 79 },
    { 0, 0x9, 255 }
};
#pragma comment(linker, "/alternatename:?lenfix_006D0300@@3QBUcode@@B=_gData_006D0300")

extern "C" const code gData_006D0B00[32] = { // 0x006D0B00
    { 16, 0x5, 1 },
    { 23, 0x5, 257 },
    { 19, 0x5, 17 },
    { 27, 0x5, 4097 },
    { 17, 0x5, 5 },
    { 25, 0x5, 1025 },
    { 21, 0x5, 65 },
    { 29, 0x5, 16385 },
    { 16, 0x5, 3 },
    { 24, 0x5, 513 },
    { 20, 0x5, 33 },
    { 28, 0x5, 8193 },
    { 18, 0x5, 9 },
    { 26, 0x5, 2049 },
    { 22, 0x5, 129 },
    { 64, 0x5, 0 },
    { 16, 0x5, 2 },
    { 23, 0x5, 385 },
    { 19, 0x5, 25 },
    { 27, 0x5, 6145 },
    { 17, 0x5, 7 },
    { 25, 0x5, 1537 },
    { 21, 0x5, 97 },
    { 29, 0x5, 24577 },
    { 16, 0x5, 4 },
    { 24, 0x5, 769 },
    { 20, 0x5, 49 },
    { 28, 0x5, 12289 },
    { 18, 0x5, 13 },
    { 26, 0x5, 3073 },
    { 22, 0x5, 193 },
    { 64, 0x5, 0 }
};
#pragma comment(linker, "/alternatename:?distfix_006D0B00@@3QBUcode@@B=_gData_006D0B00")

extern "C" const unsigned short gData_006D0B80[19] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15 }; // 0x006D0B80
#pragma comment(linker, "/alternatename:?order_006D0B80@@3QBGB=_gData_006D0B80")
