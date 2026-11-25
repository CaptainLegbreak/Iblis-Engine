#include "D2Client.h"
#include "D2Drlg.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2UiBlockRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
    char unk0x10[0x110];
};

extern int gnBlockRectCount_007C54A0;                                                                       // 0x007C54A0

extern D2UiBlockRectStrc gaBlockRects_007C54A8[32];                                                         // 0x007C54A8

struct D2ItemLabelStrc { int nLeft,nTop,nRight,nBottom; D2UnitStrc* pItem; Unicode wszText[128]; int nFillColor,nDrawMode,nTextColor; };

extern int gnItemLabelCount; // 0x007C54A0

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ??__EgaItemLabels@@YAXXZ 0x006CADB0
D2ItemLabelStrc gaItemLabels[32]; // 0x007C54A8

extern "C" const char gszShowItems[]; // 0x006DAB64

int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0

D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,unsigned int*); // 0x00619790

int __stdcall UNITS_GetPrecisionX(D2UnitStrc*); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc*); // 0x00620410

int __stdcall SCALE_CheckPerspectivePosition(int,int); // 0x004F66E0

void __stdcall SCALE_AdjustPerspectivePosition(int,int,int,int*,int*); // 0x004F6760

int __cdecl sub_0045AE90(); // 0x0045AE90

int __stdcall UNITS_GetClientCoordX(D2UnitStrc*); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc*); // 0x006206B0

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

void __fastcall UI_BuildItemHoverName(D2UnitStrc*,Unicode*,int); // 0x004527D0

void __fastcall D2Win_10131_GetTextDimensions(const Unicode*,int*,int*); // 0x00502520

void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc*); // 0x00467A70

void __fastcall D2Win_10129_DrawFramedText(const Unicode*,int,int,int,int); // 0x00502280

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc*); // 0x00629900

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0

void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0





static inline void sub_004C0640_ClampToScreen(int* pLeft, int* pTop, int* pRight, int* pBottom, int nMaxX, int nMinX, int nMaxY)
{
    if (*pLeft < nMinX)
    {
        *pRight += nMinX - *pLeft;
        *pLeft = 6;
    }

    if (*pTop < 6)
    {
        *pBottom += 6 - *pTop;
        *pTop = 6;
    }

    if (*pRight >= nMaxX)
    {
        int nDelta = *pRight - nMaxX + 1;
        *pRight -= nDelta;
        *pLeft -= nDelta;
    }

    if (*pBottom >= nMaxY)
    {
        int nDelta = *pBottom - nMaxY;
        *pBottom -= nDelta;
        *pTop -= nDelta;
    }
}

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __cdecl GAME_RequestExit(); // 0x0044D520

// 0x004C0640
int __fastcall SHOWITEMS_ClampRectToScreen(int* pLeft, int* pTop, int* pRight, int* pBottom, int nMode, int nMaxX, int nMinX)
{
    int nMaxY = gnScreenHeight - 48;

    sub_004C0640_ClampToScreen(pLeft, pTop, pRight, pBottom, nMaxX, nMinX, nMaxY);

    if (gnBlockRectCount_007C54A0 >= 32)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x47);
        exit(-1);
    }

    for (int i = 0; i < gnBlockRectCount_007C54A0; ++i)
    {
        const int bX = (*pLeft <= gaBlockRects_007C54A8[i].nRight && *pRight >= gaBlockRects_007C54A8[i].nLeft) ? 1 : 0;
        const int bY = (*pTop <= gaBlockRects_007C54A8[i].nBottom && *pBottom >= gaBlockRects_007C54A8[i].nTop) ? 1 : 0;
        if (bX && bY)
        {
            int nDelta;
            if (nMode > 6)
            {
                if ((*pRight - *pLeft) / 2 && *pLeft >= nMaxX)
                    nDelta = gaBlockRects_007C54A8[i].nLeft - *pRight - 1;
                else
                    nDelta = gaBlockRects_007C54A8[i].nRight - *pLeft + 1;
                *pLeft += nDelta;
                *pRight += nDelta;
                return 0;
            }

            if ((*pBottom - *pTop) / 2 && *pTop <= nMaxY)
                nDelta = gaBlockRects_007C54A8[i].nTop - *pBottom - 3;
            else
                nDelta = gaBlockRects_007C54A8[i].nBottom - *pTop + 5;
            *pTop += nDelta;
            *pBottom += nDelta;
            return 0;
        }
    }

    return 1;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    if(pUnit)return pUnit->dwUnitType;
    return 6;
}

