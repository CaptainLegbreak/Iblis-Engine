#include "D2LanguageNames.h"
#include "TALLOCREC.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2Win32Types.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2TileLibraryEntryStrc;
struct D2DrlgCoordStrc;
struct D2RoomCoordListStrc;
struct D2DrlgCoordsStrc;
struct D2StaticPathStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount); // 0x006196A0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom); // 0x0061AD50
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
int __stdcall TileGetFlags(D2TileLibraryEntryStrc* pTile); // 0x00604BC0
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __fastcall CUNIT_DrawAutomapDiamond(int nX, int nY, unsigned char nColor); // 0x0045B1A0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
extern int gnAutomapOriginY; // 0x007A5208
extern int gnAutomapOriginX; // 0x007A520C

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __cdecl D2GFX_GetDisplayType(); // 0x004F5140
void __stdcall AUTOMAP_DrawRoomCollision(D2ActiveRoomStrc* pRoom); // 0x0045B4F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom); // 0x0045B5F0

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, va_list args); // 0x006CC4AC

struct D2SMemBlockInfoStrc
{
    unsigned int dwSize;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int dw0C;
    unsigned int nBytes;
    unsigned int dw14;
    unsigned int dw18;
};

struct D2HellAllocHeaderStrc
{
    unsigned int dwSignature[4];
    int nLine;
    int nSize;
    unsigned int adwFile[0x41];
    unsigned int adwName[0x41];
};

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwAccess, unsigned long dwShareMode, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x006CC19C
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                 // 0x006CC134
int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, D2SMemHeapInfoStrc* pInfo);      // 0x004124B0
int __stdcall SMemFindNextBlock(unsigned int hHeap, void* pMemory, void** ppBlock, D2SMemBlockInfoStrc* pInfo); // 0x004122F0
unsigned int __stdcall SMemGetHeapByCaller(const char* szFile, int nLine);                                 // 0x00412710

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x0045B5F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom)
{
    int nTiles;
    D2DrlgTileDataStrc* pTiles = DUNGEON_GetWallTilesFromRoom(pRoom, &nTiles);
    D2_ASSERT(pTiles || !nTiles, 725);

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    for (unsigned int i = 0; i < (unsigned int)nTiles; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles[i];
        if (!pTile->pCoordList)
        {
            continue;
        }

        int nX = (pTile->nPosX + tCoords.nTileXPos) * 5 + 3;
        int nY = (pTile->nPosY + tCoords.nTileYPos) * 5 + 3;
        DUNGEON_GameSubtileToClientCoords(&nX, &nY);

        if (pTile->nTileType == 15 || (pTile->dwFlags & 0x1C000) != 0x4000)
        {
            continue;
        }

        if (TileGetFlags(pTile->pTile) & 4)
        {
            const int nDiamondX = nX + 0x20;
            tagRECT tRect;
            tRect.left = nDiamondX - gnAutomapOriginX - 0x10;
            tRect.right = nDiamondX - gnAutomapOriginX + 0x10;
            tRect.top = nY - gnAutomapOriginY;
            tRect.bottom = nY - gnAutomapOriginY + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x78);
        }
        else if (pTile->dwFlags & 0x800)
        {
            CUNIT_DrawAutomapDiamond(nX + 0x10, nY + 8, 0x78);
        }
        else
        {
            CUNIT_DrawAutomapDiamond(nX, nY, 0xFF);
        }

        nX -= gnAutomapOriginX + 7;
        nY -= gnAutomapOriginY;
        D2GFX_OutputString(nX, nY, gszFormatInt_006D57BC, pTile->pCoordList->nIndex);
    }

    if (pRoom == CUNIT_GetPlayerRoom())
    {
        int aX[4];
        int aY[4];
        for (D2RoomCoordListStrc* pCoordList = DUNGEON_GetRoomCoordList(pRoom); pCoordList; pCoordList = pCoordList->pNext)
        {
            aX[0] = aX[1] = pCoordList->pBox[0].left;
            aX[2] = aX[3] = pCoordList->pBox[0].right;
            aY[0] = aY[2] = pCoordList->pBox[0].top;
            aY[1] = aY[3] = pCoordList->pBox[0].bottom;

            for (int j = 0; j < 4; ++j)
            {
                DUNGEON_GameTileToClientCoords(&aX[j], &aY[j]);
                aX[j] -= gnAutomapOriginX;
                aY[j] -= gnAutomapOriginY;
            }

            if (pRoom == CUNIT_GetPlayerRoom())
            {
                D2GFX_DrawLine(aX[0], aY[0], aX[0], aY[0] + 0x10, 0x78, 0xFF);
                D2GFX_DrawLine(aX[1], aY[1], aX[1] + 0x10, aY[1], 0x78, 0xFF);
                D2GFX_DrawLine(aX[2], aY[2], aX[2] - 0x10, aY[2], 0x78, 0xFF);
                D2GFX_DrawLine(aX[3], aY[3], aX[3], aY[3] - 0x10, 0x78, 0xFF);
            }

            D2GFX_DrawLine(aX[0], aY[0], aX[1], aY[1], 0x78, 0xFF);
            D2GFX_DrawLine(aX[0], aY[0], aX[2], aY[2], 0x78, 0xFF);
            D2GFX_DrawLine(aX[1], aY[1], aX[3], aY[3], 0x78, 0xFF);
            D2GFX_DrawLine(aX[2], aY[2], aX[3], aY[3], 0x78, 0xFF);
        }
    }
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0045B8B0
void __cdecl sub_0045B8B0_DrawLogicalRoom()
{
    if (D2GFX_GetDisplayType() == 3)
        return;

    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    int nX = UNITS_GetXPositionInline(pPlayer);
    int nY = UNITS_GetYPositionInline(pPlayer);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    D2GFX_OutputString(10, 0x37, "Logical Room->%d", sub_0061B130_GetCollision(pRoom, nX, nY));
    AUTOMAP_DrawRoomCollision(pRoom);
    sub_0045B5F0(pRoom);
}

