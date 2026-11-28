#pragma once

class D2NpcTradeObjStrc;
class D2SquelchListStrc;
struct D2ActiveRoomStrc;
struct D2AnimSeqTxt;
struct D2BitBufferStrc;
struct D2CacheStatsStrc;
struct D2GfxDataStrc;
struct D2CelFileStrc;
struct D2CelStrc;
struct D2CellPosStrc;
struct D2ChatMessageStrc;
struct D2ClientDialogStrc;
struct D2ClientInfoStrc;
struct D2ClientListEntryStrc;
struct D2ClientNotifyStrc;
struct D2ClientServiceStrc;
struct D2ClientSoundStrc;
struct D2CommonIgnoreListStrc;
struct D2ConfigStrc;
struct D2CoordStrc;
struct D2DataTablesStrc;
struct D2DrlgActStrc;
struct D2DrlgTileDataStrc;
struct D2DynamicPathStrc;
struct D2UnitGfxDataStrc;
struct D2GfxLayerHeaderStrc;
struct D2GfxMotionStrc;
struct D2GridCellStrc;
struct D2GridInfoStrc;
struct D2HirelingInitStrc;
struct D2HoverTextStrc;
struct D2InventoryStrc;
struct D2ItemsTxt;
struct D2LevelDefBin;
struct D2LevelsTxt;
struct D2MonAnimRecStrc;
struct D2MonModeTxt;
struct D2MonStatsInitStrc;
struct D2MsgRecordChunkStrc;
struct D2NpcEntryStrc;
struct D2ObjectsTxt;
struct D2PathPointStrc;
struct D2PresetUnitStrc;
struct D2SkillListStrc;
struct D2SkillStrc;
struct D2SoundStrc;
struct D2StatListStrc;
struct D2StatStrc;
struct D2StoredUnitRecordStrc;
struct D2TextHeaderStrc;
struct D2TileRectStrc;
struct D2TokRecord;
struct D2UIVarRecordStrc;
struct D2UnitFindDataStrc;
struct D2UnitStrc;
struct D2ViewStrc;
struct D2WallRoomArgStrc;
struct D2WaypointDataStrc;
struct D2WeatherStrc;
struct D2WinControlStrc;
struct Message;
struct Rectangle;
struct Room;
struct RoomCoordinates;
struct SMSGHANDLER_PARAMS;
struct SelectionState;
struct D2SplittedTextStrc;
struct HIMC__;
struct AsyncData;
struct Unit;
struct _FILETIME;
struct _iobuf;
struct tagRECT;

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomAt(int nX, int nY); // 0x00465420
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithMaxDistance(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighborRooms, int nMaxDistance); // 0x0064E780
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct); // 0x0061A180
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit); // 0x006633B0
D2BitBufferStrc* __cdecl sub_004B32E0_GetQuestHistory(); // 0x004B32E0
D2CacheStatsStrc* __cdecl D2GFX_GetCacheResults(); // 0x004F5290
D2ClientNotifyStrc* __cdecl WINMAIN_GetClientNotify(); // 0x0044B7B0
D2ClientServiceStrc* __cdecl BNCLIENT_GetInterfaceTable(); // 0x00518C10
D2ClientSoundStrc* __cdecl SOUNDINST_AllocSoundEntry(); // 0x004B93F0
D2CommonIgnoreListStrc* IGNORELIST_GetOrCreateIgnoreList(); // 0x00611560
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, unsigned int* pCount); // 0x00619660
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemPool, const char* szText, int nTimeout); // 0x00661110
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
D2MonModeTxt* __stdcall DATATBLS_GetMonModeTxtRecord(int nMode, int nType); // 0x0065B500
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit); // 0x00621B30
D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* ptRoom); // 0x00619FD0
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool); // 0x006438B0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill); // 0x006438F0
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* hUnit); // 0x00620150
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList(); // 0x00611560
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
D2StoredUnitRecordStrc* __fastcall ROSTER_FindRosterUnitById(int nUnitId); // 0x00479BB0
D2TileRectStrc* __stdcall DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit); // 0x00619620
D2TokRecord* __stdcall DATATBLS_GetObjModeTypeTxtRecord(unsigned int nIndex, int bGetMode); // 0x0065B570
D2TokRecord* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(unsigned int nIndex, int bGetMode); // 0x0065B480
D2UnitStrc* __fastcall CUNIT_AllocClientUnit(int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nMode); // 0x004661C0
D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
D2UnitStrc* __fastcall sub_004C5470_CreateMissileToTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004C5470
D2UnitStrc* __fastcall MISSILE_SubmitTargetRequest(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004CDD10
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType); // 0x00620290
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430
AsyncData* __fastcall FOG_AsyncDataLoadFileEx(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620
char* __fastcall FOG_inet_ntoa(int nAddress); // 0x0040E080
char* __fastcall MAINMENUS_GetSlotName(int nIndex); // 0x00430B50
char* __stdcall SStrUpper(char* szString); // 0x004141E0
const char* __fastcall sub_0047A1F0(int nIndex); // 0x0047A1F0
const char* __fastcall sub_0047A210(D2UnitStrc* pUnit); // 0x0047A210
const char* __fastcall sub_0047A210_GetPartyName(D2UnitStrc* pUnit); // 0x0047A210
const char* __fastcall sub_004BDFD0_GetObjectText(D2UnitStrc* pUnit); // 0x004BDFD0
const char* __stdcall D2CMPGetGfxFileExtension(int bAllowCompressed); // 0x005FE1F0
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
char* __stdcall ITEMS_GetVarInvGfxString(D2UnitStrc* pItem, int nId); // 0x0062E920
extern "C" SelectionState* gVar_007C0E54; // 0x007C0E54
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall SendMessageA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC49C
extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey); // 0x006CC460
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh); // 0x006CC2F0
extern "C" __declspec(dllimport) void __stdcall GetSystemTimeAsFileTime(_FILETIME* pTime); // 0x006CC358
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" const char gszAsyncLoadFailed[]; // 0x006D6CC8
extern "C" const char gszBattleNetPrefix[]; // 0x006D72B0
extern "C" const char gszCmdSquelch[]; // 0x006D5698
extern "C" const char gszCmdUnsquelch[]; // 0x006D5680
extern "C" const char gszCofPathFormat[]; // 0x006D6C94
extern "C" const char gszDataLocal[]; // 0x006D41A8
extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" const char gszFormat2u[]; // 0x006DA0CC
extern "C" const char gszGfxFile[]; // 0x006D6C1C
extern "C" const char gszMissileSourceFile[]; // 0x006DAEF4
extern "C" const char gszMonsterSourceFile[]; // 0x006DA5C8
extern "C" const char gszMonstersDir[]; // 0x006D6CAC
extern "C" const char gszNameAccountFormat[]; // 0x006D72C0
extern "C" const char gszNew[]; // 0x006CC82C
extern "C" const char gszSkillsBarSourceFile[]; // 0x006DAE58
extern "C" const char gszSpace[]; // 0x006FFC44
extern "C" const char gszTokenSeparator[]; // 0x00712FFC
extern "C" const char gszStringFormat[]; // 0x006FFC58
extern "C" const char gszUnitSndSourceFile[]; // 0x006DAEE0
extern "C" const char gszDataGlobal[]; // 0x006D4118
extern "C" const char szDataLocal_006D41A8[]; // 0x006D41A8
extern "C" const char gszFmtDecRange[]; // 0x006DBEC8
extern "C" const char gszFmtDecimal[]; // 0x006DBE94
extern "C" const char gszFormatI[]; // 0x006D6454
extern "C" const char gszFormatLd[]; // 0x006D9BE8
extern "C" const char gszFmtPlusD[]; // 0x006DBE90
extern "C" const char gszFmtPlusDecimal[]; // 0x006DBE9C
extern "C" const char gszFmtPlusRange[]; // 0x006DBEA4
extern "C" const char gszGfxUtilCpp[]; // 0x006DB974
extern "C" const char szIntFormat_006D57BC[]; // 0x006D57BC
extern "C" const char gszFormatI[]; // 0x006D6454
extern "C" const char gszPlus[]; // 0x006DBEC4
extern "C" const char gszQuote[]; // 0x006D9BF4
extern "C" const char gszSkillDescFile[]; // 0x006DBF24
extern "C" const char gszSkillsEMonCpp[]; // 0x006DBF90
extern "C" const char gszUnitModeFile[]; // 0x006D8E84
extern "C" const char* const gapszSkyPalette[2]; // 0x006D3A08
extern "C" const unsigned char gabBuiltinModuleKey[]; // 0x006D8768
extern "C" const unsigned char gabBuiltinModuleRc4Key[]; // 0x006D8778
extern "C" const unsigned char gabBuiltinModule[]; // 0x006D74B0
extern "C" const unsigned char gabExponent[]; // 0x006D8D14
extern "C" const unsigned char gabModulus[]; // 0x006D8D18
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" int __cdecl isdigit(int c); // 0x00686F0F
extern "C" int __cdecl isspace(int c); // 0x00687006
extern "C" int __cdecl toupper(int nChar); // 0x00685385
extern "C" int __fastcall sub_004B9A00_Notify(int, void*, int, int, int); // 0x004B9A00
extern "C" int __stdcall ImmSetConversionStatus(HIMC__* hImc, unsigned long nConversion, unsigned long nSentence); // 0x006B00EA
extern "C" int __stdcall ImmSetOpenStatus(HIMC__* hImc, int bOpen); // 0x006B00F0
extern "C" int __stdcall sub_00420290_QueueMessage(Message*); // 0x00420290
extern "C" int gnSubsystemActive; // 0x007A0458
extern D2BitBufferStrc* gpPlayerQuestFlags; // 0x007C0D43
extern D2BitBufferStrc* gpGameQuestFlags; // 0x007C0D47
extern D2CelFileStrc* gpAutomapCels_007A5168[4]; // 0x007A5168
extern D2ClientDialogStrc* gpTradeDialog; // 0x007C0D5F
extern D2ClientDialogStrc* gpNpcMainMenuDialog; // 0x007C0D6B
extern D2ClientDialogStrc* gpNpcMessageDialog; // 0x007C0D6F
extern D2ClientDialogStrc* gpNpcConfirmDialog; // 0x007C0D73
extern D2ClientDialogStrc* gpNpcHireDialog; // 0x007C0D77
extern D2ClientDialogStrc* gpNpcGreetingDialog; // 0x007C0D7B
extern D2ConfigStrc* gpClientConfig; // 0x007A0438
extern D2ClientListEntryStrc* gpListEntries; // 0x00724264
extern D2DataTablesStrc* sgptDataTable; // 0x00744304
extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4
extern D2MsgRecordChunkStrc* gpMsgRecordChunk_0070F7A0; // 0x0070F7A0
extern D2NpcEntryStrc* gpNpcEntry; // 0x007C0C7D
extern D2NpcTradeObjStrc* gpNpcTradeObj; // 0x007C0D83
extern D2UIVarRecordStrc* gapUIVarRecords[]; // 0x00711130
extern D2UnitStrc* gpBeltItemB_007BEFAC; // 0x007BEFAC
extern D2UnitStrc* gpEventUnit_007C0C5C; // 0x007C0C5C
extern D2UnitStrc* gpOwnerSource_007BCBF4; // 0x007BCBF4
extern D2WaypointDataStrc* gpWaypointData; // 0x007BF081
extern D2WinControlStrc* gpControl_007799F4; // 0x007799F4
extern D2WinControlStrc* gpCharNameText; // 0x00779B60
extern D2WinControlStrc* gpControl_00779C68; // 0x00779C68
extern D2WinControlStrc* gpControl_00779C80; // 0x00779C80
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern D2WinControlStrc* gpControl_00779D94; // 0x00779D94
extern D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8
extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0
extern D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC
extern D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0
extern D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4
extern D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8
D2UnitStrc* __stdcall DUNGEON_GetFirstUnitInRoom(D2ActiveRoomStrc* ptRoom); // 0x00619EA0
extern char gbQuestSlotDown; // 0x007BF2B1
extern char gbTradeClickPending; // 0x007C0DE0
extern char gszBattleNetIP[]; // 0x0070F028
extern char gszOldPassword[]; // 0x00779550
extern const char gszCUnitFile[]; // 0x006D6A48
extern const char gszDataGlobal_006D4118[]; // 0x006D4118
extern const char gszEmptyString[]; // 0x006CC837
extern const char gszFormatInt_006D57BC[]; // 0x006D57BC
extern const char gszHoverTimeFormat[]; // 0x006D6AD4
extern const char gszSkillSelFile[]; // 0x006D6AE0
extern const char gszTypeExplicitList[]; // 0x0070F584
extern const char gszTypeSGameData[]; // 0x0070F56C
extern const char* gaszQuestCelNames[]; // 0x006DA2C8
extern const int gaElemDamageColors[4]; // 0x006DBEE4
extern const int gaHitRingX[18]; // 0x006DB540
extern const int gaHitRingY[18]; // 0x006DB588
extern const int gaRandomCurseSkills[]; // 0x006DA5DC
extern const int gaSprayOffsetX[8]; // 0x006DBFA8
extern const int gaSprayOffsetY[8]; // 0x006DBFC8
extern const int gaTownSkipCels[]; // 0x006D6608
extern const int gaAdjacentDirOffsets[]; // 0x006D6B34
extern const int gaDirectionDX[]; // 0x006D6B14
extern const int gaDirectionDY[]; // 0x006D6AF4
extern const int gaUnitTypes[6]; // 0x006D6ABC
extern const unsigned char gabCdKeyMap[256]; // 0x006D59F0
extern const unsigned int gdwMask_006CE26C; // 0x006CE26C
extern const unsigned int gdwBitMask7; // 0x006CE284
extern const unsigned short gawPeriodOfDayStr[]; // 0x006DBD88
extern float gfPhaseLevel; // 0x007A89A0
extern int (__cdecl* gpfnGlobal_00726F91)(); // 0x00726F91
extern int (__cdecl* gpfnGlobal_007272EB)(); // 0x007272EB
extern int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
extern int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS*); // 0x00498DC0
extern int __fastcall sub_004B9A00_Sound(int,void*,int,int,int); // 0x004B9A00
extern int __stdcall sub_004150E0_SaveValue(const char*,const char*,int,int); // 0x004150E0
extern int gaBeltKeys[4]; // 0x00722404
extern int gaCofModes[]; // 0x00712AC4
extern int gaPlayerModes[]; // 0x00712AA0
extern int gaSetPropIds[]; // 0x006DBD70
extern int ganGlobal_007C0225[6]; // 0x007C0225
extern int ganGlobal_007C023D[6]; // 0x007C023D
extern int gaQuestPageSelection[]; // 0x007BF2BD
extern int ganRowValues_007799FC[]; // 0x007799FC
extern int gbMiniPanelButtonDown; // 0x007BEFD0
extern int gbSmallPanel; // 0x007BC978
extern int gbExitApplication; // 0x0070EE8C
extern int gnLeftClickState; // 0x0070F234
extern int gnRightClickState; // 0x0070F2BC
extern int gbClientAppActive; // 0x0070F7E0
extern int gbUIVarDelayEnabled; // 0x0070FA9C
extern int gbAutomapCenter; // 0x007113E0
extern int gbAutomapParty; // 0x007113E4
extern int gdwGlobal_00711428; // 0x00711428
extern int gdwGlobal_0071142C; // 0x0071142C
extern int gnHoverMonClassId; // 0x00711F90
extern int gnHoverClassId; // 0x00711F94
extern int gdwClientFlags; // 0x00712EFC
extern int gnCTemp; // 0x00712F00
extern int gbNpcSpeechAudio; // 0x0072AE24
extern int gfMenusDone; // 0x00779974
extern int gnSlotCount; // 0x0077998C
extern int gfHasCharEntries; // 0x00779DA4
extern int gnFrameCount; // 0x007A0494
extern int gnFpsFrameCount; // 0x007A04AC
extern int gnSkippedFrames; // 0x007A04B0
extern int gnFpsSkipCount; // 0x007A04B4
extern int gnGameType; // 0x007A0610
extern int gbNoPickup; // 0x007A6A90
extern int gdwGlobal_007A6AE0; // 0x007A6AE0
extern int gnSceneScaleFactor; // 0x007B57E4
extern int gnClientSoundsTxtRecordCount; // 0x007BC9A4
extern int gnSoundEnvironTxtRecordCount; // 0x007BC9AC
extern int gnTextNpcId; // 0x007BF202
extern int gnTextObjectId; // 0x007BF206
extern int gbTextFromObject; // 0x007BF20A
extern int gnTextHoverUnitId; // 0x007BF23B
extern int gdwGlobal_007BF250; // 0x007BF250
extern int gnInteractNpcClassId; // 0x007C0D2D
extern int gnBeltBox; // 0x0072235C
extern int gnBeltRectX; // 0x00722360
extern int gnBeltRectY; // 0x00722364
extern int gnBitMasks_006CE268[8]; // 0x006CE268
extern int gnBlinkOn; // 0x00713004
extern int gaDurabilityBodyLocs[7]; // 0x007223E8
extern int gnButtonRow; // 0x0072215C
extern int gnChatHistoryCursor; // 0x007BB5D8
extern int gnChatHistoryHead; // 0x00712F44
extern int gnChatHistoryTail; // 0x00712F48
extern int gnClearScreenCount; // 0x0070F2C0
extern int gnClientSkillDoFuncs; // 0x00727DB0
extern int gnClientSkillStartFuncs; // 0x00727A8C
extern int gnCltDoFuncs; // 0x0072A34C
extern int gnCofModeCount; // 0x00712B00
extern int gnCombinedStatCount; // 0x0072CDCC
extern int gnCursorAnimCount; // 0x007120D4
extern int gaFanOffsetX[]; // 0x006DBF50
extern int gaFanOffsetY[]; // 0x006DBF70
extern int gnLevelEffectTick; // 0x007129D0
extern int gbPlayThunderSound; // 0x00712B4C
extern int gbBlendLightColor; // 0x00712B8C
extern int gnNpcTabCount; // 0x00722158
extern int gbControlPanelMouseDown; // 0x00722358
extern int gnTextTop; // 0x007225FC
extern int gnQuestTextTop; // 0x00724210
extern int gnQuestTextLeft; // 0x00724214
extern int gnQuestTitleY; // 0x00724218
extern int gnQuestIconOffsetY; // 0x0072421C
extern int gnQuestAnimOffsetY; // 0x00724220
extern int gnKeyConfigColumn; // 0x007246D4
extern int gbKeyConfigReady; // 0x00724728
extern int gnGlobal_00726CC1; // 0x00726CC1
extern int gnGlobal_00726DF9; // 0x00726DF9
extern int gnGlobal_00726E47; // 0x00726E47
extern int gnGlobal_00726E95; // 0x00726E95
extern int gnGlobal_00726EBC; // 0x00726EBC
extern int gnGlobal_00726EE3; // 0x00726EE3
extern int gnGlobal_00726F0A; // 0x00726F0A
extern int gnGlobal_00726F31; // 0x00726F31
extern int gnGlobal_00726F7F; // 0x00726F7F
extern int gnGlobal_00727216; // 0x00727216
extern int gnGlobal_0072723D; // 0x0072723D
extern int gnGlobal_0072728B; // 0x0072728B
extern int gnGlobal_007272D9; // 0x007272D9
extern int gnHotspotCount; // 0x007278FC
extern int gnWindAngleMax; // 0x007A8998
extern int gnWindAngleMin; // 0x007A89D8
extern int gnPhaseLevel; // 0x007A89E0
extern int gnCellOriginX; // 0x007B0A54
extern int gnCellOriginY; // 0x007B0A58
extern int gnWaypointId; // 0x007BF07D
extern int gbTextBoxPending; // 0x007BF1C4
extern int gbTextPanelOpen; // 0x007BF1FA
extern int gbTextCallbackAccepted; // 0x007BF23F
extern int gnPage; // 0x007C0255
extern int gnNpcMenuState; // 0x007C0C6B
extern int gnNpcGoldSnapshot; // 0x007C0C73
extern int gnNpcEntryIndex; // 0x007C0C81
extern int gnInteractNpcId; // 0x007C0D25
extern int gbNpcInteracting; // 0x007C0D29
extern int gnNpcTradeMode; // 0x007C0D31
extern int gnTradeClickX; // 0x007C0D4B
extern int gnTradeClickY; // 0x007C0D4F
extern int gdwNpcTransactionTick; // 0x007C0D57
extern int gnNpcTransactionCost; // 0x007C0D7F
extern int gnPendingNpcActionUnitId; // 0x007C0D8E
extern int gbNpcActionPending; // 0x007C0D96
extern int gnTradeItemClassId; // 0x007C0DE1
extern int gnTradeItemUnitId; // 0x007C0DE5
extern int gdwTradeRequestTick; // 0x007C0DE9
extern int gnTradeRequestFailCount; // 0x007C0DED
extern int gdwLastTradeSendTick; // 0x007C0DF1
extern int gnGoldPanelMode; // 0x007A279C
extern int gnHandlerCount; // 0x007253DC
extern int ghHintSound; // 0x007BF24B
extern int gnHoverX; // 0x0070F854
extern int gnHoverY; // 0x0070F858
extern int gnQuestPressedSlot; // 0x007BF2B5
extern int gnQuestSelectedSlot; // 0x007BF2B9
extern int gnClientLaunchState; // 0x0070EE4C
extern int gnNpcEntryCount; // 0x0072554C
extern int gnNpcIndexCount; // 0x00725A74
extern int gnPhaseLevel; // 0x007A89E0
extern int gnKeyConfigPressedButton; // 0x007C02B4
extern int gnScreenHeight; // 0x00711470
extern int gnScreenWidth_0071146C; // 0x0071146C
extern int gnSkillSelectProcs; // 0x00711F50
extern int gaSlotState[]; // 0x007BC8F8
extern int gnState_007BF298; // 0x007BF298
extern int gaSkillTabX[][3]; // 0x00724CE4
extern int gnTargetAngle; // 0x007A89F8
extern int gnTimerUnitId; // 0x007129D4
extern int gnUIVarCount; // 0x0070F9CC
extern int gnUiRecordIndex; // 0x00722354
extern int gbMissileLights; // 0x0072A348
extern int gnVisibleRows; // 0x0070CC0C
extern int gnWardenIfaceValue; // 0x00721C94
extern int gnWaypointActCount; // 0x007224E4
extern int gnWaypointAct; // 0x007BF086
extern int gnWeatherAngle; // 0x007A89C4
extern int gnWindCountdown; // 0x007A89E4
extern short gwGlobal_00726F85; // 0x00726F85
extern short gwGlobal_007BB5F8; // 0x007BB5F8
extern short gwGlobal_007BC850; // 0x007BC850
extern unsigned char gaKeyTable[0x474]; // 0x00712220
extern unsigned char gabGlobal_007BEF30[0x30]; // 0x007BEF30
extern unsigned char gnCharClass; // 0x007A0522
extern unsigned int gaLightSampleCounts[]; // 0x006DB9D8
extern unsigned int gdwLightTick_007B9530; // 0x007B9530
extern unsigned int gnCofModeCodeCount; // 0x00712B0C
extern unsigned int gnFileIndexTextCount; // 0x0072D720
extern unsigned int gnGoldPanelValue; // 0x007A2A68
extern unsigned int gnPlayerModeCount; // 0x00712AC0
extern unsigned int gnPresetUnitId; // 0x00711F30
extern unsigned long gdwNpcRequestTimeout; // 0x007C0D53
extern unsigned long gdwHelpMenu; // 0x00722310
extern unsigned long gdwShowHpText_007BEFDC; // 0x007BEFDC
extern unsigned long gdwShowMpText_007BEFE0; // 0x007BEFE0
extern unsigned long gnTextDisplaySetting; // 0x007BF1F6
extern unsigned long gdwQuestLogToggleTick; // 0x007C0259
extern unsigned short gaCaseTable[0x100]; // 0x00730778
extern unsigned short gawRosterHostileMale[2][2]; // 0x00722450
extern unsigned short gawRosterHostileFemale[2][2]; // 0x00722458
extern unsigned short gawRosterLootMale[2][2]; // 0x00722460
extern unsigned short gawRosterLootFemale[2][2]; // 0x00722468
extern unsigned short gwBlinkDelay; // 0x00713000
extern unsigned short gnHirelingName; // 0x00725494
extern unsigned short gwGlobal_007C02C4; // 0x007C02C4
extern unsigned short gwNpcGreetingString; // 0x007C0C77
extern unsigned short gwNpcMessageString; // 0x007C0C79
extern unsigned short gwNpcLastString; // 0x007C0C7B
extern void __stdcall sub_00619730_Coordinates(Room*,RoomCoordinates*); // 0x00619730
extern void __stdcall sub_00619C40_Rectangle(Room*,Rectangle*); // 0x00619C40
extern void* gpQuestSocketsCel; // 0x007BF2D1
extern void* gpQuestBackgroundCel; // 0x007BF2D5
extern void* gpQuestTabsCel; // 0x007BF2D9
extern void* gpQuestDoneCel; // 0x007BF2DD
extern void* gpQuestLastCel; // 0x007BF34D
extern void* gpInvPsCel; // 0x007BF351
extern void* gpGemSocketCel; // 0x007BEF14
extern void* gpInvWarnCel; // 0x007BEF24
extern void* gpHostilePicCel; // 0x007BEF28
extern void* gpDuroIconCel; // 0x007BEF60
extern void* gpInvCharCel; // 0x007BEF64
extern void* gpHlthManaCel; // 0x007BEF68
extern void* gpOverlapCel; // 0x007BEF80
extern void* gpChatBuffer_007BB5F4; // 0x007BB5F4
extern void* gpGoldPanel; // 0x007A27A0
extern void* gpRunButtonCel; // 0x007BEF0C
extern void* gpGlobal_007C0D47; // 0x007C0D47
extern void* gpRes_007C0D5F; // 0x007C0D5F
extern void* gpRes_007C0D6B; // 0x007C0D6B
extern void* gpRes_007C0D6F; // 0x007C0D6F
extern void* gpRes_007C0D77; // 0x007C0D77
extern void* gpStateButtonCel; // 0x007BEF70
float __cdecl sub_00473C80(); // 0x00473C80
float __stdcall FOG_10083_Cos_LUT(int nAngle); // 0x0040B330
float __stdcall FOG_10084_Sin_LUT(int nAngle); // 0x0040B350
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
int __cdecl FOG_IsHandlingError(); // 0x00407FF0
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __cdecl sub_0040EB10(); // 0x0040EB10
int __cdecl sub_00410A80_GetTime(); // 0x00410A80
int __cdecl MAINMENUS_HasSaveFiles(); // 0x00430BC0
int __cdecl UI_IsLoadingScreenActive(); // 0x00454840
int __cdecl sub_00468730_GetMouseX(); // 0x00468730
int __cdecl sub_00468740_GetMouseY(); // 0x00468740
int __cdecl sub_00473C40(); // 0x00473C40
int __cdecl UNITMODE_GetPlayerSoundEnviron(); // 0x004817A0
int __cdecl INV_IsSellMode(); // 0x00489860
int __cdecl TEXT_CloseText(); // 0x004A08C0
int __cdecl TEXT_IsMouseOnStatButton(); // 0x004A65E0
int __cdecl TEXT_IsMouseOnSkillButton(); // 0x004A6690
int __cdecl NPCMENU_OnSelectMessage(); // 0x004B1A80
int __cdecl NPCMENU_PlayIntroMessage(); // 0x004B1B80
int __cdecl NPCMENU_PlayGossipMessage(); // 0x004B1C00
int __cdecl NPCMENU_CloseSubMenuDialog(); // 0x004B4010
int __cdecl NPCMENU_CloseConfirmDialog(); // 0x004B4070
int __cdecl NPCMENU_NextNpcMessage(); // 0x004B41C0
int __cdecl NPCMENU_GreetNpcMessage(); // 0x004B41E0
int __cdecl NPCMENU_ConfirmNpcAction(); // 0x004B4290
int __cdecl sub_004B9180(); // 0x004B9180
int __cdecl D2GFX_CheckUnitPerspective(); // 0x004F5170
int __cdecl D2GFX_IsHardwareRenderMode(); // 0x004F51C0
int __cdecl sub_004F51D0_IsPerspective(); // 0x004F51D0
int __cdecl SCALE_GetFactor(); // 0x004F65E0
int __cdecl D2Win_10003(); // 0x004F9050
int __cdecl D2SOUND_GetDirectSound(); // 0x00513B50
int __cdecl D2SOUND_IsPositionalSoundEnabled(); // 0x00513B60
int __cdecl D2SOUND_GetSoundMixerOption(); // 0x00514C90
int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80
int __cdecl CLIENT_IsConnected(); // 0x0052A640
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
int __fastcall D2GFX_SetOption(int nOption, int nValue); // 0x004F52B0
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, unsigned short nNameId); // 0x00663750
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0
int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0
int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* ptAsyncData); // 0x0040A7F0
int __fastcall MAINMENUS_ConnectToRealm(const char* szName, int bFlag); // 0x00432480
int __fastcall sub_00451F70_GetUnitMode(D2UnitStrc* pUnit); // 0x00451F70
int __fastcall UI_GetMonsterLifeFraction(D2UnitStrc* pUnit); // 0x004525F0
int __fastcall AUTOMAP_SaveAutomapParty(int nValue); // 0x004577C0
int __fastcall AUTOMAP_SaveAutomapPartyNames(int nValue); // 0x004577F0
int __fastcall PLAYER_PlayerCommand(int nMode, int nX, int nY, int nFlags); // 0x00462D00
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860
int __fastcall CUNIT_IsPetSkillTarget(D2UnitStrc*,D2UnitStrc*); // 0x00464EC0
int __fastcall CUNIT_IsTargetBlocked(D2UnitStrc*,D2UnitStrc*); // 0x00464F70
int __fastcall CUNIT_IsHostileTo(D2UnitStrc*,D2UnitStrc*); // 0x00465C60
int __fastcall CUNIT_IsUnitSelectable(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x00466870
int __fastcall SELECT_IsMonsterUnit(D2UnitStrc* pUnit, void* pArg); // 0x00467640
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode); // 0x0046C140
// build: symbol ?GFXUTIL_ForEachUnitInAdjacentRooms@* 0x0046C570
int __fastcall GFXUTIL_ForEachUnitInAdjacentRooms(D2UnitStrc* pUnit, D2UnitStrc** ppFound, int* pDistance,
    int (__fastcall* pfnCheck)(D2UnitStrc* pUnit, D2UnitStrc* pOther, D2UnitStrc** ppFound, int* pDistance)); // 0x0046C570
