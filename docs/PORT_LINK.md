# Linking with a current linker

What keeps the engine from linking as an ordinary program: every unresolved and duplicate symbol of the link with
the modern linker, sorted the way Iblis Codex's `tools/linkdebt.py` sorts its link debt. A measurement: nothing in
the game source is fixed here. The Codex lanes fix the source in Codex (lanes 11 and 12 on link debt), and the
fixes come back with the next sync. Remeasure after each sync:

    ninja -C build -k 0 2> link.log                       # or the Visual Studio build's output
    python tools/link_report.py build link.log ../Iblis-Codex --md links.md

Last measured: 2026-11-28, Source/ at Codex 4136fc4 (#509) (tools/CODEX_SYNC), `link` 14.44.35230.0, the CMake build of
docs/PORT_COMPILE.md (every object of the 22 module libraries and the program, `/WHOLEARCHIVE`).

## Result

The link of Game.exe fails with **914 unresolved symbols** (LNK2001/LNK2019) and **400 symbols defined more than once** (LNK2005).
Counted as references, one per symbol and file that asks for it: **2340**.

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

At Codex 4136fc4: **2729 aliases** (1124 of them address-only), unresolved symbols with them **914** (1222 at 16572ad). Checked against
Codex's own `LINK_DEBT.json` (linkdebt.py with the user's Game.exe): 2803 agree; 3 bind the same address through the
one external definition where Codex names it differently (`gpHoverItem`, `gbGoldButtonDisabled`); 25 aren't in Codex's
list (references in code Codex's ordinary link leaves out, or tables the engine holds as source) and were checked by
hand: each binds to the definition carrying the declared address.

Not aliased because the reference and the definition disagree on the calling interface (a real ABI disagreement, a
crash risk, for Codex lane 12): **116**, by kind: calling convention 56, return eax 34, argument bytes 26. They are listed on the lane 14 board.

## Totals

| Category | References | Symbols |
|---|---:|---:|
| import | 0 | 0 |
| runtime_library | 2 | 1 |
| type_disagreement | 92 | 80 |
| different_identifier | 187 | 84 |
| placeholder | 231 | 140 |
| renamed_definition | 100 | 61 |
| interior | 6 | 6 |
| unsourced_data | 509 | 399 |
| no_address | 209 | 149 |
| duplicate_data | 185 | 83 |
| local_copy | 819 | 317 |
| **total** | 2340 | 1314 |

## By module (references)

| Module | import | crt | type | ident | plchld | renamed | inter | unsrc | noaddr | dup | copy | total |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| D2Client | 0 | 0 | 19 | 29 | 87 | 46 | 0 | 129 | 119 | 52 | 457 | 938 |
| D2Game | 0 | 2 | 25 | 132 | 44 | 21 | 0 | 24 | 3 | 49 | 76 | 376 |
| D2Common | 0 | 0 | 5 | 6 | 14 | 4 | 0 | 105 | 7 | 8 | 88 | 237 |
| Fog | 0 | 0 | 1 | 0 | 5 | 10 | 0 | 55 | 5 | 32 | 57 | 165 |
| D2CMP | 0 | 0 | 2 | 3 | 4 | 3 | 0 | 31 | 6 | 0 | 39 | 88 |
| Storm | 0 | 0 | 3 | 0 | 26 | 5 | 0 | 14 | 3 | 4 | 33 | 88 |
| D2Launch | 0 | 0 | 7 | 3 | 12 | 6 | 4 | 21 | 7 | 4 | 8 | 72 |
| D2Direct3D | 0 | 0 | 5 | 7 | 2 | 0 | 0 | 55 | 1 | 0 | 0 | 70 |
| D2Hell | 0 | 0 | 0 | 1 | 4 | 0 | 0 | 3 | 47 | 0 | 9 | 64 |
| D2Multi | 0 | 0 | 3 | 0 | 7 | 1 | 2 | 21 | 1 | 18 | 4 | 57 |
| D2Win | 0 | 0 | 7 | 1 | 17 | 2 | 0 | 14 | 0 | 2 | 4 | 47 |
| D2Glide | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 7 | 9 | 6 | 6 | 29 |
| D2BNClient | 0 | 0 | 4 | 4 | 6 | 0 | 0 | 9 | 1 | 0 | 4 | 28 |
| D2Sound | 0 | 0 | 0 | 0 | 2 | 2 | 0 | 3 | 0 | 2 | 14 | 23 |
| Bnclient | 0 | 0 | 8 | 0 | 0 | 0 | 0 | 2 | 0 | 0 | 10 | 20 |
| D2MCPClient | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 11 | 0 | 2 | 0 | 13 |
| D2Lang | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 6 | 7 |
| Main | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 4 | 0 | 6 |
| D2Gfx | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 3 | 0 | 0 | 0 | 4 |
| D2DDraw | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 2 | 4 |
| D2Net | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 2 |
| SRP | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| D2Gdi | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

## Examples, per category

**runtime_library** (1 symbols)

- `exit` at 0x00681E09, in Source/D2Game/UNIT/SUnitDmg.cpp
- `exit` at 0x00681E09, in Source/D2Game/Ai/AiThink.cpp

**type_disagreement** (80 symbols)

- `ACT2Q1_OnRadamentCreated` at 0x005991B0 -> `ACT2Q1_OnRadamentCreated`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT2Q5_OnSummonerCreated` at 0x0059C3B0 -> `ACT2Q5_OnSummonerCreated`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT3Q4_UnitIterate_UpdateCurrentQuestState` at 0x005BA290 -> `ACT3Q4_UnitIterate_UpdateCurrentQuestState`, in Source/D2Game/Quests/a3q4.cpp
- `ACT3Q6_SetObjectModes` at 0x005BCFD0 -> `ACT3Q6_SetObjectModes`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT5Q3_RemoveNihlathakFromTown` at 0x00589540 -> `ACT5Q3_RemoveNihlathakFromTown`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT5Q4_OnNihlathakActivated` at 0x0058BC40 -> `ACT5Q4_OnNihlathakActivated`, in Source/D2Game/Ai/AiThink4.cpp
- `ANIMIMAGE_Destroy` at 0x00500300 -> `ANIMIMAGE_Destroy`, in Source/D2Win/Src/D2WinMain.cpp
- `BNDOWNLOAD_DecodeCDKey` at 0x00522AE0 -> `BNDOWNLOAD_DecodeCDKey`, in Source/D2BNClient/BnSend.cpp

**different_identifier** (84 symbols)

- `UnicodeChar::UnicodeChar` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Lang/Unknown_00527090.cpp
- `UnicodeChar::UnicodeChar` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Win/Src/D2WinEditBox.cpp
- `D2Object00610D30Strc::~D2Object00610D30Strc` at 0x00610AA0 -> `D2CommonIgnoreListStrc::~IgnoreList`, in Source/D2Common/Chat/Ignorelist.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/Unknown_005D1080.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/SKILLS/SkillSor.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/SKILLS/SkillItem.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `__declspec`, in Source/D2Game/Ai/AiThink4.cpp
- `AIGENERAL_GetCurrentAiCommandFromUnit` at 0x0058EE80 -> `__declspec`, in Source/D2Game/Unknown_005EFB80.cpp

**placeholder** (140 symbols)

- `WardenModule::~WardenModule` at 0x004E06A0 -> `sub_004E06A0_FreeModules`, in Source/D2Client/WARDEN/WardenClient.cpp
- `WardenModule::~WardenModule` at 0x004E06A0 -> `sub_004E06A0_FreeModules`, in Source/D2Client/Unknown_004DF1C0.cpp
- `D2COMMON_10254_Return0` at 0x0063BE30 -> `sub_0063BE30_Return`, in Source/D2Game/ITEMS/ItemMode.cpp
- `FOG_SOCKET_WSACleanup` at 0x0040D8D0 -> `sub_0040D8D0`, in Source/Fog/Src/ErrorManager.cpp
- `distfix` at 0x006D0B00 -> `distfix_006D0B00`, in Source/Storm/zlib/inflate.c
- `gCharacterClass` at 0x0074C5C8 -> `gCharacterClass_0074C5C8`, in Source/D2Hell/Unknown_006C9A38.cpp
- `gDSPROPSETID_EAX20_ListenerProperties_006DE460` at 0x006DE460 -> `gtEaxListener20PropertySet`, in Source/D2Sound/Unknown_00513BC0.cpp
- `gDSPROPSETID_EAX_ReverbProperties_006DE480` at 0x006DE480 -> `gtEaxListener10PropertySet`, in Source/D2Sound/Unknown_00513BC0.cpp

**renamed_definition** (61 symbols)

- `BigAdd` at 0x00422300 -> `BigAdd`, in Source/Storm/SOURCE/SBig_00425350.cpp
- `EDITBOX_UpdateVisibleChars` at 0x004FE7C0 -> `EDITBOX_UpdateVisibleChars`, in Source/D2Win/Src/D2WinEditBox.cpp
- `ERRORMANAGER_FindCodeView` at 0x00404900 -> `ERRORMANAGER_FindCodeView`, in Source/Fog/Unknown_00404AB0.cpp
- `ERRORMANAGER_GetDebugDirectory` at 0x004047D0 -> `ERRORMANAGER_GetDebugDirectory`, in Source/Fog/Unknown_00404AB0.cpp
- `ERRORMANAGER_GetImageKind` at 0x00404730 -> `ERRORMANAGER_GetImageKind`, in Source/Fog/Unknown_00404AB0.cpp
- `ERRORMANAGER_IsDosHeaderValid` at 0x00404760 -> `ERRORMANAGER_IsDosHeaderValid`, in Source/Fog/Unknown_00404AB0.cpp
- `ERRORMANAGER_ReadNb10` at 0x00404F80 -> `ERRORMANAGER_ReadNb10`, in Source/Fog/Unknown_004049A0.cpp
- `ERRORMANAGER_ReadNb10` at 0x00404F80 -> `ERRORMANAGER_ReadNb10`, in Source/Fog/Unknown_004047D0.cpp

**interior** (6 symbols)

- `gdwBitMask5` at 0x006CE27C -> `gdwBitMasks+0x14`, in Source/D2Launch/Src/CharSel.cpp
- `gdwBitMask7` at 0x006CE284 -> `gdwBitMasks+0x1C`, in Source/D2Multi/Src/ComCallback.cpp
- `gdwTitleMaskA` at 0x006CE280 -> `gdwBitMasks+0x18`, in Source/D2Multi/Src/ComCallback.cpp
- `gnFlagClear0` at 0x006CE2F8 -> `gdwInvBitMasks+0x10`, in Source/D2Launch/Src/CharSel.cpp
- `gnFlagClear1` at 0x006CE2FC -> `gdwInvBitMasks+0x14`, in Source/D2Launch/Src/CharSel.cpp
- `gnFlagSet0_006CE278` at 0x006CE278 -> `gdwBitMasks+0x10`, in Source/D2Launch/Src/CharSel.cpp

**unsourced_data** (399 symbols)

- `gAvailableMemory` at 0x0096F4D0, in Source/D2Direct3D/Src/d3dCore.cpp
- `gBufferCopies` at 0x00970E80, in Source/D2Direct3D/Src/d3dCore.cpp
- `gCmpPool` at 0x0088CAE0, in Source/D2CMP/SRC/SpriteCache.cpp
- `gCmpPool` at 0x0088CAE0, in Source/D2CMP/SRC/CelCmp.cpp
- `gCmpTilePool` at 0x0088DB20, in Source/D2CMP/SRC/SpriteCache.cpp
- `gCmpTilePool` at 0x0088DB20, in Source/D2CMP/SRC/CelCmp.cpp
- `gIndexStrips` at 0x009716B0, in Source/D2Direct3D/Unknown_006B7530.cpp
- `gLargeBudget` at 0x007C90E0, in Source/D2Direct3D/Src/d3dCore.cpp

**no_address** (149 symbols)

- `ListBoxWrapper::ListBoxWrapper`, in Source/D2Client/UI/text.cpp
- `ListBoxWrapper::ListBoxWrapper`, in Source/D2Client/UI/npcmenu_004B5C60.cpp
- `UnicodeChar::UnicodeChar`, in Source/D2Launch/Unknown_0043B7A0.cpp
- `UnicodeChar::UnicodeChar`, in Source/D2Multi/Src/ChatDlg.cpp
- `D2SGameDataStrc::~D2SGameDataStrc`, in Source/D2CMP/SRC/CelCmp.cpp
- `D2StormGameArrayStrc::~D2StormGameArrayStrc`, in Source/D2CMP/SRC/CelCmp.cpp
- `WardenModule::~WardenModule`, in Source/D2CMP/SRC/CelCmp.cpp
- `WardenModule::~WardenModule`, in Source/D2Client/GAME/Game.cpp

**duplicate_data** (83 symbols)

- `gpfnMcpMotdCallback`, in Source/D2Client/CORE/WINMAIN.CPP, Source/D2Client/Unknown_0044B400.cpp, Source/D2Client/Unknown_0044BA20.cpp, Source/D2M
- `gGameListLock`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gaStateStack`, in Source/D2Client/CORE/WINMAIN.CPP, Source/D2Client/GAME/Game.cpp, Source/D2Client/GAME/Game_0044B7B0.cpp
- `gbQuestDebug`, in Source/D2Game/MONSTER/MonsterRegion.cpp, Source/D2Game/OBJECTS/objrgn.cpp, Source/D2Game/Quests/QUESTS.CPP
- `gdwGlobal_00882D14`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gdwLastClientsUpdateTick`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gdwPlayerPos`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp
- `gnAct`, in Source/D2Game/GAME/Clients.cpp, Source/D2Game/GAME/Game.cpp, Source/D2Game/OBJECTS/objrgn.cpp

**local_copy** (317 symbols)

- `ACT3Q7_StatusFilterCallback`, in Source/D2Game/Quests/a2q0.cpp, Source/D2Game/Quests/a2q7.cpp, Source/D2Game/Quests/a2q8.cpp, Source/D2Game/Quests/a3q0.c
- `sub_M106_Emit_0051DC70`, in Source/Bnclient/Unknown_00520DC0.cpp, Source/Bnclient/Unknown_00527BE0.cpp, Source/D2BNClient/BnDownload.cpp, Source/D2B
- `ACT3Q5_Callback10_PlayerLeavesGame`, in Source/D2Game/Quests/a2q1.cpp, Source/D2Game/Quests/a2q2.cpp, Source/D2Game/Quests/a2q4.cpp, Source/D2Game/Quests/a2q5.c
- `ERRORMANAGER_UnlockSymbols`, in Source/Fog/Unknown_00401010.cpp, Source/Fog/Unknown_00401DF0.cpp, Source/Fog/Unknown_00402280.cpp, Source/Fog/Unknown_00
- `D2ChatStormListCStrc::D2ChatStormListCStrc`, in Source/D2Client/GAME/Game.cpp, Source/D2Common/Chat/Ignorelist.cpp, Source/Storm/SOURCE/SERR.CPP, Source/Storm/SOURCE/SE
- `D2Storm4167B0Strc::~D2Storm4167B0Strc`, in Source/D2CMP/SRC/CelCmp.cpp, Source/D2Client/GAME/Game.cpp, Source/D2Common/DRLG/Preset.cpp, Source/D2Game/GAME/Game.cpp
- `D2Storm4168F0Strc::~D2Storm4168F0Strc`, in Source/D2CMP/SRC/CelCmp.cpp, Source/D2Client/GAME/Game.cpp, Source/D2Common/DRLG/Preset.cpp, Source/D2Game/GAME/Game.cpp
- `DRLGPRESET_GetLinkRawNext`, in Source/D2Client/GAME/Game.cpp, Source/D2Common/DRLG/Preset.cpp, Source/D2Common/Unknown_00650D70.cpp, Source/D2Game/GAME