// 0x0045B960
void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...)
{
    char szBuffer[256];
    va_list args;
    va_start(args, szFormat);
    unsigned long nWritten = wvsprintfA(szBuffer, szFormat, args);
    WriteFile(hFile, szBuffer, nWritten, &nWritten, 0);
}

// 0x0045BA90
extern "C" void* __fastcall sub_0045BA90(void* value) { return value; }

// The memory report's list members (TSLink and TSList for TALLOCREC), in the order the object has them.
// build: symbol ?Next@?$TSLink@UTALLOCREC@@@@QAEPAUTALLOCREC@@XZ 0x0045B9D0
// build: symbol ?RawNext@?$TSLink@UTALLOCREC@@@@QAEPAUTALLOCREC@@XZ 0x0045B9E0
// build: symbol ?Unlink@?$TSLink@UTALLOCREC@@@@QAEXXZ 0x0045B9F0
// build: symbol ??1?$TSLink@UTALLOCREC@@@@QAE@XZ 0x0045BA30
// build: symbol ?Next@?$TSLinkedNode@UTALLOCREC@@@@QAEPAUTALLOCREC@@XZ 0x0045BAA0
// build: symbol ?InitializeTerminator@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXXZ 0x0045BA80
// build: symbol ?Head@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@XZ 0x0045BAB0
// build: symbol ??0?$TSLink@UTALLOCREC@@@@QAE@XZ 0x0045BAC0
// build: symbol ??0?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAE@XZ 0x0045BBC0
// build: symbol ?UnlinkAll@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXXZ 0x0045BD00
// build: symbol ??1?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAE@XZ 0x0045BD40
template TALLOCREC* TSLink<TALLOCREC>::Next();
template TALLOCREC* TSLink<TALLOCREC>::RawNext();
template void TSLink<TALLOCREC>::Unlink();
template TSLink<TALLOCREC>::~TSLink();
template TALLOCREC* TSLinkedNode<TALLOCREC>::Next();
template void TSList<TALLOCREC>::InitializeTerminator();
template TALLOCREC* TSList<TALLOCREC>::Head();
template TSLink<TALLOCREC>::TSLink();
template TSList<TALLOCREC>::TSList();
template TSList<TALLOCREC>::~TSList();
// build: symbol ?NextLink@?$TSLink@UTALLOCREC@@@@QAEPAU1@H@Z 0x0045B9A0
// build: symbol ?Link@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAU?$TSLink@UTALLOCREC@@@@PBUTALLOCREC@@@Z 0x0045BB30
// build: symbol ?Next@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@PBU2@@Z 0x0045BB50
// build: symbol ?UnlinkNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXPAUTALLOCREC@@@Z 0x0045BB70
// build: symbol ?LinkNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXPAUTALLOCREC@@I0@Z 0x0045BBE0
// build: symbol ?RawNext@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@PBU2@@Z 0x0045BC90
// build: symbol ?NewNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@III@Z 0x0045BDD0
// build: symbol ??0?$TSLinkedNode@UTALLOCREC@@@@QAE@XZ 0x0045BCB0
// build: symbol ??1?$TSLinkedNode@UTALLOCREC@@@@QAE@XZ 0x0045BCC0
// build: symbol ??0TALLOCREC@@QAE@XZ 0x0045BD80
// build: symbol ??1TALLOCREC@@QAE@XZ 0x0045BD90
// build: symbol ??_GTALLOCREC@@QAEPAXI@Z 0x0045BE30
// build: symbol ?DeleteNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@PAU2@@Z 0x0045BE90
// build: symbol ??_R0?AUTALLOCREC@@@8 0x00711478
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
template TSLink<TALLOCREC>* TSLink<TALLOCREC>::NextLink(int);
template TSLink<TALLOCREC>* TSList<TALLOCREC>::Link(const TALLOCREC*);
template TALLOCREC* TSList<TALLOCREC>::Next(const TALLOCREC*);
template void TSList<TALLOCREC>::UnlinkNode(TALLOCREC*);
template void TSList<TALLOCREC>::LinkNode(TALLOCREC*, unsigned int, TALLOCREC*);
template TALLOCREC* TSList<TALLOCREC>::RawNext(const TALLOCREC*);
template void TSList<TALLOCREC>::UnlinkAll();
template TALLOCREC* TSList<TALLOCREC>::NewNode(unsigned int, unsigned int, unsigned int);
template TALLOCREC* TSList<TALLOCREC>::DeleteNode(TALLOCREC*);

