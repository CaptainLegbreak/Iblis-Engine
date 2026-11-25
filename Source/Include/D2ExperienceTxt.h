#pragma once
// D2Common: experience.txt, as DATATBLS loads it: the first row (the maximum level per class) and then one row
// per level, each with the experience per class and the ratio.

#include "D2Check.h"

struct D2ExperienceTxt
{
    unsigned int dwClass[7];
    unsigned int dwExpRatio;
};

struct D2ExperienceDataTbl
{
    D2ExperienceTxt tMax;
    D2ExperienceTxt aLevels[1];
};