int __fastcall GFXUTIL_FindNearestUnitCallback(D2UnitStrc* pUnit, D2UnitStrc* pOther, D2UnitStrc** ppFound, int* pDistance); // 0x0046C600
int __fastcall GFX_FindCorpseCallback(D2UnitStrc* pUnit, D2UnitStrc* pOther, D2UnitStrc** ppFound, int* pDistance); // 0x0046C660
int __fastcall GFX_GetConvertedUnitType(D2UnitStrc* pUnit); // 0x0046D9F0
int __fastcall GFX_GetConvertedUnitMode(D2UnitStrc* pUnit); // 0x0046DA60
int __fastcall GFX_GetConvertedClassId(D2UnitStrc* pUnit); // 0x0046DAC0
int __fastcall sub_0046E100(D2UnitStrc* pUnit, int nOverlay); // 0x0046E100
int __fastcall GFX_DrawSimpleUnitShadow(D2UnitStrc* pUnit); // 0x00471450
int __fastcall ROSTER_IsHostileRelation(int nPlayerId, int nOtherId); // 0x0047A070
int __fastcall ROSTER_IsSameParty(int nUnitId1, int nUnitId2); // 0x0047A520
int __fastcall ROSTER_GetOtherPartyLife(int nUnitId); // 0x0047A6B0
int __fastcall sub_004807C0(D2UnitStrc* pUnit); // 0x004807C0
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag); // 0x00480C10
int __fastcall INV_ClickNpcPanel(SMSGHANDLER_PARAMS* pMsg); // 0x00489190
int __fastcall TEXT_IsInRightPanelButton(int nMode, int nX, int nY); // 0x004A6630
int __fastcall sub_004AC7E0_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag); // 0x004AC7E0
int __fastcall NPCMENU_GetMonsterTypeFlags(D2UnitStrc* pUnit, int nMode); // 0x004AE080
int __fastcall MONSTER_IsChampionMonster(D2UnitStrc* pUnit); // 0x004AE320
int __fastcall MONSTER_IsGhostlyMonster(D2UnitStrc* pUnit); // 0x004AE340
int __fastcall MONSTER_IsConvertible(D2UnitStrc* pUnit); // 0x004B11F0
int __fastcall MONSTER_HandleSequenceStop(D2UnitStrc* pUnit, D2MonAnimRecStrc* pRecord); // 0x004B1280
int __fastcall sub_004B95C0_IsHintPlaying(void* pHint); // 0x004B95C0
int __fastcall sub_004B9610_FindHint(int nId); // 0x004B9610
int __fastcall UNITSND_GetFootstepSound(D2UnitStrc* pUnit, int nMode); // 0x004CAEB0
int __fastcall MISSILE_GetSkillMissileRange(int nSkillId, int nSkillLevel); // 0x004CC7C0
int __fastcall GFXUTIL_IsCelOnScreen(D2CelStrc* pCel, int nX, int nY, int nArg4); // 0x004DAB40
// Also in D2ClientFuncs.h; kept here because inv_0048DD90.cpp's code changes with the number of declarations before it.
int __fastcall GFXUTIL_InitUnitCelContext(D2GfxDataStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50
int __fastcall GFXUTIL_GetComponentsMaxHeight(D2UnitStrc* pUnit, D2GfxLayerHeaderStrc* pHeader, unsigned char* pLayers, int* pOut, int nDirection, int nFrame); // 0x004DBD30
int __fastcall sub_004E4120(int nRange); // 0x004E4120
int __fastcall sub_004F2260_GetSkillCount(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004F2260
int __fastcall sub_004F9710_TestFlag(D2WinControlStrc* pControl); // 0x004F9710
int __fastcall D2Win_10127_SetFont(int nFont); // 0x00502EF0
int __fastcall D2SOUND_IsEaxEnabled(); // 0x00513B70
int __fastcall sub_00514C90_GetSoundMode(); // 0x00514C90
int __fastcall STRTABLE_LoadStringTables(void* pArg, int nArg); // 0x005259C0
int __fastcall SERVER_GetServerPacketSize(unsigned char* pPacket, unsigned int nLength, int* pSize); // 0x0052B920
int __fastcall uncompress(void* pDest, unsigned int* pDestSize, const void* pSource, unsigned int nSourceSize); // 0x006C79C0
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit); // 0x0064F460
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int bAllowDying); // 0x00645510
int __stdcall D2COMMON_11018(D2UnitStrc* pUnit); // 0x00645590
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit); // 0x006455E0
int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261B0
int __stdcall D2Common_11050(D2UnitStrc* pUnit, int a2); // 0x0063E6B0
int __stdcall D2GFX_EndScene(); // 0x004F6190
int __stdcall D2GFX_GammaCanBeControlled(); // 0x004F5260
int __stdcall D2GFX_HardwareAcceleratedRenderMode(); // 0x004F6270
int __stdcall D2GFX_SetGamma(int nGamma); // 0x004F5230
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004F60F0
int __stdcall D2Win_10125(); // 0x00501A40
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel); // 0x00611800
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel); // 0x00663270
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit); // 0x006633D0
int __stdcall DRLG_GetLOSDrawFromLevelId(int nLevelId); // 0x00642840
int __stdcall ENVIRONMENT_GetCycleIndexFromAct(D2DrlgActStrc* pAct); // 0x0061C220
int __stdcall GAME_Initialize(); // 0x00530690
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* hItem); // 0x006295B0
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062FDC0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __stdcall MISSILE_GetClassId(D2UnitStrc* pMissile); // 0x0064A3E0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile); // 0x0064A300
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster); // 0x0063E990
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0
int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pPath); // 0x00648C10
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints); // 0x006487D0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath); // 0x006486C0
int __stdcall SBigFromBinary(void* hBig, const void* pData, unsigned int nSize); // 0x00423850
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId); // 0x00644920
int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId); // 0x006447D0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647D00
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647BC0
int __stdcall SKILLS_GetParam1(D2SkillStrc* ptSkill); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* ptSkill); // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* ptSkill); // 0x00644500
int __stdcall SKILLS_GetParam4(D2SkillStrc* ptSkill); // 0x00644530
int __stdcall SKILLS_GetQuantity(D2SkillStrc* ptSkill); // 0x006450F0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* hSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall SMemCmp(const void* pLocation1, const void* pLocation2, unsigned int nSize); // 0x0041D200
int __stdcall SMsgPushRegisterState(int nType); // 0x00420360
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars); // 0x00413550
int __stdcall STATES_CheckStateMaskArmBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A550
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit); // 0x0063A3E0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320
int __stdcall STATES_CheckStateMaskRCBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A590
int __stdcall STATES_CheckStateMaskRCRedOnUnit(D2UnitStrc* pUnit); // 0x0063A630
int __stdcall STATES_CheckStateMaskRFBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A570
int __stdcall STATES_CheckStateMaskRFRedOnUnit(D2UnitStrc* pUnit); // 0x0063A610
int __stdcall STATES_CheckStateMaskRLBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A5B0
int __stdcall STATES_CheckStateMaskRLRedOnUnit(D2UnitStrc* pUnit); // 0x0063A650
int __stdcall STATES_CheckStateMaskRPBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A5D0
int __stdcall STATES_CheckStateMaskRPRedOnUnit(D2UnitStrc* pUnit); // 0x0063A670
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00650D70
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
int __stdcall TEXT_GetMenuType2NodeCount(D2TextHeaderStrc* pTextHeader); // 0x00661390
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker); // 0x00622560
int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit); // 0x00621ED0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit); // 0x006223F0
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall UNITS_GetNewDirection(D2UnitStrc* hUnit); // 0x006238C0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* ptUnit); // 0x006217C0
int __stdcall UnitIsDoor(D2UnitStrc* ptUnit); // 0x00621A70
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* hUnit); // 0x00622D00
int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit); // 0x00621B00
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0
int __stdcall WINDOW_GetState(); // 0x004F6070
int __stdcall SFileCloseFile(void* hFile); // 0x004198D0
int __stdcall SMsgPopRegisterState(void* pContext); // 0x00420320
int __stdcall MAINMENUS_OnCloseBox(int nArg); // 0x004334D0
int __stdcall sub_004DA0B0_GetUnitGfxOffsetX(D2UnitStrc* pUnit); // 0x004DA0B0
int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit); // 0x004DA0F0
int __stdcall sub_004E89A0(D2UnitStrc*, int*, int*, int*, D2SkillStrc*); // 0x004E89A0
int __stdcall TEXTURE_CelDrawEx(D2GfxDataStrc* pContext, int nX, int nY, int nTop, int nHeight, int nDrawMode); // 0x004F64E0
int __stdcall SCALE_CheckPerspectivePosition(int nPrecisionX, int nPrecisionY); // 0x004F66E0
int __stdcall CLIENT_Send(int nSize, int nFlags, void* pData); // 0x0052AE50
int __stdcall D2CMPSpriteFindAsynchSiblings(int nKeyA, int nKeyB, int nKeyC); // 0x005FF300
int __stdcall D2CMPSpriteRequest(D2GfxDataStrc* pContext); // 0x006004E0
int __stdcall CelConvertDir(unsigned int nDirection, unsigned int nDirections, int nNewDirections, int bAlt); // 0x00600CB0
int __stdcall CelGameDirToNormalDir(unsigned int nIndex, unsigned int nDirections); // 0x00600E20
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
int __stdcall DUNGEON_GetWarpDestinationLevel(D2ActiveRoomStrc* pRoom, int nSourceLevel); // 0x0061A1D0
int __stdcall DUNGEON_GetActNoFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AB30
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130
int __stdcall sub_00621050(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* ptUnit); // 0x006217C0
unsigned int __stdcall UNITS_GetNameOffsetFromObject(D2UnitStrc* ptUnit); // 0x00622270
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_GetColor(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned char* pShift, int nArg); // 0x0062C100
int __stdcall ITEMS_CanBeImbued(D2UnitStrc* pItem); // 0x0062C590
int __stdcall ITEMS_IsPersonalizable(D2UnitStrc* hItem); // 0x0062C6A0
int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem); // 0x0062C770
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem); // 0x0062E660
int __stdcall STATES_CheckStateMaskAuraOnUnit(D2UnitStrc* pUnit); // 0x0063A250
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit); // 0x0063A340
int __stdcall sub_0063B9D0_PlaceItemAt(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, int* pX, int* pY, unsigned char nPage); // 0x0063B9D0
int __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCC0
int __stdcall sub_0063BDB0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc); // 0x0063BDB0
int __stdcall INVENTORY_GetUseableItemFromBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot, int* pResult); // 0x0063C830
int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pMonster, int bAlwaysReturnFalse); // 0x0063E8D0
int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall SKILLS_IsPlayerClassSkill(int nSkillId, int* pPlayerClass); // 0x00645080
int __stdcall D2COMMON_11021(D2UnitStrc* pUnit); // 0x00645680
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nColMask); // 0x00645950
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath); // 0x00648E30
int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc* pMissile); // 0x0064A380
int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A3B0
int __stdcall MISSILE_GetElementalLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0
int __stdcall COMPOSIT_IsArmorComponent(int nComponent); // 0x0064F420
unsigned int __stdcall COMPOSIT_GetArmorTypeFromComponent(int eComponent, unsigned char* pArmorComponents); // 0x0064F500
int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath); // 0x006505C0
int __stdcall D2Common_10229(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
int __stdcall D2QSSOCKET_SendPacket(void* pConnection, const unsigned char* pBuffer, int nSize); // 0x006BC8A0
int* __fastcall sub_004AE110_GetAiTimer(D2UnitStrc* pUnit); // 0x004AE110
short __stdcall TEXT_GetStringIdOfMenuType2Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x006613C0
unsigned char __cdecl sub_0047AA20_GetClassOverride(); // 0x0047AA20
unsigned char __cdecl INV_IsCinematicBusy(); // 0x00483350
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId); // 0x0061DC20
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId); // 0x0061DBA0
unsigned char __stdcall PATH_GetNewDirection(D2DynamicPathStrc* pDynamicPath); // 0x00648810
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit); // 0x00620100
unsigned char __stdcall PALETTE_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
unsigned char __stdcall ITEMS_GetVarGfxIndex(D2UnitStrc* pItem); // 0x006283F0
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem); // 0x0062E8D0
unsigned char __stdcall MONSTERS_GetMaximalLightRadius(D2UnitStrc* pMonster); // 0x0063EBD0
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath); // 0x00648EA0
unsigned char* __fastcall GFXUTIL_GetLayerOrder(void* pGfx, int nA, int nFrame); // 0x004DB110
unsigned int __cdecl sub_0044CE60_GetPing(); // 0x0044CE60
unsigned int __cdecl D2CMPSpriteNumAsyncLoads(); // 0x005FF2A0
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData); // 0x0040AA40
unsigned int __fastcall D2SOUNDSMP_GetStreamPosition(D2SoundStrc* pSound); // 0x005159B0
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860
int __stdcall INVENTORY_GetItemGUID(D2UnitStrc* pItem); // 0x0063E000
unsigned int __stdcall ITEMS_GetAltGfx(D2UnitStrc* hItem); // 0x006285F0
unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName); // 0x006220F0
int __stdcall D2Common_11070(int nMonsterId, unsigned int nComponent, unsigned int nIndex); // 0x00664930
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
short __stdcall TEXT_GetStringIdOfMenuType0Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661400
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...); // 0x004F6890
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
struct D2PoolSystemStrc;
void __cdecl ERRORMANAGER_FreeUnusedPoolBlocks(D2PoolSystemStrc* pArg); // 0x00409B80
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __cdecl MAINMENUS_Reset(); // 0x0042F480
void __cdecl MAINMENUS_ShowConnectingPopup(); // 0x0042F6E0
void __cdecl MAINMENUS_ReturnToCharSelect(); // 0x0042FDD0
void __cdecl MAINMENUS_CreateMultiplayerScreen(); // 0x004301A0
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __cdecl MAINMENUS_CreateCharCreateScreen(); // 0x00435580
void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0
void __cdecl MAINMENUS_CreateInfoScreen(); // 0x004370C0
void __cdecl CHARSEL_InitCharSelectScreen(); // 0x0043B080
void __cdecl CHARSEL_ClearCancelled(); // 0x0043B820
void __cdecl CHARSEL_DisconnectBattleNet(); // 0x0043B9A0
void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0
void __cdecl AUTOMAP_SaveAutomapLayer(); // 0x004584C0
void __cdecl AUTOMAP_ResetAutomapCells(); // 0x00458680
void __cdecl AUTOMAP_LoadAutomapLayer(); // 0x00458750
void __cdecl CMDTBL_RestoreHotkeys(); // 0x00469D50
void __cdecl sub_00472610(); // 0x00472610
void __cdecl DLIGHTMAP_RunLightPass(); // 0x00475800
void __cdecl sub_00477EE0(); // 0x00477EE0
void __cdecl sub_00480340(); // 0x00480340
void __cdecl INV_ResetNpcState(); // 0x00487B30
void __cdecl INV_RestoreSelectedShopButton(); // 0x00488F10
void __cdecl INV_QuestCodeUpdate(); // 0x0048A540
void __cdecl INV_ResetNpcCursor(); // 0x0048A6A0
void __cdecl VIEW_InitTextColorRed(); // 0x00497250
void __cdecl HIREABLES_InitTextColorA(); // 0x00497270
void __cdecl HIREABLES_InitTextColorB(); // 0x00497290
void __cdecl VIEW_InitBeltColors(); // 0x004972B0
void __cdecl PANEL_SetRedColour(); // 0x00499E10
void __cdecl TEXT_FillListBox(); // 0x0049E340
void __cdecl QUESTLOG_FreeQuestCels(); // 0x004A2550
void __cdecl TEXT_LayoutSlider(); // 0x004A5060
void __cdecl TEXT_RegisterKeyCaptureHandlers(); // 0x004A5D00
void __cdecl sub_004AB2F0(); // 0x004AB2F0
void __cdecl NPCMENU_ShowTradeDialog(); // 0x004B2F50
void __cdecl sub_004BA8F0_StopSongs(); // 0x004BA8F0
void __cdecl SOUNDINST_LockSpeechSounds(); // 0x004BAA50
void __cdecl SOUNDINST_RefreshGroupTimers(); // 0x004BAAB0
void __cdecl USEITEM_CloseUseItemPanel(); // 0x004C0090
void __cdecl sub_004C0440(); // 0x004C0440
void __cdecl sub_004DCA30(); // 0x004DCA30
void __cdecl SCALE_SetDefaultFactorPerspectiveFactor(); // 0x004F6830
void __cdecl sub_004FA550(); // 0x004FA550
void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70
void __cdecl D2SOUNDFAST_FadeOutWaves(); // 0x00515020
void __cdecl STRTABLE_UnloadStringTables(); // 0x00524E40
void __cdecl GAME_ProcessNetworkMessages(); // 0x0052CFE0
void __cdecl GAME_CloseAllGames(); // 0x0052E9C0
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...); // 0x006248E0
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile); // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void __fastcall D2SOUND_10034(int nArg); // 0x005148F0
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall FOG_GetInstallPath(char* szPath, int nBufferSize); // 0x00406BA0
int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0
void __fastcall FOG_AsyncDataFree(AsyncData* ptAsyncData); // 0x0040AB00
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall CHARSEL_SetFlagBit2(int bSet); // 0x0043C6A0
void __fastcall UI_BuildItemHoverName(D2UnitStrc* pUnit, int nA, int nB); // 0x004527D0
void __fastcall UI_TogglePanelHandlers(int bSet); // 0x004545C0
void __fastcall UI_ClearPanelHandlers(int nUIVar); // 0x00455AE0
void __fastcall UI_DrawLoadingScreen(int nArg); // 0x004565E0
void __fastcall AUTOMAP_RefreshItemStats(D2UnitStrc* pUnit); // 0x0045D3E0
void __fastcall PLAYER_InitClientPlayer(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00460BF0
void __fastcall PLAYER_FreeClientPlayer(D2UnitStrc* pUnit); // 0x00460D50
void __fastcall CUNIT_SetBasePalShiftIndex(D2UnitStrc* pUnit, int bSet); // 0x00463E20
void __fastcall CUNIT_SetPalShiftIndex(D2UnitStrc* pUnit, int bSet); // 0x00463E80
void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0
void __fastcall CUNIT_SetStartLight(D2UnitStrc* pUnit, int nRadius); // 0x00464CF0
void __fastcall CUNIT_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg); // 0x00465BF0
void __fastcall CUNIT_RemoveServerSideUnit(int nUnitId, int nUnitType); // 0x00465F00
void __fastcall CMDTBL_SetHotkeyHandlers(int nArg1, int nArg2); // 0x0046AA20
void __fastcall sub_0046BFF0(D2UnitStrc* pUnit); // 0x0046BFF0
void __fastcall GFX_SetGfxMotionFlag(D2UnitStrc* pUnit, D2GfxMotionStrc* pMotion); // 0x0046F070
void __fastcall GFX_SetGfxBasePalShift(D2UnitGfxDataStrc* pGfxData, int nValue); // 0x0046F1C0
void __fastcall GFX_SetGfxPalShift(D2UnitGfxDataStrc* pGfxData, int nValue); // 0x0046F220
void __fastcall GFX_LoadMonsterCofs(int nItemId, int nArg); // 0x0046F870
void __fastcall GFX_DrawUnitShadow(D2CellPosStrc* pPos); // 0x00471620
void __fastcall sub_00472DA0(int nX, int nY, int nSubX, int nSubY); // 0x00472DA0
void __fastcall sub_00472EC0(int nX, int nY, int nSubX, int nSubY); // 0x00472EC0
void __fastcall VIEW_SetViewRects(D2ViewStrc* pView, int nLeft, int nTop, int nRight, int nBottom); // 0x00476000
void __fastcall SCMD_StartTimedEffect(int nArg1, int nArg2, int nArg3, int nArg4); // 0x00476A80
void __fastcall ROSTER_ToggleLoot(D2StoredUnitRecordStrc* pEntry); // 0x00479DA0
void __fastcall ROSTER_ToggleMute(D2StoredUnitRecordStrc* pEntry); // 0x00479DE0
void __fastcall ROSTER_ToggleSquelch(D2StoredUnitRecordStrc* pEntry); // 0x00479E20
void __fastcall ROSTER_ToggleHostile(D2StoredUnitRecordStrc* pEntry); // 0x00479FE0
void __fastcall SOUNDHDR_AddVariantRefs(int nId, int nValue); // 0x004822B0
void __fastcall SOUNDHDR_ClearVariantRefs(int nId); // 0x00482370
void __fastcall SOUNDHDR_GetSoundPath(int nIndex, char* szPath); // 0x00482710
void __fastcall TEXT_FreeHoverText(void* pSoundData); // 0x0049F3D0
void __fastcall TEXT_HandleChatPacket(D2ChatMessageStrc* pMessage); // 0x0049F490
void __fastcall TEXT_ShowNpcMessage(D2UnitStrc* pUnit, unsigned short nMessage, int nArg); // 0x004A10E0
void __fastcall QUESTLOG_SendQuestUpdates(int nCount); // 0x004A2760
void __fastcall sub_004AC780_SetMonsterWord(D2UnitStrc* pUnit, unsigned short nValue); // 0x004AC780
void __fastcall MONUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet); // 0x004AC810
void __fastcall MONUNIQUE_ApplyUMods(D2UnitStrc* pUnit); // 0x004AD020
void __fastcall MONSTER_OwnerMissileHit(D2UnitStrc* pUnit); // 0x004AE3C0
void __fastcall MONSTER_ChangeMonsterClass(D2UnitStrc* pUnit, int nMonsterId); // 0x004AEDD0
void __fastcall MONSTER_SpawnBloodMissiles(D2UnitStrc* pUnit, int nArg1, int nArg2); // 0x004AF890
void __fastcall NPCMENU_CancelNpcAndFlag(int nUnitId); // 0x004B3D10
void __fastcall SOUNDINST_MoveSound(int nHandle, int nPan, int nVolume, int nArg); // 0x004B99A0
void __fastcall OBJECT_InitObject(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nArg); // 0x004BC720
void __fastcall OBJECT_SetShrine(D2UnitStrc* pUnit); // 0x004BD6B0
void __fastcall ITEM_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nArg, int bFlag); // 0x004C1910
void __fastcall SKILLS_ScaleUpDirection(int* pX, int* pY); // 0x004C5390
void __fastcall SKILLS_AttachMissileLight(D2UnitStrc* pUnit, int nAuraFunc); // 0x004C5680
void __fastcall SKILLSPAL_DrawMotionTrail(D2UnitStrc* pUnit, int nArg, int bForward); // 0x004C9990
void __fastcall UNITSND_AddUnitSfx(D2UnitStrc* pUnit, int nHandle); // 0x004CA8A0
void __fastcall UNITSND_UpdateFootsteps(D2UnitStrc* pUnit); // 0x004CAF60
void __fastcall sub_004CBDE0_PetCommand(int nPetId, char bFlag, int nSkill); // 0x004CBDE0
void __fastcall UNITSND_AddUnitSoundRefs(D2UnitStrc* pUnit, int nValue); // 0x004CC160
void __fastcall UNITSND_UpdateUnitSound(D2UnitStrc* pUnit, int nMode, int nArg); // 0x004CC5B0
void __fastcall MISSILE_InitFromOwner(D2UnitStrc* pMissile); // 0x004CC870
void __fastcall MISSILE_SubmitWithDirection(D2UnitStrc* pMissile, int nMissile); // 0x004CED20
D2UnitStrc* __fastcall MISSILE_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg); // 0x004D2D70
void __fastcall GFXUTIL_SetMotionFlag10(D2UnitStrc* pUnit, int nArg); // 0x004DA620
void __fastcall GFXUTIL_SetGfxEntryByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue); // 0x004DB1C0
void __fastcall sub_004DC7B0(D2CellPosStrc* pPos, unsigned int nColor, int nArg); // 0x004DC7B0
void __fastcall GFXUTIL_ApplySoundEnviron(int nEnvironId); // 0x004DF6C0
void __fastcall sub_004DF7B0(void* pStream); // 0x004DF7B0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet); // 0x004F9740
void __fastcall D2Win_10179_UpdatePaletteFlash(); // 0x004FB0D0
void __fastcall D2Win_10176_StartPaletteFlash(int bActive); // 0x004FB130
void __fastcall sub_004FB480_SetActA(unsigned char nAct); // 0x004FB480
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall D2Win_10200(D2SplittedTextStrc* pLines); // 0x005028A0
void __fastcall D2SOUND_10034(int nValue); // 0x005148F0
void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0
void __fastcall D2SOUNDSMP_StopSound(D2SoundStrc* pSound); // 0x00515EE0
void __fastcall sub_005179A4_VirtualFree(void* pMemory); // 0x005179A4
void __fastcall PLAYER_SetVirtualPlayerCount(int nPlayers); // 0x00535780
void __fastcall DATAARRAYS_Reset(D2WeatherStrc* pArray); // 0x006BCAC0
void __fastcall DATAARRAYS_FreeEntry(D2WeatherStrc* pArray, int nSlot); // 0x006BCCD0
void __stdcall CHAT_CopyHoverMsgToBuffer(D2HoverTextStrc* pHoverMsg, char* szMessage); // 0x006611E0
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId); // 0x00661230
void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CBE0
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB90
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall D2COMMON_10190_PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nDistance); // 0x00648E40
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath); // 0x00648640
void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pDynamicPath, int bReset); // 0x00649030
void __stdcall D2COMMON_10212_PATH_SetMoveFlags(D2UnitStrc* pUnit, int bSet); // 0x006491B0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __stdcall D2Common_10213(D2UnitStrc* pUnit); // 0x00649210
void __stdcall D2Common_10214(D2UnitStrc* pUnit); // 0x00649CA0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit); // 0x006505E0
void __stdcall D2GFX_ClearScreen(int bPartial); // 0x004F63B0
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340
void __stdcall D2GFX_UtilDiamond(tagRECT* pRect, unsigned char nPaletteIndex); // 0x004F6280
void __stdcall D2Win_10004(int nResolution); // 0x004F9060
void __stdcall D2Win_10029(int bDrawCursor); // 0x004FA410
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420
void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt* pMonSeqTxt, int nTargetFramePoint, int nCurrentFramePoint, int* pMode, int* pFrame, int* pDirection, int* pEvent); // 0x00663410
void __stdcall DUNGEON_ClientToGameSubtileCoords(int* pX, int* pY); // 0x00643510
void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* ptAct); // 0x0061AFD0
void __stdcall DUNGEON_UpdateWarpRoomDeselect(D2ActiveRoomStrc* ptRoom, int nLevelId); // 0x0061AC90
void __stdcall DUNGEON_UpdateWarpRoomSelect(D2ActiveRoomStrc* ptRoom, int nLevelId); // 0x0061AC50
void __stdcall ENVIRONMENT_InitializeEnvironment(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom, int nIndex, int nTicks, int bEclipse); // 0x0061C240
void __stdcall GAME_SetInitSeed(int nInitSeed); // 0x0052C320
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc); // 0x0063E490
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem); // 0x00627C90
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem); // 0x00627D00
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem); // 0x00627DC0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame); // 0x0064A5F0
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed); // 0x0064A690
void __stdcall MISSILE_SetLevel(D2UnitStrc* pMissile, int nLevel); // 0x0064A1E0
void __stdcall MISSILE_SetSkill(D2UnitStrc* pMissile, int nSkill); // 0x0064A240
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* ptPath, int* pTargetType, int* pTargetGUID); // 0x00648BB0
void __stdcall PATH_SetAcceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration); // 0x00648700
void __stdcall PATH_SetMaxVelocity(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity); // 0x006486D0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648CE0
void __stdcall PATH_SetPrecisionX(D2DynamicPathStrc* pDynamicPath, unsigned int dwPrecisionX); // 0x006489A0
void __stdcall PATH_SetPrecisionY(D2DynamicPathStrc* pDynamicPath, int nPrecisionY); // 0x006489B0
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short wBufSize, int bResetStates); // 0x0065C4D0
void __stdcall SBigDel(void* hBig); // 0x00424E40
void __stdcall SBigNew(void** phBig); // 0x00423950
void __stdcall SBigPowMod(void* hResult, void* hBase, void* hExponent, void* hModulus); // 0x00425330
void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead); // 0x00423B30
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder); // 0x004F67C0
void __stdcall SCALE_SetDefaultFactor(); // 0x004F65F0
void __stdcall SCALE_SetPerspectiveScale(int nX, int nY); // 0x004F6670
void __stdcall SCALE_UpdateFactor(); // 0x004F65C0
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent); // 0x00646280
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit); // 0x00646F20
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine); // 0x006470F0
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, unsigned int nSkillMode); // 0x00644340
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATLIST_MergeBaseStats(D2StatListStrc* pTargetStatList, D2StatListStrc* pSourceStatlist); // 0x006274F0
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader); // 0x006612A0
int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit); // 0x00623520
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit); // 0x00623570
void __stdcall UNITS_FreeUnit(D2UnitStrc* unit); // 0x00620300
void __stdcall UNITS_GetCoords(D2UnitStrc* ptUnit, D2CoordStrc* pCoord); // 0x00620870
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* ptUnit, int* pFrameNo, int* pFrameCount); // 0x00621810
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* ptUnit, int nFrame); // 0x006212C0
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed); // 0x00621780
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* ptUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* ptUnit, int nX); // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* ptUnit, int nY); // 0x006204C0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x00623F50
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY); // 0x00621C00
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit); // 0x00621310
void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDest, const void* pSource); // 0x00661030
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame); // 0x004F5D90
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0
void __stdcall CHATDLG_SetMcpResult(int nValue); // 0x00449BF0
void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20
void __stdcall sub_0048B0A0(D2UnitStrc* pUnit); // 0x0048B0A0
void __stdcall sub_004A4AD0_Press(int nX, int nY); // 0x004A4AD0
void __stdcall NPCMENU_SendTradeRequest(int nArg1, int nArg2); // 0x004B2650
void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __stdcall GFXUTIL_SetMotionVectorD(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5); // 0x004DA250
void __stdcall WALL2_VisitRoom(D2ActiveRoomStrc* pRoom, D2WallRoomArgStrc* pArg); // 0x004DD7C0
void __stdcall D2GFX_SetTownMode(int bTown); // 0x004F5190
void __stdcall WINDOW_ShowCursor(int nArg); // 0x004F59F0
void __stdcall SCALE_AdjustPerspectivePosition(int nX, int nY, int nZ, int* pOutX, int* pOutY); // 0x004F6760
void __stdcall SCALE_AdjustPerspectivePosition(int nPrecisionX, int nPrecisionY, int nArg, int* pX, int* pY); // 0x004F6760
void __stdcall D2GFX_FloorTileDraw(D2GridInfoStrc* pInfo, D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int nAlpha, int nMode, int nArg); // 0x004F68E0
void __stdcall TILE_ShadowTileDraw(int nHandle, int nX, int nY, int nArg4, int nArg5); // 0x004F6980
void __stdcall sub_004F90A0(int nResolution); // 0x004F90A0
void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField); // 0x00525260
void __stdcall GAME_UpdateClients(int nArg1, int nArg2); // 0x0052FD90
void __stdcall D2CMPPalShiftSetAct(int nAct); // 0x00600C00
void __stdcall DUNGEON_CallRoomCallback(D2ActiveRoomStrc* pRoom, void* pfCallback, D2WallRoomArgStrc* pArg); // 0x00619BD0
void __stdcall DUNGEON_GetRGB_IntensityFromRoom(D2ActiveRoomStrc* pRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x00619D70
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed); // 0x00621780
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY); // 0x00621C00
void __stdcall sub_00624390(D2UnitStrc* pUnit); // 0x00624390
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __stdcall D2COMMON_10267_Return(D2InventoryStrc* pInventory, int nX); // 0x0063C550
void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY); // 0x0063E7E0
void __stdcall MONSTERS_GetChainDirectionDelta(D2UnitStrc* unit,int* x,int* y); // 0x0063EE10
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
void __stdcall DUNGEON_ClientTileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY); // 0x00643340
void __stdcall D2Common_11030(D2UnitStrc* pUnit, int nSkillId, int nLevelBonus); // 0x00647AA0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath); // 0x00648DC0
extern "C" void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode); // 0x00649190
void __stdcall PATH_SetUnitAliveCollision(D2UnitStrc* pUnit, int bSkip); // 0x00649FF0
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed); // 0x0064A690
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath); // 0x00650590
void* __cdecl sub_00454600(); // 0x00454600
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsyncData); // 0x0040A9E0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall GFXUTIL_GetNextRosterInfo(D2UnitStrc* pUnit); // 0x004DC0B0
void* __fastcall sub_00517993_VirtualAlloc(unsigned int nSize); // 0x00517993
void* __stdcall D2Win_GetArchive(); // 0x004FAC80
extern "C" void* __stdcall SMemReAlloc(void* pMemory, unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x004133D0
#define CREATE_ALWAYS 2
#define CURSOR_ANIM_COUNT 7
#define D2_HIWORD(l) ((unsigned short)(((unsigned int)(l) >> 16) & 0xFFFF))
#define D2_LOWORD(l) ((unsigned short)((unsigned int)(l) & 0xFFFF))
#define D2_RESET_QUEST_SELECTION() \
    gtQuestLog.bQuestSlotDown = 0; \
    gtQuestLog.bCloseButtonDown = 0; \
    gtQuestLog.bQuestButtonDown = 0; \
    gtQuestLog.nPressedSlot = -1; \
    gtQuestLog.bDescButtonDown = 0; \
    gtQuestLog.bDurielCofsLoaded = 0; \
    gtQuestLog.bAncientsCofsLoaded = 0; \
    gtQuestLog.bHasQuestPacketValue = 0; \
    gtQuestLog.bQuestUnitsSpawned = 0
#define E06_ABS(x) ((x) < 0 ? -(x) : (x))
#define GENERIC_WRITE 0x40000000
#define GFX_ENTRY_COUNT 20
#define GFX_INDEX_COUNT 16
#define HOTKEY_UNBOUND 0xFFFF
#define I07_OFFSET(s, m) ((unsigned int)&((s*)0)->m)
#define I20_OFFSET(s, m) ((unsigned int)&((s*)0)->m)
#define KEY_WHEEL_DOWN 0x104
#define KEY_WHEEL_UP 0x103
// build: symbol ?CUNIT_FindClientUnit@* 0x00463990
#define NPC_GET_INTERACT_UNIT() (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0)
#define NULL 0
#define SUMMIT_ROLL(pSeed, lSeed) ((lSeed) = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
    (pSeed)->nHighSeed = (unsigned int)((lSeed) >> 32), (pSeed)->nLowSeed = (unsigned int)(lSeed), (unsigned int)(lSeed))
