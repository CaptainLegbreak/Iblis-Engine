#pragma once

struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2CriticalSectionStrc;
struct D2DataTablesStrc;
struct D2DrlgFileStrc;
struct D2DrlgGridStrc;
struct D2DrlgLevelStrc;
struct D2DrlgRoomStrc;
struct D2DrlgTileGridStrc;
struct D2DynamicPathStrc;
struct D2ItemTypesTxt;
struct D2LvlMazeTxt;
struct D2LvlTypesTxt;
struct D2LvlWarpTxt;
struct D2PathPointStrc;
struct D2SetsTxt;
struct D2SkillDescTxt;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2SystemTimeStrc;
struct D2TileLibraryEntryStrc;
struct D2TileLibraryHeaderStrc;
struct D2TxtLinkStrc;
struct D2UnitStrc;
struct SkillRecord;
struct Unit;
struct _iobuf;

D2ItemTypesTxt* __fastcall sub_00555C90_GetItemTypesTxtRecord(int nItemType); // 0x00555C90
D2LvlMazeTxt* __fastcall DATATBLS_GetLvlMazeTxtRecordFromLevelId(int nLevelId); // 0x0061F490
D2LvlTypesTxt* __stdcall DATATBLS_GetLevelTypesTxtRecord(int nLevelType); // 0x0061EAA0
D2LvlWarpTxt* __fastcall DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(int nLevelId, char szDirection); // 0x0061F310
D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId); // 0x00483410
D2SkillDescTxt* __fastcall sub_004A89D0(int nSkillId); // 0x004A89D0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine); // 0x006BD040
D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine); // 0x006BD040
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine); // 0x006BD040
char* __stdcall SStrDup(const char* szString); // 0x00414310
extern "C" SkillRecord* __fastcall sub_0045C4B0_GetSkillRecord(int); // 0x0045C4B0
extern "C" Unit* __stdcall sub_00622830_GetWeapon(Unit*); // 0x00622830
extern "C" Unit* __stdcall sub_00623990_GetWeaponSlot(Unit*, int); // 0x00623990
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" char* __cdecl fgets(char* szBuffer, int nCount, _iobuf* pFile); // 0x00688271
extern "C" const char gszDrlgPresetSourceFile; // 0x006EE7C4
extern "C" const char gszDrlgPresetSourceFile_006EE7C4[]; // 0x006EE7C4
extern "C" const char gszDrlgRoomTileSourceFile; // 0x006EF540
extern "C" const char gszExcelDirectory[]; // 0x006D8ED4
extern "C" const char gszInventorySourceFile[]; // 0x006EA918
extern "C" const char gszMonsterTblsSourceFile[]; // 0x006EBE70
extern "C" const char gszNewline[]; // 0x006FFCB0
extern "C" const char gszOutRoomSourceFile; // 0x006F1F68
extern "C" const char gszPathFormat[]; // 0x006D4124
extern "C" const char gszTxtField_Expansion[]; // 0x006DCF44
extern "C" const char gszTxtField_code[]; // 0x006DCCE0
extern "C" const char gszTxtField_end[]; // 0x006D9060
extern "C" const char gszTxtField_version[]; // 0x006DCCF0
extern "C" const char gszTypeNameMappingEntryList[]; // 0x007436AC
extern "C" const char gszTypeNameStringEntryList[]; // 0x0074366C
extern "C" const char gszDataGlobal[]; // 0x006D4118
extern "C" double __cdecl cos(double x); // 0x006886C0
extern "C" double __cdecl sin(double x); // 0x00688590
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" int __cdecl fflush(_iobuf* pFile); // 0x00688927
extern "C" int __fastcall DATATBLS_ApplyRatio(int, int, int); // 0x00483360
extern "C" int __stdcall sub_006289C0_IsWeapon(Unit*); // 0x006289C0
extern "C" int __stdcall sub_00629BB0_IsItemType(Unit*, int); // 0x00629BB0
extern "C" int __stdcall sub_0062BA80_UsesThrowDamage(Unit*); // 0x0062BA80
extern "C" int __stdcall sub_0063D340_GetWeaponMode(Unit*, void*); // 0x0063D340
extern "C" int __stdcall sub_0063EE90_UsesDexterity(Unit*); // 0x0063EE90
extern "C" int __stdcall sub_00644D50_GetSkillElementMin(Unit*, int, int, int); // 0x00644D50
extern "C" int __stdcall sub_00644E40_GetSkillElementMax(Unit*, int, int, int); // 0x00644E40
extern "C" int __stdcall sub_00644F20_GetSkillElementLength(Unit*, int, int, int); // 0x00644F20
extern "C" int __stdcall sub_00645830_GetItemBonus(Unit*, Unit*, int, int); // 0x00645830
extern "C" int __stdcall sub_00647BC0_GetSkillPhysicalMin(Unit*, int, int, int); // 0x00647BC0
extern "C" int __stdcall sub_00647D00_GetSkillPhysicalMax(Unit*, int, int, int); // 0x00647D00
extern "C" int __stdcall sub_0064AF20_GetMissilePhysicalMin(Unit*, Unit*, int, int); // 0x0064AF20
extern "C" int __stdcall sub_0064AFF0_GetMissilePhysicalMax(Unit*, Unit*, int, int); // 0x0064AFF0
extern "C" int __stdcall sub_0064B100_GetMissileElementMin(Unit*, Unit*, int, int); // 0x0064B100
extern "C" int __stdcall sub_0064B1D0_GetMissileElementMax(Unit*, Unit*, int, int); // 0x0064B1D0
extern "C" unsigned char gVar_006CE268; // 0x006CE268
extern "C" unsigned char gdwBitMask6; // 0x006CE280
extern "C" unsigned char gdwBitMask7; // 0x006CE284
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" unsigned int __cdecl strcspn(const char* szString, const char* szSet); // 0x00688990
extern "C" void __cdecl _chkstk(); // 0x006831B0
extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x00685B50
extern "C" void __stdcall sub_00622E90_EndWeapon(Unit*, int); // 0x00622E90
extern "C" void __stdcall sub_00623C80_BeginWeapon(Unit*, int); // 0x00623C80
extern D2DataTablesStrc* sgptDataTable; // 0x00744304
extern D2TxtLinkStrc* gpSoundsLinker; // 0x0096BDC8
extern D2TxtLinkStrc* gTxtLink_0096C7CC; // 0x0096C7CC
extern D2TxtLinkStrc* gTxtLink_0096C800; // 0x0096C800
extern D2TxtLinkStrc* gpItemStatCostLinker; // 0x0096C800
extern D2TxtLinkStrc* gpItemTypesLinker; // 0x0096C824
extern D2TxtLinkStrc* gpMonModeLinker; // 0x0096BC5C
extern D2TxtLinkStrc* gpMonStatsLinker; // 0x0096C6AC
extern D2TxtLinkStrc* gpMonTableLinker_96C7AC; // 0x0096C7AC
extern D2TxtLinkStrc* gpPettypeLinker; // 0x0096C81C
extern D2TxtLinkStrc* gpSetItemsLinker; // 0x0096C844
extern D2TxtLinkStrc* gpTreasureClassExLinker; // 0x0096C5E8
extern D2TxtLinkStrc* gpUniqueItemsLinker; // 0x0096C850
extern const int gnIdaStarNeighborSequences[8][8]; // 0x006F17D8
extern const int gnIdaStarNeighborRandOffsets[32]; // 0x006F18D8
extern const int gaCollisionPatternsFromSize[4]; // 0x006EB3DC
extern const int gaPathDeltaTable[]; // 0x006F1E28
extern const int gnCellOffsetsToDirections[9]; // 0x006F1E18
extern const int gnMazeTombBaalPrevPresets[4][2]; // 0x006EF888
extern const int gnNextDirection1[16]; // 0x006F1EC0
extern const int gnNextDirection2[16]; // 0x006F1E40
extern const int gnPreviousDirection1[16]; // 0x006F1F00
extern const int gnPreviousDirection2[16]; // 0x006F1E80
extern const int gnSetItemStates[]; // 0x006EDB40
extern const int gnSetItemStatlistFlags[]; // 0x006EDB5C
extern const int gnSetItemsCount[]; // 0x006EDA40
// Snap offsets indexed by [delta + PATH_SNAP_CENTER], delta in -4..4
extern const int gaOffsetsForSnappingToCardinalDirection[][9]; // 0x006EB3F0
extern const int gnWallRemapIndices[]; // 0x006EF620
extern const int gnWallTileTypeRemap[6][7]; // 0x006EF578
extern int DATATBLS_LoadFromBin; // 0x00744308
extern int __fastcall sub_00674200_IsValid(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674200
extern int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
extern int gaBarricadeCliffBorderIds[][2]; // 0x006F06F0
extern int gaBorderIndices[]; // 0x006F0FD0
extern int gaBorderIndicesByDelta[]; // 0x006F1088
extern int gaBorderLevelPrestIds[][4]; // 0x006F0630
extern int gnDirectionDiffTable[]; // 0x006EB548
extern int gnHirelingTxtRecordCount; // 0x0096BDD4
extern int gnItemSetStatesBySetIndex[5]; // 0x006E90B8
extern int gnObjectsTxtRecordCount; // 0x0096D474
extern int gnShrinesTxtRecordCount; // 0x0096D46C
extern int gnSkillsCalcFunctions; // 0x007457AC
extern int gnTimeRates[]; // 0x007443E4
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern void (__fastcall* gRoomExSetStatus[4])(D2DrlgRoomStrc*); // 0x00744384
extern void (__fastcall* gRoomExUnsetStatus[4])(D2DrlgRoomStrc*); // 0x00744394
extern void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPreset, int nFile, int nFlag); // 0x006743C0
extern void* gpCharstatsTxt; // 0x0096C7F4
extern void* gpPettypeTxt; // 0x0096C818
extern void* gpSetItemsTxt; // 0x0096C848
extern void* gpSkillsCalcFunctions[]; // 0x00745774
extern void* gpUniqueItemsTxt; // 0x0096C854
float __stdcall FOG_10083_Cos_LUT(int nAngle); // 0x0040B330
float __stdcall FOG_10084_Sin_LUT(int nAngle); // 0x0040B350
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463900
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall sub_00451F70_GetUnitMode(D2UnitStrc* pUnit); // 0x00451F70
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __fastcall ITEMS_CalculateTransactionCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062EFB0
int __fastcall PATH_GetFirstDirectionXY(int nX1, int nY1, int nX2, int nY2); // 0x00678CF0
extern "C" int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn); // 0x006BD3C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int b2Handed); // 0x00625EF0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
int __stdcall TileGetStyle(D2TileLibraryEntryStrc* pTile); // 0x00604B90
int __stdcall TileGetSequence(D2TileLibraryEntryStrc* pTile); // 0x00604C50
int __stdcall sub_00629BB0_CheckItemType(D2UnitStrc* pItem, int nType); // 0x00629BB0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem); // 0x0062C0B0
int __stdcall sub_00645910_TestLine(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
int __stdcall DRLGROOMTILE_FindTilePresetUnitIndex(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor); // 0x0066D960
int* __fastcall DATATBLS_GetPortalLevels(int* pnPortalLevels); // 0x0061DDF0
unsigned char* __stdcall D2CMPPalShiftGetTransform(int nSet, int nIndex); // 0x00600C20
unsigned int __stdcall D2CMP_10079_GetTileFlags(D2TileLibraryEntryStrc* pTile); // 0x00604BC0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00411020
unsigned int __stdcall SStrPack(char* dest, const char* source, unsigned int limit); // 0x00413800
void __cdecl sub_0063D710_InitCodes(); // 0x0063D710
void __fastcall DRLGACTIVATE_RoomExPropagateSetStatus(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus); // 0x0061B390
void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags); // 0x0067CBF0
void __fastcall DRLGOUTDESR_InitAct2OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x0067F980
void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc** ppDrlgFile, void* hArchive, const char* szFile); // 0x00665F40
void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom); // 0x00667890
void __fastcall DRLGROOMTILE_AddRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EE70
void __fastcall DRLGROOMTILE_FreeRoom(D2DrlgRoomStrc* pDrlgRoom, int bKeepRoom); // 0x0066F1A0
void __fastcall DRLGROOMTILE_InitTileShadow(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, unsigned int nFlags); // 0x0066E060
void __fastcall DRLGROOMTILE_ReallocRoofTileGrid(void* pMemPool, D2DrlgTileGridStrc* pTileGrid, int nCount); // 0x0066EFB0
void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection); // 0x0066B5E0
void __fastcall DRLGROOM_FreeRoomTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B4F0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall PATHUTIL_AdvanceTowardsTarget(D2DynamicPathStrc* pPath); // 0x00679190
void __fastcall PATH_CheckPathInRoom(D2DynamicPathStrc* pPath); // 0x00647FB0
void __fastcall PATH_GetAltDirectionTriplet(int* pTestDir, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x00678DF0
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer); // 0x00411070
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DC00
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DE30
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel); // 0x006424A0
void __stdcall TileLibraryAddProject(D2TileLibraryHeaderStrc** ppList, const char* szFilePath); // 0x00604A40
void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
extern "C" void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker); // 0x006BD0B0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall UNITS_SetAnimData(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nAnimMode); // 0x00620F00
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x00413020
#define ACT_III 2
#define ACT_IV 3
#define ACT_V 4
#define AFFECTED_COUNT 64
#define BELT_COLUMNS 4
#define BELT_DEFAULT_TYPE 2
#define BELT_SLOTS 16
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
#define BODYLOC_BELT 8
#define BODYLOC_LARM 5
#define BODYLOC_RARM 4
#define BODYLOC_TORSO 3
#define COLLIDE_CORPSE 0x8000
#define COLLIDE_DOOR 0x800
#define COLLIDE_MASK_FLYING_UNIT 0x1804
#define COLLIDE_MASK_LINE 0x804
#define COLLIDE_MASK_MONSTER_PATH 0x3C01
#define COLLIDE_MASK_MONSTER_THAT_CAN_OPEN_DOORS 0x3401
#define COLLIDE_MASK_PLAYER_PATH 0x1C09
#define COLLIDE_MONSTER 0x100
#define COLLIDE_PLAYER 0x80
#define COLLISION_PATTERN_BIG_PET_PRESENCE 4
#define COLLISION_PATTERN_BIG_UNIT_PRESENCE 2
#define COLLISION_PATTERN_SMALL_NO_PRESENCE 5
#define COLLISION_PATTERN_SMALL_PET_PRESENCE 3
#define COLLISION_PATTERN_SMALL_UNIT_PRESENCE 1
#define COLLISION_UNIT_SIZE_COUNT 4
#define COMPOSIT_LEFTHAND 6
#define D2UnitInvalidGUID -1
// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ENVCYCLE_NOON 2
#define ENVCYCLE_SUNRISE 0
#define ENVPERIOD_NIGHT 2
#define ENV_FULL_CIRCLE_DEGREES 360
#define ENV_HALF_CIRCLE_DEGREES 180
#define EXTRA_OFFSET 0x5C
#define FALSE 0
#define FIELD(T, p, off) (*(T*)((u8*)(p) + (off)))
#define IFLAG_BROKEN 0x00000100
#define IFLAG_INIT 0x80000
#define IFLAG_JUSTSAVED 0x800000
#define IFLAG_LOWQUALITY 0x2000000
#define IFLAG_NOEQUIP 0x00004000
#define IFLAG_PERSONALIZED 0x1000000
#define IFLAG_RUNEWORD 0x4000000
#define IFLAG_SOCKETED 0x800
#define INVENTORY_GRID_X_LIMIT 11
#define INVGRID_BELT 1
#define INVGRID_BODYLOC 0
#define INVGRID_INVENTORY 2
#define INVPAGE_INVENTORY 0
#define ISC_FLAG_DAMAGERELATED 2
#define ISC_FLAG_FCALLBACK 11
#define ISC_FLAG_FMIN 10
#define ISC_FLAG_SAVED 12
#define ITEMMODS_ITEMSTXT() \
    D2ItemsTxt* pItemsTxtRecord; \
    if (pUnit && pUnit->dwUnitType == 4) \
    { \
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId); \
    } \
    else \
    { \
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1); \
    }
