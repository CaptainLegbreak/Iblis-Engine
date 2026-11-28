#pragma once

// D2Game functions that two or more of the module's files call, declared once here.
// D2Game.h and the shared record headers come first.

// These units keep their own private declarations instead and don't include this header:
// Ai/AiThink4_005E17E0.cpp, Ai/AiThink4_005ED2A0.cpp, MISSILES/MissMode_005ADF10.cpp, MONSTER/MonsterUnique_005A49B0.cpp, MONSTER/Monster_00573CB0.cpp, PLAYER/PlayerPets.cpp, Quests/QUESTS.CPP, SKILLS/SkillItem_005C1560.cpp, SKILLS/SkillNec.cpp, UNIT/Party.cpp.
// Their code depends on how many declarations precede it, and this header changes that.

struct D2PoolSystemStrc;
struct D2Act1Quest5Strc;
struct D2Act4Quest2Strc;
struct D2ActiveRoomStrc;
struct D2AiCmdStrc;
struct D2AiControlStrc;
struct D2AiParamStrc;
struct D2AiTickParamStrc;
struct D2AuraCallbackStrc;
struct D2BitBufferStrc;
struct D2CharItemStrc;
struct D2CharStatsTxt;
struct D2ClientStrc;
struct D2CoordStrc;
struct D2CurseStrc;
struct D2DamageStrc;
struct D2EventTimerStrc;
struct D2GSPacketSrv26;
struct D2GSPacketSrv27;
struct D2GSPacketSrv29;
struct D2GSPacketSrv50;
struct D2GSPacketSrv52;
struct D2GSPacketSrv53;
struct D2GSPacketSrv58;
struct D2GSPacketSrv5A;
struct D2GSPacketSrv5D;
struct D2GSPacketSrv5E;
struct D2GSPacketSrv89;
struct D2GSPacketSrv8A;
struct D2GSPacketSrv91;
struct D2GameStrc;
struct D2InventoryStrc;
struct D2ItemDropStrc;
struct D2LinkStrc;
struct D2MapAIStrc;
struct D2MinionListStrc;
struct D2MissileStrc;
struct D2ModeChangeStrc;
struct D2MonStatsTxt;
struct D2MonsterInteractStrc;
struct D2MonsterRegionStrc;
struct D2NpcRecordStrc;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2ObjectsTxt;
struct D2PacketDataStrc;
struct D2PetInfoStrc;
struct D2PlayerCountBonusStrc;
struct D2PlrIntroStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;
struct D2QuestGUIDStrc;
struct D2RoomCoordListStrc;
struct D2SaveHeaderStrc;
struct D2SavedItemStrc;
union D2SeedStrc;
struct D2SkillStrc;
struct D2SkillsTxt;
struct D2StatListStrc;
struct D2SummonArgStrc;
struct D2TextHeaderStrc;
struct D2UnitDescriptionListStrc;
struct D2UnitEventStrc;
struct D2UnitFindDataStrc;
struct D2UnitInfoStrc;
struct D2UnitStrc;
struct D2UnkMonCreateStrc;
struct D2WaypointDataStrc;

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...); // 0x0052BE20
int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId); // 0x0052C060
void __stdcall GAME_SetReservedGameGUID(int nGameGUID, unsigned short nGameId); // 0x0052C110
void __fastcall GAME_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0052C210
void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0052C410
void __fastcall SrvFreeGame(int nGameGUID, D2GameStrc* pGame); // 0x0052C7F0
void __fastcall GAME_SaveAllPlayers(D2GameStrc* pGame); // 0x0052CA10
void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType); // 0x0052CAF0
void __fastcall GAME_FindGameOwnerCallback(D2ClientStrc* pClient, void* pContext); // 0x0052CBB0
void __fastcall GAME_FindFirstClientCallback(D2ClientStrc* pClient, void* pContext); // 0x0052CBD0
void __stdcall GAME_RemoveUntilableRooms(D2GameStrc* pGame); // 0x0052D240
void __stdcall GAME_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected); // 0x0052D350
void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame); // 0x0052D7B0
void __fastcall GAME_UpdateProgress(D2GameStrc* pGame); // 0x0052D870
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90
void __fastcall GAME_SaveAndSendClientSaves(D2GameStrc* pGame); // 0x0052E2A0
void __fastcall GAME_CloseGame(int nGameGUID); // 0x0052E770
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860
void __stdcall GAME_SendGameList(void* pArg); // 0x0052E8E0
int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId); // 0x0052EFF0
void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType); // 0x0052F160
void __stdcall GAME_SendMessageToAllClients(int nMessageType, int nPacketParam, const char* szMessage); // 0x0052F4C0
int __fastcall GAME_IsGameNameUnused(const char* szGameName); // 0x0052F8B0
void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int dwFlags); // 0x0052F940
int __stdcall GAME_AbortClientById(int nClientId, int szFile, int nLine); // 0x005300F0
void __fastcall SrvDisconnectClientById(int nClientId, int nEventType); // 0x00530270
void __fastcall SrvEndGame(int nClientId, int bSendLeaveMessage); // 0x005303D0
void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* game, D2ClientStrc* client); // 0x00530590
void __fastcall D2GAME_SetStatOrResetGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x00530EA0
int __fastcall PLRSAVE_CreateAndPlaceLegacyPlayerItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount); // 0x00531040
int __fastcall PLRSAVE_PlacePlayerItem(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem,D2UnitStrc* pSocketItem); // 0x00531210
int __fastcall PLRSAVE_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pData, int nBufferSize, int bUseTradeInventory, int nUnused, int bSizing); // 0x005317B0
int __fastcall PLRSAVE_WriteUnitItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0
int __fastcall D2GAME_SAVE_CalculateChecksum(D2SaveHeaderStrc* pSaveHeader, int nSize); // 0x00531E30
int __fastcall D2GAME_SAVE_WriteFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400
int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData); // 0x00532F30
int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x00533350
int __fastcall PLRSAVE_ReadItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x005335E0
int __fastcall PLRSAVE_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0
int __fastcall PLRSAVE_ReadSaveData(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00534330
int __fastcall D2GAME_SAVE_GetUnitDataFromFile(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, int bLoadSave, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005345A0
void __fastcall PLAYER_CreatePlayerIntros(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00534800
void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005349D0
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame); // 0x00534A50
void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem); // 0x00534D60
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit); // 0x005350B0
void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* pPlayer, int nUnitGUID); // 0x005353B0
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer); // 0x005353F0
void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00535430
int __fastcall PLAYER_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue); // 0x00535510
int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame); // 0x00535790
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker); // 0x00535AB0
void __fastcall PLAYER_CheckHostilityCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs); // 0x00535AF0
D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit); // 0x00535BC0
void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc* pAttacker, int bTemporaryWeaponStats); // 0x00535D10
void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc* pTarget, int bTemporaryWeaponStats); // 0x00535E20
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
void __fastcall SUNITPROXY_InitializeNpcControl(D2GameStrc* pGame); // 0x00536070
void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame); // 0x00536640
void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x00536820
void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536B50
D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536C50
void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId); // 0x00536D50
void __fastcall SUNITPROXY_FillGlobalItemCache(); // 0x00536F80
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId); // 0x00537340
void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00537680
void __fastcall CLIENTS_Initialize(); // 0x005376C0
int __cdecl CLIENTS_GetExpansionClientCount(); // 0x005377B0
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* ptGame, int nClientId); // 0x00537810
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* ptClient, int bIgnoreDeath); // 0x00537860
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* ptClient, D2UnitStrc* pUnit); // 0x005378E0
void __fastcall CLIENTS_SetGameData(D2ClientStrc* pClient); // 0x005379A0
void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame); // 0x00537AC0
void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* ptClient, unsigned int nUpdateSize); // 0x00537FD0
void __fastcall CLIENTS_SynchronizePlayer(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x005380D0
int __fastcall CLIENTS_IsInGame(D2GameStrc* pGame, int nClientId); // 0x005381C0
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* ptClient, D2ActiveRoomStrc* pRoom); // 0x005381F0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* ptClient); // 0x005382B0
void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct); // 0x005382E0
void __fastcall CLIENTS_EnableCharacterUnlock(D2ClientStrc* ptClient); // 0x00538320
int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient); // 0x00538590
int __fastcall CLIENTS_GetClassId(D2ClientStrc* ptClient); // 0x005385F0
void __fastcall CLIENTS_SetClassId(D2ClientStrc* pClient, int nClass); // 0x00538620
int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient); // 0x00538640
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag); // 0x00538670
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState); // 0x005386D0
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* ptClient); // 0x005387C0
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
int __fastcall CLIENTS_CheckState(int nClientId, int nExpectedClientState); // 0x00538930
void __fastcall CLIENTS_UpdatePing(int nClientId, int nTick, int nDelay, int nUnused); // 0x005389A0
int __fastcall CLIENTS_GetNameById(int nClientId, char* szName); // 0x00538B70
int __fastcall CLIENTS_GetClientIdByName(const char* szName); // 0x00538BF0
int __fastcall CLIENTS_GetCanonicalName(const char* szName, char* szGameName); // 0x00538C60
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int nUnused1, int nUnused2); // 0x00538CE0
void __fastcall CLIENTS_CopySaveDataToClient(D2ClientStrc* ptClient, const void* pData, unsigned int nSize); // 0x00538E60
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* ptClient); // 0x00538F10
int __fastcall CLIENTS_HasLoadedSave(D2ClientStrc* ptClient); // 0x00538FC0
void __fastcall CLIENTS_SetGameOwner(D2ClientStrc* ptClient); // 0x00539000
unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* ptClient); // 0x00539030
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss); // 0x005391E0
void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pSinglePacketData); // 0x00539270
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient); // 0x005392A0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szAccount); // 0x005392F0
void __fastcall CLIENTS_SpawnPlayer(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nXArg, int nYArg); // 0x005394A0
int __fastcall ClientAddPlayerToGame(D2ClientStrc* ptClient, D2GameStrc* ptGame, int bLoadFromSave, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00539760
D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int nUnused1, int nUnused2); // 0x00539A30
void __fastcall LEVEL_UpdateUnitsInAdjacentRooms(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0053A620
void __fastcall LEVEL_RemoveUnitsExceptClientPlayer(D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient); // 0x0053A770
void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame); // 0x0053A820
void __fastcall LEVEL_AddClient(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient); // 0x0053A8E0
void __fastcall LEVEL_RemoveClient(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient); // 0x0053A9B0
void __fastcall LEVEL_RemoveClientFromAdjacentRooms(D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient); // 0x0053AB80
void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0053ABE0
void __fastcall LEVEL_ChangeAct(D2GameStrc* pGame, D2ClientStrc* ptClient, int nDestinationLevelId, int nTileCalc); // 0x0053ACC0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall LEVEL_LoadAct(D2GameStrc* pGame, unsigned char nAct); // 0x0053AFB0
void __fastcall LEVEL_RemoveAllUnits(D2GameStrc* pGame); // 0x0053AFD0
void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame); // 0x0053B000
void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId); // 0x0053B220
void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nErrorCode); // 0x0053B260
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader); // 0x0053B320
void __fastcall D2GAME_PACKETS_SendPacket0x01(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame); // 0x0053B340
void __fastcall D2GAME_PACKETS_SendPacket0x03(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId); // 0x0053B390
void __fastcall D2GAME_SendPacketSize05(D2ClientStrc* pClient, unsigned char nHeader, int nValue); // 0x0053B400
void __fastcall D2GAME_PACKETS_SendPacket0x0C(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char nMessage, unsigned char nHitClass, unsigned char nLifePct); // 0x0053B430
void __fastcall D2GAME_PACKETS_SendPacket0x0D(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
void __fastcall D2GAME_PACKETS_SendPacket0x10(D2ClientStrc* pClient, char nHeader, char nUnitType, int nUnitGUID, char nFlags, int nTargetType, int nTargetGUID, short nCurrentPosX, short nCurrentPosY); // 0x0053B520
void __fastcall D2GAME_PACKETS_SendPacket0x0F(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int nUnitGUID, char nFlags, short nDestPosX, short nDestPosY, char nHitClass, short nCurrentPosX, short nCurrentPosY); // 0x0053B570
void __fastcall D2GAME_PACKETS_SendPacket0x15(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char bReassign); // 0x0053BC10
void __fastcall D2GAME_PACKETS_SendPacket0x0A_RemoveObject(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F(D2ClientStrc* pClient, unsigned short wStat, unsigned int nValue); // 0x0053BE40
void __fastcall D2GAME_PACKETS_SendPacket0xA3(D2ClientStrc* pClient, unsigned char nSeed, unsigned short nSkillId, unsigned short nSkillLevel, int nUnitType, int nUnitGUID, int nTargetType, int nTargetGUID, int nX, int nY); // 0x0053C0E0
void __fastcall D2GAME_PACKETS_SendPacket0xAB(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife); // 0x0053C150
void __fastcall D2GAME_PACKETS_SendPacket0xA5(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned short nSkillId); // 0x0053C190
void __fastcall SCMD_SendUnitStat(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short wStat, int nValue); // 0x0053C1D0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove); // 0x0053C4A0
void __fastcall D2GAME_PACKETS_SendPacket0x23(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char bLeftSkill, unsigned short nSkillId, int nSkillOwnerGUID); // 0x0053C590
void __fastcall SCMD_SendSkillList(D2ClientStrc* pClient, D2UnitStrc* hUnit); // 0x0053C5D0
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750
void __fastcall D2GAME_PACKETS_SendPacket0x5A(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850
void __fastcall D2GAME_PACKETS_SendPacket0x27(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0
void __fastcall D2GAME_SendPacket0x53(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket); // 0x0053C900
void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc* pClient1, D2UnitStrc* pPlayer, D2ClientStrc* pClient2); // 0x0053C940
void __fastcall D2GAME_PACKETS_SendPacket0x5C(D2ClientStrc* pClient, int nUnitGUID); // 0x0053CA90
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x7A(D2ClientStrc* pClient, char bAdd, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass); // 0x0053CB30
void __fastcall D2GAME_PACKETS_SendPacket0x81(D2ClientStrc* pClient, char nUnused, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName); // 0x0053CB80
void __fastcall SCMD_SendUnitLifeAndPositionUpdate(D2ClientStrc* pClient, D2UnitStrc* hUnit); // 0x0053CDF0
void __fastcall D2GAME_UpdateClientItem(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_SendP0x9D_ItemAction_Equip(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D090
void __fastcall D2GAME_PACKETS_SendPacket0x3E(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short nStatLayer); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x42(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D2E0
void __fastcall D2GAME_SendPacket0x48(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nUnused); // 0x0053D3C0
void __fastcall SCMD_SendUnitActionAtPosition(D2ClientStrc* pClient, unsigned char nSourceUnitType, int nSourceUnitGUID, unsigned short nX, unsigned short nY, int nActionId, unsigned short nSkillParam, unsigned char nActionParam, int bQueued); // 0x0053D4D0
void __fastcall D2GAME_SendPacket0x28(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, D2BitBufferStrc* pQuestRecord, unsigned char nQuestFlags); // 0x0053D670
void __fastcall SCMD_SendInteractionTarget(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int nUnused); // 0x0053D6D0
void __fastcall D2GAME_PACKETS_SendPacket0x29(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket); // 0x0053D700
void __fastcall SCMD_SendPacket0x5D(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
void __fastcall D2GAME_SendPacket0x50(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
void __fastcall D2GAME_PACKETS_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket); // 0x0053D830
void __fastcall D2GAME_SendPacket0x52(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket); // 0x0053D840
void __fastcall SCMD_SendUniqueMonsterInfo(D2ClientStrc* pClient, int dwUnitGUID, unsigned char nUnitType, unsigned short nNameSeed, unsigned short nUMods01, unsigned short nUMods23, unsigned short bChampion); // 0x0053D880
void __fastcall D2GAME_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0
void __fastcall SCMD_SendPortalState(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D900
void __fastcall D2GAME_PACKETS_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer); // 0x0053DA90
void __fastcall SCMD_SendPlayerRelationshipCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DDF0
void __fastcall SCMD_BroadcastPlayerRelationship(D2GameStrc* pGame, int dwPlayerId1, int dwPlayerId2, short wRelationState); // 0x0053DE20
void __fastcall SCMD_BroadcastPlayerParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0053DEC0
void __fastcall D2GAME_PACKETS_SendPacket0x8D(D2UnitStrc* pUnit, D2UnitStrc* pPlayer); // 0x0053DF00
void __fastcall SCMD_SendCorpseAssignCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DF50
void __fastcall D2GAME_PACKETS_SendPacket0x8E(D2ClientStrc* pClient, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DFB0
void __fastcall D2GAME_PACKETS_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket); // 0x0053DFE0
void __fastcall D2GAME_SendPacket0x8A(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket); // 0x0053DFF0
void __fastcall D2GAME_PACKETS_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket); // 0x0053E060
void __fastcall D2GAME_PACKETS_SendPacket0x9B(D2ClientStrc* pClient, unsigned short nUnitGUID, int nReviveCost); // 0x0053E0E0
void __fastcall D2GAME_PACKETS_SendPacket0x97(D2ClientStrc* pClient); // 0x0053E110
void __fastcall SCMD_SendUnitUpdates(D2ClientStrc* pClient); // 0x0053E130
void __fastcall SCMD_SendRawPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize); // 0x0053E8D0
void __fastcall D2GAME_SendPacket0x9C(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053EAE0
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, int dwFlags); // 0x0053EC90
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70
void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize); // 0x0053F100
void __fastcall ProcessClientMessage(void* pData, int nPacketSize); // 0x0053F3D0
void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int nUnused, unsigned int nFlags, unsigned char nTemplate); // 0x0053F4B0
void __fastcall ARENA_FreeArena(D2GameStrc* pGame); // 0x0053F500
void __fastcall ARENA_AllocArenaUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053F530
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender); // 0x0053F720
void __fastcall ARENA_ClearUpdateFlag(D2GameStrc* pGame); // 0x0053FAE0
void __fastcall ARENA_SynchronizeWithClients(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0053FC20
void __fastcall ARENA_SendScoresToClient(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0053FC70
unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame); // 0x0053FCA0
unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame); // 0x0053FCE0
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame); // 0x0053FD40
unsigned int __fastcall ARENA_ShouldTreatClassIdAsTemplateId(D2GameStrc* pGame); // 0x0053FE70
int __fastcall ARENA_GetTemplateType(D2GameStrc* pGame); // 0x0053FEA0
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
void __fastcall PARTY_AllocPartyControl(D2GameStrc* ptGame); // 0x0053FF90
void __fastcall PARTY_FreePartyControl(D2GameStrc* ptGame); // 0x00540000
void __fastcall PARTY_AddLivingMemberLevelCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs); // 0x005404C0
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits); // 0x005404F0
void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005406A0
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005407A0
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGoldValue); // 0x00540900
void __fastcall D2GAME_EVENTS_Delete(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0
void __fastcall D2GAME_DeleteTimersOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30
void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame); // 0x00541400
void __fastcall EVENT_AllocEventQueue(D2GameStrc* pGame); // 0x00541470
void __fastcall EVENT_IterateEvents(D2GameStrc* pGame); // 0x005414D0
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct); // 0x00542AC0
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom); // 0x00542B40
void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame); // 0x00543080
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005433F0
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuest); // 0x005436B0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_QuestFree(D2GameStrc* pGame); // 0x00543800
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker); // 0x00543A30
void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nOldLevelId, int nTargetLevelId, D2UnitStrc* pUnit); // 0x00543B90
void __fastcall QUESTS_PlayerDroppedWithQuestItem(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543BD0
void __fastcall QUESTS_StatusCycleNpcActivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00543CE0
void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl); // 0x00543D10
void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC); // 0x00543D50
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80
void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543DB0
void __fastcall QUESTS_StatusCycleObjectReset(D2GameStrc* pGame, D2UnitStrc* pTarget); // 0x00543DE0
void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame); // 0x00543E10
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pStatus, D2BitBufferStrc* pFlags); // 0x00543F90
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage); // 0x005443B0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* ptGame, int nQuestId); // 0x005444B0
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760
void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00544E80
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArgs); // 0x00545530
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0
int __fastcall QUESTS_FXIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005456F0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char nEvent); // 0x00545760
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp); // 0x00545850
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00545B50
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nTargetLevel); // 0x00545B80
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex); // 0x00545C30
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0
void __fastcall QUESTS_QuestInit(D2GameStrc* pGame); // 0x00545D80
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int bGameEnter); // 0x00546270
D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* ptGame); // 0x00546E90
void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion); // 0x005479C0
void __fastcall MONSTERREGION_FreeAll(D2PoolSystemStrc* pMemPool, D2MonsterRegionStrc** ppMonsterRegion); // 0x00547B50
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame); // 0x00547D20
void __fastcall MONSTERREGION_UndoMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit); // 0x00547E90
D2WaypointDataStrc* __fastcall PLRMSG_GetWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50
void __fastcall PLRMSG_SendWalkMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode); // 0x00548180
void __fastcall PLRMSG_SendUnitMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005484B0
int __fastcall PLRMSG_SendPlayerStatUpdates(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int bSkipHpCheck); // 0x00548760
int __fastcall PLRMSG_InteractWithUnit(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00
void __fastcall PLRMSG_BroadcastChatMessage(D2GameStrc* game, const char* message, unsigned char color); // 0x0054A930
void __fastcall PLRMSG_BroadcastSystemMessage(D2GameStrc* pGame, const char* szMessage, unsigned char nColor); // 0x0054A9B0
void __fastcall PLRMSG_BroadcastEventMessage(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket); // 0x0054AA40
void __fastcall D2GAME_PlayerChangeAct(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc); // 0x0054B830
int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nNoInChain); // 0x0054DA60
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
void __fastcall D2GAME_PopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054EC90
void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054F060
void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00552610
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame); // 0x00552A40
unsigned char __fastcall OBJECTS_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord); // 0x00552AA0
unsigned char __fastcall OBJECTS_GetRegenerateSteps(); // 0x00552AB0
void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pPortal, int nUnitId); // 0x00552AF0
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit); // 0x00552B10
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* ptUnit); // 0x00552DB0
void __fastcall SUNIT_InitSeed(D2UnitStrc* ptUnit, D2SeedStrc* pSeed); // 0x00552DF0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* hUnit, D2ClientStrc* pClient); // 0x00553180
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_UpdateClientIfRoomInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005531E0
void __fastcall SUNIT_InitializeAnimation(D2UnitStrc* ptUnit); // 0x005533D0
void __fastcall SUNIT_ValidateTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553720
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980
void __fastcall D2GAME_DeletePlayerPerFrameEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990
void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFramesToRewind); // 0x00553C70
void __fastcall D2GAME_SKILLS_RewindSkillEx(D2GameStrc* pGame, D2UnitStrc* pUnit, int nElapsedFrames); // 0x00553DC0
void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* ptInfo); // 0x00553F30
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* hUnit); // 0x00554010
void __fastcall D2GAME_SetSparkChest(D2UnitStrc* pUnit, unsigned char nSparkChest); // 0x005540A0
unsigned char __fastcall D2GAME_CheckIfSparklyChest(D2UnitStrc* pUnit); // 0x005540D0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0
void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int bUpdate); // 0x005543B0
void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* hUnit, int bSetUninterruptable); // 0x005544B0
void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* ptGame, D2ActiveRoomStrc* hRoom, int bSkipRoomUpdate); // 0x00554850
int __fastcall SUNIT_UpdateUnitPath(D2GameStrc* ptGame, D2UnitStrc* pMissile); // 0x00554CA0
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x00554D20
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00554DE0
void __fastcall SUNIT_WarpPlayer(D2GameStrc* ptGame,D2UnitStrc* hUnit,D2UnitStrc* pTile); // 0x005550B0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall SUNIT_RemoveAllTiles(D2GameStrc* pGame); // 0x00555770
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags); // 0x005557D0
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x005559A0
void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555AE0
int __fastcall D2GAME_InitItemStats(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int bQuestItem); // 0x00557AB0
void __fastcall ITEMS_RemoveAll(D2GameStrc* pGame); // 0x00557F10
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2InventoryStrc* pOtherInventory); // 0x00557FF0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId); // 0x00558200
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558530
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558580
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10
void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct); // 0x00558B90
D2UnitStrc* __fastcall D2GAME_CreateItemEx(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90
D2UnitStrc* __fastcall ITEMS_DropRandomItemNearCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDropOut); // 0x00559130
D2UnitStrc* __fastcall D2GAME_DropArmor(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int nItemType, int bIgnoreRarity, D2UnitStrc* pUnit); // 0x005594C0
D2UnitStrc* __fastcall D2GAME_DropWeapon(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int nItemType, int bIgnoreRarity, D2UnitStrc* pUnit); // 0x00559630
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity); // 0x00559A30
D2UnitStrc* __fastcall D2GAME_CreateItemUnit(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B030
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B060
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B140
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags, int bSet); // 0x0055B260
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300
void __fastcall PLAYERLIST_SetPartyState(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nPartyState); // 0x0055B3A0
void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* hPlayer); // 0x0055B620
void __fastcall ITEMMODE_SendGroundItemToClient(D2UnitStrc* pItem, D2ClientStrc* pClient); // 0x0055BED0
void __fastcall ITEMMODE_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats); // 0x0055C460
int __fastcall ITEMMODE_CanPickUpItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055CC90
void __fastcall D2GAME_PickupItemEx(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int* pItemStatus); // 0x0055CF50
int __fastcall ITEMMODE_FindFreeBodyLocation(D2UnitStrc* pUnit, D2UnitStrc* hItem, int* pBodyLoc, int bSkipRequirementCheck); // 0x0055D710
void __fastcall D2GAME_ITEMS_UpdateInventoryItems(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused, int nArg); // 0x0055DF00
void __fastcall D2GAME_RemoveItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* hItem, int bSendPacket); // 0x0055DF10
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status); // 0x0055E170
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus); // 0x0055E7C0
int __fastcall ITEMMODE_PlaceCursorItemInBelt(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* pItemStatus); // 0x0055E9B0
void __fastcall ITEMMODE_CompactBeltColumn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX); // 0x0055EDC0
int __fastcall D2GAME_RemoveItemIfOnCursor(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
int __fastcall D2GAME_DoKeyCheck(D2GameStrc* ptGame, D2UnitStrc* hUnit); // 0x0055F140
void __fastcall D2GAME_UpdatePlayerVitals(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055F500
int __fastcall D2GAME_CheckHasFilledSockets(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590
D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pFreeQuantity); // 0x0055F640
void __fastcall ITEMMODE_AddBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue); // 0x0055F6E0
void __fastcall ITEMMODE_BreakItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F850
void __fastcall D2GAME_RepairBrokenItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F900
void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F9C0
void __fastcall ITEMMODE_RebuildBookScrollSkillQuantities(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055FA40
int __fastcall ITEMMODE_MarkItemOnCursor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* hItem); // 0x0055FB10
void __fastcall D2GAME_UpdatePlayerItems(D2GameStrc* pGame, D2UnitStrc* pUnit, int bRefresh); // 0x0055FDE0
void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0055FE00
int __fastcall D2GAME_RechargeItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80
int __fastcall D2GAME_PlaceItem(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int bAutoPosition, int bNotify, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall ITEMMODE_RemoveStoredItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus, int nUpdateMode, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int bAllowOccupiedCursor); // 0x00560420
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus); // 0x005606B0
int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus); // 0x00560CD0
void __fastcall ITEMMODE_RemoveBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00561E70
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390
void __fastcall D2GAME_ITEMS_Identify(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590
int __fastcall D2GAME_ITEMSOCKET_PlaceItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int bRecharge); // 0x00562660
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x00562E00
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00563470
int __fastcall D2GAME_PickupItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560
void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink); // 0x00564250
D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink); // 0x005642E0
int __fastcall TASK_GetClockTime(); // 0x00564340
void __stdcall TASK_FreeAllQueueSlots(); // 0x00564890
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit); // 0x00564CB0
void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00566BF0
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90
void __fastcall PLRTRADE_CloseCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567330
void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00567400
int __fastcall PLRTRADE_CopyTradeSaveDataToBuffer(D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize); // 0x005675E0
int __fastcall PLRTRADE_PrepareItemChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00567620
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused); // 0x005678A0
void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00568640
void __fastcall PLRSAVE2_InitPlayerFromClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00569F20
int __fastcall PLRSAVE2_ReadSaveHeader(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char** ppSection, unsigned char* pEnd, D2UnitStrc** ppPlayer); // 0x0056A090
int __fastcall PLRSAVE2_ReadQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A370
int __fastcall PLRSAVE2_ReadWaypointData(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A3E0
int __fastcall PLRSAVE2_ReadStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nStats); // 0x0056A620
int __fastcall PLRSAVE2_ReadSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nSkills); // 0x0056A710
int __fastcall PLRSAVE2_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError); // 0x0056A7E0
int __fastcall PLRSAVE2_ReadCorpses(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int* pDetailError); // 0x0056A830
int __fastcall PLRSAVE2_ReadPetSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion, int* pDetailError); // 0x0056AC10
int __fastcall PLRSAVE2_ReadIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion); // 0x0056AE50
void __fastcall PLRSAVE2_InitializeStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nHitpoints, int nMana); // 0x0056AF80
void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit); // 0x0056B6C0
void __fastcall SKILLS_ApplyDamageToTarget(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused); // 0x0056B9C0
int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int nPreviousTargetGUID, int* pTargetCount); // 0x0056BD10
int __fastcall SKILLS_ConsumeSkillMana(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel); // 0x0056BFE0
int __fastcall D2GAME_SKILLMANA_AuraConsume(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110
D2UnitFindDataStrc* __fastcall SKILLS_AllocUnitSearch(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210
int __fastcall SKILLS_ConsumeWeaponOrAmmoQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0
int __fastcall SKILLS_CanUseWeaponAmmo(D2UnitStrc* pUnit); // 0x0056C4E0
int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nStateId, int bIncludeState); // 0x0056C740
void __fastcall SKILLS_SetElementalDurationFromSkill(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId); // 0x0056C840
void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nLength, int* pResistStatId, int* pElementalType); // 0x0056C8E0
int __fastcall D2GAME_CreatePortalObject(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* hRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall D2GAME_GetXAndYFromTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
void __fastcall SKILLS_EnlargeVector(int* pX, int* pY); // 0x0056D370
void __fastcall SKILLS_MakeShortPerpendicularVector(int* pX, int* pY); // 0x0056D3B0
void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400
D2UnitStrc* __fastcall D2GAME_SummonPet(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit); // 0x0056DE40
void __fastcall D2GAME_RefreshPassiveSkills(D2UnitStrc* pUnit); // 0x0056DFA0
void __fastcall D2GAME_RollPhysicalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
void __fastcall SKILLS_RewindUnitAnimation(D2UnitStrc* pUnit, int nArg); // 0x0056E210
int __fastcall SKILLS_StartBasicAttack(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* hTarget); // 0x0056E230
int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
D2UnitStrc* __fastcall SKILLS_FindCorpseNearTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x0056E390
int __fastcall SKILLS_IsMissileTargetPositionClear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit); // 0x0056E510
void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit); // 0x0056E580
int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit); // 0x0056E5B0
unsigned short __fastcall SKILLS_SetDamageResultFlagsFromSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int nRangeOffset); // 0x0056E680
unsigned short __fastcall SKILLS_SetDamageResultFlags(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int nToHitFactor, D2DamageStrc* pDamage, int nRangeOffset); // 0x0056E6F0
D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nParam1, int nParam2, int nEventFunc, int nEventGroup, int nEventKey); // 0x0056E740
void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970
D2UnitStrc* __fastcall D2GAME_CreateMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
void __fastcall SKILLS_ApplySkillDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056F020
int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FAF0
void __fastcall SKILLS_ExecuteUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FC50
int __fastcall SKILLS_TryIncreaseSkillLevel(D2UnitStrc* pUnit, int nSkillId); // 0x00570080
void __fastcall D2GAME_AssignSkill(D2UnitStrc* pUnit, int bLeftSkill, int nSkillId, int nFlags); // 0x005701B0
void __fastcall SKILLS_ResetSkillsAndRefundPoints(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570360
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct); // 0x005706D0
void __fastcall PLAYERSTATS_OnPlayerLeveledUp(void* pUnused, D2UnitStrc* pUnit, int nArg); // 0x00570850
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* game,D2UnitStrc* unit); // 0x00570880
void __fastcall PLAYERSTATS_ResetToBaseStats(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570C80
void __fastcall D2GAME_STATES_SendUnitStates(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00570E30
void __fastcall D2GAME_STATES_SendStates(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580
void __fastcall SUNITMSG_SendOverlay(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0
void __fastcall SUNITMSG_SendRemoveObject(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600
void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620
void __fastcall D2GAME_UpdateUnit(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740
void __fastcall SUNITMSG_QueueItemSkillOnUnit(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, unsigned char nUnitType, int nUnitGUID, unsigned char nSkillParam); // 0x005717C0
void __fastcall D2GAME_MERCS_SendStat(D2UnitStrc* pUnit, unsigned short wStat, int nValue); // 0x005718C0
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent); // 0x00571A10
void __fastcall SUNITMSG_QueueSkillEvent(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char nSkillParam); // 0x00571AA0
void __fastcall SUNITMSG_QueueSkillStop(D2UnitStrc* pUnit, int nSkillId); // 0x00571B70
void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0
void __fastcall SUNITMSG_SendUnitToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572420
int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572470
void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId); // 0x005724C0
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwZero); // 0x005726C0
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* ptGame, D2UnitStrc* hPlayer, D2UnitStrc* pMerc, int nLevel); // 0x00572840
void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract); // 0x00572E00
void __fastcall MONSTERAI_ClearTargetOverride(D2UnitStrc* pUnit); // 0x00573120
int __fastcall MONSTERAI_IsInteractionReady(D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00573140
void __fastcall MONSTER_RemoveAll(D2GameStrc* pGame); // 0x00573640
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster); // 0x005736A0
void __fastcall MONSTER_ClearTargetIfMatches(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00573750
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005738D0
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster); // 0x00573930
int __fastcall MONSTER_HasComponents(D2UnitStrc* pUnit); // 0x00573AE0
void __fastcall MONSTER_Initialize(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom,D2UnitStrc* pMonster,int nUnitGUID); // 0x00574250
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClassId, int nMode); // 0x00574370
void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005746D0
void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc* pUnit, int nPetType, int nUnitGUID, D2PetInfoStrc* pPetInfo); // 0x005749B0
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00574BD0
D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int bIncludeDead); // 0x00574EC0
void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int bKillPet); // 0x005750E0
void __fastcall PLAYERPETS_HandlePetDeath(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet); // 0x005751A0
void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nX, int nY); // 0x005754B0
void __fastcall PLAYERPETS_SetPetLimit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax); // 0x00575850
void __fastcall PLAYERPETS_UpdatePetLimits(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575900
void __fastcall PLAYERPETS_AllocPetList(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575AF0
void __fastcall D2GAME_KillPlayerPets(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575BC0
void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo); // 0x00575E90
void __fastcall SUNITNPC_RemoveStoreItem(D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit); // 0x005766D0
void __fastcall D2GAME_NPC_BuildHirelingList(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo); // 0x00576770
D2UnitStrc* __fastcall D2GAME_MERCS_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short wName, int nSeed, unsigned short wVersion, int nBaseMonster, int bDead); // 0x005774F0
void __fastcall D2GAME_NPC_HireMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nMercName); // 0x00577FE0
void __fastcall D2GAME_NPC_IdentifyAllItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID); // 0x00578460
int __fastcall D2GAME_NPC_RemoveStates(D2UnitStrc* pUnit); // 0x00578C20
void __fastcall D2GAME_NPC_ResetInteract(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00579130
void __fastcall D2GAME_NPC_ResurrectMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId); // 0x00579C00
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2); // 0x0057A830
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057AF30
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender,D2DamageStrc* pDamage,int nWeapon,unsigned char nSrcDam); // 0x0057B7D0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker); // 0x0057C980
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bPetKill); // 0x0057CCB0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x0057CEE0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057D690
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid, int bBlock); // 0x0057DFB0
void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270
void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057E990
void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, int nExperienceBonus); // 0x0057EAB0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __fastcall PLRMODE_CanInterruptCurrentMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int bCheckUsedSkill, D2SkillStrc* pSkill); // 0x0057EEC0
void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310
void __fastcall PLRMODE_BreakDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00580380
void __fastcall PLRMODE_SendPlayerUpdates(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient, int bSkipInventory); // 0x00580860
void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int bAllowReEnter); // 0x005809D0
void __fastcall StartModeID(D2GameStrc* ptGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
void __fastcall OBJMODE_RemoveStaminaShrine(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x00583A40
void __fastcall OBJMODE_RemoveSkillShrine(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x00583BD0
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420
void __fastcall OBJMODE_CloseObjectInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x005854D0
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90
void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x00587950
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
int __fastcall ACT5Q2_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00587FC0
int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData); // 0x00588C50
void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pPortal); // 0x00588CA0
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588EB0
int __fastcall ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00589A50
int __fastcall ACT5Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00589AA0
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A0A0
void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A500
void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058A730
bool __fastcall ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0058AAB0
void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AD80
void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AE10
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058AEA0
void __fastcall ACT5Q4_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058B940
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058BE20
void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058C0E0
int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058C210
void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058CF00
void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058CF50
int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame); // 0x0058CF90
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel); // 0x0058D090
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D770
int __fastcall ACT5Q6_UnitIterate_SendZooMonsterIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058E180
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058E2B0
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058E640
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10
void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058EDE0
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pUnitGUID, int* pUnitType); // 0x0058F090
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList); // 0x0058F350
int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit); // 0x0058F710
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
void __fastcall ACT1Intro_Callback11_ScrollMessage(D2QuestDataStrc* quest, D2QuestArgStrc* arg); // 0x0058F870
void __fastcall ACT1Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058F8F0
bool __fastcall ACT1Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058F9B0
bool __fastcall ACT1Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058F9C0
void __fastcall ACT1Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FA90
void __fastcall ACT1Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FAD0
bool __fastcall ACT1Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058FB40
bool __fastcall ACT1Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058FB50
int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FBE0
int __fastcall ACT1Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590080
int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005900E0
void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590120
int __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590190
bool __fastcall ACT1Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x00590230
void __fastcall ACT1Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590690
int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590830
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005912E0
void __fastcall ACT1Q3_ACT1Q3_InitMalusObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00592090
void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00592F80
void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593290
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593CB0
void __fastcall ACT1Q4_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00594060
void __fastcall ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005940A0
void __fastcall OBJECTS_InitFunction54_CainStartPosition(D2ObjInitFnStrc* pOp); // 0x005940E0
void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005942C0
void __fastcall ACT1Q4_DropWirtsBodyGold(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00594630
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594830
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594890
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx); // 0x005954F0
void __fastcall ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005956C0
int __fastcall ACT1Q6_IsAndarielKilled(D2QuestDataStrc* pQuestData); // 0x005968C0
void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597310
void __fastcall D2GAME_INVMODE_First(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890
void __fastcall D2GAME_ResetSomeItemFlags(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x005979B0
void __fastcall D2GAME_INVMODE_Last(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597B00
void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc* pGame,D2UnitStrc* pUnit,D2ClientStrc* hClient); // 0x00597E20
void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005986B0
bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598780
int __fastcall ACT2Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005988B0
int __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598E20
int __fastcall ACT2Q2_UnitIterate_DetermineHoradricScrollDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599700
int __fastcall ACT2Q2_UnitIterate_DetermineStaffDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599750
int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005997C0
void __fastcall ACT2Q3_InitAltarObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059A3F0
bool __fastcall ACT2Q3_IsAltarDestroyed(D2QuestDataStrc* pQuest); // 0x0059AC80
void __fastcall ACT2Q4_OpenPalaceOrCycle(D2GameStrc* pGame); // 0x0059B660
void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059B710
int __fastcall ACT2Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BCB0
int __fastcall ACT2Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BD10
int __fastcall ACT2Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C650
int __fastcall ACT2Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused); // 0x0059C6C0
void __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C920
void __fastcall ACT2Q6_UnitIterate_SetCustom1Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CF20
void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059D6A0
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059D870
void __fastcall D2GAME_WarpPlayerToTile(D2ObjOperateFnStrc* pOp); // 0x0059D9D0
int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059DB20
bool __fastcall ACT2Q6_IsTyraelPortalOpened(D2GameStrc* pGame); // 0x0059DFB0
int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom); // 0x0059DFD0
void __fastcall ACT2Q8_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E3C0
void __fastcall ACT2Q8_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E3F0
bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059E4B0
void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F380
void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F440
unsigned char __fastcall ACT2Q4_IsJerhynPalaceBlocked(D2GameStrc* pGame); // 0x0059F510
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame); // 0x0059F840
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __fastcall MONSTERUNIQUE_GetMonUModConstant(int nIndex); // 0x005A00F0
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0
int __fastcall MONSTERUNIQUE_GetUModCount(unsigned char* pUMods); // 0x005A0260
void __fastcall MONSTERUNIQUE_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nMode, int bApply); // 0x005A0E80
void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A1650
void __fastcall MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005A23D0
void __fastcall MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A29A0
void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A3040
void __fastcall MONSTERUNIQUE_ExecuteUModModeStartCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4350
void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4360
void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4390
void __fastcall MONSTERUNIQUE_ExecuteUModDamagedCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A43A0
void __fastcall MONSTERUNIQUE_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile); // 0x005A43B0
void __fastcall MONSTERMODE_AllocateTargetCombat(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x005A5490
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg); // 0x005A5C70
void __fastcall PARTYSCREEN_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure); // 0x005A5D20
int __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2); // 0x005A6080
void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2); // 0x005A60E0
void __fastcall MONSTERMODE_SetVelocityParams(D2AiParamStrc* pAiParam, int nParam18, int nParam1C, unsigned char nParam20); // 0x005A6260
int __stdcall D2GAME_ModeChange(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int bClearUsedSkill); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops); // 0x005A9370
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005AD730
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int bForceCollision); // 0x005ADF10
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* hUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall D2GAME_UpdateSummonAI(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNodeData, int nNodeIndex); // 0x005B1900
void __fastcall TARGETS_InsertUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNodeData, int nNodeIndex); // 0x005B1990
void __fastcall TARGETS_RemoveUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B1A90
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2490
int __fastcall MONSTERSPAWN_SpawnTentacleMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags); // 0x005B2570
D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster(D2UnkMonCreateStrc* pCreate); // 0x005B2A00
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F70
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B3040
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags); // 0x005B3090
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int nMaxSearchRings, short nFlags); // 0x005B30E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithOwnerData(D2GameStrc* pGame, void* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, int bSetFlag2, unsigned short nFlags); // 0x005B3130
int __fastcall sub_005B31B0_SpawnMinionsAt(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, int nCount, short nFlags); // 0x005B31B0
int __fastcall MONSTERSPAWN_SpawnBonePrison(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused1, int nUnused2, D2UnitStrc* pTargetUnit, int nMonsterId, short nFlags); // 0x005B34C0
bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B3750
bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B37F0
int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3860
bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B38E0
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData); // 0x005B3940
void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B39A0
void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3BB0
int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3CD0
void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3D70
int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3DE0
bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest); // 0x005B3E60
int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3F20
void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4020
void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4140
void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B41D0
void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4220
int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4A80
D2UnitStrc* __fastcall ACT4Q2_TrySpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx); // 0x005B4B60
void __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4DA0
void __stdcall ACT4Q2_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005B4FF0
void __fastcall ACT4Q2_SpawnSealBoss(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B5750
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B59C0
void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B5A90
bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B5EE0
bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B5F40
int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B5FC0
void __fastcall ACT4Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6080
void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6100
void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B62D0
void __fastcall ACT4Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg); // 0x005B6440
void __fastcall ACT4Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B64A0
void __fastcall ACT4Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B64C0
void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B64E0
void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B65D0
void __fastcall ACT4Q3_InitQuestData(D2QuestDataStrc* pQuestData); // 0x005B6610
void __fastcall ACT4Q3_CreateReward(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B6710
void __fastcall ACT4Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6940
bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B69F0
void __fastcall ACT4Q4_InitQuestData(D2QuestDataStrc* pQuestData); // 0x005B6A70
void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6D30
bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B6E20
bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B6E30
void __fastcall ACT3Intro_InitQuestData(D2QuestDataStrc* pQuestData); // 0x005B6E60
void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6ED0
void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6F20
bool __fastcall ACT3Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B6FA0
void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6FD0
void __fastcall ACT3Q1_InitTomeObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x005B7310
int __fastcall ACT3Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B7340
void __fastcall ACT3Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7400
void __fastcall ACT3Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7740
void __fastcall ACT3Q2_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B85E0
int __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BAC70
void __fastcall ACT3Q4_CheckGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BACF0
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BADC0
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAF70
void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BB550
bool __fastcall ACT3Q5_IsOrbNotSmashed(D2GameStrc* pGame); // 0x005BBF80
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BBFA0
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC210
void __fastcall ACT3Q6_UpdateHellGatePortal(D2QuestDataStrc* pQuest, D2UnitStrc* pObject); // 0x005BCAC0
bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BD0C0
bool __fastcall ACT3Q7_SpawnVileDogs(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005BD390
void __cdecl sub_005BDB10_Return(); // 0x005BDB10
int __fastcall MONSTERCHOOSE_GetPresetMonsterId(D2GameStrc* pGame, D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom, D2MonStatsTxt** ppMonStatsTxtRecord, unsigned char nChance, int bSpawnUMon); // 0x005BDE80
int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId); // 0x005BEDA0
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY); // 0x005BF240
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues); // 0x005BFDA0
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int nEventKey); // 0x005C0B50
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30
void __stdcall ITEMS_AssignLegacyStaffMods(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId); // 0x005C0D70
void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pUnit, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl); // 0x005C0F90
short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0
unsigned short __fastcall ITEMS_RollTemperedItemAffix(D2UnitStrc* pItem, int bPrefix); // 0x005C1BC0
int __fastcall D2GAME_RollRareItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21A0
int __fastcall ITEMS_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21D0
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll); // 0x005C2540
int __stdcall ITEMS_RollLegacySetItem(D2UnitStrc* pItem); // 0x005C2740
void __fastcall SKILLS_CurseStateCallback_ResetAi(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3370
void __fastcall SKILLS_ApplyDimVisionToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0
int __fastcall D2GAME_SKILLS_SetSummonBaseStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0
int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nLife); // 0x005C6870
int __fastcall SKILLS_GetConvertedMode(D2UnitStrc* pUnit, int nMode); // 0x005C6BF0
void __fastcall SKILLS_RemoveStateAndRestoreSkillMode(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList); // 0x005C6C50
void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0
int __fastcall SKILLS_CreateMissileSpread(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int bCreateFirstMissile); // 0x005C7040
int __stdcall SKILLS_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel); // 0x005C7B10
void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C8BF0
int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0
int __fastcall SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8E30
void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C9420
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender); // 0x005C96A0
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C9D90
void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x005CC440
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960
int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005CCC80
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CEDC0
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D0D70
void __fastcall SKILLS_AttachImpToMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D18E0
void __fastcall SKILLS_DetachImpFromMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel); // 0x005D19D0
D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nUnitSize); // 0x005D2F80
int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490
void __fastcall SKILLS_ApplyProgressivePhysicalDamageBonus(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3AC0
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3DA0
int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMissileId, int nCount, int nRange, int nSkillId, int nSkillLevel); // 0x005D5BF0
int __fastcall SKILLS_SrvDo048_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D68A0
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel, int bCheckOnInit); // 0x005D6B60
int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0
int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290
int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005D8510
int __fastcall SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8C70
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int nBonus); // 0x005DB6A0
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530
int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DC640
int __fastcall AIUTIL_GetLifePercentage(D2UnitStrc* pArg); // 0x005DD280
int __fastcall AIUTIL_HasClearMissilePath(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DD290
int __fastcall AIUTIL_IsGettingHit(D2UnitStrc* pUnit); // 0x005DD2B0
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330
D2UnitStrc* __fastcall AIUTIL_FindAiTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nParam1, int nDuration); // 0x005DDD00
D2UnitStrc* __fastcall AITACTICS_FindTargetInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance); // 0x005DDE50
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall D2GAME_AICORE_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
D2UnitStrc* __fastcall AITACTICS_FindTargetOrIdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DE890
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DECA0
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DED20
int __fastcall AITACTICS_WalkToTargetWithPathType13(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DED90
int __fastcall AITACTICS_WalkToTargetCoordinatesNoSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEF30
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteEvent); // 0x005DEFE0
int __fastcall AITACTICS_RunAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nDistance, int bDeleteEvent); // 0x005DF140
int __fastcall AITACTICS_WanderToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance); // 0x005DF400
int __fastcall D2GAME_AICORE_WalkToOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530
void __fastcall QUESTSFX_Bloodraven(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DFD90
void __fastcall QUESTSFX_SpawnMephistoDeathControlMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DFDB0
void __fastcall QUESTSFX_Andariel(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DFE00
void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DFE20
void __fastcall QUESTSFX_SpawnCompellingOrbMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DFEE0
void __fastcall QUESTSFX_Izual(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005E0020
void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005E0040
void __fastcall QUESTSFX_OnQuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005E0060
void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005E0070
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E2B70
int __fastcall AITHINK_PetMove(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nMode, int bRun, int nVelocity, int nDistance); // 0x005E3930
int __fastcall D2GAME_AI_PetMove(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nMove, int bRun, int nVelocity, int nRange); // 0x005E3EA0
int __fastcall AITHINK_TryPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int bCombat, D2AiTickParamStrc* pAiTickParam, int bSkipIdle, int nRange); // 0x005E45D0
void __fastcall AITHINK_HirelingCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, D2UnitStrc* pOwner, D2UnitStrc* pTarget, D2SeedStrc* pSeed, D2AiTickParamStrc* pAiTickParam); // 0x005E5050
int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiCmdStrc* pArgs); // 0x005E8530
int __fastcall AITHINK_AreUnitsInSameLevel(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005EEB10
int __fastcall AITHINK_GetTrapArrowVariant(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005FB650
int __fastcall MONSTERSPAWN_CanSpawnAtSpawnerExit(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int nFlag); // 0x005FD350
int __fastcall MONSTERSPAWN_CheckSkillPlacement(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005FD470
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int bUseResurrectConfig); // 0x005FD7B0
int __fastcall SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int nItemEffectParam); // 0x005FDA80
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nItemEffectParam); // 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nItemEffectParam); // 0x005FDD60
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

