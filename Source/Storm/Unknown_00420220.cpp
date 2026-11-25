#include "D2GameTypes.h"
#include "Storm.h"
#include "D2Win32Message.h"


typedef int (__stdcall* SMSGIDLEPROC)(int nCount);

struct D2Strc00420E80
{
    char pad0x00[0x158];
    char tField158;
    void* sub_00420E80_GetField158();
};

// 0x00420E80
void* D2Strc00420E80::sub_00420E80_GetField158()
{
    return &tField158;
}

// 0x00420E90
static inline unsigned int sub_00420E90_TakeLow32(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    return nLow;
}

// 0x00420F00
static inline unsigned int sub_00420F00_TakeLow32Ext(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    if (*pValue >= 0x80000000)
    {
        *pValue |= 0xFFFFFFFF00000000ull;
    }
    return nLow;
}

unsigned int __fastcall sub_M119_Emit_00420E90(unsigned __int64* pValue, int nOther)
{
    return sub_00420E90_TakeLow32(pValue) + sub_00420F00_TakeLow32Ext((unsigned __int64*)nOther);
}
