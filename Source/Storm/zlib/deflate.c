// Altered from the original zlib source.
#define Z_NULL 0
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_STREAM_ERROR (-2)
#define Z_BUF_ERROR (-5)
#define Z_NEED_DICT 2
#define Z_NO_FLUSH 0
#define Z_PARTIAL_FLUSH 1
#define Z_FULL_FLUSH 3
#define Z_FINISH 4
#define Z_BLOCK 5
#define Z_DATA_ERROR (-3)
#define Z_MEM_ERROR (-4)
#define Z_VERSION_ERROR (-6)
#define Z_FIXED 4
#define Z_DEFAULT_COMPRESSION (-1)
#define Z_DEFAULT_STRATEGY 0
#define Z_UNKNOWN 2
#define ZLIB_VERSION "1.2.8"
#define MAX_WBITS 15
#define MAX_MEM_LEVEL 9
#define DEF_MEM_LEVEL 8
#define Buf_size 16

const char deflate_copyright[] = " deflate 1.2.8 Copyright 1995-2013 Jean-loup Gailly and Mark Adler "; // 0x006D0238
#define Z_FILTERED 1
#define Z_HUFFMAN_ONLY 2
#define Z_RLE 3
#define Z_DEFLATED 8
#define NIL 0
#define MIN_MATCH 3
#define MAX_MATCH 258
#define MIN_LOOKAHEAD (MAX_MATCH + MIN_MATCH + 1)
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)
#define WIN_INIT MAX_MATCH
#define TOO_FAR 4096
#define LITERALS 256
#define PRESET_DICT 0x20
#define OS_CODE 0x0b
#define INIT_STATE 42
#define EXTRA_STATE 69
#define NAME_STATE 73
#define COMMENT_STATE 91
#define HCRC_STATE 103
#define BUSY_STATE 113
#define FINISH_STATE 666

typedef enum
{
    need_more,
    block_done,
    finish_started,
    finish_done
} block_state;

typedef struct deflate_state deflate_state;
typedef struct z_stream z_stream;
typedef struct gz_header gz_header;
typedef struct config config;
typedef struct ct_data ct_data;
typedef struct static_tree_desc static_tree_desc;
typedef struct tree_desc tree_desc;
typedef block_state (__fastcall* compress_func)(deflate_state* s, int flush);
typedef void* (__fastcall* alloc_func)(void* opaque, unsigned int items, unsigned int size);
typedef void (__fastcall* free_func)(void* opaque, void* address);

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

struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char* msg;
    deflate_state* state;
    alloc_func zalloc;
    free_func zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

struct ct_data
{
    union { unsigned short freq; unsigned short code; } fc;
    union { unsigned short dad; unsigned short len; } dl;
};

struct static_tree_desc;

struct tree_desc
{
    ct_data* dyn_tree;
    int max_code;
    static_tree_desc* stat_desc;
};

struct deflate_state
{
    z_stream* strm;
    int status;
    unsigned char* pending_buf;
    unsigned long pending_buf_size;
    unsigned char* pending_out;
    unsigned int pending;
    int wrap;
    gz_header* gzhead;
    unsigned int gzindex;
    unsigned char method;
    int last_flush;
    unsigned int w_size;
    unsigned int w_bits;
    unsigned int w_mask;
    unsigned char* window;
    unsigned long window_size;
    unsigned short* prev;
    unsigned short* head;
    unsigned int ins_h;
    unsigned int hash_size;
    unsigned int hash_bits;
    unsigned int hash_mask;
    unsigned int hash_shift;
    long block_start;
    unsigned int match_length;
    unsigned int prev_match;
    int match_available;
    unsigned int strstart;
    unsigned int match_start;
    unsigned int lookahead;
    unsigned int prev_length;
    unsigned int max_chain_length;
    unsigned int max_lazy_match;
    int level;
    int strategy;
    unsigned int good_match;
    int nice_match;
    ct_data dyn_ltree[573];
    ct_data dyn_dtree[61];
    ct_data bl_tree[39];
    tree_desc l_desc;
    tree_desc d_desc;
    tree_desc bl_desc;
    unsigned short bl_count[16];
    int heap[573];
    int heap_len;
    int heap_max;
    unsigned char depth[573];
    unsigned char* l_buf;
    unsigned int lit_bufsize;
    unsigned int last_lit;
    unsigned short* d_buf;
    unsigned long opt_len;
    unsigned long static_len;
    unsigned int matches;
    unsigned int insert;
    unsigned short bi_buf;
    int bi_valid;
    unsigned long high_water;
};

struct config
{
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    compress_func func;
};

void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned long __fastcall adler32(unsigned long adler, const unsigned char* buf, unsigned int len);          // 0x0042B660
unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len);              // 0x0042DC00
void __fastcall _tr_stored_block(deflate_state* s, char* buf, unsigned long stored_len, int last);         // 0x0042D0A0
void __fastcall _tr_flush_bits(deflate_state* s);                                                           // 0x0042D150
void __fastcall _tr_align(deflate_state* s);                                                                // 0x0042D160
void __fastcall _tr_flush_block(deflate_state* s, char* buf, unsigned long stored_len, int last);          // 0x0042D250
extern const char* const z_errmsg[10];                                                                      // 0x006D3848
extern config configuration_table[10];                                                                      // 0x006D0280
extern const unsigned char _dist_code[];                                                              // 0x006D13D8
extern const unsigned char _length_code[];                                                            // 0x006D15D8
void __fastcall _tr_init(deflate_state* s);                                                                 // 0x0042CCD0
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size);                              // 0x0042DC70
void __fastcall zcfree(void* opaque, void* ptr);                                                            // 0x0042DC90
int __fastcall deflateEnd(z_stream* strm);                                                                  // 0x004274A0
int __fastcall deflateReset(z_stream* strm);                                                                // 0x00428C40
int __fastcall deflate(z_stream* strm, int flush);                                                          // 0x00428C60
int __fastcall deflateInit2_(z_stream* strm, int level, int method, int windowBits, int memLevel, int strategy, const char* version, int stream_size); // 0x004294C0
static void fill_window(deflate_state* s);
block_state __fastcall deflate_stored(deflate_state* s, int flush);
block_state __fastcall deflate_fast(deflate_state* s, int flush);
block_state __fastcall deflate_slow(deflate_state* s, int flush);
static block_state __stdcall deflate_rle(deflate_state* s, int flush);
static block_state __stdcall deflate_huff(deflate_state* s, int flush);
static void lm_init(deflate_state* s);
static void putShortMSB(deflate_state* s, unsigned int b);
static void flush_pending(z_stream* strm);
static unsigned read_buf(z_stream* strm, unsigned char* buf, unsigned size);
static unsigned int __stdcall longest_match(deflate_state* s, unsigned int cur_match);

#define ZFREE(strm, addr) (*((strm)->zfree))((strm)->opaque, (void*)(addr))
#define TRY_FREE(s, p) { if (p) ZFREE(s, p); }
#define ERR_MSG(err) z_errmsg[Z_NEED_DICT - (err)]
#define ERR_RETURN(strm, err) return (strm->msg = (char*)ERR_MSG(err), (err))
#define put_byte(s, c) { s->pending_buf[s->pending++] = (c); }
#define UPDATE_HASH(s, h, c) (h = (((h) << s->hash_shift) ^ (c)) & s->hash_mask)
#define INSERT_STRING(s, str, match_head) \
    (UPDATE_HASH(s, s->ins_h, s->window[(str) + (MIN_MATCH - 1)]), \
     match_head = s->prev[(str) & s->w_mask] = s->head[s->ins_h], \
     s->head[s->ins_h] = (unsigned short)(str))
#define CLEAR_HASH(s) \
    s->head[s->hash_size - 1] = NIL; \
    memset((unsigned char*)s->head, 0, (unsigned)(s->hash_size - 1) * sizeof(*s->head));
#define d_code(dist) ((dist) < 256 ? _dist_code[dist] : _dist_code[256 + ((dist) >> 7)])
#define _tr_tally_lit(s, c, flush) \
  { unsigned char cc = (c); \
    s->d_buf[s->last_lit] = 0; \
    s->l_buf[s->last_lit++] = cc; \
    s->dyn_ltree[cc].fc.freq++; \
    flush = (s->last_lit == s->lit_bufsize - 1); \
  }
#define _tr_tally_dist(s, distance, length, flush) \
  { unsigned char len = (unsigned char)(length); \
    unsigned short dist = (unsigned short)(distance); \
    s->d_buf[s->last_lit] = dist; \
    s->l_buf[s->last_lit++] = len; \
    dist--; \
    s->dyn_ltree[_length_code[len] + LITERALS + 1].fc.freq++; \
    s->dyn_dtree[d_code(dist)].fc.freq++; \
    flush = (s->last_lit == s->lit_bufsize - 1); \
  }
#define FLUSH_BLOCK_ONLY(s, last) { \
    _tr_flush_block(s, (s->block_start >= 0L ? \
                    (char*)&s->window[(unsigned)s->block_start] : \
                    (char*)Z_NULL), \
                    (unsigned long)((long)s->strstart - s->block_start), \
                    (last)); \
    s->block_start = s->strstart; \
    flush_pending(s->strm); \
}
#define FLUSH_BLOCK(s, last) { \
    FLUSH_BLOCK_ONLY(s, last); \
    if (s->strm->avail_out == 0) return (last) ? finish_started : need_more; \
}
#define RANK(f) (((f) << 1) - ((f) > 4 ? 9 : 0))

// 0x004297F0
int __fastcall deflateInit_(z_stream* strm, int level, const char* version, int stream_size)
{
    return deflateInit2_(strm, level, Z_DEFLATED, MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY, version, stream_size);
}

// 0x004294C0
int __fastcall deflateInit2_(z_stream* strm, int level, int method, int windowBits, int memLevel, int strategy, const char* version, int stream_size)
{
    deflate_state* s;
    int wrap = 1;
    unsigned short* overlay;

    if (version == Z_NULL || version[0] != ZLIB_VERSION[0] || stream_size != sizeof(z_stream))
    {
        return Z_VERSION_ERROR;
    }
    if (strm == Z_NULL) return Z_STREAM_ERROR;

    strm->msg = Z_NULL;
    if (strm->zalloc == (alloc_func)0)
    {
        strm->zalloc = zcalloc;
        strm->opaque = (void*)0;
    }
    if (strm->zfree == (free_func)0) strm->zfree = zcfree;

    if (level == Z_DEFAULT_COMPRESSION) level = 6;

    if (windowBits < 0)
    {
        wrap = 0;
        windowBits = -windowBits;
    }
    else if (windowBits > 15)
    {
        wrap = 2;
        windowBits -= 16;
    }
    if (memLevel < 1 || memLevel > MAX_MEM_LEVEL || method != Z_DEFLATED ||
        windowBits < 8 || windowBits > 15 || level < 0 || level > 9 ||
        strategy < 0 || strategy > Z_FIXED)
    {
        return Z_STREAM_ERROR;
    }
    if (windowBits == 8) windowBits = 9;
    s = (deflate_state*)(*strm->zalloc)(strm->opaque, 1, sizeof(deflate_state));
    if (s == Z_NULL) return Z_MEM_ERROR;
    strm->state = s;
    s->strm = strm;

    s->wrap = wrap;
    s->gzhead = Z_NULL;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;

    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift = ((s->hash_bits + MIN_MATCH - 1) / MIN_MATCH);

    s->window = (unsigned char*)(*strm->zalloc)(strm->opaque, s->w_size, 2 * sizeof(unsigned char));
    s->prev = (unsigned short*)(*strm->zalloc)(strm->opaque, s->w_size, sizeof(unsigned short));
    s->head = (unsigned short*)(*strm->zalloc)(strm->opaque, s->hash_size, sizeof(unsigned short));

    s->high_water = 0;

    s->lit_bufsize = 1 << (memLevel + 6);

    overlay = (unsigned short*)(*strm->zalloc)(strm->opaque, s->lit_bufsize, sizeof(unsigned short) + 2);
    s->pending_buf = (unsigned char*)overlay;
    s->pending_buf_size = (unsigned long)s->lit_bufsize * (sizeof(unsigned short) + 2L);

    if (s->window == Z_NULL || s->prev == Z_NULL || s->head == Z_NULL || s->pending_buf == Z_NULL)
    {
        s->status = FINISH_STATE;
        strm->msg = (char*)ERR_MSG(Z_MEM_ERROR);
        deflateEnd(strm);
        return Z_MEM_ERROR;
    }
    s->d_buf = overlay + s->lit_bufsize / sizeof(unsigned short);
    s->l_buf = s->pending_buf + (1 + sizeof(unsigned short)) * s->lit_bufsize;

    s->level = level;
    s->strategy = strategy;
    s->method = (unsigned char)method;

    return deflateReset(strm);
}

