#pragma once
// D2Lang: the 16-bit game text character and its string routines.

extern "C" int __cdecl isspace(int c); // 0x00687006
extern unsigned short gawToUpperTable[0x100]; // 0x00730578

struct Unicode
{
    enum Direction
    {
        DIR_LEFT_TO_RIGHT = 0xF0,
        DIR_RIGHT_TO_LEFT = 0xF1,
        DIR_NEUTRAL = 0xF2,
    };

    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}

    int isWhitespace() const
    {
        if (wChar < 0x100 && isspace(wChar))
            return 1;
        return 0;
    }
    int isNewline() const { return wChar == '\n'; }
    int isPipe() const
    {
        if (wChar < 0x100)
            return wChar == 0xFF;
        return 0;
    }
    int IsColorCodePrefix() const
    {
        if (wChar >= 0x100)
            return 0;
        return wChar == 0xFF;
    }
    int ToDigit() const { return wChar - '0'; }
    Unicode toUpper() const { return Unicode(wChar < 0x100 ? gawToUpperTable[wChar] : wChar); }
    int isAlpha() const;
    int isLeftToRight() const; // 0x00526D00
    Direction directionality(); // 0x00526FB0
    Unicode toLower() const; // 0x004B15F0

    static int __fastcall compare(Unicode lhs, Unicode rhs);
    static int __fastcall strcmp(const Unicode* str1, const Unicode* str2);
    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count);
    static int __fastcall stricmp(const Unicode* str1, const Unicode* str2);
    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, unsigned int count);
    static Unicode* __fastcall strchr(const Unicode* str, Unicode ch);
    static Unicode* __fastcall strcat(Unicode* dest, const Unicode* src);
    static Unicode* __fastcall strncat(Unicode* dest, const Unicode* src, int count);
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);
    static Unicode* __fastcall strcpy(Unicode* dest, const Unicode* src);
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);
    static char* __fastcall unicode2Win(char* dest, const Unicode* src, int count);
};

// The string routines are named by their decorated names: their plain names are also C runtime names.
// build: symbol ?compare@Unicode@@SIHU1@0@Z 0x00526490
// build: symbol ?strcmp@Unicode@@SIHPBU1@0@Z 0x005264F0
// build: symbol ?strncmp@Unicode@@SIHPBU1@0I@Z 0x00526540
// build: symbol ?stricmp@Unicode@@SIHPBU1@0@Z 0x00526590
// build: symbol ?strnicmp@Unicode@@SIHPBU1@0I@Z 0x00526610
// build: symbol ?strchr@Unicode@@SIPAU1@PBU1@U1@@Z 0x005266C0
// build: symbol ?strcat@Unicode@@SIPAU1@PAU1@PBU1@@Z 0x00526700
// build: symbol ?strncat@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526740
// build: symbol ?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526790
// build: symbol ?strcpy@Unicode@@SIPAU1@PAU1@PBU1@@Z 0x005267E0
// build: symbol ?win2Unicode@Unicode@@SIPAU1@PAU1@PBDH@Z 0x00526F20
// build: symbol ?unicode2Win@Unicode@@SIPADPADPBU1@H@Z 0x00526F70

// The default constructor closure the compiler emits for arrays of Unicode.
// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
