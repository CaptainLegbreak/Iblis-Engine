# Iblis Engine: the game as one Windows program.
#
#   cmake -G "Visual Studio 17 2022" -A Win32 -S . -B build
#   cmake --build build --config Release
#
# Needs Visual Studio 2022 (v143) for 32-bit x86, and nothing else: no game files, no Iblis Codex.
# State of the port: docs/PORT_COMPILE.md (compiling) and docs/PORT_LINK.md (linking).
cmake_minimum_required(VERSION 3.21)
project(IblisEngine C CXX)

option(IBLIS_TESTS "Build the engine's tests" OFF)

if(NOT MSVC OR NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "Iblis Engine builds with 32-bit MSVC for now (Visual Studio 2022, -A Win32).")
endif()

# The static runtime, as the original links it.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# Each game source file carries its original optimiser options (cmake/Sources.cmake); CMake's per-configuration
# defaults would override them.
foreach(_lang C CXX)
  foreach(_cfg RELEASE RELWITHDEBINFO MINSIZEREL)
    set(CMAKE_${_lang}_FLAGS_${_cfg} "")
  endforeach()
endforeach()

# What the game's 2005 code needs from a current compiler: every switch that makes v143 treat the code the way
# Visual C++ 2005 did, in one place.
set(IBLIS_MSVC2005_COMPAT
  /arch:IA32               # x87 floating point, as the original (no SSE2 code generation)
  /permissive              # 2005's lookup and conversion rules
  /Zc:threadSafeInit-      # function-local statics initialised without the thread-safe guard 2005 didn't have
  /Zc:sizedDealloc-        # no sized operator delete, which 2005 didn't have
  /Zc:wchar_t              # wchar_t a type of its own, as in 2005's default
  /Zc:forScope             # for-loop variables scoped to the loop (2005's default)
)

# Options every game source file shares, besides its own.
set(IBLIS_COMMON_OPTIONS ${IBLIS_MSVC2005_COMPAT} /Z7 /W1 /bigobj)
set(IBLIS_COMMON_DEFINITIONS _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE)

include(cmake/Sources.cmake)

# Engine-only code in the original module folders: not from the original build.
list(APPEND IBLIS_Storm_SOURCES
  Source/Storm/pklib/explode.cpp
  Source/Storm/pklib/implode.cpp
  Source/Storm/pklib/tables.cpp
  Source/Storm/pklib/codex_names.cpp
)
set_source_files_properties(Source/Storm/pklib/explode.cpp Source/Storm/pklib/implode.cpp
  Source/Storm/pklib/tables.cpp Source/Storm/pklib/codex_names.cpp PROPERTIES COMPILE_OPTIONS "/O2;/GS-")

# One static library per original module folder, and the program from Source/Main. Bare-name headers resolve in
# the file's own module folder first, then in Source/Include.
foreach(_module IN LISTS IBLIS_MODULES)
  if(_module STREQUAL "Main")
    continue()
  endif()
  add_library(${_module} STATIC ${IBLIS_${_module}_SOURCES})
  target_compile_options(${_module} PRIVATE ${IBLIS_COMMON_OPTIONS})
  target_compile_definitions(${_module} PRIVATE ${IBLIS_COMMON_DEFINITIONS})
  target_include_directories(${_module} PRIVATE Source/${_module} Source/Include .)
  list(APPEND IBLIS_LIBRARIES ${_module})
endforeach()

add_executable(Game WIN32 ${IBLIS_Main_SOURCES} Source/Main/link_aliases.cpp Source/Main/res/Game.rc)
target_compile_options(Game PRIVATE ${IBLIS_COMMON_OPTIONS})
target_compile_definitions(Game PRIVATE ${IBLIS_COMMON_DEFINITIONS})
target_include_directories(Game PRIVATE Source/Main Source/Include .)
target_link_libraries(Game PRIVATE ${IBLIS_LIBRARIES})
# Every object of every module goes into the program, as in the original link (a static library would otherwise
# leave out objects nothing names, with their static constructors).
foreach(_lib IN LISTS IBLIS_LIBRARIES)
  target_link_options(Game PRIVATE "/WHOLEARCHIVE:${_lib}.lib")
endforeach()

# Import libraries for the video and JPEG DLLs that ship with the game (Bink, Smacker, Intel JPEG Library), built
# from stubs that only name their exports, into their own folder so they never sit next to Game.exe.
foreach(_dll binkw32 smackw32 ijl11)
  set(_stub cmake/imports/${_dll}.cpp)
  if(EXISTS "${CMAKE_SOURCE_DIR}/cmake/imports/${_dll}.def")
    list(APPEND _stub cmake/imports/${_dll}.def)
  endif()
  add_library(${_dll}_import SHARED ${_stub})
  set_target_properties(${_dll}_import PROPERTIES OUTPUT_NAME ${_dll}
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/import-stubs"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/import-stubs")
  target_link_libraries(Game PRIVATE ${_dll}_import)
endforeach()

target_link_options(Game PRIVATE /SAFESEH:NO /LARGEADDRESSAWARE /MANIFEST:NO)
target_link_libraries(Game PRIVATE kernel32 user32 gdi32 advapi32 shell32 ole32 oleaut32 comctl32 comdlg32
  winmm wsock32 ws2_32 version imm32 ddraw dsound dxguid psapi crypt32 legacy_stdio_definitions)

if(IBLIS_TESTS)
  add_executable(pklib_test tests/pklib_test.cpp Source/Storm/pklib/explode.cpp Source/Storm/pklib/implode.cpp
    Source/Storm/pklib/tables.cpp)
  target_compile_options(pklib_test PRIVATE /EHsc)
endif()
