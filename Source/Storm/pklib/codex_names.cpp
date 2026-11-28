// The names the game source (a copy of Iblis Codex) still calls the PKWARE routines by: placeholders for the
// library code at 0x006B01B0 and 0x006B0870 in 1.14d. They go away when Codex names the calls explode/implode.
#include "pklib.h"

extern "C" unsigned int __cdecl sub_006B01B0_Explode(PKReadFn pfnRead, PKWriteFn pfnWrite, char* pWork, void* pParam)
{
    return explode(pfnRead, pfnWrite, pWork, pParam);
}

extern "C" unsigned int __cdecl sub_006B0870_Implode(PKReadFn pfnRead, PKWriteFn pfnWrite, char* pWork, void* pParam,
                                                     unsigned int* pType, unsigned int* pDictSize)
{
    return implode(pfnRead, pfnWrite, pWork, pParam, pType, pDictSize);
}
