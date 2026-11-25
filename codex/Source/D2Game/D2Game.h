#pragma once
struct D2ItemTypesTxt;
struct D2MapAIPathPositionStrc;
struct D2PresetUnitStrc;

struct D2PathPointStrc;

struct AiState;
struct AuraRequest;
struct D2ActiveRoomStrc;
struct D2AiControlStrc;
struct D2AiTickParamStrc;
struct D2AnimSeqTxt;
struct D2ArenaTxt;
struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2CoordStrc;
struct D2CriticalSectionStrc;
struct D2CubeMainTxt;
struct D2DamageStrc;
struct D2DataTablesStrc;
struct D2DrlgActStrc;
struct D2DynamicPathStrc;
struct D2EventTimerStrc;
struct D2GSPacketSrv5A;
struct D2GameStrc;
struct D2HirelingTxt;
struct D2HoverTextStrc;
struct D2InventoryStrc;
struct D2ItemDataTbl;
struct D2ItemDropStrc;
struct D2ItemSaveStrc;
struct D2ItemStatCostTxt;
struct D2MapAIStrc;
struct D2MissileDamageDataStrc;
struct D2MissileStrc;
struct D2MonsterInteractStrc;
struct D2ObjGroupTxt;
struct D2ObjectRegionStrc;
struct D2ObjectsTxt;
struct D2PathRecordStrc;
struct D2PlrIntroStrc;
struct D2PoolSystemStrc;
struct D2QualityItemDataTbl;
struct D2QualityItemsTxt;
struct D2QuestArgStrc;
struct D2QuestDataStrc;
struct D2RareAffixDataTbl;
struct D2RareAffixTxt;
struct D2RoomCoordListStrc;
struct D2ShrinesTxt;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2StatStrc;
struct D2TCExShortStrc;
struct D2TextHeaderStrc;
struct D2TimerArgStrc;
struct D2UniqueItemsTxt;
struct D2UnitEventStrc;
struct D2UnitFindDataStrc;
struct D2UnitStrc;
struct D2UnkMonCreateStrc2;
struct D2WaypointDataStrc;
struct Damage;
struct DataTables;
struct Difficulty;
struct Game;
struct ItemRecord;
struct ModeRequest;
struct ObjectRecord;
struct Path;
struct Point;
struct Quest;
struct Room;
struct RoomBounds;
struct Seed;
struct ShrineLists;
struct ShrineRecord;
struct Skill;
struct SkillRecord;
struct StaticPath;
struct Tables;
struct Text;
struct Unit;
struct _iobuf;
struct D2SystemTimeStrc;
struct tagRECT;