#define UNIT_GETX(pUnit, outX) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outX = (pUnit)->pStaticPath->nXPos; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outX = PATH_GetXPosition((pUnit)->pDynamicPath); \
        else \
            outX = 0; \
        break; \
    }
#define UNIT_GETX_K5(pUnit, outX) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outX = (pUnit)->pStaticPath->nXPos; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outX = PATH_GetXPosition((pUnit)->pDynamicPath); \
        else \
            outX = 0; \
        break; \
    }
#define UNIT_GETY(pUnit, outY) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outY = (pUnit)->pStaticPath->nYPos; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outY = PATH_GetYPosition((pUnit)->pDynamicPath); \
        else \
            outY = 0; \
        break; \
    }
#define UNIT_GETY_K5(pUnit, outY) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outY = (pUnit)->pStaticPath->nYPos; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outY = PATH_GetYPosition((pUnit)->pDynamicPath); \
        else \
            outY = 0; \
        break; \
    }
// build: symbol ?gtTradePage1Grid@* 0x007BCB18
#define gnGlobal_007BCB1C (gtTradePage1Grid.nGridLeft)
#define gnGlobal_007BCB20 (gtTradePage1Grid.nGridRight)
#define gnGlobal_007BCB24 (gtTradePage1Grid.nGridTop)
#define gnGlobal_007BCB28 (gtTradePage1Grid.nGridBottom)
// build: symbol ?gtCubeRect@* 0x007BCB30
#define gnGlobal_007BCB30 (gtCubeRect.nLeft)
#define gnGlobal_007BCB34 (gtCubeRect.nRight)
#define gnGlobal_007BCB3C (gtCubeRect.nBottom)
#define va_start(ap, v) (ap = (va_list)&v + sizeof(v))