// Three of the object's members are still unplaced: a link clear, a second unlink and a list reset. They are
// probably members of TSLink or TSList the template here doesn't have, so they keep their own names.
struct D2AllocRecPairStrc
{
    int nFirst;
    int nSecond;

    void sub_0045BA70_Clear();
};

struct D2AllocRecLinkStrc
{
    TSLink<TALLOCREC>* m_prevlink;
    TALLOCREC* m_next;

    void sub_0045BAD0_Unlink();
};

struct D2AllocRecListResetStrc
{
    int m_linkoffset;
    TSLink<TALLOCREC> m_terminator;

    void sub_0045BB10_Initialize();
};

// 0x0045BA70
void D2AllocRecPairStrc::sub_0045BA70_Clear()
{
    nFirst = 0;
    nSecond = 0;
}

// 0x0045BAD0
void D2AllocRecLinkStrc::sub_0045BAD0_Unlink()
{
    ((TSLink<TALLOCREC>*)this)->Unlink();
}

// 0x0045BB10
void D2AllocRecListResetStrc::sub_0045BB10_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (TALLOCREC*)~(unsigned int)&m_terminator;
}


// 0x0045BF00
void __cdecl sub_0045BF00_DumpMemory()
{
    void* hFile = CreateFileA("D2Mem.txt", 0x40000000, 0, 0, 2, 0x80, 0);
    sub_0045B960_FilePrintf(hFile, "D2 MEMORY CHECK\n");
    sub_0045B960_FilePrintf(hFile, "================================================\n\n");

    TSList<TALLOCREC> tList;
    D2SMemHeapInfoStrc tInfo;
    unsigned int hHeap = 0;
    tInfo.dwSize = sizeof(tInfo);
    while (SMemFindNextHeap(hHeap, &hHeap, &tInfo))
    {
        TALLOCREC* pNode = tList.NewNode(0, 0, 0);
        pNode->tInfo = tInfo;
        TALLOCREC* pCurrent = tList.Head();
        if (pCurrent)
        {
            if (pCurrent->tInfo.dw124 < tInfo.dw124)
            {
                tList.LinkNode(pNode, 1, 0);
            }
            else
            {
                TALLOCREC* pNext;
                while ((pNext = pCurrent->Next()) != 0 && pNext->tInfo.dw124 > tInfo.dw124)
                {
                    pCurrent = pNext;
                }
                tList.LinkNode(pNode, 1, pCurrent);
            }
        }
        else
        {
            tList.LinkNode(pNode, 1, 0);
        }
    }

    unsigned int nTotal124 = 0;
    unsigned int nTotal120 = 0;
    unsigned int nTotal118 = 0;
    unsigned int nTotal114 = 0;
    unsigned int nTotal11C = 0;
    unsigned int nTotal110 = 0;
    int nHeaps = 0;
    sub_0045B960_FilePrintf(hFile, "      SIZE|    BLOCKS|  RESERVED| COMMITTED|       MAX|   REGIONS|FILENAME:LINE\n");
    TALLOCREC* pHead = tList.Head();
    for (TALLOCREC* pRec = pHead; (int)pRec > 0; pRec = pRec->m_link.m_next)
    {
        sub_0045B960_FilePrintf(hFile, "%10d|%10d|%10d|%10d|%10d|%10d|%s:%d\n", pRec->tInfo.dw124, pRec->tInfo.dw120, pRec->tInfo.dw118,
            pRec->tInfo.dw114, pRec->tInfo.dw11C, pRec->tInfo.dw110, (char*)pRec->tInfo.adwName, pRec->tInfo.nLine);
        nTotal124 += pRec->tInfo.dw124;
        nTotal120 += pRec->tInfo.dw120;
        nTotal118 += pRec->tInfo.dw118;
        nTotal114 += pRec->tInfo.dw114;
        nTotal11C += pRec->tInfo.dw11C;
        nTotal110 += pRec->tInfo.dw110;
        ++nHeaps;
    }

    sub_0045B960_FilePrintf(hFile, "================================================\n\n");
    sub_0045B960_FilePrintf(hFile, "NUM HEAPS:       %10d\n", nHeaps);
    sub_0045B960_FilePrintf(hFile, "TOTAL MEMORY:    %10d\n", nTotal124);
    sub_0045B960_FilePrintf(hFile, "TOTAL BLOCKS:    %10d\n", nTotal120);
    sub_0045B960_FilePrintf(hFile, "TOTAL RESERVED:  %10d\n", nTotal118);
    sub_0045B960_FilePrintf(hFile, "TOTAL COMMITTED: %10d\n", nTotal114);
    sub_0045B960_FilePrintf(hFile, "TOTAL MAX:       %10d\n", nTotal11C);
    sub_0045B960_FilePrintf(hFile, "TOTAL REGIONS:   %10d\n\n\n\n\n", nTotal110);
    sub_0045B960_FilePrintf(hFile, "================================================\n\n");

    hHeap = SMemGetHeapByCaller("SOURCE\\D2HELL\\Src\\Archive.cpp", 0xF5);
    D2SMemBlockInfoStrc tBlock;
    tBlock.dwSize = sizeof(tBlock);
    void* pBlock = 0;
    unsigned int nAllocTotal = 0;
    unsigned int nAllocCount = 0;
    unsigned int nBlockTotal = 0;
    while (SMemFindNextBlock(hHeap, pBlock, &pBlock, &tBlock))
    {
        if (tBlock.nBytes > 0x220 && tBlock.dw0C && tBlock.dw08)
        {
            for (unsigned int* p = (unsigned int*)pBlock; p < (unsigned int*)((char*)pBlock + tBlock.nBytes); ++p)
            {
                if (p[0] == 'LOAD' && p[1] == 'FUCK' && p[2] == 'THIS' && p[3] == 'NOW ')
                {
                    D2HellAllocHeaderStrc* pHeader = (D2HellAllocHeaderStrc*)p;
                    sub_0045B960_FilePrintf(hFile, "%8d\t%50s\t(%s:%d)\n", pHeader->nSize, (char*)pHeader->adwName, (char*)pHeader->adwFile, pHeader->nLine);
                    nAllocTotal += pHeader->nSize;
                    nBlockTotal += tBlock.nBytes;
                    ++nAllocCount;
                    break;
                }
            }
        }
    }

    sub_0045B960_FilePrintf(hFile, "TOTAL MEMORY: %8d\n", nAllocTotal);
    sub_0045B960_FilePrintf(hFile, "TOTAL ALLOC:  %8d\n", nBlockTotal);
    sub_0045B960_FilePrintf(hFile, "TOTAL BLOCKS: %8d\n\n\n\n", nAllocCount);
    CloseHandle(hFile);
}

#include "gen/data/Source/D2Client/Unknown_0045B5F0.inc"
