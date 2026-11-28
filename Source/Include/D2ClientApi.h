#pragma once
// D2Client's exports that the other modules call; included only by the units that use it.

struct D2ActiveRoomStrc;
struct D2AutomapLayerStrc;
struct D2ByteRecordStrc;
struct D2CharStatsTxt;
struct D2CmdParamsStrc;
struct D2ConfigStrc;
struct D2ItemStatCostTxt;
struct D2MissileStrc;
struct D2MissilesTxt;
struct D2MonStats2Txt;
struct D2MonStatsTxt;
struct D2R01LightStrc;
struct D2RosterInfoStrc;
union D2SeedStrc;
struct D2SetItemsTxt;
struct D2SetsTxt;
struct D2SkillDescTxt;
struct D2SkillsTxt;
struct D2StatesTxt;
struct D2TextHeaderStrc;
struct D2UniqueItemsTxt;
struct D2UnitDropItemsPacketStrc;
struct D2UnitStrc;

unsigned __int64 __cdecl AUTOMAP_ReadTimeStampCounter(); // 0x0040E850
void __cdecl AUTOMAP_ReleaseFreeBlocks(); // 0x00412000
int __cdecl sub_0042F6D0_GetMenusDone(); // 0x0042F6D0
int __cdecl GAME_GetStopMainLoop(); // 0x0042FA30
int __cdecl GAME_IsLaunchExpansion(); // 0x0043DB10
void __fastcall GAME_CalcCdKeyChecksum(char* szKey, unsigned int* pChecksum); // 0x00449890
int __fastcall WINMAIN_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue); // 0x00449920
int __cdecl WINMAIN_PopStateValue(); // 0x0044B480
int __stdcall WINMAIN_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused); // 0x0044B4E0
int __stdcall WINMAIN_HandleExtraArgument(int nArg); // 0x0044B5C0
int __stdcall WINMAIN_HandleArgumentError(int nArg); // 0x0044B5D0
int __stdcall WINMAIN_SetLaunchMode(const D2CmdParamsStrc* pParams, int nUnused); // 0x0044B600
int __stdcall WINMAIN_LauncherRun(void* hInstance, D2ConfigStrc* pRecord); // 0x0044B8A0
int __stdcall WINMAIN_PollSystemPackets(int nUnused); // 0x0044BAD0
extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80
int __stdcall WINMAIN_PumpSystemPackets(int nUnused); // 0x0044BD20
int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0
int __cdecl sub_0044DA90_GetTickCounter(); // 0x0044DA90
void __fastcall GAME_ShowLoadingMessage(int nIndex); // 0x0044E380
void __cdecl RECORD_AddRecordChunk(); // 0x00451400
void __fastcall RECORD_RecordInputMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x004514B0
void __cdecl RECORD_WriteRecordFile(); // 0x00451620
void __cdecl RECORD_LoadRecordFile(); // 0x00451710
void __cdecl RECORD_StartPlayback(); // 0x004518E0
void __stdcall RECORD_RecordHandler(int nArg1, int nArg2, int nArg3); // 0x00451920
int __cdecl RECORD_IsReplayActive(); // 0x00451990
void __cdecl RECORD_ToggleRecordPlayback(); // 0x004519A0
int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId); // 0x00452040
void __cdecl UI_DrawProgressiveStates(); // 0x00453470
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall UI_DrawLoadingScreen(int bAdvanceFrame); // 0x004565E0
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
void __cdecl AUTOMAP_SaveAutomapLayer(); // 0x004584C0
void __cdecl AUTOMAP_ResetAutomapCells(); // 0x00458680
void __cdecl AUTOMAP_LoadAutomapLayer(); // 0x00458750
void __stdcall AUTOMAP_SetAutomapContext(D2AutomapLayerStrc* pContext); // 0x00458CD0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2ItemStatCostTxt* __fastcall PLAYER_GetItemStatCostTxtRecord(int nStatId); // 0x0045C4F0
void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nSize); // 0x0045C850
void __fastcall SCMD_ProcessPackets(unsigned char* pData, int nSize); // 0x0045F7B0
unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0
void __fastcall SCMD_DropUnitItems(D2UnitDropItemsPacketStrc* pPacket); // 0x00462F60
int __fastcall ITEMS_CheckUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y); // 0x00463740
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
D2MissilesTxt* __fastcall sub_0046ACE0_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
void __fastcall GFX_DrawProgressiveStateOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY); // 0x0046E1B0
void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nIndex); // 0x0046F280
void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210
int __fastcall sub_00472280_RollInRange(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __fastcall SCMD_SetLightColorBytes(D2ByteRecordStrc* pRecord, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390
void __fastcall DLIGHTMAP_ReleaseLight(D2R01LightStrc* pLight); // 0x004743D0
void __cdecl DLIGHTMAP_ScanGridCollision(); // 0x004756D0
void __fastcall MSG_ShowProgressSteps(int nDone, int nTotal); // 0x00478160
void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nMode); // 0x00480E70
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0
D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId); // 0x00483410
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex); // 0x00483440
D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470
void __cdecl TEXT_ResetTextBox(); // 0x0049F960
extern "C" void __cdecl QUESTLOG_ResetQuestButtonState(); // 0x004A3000
extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value); // 0x004A3100
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0
int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0
int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020
extern "C" void __cdecl SOUNDINST_ResetSoundState(); // 0x004B9D00
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nAltMissile, int nSkill, int nSkillLevel, int nVelocity); // 0x004C70D0
int __fastcall SKILLS_GetFirstSkillParam(int nSkillId); // 0x004C9460
int __fastcall MISSILE_GetSkillMissileRange(int nSkillId, int nLevel); // 0x004CC7C0
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
D2RosterInfoStrc* __fastcall GFXUTIL_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo); // 0x004DC0B0
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset); // 0x004E2ED0
extern "C" void __cdecl sub_004E4280_ResetEnvironSounds(); // 0x004E4280
int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId); // 0x004E6C50
int __fastcall SKILLDESC_GetSkillParamFive(int nSkillId); // 0x004E6C70
int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0
int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20
int __fastcall SKILLDESC_GetSkillParamThree(int nSkillId); // 0x004EFC50
int __fastcall SKILLDESC_GetSkillParamFour(int nSkillId); // 0x004EFC80
int __fastcall SKILLDESC_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110
void __cdecl sub_006CB400_Nop(); // 0x006CB400
extern int gabFreeBlockDirty[0x100]; // 0x007784C8
extern int gbMcpPacket0FReceived; // 0x00798F5C
extern int gbMcpCreateQueued; // 0x00798F7C
extern unsigned short gwMcpReplyRequestId; // 0x00798F80
extern int gbMcpServerAddressReceived; // 0x00798F84
extern void* gpMcpConnection; // 0x00798FB4
extern int gbMcpPacket0BReceived; // 0x00799100
extern int gnMcpCreateQueuePosition; // 0x00799104
extern char gabMcpReply[4]; // 0x00799108
extern int gbMcpCharDeleteReceived; // 0x00799298
extern int gbMcpPacket0CReceived; // 0x007992A0
extern int gbMcpPacket0DReceived; // 0x007992A8
extern int gbMcpCharLogonReceived; // 0x007992E0
extern int gbMcpCharCreateReceived; // 0x007992E8
extern int gbMcpCharUpgradeReceived; // 0x007992F0
extern char gszClientCharName[16]; // 0x007A05C4
extern int gnRecordPos; // 0x007A2784
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern D2UnitStrc* gapAiTargets[8]; // 0x007A7470
extern int gnProgress; // 0x007BB3B4
extern int gdwGlobal_007BC974; // 0x007BC974
extern int gbHoverInGrid; // 0x007BCBE4
extern int gnInvPanelMode; // 0x007BCBF0
extern D2UnitStrc* gpHoverItem; // 0x007BCBF4
extern int gbGoldButtonDisabled; // 0x007BCE2C
extern unsigned char gnLifeColorHigh; // 0x007BEED0
extern unsigned char gnLifeColorMid; // 0x007BEED1
extern unsigned char gnLifeColorLow; // 0x007BEED2
extern unsigned char gbLifeColorsInit; // 0x007BEED3
extern unsigned char gabBeltColors[4]; // 0x007BEF6C
extern D2UnitStrc* gpBeltItemA; // 0x007BEFA8
extern int gpBeltItemB; // 0x007BEFAC
extern unsigned char gabBeltHotkey[4]; // 0x007BEFB0
extern unsigned char gnTextColorRed; // 0x007BEFBA
extern D2TextHeaderStrc* gpTextHeader; // 0x007BF250
extern int gnTextLeft; // 0x007BF278
extern int gnTradeState; // 0x007C0E7C