D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x00619E50
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct); // 0x0061A180
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit); // 0x006633B0
D2ArenaTxt* __fastcall DATATBLS_GetArenaTxtRecord(int nArenaType); // 0x00664AB0
D2ClientStrc* __fastcall sub_00539070_GetClientList(D2GameStrc* pGame); // 0x00539070
D2CubeMainTxt* __stdcall DATATBLS_GetCubemainTxtRecord(int nIndex); // 0x0066A1B0
D2GameStrc* __cdecl sub_0052F6E0_LockFirstGame(); // 0x0052F6E0
D2GameStrc* __fastcall sub_0052FEE0_LockGameByClientId(int nClientId); // 0x0052FEE0
D2GameStrc* __fastcall sub_00554010_GetGame(D2UnitStrc* pUnit); // 0x00554010
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel); // 0x006562F0
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemoryPool, const char* szText, int nGameFrame); // 0x00661110
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590
D2ItemStatCostTxt* __fastcall PLAYER_GetItemStatCostTxtRecord(int nStatId); // 0x0045C4F0
D2ObjGroupTxt* __stdcall DATATBLS_GetObjGroupTxtRecord(int nId); // 0x006412F0
D2ObjectRegionStrc* __fastcall OBJRGN_GetObjectRegionForLevel(D2GameStrc* pGame, int nLevelId); // 0x00546F90
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit); // 0x00621B30
D2QualityItemDataTbl* __fastcall DATATBLS_GetQualityItemDataTables(); // 0x00636B10
D2QualityItemsTxt* __stdcall DATATBLS_GetQualityItemsTxtRecord(int nIndex); // 0x00636B20
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables(); // 0x00634250
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061AD30
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId); // 0x006414B0
D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit); // 0x00621B70
D2SkillStrc* __fastcall sub_006439B0_SkillFindByOwner(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromIdAndLevel(unsigned short wTCId, int nLvl); // 0x00654E00
D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(void* pMemPool); // 0x00661240
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit); // 0x006234F0
D2UniqueItemsTxt* __fastcall sub_00483470(int nUniqueItemId); // 0x00483470
D2UnitEventStrc* __fastcall SUNITEVENT_GetEvent(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005C0BE0
D2UnitStrc* __fastcall ITEMS_DropRandomItemAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDrop); // 0x00559130
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLinkedMinionsAtOwner(D2GameStrc* pGame, D2UnitStrc* pOwner, int nMonsterId, int nAnimMode, int nMin, int nMax, short nFlags); // 0x005B24E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int a8, short nFlags); // 0x005B30E0
D2UnitStrc* __fastcall PLRSAVE2_ReadMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData, unsigned int dwVersion); // 0x0056AA50
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall sub_00558D90_SpawnItem(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
D2UnitStrc* __fastcall sub_6FC6A090(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags); // 0x005B3090
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050
ObjectRecord* __stdcall sub_00640E90_ObjectRecord(int); // 0x00640E90
Room* __stdcall sub_00620BB0(Unit*); // 0x00620BB0
Seed* __fastcall sub_00546FA0_Control(Game*,Room*); // 0x00546FA0
ShrineLists* __fastcall sub_00546FB0_Lists(Game*); // 0x00546FB0
ShrineRecord* __stdcall sub_006414B0_ShrineRecord(int); // 0x006414B0
Skill* __stdcall sub_00620250(Unit*); // 0x00620250
bool __fastcall ACT1Q1_CanClientFXBeTriggered(D2QuestDataStrc* pQuestData); // 0x00590810
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem); // 0x00628340
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
extern "C" DataTables* gVar_00744304; // 0x00744304
extern "C" ItemRecord* __stdcall sub_006335F0_Record(int); // 0x006335F0
extern "C" D2StatListStrc* __fastcall sub_0056E970_Apply(AuraRequest*); // 0x0056E970
extern "C" D2StatListStrc* __stdcall sub_006251F0_Allocate(void*, int, int, int, int); // 0x006251F0
extern "C" Unit* __stdcall sub_00553540_Target(Game*, Unit*); // 0x00553540
extern "C" Unit* __stdcall sub_0063AD90_Remove(void*, Unit*); // 0x0063AD90
extern "C" Unit* __stdcall sub_0063B2C0_First(void*); // 0x0063B2C0
extern "C" Unit* __stdcall sub_0063DFA0_Next(Unit*); // 0x0063DFA0
extern "C" Unit* __stdcall sub_0063DFD0_Item(Unit*); // 0x0063DFD0
extern "C" __declspec(dllimport) int __stdcall CopyRect(tagRECT* lprcDst, const tagRECT* lprcSrc); // 0x006CC458
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" const char gszA1Q2SourceFile[]; // 0x006E1B98
extern "C" const char gszA1Q4SourceFile[]; // 0x006E1C48
extern "C" const char gszFormatD[]; // 0x006D57BC
extern "C" const char gszMissilesSourceFile[]; // 0x006E2150
extern "C" const char gszFileModeRb[]; // 0x006CDC90
extern "C" const char gszPlayerPetsSourceFile[]; // 0x006E15D8
extern "C" const char gszSUnitDmgSourceFile; // 0x006E16C0
extern "C" const char gszSkillDruidSourceFile[]; // 0x006E30AC
extern "C" const char gszSkillPalSourceFile[]; // 0x006E323C
extern "C" const char gszSkillSorSourceFile[]; // 0x006E30C4
extern "C" const char gszTargetsSourceFile[]; // 0x006E2C78
extern "C" const char gszAiBaalSourceFile[]; // 0x006E3580
extern "C" const char szPlayerCppFile[]; // 0x006E0A1C
extern "C" int gnAct2Quest5NpcIndices[]; // 0x0073B278
extern "C" unsigned int gnA5Q2NpcActivateIndices[]; // 0x00734270
extern "C" int __fastcall sub_0045C390_Roll(Seed*, int); // 0x0045C390
extern "C" int __fastcall sub_00463860_BaseClass(Unit*); // 0x00463860
extern "C" int __fastcall sub_00463900_ValidateClass(int); // 0x00463900
extern "C" int __fastcall sub_0054DA60_Resolve(int, int); // 0x0054DA60
extern "C" int __fastcall sub_005541B0_Inactive(Unit*); // 0x005541B0
extern "C" int __fastcall sub_0056E620_Select(Unit*, int, int, int, int*, int, int); // 0x0056E620
extern "C" int __fastcall sub_00574370_Change(Game*, Unit*, int, int); // 0x00574370
extern "C" int __stdcall sub_005A7C20_SetMode(Game*, ModeRequest*, int); // 0x005A7C20
extern "C" int __stdcall sub_0062FF70_Check(Unit*, Unit*); // 0x0062FF70
extern "C" int __stdcall sub_00639DF0_HasState(Unit*, int); // 0x00639DF0
extern "C" int __stdcall sub_0063B210_Add(void*, Unit*, int); // 0x0063B210
extern "C" int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pPath); // 0x00648780
extern "C" int __stdcall sub_006488C0_X(StaticPath*); // 0x006488C0
extern "C" int __stdcall sub_00648900_Y(StaticPath*); // 0x00648900
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280
extern "C" int __stdcall sub_006510C0_ClassInfo(int, int*, int*); // 0x006510C0
extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __cdecl _chkstk(); // 0x006831B0
extern "C" void __fastcall sub_005A4850_Effect(Game*, Unit*, int, int); // 0x005A4850
extern "C" void __fastcall sub_005B0E00_Ai(Game*, Unit*, AiState*, int); // 0x005B0E00
extern "C" void __fastcall sub_005C6CC0_Configure(Unit*, D2StatListStrc*, SkillRecord*, int, int); // 0x005C6CC0
extern "C" void __stdcall sub_005A7E60_FillMode(Unit*, int, ModeRequest*); // 0x005A7E60
extern "C" void __stdcall sub_00620870_Position(Unit*, Point*); // 0x00620870
extern "C" void __stdcall sub_00621000_SetFlag(Unit*, int); // 0x00621000
extern "C" void __stdcall sub_00624690_Mode(Unit*, int); // 0x00624690
extern "C" void __stdcall sub_006252D0_State(D2StatListStrc*, int); // 0x006252D0
extern "C" void __stdcall sub_00626E10_Attach(Unit*, D2StatListStrc*, int); // 0x00626E10
extern "C" void __stdcall sub_00627150_Stat(D2StatListStrc*, int, int, int); // 0x00627150
extern "C" void __stdcall sub_00639DB0_SetState(Unit*, int, int); // 0x00639DB0
extern "C" void __stdcall sub_0063C180_Cursor(void*, Unit*); // 0x0063C180
extern "C" void __stdcall sub_0063CC70_Refresh(void*, Unit*); // 0x0063CC70
extern "C" void* __cdecl sub_00681EF0_memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __stdcall sub_00620BB0_Room(Unit*); // 0x00620BB0
extern D2DataTablesStrc* sgptDataTable; // 0x00744304
extern D2EventTimerStrc* __fastcall sub_00553980_GetTimer(D2UnitStrc*); // 0x00553980
extern Difficulty* __stdcall sub_00611D30_Difficulty(int); // 0x00611D30
extern Tables* tables; // 0x00744304
extern char gbQuestStateInitializationEnabled; // 0x0073150C
extern char gpAct1Q3NpcMessages[]; // 0x00737198
extern char gpAct1Q4NpcMessages[]; // 0x00737668
extern char gpAct2Q2NpcMessages[]; // 0x00739918
extern const char empty_assert; // 0x006CC837
extern const char gszNpcSourceFile[]; // 0x006E15F0
extern const int gaSlotRows[]; // 0x006E0B9C
extern const int gnStartingActTargetLevels[5]; // 0x006E1520
extern const int gnBaseUMods[4]; // 0x006E2168
extern const int gnBonePrisonOffsetX[12]; // 0x006E304C
extern const int gnBonePrisonOffsetY[12]; // 0x006E307C
extern const int gnExpFactorHigherLevel[11]; // 0x006E1694
extern const int gnExpFactorLowerLevel[11]; // 0x006E1668
extern const int gnMeteorSubmissileOffsetsX[18]; // 0x006E2550
extern const int gnMeteorSubmissileOffsetsY[18]; // 0x006E2598
extern const int gnPrimePoisonNovaX_006E31E8[16]; // 0x006E31E8
extern const int gnPrimePoisonNovaY[16]; // 0x006E31A8
extern const int gnSrvDo15_XPositions[64]; // 0x006E2B78
extern const int gnSrvDo15_YPositions[64]; // 0x006E2A78
extern const int gnUniqueElementalStats[5][3]; // 0x006E21B8
extern const int gnVolleyOffsetX[4]; // 0x006E3254
extern const int gnVolleyOffsetY[4]; // 0x006E3264
extern const int gnUnitListOffsets[6]; // 0x006E10E0
extern const unsigned char gnAndrialSprayDirections[8]; // 0x006E3188
extern const unsigned char gnAndrialSprayOffsets[72]; // 0x006E3140
extern const unsigned char gnMaggotLayDirections[8]; // 0x006E3138
extern int __fastcall sub_00483360_Ratio(int,int,int); // 0x00483360
extern int __fastcall sub_005C0C30_Event(Game*,int,Unit*,Unit*,Damage*); // 0x005C0C30
extern int __stdcall sub_00625480_Stat(Unit*,int,int); // 0x00625480
extern int __stdcall sub_00625500_BaseStat(Unit*,int,int); // 0x00625500
extern int __stdcall sub_00639DF0_CheckState(D2UnitStrc*, int); // 0x00639DF0
extern int __stdcall sub_00639DF0_State(Unit*,int); // 0x00639DF0
extern int __stdcall sub_0063E940_ClassA(Unit*); // 0x0063E940
extern int __stdcall sub_0063E990_ClassB(Unit*); // 0x0063E990
extern int __stdcall sub_0063E9F0_ClassC(Game*,Unit*); // 0x0063E9F0
extern int __stdcall sub_0063EDC0_ClassD(Unit*); // 0x0063EDC0
extern int __stdcall sub_0063EE90_ClassE(Unit*); // 0x0063EE90
extern int gnActCount; // 0x007326B4
extern int gnArmorStandOrRackCount; // 0x00731EB0
extern int gnArmorStandOrRackIds[]; // 0x00731EA0
extern int gnBitMasks_006CE268[8]; // 0x006CE268
extern int gnCoordInitCount; // 0x00731E64
extern int gbWriteSaveFile; // 0x007310CC
extern int gnInactiveCmdParam1; // 0x007314C0
extern int gnInactiveNoTcParam2; // 0x007314C8
extern int gnInactiveNoXpParam2; // 0x007314C4
extern int gnInitSeed; // 0x00731004
extern int gnMissileSrvDmgFnCount; // 0x0073C95C
extern int gnMissileSrvHitFnCount; // 0x0073C83C
extern int gnObeliskPowerUpCount; // 0x00732FAC
extern int gnObjectTrapHandlerCount; // 0x00732D14
extern int gnPSpellTableCount; // 0x0074178C
extern int gnPlrIntroNpcIndexMapCount; // 0x00732734
extern int gnQuestInitTableCount; // 0x00731888
extern int gnShrineTableCount; // 0x00732EAC
extern int gnAct1NpcIds[6]; // 0x007318B0
extern int gnAct2NpcIds[11]; // 0x007318C8
extern int gnAct3NpcIds[7]; // 0x007318F4
extern int gnAct5NpcIds[7]; // 0x00731910
extern unsigned char gnObjectGoreLevel; // 0x00731BBC
extern unsigned char gnObjectPopulateDensity; // 0x00731BBD
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern void __fastcall sub_005347D0_Report(Game*,Unit*,Unit*,int,int,int,int,const char*,unsigned char); // 0x005347D0
extern void __fastcall sub_005347E0_ReportAbsorb(Game*,Unit*,Unit*,int,const char*); // 0x005347E0
extern void __fastcall sub_00541400_FreeQueue(D2GameStrc*); // 0x00541400
extern void __fastcall sub_00553970_SetTimer(D2UnitStrc*, D2EventTimerStrc*); // 0x00553970
extern void* __fastcall sub_0040B430_Alloc(void*, unsigned int, const char*, int, int); // 0x0040B430
int __cdecl FOG_GetMemoryUsage(D2PoolSystemStrc* pSystem); // 0x0040A040
int __cdecl sub_00641500_ShrineCount(); // 0x00641500
int __fastcall ACT1Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590890
int __fastcall ACT1Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00591340
int __fastcall ACT1Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00592130
int __fastcall ACT2Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005989E0
int __fastcall ACT3Q4_UnitIterate_UpdateCurrentQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BA290
int __fastcall ACT5Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D8B0
int __fastcall AIUTIL_CheckAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag); // 0x005DD220
int __fastcall DATATBLS_GetCubemainTxtRecordCount(); // 0x0066A200
int __fastcall ITEMMODE_CanPickUpItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055CC90
int __fastcall MONSTERAI_GetInteractUnitCount(D2MonsterInteractStrc* pMonInteract); // 0x00572DA0
int __fastcall MONSTERAI_IsTrading(D2UnitStrc* pUnit, D2UnitStrc* pPlayer); // 0x00572EE0
int __fastcall MONSTER_CheckSummonerFlag(D2UnitStrc* pUnit, int nFlag); // 0x00573540
int __fastcall MONSTER_GetAiState(D2UnitStrc* pMonster); // 0x005734E0
int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit); // 0x00573520
int __fastcall NET_IsLocalConnection(); // 0x0052B7E0
int __fastcall SEED_GetRandomValue(int nValue); // 0x00650DE0
int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __fastcall sub_00451F70_GetUnitMode(D2UnitStrc* pUnit); // 0x00451F70
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
int __fastcall sub_00463860_GetMonsterId(D2UnitStrc* pUnit); // 0x00463860
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId); // 0x004E6C50
int __fastcall SKILLDESC_GetSkillParamFive(int nSkillId); // 0x004E6C70
int __fastcall SKILLDESC_GetSkillParamThree(int nSkillId); // 0x004EFC50
int __fastcall SKILLDESC_GetSkillParamFour(int nSkillId); // 0x004EFC80
int __fastcall sub_00560200_PlaceItem(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200
int __fastcall sub_0056A470_ReadPlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A470
int __fastcall sub_005A0070(D2UnitStrc* pUnit, int nMonType); // 0x005A0070
int __fastcall sub_005B3270(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pOwner, int nClassId, int nAnimMode, D2UnkMonCreateStrc2* a8, short nFlags); // 0x005B3270
int __fastcall sub_005B5210(D2GameStrc* pGame); // 0x005B5210
int __fastcall sub_005B9980_QuestCallback(D2QuestDataStrc* pQuestData, void* pArg); // 0x005B9980
int __fastcall sub_005C2FB0_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2FB0
int __fastcall sub_005DD290_HasClearPath(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DD290
int __fastcall sub_005E3EA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int mode, int run, int velocity, int a7); // 0x005E3EA0
int __fastcall sub_005E45D0_PetFollow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int bCombat, D2AiTickParamStrc* pTick, int a7, int a8); // 0x005E45D0
int __fastcall sub_00623C20(D2UnitStrc* pUnit); // 0x00623C20
int __fastcall sub_6FC49F80(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, unsigned char nBodyLoc); // 0x00562A30
int __fastcall sub_6FC91250(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, int nGoldAmount); // 0x00568060
int __fastcall sub_6FCD0E80(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
int __fastcall sub_6FD00370(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel); // 0x005C8980
int __fastcall sub_6FD01910(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005D2140
int __fastcall sub_6FD0B2B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C3420
int __fastcall SKILLS_ApplyResistanceImmunityPenalty(D2UnitStrc* pUnit, int nStatId, int nResist); // 0x005C3540
int __fastcall sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nAuraFilter); // 0x0056B3E0
int __fastcall sub_6FD12950(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056F640
int __fastcall sub_6FD15460(D2UnitStrc* pUnit); // 0x0056E510
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit); // 0x0064F460
int __stdcall D2COMMON_10530_D2CheckStatlistFlagDMGRed(D2UnitStrc* pUnit); // 0x00625A20
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2); // 0x00645510
int __stdcall D2COMMON_11018(D2UnitStrc* pUnit); // 0x00645590
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit); // 0x006455E0
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId); // 0x00645C10
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue); // 0x00645F00
int __stdcall D2COMMON_11068_GetCompInfo(D2UnitStrc* pUnit, int nComponent); // 0x006647C0
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom); // 0x0061A4D0
int __stdcall D2Common_10087(D2ActiveRoomStrc* pRoom); // 0x0061ABB0
int __stdcall D2Common_11034(int nSkillLevel, int nSkillId); // 0x00645B70
int __stdcall D2Common_11050(D2UnitStrc* pUnit, int a2); // 0x0063E6B0
int __stdcall DATATBLS_GetExpRatio(int nLevel); // 0x00613E60
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel); // 0x00663270
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion); // 0x0061DCA0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique); // 0x00659B80
int __stdcall DRLG_GetSaveMonstersFromLevelId(int nLevelId); // 0x00642820
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct); // 0x0061AEB0
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1F0
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId); // 0x0061ABF0
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId); // 0x0061AE30
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct); // 0x0061AE80
int __stdcall DUNGEON_HasWaypoint(D2ActiveRoomStrc* pRoom); // 0x0061A210
int __stdcall DUNGEON_IsTownLevelId(int nLevelId); // 0x0061AAF0
int __stdcall INVENTORY_CanItemsBeTraded(void* pMemPool, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int* pTradeState); // 0x0063E370
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C110
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
int __stdcall ITEMMODS_CanItemBeHighQuality(D2UnitStrc* pItem, const D2QualityItemsTxt* pQualityItemsTxtRecord); // 0x0065E7D0
int __stdcall ITEMMODS_CanItemHaveRareAffix(D2UnitStrc* pItem, const D2RareAffixTxt* pRareAffixTxtRecord); // 0x0065E710
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall ITEMS_CanBeMagic(D2UnitStrc* pItem); // 0x0062E9E0
int __stdcall ITEMS_CanBeNormal(D2UnitStrc* pItem); // 0x0062EA30
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem); // 0x0062E990
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x00628BA0
int __stdcall ITEMS_CheckItemCMDFlag(D2UnitStrc* pItem, int nFlag); // 0x00628140
int __stdcall ITEMS_CheckType(int nItemType, int nItemTypeToCheck); // 0x00629B50
int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int dwVersion); // 0x0062AE20
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0
int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem); // 0x00629F20
int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType); // 0x00628480
int __stdcall ITEMS_GetReEquip(D2UnitStrc* pItem); // 0x0062E830
int __stdcall ITEMS_GetReload(D2UnitStrc* pItem); // 0x0062E7E0
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc*,D2UnitStrc*,int,D2BitBufferStrc*,int,int); // 0x0062FDC0
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A710
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc*, D2UnitStrc*); // 0x0062A1E0
int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem); // 0x0062FDF0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem); // 0x0062A0F0
int __stdcall ITEMS_IsMetalItem(int nItemId); // 0x00629CC0
int __stdcall ITEMS_IsQuestItem(D2UnitStrc* pItem); // 0x00628CD0
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A470
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile); // 0x0064A300
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel); // 0x00663790
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster); // 0x0063EDC0
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster); // 0x0063E990
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2); // 0x0064FDC0
int __stdcall SERVER_GetClientGameGUID(int nClientId); // 0x0052B610
int __stdcall SERVER_SetClientGameGUID(int nClientId, int dwGameGuid); // 0x0052B5E0
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId); // 0x00644300
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition); // 0x006460F0
int __stdcall SKILLS_GetManaCosts(int nSkillId, int nSkillLevel); // 0x00644B10
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644E40
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644D50
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0
int __stdcall SKILLS_GetPassiveState(int nSkillId); // 0x00643690
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId); // 0x00646140
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit); // 0x00646020
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState); // 0x0063A460
int __stdcall STATES_CheckStateMaskCurseByStateId(int); // 0x0063A420
int __stdcall STATES_CheckStateMaskExpByStateId(int); // 0x0063A6B0
int __stdcall STATES_CheckStateMaskExpOnUnit(D2UnitStrc* pUnit); // 0x0063A690
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState); // 0x0063A4A0
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit); // 0x0063A770
int __stdcall STATES_IsAnyGfxStateFlagSet(D2UnitStrc* pUnit); // 0x00639F20
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00650D70
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
int __stdcall STATLIST_GetOwnerGUID(D2StatListStrc* pStatList); // 0x006252B0
int __stdcall STATLIST_GetOwnerType(D2StatListStrc* pStatList); // 0x00625250
int __stdcall STATLIST_GetState(D2StatListStrc*); // 0x006252F0
int __stdcall UNITFINDS_AreUnitsInNeighboredRooms(D2UnitStrc* pDestUnit, D2UnitStrc* pSrcUnit); // 0x0065A590
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x0064C350
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker); // 0x00622560
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit); // 0x00623B10
int __stdcall UNITS_GetMeleeRange(D2UnitStrc* pUnit); // 0x00622870
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit); // 0x00622230
int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit); // 0x00623460
int __stdcall UNITS_GetWeaponGUID(D2UnitStrc* pUnit); // 0x00623410
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit); // 0x006217C0
int __stdcall UNITS_IsCorpseUseable(D2UnitStrc* pUnit); // 0x00623600
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit); // 0x00620F50
int __stdcall UNITS_IsInRange(D2UnitStrc* pUnit, D2CoordStrc* pCoord, int nDistance); // 0x00641890
int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask); // 0x006229F0
int __stdcall sub_0061A1F0_Region(Room*); // 0x0061A1F0
int __stdcall sub_0061ABF0(int nActData, int nLevelId); // 0x0061ABF0
int __stdcall sub_00621B00_IsShrine(D2UnitStrc* pUnit); // 0x00621B00
int __stdcall sub_006253B0_GetBaseStat(D2UnitStrc*,int,int); // 0x006253B0
int __stdcall sub_00625560(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625560
int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x006270B0
int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0
int __stdcall sub_00628C70(D2UnitStrc* pItem); // 0x00628C70
int __stdcall sub_0063BDB0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc); // 0x0063BDB0
int __stdcall sub_0063EE90_IsHireling(D2UnitStrc*); // 0x0063EE90
int __stdcall SKILLS_CanUnitCorpseBeSelected(D2UnitStrc* pUnit); // 0x006456D0
int __stdcall sub_00645910_TestLine(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
int __stdcall sub_006488C0_PathGetX(D2PathRecordStrc* pPath); // 0x006488C0
int __stdcall sub_006488C0_PathX(Path*); // 0x006488C0
int __stdcall sub_00648900_PathGetY(D2PathRecordStrc* pPath); // 0x00648900
int __stdcall sub_00648900_PathY(Path*); // 0x00648900
int __stdcall sub_00648E30_GetPathValue(D2DynamicPathStrc* pPath); // 0x00648E30
long __cdecl SYSTEM_GetSyncTime(); // 0x00410A80
short __fastcall sub_6FCBA9D0(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B3F0
short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup); // 0x005C1560
unsigned char __fastcall sub_00547330_Force(Game*,int); // 0x00547330
unsigned char __fastcall sub_00547360_Limit(Game*,int); // 0x00547360
unsigned char __fastcall sub_00547430_Permit(Game*,int,int,int); // 0x00547430
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit); // 0x006222C0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem); // 0x00627DF0
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId); // 0x00628700
unsigned int __stdcall MISSILE_GetFlags(D2UnitStrc* pMissile); // 0x0064A190
unsigned short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int a2, int bForce, int a4, int bPrefix, int nAffix); // 0x005C18E0
unsigned short __fastcall sub_0057EC10(Game*,Unit*,Unit*,int,int); // 0x0057EC10
unsigned short __fastcall sub_005C1940_RollAutoAffix(D2UnitStrc* pItem, int a2, int a3, int a4, int a5, int a6, int nGroup); // 0x005C1940
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870
unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem); // 0x00627F20
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo); // 0x00627EC0
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660
void __cdecl sub_0052DF40_UnlockFirstGame(); // 0x0052DF40
void __fastcall ACT1Q4_SpawnCainPortalInTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005944F0
void __fastcall ACT2Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00599A10
void __fastcall AIUTIL_ToggleAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag, int bSet); // 0x005DD230
void __fastcall D2Common_10136(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int a3, unsigned short nMask, D2ActiveRoomStrc** ppRoom); // 0x0064E840
void __fastcall D2GAME_DropTC_6FC51360(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, D2TCExShortStrc* pTCTxtRecord, int nQuality, int nLvl, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems); // 0x0055A6D0
void __fastcall D2GAME_ITEMS_UpdateInventoryItems_6FC45050(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00
void __fastcall D2GAME_NPC_AssignMercenary_6FCCB520(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId); // 0x00579180
void __fastcall D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char a3, int a4, int a5, unsigned short a6); // 0x0053D220
void __fastcall D2GAME_PACKETS_SendPacket0xA0_A1_A2_6FC3D610(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nStatId, unsigned int nBaseValue, unsigned int nFullValue); // 0x0053BFD0
void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054EC90
void __fastcall D2GAME_RepairBrokenItem_6FC4B630(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x0055F900
void __fastcall D2GAME_UpdatePlayerVitals_6FC4B240(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055F500
void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAi); // 0x00666130
void __fastcall ITEMS_AssignStaffModsForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C1260
void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused); // 0x005AC040
void __fastcall MISSMODE_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005ADAF0
void __fastcall MONSTERUNIQUE_InitializeUMod(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A2100
void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pMonster); // 0x005738D0
void __fastcall MONSTER_SetAiState(D2UnitStrc* pMonster, int nAiState); // 0x005734C0
void __fastcall PLRINTRO_CopyBufferToNpcIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572550
void __fastcall PLRINTRO_CopyBufferToQuestIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572540
void __fastcall SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int nArg); // 0x005C9290
void __fastcall SKILLS_StatRemoveCallback_ProgressiveStrike(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D3310
void __fastcall SUNITDMG_CalculateTotalDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057C1E0
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00542B40
void __fastcall SUNIT_ResetRecurringModeChangeEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553F00
void __fastcall SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer); // 0x00553970
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall sub_0052E050_RemoveUnit(D2UnitStrc*,D2GameStrc*); // 0x0052E050
void __fastcall sub_00539230_SetWeaponSwitch(D2ClientStrc*, unsigned char); // 0x00539230
void __fastcall sub_0053B240_SendHeaderOnly0x06(int nClientId); // 0x0053B240
void __fastcall sub_00540E60(D2GameStrc*,D2UnitStrc*,int,int); // 0x00540E60
void __fastcall sub_00547390_Increment(Game*,int); // 0x00547390
void __fastcall sub_00547490_Add(Game*,int,int,int); // 0x00547490
void __fastcall sub_00553220(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553220
void __fastcall sub_0057EB10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEntry); // 0x0057EB10
void __fastcall sub_00599A20_ACT2Q2_Callback08_Empty(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00599A20
void __fastcall sub_005A9930_CreateAtMissile(D2GameStrc*, D2UnitStrc*, int); // 0x005A9930
void __fastcall sub_005B1A90(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B1A90
void __fastcall ITEMS_AssignStaffModsForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C1260
void __fastcall SKILLS_DamagePaladinCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C2FF0
void __fastcall sub_6FC32220(D2ClientStrc* pClient); // 0x00537970
void __fastcall sub_6FC35570(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5); // 0x00541650
void __fastcall sub_6FC385A0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0052D0F0
void __fastcall sub_6FC39270(D2GameStrc* pGame, int a2); // 0x0052E440
void __fastcall sub_6FC44030(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00563C00
void __fastcall sub_6FC4B830(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055FA40
void __fastcall sub_6FC61E30(D2UnitStrc* pUnit, int a2, int a3); // 0x00573090
void __fastcall sub_6FC627B0(D2UnitStrc* pUnit, int nMode); // 0x005A4F50
void __fastcall sub_6FC659E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4); // 0x00598220
void __fastcall sub_6FC7B450(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A5FF0
void __fastcall sub_6FC7D7A0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nPetType, int nPetMax); // 0x00575D90
void __fastcall sub_6FC7E310(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3, int a4); // 0x005754B0
void __fastcall sub_6FC81CA0(D2UnitStrc* pPlayer, D2ClientStrc* pClient, int a3); // 0x00548010
void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket); // 0x0054AA40
void __fastcall sub_6FC90AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678F0
void __fastcall sub_6FCBAA20(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B440
void __fastcall sub_6FCBC4D0(D2UnitStrc* pUnit); // 0x005533D0
void __fastcall sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005539B0
void __fastcall sub_6FCF5870(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0
void __fastcall sub_6FCF77E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D5220
void __fastcall sub_6FD10E20(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData); // 0x0056C2A0
void __fastcall sub_6FD11260(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nStatId, int nState, int a7); // 0x0056EBE0
void __fastcall sub_6FD14260(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams); // 0x0056D4E0
void __fastcall sub_6FD14C30(D2UnitStrc* pUnit); // 0x0056DE40
void __fastcall sub_6FD15470(D2UnitStrc* pUnit, int nAttackRate); // 0x0056E520
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0
void __stdcall D2COMMON_10190_PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nDistance); // 0x00648E40
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061A510
void __stdcall D2Common_10214(D2UnitStrc* pUnit); // 0x00649CA0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0
void __stdcall D2Common_10469(D2UnitStrc* pUnit); // 0x00627540
void __stdcall D2NET_10016(int nClientId); // 0x0052B570
void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent); // 0x006634C0
void __stdcall DUNGEON_GameTileToSubtileCoords(long* pX, long* pY); // 0x00643560
void __stdcall DUNGEON_RemoveClientFromRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0061A700
void __stdcall ENVIRONMENT_TaintedSunBegin(D2DrlgActStrc* pAct); // 0x0061C450
void __stdcall ENVIRONMENT_TaintedSunEnd(D2DrlgActStrc* pAct); // 0x0061C4D0
void __stdcall INVENTORY_CreateCorpseForPlayer(D2InventoryStrc* pInventory, int nUnitId, int a3, int a4); // 0x0063D470
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem); // 0x0065E4D0
void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
void __stdcall ITEMS_SetAutoAffix(D2UnitStrc* pItem, unsigned short nAffix); // 0x00627F50
void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, int nLevel); // 0x006283D0
void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName); // 0x00628370
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed); // 0x00627E20
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex); // 0x00628420
void __stdcall MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel); // 0x0064B860
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame); // 0x0064A5F0
void __stdcall MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel); // 0x0064AC60
void __stdcall MISSILE_SetFlags(D2UnitStrc* pMissile, unsigned int dwFlags); // 0x0064A1C0
void __stdcall MISSILE_SetLevel(D2UnitStrc* pMissile, int nSkillLevel); // 0x0064A1E0
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A400
void __stdcall MISSILE_SetSkill(D2UnitStrc* pMissile, int nSkill); // 0x0064A240
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc* pUnit, int* pMonsterId, int* pX, int* pY, int* pSpawnMode, int a6, int (__fastcall* pfnGetClassId)(D2UnitStrc*)); // 0x0063EFA0
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath); // 0x00650590
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath); // 0x00648DC0
void __stdcall PATH_SetAcceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration); // 0x00648700
void __stdcall PATH_SetMaxVelocity(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity); // 0x006486D0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic); // 0x00649F70
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestFlags, unsigned char* pBuffer, int nBufferSize, int nUnused); // 0x0065C560
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent); // 0x00646280
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit); // 0x00646F20
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode); // 0x00644340
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss); // 0x00639FB0
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame); // 0x00627460
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader); // 0x006612A0
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit); // 0x0064C450
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer); // 0x00622060
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID); // 0x006230C0
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID); // 0x00623060
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount); // 0x00621810
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit); // 0x00622F10
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit); // 0x00622EA0
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620AE0
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX); // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY); // 0x006204C0
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit); // 0x00623E00
void __stdcall UNITS_StoreLastAttacker(D2UnitStrc* pUnit, D2UnitStrc* pAttacker); // 0x00621D50
void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x00623F50
void __stdcall WAYPOINTS_ValidateAndCopyWaypointData(D2WaypointDataStrc* pSource, D2WaypointDataStrc* pDestination); // 0x006610B0
void __stdcall sub_00619730_Bounds(Room*,RoomBounds*); // 0x00619730
void __stdcall sub_00621780_SetMissileArg(D2UnitStrc* pMissile, int nArg); // 0x00621780
void __stdcall sub_00621BB0_SetShrine(Unit*,ShrineRecord*); // 0x00621BB0
void __stdcall sub_006272B0_UnitStatListCall(D2UnitStrc* pUnit, int nType, int nValue, int n0); // 0x006272B0
void __stdcall sub_00628170_SetItemCommandFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall sub_0063D1D0_InventoryItemCall(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D1D0
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode); // 0x00649190
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

