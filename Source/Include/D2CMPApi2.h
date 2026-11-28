#pragma once
// D2CMP's exports that the other modules call; included only by the units that use it.

int __stdcall D2CMPSpriteFindAsynchSiblings(int nKeyA, int nKeyB, int nKeyC); // 0x005FF300
unsigned char* __stdcall D2CMPPalShiftGetTransform(int nSet, int nIndex); // 0x00600C20
int __stdcall CelConvertDir(unsigned int nDirection, unsigned int nDirections, int nNewDirections, int bAlt); // 0x00600CB0
int __stdcall CelGameDirToNormalDir(unsigned int nIndex, unsigned int nDirections); // 0x00600E20
int __cdecl DATATBLS_GetShrinesTxtRecordCount(); // 0x00641500
extern int gnShrinesTxtRecordCount; // 0x0096D46C