static inline unsigned int UnitIsSelectable(D2UnitStrc* pUnit)
{
    if(!pUnit)return 0;
    return (pUnit->dwFlagEx>>7)&1;
}

int __fastcall sub_004C0640_AdjustLabel(int* pLeft, int* pTop, int* pRight, int* pBottom, int nMode, int nMaxX, int nMinX)
{
    int nMaxY = gnScreenHeight - 48;

    sub_004C0640_ClampToScreen(pLeft, pTop, pRight, pBottom, nMaxX, nMinX, nMaxY);

    if (gnItemLabelCount >= 32)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x47);
        exit(-1);
    }

    for (int i = 0; i < gnItemLabelCount; ++i)
    {
        const int bX = (*pLeft <= gaItemLabels[i].nRight && *pRight >= gaItemLabels[i].nLeft) ? 1 : 0;
        const int bY = (*pTop <= gaItemLabels[i].nBottom && *pBottom >= gaItemLabels[i].nTop) ? 1 : 0;
        if (bX && bY)
        {
            int nDelta;
            if (nMode > 6)
            {
                if ((*pRight - *pLeft) / 2 && *pLeft >= nMaxX)
                    nDelta = gaItemLabels[i].nLeft - *pRight - 1;
                else
                    nDelta = gaItemLabels[i].nRight - *pLeft + 1;
                *pLeft += nDelta;
                *pRight += nDelta;
                return 0;
            }

            if ((*pBottom - *pTop) / 2 && *pTop <= nMaxY)
                nDelta = gaItemLabels[i].nTop - *pBottom - 3;
            else
                nDelta = gaItemLabels[i].nBottom - *pTop + 5;
            *pTop += nDelta;
            *pBottom += nDelta;
            return 0;
        }
    }

    return 1;
}

// 0x004C0810
void __cdecl SHOWITEMS_DrawUnitNames()
{
    int bPerspective=D2GFX_CheckPerspective();
    D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
    if(!pPlayer)return;
    D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
    if(!pRoom)return;
    D2UnitStrc* pSelectedUnit=SELECT_GetSelectedUnit();
    int nMouseX=sub_00468730_GetMouseX();
    int nMouseY=sub_00468740_GetMouseY();
    D2ActiveRoomStrc** ppRooms;
    unsigned int nRoomCount;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRooms,&nRoomCount);
