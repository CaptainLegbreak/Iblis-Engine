#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2DrlgMaps.h"
#include "D2Win32Types.h"
#include "FogApi.h"

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

void __stdcall D2Common_10052(D2ActiveRoomStrc* pRoom, Rectangle* pRect); // 0x00619C40

D2UnitStrc* __stdcall DUNGEON_GetFirstUnitInRoom(D2ActiveRoomStrc* pRoom); // 0x00619EA0


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2WallCellStrc;

struct D2WallCtxStrc;

struct D2StaticPathStrc;

struct Obj004DCF10;

struct D2WallRoomArgStrc
{
    D2WallCtxStrc* pCtx;
    tagRECT tRect;
    D2ActiveRoomStrc* pRoom;
    int nValue;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0





int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath); // 0x006488C0

unsigned int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

struct Obj004DCF10 {
    unsigned char bUnknown00[0x38];
    unsigned int dwValue38;
    unsigned char bUnknown3C[0xEA9C - 0x3C];
    unsigned int dwValueEA9C;
    unsigned int dwUnknownEAA0;
    unsigned int dwUnknownEAA4;
    unsigned int dwValueEAA8;
    unsigned int dwUnknownEAAC;
    unsigned int dwValueEAB0;
};

static tagRECT s_tWallRect; // 0x007C8A14

static int s_nPlayerX; // 0x007C8A08

static int s_nCollision; // 0x007C8A0C

static int s_nPlayerY; // 0x007C8A10

struct D2ViewStrc
{
    char unk0x00[0x38];
    int nField0x38;
    char unk0x3C[0xEA60];
    int nField0xEA9C;
    char unk0xEAA0[8];
    void* pCells;
    char unk0xEAAC[4];
    int nField0xEAB0;
};

struct Tile;

struct Path;

struct Cell;

struct Context;

struct View;

struct TileRecord;

struct Frame;

#define FIELD(T,p,off) (*(T*)((unsigned char*)(p)+(off)))

struct Node
{
    int type;
    int x;
    int y;
    void* object;
    Node* next;
};


extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260

extern int gVar_0072A968_Mode; // 0x0072A968

extern unsigned int gdwBitMasks[]; // 0x006CE268



extern int __fastcall CUNIT_IsUnitDead(D2UnitStrc*); // 0x00464860

extern int __stdcall TileGetTotalHeight(TileRecord*); // 0x00604CB0

extern Tile* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc*,unsigned int*); // 0x006196A0

extern Tile* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc*,unsigned int*); // 0x006196E0

extern int __stdcall UNITS_GetClientCoordX(D2UnitStrc*); // 0x00620650

extern int __stdcall UNITS_GetClientCoordY(D2UnitStrc*); // 0x006206B0

extern void __stdcall DUNGEON_ClientTileDrawPositionToGameCoords(int,int,int*,int*); // 0x00643340

extern int __stdcall PATH_GetXPosition(Path*); // 0x006488C0

extern int __stdcall PATH_GetYPosition(Path*); // 0x00648900

struct Cell36
{
    unsigned int data[9];
};

struct WallContext
{
    int unk0x00;
    Node nodes[3000];
    unsigned int count;
};

static void __stdcall WALL2_AddWall(Context* context,Cell* cell,D2ActiveRoomStrc* room,Tile* tile); // 0x004DD180

// 0x004DCE60
static void WALL2_ResizeWallCells(D2WallCtxStrc* pCtx)
{
    const int nWidth = (pCtx->nRight - pCtx->nLeft) / 160 + 11;
    const int nHeight = (pCtx->nBottom - pCtx->nTop) / 80 + 12;
    const int nSize = nHeight + nWidth - 1;
    const int nCount = nSize * nSize;
    if (!pCtx->pCells || nCount != pCtx->nCellCount)
    {
        if (pCtx->pCells)
            FOG_Free(pCtx->pCells, ".\\GAME\\Wall2.cpp", 0x3A, 0);
        pCtx->pCells = (D2WallCellStrc*)FOG_Alloc(nCount * sizeof(D2WallCellStrc), ".\\GAME\\Wall2.cpp", 0x3D, 0);
        pCtx->nCellCount = nCount;
    }
    pCtx->nSize = nSize;
    pCtx->nWidth = nWidth;
    pCtx->nHeight = nHeight;
}

static unsigned int GetUnitXPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static unsigned int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nYPos;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

struct D2WallPointStrc;

struct D2ClearPairStrc;

struct D2GridRectStrc;

struct D2WallPointStrc
{
    int nX;
    int nY;
};

struct D2ClearPairStrc
{
    char pad0x00[0x14];
    int nFirst;
    int nSecond;

    D2ClearPairStrc();
};

struct D2GridCellStrc
{
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    int nX;
    int nY;
};

extern void* gpGlobal_007A0634; // 0x007A0634

unsigned char __stdcall ENVIRONMENT_GetIntensityFromAct(void* pAct); // 0x0061C0E0

void __stdcall ENVIRONMENT_GetLightColorFromAct(void* pAct, unsigned char* pR, unsigned char* pG, unsigned char* pB); // 0x0061C0B0

void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pB0, unsigned char* pB1, unsigned char* pB2, unsigned char* pB3); // 0x00475AA0