#define A1Q3_INITNO 5
#define A1Q3_SEQID 6
#define ACT_I 0
#define ACT_IV 3
#define AI_RollChance(pGame, pSeed, pMonStatsTxt, nParamId) ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, nParamId))
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
#define BODYLOC_LARM 5
#define BODYLOC_RARM 4
#define BYTEFIELD(p,offset) (*(unsigned char*)((char*)(p)+(offset)))
#define CLIENTSTATE_INGAME 4
#define COLLIDE_MASK_MONSTER_PATH 0x3C01
#define COLLIDE_MASK_PLACEMENT 0x3F11
#define COLLIDE_MASK_SPAWN 0x3E01
#define D2GameReservedSlotHandle (-1)
#define D2PartyIdNone 0xFFFF
#define D2_MAYBE_UNUSED(x) (void)(x)
#define DIFFMODE_NORMAL 0
#define DRAIN_MIN 256
#define EVENTFLAG_0x1 1
#define EVENTFLAG_0x2 2
#define EVENTFLAG_0x8 8
#define EVENTTYPE_AIRESET 10
#define EVENTTYPE_PERIODICSKILLS 8
#define FIELD(p,offset) (*(int*)((char*)(p)+(offset)))
#define GAMEFLAG_ARENA_UPDATE 0x400
#define GAMETYPE_1 1
#define GAMETYPE_2 2
#define IFLAG_INSTORE 0x2000
#define IFLAG_NOEQUIP 0x4000
#define IFLAG_PERSONALIZED 0x1000000
#define IFLAG_STARTITEM 0x20000
#define INVPAGE_EQUIP 1
#define INVPAGE_INVENTORY 0
#define INVPAGE_NULL 0xFF
#define INVPAGE_TRADE 2
#define ITEMCODE_MALUS ' mdh'
#define ITEMSPAWN_GROUND 3
#define ITEMSTATCOSTFLAGINDEX_CSVSIGNED 13
#define ITEM_BOOK_BKS 0x20736B62
#define ITEM_SCROLL_BKD 0x20646B62
#define ITERSTATE_13 13
#define ITERSTATE_2 2
#define ITERSTATE_3 3
#define LINE_SCROLL_ASSERT1 0xFA
#define LINE_SCROLL_ASSERT2 0x102
#define LINE_SCROLL_DEBUG2 0x10C
#define LINE_SCROLL_DEBUG5 0xF7
#define MALUS_MIN_LEVEL 8
#define MAXIMUM(a,b) ((a) > (b) ? (a) : (b))
#define MAX_NPC_RECORDS 64
#define MISSILE_FLAGBIT(pRecord, nBit) ((pRecord)->nMissileFlags[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
#define MONTYPEFLAG_SUPERUNIQUE 2
#define MSG_CHARSI_END 163
#define MSG_CHARSI_INTRO 146
#define N0 0
#define N1 1
#define N10 10
#define N100 100
#define N108 108
#define N12 12
#define N148 148
#define N16 16
#define N18 18
#define N180 180
#define N196 196
#define N2 2
#define N20 20
#define N3 3
#define N30 30
#define N32 32
#define N4 4
#define N5 5
#define N573 573
#define N59 59
#define N716 716
#define N8 8
#define N84 84
#define NNEG1 -1
#define NRNG 0x6ac690c5u
#define NUMBER_OF_PLAYERCLASSES 7
#define NUM_ACTS 5
#define OBJECT_EXPLODINGBARREL 11
#define OBJECT_INTERACT_TRAPPED 0x80
#define PATHTYPE_WALL_FOLLOW 15
#define PCLASS_PALADIN 3
#define PETTYPE_HIREABLE 7
#define PLAYERLIST_FLAG_HOSTILE 8
#define PLRSAVE2ERROR_BAD_STATS 0x12
#define PLRSAVE2ERROR_COUNT 27
#define PLRSAVE2ERROR_NEWBIE_SAVE 2
#define PLRSAVE2ERROR_NO_CLIENT 3
#define PLRSAVE2ERROR_UNKNOWN 1
#define QFLAG_CUSTOM5 9
#define QSTATE_2 2
#define QSTATE_3 3
#define QSTATE_4 4
#define QSTATE_5 5
#define QUESTEVENT_CHANGEDLEVEL 3
#define QUESTEVENT_ITEMPICKEDUP 4
#define QUESTEVENT_MALUSREMOVED 6
#define QUESTEVENT_MONSTERKILLED 8
#define QUESTEVENT_NPCACTIVATE 0
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM 9
#define QUESTEVENT_PLAYERJOINEDGAME 14
#define QUESTEVENT_PLAYERLEAVESGAME 10
#define QUESTEVENT_PLAYERSTARTEDGAME 13
#define QUESTEVENT_SCROLLMESSAGE 11
#define QUESTSTATEFLAG_A1Q0 0
#define QUESTSTATEFLAG_A3Q1 17
#define QUESTSTATEFLAG_A3Q2 18
#define QUESTSTATEFLAG_A3Q3 19
#define QUESTSTATEFLAG_A3Q4 20
#define QUESTSTATEFLAG_A3Q6 22
#define QUESTSTATEFLAG_A4Q3 27
#define QUESTSTATEFLAG_A5Q1 35
#define QUESTSTATEFLAG_A5Q2 36
#define QUESTSTATEFLAG_A5Q3 37
#define QUESTSTATEFLAG_A5Q5 39
#define QUEST_A3Q2_KHALIMFLAIL 16
#define QUEST_A3Q4_GOLDENBIRD 0x12
#define QUEST_A3Q5_TRAVINCAL 19
#define QUEST_A3Q6_MEPHISTO 20
#define QUEST_A5Q1_SHENK 31
#define QUEST_A5Q2_RESCUESOLDIERS 32
#define QUEST_FLAGS_KIND 6
#define QUEST_FLAGS_PACKET 0x28
#define QUEST_LOG_PACKET 0x5D
#define SEED_ROLL_LIMITED_INLINE(pSeed, nMax, nResult) \
    if ((nMax) <= 0) \
    { \
        nResult = 0; \
    } \
    else if (((nMax) - 1) & (nMax)) \
    { \
        unsigned __int64 lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed; \
        (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32); \
        (pSeed)->nLowSeed = (unsigned int)lSeed; \
        nResult = (unsigned int)lSeed % (nMax); \
    } \
    else \
    { \
        unsigned __int64 lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed; \
        (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32); \
        (pSeed)->nLowSeed = (unsigned int)lSeed; \
        nResult = (unsigned int)lSeed & ((nMax) - 1); \
    }
