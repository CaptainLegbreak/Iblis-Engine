// Functional replacement for the function at 0x004F8B80, not the original code: only the ordinary build (tools/link.py) uses it.

struct D2TileLibraryBlockStrc
{
    short nPosX;
    short nPosY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned char nFormat;
    char unk0x09[0x07];
    unsigned char* pData;
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x50];
    int nBlocks;
    D2TileLibraryBlockStrc* pBlocks;
};

struct D2LightCellStrc
{
    unsigned char nLevel;
    unsigned char unk0x01[0x0B];
};

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

void __fastcall CMNSUBTILE_DrawBlock(D2TileLibraryBlockStrc* pBlock, unsigned char* pDst, unsigned char nLight); // 0x004F8810
void __fastcall CMNSUBTILE_DrawLitBlock(D2TileLibraryBlockStrc* pBlock, unsigned char* pDst, int* pLight); // 0x004F8850
void __fastcall CMNSUBTILE_DrawBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, unsigned char nLight); // 0x004F88B0
void __fastcall CMNSUBTILE_DrawLitBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, int* pLight); // 0x004F89F0

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48
extern int gnInnerBlockTop; // 0x007C9780
extern int gnTileClipLeft_007C9788; // 0x007C9788
extern int gnTileClipRight_007C9798; // 0x007C9798
extern int gnInnerBlockBottom; // 0x007C979C
extern int gnInnerBlockLeft; // 0x007C97A4
extern int gnInnerBlockRight; // 0x007D2320
extern int gnTileClipTop_007D2330; // 0x007D2330
extern int gnTileClipBottom_007D2338; // 0x007D2338
extern int gnLightingOff; // 0x007D2340
extern unsigned char* gpScreenBuffer; // 0x007D5448
extern int gnScreenPitch; // 0x007D544C

// 0x004F8B80
void __fastcall sub_004F8B80_DrawTileBlocks(D2TileLibraryEntryStrc* pTile, int nX, int nY, D2LightCellStrc (*pLight)[8])
{
    unsigned char* pScreen = gnScreenPitch * nY + gpScreenBuffer + nX;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        D2TileLibraryBlockStrc* pBlock = &pTile->pBlocks[i];
        const int nPosX = pBlock->nPosX;
        unsigned char* pDst = pBlock->nPosY * gnScreenPitch + nPosX + pScreen;
        const int nBlockY = nY + pBlock->nPosY;
        if (!(pBlock->nFormat & 1))
            continue;
        const int nBlockX = nPosX + nX;
        if (nBlockY < gnTileClipTop_007D2330 || nBlockY >= gnTileClipBottom_007D2338 || nBlockX < gnTileClipLeft_007C9788 || nBlockX >= gnTileClipRight_007C9798)
            continue;

        int aLight[4];
        int bFlat = 0;
        unsigned char nLight = 0;
        if (gnLightingOff)
        {
            nLight = pLight[pBlock->nGridY + 1][pBlock->nGridX + 1].nLevel;
            bFlat = 1;
        }
        else
        {
            D2LightCellStrc* pCell = pLight[pBlock->nGridY] + pBlock->nGridX;
            const int nL21 = pCell[10].nLevel;
            const int nL12 = pCell[17].nLevel;
            const int nL11 = pCell[9].nLevel;
            const int nL22 = pCell[18].nLevel;
            int nDelta = nL21 - nL11;
            const int nDiff1 = D2_ABS(nDelta);
            nDelta = nL12 - nL11;
            const int nDiff2 = D2_ABS(nDelta);
            nDelta = nL22 - nL21;
            const int nDiff3 = D2_ABS(nDelta);
            if (!gGfxSettings.bLowQuality && nDiff3 + nDiff2 + nDiff1 >= 10)
            {
                aLight[0] = (nL12 + pCell[16].nLevel + nL11 + pCell[8].nLevel) >> 2;
                aLight[1] = (pCell[1].nLevel + pCell[2].nLevel + nL21 + nL11) >> 2;
                aLight[2] = (pCell[19].nLevel + nL12 + pCell[11].nLevel + nL21) >> 2;
                aLight[3] = (pCell[25].nLevel + pCell[26].nLevel + nL22 + nL12) >> 2;
            }
            else
            {
                nLight = nL11;
                bFlat = 1;
            }
        }

        if (nBlockY >= gnInnerBlockTop && nBlockY < gnInnerBlockBottom && nBlockX >= gnInnerBlockLeft && nBlockX < gnInnerBlockRight)
        {
            if (bFlat)
                CMNSUBTILE_DrawBlock(pBlock, pDst, nLight);
            else
                CMNSUBTILE_DrawLitBlock(pBlock, pDst, aLight);
        }
        else
        {
            if (bFlat)
                CMNSUBTILE_DrawBlockClipped(pBlock, nBlockX, nBlockY, pDst, nLight);
            else
                CMNSUBTILE_DrawLitBlockClipped(pBlock, nBlockX, nBlockY, pDst, aLight);
        }
    }
}