// 0x004DDB70
void __fastcall WALL2_PrepareWallCells(D2WallCtxStrc* pCtx, int nValue)
{
    WALL2_ResizeWallCells(pCtx);
    D2WallRoomArgStrc tArg;
    tArg.pCtx = pCtx;
    tArg.nValue = nValue;
    if (sub_004F51D0_IsPerspective())
        SetRect(&tArg.tRect, pCtx->nX - 0x30, pCtx->nY - 0x30, pCtx->nRight - pCtx->nLeft + pCtx->nX + 0x30, pCtx->nBottom - pCtx->nTop + pCtx->nY);
    else
        SetRect(&tArg.tRect, pCtx->nX, pCtx->nY, pCtx->nRight - pCtx->nLeft + pCtx->nX, pCtx->nBottom - pCtx->nTop + pCtx->nY);
    s_tWallRect = tArg.tRect;
    pCtx->nUnk0xEA9C = 0;
    pCtx->nUnk0x38 = 0;
    D2_ASSERT(pCtx->pCells, 0x33C);
    memset(pCtx->pCells, 0, pCtx->nCellCount * sizeof(D2WallCellStrc));
    D2WallPointStrc tOrigin;
    DUNGEON_ClientTileDrawPositionToGameCoords(pCtx->nX, pCtx->nY, &tOrigin.nX, &tOrigin.nY);
    tOrigin.nX -= 3;
    tOrigin.nY -= pCtx->nWidth;
    pCtx->nOriginX = tOrigin.nX;
    pCtx->nOriginY = tOrigin.nY;
    D2WallCellStrc* pCell = pCtx->pCells;
    for (unsigned int nRow = 0; nRow < pCtx->nSize; ++nRow)
    {
        for (unsigned int nColumn = 0; nColumn < pCtx->nSize; ++nColumn)
        {
            pCell->nX = tOrigin.nX + nColumn;
            pCell->nY = tOrigin.nY + nRow;
            ++pCell;
        }
    }
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x351);
    tArg.pRoom = CUNIT_GetPlayerRoom();
    s_nPlayerX = GetUnitXPosition_Inline(pPlayer) / 5;
    s_nPlayerY = GetUnitYPosition_Inline(pPlayer) / 5;
    s_nCollision = D2Common_10095(UNITS_GetRoom(pPlayer), GetUnitXPosition_Inline(pPlayer), GetUnitYPosition_Inline(pPlayer));
    DUNGEON_CallRoomCallback(tArg.pRoom, WALL2_VisitRoom, &tArg);
}

// 0x004DCF10
extern "C" __declspec(dllexport) void __fastcall WALL2_ResetViewCells(Obj004DCF10* pObj) {
    pObj->dwValueEAB0 = 0;
    pObj->dwValueEA9C = 0;
    pObj->dwValue38 = 0;
    pObj->dwValueEAA8 = 0;
}

// 0x004DCF30
void __fastcall WALL2_FreeViewCells(D2ViewStrc* pView)
{
    if (pView->pCells)
    {
        FOG_Free(pView->pCells, ".\\GAME\\Wall2.cpp", 0x55, 0);
    }

    pView->pCells = 0;
    pView->nField0xEAB0 = 0;
    pView->nField0xEA9C = 0;
    pView->nField0x38 = 0;
}

// 0x004DCF70
static int __cdecl WALL2_Inside(Context* context,int y,int x)
{
    x-=FIELD(int,context,0xEA68);
    y-=FIELD(int,context,0xEA6C);
    if(x<0) return 0;
    if(y<0) return 0;
    int size=FIELD(int,context,0xEA78);
    if(x>=size) return 0;
    return y<size;
}

static inline int sub_004DCF70_Inside_inl(Context* context,int y,int x)
{
    x-=FIELD(int,context,0xEA68);
    y-=FIELD(int,context,0xEA6C);
    if(x<0) return 0;
    if(y<0) return 0;
    int size=FIELD(int,context,0xEA78);
    if(x>=size) return 0;
    if(y>=size) return 0;
    return 1;
}

static inline unsigned int UNIT_GetFlagC4_20(D2UnitStrc* unit)
{
    if(!unit) return 0;
    return (FIELD(unsigned int,unit,196)>>20)&1;
}

static inline unsigned int UNIT_GetFlagC8_7(D2UnitStrc* unit)
{
    if(!unit) return 0;
    return (FIELD(unsigned int,unit,200)>>7)&1;
}

