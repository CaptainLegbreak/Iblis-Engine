#include "D2MonsterIds.h"

#include "D2ItemTypes.h"

#include "D2DrlgMaps.h"

#include "D2DrlgTiles.h"

#include "D2TxtTables.h"

#include "D2LevelIds.h"

#include "D2Unicode.h"

#include "D2StateIds.h"

#include "D2SkillIds.h"

#include "D2StatIds.h"

#include "D2Records.h"

#include "D2Skills.h"

#include "D2LevelTxt.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"

#include "D2PathFind.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Drlg.h"

#include "D2DrlgPresets.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#define PATH_UNKNOWN_FLAG_0x00010 0x00010

#define PATH_UNKNOWN_FLAG_0x00020 0x00020

#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define PATH_CORPSE_SIZE 3

struct ActiveRoom;

struct Room;

struct D2CoordStrc;

union D2FP32_16;

struct D2DrlgCoordsStrc;

struct D2StaticPathStrc;

struct D2PathInfoStrc;

struct PATH_SetVelocity;

struct Obj00648690;

struct Obj006486D0;

struct RoomStatusNode;

struct DrlgView;

struct PathView;

struct UnitView;

struct Obj00648750;

struct View_00648780;

struct View_006489C0;

struct View_00648AA0;

struct View_00648700;

struct Obj00648790;

struct PATH_GetPathPoints;

struct Obj006487D0;

struct Obj00648810;

struct Obj006488A0;

struct PathPrecisionView;

struct PathPreviousView;

struct Obj006BCDE0;

struct Obj006489D0;

struct Obj00648A20;

struct Obj00648A30;

struct Entry00648A40;

struct PATH_GetLastPointX;

struct Obj00648A40;

struct Entry00648A60;

struct PATH_GetLastPointY;

struct Obj00648A60;

struct Obj00648A80;

struct Obj00648AB0;

struct Obj00648AD0;

struct RoomFlags;

struct PathFlags;

struct KeyValue;

struct CodeRow;

struct CodeOutput;

struct LinkView;

struct CodeLink;

struct Vector;

struct DirectionRecord;

struct B25TargetUnit;

struct B25Path;

struct B25DistancePath;

struct B25MissileData;

struct B25MissileUnit;

struct Obj00648C10;

struct Obj00648CD0;

struct D2Record00648E40Strc;

struct PathCollisionView;

struct PATH_SetStepNum;

struct Obj00649070;

struct Obj006490A0;

struct Obj00649120;

struct D2PathPointStrc;

struct D2ActiveRoomStrc;

struct D2UnitStrc;

struct D2DynamicPathStrc;

typedef int BOOL;

typedef int (__fastcall* PATH_FUNCTION)(D2PathInfoStrc* pPathInfo);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C

extern const D2CoordStrc gaDirectionToOffset[8]; // 0x006EB398

extern PATH_FUNCTION const gpfnPathFunctions[]; // 0x006EB6D8

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall UnitIsDoor(D2UnitStrc* pUnit); // 0x00621A70

int __fastcall UNITS_CheckIfObjectOrientationIs1(D2UnitStrc* pUnit); // 0x00621AC0

int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster); // 0x0063E860

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400

int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064D910

int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40

int __fastcall PATH_ComputePathBlessedHammer_6FDAB3C0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed); // 0x0067A140

int __fastcall PATH_ComputePathChargedBolt_6FDAB4A0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed); // 0x0067A240

static void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo); // 0x00648050

static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo);

struct PATH_SetVelocity {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00648690 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    int nValue38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned int dwUnknown64;
    unsigned int dwUnknown68;
    unsigned int dwUnknown6C;
    unsigned int dwUnknown70;
    unsigned int dwUnknown74;
    unsigned int dwUnknown78;
    int nValue7C;
    unsigned int dwUnknown80;
    int nValue84;
};

struct Obj006486D0 { unsigned int dwUnknown00[33]; unsigned int dwValue84; };

typedef unsigned char U8;

typedef unsigned int U32;

struct RoomStatusNode
{
    char retainedPrefix[0x1c];
    RoomStatusNode* statusNext;
    char retainedMiddle[0x10];
    ActiveRoom* activeRoom;
    char retainedBeforeStatus[0x10];
    U8 status;
    char retainedTail[0xA7];
};

struct DrlgView
{
    char retainedPrefix[0xa0];
    RoomStatusNode statusRooms[4];
};

struct PathView
{
    char retainedPrefix[0x28];
    int pointCount;
    char retainedGap[8];
    U32 flags;
    char retainedBeforePattern[0x10];
    int collisionPattern;
};

struct UnitView
{
    char retainedPrefix[0x2c];
    PathView* path;
};

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_room_next[OFFSET(RoomStatusNode,statusNext)==0x1c?1:-1];

typedef char check_room_active[OFFSET(RoomStatusNode,activeRoom)==0x30?1:-1];

typedef char check_room_status[OFFSET(RoomStatusNode,status)==0x44?1:-1];

typedef char check_room_stride[sizeof(RoomStatusNode)==0xec?1:-1];

typedef char check_room_array[OFFSET(DrlgView,statusRooms)==0xa0?1:-1];

typedef char check_first_head[OFFSET(DrlgView,statusRooms)+OFFSET(RoomStatusNode,statusNext)==0xbc?1:-1];

typedef char check_second_sentinel[OFFSET(DrlgView,statusRooms)+sizeof(RoomStatusNode)==0x18c?1:-1];

typedef char check_second_head[OFFSET(DrlgView,statusRooms)+sizeof(RoomStatusNode)+OFFSET(RoomStatusNode,statusNext)==0x1a8?1:-1];

typedef char check_path_count[OFFSET(PathView,pointCount)==0x28?1:-1];

typedef char check_path_flags[OFFSET(PathView,flags)==0x34?1:-1];

typedef char check_path_pattern[OFFSET(PathView,collisionPattern)==0x48?1:-1];

typedef char check_unit_path[OFFSET(UnitView,path)==0x2c?1:-1];

struct Obj00648750 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwFlags34;
};

struct View_00648780
{
    char gap[0x28];
    int pointCount;
};

typedef char check_offset_00648780[OFFSET(View_00648780,pointCount)==0x28?1:-1];

typedef char check_size_00648780[sizeof(View_00648780)==0x2C?1:-1];

struct View_006489C0
{
    char gap[0x8];
    int clientX;
};

typedef char check_offset_006489C0[OFFSET(View_006489C0,clientX)==0x8?1:-1];

typedef char check_size_006489C0[sizeof(View_006489C0)==0xC?1:-1];

struct View_00648AA0
{
    char gap[0x20];
    Room* previousRoom;
};

typedef char check_offset_00648AA0[OFFSET(View_00648AA0,previousRoom)==0x20?1:-1];

typedef char check_size_00648AA0[sizeof(View_00648AA0)==0x24?1:-1];

struct View_00648700
{
    char gap[0x88];
    int acceleration;
};

typedef char check_offset_00648700[OFFSET(View_00648700,acceleration)==0x88?1:-1];

typedef char check_size_00648700[sizeof(View_00648700)==0x8C?1:-1];

struct Obj00648790 { unsigned char bUnknown00[0x28]; int nValue28; };

struct PATH_GetPathPoints {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj006487D0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwValue28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    PATH_GetPathPoints tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    unsigned int dwUnknown98;
    unsigned int dwField9C;
};

struct Obj00648810 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned char nUnknown64;
    unsigned char nValue65;
};

struct Obj006488A0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned char nValue64;
    unsigned char nValue65;
};

typedef unsigned short U16;

typedef char check_word_width[sizeof(U16)==2?1:-1];

struct PathPrecisionView
{
    U32 precisionX;
};

typedef char check_precision_x[OFFSET(PathPrecisionView,precisionX)==0?1:-1];

struct PathPreviousView
{
    char retainedPrefix[0x14];
    U16 previousTargetX;
    U16 previousTargetY;
};

typedef char check_previous_x[OFFSET(PathPreviousView,previousTargetX)==0x14?1:-1];

typedef char check_previous_y[OFFSET(PathPreviousView,previousTargetY)==0x16?1:-1];

struct Obj006BCDE0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

struct Obj006489D0 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwValue0C; };

struct Obj00648A20 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned short wValue18;
};

struct Obj00648A30 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned short wUnknown18;
    unsigned short wValue1A;
};

struct Entry00648A40 {
    unsigned short wFirst;
    unsigned short wSecond;
};

struct PATH_GetLastPointX {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00648A40 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    int nIndex28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    PATH_GetLastPointX tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    Entry00648A40 tEntries98;
};

