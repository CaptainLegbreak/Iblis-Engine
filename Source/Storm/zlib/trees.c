// Altered from the original zlib source.
#define Buf_size 16
#define MAX_BITS 15
#define L_CODES (LITERALS + 1 + 29)
#define D_CODES 30
#define BL_CODES 19
#define LITERALS 256
#define END_BLOCK 256
#define HEAP_SIZE (2 * L_CODES + 1)
#define SMALLEST 1
#define REP_3_6 16
#define REPZ_3_10 17
#define REPZ_11_138 18
#define STORED_BLOCK 0
#define Z_BINARY 0
#define Z_TEXT 1
#define STATIC_TREES 1
#define DYN_TREES 2
#define Z_UNKNOWN 2
#define Z_FIXED 4

typedef struct deflate_state deflate_state;
typedef struct z_stream z_stream;
typedef struct ct_data ct_data;
typedef struct static_tree_desc static_tree_desc;
typedef struct tree_desc tree_desc;

struct ct_data
{
    union { unsigned short freq; unsigned short code; } fc;
    union { unsigned short dad; unsigned short len; } dl;
};

struct static_tree_desc
{
    const ct_data* static_tree;
    const int* extra_bits;
    int extra_base;
    int elems;
    int max_length;
};

struct tree_desc
{
    ct_data* dyn_tree;
    int max_code;
    static_tree_desc* stat_desc;
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
    void* zalloc;
    void* zfree;
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
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
    void* gzhead;
    unsigned int gzindex;
    int method;
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
    char pad1695[0x3];
    unsigned char* l_buf;
    unsigned int lit_bufsize;
    unsigned int last_lit;
    unsigned short* d_buf;
    unsigned long opt_len;
    unsigned long static_len;
    unsigned int matches;
    unsigned int insert;
    unsigned short bi_buf;
    char pad16BA[0x2];
    int bi_valid;
    unsigned long high_water;
};

extern const int extra_lbits[];                                                                   // 0x006D0D90
extern const unsigned char bl_order[];                                                            // 0x006D0E04
extern const int extra_dbits[];                                                                   // 0x006D0E18
extern const ct_data static_dtree[];                                                              // 0x006D1360
extern const int base_length[];                                                                   // 0x006D16D8
extern const int base_dist[];                                                                     // 0x006D1750
extern static_tree_desc static_l_desc;                                                            // 0x007088F4
extern static_tree_desc static_d_desc;                                                            // 0x00708908
extern static_tree_desc static_bl_desc;                                                           // 0x0070891C

