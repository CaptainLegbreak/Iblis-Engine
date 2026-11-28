#pragma once
// D2Common's exports that the other modules call most: units, rooms, paths, stats, states, quests, skills
// and the data tables.

struct D2PoolSystemStrc;
struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2CoordStrc;
struct D2DifficultyLevelsTxt;
struct D2DrlgCoordsStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2ItemsTxt;
struct D2ObjectsTxt;
struct D2PlayerDataStrc;
union D2SeedStrc;
struct D2SkillStrc;
struct D2StatListExStrc;
struct D2StatListStrc;
struct D2UnitStrc;
struct D2AnimSeqTxt;
struct D2BeltsTxt;
struct D2BookDataTbl;
struct D2BooksTxt;
struct D2CorpseStrc;
struct D2DrlgActStrc;
struct D2DrlgDeleteStrc;
struct D2DrlgStrc;
struct D2DrlgTileDataStrc;
struct D2GemsTxt;
struct D2HirelingTxt;
struct D2HoverTextStrc;
struct D2LevelDefBin;
struct D2LvlWarpTxt;
struct D2MagicAffixDataTbl;
struct D2MagicAffixTxt;
struct D2MapAIStrc;
struct D2MonSoundsTxt;
struct D2MonStatsInitStrc;
struct D2PathPointStrc;
struct D2RareAffixTxt;
struct D2RoomCoordListStrc;
struct D2RunesTxt;
struct D2SetItemsTxt;
struct D2ShrinesTxt;
struct D2SkillListStrc;
struct D2StatStrc;
struct D2TextHeaderStrc;
struct D2UnitFindDataStrc;
struct D2WaypointDataStrc;

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* ptUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* hPath); // 0x00648900
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* hQuestRecord, int nQuest, int nState); // 0x0065C310
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* hQuestRecord, int nQuest, int nState); // 0x0065C360
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x006253B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* hUnit); // 0x00620250
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* ptRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
D2StatListStrc* __stdcall STATLIST_AllocStatList(D2PoolSystemStrc* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListExStrc* pStatList, int bResetFlag); // 0x00626E10
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall SKILLS_SetParam1(D2SkillStrc* ptSkill, int nValue); // 0x00644560
void __stdcall UNITS_GetCoords(D2UnitStrc* ptUnit, D2CoordStrc* pCoord); // 0x00620870
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __stdcall SKILLS_SetParam2(D2SkillStrc* ptSkill, int nValue); // 0x006445A0
void __stdcall PATH_SetType(D2DynamicPathStrc* ptPath, int eType); // 0x00648CF0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* ptUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* pStrength, int* pDexterity, int* pLevel); // 0x0062EAF0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* hUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, int nItemCell); // 0x00628320
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* ptUnit, int nFrame); // 0x006212C0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* hQuestRecord, int nQuest); // 0x0065C3E0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644E40
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nIndex); // 0x006372C0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647D00
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY); // 0x0063E7E0
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit); // 0x0063A100
int __stdcall SKILLS_GetParam4(D2SkillStrc* ptSkill); // 0x00644530
int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0
int __stdcall SKILLS_GetParam3(D2SkillStrc* ptSkill); // 0x00644500
int __stdcall SKILLS_GetParam2(D2SkillStrc* ptSkill); // 0x006444D0
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader); // 0x006612A0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* hSkill); // 0x00643AD0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
void __stdcall UNITS_GetClientCoords(D2UnitStrc* ptUnit, D2CoordStrc* pClientCoords); // 0x00620900
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00
unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool); // 0x0065C430
int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int nPosIncrementValue); // 0x0064E7E0
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc** ppMapAI2); // 0x00666120
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* ptAct, int nLevelId, int nTileIndex, int* pX, int* pY, int nUnitSize); // 0x0061B060
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath); // 0x006505C0
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem); // 0x00628C20
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20
int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue); // 0x0062A5D0
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue); // 0x0062A620
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0
int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit); // 0x00626020
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* hItem); // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50
void __stdcall QUESTRECORD_FreeRecord(D2PoolSystemStrc* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed); // 0x00650E50
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
void __stdcall ENVIRONMENT_GetLightColorFromAct(D2DrlgActStrc* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0
int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390
int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20
D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool); // 0x00660F30
void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct); // 0x0061AA20
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* hRoom, int nUnitType, int nClassId); // 0x0065A620
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860
void __stdcall PATH_AllocDynamicPath(D2PoolSystemStrc* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00
void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910
int __stdcall D2Common_10399(D2UnitStrc* a,D2UnitStrc* b); // 0x00641530
int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A380
int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit); // 0x0063A3A0
int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId); // 0x006461D0
int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* hItem); // 0x00628C70
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062FDC0
int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, D2UnitStrc** ppOtherItem, unsigned char nPage, int bExcludeCube); // 0x0063BB20
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nGridX, int nGridY, int* pX, int* pY, int nInventoryRecordId, unsigned char nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0
void __stdcall CHAT_FreeHoverMsg(D2PoolSystemStrc* pMemPool, D2HoverTextStrc* pHoverMsg); // 0x006611A0
int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc* pMissile); // 0x0064A380
int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A3B0
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061AD30
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName); // 0x006220F0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nColMask); // 0x00645950
void __cdecl sub_006115F0_Empty(); // 0x006115F0
void __cdecl PROFCORE_CloseLog(); // 0x00611600
int __stdcall ENVIRONMENT_GetIntensityFromAct(D2DrlgActStrc* pAct); // 0x0061C0E0
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* ptUnit, int* pFrameNo, int* pFrameCount); // 0x00621810
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags); // 0x006221E0
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath); // 0x00650590
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId); // 0x00626070
void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord); // 0x00660CB0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem); // 0x0062C0B0
unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661220
int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int bExpansion); // 0x00622720
void __stdcall WAYPOINTS_FreeWaypointData(D2PoolSystemStrc* pMemPool, D2WaypointDataStrc* pData); // 0x00660FD0
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* ptUnit, D2ActiveRoomStrc* pRoom, D2CoordStrc tCoord); // 0x00620AE0
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x0064C350
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40
void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50
void __stdcall PATH_FreeDynamicPath(D2PoolSystemStrc* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId); // 0x00646140
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill); // 0x006438F0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerGuid); // 0x0063D430
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct); // 0x0061A180
void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse); // 0x0061C330
void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom); // 0x0064C160
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C150
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience); // 0x00611860
void __stdcall SKILLS_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed); // 0x00621780
int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit); // 0x0063A360
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit); // 0x006633B0
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit); // 0x006633D0
void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent); // 0x006634C0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* ptSkill, int nValue); // 0x00645120
D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount); // 0x006196A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount); // 0x00619660
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem); // 0x0062A310
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue); // 0x00645F00
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId); // 0x00656F90
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile); // 0x0064A300
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pDynamicPath, int bReset); // 0x00649030
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo); // 0x00627EC0
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem); // 0x00628340
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* hItem); // 0x0062A710
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId); // 0x00645C10
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pUnit, int b2Handed); // 0x00625E60
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pUnit, int b2Handed); // 0x00625EF0
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062BA60
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem); // 0x0062C060
void __stdcall CHAT_SetUsedInHoverMsg(D2HoverTextStrc* pHoverMsg, int bUsed); // 0x00661210
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0
D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(D2PoolSystemStrc* pMemPool); // 0x00661240
void __stdcall TEXT_SortTextNodeListByStringId(D2TextHeaderStrc* pTextHead); // 0x006616E0
void __stdcall STATLIST_FreeModStats(D2UnitStrc* pUnit); // 0x00625960
void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* ptRoom, int nX, int nY, int bOtherRoom); // 0x0061ACD0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUpdateMode, int bForceStateUpdate); // 0x00663CC0
int __stdcall ITEMS_GetCompactItemDataFromBitstreamDefault(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
int __stdcall MISSILE_GetClassId(D2UnitStrc* pMissile); // 0x0064A3E0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel); // 0x006562F0
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit); // 0x00623E00
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord); // 0x00621BB0
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* ptUnit); // 0x00621F90
void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit); // 0x00647EE0
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00645460
void __stdcall DUNGEON_InitRoomTileAnimation(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2); // 0x0061AF10
void __stdcall UNITS_GetRunAndWalkSpeedForPlayer(int nUnused, int nCharId, int* pWalkSpeed, int* pRunSpeed); // 0x00620E40
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* ptUnit, int bInvalid); // 0x00620FA0
int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pMonster, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0063EA70
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath); // 0x006486C0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition); // 0x006460F0
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* ptRoom); // 0x0061A2C0
D2UnitStrc* __stdcall INVENTORY_GetSecondaryWeapon(D2InventoryStrc* pInventory); // 0x0063BF90
void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* ptAct); // 0x0061AFD0
int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061A3F0
int __stdcall D2Common_10081_GetTileCountFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A790
void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061A910
int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom); // 0x0061A460
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom); // 0x0061A4D0
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061A510
int __stdcall ENVIRONMENT_UpdateCycleIndex(D2DrlgActStrc* pAct, int nActNo); // 0x0061C040
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80
void __stdcall sub_0062BCB0_AddSockets(D2UnitStrc* item, int sockets); // 0x0062BCB0
D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables(); // 0x006374A0
int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0
void __stdcall TEXT_AddNodeToTextList(D2TextHeaderStrc* pTextHeader, short nStringId, int nMenu); // 0x006612F0
void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660EC0
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(D2PoolSystemStrc* pMemPool); // 0x006438B0
int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* hItem); // 0x0062BB20
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables(); // 0x00633ED0
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc* pItem, const D2MagicAffixTxt* pMagicAffixTxtRecord); // 0x0065E620
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel); // 0x00663270
void __stdcall DATATBLS_LoadAllTxts(void* hArchive, int bLoadFiles, int extra); // 0x00619300
void __stdcall DATATBLS_UnloadAllBins(); // 0x00619140
void __cdecl PROFCORE_WriteProfileCounters(); // 0x006116B0
D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nComponent); // 0x0063C050
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* hUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int determine, D2InventoryStrc* pInventory, int nAnimMode); // 0x0064FA00
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit); // 0x00620100
int __stdcall STATES_CheckStateMaskGreenOnUnit(D2UnitStrc* pUnit); // 0x0063A790
void __stdcall DUNGEON_AnimateTiles(D2ActiveRoomStrc* pRoom); // 0x0061AEF0
int __stdcall ENVIRONMENT_UpdatePeriodOfDay(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061BFC0
D2DrlgStrc* __stdcall DUNGEON_GetDrlgFromAct(D2DrlgActStrc* pAct); // 0x0061AA90
void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg); // 0x0061B920
void __stdcall ENVIRONMENT_InitializeEnvironment(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom, int nIndex, int nTicks, int bEclipse); // 0x0061C240
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId); // 0x00621CC0
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619F20
int __stdcall ITEMS_IsMetalItem(int nItemId); // 0x00629CC0
int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nCollisionMask); // 0x00645910
int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY); // 0x00645CA0
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* hPlayer, D2UnitStrc* hItem); // 0x0062A1E0
int __stdcall MISSILE_GetElementalLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0
D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId); // 0x00634260
void __stdcall D2COMMON_10251_Return(int nUnused); // 0x0063BD00
void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory); // 0x0063CB70
unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit); // 0x00622DE0
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pUnit); // 0x0062A530
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit); // 0x006222C0
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430
void __stdcall STATLIST_ClampStaminaManaHP(D2UnitStrc* pUnit); // 0x006275B0
unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00623D60
int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40
void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D1D0
int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory); // 0x0063E0B0
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627220
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit); // 0x0064C450
int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* hUnit); // 0x0064C260
int __stdcall MISSILE_GetActivateFrame(D2UnitStrc* pMissile); // 0x0064A640
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* ptPath, D2PathPointStrc** ppPathPoints); // 0x00648F40
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x0064A400
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A470
void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile); // 0x0064A150
int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pMonster, int bAlwaysReturnFalse); // 0x0063E8D0
void __stdcall MONSTERS_ApplyClassicScaling(D2UnitStrc* unit, int mode, unsigned char difficulty); // 0x0063EEF0
void __stdcall D2COMMON_11062_Return(int nUnused1, int nUnused2); // 0x0063EBC0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath); // 0x00648DC0
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId); // 0x006414B0
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom); // 0x0061AA40
void __stdcall D2Common_10954(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory); // 0x00647530
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* ptUnit); // 0x006217C0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList); // 0x00627340
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom); // 0x0061AD50
int __stdcall WAYPOINTS_GetLevelIdFromWaypointNo(unsigned short nWaypointNo, int* pLevelId); // 0x00660D90
D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0
void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CBE0
void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2); // 0x0061A110
void __stdcall D2Common_10077(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2); // 0x0061A9F0
int __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, unsigned int nUnitId, unsigned int bWasCounted); // 0x0063D4E0
int __fastcall DATATBLS_GetClassFromCharTemplateTxtRecord(int nTemplate, int nLevel); // 0x006657C0
int __stdcall DATATBLS_MapOldItemIndexToCurrent(int nItemId); // 0x006335A0
D2DrlgDeleteStrc* __stdcall DUNGEON_GetDrlgDeleteFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A330
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath); // 0x00648EA0
int __stdcall D2COMMON_11079_Return0(int nUnused1, int nUnused2); // 0x0062A360
void __stdcall D2COMMON_10267_Return(int nUnused1, int nUnused2); // 0x0063C550
unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* ptSkill); // 0x006450F0
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* hWeapon); // 0x006233A0
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, int nNameId); // 0x00663750
void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x00623F50
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath); // 0x00648E30
void __fastcall D2Common_10136(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nSize, unsigned short nMask, D2ActiveRoomStrc** ppRoom); // 0x0064E840
int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit); // 0x00621B00
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem); // 0x0063CD80
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc* pRoom, int nSourceLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x006195A0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0
void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDestination, D2WaypointDataStrc* pSource); // 0x00661030
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel); // 0x00663790
D2MapAIStrc* __fastcall DRLGPRESET_CreateCopyOfMapAI(D2PoolSystemStrc* pMemPool, D2MapAIStrc* pMapAI); // 0x006660B0
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc* pStatList); // 0x00626100
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* hUnit); // 0x00622D00
int __stdcall D2COMMON_11021(D2UnitStrc* pUnit); // 0x00645680
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc* pStatList, int nExpireFrame); // 0x00625310
unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem); // 0x0062E880
int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask); // 0x006229F0
int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem); // 0x0062BBD0
