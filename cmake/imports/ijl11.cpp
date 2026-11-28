// Import stub for ijl11.dll, which ships with Diablo II 1.14d: it only gives the linker an import library.
// Never shipped; the game folder has the real DLL.

extern "C" __declspec(dllexport) int __stdcall ijlFree(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall ijlInit(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall ijlWrite(int, int) { return 0; }
