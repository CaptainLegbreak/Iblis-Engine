#pragma once
// D2Multi: two views of a .d2s character save: its header and the whole 0x2000-byte file (old flags at 0x18, flags at 0x24).

#include "D2Check.h"

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    unsigned int dwChecksum;
    char unk0x10[0x13F];
};

struct D2CharSaveFileStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    unsigned int dwChecksum;
    char unk0x10[0x08];
    unsigned int dwOldFlags;
    char unk0x1C[0x08];
    unsigned int dwFlags;
    char unk0x28[0x1FD8];
};
