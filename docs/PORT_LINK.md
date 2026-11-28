# Linking with a current linker

What keeps the engine from linking as an ordinary program: every unresolved and duplicate symbol of the link with
the modern linker, sorted the way Iblis Codex's `tools/linkdebt.py` sorts its link debt. A measurement: nothing in
the game source is fixed here. The Codex lanes fix the source in Codex (lanes 11 and 12 on link debt), and the
fixes come back with the next sync. Remeasure after each sync:

    ninja -C build -k 0 2> link.log                       # or the Visual Studio build's output
    python tools/link_report.py build link.log ../Iblis-Codex --md links.md

Last measured: 2026-11-27, Source/ at Codex 7442280 (#492) (tools/CODEX_SYNC), `link` 14.44.35230.0, the CMake build of
docs/PORT_COMPILE.md (every object of the 22 module libraries and the program, `/WHOLEARCHIVE`).

## Result

The link of Game.exe fails with **4193 unresolved symbols** (LNK2001/LNK2019) and **408 symbols defined more than once** (LNK2005).
Counted as references, one per symbol and file that asks for it: **7345**.

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

## Totals

| Category | References | Symbols |
|---|---:|---:|
| import | 0 | 0 |
| runtime_library | 2 | 1 |
| type_disagreement | 2557 | 1940 |
| different_identifier | 347 | 157 |
| placeholder | 1781 | 1087 |
| renamed_definition | 118 | 80 |
| interior | 9 | 9 |
| unsourced_data | 1270 | 768 |
| no_address | 235 | 172 |
| duplicate_data | 187 | 84 |
| local_copy | 839 | 324 |
| **total** | 7345 | 4601 |

## By module (references)

| Module | import | crt | type | ident | plchld | renamed | inter | unsrc | noaddr | dup | copy | total |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| D2Client | 0 | 0 | 763 | 70 | 634 | 57 | 2 | 387 | 132 | 54 | 459 | 2558 |
| D2Game | 0 | 2 | 1028 | 134 | 408 | 20 | 0 | 123 | 7 | 49 | 101 | 1872 |
| D2Common | 0 | 0 | 176 | 82 | 158 | 5 | 0 | 263 | 9 | 8 | 88 | 789 |
| D2Direct3D | 0 | 0 | 79 | 27 | 76 | 0 | 1 | 83 | 2 | 0 | 0 | 268 |
| D2Launch | 0 | 0 | 79 | 3 | 110 | 7 | 4 | 28 | 7 | 4 | 8 | 250 |
| Fog | 0 | 0 | 38 | 2 | 11 | 9 | 0 | 89 | 5 | 32 | 55 | 241 |
| D2Win | 0 | 0 | 63 | 9 | 63 | 2 | 0 | 65 | 0 | 2 | 4 | 208 |
| D2Multi | 0 | 0 | 31 | 1 | 109 | 1 | 2 | 35 | 1 | 18 | 4 | 202 |
| D2CMP | 0 | 0 | 62 | 10 | 11 | 3 | 0 | 46 | 11 | 0 | 39 | 182 |
| Storm | 0 | 0 | 28 | 2 | 45 | 10 | 0 | 27 | 3 | 4 | 33 | 152 |
| D2BNClient | 0 | 0 | 76 | 1 | 34 | 0 | 0 | 33 | 1 | 0 | 4 | 149 |
| D2Glide | 0 | 0 | 38 | 0 | 19 | 0 | 0 | 36 | 9 | 6 | 6 | 114 |
| D2Hell | 0 | 0 | 2 | 2 | 19 | 1 | 0 | 6 | 47 | 0 | 9 | 86 |
| D2Gdi | 0 | 0 | 22 | 0 | 34 | 0 | 0 | 3 | 0 | 0 | 0 | 59 |
| D2Sound | 0 | 0 | 13 | 3 | 11 | 2 | 0 | 7 | 0 | 2 | 8 | 46 |
| D2DDraw | 0 | 0 | 24 | 0 | 13 | 0 | 0 | 4 | 0 | 2 | 2 | 45 |
| D2MCPClient | 0 | 0 | 13 | 0 | 3 | 0 | 0 | 13 | 0 | 2 | 0 | 31 |
| Bnclient | 0 | 0 | 11 | 0 | 5 | 1 | 0 | 2 | 0 | 0 | 11 | 30 |
| D2Lang | 0 | 0 | 2 | 1 | 11 | 0 | 0 | 7 | 1 | 0 | 6 | 28 |
| Main | 0 | 0 | 7 | 0 | 2 | 0 | 0 | 7 | 0 | 4 | 0 | 20 |
| D2Gfx | 0 | 0 | 1 | 0 | 5 | 0 | 0 | 4 | 0 | 0 | 0 | 10 |
| D2Net | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 0 | 2 | 4 |
| SRP | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

## Examples, per category

**runtime_library** (1 symbols)

- `exit` at 0x00681E09, in Source/D2Game/UNIT/SUnitDmg.cpp
- `exit` at 0x00681E09, in Source/D2Game/Ai/AiThink.cpp

**type_disagreement** (1940 symbols)

- `ACCOUNTLIST_Create` at 0x00507CA0 -> `ACCOUNTLIST_Create`, in Source/D2Win/Src/D2WinMain.cpp
- `ACCOUNTLIST_Destroy` at 0x00507AF0 -> `ACCOUNTLIST_Destroy`, in Source/D2Win/Src/D2WinMain.cpp
- `ACT1Q1_GetMonstersToBeKilled` at 0x005901E0 -> `ACT1Q1_GetMonstersToBeKilled`, in Source/D2Game/Quests/QUESTS.CPP
- `ACT1Q2_UnitIterate_UpdateQuestStateFlags` at 0x00590890 -> `ACT1Q2_UnitIterate_UpdateQuestStateFlags`, in Source/D2Game/Quests/a1q2.cpp
- `ACT1Q4_OpenPortalToTristram` at 0x00592D50 -> `ACT1Q4_OpenPortalToTristram`, in Source/D2Game/Quests/a1q4.cpp
- `ACT1Q4_UnitIterate_UpdateQuestStateFlags` at 0x00592130 -> `ACT1Q4_UnitIterate_UpdateQuestStateFlags`, in Source/D2Game/Quests/a1q4.cpp
- `ACT1Q6_EmptyCallback` at 0x00596BA0 -> `ACT1Q6_EmptyCallback`, in Source/D2Game/Unknown_00596BB0.cpp
- `ACT1Q7_Callback00_NpcActivate` at 0x00596A90 -> `ACT1Q7_Callback00_NpcActivate`, in Source/D2Game/Unknown_00596BB0.cpp

**different_identifier** (157 symbols)

- `D2UiControlAStrc::D2UiControlAStrc` at 0x004BC480 -> `SpinnerWrapper::SpinnerWrapper`, in Source/D2Client/UI/ui.cpp
- `D2UiControlBStrc::D2UiControlBStrc` at 0x004BBD80 -> `EditBoxWrapper::EditBoxWrapper`, in Source/D2Client/UI/ui.cpp
- `D2UiControlCStrc::D2UiControlCStrc` at 0x004BB0F0 -> `ButtonWrapper::ButtonWrapper`, in Source/D2Client/UI/ui.cpp
- `THuffmannTree::THuffmannTree` at 0x0041F4A0 -> `CHuffman::CHuffman`, in Source/Storm/Unknown_0041F6A0.cpp
- `UnicodeChar::UnicodeChar` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Lang/Unknown_00527090.cpp
- `UnicodeChar::UnicodeChar` at 0x0042F530 -> `NPCMENU_ClearUnicode`, in Source/D2Win/Src/D2WinEditBox.cpp
- `D2GameNodeStrc::~D2GameNodeStrc` at 0x0044F820 -> `??1?$TSHashObject@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ`, in Source/D2Game/GAME/Game.cpp
- `D2Object00610D30Strc::~D2Object00610D30Strc` at 0x00610AA0 -> `D2CommonIgnoreListStrc::~D2CommonIgnoreListStrc`, in Source/D2Common/Chat/Ignorelist.cpp

**placeholder** (1087 symbols)

- `TOutputStream::TOutputStream` at 0x0041D920 -> `sub_0041D920`, in Source/Storm/Unknown_0041F6A0.cpp
- `WardenModule::~WardenModule` at 0x004E06A0 -> `sub_004E06A0_FreeModules`, in Source/D2Client/WARDEN/WardenClient.cpp
- `WardenModule::~WardenModule` at 0x004E06A0 -> `sub_004E06A0_FreeModules`, in Source/D2Client/Unknown_004DF1C0.cpp
- `ACT1Q1_CanClientFXBeTriggered` at 0x00590810 -> `sub_00590810`, in Source/D2Game/Quests/QUESTS.CPP
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `sub_00541860`, in Source/D2Game/Unknown_005D1080.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `sub_00541860`, in Source/D2Game/SKILLS/SkillSor.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `sub_00541860`, in Source/D2Game/SKILLS/SkillItem.cpp
- `AIGENERAL_GetAiControlFromUnit` at 0x00541860 -> `sub_00541860`, in Source/D2Game/Ai/AiThink4.cpp

**renamed_definition** (80 symbols)

- `D2StormHashCtxStrc::Append` at 0x00425DD0 -> `Append`, in Source/D2Client/WARDEN/WardenClient.cpp
- `BigAdd` at 0x00422300 -> `BigAdd`, in Source/Storm/SOURCE/SBig_00425350.cpp
- `THuffmannTree::Compress` at 0x0041F850 -> `D2StormHuffTreeStrc::Compress`, in Source/Storm/Unknown_0041F6A0.cpp
- `CHuffman::Decompress` at 0x0041F740 -> `Decompress`, in Source/Storm/SOURCE/SSignature.cpp
- `EDITBOX_UpdateVisibleChars` at 0x004FE7C0 -> `EDITBOX_UpdateVisibleChars`, in Source/D2Win/Src/D2WinEditBox.cpp
- `D2GridLightStrc::ExtendBounds` at 0x004DDE80 -> `ExtendBounds`, in Source/D2Client/GAME/Wall2.cpp
- `FindPrime` at 0x004255E0 -> `FindPrime`, in Source/Storm/SOURCE/SBig_00425350.cpp
- `GFX_BuildMonsterCofPath` at 0x0046F490 -> `GFX_BuildMonsterCofPath`, in Source/D2Client/ENGINE/Gfx_0046F870.cpp

**interior** (9 symbols)

- `gbPanelFlag` at 0x0071315C -> `gaEscMenuUIState+0x104`, in Source/D2Client/Unknown_0047CC90.cpp
- `gdwBitMask5` at 0x006CE27C -> `gdwBitMasks+0x14`, in Source/D2Launch/Src/CharSel.cpp
- `gdwBitMask7` at 0x006CE284 -> `gdwBitMasks+0x1C`, in Source/D2Multi/Src/ComCallback.cpp
- `gdwTitleMaskA` at 0x006CE280 -> `gdwBitMasks+0x18`, in Source/D2Multi/Src/ComCallback.cpp
- `gnFlagClear0` at 0x006CE2F8 -> `gdwInvBitMasks+0x10`, in Source/D2Launch/Src/CharSel.cpp
- `gnFlagClear1` at 0x006CE2FC -> `gdwInvBitMasks+0x14`, in Source/D2Launch/Src/CharSel.cpp
- `gnFlagSet0_006CE278` at 0x006CE278 -> `gdwBitMasks+0x10`, in Source/D2Launch/Src/CharSel.cpp
- `gnRenderFlag` at 0x006CE290 -> `gdwBitMasks+0x28`, in Source/D2Direct3D/Src/d3dSmack.cpp

**unsourced_data** (768 symbols)

- `empty` at 0x006CC837, in Source/D2Client/UI/npcmenu.cpp
- `g007C0C6B` at 0x007C0C6B, in Source/D2Client/UI/npcmenu.cpp
- `g007C0D31` at 0x007C0D31, in Source/D2Client/UI/npcmenu.cpp
- `g007C0D3F` at 0x007C0D3F, in Source/D2Client/UI/npcmenu.cpp
- `g007C0D5B` at 0x007C0D5B, in Source/D2Client/UI/npcmenu.cpp
- `g007C0D67` at 0x007C0D67, in Source/D2Client/UI/npcmenu.cpp
- `g007C0DE1` at 0x007C0DE1, in Source/D2Client/UI/npcmenu.cpp
- `g007C0DE5` at 0x007C0DE5, in Source/D2Client/UI/npcmenu.cpp

**no_address** (172 symbols)

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

