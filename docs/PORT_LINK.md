# Linking with a current linker

What keeps the engine from linking as an ordinary program: every unresolved and duplicate symbol of the link with
the modern linker, sorted the way Iblis Codex's `tools/linkdebt.py` sorts its link debt. A measurement: nothing in
the game source is fixed here. The Codex lanes fix the source in Codex (lanes 11 and 12 on link debt), and the
fixes come back with the next sync. Remeasure after each sync:

    ninja -C build -k 0 2> link.log                       # or the Visual Studio build's output
    python tools/link_report.py build link.log ../Iblis-Codex --md links.md

Last measured: 2026-11-27, Source/ at Codex 3f6ca97 (#498) (tools/CODEX_SYNC), `link` 14.44.35230.0, the CMake build of
docs/PORT_COMPILE.md (every object of the 22 module libraries and the program, `/WHOLEARCHIVE`).

## Result

The link of Game.exe fails with **1224 unresolved symbols** (LNK2001/LNK2019) and **408 symbols defined more than once** (LNK2005).
Counted as references, one per symbol and file that asks for it: **3062**.

Codex's count (21,648 references on Codex #492) counts every place in the code that uses a symbol; this report
counts each symbol once per file. The categories are the same, with three differences:

- Codex's `data_cluster` (runs of globals the code treats as one object) needs Game.exe to see; those references
  appear here as `interior`, `placeholder` or `type_disagreement`.
- `pkware` is gone: the engine has its own PKWARE routines (Source/Storm/pklib).
- `no_address` is this report's own: a reference whose declaration carries no `// 0x` address, so where it should
  bind can't be told from the source.

How a reference is placed: the declaration the file sees (in the file or a header it includes) gives the address it
means; Codex's `build/functions.json` and data plan, and the source's own address markers, give the definition
there. `renamed_definition` means the definition exists under that name but no object exports it (static or
inline); `import` is empty because the Bink, Smacker and IJL imports link against the engine's import libraries
(PR #5), and the Windows SDK and C runtime cover the rest, with `legacy_stdio_definitions`.

## Link aliases (Source/Main/link_aliases.cpp)

Before measuring, the build links `Source/Main/link_aliases.cpp`, which `tools/link_aliases.py` regenerates after each
sync. It binds each reference whose name differs from its definition's (type, ident, placeholder) to the definition at
the address the reference's declaration names, as Codex's linker binds by address. It aliases only where the two agree
on calling convention, argument bytes and return register (`tools/abi.py`); a reference used only from data (a table
of function pointers) is bound for its address alone. No game source is changed, and an alias drops out when Codex
fixes the declaration.

At Codex 3f6ca97: **2807 aliases** (1132 of them address-only), unresolved symbols **4,031 → 1224**. Checked against
Codex's own `LINK_DEBT.json` (linkdebt.py with the user's Game.exe): 2803 agree; 3 bind the same address through the
one external definition where Codex names it differently (`gpHoverItem`, `gbGoldButtonDisabled`); 25 aren't in Codex's
list (references in code Codex's ordinary link leaves out, or tables the engine holds as source) and were checked by
hand: each binds to the definition carrying the declared address.

Not aliased because the reference and the definition disagree on the calling interface (a real ABI disagreement, a
crash risk, for Codex lane 12): **151**, by kind: calling convention 76, return eax 39, argument bytes 36. They are listed on the lane 14 board.

## Totals

| Category | References | Symbols |
|---|---:|---:|
| import | 0 | 0 |
| runtime_library | 2 | 1 |
| type_disagreement | 140 | 115 |
| different_identifier | 196 | 90 |
| placeholder | 232 | 141 |
| renamed_definition | 97 | 60 |
| interior | 6 | 6 |
| unsourced_data | 1146 | 662 |
| no_address | 217 | 157 |
| duplicate_data | 187 | 84 |
| local_copy | 839 | 324 |
| **total** | 3062 | 1632 |

## By module (references)

| Module | import | crt | type | ident | plchld | renamed | inter | unsrc | noaddr | dup | copy | total |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| D2Client | 0 | 0 | 32 | 29 | 87 | 45 | 0 | 281 | 122 | 54 | 459 | 1109 |
| D2Game | 0 | 2 | 51 | 141 | 45 | 20 | 0 | 123 | 6 | 49 | 101 | 538 |
| D2Common | 0 | 0 | 8 | 6 | 14 | 4 | 0 | 263 | 9 | 8 | 88 | 400 |
| Fog | 0 | 0 | 2 | 0 | 5 | 9 | 0 | 89 | 5 | 32 | 55 | 197 |
| D2CMP | 0 | 0 | 3 | 3 | 4 | 3 | 0 | 46 | 6 | 0 | 39 | 104 |
| Storm | 0 | 0 | 4 | 0 | 26 | 5 | 0 | 27 | 3 | 4 | 33 | 102 |
| D2Direct3D | 0 | 0 | 6 | 7 | 2 | 0 | 0 | 83 | 1 | 0 | 0 | 99 |
| D2Win | 0 | 0 | 7 | 1 | 17 | 2 | 0 | 64 | 0 | 2 | 4 | 97 |
| D2Launch | 0 | 0 | 8 | 3 | 12 | 6 | 4 | 28 | 7 | 4 | 8 | 80 |
| D2Multi | 0 | 0 | 3 | 0 | 7 | 1 | 2 | 35 | 1 | 18 | 4 | 71 |
| D2Hell | 0 | 0 | 0 | 1 | 4 | 0 | 0 | 6 | 47 | 0 | 9 | 67 |
| D2BNClient | 0 | 0 | 4 | 4 | 6 | 0 | 0 | 33 | 1 | 0 | 4 | 52 |
| D2Glide | 0 | 0 | 1 | 0 | 1 | 0 | 0 | 19 | 9 | 6 | 6 | 42 |
| D2Sound | 0 | 0 | 0 | 0 | 2 | 2 | 0 | 7 | 0 | 2 | 8 | 21 |
| Bnclient | 0 | 0 | 8 | 0 | 0 | 0 | 0 | 2 | 0 | 0 | 11 | 21 |
| D2MCPClient | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 13 | 0 | 2 | 0 | 15 |
| D2Lang | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 7 | 0 | 0 | 6 | 14 |
| Main | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 7 | 0 | 4 | 0 | 11 |
| D2DDraw | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | 2 | 2 | 8 |
| D2Gfx | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 4 | 0 | 0 | 0 | 5 |
| D2Net | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 0 | 2 | 4 |
| D2Gdi | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 3 | 0 | 0 | 0 | 4 |
| SRP | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

## Examples, per category

**runtime_library** (1 symbols)

- `exit` at 0x00681E09, in Source/D2Game/UNIT/SUnitDmg.cpp
- `exit` at 0x00681E09, in Source/D2Game/Ai/AiThink.cpp

**type_disagreement** (115 symbols)

- `ACT1Q6_EmptyCallback` at 0x00596BA0 -> `ACT1Q6_EmptyCallback`, in Source/D2Game/Unknown_00596BB0.cpp
- `ACT1Q7_Callback00_NpcActivate` at 0x00596A90 -> `ACT1Q7_Callback00_NpcActivate`, in Source/D2Game/Unknown_00596BB0.cpp
- `ACT2Q1_OnRadamentCreated` at 0x005991B0 -> `ACT2Q1_OnRadamentCreated`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT2Q4_OnJerhynSpawned` at 0x0059B6C0 -> `ACT2Q4_OnJerhynSpawned`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT2Q4_OnPalaceGuardSpawned` at 0x0059B6D0 -> `ACT2Q4_OnPalaceGuardSpawned`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT2Q5_OnSummonerActivated` at 0x0059C330 -> `ACT2Q5_OnSummonerActivated`, in Source/D2Game/Unknown_005EFB80.cpp
- `ACT2Q5_OnSummonerCreated` at 0x0059C3B0 -> `ACT2Q5_OnSummonerCreated`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT3Q4_UnitIterate_UpdateCurrentQuestState` at 0x005BA290 -> `ACT3Q4_UnitIterate_UpdateCurrentQuestState`, in Source/D2Game/Quests/a3q4.cpp

**different_identifier** (90 symbols)

- `UnicodeChar::UnicodeChar` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Lang/Unknown_00527090.cpp
- `UnicodeChar::UnicodeChar` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Win/Src/D2WinEditBox.cpp
- `D2Object00610D30Strc::~D2Object00610D30Strc` at 0x00610AA0 -> `D2CommonIgnoreListStrc::~IgnoreList`, in Source/D2Common/Chat/Ignorelist.cpp
- `ACT1Q1_CanClientFXBeTriggered` at 0x00590810 -> `__declspec`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT1Q1_GetMonstersToBeKilled` at 0x005901E0 -> `__declspec`, in Source/D2Game/Quests/QUESTS.CPP
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/Unknown_005D1080.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/SKILLS/SkillSor.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/SKILLS/SkillItem.cpp

**placeholder** (141 symbols)

- `WardenModule::~WardenModule` at 0x004E06A0 -> `sub_004E06A0_FreeModules`, in Source/D2Client/WARDEN/WardenClient.cpp
- `WardenModule::~WardenModule` at 0x004E06A0 -> `sub_004E06A0_FreeModules`, in Source/D2Client/Unknown_004DF1C0.cpp
- `D2COMMON_10254_Return0` at 0x0063BE30 -> `sub_0063BE30_Return`, in Source/D2Game/ITEMS/ItemMode.cpp
- `FOG_SOCKET_WSACleanup` at 0x0040D8D0 -> `sub_0040D8D0`, in Source/Fog/Src/ErrorManager.cpp
- `distfix` at 0x006D0B00 -> `distfix_006D0B00`, in Source/Storm/zlib/inflate.c
- `gCharacterClass` at 0x0074C5C8 -> `gCharacterClass_0074C5C8`, in Source/D2Hell/Unknown_006C9A38.cpp
- `gDSPROPSETID_EAX20_ListenerProperties_006DE460` at 0x006DE460 -> `gtEaxListener20PropertySet`, in Source/D2Sound/Unknown_00513BC0.cpp
- `gDSPROPSETID_EAX_ReverbProperties_006DE480` at 0x006DE480 -> `gtEaxListener10PropertySet`, in Source/D2Sound/Unknown_00513BC0.cpp

**renamed_definition** (60 symbols)

- `BigAdd` at 0x00422300 -> `BigAdd`, in Source/Storm/SOURCE/SBig_00425350.cpp
- `EDITBOX_UpdateVisibleChars` at 0x004FE7C0 -> `EDITBOX_UpdateVisibleChars`, in Source/D2Win/Src/D2WinEditBox.cpp
- `FindPrime` at 0x004255E0 -> `FindPrime`, in Source/Storm/SOURCE/SBig_00425350.cpp
- `GFX_BuildMonsterCofPath` at 0x0046F490 -> `GFX_BuildMonsterCofPath`, in Source/D2Client/ENGINE/Gfx_0046F870.cpp
- `GFX_LoadHashedEntry` at 0x0046DCC0 -> `GFX_LoadHashedEntry`, in Source/D2Client/ENGINE/Gfx_0046F870.cpp
- `GFX_RemoveStateOverlay` at 0x0046E040 -> `GFX_RemoveStateOverlay`, in Source/D2Client/UI/automap.cpp
- `MAINMENUS_IsListedCode` at 0x00432350 -> `MAINMENUS_IsListedCode`, in Source/D2Launch/Src/MainMenus.cpp
- `NPCMENU_ClearUnicode` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Client/UI/SkillDesc.cpp

**interior** (6 symbols)

- `gdwBitMask5` at 0x006CE27C -> `gdwBitMasks+0x14`, in Source/D2Launch/Src/CharSel.cpp
- `gdwBitMask7` at 0x006CE284 -> `gdwBitMasks+0x1C`, in Source/D2Multi/Src/ComCallback.cpp
- `gdwTitleMaskA` at 0x006CE280 -> `gdwBitMasks+0x18`, in Source/D2Multi/Src/ComCallback.cpp
- `gnFlagClear0` at 0x006CE2F8 -> `gdwInvBitMasks+0x10`, in Source/D2Launch/Src/CharSel.cpp
- `gnFlagClear1` at 0x006CE2FC -> `gdwInvBitMasks+0x14`, in Source/D2Launch/Src/CharSel.cpp
- `gnFlagSet0_006CE278` at 0x006CE278 -> `gdwBitMasks+0x10`, in Source/D2Launch/Src/CharSel.cpp

**unsourced_data** (662 symbols)

- `empty` at 0x006CC837, in Source/D2Client/UI/npcmenu.cpp
- `gAvailableMemory` at 0x0096F4D0, in Source/D2Direct3D/Src/d3dCore.cpp
- `gBufferCopies` at 0x00970E80, in Source/D2Direct3D/Src/d3dCore.cpp
- `gCmpPool` at 0x0088CAE0, in Source/D2CMP/SRC/SpriteCache.cpp
- `gCmpPool` at 0x0088CAE0, in Source/D2CMP/SRC/CelCmp.cpp
- `gCmpTilePool` at 0x0088DB20, in Source/D2CMP/SRC/SpriteCache.cpp
- `gCmpTilePool` at 0x0088DB20, in Source/D2CMP/SRC/CelCmp.cpp
- `gCoopError` at 0x006DE0A8, in Source/D2Direct3D/Src/d3dCore.cpp

**no_address** (157 symbols)

- `ListBoxWrapper::ListBoxWrapper`, in Source/D2Client/UI/text.cpp
- `ListBoxWrapper::ListBoxWrapper`, in Source/D2Client/UI/npcmenu_004B5C60.cpp
- `UnicodeChar::UnicodeChar`, in Source/D2Launch/Unknown_0043B7A0.cpp
- `UnicodeChar::UnicodeChar`, in Source/D2Multi/Src/ChatDlg.cpp
- `D2SGameDataStrc::~D2SGameDataStrc`, in Source/D2CMP/SRC/CelCmp.cpp
- `D2StormGameArrayStrc::~D2StormGameArrayStrc`, in Source/D2CMP/SRC/CelCmp.cpp
- `WardenModule::~WardenModule`, in Source/D2CMP/SRC/CelCmp.cpp
- `WardenModule::~WardenModule`, in Source/D2Client/GAME/Game.cpp

**duplicate_data** (84 symbols)

- `gpfnMcpMotdCallback`, in Source/D2Client/CORE/WINMAIN.CPP, Source/D2Client/Unknown_0044B400.cpp, Source/D2Client/Unknown_0044BA20.cpp, Source/D2M
- `gGameListLock`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gaStateStack`, in Source/D2Client/CORE/WINMAIN.CPP, Source/D2Client/GAME/Game.cpp, Source/D2Client/GAME/Game_0044B7B0.cpp
- `gbQuestDebug`, in Source/D2Game/MONSTER/MonsterRegion.cpp, Source/D2Game/OBJECTS/objrgn.cpp, Source/D2Game/Quests/QUESTS.CPP
- `gdwGlobal_00882D14`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gdwLastClientsUpdateTick`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gdwPlayerPos`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gnAct`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp

**local_copy** (324 symbols)

- `sub_M106_Emit_0051DC70`, in Source/Bnclient/Unknown_00520DC0.cpp, Source/Bnclient/Unknown_00527BE0.cpp, Source/D2BNClient/BnDownload.cpp, Source/D2B
- `ACT3Q7_StatusFilterCallback`, in Source/D2Game/Quests/a2q0.cpp, Source/D2Game/Quests/a2q7.cpp, Source/D2Game/Quests/a2q8.cpp, Source/D2Game/Quests/a3q0.c
- `ACT3Q5_Callback10_PlayerLeavesGame`, in Source/D2Game/Quests/a2q1.cpp, Source/D2Game/Quests/a2q2.cpp, Source/D2Game/Quests/a2q4.cpp, Source/D2Game/Quests/a2q5.c
- `sub_00401A60_UnlockSymbols`, in Source/Fog/Unknown_00401010.cpp, Source/Fog/Unknown_00401DF0.cpp, Source/Fog/Unknown_00402280.cpp, Source/Fog/Unknown_00
- `D2ChatStormListCStrc::D2ChatStormListCStrc`, in Source/D2Client/GAME/Game.cpp, Source/D2Common/Chat/Ignorelist.cpp, Source/Storm/SOURCE/SERR.CPP, Source/Storm/SOURCE/SE
- `D2Storm4167B0Strc::~D2Storm4167B0Strc`, in Source/D2CMP/SRC/CelCmp.cpp, Source/D2Client/GAME/Game.cpp, Source/D2Common/DRLG/Preset.cpp, Source/D2Game/GAME/Game.cpp
- `D2Storm4168F0Strc::~D2Storm4168F0Strc`, in Source/D2CMP/SRC/CelCmp.cpp, Source/D2Client/GAME/Game.cpp, Source/D2Common/DRLG/Preset.cpp, Source/D2Game/GAME/Game.cpp
- `DRLGPRESET_GetLinkRawNext`, in Source/D2Client/GAME/Game.cpp, Source/D2Common/DRLG/Preset.cpp, Source/D2Common/Unknown_00650D70.cpp, Source/D2Game/GAME