struct Entry00648A60 {
    unsigned short wFirst;
    unsigned short wSecond;
};

struct PATH_GetLastPointY {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00648A60 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    int nIndex28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    PATH_GetLastPointY tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    Entry00648A60 tEntries98;
};

struct Obj00648A80 { unsigned int dwUnknown00[7]; unsigned int dwValue1C; };

struct Obj00648AB0 { unsigned int dwUnknown00[8]; unsigned int dwValue20; };

struct Obj00648AD0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned short wValue10;
    unsigned short wValue12;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwValue58;
};

typedef signed char S8;

struct RoomFlags
{
    char pad0[0x28];
    U32 flags;
};

typedef char check_RoomFlags_flags[OFFSET(RoomFlags,flags)==0x28?1:-1];

typedef char check_RoomFlags_size[sizeof(RoomFlags)==0x2C?1:-1];

struct PathFlags
{
    char pad0[0x34];
    U32 flags;
};

typedef char check_PathFlags_flags[OFFSET(PathFlags,flags)==0x34?1:-1];

typedef char check_PathFlags_size[sizeof(PathFlags)==0x38?1:-1];

struct KeyValue
{
    U32 key;
    int value;
};

typedef char check_KeyValue_value[OFFSET(KeyValue,value)==4?1:-1];

typedef char check_KeyValue_size[sizeof(KeyValue)==8?1:-1];

struct CodeRow
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    int row;
};

typedef char check_CodeRow_row[OFFSET(CodeRow,row)==4?1:-1];

typedef char check_CodeRow_c0[OFFSET(CodeRow,c0)==0?1:-1];

typedef char check_CodeRow_c1[OFFSET(CodeRow,c1)==1?1:-1];

typedef char check_CodeRow_c2[OFFSET(CodeRow,c2)==2?1:-1];

typedef char check_CodeRow_c3[OFFSET(CodeRow,c3)==3?1:-1];

typedef char check_CodeRow_size[sizeof(CodeRow)==8?1:-1];

struct CodeOutput
{
    S8 c0;
    S8 c1;
    S8 c2;
    S8 c3;
    S8 terminal;
};

typedef char check_CodeOutput_terminal[OFFSET(CodeOutput,terminal)==4?1:-1];

typedef char check_CodeOutput_c0[OFFSET(CodeOutput,c0)==0?1:-1];

typedef char check_CodeOutput_c1[OFFSET(CodeOutput,c1)==1?1:-1];

typedef char check_CodeOutput_c2[OFFSET(CodeOutput,c2)==2?1:-1];

typedef char check_CodeOutput_c3[OFFSET(CodeOutput,c3)==3?1:-1];

typedef char check_CodeOutput_size[sizeof(CodeOutput)==5?1:-1];

struct LinkView
{
    int count;
    char pad4[0x4];
    KeyValue* entries;
};

typedef char check_LinkView_entries[OFFSET(LinkView,entries)==0x8?1:-1];

typedef char check_LinkView_size[sizeof(LinkView)==0xC?1:-1];

struct CodeLink
{
    int count;
    char pad4[0x4];
    CodeRow* entries;
};

typedef char check_CodeLink_entries[OFFSET(CodeLink,entries)==0x8?1:-1];

typedef char check_CodeLink_size[sizeof(CodeLink)==0xC?1:-1];

struct Vector
{
    int x;
    int y;
};

typedef char check_Vector_y[OFFSET(Vector,y)==4?1:-1];

typedef char check_Vector_size[sizeof(Vector)==8?1:-1];

struct DirectionRecord
{
    int x;
    int y;
    int angle;
};

typedef char check_DirectionRecord_y[OFFSET(DirectionRecord,y)==4?1:-1];

typedef char check_DirectionRecord_angle[OFFSET(DirectionRecord,angle)==8?1:-1];

typedef char check_DirectionRecord_size[sizeof(DirectionRecord)==12?1:-1];

// build: symbol ?gaTanToDirectionTable@* 0x006EB7E0
extern DirectionRecord gaTanToDirectionTable[128];

struct B25TargetUnit
{
    unsigned int type;
    U8 pad4[0x8];
    unsigned int id;
};

struct B25Path
{
    U8 pad0[0x58];
    B25TargetUnit* target;
    unsigned int targetType;
    unsigned int targetId;
};

struct B25DistancePath
{
    U8 pad0[0x90];
    U8 distance;
    U8 newDistance;
};

struct B25MissileData
{
    U8 pad0[0x28];
    int targetStatus;
};

struct B25MissileUnit
{
    unsigned int type;
    U8 pad4[0x10];
    B25MissileData* data;
};

typedef char CheckTargetUnitid[(OFFSET(B25TargetUnit,id)==0xC)?1:-1];

typedef char CheckPathtarget[(OFFSET(B25Path,target)==0x58)?1:-1];

typedef char CheckPathtargetType[(OFFSET(B25Path,targetType)==0x5C)?1:-1];

typedef char CheckPathtargetId[(OFFSET(B25Path,targetId)==0x60)?1:-1];

typedef char CheckDistancePathdistance[(OFFSET(B25DistancePath,distance)==0x90)?1:-1];

typedef char CheckDistancePathnewDistance[(OFFSET(B25DistancePath,newDistance)==0x91)?1:-1];

typedef char CheckMissileDatatargetStatus[(OFFSET(B25MissileData,targetStatus)==0x28)?1:-1];

typedef char CheckMissileUnitdata[(OFFSET(B25MissileUnit,data)==0x14)?1:-1];

struct Obj00648C10 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwValue4C;
};

struct Obj00648CD0 { unsigned int dwUnknown00[20]; unsigned int dwValue50; };

struct D2Record00648E40Strc
{
    unsigned char unk_00[0x90];
    unsigned char nValue90;
};

extern "C" U16 __stdcall COLLISION_CheckMaskWithSize(ActiveRoom* room,int x,int y,int unitSize,U16 mask); // 0x0064D9B0

struct PathCollisionView
{
    char retainedGap0[0x2];
    U16 positionX;
    char retainedGap1[0x2];
    U16 positionY;
    char retainedGap2[0x14];
    ActiveRoom* room;
    char retainedGap3[0x24];
    int f_44;
    char retainedGap4[0xC];
    U16 collidedMask;
    char retainedGap5[0x26];
    int velocity;
};

typedef char check_positionX[OFFSET(PathCollisionView,positionX)==0x2?1:-1];

typedef char check_positionY[OFFSET(PathCollisionView,positionY)==0x6?1:-1];

typedef char check_room[OFFSET(PathCollisionView,room)==0x1C?1:-1];

typedef char check_unitSize[OFFSET(PathCollisionView,f_44)==0x44?1:-1];

typedef char check_collidedMask[OFFSET(PathCollisionView,collidedMask)==0x54?1:-1];

typedef char check_velocity[OFFSET(PathCollisionView,velocity)==0x7C?1:-1];

struct PATH_SetStepNum {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00649070 {
    PATH_SetStepNum tPad000;
    PATH_SetStepNum tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned char nUnknown90;
    unsigned char nUnknown91;
    unsigned char nUnknown92;
    unsigned char nValue93;
};

struct Obj006490A0 { unsigned char bUnknown00[0x93]; unsigned char bValue93; };

struct Obj00649120 { unsigned char bUnknown00[0x94]; unsigned char bValue94; };

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath); // 0x00650590

static unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo);

static int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath);

static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit);

static BOOL PATH_IsTargetDestinationAllowed(D2PathInfoStrc* pPathInfo, D2UnitStrc* pUnit);

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);

static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo);

#define COLLIDE_MISSILE_BARRIER 0x4

#define MONSTATSFLAGINDEX_INTERACT 9

#define UNITFLAG_ISASYNC 0x00200000

#define PATH_UNKNOWN_FLAG_0x02000 0x00002000

#define PATH_WITH_PREVIOUS_VELOCITY 0x00008000

struct D2MonStatsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY); // 0x00643290

int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize); // 0x00648580

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x0064C350

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0

int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2); // 0x00650350

int __stdcall D2Common_10227(D2UnitStrc* pUnit); // 0x00650540

extern int gaOffsetForPathType[]; // 0x006EB648

extern int gaPathTypeFlags[]; // 0x006EB690

void __stdcall DUNGEON_ClientToGameCoords(int* pX, int* pY); // 0x00643540

void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60

int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit); // 0x006209D0

int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall UNITS_HasCollision(D2UnitStrc* pUnit); // 0x006219C0

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EA00

void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

#define PATH_NB_DIRECTIONS 64

#define PATHTYPE_IDASTAR 0