// 0x004DCFA0
static void __cdecl WALL2_AddUnit(Cell* cell,Context* context,D2UnitStrc* unit)
{
    unsigned int index=FIELD(unsigned int,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=0;
    node->object=unit;
    node->next=0;
    int x;
    int type=FIELD(int,unit,0);
    if(type==2 || (type>3 && type<=5)) x=FIELD(int,FIELD(Path*,unit,44),12);
    else { Path* path=FIELD(Path*,unit,44); x=path ? PATH_GetXPosition(path) : 0; }
    node->x=8*x;
    int y;
    type=FIELD(int,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(int,FIELD(Path*,unit,44),16);
    else { Path* path=FIELD(Path*,unit,44); y=path ? PATH_GetYPosition(path) : 0; }
    node->y=8*y;
    Node* last=FIELD(Node*,cell,24);
    if(!last) { FIELD(Node*,cell,24)=node; return; }
    while(last->next) last=last->next;
    last->next=node;
}

// 0x004DD060
static int __stdcall WALL2_Occludes(D2ActiveRoomStrc* room,Tile* tile)
{
    if(gVar_0072A968_Mode)
    {
        Frame* frame=FIELD(Frame*,tile,16);
        if(!frame) return 0;
        if(FIELD(int,frame,40)==s_nCollision) return 0;
        if(s_nPlayerX<FIELD(int,frame,0)) return 1;
        return s_nPlayerY<FIELD(int,frame,4);
    }
    D2DrlgCoordsStrc coordinates;
    DUNGEON_GetRoomCoordinates(room, &coordinates);
    int x=coordinates.nSubtileX+5*FIELD(int,tile,8);
    int y=coordinates.nSubtileY+5*FIELD(int,tile,12);
    int viewX=5*s_nPlayerX;
    int viewY=5*s_nPlayerY;
    if(viewX<x && viewX>x-20)
    {
        switch(FIELD(int,tile,28))
        {
        case 1: case 4: case 5: case 7: case 8: case 10: case 12: return 1;
        }
    }
    if(viewY<y && viewY>y-20)
    {
        switch(FIELD(int,tile,28))
        {
        case 2: case 3: case 6: case 7: case 9: case 11: case 12: return 1;
        }
    }
    return 0;
}

// @ref 0x004DD180
// 0x004DD180
static void __stdcall WALL2_AddWall(Context* context,Cell* cell,D2ActiveRoomStrc* room,Tile* tile)
{
    if(FIELD(int,tile,28)!=0 && FIELD(int,tile,28)!=13 && !(FIELD(unsigned int,tile,20)&4)) FIELD(unsigned int,cell,0)|=4;
    WallContext* wallContext=(WallContext*)context;
    unsigned int index=wallContext->count++;
    if(index>=3000) return;
    unsigned int expiry=GetTickCount()+500;
    Node* node=&wallContext->nodes[index];
    node->type=1;
    node->object=tile;
    node->next=0;
    if(!(FIELD(unsigned int,tile,20)&4))
    {
        int occludes=WALL2_Occludes(room,tile);
        unsigned int flags=FIELD(unsigned int,tile,36);
        if(occludes)
        {
            if(!(flags&1))
            {
                unsigned char alpha=FIELD(unsigned char,tile,40);
                FIELD(unsigned char,tile,41)=255;
                FIELD(unsigned char,tile,42)=128;
                if(alpha==255) FIELD(unsigned int,tile,44)=expiry;
                else FIELD(unsigned int,tile,44)=expiry+(int(alpha)-255)*500/127;
                FIELD(unsigned int,tile,36)=flags|3;
            }
        }
        else if(flags&1)
        {
            unsigned char alpha=FIELD(unsigned char,tile,40);
            FIELD(unsigned char,tile,41)=128;
            FIELD(unsigned char,tile,42)=255;
            if(alpha==128) FIELD(unsigned int,tile,44)=expiry;
            else FIELD(unsigned int,tile,44)=expiry+(128-int(alpha))*500/127;
            FIELD(unsigned int,tile,36)=(flags&~1)|2;
        }
    }
    {
        D2DrlgCoordsStrc coordinates;
        DUNGEON_GetRoomCoordinates(room, &coordinates);
        node->x=8*(coordinates.nSubtileX+5*FIELD(int,tile,8));
        node->y=8*(coordinates.nSubtileY+5*FIELD(int,tile,12));
    }
    Node* last=FIELD(Node*,cell,20);
    if(!last) { FIELD(Node*,cell,20)=node; return; }
    Node* previous=0;
    int order=(FIELD(unsigned int,node->object,20)>>14)&7;
    Node* next=last->next;
    if(next) do
    {
        if(order<int((FIELD(unsigned int,last->object,20)>>14)&7))
        {
            node->next=last;
            if(previous) previous->next=node;
            else FIELD(Node*,cell,20)=node;
            break;
        }
        previous=last;
        last=previous->next;
        next=last->next;
    } while(next);
    if(!last->next) last->next=node;
}

// @ref 0x004DD350
static __forceinline void sub_004DD460_InsertSorted(Node** list,Node* node)
{
    Node* last=*list;
    if(!last) { *list=node; return; }
    Node* previous=0;
    int order=(FIELD(unsigned int,node->object,20)>>14)&7;
    Node* next=last->next;
    if(next) do
    {
        if(order<int((FIELD(unsigned int,last->object,20)>>14)&7))
        {
            node->next=last;
            if(previous) previous->next=node;
            else *list=node;
            break;
        }
        previous=last;
        last=previous->next;
        next=last->next;
    } while(next);
    if(!last->next) last->next=node;
}

// 0x004DD350
static void __stdcall WALL2_AddUpper(Cell* cell,D2ActiveRoomStrc* room,Context* context,Tile* tile)
{
    if(FIELD(int,tile,28)!=0 && FIELD(int,tile,28)!=13 && !(FIELD(unsigned int,tile,20)&4)) FIELD(unsigned int,cell,0)|=4;
    unsigned int index=FIELD(unsigned int,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=1;
    node->object=tile;
    node->next=0;
    {
        D2DrlgCoordsStrc coordinates;
        DUNGEON_GetRoomCoordinates(room, &coordinates);
        node->x=8*(coordinates.nSubtileX+5*FIELD(int,tile,8));
        node->y=8*(coordinates.nSubtileY+5*FIELD(int,tile,12));
    }
    FIELD(unsigned int,context,0)|=gdwBitMasks[0];
    sub_004DD460_InsertSorted(&FIELD(Node*,cell,32),node);
}

// @ref 0x004DD460
// 0x004DD460
static void __stdcall WALL2_AddRoof(Cell* cell,D2ActiveRoomStrc* room,Context* context,Tile* tile)
{
    unsigned int index=FIELD(unsigned int,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=1;
    node->object=tile;
    node->next=0;
    {
        D2DrlgCoordsStrc coordinates;
        DUNGEON_GetRoomCoordinates(room, &coordinates);
        node->x=8*(coordinates.nSubtileX+5*FIELD(int,tile,8));
        node->y=8*(coordinates.nSubtileY+5*FIELD(int,tile,12));
    }
    FIELD(unsigned int,context,0)|=gdwBitMasks[1];
    sub_004DD460_InsertSorted(&FIELD(Node*,cell,28),node);
}

// @ref 0x004DD550
// 0x004DD550
static void __stdcall WALL2_AddFloor(Cell* cell, D2ActiveRoomStrc* room, Context* context, Tile* tile)
{
    unsigned int index = FIELD(unsigned int, context, 0xEA64)++;
    if (index >= 3000)
    {
        return;
    }
    Node* node = &FIELD(Node, context, 4) + index;
    node->type = 1;
    node->object = tile;
    node->next = 0;
    {
        D2DrlgCoordsStrc coordinates;
        DUNGEON_GetRoomCoordinates(room, &coordinates);
        node->x = 8 * (coordinates.nSubtileX + 5 * FIELD(int, tile, 8));
        node->y = 8 * (coordinates.nSubtileY + 5 * FIELD(int, tile, 12));
    }
    FIELD(unsigned int, context, 0) |= gdwBitMasks[3];
    Node* last = FIELD(Node*, cell, 16);
    if (!last)
    {
        FIELD(Node*, cell, 16) = node;
        return;
    }
    while (last->next)
    {
        last = last->next;
    }
    last->next = node;
}

// @ref 0x004DD600
// 0x004DD600
static void __stdcall WALL2_AddSpecial(Cell* cell,Context* context,D2UnitStrc* unit)
{
    unsigned int index=FIELD(unsigned int,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=0;
    node->object=unit;
    node->next=0;
    int x;
    int type=FIELD(int,unit,0);
    if(type==2 || (type>3 && type<=5)) x=FIELD(int,FIELD(D2DynamicPathStrc*,unit,44),12);
    else { D2DynamicPathStrc* path=FIELD(D2DynamicPathStrc*,unit,44); x=path ? PATH_GetXPosition(path) : 0; }
    node->x=8*x;
    int y;
    type=FIELD(int,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(int,FIELD(D2DynamicPathStrc*,unit,44),16);
    else { D2DynamicPathStrc* path=FIELD(D2DynamicPathStrc*,unit,44); y=path ? PATH_GetYPosition(path) : 0; }
    node->y=8*y;
    FIELD(unsigned int,context,0)|=gdwBitMasks[3];
    Node* last=FIELD(Node*,cell,16);
    if(!last) { FIELD(Node*,cell,16)=node; return; }
    while(last)
    {
        if(!last->next) break;
        last=last->next;
    }
    last->next=node;
}

// 0x004DD6E0
static void __stdcall WALL2_AddOverlay(Cell* cell,Context* context,D2UnitStrc* unit)
{
    unsigned int index=FIELD(unsigned int,context,0xEA64)++;
    if(index>=3000) return;
    Node* node=&FIELD(Node,context,4)+index;
    node->type=2;
    node->object=unit;
    node->next=0;
    int x;
    int type=FIELD(int,unit,0);
    if(type==2 || (type>3 && type<=5)) x=FIELD(int,FIELD(Path*,unit,44),12);
    else { Path* path=FIELD(Path*,unit,44); x=path ? PATH_GetXPosition(path) : 0; }
    node->x=8*x;
    int y;
    type=FIELD(int,unit,0);
    if(type==2 || (type>3 && type<=5)) y=FIELD(int,FIELD(Path*,unit,44),16);
    else { Path* path=FIELD(Path*,unit,44); y=path ? PATH_GetYPosition(path) : 0; }
    node->y=8*y;
    FIELD(unsigned int,context,0)|=gdwBitMasks[3];
    Node* last=FIELD(Node*,cell,16);
    if(!last) { FIELD(Node*,cell,16)=node; return; }
    while(last->next) last=last->next;
    last->next=node;
}

// 0x004DD7C0
int __stdcall WALL2_VisitRoom(D2ActiveRoomStrc* room,View* view)
{
    Context* context=(Context*)((unsigned char*)FIELD(void*,view,0)+56);
    Rectangle rectangle;
    D2Common_10052(room, &rectangle);
    if(rectangle.left>FIELD(int,view,12)) return 1;
    if(rectangle.top>FIELD(int,view,16)+400) return 1;
    if(rectangle.right<FIELD(int,view,4)-200) return 1;
    if(rectangle.bottom<FIELD(int,view,8)) return 1;
    unsigned int i;
    unsigned int count;
    Tile* tiles=DUNGEON_GetWallTilesFromRoom(room,&count);
    for(i=0;i<count;++i)
    {
        Tile* tile=(Tile*)((unsigned char*)tiles+48*i);
        TileRecord* record=FIELD(TileRecord*,tile,24);
        int height=TileGetTotalHeight(record);
        int y,x;
        DUNGEON_ClientTileDrawPositionToGameCoords(FIELD(int,tile,0),FIELD(int,tile,4),&x,&y);
        --y;
        if(FIELD(int,tile,0)>FIELD(int,view,12)) continue;
        if(FIELD(int,tile,0)+160<FIELD(int,view,4)) continue;
        int pixelY=FIELD(int,tile,4)-FIELD(unsigned short,record,4);
        if(pixelY+height>FIELD(int,view,16)) continue;
        if(pixelY-height<FIELD(int,view,8)) continue;
        if(!WALL2_Inside(context,y,x)) continue;
        x-=FIELD(int,context,0xEA68);
        y-=FIELD(int,context,0xEA6C);
        Cell* cell=(Cell*)((unsigned char*)FIELD(Cell*,context,0xEA70)+36*(x+FIELD(int,context,0xEA78)*y));
        FIELD(unsigned int,cell,0)=0;
        if(!(FIELD(unsigned int,tile,20)&0x1C000)) WALL2_AddFloor(cell,room,context,tile);
        else
        {
            switch(FIELD(int,tile,28))
            {
            case 15: WALL2_AddRoof(cell,room,context,tile); break; // 0x004DD460
            case 16: case 17: case 18: case 19: WALL2_AddUpper(cell,room,context,tile); break; // 0x004DD350
            default: WALL2_AddWall(context,cell,room,tile); break; // 0x004DD180
            }
        }
    }
    tiles=DUNGEON_GetRoofTilesFromRoom(room,&count);
    for(i=0;i<count;++i)
    {
        Tile* tile=(Tile*)((unsigned char*)tiles+48*i);
        int height=TileGetTotalHeight(FIELD(TileRecord*,tile,24));
        int y,x;
        DUNGEON_ClientTileDrawPositionToGameCoords(FIELD(int,tile,0),FIELD(int,tile,4),&x,&y);
        --y;
        if(FIELD(int,tile,0)>FIELD(int,view,12)) continue;
        if(FIELD(int,tile,0)+160<FIELD(int,view,4)) continue;
        if(FIELD(int,tile,4)+height>FIELD(int,view,16)) continue;
        if(FIELD(int,tile,4)-height<FIELD(int,view,8)) continue;
        if(!WALL2_Inside(context,y,x)) continue;
        x-=FIELD(int,context,0xEA68);
        y-=FIELD(int,context,0xEA6C);
        Cell* cell=(Cell*)((unsigned char*)FIELD(Cell*,context,0xEA70)+36*(x+FIELD(int,context,0xEA78)*y));
        WALL2_AddFloor(cell,room,context,tile);
    }
    if(FIELD(int,view,24)) return 1;
    for(D2UnitStrc* unit=DUNGEON_GetFirstUnitInRoom(room);unit;unit=FIELD(D2UnitStrc*,unit,232))
    {
        int x=UNITS_GetClientCoordX(unit);
        int y=UNITS_GetClientCoordY(unit);
        DUNGEON_ClientTileDrawPositionToGameCoords(x,y,&x,&y);
        if(!sub_004DCF70_Inside_inl(context,y,x)) continue;
        x-=FIELD(int,context,0xEA68);
        y-=FIELD(int,context,0xEA6C);
        D2_ASSERT(x>=0 && x<FIELD(int,context,0xEA78),768);
        D2_ASSERT(y>=0 && y<FIELD(int,context,0xEA78),769);
        Cell* cell=(Cell*)&FIELD(Cell36*,context,0xEA70)[x+FIELD(int,context,0xEA78)*y];
        if(CUNIT_IsUnitDead(unit)) WALL2_AddSpecial(cell,context,unit);
        else if(UNIT_GetFlagC4_20(unit)) WALL2_AddSpecial(cell,context,unit);
        else
        {
            WALL2_AddUnit(cell,context,unit);
            if(UNIT_GetFlagC8_7(unit)) WALL2_AddOverlay(cell,context,unit);
        }
    }
    return 1;
}

// 0x004DDDD0
D2ClearPairStrc::D2ClearPairStrc()
{
    nFirst = 0;
    nSecond = 0;
}

// 0x004DDDE0
void __cdecl sub_004DDDE0_Nop()
{
}

// 0x004DDE40
static inline int WALL2_IsPointInRect(D2GridRectStrc* pRect, int nX, int nY)
{
    D2_ASSERT(pRect, 0x76);
    if (nX < pRect->nLeft || nX >= pRect->nRight || nY < pRect->nTop || nY >= pRect->nBottom)
    {
        return 0;
    }
    return 1;
}

// 0x004DDEC0
static inline void WALL2_FillCells(D2GridCellStrc* pCells)
{
    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            pCells->nIntensity = 0xFF;
            pCells->nRed = 0xFF;
            pCells->nBlue = 0xFF;
            pCells->nGreen = 0xFF;
            ++pCells;
        }
    }
}

// 0x004DDEF0
static void __stdcall WALL2_BuildLargeGrid(int nX, int nY, int bFlat, D2GridCellStrc* pCells)
{
    if (bFlat)
    {
        const unsigned char nB0 = ENVIRONMENT_GetIntensityFromAct(gpGlobal_007A0634);
        unsigned char nB1, nB2, nB3;
        ENVIRONMENT_GetLightColorFromAct(gpGlobal_007A0634, &nB1, &nB2, &nB3);
        for (int j = 0; j < 8; ++j)
        {
            for (int i = 0; i < 8; ++i)
            {
                pCells->nRed = nB1;
                pCells->nIntensity = nB0;
                pCells->nBlue = nB3;
                pCells->nGreen = nB2;
                ++pCells;
            }
        }
        return;
    }

    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            SCMD_ReadGridCell(8 * (nX + i - 1), 8 * (nY + j - 1), &pCells->nIntensity, &pCells->nRed, &pCells->nGreen, &pCells->nBlue);
            ++pCells;
        }
    }
}

struct D2TileStrc;

struct D2GridOwnerStrc;

struct D2GridUnitStrc;

struct D2GridLightStrc;

struct D2GridCoordStrc;

union D2SeedStrc;

struct D2DrlgCoordsStrc;

struct D2FloorViewArgStrc;

struct D2FloorTileViewStrc;

struct D2GridLightStrc
{
    int bCorners;
    int bSmall;
    int bEffectA;
    int bEffectB;
    int nLimitA;
    char pad0x14[0x8];
    int f_1C;
    int nMode;
    D2GridOwnerStrc* pOwner;

    void __thiscall ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY); // 0x004DE410
    void __thiscall ExtendBounds(D2GridUnitStrc* pUnit, int nSubX, int nSubY);     // 0x004DDE80
};



void __stdcall WALL2_FillGridLight(D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE070

void __stdcall WALL2_FillCellLights(D2GridCellStrc* pCells, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE260

int __fastcall SEED_RollInRange(int nSeed, int nZero, int nMax); // 0x00472280

static void __stdcall WALL2_BuildSmallFlatGrid(D2GridCoordStrc tX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode); // 0x004DDFD0

static void __stdcall WALL2_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode); // 0x004DE190

struct D2FloorViewArgStrc
{
    char unk0x00[0x24];
    int nX;
    int nY;
};

struct D2FloorTileViewStrc
{
    int nMode;
    int bPerspective;
    int bTickFlag;
    int bMudFlag;
    int nPhase;
    unsigned int dwTickA;
    unsigned int dwTickB;
    D2SeedStrc* pSeed;
    int nBorder;
    D2FloorViewArgStrc* pArg;
    int bEdges;
    int nMinX;
    int nMaxX;
    int nMinY;
    int nMaxY;
    int nOffsetX;
    int nOffsetY;
    void __thiscall sub_004DE410_DrawFloorTile(D2TileStrc* pTile, int nArg, int nScreenX, int nScreenY, int nX, int nY);
    void __thiscall DrawTileAt(int nX, int nY); // 0x004DE630
    void __thiscall DrawTileTriple(int nX, int nY, int nStepX, int nStepY); // 0x004DE6C0
    void __thiscall UpdateView(void* pArgument); // 0x004DE730
};




int __cdecl sub_00473770_IsMudLevel(); // 0x00473770

float __cdecl sub_00473C80_GetPhaseLevel(); // 0x00473C80

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0

int __cdecl D2GFX_CheckLowQuality(); // 0x004F5210

D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount); // 0x00619660

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* ptRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

// 0x004DDFD0
static void __stdcall WALL2_BuildSmallFlatGrid(D2GridCoordStrc tX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    switch (nMode)
    {
    case 1:
        tX.n -= gnScreenWidth / 4;
        break;
    case 2:
        tX.n += gnScreenWidth / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                pCells->nIntensity = 0xFF;
                pCells->nX = 16 * (i - j) + tX.n;
                pCells->nY = nY + 8 * (i + j);
                pCells->nRed = 0xFF;
                pCells->nBlue = 0xFF;
                pCells->nGreen = 0xFF;
            }
            ++pCells;
        }
    }
}

