#include "Storm.h"
// Altered from the original zlib source.
#define OFF 1
#define PUP(a) *++(a)
#define TYPE 11
#define BAD 29
#define MAXBITS 15
#define ENOUGH_LENS 852
#define ENOUGH_DISTS 592

typedef enum
{
    CODES,
    LENS,
    DISTS
} codetype;

struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char* msg;
    void* state;
};

struct inflate_state
{
    int mode;
    char pad04[0x24];
    unsigned int wsize;
    unsigned int whave;
    unsigned int wnext;
    unsigned char* window;
    unsigned long hold;
    unsigned int bits;
    char pad40[0xC];
    const code* lencode;
    const code* distcode;
    unsigned int lenbits;
    unsigned int distbits;
    char pad5C[0x1B64];
    int sane;
};

// 0x0042DCA0
void __fastcall inflate_fast(z_stream* strm, unsigned start)
{
    inflate_state* state;
    const unsigned char* in;
    const unsigned char* last;
    unsigned char* out;
    unsigned char* beg;
    unsigned char* end;
    unsigned wsize;
    unsigned whave;
    unsigned wnext;
    unsigned char* window;
    unsigned long hold;
    unsigned bits;
    const code* lcode;
    const code* dcode;
    unsigned lmask;
    unsigned dmask;
    code here;
    unsigned op;
    unsigned len;
    unsigned dist;
    unsigned char* from;

    state = (inflate_state*)strm->state;
    in = strm->next_in - OFF;
    last = in + (strm->avail_in - 5);
    out = strm->next_out - OFF;
    beg = out - (start - strm->avail_out);
    end = out + (strm->avail_out - 257);
    wsize = state->wsize;
    whave = state->whave;
    wnext = state->wnext;
    window = state->window;
    hold = state->hold;
    bits = state->bits;
    lcode = state->lencode;
    dcode = state->distcode;
    lmask = (1U << state->lenbits) - 1;
    dmask = (1U << state->distbits) - 1;

    do {
        if (bits < 15) {
            hold += (unsigned long)(PUP(in)) << bits;
            bits += 8;
            hold += (unsigned long)(PUP(in)) << bits;
            bits += 8;
        }
        here = lcode[hold & lmask];
      dolen:
        op = (unsigned)(here.bits);
        hold >>= op;
        bits -= op;
        op = (unsigned)(here.op);
        if (op == 0) {
            PUP(out) = (unsigned char)(here.val);
        }
        else if (op & 16) {
            len = (unsigned)(here.val);
            op &= 15;
            if (op) {
                if (bits < op) {
                    hold += (unsigned long)(PUP(in)) << bits;
                    bits += 8;
                }
                len += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
            }
            if (bits < 15) {
                hold += (unsigned long)(PUP(in)) << bits;
                bits += 8;
                hold += (unsigned long)(PUP(in)) << bits;
                bits += 8;
            }
            here = dcode[hold & dmask];
          dodist:
            op = (unsigned)(here.bits);
            hold >>= op;
            bits -= op;
            op = (unsigned)(here.op);
            if (op & 16) {
                dist = (unsigned)(here.val);
                op &= 15;
                if (bits < op) {
                    hold += (unsigned long)(PUP(in)) << bits;
                    bits += 8;
                    if (bits < op) {
                        hold += (unsigned long)(PUP(in)) << bits;
                        bits += 8;
                    }
                }
                dist += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
                op = (unsigned)(out - beg);
                if (dist > op) {
                    op = dist - op;
                    if (op > whave) {
                        if (state->sane) {
                            strm->msg = (char*)"invalid distance too far back";
                            state->mode = BAD;
                            break;
                        }
                    }
                    from = window - OFF;
                    if (wnext == 0) {
                        from += wsize - op;
                        if (op < len) {
                            len -= op;
                            do {
                                PUP(out) = PUP(from);
                            } while (--op);
                            from = out - dist;
                        }
                    }
                    else if (wnext < op) {
                        from += wsize + wnext - op;
                        op -= wnext;
                        if (op < len) {
                            len -= op;
                            do {
                                PUP(out) = PUP(from);
                            } while (--op);
                            from = window - OFF;
                            if (wnext < len) {
                                op = wnext;
                                len -= op;
                                do {
                                    PUP(out) = PUP(from);
                                } while (--op);
                                from = out - dist;
                            }
                        }
                    }
                    else {
                        from += wnext - op;
                        if (op < len) {
                            len -= op;
                            do {
                                PUP(out) = PUP(from);
                            } while (--op);
                            from = out - dist;
                        }
                    }
                    while (len > 2) {
                        PUP(out) = PUP(from);
                        PUP(out) = PUP(from);
                        PUP(out) = PUP(from);
                        len -= 3;
                    }
                    if (len) {
                        PUP(out) = PUP(from);
                        if (len > 1)
                            PUP(out) = PUP(from);
                    }
                }
                else {
                    from = out - dist;
                    do {
                        PUP(out) = PUP(from);
                        PUP(out) = PUP(from);
                        PUP(out) = PUP(from);
                        len -= 3;
                    } while (len > 2);
                    if (len) {
                        PUP(out) = PUP(from);
                        if (len > 1)
                            PUP(out) = PUP(from);
                    }
                }
            }
            else if ((op & 64) == 0) {
                here = dcode[here.val + (hold & ((1U << op) - 1))];
                goto dodist;
            }
            else {
                strm->msg = (char*)"invalid distance code";
                state->mode = BAD;
                break;
            }
        }
        else if ((op & 64) == 0) {
            here = lcode[here.val + (hold & ((1U << op) - 1))];
            goto dolen;
        }
        else if (op & 32) {
            state->mode = TYPE;
            break;
        }
        else {
            strm->msg = (char*)"invalid literal/length code";
            state->mode = BAD;
            break;
        }
    } while (in < last && out < end);

    len = bits >> 3;
    in -= len;
    bits -= len << 3;
    hold &= (1U << bits) - 1;

    strm->next_in = (unsigned char*)(in + OFF);
    strm->next_out = out + OFF;
    strm->avail_in = (unsigned)(in < last ? 5 + (last - in) : 5 - (in - last));
    strm->avail_out = (unsigned)(out < end ? 257 + (end - out) : 257 - (out - end));
    state->hold = hold;
    state->bits = bits;
    return;
}
