#pragma once
// Client: a list box line (six text columns, its flags, data and font).

#include "D2Check.h"

#pragma pack(push, 2)
struct D2ListBoxLineStrc
{
    inline D2ListBoxLineStrc()
    {
    }

    Unicode wszText0[0x400];
    Unicode wszText1[0x400];
    Unicode wszText2[0x400];
    Unicode wszText3[0x400];
    Unicode wszText4[0x400];
    Unicode wszText5[0x400];
    short nFlags;
    int nData;
    int nColor;
    int nFont;
};
#pragma pack(pop)
