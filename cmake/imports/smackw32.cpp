// Import stub for smackw32.dll, which ships with Diablo II 1.14d: it only gives the linker an import library.
// Never shipped; the game folder has the real DLL.

extern "C" __declspec(dllexport) int __stdcall SmackClose(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall SmackDoFrame(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall SmackNextFrame(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall SmackOpen(int, int, int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall SmackToBuffer(int, int, int, int, int, int, int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall SmackWait(int) { return 0; }
