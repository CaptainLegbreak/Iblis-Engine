#pragma once
// D2Common's exports that the other modules call and D2CommonApi.h doesn't declare. A separate header because
// adding to D2CommonApi.h clashes with private copies in its includers; included only by the units that use it.

struct B25DistancePath;
struct B25Path;
struct B25TargetUnit;
struct D2Act00619DA0Strc;
struct D2ActRoom00619DA0Strc;
struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2Block0;
struct D2Block1;
struct D2Block2;
struct D2ClientStrc;
struct D2CoordStrc;
struct D2CubeMainTxt;
struct D2DrlgActStrc;
struct D2DrlgCoordStrc;
struct D2DrlgLevelLinkDataStrc;
struct D2DrlgLevelStrc;
struct D2DrlgRoomStrc;
struct D2DrlgStrc;
struct D2DrlgTileDataStrc;
struct D2DrlgWarpStrc;
struct D2DynamicPathStrc;
struct D2GambleDataTbl;
struct D2GfxLightStrc;
struct D2HirelingInitStrc;
struct D2HirelingTxt;
struct D2HoverTextStrc;
struct D2InvRectStrc;
struct D2InventoryNodeStrc;
struct D2InventoryStrc;
struct D2ItemDataTbl;
struct D2ItemRatioTxt;
struct D2ItemsTxt;
struct D2LevelDefBin;
struct D2LevelsTxt;
struct D2LowQualityItemDataTbl;
struct D2LowQualityItemsTxt;
struct D2MapAIStrc;
struct D2MessageListStrc;
struct D2MonSoundsTxt;
struct D2MonStatsTxt;
struct D2PresetUnitStrc;
struct D2PropertyStrc;
struct D2Record00648E40Strc;
struct D2RunesTxt;
struct D2ShrinesTxt;
struct D2SkillStrc;
struct D2SkillsTxt;
struct D2StatListStrc;
struct D2StatStrc;
struct D2SuperUniquesTxt;
struct D2TCExShortStrc;
struct D2TextHeaderStrc;
struct D2TimerArgStrc;
struct D2TokRecord;
struct D2UnitFindArgStrc;
struct D2UnitFindDataStrc;
struct D2UnitStrc;
struct Obj00619720;
struct Obj00619EE0;
struct Obj0061AFA0;
struct Obj00625250;
struct Obj006252B0;
struct Obj006252D0;
struct Obj006252F0;
struct Obj00625330;
struct Obj00625CE0;
struct Obj00626090;
struct Obj006260B0;
struct Obj0063CD20;
struct Obj0063CD40;
struct Obj0063D650;
struct Obj0063D670;
struct Obj00644340;
struct Obj00648690;
struct Obj00648750;
struct Obj00648790;
struct Obj006487D0;
struct Obj00648810;
struct Obj006488A0;
struct Obj00648A20;
struct Obj00648A30;
struct Obj00648A40;
struct Obj00648A60;
struct Obj00648AB0;
struct Obj00648AD0;
struct Obj00648C10;
struct Obj00648CD0;
struct Obj00649070;
struct Obj006490A0;
struct Pair00650E60;
struct Pair00650E70;
struct PathCollisionView;
struct PathFlags;
struct PathPreviousView;
struct PathView;
struct Room;
struct UnitView;
struct View_00648780;
struct View_00648AA0;