#define SKILLS_ROLL_SEED(pSeed, lSeed) \
    (lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
     (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32), \
     (pSeed)->nLowSeed = (unsigned int)lSeed, \
     (unsigned int)lSeed)
#define SOUND_MALUS_PICKUP 36
#define STATLIST_FLAG_EXP 0x800
#define SYSERROR_UNK_14 14
#define UNIQUEITEMSFLAGINDEX_CARRY1 2
#define UNIQUEITEMSFLAGINDEX_NOLIMIT 1
#define UNITEVENT_LEVELUP 12
#define UNITFLAGEX_HASINV 0x00000001
#define UNITFLAGEX_ITEMINIT 0x00000010
#define UNITFLAGEX_STOREOWNERINFO 0x400
#define UNITFLAG_SENDREFRESHMSG 0x00001000
#define UNITFLAG_UPGRLIFENHITCLASS 0x00008000
#define UNIT_ALIGNMENT_UNASSIGNED 4
#define UNIT_CLASSID_OR_INVALID(pUnit) ((pUnit) ? (pUnit)->dwClassId : -1)
#define UNIT_LIST_MASK 0x7F

struct AiControl { char unknown00[0x14]; int param[3]; };

struct D2ArenaUnitStrc
{
    int nScore;
    int bUpdateScore;
};