static const ct_data static_ltree[L_CODES + 2] = {                                         // 0x006D0EE0
    {{ 12},{  8}},{{140},{  8}},{{ 76},{  8}},{{204},{  8}},{{ 44},{  8}},
    {{172},{  8}},{{108},{  8}},{{236},{  8}},{{ 28},{  8}},{{156},{  8}},
    {{ 92},{  8}},{{220},{  8}},{{ 60},{  8}},{{188},{  8}},{{124},{  8}},
    {{252},{  8}},{{  2},{  8}},{{130},{  8}},{{ 66},{  8}},{{194},{  8}},
    {{ 34},{  8}},{{162},{  8}},{{ 98},{  8}},{{226},{  8}},{{ 18},{  8}},
    {{146},{  8}},{{ 82},{  8}},{{210},{  8}},{{ 50},{  8}},{{178},{  8}},
    {{114},{  8}},{{242},{  8}},{{ 10},{  8}},{{138},{  8}},{{ 74},{  8}},
    {{202},{  8}},{{ 42},{  8}},{{170},{  8}},{{106},{  8}},{{234},{  8}},
    {{ 26},{  8}},{{154},{  8}},{{ 90},{  8}},{{218},{  8}},{{ 58},{  8}},
    {{186},{  8}},{{122},{  8}},{{250},{  8}},{{  6},{  8}},{{134},{  8}},
    {{ 70},{  8}},{{198},{  8}},{{ 38},{  8}},{{166},{  8}},{{102},{  8}},
    {{230},{  8}},{{ 22},{  8}},{{150},{  8}},{{ 86},{  8}},{{214},{  8}},
    {{ 54},{  8}},{{182},{  8}},{{118},{  8}},{{246},{  8}},{{ 14},{  8}},
    {{142},{  8}},{{ 78},{  8}},{{206},{  8}},{{ 46},{  8}},{{174},{  8}},
    {{110},{  8}},{{238},{  8}},{{ 30},{  8}},{{158},{  8}},{{ 94},{  8}},
    {{222},{  8}},{{ 62},{  8}},{{190},{  8}},{{126},{  8}},{{254},{  8}},
    {{  1},{  8}},{{129},{  8}},{{ 65},{  8}},{{193},{  8}},{{ 33},{  8}},
    {{161},{  8}},{{ 97},{  8}},{{225},{  8}},{{ 17},{  8}},{{145},{  8}},
    {{ 81},{  8}},{{209},{  8}},{{ 49},{  8}},{{177},{  8}},{{113},{  8}},
    {{241},{  8}},{{  9},{  8}},{{137},{  8}},{{ 73},{  8}},{{201},{  8}},
    {{ 41},{  8}},{{169},{  8}},{{105},{  8}},{{233},{  8}},{{ 25},{  8}},
    {{153},{  8}},{{ 89},{  8}},{{217},{  8}},{{ 57},{  8}},{{185},{  8}},
    {{121},{  8}},{{249},{  8}},{{  5},{  8}},{{133},{  8}},{{ 69},{  8}},
    {{197},{  8}},{{ 37},{  8}},{{165},{  8}},{{101},{  8}},{{229},{  8}},
    {{ 21},{  8}},{{149},{  8}},{{ 85},{  8}},{{213},{  8}},{{ 53},{  8}},
    {{181},{  8}},{{117},{  8}},{{245},{  8}},{{ 13},{  8}},{{141},{  8}},
    {{ 77},{  8}},{{205},{  8}},{{ 45},{  8}},{{173},{  8}},{{109},{  8}},
    {{237},{  8}},{{ 29},{  8}},{{157},{  8}},{{ 93},{  8}},{{221},{  8}},
    {{ 61},{  8}},{{189},{  8}},{{125},{  8}},{{253},{  8}},{{ 19},{  9}},
    {{275},{  9}},{{147},{  9}},{{403},{  9}},{{ 83},{  9}},{{339},{  9}},
    {{211},{  9}},{{467},{  9}},{{ 51},{  9}},{{307},{  9}},{{179},{  9}},
    {{435},{  9}},{{115},{  9}},{{371},{  9}},{{243},{  9}},{{499},{  9}},
    {{ 11},{  9}},{{267},{  9}},{{139},{  9}},{{395},{  9}},{{ 75},{  9}},
    {{331},{  9}},{{203},{  9}},{{459},{  9}},{{ 43},{  9}},{{299},{  9}},
    {{171},{  9}},{{427},{  9}},{{107},{  9}},{{363},{  9}},{{235},{  9}},
    {{491},{  9}},{{ 27},{  9}},{{283},{  9}},{{155},{  9}},{{411},{  9}},
    {{ 91},{  9}},{{347},{  9}},{{219},{  9}},{{475},{  9}},{{ 59},{  9}},
    {{315},{  9}},{{187},{  9}},{{443},{  9}},{{123},{  9}},{{379},{  9}},
    {{251},{  9}},{{507},{  9}},{{  7},{  9}},{{263},{  9}},{{135},{  9}},
    {{391},{  9}},{{ 71},{  9}},{{327},{  9}},{{199},{  9}},{{455},{  9}},
    {{ 39},{  9}},{{295},{  9}},{{167},{  9}},{{423},{  9}},{{103},{  9}},
    {{359},{  9}},{{231},{  9}},{{487},{  9}},{{ 23},{  9}},{{279},{  9}},
    {{151},{  9}},{{407},{  9}},{{ 87},{  9}},{{343},{  9}},{{215},{  9}},
    {{471},{  9}},{{ 55},{  9}},{{311},{  9}},{{183},{  9}},{{439},{  9}},
    {{119},{  9}},{{375},{  9}},{{247},{  9}},{{503},{  9}},{{ 15},{  9}},
    {{271},{  9}},{{143},{  9}},{{399},{  9}},{{ 79},{  9}},{{335},{  9}},
    {{207},{  9}},{{463},{  9}},{{ 47},{  9}},{{303},{  9}},{{175},{  9}},
    {{431},{  9}},{{111},{  9}},{{367},{  9}},{{239},{  9}},{{495},{  9}},
    {{ 31},{  9}},{{287},{  9}},{{159},{  9}},{{415},{  9}},{{ 95},{  9}},
    {{351},{  9}},{{223},{  9}},{{479},{  9}},{{ 63},{  9}},{{319},{  9}},
    {{191},{  9}},{{447},{  9}},{{127},{  9}},{{383},{  9}},{{255},{  9}},
    {{511},{  9}},{{  0},{  7}},{{ 64},{  7}},{{ 32},{  7}},{{ 96},{  7}},
    {{ 16},{  7}},{{ 80},{  7}},{{ 48},{  7}},{{112},{  7}},{{  8},{  7}},
    {{ 72},{  7}},{{ 40},{  7}},{{104},{  7}},{{ 24},{  7}},{{ 88},{  7}},
    {{ 56},{  7}},{{120},{  7}},{{  4},{  7}},{{ 68},{  7}},{{ 36},{  7}},
    {{100},{  7}},{{ 20},{  7}},{{ 84},{  7}},{{ 52},{  7}},{{116},{  7}},
    {{  3},{  8}},{{131},{  8}},{{ 67},{  8}},{{195},{  8}},{{ 35},{  8}},
    {{163},{  8}},{{ 99},{  8}},{{227},{  8}}
};

