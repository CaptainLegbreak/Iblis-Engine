#include "D2LanguageNames.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Primitives.h"
#include "D2StormTypes.h"
#include "D2ClientParty.h"
#include "D2WinSplitText.h"
#include "D2WaypointActRange.h"
#include "D2CommonApi.h"
#include "StormApi.h"

struct D2PartyRowStrc;
struct D2PacketRecord21Strc;
struct D2WaypointMenuEntryStrc;
struct D2WaypointRowRectStrc;



extern D2PartyRowStrc* gpRosterUnits; // 0x007BF014
extern int gnWaypointSelected; // 0x007BF06D

struct D2PacketRecord21Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char pWaypointData[16];
};
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
void __cdecl WARDENCLIENT_BuildWaypointList(); // 0x0049C7F0
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
#include "D2WaypointLayout.h"
extern D2WaypointLayoutStrc gaLayouts[9]; // 0x007224E8
extern bool gbWaypointClosePressed; // 0x007BF06C
// 0x0049BB40
static inline void TEXT_SetSlotCount(D2PartyRowStrc* pRow, int nSlot)
{
    if (pRow->aSlots[nSlot].nState != 1)
        pRow->aSlots[nSlot].nFrame = 1;
}

void __fastcall sub_M110_Emit_0049BB40(D2PartyRowStrc* pRow, int nSlot)
{
    TEXT_SetSlotCount(pRow, nSlot + 1);
}

int gbRosterButtonDown; // 0x007BF030

int gbRosterMode; // 0x007BF038

static inline int sub_M165_InSlot(int nSlotX, int nSlotY, int nWidth)
{
    const int nCursorX = sub_00468730();
    const int nCursorY = sub_00468740();
    return nCursorX >= gnPanelOffsetX + nSlotX && nCursorX <= gnPanelOffsetX + nSlotX + nWidth && nCursorY >= nSlotY - gnPanelOffsetY - 0x14 && nCursorY <= nSlotY - gnPanelOffsetY;
}

// 0x0049BB60
void __stdcall TEXT_OnRosterMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = sub_00468730();
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    pEntry = ROSTER_GetNextStoredUnit(pEntry);
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nCursorX = sub_00468730();
    int nCursorY = sub_00468740();
    if (nCursorX >= gnPanelOffsetX + 0x116 && nCursorX <= gnPanelOffsetX + 0x136 && nCursorY >= 0x185 - gnPanelOffsetY && nCursorY <= 0x1A5 - gnPanelOffsetY)
    {
        gbRosterButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    if (nX < gnScreenWidth / 2)
    {
        while (pRow)
        {
            for (int i = 0; i < 5; ++i)
            {
                if (!pRow->aSlots[i].bFlag)
                {
                    if (sub_M165_InSlot(pRow->aSlots[i].nX, pRow->aSlots[i].nY, 0x14))
                    {
                        if (pRow->aSlots[i].nType == 1 && ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) < 9)
                        {
                            pMsg->bReturn = 1;
                            pMsg->lResult = 0;
                            sub_00420290_BreakHandlerChain(pMsg);
                            return;
                        }

                        if (pRow->aSlots[i].nType == 1)
                        {
                            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
                            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
                                continue;
                        }

                        const int nCount = pRow->aSlots[i].nFrame;
                        if (pRow->aSlots[i].bActive)
                            continue;
                        pRow->aSlots[i].nFrame = nCount + 1;
                        pRow->aSlots[i].bActive = 1;
                        gbRosterMode = 1;

                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        sub_00420290_BreakHandlerChain(pMsg);
                        return;
                    }
                }
                else if (sub_M165_InSlot(pRow->aSlots[i].nX, pRow->aSlots[i].nY, 0x35))
                {
                    if (pRow->aSlots[i].nState != 1)
                        pRow->aSlots[i].nFrame = 1;
                    pRow->aSlots[i].bActive = 1;
                    gbRosterMode = 1;
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }
            }

            pRow = pRow->pNext;
            if (pEntry)
                pEntry = ROSTER_GetNextStoredUnit(pEntry);
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
}

char gbGlobal_007BF06C; // 0x007BF06C

// 0x0049C470
static inline bool TEXT_IsPointInRect(int nX, int nY)
{
    if (nX >= 0x111 && nX <= 0x134 && nY >= 0x183 && nY <= 0x1A4)
        return true;
    return false;
}

int __stdcall sub_M113_Emit_0049C470(int nX, int nY)
{
    return TEXT_IsPointInRect(nX, nY) ? 3 : 7;
}

// 0x0049C560
void __cdecl TEXT_ResetSelection()
{
    gbGlobal_007BF06C = 0;
    gnWaypointSelected = -1;
}

// 0x0049C490
static int TEXT_GetActTabAtPoint(int nX, int nY)
{
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        if (nY > 0x1E || nX > 0x140)
            return -1;
        if (nX < 0x40)
            return 0;
        if (nX < 0x80)
            return 1;
        if (nX < 0xC0)
            return 2;
        if (nX < 0x100)
            return 3;
        return 4;
    }

    if (nY > 0x1E || nX > 0x140)
        return -1;
    if (nX < 0x50)
        return 0;
    if (nX < 0xA0)
        return 1;
    if (nX < 0xF0)
        return 2;
    return 3;
}