struct D2CharStatsTxtRun
{
    char unk0x00[0x41];
    unsigned char nRunSpeed;
};

struct D2DamageHitClassMappingStrc
{
    int nDamageStrcOffset;
    unsigned int nHitClass;
};

struct D2EquipmentRefreshStateStrc
{
    int nHitpoints;
    int nMana;
    int nStamina;
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillOwnerGUID;
    int nLeftSkillOwnerGUID;
};

typedef int (__stdcall* D2FarProcFn)();

struct D2GSPacketSrv91
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned short pNPCFlags[12];
};

struct D2HashKeyNoneStrc
{
    char unk0x00;
};

#include "D2HotkeySkill.h"

struct D2ItemCacheStrc
{
    unsigned char nMin;
    unsigned char nMax;
    unsigned char nMagicMin;
    unsigned char nMagicMax;
    unsigned int dwCode;
    unsigned char nMagicLevel;
    char unk0x09[3];
};

struct D2ItemModeArgStrc
{
    int bIsBow;
    int bIsCrossBow;
    int bIsBowQuiver;
    int bIsCrossBowQuiver;
    int bIsShield;
    int bIsWeapon;
    int bIsTwoHanded;
    int bCanUse2Weapons;
    int bIsThrowable;
    int bIsRing;
};