typedef char* va_list;

struct D2AutomapPointStrc
{
    int nX;
    int nY;
};

struct D2AutomapRecordStrc
{
    unsigned int nGameSeed;
    unsigned int nValue;
};

struct D2AutomapSaveStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    unsigned int nObjectSeed;
    unsigned int dwFloorSize;
    unsigned int dwWallsSize;
    unsigned int nObjects;
    unsigned int dwExtraSize;
    void* pFloors;
    void* pWalls;
    void* pObjects;
    void* pExtras;
};

struct D2Block1 { int n[6]; };

struct D2BnetChatPacketStrc
{
    int nType;
    char unk0x04[0x14];
    char szName[0x1D0];
};

struct D2ButtonStringStrc
{
    unsigned short nCelFrame;
    unsigned short nStringIndex;
};

struct D2CellPosStrc
{
    int nX;
    int nY;
    char unk0x08[0x10];
    int f_18;
};

struct D2CellNodeStrc
{
    unsigned int dwFlags;
    int nA;
    int nB;
    D2CellPosStrc* pPos;
    D2CellNodeStrc* pNext;
};

struct D2ChatSendStrc
{
    char nType;
    char nCode;
    char nLang;
    char szText[0x100];
    char szArgument[0x11];
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;

    D2ChatStormBaseArrayAStrc();
    unsigned int IGNORELIST_GetStringSlotArrayCount();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;