const unsigned char _dist_code[512] = {                                                          // 0x006D13D8
  0,  1,  2,  3,  4,  4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  8,
  8,  8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10, 10, 10,
 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13,
 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0, 16, 17,
 18, 18, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22,
 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27,
 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
 27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
 28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29
};

const unsigned char _length_code[256] = {                                                        // 0x006D15D8
  0,  1,  2,  3,  4,  5,  6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 12, 12,
 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16,
 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19,
 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22,
 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23,
 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 26,
 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 28
};

#define put_byte(s, c) { s->pending_buf[s->pending++] = (c); }
#define put_short(s, w) { \
    put_byte(s, (unsigned char)((w) & 0xff)); \
    put_byte(s, (unsigned char)((unsigned short)(w) >> 8)); \
}
#define send_bits(s, value, length) \
{ int len = length; \
  if (s->bi_valid > (int)Buf_size - len) { \
    int val = value; \
    s->bi_buf |= (unsigned short)val << s->bi_valid; \
    put_short(s, s->bi_buf); \
    s->bi_buf = (unsigned short)val >> (Buf_size - s->bi_valid); \
    s->bi_valid += len - Buf_size; \
  } else { \
    s->bi_buf |= (unsigned short)(value) << s->bi_valid; \
    s->bi_valid += len; \
  } \
}
#define send_code(s, c, tree) send_bits(s, tree[c].fc.code, tree[c].dl.len)
#define d_code(dist) ((dist) < 256 ? _dist_code[dist] : _dist_code[256 + ((dist) >> 7)])
#define smaller(tree, n, m, depth) \
   (tree[n].fc.freq < tree[m].fc.freq || \
   (tree[n].fc.freq == tree[m].fc.freq && depth[n] <= depth[m]))
#define pqremove(s, tree, top) \
{ \
    top = s->heap[SMALLEST]; \
    s->heap[SMALLEST] = s->heap[s->heap_len--]; \
    pqdownheap(s, tree, SMALLEST); \
}

static void init_block(deflate_state* s);
static void __stdcall pqdownheap(deflate_state* s, ct_data* tree, int k);
static void gen_bitlen(deflate_state* s, tree_desc* desc);
static void __stdcall scan_tree(deflate_state* s, ct_data* tree, int max_code);
static void send_tree(deflate_state* s, ct_data* tree, int max_code);
static void __stdcall send_all_trees(deflate_state* s, int lcodes, int dcodes, int blcodes);
static void __stdcall compress_block(deflate_state* s, const ct_data* ltree, const ct_data* dtree);
static int detect_data_type(deflate_state* s);
static unsigned bi_reverse(unsigned code, int len);
static void bi_flush(deflate_state* s);
static void bi_windup(deflate_state* s);
static void __stdcall copy_block(deflate_state* s, char* buf, unsigned len, int header);
static void __stdcall gen_codes(ct_data* tree, int max_code, unsigned short* bl_count);
static void __stdcall build_tree(deflate_state* s, tree_desc* desc);
static int build_bl_tree(deflate_state* s);
void __fastcall _tr_stored_block(deflate_state* s, char* buf, unsigned long stored_len, int last);
void __fastcall _tr_flush_bits(deflate_state* s);
void __fastcall _tr_align(deflate_state* s);
void __fastcall _tr_flush_block(deflate_state* s, char* buf, unsigned long stored_len, int last);

