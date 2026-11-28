#pragma once
// The squelch list D2Common keeps for the chat (sub_00611560_GetSquelchList): names squelched and texts
// filtered, called through its vtable.

class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void AddName(const char* szName, int nSize);
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};
