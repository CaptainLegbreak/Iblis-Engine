#include "D2Structs.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Win32Types.h"
#include "D2Drlg.h"
#include "D2WinSplitText.h"
#include "D2ClientUiRecords.h"


extern int gnPanelSlideMode; // 0x007A5210

struct D2UnitStrc;

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __cdecl AUTOMAP_UpdateAutomapLayout(); // 0x00457520

void __cdecl AUTOMAP_PaintAutomap(); // 0x00459700

void __cdecl AUTOMAP_DrawGameInfoLines(); // 0x00459E90

void __cdecl AUTOMAP_DrawStringLine(); // 0x00459FF0

void __cdecl AUTOMAP_DrawLevelName(); // 0x0045A050

void __cdecl AUTOMAP_DrawVersionLine(); // 0x0045A0A0

void __cdecl AUTOMAP_DrawLocalIpLine(); // 0x0045A120

void __cdecl AUTOMAP_DrawDifficultyLine(); // 0x0045A190

void __cdecl AUTOMAP_DrawAutomapUnits(); // 0x0045AC90

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

extern void* gpGlobal_007A0634; // 0x007A0634

extern int gnAutomapTextY; // 0x007A51BC

struct D2ActiveRoomStrc;

// 0x0045AD60
void __cdecl PLAYER_DrawAutomap()
{
    if (!gpGlobal_007A0634)
    {
        return;
    }
    if (!sub_00463DE0_GetPlayerUnit())
    {
        return;
    }
    if (!UNITS_GetRoom(sub_00463DE0_GetPlayerUnit()))
    {
        return;
    }
    AUTOMAP_UpdateAutomapLayout();
    AUTOMAP_PaintAutomap();
    AUTOMAP_DrawAutomapUnits();
    gnAutomapTextY = 0x18;
    const int nAct = GAME_GetConnectionType();
    const int nPrevious = D2Win_10127_SetFont(1);
    AUTOMAP_DrawGameInfoLines();
    AUTOMAP_DrawLevelName();
    AUTOMAP_DrawVersionLine();
    AUTOMAP_DrawDifficultyLine();
    if (nAct == 6 || nAct == 8)
    {
        AUTOMAP_DrawLocalIpLine();
    }
    if (GAME_IsExpansion())
    {
        AUTOMAP_DrawStringLine();
    }
    D2Win_10127_SetFont(nPrevious);
}

struct Unicode;

struct D2TileRectStrc;

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

// 0x0045ADF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

// 0x0045AE20
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0045AE50
void __fastcall sub_0045AE50_SetGlobal00711428(int nValue)
{
    gdwGlobal_00711428 = nValue;
}

// 0x0045AE60
int __cdecl sub_0045AE60()
{
    return gdwGlobal_00711428;
}

// 0x0045AE70
void __fastcall sub_0045AE70_SetGlobal0071142C(int nValue)
{
    gdwGlobal_0071142C = nValue;
}

// 0x0045AE80
int __cdecl sub_0045AE80()
{
    return gdwGlobal_0071142C;
}

// 0x0045AE90
int __cdecl sub_0045AE90()
{
    return gnPanelSlideMode;
}


void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

void __fastcall D2GFX_SetViewMatrixAdjust(int nOffset); // 0x004F52A0

extern D2ViewStrc* gpClientView; // 0x007A0640

extern int gnScreenWidth; // 0x0071146C

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

int gnPanelSlideOffsetX; // 0x007A5214

// 0x0045AEA0
void __fastcall PLAYER_SetPanelSlide(int nMode)
{
    switch (nMode)
    {
    case 0:
    case 3:
        gnPanelSlideOffsetX = 0;
        break;
    case 1:
        gnPanelSlideOffsetX = -(gnScreenWidth / 4);
        break;
    case 2:
        gnPanelSlideOffsetX = gnScreenWidth / 4;
        break;
    }
    gnPanelSlideMode = nMode;
    D2GFX_SetViewMatrixAdjust(gnPanelSlideOffsetX);
    const int nWidth = gnAutomapWidth;
    const int nQuarter = nWidth / 4;
    switch (nMode)
    {
    case 0:
        sub_00476000_SetViewRect(gpClientView, 0, 0, nWidth, gnAutomapHeight_007A521C);
        break;
    case 1:
        sub_00476000_SetViewRect(gpClientView, -nQuarter, 0, nWidth - nQuarter, gnAutomapHeight_007A521C);
        break;
    case 2:
        sub_00476000_SetViewRect(gpClientView, nQuarter, 0, nWidth + nQuarter, gnAutomapHeight_007A521C);
        break;
    case 3:
        sub_00476000_SetViewRect(gpClientView, 0, 0, nWidth, gnAutomapHeight_007A521C);
        GAME_ResetMouseButtons();
        break;
    }
}

