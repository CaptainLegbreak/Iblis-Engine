#pragma once
// The language names, indexed by language id (STRTABLE_GetSystemLanguage and the game language).
//
// The table is static and defined in this header, so each object that includes the header keeps its
// own copy in .data, read or not, as in the original game, which has 308 copies.

static const char* gaszLanguageNames[15] =
{
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14",
};
