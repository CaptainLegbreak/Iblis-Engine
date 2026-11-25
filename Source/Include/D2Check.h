// Layout checks for the shared structs: a wrong size or offset makes the array size negative and stops the compile.
#pragma once

#define D2_CHECK_SIZE(T, n) typedef char D2SizeCheck_##T[(sizeof(T) == (n)) ? 1 : -1]
#define D2_CHECK_OFFSET(T, m, n) typedef char D2OffsetCheck_##T##_##m[((unsigned int)&((T*)0)->m == (n)) ? 1 : -1]