// 0x00428AB0
int __fastcall deflateSetDictionary(z_stream* strm, const unsigned char* dictionary, unsigned int dictLength)
{
    deflate_state* s;
    unsigned int str, n;
    int wrap;
    unsigned avail;
    const unsigned char* next;

    if (strm == Z_NULL || strm->state == Z_NULL || dictionary == Z_NULL)
        return Z_STREAM_ERROR;
    s = strm->state;
    wrap = s->wrap;
    if (wrap == 2 || (wrap == 1 && s->status != INIT_STATE) || s->lookahead)
        return Z_STREAM_ERROR;

    if (wrap == 1)
        strm->adler = adler32(strm->adler, dictionary, dictLength);
    s->wrap = 0;

    if (dictLength >= s->w_size) {
        if (wrap == 0) {
            CLEAR_HASH(s);
            s->strstart = 0;
            s->block_start = 0L;
            s->insert = 0;
        }
        dictionary += dictLength - s->w_size;
        dictLength = s->w_size;
    }

    avail = strm->avail_in;
    next = strm->next_in;
    strm->avail_in = dictLength;
    strm->next_in = (unsigned char*)dictionary;
    fill_window(s);
    while (s->lookahead >= MIN_MATCH) {
        str = s->strstart;
        n = s->lookahead - (MIN_MATCH - 1);
        do {
            UPDATE_HASH(s, s->ins_h, s->window[str + MIN_MATCH - 1]);
            s->prev[str & s->w_mask] = s->head[s->ins_h];
            s->head[s->ins_h] = (unsigned short)str;
            str++;
        } while (--n);
        s->strstart = str;
        s->lookahead = MIN_MATCH - 1;
        fill_window(s);
    }
    s->strstart += s->lookahead;
    s->block_start = (long)s->strstart;
    s->insert = s->lookahead;
    s->lookahead = 0;
    s->match_length = s->prev_length = MIN_MATCH - 1;
    s->match_available = 0;
    strm->next_in = (unsigned char*)next;
    strm->avail_in = avail;
    s->wrap = wrap;
    return Z_OK;
}

// 0x00427160
int __fastcall deflateResetKeep(z_stream* strm)
{
    deflate_state* s;
    if (strm == Z_NULL || strm->state == Z_NULL || strm->zalloc == (alloc_func)0 || strm->zfree == (free_func)0)
    {
        return Z_STREAM_ERROR;
    }
    strm->total_in = strm->total_out = 0;
    strm->msg = Z_NULL;
    strm->data_type = Z_UNKNOWN;
    s = (deflate_state*)strm->state;
    s->pending = 0;
    s->pending_out = s->pending_buf;
    if (s->wrap < 0)
    {
        s->wrap = -s->wrap;
    }
    s->status = s->wrap ? INIT_STATE : BUSY_STATE;
    strm->adler = s->wrap == 2 ? crc32(0L, Z_NULL, 0) : adler32(0L, Z_NULL, 0);
    s->last_flush = Z_NO_FLUSH;
    _tr_init(s);
    return Z_OK;
}

// 0x00428C40
int __fastcall deflateReset(z_stream* strm)
{
    int ret;
    ret = deflateResetKeep(strm);
    if (ret == 0)
        lm_init(strm->state);
    return ret;
}

// 0x00427200
int __fastcall deflateSetHeader(z_stream* strm, gz_header* head)
{
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    if (strm->state->wrap != 2) return Z_STREAM_ERROR;
    strm->state->gzhead = head;
    return Z_OK;
}

// 0x00427220
int __fastcall deflatePending(z_stream* strm, unsigned int* pending, int* bits)
{
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    if (pending != 0) *pending = ((deflate_state*)strm->state)->pending;
    if (bits != 0) *bits = ((deflate_state*)strm->state)->bi_valid;
    return Z_OK;
}

// 0x00427260
int __fastcall deflatePrime(z_stream* strm, int bits, int value)
{
    deflate_state* s;
    int put;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;
    if ((unsigned char*)(s->d_buf) < s->pending_out + ((Buf_size + 7) >> 3))
        return Z_BUF_ERROR;
    do {
        put = Buf_size - s->bi_valid;
        if (put > bits)
            put = bits;
        s->bi_buf |= (unsigned short)((value & ((1 << put) - 1)) << s->bi_valid);
        s->bi_valid += put;
        _tr_flush_bits(s);
        value >>= put;
        bits -= put;
    } while (bits);
    return Z_OK;
}

// 0x00429700
int __fastcall deflateParams(z_stream* strm, int level, int strategy)
{
    deflate_state* s;
    compress_func func;
    int err = Z_OK;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;

    if (level == Z_DEFAULT_COMPRESSION) level = 6;
    if (level < 0 || level > 9 || strategy < 0 || strategy > Z_FIXED) {
        return Z_STREAM_ERROR;
    }
    func = configuration_table[s->level].func;

    if ((strategy != s->strategy || func != configuration_table[level].func) && strm->total_in != 0) {
        err = deflate(strm, Z_BLOCK);
        if (err == Z_BUF_ERROR && s->pending == 0)
            err = Z_OK;
    }
    if (s->level != level) {
        s->level = level;
        s->max_lazy_match = configuration_table[level].max_lazy;
        s->good_match = configuration_table[level].good_length;
        s->nice_match = configuration_table[level].nice_length;
        s->max_chain_length = configuration_table[level].max_chain;
    }
    s->strategy = strategy;
    return err;
}