// 0x0049C510
static int sub_0049C510_GetWaypointRowAtPoint(int nX, int nY)
{
    for (int i = 0; i < 9; ++i)
    {
        if (gaWaypointEntries[i].bEnabled && nX > gaLayouts[i].nRowX && nX < gaLayouts[i].nRowX + 0x118
            && nY > gaLayouts[i].nRowY && nY < gaLayouts[i].nRowY + 0x1E)
            return i;
    }
    return -1;
}

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00


struct D2CelFileStrc;

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0


extern void* gpWaypointBackgroundCel; // 0x007BF071

extern void* gpWaypointActTabsCel; // 0x007BF075

extern void* gpWaypointIconCel; // 0x007BF079



extern "C" void __cdecl TEXT_FreeWaypointCels(); // 0x0049C650

// 0x0049C580
void __cdecl TEXT_LoadWaypointPanelCels()
{
    char szPath[0x104];
    if (!gpWaypointBackgroundCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygatebackground", gszDataGlobal);
        gpWaypointBackgroundCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpWaypointActTabsCel)
    {
        if (FOG_IsExpansion() && GAME_IsExpansion())
        {
            sprintf(szPath, "%s\\ui\\menu\\expwaygatetabs", gszDataGlobal);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\waygatetabs", gszDataGlobal);
        }
        gpWaypointActTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpWaypointIconCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygateicons", gszDataGlobal);
        gpWaypointIconCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

// 0x0049C650
extern "C" void __cdecl TEXT_FreeWaypointCels()
{
    if (gpWaypointBackgroundCel)
    {
        ARCHIVE_FreeClientCellFile(gpWaypointBackgroundCel);
        gpWaypointBackgroundCel = 0;
    }
    if (gpWaypointActTabsCel)
    {
        ARCHIVE_FreeClientCellFile(gpWaypointActTabsCel);
        gpWaypointActTabsCel = 0;
    }
    if (gpWaypointIconCel)
    {
        ARCHIVE_FreeClientCellFile(gpWaypointIconCel);
        gpWaypointIconCel = 0;
    }
}

// 0x0049C6A0
void __cdecl TEXT_InitWaypointData()
{
    gpWaypointData = WAYPOINTS_AllocWaypointData(0);
    gbSent = 0;
}

// 0x0049C6C0
void __cdecl sub_0049C6C0_SendWaypointClose()
{
    if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
    {
        MSG_SendTwoDwords(0x49, gnWaypointId, 0);
        gbSent = 1;
    }
}

// 0x0049C700
void __cdecl TEXT_CloseWaypointPanel()
{
    sub_0049C6C0_SendWaypointClose();
    if (gpWaypointData)
        WAYPOINTS_FreeWaypointData(0, gpWaypointData);
    gpWaypointData = 0;
    TEXT_FreeWaypointCels();
}

// 0x0049C760
static void TEXT_SetWaypointAct(int nAct)
{
    if (nAct >= gnWaypointActCount)
        nAct = 0;

    switch (nAct)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1C, 0))
            nAct = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0))
            nAct = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0))
            nAct = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0))
            nAct = 0;
    }

    gnWaypointAct = nAct;
}