struct D2ItemRatioTxt
{
    int dwUnique;
    int dwUniqueDivisor;
    int dwUniqueMin;
    int dwRare;
    int dwRareDivisor;
    int dwRareMin;
    int dwSet;
    int dwSetDivisor;
    int dwSetMin;
    int dwMagic;
    int dwMagicDivisor;
    int dwMagicMin;
    int dwHiQuality;
    int dwHiQualityDivisor;
    int dwNormal;
    int dwNormalDivisor;
};

struct D2ItemTradeStrc
{
    int nItemGUID1;
    int nItemGUID2;
    D2ItemTradeStrc* pNext;
};

struct D2ItemsTxtSpeed
{
    char unk0x00[0xD8];
    int dwSpeed;
};

struct D2LargeIntegerPartsStrc
{
    unsigned int LowPart;
    int HighPart;
};

struct D2LargeIntegerStrc
{
    __int64 QuadPart;
};

union D2LargeIntegerUnion
{
    struct
    {
        unsigned long LowPart;
        long HighPart;
    };
    __int64 QuadPart;
};

struct D2LifeSyncStrc
{
    int nUnitGUID;
    int nLifePercentage;
    int nLevelId;
    unsigned char nUpdateCount;
    D2LifeSyncStrc* pNext;
};

struct D2LinkStrc
{
    D2LinkStrc* pPrev;
    D2LinkStrc* pNext;
};

