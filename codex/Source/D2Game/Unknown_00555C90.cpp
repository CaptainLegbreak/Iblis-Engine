#define FIELD_OFFSET(s, m) ((unsigned int)&(((s*)0)->m))

struct FieldRecord;
struct ThreeFieldRecord;
struct FlagsRecord;
struct TableRow;
struct TablesPartial;
struct NestedData;
struct TypedRecord;
struct D2UnkEntry8Strc;

struct FieldRecord
{
    char unknown00[0xDC];
    void* value;
};

struct ThreeFieldRecord
{
    char unknown00[0x64];
    int first;
    int second;
    unsigned char valid;
};

struct FlagsRecord
{
    char unknown00[0x60];
    unsigned int flags;
};

struct TableRow
{
    char bytes[0xE4];
};

struct TablesPartial
{
    char unknown00[0xBF8];
    TableRow* rows;
    int count;
};

struct NestedData
{
    int value;
};

struct TypedRecord
{
    int type;
    char unknown04[0x14 - 4];
    NestedData* data;
};


extern "C" TablesPartial* sgptDataTables; // 0x00744304

typedef char check_FieldRecord_value[FIELD_OFFSET(FieldRecord, value) == 0xDC ? 1 : -1];

typedef char check_FieldRecord_size[sizeof(FieldRecord) == 0xDC + 4 ? 1 : -1];

typedef char check_ThreeFieldRecord_first[FIELD_OFFSET(ThreeFieldRecord, first) == 0x64 ? 1 : -1];

typedef char check_ThreeFieldRecord_second[FIELD_OFFSET(ThreeFieldRecord, second) == 0x68 ? 1 : -1];

typedef char check_ThreeFieldRecord_valid[FIELD_OFFSET(ThreeFieldRecord, valid) == 0x6C ? 1 : -1];

typedef char check_ThreeFieldRecord_size[sizeof(ThreeFieldRecord) == 0x6C + 4 ? 1 : -1];

typedef char check_FlagsRecord_flags[FIELD_OFFSET(FlagsRecord, flags) == 0x60 ? 1 : -1];

typedef char check_FlagsRecord_size[sizeof(FlagsRecord) == 0x60 + 4 ? 1 : -1];

typedef char check_TableRow_size[sizeof(TableRow) == 0xE4 ? 1 : -1];

typedef char check_TablesPartial_rows[FIELD_OFFSET(TablesPartial, rows) == 0xBF8 ? 1 : -1];

typedef char check_TablesPartial_count[FIELD_OFFSET(TablesPartial, count) == 0xBFC ? 1 : -1];

typedef char check_TablesPartial_size[sizeof(TablesPartial) == 0xBFC + 4 ? 1 : -1];

typedef char check_TypedRecord_type[FIELD_OFFSET(TypedRecord, type) == 0 ? 1 : -1];

typedef char check_TypedRecord_data[FIELD_OFFSET(TypedRecord, data) == 0x14 ? 1 : -1];

typedef char check_TypedRecord_size[sizeof(TypedRecord) == 0x14 + 4 ? 1 : -1];

typedef char check_NestedData_value[FIELD_OFFSET(NestedData, value) == 0 ? 1 : -1];

typedef char check_NestedData_size[sizeof(NestedData) == 4 ? 1 : -1];

struct D2UnkEntry8Strc
{
    int f_0;
    int f_4;
};


int __stdcall sub_K11_EmitUse(D2UnkEntry8Strc* pEntry);

// 0x00555D00
static D2UnkEntry8Strc* __stdcall sub_00555D00_GetBoundedEntry(D2UnkEntry8Strc* pBase, int nIndex, int nMax)
{
    if (nIndex > nMax)
    {
        return 0;
    }
    return &pBase[nIndex];
}

int __fastcall sub_K11_Emit00555D00(D2UnkEntry8Strc* pBase, int nIndex, int nMax)
{
    return sub_K11_EmitUse(sub_00555D00_GetBoundedEntry(pBase, nIndex + 3, nMax));
}