#define ITEMMODS_ROLL_MIN() \
    int nMin = pProperty->nMin; \
    int nMax = pProperty->nMax; \
    if (nMin != nMax) \
    { \
        if (nMax < nMin) \
        { \
            const int nTemp = nMax; \
            nMax = nMin; \
            nMin = nTemp; \
        } \
        int nPossibleRolls = nMax - nMin; \
        if (ITEMS_GetItemFormat(pItem) >= 1) \
        { \
            ++nPossibleRolls; \
        } \
        nMin += ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls); \
    }
#define ITEMMODS_ROLL_VALUE(nValue) \
        int nMin = pProperty->nMin; \
        int nMax = pProperty->nMax; \
        if (nMax == nMin) \
        { \
            nValue = nMin; \
        } \
        else \
        { \
            if (nMax < nMin) \
            { \
                const int nTemp = nMax; \
                nMax = nMin; \
                nMin = nTemp; \
            } \
            int nPossibleRolls = nMax - nMin; \
            if (ITEMS_GetItemFormat(pItem) >= 1) \
            { \
                ++nPossibleRolls; \
            } \
            nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls); \
        }
#define ITEMSTATCOST_HASFLAG(pRecord, nFlag) ((pRecord)->nItemStatFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])
#define ITEM_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LINE_DOOR 0x215
#define LINE_GETDIMENSIONS 2855
#define LINE_GRID_ALLOC1 721
#define LINE_GRID_ALLOC2 747
#define LINE_GRID_REALLOC 740
#define LINE_NOT_MISSILE_PATH 0x207
#define LINE_PATH_FUNCTION 0x37E
#define LINE_PATH_UNIT 0x2E8
#define LINE_PREPARE_MISSILE 0xC7
#define LINE_START_COORD 0x389
#define MASK_ALL 0xFFFF
#define MASK_INVALID 0x27
#define MONSTATSFLAGINDEX_BOSS 6
#define MONSTATSFLAGINDEX_FLYING 14
#define MONSTATSFLAGINDEX_OPENDOORS 3
#define NUM_ENVIRONMENT_CYCLES 6
#define NUM_GRID_BODYLOCS 11
#define NUM_TIME_RATES 3
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
#define OPDATA_COUNT 16
#define OPSTAT_COUNT 3
#define PATHTYPE_BLESSEDHAMMER 14
#define PATHTYPE_CHARGEDBOLT 10
#define PATHTYPE_KNOCKBACK_CLIENT 11
#define PATHTYPE_KNOCKBACK_SERVER 8
#define PATHTYPE_MISSILE 4
#define PATHTYPE_STRAIGHT 7
#define PATHTYPE_TOWARD 2
#define PATH_DIR_NULL 0xFF
#define PATH_MAX_DISTANCE 100
#define PATH_MISSILE_MASK 0x40000
#define PATH_ONE 1
#define PATH_SET_TARGET_AND_LEAVE(tPoint)                                       \
    pPathInfo->tTargetCoord.X = tPoint.X;                                       \
    pPathInfo->tTargetCoord.Y = tPoint.Y;                                       \
    if (tPoint.X == nStartX && tPoint.Y == nStartY)                             \
    {                                                                           \
        return FALSE;                                                           \
    }                                                                           \
    break;