// 0x004DE070
void __stdcall WALL2_FillGridLight(D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int bFlat, int nMode, int bCorners)
{
    const unsigned char nB0 = ENVIRONMENT_GetIntensityFromAct(gpGlobal_007A0634);
    D2GridCellStrc* pCell = pCells;
    switch (nMode)
    {
    case 1:
        nX += -(gnScreenWidth / 4);
        break;
    case 2:
        nX += gnScreenWidth / 4;
        break;
    }

    unsigned char nB1, nB2, nB3;
    ENVIRONMENT_GetLightColorFromAct(gpGlobal_007A0634, &nB1, &nB2, &nB3);

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i, ++pCell)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                pCell->nX = ((i - j) << 4) + nX;
                pCell->nY = nY + ((i + j) << 3);
                if (bFlat)
                {
                    pCell->nIntensity = nB0;
                    pCell->nRed = nB1;
                    pCell->nBlue = nB3;
                    pCell->nGreen = nB2;
                }
                else
                    SCMD_ReadGridCell((nSubX + i) << 3, 8 * (nSubY + j), &pCell->nIntensity, &pCell->nRed, &pCell->nGreen, &pCell->nBlue);
            }
        }
    }
}


// 0x004DE190
static void __stdcall WALL2_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    int nShift = 0;
    switch (nMode)
    {
    case 1:
        nShift = -(gnScreenWidth / 4);
        break;
    case 2:
        nShift = gnScreenWidth / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        const int nY = nSubY + j;
        for (int i = 0; i < 6; ++i, ++pCells)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                SCALE_AdjustPerspectivePosition((nSubX + i) << 16, nY << 16, nZ, &pCells->nX, &pCells->nY);
                pCells->nX += nShift;
                pCells->nIntensity = 0xFF;
                pCells->nRed = 0xFF;
                pCells->nBlue = 0xFF;
                pCells->nGreen = 0xFF;
            }
        }
    }
}