int gnAutomapOriginX; // 0x007A520C

// 0x0045AFA0
int __cdecl UI_GetAutomapOffsetX()
{
    return gnAutomapOriginX;
}

int gnAutomapOriginY; // 0x007A5208

// 0x0045AFB0
int __cdecl UI_GetAutomapOffsetY()
{
    return gnAutomapOriginY;
}

// 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetX()
{
    return gnAutomapOriginX - gnPanelSlideOffsetX;
}

// 0x0045AFD0
extern "C" int __cdecl PLAYER_GetScreenOffsetY()
{
    return gnAutomapOriginY - 8;
}

// 0x0045AFE0
void __fastcall AUTOMAP_SetAutomapOffsets(int nX, int nY)
{
    gnAutomapOriginX = nX;
    gnAutomapOriginY = nY;
}

// 0x0045AFF0
void __fastcall AUTOMAP_ScreenToMap(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    if (sub_004F51D0_IsPerspective())
    {
        nY += nY / -40;
        int nHalfWidth = gnScreenWidth / 2;
        nX += (40 - nY / 4) * (nX - nHalfWidth) / nHalfWidth;
    }
    nY += gnAutomapOriginY;
    nX += gnAutomapOriginX - gnPanelSlideOffsetX;
    DUNGEON_ClientToGameSubtileCoords(&nX, &nY);
    *pX = nX;
    *pY = nY;
}

// 0x0045B090
void __cdecl sub_0045B090_Nop()
{
}

// 0x0045B0A0
void __cdecl sub_0045B0A0_Nop()
{
}

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __fastcall VIEW_GetViewShift(int* pX, int* pY); // 0x00476AC0

int gnAutomapPanelShiftX; // 0x007A5204

struct D2ClientUnitPointStrc;

void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380

struct D2ClientUnitPointStrc
{
    int nX;
    int nY;
    char unk0x08[0x18];
    D2ClientUnitPointStrc* pNext;
};

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

struct D2ViewStrc
{
    unsigned int dwFlags;
    tagRECT tRect;
    unsigned char unk_14[0x10];
    int nPosX;
    int nPosY;
    void* pLerpData;
    void* pLerpTable;
    void* pLerpRows;
    unsigned int dwDrawFlags;
};

// 0x0045B0B0
void __fastcall VIEW_DrawRoomUnitBoxes(D2ActiveRoomStrc* pRoom)
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            const int nX = UNITS_GetClientCoordX(pUnit) - gnAutomapOriginX;
            const int nY = UNITS_GetClientCoordY(pUnit) - gnAutomapOriginY;
            D2GFX_DrawBox(nX, nY, nX + 4, nY + 4, 0xFF, 5);
            if (pUnit && pUnit->dwUnitType == UNIT_TILE)
            {
                for (D2ClientUnitPointStrc* pPoint = (D2ClientUnitPointStrc*)pUnit->pGfxData; pPoint; pPoint = pPoint->pNext)
                {
                    D2GFX_DrawLine(UNITS_GetClientCoordX(pUnit) - gnAutomapOriginX, UNITS_GetClientCoordY(pUnit) - gnAutomapOriginY, pPoint->nX - gnAutomapOriginX, pPoint->nY - gnAutomapOriginY, 0xFF, 0xFF);
                }
            }
        }
    }
}

// 0x0045B1A0
void __fastcall CUNIT_DrawAutomapDiamond(int nX, int nY, unsigned char nColor)
{
    tagRECT tRect;
    tRect.left = nX - gnAutomapOriginX - 0x10;
    tRect.right = nX - gnAutomapOriginX + 0x10;
    tRect.top = nY - gnAutomapOriginY;
    tRect.bottom = nY - gnAutomapOriginY + 0x10;
    D2GFX_UtilDiamond(&tRect, nColor);
}

struct D2DrlgCoordsStrc;

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260



D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

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