    D2ChatStormBaseArrayBStrc();
    unsigned int IGNORELIST_GetMappingSlotArrayCount();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    bool IGNORELIST_IsLinkLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitStringListTerminator();
    char* IGNORELIST_GetStringListHead();
    void IGNORELIST_ResetStringList();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* IGNORELIST_GetStringTableHead();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitMappingListTerminator();
    char* IGNORELIST_GetMappingListHead();
    void IGNORELIST_ResetMappingList();
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    char* IGNORELIST_GetStringEntryKey();
};

struct D2ChatTextStrc
{
    char sz[0x100];
};

struct D2ClientCacheNodeStrc
{
    int nId;
    D2ClientCacheNodeStrc* pNext;
};

typedef void (__fastcall* D2ClientCallbackFn)(void* pArg);

struct D2ClientSkillArgsStrc
{
    int nSkillId;
    int nOwnerGUID;
    int nArg1;
    int nArg2;
    int nSkillLevel;
};

struct D2ClientTabStrc
{
    unsigned char bSelected[4];
    unsigned char bEnabled[4];
    unsigned char unk0x08[0x0A];
};

struct D2ClientTextDataStrc
{
    char unk0x00[0x80];
    int dwTag;
};

struct D2ClientTimedBoxStrc
{
    int bActive;
    int nValue;
    unsigned char nColor[4];
    int nFadeIn;
    int nFadeOut;
    int nHold;
    int nTotal;
    int nTick;
    int nAngle;
    int nLevelId;
    int bLocked;
};

