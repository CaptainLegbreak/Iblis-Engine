#pragma once

// D2Client functions that many of the module's files call, declared once here.
// D2Client.h holds the module's records and globals; it has to come first.
//
// Eight units keep their own private declarations of these instead and don't include this header:
// GAME/Msg.cpp, UI/inv.cpp, UI/inv_004886C0.cpp, UI/inv_0048BC10.cpp, UI/inv_0048DD90.cpp,
// UI/UseItem.cpp, UNIT/Item.cpp and UNIT/UnitSnd.cpp. Their code depends on how many declarations
// precede it, and a header that grows changes that.

struct D2PoolSystemStrc;
struct D2ClientEntryStrc;
struct D2GSPacketSrv26;
struct D2GfxListNodeStrc;
struct D2HashedFileEntryStrc;
struct D2HashedFileStrc;
struct D2LoadingTimerStrc;
struct D2OptionEntryStrc;
struct D2OptionHeaderStrc;
struct D2SetItemsTxt;
struct D2SetsTxt;
struct D2SoundsTxt;
struct D2TextBoxStrc;
struct D2TextNodeStrc;
struct D2MonStats2Txt;
struct D2UniqueItemsTxt;
struct D2RosterInfoStrc;
struct D2MissileStrc;
struct D2MonTypeTxt;
union D2SeedStrc;
struct D2SkillDescTxt;
struct D2SoundEnvironTxtStrc;
struct D2UnitTargetStrc;
struct D2MissilesTxt;
struct D2UnitStrc;
struct D2CinematicPacketStrc;
struct D2ClientPacket7Strc;
struct D2GSPacketSrv42Strc;
struct D2GSPacketSrv5E;
struct D2GSPacketSrv7DStrc;
struct D2GSPacketSrv9C;
struct D2GSPacketSrv9D;
struct D2HirelingInfoStrc;
struct D2ItemStatCostTxt;
struct D2PacketRecord11Strc;
struct D2PacketRecord13Strc;
struct D2PacketRecord6Strc;
struct D2PacketRecord7Strc;
struct D2PacketRecord8Strc;
struct D2SkillsTxt;
struct D2TileLightCtxStrc;