// 0x0045B1E0
void __stdcall AUTOMAP_DrawUnitTileRect(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2TileRectStrc* pTileRect = sub_00619620(pRoom, pUnit);
    if (!pTileRect)
    {
        return;
    }
    int nX = UNITS_GetXPositionInline(pUnit);
    int nY = UNITS_GetYPositionInline(pUnit);
    DUNGEON_GameSubtileToClientCoords(&nX, &nY);
    int nLeft = pTileRect->nX - gnAutomapOriginX + nX;
    int nTop = pTileRect->nY - gnAutomapOriginY + nY;
    int nRight = pTileRect->nWidth + nLeft;
    int nBottom = pTileRect->nHeight + nTop;
    D2GFX_DrawLine(nLeft, nTop, nLeft, nBottom, 0xFF, 0xFF);
    D2GFX_DrawLine(nLeft, nTop, nRight, nTop, 0xFF, 0xFF);
    D2GFX_DrawLine(nLeft, nBottom, nRight, nBottom, 0xFF, 0xFF);
    D2GFX_DrawLine(nRight, nTop, nRight, nBottom, 0xFF, 0xFF);
    nX += 1;
    tagRECT tRect;
    tRect.left = nX - gnAutomapOriginX - 0x10;
    tRect.right = nX - gnAutomapOriginX + 0x10;
    tRect.top = nY - gnAutomapOriginY;
    tRect.bottom = nY - gnAutomapOriginY + 0x10;
    D2GFX_UtilDiamond(&tRect, 0xFF);
    nX = UNITS_GetXPositionInline(pUnit);
    nY = UNITS_GetYPositionInline(pUnit);
    nX += pTileRect->nOffsetX;
    nY += pTileRect->nOffsetY;
    DUNGEON_GameSubtileToClientCoords(&nX, &nY);
    nX += 1;
    tRect.left = nX - gnAutomapOriginX - 0x10;
    tRect.right = nX - gnAutomapOriginX + 0x10;
    tRect.top = nY - gnAutomapOriginY;
    tRect.bottom = nY - gnAutomapOriginY + 0x10;
    D2GFX_UtilDiamond(&tRect, 0x2D);
}

// 0x0045B3E0
void __cdecl AUTOMAP_DrawRoomTileRects()
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
            {
                if (pUnit->dwUnitType == UNIT_TILE)
                {
                    AUTOMAP_DrawUnitTileRect(pUnit);
                }
            }
        }
    }
}

// 0x0045B440
void __cdecl AUTOMAP_UpdateAutomapOrigin()
{
    int nShiftX;
    int nShiftY;
    gnAutomapPanelShiftX = -0xA0;
    if (gnPanelSlideMode == 2)
    {
        gnAutomapPanelShiftX = gnScreenWidth / 2 - 0xA0;
    }
    else if (gnPanelSlideMode == 3)
    {
        gnAutomapPanelShiftX = 0;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nX = UNITS_GetClientCoordX(pPlayer);
    int nY = UNITS_GetClientCoordY(pPlayer);
    gnAutomapOriginX = nX - gnScreenWidth / 2;
    gnAutomapOriginY = nY - gnScreenHeight / 2 + 0x10;
    if (VIEW_GetViewShift(&nShiftX, &nShiftY))
    {
        gnAutomapOriginX += nShiftX;
        gnAutomapOriginY += nShiftY;
    }
}

// 0x0045B4F0
void __stdcall AUTOMAP_DrawRoomCollision(D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    for (int nY = tCoords.nSubtileY + 2; nY < tCoords.nSubtileY + tCoords.nSubtileHeight + 5; nY += 5)
    {
        for (int nX = tCoords.nSubtileX + 3; nX < tCoords.nSubtileX + tCoords.nSubtileWidth + 5; nX += 5)
        {
            int nCollision = sub_0061B130_GetCollision(pRoom, nX, nY);
            int nScreenX = nX;
            int nScreenY = nY;
            DUNGEON_GameSubtileToClientCoords(&nScreenX, &nScreenY);
            tagRECT tRect;
            tRect.left = nScreenX - gnAutomapOriginX - 0x10;
            tRect.right = nScreenX - gnAutomapOriginX + 0x10;
            tRect.top = nScreenY - gnAutomapOriginY;
            tRect.bottom = nScreenY - gnAutomapOriginY + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x46);
            nScreenX = nScreenX - 7 - gnAutomapOriginX;
            nScreenY = nScreenY - gnAutomapOriginY;
            D2GFX_OutputString(nScreenX, nScreenY, gszFormatInt_006D57BC, nCollision);
        }
    }
}

#include "gen/data/Source/D2Client/Unknown_0045AE90.inc"