// 0x004272F0
int __fastcall deflateTune(z_stream* strm, int good_length, int max_lazy, int nice_length, int max_chain)
{
    deflate_state* s;
    if (strm == 0 || strm->state == 0) return Z_STREAM_ERROR;
    s = (deflate_state*)strm->state;
    s->good_match = good_length;
    s->max_lazy_match = max_lazy;
    s->nice_match = nice_length;
    s->max_chain_length = max_chain;
    return Z_OK;
}

// 0x00427330
unsigned long __fastcall deflateBound(z_stream* strm, unsigned long sourceLen)
{
    deflate_state* s;
    unsigned long complen, wraplen;
    unsigned char* str;

    complen = sourceLen + ((sourceLen + 7) >> 3) + ((sourceLen + 63) >> 6) + 5;

    if (strm == Z_NULL || strm->state == Z_NULL)
        return complen + 6;

    s = (deflate_state*)strm->state;
    switch (s->wrap) {
    case 0:
        wraplen = 0;
        break;
    case 1:
        wraplen = 6 + (s->strstart ? 4 : 0);
        break;
    case 2:
        wraplen = 18;
        if (s->gzhead != Z_NULL) {
            if (s->gzhead->extra != Z_NULL)
                wraplen += 2 + s->gzhead->extra_len;
            str = s->gzhead->name;
            if (str != Z_NULL)
                do {
                    wraplen++;
                } while (*str++);
            str = s->gzhead->comment;
            if (str != Z_NULL)
                do {
                    wraplen++;
                } while (*str++);
            if (s->gzhead->hcrc)
                wraplen += 2;
        }
        break;
    default:
        wraplen = 6;
    }

    if (s->w_bits != 15 || s->hash_bits != 8 + 7)
        return complen + wraplen;

    return sourceLen + (sourceLen >> 12) + (sourceLen >> 14) + (sourceLen >> 25) + 13 - 6 + wraplen;
}

// 0x00427420
static void putShortMSB(deflate_state* s, unsigned int b)
{
    put_byte(s, (unsigned char)(b >> 8));
    put_byte(s, (unsigned char)(b & 0xff));
}

// 0x00427450
static void flush_pending(z_stream* strm)
{
    unsigned len;
    deflate_state* s = strm->state;

    _tr_flush_bits(s);
    len = s->pending;
    if (len > strm->avail_out) len = strm->avail_out;
    if (len == 0) return;

    memcpy(strm->next_out, s->pending_out, len);
    strm->next_out += len;
    s->pending_out += len;
    strm->total_out += len;
    strm->avail_out -= len;
    s->pending -= len;
    if (s->pending == 0) {
        s->pending_out = s->pending_buf;
    }
}