#define PATH_CURRENT_ROOM_INVALID 0x00002

#define PATH_UNUSED_FLAG_0x00004 0x00004

#define PATH_UNKNOWN_FLAG_0x00040 0x00040

#define PATH_SAVE_STEPS_MASK 0x20000

static int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath);

static unsigned char PATH_AdvanceToDoor(D2PathInfoStrc* pPathInfo);

static unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo);

static int PATH_GetMonsterMoveTestMask(D2UnitStrc* pUnit);

int __stdcall PATH_ComputeDirectionFromPreciseCoords_6FDAC760(D2FP32_16 tStart, D2FP32_16 tTarget); // 0x0064FE10

void __fastcall PATH_SetNewDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006485F0

static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit);

void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag);

void __stdcall D2Common_10228(D2UnitStrc* pUnit);

void __cdecl sub_00403F50_Nop()
{
}

inline unsigned int PATH_InlineGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline unsigned int PATH_InlineGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct D2PathPoint00647FB0Strc
{
    unsigned short X;
    unsigned short Y;
};
struct D2ActiveRoom00647FB0Strc
{
    unsigned char unk_00[0x4C];
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
};
struct D2DynamicPath00647FB0Strc
{
    unsigned char unk_00[0x1C];
    D2ActiveRoom00647FB0Strc* pRoom;
    unsigned char unk_20[8];
    int nPathPoints;
    unsigned char unk_2C[8];
    unsigned int dwFlags;
    unsigned char unk_38[0x64];
    D2PathPoint00647FB0Strc PathPoints[78];
};

// 0x00647FB0
void __fastcall sub_6FDA8220(D2DynamicPathStrc* pDynamicPath)
{
    D2DynamicPath00647FB0Strc* const pPath = (D2DynamicPath00647FB0Strc*)pDynamicPath;
    D2PathPoint00647FB0Strc* const pPathPoints = pPath->PathPoints;
    pPath->dwFlags &= ~1u;
    D2ActiveRoom00647FB0Strc* pRoom = pPath->pRoom;
    for (int i = 0; i < pPath->nPathPoints; ++i)
    {
        if (!pRoom
            || pPathPoints[i].X < pRoom->nSubtileX || pPathPoints[i].X >= pRoom->nSubtileX + pRoom->nSubtileWidth
            || pPathPoints[i].Y < pRoom->nSubtileY || pPathPoints[i].Y >= pRoom->nSubtileY + pRoom->nSubtileHeight)
        {
            pPath->dwFlags |= 1;
            return;
        }
    }
}

// 0x00648020
static void __stdcall PATH_GetTablePair(int b, int a, int* pOut1, int* pOut2)
{
    *pOut1 = gnOrthogonalStepTable[a][b];
    *pOut2 = gnOrthogonalStepTable[b][a];
}

void __stdcall sub_K15_Emit8(int* p, int n)
{
    PATH_GetTablePair(p[1], n, p, p + 1);
    PATH_GetTablePair(n, p[2], p + 2, p + 3);
}

// 0x00648050
static void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo)
{
    int nY;
    const int nDeltaX = pPathInfo->tTargetCoord.X - pPathInfo->tStartCoord.X;
    const int nDeltaY = pPathInfo->tTargetCoord.Y - pPathInfo->tStartCoord.Y;
    const int nAbsDeltaX = D2_ABS(nDeltaX);
    const int nAbsDeltaY = D2_ABS(nDeltaY);
    if (nAbsDeltaX < PATH_SNAP_RANGE && nAbsDeltaY < PATH_SNAP_RANGE && (nAbsDeltaX != 0 || nAbsDeltaY != 0))
    {
        int nX = pPathInfo->tTargetCoord.X;
        const int nCollisionPattern = pPathInfo->nCollisionPattern;
        const int nCollisionMask = pPathInfo->nCollisionMask;
        const int nOffsetX = gnOrthogonalStepTable[nDeltaY][nDeltaX];
        const int nOffsetY = gnOrthogonalStepTable[nDeltaX][nDeltaY];
        nY = pPathInfo->tTargetCoord.Y;
        int nChebyshevDistance = D2_MAX(nAbsDeltaX, nAbsDeltaY);
        while (nChebyshevDistance < PATH_SNAP_RANGE)
        {
            nX += nOffsetX;
            nY += nOffsetY;
            if (COLLISION_CheckAnyCollisionWithPattern(pPathInfo->pStartRoom, nX, nY, nCollisionPattern, nCollisionMask))
            {
                break;
            }

            pPathInfo->tTargetCoord.X = nX;
            pPathInfo->tTargetCoord.Y = nY;
            ++nChebyshevDistance;
        }
    }
}

// 0x00648120
static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* ptPath = pPathInfo->pDynamicPath;
    D2_ASSERT(!(ptPath->dwFlags & PATH_MISSILE_MASK), LINE_PREPARE_MISSILE);

    const unsigned short nStartX = pPathInfo->tStartCoord.X;
    const unsigned short nStartY = pPathInfo->tStartCoord.Y;
    const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
    const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nUnitType = !ptPath->pUnit ? UNIT_NONE : ptPath->pUnit->dwUnitType;

    D2PathPointStrc aTestDirPathPoints[3];
    aTestDirPathPoints[0].X = nTargetX;
    aTestDirPathPoints[0].Y = nTargetY;
    aTestDirPathPoints[1].X = nTargetX;
    aTestDirPathPoints[1].Y = nTargetY;
    aTestDirPathPoints[2].X = nTargetX;
    aTestDirPathPoints[2].Y = nTargetY;

    int aTestDir[3];
    sub_6FDAB7D0(aTestDir, pPathInfo->tTargetCoord, pPathInfo->tStartCoord);
    while (1)
    {
        if (nStartX == aTestDirPathPoints[0].X && nStartY == aTestDirPathPoints[0].Y)
        {
            break;
        }

        aTestDirPathPoints[0].X += gaDirectionToOffset[aTestDir[0]].nX;
        aTestDirPathPoints[0].Y += gaDirectionToOffset[aTestDir[0]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[0].X, aTestDirPathPoints[0].Y, nCollisionPattern, nCollisionMask))
        {
            pPathInfo->tTargetCoord.X = aTestDirPathPoints[0].X;
            pPathInfo->tTargetCoord.Y = aTestDirPathPoints[0].Y;
            if (aTestDirPathPoints[0].X == nStartX && aTestDirPathPoints[0].Y == nStartY)
            {
                return FALSE;
            }

            if (nUnitType == UNIT_PLAYER)
            {
                PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
            }
            return PATH_TRUE;
        }

        aTestDirPathPoints[1].X += gaDirectionToOffset[aTestDir[1]].nX;
        aTestDirPathPoints[1].Y += gaDirectionToOffset[aTestDir[1]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[1].X, aTestDirPathPoints[1].Y, nCollisionPattern, nCollisionMask))
        {
            pPathInfo->tTargetCoord.X = aTestDirPathPoints[1].X;
            pPathInfo->tTargetCoord.Y = aTestDirPathPoints[1].Y;
            if (aTestDirPathPoints[1].X == nStartX && aTestDirPathPoints[1].Y == nStartY)
            {
                return FALSE;
            }

            if (nUnitType == UNIT_PLAYER)
            {
                PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
            }
            return PATH_TRUE;
        }

        if (aTestDir[2] != PATH_DIR_NULL)
        {
            aTestDirPathPoints[2].X += gaDirectionToOffset[aTestDir[2]].nX;
            aTestDirPathPoints[2].Y += gaDirectionToOffset[aTestDir[2]].nY;
            if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[2].X, aTestDirPathPoints[2].Y, nCollisionPattern, nCollisionMask))
            {
                pPathInfo->tTargetCoord.X = aTestDirPathPoints[2].X;
                pPathInfo->tTargetCoord.Y = aTestDirPathPoints[2].Y;
                if (aTestDirPathPoints[2].X == nStartX && aTestDirPathPoints[2].Y == nStartY)
                {
                    return FALSE;
                }

                if (nUnitType == UNIT_PLAYER)
                {
                    PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
                }
                return PATH_TRUE;
            }
        }

        int aNextTestDir[3];
        sub_6FDAB7D0(aNextTestDir, aTestDirPathPoints[0], pPathInfo->tStartCoord);
        aTestDir[0] = aNextTestDir[0];
    }

    return FALSE;
}

#define MONSTATS2FLAGINDEX_REVIVE 8

#define MONSTATS2FLAGINDEX_ISATT 9

#define MONSTATS2FLAGINDEX_SMALL 10

int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit); // 0x00622D00

