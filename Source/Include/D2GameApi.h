#pragma once
// D2Game's exports that the other modules call; included only by the units that use it.

struct D2StoredUnitRecordStrc;

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
void __cdecl TEXT_FreeTextSliderCel(); // 0x004A51E0
int __cdecl GAME_GetAbortFlag(); // 0x00520AE0
int __fastcall GAME_DeleteBigNum(void* pArg); // 0x0052A600
void __stdcall GAME_SetInitSeed(int nInitSeed); // 0x0052C320
void __fastcall GAME_ProcessNetworkMessages(); // 0x0052CFE0
void __stdcall GAME_CloseAllGames(); // 0x0052E9C0
int __stdcall GAME_UpdateClients(int bForceUpdate1, int bForceUpdate2); // 0x0052FD90
int __stdcall GAME_Initialize(); // 0x00530690
void __fastcall PLAYER_SetVirtualPlayerCount(int nPlayers); // 0x00535780