// 0x0042B9E0
static void init_block(deflate_state* s)
{
    int n;

    for (n = 0; n < L_CODES; n++) s->dyn_ltree[n].fc.freq = 0;
    for (n = 0; n < D_CODES; n++) s->dyn_dtree[n].fc.freq = 0;
    for (n = 0; n < BL_CODES; n++) s->bl_tree[n].fc.freq = 0;

    s->dyn_ltree[END_BLOCK].fc.freq = 1;
    s->opt_len = s->static_len = 0L;
    s->last_lit = s->matches = 0;
}

// 0x0042BA50
static void __stdcall pqdownheap(deflate_state* s, ct_data* tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;
    while (j <= s->heap_len) {
        if (j < s->heap_len &&
            smaller(tree, s->heap[j + 1], s->heap[j], s->depth)) {
            j++;
        }
        if (smaller(tree, v, s->heap[j], s->depth)) break;

        s->heap[k] = s->heap[j];  k = j;

        j <<= 1;
    }
    s->heap[k] = v;
}

// 0x0042BB30
static void gen_bitlen(deflate_state* s, tree_desc* desc)
{
    ct_data* tree = desc->dyn_tree;
    int max_code = desc->max_code;
    const ct_data* stree = desc->stat_desc->static_tree;
    const int* extra = desc->stat_desc->extra_bits;
    int base = desc->stat_desc->extra_base;
    int max_length = desc->stat_desc->max_length;
    int h;
    int n, m;
    int bits;
    int xbits;
    unsigned short f;
    int overflow = 0;

    for (bits = 0; bits <= MAX_BITS; bits++) s->bl_count[bits] = 0;

    tree[s->heap[s->heap_max]].dl.len = 0;

    for (h = s->heap_max + 1; h < HEAP_SIZE; h++) {
        n = s->heap[h];
        bits = tree[tree[n].dl.dad].dl.len + 1;
        if (bits > max_length) bits = max_length, overflow++;
        tree[n].dl.len = (unsigned short)bits;

        if (n > max_code) continue;

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base) xbits = extra[n - base];
        f = tree[n].fc.freq;
        s->opt_len += (unsigned long)f * (bits + xbits);
        if (stree) s->static_len += (unsigned long)f * (stree[n].dl.len + xbits);
    }
    if (overflow == 0) return;

    do {
        bits = max_length - 1;
        while (s->bl_count[bits] == 0) bits--;
        s->bl_count[bits]--;
        s->bl_count[bits + 1] += 2;
        s->bl_count[max_length]--;
        overflow -= 2;
    } while (overflow > 0);

    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code) continue;
            if ((unsigned) tree[m].dl.len != (unsigned) bits) {
                s->opt_len += ((long)bits - (long)tree[m].dl.len)
                              *(long)tree[m].fc.freq;
                tree[m].dl.len = (unsigned short)bits;
            }
            n--;
        }
    }
}

