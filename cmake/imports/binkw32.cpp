// Import stub for binkw32.dll, which ships with Diablo II 1.14d: it only gives the linker an import library.
// Never shipped; the game folder has the real DLL.

extern "C" __declspec(dllexport) int __stdcall BinkClose(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkCopyToBuffer(int, int, int, int, int, int, int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkDDSurfaceType(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkDoFrame(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkNextFrame(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkOpen(int, int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkOpenDirectSound(int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkSetSoundSystem(int, int) { return 0; }
extern "C" __declspec(dllexport) int __stdcall BinkWait(int) { return 0; }
