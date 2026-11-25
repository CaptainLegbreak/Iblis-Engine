// Altered from the original zlib source.
#define Z_NEED_DICT 2
#define ZLIB_VERSION "1.2.8"
#define ERR_MSG(err) z_errmsg[Z_NEED_DICT - (err)]

void* __cdecl malloc(unsigned int nSize); // 0x00683EFD
void* __cdecl calloc(unsigned int nCount, unsigned int nSize);
void __cdecl free(void* pMemory); // 0x00683FC0
extern const char* const z_errmsg[10]; // 0x006D3848

// 0x0042DC30
const char* __cdecl zlibVersion(void)
{
    return ZLIB_VERSION;
}

// 0x0042DC40
unsigned long __cdecl zlibCompileFlags(void)
{
    unsigned long flags;

    flags = 0;
    switch ((int)(sizeof(unsigned int))) {
    case 2:     break;
    case 4:     flags += 1;     break;
    case 8:     flags += 2;     break;
    default:    flags += 3;
    }
    switch ((int)(sizeof(unsigned long))) {
    case 2:     break;
    case 4:     flags += 1 << 2;        break;
    case 8:     flags += 2 << 2;        break;
    default:    flags += 3 << 2;
    }
    switch ((int)(sizeof(void*))) {
    case 2:     break;
    case 4:     flags += 1 << 4;        break;
    case 8:     flags += 2 << 4;        break;
    default:    flags += 3 << 4;
    }
    switch ((int)(sizeof(long))) {
    case 2:     break;
    case 4:     flags += 1 << 6;        break;
    case 8:     flags += 2 << 6;        break;
    default:    flags += 3 << 6;
    }
    return flags;
}

// 0x0042DC50
const char* __fastcall zError(int err)
{
    return ERR_MSG(err);
}

// 0x0042DC70
void* __fastcall zcalloc(void* opaque, unsigned int items, unsigned int size)
{
    return sizeof(unsigned int) > 2 ? malloc(items * size) : calloc(items, size);
}

// 0x0042DC90
void __fastcall zcfree(void* opaque, void* ptr)
{
    free(ptr);
}

#include "gen/data/Source/Storm/zlib/zutil.inc"