// 0x0042BD30
static void __stdcall scan_tree(deflate_state* s, ct_data* tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].dl.len;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0) max_count = 138, min_count = 3;
    tree[max_code + 1].dl.len = (unsigned short)0xffff;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n + 1].dl.len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].fc.freq += count;
        } else if (curlen != 0) {
            if (curlen != prevlen) s->bl_tree[curlen].fc.freq++;
            s->bl_tree[REP_3_6].fc.freq++;
        } else if (count <= 10) {
            s->bl_tree[REPZ_3_10].fc.freq++;
        } else {
            s->bl_tree[REPZ_11_138].fc.freq++;
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

// 0x0042BE10
static void send_tree(deflate_state* s, ct_data* tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].dl.len;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0) max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n + 1].dl.len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do { send_code(s, curlen, s->bl_tree); } while (--count != 0);

        } else if (curlen != 0) {
            if (curlen != prevlen) {
                send_code(s, curlen, s->bl_tree); count--;
            }
            send_code(s, REP_3_6, s->bl_tree); send_bits(s, count - 3, 2);

        } else if (count <= 10) {
            send_code(s, REPZ_3_10, s->bl_tree); send_bits(s, count - 3, 3);

        } else {
            send_code(s, REPZ_11_138, s->bl_tree); send_bits(s, count - 11, 7);
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

// 0x0042C390
static void __stdcall send_all_trees(deflate_state* s, int lcodes, int dcodes, int blcodes)
{
    int rank;

    send_bits(s, lcodes - (LITERALS + 1), 5);
    send_bits(s, dcodes - 1, 5);
    send_bits(s, blcodes - 4, 4);
    for (rank = 0; rank < blcodes; rank++) {
        send_bits(s, s->bl_tree[bl_order[rank]].dl.len, 3);
    }

    send_tree(s, (ct_data*)s->dyn_ltree, lcodes - 1);

    send_tree(s, (ct_data*)s->dyn_dtree, dcodes - 1);
}

// 0x0042C6A0
static void __stdcall compress_block(deflate_state* s, const ct_data* ltree, const ct_data* dtree)
{
    unsigned dist;
    int lc;
    unsigned lx = 0;
    unsigned code;
    int extra;

    if (s->last_lit != 0) do {
        dist = s->d_buf[lx];
        lc = s->l_buf[lx++];
        if (dist == 0) {
            send_code(s, lc, ltree);
        } else {
            code = _length_code[lc];
            send_code(s, code + LITERALS + 1, ltree);
            extra = extra_lbits[code];
            if (extra != 0) {
                lc -= base_length[code];
                send_bits(s, lc, extra);
            }
            dist--;
            code = d_code(dist);

            send_code(s, code, dtree);
            extra = extra_dbits[code];
            if (extra != 0) {
                dist -= base_dist[code];
                send_bits(s, dist, extra);
            }
        }

    } while (lx < s->last_lit);

    send_code(s, END_BLOCK, ltree);
}

// 0x0042CAB0
static int detect_data_type(deflate_state* s)
{
    unsigned long black_mask = 0xf3ffc07fUL;
    int n;

    for (n = 0; n <= 31; n++, black_mask >>= 1)
        if ((black_mask & 1) && (s->dyn_ltree[n].fc.freq != 0))
            return Z_BINARY;

    if (s->dyn_ltree[9].fc.freq != 0 || s->dyn_ltree[10].fc.freq != 0
            || s->dyn_ltree[13].fc.freq != 0)
        return Z_TEXT;
    for (n = 32; n < LITERALS; n++)
        if (s->dyn_ltree[n].fc.freq != 0)
            return Z_TEXT;

    return Z_BINARY;
}

// 0x0042CB20
static unsigned bi_reverse(unsigned code, int len)
{
    register unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

// 0x0042CB40
static void bi_flush(deflate_state* s)
{
    if (s->bi_valid == Buf_size) {
        put_short(s, s->bi_buf);
        s->bi_buf = 0;
        s->bi_valid = 0;
    } else if (s->bi_valid >= 8) {
        put_byte(s, (unsigned char)s->bi_buf);
        s->bi_buf >>= 8;
        s->bi_valid -= 8;
    }
}

// 0x0042CBC0
static void bi_windup(deflate_state* s)
{
    if (s->bi_valid > 8) {
        put_short(s, s->bi_buf);
    } else if (s->bi_valid > 0) {
        put_byte(s, (unsigned char)s->bi_buf);
    }
    s->bi_buf = 0;
    s->bi_valid = 0;
}

// 0x0042CC40
static void __stdcall copy_block(deflate_state* s, char* buf, unsigned len, int header)
{
    bi_windup(s);

    if (header) {
        put_short(s, (unsigned short)len);
        put_short(s, (unsigned short)~len);
    }
    while (len--) {
        put_byte(s, *buf++);
    }
}

// 0x0042CCD0
void __fastcall _tr_init(deflate_state* s)
{
    s->l_desc.dyn_tree = s->dyn_ltree;
    s->l_desc.stat_desc = &static_l_desc;

    s->d_desc.dyn_tree = s->dyn_dtree;
    s->d_desc.stat_desc = &static_d_desc;

    s->bl_desc.dyn_tree = s->bl_tree;
    s->bl_desc.stat_desc = &static_bl_desc;

    s->bi_buf = 0;
    s->bi_valid = 0;

    init_block(s);
}

// 0x0042CD30
static void __stdcall gen_codes(ct_data* tree, int max_code, unsigned short* bl_count)
{
    unsigned short next_code[MAX_BITS + 1];
    unsigned short code = 0;
    int bits;
    int n;

    for (bits = 1; bits <= MAX_BITS; bits++) {
        next_code[bits] = code = (code + bl_count[bits - 1]) << 1;
    }
    for (n = 0; n <= max_code; n++) {
        int len = tree[n].dl.len;
        if (len == 0) continue;
        tree[n].fc.code = (unsigned short)bi_reverse(next_code[len]++, len);
    }
}

// 0x0042CDD0
static void __stdcall build_tree(deflate_state* s, tree_desc* desc)
{
    ct_data* tree = desc->dyn_tree;
    const ct_data* stree = desc->stat_desc->static_tree;
    int elems = desc->stat_desc->elems;
    int n, m;
    int max_code = -1;
    int node;

    s->heap_len = 0, s->heap_max = HEAP_SIZE;

    for (n = 0; n < elems; n++) {
        if (tree[n].fc.freq != 0) {
            s->heap[++(s->heap_len)] = max_code = n;
            s->depth[n] = 0;
        } else {
            tree[n].dl.len = 0;
        }
    }

    while (s->heap_len < 2) {
        node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
        tree[node].fc.freq = 1;
        s->depth[node] = 0;
        s->opt_len--; if (stree) s->static_len -= stree[node].dl.len;
    }
    desc->max_code = max_code;

    for (n = s->heap_len / 2; n >= 1; n--) pqdownheap(s, tree, n);

    node = elems;
    do {
        pqremove(s, tree, n);
        m = s->heap[SMALLEST];

        s->heap[--(s->heap_max)] = n;
        s->heap[--(s->heap_max)] = m;

        tree[node].fc.freq = tree[n].fc.freq + tree[m].fc.freq;
        s->depth[node] = (unsigned char)((s->depth[n] >= s->depth[m] ?
                                s->depth[n] : s->depth[m]) + 1);
        tree[n].dl.dad = tree[m].dl.dad = (unsigned short)node;
        s->heap[SMALLEST] = node++;
        pqdownheap(s, tree, SMALLEST);

    } while (s->heap_len >= 2);

    s->heap[--(s->heap_max)] = s->heap[SMALLEST];

    gen_bitlen(s, (tree_desc*)desc);

    gen_codes((ct_data*)tree, max_code, s->bl_count);
}

// 0x0042CFD0
static int build_bl_tree(deflate_state* s)
{
    int max_blindex;

    scan_tree(s, (ct_data*)s->dyn_ltree, s->l_desc.max_code);
    scan_tree(s, (ct_data*)s->dyn_dtree, s->d_desc.max_code);

    build_tree(s, (tree_desc*)(&(s->bl_desc)));

    for (max_blindex = BL_CODES - 1; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[bl_order[max_blindex]].dl.len != 0) break;
    }
    s->opt_len += 3 * (max_blindex + 1) + 5 + 5 + 4;

    return max_blindex;
}

// 0x0042D0A0
void __fastcall _tr_stored_block(deflate_state* s, char* buf, unsigned long stored_len, int last)
{
    send_bits(s, (STORED_BLOCK << 1) + last, 3);
    copy_block(s, buf, (unsigned)stored_len, 1);
}

// 0x0042D150
void __fastcall _tr_flush_bits(deflate_state* s)
{
    bi_flush(s);
}

// 0x0042D160
void __fastcall _tr_align(deflate_state* s)
{
    send_bits(s, (STATIC_TREES << 1), 3);
    send_code(s, END_BLOCK, static_ltree);
    bi_flush(s);
}

// 0x0042D250
void __fastcall _tr_flush_block(deflate_state* s, char* buf, unsigned long stored_len, int last)
{
    unsigned long opt_lenb, static_lenb;
    int max_blindex = 0;

    if (s->level > 0) {

        if (s->strm->data_type == Z_UNKNOWN)
            s->strm->data_type = detect_data_type(s);

        build_tree(s, (tree_desc*)(&(s->l_desc)));

        build_tree(s, (tree_desc*)(&(s->d_desc)));

        max_blindex = build_bl_tree(s);

        opt_lenb = (s->opt_len + 3 + 7) >> 3;
        static_lenb = (s->static_len + 3 + 7) >> 3;

        if (static_lenb <= opt_lenb) opt_lenb = static_lenb;

    } else {
        opt_lenb = static_lenb = stored_len + 5;
    }

    if (stored_len + 4 <= opt_lenb && buf != (char*)0) {
        _tr_stored_block(s, buf, stored_len, last);

    } else if (s->strategy == Z_FIXED || static_lenb == opt_lenb) {
        send_bits(s, (STATIC_TREES << 1) + last, 3);
        compress_block(s, (const ct_data*)static_ltree,
                       (const ct_data*)static_dtree);
    } else {
        send_bits(s, (DYN_TREES << 1) + last, 3);
        send_all_trees(s, s->l_desc.max_code + 1, s->d_desc.max_code + 1,
                       max_blindex + 1);
        compress_block(s, (const ct_data*)s->dyn_ltree,
                       (const ct_data*)s->dyn_dtree);
    }
    init_block(s);

    if (last) {
        bi_windup(s);
    }
}

// 0x0042C600
int __fastcall _tr_tally(deflate_state* s, unsigned dist, unsigned lc)
{
    s->d_buf[s->last_lit] = (unsigned short)dist;
    s->l_buf[s->last_lit++] = (unsigned char)lc;
    if (dist == 0) {
        s->dyn_ltree[lc].fc.freq++;
    } else {
        s->matches++;
        dist--;
        s->dyn_ltree[_length_code[lc] + LITERALS + 1].fc.freq++;
        s->dyn_dtree[d_code(dist)].fc.freq++;
    }
    return (s->last_lit == s->lit_bufsize - 1);
}

extern const int gData_006D0D90[29] = { // 0x006D0D90
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002,
    0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000004,
    0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000000
};
#pragma comment(linker, "/alternatename:_extra_lbits=_gData_006D0D90")

extern const unsigned char gData_006D0E04[20] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15, 0 }; // 0x006D0E04
#pragma comment(linker, "/alternatename:_bl_order=_gData_006D0E04")

