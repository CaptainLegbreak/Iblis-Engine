#pragma once
// Monster modes: the value of D2UnitStrc::dwAnimMode for a monster unit.

enum D2C_MonModes
{
    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_WALK = 2,
    MONMODE_GETHIT = 3,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    MONMODE_BLOCK = 6,
    MONMODE_CAST = 7,
    MONMODE_SKILL1 = 8,
    MONMODE_SKILL2 = 9,
    MONMODE_SKILL3 = 10,
    MONMODE_SKILL4 = 11,
    MONMODE_DEAD = 12,
    MONMODE_KNOCKBACK = 13,
    MONMODE_SEQUENCE = 14,
    MONMODE_RUN = 15,
};