struct D2SkillFormulaCtxStrc { D2UnitStrc* pUnit; int nSkillId; int nSkillLevel; };

inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00648300
void __stdcall PATH_GetClientCoordsVelocity(D2UnitStrc* pUnit, int* pX, int* pY)
{
    if (pUnit && UNITS_IsInMovingMode(pUnit))
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        if (pDynamicPath->dwPathPoints)
        {
            *pX = pDynamicPath->tVelocityVector.nX;
            *pY = pDynamicPath->tVelocityVector.nY;
            *pX >>= 11;
            *pY >>= 11;
            DUNGEON_GameToClientCoords(pX, pY);
        }
        else
        {
            *pX = 0;
            *pY = 0;
        }
    }
    else
    {
        *pX = 0;
        *pY = 0;
    }
}

// 0x00648370
void __cdecl sub_00648370_Nop()
{
}

// 0x00648380
void __cdecl sub_00648380_Nop()
{
}

// 0x00648390
int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x006483A0
static BOOL PATH_IsTargetDestinationAllowed(D2PathInfoStrc* pPathInfo, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_NONE;
    if (nUnitType != UNIT_MONSTER)
    {
        return TRUE;
    }

    if (MONSTERS_CanBeInTown(pUnit))
    {
        return TRUE;
    }

    D2ActiveRoomStrc* pTargetRoom = pPathInfo->pTargetRoom;
    if (!pTargetRoom)
    {
        const unsigned short nStartX = pPathInfo->tStartCoord.X;
        const unsigned short nStartY = pPathInfo->tStartCoord.Y;
        const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
        const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
        D2ActiveRoomStrc* pRoomHalfway = sub_00463740_FindRoomAtPoint(
            pPathInfo->pStartRoom,
            nStartX + (nTargetX - nStartX) / 2,
            nStartY + (nTargetY - nStartY) / 2);
        pTargetRoom = sub_00463740_FindRoomAtPoint(pRoomHalfway, nTargetX, nTargetY);
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}

// 0x00648430
void __cdecl sub_00648430_Nop()
{
}

// 0x00648440
void __cdecl sub_00648440_Nop()
{
}

// 0x00648450
void __cdecl sub_00648450_Nop()
{
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x006484E0
int __stdcall PATH_GetCollisionPatternFromMonStats2Txt(int nMonsterId)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (pMonStats2TxtRecord)
    {
        int nSizeX = pMonStats2TxtRecord->nSizeX;
        if (nSizeX >= 0 && nSizeX < COLLISION_UNIT_SIZE_COUNT)
        {
            int nCollisionPattern = gaCollisionPatternsFromSize[nSizeX];

            if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_REVIVE >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_REVIVE & 7]
                || pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_SMALL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL & 7])
            {
                if (!(pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_ISATT >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_ISATT & 7]))
                {
                    switch (nCollisionPattern)
                    {
                    case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
                        nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
                        break;
                    case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
                        nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
                        break;
                    }
                }
            }

            return nCollisionPattern;
        }
    }

    return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
}

// 0x00648640
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath)
{
    if ((pDynamicPath->nDirection != pDynamicPath->nNewDirection) && !(pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00040))
    {
        pDynamicPath->nDirection = (pDynamicPath->nDirection + pDynamicPath->nDiffDirection) & 63;

        const unsigned char dirDiff = (pDynamicPath->nDirection - pDynamicPath->nNewDirection) & 63;
        if ((dirDiff > 31 && pDynamicPath->nDiffDirection > 63) || (dirDiff < 31 && pDynamicPath->nDiffDirection < 63))
        {
            pDynamicPath->nDirection = pDynamicPath->nNewDirection;
        }
    }
}

// 0x006486F0
int __stdcall PATH_GetMaxVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwMaxVelocity;
}

// 0x00648720
int __stdcall PATH_GetAcceleration(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwAcceleration;
}

// 0x00648770
int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pDynamicPath)
{
    return (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00020);
}

// 0x006487C0
int __stdcall D2Common_10155(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwCurrentPointIdx;
}

// 0x00649180
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit)
{
    return pUnit->pDynamicPath->dwCollisionPattern;
}

// 0x00648750
extern "C" __declspec(dllexport) void __stdcall PATH_SetPathingFlag(Obj00648750* pObj, int bSet) {
    if (bSet) {
        pObj->dwFlags34 |= 0x20;
    } else {
        pObj->dwFlags34 &= ~0x20;
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00648460
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath)
{
    sub_0040B480(pMemPool, pDynamicPath, ".\\PATH\\Path.cpp", 985, 0);
}

// 0x00648480
static int PATH_GetMonsterMoveTestMask(D2UnitStrc* pUnit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? DATATBLS_GetMonStatsTxtRecordInl(pUnit->dwClassId) : 0;
    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_FLYING))
    {
        return COLLIDE_MASK_FLYING_UNIT;
    }
    return BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) ? COLLIDE_MASK_MONSTER_THAT_CAN_OPEN_DOORS : COLLIDE_MASK_MONSTER_PATH;
}

// 0x00648580
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize)
{
    if (nSize < 0 || nSize >= COLLISION_UNIT_SIZE_COUNT)
    {
        return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
    }

    int nCollisionPattern = gaCollisionPatternsFromSize[nSize];
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && MONSTERS_CanBeInTown(pUnit) && !MONSTERUNIQUE_CheckMonStatsFlag(pUnit->dwClassId, MONSTATSFLAGINDEX_INTERACT))
    {
        switch (nCollisionPattern)
        {
        case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
            break;
        case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
            break;
        }
    }

    return nCollisionPattern;
}

// 0x00649190
extern "C" void __stdcall PATH_SetUnitCollisionPattern(UnitView* unit,int collisionPattern)
{
    unit->path->collisionPattern = collisionPattern;
}

// 0x006485F0
void __fastcall PATH_SetNewDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection)
{
    nDirection &= 63;
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case 2:
    case 4:
        pDynamicPath->nDirection = nDirection;
        break;
    case 3:
        if (!(pDynamicPath->dwFlags & 0x40))
        {
            pDynamicPath->nDirection = nDirection;
        }
        break;
    default:
        if (nDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nDirection;
            const unsigned char nDiff = nDirection - pDynamicPath->nDirection;
// build: symbol ?gnDirectionDiffTable@* 0x006EB548
            pDynamicPath->nDiffDirection = gnDirectionDiffTable[nDiff & 63];
        }
        break;
    }
}

// 0x00648690
extern "C" __declspec(dllexport) void __stdcall PATH_SetVelocity(Obj00648690* pObj, int nValue, int nUnused3, int nUnused4) {
    if (pObj) {
        if (nValue != pObj->nValue7C) {
            pObj->nValue38 = 15;
        }
        pObj->nValue7C = nValue;
        pObj->nValue84 = nValue;
    }
}

extern "C" ActiveRoom* __fastcall DRLGACTIVATE_GetARoomInClientSight(DrlgView* drlg)
{
    RoomStatusNode* room = drlg->statusRooms[0].statusNext;
    if (room == &drlg->statusRooms[0] || !room)
    {
        room = drlg->statusRooms[1].statusNext;
        if (room == &drlg->statusRooms[1] || !room)
            return 0;
    }
    return room->activeRoom;
}

// 0x00649F50
void __stdcall D2Common_10228(D2UnitStrc* pUnit)
{
    if (pUnit->pDynamicPath)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
    }
}

// 0x0064A0E0
void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
}

// 0x006486C0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwVelocity;
}

// 0x006486D0
extern "C" __declspec(dllexport) void __stdcall PATH_SetMaxVelocity(Obj006486D0* pObj, unsigned int dwValue) {
    pObj->dwValue84 = dwValue;
}

// 0x00648700
extern "C" void __stdcall PATH_SetAcceleration(View_00648700* path, int value)
{
    path->acceleration = value;
}

// 0x00648730
extern "C" void __stdcall PATH_ClearPathingFlagAndPoints(PathView* path)
{
    path->flags &= 0xffffffdf;
    path->pointCount = 0x0;
}

// 0x00648780
extern "C" int __stdcall PATH_GetNumberOfPathPoints(View_00648780* path)
{
    return path->pointCount;
}

// 0x00648790
extern "C" __declspec(dllexport) void __stdcall PATH_SetNumberOfPathPoints(Obj00648790* pObj, int nValue) {
    if (nValue > 77) {
        nValue = 77;
    }
    pObj->nValue28 = nValue;
}

// 0x006487D0
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetPathPoints(Obj006487D0* pObj, unsigned int** ppOut) {
    *ppOut = &pObj->dwField9C;
    return pObj->dwValue28;
}