void __fastcall GAME_CalcCdKeyChecksum(char* szKey, unsigned int* pChecksum); // 0x00449890
int __cdecl WINMAIN_PollMcpConnection(); // 0x00449B70
void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue); // 0x00449C60
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue); // 0x00449C80
void __stdcall sub_00449C90_SetValue(int nValue); // 0x00449C90
void __stdcall sub_00449CC0_SetValue(int nValue); // 0x00449CC0
void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2); // 0x00449D10
void __stdcall sub_00449D90_SetValue(int nValue); // 0x00449D90
void __stdcall sub_00449DB0_SetValue(int nValue); // 0x00449DB0
void __stdcall sub_00449DD0_SetValue(int nValue); // 0x00449DD0
void __stdcall sub_00449E30_SetValue(int nValue); // 0x00449E30
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize); // 0x00449E70
int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId); // 0x0044A4E0
int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId); // 0x0044A680
int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId); // 0x0044A710
int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2); // 0x0044A870
int __fastcall sub_0044A900_SendPacket0C(const char* szText); // 0x0044A900
int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC); // 0x0044AAE0
void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220
int __stdcall WINMAIN_PollSystemPackets(int nUnused); // 0x0044BAD0
int __cdecl GAME_GetConnectFailed(); // 0x0044BBA0
int __stdcall WINMAIN_WaitConnect(int nUnused); // 0x0044BBB0
int __stdcall WINMAIN_PumpSystemPackets(int nUnused); // 0x0044BD20
int __cdecl GAME_GetAlwaysRun(); // 0x0044BE90
void __fastcall GAME_SetStandStillHeld(int nValue); // 0x0044BEA0
unsigned short __cdecl GAME_GetClickFlags(); // 0x0044BEC0
int __cdecl GAME_GetLeftClickState(); // 0x0044BF00
int __cdecl GAME_GetRightClickState(); // 0x0044BF10
int __cdecl GAME_IsLeftClickRepeating(); // 0x0044BFE0
void __cdecl GAME_StartClick(); // 0x0044C000
void __cdecl GAME_ResetLeftClick(); // 0x0044C060
void __cdecl GAME_StartRightClick(); // 0x0044C2C0
void __cdecl GAME_InitRooms(); // 0x0044C750
void __cdecl GAME_UpdateGameState(); // 0x0044C790
void __stdcall GAME_DestroyWindowAndGfx(int nArg1, int nArg2, int nArg3); // 0x0044C850
void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860
void __cdecl GAME_FreeWeather(); // 0x0044C880
void __cdecl GAME_ReleaseGameState(); // 0x0044C890
void __cdecl GAME_AverageFrameCounters(); // 0x0044CCE0
void __cdecl GAME_TickKeepAlive(); // 0x0044CD70
void __cdecl GAME_UpdateKeyState(); // 0x0044CE90
void __cdecl GAME_SetCinematicPlayed(); // 0x0044D510
void __cdecl GAME_RequestExit(); // 0x0044D520
void __fastcall GAME_SetPlayCinematic(int nValue); // 0x0044D530
int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0
int __cdecl GAME_IsExitPending(); // 0x0044DA30
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70
int __cdecl GAME_GetSkippedFrames(); // 0x0044DAF0
int __cdecl sub_0044DB00_GetTickCounter(); // 0x0044DB00
int __cdecl GAME_GetConnectionType(); // 0x0044DB30
void __fastcall GAME_ExtendDelay(int nDelay); // 0x0044DB40
void __cdecl GAME_ReadColorFlag(); // 0x0044DBE0
int __cdecl GAME_GetColorFlag(); // 0x0044DC60
void __fastcall GAME_SetDifficulty(unsigned char nDifficulty); // 0x0044DC70
void __fastcall GAME_SetExpansion(unsigned char nValue); // 0x0044DC80
void __fastcall GAME_SetLadderFlag(int nValue); // 0x0044DC90
unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0
void __cdecl GAME_ExitForCinematic(); // 0x0044DD60
int __fastcall GAME_IsTimerExpired(D2LoadingTimerStrc* pTimer); // 0x0044DFF0
void __cdecl GAME_InitGameState(); // 0x0044E200
void __fastcall GAME_ShowLoadingMessage(int nError); // 0x0044E380
void __cdecl GAME_SetDifficultyFlags(); // 0x0044EC80
int __stdcall COMCALLBACK_LoadLngString(int nId, char* szBuffer, unsigned int nSize); // 0x004512C0
int __cdecl GAME_LoadLngModule(); // 0x00451330
void __cdecl RECORD_WriteRecordFile(); // 0x00451620
void __cdecl RECORD_StartPlayback(); // 0x004518E0
void __stdcall RECORD_RecordHandler(int nArg1, int nArg2, int nArg3); // 0x00451920
void __cdecl RECORD_InstallRecordHandler(); // 0x00451940
void __cdecl RECORD_SetRecordPlaying(); // 0x00451970
int __cdecl RECORD_IsReplayActive(); // 0x00451990
void __cdecl RECORD_ToggleRecordPlayback(); // 0x004519A0
int __cdecl GAME_PushRegisterState(); // 0x00451F10
void __cdecl GAME_DrawPopUpText(); // 0x00453060
void __cdecl UI_DrawProgressiveStates(); // 0x00453470
int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90
void __cdecl UI_DisableUIVarDelay(); // 0x00453AC0
void __cdecl UI_EnableUIVarDelay(); // 0x00453AD0
void __cdecl UI_StartUIVarDelay(); // 0x00453AE0
void __cdecl UI_FreePlayerUI(); // 0x00453DE0
void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0
void __fastcall UI_OpenGoldPanel(int nMode); // 0x00454150
void __cdecl GAME_LoadLoadingPalette(); // 0x00454740
void __fastcall UI_FreeLoadingScreen(); // 0x004547B0
int __cdecl UI_TickElapsed(); // 0x00454850
void __cdecl UI_RegisterKeyConfigHandlers(); // 0x00454980
void __cdecl GAME_LoadLoadingScreen(); // 0x00456550
void __cdecl UI_ShutdownUI(); // 0x00456D80
void __fastcall SKILLS_InitGfxCaches(D2PoolSystemStrc* pMemPool, int bCelPool); // 0x00457300
void __fastcall AUTOMAP_FreeCaches(int nArg); // 0x00457420
void __fastcall sub_00457440_Nop(int nResolution); // 0x00457440
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
void __cdecl AUTOMAP_UpdateAutomapLayout(); // 0x00457520
int __fastcall AUTOMAP_SetAutomapFade(int nFade); // 0x004576F0
int __cdecl AUTOMAP_GetAutomapCenters(); // 0x00457740
int __fastcall AUTOMAP_SaveAutomapCenters(int nValue); // 0x00457750
int __cdecl AUTOMAP_GetAutomapParty(); // 0x004577B0
int __cdecl AUTOMAP_GetAutomapPartyNames(); // 0x004577E0
void __cdecl AUTOMAP_ResetAutomapCells(); // 0x00458680
void __cdecl AUTOMAP_UpdateAutomapReveal(); // 0x00459020
void __cdecl AUTOMAP_PaintAutomap(); // 0x00459700
void __cdecl AUTOMAP_DrawGameInfoLines(); // 0x00459E90
void __cdecl AUTOMAP_DrawStringLine(); // 0x00459FF0
void __cdecl AUTOMAP_DrawLevelName(); // 0x0045A050
void __cdecl AUTOMAP_DrawVersionLine(); // 0x0045A0A0
void __cdecl AUTOMAP_DrawLocalIpLine(); // 0x0045A120
void __cdecl AUTOMAP_DrawDifficultyLine(); // 0x0045A190
void __cdecl AUTOMAP_InitAutomapColors(); // 0x0045A620
int __cdecl UI_GetAutomapMode(); // 0x0045A710
void __cdecl AUTOMAP_DrawAutomapUnits(); // 0x0045AC90
int __cdecl sub_0045AE90_GetPanelSlideMode(); // 0x0045AE90
void __fastcall PLAYER_SetPanelSlide(int nMode); // 0x0045AEA0
void __fastcall AUTOMAP_ScreenToMap(int* pX, int* pY); // 0x0045AFF0
void __fastcall GFX_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470
void __stdcall UI_DrawCelPair(int bFirst); // 0x0045FBC0
void __fastcall PLAYER_SetCinematicExpansion(int bExpansion); // 0x00460480
int __cdecl sub_00460500_RunPopup(); // 0x00460500
int __cdecl sub_004605A0_RunPopup(); // 0x004605A0
int __cdecl sub_00460680_RunOkCancel(); // 0x00460680
int __fastcall PLAYER_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0
unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860
D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
void __cdecl CUNIT_ClearUnitTables(); // 0x00463C70
D2UnitStrc* __cdecl CUNIT_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl CUNIT_GetPlayerUnit2(); // 0x00463DE0
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
int __fastcall CUNIT_GetBasePalShiftIndex(D2UnitStrc* pUnit); // 0x00463E50
int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit); // 0x00463EB0
void __fastcall CUNIT_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId); // 0x004643F0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __cdecl CUNIT_UpdateObjectsForPeriod(); // 0x004646C0
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930
void __fastcall CUNIT_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg); // 0x00464E50
void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0
void __cdecl CUNIT_FreeAllUnits(); // 0x004659C0
void __cdecl CUNIT_ResetUnitTables(); // 0x00465AA0
void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00
D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0
D2UnitStrc* __fastcall CUNIT_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName); // 0x00466200
D2UnitStrc* __fastcall CUNIT_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType); // 0x00466300
void __fastcall VIEW_SpawnRoomPresets(D2ActiveRoomStrc* pRoom); // 0x00466820
int __cdecl SELECT_GetHoverMonClassId(); // 0x00466DC0
int __cdecl SELECT_GetHoverClassId(); // 0x00466DD0
void __cdecl SELECT_ClearSelection(); // 0x00466FE0
void __cdecl SELECT_UnlockHover(); // 0x00466FF0
void __fastcall CURSOR_ResetCursorState(int nArg, int nArg2); // 0x00468040
void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
void __cdecl CURSOR_ShutdownCursor(); // 0x00468170
void __cdecl CURSOR_DrawCursor(); // 0x004684C0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl CURSOR_GetCursorState(); // 0x00468830
void __cdecl sub_00468F00_ShowBelt(); // 0x00468F00
void __fastcall CMDTBL_ResetKeyConfig(int nArg); // 0x00469A60
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0
void __cdecl CMDTBL_SaveHotkeys(); // 0x00469D20
void __cdecl CMDTBL_SaveAndBindHotkeys(); // 0x00469D40
int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90
void __fastcall VIEW_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce); // 0x0046AE50
int __stdcall ROSTERPETS_GetPulseColor(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0046BD50
void __fastcall VIEW_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom); // 0x0046BE60
void __cdecl VIEW_UpdateTimers(); // 0x0046BEB0
void __fastcall VIEW_CheckThroneLevel(D2ActiveRoomStrc* pRoom); // 0x0046BF30
void __cdecl VIEW_ResetLevelEffects(); // 0x0046BF90
void __fastcall sub_0046BFD0_StartTimer(int nDelay); // 0x0046BFD0
void __cdecl CUNIT_DrawCountdown(); // 0x0046C060
void __fastcall VIEW_PopulateRoom(D2ActiveRoomStrc* pRoom); // 0x0046C460
void __fastcall GFX_RemoveAiTargetUnit(D2UnitStrc* pUnit); // 0x0046C700
void __cdecl CUNIT_ClearAiTargets(); // 0x0046D750
int __fastcall GFX_GetConvertedUnitType(D2UnitStrc* pUnit); // 0x0046D9F0
D2HashedFileEntryStrc* __stdcall GFX_FindHashedEntry(D2HashedFileStrc* pTable, const char* szPath); // 0x0046DC40
void __fastcall GFX_DrawProgressiveStateOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY); // 0x0046E1B0
D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10
void __fastcall GFX_FreeGfxNodes(D2UnitStrc* pUnit); // 0x0046EC80
void __fastcall GFX_PruneGfxNodes(D2UnitStrc* pUnit); // 0x0046ECE0
int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060
void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0
void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280
int __cdecl UI_GetGfxMemory(); // 0x0046F980
int __cdecl UI_GetCofMemoryUsed(); // 0x0046F990
int __cdecl UI_GetCofMemoryLimit(); // 0x0046F9A0
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __cdecl sub_00472320_InitWeather(); // 0x00472320
void __cdecl sub_004723C0_FreeWeather(); // 0x004723C0
void __cdecl sub_00472BD0_FreeWeatherCels(); // 0x00472BD0
void __fastcall sub_00473C90_SetGlobal(int nValue); // 0x00473C90
void __cdecl sub_00473CE0_Nop(); // 0x00473CE0
void __cdecl sub_00473CF0_Nop(); // 0x00473CF0
void __fastcall sub_00473D00_SetPhase(int nPhase); // 0x00473D00
int __fastcall DLIGHTMAP_GetDistance(int nDX, int nDY); // 0x00474080
void __cdecl DLIGHTMAP_ScanGridCollision(); // 0x004756D0
void __cdecl DLIGHTMAP_FreeAllLights(); // 0x004758D0
unsigned char* __stdcall GFX_BuildLerpTable(unsigned int nCount, int nSteps); // 0x00475B80
unsigned char** __stdcall GFX_BuildLerpRowTable(unsigned int nCount, int nSteps); // 0x00475C40
unsigned char** __stdcall SCMD_BuildRampTable(unsigned int nSize, int nSteps); // 0x00475D30
void __cdecl VIEW_FreeLerpTables(); // 0x00475EF0
void __fastcall VIEW_FreeView(D2ViewStrc* pView); // 0x00475FD0
void __fastcall VIEW_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0
int __fastcall VIEW_GetViewShift(int* pX, int* pY); // 0x00476AC0
void __fastcall VIEW_PrepareSceneLighting(D2ViewStrc* pView); // 0x00476BC0
void __cdecl PALSHIFT_AllocPalShiftEntries(); // 0x00476EA0
void __cdecl PALSHIFT_FreePalShifts(); // 0x00476FB0
void __cdecl VIEW_ToggleCacheStats(); // 0x00477C00
void __cdecl INV_CheckCacheStats(); // 0x00477C60
void __fastcall MSG_ShowProgressSteps(int nDone, int nTotal); // 0x00478160
void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0
void __fastcall MSG_SendTwoWords(char nHeader, short nArg1, short nArg2); // 0x004785D0
void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680
void __fastcall MSG_SendStrings(const unsigned char* pData); // 0x004787B0
void __fastcall ROSTERPETS_SetRosterEntry(int nKey, int nArg, int nType, int nValue); // 0x00478B10
D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey); // 0x00478E40
int __fastcall ROSTERPETS_CountPets(D2UnitStrc* pOwner, int nPetType); // 0x00478EE0
int __fastcall ROSTER_GetPetLife(int nUnitId); // 0x00479080
int __fastcall ROSTERPETS_GetHirelingClassId(int nUnitId); // 0x00479120
int __fastcall ROSTER_GetPetType(int nUnitId); // 0x00479180
int __fastcall ROSTERPETS_IsOwnedByPlayer(D2UnitStrc* pUnit); // 0x004791B0
D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
void __fastcall ROSTER_SetKillCount(int nUnitId, unsigned short nValue); // 0x00479B10
int __fastcall ROSTER_GetLevel(D2StoredUnitRecordStrc* pEntry); // 0x00479B90
D2StoredUnitRecordStrc* __fastcall ROSTER_FindRosterUnitById(int nUnitId); // 0x00479BB0
unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
unsigned short __fastcall ROSTER_LookupPartyNumber(D2UnitStrc* pUnit); // 0x00479C00
int __fastcall ROSTER_TestLootFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479C20
int __fastcall ROSTER_TestMuteFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479C60
int __fastcall ROSTER_TestSquelchFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479CA0
int __fastcall ROSTER_TestHostileFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479CE0
void __fastcall ROSTER_HandlePartyButton(D2StoredUnitRecordStrc* pEntry); // 0x00479EB0
void __cdecl ROSTER_SendLeaveParty(); // 0x00479FC0
int __fastcall ROSTER_IsHostileRelation(int nUnitId1, int nUnitId2); // 0x0047A070
int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0
void __fastcall ROSTER_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId); // 0x0047A0D0
void __fastcall ROSTER_SetPosition(int nUnitId, int nX, int nY); // 0x0047A100
int __fastcall ROSTER_GetPartyLife(int nUnitId); // 0x0047A150
int __fastcall ROSTER_IsNotSquelched(int nUnitId); // 0x0047A170
char* __fastcall ROSTER_GetUnitName(D2UnitStrc* pUnit); // 0x0047A210
void __fastcall ROSTER_SetPartyId(int nUnitId, unsigned short wPartyId); // 0x0047A330
void __fastcall ROSTER_SetPartyFlags(int nUnitId, unsigned char nFlags); // 0x0047A350
void __fastcall ROSTER_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags); // 0x0047A370
void __fastcall ROSTER_AddCorpse(int nUnitId, int nCorpseId); // 0x0047A3D0
void __fastcall ROSTER_DropCorpseEntry(int nUnitId, int nCorpseId); // 0x0047A490
int __fastcall ROSTER_CanLoot(int nUnitId1, int nUnitId2); // 0x0047A4F0
int __cdecl ROSTER_IsAnyoneHostile(); // 0x0047A560
int __fastcall ROSTER_IsHostileToPlayer(D2StoredUnitRecordStrc* pEntry); // 0x0047A5B0
int __fastcall ROSTER_IsPlayerHostile(D2StoredUnitRecordStrc* pEntry); // 0x0047A5E0
int __fastcall ROSTER_AllowsPlayerLoot(D2StoredUnitRecordStrc* pEntry); // 0x0047A610
int __fastcall ROSTER_PlayerAllowsLoot(D2StoredUnitRecordStrc* pEntry); // 0x0047A640
void __fastcall ROSTER_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags); // 0x0047A850
int __cdecl CHAT_IsNumberDisplayEnabled(); // 0x0047A980
int __cdecl CHAT_HasClassOverride(); // 0x0047AA30
bool __cdecl CHAT_IsImeLanguage(); // 0x0047B010
void __stdcall CHAT_StepChatIndex(int nDelta); // 0x0047BA80
void __fastcall ESCMENU_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries); // 0x0047DBB0
void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu); // 0x0047E090
int __cdecl MINIPANEL_IsAnyPanelOpen(); // 0x0047EA60
int __cdecl MINIPANEL_IsAnyLeftPanelOpen(); // 0x0047EB50
void __cdecl MINIPANEL_LoadResolution(); // 0x0047F1D0
int __cdecl sub_0047F210_IsMouseInSlots(); // 0x0047F210
void __fastcall MINIPANEL_ShowPage2(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg); // 0x0047F310
void __fastcall MINIPANEL_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg); // 0x0047F340
void __fastcall MINIPANEL_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg); // 0x0047F3A0
void __fastcall MINIPANEL_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg); // 0x0047F400
void __fastcall MINIPANEL_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg); // 0x0047F430
void __cdecl WARDENCLIENT_ActivatePendingModule(); // 0x00480230
void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420
void __cdecl UNITMODE_StopAllSounds(); // 0x00481830
void __cdecl sub_00481850_Nop(); // 0x00481850
void __cdecl SOUNDHDR_TickSound(); // 0x00482C20
void __fastcall INV_UpdateAuxBattleNetAddress(int nIndex); // 0x00482CA0
unsigned char __cdecl INV_IsCinematicBusy(); // 0x00483350
D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId); // 0x00483410
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex); // 0x00483440
void __cdecl INV_LoadUiRecords(); // 0x004835B0
void __cdecl INV_InitColorTable(); // 0x00483960
int __fastcall INV_IsInPlayerInvRect(int nX, int nY); // 0x00483AB0
int __cdecl INV_GetPanelX(); // 0x00486AE0
int __cdecl INV_CheckTradeClickDelay(); // 0x00486D10
int __fastcall INV_IsInNpcPanelRect(int nX, int nY); // 0x00486E10
void __cdecl INV_ResetHover(); // 0x00487990
void __stdcall INV_SelectItemPageTab(unsigned char nTab); // 0x00487A10
int __cdecl INV_ResetNpcButtons(); // 0x00487BE0
int __cdecl INV_CanUseCursor(); // 0x004888C0
void __fastcall CUNIT_SetDialogState(int nState); // 0x004898D0
void __cdecl INV_CloseCubePanel(); // 0x0048A050
int __stdcall INV_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom); // 0x0048A790
void __stdcall INV_DrawUnitName(D2UnitStrc* pUnit); // 0x0048A7D0
void __cdecl INV_DrawPanelLabels(); // 0x0048A890
void __fastcall INV_DrawMercEquipHighlights(D2UnitStrc* pUnit); // 0x0048B3F0
void __stdcall INV_DrawIconNumber(int nValue, int nX); // 0x00493100
void __cdecl TEXT_LoadPopupHireling(); // 0x004939B0
int __cdecl HIREABLES_GetHelpMenuSetting(); // 0x004942D0
void __cdecl VIEW_DrawHelpFrameLowRes(); // 0x004943B0
void __cdecl VIEW_DrawHelpFrameHighRes(); // 0x004944F0
void __cdecl ROSTERPETS_DrawHelpColumn(); // 0x00494620
void __cdecl VIEW_DrawHelpLinesLowRes(); // 0x00494680
void __cdecl VIEW_DrawHelpLinesHighRes(); // 0x00494A00
void __cdecl VIEW_DrawHelpPanelCel(); // 0x00494E40
void __cdecl HIREABLES_CloseHelpUi(); // 0x00494FC0
void __fastcall WARDENCLIENT_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg); // 0x00496BE0
int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0
int __cdecl HIREABLES_GetBeltRowCount(); // 0x004979F0
void __cdecl PANEL_DrawDurabilityIcons(); // 0x00497FE0
void __cdecl PANEL_BeltHotkeyFirst(); // 0x00498C50
void __cdecl PANEL_BeltHotkeySecond(); // 0x00498C90
void __cdecl PANEL_BeltHotkeyThird(); // 0x00498CD0
void __cdecl PANEL_BeltHotkeyFourth(); // 0x00498D10
void __cdecl PANEL_SetBlackColour(); // 0x00499E30
void __cdecl PARTY_FreeRosterUnits(); // 0x0049A020
void __cdecl PARTY_RebuildRosterUnits(); // 0x0049A640
int __stdcall TEXT_IsMouseInRect(int nX, int nY, int nWidth, int nHeight); // 0x0049AA50
int __fastcall TEXT_GetCenteredStringX(unsigned short nStringIndex, int nCenterX); // 0x0049AAA0
void __cdecl sub_0049C6C0_SendWaypointClose(); // 0x0049C6C0
void __fastcall TEXT_SaveTextDisplaySetting(unsigned long nValue); // 0x0049D570
void __fastcall TEXT_DrawTextList(D2TextBoxStrc* pTextBox, int nX, int nY); // 0x0049D8E0
void __fastcall TEXT_AddToHistory(D2TextNodeStrc* pSource); // 0x0049DBC0
void __cdecl TEXT_DrawMessageList(); // 0x0049DC40
void __cdecl TEXT_FreeMainTextBox(); // 0x0049E300
void __fastcall TEXT_HandleChatPacket(D2GSPacketSrv26* pPacket); // 0x0049F490
void __cdecl TEXT_DrawPanelFrame(); // 0x0049FA10
void __cdecl TEXT_FreeTextPanelCels(); // 0x0049FE10
void __fastcall GAME_SetResolution(int nResolution); // 0x0044BA20
int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
void __fastcall GAME_SetAlwaysRun(int bAlwaysRun); // 0x0044BE80
void __fastcall GAME_SetSkillDelayUntil(int nValue); // 0x0044CE40
int __fastcall GAME_IsTimerRunning(D2LoadingTimerStrc* pTimer); // 0x0044E040
int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __fastcall UI_DrawLoadingScreen(int bAdvanceFrame); // 0x004565E0
void __fastcall AUTOMAP_ResetBaseOffset(int bForce); // 0x00457640
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nSize); // 0x0045C850
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall CUNIT_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY); // 0x00463EE0
void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner); // 0x00466CB0
void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
void __stdcall CURSOR_HandleButtonDown(SMSGHANDLER_PARAMS* pMsg); // 0x00467F20
int __fastcall MONSTERUNIQUE_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
void __stdcall GFX_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int nColor, int bFront, int nX, int nY, int bLift); // 0x0046E300
void __fastcall GFX_LoadGlobalHashedFile(unsigned char nIndex); // 0x0046F310
void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nIndex); // 0x0046FA80
void __fastcall GFX_PreloadTick(int bAsync); // 0x00470350
void __fastcall SCMD_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int bLevelLight); // 0x00474550
unsigned char* __fastcall PALSHIFT_GetPalShift(D2UnitStrc* pUnit); // 0x00477530
void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0
void __fastcall MSG_SendFourDwords(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700
int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny); // 0x00478F20
int __fastcall ROSTERPETS_FindRosterIndex(int nUnitId); // 0x00479150
void __fastcall ROSTER_SetPortalIds(int nUnitId, int nA, int nB); // 0x0047A270
void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200
int __fastcall WARDENCLIENT_InitWarden(int nValue); // 0x004803C0
int __fastcall UNITMODE_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY); // 0x004804A0
void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0
int __fastcall UNITMODE_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitId); // 0x00480780
void __fastcall UNITMODE_SetModeOverlay(D2UnitStrc* pUnit, int nMode); // 0x00480D20
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nMode); // 0x00480E70
D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void* __fastcall GAME_LoadUiCelFile(const char* szFile); // 0x004520C0
int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int)); // 0x00451BB0
void __cdecl TEXT_ResetTextBox(); // 0x0049F960
void __fastcall GAME_SetInteractDeadline(int nValue); // 0x0044DAD0
void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue); // 0x0046F020
int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0
int __cdecl CURSOR_GetCursorItem(); // 0x004680A0
int __cdecl AUTOMAP_GetAutomapFade(); // 0x004576C0
D2RosterInfoStrc** __fastcall ROSTER_GetRosterInfoList(int nUnitId); // 0x0047A310
void __cdecl GAME_SetClickHandled(); // 0x0044BEF0
int __fastcall GAME_DispatchMcpPacket(const unsigned char* pPacket, unsigned int nSize); // 0x0044B190
int __cdecl GAME_GetSkillDelayUntil(); // 0x0044CE50
void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB); // 0x00469D70
void __fastcall VIEW_UnitRequest25A(D2UnitStrc* pUnit); // 0x0046B3C0
void __fastcall VIEW_SpawnMissileAtObject(D2UnitStrc* pUnit); // 0x0046B530
void __fastcall VIEW_SpawnBrDeathControl(D2UnitStrc* pUnit); // 0x0046B680
void __fastcall VIEW_SpawnMephistoDeath(D2UnitStrc* pUnit); // 0x0046B9A0
void __fastcall VIEW_SpawnAndarielDeath(D2UnitStrc* pUnit); // 0x0046BA50
void __fastcall VIEW_PlayerRequestAtUnit15B(D2UnitStrc* pUnit); // 0x0046BA90
void __fastcall VIEW_PlayerRequestAtUnit161(D2UnitStrc* pUnit); // 0x0046BB10
void __fastcall VIEW_PlayerRequestAtUnit16B(D2UnitStrc* pUnit); // 0x0046BB90
void __fastcall VIEW_SpawnIzualDeath(D2UnitStrc* pUnit); // 0x0046BC10
int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit); // 0x0046BC70
void __fastcall VIEW_RequestAtMonster220(D2UnitStrc* pUnit); // 0x0046BC90
void __fastcall GFX_RemoveOverlays(D2UnitStrc* pUnit); // 0x0046F170
void __fastcall GFX_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY); // 0x004706E0
void __fastcall sub_00472C50_StartLightning(int nArg); // 0x00472C50
void __cdecl VIEW_ClearGlobals(); // 0x00476AF0
int __cdecl DLIGHTMAP_GetRenderMode(); // 0x00477730
int __cdecl UNITMODE_GetPlayerLevelId(); // 0x00481780
int __cdecl SOUNDHDR_GetSongMin(); // 0x004817F0
int __cdecl SOUNDHDR_GetSongMax(); // 0x00481800
int __cdecl sub_00481810(); // 0x00481810
D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
int __cdecl TEXT_CloseMessageLogCallback(); // 0x004A0030
void __cdecl TEXT_CloseTextUnit(); // 0x004A0880
void __fastcall TEXT_DrawUnitHoverText(D2UnitStrc* pUnit); // 0x004A0B30
void __fastcall TEXT_DrawObjectHoverText(D2UnitStrc* pUnit); // 0x004A0D20
void __fastcall WARDENCLIENT_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320
void __fastcall TEXT_ShowTextBox(unsigned short nStringId); // 0x004A1510
int __cdecl TEXT_Forward(); // 0x004A1760
void __cdecl QUESTLOG_UpdateQuestPage(); // 0x004A2300
void __cdecl QUESTLOG_LoadQuestPanelCels(); // 0x004A23D0
int __stdcall QUESTLOG_OpenQuestPanel(int nArg); // 0x004A26B0
int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0
int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY); // 0x004A2970
void __fastcall QUESTLOG_SelectQuestPage(int nCondition); // 0x004A2C30
void __fastcall QUESTLOG_ClearCainFlag(D2UnitStrc* pUnit); // 0x004A2C70
void __fastcall QUESTLOG_ClearNihlathakFlag(D2UnitStrc* pUnit); // 0x004A2C90
void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0
int __fastcall TEXT_TestQuestCondition(int nCondition); // 0x004A4180
int __cdecl TEXT_GetMaxFirstEntry(); // 0x004A44C0
void __fastcall TEXT_ScrollKeyConfigList(int nStep); // 0x004A4500
int __stdcall TEXT_IsAbovePanelLine(int nX); // 0x004A4780
void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset); // 0x004A5D70
int __cdecl TEXT_IsMouseOnStatButton(); // 0x004A65E0
int __cdecl TEXT_IsMouseOnSkillButton(); // 0x004A6690
bool __stdcall TEXT_IsStatButtonHidden(int nArg); // 0x004A6A00
bool __stdcall TEXT_IsSkillButtonHidden(int nArg); // 0x004A6D50
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0
int __fastcall SPELLSEL_FindSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004A9A90
int __fastcall sub_004A9AE0_FindSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004A9AE0
int __fastcall sub_004A9B30_FindSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004A9B30
int __fastcall sub_004A9B80_FindSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004A9B80
void __fastcall SPELLSEL_SelectHotkey(int nSlot); // 0x004AA030
void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0
int __cdecl sub_004AA900_IsStateOrValue(); // 0x004AA900
void __cdecl sub_004AB530_DrawTabCel(); // 0x004AB530
void __fastcall NPCMENU_StateRequests(D2UnitStrc* pUnit); // 0x004ADCE0
void __fastcall MONSTER_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags); // 0x004AE0A0
void __fastcall MONSTER_SetMonsterLight(D2UnitStrc* pUnit); // 0x004AE210
int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit); // 0x004AE380
D2UnitStrc* __cdecl NPCMENU_GetInteractNpc(); // 0x004B1620
int __cdecl sub_004B1D70_FindNpcEntry(); // 0x004B1D70
void __cdecl TEXT_InitNpcMenu(); // 0x004B23E0
void __cdecl NPCMENU_FreeNpcMenu(); // 0x004B24A0
int __cdecl NPCMENU_IsNpcTalkActive(); // 0x004B3470
void __fastcall NPCMENU_EndNpcInteraction(int nValue); // 0x004B3C20
void __cdecl NPCMENU_CloseNpcShop(); // 0x004B3ED0
void __stdcall NPCMENU_OpenNpcPanel(int nStringIndex, int nEntryIndex); // 0x004B5890
void __stdcall NPCMENU_OpenConfirmDialog(int nStringIndex); // 0x004B5AD0
void __cdecl DIALOG_LoadDialogHotkeys(); // 0x004B7C60
void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
int __cdecl DIALOG_GetDialogCount(); // 0x004B85E0
int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0
int __fastcall SOUNDINST_GetValue(int nHandle); // 0x004B9B20
int __cdecl SOUNDINST_IsSpeechPlaying(); // 0x004B9C20
void __fastcall SOUNDINST_RefreshHintsInRangeA(int nGroupA, int nGroupB); // 0x004BA950
void __fastcall SOUNDINST_RefreshHintsInRangeB(int nGroupA, int nGroupB); // 0x004BA9D0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
void __fastcall OBJECT_HandleObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004BD6D0
char __fastcall OBJECT_RunClientFunction(D2UnitStrc* pUnit); // 0x004BDEE0
void __fastcall ITEM_RefreshUnitEquipment(D2UnitStrc* pUnit); // 0x004C1C10
int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall ITEM_ClearUninterruptableState(D2UnitStrc* pItem); // 0x004C2180
void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C51E0
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __fastcall sub_004C53D0_ScaleDownDirection(int* pX, int* pY); // 0x004C53D0
int __fastcall SKILLS_CanThrow(D2UnitStrc* pUnit); // 0x004C54F0
void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
void __fastcall SKILLS_RunStateActiveFuncs(D2UnitStrc* pUnit); // 0x004C72F0
void __fastcall SKILLS_SpawnMissileRing(D2UnitStrc* pUnit, D2MissileStrc* pMissileParams, int nArg1, int nArg2); // 0x004C7480
void __fastcall SKILLS_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent); // 0x004C76D0
int __fastcall SKILLS_ScatterRequestsAroundTarget(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel); // 0x004C7700
int __fastcall SKILLS_IsTargetPosClear(D2UnitStrc* pUnit, int nMissile); // 0x004C7B20
void __fastcall SKILLS_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue); // 0x004C7BE0
int __fastcall SKILLS_CallClientStateEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7); // 0x004C7C40
void __fastcall SKILLSBAR_RotateUnitDirection(D2UnitStrc* pUnit, int nArg, int bForward); // 0x004C9060
void __fastcall SKILLS_EndLoopSoundSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004C9420
int __fastcall SKILLS_GetFirstSkillParam(int nSkillId); // 0x004C9460
void __fastcall SKILLS_EndCharge(D2UnitStrc* pUnit, int nSkillId); // 0x004CA000
int __fastcall UNITSND_GetDirectionRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA4C0
unsigned int __fastcall UNITSND_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500
void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit); // 0x004CB190
void __fastcall UNITSND_UpdateModeSound(D2UnitStrc* pUnit); // 0x004CB460
int __fastcall MISSILE_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile); // 0x004D3630
void __fastcall PLRSKILLS_SkillSeqDoBackward(D2UnitStrc* pUnit, int nArg); // 0x004D85C0
void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __stdcall PARTICLE_FreeGfxMotion(D2UnitStrc* pUnit); // 0x004DA080
int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit); // 0x004DA0F0
int __stdcall GFXUTIL_GetMotionAX(D2UnitStrc* pUnit); // 0x004DA110
int __stdcall GFXUTIL_GetMotionAY(D2UnitStrc* pUnit); // 0x004DA130
int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150
void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0
void __fastcall GFXUTIL_ClearMotionFlagTwo(D2UnitStrc* pMissile); // 0x004DA340
void __fastcall GFXUTIL_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0
void __stdcall GFXUTIL_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690
void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0
int __fastcall GFXUTIL_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY); // 0x004DBF20
void __cdecl GFXUTIL_DrawFadeBox(); // 0x004DC000
void __fastcall CUNITEVENT_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5); // 0x004DC190
unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440
void __fastcall PLAYERLIST_InitGfxData(D2UnitStrc* pUnit); // 0x004DC510
void __fastcall GFXUTIL_ApplySoundEnviron(int nEnvironId); // 0x004DF6C0
int __cdecl sub_004DF870_IsSoundSystemInit(); // 0x004DF870
int __cdecl sub_004DF880_IsSoundSystemInit(); // 0x004DF880
void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004E3050
D2UnitStrc* __fastcall SKILLDESC_CltDoRandomMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004E31C0
void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004E4050
float __stdcall GFXUTIL_VectorLengthSquared(float fX, float fY); // 0x004E4160
D2MonTypeTxt* __fastcall SKILLDESC_GetMonTypeTxtRecord(int nMonType); // 0x004E4640
int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0
int __cdecl SKILLDESC_SumProgressiveBonus(); // 0x004E6FF0
void __stdcall TEXT_DrawHintText(int nArg1, int nStringIndex); // 0x004ED3F0
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900
void __fastcall CUNIT_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg); // 0x00465BF0
D2MissilesTxt* __fastcall sub_0046ACE0_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
int __fastcall TEXT_IsInPanelButton(int nMode, int nX, int nY); // 0x004A6580
void __fastcall MONSTER_UpdateMonsterClient(D2UnitStrc* pUnit); // 0x004B13A0
int __fastcall NPCMENU_GetInteractNpcId(int* pLow); // 0x004B3230
int __fastcall OBJECT_UpdateEnvObject(D2UnitStrc* pUnit, int bNoRefresh); // 0x004BC5E0
void __fastcall OBJECT_UpdateObject(D2UnitStrc* pUnit); // 0x004BDFF0
D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4); // 0x004C5420
int __fastcall SKILLS_ScanCount(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags); // 0x004C5E30
int __fastcall SKILLS_CallStartSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID); // 0x004C6660
int __fastcall SKILLS_RaiseTargetUnitEvent(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004C7630
void __fastcall SKILLS_AttachMoveSkillEndList(D2UnitStrc* pUnit); // 0x004C7950
int __fastcall SKILLS_GetExtendedMeleeRange(D2UnitStrc* pUnit); // 0x004C7BD0
void __fastcall MISSILE_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nOuterStep, int nInnerStep, int nLoops); // 0x004CEFE0
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
int __fastcall GFXUTIL_InitUnitCelContext(D2GfxDataStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50
int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId); // 0x004E0650
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset); // 0x004E2ED0
unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int skillId, int stringIndex); // 0x004E6CE0
void __fastcall SKILLDESC_SetSkillPopUpText(D2UnitStrc* pUnit, int nSkillId, int nArg3, int nArg4, int nArg5, int nX, int nY); // 0x004EF990
int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20
int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110

