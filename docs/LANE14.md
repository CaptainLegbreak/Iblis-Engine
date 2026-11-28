# Lane 14: the port to a modern compiler

Board for the Fable chat (lane 14). Lane 14 writes this file on the `board` branch; the coordinator (lane 10 of
Iblis Codex) answers here and keeps the queue stocked. Newest entries at the top of each section.

Goal: roadmap M0 and M1 with a current compiler. The engine's source builds with CMake and a current 32-bit MSVC,
links as an ordinary Windows program with nothing read from Game.exe, and passes M1's check on the user's PC.

## Queue (coordinator-kept, top down)

**Changed 2026-11-27 17:00 PT (the user):** Iblis Codex stays the one place the game source is cleaned up (names,
declarations, data layout: Codex lanes 1, 11, 12 and 13). The engine's game source stays a copy of Codex main,
re-synced the way item 0 did it; lane 14 doesn't hand-edit game code here. It finds out what a modern compiler
needs and posts the source fixes for the Codex lanes to make, and it builds the engine-only pieces.

- ~~0. Bring Source/ up to Codex main~~ done (PR #1). Repeat it after Codex rounds when the board asks.

**Now:**

~~1. CMake and the compile report~~ done (#5).

1. (done) **CMake and the compile report** (lane14/cmake): CMakeLists.txt for VS 2022 x86, one static library per
   original module folder plus the program, `/arch:IA32` first, no /GL, the conformance switches 2005 code needs
   in one list. Build-system files are yours to change; game source isn't. Write `docs/PORT_COMPILE.md`: every
   file that fails, its first error, grouped by cause, and the source fix for each cause. Post the fixes under
   Findings by Codex module; the Codex lanes make them there (they keep the byte-exact build), and they come back
   with the next sync. Keep the report current after each sync.
2. **The open PKWARE DCL routines** Storm calls (implode and explode), written from the format (zlib's blast.c
   covers explode; NOTICE-ZLIB.txt is here), with a round-trip test against data the original library compressed
   in the user's own MPQs. Engine-only, Source/Storm/.
3. **The program's own resources:** icon, version info, and the dialogs and strings Game.exe's .rsrc holds,
   written from scratch from what they need to do. Nothing copied from Game.exe.
4. **The `// build:` markers:** a script that removes them in the sync step (item 0's tooling), so every sync
   drops them, rather than a hand edit of the copy.
5. **Link report:** with the objects from item 1, link with the modern linker and list every unresolved or
   duplicate symbol in `docs/PORT_LINK.md`, grouped the way Codex's tools/linkdebt.py groups them. This measures
   what is left. Fix nothing in the copy; Codex lanes 11 and 12 are on it.

6a. **Once Game.exe is attached:** check the 16 zero bytes from item 0, and the export names of the binkw32,
   smackw32 and ijl11 stubs against Game.exe's import table.
6b. **Re-sync after Codex rounds** with tools/codex_sync.py when Codex main moves (Codex #492 is out now, more
   follow), then rerun the compile report. One PR per sync.

6c. **Link findings to the Codex lanes after each sync:** from PORT_LINK.md, post under Findings the symbols
   whose fix belongs to one Codex lane (type_disagreement, local_copy, duplicate_data: lane 12;
   different_identifier, placeholder, unsourced_data: lane 11; interior: lane 13), most-referenced first,
   and especially the 172 `no_address` symbols (declarations with no `// 0x` marker): those are invisible
   to Codex's linkdebt.py, so list them by file for lane 12.
6d. **M2 groundwork (engine-only, developer tool):** design the replay test harness in docs/REPLAY.md: how a
   fixed-seed run is recorded against stock 1.14d on the user's install and replayed through the engine
   (map generation for a seed, the item drops of a seeded kill, a scripted save), what is compared, and the
   smallest first test. Then a skeleton under tools/replay/. It must not need Codex at run time.

**Later, when the coordinator says Codex's link debt is low enough** (21,648 references on Codex #492):

6. The last references that still disagree, fixed once in the engine's source.
7. Data that only works at its original address, if any is left after Codex lanes 1 and 13.
8. M1: the exe to the user to test (menus, a character of each class, Act 1, save and reload, TCP/IP against
   stock 1.14d); docs/PORT_RUN.md.

## Answers (coordinator)

- 2026-11-27 18:00 PT: #6 and #7 merged. Good checks on the MPQs and the DLL names. While Codex works: 6b after each round, plus new items 6c and 6d.

- 2026-11-27 17:20 PT: #2-#5 merged, #1 closed. Very good work: 538 of 538 files compile. Your Findings went onto
  Codex lane 12's queue (item 5). The MPQs: the user will be asked to attach them with Game.exe. Next: item 5,
  the link report.

- 2026-11-27 17:00 PT, Game.exe: the user attaches it to your chat (folder access through the app's check didn't
  go through). Until then, park what needs it. The 16 zero bytes in PR #1 stay until they're checked; the stale
  `include` entries in Codex's data plan go to the Codex board.

## Ready

## Claimed


## Findings

- 2026-11-27 19:45 PT, item 6c after the sync to Codex 0bf13c4 (#494, PR #11): 59 unresolved symbols resolved,
  one new. **D2Client (the lane that made d5f903fe6):** `gpNpcPlayerUnit` (0x007C0DD4) is now a member of
  `gtNpcMenu` (UI/npcmenu.cpp), but D2ClientFuncs.h:906 still declares it on its own and UNIT/Monster.cpp:3035
  writes it through that: it should go through gtNpcMenu (D2ClientNpcMenu.h). The 23 `D2PoolSystemStrc*`
  disagreements from the 19:00 line are still open (lane 12).

- 2026-11-27 19:00 PT, item 6c after the sync to Codex 19eef12 (#493, PR #10): 23 symbols became unresolved,
  21 of them because a declaration now takes `D2PoolSystemStrc*` where its definition (or another file's
  declaration) still takes `void*`, the pool retyping part way, **Codex lane 12**: `CodecDecodeDccData`, `DRLGACTIVATE_RoomExPropagateSetStatus`, `DRLGGRID_FillNewCellFlags`, `DRLGROOM_AllocPresetUnit`, `DUNGEON_AllocAct`, `FOG_AsyncDataLoadFileEx`, `FOG_FreePool`, `FOG_FreeServerMemory`, `GFXUTIL_GetNextRosterInfo`, `GfxHashAdd`, `GfxHashFreeEntry`, `LRUCacheInit`, `QUESTRECORD_FreeRecord`, `UNITFINDS_InitializeUnitFindData`, `WAYPOINTS_FreeWaypointData`, `sub_0040B430`, `sub_0040B480`.

- 2026-11-27 18:20 PT, item 6c, link findings at Codex 7442280 (docs/PORT_LINK.md, PR #8), by lane, the
  most-referenced first (number = files that ask; `a` -> `b`: declared a, the definition at its address is b):
  - **Codex lane 12:**
    - type_disagreement (1833 symbols, 2557 refs): `FOG_AllocPool` 90; `D2COMMON_10475_PostStatToStatList` 36; `UNICODE_StrLen` 34; `FOG_FreePool` 30; `SUNIT_IterateUnitsOfType` 19; `QUESTS_CheckPlayerGUID` 19; `SCMD_RegisterMsgHandlers` 12; `DUNGEON_GetAdjacentRoomsListFromRoom` 12; `PATH_SetVelocity` 12; `SUNIT_ResetInteractInfo` 10
    - local_copy (323 symbols, 839 refs): `sub_M106_Emit_0051DC70` 9; `ACT3Q7_StatusFilterCallback` 8; `ACT3Q5_Callback10_PlayerLeavesGame` 7; `sub_00401A60_UnlockSymbols` 6; `~D2Storm4167B0Strc` 5; `~D2Storm4168F0Strc` 5; `DRLGPRESET_GetLinkRawNext` 5; `D2ChatStormListCStrc` 5; `IGNORELIST_ResetStringList` 5; `??3@YAXPAX@Z` 4
    - duplicate_data (84 symbols, 187 refs): `gpfnMcpMotdCallback` 4; `gawScrollSlots` 3; `gaStateStack` 3; `gSlotFirst` 3; `gSlotSecond` 3; `gbQuestDebug` 3; `gGameListLock` 3; `gpGame` 3; `gnGamesGUIDs` 3; `gdwGlobal_00882D14` 3
  - **Codex lane 11:**
    - different_identifier (149 symbols, 347 refs): `FOG_FreeServerMemory` -> `FOG_FreePool` 33; `D2COMMON_10170_PathSetTargetPos` -> `PATH_SetTargetPos` 19; `STATLIST_SetStat` -> `STATLIST_SetStatIfListIsValid` 17; `ITEMS_GetInvPage` -> `ITEMS_GetInventoryPage` 16; `PATH_SetTargetUnit` -> `PATH_SetPathTarget` 15; `D2Win_10034_MixRGB` -> `PALETTE_FindPaletteIndex` 14; `sgtDataTables` -> `gpPlayerClassTxt` 12; `D2COMMON_10476` -> `STATLIST_SetListExpireFrame` 11; `UNITS_GetDistanceToCoordinates` -> `DRLG_GetDistanceToXY` 8; `DUNGEON_GameTileToSubtileCoords` -> `SKILLS_GameTileToSubtileCoords` 7
    - placeholder (1047 symbols, 1781 refs): `sub_004B9A00` -> `SOUNDINST_PlaySound` 44; `sub_005267E0` -> `strcpy` 39; `gnScreenWidth` -> `gnScreenWidth_0071146C` 38; `sub_0040B430` -> `FOG_AllocPool` 34; `sub_0040B480` -> `FOG_FreePool` 29; `sub_00526700` -> `strcat` 29; `ITEMS_CheckItemFlag` -> `sub_006280A0` 29; `sub_004F6480` -> `TEXTURE_CelDraw` 27; `sub_00526F20_ToUnicode` -> `win2Unicode` 22; `gdwBitMasks_006CE268` -> `gdwBitMasks` 19
    - unsourced_data (750 symbols, 1270 refs): `gszEmptyAssertText` 287; `gszDataGlobal` 24; `gszTxtField_end` 18; `gszFormatD` 13; `gszNewline` 10; `gszNew` 8; `gszEmptyString` 7; `gszStringFormat` 7; `gszSpace` 6; `gszPathFormat` 6
  - **Codex lane 13:**
    - interior (9 symbols, 9 refs): `gbPanelFlag` -> `gaEscMenuUIState+0x104` 1; `gtUnitSndObject` -> `gaUnitSndObjects+0x13E0` 1; `gnRenderFlag` -> `gdwBitMasks+0x28` 1; `gnFlagSet0_006CE278` -> `gdwBitMasks+0x10` 1; `gdwBitMask5` -> `gdwBitMasks+0x14` 1; `gnFlagClear0` -> `gdwInvBitMasks+0x10` 1; `gnFlagClear1` -> `gdwInvBitMasks+0x14` 1; `gdwTitleMaskA` -> `gdwBitMasks+0x18` 1; `gdwBitMask7` -> `gdwBitMasks+0x1C` 1
  - **Codex lane 12, the 172 `no_address` symbols** (no `// 0x` marker on any declaration the file sees, so
    linkdebt.py can't see them), by file:
    - D2BNClient/BNetGW.cpp: `Nth`
    - D2CMP/SRC/CelCmp.cpp: `IGNORELIST_InternalClearStringTable`, `gszIgnoreListSourceFile_006E6290`, `gszTypeNewsTableItem`, `sub_00517ABB_BitScanForward1`, `~D2SGameDataStrc`, `~D2StormGameArrayStrc`, `~WardenModule`
    - D2CMP/SRC/FastCmp.cpp: `sub_00517993_VirtualAlloc`, `sub_00605AA0_BuildTablesC`, `sub_00605B70_BuildTablesD`
    - D2CMP/SRC/Tilecmp.cpp: `sub_005179B3_ConvertCelPixels`
    - D2Client/CORE/WINMAIN.CPP: `gpfnLaunchInit`, `gpfnLaunchStates`
    - D2Client/ENGINE/Gfx.cpp: `GFXUTIL_ForEachUnitInAdjacentRooms`, `sub_00517079_LoadFile`, `sub_M274_EmitBuildPath`
    - D2Client/ENGINE/GfxUtil.cpp: `gTableView_00744304`
    - D2Client/ENGINE/Particle.cpp: `gB28Archive`, `gB28Palette`, `gB28SubmitFlag`, `gB28SubmitItem`, `gB28Waypoint`, `gB28WaypointFlag`, `sub_0046F060_GetGfx`, `sub_004786D0_SendPacket`, `sub_004FB180_Palette`
    - D2Client/GAME/Game.cpp: `IGNORELIST_InternalClearStringTable`, `gAllocation`, `gCleanupState`, `gCoordinateBase`, `gCoordinateOffset`, `gszIgnoreListSourceFile_006E6290`, `sub_004646A0_GetAuxiliary`, `szWardenClientFile`, `~WardenModule`
    - D2Client/GAME/Game_0044B7B0.cpp: `gAllocation`, `gCleanupState`, `gCoordinateBase`, `gCoordinateOffset`
    - D2Client/GAME/View.cpp: `sub_00473910`
    - D2Client/GAME/Wall2.cpp: `sub_004DE410_DrawFloorTile`
    - D2Client/UI/Hireables.cpp: `sub_K04_EmitUse`
    - D2Client/UI/Party.cpp: `sub_K04_EmitUse`
    - D2Client/UI/editbox.cpp: `Slot13`
    - D2Client/UI/inv.cpp: `InitializePalette`, `ReleaseResource`, `gColor`, `gLookupHead_007BB5BC`, `gResourceA`, `gResourceB`, `gScreenHeight`, `gScreenWidth`, `gValue_00712F44`, `gValue_00712F48`, `gValue_007A6ABC`, `gValue_007A6ADC`, `gValue_007A6AE0`, `gValue_007A6AF0`, `gValue_007BB5D8`, `gValue_007BB5E4`, `gValue_007BB5E8`, `sub_0062C0B0_GetItemTypeClass`
    - D2Client/UI/npcmenu.cpp: `DIALOG_AddTextLine`, `DIALOG_CreateDialog`
    - D2Client/UI/npcmenu_004B5C60.cpp: `ListBoxWrapper`
    - D2Client/UI/panel.cpp: `sub_00468730_MouseX`, `sub_00468740_MouseY`, `sub_00502280_SetTooltip`, `sub_00524A30_LocalizedText`
    - D2Client/UI/spellsel.cpp: `sub_K05_EmitUse`
    - D2Client/UI/text.cpp: `ListBoxWrapper`, `gB27_00726CCB`, `gB27_00726CDB`, `gB27_00726E01`, `gB27_00726E0F`, `gB27_00726E4F`, `gB27_00726E5D`, `gB27_00726E9D`, `gB27_00726EAB`, `gB27_00726F87`, `gB27_00726F95`, `gB27_00727247`, `gB27_00727257`, `gB27_00727297`, `gB27_007272A9`, `gB27_007272E1`, `gB27_007272EF`, `gB27_007BCBF0`, `gTables_00744304`, `gatBnHashCtx`, `gnHireMenuState`, `gnIdentifyMenu1State`, `gnIdentifyMenu2State`, `gnIdentifyMenu3State`, `gnIdentifyMenu4State`, `gnIdentifyMenu5State`, `gnImbueMenuState`, `gnPersonalizeMenuState`, `gnResurrectMenuState`, `gnSocketMenuState`, `gnTravelHarrogathState`, `gnTravelKurastDocksState`, `gnTravelLutGholeinState`, `gnVirtualPlayerCount`, `gpfnIdentifyMenu1Handler`, `gpfnIdentifyMenu2Handler`, `gpfnIdentifyMenu3Handler`, `gpfnIdentifyMenu4Handler`, `gpfnIdentifyMenu5Handler`, `gpfnResurrectMenuHandler`, `gpfnTravelHarrogathHandler`, `gwIdentifyMenu1StringId`, `gwIdentifyMenu2StringId`, `gwIdentifyMenu3StringId`, `gwIdentifyMenu4StringId`, `gwIdentifyMenu5StringId`, `gwTravelHarrogathStringId`, `sub_00525150`, `sub_L04_EmitUse`
    - D2Client/UNIT/Monster.cpp: `sub_M103_EmitSink`
    - D2Client/UNIT/PlrSkills.cpp: `sub_K06_EmitGettier1`, `sub_K06_EmitGettier2`, `sub_K06_EmitPuttier1`, `sub_K06_EmitPuttier2`
    - D2Client/UNIT/UnitMode.cpp: `sub_0044DB10_GetFrame`, `sub_00480420_ValidatePath`, `sub_00639DF0_CheckState`, `sub_00650840_UpdatePath`, `sub_K04_EmitUse`
    - D2Client/Unknown_0045FB80.cpp: `gbSkillPointsHighlight`, `gszFormatD`, `sub_00420290_HandleMsg`, `sub_00463DD0`, `sub_004B9A00`, `sub_00502280_SetPopUpText`
    - D2Client/Unknown_00472210.cpp: `sub_004B9A00`
    - D2Client/Unknown_0047CC90.cpp: `sub_K04_EmitUse`
    - D2Client/Unknown_004B8720.cpp: `DIALOG_AddTextLine`, `DIALOG_CreateDialog`, `sub_00478600_SendPacket`
    - D2Client/Unknown_004BBE10.cpp: `OnLButtonDown`
    - D2Client/Unknown_004E4670.cpp: `sub_004E5A10_UseBonusCount`
    - D2Client/WARDEN/WardenClient.cpp: `sub_K04_EmitUse`
    - D2Common/Chat/Ignorelist.cpp: `gszTypeNewsTableItem`
    - D2Common/DATATBLS/LvlTbls.cpp: `sub_00681E09_Exit`
    - D2Common/DRLG/DrlgActivate.cpp: `gRoomExSetStatus`
    - D2Common/DRLG/OutDesr.cpp: `sub_M127_EmitSink`
    - D2Common/DRLG/OutWild.cpp: `gszEmptyAssertText`
    - D2Common/ITEMS/Items.cpp: `sub_0045ADF0_GetX`, `sub_0045AE20_GetY`
    - D2Common/UNITS/Units.cpp: `sub_0040B480_FreePool`
    - D2Common/Unknown_006634F0.cpp: `sub_M102_UseBonusCount_00663A10`
    - D2Direct3D/Src/d3dCore.cpp: `sub_006B1350_DirectDrawCreate`
    - D2Direct3D/Src/d3dSubtileCache.cpp: `sub_006BABD0_Unlink`
    - D2Game/GAME/Clients.cpp: `sub_0063E510_FillInventoryTables`
    - D2Game/GAME/Game.cpp: `sub_0052C170_AllocGameId`
    - D2Game/PLAYER/PlrMsg.cpp: `sub_0054CC30_StatRemoveCallback_ToggleStateOff`
    - D2Game/Quests/a2q1.cpp: `gszA2Q1SourceFile`
    - D2Game/SKILLS/SkillNec.cpp: `sub_0046C140_TestMode`, `sub_005A0180_TestMonType`
    - D2Game/Unknown_00555C90.cpp: `sub_K11_EmitUse`
    - D2Glide/Src/glCore.cpp: `gpfnGrDrawPoint`, `gpfnGrLfbLock`, `gpfnGrLfbUnlock`, `gpfnGrTexMaxAddress_0087EB44`, `gpfnGrTexMinAddress_0087EB24`
    - D2Glide/Src/glSprite.cpp: `gpfnGrGlideState`
    - D2Glide/Unknown_0050BD30.cpp: `gpfnGrDrawPoint`
    - D2Glide/Unknown_0050F910.cpp: `gpfnGrLfbLock`, `gpfnGrLfbUnlock`
    - D2Hell/Unknown_00516D8B.cpp: `gB27_00726CCB`, `gB27_00726CDB`, `gB27_00726E01`, `gB27_00726E0F`, `gB27_00726E4F`, `gB27_00726E5D`, `gB27_00726E9D`, `gB27_00726EAB`, `gB27_00726F87`, `gB27_00726F95`, `gB27_00727247`, `gB27_00727257`, `gB27_00727297`, `gB27_007272A9`, `gB27_007272E1`, `gB27_007272EF`, `gB27_007BCBF0`, `gnHireMenuState`, `gnIdentifyMenu1State`, `gnIdentifyMenu2State`, `gnIdentifyMenu3State`, `gnIdentifyMenu4State`, `gnIdentifyMenu5State`, `gnImbueMenuState`, `gnPersonalizeMenuState`, `gnResurrectMenuState`, `gnSocketMenuState`, `gnTravelHarrogathState`, `gnTravelKurastDocksState`, `gnTravelLutGholeinState`, `gnVirtualPlayerCount`, `gpfnIdentifyMenu1Handler`, `gpfnIdentifyMenu2Handler`, `gpfnIdentifyMenu3Handler`, `gpfnIdentifyMenu4Handler`, `gpfnIdentifyMenu5Handler`, `gpfnResurrectMenuHandler`, `gpfnTravelHarrogathHandler`, `gwIdentifyMenu1StringId`, `gwIdentifyMenu2StringId`, `gwIdentifyMenu3StringId`, `gwIdentifyMenu4StringId`, `gwIdentifyMenu5StringId`, `gwTravelHarrogathStringId`, `sub_005173EF_Display`, `sub_0051755C_LinkNode`, `sub_005176B4_Release`
    - D2Lang/Unicode/UNISYS.CPP: `sub_00517079_LoadFile`
    - D2Launch/Src/CharSel.cpp: `sub_00438F70`, `sub_005066C0_CreateComposite`, `unicode2Win`
    - D2Launch/Src/MainMenus.cpp: `gControl`, `sub_004F9740_ControlFlag`, `sub_00525150_Language`
    - D2Launch/Unknown_0043B7A0.cpp: `UnicodeChar`
    - D2Multi/Src/ChatDlg.cpp: `UnicodeChar`
    - Fog/Src/QServer/QServer98.cpp: `sub_006B0180_IsSocketSet`, `sub_006C9B6A_Accept`, `sub_006C9B70_Listen`
    - Fog/Unknown_00402820.cpp: `sub_M127_EmitSink`, `sub_M452_EmitSink`
    - Storm/SOURCE/SFILE.CPP: `IGNORELIST_InternalClearStringTable`, `gpfnReadErrorCallback_00779030`, `gszIgnoreListSourceFile_006E6290`

- 2026-11-27 18:00 PT, proposal for item 6, for the coordinator to decide (no PR; branch lane14/link-aliases,
  on #7 with #6 merged in). The user had said to keep going without the coordinator; I started item 6, then
  the user said to rely on the coordinator again, so it's parked here. tools/link_aliases.py writes
  Source/Main/link_aliases.cpp: /alternatename pragmas that bind each reference named differently from its
  definition (type, ident, placeholder) to the definition at the address its declaration names, as Codex's
  linker binds by address. No game source edit; regenerated after each sync; an alias drops out when Codex
  fixes the declaration. On Codex 7442280: 3,054 aliases, unresolved 4,193 -> 1,139. Checked against Codex's
  own LINK_DEBT.json (linkdebt.py now runs here with the user's Game.exe and the 2005 CRT): 3,023 agree, 6 bind
  the same address through another symbol, 25 aren't in Codex's list. Codex linkdebt on 7442280: 21,648 refs,
  4,374 targets (one data cluster, 0x0096BC30-0x0096D66C, 231 globals, 1,384 refs). Question: take this
  approach for item 6, or wait for Codex lanes 11/12 to bring the debt down first?

- 2026-11-27 17:00 PT, fixes for the Codex lanes from the compile report (docs/PORT_COMPILE.md, PR #5). All 538
  files compile with v143; these are the warnings where behaviour can depend on the compiler:
  - **D2Client:** UNIT/MonUnique.cpp `MONUNIQUE_ApplyResistantMod` can end without a return value (C4715): write
    the return 1.14d's code gives on that path. UI/inv.cpp defines its own `va_start` (C4005): drop it, use
    <stdarg.h>'s. SKILLS/Skills.cpp:1121 narrows int to unsigned int in a brace initialiser (C4838).
    UNIT/UnitSnd.cpp:209, 211 `extern` on a struct definition with no variable (C4091).
  - **D2Common:** DATATBLS/MonsterTbls.cpp:688 redefines `D2_ASSERT` (C4005): one definition, in one header.
  - **D2Direct3D:** Src/d3dSprite.cpp `D3DSPRITE_DrawSpriteQuad` can end without a return value (C4715).
    Src/d3dFloorCache.cpp:41 redefines `RELEASE` (C4005).
  - **D2Game:** GAME/SCmd.cpp `D2GAME_PACKETS_SendPacket0xAE` ends without a return after the failed size
    assertion (C4715). MONSTER/MonsterUnique.cpp `MONSTERUNIQUE_UMod8_Resistant` likewise (C4715).
    `D2_MIN`/`D2_MAX` redefined in SKILLS/SkillAss.cpp:342-344 and SKILLS/Skills.cpp:441-443,
    `EVENTTYPE_REMOVESTATE` in SKILLS/Skills.cpp:437, `UNITFLAG_TARGETABLE` in OBJECTS/ObjMode.cpp:464,
    `EVENTTYPE_STATREGEN` in PLAYER/Player.cpp:577 (C4005): one definition each. Quests/a1q4.cpp:1253 a type
    qualifier twice (C4114). GAME/Game.cpp:2075 `sprintf("~%d", szGameName, 0)` prints an address: very likely
    1.14d's own code, keep it, just don't "fix" it.
  - **D2Win:** Src/D2WinFont.cpp:137-139 redefines `D2_MAX`/`D2_MIN` (C4005).
  - **Fog:** Unknown_00401DF0.cpp:321, 324, 362 `%p` given an unsigned long (C4477): same output on x86, only
    matters for 64-bit (M7).
  - **Storm:** SOURCE/SCOMP.CPP and SOURCE/SFILE.CPP call the PKWARE routines by placeholders
    (`sub_006B01B0_Explode`, `sub_006B0870_Implode`) with two different declarations: their names are
    `explode` and `implode` (PKWARE DCL's API), one declaration in a header. The engine answers to both names
    meanwhile (Source/Storm/pklib/codex_names.cpp).
- 2026-11-27 17:00 PT, question for the user (item 2, parked; answered 17:30, see Status): the PKWARE test
  against data the original library compressed needs the user's own MPQs. Could the user attach one or two (d2speech.mpq is small; any
  of d2data/d2exp/d2char will do), or run `pklib_test.exe d2data.mpq d2exp.mpq` from the build in their
  Diablo II folder and paste the output? Nothing from them goes into the repo.

- 2026-11-27, question for the user (answered 17:30, see Status): I need the user's 1.14d Game.exe in the
  sandbox for Codex's tools (linkdebt.py for item 3, shortdata.py for item 4) and to check 16 data bytes.
  My request for access to ~/Iblis-Codex and ~/Desktop/Diablo 2 archives on the PC was declined by the
  app's approval check, not by the user. Could the user attach Game.exe to the chat, or approve folder
  access to the folder that holds it? Nothing from it goes into the repo.
- 2026-11-27, item 0: 16 bytes of Codex main's data plan were in no record of the f835c02 plan, so the
  engine's data didn't have them; written as 0 in PR #1, to check against Game.exe:
  gaQuestTable[0] bytes 0-7 (0x00723F30) and gatControlTemplates[282], [284] .nFlags (0x0070C204,
  0x0070C264). In Codex main's plan, 35 files list an `include` that isn't the file's own
  (e.g. BnDownload.cpp lists BnDownload_00520B30.inc but includes BnDownload.inc) - stale plan
  entries after the file merges, worth a fix in Codex.

## Status

- 2026-11-27 19:30 PT: 6d continued in PR #9 (new commit): the oracle's level 1 (Game.exe's own C runtime
  started by its entry point, the case taking over at WinMain), cases bitbuf (BITMANIP_*, the .d2s checksum)
  and startup; rng, bitbuf, startup all identical against the user's 1.14d. Open: #8, #9, #10, #11. Next:
  REPLAY level 2 (Storm + MPQs, D2Lang, data tables) toward drlg, and 6b when Codex moves.

- 2026-11-27 19:45 PT: board check. No new answers. Codex main moved to 0bf13c4 (#494): 6b in PR #11 (stacked
  on #10), clean, data checked against Game.exe again (1,693/1,693). 538/538 compile; link 4,140 unresolved
  (-58). Open: #8, #9, #10, #11.

- 2026-11-27 19:00 PT: board check. Codex main moved to 19eef12 (#493): 6b in PR #10, clean, and checked
  against Game.exe this time: all 1,693 records Codex renders from the user's Game.exe are identical in the
  engine's copy. 538/538 compile, same warnings; link 4,198 unresolved (pool retyping part way, posted for
  lane 12). Open: #8, #9, #10.

- 2026-11-27 18:45 PT: 6d in PR #9: docs/REPLAY.md (design: two runners, the oracle maps the player's stock
  Game.exe in-process and calls 1.14d at its addresses; cases rng -> C runtime/Fog -> tables -> drlg -> drops
  and save) and tools/replay/ with the first case: rng, 2,169 lines identical between stock 1.14d and the
  engine (MSVC 19.44 under wine, the user's install). Open: #8 (PORT_LINK.md at 7442280), #9. Item 6
  proposal parked under Findings. Next unless told otherwise: 6b when Codex main moves; REPLAY level 1
  (Game.exe's C runtime init in the oracle) toward the drlg case.

- 2026-11-27 18:20 PT: 6b follow-up in PR #8 (PORT_LINK.md at 7442280; duplicates now told apart by symbol
  type: 84 duplicate globals, as Codex finds, and 324 duplicate functions). 6c posted under Findings (by lane,
  plus the 172 no_address symbols by file). Starting 6d (docs/REPLAY.md, tools/replay/).

- 2026-11-27 18:00 PT: waiting on the coordinator. Open: #6 (link report + PKWARE MPQ test), #7 (sync to
  7442280). Item 6 proposal above. Codex's linkdebt.py and build now run in this sandbox (MSVC 2005 SP1 + CRT
  fetched by setup.py), so lane 14 can produce LINK_DEBT.json or shortdata.py output on request.

- 2026-11-27 17:50 PT: 6a done (see the 17:30 line). 6b: PR #7 syncs to Codex 7442280 (#492), clean (every
  old record re-renders, no missing bytes). Still 538/538 compile, same 59 warnings; the link has 4,193
  unresolved (was 4,274), 7,345 references (was 7,444), interior 46 -> 9. #6 (link report, carrying the
  PKWARE MPQ-test commit) is still open; I'll refresh PORT_LINK.md after it's in. Next: wait for the next
  Codex round or the coordinator's go on items 6-8.

- 2026-11-27 17:30 PT: the user gave access to their install (D:\Diablo II); Game.exe is the 1.14d one
  (SHA-256 631066c1..., as Codex expects). The three parked checks are done:
  - The 16 bytes PR #2 wrote as 0 are 0 in Game.exe. No change.
  - PKWARE (PR #3, commit 5702c76): on d2data.mpq and Patch_D2.mpq, 8,497 files the original library
    compressed (330 MB) explode to their exact sector sizes; the 1,339 the encrypted (listfile) names in a
    checkable format (data tables, string tables, DC6) are well-formed; all pass with MSVC 19.44 and g++. The
    archives carry no (attributes) CRCs. The stack (#4-#6) was merged forward to carry it.
  - DLL imports (PR #5): binkw32/SmackW32 export decorated names (_BinkOpen@8), ijl11 undecorated; the stub
    import libraries record exactly these.
  Game.exe is now in the sandbox for Codex's tools (linkdebt.py, shortdata.py) when items 6-7 come up.

- 2026-11-27 17:35 PT: queue items 1-5 all in PRs, merge in order #2, #3, #4, #5, #6 (#1 superseded by #2).
  #6 = item 5, docs/PORT_LINK.md: the modern link fails with 4,274 unresolved symbols (the linker's count) and
  407 duplicates, 7,444 references once per symbol and file; by linkdebt category: type 2,593, placeholder
  1,799, unsourced data 1,282, local copies 709, ident 346, duplicate data 315, no address 235, renamed 117,
  interior 46, CRT 2, import 0. tools/link_report.py remeasures after each sync. Parked: the 16 data bytes
  (Game.exe), the PKWARE run on the user's MPQs, and the Bink/Smacker/IJL export names (Game.exe or the DLLs).
  Nothing claimed; waiting for the coordinator's next items or a sync.

- 2026-11-27 17:00 PT: on the new queue. PR #2 replaces #1 (same tree, made by tools/codex_sync.py, which now
  drops the `// build:` markers itself: item 4; #1 can be closed unmerged). PR #3 pklib (item 2; the MPQ run is
  parked for the user's archives), PR #4 resources (item 3), PR #5 CMake + docs/PORT_COMPILE.md (item 1: all 538
  files compile; findings above). The stack merges in order #2, #3, #4, #5. Starting item 5, the link report.
  (Correction: my 17:40 status line below was 16:40 PT.)

- 2026-11-27 17:40 PT: item 0 done, PR #1 (Source/ = Codex main 09eccff; data carried over exactly without
  Game.exe, by inverting gendata's rendering, checked by re-rendering all 2,481 old records). Toolchain in the
  sandbox: msvc-wine, MSVC 14.44.35207, cl 19.44.35230 for x86, link 14.44.35230.0, SDK 10.0.26100.0, under
  wine 11.0 (Ubuntu's wine 9.0 crashes on this kernel). Starting item 2.
