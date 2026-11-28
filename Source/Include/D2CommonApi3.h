#pragma once
// D2Common's exports that the other modules call; included only by the units that use it.

struct D2PoolSystemStrc;
struct D2ActiveRoomStrc;
struct D2ArenaTxt;
struct D2BitBufferStrc;
struct D2CommonIgnoreListStrc;
struct D2CoordStrc;
struct D2DrlgActStrc;
struct D2DynamicPathStrc;
struct D2HoverTextStrc;
struct D2InventoryStrc;
struct D2ItemSaveStrc;
struct D2MissileDamageDataStrc;
struct D2ObjGroupTxt;
struct D2ObjectsTxt;
struct D2PathPointStrc;
struct D2QualityItemDataTbl;
struct D2QualityItemsTxt;
struct D2RareAffixDataTbl;
struct D2RareAffixTxt;
union D2SeedStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2StatStrc;
struct D2TextHeaderStrc;
struct D2TokRecord;
struct D2UnitFindDataStrc;
struct D2UnitStrc;
struct D2WaypointDataStrc;
struct Unicode;

D2CommonIgnoreListStrc* IGNORELIST_GetOrCreateIgnoreList(); // 0x00611560
unsigned int __stdcall DATATBLS_GetExpRatio(int nLevel); // 0x00613E60
void __stdcall DUNGEON_GetRGB_IntensityFromRoom(D2ActiveRoomStrc* pRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x00619D70
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* ptAct, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x00619E50
D2UnitStrc* __stdcall DUNGEON_GetFirstUnitInRoom(D2ActiveRoomStrc* ptRoom); // 0x00619EA0
int __stdcall DUNGEON_GetWarpDestinationLevel(D2ActiveRoomStrc* pRoom, int nSourceLevel); // 0x0061A1D0
int __stdcall DUNGEON_HasWaypoint(D2ActiveRoomStrc* ptRoom); // 0x0061A210
int __stdcall DUNGEON_GetActNoFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AB30
int __stdcall D2Common_10087(D2ActiveRoomStrc* ptRoom); // 0x0061ABB0
void __stdcall DUNGEON_UpdateWarpRoomSelect(D2ActiveRoomStrc* ptRoom, int nLevelId); // 0x0061AC50
void __stdcall DUNGEON_UpdateWarpRoomDeselect(D2ActiveRoomStrc* ptRoom, int nLevelId); // 0x0061AC90
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct); // 0x0061AEB0
int __stdcall ENVIRONMENT_GetCycleIndexFromAct(D2DrlgActStrc* pAct); // 0x0061C220
void __stdcall ENVIRONMENT_TaintedSunBegin(D2DrlgActStrc* pAct); // 0x0061C450
void __stdcall ENVIRONMENT_TaintedSunEnd(D2DrlgActStrc* pAct); // 0x0061C4D0
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId); // 0x0061DBA0
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId); // 0x0061DC20
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* hUnit); // 0x00620150
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* ptUnit, int nX); // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* ptUnit, int nY); // 0x006204C0
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit); // 0x00621310
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit); // 0x00621B30
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY); // 0x00621C00
void __stdcall UNITS_StoreLastAttacker(D2UnitStrc* ptUnit, D2UnitStrc* pKiller); // 0x00621D50
unsigned int __stdcall UNITS_GetNameOffsetFromObject(D2UnitStrc* ptUnit); // 0x00622270
int __stdcall UNITS_GetWeaponGUID(D2UnitStrc* ptUnit); // 0x00623410
int __stdcall UNITS_IsCorpseUseable(D2UnitStrc* pUnit); // 0x00623600
int __stdcall UNITS_GetNewDirection(D2UnitStrc* hUnit); // 0x006238C0
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit); // 0x00623B10
int __stdcall STATLIST_GetOwnerType(D2StatListStrc* pStatList); // 0x00625250
int __stdcall STATLIST_GetOwnerGUID(D2StatListStrc* pStatList); // 0x006252B0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
int __stdcall STATLIST_GetState(D2StatListStrc* pStatList); // 0x006252F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
int __stdcall D2COMMON_10530_D2CheckStatlistFlagDMGRed(D2UnitStrc* pUnit); // 0x00625A20
int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261B0
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
void __stdcall STATLIST_MergeBaseStats(D2StatListStrc* pTargetStatList, D2StatListStrc* pSourceStatlist); // 0x006274F0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed); // 0x00627E20
unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem); // 0x00627F20
void __stdcall ITEMS_SetAutoAffix(D2UnitStrc* pItem, unsigned short wAffix); // 0x00627F50
unsigned int __stdcall ITEMS_CheckItemCMDFlag(D2UnitStrc* pItem, unsigned int dwMask); // 0x00628140
void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, unsigned char nLevel); // 0x006283D0
unsigned char __stdcall ITEMS_GetVarGfxIndex(D2UnitStrc* pItem); // 0x006283F0
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex); // 0x00628420
unsigned int __stdcall ITEMS_GetAltGfx(D2UnitStrc* hItem); // 0x006285F0
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* hItem); // 0x00628BA0
int __stdcall ITEMS_IsQuestItem(D2UnitStrc* hItem); // 0x00628CD0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0
int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int dwVersion); // 0x0062AE20
unsigned int __stdcall ITEMS_GetReload(D2UnitStrc* pItem); // 0x0062E7E0
unsigned int __stdcall ITEMS_GetReEquip(D2UnitStrc* pItem); // 0x0062E830
char* __stdcall ITEMS_GetVarInvGfxString(D2UnitStrc* pItem, int nId); // 0x0062E920
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem); // 0x0062E990
int __stdcall ITEMS_CanBeMagic(D2UnitStrc* pItem); // 0x0062E9E0
int __stdcall ITEMS_CanBeNormal(D2UnitStrc* pItem); // 0x0062EA30
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables(); // 0x00634250
D2QualityItemDataTbl* __fastcall DATATBLS_GetQualityItemDataTables(); // 0x00636B10
D2QualityItemsTxt* __stdcall DATATBLS_GetQualityItemsTxtRecord(int nIndex); // 0x00636B20
int __stdcall STATES_IsAnyGfxStateFlagSet(D2UnitStrc* pUnit); // 0x00639F20
int __stdcall STATES_CheckStateMaskAuraOnUnit(D2UnitStrc* pUnit); // 0x0063A250
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit); // 0x0063A340
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit); // 0x0063A3E0
int __stdcall STATES_CheckStateMaskCurseByStateId(int nState); // 0x0063A420
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState); // 0x0063A460
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState); // 0x0063A4A0
int __stdcall STATES_CheckStateMaskArmBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A550
int __stdcall STATES_CheckStateMaskRFBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A570
int __stdcall STATES_CheckStateMaskRCBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A590
int __stdcall STATES_CheckStateMaskRLBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A5B0
int __stdcall STATES_CheckStateMaskRPBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A5D0
int __stdcall STATES_CheckStateMaskRFRedOnUnit(D2UnitStrc* pUnit); // 0x0063A610
int __stdcall STATES_CheckStateMaskRCRedOnUnit(D2UnitStrc* pUnit); // 0x0063A630
int __stdcall STATES_CheckStateMaskRLRedOnUnit(D2UnitStrc* pUnit); // 0x0063A650
int __stdcall STATES_CheckStateMaskRPRedOnUnit(D2UnitStrc* pUnit); // 0x0063A670
int __stdcall STATES_CheckStateMaskExpOnUnit(D2UnitStrc* pUnit); // 0x0063A690
int __stdcall STATES_CheckStateMaskExpByStateId(int nState); // 0x0063A6B0
void __stdcall INVENTORY_CreateCorpseForPlayer(D2InventoryStrc* pInventory, int nUnitId, int nArg3, int bCounted); // 0x0063D470
int __stdcall INVENTORY_GetItemGUID(D2UnitStrc* pItem); // 0x0063E000
int __stdcall D2Common_11050(D2UnitStrc* pUnit, int nArg2); // 0x0063E6B0
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName); // 0x0063E810
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster); // 0x0063E990
unsigned char __stdcall MONSTERS_GetMaximalLightRadius(D2UnitStrc* pMonster); // 0x0063EBD0
D2ObjGroupTxt* __stdcall DATATBLS_GetObjGroupTxtRecord(int nId); // 0x006412F0
int __stdcall UNITS_IsInRange(D2UnitStrc* pUnit, D2CoordStrc* pCoord, int nDistance); // 0x00641890
int __stdcall DRLG_GetLOSDrawFromLevelId(int nLevelId); // 0x00642840
void __stdcall DUNGEON_ClientToGameSubtileCoords(int* pX, int* pY); // 0x00643510
int __stdcall SKILLS_GetPassiveState(int nSkillId); // 0x00643690
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, unsigned int nSkillMode); // 0x00644340
int __stdcall SKILLS_GetManaCosts(int nSkillId, int nSkillLevel); // 0x00644B10
int __stdcall SKILLS_IsPlayerClassSkill(int nSkillId, int* pPlayerClass); // 0x00645080
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int bAllowDying); // 0x00645510
int __stdcall D2COMMON_11018(D2UnitStrc* pUnit); // 0x00645590
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit); // 0x006455E0
int __stdcall SKILLS_CanUnitCorpseBeSelected(D2UnitStrc* pUnit); // 0x006456D0
int __stdcall D2Common_11034(int nLevel, int nSkillId); // 0x00645B70
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit); // 0x00646020
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent); // 0x00646280
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit); // 0x00646F20
void __stdcall D2Common_11030(D2UnitStrc* pUnit, int nSkillId, int nLevelBonus); // 0x00647AA0
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath); // 0x00648640
void __stdcall PATH_SetMaxVelocity(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity); // 0x006486D0
void __stdcall PATH_SetAcceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration); // 0x00648700
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints); // 0x006487D0
unsigned char __stdcall PATH_GetNewDirection(D2DynamicPathStrc* pDynamicPath); // 0x00648810
void __stdcall PATH_SetPrecisionX(D2DynamicPathStrc* pDynamicPath, unsigned int dwPrecisionX); // 0x006489A0
void __stdcall PATH_SetPrecisionY(D2DynamicPathStrc* pDynamicPath, int nPrecisionY); // 0x006489B0
extern "C" void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070
void __stdcall D2COMMON_10212_PATH_SetMoveFlags(D2UnitStrc* pUnit, int bSet); // 0x006491B0
void __stdcall D2Common_10213(D2UnitStrc* pUnit); // 0x00649210
void __stdcall D2Common_10214(D2UnitStrc* pUnit); // 0x00649CA0
void __stdcall PATH_SetUnitAliveCollision(D2UnitStrc* pUnit, int bSkip); // 0x00649FF0
unsigned int __stdcall MISSILE_GetFlags(D2UnitStrc* pMissile); // 0x0064A190
void __stdcall MISSILE_SetFlags(D2UnitStrc* pMissile, unsigned int dwFlags); // 0x0064A1C0
void __stdcall MISSILE_SetSkill(D2UnitStrc* pMissile, int nSkill); // 0x0064A240
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame); // 0x0064A5F0
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed); // 0x0064A690
void __stdcall MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel); // 0x0064AC60
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithMaxDistance(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighborRooms, int nMaxDistance); // 0x0064E780
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EBA0
int __stdcall COMPOSIT_IsArmorComponent(int nComponent); // 0x0064F420
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit); // 0x0064F460
unsigned int __stdcall COMPOSIT_GetArmorTypeFromComponent(int eComponent, unsigned char* pArmorComponents); // 0x0064F500
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2); // 0x0064FDC0
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00650D70
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
const Unicode* __fastcall DATATBLS_RollRandomUniquePrefixString(D2UnitStrc* pUnit); // 0x00653ED0
const Unicode* __fastcall DATATBLS_RollRandomUniqueSuffixString(D2UnitStrc* pUnit); // 0x00653F10
const Unicode* __fastcall DATATBLS_RollRandomUniqueAppellationString(D2UnitStrc* pUnit); // 0x00653F50
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique); // 0x00659B80
int __stdcall UNITFINDS_AreUnitsInNeighboredRooms(D2UnitStrc* pDestUnit, D2UnitStrc* pSrcUnit); // 0x0065A590
int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
D2TokRecord* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(unsigned int nIndex, int bGetMode); // 0x0065B480
D2TokRecord* __stdcall DATATBLS_GetObjModeTypeTxtRecord(unsigned int nIndex, int bGetMode); // 0x0065B570
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short wBufSize, int bResetStates); // 0x0065C4D0
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short wBufSize, int nUnused); // 0x0065C560
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* hItem); // 0x0065E4D0
int __stdcall ITEMMODS_CanItemHaveRareAffix(D2UnitStrc* pItem, const D2RareAffixTxt* pRareAffixTxtRecord); // 0x0065E710
int __stdcall ITEMMODS_CanItemBeHighQuality(D2UnitStrc* pItem, const D2QualityItemsTxt* pQualityItemsTxtRecord); // 0x0065E7D0
void __stdcall WAYPOINTS_ValidateAndCopyWaypointData(D2WaypointDataStrc* pSource, D2WaypointDataStrc* pDestination); // 0x006610B0
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(D2PoolSystemStrc* pMemPool, const char* szText, int nTimeout); // 0x00661110
int __stdcall TEXT_GetMenuType2NodeCount(D2TextHeaderStrc* pTextHeader); // 0x00661390
short __stdcall TEXT_GetStringIdOfMenuType2Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x006613C0
short __stdcall TEXT_GetStringIdOfMenuType0Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661400
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0
const Unicode* __fastcall MONSTERS_GetHirelingDescString(int nId); // 0x00663720
int __stdcall D2COMMON_11068_GetCompInfo(D2UnitStrc* pMonster, int nComponent); // 0x006647C0
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860
int __stdcall D2Common_11070(int nMonsterId, unsigned int nComponent, unsigned int nIndex); // 0x00664930
D2ArenaTxt* __fastcall DATATBLS_GetArenaTxtRecord(int nArenaType); // 0x00664AB0