// 0x006487F0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->nDirection;
}

// 0x00648810
extern "C" __declspec(dllexport) unsigned char __stdcall PATH_GetNewDirection(Obj00648810* pObj) {
    return pObj->nValue65;
}

// 0x00648820
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char bDir)
{
    D2_ASSERT(bDir < PATH_NB_DIRECTIONS, 1650);

    const unsigned char nNormalizedDirection = bDir & (PATH_NB_DIRECTIONS - 1);
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = UNIT_TYPES_COUNT;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        pDynamicPath->nDirection = nNormalizedDirection;
        break;
    case UNIT_MISSILE:
        if (!(pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00040))
        {
            pDynamicPath->nDirection = nNormalizedDirection;
        }
        break;
    default:
        if (nNormalizedDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nNormalizedDirection;
            const unsigned char nDiff = nNormalizedDirection - pDynamicPath->nDirection;
            pDynamicPath->nDiffDirection = gnDirectionDiffTable[nDiff & (PATH_NB_DIRECTIONS - 1)];
        }
        break;
    }
}

// 0x006488A0
extern "C" __declspec(dllexport) void __stdcall sub_006488A0(Obj006488A0* pObj, unsigned char nValue) {
    if (pObj) {
        unsigned char nMasked = nValue & 0x3F;
        pObj->nValue64 = nMasked;
        pObj->nValue65 = nMasked;
    }
}

// 0x006488C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1682);

    return hPath->tGameCoords.wPosX;
}

// 0x00648900
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1693);

    return hPath->tGameCoords.wPosY;
}

// 0x00648940
int __stdcall PATH_GetPrecisionX(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1704);

    return hPath->tGameCoords.dwPrecisionX;
}

// 0x00648970
int __stdcall PATH_GetPrecisionY(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1715);

    return hPath->tGameCoords.dwPrecisionY;
}

// 0x006489A0
extern "C" void __stdcall PATH_SetPrecisionX(PathPrecisionView* path,U32 precisionX)
{
    path->precisionX = precisionX;
}

// 0x006489B0
void __stdcall PATH_SetPrecisionY(D2DynamicPathStrc* pDynamicPath, int nPrecisionY)
{
    pDynamicPath->tGameCoords.dwPrecisionY = nPrecisionY;
}

// 0x006489C0
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetClientCoordX(Obj006BCDE0* pObj) {
    return pObj->dwValue08;
}

// 0x006489D0
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetClientCoordY(Obj006489D0* pObj) {
    return pObj->dwValue0C;
}

// 0x006489E0
void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX)
{
    pPath->dwClientCoordX = nX;
}

// 0x006489F0
void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY)
{
    pPath->dwClientCoordY = nY;
}

// 0x00648A00
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.X;
}

// 0x00648A10
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.Y;
}

// 0x00648A20
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetFinalTargetX(Obj00648A20* pObj) {
    return pObj->wValue18;
}

extern "C" int __stdcall sub_006489C0_clientX(View_006489C0* path)
{
    return path->clientX;
}

// 0x00648A30
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetFinalTargetY(Obj00648A30* pObj) {
    return pObj->wValue1A;
}

// 0x00648A40
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetLastPointX(Obj00648A40* pObj) {
    int nIndex = pObj->nIndex28;
    if (nIndex) {
        return (&pObj->tEntries98 + nIndex)->wFirst;
    }
    return 0;
}

// 0x00648A60
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetLastPointY(Obj00648A60* pObj) {
    int nIndex = pObj->nIndex28;
    if (nIndex) {
        return (&pObj->tEntries98 + nIndex)->wSecond;
    }
    return 0;
}

// 0x00648A80
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetRoom(Obj00648A80* pObj) {
    return pObj->dwValue1C;
}

// 0x00648A90
void __stdcall PATH_SetRoom(D2DynamicPathStrc* pDynamicPath, D2ActiveRoomStrc* pRoom)
{
    pDynamicPath->pRoom = pRoom;
}

// build: symbol @DRLGACTIVATE_ToggleHasPortalFlag@* 0x0061BAC0
extern "C" void __fastcall DRLGACTIVATE_ToggleHasPortalFlag(RoomFlags* room, int reset)
{
    if (reset)
        room->flags &= ~0x400000U;
    else
        room->flags |= 0x400000U;
}

// 0x006497D0
static unsigned char PATH_AdvanceToDoor(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* hTarget = pPath->hTarget;

    D2_ASSERT(UnitIsDoor(hTarget), LINE_DOOR);

    if (UNITS_CheckIfObjectOrientationIs1(hTarget))
    {
        if (pPath->tGameCoords.wPosY < PATH_InlineGetUnitY(hTarget))
        {
            pPath->tTargetCoord.Y -= 2;
        }
        else
        {
            pPath->tTargetCoord.Y += 2;
        }
    }
    else
    {
        if (pPath->tGameCoords.wPosX < PATH_InlineGetUnitX(hTarget))
        {
            pPath->tTargetCoord.X -= 2;
        }
        else
        {
            pPath->tTargetCoord.X += 2;
        }
    }

    return 2;
}

// 0x00649970
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown)
{
    if (!pPath)
    {
        return 0;
    }

    D2_ASSERT(pPath->pUnit == pUnit, LINE_PATH_UNIT);

    if (pPath->dwFlags & PATH_MISSILE_MASK)
    {
        return PATH_MissileToTarget(pPath, pUnit);
    }

    pPath->nCollidedWithMask = 0;
    D2UnitStrc* pTargetUnit = pPath->hTarget;
    if (pTargetUnit && (!CLIENTS_GetUnitX(pTargetUnit) || !CLIENTS_GetUnitY(pTargetUnit)))
    {
        return 0;
    }

    D2PathInfoStrc tPathInfo;
    D2PathPointStrc tStart;
    tStart.X = pPath->tGameCoords.wPosX;
    tStart.Y = pPath->tGameCoords.wPosY;
    tPathInfo.tStartCoord = tStart;
    if (tStart.X != 0 || tStart.Y != 0)
    {
        tPathInfo.nUnitSize = pPath->dwUnitSize;
        tPathInfo.nCollisionPattern = pPath->dwCollisionPattern;
        tPathInfo.pDynamicPath = pPath;
        tPathInfo.nCollisionMask = pPath->nMoveTestCollisionMask;
        tPathInfo.nDistMax = pPath->bDistMax;
        tPathInfo.nMinimumFScoreToEvaluate = pPath->nIDAStarInitFScore;
        tPathInfo.field_14 = PATH_UpdateTargetUnit(&tPathInfo);

        if (pPath->tTargetCoord.X != 0 || pPath->tTargetCoord.Y != 0)
        {
            tPathInfo.tTargetCoord = pPath->tTargetCoord;
            if (tPathInfo.tStartCoord.X != tPathInfo.tTargetCoord.X || tPathInfo.tStartCoord.Y != tPathInfo.tTargetCoord.Y)
            {
                const int nDeltaX = tPathInfo.tTargetCoord.X - tPathInfo.tStartCoord.X;
                const int nDeltaY = tPathInfo.tTargetCoord.Y - tPathInfo.tStartCoord.Y;
                if (nDeltaX <= PATH_MAX_DISTANCE && -nDeltaX <= PATH_MAX_DISTANCE && nDeltaY <= PATH_MAX_DISTANCE && -nDeltaY <= PATH_MAX_DISTANCE)
                {
                    tPathInfo.pStartRoom = pPath->pRoom;
                    tPathInfo.pTargetRoom = sub_00463740_FindRoomAtPoint(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y);
                    if (tPathInfo.pStartRoom && tPathInfo.pTargetRoom && (PATH_IsTargetDestinationAllowed(&tPathInfo, pUnit) || bAllowInTown))
                    {
                        tPathInfo.nPathType = pPath->eType;

                        D2UnitStrc* pPathTargetUnit = pPath->hTarget;
                        BOOL bRemovedTargetUnitFootprint = FALSE;
                        PATH_RemoveCollisionFootprintForUnit(pUnit, FALSE);
                        if (pPathTargetUnit && UNITS_GetUnitSizeX(pPathTargetUnit) && (pPath->dwFlags & PATH_UNKNOWN_FLAG_0x00800))
                        {
                            bRemovedTargetUnitFootprint = PATH_RemoveCollisionFootprintForUnit(pPathTargetUnit, FALSE);
                        }

                        BOOL bUpdatePath = PATH_TRUE;
                        if ((pPath->dwFlags & PATH_UNKNOWN_FLAG_0x01000)
                            && COLLISION_CheckAnyCollisionWithPattern(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y, pPath->dwCollisionPattern, pPath->nMoveTestCollisionMask))
                        {
                            bUpdatePath = PATH_PreparePathTargetForPathUpdate(&tPathInfo);
                        }

                        pPath->tFinalTargetCoord.X = tPathInfo.tTargetCoord.X;
                        pPath->dwCurrentPointIdx = 0;
                        pPath->tFinalTargetCoord.Y = tPathInfo.tTargetCoord.Y;
                        pPath->dwPathPoints = 0;

                        int nPathPoints;
                        if (bUpdatePath)
                        {
                            pPath->dwCurrentPointIdx = 0;
                            D2_ASSERT(!IsBadCodePtr((void*)gpfnPathFunctions[tPathInfo.nPathType]), LINE_PATH_FUNCTION);
                            nPathPoints = gpfnPathFunctions[tPathInfo.nPathType](&tPathInfo);
                        }
                        else
                        {
                            pPath->dwCurrentPointIdx = 0;
                            nPathPoints = 0;
                        }
                        pPath->dwPathPoints = nPathPoints;

                        D2_ASSERT(tPathInfo.tStartCoord.X == tStart.X && tPathInfo.tStartCoord.Y == tStart.Y, LINE_START_COORD);

                        if (bRemovedTargetUnitFootprint)
                        {
                            PATH_AddCollisionFootprintForUnit(pPath->hTarget);
                        }
                        PATH_AddCollisionFootprintForUnit(pUnit);

                        if (!pPath->dwPathPoints)
                        {
                            pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
                            return 0;
                        }

                        PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_TRUE, PATH_TRUE);
                        if (pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                        {
                            sub_6FDA8220(pPath);
                            pPath->unk0x38 = 0;
                            pPath->tPrevTargetCoord.X = pPath->tTargetCoord.X;
                            pPath->tPrevTargetCoord.Y = pPath->tTargetCoord.Y;
                            const unsigned int nFlags = pPath->dwFlags;
                            if (!(nFlags & PATH_UNKNOWN_FLAG_0x00010) && !pPath->hTarget)
                            {
                                pPath->tTargetCoord.X = pPath->PathPoints[pPath->dwPathPoints - 1].X;
                                pPath->tTargetCoord.Y = pPath->PathPoints[pPath->dwPathPoints - 1].Y;
                            }

                            if (pPath->dwPathPoints)
                            {
                                pPath->dwFlags = nFlags | PATH_UNKNOWN_FLAG_0x00020;
                            }
                            else
                            {
                                pPath->dwFlags = nFlags & ~PATH_UNKNOWN_FLAG_0x00020;
                            }
                            return pPath->dwPathPoints;
                        }
                    }
                }
            }
        }
    }

    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
    return 0;
}