// D2Game data that two or more of the module's files use.
extern const char gszEmptyLoadComplete[184]; // 0x006E0498
extern const char gData_006E0550[24]; // 0x006E0550
extern const char gData_006E0568[272]; // 0x006E0568
extern const int gnBugLightningYOffsets[]; // 0x006E2198
extern const int gnBugLightningXOffsets[]; // 0x006E21A8
extern const int gnDifficultyBonus[]; // 0x006E21F4
extern const int gnRareAffixCounts[]; // 0x006E3014
extern const int gnHydraOffsetY[]; // 0x006E3120
extern const int gnHydraOffsetX[]; // 0x006E312C
extern const unsigned char gnGargoyleTrapDirectionAxis[]; // 0x006E353C
extern const unsigned char gnGargoyleTrapDirectionMap[]; // 0x006E3540
extern int gbCheckHeartbeat; // 0x00730FFC
extern int nInitSeed_6FDC2CA08; // 0x00731004
extern int gdwGlobal_00731008; // 0x00731008
extern int gbFixedCpuTargetRatio; // 0x0073100C
extern int gdwGlobal_00731010; // 0x00731010
extern int gnFrameRate; // 0x00731010
extern int gnTargetFrameRate; // 0x00731014
extern int gnQuestInitTableCount; // 0x00731888
extern int gnQuestIntroTableCount; // 0x007318AC
extern int gnBaseStatIdsToSend[]; // 0x00731AD8
extern unsigned int gnA5Q4NpcIndices[]; // 0x007350E8
extern char gpAct1IntroNpcMessages[]; // 0x007361F8
extern char gpAct1Q0NpcMessages[]; // 0x00736460
extern char gpAct2Q8NpcMessages[]; // 0x0073BD58
extern char gpAct4Q0NpcMessages[]; // 0x0073D580
extern char gpAct4Q1NpcMessages[]; // 0x0073D708
extern char gpAct3IntroNpcMessages[]; // 0x0073E850
extern char gpAct3Q0NpcMessages[]; // 0x0073EAA0
