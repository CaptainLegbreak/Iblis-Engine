#pragma once
// Client: the list node of a dialog's widgets.

#include "D2Check.h"

struct D2DialogWidget;

struct D2DialogWidgetNodeStrc
{
    D2DialogWidget* pWidget;
    D2DialogWidgetNodeStrc* pNext;
};
