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
extern "C" const char gszExcelDirectory_006D8ED4[]; // 0x006D8ED4
extern "C" const char gszInventorySourceFile[]; // 0x006EA918
extern "C" const char gszMonsterTblsSourceFile[]; // 0x006EBE70
extern "C" const char gszNewline[]; // 0x006FFCB0
extern "C" const char gszOutRoomSourceFile; // 0x006F1F68
extern "C" const char gszPathFormat_006D4124[]; // 0x006D4124
extern "C" const char gszTxtField_Expansion[]; // 0x006DCF44
extern "C" const char gszTxtField_code[]; // 0x006DCCE0
extern "C" const char gszTxtField_end[]; // 0x006D9060
extern "C" const char gszTxtField_version[]; // 0x006DCCF0
extern "C" const char gszTypeNameMappingEntryList_007436AC[]; // 0x007436AC
extern "C" const char gszTypeNameStringEntryList_0074366C[]; // 0x0074366C
extern "C" const char gszDataGlobal[]; // 0x006D4118
extern "C" double __cdecl cos(double x); // 0x006886C0
extern "C" double __cdecl sin(double x); // 0x00688590
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" int __cdecl fflush(_iobuf* pFile); // 0x00688927
extern "C" int __fastcall sub_00483360_Ratio(int, int, int); // 0x00483360
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
extern "C" unsigned char gVar_006CE280; // 0x006CE280
extern "C" unsigned char gVar_006CE284; // 0x006CE284
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
extern D2TxtLinkStrc* gpMonModeLinker_0096BC5C; // 0x0096BC5C
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
extern const int gnOrthogonalStepTable[][9]; // 0x006EB490
extern const int gnWallRemapIndices[]; // 0x006EF620
extern const int gnWallTileTypeRemap[6][7]; // 0x006EF578
extern int DATATBLS_LoadFromBin; // 0x00744308
extern int __fastcall sub_00674200_IsValid(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674200
extern int __fastcall sub_0067C570_GetGrid(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
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
extern void __fastcall sub_006743C0_PlacePreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPreset, int nFile, int nFlag); // 0x006743C0
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
int __fastcall sub_004638A0(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __fastcall sub_0062EFB0_GetRepairCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062EFB0
int __fastcall PATH_GetFirstDirectionXY(int nX1, int nY1, int nX2, int nY2); // 0x00678CF0
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn); // 0x006BD3C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625EF0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
int __stdcall sub_00604B90_GetTileStyle(D2TileLibraryEntryStrc* pTile); // 0x00604B90
int __stdcall sub_00604C50_GetTileSequence(D2TileLibraryEntryStrc* pTile); // 0x00604C50
int __stdcall sub_00629BB0_CheckItemType(D2UnitStrc* pItem, int nType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem); // 0x0062C0B0
int __stdcall sub_00645910_TestLine(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
int __stdcall DRLGROOMTILE_FindTilePresetUnitIndex(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor); // 0x0066D960
int* __fastcall DATATBLS_GetPortalLevels(int* pnPortalLevels); // 0x0061DDF0
unsigned char* __stdcall D2CMPPalShiftGetTransform(int nSet, int nIndex); // 0x00600C20
unsigned int __stdcall D2CMP_10079_GetTileFlags(D2TileLibraryEntryStrc* pTile); // 0x00604BC0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00411020
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
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
void __fastcall PATHUtil_AdvanceTowardsTarget_6FDAB890(D2DynamicPathStrc* pPath); // 0x00679190
void __fastcall sub_6FDA8220(D2DynamicPathStrc* pPath); // 0x00647FB0
void __fastcall sub_6FDAB7D0(int* pTestDir, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x00678DF0
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer); // 0x00411070
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DC00
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DE30
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel); // 0x006424A0
void __stdcall TileLibraryAddProject(D2TileLibraryHeaderStrc** ppList, const char* szFilePath); // 0x00604A40
void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker); // 0x006BD0B0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall sub_00620F00(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nAnimMode); // 0x00620F00
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

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