extern const int gData_006D0E18[30] = { // 0x006D0E18
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000001, 0x00000002, 0x00000002,
    0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000005, 0x00000005, 0x00000006, 0x00000006,
    0x00000007, 0x00000007, 0x00000008, 0x00000008, 0x00000009, 0x00000009, 0x0000000A, 0x0000000A,
    0x0000000B, 0x0000000B, 0x0000000C, 0x0000000C, 0x0000000D, 0x0000000D
};
#pragma comment(linker, "/alternatename:_extra_dbits=_gData_006D0E18")

extern const int gData_006D0E90[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 7, 0 }; // 0x006D0E90

extern const ct_data gData_006D1360[30] = { // 0x006D1360
    { { 0 }, { 5 } },
    { { 16 }, { 5 } },
    { { 8 }, { 5 } },
    { { 24 }, { 5 } },
    { { 4 }, { 5 } },
    { { 20 }, { 5 } },
    { { 12 }, { 5 } },
    { { 28 }, { 5 } },
    { { 2 }, { 5 } },
    { { 18 }, { 5 } },
    { { 10 }, { 5 } },
    { { 26 }, { 5 } },
    { { 6 }, { 5 } },
    { { 22 }, { 5 } },
    { { 14 }, { 5 } },
    { { 30 }, { 5 } },
    { { 1 }, { 5 } },
    { { 17 }, { 5 } },
    { { 9 }, { 5 } },
    { { 25 }, { 5 } },
    { { 5 }, { 5 } },
    { { 21 }, { 5 } },
    { { 13 }, { 5 } },
    { { 29 }, { 5 } },
    { { 3 }, { 5 } },
    { { 19 }, { 5 } },
    { { 11 }, { 5 } },
    { { 27 }, { 5 } },
    { { 7 }, { 5 } },
    { { 23 }, { 5 } }
};
#pragma comment(linker, "/alternatename:_static_dtree=_gData_006D1360")

extern const int gData_006D16D8[30] = { // 0x006D16D8
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 16, 20, 24, 28,
    32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 0, 0
};
#pragma comment(linker, "/alternatename:_base_length=_gData_006D16D8")

extern const int gData_006D1750[30] = { // 0x006D1750
    0, 1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96, 128, 192,
    256, 384, 512, 768, 1024, 1536, 2048, 3072, 4096, 6144, 8192, 12288, 16384, 24576
};
#pragma comment(linker, "/alternatename:_base_dist=_gData_006D1750")

static_tree_desc static_l_desc = { static_ltree, extra_lbits, 257, 286, 15 }; // 0x007088F4

static_tree_desc static_d_desc = { static_dtree, extra_dbits, 0, 30, 15 }; // 0x00708908

static_tree_desc static_bl_desc = { 0, gData_006D0E90, 0, 19, 7 }; // 0x0070891C