// 0x00428C60
int __fastcall deflate(z_stream* strm, int flush)
{
    int old_flush;
    deflate_state* s;

    if (strm == Z_NULL || strm->state == Z_NULL ||
        flush > Z_BLOCK || flush < 0) {
        return Z_STREAM_ERROR;
    }
    s = strm->state;

    if (strm->next_out == Z_NULL ||
        (strm->next_in == Z_NULL && strm->avail_in != 0) ||
        (s->status == FINISH_STATE && flush != Z_FINISH)) {
        ERR_RETURN(strm, Z_STREAM_ERROR);
    }
    if (strm->avail_out == 0) ERR_RETURN(strm, Z_BUF_ERROR);

    s->strm = strm;
    old_flush = s->last_flush;
    s->last_flush = flush;

    if (s->status == INIT_STATE) {
        if (s->wrap == 2) {
            strm->adler = crc32(0L, Z_NULL, 0);
            put_byte(s, 31);
            put_byte(s, 0x8b);
            put_byte(s, Z_DEFLATED);
            if (s->gzhead == Z_NULL) {
                put_byte(s, 0);
                put_byte(s, 0);
                put_byte(s, 0);
                put_byte(s, 0);
                put_byte(s, 0);
                put_byte(s, s->level == 9 ? 2 :
                            (s->strategy >= Z_HUFFMAN_ONLY || s->level < 2 ?
                             4 : 0));
                put_byte(s, OS_CODE);
                s->status = BUSY_STATE;
            }
            else {
                put_byte(s, (s->gzhead->text ? 1 : 0) +
                            (s->gzhead->hcrc ? 2 : 0) +
                            (s->gzhead->extra == Z_NULL ? 0 : 4) +
                            (s->gzhead->name == Z_NULL ? 0 : Z_DEFLATED) +
                            (s->gzhead->comment == Z_NULL ? 0 : 16)
                        );
                put_byte(s, (unsigned char)(s->gzhead->time & 0xff));
                put_byte(s, (unsigned char)((s->gzhead->time >> 8) & 0xff));
                put_byte(s, (unsigned char)((s->gzhead->time >> 16) & 0xff));
                put_byte(s, (unsigned char)((s->gzhead->time >> 24) & 0xff));
                put_byte(s, s->level == 9 ? 2 :
                            (s->strategy >= Z_HUFFMAN_ONLY || s->level < 2 ?
                             4 : 0));
                put_byte(s, s->gzhead->os & 0xff);
                if (s->gzhead->extra != Z_NULL) {
                    put_byte(s, s->gzhead->extra_len & 0xff);
                    put_byte(s, (s->gzhead->extra_len >> 8) & 0xff);
                }
                if (s->gzhead->hcrc)
                    strm->adler = crc32(strm->adler, s->pending_buf,
                                        s->pending);
                s->gzindex = 0;
                s->status = EXTRA_STATE;
            }
        }
        else
        {
            unsigned int header = (Z_DEFLATED + ((s->w_bits - Z_DEFLATED) << 4)) << 8;
            unsigned int level_flags;

            if (s->strategy >= Z_HUFFMAN_ONLY || s->level < 2)
                level_flags = 0;
            else if (s->level < 6)
                level_flags = 1;
            else if (s->level == 6)
                level_flags = 2;
            else
                level_flags = 3;
            header |= (level_flags << 6);
            if (s->strstart != 0) header |= PRESET_DICT;
            header += 31 - (header % 31);

            s->status = BUSY_STATE;
            putShortMSB(s, header);

            if (s->strstart != 0) {
                putShortMSB(s, (unsigned int)(strm->adler >> 16));
                putShortMSB(s, (unsigned int)(strm->adler & 0xffff));
            }
            strm->adler = adler32(0L, Z_NULL, 0);
        }
    }
    if (s->status == EXTRA_STATE) {
        if (s->gzhead->extra != Z_NULL) {
            unsigned int beg = s->pending;

            while (s->gzindex < (s->gzhead->extra_len & 0xffff)) {
                if (s->pending == s->pending_buf_size) {
                    if (s->gzhead->hcrc && s->pending > beg)
                        strm->adler = crc32(strm->adler, s->pending_buf + beg,
                                            s->pending - beg);
                    flush_pending(strm);
                    beg = s->pending;
                    if (s->pending == s->pending_buf_size)
                        break;
                }
                put_byte(s, s->gzhead->extra[s->gzindex]);
                s->gzindex++;
            }
            if (s->gzhead->hcrc && s->pending > beg)
                strm->adler = crc32(strm->adler, s->pending_buf + beg,
                                    s->pending - beg);
            if (s->gzindex == s->gzhead->extra_len) {
                s->gzindex = 0;
                s->status = NAME_STATE;
            }
        }
        else
            s->status = NAME_STATE;
    }
    if (s->status == NAME_STATE) {
        if (s->gzhead->name != Z_NULL) {
            unsigned int beg = s->pending;
            int val;

            do {
                if (s->pending == s->pending_buf_size) {
                    if (s->gzhead->hcrc && s->pending > beg)
                        strm->adler = crc32(strm->adler, s->pending_buf + beg,
                                            s->pending - beg);
                    flush_pending(strm);
                    beg = s->pending;
                    if (s->pending == s->pending_buf_size) {
                        val = 1;
                        break;
                    }
                }
                val = s->gzhead->name[s->gzindex++];
                put_byte(s, val);
            } while (val != 0);
            if (s->gzhead->hcrc && s->pending > beg)
                strm->adler = crc32(strm->adler, s->pending_buf + beg,
                                    s->pending - beg);
            if (val == 0) {
                s->gzindex = 0;
                s->status = COMMENT_STATE;
            }
        }
        else
            s->status = COMMENT_STATE;
    }
    if (s->status == COMMENT_STATE) {
        if (s->gzhead->comment != Z_NULL) {
            unsigned int beg = s->pending;
            int val;

            do {
                if (s->pending == s->pending_buf_size) {
                    if (s->gzhead->hcrc && s->pending > beg)
                        strm->adler = crc32(strm->adler, s->pending_buf + beg,
                                            s->pending - beg);
                    flush_pending(strm);
                    beg = s->pending;
                    if (s->pending == s->pending_buf_size) {
                        val = 1;
                        break;
                    }
                }
                val = s->gzhead->comment[s->gzindex++];
                put_byte(s, val);
            } while (val != 0);
            if (s->gzhead->hcrc && s->pending > beg)
                strm->adler = crc32(strm->adler, s->pending_buf + beg,
                                    s->pending - beg);
            if (val == 0)
                s->status = HCRC_STATE;
        }
        else
            s->status = HCRC_STATE;
    }
    if (s->status == HCRC_STATE) {
        if (s->gzhead->hcrc) {
            if (s->pending + 2 > s->pending_buf_size)
                flush_pending(strm);
            if (s->pending + 2 <= s->pending_buf_size) {
                put_byte(s, (unsigned char)(strm->adler & 0xff));
                put_byte(s, (unsigned char)((strm->adler >> 8) & 0xff));
                strm->adler = crc32(0L, Z_NULL, 0);
                s->status = BUSY_STATE;
            }
        }
        else
            s->status = BUSY_STATE;
    }

    if (s->pending != 0) {
        flush_pending(strm);
        if (strm->avail_out == 0) {
            s->last_flush = -1;
            return Z_OK;
        }

    } else if (strm->avail_in == 0 && RANK(flush) <= RANK(old_flush) &&
               flush != Z_FINISH) {
        ERR_RETURN(strm, Z_BUF_ERROR);
    }

    if (s->status == FINISH_STATE && strm->avail_in != 0) {
        ERR_RETURN(strm, Z_BUF_ERROR);
    }

    if (strm->avail_in != 0 || s->lookahead != 0 ||
        (flush != Z_NO_FLUSH && s->status != FINISH_STATE)) {
        block_state bstate;

        bstate = s->strategy == Z_HUFFMAN_ONLY ? deflate_huff(s, flush) :
                    (s->strategy == Z_RLE ? deflate_rle(s, flush) :
                        (*(configuration_table[s->level].func))(s, flush));

        if (bstate == finish_started || bstate == finish_done) {
            s->status = FINISH_STATE;
        }
        if (bstate == need_more || bstate == finish_started) {
            if (strm->avail_out == 0) {
                s->last_flush = -1;
            }
            return Z_OK;
        }
        if (bstate == block_done) {
            if (flush == Z_PARTIAL_FLUSH) {
                _tr_align(s);
            } else if (flush != Z_BLOCK) {
                _tr_stored_block(s, (char*)0, 0L, 0);
                if (flush == Z_FULL_FLUSH) {
                    CLEAR_HASH(s);
                    if (s->lookahead == 0) {
                        s->strstart = 0;
                        s->block_start = 0L;
                        s->insert = 0;
                    }
                }
            }
            flush_pending(strm);
            if (strm->avail_out == 0) {
                s->last_flush = -1;
                return Z_OK;
            }
        }
    }

    if (flush != Z_FINISH) return Z_OK;
    if (s->wrap <= 0) return Z_STREAM_END;

    if (s->wrap == 2) {
        put_byte(s, (unsigned char)(strm->adler & 0xff));
        put_byte(s, (unsigned char)((strm->adler >> 8) & 0xff));
        put_byte(s, (unsigned char)((strm->adler >> 16) & 0xff));
        put_byte(s, (unsigned char)((strm->adler >> 24) & 0xff));
        put_byte(s, (unsigned char)(strm->total_in & 0xff));
        put_byte(s, (unsigned char)((strm->total_in >> 8) & 0xff));
        put_byte(s, (unsigned char)((strm->total_in >> 16) & 0xff));
        put_byte(s, (unsigned char)((strm->total_in >> 24) & 0xff));
    }
    else
    {
        putShortMSB(s, (unsigned int)(strm->adler >> 16));
        putShortMSB(s, (unsigned int)(strm->adler & 0xffff));
    }
    flush_pending(strm);
    if (s->wrap > 0) s->wrap = -s->wrap;
    return s->pending != 0 ? Z_OK : Z_STREAM_END;
}

