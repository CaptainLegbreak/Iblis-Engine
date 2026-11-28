#pragma once
// D2Game items: the books.txt table as the item code reads it (record count, records).

#include "D2Check.h"

struct D2BooksTxt;

struct D2BookDataTbl
{
    int nBooksTxtRecordCount;
    D2BooksTxt* pBooksTxt;
};