static inline int CLIENTS_GetUnitX_FloorView(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY_FloorView(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004DE260
void __stdcall WALL2_FillCellLights(D2GridCellStrc* pCells, int nSubX, int nSubY, int nZ, int nMode, int bCorners)
{
    const unsigned char nB0 = ENVIRONMENT_GetIntensityFromAct(gpGlobal_007A0634);
    D2GridCellStrc* pCell = pCells;

    int nOffset = 0;
    switch (nMode)
    {
    case 1:
        nOffset = -(gnScreenWidth / 4);
        break;

    case 2:
        nOffset = gnScreenWidth / 4;
        break;
    }

    unsigned char nB1, nB2, nB3;
    ENVIRONMENT_GetLightColorFromAct(gpGlobal_007A0634, &nB1, &nB2, &nB3);

    int i;
    int j;

    if (nZ)
    {
        for (j = 0; j < 6; ++j)
        {
            const int nY = j + nSubY;
            for (i = 0; i < 6; ++i)
            {
                if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
                {
                    SCALE_AdjustPerspectivePosition((i + nSubX) << 16, nY << 16, nZ, &pCell->nX, &pCell->nY);
                    pCell->nX += nOffset;
                    pCell->nIntensity = nB0;
                    pCell->nRed = nB1;
                    pCell->nBlue = nB3;
                    pCell->nGreen = nB2;
                }

                ++pCell;
            }
        }
    }
    else
    {
        for (j = 0; j < 6; ++j)
        {
            const int nY = j + nSubY;
            for (i = 0; i < 6; ++i)
            {
                if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
                {
                    const int nX = i + nSubX;
                    SCALE_AdjustPerspectivePosition(nX << 16, nY << 16, 0, &pCell->nX, &pCell->nY);
                    pCell->nX += nOffset;
                    SCMD_ReadGridCell(nX << 3, nY << 3, &pCell->nIntensity, &pCell->nRed, &pCell->nGreen, &pCell->nBlue);
                }

                ++pCell;
            }
        }
    }
}

// 0x004DE410
void __thiscall D2GridLightStrc::ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY)
{
    if (pUnit->dwFlags & 0x408)
    {
        return;
    }

    D2GridRectStrc* pRect = &pOwner->tRect;
    if (!WALL2_IsPointInRect(pRect, nX, nY))
    {
        return;
    }

    D2GridInfoStrc* pInfo = pUnit->pInfo;
    if (pInfo->nBusy)
    {
        return;
    }

    D2GridCellStrc tLarge[8 * 8];
    D2GridCellStrc tSmall[6 * 6];
    if (DLIGHTMAP_GetRenderMode() < 4)
    {
        if (pInfo->wFlags & 0x100)
        {
            WALL2_FillCells(tLarge);
        }
        else
        {
            WALL2_BuildLargeGrid(nSubX, nSubY, 0, tLarge);
        }
        D2GFX_FloorTileDraw(pUnit->pInfo, tLarge, nX, nY, nSubX, nSubY, 0xFF, nMode, nArg);
    }
    else
    {
        if (bSmall)
        {
            if (pInfo->wFlags & 0x100)
            {
                WALL2_BuildSmallGrid(nSubX, nSubY, 0, bCorners, tSmall, nMode);
            }
            else
            {
                WALL2_FillCellLights(tSmall, nSubX, nSubY, 0, nMode, bCorners);
            }
        }
        else
        {
            if (pInfo->wFlags & 0x100)
            {
                D2GridCoordStrc tX;
                tX.n = nX;
                WALL2_BuildSmallFlatGrid(tX, nY, bCorners, tSmall, nMode);
            }
            else
            {
                WALL2_FillGridLight(tSmall, nX, nY, nSubX, nSubY, 0, nMode, bCorners);
            }
        }
        D2GFX_FloorTileDraw(pUnit->pInfo, tSmall, nX, nY, nSubX, nSubY, 0xFF, nMode, nArg);
    }

    if (pInfo->wFlags & 2)
    {
        const int nRoll = SEED_RollInRange(f_1C, 0, 1000);
        const int nFixX = nSubX << 16;
        const int nFixY = nSubY << 16;
        if (bEffectA && nRoll < nLimitA)
        {
            sub_00472DA0(nX, nY, nFixX, nFixY);
        }
        if (bEffectB && nRoll < 100)
        {
            sub_00472EC0(nX, nY, nFixX, nFixY);
        }
    }

    ExtendBounds(pUnit, nSubX, nSubY);
}

D2TileStrc* __stdcall DUNGEON_GetTileDataFromAct(void* pAct); // 0x00619720

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

// 0x004DE630
void __thiscall D2FloorTileViewStrc::DrawTileAt(int nX, int nY)
{
    int nScreenX = nX;
    int nScreenY = nY + 5;
    DUNGEON_GameSubtileToClientCoords(&nScreenX, &nScreenY);
    nScreenY += 0x28;
    D2_ASSERT(gpGlobal_007A0634, 0xDF);
    nScreenX += nOffsetX;
    nScreenY += nOffsetY;
    D2TileStrc* pTile = DUNGEON_GetTileDataFromAct(gpGlobal_007A0634);
    if (pTile)
    {
        sub_004DE410_DrawFloorTile(pTile, 1, nScreenX, nScreenY, nX, nY);
    }
}

// 0x004DE6C0
void __thiscall D2FloorTileViewStrc::DrawTileTriple(int nX, int nY, int nStepX, int nStepY)
{
    const int nBaseX = nX / 5 * 5;
    const int nBaseY = nY / 5 * 5;
    DrawTileAt(nBaseX, nBaseY);
    DrawTileAt(nBaseX + nStepX, nBaseY + nStepY);
    DrawTileAt(nBaseX + 2 * nStepX, nBaseY + 2 * nStepY);
}

// 0x004DE730
void __thiscall D2FloorTileViewStrc::UpdateView(void* pArgument)
{
    D2ActiveRoomStrc** ppRooms;
    int nRooms;
    int nTiles;

    nMode = D2GFX_CheckLowQuality();
    bPerspective = D2GFX_CheckPerspective();
    const unsigned int dwTick = sub_0044DB00_GetTickCounter();
    bTickFlag = 0;
    bMudFlag = 0;
    nPhase = (int)(sub_00473C80_GetPhaseLevel() * 1000.0);
    const int nBorderType = UI_GetPanelSlideMode();
    nBorder = nBorderType;
    pArg = (D2FloorViewArgStrc*)pArgument;

    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    bEdges = pRoom && DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->nDrawEdges && !nBorderType && D2GFX_GetResolutionMode() == 2;

    nMinX = 0x7FFFFFFF;
    nMaxX = 0x80000000;
    nMinY = 0x7FFFFFFF;
    nMaxY = 0x80000000;
    nOffsetX = 0x50 - pArg->nX;
    nOffsetY = -0x50 - pArg->nY;

    if (dwTick > dwTickA + 3)
    {
        dwTickA = dwTick;
        if (nPhase)
            bTickFlag = 1;
    }

    if (sub_00473770_IsMudLevel() && dwTick > dwTickB + 0x19)
    {
        dwTickB = dwTick;
        bMudFlag = 1;
    }

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x11E);
    pSeed = &pPlayer->pSeed;

    pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
        return;

    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
    D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxt, 0x130);
    const int bNoFilter = pLevelsTxt->dwFloorFilter == 0;

    const int& nViewX = nOffsetX;
    for (int i = 0; i < nRooms; ++i)
    {
        D2DrlgCoordsStrc tCoords;
        DUNGEON_GetRoomCoordinates(ppRooms[i], &tCoords);
        for (unsigned int nLayer = 1; nLayer < 3; ++nLayer)
        {
            const int bArg = !bNoFilter && nLayer == 1;
            D2DrlgTileDataStrc* pTile = DUNGEON_GetFloorTilesFromRoom(ppRooms[i], &nTiles);
            while (nTiles)
            {
                if (((pTile->dwFlags >> 0xE) & 7) == nLayer)
                {
                    sub_004DE410_DrawFloorTile((D2TileStrc*)pTile, bArg, nViewX + pTile->nWidth,
                        pTile->nHeight + nOffsetY, tCoords.nSubtileX + 5 * pTile->nPosX, tCoords.nSubtileY + 5 * pTile->nPosY);
                }
                --nTiles;
                ++pTile;
            }
        }
    }

    if (!bEdges)
        return;

    const int nRangeA = bPerspective ? 0x21 : 0x1E;
    const int nRangeB = bPerspective ? 0x17 : 0x19;
    D2UnitStrc* pUnit = CUNIT_GetPlayerUnit2();
    if (!pUnit)
        return;

    const int nX = CLIENTS_GetUnitX_FloorView(pUnit);
    const int nY = CLIENTS_GetUnitY_FloorView(pUnit);
    if (nX - nMinX < nRangeA)
        DrawTileTriple(nMinX - 5, nY, 0, -5);
    if (nMaxX - nX < nRangeB)
        DrawTileTriple(nMaxX + 5, nY, 0, 5);
    if (nY - nMinY < nRangeA)
        DrawTileTriple(nX, nMinY - 5, -5, 0);
    if (nMaxY - nY < nRangeB)
        DrawTileTriple(nX, nMaxY + 5, 5, 0);
}