// 0x004274A0
int __fastcall deflateEnd(z_stream* strm)
{
    int status;
    if (strm == Z_NULL || strm->state == Z_NULL)
        return Z_STREAM_ERROR;
    status = ((deflate_state*)strm->state)->status;
    if (status != INIT_STATE && status != EXTRA_STATE && status != NAME_STATE && status != COMMENT_STATE && status != HCRC_STATE && status != BUSY_STATE && status != FINISH_STATE)
    {
        return Z_STREAM_ERROR;
    }
    TRY_FREE(strm, ((deflate_state*)strm->state)->pending_buf);
    TRY_FREE(strm, ((deflate_state*)strm->state)->head);
    TRY_FREE(strm, ((deflate_state*)strm->state)->prev);
    TRY_FREE(strm, ((deflate_state*)strm->state)->window);
    ZFREE(strm, strm->state);
    strm->state = Z_NULL;
    return status == BUSY_STATE ? Z_DATA_ERROR : Z_OK;
}

// 0x00427560
int __fastcall deflateCopy(z_stream* dest, z_stream* source)
{
    deflate_state* ds;
    deflate_state* ss;
    unsigned short* overlay;

    if (source == Z_NULL || dest == Z_NULL || source->state == Z_NULL) {
        return Z_STREAM_ERROR;
    }
    ss = (deflate_state*)source->state;
    memcpy(dest, source, sizeof(z_stream));
    ds = (deflate_state*)dest->zalloc(dest->opaque, 1, sizeof(deflate_state));
    if (ds == Z_NULL) return Z_MEM_ERROR;
    dest->state = ds;
    memcpy(ds, ss, sizeof(deflate_state));
    ds->strm = dest;

    ds->window = (unsigned char*)dest->zalloc(dest->opaque, ds->w_size, 2 * sizeof(unsigned char));
    ds->prev = (unsigned short*)dest->zalloc(dest->opaque, ds->w_size, sizeof(unsigned short));
    ds->head = (unsigned short*)dest->zalloc(dest->opaque, ds->hash_size, sizeof(unsigned short));
    overlay = (unsigned short*)dest->zalloc(dest->opaque, ds->lit_bufsize, sizeof(unsigned short) + 2);
    ds->pending_buf = (unsigned char*)overlay;

    if (ds->window == Z_NULL || ds->prev == Z_NULL || ds->head == Z_NULL || ds->pending_buf == Z_NULL) {
        deflateEnd(dest);
        return Z_MEM_ERROR;
    }
    memcpy(ds->window, ss->window, ds->w_size * 2 * sizeof(unsigned char));
    memcpy(ds->prev, ss->prev, ds->w_size * sizeof(unsigned short));
    memcpy(ds->head, ss->head, ds->hash_size * sizeof(unsigned short));
    memcpy(ds->pending_buf, ss->pending_buf, (unsigned int)ds->pending_buf_size);

    ds->pending_out = ds->pending_buf + (ss->pending_out - ss->pending_buf);
    ds->d_buf = overlay + ds->lit_bufsize / sizeof(unsigned short);
    ds->l_buf = ds->pending_buf + (1 + sizeof(unsigned short)) * ds->lit_bufsize;

    ds->l_desc.dyn_tree = ds->dyn_ltree;
    ds->d_desc.dyn_tree = ds->dyn_dtree;
    ds->bl_desc.dyn_tree = ds->bl_tree;

    return Z_OK;
}

// 0x00427700
static unsigned read_buf(z_stream* strm, unsigned char* buf, unsigned size)
{
    unsigned len = strm->avail_in;

    if (len > size) len = size;
    if (len == 0) return 0;

    strm->avail_in -= len;

    memcpy(buf, strm->next_in, len);
    if (strm->state->wrap == 1) {
        strm->adler = adler32(strm->adler, buf, len);
    }
    else if (strm->state->wrap == 2) {
        strm->adler = crc32(strm->adler, buf, len);
    }
    strm->next_in += len;
    strm->total_in += len;

    return len;
}

// 0x00427770
static void lm_init(deflate_state* s)
{
    s->window_size = (unsigned long)2L * s->w_size;
    s->head[s->hash_size - 1] = 0;
    memset((unsigned char*)s->head, 0, (unsigned)(s->hash_size - 1) * sizeof(*s->head));
    s->max_lazy_match = configuration_table[s->level].max_lazy;
    s->good_match = configuration_table[s->level].good_length;
    s->nice_match = configuration_table[s->level].nice_length;
    s->max_chain_length = configuration_table[s->level].max_chain;
    s->strstart = 0;
    s->block_start = 0L;
    s->lookahead = 0;
    s->insert = 0;
    s->match_length = s->prev_length = 3 - 1;
    s->match_available = 0;
    s->ins_h = 0;
}