struct D2MessageStrc
{
    unsigned char nMenu;
    unsigned char pad0x01;
    unsigned short nStringId;
};

struct D2MessageListStrc
{
    unsigned char bCount;
    unsigned char pad0x01;
    D2MessageStrc pMessages[8];
};

struct D2MinionListStrc
{
    int dwMinionGUID;
    D2MinionListStrc* pNext;
};

struct D2MissileDamageDataStrc
{
    int nFlags;
    int nMinDamage;
    int nMaxDamage;
    int nFireMinDamage;
    int nFireMaxDamage;
    int nFireLength;
    int nLightMinDamage;
    int nLightMaxDamage;
    int nMagicMinDamage;
    int nMagicMaxDamage;
    int nColdMinDamage;
    int nColdMaxDamage;
    int nColdLength;
    int nPoisonMinDamage;
    int nPoisonMaxDamage;
    int nPoisonLength;
    int nPoisonCount;
    int nLifeDrainMinDamage;
    int nLifeDrainMaxDamage;
    int nManaDrainMinDamage;
    int nManaDrainMaxDamage;
    int nStaminaDrainMinDamage;
    int nStaminaDrainMaxDamage;
    int nStunLength;
    int nBurningMin;
    int nBurningMax;
    int nBurnLength;
    int nDemonDamagePercent;
    int nUndeadDamagePercent;
    int nDamageTargetAC;
    int nDamagePercent;
};