struct D2CltUnitEventStrc
{
    int nType;
    int nParam4;
    int nParam5;
    int nParam1;
    int nParam2;
    int nParam3;
    D2CltUnitEventStrc* pPrevious;
    D2CltUnitEventStrc* pNext;
};

struct D2CofModeEntryStrc
{
    unsigned int dwCode;
    int nMode;
};

struct D2CombinedStatIdStrc
{
    int nStatId;
    char unk0x04[0x0C];
};

struct D2CombinedStatStrc
{
    int nMin;
    int nMax;
    int nLength;
    int nCount;
    int bCombined;
    int bShown;
};

struct D2CombinedStatsStrc
{
    D2CombinedStatStrc tDamage;
    D2CombinedStatStrc tDamagePercent;
    D2CombinedStatStrc tCold;
    D2CombinedStatStrc tLightning;
    D2CombinedStatStrc tFire;
    D2CombinedStatStrc tPoison;
    D2CombinedStatStrc tMagic;
};

struct D2CommonChatIgnoreListStrc
{
    virtual int IGNORELIST_AddName(const char* szName) = 0;
    virtual int IGNORELIST_RemoveName(const char* szName) = 0;
    virtual int IGNORELIST_IsListed(const char* szName) = 0;
    virtual void IGNORELIST_AddAlias() = 0; // 0x00610F90
    virtual int IGNORELIST_RemoveAlias(const char* szName) = 0;
    virtual int sub_0060FC40_IsTextFiltered(const char* szText) = 0;
    virtual void IGNORELIST_StoreAccountAlias() = 0; // 0x00611320
    virtual void IGNORELIST_TranslateAlias(const char* szName, char* szOut, int nSize) = 0;
    virtual int IGNORELIST_IsEnabled() = 0;
    virtual void IGNORELIST_SetEnabled(int bEnabled) = 0;
    virtual void IGNORELIST_ClearAccountAliases() = 0;
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    ~D2CommonMappingEntryNodeBaseStrc();
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStormHashTableAStrc
{
    void IGNORELIST_InternalClearStringTable(int bWarn);
    void IGNORELIST_ClearStringTable();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListAStrc();
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
    void UnlinkAll();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    ~D2CommonStringEntryNodeStrc();
    void IGNORELIST_DestroyStringEntryNode();
};

struct D2CompArgStrc
{
    int unk0x00[4];
    int nArg18;
};

union D2CompCodeStrc
{
    unsigned int dwCode;
    struct
    {
        char c0;
        char c1;
        char c2;
        char c3;
    };
};

struct D2CompRecordStrc
{
    unsigned char nComponent;
    char unk0x01[4];
    char szCode[4];
};

struct D2CompEntryStrc
{
    unsigned char nCount;
    char unk0x01[0x1B];
    D2CompRecordStrc aComps[16];
};

struct D2CoordPairStrc { int nX; int nY; };

struct D2CursorAnimStrc
{
    int bAnimated;
    int f_4;
    int nFrames;
    int nStep;
    void* pData;
    void* pfnHandler;
    const char* szName;
};

struct D2DialogItemStrc
{
    int nHeight;
    char unk0x04[0x14];
    int (__cdecl* pfnCallback)();
    int nType;
    char unk0x20[0xF0];
};

struct D2DirRateStrc
{
    int nValue;
    unsigned int nRate;
};

struct D2DirectionArgStrc
{
    unsigned char nDirection;
};

struct D2ElemDamageStatsStrc
{
    int nMinStat;
    int nMaxStat;
    int nMasteryStat;
};

struct D2ElemDamageStrc
{
    int nMinStat;
    int f_4;
    int nColor;
};

struct D2EscMenuUIStateStrc
{
    int bCheck;
    int bSave;
    int nSaved;
};

struct D2FileIndexTextStrc
{
    int nFileIndex;
    int nMode;
    unsigned short wStrPos;
    unsigned short wStrNeg;
    int nPos;
};

struct D2GfxEntryStrc
{
    unsigned char nValue;
    unsigned char unk0x01;
};

struct D2GfxLightStrc
{
    unsigned int aColor[8];
};

struct D2GridCoordStrc
{
    int n;
};

struct D2GridInfoStrc
{
    char pad0x00[0x6];
    unsigned short wFlags;
    char pad0x08[0xC];
    int nBusy;
};

struct D2GridRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2GridOwnerStrc
{
    char pad0x00[0x14];
    D2GridRectStrc tRect;
};

struct D2GridUnitStrc
{
    char pad0x00[0x14];
    unsigned int dwFlags;
    D2GridInfoStrc* pInfo;
};

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

struct D2HotkeySlotTableStrc
{
    int nX[60];
    int nY[60];
    int nSkill[60];
    int f_2D0[60];
};

struct D2HoverBoxStrc
{
    int nBoxX;
    int nBoxY;
    int nTitleX;
    int nTitleY;
    int nTextX;
    int nTextY;
};

struct D2HoverCoordStrc
{
    int nValue;
};

struct D2ItemPacket9CStrc
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nSize;
    unsigned char nCategory;
    int dwUnitId;
    unsigned char pData[1];
};

