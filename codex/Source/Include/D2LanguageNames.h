#pragma once
// The language names, indexed by language id (STRTABLE_GetSystemLanguage and the game language).
//
// The table is static and defined in this header, so each object that includes the header keeps its
// own copy in .data, read or not; the image has 308 copies. The copy lands where the include sits among
// the unit's data definitions, so an include at the top of a unit puts it before the unit's other data
// (the gen/data include comes last). Include this header only in a unit whose original data has a copy:
// a unit that gains a copy the image doesn't have breaks the build.

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