static D2FloorTileViewStrc gObj_007C8A28; // 0x007C8A28

unsigned char gnRoomColorBlue; // 0x007C8A6C

unsigned char gnRoomColorGreen; // 0x007C8A6D

unsigned char gnRoomColorIntensity; // 0x007C8A6E

unsigned char gnRoomColorRed; // 0x007C8A6F

// 0x004DED10
void __fastcall WALL2_UpdateView(void* pArg)
{
    gObj_007C8A28.UpdateView(pArg);
}

// 0x004DED20
void __cdecl WALL2_UpdateRoomColor()
{
    ENVIRONMENT_GetLightColorFromAct(gpGlobal_007A0634, &gnRoomColorRed, &gnRoomColorGreen, &gnRoomColorBlue);
    gnRoomColorIntensity = ENVIRONMENT_GetIntensityFromAct(gpGlobal_007A0634);

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    DUNGEON_GetRGB_IntensityFromRoom(pRoom, &nIntensity, &nRed, &nGreen, &nBlue);
    if (nRed || nGreen || nBlue)
    {
        gnRoomColorIntensity = nIntensity;
        gnRoomColorRed = nRed;
        gnRoomColorGreen = nGreen;
        gnRoomColorBlue = nBlue;
    }
}

#pragma pack(push, 1)
struct d2data_0072A96C_t
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

extern "C" struct d2data_0072A96C_t gData_0072A96C; // 0x0072A96C

extern s32 gVar_0072A968_Mode = 1; // 0x0072A968

extern "C" struct d2data_0072A96C_t gData_0072A96C = {
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
}; // 0x0072A96C
