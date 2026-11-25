#include "D2Gdi.h"
#include "D2GfxTypes.h"

extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148

// 0x006C8A50
int __cdecl sub_006C8A50_GetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}
