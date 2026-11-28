struct D2UnitStrc; struct D2ActiveRoomStrc; struct D2BitBufferStrc;
struct D2GfxDataStrc { int nFrame; int unknown04[12]; void* pCellFile; int unknown38[2]; int nDirection; int unknown44; };
struct Unicode { unsigned short wChar; };
#include "D2WaypointLayout.h"
#pragma pack(push,1)
struct D2WaypointEntryStrc { int nLevelId; unsigned char bEnabled; };
#pragma pack(pop)
extern "C" void* __cdecl memset(void*,int,unsigned int);
void __cdecl TEXT_LoadWaypointPanelCels(); // 0x0049C580
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
int __fastcall D2Win_10127_SetFont(int nFontSize); // 0x00502EF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*,int,int); // 0x0065C310
void* __cdecl sub_00454600_GetCloseButtonCell(); // 0x00454600
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
const Unicode* __fastcall UI_GetLevelName(int nLevelId); // 0x00453E70
void __fastcall D2Win_10117_DrawText(const Unicode*,int,int,int,int); // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30
int __fastcall D2Win_10121_GetTextWidth(const Unicode*); // 0x00501820
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
extern int gnScreenHeight; // 0x00711470
extern int gnOffsetX_007A2858; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern D2WaypointEntryStrc gaWaypointEntries[]; // 0x007BF03C
extern unsigned char gbWaypointClosePressed; // 0x007BF06C
extern int gnWaypointSelected; // 0x007BF06D
extern D2WaypointLayoutStrc gaLayouts[]; // 0x007224E8
extern void* gpWaypointBackgroundCel; // 0x007BF071
extern void* gpWaypointActTabsCel; // 0x007BF075
extern void* gpWaypointIconCel; // 0x007BF079
extern int gnWaypointId; // 0x007BF07D
extern unsigned char gbSent; // 0x007BF085
extern int gnWaypointAct; // 0x007BF086
extern int gnWaypointCount; // 0x007BF08A
extern int gnWaypointEnabledCount; // 0x007BF08E
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

static inline int GetWaypointPanelBottom() { return gnScreenHeight+gnPanelOffsetY; }