// 0x00649CA0
void __stdcall D2Common_10214(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (pDynamicPath)
    {
        if (UNITS_GetRoom(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            pUnit->pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);
            PATH_AddCollisionFootprintForUnit(pUnit);
        }
        else
        {
            pUnit->pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);
        }
    }
}

// 0x00649F70
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, BOOL bForGameLogic)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (bForGameLogic || pUnit->dwUnitType != UNIT_MONSTER)
    {
        D2Common_10228(pUnit);
        COLLISION_SetMaskWithSizeXY(pPath->pRoom, pPath->wPosX, pPath->wPosY, PATH_CORPSE_SIZE, PATH_CORPSE_SIZE, COLLIDE_CORPSE);
    }
    else
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
        PATH_SetFootprintCollisionMask(pPath, COLLIDE_CORPSE);
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
    PATH_RecacheRoomIfNeeded(pPath);
}

// 0x00648AA0
extern "C" Room* __stdcall PATH_GetNextRoom(View_00648AA0* path)
{
    return path->previousRoom;
}

// 0x00648AB0
extern "C" __declspec(dllexport) void __stdcall PATH_ClearNextRoom(Obj00648AB0* pObj) {
    pObj->dwValue20 = 0;
}

// 0x00648AD0
extern "C" __declspec(dllexport) void __stdcall PATH_SetTargetPos(Obj00648AD0* pObj, unsigned short wA, unsigned short wB) {
    if (pObj) {
        pObj->wValue10 = wA;
        pObj->wValue12 = wB;
        pObj->dwValue58 = 0;
    }
}

// 0x00648B00
void __stdcall PATH_SetTargetCoordFromClient(D2DynamicPathStrc* pDynamicPath, int nX, int nY)
{
    DUNGEON_ClientToGameCoords(&nX, &nY);
    nX >>= 11;
    nY >>= 11;
    pDynamicPath->tTargetCoord.X = nX;
    pDynamicPath->tTargetCoord.Y = nY;
}

// 0x00648B30
int __stdcall PATH_IsCurrentRoomInvalid(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwFlags & PATH_CURRENT_ROOM_INVALID;
}

// 0x00648B40
extern "C" void __stdcall PATH_SetCurrentRoomInvalid(PathFlags* path, int invalid)
{
    if (invalid != 0)
        path->flags |= 2U;
    else
        path->flags &= ~2U;
}

// 0x00648B60
void __stdcall PATH_SetUnusedFlag_0x00004(D2DynamicPathStrc* pDynamicPath, int bSet)
{
    if (bSet)
    {
        pDynamicPath->dwFlags |= PATH_UNUSED_FLAG_0x00004;
    }
    else
    {
        pDynamicPath->dwFlags &= ~PATH_UNUSED_FLAG_0x00004;
    }
}

// 0x00648B80
int __stdcall PATH_GetUnusedFlag_0x00004(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwFlags & PATH_UNUSED_FLAG_0x00004;
}

// 0x00648B90
extern "C" void __stdcall PATH_SetPathTarget(B25Path* path, B25TargetUnit* target)
{
    path->target = target;
    if (target)
    {
        path->targetType = target->type;
        path->targetId = target->id;
    }
}

// 0x00648BB0
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* ptPath, int* pTargetType, int* pTargetGUID)
{
    D2_ASSERT(ptPath->hTarget, 1984);

    *pTargetType = ptPath->dwTargetType;
    *pTargetGUID = ptPath->dwTargetId;
}

// 0x00648BF0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->hTarget;
}

// 0x00648C10
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetFootprintCollisionMaskExported(Obj00648C10* pObj) {
    if (!pObj) {
        return 0xFFFF;
    }
    return pObj->dwValue4C;
}

// 0x00648C30
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask)
{
    D2PathPointStrc tPosition;
    tPosition.X = pDynamicPath->tGameCoords.wPosX;
    tPosition.Y = pDynamicPath->tGameCoords.wPosY;

    if (pDynamicPath->pRoom)
    {
        if (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MISSILE)
        {
            COLLISION_ResetMaskWithSize(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwUnitSize, pDynamicPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_ResetMaskWithPattern(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwCollisionPattern, pDynamicPath->nFootprintCollisionMask);
        }
    }

    pDynamicPath->nFootprintCollisionMask = nCollisionMask;

    if (pDynamicPath->pRoom)
    {
        if (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MISSILE)
        {
            COLLISION_SetMaskWithSize(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwUnitSize, nCollisionMask);
        }
        else
        {
            COLLISION_SetMaskWithPattern(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwCollisionPattern, nCollisionMask);
        }
    }
}

// 0x00648CD0
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetMoveTestCollisionMask(Obj00648CD0* pObj) {
    return pObj->dwValue50;
}

// 0x00648CE0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask)
{
    pDynamicPath->nMoveTestCollisionMask = nCollisionMask;
}

// 0x00648DC0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath->pUnit, 2174);

    if (pDynamicPath->dwFlags & PATH_WITH_PREVIOUS_VELOCITY)
    {
        pDynamicPath->dwVelocity = pDynamicPath->nPreviousVelocity;
    }

    if (pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER)
    {
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
    }
    else if (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x02000)
    {
        PATH_SetType(pDynamicPath, pDynamicPath->ePrevType);
    }
}

// 0x00648E30
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->eType;
}

// 0x00648E40
void __stdcall PATH_SetDist(D2Record00648E40Strc* pRecord, unsigned char nValue)
{
    pRecord->nValue90 = nValue;
}

// 0x00648E60
unsigned char __stdcall D2COMMON_10191_PATH_GetDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nDist;
}

// 0x00648E70
extern "C" void __stdcall PATH_SetNewDistance(B25DistancePath* path, U8 distance)
{
    if (path)
    {
        if (distance >= 0x4D)
            distance = 0x4D;
        path->newDistance = distance;
        path->distance = distance;
    }
}

// 0x00648EA0
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->bDistMax;
}