// D2Client from 0x004A0000 up
int __cdecl TEXT_IsTextBoxOpen(); // 0x004A0000
void __cdecl TEXT_FreeTextLists(); // 0x004A0010
void TEXT_OpenMessageLogDialog(); // 0x004A0050
void __cdecl TEXT_CloseMessageLogDialog(); // 0x004A01A0
void __cdecl TEXT_ToggleListDialogUI(); // 0x004A02F0
void __cdecl TEXT_FreeTextResources(); // 0x004A0680
void __fastcall TEXT_UpdateTexts(D2ViewStrc* pView); // 0x004A0E70
void __cdecl QUESTLOG_FreeQuestCels(); // 0x004A2550
void __cdecl QUESTLOG_FreeQuestPanel(); // 0x004A2600
void __cdecl QUESTLOG_ResetQuestButton(); // 0x004A28D0
void __cdecl QUESTLOG_DrawQuestButton(); // 0x004A2A80
void __fastcall TEXT_HandleQuestEvent(int nArg, D2PacketRecord6Strc* pPacket); // 0x004A2CB0
void __cdecl TEXT_ClearQuestFlags(); // 0x004A3020
void __cdecl QUESTLOG_ResetQuestPages(); // 0x004A3050
void __cdecl QUESTLOG_LoadDurielCofsOnce(); // 0x004A30A0
void __cdecl QUESTLOG_LoadAncientsCofsOnce(); // 0x004A30C0
char __cdecl QUESTLOG_HasQuestPacketValue(); // 0x004A3110
char __cdecl QUESTLOG_IsQuestUnitPresent(); // 0x004A3120
void __fastcall QUESTLOG_SpawnQuestUnits(int nX, int nY); // 0x004A3150
void __stdcall TEXT_LoadQuestPage(int nPage, int bReset); // 0x004A3220
void __cdecl TEXT_ResetQuestPanel(); // 0x004A3410
void __cdecl QUESTLOG_DrawQuestPage(); // 0x004A34F0
void __cdecl TEXT_InitKeyConfigEntries(); // 0x004A43E0
void __fastcall TEXT_MoveKeyConfigSelection(int nStep); // 0x004A45C0
void __cdecl TEXT_InitTextSlider(); // 0x004A5190
void __cdecl TEXT_FreeTextSliderCel(); // 0x004A51E0
void __fastcall TEXT_ToggleKeyConfigPanel(int nArg); // 0x004A5200
void __cdecl TEXT_DrawKeyConfigPanel(); // 0x004A5270
void __cdecl TEXT_CloseKeyCaptureHandlers(); // 0x004A5DE0
void __cdecl TEXT_LoadLevelCels(); // 0x004A6460
void __cdecl TEXT_FreeLevelCels(); // 0x004A6480
void __cdecl TEXT_UpdateLevelUpButtons(); // 0x004A64C0
void __cdecl TEXT_DrawLeftPanelButton(); // 0x004A6A70
void __cdecl TEXT_DrawStatButton(); // 0x004A6B30
void __cdecl TEXT_DrawRightPanelButton(); // 0x004A6DA0
void __cdecl TEXT_DrawSkillButton(); // 0x004A6E60
void __cdecl TEXT_SetGoldDialogFlag(); // 0x004A7A90
void __cdecl TEXT_InitTextEntryLengths(); // 0x004A7AA0
void __cdecl sub_004A7AD0_Nop(); // 0x004A7AD0
void __cdecl TEXT_DrawCharStats(); // 0x004A7D00
void __cdecl SPELLSEL_InitSkillIcons(); // 0x004A8A30
void __cdecl SPELLSEL_FreeSkillIcons(); // 0x004A8C00
void __fastcall SPELLSEL_SetSkillSelectRight(int nValue); // 0x004A8CE0
int __fastcall SPELLSEL_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004A8D30
void __fastcall SPELLSEL_UpdateSkillButtonHover(short* pId, int nState, int nA, int nB, int nX, int nY); // 0x004A8D50
void __cdecl SPELLSEL_UpdateSkillIcons(); // 0x004A9DF0
void __fastcall SPELLSEL_AssignHotkey(int nHotkey); // 0x004A9E60
void __fastcall SPELLSEL_SetHotkeySkillSlot(int nSlot, int nValueA, int nValueB, int nValueC); // 0x004AA0C0
void __fastcall SPELLSEL_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0
void __fastcall SPELLSEL_CycleHotkey(int nDelta); // 0x004AA740
void __cdecl SPELLSEL_ResetSkillIcons(); // 0x004AA7E0
void __cdecl sub_004AA920_LoadPanelCel(); // 0x004AA920
void __cdecl sub_004AA980_FreePanelCel(); // 0x004AA980
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage); // 0x004AAAE0
void __cdecl sub_004ABF10_ClearSkillStates(); // 0x004ABF10
void __cdecl sub_004AC690_DrawSkillPanel(); // 0x004AC690
unsigned char* __fastcall MONUNIQUE_GetMonUmods(D2UnitStrc* pUnit); // 0x004AC740
short __fastcall MONUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x004AC7C0
void __stdcall MONSTER_RunUModCallbacks(D2UnitStrc* pUnit, void* pArgument, int nMode); // 0x004ADD90
void __fastcall MONSTER_RunUModCommandCallbacks(D2UnitStrc* pUnit); // 0x004ADE40
void __fastcall MONSTER_RunUModUpdateCallbacks(D2UnitStrc* pUnit); // 0x004ADE50
void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit); // 0x004ADE60
void __fastcall MONSTER_RunUModHitCallbacks(D2UnitStrc* pUnit); // 0x004ADE70
void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, void* pArg); // 0x004ADE80
int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360
void __fastcall MONSTER_FreeClientUnit(D2UnitStrc* pUnit); // 0x004AED30
void __fastcall MONSTER_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo); // 0x004B1090
void __fastcall MONSTER_SetMinionSpawnClass(D2ClientPacket7Strc* pPacket); // 0x004B1240
void __stdcall NPCMENU_PickNpcChoice(D2NpcEntryStrc* pEntry); // 0x004B1680
int __cdecl sub_004B1DC0_Return0(); // 0x004B1DC0
void __cdecl NPCMENU_ResetSlots(); // 0x004B3290
void __cdecl NPCMENU_ResetNpcMenu(); // 0x004B32F0
void __fastcall NPCMENU_ReloadHirelingPopup(unsigned short nArg); // 0x004B3340
void __fastcall NPCMENU_OnNpcWantsInteract(D2PacketRecord6Strc* pPacket); // 0x004B3380
int __cdecl NPCMENU_IsAnyDialogOpen(); // 0x004B34A0
int __cdecl NPCMENU_IsGambleShop(); // 0x004B3500
int __cdecl NPCMENU_HireMercHandler(); // 0x004B3660
void __fastcall NPCMENU_RefreshNpcEntries(D2UnitStrc* pUnit); // 0x004B3E10
void __cdecl NPCMENU_CloseByState(); // 0x004B3F10
void __cdecl NPCMENU_UpdateNpcInteract(); // 0x004B4380
void __cdecl NPCMENU_BuildNpcMenu(); // 0x004B4830
void __fastcall NPCMENU_OnUnitRemoved(unsigned char nUnitType, int nUnitId); // 0x004B5320
int __cdecl sub_004B5BC0_SelectNpcEntry(); // 0x004B5BC0
int __cdecl NPCMENU_CloseHireDialog(); // 0x004B5C20
int __cdecl NPCMENU_ShowMainMenu(); // 0x004B5C60
void __fastcall NPCMENU_SetNpcMenuState(unsigned short wValue, int nValue); // 0x004B6980
void __cdecl NPCMENU_CloseTrade(); // 0x004B69E0
void __fastcall NPCMENU_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg); // 0x004B6DD0
void __cdecl DIALOG_InitDialogs(); // 0x004B7B40
void __cdecl DIALOG_FreeDialogs(); // 0x004B7B50
void __cdecl MONSTER_ResetTradeState(); // 0x004B8720
void __cdecl MONSTER_DrawDialogHover(); // 0x004B8730
void __cdecl MONSTER_ClearTradeGold(); // 0x004B8920
void __fastcall MONSTER_CloseWait(int bReopen); // 0x004B8940
int __cdecl CUNIT_IsTrading(); // 0x004B8A10
void __cdecl sub_004B8CB0_BeginTradeWait(); // 0x004B8CB0
void __fastcall MONSTER_SendGoldRequest(unsigned long nGold); // 0x004B9110
void __cdecl sub_004B91F0_CloseWait(); // 0x004B91F0
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket); // 0x004B92B0
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket); // 0x004B9320
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax); // 0x004B93A0
void __fastcall SOUNDINST_SetValue(int nKey, int nValue); // 0x004B9B50
int __cdecl SOUNDINST_IsSongPlaying(); // 0x004B9C60
void __cdecl SOUNDINST_FreeAllSounds(); // 0x004B9D20
void __fastcall SOUNDINST_UpdateSounds(unsigned int nTick); // 0x004BA020
void __fastcall SOUNDINST_LockSoundsById(int nHintId); // 0x004BA890
void __cdecl SOUNDINST_ToggleHints(); // 0x004BABC0
void __fastcall OBJECT_UpdateObjectOverlay(D2UnitStrc* pUnit); // 0x004BC8D0
void __fastcall OBJECT_ReleaseObjectUnit(D2UnitStrc* pUnit); // 0x004BCA50
void __fastcall OBJECT_SetObjectOwnerName(D2UnitStrc* pUnit, const char* szName); // 0x004BDFE0
void __cdecl TEXT_LoadTextSliderCel(); // 0x004BE020
void __cdecl sub_004BE060_FreeSliderCel(); // 0x004BE060
void __cdecl USEITEM_InitUseItemPanel(); // 0x004BF9D0
void __cdecl USEITEM_FreeUseItemPanel(); // 0x004C0100
void __cdecl USEITEM_DrawPanelUnit(); // 0x004C01E0
int __cdecl sub_004C0440_Thunk(); // 0x004C0440
void __fastcall USEITEM_HandleUseItemPacket(D2PacketRecord7Strc* pPacket); // 0x004C0550
void __fastcall USEITEM_OpenNpcItemPanel(int nValue); // 0x004C0620
void __cdecl SHOWITEMS_DrawUnitNames(); // 0x004C0810
void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
void __fastcall ITEM_ReleaseItemUnit(D2UnitStrc* pUnit); // 0x004C1A70
void __fastcall ITEM_UpdateItemAnim(D2UnitStrc* pUnit); // 0x004C1AD0
void __fastcall ITEM_HandleItemCommand(int nEvent, D2UnitStrc* pUnit, int bSet, int nMode); // 0x004C1B80
void __fastcall ITEM_RefreshUnitItemsFromPacket(D2PacketRecord11Strc* pPacket, int nArg); // 0x004C1BC0
void __fastcall ITEM_RefreshUnitItemsFromRecord(D2PacketRecord11Strc* pPacket); // 0x004C1BF0
int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20
void __cdecl ITEM_ResetWeaponClasses(); // 0x004C1E30
void __fastcall ITEM_UpdateItemStat(unsigned int nA, unsigned char nB, unsigned int nC, unsigned int nD, unsigned short nE); // 0x004C1F30
void __fastcall ITEM_SetItemFlagFromPacket(D2PacketRecord13Strc* pPacket); // 0x004C2020
void __fastcall ITEM_ClearCursorItemFromPacket(D2GSPacketSrv42Strc* pPacket); // 0x004C2050
void __fastcall ITEM_HandleItemToCursor(D2GSPacketSrv9C* pPacket); // 0x004C20B0
void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pUnit); // 0x004C21F0
int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pUnit); // 0x004C2240
void __fastcall ITEM_HandleItemStatePacket(D2GSPacketSrv7DStrc* pPacket); // 0x004C2270
void __fastcall ITEM_HandleOwnedItemToCursor(D2GSPacketSrv9D* pPacket); // 0x004C2340
void __fastcall ITEM_RemoveEquippedItems(D2UnitStrc* pUnit); // 0x004C23E0
void __fastcall ITEM_HandleGroundToCursor(D2GSPacketSrv9C* pPacket); // 0x004C2650
void __fastcall ITEM_HandleDropToGround(D2GSPacketSrv9C* pPacket); // 0x004C26F0
void __fastcall ITEM_HandleItemOnGround(D2GSPacketSrv9C* pPacket); // 0x004C2810
void __fastcall ITEM_HandleItemToStorage(D2GSPacketSrv9C* pPacket); // 0x004C2AD0
void __fastcall ITEM_HandleItemFromStorage(D2GSPacketSrv9D* pPacket); // 0x004C2C80
void __fastcall ITEM_HandleEquipItem(D2GSPacketSrv9D* pPacket); // 0x004C2E90
void __fastcall ITEM_HandleIndirectSwapBodyItem(D2GSPacketSrv9D* pPacket); // 0x004C3070
void __fastcall ITEM_HandleUnequipItem(D2GSPacketSrv9D* pPacket); // 0x004C3380
void __fastcall ITEM_HandleSwapBodyItem(D2GSPacketSrv9D* pPacket); // 0x004C3920
void __fastcall ITEM_HandleWeaponSwitch(D2GSPacketSrv9D* pPacket); // 0x004C3B00
void __fastcall ITEM_UpdateItemFromPacket(D2GSPacketSrv9C* pPacket); // 0x004C3B30
void __fastcall ITEM_HandleShopItem(D2GSPacketSrv9C* pPacket); // 0x004C3C00
void __fastcall ITEM_HandleCursorBeltSwap(D2GSPacketSrv9C* pPacket); // 0x004C40D0
void __fastcall ITEM_HandlePutInBelt(D2GSPacketSrv9C* pPacket); // 0x004C4130
void __fastcall ITEM_HandleRemoveFromBelt(D2GSPacketSrv9C* pPacket); // 0x004C42A0
void __fastcall ITEM_HandleBeltSwap(D2GSPacketSrv9C* pPacket); // 0x004C45C0
void __fastcall ITEM_HandleUseStackableItem(D2PacketRecord8Strc* pPacket); // 0x004C4620
void __fastcall ITEM_HandleAutoUnequip(D2GSPacketSrv9D* pPacket); // 0x004C4740
void __fastcall ITEM_HandleItemToSocket(D2GSPacketSrv9D* pPacket); // 0x004C4990
void __fastcall ITEM_HandleGridItemToBody(D2GSPacketSrv9D* pPacket); // 0x004C4AA0
D2UnitStrc* __fastcall ITEM_HandleBodyGridSwap(D2GSPacketSrv9D* pPacket); // 0x004C4C70
int __fastcall SKILLS_DoClientSkill(D2UnitStrc* unit,int skillId,int skillLevel,int mode); // 0x004C6680
void __fastcall SKILLS_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode); // 0x004C6930
void __fastcall SKILLS_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nCharges); // 0x004C6AC0
void __fastcall SKILLS_CreateSpiralMissiles(int nCount, D2MissileStrc* pMissileParams); // 0x004C71F0
void __fastcall SKILLS_ApplySkillLevelBonus(D2UnitStrc* pUnit, int nA, int nB, unsigned char nC); // 0x004C7990
void __fastcall SKILLSBAR_ResetLeapCollision(D2UnitStrc* pUnit); // 0x004C8B80
int __fastcall MISSILE_SkillStartAtTargetPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C95E0
int __fastcall SKILLS_CreateMissileAtTarget(D2UnitStrc* pUnit,int nSkillId,int nSkillLevel); // 0x004C96D0
int __fastcall SKILLS_FindEventFrame(D2UnitStrc* pUnit); // 0x004C9D70
int __fastcall SKILLS_CltDoCharge(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C9DB0
int __fastcall SKILLS_TickEvent(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004CA030
int __fastcall SKILLS_TriggerSkillOnUnit(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5); // 0x004CA200
int __fastcall SKILLS_DoSkillAtPosition(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x004CA230
void __cdecl SKILLS_ResetLevelSpeech(); // 0x004CA280
void* __fastcall UNITSND_GetLinkFirst(D2UnitStrc* pUnit); // 0x004CA990
void __fastcall UNITSND_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce); // 0x004CA9C0
void __fastcall UNITSND_PlayAttackSound(D2UnitStrc* pUnit, int nMode, int bDelay); // 0x004CB6A0
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
void __fastcall UNITSND_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0
void __cdecl UNITSND_CheckLevelSpeech(); // 0x004CC270
void __fastcall UNITSND_PlayInitSound(D2UnitStrc* pUnit); // 0x004CC380
void __fastcall UNITSND_UpdateUnitSound(D2UnitStrc* pUnit, int nMode, int bModeGiven); // 0x004CC5B0
void __fastcall MISSILE_SetMissileLights(int nValue); // 0x004CCF20
int __cdecl MISSILE_GetMissileLights(); // 0x004CCF30
void __fastcall MISSILE_FreeMissileUnit(D2UnitStrc* pMissile); // 0x004CD170
void __fastcall MISSILE_CltDoMissile(D2UnitStrc* pMissile); // 0x004D2C70
void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile); // 0x004D66E0
void __fastcall PLRSKILLS_SkillSeqDoForward(D2UnitStrc* pUnit, int nArg); // 0x004D8520
void __fastcall PLRSKILLS_CallSkillSeqDoForward(D2UnitStrc* pUnit, int nArg); // 0x004D85B0
void __fastcall PLRSKILLS_CallSkillSeqDoBackward(D2UnitStrc* pUnit, int nArg); // 0x004D8650
void __fastcall PLRSKILLS_BeginState(D2UnitStrc* pUnit, int nState); // 0x004D9B20
void __fastcall PLRSKILLS_EndState(D2UnitStrc* pUnit, int nState); // 0x004D9C30
void __fastcall PLRSKILLS_StartClientState(D2UnitStrc* pUnit, int nState); // 0x004D9E60
void __fastcall PLRSKILLS_EndClientState(D2UnitStrc* pUnit, int nState); // 0x004D9F40
int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit); // 0x004DA0D0
int __stdcall GFXUTIL_GetMotionRawAZ(D2UnitStrc* pUnit); // 0x004DA1B0
void __stdcall GFXUTIL_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1); // 0x004DA2F0
int __stdcall GFXUTIL_GetMotionFirstParam(D2UnitStrc* pUnit); // 0x004DA320
void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350
void __stdcall GFXUTIL_SetMotionFlag1(D2UnitStrc* pUnit); // 0x004DA640
int __stdcall GFXUTIL_TestMotionFlags(D2UnitStrc* pUnit); // 0x004DA6B0
void __cdecl GFXUTIL_InitModeTokens(); // 0x004DA790
int __fastcall GFXUTIL_UnitSupportsMode(D2UnitStrc* pUnit, int nMode); // 0x004DAE60
int __fastcall GFXUTIL_GetCofLayerShadow(void* pCof, int nComponent); // 0x004DB090
int __fastcall GFXUTIL_IsPlayerMonsterOrObject(D2UnitStrc* pUnit); // 0x004DB180
unsigned char __fastcall GFXUTIL_GetGfxEntryByte(D2UnitStrc* pUnit, int nIndex); // 0x004DB1A0
int __fastcall GFXUTIL_UpdateUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x004DB670
void __cdecl GFXUTIL_StartFadeTimer(); // 0x004DBFE0
void __cdecl GFXUTIL_ClearFadeTimer(); // 0x004DC0A0
void __fastcall CUNITEVENT_FreeCltUnitEvents(D2UnitStrc* pUnit); // 0x004DC0C0
D2RosterInfoStrc** __cdecl PLAYERLIST_AllocRosterInfoList(); // 0x004DC270
void __fastcall PLAYERLIST_AddRosterInfo(int nUnitId1, int nUnitId2); // 0x004DC320
void __fastcall GFXUTIL_SetRelationFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet); // 0x004DC3E0
void __fastcall GFXUTIL_SetRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC4C0
void __fastcall sub_004DCAA0_UpdateLevelSong(unsigned int dwTick); // 0x004DCAA0
void __fastcall WALL2_FreeViewCells(D2ViewStrc* pView); // 0x004DCF30
void __fastcall DFLOOR_UpdateFloorView(D2ViewStrc* pView); // 0x004DEA70
void __fastcall WALL2_UpdateView(void* pArg); // 0x004DED10
void __cdecl WALL2_UpdateRoomColor(); // 0x004DED20
void __fastcall sub_004DF480_UpdateAllTileLights(D2TileLightCtxStrc* pCtx); // 0x004DF480
void __cdecl sub_004DF800_StopAllSlots(); // 0x004DF800
void __cdecl sub_004DF890_ReleaseFinishedSlots(); // 0x004DF890
int __cdecl sub_004DF940_IsPositionalSoundEnabled(); // 0x004DF940
int __cdecl sub_004DF960_IsEaxEnabled(); // 0x004DF960
int __cdecl sub_004DF9B0_IsSoundMode2(); // 0x004DF9B0
void __fastcall sub_004E0050_RestartSound(int nArg); // 0x004E0050
void __cdecl sub_004E00C0_CloseSoundChannels(); // 0x004E00C0
int __cdecl sub_004E00D0_ToggleSoundMode01(); // 0x004E00D0
int __cdecl sub_004E0140_ToggleSoundMode12(); // 0x004E0140
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType); // 0x004E0590
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue); // 0x004E0690
int __fastcall PLRSKILLS_FireAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004E1B10
void __fastcall sub_004E1C80_CltMissileInitDiabWall(D2UnitStrc* pMissile, int nInitSeed); // 0x004E1C80
void __fastcall sub_004E3170_SetMissileFrames(D2UnitStrc* pMissile, int nDivisor); // 0x004E3170
void __fastcall sub_004E4020_Nop(D2UnitStrc* pUnit); // 0x004E4020
float __stdcall GFXUTIL_VectorLength(float fX, float fY); // 0x004E4130
void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int dwTick); // 0x004E42E0
int __stdcall SKILLDESC_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame); // 0x004E4CE0
int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0
void __fastcall SKILLDESC_DrawWeaponPhysElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EAD60
void __fastcall SKILLDESC_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot); // 0x004ED570
void __fastcall SKILLDESC_RefreshSkills(D2UnitStrc* pUnit); // 0x004EDA20
int __fastcall SKILLDESC_CallSkillDescFunc(D2UnitStrc* pUnit, int bLeft); // 0x004EDA80
void __fastcall SKILLDESC_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY); // 0x004EEF00
void __fastcall SKILLDESC_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY); // 0x004EF410
int __fastcall sub_004F0650_CltSkillMissileFan(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004F0650
int __fastcall SKILLDESC_IsVineBeastMissile(D2UnitStrc* unit, void* unused); // 0x004F0F10
int __fastcall SKILLDESC_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nArg0, int nArg3, int nArg4, int nMissileArg, int bFirst, int bClearPathFlag); // 0x004F16F0
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __fastcall SKILLSMON_StartStateList(D2UnitStrc* pUnit, int nSkillId, int nArg); // 0x004F2450
void __fastcall SKILLDESC_MissileScatter(D2UnitStrc* pUnit, int nSeed, int nMissile, int nX, int nY, int nRadius, int nSkillId, int nSkillLevel); // 0x004F28A0
void __fastcall SKILLDESC_MissileInit(D2UnitStrc* pMissile, int nSeed); // 0x004F2AC0
void __fastcall SKILLDESC_InitCurvingMissilePath(D2UnitStrc* pMissile, int nInitSeed); // 0x004F2BE0
int __fastcall SKILLDESC_CreateCorpseExplosionMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nMonsterId); // 0x004F3A60
int __fastcall SKILLDESC_GetMonSkillSound(D2UnitStrc* pUnit, int nSkillId); // 0x004F4F40

