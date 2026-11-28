#pragma once
// A hireling's stats as MONSTERS_HirelingInit (D2Common) fills them from hireling.txt for the
// server's hire list and the client's NPC menu.

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short pad0x3A;
};