// build: symbol ?PALETTE_FindPaletteIndex@* 0x004FB180
    unsigned char nHighlight=PALETTE_FindPaletteIndex(0,64,128);
    gnItemLabelCount=0;
    int bSelected=0;
    for(unsigned int nRoom=0;nRoom<nRoomCount;++nRoom)
    {
        for(D2UnitStrc* pItem=ppRooms[nRoom]->pUnitFirst;pItem;pItem=pItem->ptRoomNext)
        {
            if(!UnitIsSelectable(pItem) || GetUnitType(pItem)!=4 || gnItemLabelCount>=32)continue;
            D2ItemLabelStrc* pLabel=&gaItemLabels[gnItemLabelCount];
            pLabel->pItem=pItem;
            int nX,nY,nBottom;
            if(bPerspective)
            {
                int nPrecisionX=UNITS_GetPrecisionX(pItem);
                int nPrecisionY=UNITS_GetPrecisionY(pItem);
                if(!SCALE_CheckPerspectivePosition(nPrecisionX,nPrecisionY))continue;
                int nProjectedX,nProjectedY;
                SCALE_AdjustPerspectivePosition(nPrecisionX,nPrecisionY,0,&nProjectedX,&nProjectedY);
                switch(sub_0045AE90())
                {
                case 1:nProjectedX+=-(gnScreenWidth_0071146C/4);break;
                case 2:nProjectedX+=gnScreenWidth_0071146C/4;break;
                }
                nX=nProjectedX;
                nY=nProjectedY;
                nBottom=nY;
            }
            else
            {
                nX=UNITS_GetClientCoordX(pItem)-PLAYER_GetScreenOffsetX();
                nY=UNITS_GetClientCoordY(pItem)+(-16-PLAYER_GetScreenOffsetY());
                nBottom=nY;
            }
            int nMinX=0;
            int nMaxX=gnScreenWidth_0071146C;
            switch(sub_0045AE90())
            {
            case 1:nMaxX=gnScreenWidth_0071146C/2-32;break;
            case 2:nMinX=gnScreenWidth_0071146C/2;break;
            }
            if(nX<nMinX || nX>nMaxX || nY<-8 || nY>gnScreenHeight-16)continue;
            pLabel->wszText[0].wChar=0;
            UI_BuildItemHoverName(pItem,pLabel->wszText,256);
            int nWidth,nTop;
            D2Win_10131_GetTextDimensions(pLabel->wszText,&nWidth,&nTop);
            nWidth+=8;
            nTop=nY-nTop+4;
            nX-=nWidth>>1;

            int nSum = nTop ? nWidth+nX : nWidth+nX;
            int nRight=nSum;
            int nTry=0;
            int bPlaced=1;
            for(;nTry<12;++nTry)
            {
                if(sub_004C0640_AdjustLabel(&nX,&nTop,&nRight,&nBottom,nTry,nMaxX,nMinX))
                    goto Placed;
            }
            bPlaced=0;
Placed:
            if(nRight>nMaxX || nX<nMinX || !bPlaced)continue;
            pLabel->nLeft=nX;pLabel->nTop=nTop;pLabel->nRight=nRight;pLabel->nBottom=nBottom;
            if(!bSelected && nMouseX>=nX && nMouseX<=nRight && nMouseY>=nTop && nMouseY<=nBottom+4)
            {
                pLabel->nFillColor=nHighlight;pLabel->nDrawMode=5;pLabel->nTextColor=0;
                SELECT_RefreshHoverUnit(pItem);
                bSelected=1;
            }
            else if(!bSelected && pItem==pSelectedUnit)
            {
                pLabel->nFillColor=nHighlight;pLabel->nDrawMode=5;pLabel->nTextColor=0;
                D2Win_10129_DrawFramedText(0,0,0,0,0);
                SELECT_ClearSelection();
                bSelected=1;
            }
            else
            {
                int nColor=0;
                pLabel->nFillColor=0;pLabel->nDrawMode=1;
                switch(ITEMS_GetItemQuality(pItem))
                {
                case ITEMQUAL_MAGIC:nColor=3;break;
                case ITEMQUAL_RARE:nColor=9;break;
                case ITEMQUAL_CRAFT:nColor=8;break;
                case ITEMQUAL_TEMPERED:nColor=10;break;
                case ITEMQUAL_UNIQUE:nColor=4;break;
                case ITEMQUAL_SET:nColor=2;break;
                default:
                    if((ITEMS_CheckItemFlag(pItem,0x800,0x106,gszShowItems) && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem)>0) || ITEMS_CheckItemFlag(pItem,0x400000,0x10C,gszShowItems))nColor=5;
                    break;
                }
                int nClassId=pItem->dwClassId;
                D2ItemsTxt* pRecord=DATATBLS_GetItemsTxtRecord(nClassId);
                if(pRecord->nQuest && pRecord->dwCode!=0x2067656C)nColor=4;
                pLabel->nTextColor=nColor;
            }
            ++gnItemLabelCount;
        }
    }
    for(int i=0;i<gnItemLabelCount;++i)
    {
        D2ItemLabelStrc* pLabel=&gaItemLabels[i];
        D2Win_10132(pLabel->wszText,pLabel->nLeft,pLabel->nBottom,pLabel->nFillColor,pLabel->nDrawMode,pLabel->nTextColor);
    }
    if(!bSelected)
    {
        SELECT_ClearSelection();
        D2Win_10129_DrawFramedText(0,0,0,0,0);
    }
}

struct D2ClientValues40Strc
{
    char unk0x00[0x14];
    int nValues[0x40];
};

// 0x004C0CE0
D2ClientValues40Strc* __fastcall SHOWITEMS_ClearValues(D2ClientValues40Strc* pValues)
{
    for (int i = 0; i < 0x40; ++i)
    {
        pValues->nValues[i] = 0;
    }
    return pValues;
}

// 0x004C0D00
void __cdecl USEITEM_LeaveGame()
{
    sub_00477EE0();
    WINMAIN_SetExitApplication(0);
    GAME_SetCinematicExit(1);
    GAME_RequestExit();
}


#include "gen/data/Source/D2Client/UI/showitems.inc"