#define PATH_SNAP_RANGE 5
#define PATH_SNAP_CENTER (PATH_SNAP_RANGE - 1)
#define PATH_TRUE 1
#define PATH_UNKNOWN_FLAG_0x00800 0x00800
#define PATH_UNKNOWN_FLAG_0x01000 0x01000
#define PCLASS_AMAZON 0
#define PCLASS_ASSASSIN 6
#define PCLASS_BARBARIAN 4
#define PCLASS_DRUID 5
#define PCLASS_INVALID 7
#define PCLASS_NECROMANCER 2
#define PCLASS_PALADIN 3
#define PCLASS_SORCERESS 1
#define SIZE_LINE 0x199
#define SKILLS_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define SKILLS_HasFlag(pSkillsTxt, nFlag) ((pSkillsTxt)->nFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])
#define STATEMASK_AURA 1
#define STATEMASK_DISGUISE 16
#define STATEMASK_HIDE 2
#define STATEMASK_MONSTAYDEATH 14
#define STATEMASK_PGSV 4
#define STATEMASK_PLRSTAYDEATH 13
#define STATES_CHECKFLAG(pRecord, nFlag) ((pRecord)->nStateFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])
#define STATLIST_DYNAMIC 0x40000000
#define STATLIST_EXTENDED 0x80000000
#define STATLIST_PERMANENT 0x20000000
#define STATS_GROWTH 4
#define STATS_SHRINK 8
#define STAT_SHIFT 16
#define STAT_GETID(nLayer_StatId) (((nLayer_StatId) >> STAT_SHIFT) & 0xFFFF)
#define STAT_GOLD 14
#define STAT_ITEM_CHARGED_SKILL 204
#define STAT_ITEM_REQ_PERCENT 91
#define STAT_MAKE(nStatId, nLayer) (((nStatId) << STAT_SHIFT) + (nLayer))
#define STAT_MAXDURABILITY 73
#define STAT_MAXSTAMINA 11
#define STAT_NONE 0xFFFF
#define STAT_QUESTITEMDIFFICULTY 356
#define STAT_STRENGTH 0
#define TBL_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define TRUE 1
#define UNITFLAGEX_ISSHAPESHIFTED 8
#define UNITFLAGEX_SERVERUNIT 0x4000000
#define UNITFLAGEX_UNK_PATH_RELATED 0x00002000
#define UNITS_IsType(pUnit, nType) ((pUnit) && (pUnit)->dwUnitType == (nType))
#define UNIT_ALIGNMENT_GOOD 2
#define UNIT_NONE 6
#define WEAPONCLASS_1HS 2
#define WEAPONCLASS_1HT 3