struct Unicode;

struct D2WaypointActRangeStrc;





extern D2WaypointActRangeStrc gaWaypointActRanges[]; // 0x007224AC

extern int gnWaypointCount; // 0x007BF08A

extern int gnWaypointEnabledCount; // 0x007BF08E



class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

// 0x0049C7F0
void __cdecl WARDENCLIENT_BuildWaypointList()
{
    gnWaypointCount = 0;
    gnWaypointEnabledCount = 0;
    const int nCurrentLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));

    for (int i = 0; i < 9; ++i)
    {
        gaWaypointEntries[i].nLevelId = 0;
        gaWaypointEntries[i].bEnabled = 0;
    }

    if ((unsigned int)gnWaypointAct > 5)
    {
        gbSent = 0;
        return;
    }

    if (!gaWaypointActRanges[gnWaypointAct].bInit)
    {
        gaWaypointActRanges[gnWaypointAct].bInit = 1;
        for (int nLevelId = *(int*)gaWaypointActRanges[gnWaypointAct].nFirstLevelId;
            nLevelId <= *(int*)gaWaypointActRanges[gnWaypointAct].nLastLevelId; ++nLevelId)
        {
            unsigned short wWaypoint;
            if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &wWaypoint))
            {
                const unsigned char nIndex = (unsigned char)wWaypoint;
                if (gaWaypointActRanges[gnWaypointAct].nMinWaypoint == 0xFF)
                {
                    gaWaypointActRanges[gnWaypointAct].nMinWaypoint = nIndex;
                }

                gaWaypointActRanges[gnWaypointAct].nMaxWaypoint = nIndex > gaWaypointActRanges[gnWaypointAct].nMaxWaypoint ? nIndex : gaWaypointActRanges[gnWaypointAct].nMaxWaypoint;
            }
        }
    }

    for (int i = gaWaypointActRanges[gnWaypointAct].nMinWaypoint; i <= gaWaypointActRanges[gnWaypointAct].nMaxWaypoint; ++i)
    {
        const unsigned short wWaypoint = (unsigned short)i;
        if (WAYPOINTS_IsActivated(gpWaypointData, wWaypoint))
        {
            int nLevelId;
            if (WAYPOINTS_GetLevelIdFromWaypointNo(wWaypoint, &nLevelId))
            {
                gaWaypointEntries[gnWaypointCount].nLevelId = nLevelId;
                if (nCurrentLevelId == nLevelId)
                {
                    gaWaypointEntries[gnWaypointCount].bEnabled = 0;
                }
                else
                {
                    ++gnWaypointEnabledCount;
                    gaWaypointEntries[gnWaypointCount].bEnabled = 1;
                }
                ++gnWaypointCount;
            }
        }
        else
        {
            int nLevelId;
            if (WAYPOINTS_GetLevelIdFromWaypointNo(wWaypoint, &nLevelId))
            {
                gaWaypointEntries[gnWaypointCount].nLevelId = nLevelId;
                gaWaypointEntries[gnWaypointCount].bEnabled = 0;
                ++gnWaypointCount;
            }
        }
    }
}

// 0x0049C980
void __cdecl TEXT_UpdateWaypointAct()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                TEXT_SetWaypointAct(DRLG_GetActNoFromLevelId(nLevelId));
                WARDENCLIENT_BuildWaypointList();
                return;
            }
        }
    }

    gnWaypointAct = 0;
    WARDENCLIENT_BuildWaypointList();
}



// 0x0049CEC0
void __stdcall TEXT_WaypointKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->uMessage == 0x102 && pMsg->wParam == 9)
    {
        return;
    }

    if (pMsg->uMessage == 0x104 && pMsg->wParam == 0x73)
    {
        return;
    }

    if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
    {
        MSG_SendTwoDwords(0x49, gnWaypointId, 0);
        gbSent = 1;
    }

    UI_SetUIVar(20, 1, 1);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


