#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Drlg.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
#include "D2GfxApi.h"
#include "D2WinApi2.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2UiBlockRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
    char unk0x10[0x110];
};

extern int gnItemLabelCount;                                                                       // 0x007C54A0


struct D2ItemLabelStrc { int nLeft,nTop,nRight,nBottom; D2UnitStrc* pItem; Unicode wszText[128]; int nFillColor,nDrawMode,nTextColor; };

extern int gnItemLabelCount; // 0x007C54A0

D2ItemLabelStrc gaItemLabels[32]; // 0x007C54A8

extern "C" const char gszShowItems[]; // 0x006DAB64



D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,unsigned int*); // 0x00619790




extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

void __fastcall UI_BuildItemHoverName(D2UnitStrc*,Unicode*,int); // 0x004527D0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0


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



// 0x004C0640
int __fastcall SHOWITEMS_ClampRectToScreen(int* pLeft, int* pTop, int* pRight, int* pBottom, int nMode, int nMaxX, int nMinX)
{
    int nMaxY = gnScreenHeight - 48;

    sub_004C0640_ClampToScreen(pLeft, pTop, pRight, pBottom, nMaxX, nMinX, nMaxY);

    if (gnItemLabelCount >= 32)
    {
        FOG_DisplayHalt("", sub_00408090(), 0x47);
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
        FOG_DisplayHalt("", sub_00408090(), 0x47);
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
    D2UnitStrc* pPlayer=CUNIT_GetPlayerUnit();
    if(!pPlayer)return;
    D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
    if(!pRoom)return;
    D2UnitStrc* pSelectedUnit=SELECT_GetSelectedUnit();
    int nMouseX=sub_00468730_GetMouseX();
    int nMouseY=sub_00468740_GetMouseY();
    D2ActiveRoomStrc** ppRooms;
    unsigned int nRoomCount;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRooms,&nRoomCount);
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
                switch(sub_0045AE90_GetPanelSlideMode())
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
            switch(sub_0045AE90_GetPanelSlideMode())
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


#pragma pack(push, 1)
struct d2data_007279B0_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_007279B0_t gData_007279B0; // 0x007279B0

extern "C" struct d2data_007279B0_t gData_007279B0 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x007279B0

extern "C" const char gszShowItems[20] = ".\\UI\\showitems.cpp"; // 0x006DAB64