// 0x00648EB0
extern "C" U16 __stdcall PATH_GetCollidedWithMask(PathCollisionView* path)
{
    if (path->velocity == 0)
        path->collidedMask = COLLISION_CheckMaskWithSize(path->room,path->positionX,path->positionY,path->f_44,0x7FFF);
    return path->collidedMask;
}

// 0x00648EF0
unsigned short __stdcall D2Common_10202(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nCollidedWithMask;
}

// 0x00648F00
void __stdcall PATH_SetIDAStarInitFScore(D2DynamicPathStrc* ptPath, int nIDAStarInitFScore)
{
    D2_ASSERT(ptPath->eType == PATHTYPE_IDASTAR, 2280);

    ptPath->nIDAStarInitFScore = nIDAStarInitFScore;
}

// 0x00648F40
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* ptPath, D2PathPointStrc** ppPathPoints)
{
    D2_ASSERT(ptPath->dwFlags & PATH_SAVE_STEPS_MASK, 2292);

    *ppPathPoints = ptPath->SavedSteps;
    return ptPath->nSavedStepsCount;
}

// 0x00648F90
int __stdcall D2COMMON_10199_PathGetSaveX(D2DynamicPathStrc* ptPath)
{
    D2_ASSERT(ptPath->dwFlags & PATH_SAVE_STEPS_MASK, 2306);

    if (ptPath->nSavedStepsCount)
    {
        return ptPath->SavedSteps[ptPath->nSavedStepsCount - 1].X;
    }

    return 0;
}

// 0x00648FE0
int __stdcall D2COMMON_10200_PathGetSaveY(D2DynamicPathStrc* ptPath)
{
    D2_ASSERT(ptPath->dwFlags & PATH_SAVE_STEPS_MASK, 2321);

    if (ptPath->nSavedStepsCount)
    {
        return ptPath->SavedSteps[ptPath->nSavedStepsCount - 1].Y;
    }

    return 0;
}

// 0x00649030
void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pDynamicPath, int bReset)
{
    if (pDynamicPath)
    {
        if (!bReset)
        {
            pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00040;
        }
        else
        {
            pDynamicPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00040;
        }
    }
}

// 0x00649050
extern "C" void __stdcall PATH_ClearPreviousTargetPoint(PathPreviousView* path)
{
    path->previousTargetX = 0;
    path->previousTargetY = 0;
}

// 0x00649070
extern "C" __declspec(dllexport) void __stdcall PATH_SetStepNum(Obj00649070* pObj, unsigned char nValue) {
    if (pObj) {
        if (nValue >= 1 && nValue <= 19) {
            pObj->nValue93 = nValue - 1;
        } else {
            pObj->nValue93 = 0;
        }
    }
}

// 0x006490A0
extern "C" __declspec(dllexport) int __stdcall PATH_GetStepNum(Obj006490A0* pObj) {
    return pObj->bValue93 + 1;
}

// 0x006490C0
void __stdcall D2Common_10207(D2DynamicPathStrc* pDynamicPath, char a2, char dwSpeed)
{
    pDynamicPath->unk0x67 = a2;
    pDynamicPath->dwSpeed = dwSpeed;
}

// 0x006490E0
void __stdcall PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, int nDist)
{
    D2_ASSERT(nDist >= 0 && nDist <= 255, 2405);

    pDynamicPath->nDistance = nDist;
}

// 0x00649120
extern "C" __declspec(dllexport) unsigned int __stdcall PATH_GetDistance(Obj00649120* pObj) {
    return pObj->bValue94;
}

inline int __fastcall UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int __fastcall UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00649400
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    switch (nType)
    {
    case 0:
    case 1:
    {
        const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
        COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
        break;
    }

    case 2:
        COLLISION_SetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
        break;

    default:
        COLLISION_SetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        break;
    }
}

// 0x00649560
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
        if ((pUnit && pUnit->dwAnimMode != 17 && pUnit->dwAnimMode != 0) || bForce)
        {
ResetPattern:
            const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
            COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    case 1:
        if ((pUnit && pUnit->dwAnimMode != 12 && pUnit->dwAnimMode != 0) || bForce)
        {
            goto ResetPattern;
        }
        break;

    case 2:
        if (UNITS_HasCollision(pUnit) || bForce)
        {
            COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    default:
        COLLISION_ResetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        return 1;
    }

    return 0;
}

// 0x00649760
static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit)
{
    switch (pPath->eType)
    {
    case 4:
        if (PATH_ComputePathClassicMissile(pPath))
        {
            pPath->dwFlags |= 0x20;
            return pPath->dwPathPoints;
        }
        pPath->dwFlags &= ~0x20;
        return 0;
    case 10:
        PATH_ComputePathChargedBolt_6FDAB4A0(pPath, &pUnit->pSeed);
        pPath->dwFlags |= 0x20;
        return pPath->dwPathPoints;
    case 14:
        PATH_ComputePathBlessedHammer_6FDAB3C0(pPath, &pUnit->pSeed);
        pPath->dwFlags |= 0x20;
        return pPath->dwPathPoints;
    default:
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x207);
        exit(-1);
    }
}

// 0x006498A0
static unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* pPathTargetUnit = pPath->hTarget;
    if (pPathTargetUnit)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPathTargetUnit);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPathTargetUnit);

        if (pPath->tTargetCoord.X == 0 && pPath->tTargetCoord.Y == 0)
        {
            return 0;
        }

        switch (pPathTargetUnit->dwUnitType)
        {
        case UNIT_ITEM:
            return 2;

        case UNIT_OBJECT:
            if (!UnitIsDoor(pPathTargetUnit))
            {
                return 2;
            }
            return PATH_AdvanceToDoor(pPathInfo);

        case UNIT_PLAYER:
        case UNIT_MONSTER:
            if (pPath->dwSpeed)
            {
                PATHUtil_AdvanceTowardsTarget_6FDAB890(pPath);
            }
            return 1;

        default:
            return 1;
        }
    }
    return 1;
}

// 0x00649140
void __stdcall PATH_AddToDistance(D2DynamicPathStrc* pDynamicPath, int nAddition)
{
    const int nDistance = pDynamicPath->nDistance + nAddition;
    if (nDistance < 0)
    {
        pDynamicPath->nDistance = 0;
    }
    else if (nDistance > 255)
    {
        pDynamicPath->nDistance = 255;
    }
    else
    {
        pDynamicPath->nDistance = nDistance;
    }
}

// 0x006491B0
void __stdcall D2COMMON_10212_PATH_SetMoveFlags(D2UnitStrc* pUnit, int bSet)
{
    D2DynamicPathStrc* ptPath = pUnit->pDynamicPath;

    D2_ASSERT(ptPath, 2466);

    if (bSet)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_UNK_PATH_RELATED;
    }
    else
    {
        pUnit->dwFlagEx &= ~UNITFLAGEX_UNK_PATH_RELATED;
    }
    ptPath->unk0x38 = 0;
}

// 0x00649210
void __stdcall D2Common_10213(D2UnitStrc* pUnit)
{
    if (pUnit && !UNIT_HasFlag(pUnit, UNITFLAG_ISASYNC) && UNIT_HasFlagEx(pUnit, UNITFLAGEX_UNK_PATH_RELATED))
    {
        D2DynamicPathStrc* ptPath = pUnit->pDynamicPath;
        D2_ASSERT(ptPath, 2485);

        ++ptPath->unk0x38;
        if ((int)ptPath->unk0x38 > 1)
        {
            ptPath->unk0x38 = 0;
            if (!D2Common_10227(pUnit))
            {
                if (D2Common_10236(pUnit, PATH_GetTargetUnit(pUnit->pDynamicPath) != 0))
                {
                    UNITS_ChangeAnimMode(pUnit, 2);
                }
            }
        }
    }
}

inline unsigned int PATH_ToFP16Center(int nValue)
{
    return (nValue << 16) + 0x8000;
}

