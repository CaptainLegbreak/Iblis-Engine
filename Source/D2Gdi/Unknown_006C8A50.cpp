#include "D2Gdi.h"
#include "D2GfxTypes.h"
#include "D2GlideApi.h"

// 0x006C8A50
int __cdecl sub_006C8A50_GetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}