struct D2ItemPacket9DStrc
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nSize;
    unsigned char nCategory;
    int dwUnitId;
    unsigned char unk0x08[5];
    unsigned char pData[1];
};

struct D2LaunchAddressStrc
{
    int nData0;
    int nData1;
    int nData2;
    int nData3;
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

typedef void (__cdecl* D2LaunchDoneFn)();

struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};

struct D2LightOffsetStrc
{
    int nX;
    int nY;
};

struct D2LightOffsetsStrc
{
    D2LightOffsetStrc aOffset[6];
};

struct D2ListBoxEntryStrc
{
    char unk0x0000[0x3006];
    char nData[4];
    char unk0x300A[4];
};

typedef void (__fastcall* D2McpCallbackFn)(unsigned short wRequestId, unsigned char* pData);

typedef int (__fastcall* D2McpPacketHandler)(const unsigned char* pPacket, unsigned int nSize);

struct D2MercStatLineStrc
{
    int nLeft;
    int nRight;
    int nY;
    int nMaxWidth;
    int nStatId;
};

struct D2MonAnimRecStrc
{
    int nType;
    int unk0x04;
    int nAction;
};

struct D2MonCmdRecordStrc
{
    int nIndex;
    int bSet;
};

struct D2MonCofInfoStrc
{
    short nMonsterId;
    char unk0x02[0x03 - 0x02];
    unsigned char nCount;
    char unk0x04[0x34 - 0x04];
};