// 0x0049CF50
void __cdecl sub_0049CF50_SendWaypointClose()
{
    if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
    {
        MSG_SendTwoDwords(0x49, gnWaypointId, 0);
        gbSent = 1;
    }
}

// 0x0049CF90
void __fastcall TEXT_OpenWaypointPanel(D2PacketRecord21Strc* pPacket)
{
    if (UI_SetUIVar(0x14, 0, 1) == 1)
    {
        GAME_ResetMouseState();
        TEXT_UpdateWaypointAct();
        gnWaypointId = *(int*)pPacket->nUnitGUID;
        WAYPOINTS_CopyAndValidateWaypointData(gpWaypointData, pPacket->pWaypointData);
        gbSent = 0;
        WARDENCLIENT_BuildWaypointList();
    }
}

void __stdcall TEXT_OnWaypointMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX <= gnScreenWidth && nY <= gnScreenHeight - 0x31)
    {
        nX -= gnPanelOffsetX;
        nY += gnPanelOffsetY;
        if (gbWaypointClosePressed)
        {
            if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
            {
                UI_SetUIVar(0x14, 1, 0);
                sub_0049C6C0_SendWaypointClose();
            }
        }
        else if (gnWaypointSelected != -1 && gnWaypointSelected == sub_0049C510_GetWaypointRowAtPoint(nX, nY))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            MSG_SendTwoDwords(0x49, gnWaypointId, gaWaypointEntries[gnWaypointSelected].nLevelId);
            gbSent = 1;
            sub_0049C6C0_SendWaypointClose();
            gbWaypointClosePressed = false;
            gnWaypointSelected = -1;
            UI_SetUIVar(0x14, 1, 0);
            sub_004B9A00(0x8B7, 0, 0, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
    }
}

// 0x0049D160
void __stdcall TEXT_WaypointMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX > gnScreenWidth / 2 || nY > gnScreenHeight - 0x31)
    {
        if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
        {
            MSG_SendTwoDwords(0x49, gnWaypointId, 0);
            gbSent = 1;
        }
        UI_SetUIVar(0x14, 1, 1);
        return;
    }

    nX -= gnPanelOffsetX;
    nY += gnPanelOffsetY;
    const int nTab = TEXT_GetActTabAtPoint(nX, nY);
    if (nTab != -1)
    {
        if (nTab != gnWaypointAct)
            sub_004B9A00(6, 0, 0, 0, 0);
        TEXT_SetWaypointAct(nTab);
        WARDENCLIENT_BuildWaypointList();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }

    gnWaypointSelected = -1;
    if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
    {
        gbWaypointClosePressed = true;
        sub_004B9A00(4, 0, 0, 0, 0);
    }
    else
    {
        gnWaypointSelected = sub_0049C510_GetWaypointRowAtPoint(nX, nY);
        if (gnWaypointSelected != -1)
            sub_004B9A00(4, 0, 0, 0, 0);
    }

    if ((unsigned short)pMsg->lParam > gnScreenWidth || (unsigned short)((unsigned int)pMsg->lParam >> 16) > gnScreenHeight - 0x31)
        return;

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

extern D2WaypointActRangeStrc gaWaypointActRanges[5] = {
    { 0, { 1 }, "&", 0xFF },
    { 0, "(", "J", 0xFF },
    { 0, "K", "f", 0xFF },
    { 0, "g", "k", 0xFF },
    { 0, "m", "\x88", 0xFF }
}; // 0x007224AC

extern int gnWaypointActCount = 5; // 0x007224E4

extern D2WaypointLayoutStrc gaLayouts[9] = {
    { 17, 89, 80, 84, 17, 60 },
    { 17, 125, 80, 119, 17, 96 },
    { 17, 161, 80, 154, 17, 132 },
    { 17, 197, 80, 189, 17, 168 },
    { 17, 234, 80, 224, 17, 205 },
    { 17, 270, 80, 259, 17, 241 },
    { 17, 306, 80, 294, 17, 277 },
    { 17, 342, 80, 329, 17, 313 },
    { 17, 378, 80, 364, 17, 349 }
}; // 0x007224E8