typedef unsigned char u8;

void __fastcall COLLISION_AllocRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064C900
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064CA10
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EA00
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags(D2UnitStrc* pUnit); // 0x00625BB0
int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2); // 0x00650350
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0
void __fastcall DATATBLS_FreeTreasureClassEx(); // 0x00654D50
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx); // 0x00613E90
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode); // 0x006117D0
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0
void __fastcall DATATBLS_LoadLevelTypesTxt(void* hArchive); // 0x0061E520
void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles); // 0x0061EBB0
void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive); // 0x00658520
void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive); // 0x00641320
void __fastcall DATATBLS_SkillCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00611BD0
void __fastcall DATATBLS_SkillDescCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00611C70
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pPreviousRoom, D2DrlgRoomStrc* pNewRoom); // 0x0061B6F0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgGridStrc* pWallGrid, int nWalls, D2DrlgGridStrc* pFloorGrid, int nFloors, D2DrlgGridStrc* pShadowGrid); // 0x0066D700
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation); // 0x0067C590
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation); // 0x0067C600
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellsFlags, int* pCellsRowOffsets); // 0x0067CBF0
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pDrlgGrid); // 0x0067CD90
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570
int* __fastcall DRLGGRID_GetGridFlagsPointer(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C550
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight); // 0x0067CB80
int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid); // 0x0067C480
int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C4A0
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid); // 0x0067CDC0
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom); // 0x0066CCB0
void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C6E0
int __fastcall DRLGLOGIC_GetRoomCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY); // 0x0066CE30
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid); // 0x0066D110
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pIgnoredRoom, int nMargin); // 0x0066B900
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId); // 0x006752A0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag); // 0x006743C0
unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741E0
D2DrlgRoomStrc* __fastcall DRLGOUTPLACE_CreateOutdoorRoomEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50); // 0x0067D540
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel); // 0x00675850
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770
void __fastcall DRLGOUTROOM_AllocDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom); // 0x0067D6D0
unsigned int __fastcall DRLGOUTROOM_CheckOutdoorRoomFlag(D2DrlgRoomStrc* pRoom); // 0x0067D7A0
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom); // 0x0067D610
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoomData(D2DrlgRoomStrc* pRoom); // 0x0067D680
void __fastcall DRLGOUTROOM_InitializeDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom); // 0x0067D710
int __fastcall DRLGOUTSIEGE_GetBorderLookupId(D2DrlgLevelStrc* pLevel); // 0x0067DCE0
void __fastcall DRLGOUTSIEGE_InitAct5OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x0067E600
void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY); // 0x0067FC20
void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom); // 0x00666AC0
void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x00666630
void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile); // 0x00668300
void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x00666610
void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x006665B0
void __fastcall DRLGPRESET_GenerateLevel(D2DrlgLevelStrc* pLevel); // 0x00668100
char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x00667010
int __fastcall DRLGPRESET_GetSizeX(int nLvlPrestId); // 0x00666FD0
int __fastcall DRLGPRESET_GetSizeY(int nLvlPrestId); // 0x00666FE0
void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x006667D0
void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc** ppDrlgFile, void* hArchive, const char* szFile); // 0x00665F40
void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom); // 0x006671E0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EEE0
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EEA0
void __fastcall DRLGROOMTILE_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileInfoGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY); // 0x0066ECE0
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileInfoGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY); // 0x0066EDB0
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation); // 0x0066D820
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EE40
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0066F240
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY); // 0x0066EC10
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970
void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection); // 0x0066B5E0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType); // 0x0066B3E0
int __fastcall DRLGROOM_GetNumberOfNearRooms(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BCF0
int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel); // 0x0066BAC0
void __fastcall DRLGROOM_UnlinkActiveRoom(D2DrlgRoomStrc* pDrlgRoom, int bClient, unsigned int nFlags); // 0x0066B4C0
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x0066AB00
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char szDirection); // 0x0066AF50
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId); // 0x0066AF30
int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY); // 0x00642520
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00642630
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel); // 0x006424A0
int __fastcall DRLG_IsTownLevel(int nLevelId); // 0x006426A0
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* ptRoom); // 0x0061A2C0
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY); // 0x00643290
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* ptRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem); // 0x0063AAF0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* hItem); // 0x0065E4D0
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30
void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState); // 0x00660120
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BE00
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType); // 0x00629A90
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* pStrength, int* pDexterity, int* pLevel); // 0x0062EAF0
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2); // 0x00629B50
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* hItem); // 0x006295B0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem); // 0x00629FE0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem); // 0x0062A0F0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...); // 0x006248E0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel); // 0x0064B340
void __fastcall MazeLevelGenerate(D2DrlgLevelStrc* ptDrlgLevel); // 0x00673B30
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2); // 0x0064FDC0
int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath); // 0x006487F0
void __fastcall PATH_GetDirections(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70
int __stdcall PATH_GetTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* hPath); // 0x00648900
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
void __fastcall PATH_SetNewDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006485F0
void __stdcall PATH_SetType(D2DynamicPathStrc* ptPath, int eType); // 0x00648CF0
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage); // 0x00644B70
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall SKILLS_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel); // 0x00646460
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit); // 0x0063A770
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
int __stdcall STATLIST_GetBaseStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625350
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625420
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList); // 0x00627340
int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x0064C350
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* hUnit); // 0x0064C370
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit); // 0x0064C450
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker); // 0x00622560
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* ptUnit); // 0x006209D0
int __stdcall UNITS_GetEventFrameInfo(D2UnitStrc* ptUnit, int nFrame); // 0x00621920
void __stdcall UNITS_GetFrameMetrics(D2UnitStrc* pUnit, int* pFrame, int* pFrameCount); // 0x00621870
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* hUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* hUnit); // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* ptUnit); // 0x00620BB0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