// 0x0049C9C0
void __cdecl TEXT_DrawWaypointPanel()
{
    TEXT_LoadWaypointPanelCels();
    if(CUNIT_IsPlayerDeadOrMissing())
    {
        UI_SetUIVar(20,1,0);
        if(!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
        {
            MSG_SendTwoDwords(0x49,gnWaypointId,0);
            gbSent=1;
        }
    }
    D2Win_10127_SetFont(1);
    D2GfxDataStrc tGfx;
    memset(&tGfx,0,sizeof(tGfx));
    tGfx.pCellFile=gpWaypointBackgroundCel;
    tGfx.nDirection=0;
    tGfx.nFrame=0;
    TEXTURE_CelDraw(&tGfx,gnOffsetX_007A2858,GetWaypointPanelBottom()-224,-1,5,0);
    tGfx.nFrame=1;
    TEXTURE_CelDraw(&tGfx,gnOffsetX_007A2858+256,GetWaypointPanelBottom()-224,-1,5,0);
    tGfx.nFrame=2;
    TEXTURE_CelDraw(&tGfx,gnOffsetX_007A2858,(gnScreenHeight+gnPanelOffsetY)-48,-1,5,0);
    tGfx.nFrame=3;
    TEXTURE_CelDraw(&tGfx,gnOffsetX_007A2858+256,(gnScreenHeight+gnPanelOffsetY)-48,-1,5,0);
    int nMouseX=sub_00468730();
    int nMouseY=sub_00468740();
    nMouseX-=gnOffsetX_007A2858;
    nMouseY+=gnPanelOffsetY;
    tGfx.pCellFile=gpWaypointActTabsCel;
    int nActCount=5;
    int nYOffset=0;
    int nActPositions[5];
    if(FOG_IsExpansion() && GAME_IsExpansion())
    {
        nYOffset=1;
        nActPositions[0]=5;
        nActPositions[1]=67;
        nActPositions[2]=129;
        nActPositions[3]=191;
        nActPositions[4]=253;
    }
    else
    {
        nActCount=4;
        nActPositions[0]=3;
        nActPositions[1]=81;
        nActPositions[2]=159;
        nActPositions[3]=237;
    }
    for(int nAct=0;nAct<nActCount;++nAct)
    {
        if(nAct==gnWaypointAct)
            tGfx.nFrame=nAct*2;
        else
        {
            unsigned char bAllowed=1;
            switch(nAct)
            {
            case 1:
                if(!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(),7,0))bAllowed=0;
                break;
            case 2:
                if(!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(),15,0))bAllowed=0;
                break;
            case 3:
                if(!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(),23,0))bAllowed=0;
                break;
            case 4:
                if(!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(),26,0))bAllowed=0;
                if(!FOG_IsExpansion() || !GAME_IsExpansion())bAllowed=0;
                break;
            }
            if(!bAllowed)continue;
            tGfx.nFrame=nAct*2+1;
        }
        TEXTURE_CelDraw(&tGfx,nActPositions[nAct]+gnOffsetX_007A2858,nYOffset-gnPanelOffsetY+33,-1,5,0);
    }
    tGfx.pCellFile=sub_00454600_GetCloseButtonCell();
    tGfx.nFrame=10+(gbWaypointClosePressed!=0);
    TEXTURE_CelDraw(&tGfx,gnOffsetX_007A2858+273,417-gnPanelOffsetY,-1,5,0);
    int nLevelId=DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));
    tGfx.pCellFile=gpWaypointIconCel;
    for(int nRow=0;nRow<gnWaypointCount;++nRow)
    {
        int nColor;
        if(gaWaypointEntries[nRow].bEnabled)
        {
            if(gaWaypointEntries[nRow].nLevelId==nLevelId)
                tGfx.nFrame=gnWaypointSelected==nRow;
            else
                tGfx.nFrame=3+(gnWaypointSelected==nRow);
            TEXTURE_CelDraw(&tGfx,gaLayouts[nRow].nCellX+gnOffsetX_007A2858,gaLayouts[nRow].nCellY-gnPanelOffsetY,-1,5,0);
            nColor=0;
        }
        else nColor=5;
        if(!gbWaypointClosePressed && gnWaypointSelected!=-1 && nRow==gnWaypointSelected)nColor=3;
        if(gaWaypointEntries[nRow].nLevelId==nLevelId)
        {
            nColor=3;
            tGfx.nFrame=0;
            TEXTURE_CelDraw(&tGfx,gaLayouts[nRow].nCellX+gnOffsetX_007A2858,gaLayouts[nRow].nCellY-gnPanelOffsetY,-1,5,0);
        }
        D2Win_10117_DrawText(UI_GetLevelName(gaWaypointEntries[nRow].nLevelId),gaLayouts[nRow].nTextX+gnOffsetX_007A2858,gaLayouts[nRow].nTextY-gnPanelOffsetY,nColor,0);
    }
    if((unsigned int)(nMouseX-273)<=35 && (unsigned int)(nMouseY-387)<=33)
    {
        const Unicode* wszText=D2LANG_GetStringFromTblIndex(0x1022);
        int nWidth=D2Win_10121_GetTextWidth(wszText);
        D2GFX_DrawBox(gnOffsetX_007A2858-nWidth/2+287,370-gnPanelOffsetY,nWidth/2+gnOffsetX_007A2858+294,387-gnPanelOffsetY,0,2);
        D2Win_10117_DrawText(wszText,gnOffsetX_007A2858-nWidth/2+292,385-gnPanelOffsetY,0,0);
    }
    if(!gnWaypointEnabledCount)
    {
        const Unicode* wszText=D2LANG_GetStringFromTblIndex(0xF97);
        int nWidth=D2Win_10121_GetTextWidth(wszText);
        D2Win_10117_DrawText(wszText,gnOffsetX_007A2858-nWidth/2+160,48-gnPanelOffsetY,0,0);
    }
    else
    {
        const Unicode* wszText=D2LANG_GetStringFromTblIndex(0xF96);
        int nWidth=D2Win_10121_GetTextWidth(wszText);
        D2Win_10117_DrawText(wszText,gnOffsetX_007A2858-nWidth/2+160,48-gnPanelOffsetY,0,0);
    }
}