// 0x00427800
static unsigned int __stdcall longest_match(deflate_state* s, unsigned int cur_match)
{
    unsigned chain_length = s->max_chain_length;
    register unsigned char* scan = s->window + s->strstart;
    register unsigned char* match;
    register int len;
    int best_len = s->prev_length;
    int nice_match = s->nice_match;
    unsigned int limit = s->strstart > (unsigned int)MAX_DIST(s) ?
        s->strstart - (unsigned int)MAX_DIST(s) : NIL;
    unsigned short* prev = s->prev;
    unsigned int wmask = s->w_mask;
    register unsigned char* strend = s->window + s->strstart + MAX_MATCH;
    register unsigned char scan_end1 = scan[best_len - 1];
    register unsigned char scan_end = scan[best_len];

    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }
    if ((unsigned int)nice_match > s->lookahead) nice_match = s->lookahead;

    do {
        match = s->window + cur_match;

        if (match[best_len] != scan_end ||
            match[best_len - 1] != scan_end1 ||
            *match != *scan ||
            *++match != scan[1]) continue;

        scan += 2, match++;

        do {
        } while (*++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 scan < strend);

        len = MAX_MATCH - (int)(strend - scan);
        scan = strend - MAX_MATCH;

        if (len > best_len) {
            s->match_start = cur_match;
            best_len = len;
            if (len >= nice_match) break;
            scan_end1 = scan[best_len - 1];
            scan_end = scan[best_len];
        }
    } while ((cur_match = prev[cur_match & wmask]) > limit
             && --chain_length != 0);

    if ((unsigned int)best_len <= s->lookahead) return (unsigned int)best_len;
    return s->lookahead;
}

// 0x00427980
static void fill_window(deflate_state* s)
{
    register unsigned n, m;
    register unsigned short* p;
    unsigned more;
    unsigned int wsize = s->w_size;

    do {
        more = (unsigned)(s->window_size - (unsigned long)s->lookahead - (unsigned long)s->strstart);

        if (s->strstart >= wsize + MAX_DIST(s)) {

            memcpy(s->window, s->window + wsize, (unsigned)wsize);
            s->match_start -= wsize;
            s->strstart -= wsize;
            s->block_start -= (long)wsize;

            n = s->hash_size;
            p = &s->head[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : NIL);
            } while (--n);

            n = wsize;
            p = &s->prev[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : NIL);
            } while (--n);
            more += wsize;
        }
        if (s->strm->avail_in == 0) break;

        n = read_buf(s->strm, s->window + s->strstart + s->lookahead, more);
        s->lookahead += n;

        if (s->lookahead + s->insert >= MIN_MATCH) {
            unsigned int str = s->strstart - s->insert;
            s->ins_h = s->window[str];
            UPDATE_HASH(s, s->ins_h, s->window[str + 1]);
            while (s->insert) {
                UPDATE_HASH(s, s->ins_h, s->window[str + MIN_MATCH - 1]);
                s->prev[str & s->w_mask] = s->head[s->ins_h];
                s->head[s->ins_h] = (unsigned short)str;
                str++;
                s->insert--;
                if (s->lookahead + s->insert < MIN_MATCH)
                    break;
            }
        }

    } while (s->lookahead < MIN_LOOKAHEAD && s->strm->avail_in != 0);

    if (s->high_water < s->window_size) {
        unsigned long curr = s->strstart + (unsigned long)(s->lookahead);
        unsigned long init;

        if (s->high_water < curr) {
            init = s->window_size - curr;
            if (init > WIN_INIT)
                init = WIN_INIT;
            memset(s->window + curr, 0, (unsigned)init);
            s->high_water = curr + init;
        }
        else if (s->high_water < (unsigned long)curr + WIN_INIT) {
            init = (unsigned long)curr + WIN_INIT - s->high_water;
            if (init > s->window_size - s->high_water)
                init = s->window_size - s->high_water;
            memset(s->window + s->high_water, 0, (unsigned)init);
            s->high_water += init;
        }
    }
}

// 0x00427BB0
block_state __fastcall deflate_stored(deflate_state* s, int flush)
{
    unsigned long max_block_size = 0xffff;
    unsigned long max_start;

    if (max_block_size > s->pending_buf_size - 5) {
        max_block_size = s->pending_buf_size - 5;
    }

    for (;;) {
        if (s->lookahead <= 1) {
            fill_window(s);
            if (s->lookahead == 0 && flush == Z_NO_FLUSH) return need_more;
            if (s->lookahead == 0) break;
        }
        s->strstart += s->lookahead;
        s->lookahead = 0;

        max_start = s->block_start + max_block_size;
        if (s->strstart == 0 || (unsigned long)s->strstart >= max_start) {
            s->lookahead = (unsigned int)(s->strstart - max_start);
            s->strstart = (unsigned int)max_start;
            FLUSH_BLOCK(s, 0);
        }
        if (s->strstart - (unsigned int)s->block_start >= MAX_DIST(s)) {
            FLUSH_BLOCK(s, 0);
        }
    }
    s->insert = 0;
    if (flush == Z_FINISH) {
        FLUSH_BLOCK(s, 1);
        return finish_done;
    }
    if ((long)s->strstart > s->block_start)
        FLUSH_BLOCK(s, 0);
    return block_done;
}

// 0x00427DD0
block_state __fastcall deflate_fast(deflate_state* s, int flush)
{
    unsigned int hash_head;
    int bflush;

    for (;;) {
        if (s->lookahead < MIN_LOOKAHEAD) {
            fill_window(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
                return need_more;
            }
            if (s->lookahead == 0) break;
        }

        hash_head = NIL;
        if (s->lookahead >= MIN_MATCH) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        if (hash_head != NIL && s->strstart - hash_head <= MAX_DIST(s)) {
            s->match_length = longest_match(s, hash_head);
        }
        if (s->match_length >= MIN_MATCH) {
            _tr_tally_dist(s, s->strstart - s->match_start,
                           s->match_length - MIN_MATCH, bflush);

            s->lookahead -= s->match_length;

            if (s->match_length <= s->max_lazy_match &&
                s->lookahead >= MIN_MATCH) {
                s->match_length--;
                do {
                    s->strstart++;
                    INSERT_STRING(s, s->strstart, hash_head);
                } while (--s->match_length != 0);
                s->strstart++;
            } else
            {
                s->strstart += s->match_length;
                s->match_length = 0;
                s->ins_h = s->window[s->strstart];
                UPDATE_HASH(s, s->ins_h, s->window[s->strstart + 1]);
            }
        } else {
            _tr_tally_lit(s, s->window[s->strstart], bflush);
            s->lookahead--;
            s->strstart++;
        }
        if (bflush) FLUSH_BLOCK(s, 0);
    }
    s->insert = s->strstart < MIN_MATCH - 1 ? s->strstart : MIN_MATCH - 1;
    if (flush == Z_FINISH) {
        FLUSH_BLOCK(s, 1);
        return finish_done;
    }
    if (s->last_lit)
        FLUSH_BLOCK(s, 0);
    return block_done;
}

