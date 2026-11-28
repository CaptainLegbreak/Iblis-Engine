#pragma once
// D2CMP's exports that the other modules call: cel files, tiles and the sprite cache.

struct D2PoolSystemStrc;
struct D2CelFileStrc;
struct D2CelStrc;
struct D2CmpCelContextStrc;
struct D2TileLibraryEntryStrc;

void __stdcall D2CMPTileCacheDestroy(int bFree); // 0x005FDE10
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pEntry, int nUnused1, int nUnused2); // 0x005FDEA0
void __fastcall D2CMPTileCacheSetFreeCallback(void* pfnCallback); // 0x005FE000
void __stdcall D2CMPGetTileCacheHits(int* pnArg, int* pnCountB, int* pnCountA, int* pnHitPercent); // 0x005FE010
extern "C" void __cdecl D2CMPResetTileCacheHits(); // 0x005FE060
void __cdecl D2CMPTileFreeAsyncLoads(); // 0x005FE070
void __stdcall D2CMPTileCacheInit(D2PoolSystemStrc* pMemPool, int nArg); // 0x005FE120
const char* __stdcall D2CMPGetGfxFileExtension(int bAllowCompressed); // 0x005FE1F0
void __stdcall D2CMPSetNoCompress(int bAllowCompressed); // 0x005FE280
unsigned int __cdecl D2CMPSpriteCacheGetUsedMemory(); // 0x005FEE10
int __cdecl D2CMPSpriteCacheGetMaxMemory(); // 0x005FEE40
int __cdecl D2CMPCelDataCacheGetUsedMemory(); // 0x005FEE60
int __cdecl D2CMPCelDataCacheGetMaxMemory(); // 0x005FEE70
void __cdecl D2CMPSpriteFreeAsyncLoads(); // 0x005FF3A0
void __stdcall D2CMPSpriteCacheInit(D2PoolSystemStrc* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40
void __stdcall D2CMPSpriteCacheDestroy(int bFree); // 0x005FFE30
void __cdecl D2CMP_LoadItemPalShifts(); // 0x00600B80
int __fastcall DATATBLS_CallFree(void* pMemory); // 0x00600C60
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused); // 0x00601340
void __stdcall CelDrawEx(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nClipTop, int nClipRows, int nArg13); // 0x00601650
void __stdcall CelDrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor); // 0x00601730
D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pCelContext); // 0x00601840
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pFile); // 0x006019F0
int __stdcall CelFileFreeHardware(D2CelFileStrc* ptFile); // 0x00601A50
void* __stdcall CelGetHardwareData(D2CelStrc* pCel); // 0x00601B10
int __stdcall TileGetType(D2TileLibraryEntryStrc* hTile); // 0x00604B60
int __stdcall TileGetStyle(D2TileLibraryEntryStrc* pTile); // 0x00604B90
int __stdcall TileGetFlags(D2TileLibraryEntryStrc* hTile); // 0x00604BC0
int __stdcall TileGetRarity(D2TileLibraryEntryStrc* hTile); // 0x00604C20
int __stdcall TileGetSequence(D2TileLibraryEntryStrc* hTile); // 0x00604C50
int __stdcall TileGetTotalHeight(D2TileLibraryEntryStrc* hTile); // 0x00604CB0
unsigned char* __stdcall TileGetCollisionInfo(D2TileLibraryEntryStrc* pTile); // 0x00604CE0
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __stdcall CmpDoLensEffect(unsigned char* pBuffer, int nPitch); // 0x00608C00
int __cdecl DATATBLS_GetAnimData(); // 0x00611D20
void __stdcall sub_0066A220(int nUnused1, int nUnused2); // 0x0066A220