struct D2MissileUnitFindTableStrc
{
    void* pfUnitFindCallback;
    int nCollisionMask;
};

struct D2MonLvlTxt
{
    int nValues[10][3];
};

struct D2MonModeInfoTableStrc
{
    int bAlwaysEnabled;
    int unk0x04;
    int bUseMovingFlags;
};

struct D2MonStatsCountStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

struct D2MonStatsTxtRun
{
    char unk0x00[0x34];
    short nRun;
};

struct D2NecroSkeletonComponentStrc
{
    unsigned char nHead;
    unsigned char nShield;
    unsigned char nTorso;
    unsigned char nSpecial1;
    unsigned char nSpecial2;
    unsigned char nLegs;
    unsigned char nRightArm;
    unsigned char nLeftArm;
    unsigned char nRightHand;
};

struct D2NpcIndexMapStrc
{
    int nNpcClassId;
    int nIndex;
};

struct D2PackedGuidStrc
{
    unsigned short f_0;
    unsigned short f_2;
};

struct D2PackedWordStrc
{
    union
    {
        unsigned short wRaw;
        struct
        {
            unsigned short nId : 12;
            unsigned short nUnused : 3;
            unsigned short bFlag : 1;
        };
    };
    unsigned short nCount;
};

struct D2PartyNodeStrc
{
    int nUnitGUID;
    D2PartyNodeStrc* pNext;
};

struct D2PlayerListStrc
{
    int nUnitGUID;
    unsigned int dwFlags;
    int field_8;
    int field_C;
    D2PlayerListStrc* pNext;
};

struct D2PutridDefilerAiCallbackArgStrc
{
    int unk0x00;
    int nMaxDistance;
    int unk0x08[8];
};

struct D2QualityItemDataTbl
{
    int nQualityItemsTxtRecordCount;
};

struct D2QuestInitTableStrc
{
    void* pfInit;
    unsigned char bAct;
    unsigned char pad0x05[3];
    unsigned int nVersion;
    unsigned char bNoSetState;
    unsigned char pad0x0D[3];
    int nChainNo;
    int nQuestNo;
};

struct D2QuestItemPairStrc
{
    int nQuestFlag;
    unsigned char nItemQuest;
    char unk0x05[3];
};

struct D2RareAffixTxt
{
    char unk0x00[0x48];
};

struct D2RareAffixDataTbl
{
    int nRareAffixTxtRecordCount;
    D2RareAffixTxt* pRareAffixTxt;
    D2RareAffixTxt* pRareSuffix;
    D2RareAffixTxt* pRarePrefix;
};

struct D2RareAffixIndexAndPtrStrc
{
    int nIndex;
    D2RareAffixTxt* pRareAffixRecord;
};

struct D2SrvDo47Strc
{
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraTargetState;
    int nAuraStat[6];
    int nAuraStatCalcValue[6];
};

struct D2StaticFieldCallbackArgStrc
{
    int nMinDamage;
    int nDamagePct;
    int nStaticFieldMin;
    int nElementalLength;
    int nElementalType;
};

struct D2TaskStrc
{
    int dwTaskQ;
    int nType;
    D2LinkStrc pTaskBalanceLink;
    D2LinkStrc pTaskQueueLink;
};

struct D2UnitDescriptionListStrc
{
    int nClassId;
    int nCount;
    int nDefaultCount;
    char szDescription[0x80];
    D2UnitDescriptionListStrc* pNext;
};

struct D2UnitProxyArgStrc
{
    int nLevelId;
    int nCounter;
};

struct D2UnitProxyStrc
{
    D2ItemCacheStrc* pItemCache;
    int nItems;
    unsigned int* pPermCache;
    int nPerms;
};

struct D2UnkMonCreateStrc3
{
    int nXOffset;
    int nYOffset;
    int nSpawnType;
};

struct D2UnkPalSkillStrc2
{
    int nSkillId;
    int nSkillLevel;
    int nCounter;
};

struct SkillRecord
{
    unsigned char pad0[96];
    unsigned int calc;
    unsigned char pad1[130 - 100];
    short state;
    unsigned char pad2[228 - 132];
    short effect;
    unsigned char pad3[312 - 230];
    unsigned int chance;
    unsigned char pad4[572 - 316];
};

struct DataTables
{
    unsigned char pad0[196];
    int stateCount;
    unsigned char pad1[2968 - 200];
    SkillRecord* skills;
    unsigned char pad2[2976 - 2972];
    int skillCount;
};

struct HASHKEY_NONE
{
    int nUnused;
};

struct ItemRecord
{
    unsigned char pad00[128];
    unsigned int code;
};

struct Monster
{
    unsigned char pad[40];
    AiState* ai;
};

struct ObjectData
{
    unsigned int unused;
    unsigned char interact;
};

struct ObjectRecord
{
    char reserved0[N196];
    unsigned char collisions[N12];
    int sizeX;
    int sizeY;
    char reserved216[N100];
    unsigned char placement;
    char reserved317[N59];
    int selection;
    int subclass;
};

struct Path
{
    unsigned int unused0;
    unsigned int unused4;
    unsigned int unused8;
    int x;
    int y;
};

typedef unsigned char (__fastcall *Permit)(Game*,int,int,int);

struct Point
{
    int x;
    int y;
};

struct Record
{
    int damageOffset;
    int resistanceStat;
    int maximumStat;
    int pierceStat;
    int absorbPercentStat;
    int absorbFlatStat;
    int reductionIndex;
    int requiresAttackerFlag;
    int scales;
    const char* name;
    unsigned char flags;
    unsigned char tail[3];
};

struct RoomBounds
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};

struct ShrineLists
{
    int counts[N8];
    int* lists[N8];
};

struct ShrineRecord
{
    char reserved0[N180];
    unsigned int minimumLevel;
};

typedef unsigned int size_t;

typedef unsigned __int64 uint64_t;