// D2Client globals that several of the module's files use, declared once here.
class ListBoxWrapper;
extern int gnScreenWidth; // 0x0071146C
extern int gbPositionalSound; // 0x007A061C
extern D2DrlgActStrc* gpAct; // 0x007A0634
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth; // 0x007A5220
extern int gnGlobal_007BCAF0; // 0x007BCAF0
extern int gnInvPanelMode; // 0x007BCBF0
extern int gdwNpcPanelDelayTick; // 0x007BCC08
extern int gnSelectedShopButton; // 0x007BCC40
extern int gbRosterButtonDown; // 0x007BF030
extern D2WaypointMenuEntryStrc gaWaypointEntries[9]; // 0x007BF03C
extern char gbSent; // 0x007BF085
extern D2RectStrc gaHoverRects[16]; // 0x007BF0A8
extern D2ClientDialogStrc* gpListDialog; // 0x007BF1B0
extern ListBoxWrapper* gpListBox; // 0x007BF1B4
extern int gbTextBoxDone; // 0x007BF1BC
extern int gnTextActive; // 0x007BF1C0
extern int gbTextBoxShown; // 0x007BF1C8
extern unsigned short gwTextStringId; // 0x007BF212
extern D2ClientTextDataStrc* gpTextData; // 0x007BF228
extern unsigned long gnStartTick; // 0x007BF22C
extern int gbTextSound; // 0x007BF230
extern unsigned char gbTextHoverSet; // 0x007BF23A
extern int gbTextDataOpen; // 0x007BF254
extern void* gpTextCallbackContext; // 0x007BF25C
extern int gnHintId; // 0x007BF260
extern int gnTextLeft; // 0x007BF278
extern int gaQuestPageDefault[5]; // 0x007BF280
extern int gnKeyConfigThumbScale; // 0x007C0278
extern int gaPressed[7]; // 0x007C0288
extern int gbKeyCaptureActive; // 0x007C02B8
extern void* gpLevelCel; // 0x007C02DC
extern void* gpLevelSocketCel; // 0x007C02E0
extern int gbSkillButtonPressed; // 0x007C02E8
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8
extern int gbGambleShop; // 0x007C0DB0
extern int gbWaitSoundPlayed; // 0x007C0DBC
extern int gbWaitSoundScheduled; // 0x007C0DC0
extern void* gpBuySellCel; // 0x007C0DC8
extern void* gpGoldBtnCel; // 0x007C0DCC
extern D2UnitStrc* gpNpcPlayerUnit; // 0x007C0DD4
extern int gaLevelVisited[]; // 0x007C78B8
extern int gnNeutralTick; // 0x007C88B8
extern int gnSfxTick; // 0x007C88BC
extern int gnNeutralDelay; // 0x007C88C0
extern int gnLastRequestTick; // 0x007C88C4
extern int gnLastRequestSound; // 0x007C88C8
extern unsigned int gdwFadeTick; // 0x007C89CC