void __cdecl IGNORELIST_FreeIgnoreList(); // 0x0060DDB0
void IGNORELIST_CreateIgnoreList(); // 0x006114E0
void __stdcall DATATBLS_ToggleCompileTxtFlag(int bSilent); // 0x006125A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount); // 0x006196E0
void** __stdcall DUNGEON_GetTileDataFromAct(D2DrlgActStrc* pAct); // 0x00619720
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0
void __stdcall DUNGEON_IncreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619EE0
D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* ptRoom); // 0x00619FD0
void __stdcall DUNGEON_SetClientIsInSight(D2DrlgActStrc* ptAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom); // 0x0061A070
void __stdcall DUNGEON_UnsetClientIsInSight(D2DrlgActStrc* ptAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom); // 0x0061A0C0
D2ActiveRoomStrc* __stdcall DUNGEON_StreamRoomAtCoords(D2DrlgActStrc* ptAct, int nX, int nY); // 0x0061A140
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1F0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall DUNGEON_AddClientToRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0061A660
void __stdcall DUNGEON_RemoveClientFromRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0061A700
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct); // 0x0061AAC0
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId); // 0x0061AAF0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId); // 0x0061ABF0
int* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* ptRoom); // 0x0061AC10
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nPortalLevelId); // 0x0061AE30
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct); // 0x0061AE80
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset); // 0x0061AED0
extern "C" void __stdcall DUNGEON_SaveKilledUnitGUID(Obj0061AFA0* pObj, unsigned int dwValue); // 0x0061AFA0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
unsigned char __stdcall DATATBLS_GetNoPerFromLevelsTxt(int nLevelId); // 0x0061DBE0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion); // 0x0061DCA0
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
int __stdcall DATATBLS_CheckActInLevelTypesTxt(int nLevelType, unsigned char nAct); // 0x0061EAE0
void __stdcall DATATBLS_GetFileNameFromLevelTypeAndFileId(int nLevelType, int nFile, char* szFile); // 0x0061EB40
int __fastcall DATATBLS_GetAutomapCellId(int nLevelNo, int nTileType, int nStyle, int nSequence); // 0x0061FFF0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* hUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* hUnit); // 0x006201D0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* hUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType); // 0x00620290
void __stdcall UNITS_FreeUnit(D2UnitStrc* unit); // 0x00620300
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* ptUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* ptUnit); // 0x00620410
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* ptUnit); // 0x006205A0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* ptUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* ptUnit); // 0x006206B0
void __stdcall UNITS_SetAnimData(D2UnitStrc* ptUnit, int nUnitType, int nClassId, int nMode); // 0x00620F00
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* ptUnit); // 0x00620F50
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050
D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* ptUnit); // 0x00621150
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit); // 0x00621260
void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate); // 0x00621330
int __stdcall UnitIsDoor(D2UnitStrc* ptUnit); // 0x00621A70
D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit); // 0x00621B70
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40
int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit); // 0x00621ED0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit); // 0x00621F60
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* ptUnit); // 0x00622060
char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x00622150
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit); // 0x00622230
int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag); // 0x00622350
int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit); // 0x006223A0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit); // 0x006223F0
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker); // 0x00622560
int __stdcall UNITS_GetMeleeRange(D2UnitStrc* hUnit); // 0x00622870
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit); // 0x00622EA0
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit); // 0x00622F10
void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc* pUnit); // 0x00622F80
void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc* pUnit); // 0x00622FF0
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pRightSkillId, int* pRightSkillFlags); // 0x00623060
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pLeftSkillId, int* pLeftSkillFlags); // 0x006230C0
void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags); // 0x00623120
void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags); // 0x006231A0
void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags); // 0x00623220
void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags); // 0x00623290
void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSwitchLeftSkillId, int nSwitchLeftSkillFlags); // 0x00623300
void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSwitchRightSkillId, int nSwitchRightSkillFlags); // 0x00623350
int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470
void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, D2TimerArgStrc* pTimerArg); // 0x006234C0
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit); // 0x006234F0
void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit); // 0x00623520
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit); // 0x00623570
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int nArg2); // 0x00623990
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...); // 0x006248E0
void __fastcall LOGGING_SetLoggingEnabled(int bEnable); // 0x00624B50
int __stdcall STATLIST_GetFullStatsCountFromUnit(D2UnitStrc* pUnit); // 0x00625290
int __stdcall STATLIST_GetExpireFrame(D2StatListStrc* pStatList); // 0x00625330
D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag); // 0x00625730
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
int __stdcall STATLIST_GetTotalStatValue_Layer0(D2StatListStrc* pStatListEx, int nStatId); // 0x00625A50
extern "C" void __stdcall STATLIST_SetStatRemoveCallback(Obj00625CE0* pObj, unsigned int dwValue); // 0x00625CE0
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
int __stdcall STATLIST_GetListExpireFrame(D2StatListStrc* pStatList); // 0x00626090
void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __stdcall STATLIST_SetSkillId(D2StatListStrc* pStatList, int nSkillId); // 0x006260D0
D2SkillStrc* __stdcall STATLIST_GetSkillId(D2StatListStrc* pStatList); // 0x006260E0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc* pStatList, int nSkillLevel); // 0x006260F0
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallbackFunc, void* pGame); // 0x00626D40
void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit); // 0x006272E0
void __stdcall STATLIST_RemoveAllStatsFromOverlay(D2UnitStrc* pUnit); // 0x00627410
void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame); // 0x00627460
void __stdcall D2Common_10469(D2UnitStrc* pUnit); // 0x00627540
void __stdcall D2Common_10525(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x006276C0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem); // 0x00627C90
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem); // 0x00627D00
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem); // 0x00627DC0
unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem); // 0x00627DF0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
void __stdcall ITEMS_SetItemQuality(D2UnitStrc* pItem, unsigned int dwQuality); // 0x00627EA0
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0
unsigned short __stdcall ITEMS_GetRarePrefixIndex(D2UnitStrc* pItem); // 0x00627FE0
unsigned short __stdcall ITEMS_GetRareSuffixIndex(D2UnitStrc* pItem); // 0x00628040
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel); // 0x00628220
char __stdcall ITEMS_GetInventoryPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, int nCellOverlap); // 0x006282D0
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem); // 0x006282F0
void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName); // 0x00628370
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem); // 0x006283A0
int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType); // 0x00628480
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* hItem); // 0x00628660
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId); // 0x00628700
unsigned char __stdcall ITEMS_GetItemQlvl(const D2UnitStrc* hItem); // 0x00628740
unsigned int __stdcall ITEMS_CheckIfFlagIsSet(unsigned int dwFlags, unsigned int dwFlag); // 0x006287A0
int __stdcall ITEMS_CheckItemTypeIfThrowable(int nItemType); // 0x00628860
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem); // 0x00629660
int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem); // 0x006296F0
unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* hItem); // 0x00629800
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem); // 0x006299B0
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType); // 0x00629A90
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2); // 0x00629B50
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId); // 0x00629C80
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem); // 0x00629F20
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem); // 0x00629FE0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem); // 0x0062A0F0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat); // 0x0062A6C0
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall ITEMS_CanBeImbued(D2UnitStrc* pItem); // 0x0062C590
int __stdcall ITEMS_IsPersonalizable(D2UnitStrc* hItem); // 0x0062C6A0
int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem); // 0x0062C770
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem); // 0x0062E660
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem); // 0x0062E8D0
int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem); // 0x0062FDF0
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680
D2LowQualityItemDataTbl* __fastcall DATATBLS_GetLowQualityItemDataTables(); // 0x006375B0
D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nIndex); // 0x006375C0
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int nItemId, unsigned char nDifficulty, unsigned short wVersion); // 0x00637910
D2GambleDataTbl* __fastcall DATATBLS_GetGambleDataTables(); // 0x00638CC0
void __stdcall DATATBLS_AddOrChangeRunesTxtRecord(int nRecordId, D2RunesTxt* pRecord); // 0x00639CC0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit); // 0x00639EE0
unsigned int* __stdcall STATES_GetGfxStateFlags(D2UnitStrc* hUnit); // 0x00639F70
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss); // 0x00639FB0
int __stdcall STATES_CheckStateMaskAuraByStateId(int nState); // 0x0063A210
int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit); // 0x0063A2B0
void __stdcall STATES_UpdatePgsvFlags(D2UnitStrc* pUnit); // 0x0063A2D0
int __stdcall STATES_CheckStateMaskArmRedOnUnit(D2UnitStrc* pUnit); // 0x0063A5F0
int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit); // 0x0063A6F0
int __stdcall STATES_CheckStateMaskLifeOnUnit(D2UnitStrc* pUnit); // 0x0063A750
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit); // 0x0063A770
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
void __stdcall sub_0063BE30_Return(int nUnused1, int nUnused2); // 0x0063BE30
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C110
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pScrolls, D2UnitStrc* pCheckItem); // 0x0063C3B0
D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc* pInventory); // 0x0063CBB0
void __stdcall INVENTORY_FreeTradeInventory(D2InventoryStrc* pInventory); // 0x0063CBD0
D2InventoryNodeStrc* __stdcall INVENTORY_GetNextNode(D2InventoryNodeStrc* pNode); // 0x0063CD20
int __stdcall INVENTORY_GetItemGUIDFromNode(D2InventoryNodeStrc* pNode); // 0x0063CD40
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall INVENTORY_GetCorpseCount(D2InventoryStrc* pInventory); // 0x0063D5F0
struct D2CorpseStrc;
unsigned int __stdcall INVENTORY_GetCorpseMercNameId(D2CorpseStrc* pCorpse); // 0x0063D650
unsigned int __stdcall INVENTORY_IsPlayerCorpse(D2CorpseStrc* pCorpse); // 0x0063D670
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc); // 0x0063E490
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster); // 0x0063EDC0
void __stdcall MONSTERS_GetChainDirectionDelta(D2UnitStrc* unit,int* x,int* y); // 0x0063EE10
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling); // 0x0063EE90
int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
void __fastcall UNITS_SetInteractData(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2); // 0x00641F20
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
int __stdcall DRLG_GetLevelTypeFromLevelId(int nLevelId); // 0x00642750
int __stdcall DRLG_GetSaveMonstersFromLevelId(int nLevelId); // 0x00642820
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nId); // 0x00642920
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY); // 0x00643290
void __stdcall DUNGEON_ClientTileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY); // 0x00643340
void __stdcall DUNGEON_ClientSubileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY); // 0x00643400
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue); // 0x00643A00
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* hSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId); // 0x00644300
int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill); // 0x00644360
int __stdcall SKILLS_GetParam1(D2SkillStrc* ptSkill); // 0x006444A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* ptSkill, int nValue); // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* ptSkill, int nValue); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* ptSkill, int nValue); // 0x00644660
int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId); // 0x006447D0
int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId); // 0x00644920
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall SKILLS_GetHighestSkillLevelById(D2UnitStrc* pUnit, int nSkillId); // 0x00644AA0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall D2Common_11020(D2UnitStrc* pUnit); // 0x00645630
int __stdcall D2Common_11024(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType, int* pHasThrowBonus); // 0x00645720
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall SKILLS_GetShiftedManaCosts(int nSkillId, int nSkillLevel); // 0x006459F0
int __stdcall SKILLS_IsEnhanceable(int nSkillId); // 0x00645FB0
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine); // 0x006470F0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* ptSkill); // 0x00647960
void __stdcall D2Common_11031(D2UnitStrc* pUnit, int nSkillId, int nBonus); // 0x00647B20
void __stdcall PATH_GetClientCoordsVelocity(D2UnitStrc* pUnit, int* pX, int* pY); // 0x00648300
void __stdcall PATH_ClearPathingFlagAndPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648730
void __stdcall PATH_SetPathingFlag(D2DynamicPathStrc* pDynamicPath, int bSet); // 0x00648750
int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pDynamicPath); // 0x00648770
void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath, int nPathPoints); // 0x00648790
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath); // 0x006487F0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char bDir); // 0x00648820
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0
unsigned int __stdcall PATH_GetFinalTargetX(D2DynamicPathStrc* pDynamicPath); // 0x00648A20
unsigned int __stdcall PATH_GetFinalTargetY(D2DynamicPathStrc* pDynamicPath); // 0x00648A30
unsigned int __stdcall PATH_GetLastPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A40
unsigned int __stdcall PATH_GetLastPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A60
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AA0
void __stdcall PATH_ClearNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AB0
void __stdcall PATH_SetTargetPos(D2DynamicPathStrc* pDynamicPath, unsigned short nX, unsigned short nY); // 0x00648AD0
extern "C" void __stdcall PATH_SetCurrentRoomInvalid(D2DynamicPathStrc* pDynamicPath, int bInvalid); // 0x00648B40
extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit); // 0x00648B90
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* ptPath, int* pTargetType, int* pTargetGUID); // 0x00648BB0
unsigned int __stdcall PATH_GetFootprintCollisionMaskExported(D2DynamicPathStrc* pDynamicPath); // 0x00648C10
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
unsigned int __stdcall PATH_GetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath); // 0x00648CD0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648CE0
void __stdcall PATH_SetDist(D2DynamicPathStrc* pDynamicPath, unsigned char nDist); // 0x00648E40
unsigned char __stdcall D2COMMON_10191_PATH_GetDistance(D2DynamicPathStrc* pDynamicPath); // 0x00648E60
unsigned short __stdcall PATH_GetCollidedWithMask(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0
void __stdcall PATH_ClearPreviousTargetPoint(D2DynamicPathStrc* pDynamicPath); // 0x00649050
int __stdcall PATH_GetStepNum(D2DynamicPathStrc* pDynamicPath); // 0x006490A0
void __stdcall PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, int nDist); // 0x006490E0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall PATH_SetUnitCollisionPattern(D2UnitStrc* pUnit, int nCollisionPattern); // 0x00649190
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
void __stdcall D2Common_10216(D2DynamicPathStrc* pDynamicPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0
void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit); // 0x0064A0E0
void __stdcall MISSILE_SetLevel(D2UnitStrc* pMissile, int nLevel); // 0x0064A1E0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall MISSILE_SetStreamMissile(D2UnitStrc* pMissile, int nStreamMissile); // 0x0064A4E0
int __stdcall MISSILE_GetStreamMissile(D2UnitStrc* pMissile); // 0x0064A510
void __stdcall MISSILE_SetStreamRange(D2UnitStrc* pMissile, short nStreamRange); // 0x0064A540
int __stdcall MISSILE_GetStreamRange(D2UnitStrc* pMissile); // 0x0064A570
int __stdcall MISSILE_GetHitClass(D2UnitStrc* pMissile); // 0x0064A5A0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* hRoom, int nUnused); // 0x0064C2C0
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* hUnit); // 0x0064C370
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB90
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighborRooms); // 0x0064E7B0
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EA00
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit); // 0x006505E0
int __fastcall SEED_GetRandomValue(int nValue); // 0x00650DE0
union D2SeedStrc;
void __fastcall SEED_SetSeeds(D2SeedStrc* pSeed, unsigned int nLowSeed, unsigned int nHighSeed); // 0x00650E60
void __fastcall SEED_GetSeeds(D2SeedStrc* pSeed, unsigned int* pLowSeed, unsigned int* pHighSeed); // 0x00650E70
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromIdAndLevel(unsigned short wTCId, int nLvl); // 0x00654E00
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(int nDifficulty, int nAct, int nIndex); // 0x00654E80
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0
int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount(); // 0x00655710
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x006564D0
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x00656580
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId); // 0x00656FC0
int __stdcall UNITFINDS_TestUnit(D2UnitStrc* unit,D2UnitFindArgStrc* args); // 0x0065AA40
D2TokRecord* __stdcall DATATBLS_GetCompositTxtRecord(int nComposit); // 0x0065B5E0
D2TokRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(int nId); // 0x0065B620
void __stdcall DATATBLS_GetInventoryRect(int nId, int nGroup, D2Block0* pBlock); // 0x0065C180
void __stdcall DATATBLS_GetInventoryGridInfo(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0
void __stdcall DATATBLS_GetInventoryComponentGrid(int nId, int nGroup, D2Block2* pBlock, int nEntry); // 0x0065C270
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* hQuestRecord, int nQuest, int nState); // 0x0065C3A0
int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pValue, D2StatListStrc** ppStatList); // 0x0065C820
int __stdcall ITEMMODS_UpdateItemWithSkillCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges); // 0x0065C940
void __stdcall ITEMMODS_SetRandomElixirFileIndex(D2UnitStrc* pItem); // 0x0065E8E0
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* pTargetUnit); // 0x0065FD70
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* pTargetUnit, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0
int __stdcall ITEMMODS_UpdateRuneword(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused); // 0x006600A0
void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc* pItem, D2PropertyStrc* pProperty, int nUnused); // 0x00660240
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2InvRectStrc* pInvRect, int nBoxId); // 0x00660D10
void __stdcall CHAT_CopyHoverMsgToBuffer(D2HoverTextStrc* pHoverMsg, char* szMessage); // 0x006611E0
int __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661200
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId); // 0x00661230
short __stdcall TEXT_GetStringIdOfMenuType1Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661440
void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHead, D2MessageListStrc* pMsgList); // 0x00661480
void __stdcall TEXT_CreateTextHeaderFromMessageList(D2TextHeaderStrc* pTextHead, D2MessageListStrc* pMsgList); // 0x00661510
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling); // 0x006637B0
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0
void __stdcall MISSTREAM_FreeMissileStream(D2UnitStrc* pMissile); // 0x00663D90
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId); // 0x00664740
void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAI); // 0x00666130
D2CubeMainTxt* __stdcall DATATBLS_GetCubemainTxtRecord(int nIndex); // 0x0066A1B0
int __fastcall DATATBLS_GetCubemainTxtRecordCount(); // 0x0066A200
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066AEC0
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistanceToAssumeCollision); // 0x0066B860
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nOrthogonalDistanceMax); // 0x0066B880
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040
int __fastcall DRLGOUTPLACE_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676DD0
int __fastcall DRLGOUTPLACE_LinkAct1Monastery(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676EB0
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration); // 0x00677110
void __fastcall DRLGOUTPLACE_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand); // 0x00677180
int __fastcall DRLGOUTSIEGE_GetBorderLookupId(D2DrlgLevelStrc* pLevel); // 0x0067DCE0