struct D2MonCompInfoStrc
{
    short nClass;
    char unk0x02[2];
    unsigned char aComp[4][16];
};

struct D2MonModeTxt
{
    char unk0x00[0x20];
    unsigned int dwToken;
};

struct D2MonStats2SelectStrc { char pad0[4]; unsigned char nFlags[4]; char pad8[0xE4]; unsigned char nComponents; char padED[0x21]; short nTop,nLeft,nWidth,nHeight; };

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};

struct D2NpcMenuSlotStrc
{
    unsigned short wId;
    char unk0x02[0x0E];
};

struct D2NpcQuestHandlerStrc
{
    int nNpcId;
    int nQuestId;
    int nState;
    int bSet;
    int (__cdecl* pfHandler)();
};

struct D2NpcSoundStrc
{
    int nDefaultSound;
    int nDaySound;
    int nNightSound;
    int nGreetSound;
    int nLastSound;
    int nLastTick;
};

struct D2OverlaySourceStrc
{
    int unk0x00;
    int nOverlay;
    int unk0x08[4];
    int nArg0;
};

struct D2Packet81ArgsStrc
{
    int nArg0C;
    int nArg10;
    int nZero;
};

struct D2PacketBufferStrc
{
    int nMax;
    int nCount;
    int unk0x08;
    unsigned char* pData;
};

struct D2PathDirectionStrc
{
    unsigned char nDirection;
};

struct D2PeriodLightStrc
{
    unsigned char nUnused;
    unsigned char nLight;
};

struct D2QuestPageRangeStrc
{
    int nFirst;
    int nLast;
};

struct D2QuestPosStrc
{
    int nX;
    int nY;
    int unk0x08[2];
};

struct D2QuestSlotRectStrc
{
    int nX;
    int nY;
    int unk0x08;
    int unk0x0C;
};

struct D2QuestTextsStrc
{
    unsigned short awIds[64];
};

struct D2R01LightStrc
{
    int nUnitType;
    unsigned int nUnitId;
    unsigned char f_8;
    char unk0x09[3];
    int nMode;
    int nX;
    int nY;
    int nRadius;
    int nTargetRadius;
    int bFixed;
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    D2R01LightStrc* pNext;
    int bMaskReady;
    unsigned int* pMask;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2RosterButtonStrc
{
    int nX;
    int nY;
    int unk0x08[2];
    int nType;
    int nState;
    int unk0x18[2];
};

struct D2RosterPetNodeStrc
{
    int nValue;
    int nType;
    int nKey;
    int nArg;
    int unk0x10[3];
    int nInit;
    int nClear;
    int unk0x24[3];
    D2RosterPetNodeStrc* pNext;
};

struct D2SkillIconStateStrc
{
    char unk0x000[0x2D0];
    int anValues[60];
    unsigned char bFlag;
    char unk0x3C1[0x4];
};

struct D2SkillRefStrc
{
    int nSkillId;
    int nOwnerGUID;
};

struct D2SkillStateStrc
{
    int nLife;
    int nMana;
    int nStamina;
    int nRightSkillId;
    int nLeftSkillId;
    int nRightOwnerGUID;
    int nLeftOwnerGUID;
};

struct D2SoundVecStrc
{
    float fX;
    float fY;
    float fZ;
};

struct D2StatusStrc
{
    int nCode;
    int nArg;
};

struct D2StringRefStrc
{
    unsigned short nStringId;
    unsigned short unk0x02;
};

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

struct D2TokRecord
{
    char unk0x00[0x20];
    unsigned int dwCode;
    char unk0x24[0x10];
};

struct D2UiEntry10Strc
{
    int nKey;
    int nId;
    int unk0x08;
    int unk0x0C;
};

struct D2UnitSndObjectStrc
{
    int nModeSound[8];
    int nSoundA;
    int nSoundAMode;
    int nSoundB;
    int nSoundBMode;
};

struct D2UnitSndPlayerStrc
{
    int f_0;
    int nDeathSound;
    int anEventSounds[8];
    int nFootstep;
};

struct D2WallCellStrc
{
    char unk0x00[0x8];
    int nX;
    int nY;
    char unk0x10[0x14];
};

struct D2WallCtxStrc
{
    char unk0x00[0x4];
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
    char unk0x14[0x10];
    int nX;
    int nY;
    char unk0x2C[0xC];
    int nUnk0x38;
    char unk0x3C[0xEA60];
    int nUnk0xEA9C;
    int f_EAA0;
    int f_EAA4;
    D2WallCellStrc* pCells;
    int nCellCount;
    unsigned int nSize;
    int nWidth;
    int nHeight;
};

#pragma pack(push, 1)
struct D2WaypointMenuEntryStrc
{
    int nLevelId;
    char bEnabled;
};
#pragma pack(pop)

struct D2WaypointRowRectStrc
{
    int nX;
    int nY;
    int nUnk0x08[4];
};

struct D2WeatherSplashStrc
{
    short bActive;
    short unk0x02;
    int nX;
    int nY;
    int nType;
    int nFrame;
    int nFrameDelay;
};

typedef void (__cdecl* D2WheelCallbackFn)();

typedef int (__stdcall* FARPROC)();

typedef int(__fastcall* MENUENABLED)();

typedef unsigned int U32;

struct PlayerNode
{
    int playerId;
    U32 flags;
    PlayerNode* next;
};

typedef char NodeSize[(sizeof(PlayerNode) == 12) ? 1 : -1];

struct PlayerListHead
{
    PlayerNode* first;
};

typedef int s32;

struct Rectangle
{
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
};

struct SelectionEntry
{
    int enabled;
    char pad04[272-4];
};

struct D2WeatherParticleStrc
{
    short bActive;
    short unk0x02;
    int nX;
    int nY;
    int nYEnd;
    int nParam;
    int nParam2;
    int nFrame;
    int bDrop;
    int nType;
    unsigned char nColor;
    unsigned char nAlpha;
    short unk0x26;
};

typedef unsigned short U16;

typedef unsigned char U8;

typedef char pointer_width[sizeof(void*)==4?1:-1];

typedef unsigned int size_t;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef char word_width[sizeof(unsigned int)==4?1:-1];
