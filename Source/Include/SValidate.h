#pragma once
// Storm's argument validation. Every test is collected in nValid; the release build also assumes each one holds,
// so a test the optimizer could otherwise prove redundant is still made.
// The caller declares sub_0041C340_SetLastError (Storm.h does).

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0; __assume(x)
#define VALIDATEKEEP(x) nValid = (x) ? nValid : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }
