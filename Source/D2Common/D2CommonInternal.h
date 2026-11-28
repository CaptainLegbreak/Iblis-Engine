#pragma once
// D2Common functions that several D2Common units call. Include after D2Common.h.

struct D2PoolSystemStrc;
struct D2BinFieldStrc;
struct D2CoordStrc;
struct D2DrlgActStrc;
struct D2DrlgCoordStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgEnvironmentStrc;
struct D2DrlgMapStrc;
struct D2DrlgOrthStrc;
struct D2DrlgStrc;
struct D2DrlgSubstGroupStrc;
struct D2DrlgTileDataStrc;
struct D2DrlgVertexStrc;
struct D2FieldStrc;
struct D2InventoryStrc;
struct D2ItemDataTbl;
struct D2ItemsTxt;
struct D2LevelDefBin;
struct D2LvlPrestTxt;
struct D2LvlSubTxt;
struct D2ObjectsTxt;
struct D2PathInfoStrc;
struct D2PresetUnitStrc;
struct D2RunesTxt;
struct D2SkillListStrc;
struct D2StatStrc;
struct D2UnkOutdoorStrc2;
struct D2UnkOutdoorStrc;
union D2SeedStrc;

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061A910
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct);                       // 0x0061AA60
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                          // 0x0061E470
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId); // 0x0061F0B0
D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId);                                                 // 0x0061FA90
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit);                                                      // 0x00622D00
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem); // 0x00628500
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006336A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc*, D2UnitStrc**, int*, int*); // 0x0063C9B0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg); // 0x00642230
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x006422A0
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg); // 0x00642A00
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                  // 0x00642BB0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel); // 0x00642C30
void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg, D2DrlgLevelStrc* pLevel);                       // 0x00642D10
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910
D2ActiveRoomStrc* __stdcall PATH_GetRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648A80
void __fastcall COLLISION_ReplaceTileCollision(D2ActiveRoomStrc* pRoom, D2DrlgTileDataStrc* pTileData, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0064C860
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60
void __fastcall PATH_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0
int __stdcall D2Common_11098(D2FieldStrc*,int*,int*); // 0x0066A5D0
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066AEC0
void __fastcall DRLGROOM_FreeRoomData(D2PoolSystemStrc* pMemPool, D2DrlgOrthStrc* pDrlgOrth);                           // 0x0066B530
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790
int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY); // 0x0066B800
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance);    // 0x0066B860
int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY);      // 0x0066B9D0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BFA0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040
D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom); // 0x0066C0B0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType); // 0x0066DC50
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DEF0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DF40
void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset); // 0x0066F520
extern int __stdcall DRLGTILESUB_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord, D2DrlgSubstGroupStrc* pGroup); // 0x0066F690
void __stdcall sub_0066FF50_SubstituteAll(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord); // 0x0066FF50
void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pLvlSubTxtRecord);                    // 0x006704E0
void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel);                                   // 0x00674B70
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines);                      // 0x00674E40
int __fastcall sub_00679B30_ComputeOffsetPath(D2PathInfoStrc* pPathInfo); // 0x00679B30
void __fastcall DRLGGRID_AlterFlagsAlongVertexEdge(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag, int eOperation, int bAlterNextVertex); // 0x0067C760
void __fastcall DRLGGRID_SetVertexGridFlags(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag); // 0x0067C890
void __fastcall DRLGGRID_FillNewCellFlags(D2PoolSystemStrc* pMemPool, D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth); // 0x0067CCC0
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(D2PoolSystemStrc* pMemPool, unsigned char nDirection); // 0x0067CDD0
void __fastcall DRLGVER_CreateVertices(D2PoolSystemStrc* pMemPool, D2DrlgVertexStrc** ppVertices, D2DrlgCoordStrc* pDrlgCoord, unsigned char nDirection, D2DrlgOrthStrc* pDrlgOrth); // 0x0067D050
void __fastcall DRLGVER_FreeVertices(D2PoolSystemStrc* pMemPool, D2DrlgVertexStrc** ppVertex); // 0x0067D1E0
void __fastcall DRLGVER_GetCoordDiff(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280
void __fastcall DRLGOUTPLACE_InitOutdoorRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D2D0
void __stdcall DRLGOUTDESR_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn); // 0x0067FE90
void __stdcall DRLGOUTDESR_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel); // 0x00680200
void __fastcall DRLGOUTDOORS_SpawnAct1DirtPaths(D2DrlgLevelStrc* pLevel);                                   // 0x00681420
