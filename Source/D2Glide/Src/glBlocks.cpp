#include "D2Glide.h"

unsigned char* gpGlideTileDecodeBuffer;                                                            // 0x00880BFC
unsigned char* gpGlideFloorDecodeBuffer;                                                           // 0x00880C00

extern D2GrTexInfoStrc gtGlideFloorTexInfo; // 0x0072F6BC

extern D2GrTexInfoStrc gtGlideTileTexInfo; // 0x0072F6A8

// 0x0050F8C0
void __cdecl GLBLOCKS_FreeBlockBuffers()
{
    if (gpGlideTileDecodeBuffer)
    {
        FOG_Free(gpGlideTileDecodeBuffer, ".\\Src\\glBlocks.cpp", 0x3F, 0);
        gpGlideTileDecodeBuffer = 0;
    }
    if (gpGlideFloorDecodeBuffer)
    {
        FOG_Free(gpGlideFloorDecodeBuffer, ".\\Src\\glBlocks.cpp", 0x45, 0);
        gpGlideFloorDecodeBuffer = 0;
    }
}

// 0x0050F870
void __cdecl GLBLOCKS_InitBlockBuffers()
{
    gpGlideTileDecodeBuffer = (unsigned char*)FOG_Alloc(0x400, ".\\Src\\glBlocks.cpp", 0x33, 0);
    gpGlideFloorDecodeBuffer = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glBlocks.cpp", 0x34, 0);
    gtGlideTileTexInfo.pData = gpGlideTileDecodeBuffer;
    gtGlideFloorTexInfo.pData = gpGlideFloorDecodeBuffer;
}