// 0x00649D00
void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag)
{
    D2DynamicPathStrc* pDynamicPath = (D2DynamicPathStrc*)FOG_AllocPool(pMemPool, sizeof(D2DynamicPathStrc), ".\\PATH\\Path.cpp", 1107, 0);
    memset(pDynamicPath, 0, sizeof(D2DynamicPathStrc));

    pUnit->pDynamicPath = pDynamicPath;
    pDynamicPath->pUnit = pUnit;
    pDynamicPath->dwUnitSize = UNITS_GetUnitSizeX(pUnit);
    pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);

    pDynamicPath->dwPrecisionX = PATH_ToFP16Center(nX);
    pDynamicPath->dwPrecisionY = PATH_ToFP16Center(nY);
    pDynamicPath->dwVelocity = 2048;
    pDynamicPath->pRoom = pRoom;
    pDynamicPath->nStepNum = 0;
    pDynamicPath->nSavedStepsCount = 1;
    pDynamicPath->SavedSteps[0].X = nX;
    pDynamicPath->SavedSteps[0].Y = nY;

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        pDynamicPath->nFootprintCollisionMask = COLLIDE_PLAYER;
        pDynamicPath->nMoveTestCollisionMask = COLLIDE_MASK_PLAYER_PATH;
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
        pDynamicPath->bDistMax = 73;
        pDynamicPath->nIDAStarInitFScore = 70;
        break;

    case UNIT_MONSTER:
    {
        pDynamicPath->nFootprintCollisionMask = COLLIDE_MONSTER;

        D2_ASSERT(!(pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER), 2145);
        pDynamicPath->dwFlags &= 0xFFF800FF;
        pDynamicPath->eType = PATHTYPE_TOWARD;
        pDynamicPath->nDirOffset = 0;
        D2_ASSERT(pDynamicPath->ePrevType != PATHTYPE_KNOCKBACK_CLIENT, 2161);
        D2_ASSERT(pDynamicPath->ePrevType != PATHTYPE_KNOCKBACK_SERVER, 2162);

// build: symbol ?CUNIT_GetMonsterBaseId@* 0x00463860
        const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            switch (nBaseId)
            {
            case MONSTER_WRAITH1:
                pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
                pDynamicPath->nMoveTestCollisionMask = COLLIDE_MISSILE_BARRIER | COLLIDE_DOOR;
                pDynamicPath->bDistMax = 14;
                break;

            default:
                pDynamicPath->nMoveTestCollisionMask = PATH_GetMonsterMoveTestMask(pUnit);
                pDynamicPath->bDistMax = 14;
                break;
            }
        }
        else
        {
            pDynamicPath->nMoveTestCollisionMask = PATH_GetMonsterMoveTestMask(pUnit);
            pDynamicPath->bDistMax = 14;
        }
        break;
    }

    case UNIT_MISSILE:
        pDynamicPath->nFootprintCollisionMask = 0;
        pDynamicPath->nMoveTestCollisionMask = 0;
        PATH_SetType(pDynamicPath, PATHTYPE_MISSILE);
        break;
    }

    if (pRoom)
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
        UNITROOM_AddUnitToRoom(pUnit, pDynamicPath->pRoom);
    }

    int nClientX = pDynamicPath->dwPrecisionX >> 11;
    int nClientY = pDynamicPath->dwPrecisionY >> 11;
    DUNGEON_GameToClientCoords(&nClientX, &nClientY);
    pDynamicPath->dwClientCoordX = nClientX;
    pDynamicPath->dwClientCoordY = nClientY;

    if (bSetFlag)
    {
        pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00010;
    }
}

// 0x00649EF0
void __stdcall D2Common_10216(D2DynamicPathStrc* pDynamicPath, int nX, int nY, int bSetBothDirections)
{
    if (pDynamicPath)
    {
        D2FP32_16 tTarget;
        tTarget.dwPrecisionX = (nX << 16) + 0x8000;
        tTarget.dwPrecisionY = (nY << 16) + 0x8000;
        const int nDirection = PATH_ComputeDirectionFromPreciseCoords_6FDAC760(pDynamicPath->tGameCoords, tTarget);
        if (bSetBothDirections)
        {
            pDynamicPath->nDirection = nDirection & 0x3F;
            pDynamicPath->nNewDirection = nDirection & 0x3F;
        }
        else
        {
            PATH_SetNewDirection(pDynamicPath, nDirection);
        }
    }
}

// 0x00648CF0
void __stdcall PATH_SetType(D2DynamicPathStrc* ptPath, int eType)
{
    D2_ASSERT(!(ptPath->pUnit && ptPath->pUnit->dwUnitType == UNIT_PLAYER && eType == 2), 0x861);

    int nFlag = gaPathTypeFlags[eType];
    if ((nFlag & 0x2000) && !(ptPath->dwFlags & 0x4000))
    {
        ptPath->ePrevType = ptPath->eType;
    }

    if ((nFlag & 0x8000) && !(ptPath->dwFlags & 0x10000))
    {
        ptPath->nPreviousVelocity = ptPath->dwVelocity;
    }

    ptPath->eType = eType;
    ptPath->dwFlags = nFlag | ptPath->dwFlags & 0xFFF800FF;
    ptPath->nDirOffset = gaOffsetForPathType[eType];

    D2_ASSERT(ptPath->ePrevType != 0xB, 0x871);
    D2_ASSERT(ptPath->ePrevType != 8, 0x872);
    D2_ASSERT((eType != 4) || (ptPath->bDistMax < 78), 0x873);
}

int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0xFFFF;
    }

    return pDynamicPath->nFootprintCollisionMask;
}

static __forceinline int sub_00649FF0_GetCollisionPattern(D2UnitStrc* pUnit)
{
    int nPattern = D2Common_11281_CollisionPatternFromSize(pUnit, UNITS_GetUnitSizeX(pUnit));
    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        switch (nBaseId)
        {
        case MONSTER_WRAITH1:
        case MONSTER_BIRD1:
        case MONSTER_BIRD2:
        case MONSTER_PARROT:
            nPattern = 5;
            break;
        }
    }
    return nPattern;
}

// 0x00649FF0
void __stdcall PATH_SetUnitAliveCollision(D2UnitStrc* pUnit, int bSkip)
{
    if (bSkip)
    {
        return;
    }

    int nValue = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nValue == UNIT_MONSTER, 1346);

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (PATH_GetFootprintCollisionMask(pDynamicPath) == 0x8000)
    {
        nValue = sub_00649FF0_GetCollisionPattern(pUnit);
        if (UNITS_GetRoom(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            pUnit->pDynamicPath->dwCollisionPattern = nValue;
            PATH_SetFootprintCollisionMask(pDynamicPath, 0x100);
            PATH_AddCollisionFootprintForUnit(pUnit);
        }
        else
        {
            pUnit->pDynamicPath->dwCollisionPattern = nValue;
            PATH_SetFootprintCollisionMask(pDynamicPath, 0x100);
        }
    }
}

// 0x006492A0
extern "C" __declspec(dllexport) int __stdcall sub_006492A0(int nX1, int nY1, int nX2, int nY2) {
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    return nDX * nDX + nDY * nDY;
}

// 0x006492C0
int __stdcall D2Common_10237(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->dwCurrentPointIdx < pDynamicPath->dwPathPoints;
}

// build: symbol _FOG_GetLinkIndexByCode@* 0x006BD130
extern "C" int __stdcall FOG_GetLinkIndexByCode(LinkView* link, U32 key, int unusedLogError)
{
    int upper = link->count;
    int lower = 0;
    KeyValue* entries = link->entries;
    while (lower < upper)
    {
        int middle = lower + (upper - lower) / 2;
        U32 current = entries[middle].key;
        if (key > current)
            lower = middle + 1;
        else if (key < current)
            upper = middle;
        else
            return entries[middle].value;
    }
    return -1;
}

// 0x006492F0
static int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tOldCoords;
    tOldCoords.X = pPath->tGameCoords.wPosX;
    tOldCoords.Y = pPath->tGameCoords.wPosY;

    pPath->dwCurrentPointIdx = 0;

    if (pPath->hTarget)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPath->hTarget);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPath->hTarget);
    }

    int nXDistance = tOldCoords.X - pPath->tTargetCoord.X;
    if (nXDistance < 0)
    {
        nXDistance = -nXDistance;
    }
    if (nXDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    int nYDistance = tOldCoords.Y - pPath->tTargetCoord.Y;
    if (nYDistance < 0)
    {
        nYDistance = -nYDistance;
    }
    if (nYDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    if (!pPath->tTargetCoord.X || !pPath->tTargetCoord.Y)
    {
        return 0;
    }

    pPath->PathPoints[0] = pPath->tTargetCoord;
    pPath->dwPathPoints = PATH_ONE;
    pPath->unk0x38 = 0;
    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_ONE, PATH_ONE);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    if (!pRoom
        || !(pPath->tTargetCoord.X >= pRoom->tCoords.nSubtileX && pPath->tTargetCoord.X < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
            && pPath->tTargetCoord.Y >= pRoom->tCoords.nSubtileY && pPath->tTargetCoord.Y < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight))
    {
        pPath->dwFlags |= PATH_ONE;
    }
    return pPath->dwPathPoints;
}

// 0x0066A280
void __fastcall D2COMMON_10916_Return()
{
}

#include "gen/data/Source/D2Common/PATH/Path.inc"