// 0x00428150
block_state __fastcall deflate_slow(deflate_state* s, int flush)
{
    unsigned int hash_head;
    int bflush;

    for (;;) {
        if (s->lookahead < MIN_LOOKAHEAD) {
            fill_window(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
                return need_more;
            }
            if (s->lookahead == 0) break;
        }

        hash_head = NIL;
        if (s->lookahead >= MIN_MATCH) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = MIN_MATCH - 1;

        if (hash_head != NIL && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= MAX_DIST(s)) {
            s->match_length = longest_match(s, hash_head);

            if (s->match_length <= 5 && (s->strategy == Z_FILTERED
                || (s->match_length == MIN_MATCH &&
                    s->strstart - s->match_start > TOO_FAR)
                )) {
                s->match_length = MIN_MATCH - 1;
            }
        }
        if (s->prev_length >= MIN_MATCH && s->match_length <= s->prev_length) {
            unsigned int max_insert = s->strstart + s->lookahead - MIN_MATCH;

            _tr_tally_dist(s, s->strstart - 1 - s->prev_match,
                           s->prev_length - MIN_MATCH, bflush);

            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = MIN_MATCH - 1;
            s->strstart++;

            if (bflush) FLUSH_BLOCK(s, 0);

        } else if (s->match_available) {
            _tr_tally_lit(s, s->window[s->strstart - 1], bflush);
            if (bflush) {
                FLUSH_BLOCK_ONLY(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0) return need_more;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        _tr_tally_lit(s, s->window[s->strstart - 1], bflush);
        s->match_available = 0;
    }
    s->insert = s->strstart < MIN_MATCH - 1 ? s->strstart : MIN_MATCH - 1;
    if (flush == Z_FINISH) {
        FLUSH_BLOCK(s, 1);
        return finish_done;
    }
    if (s->last_lit)
        FLUSH_BLOCK(s, 0);
    return block_done;
}

// 0x004285F0
static block_state __stdcall deflate_rle(deflate_state* s, int flush)
{
    int bflush;
    unsigned int prev;
    unsigned char* scan;
    unsigned char* strend;

    for (;;) {
        if (s->lookahead <= MAX_MATCH) {
            fill_window(s);
            if (s->lookahead <= MAX_MATCH && flush == Z_NO_FLUSH) {
                return need_more;
            }
            if (s->lookahead == 0) break;
        }

        s->match_length = 0;
        if (s->lookahead >= MIN_MATCH && s->strstart > 0) {
            scan = s->window + s->strstart - 1;
            prev = *scan;
            if (prev == *++scan && prev == *++scan && prev == *++scan) {
                strend = s->window + s->strstart + MAX_MATCH;
                do {
                } while (prev == *++scan && prev == *++scan &&
                         prev == *++scan && prev == *++scan &&
                         prev == *++scan && prev == *++scan &&
                         prev == *++scan && prev == *++scan &&
                         scan < strend);
                s->match_length = MAX_MATCH - (int)(strend - scan);
                if (s->match_length > s->lookahead)
                    s->match_length = s->lookahead;
            }
        }

        if (s->match_length >= MIN_MATCH) {
            _tr_tally_dist(s, 1, s->match_length - MIN_MATCH, bflush);

            s->lookahead -= s->match_length;
            s->strstart += s->match_length;
            s->match_length = 0;
        } else {
            _tr_tally_lit(s, s->window[s->strstart], bflush);
            s->lookahead--;
            s->strstart++;
        }
        if (bflush) FLUSH_BLOCK(s, 0);
    }
    s->insert = 0;
    if (flush == Z_FINISH) {
        FLUSH_BLOCK(s, 1);
        return finish_done;
    }
    if (s->last_lit)
        FLUSH_BLOCK(s, 0);
    return block_done;
}

// 0x00428900
static block_state __stdcall deflate_huff(deflate_state* s, int flush)
{
    int bflush;

    for (;;) {
        if (s->lookahead == 0) {
            fill_window(s);
            if (s->lookahead == 0) {
                if (flush == Z_NO_FLUSH)
                    return need_more;
                break;
            }
        }

        s->match_length = 0;
        _tr_tally_lit(s, s->window[s->strstart], bflush);
        s->lookahead--;
        s->strstart++;
        if (bflush) FLUSH_BLOCK(s, 0);
    }
    s->insert = 0;
    if (flush == Z_FINISH) {
        FLUSH_BLOCK(s, 1);
        return finish_done;
    }
    if (s->last_lit)
        FLUSH_BLOCK(s, 0);
    return block_done;
}

extern const config gData_006D0280[10] = { // 0x006D0280
    { 0, 0, 0, 0, &deflate_stored },
    { 4, 4, 8, 4, &deflate_fast },
    { 4, 5, 16, 8, &deflate_fast },
    { 4, 6, 32, 32, &deflate_fast },
    { 4, 4, 16, 16, &deflate_slow },
    { 8, 16, 32, 32, &deflate_slow },
    { 8, 16, 128, 128, &deflate_slow },
    { 8, 32, 128, 256, &deflate_slow },
    { 32, 128, 258, 1024, &deflate_slow },
    { 32, 258, 258, 4096, &deflate_slow }
};
#pragma comment(linker, "/alternatename:_configuration_table=_gData_006D0280")

extern const char gData_006D02F8[8] = "1.2.8"; // 0x006D02F8
