# Compiles every source file into an object with the compiler options recorded in build/units.json.
#
# This is the ordinary project view of the sources: it builds the objects, nothing more. It does not check
# the objects against Game.exe and does not link them; tools/build.py links them at the original addresses into
# the byte-identical Game.exe, and tools/link.py links them as an ordinary program (see README, "Building").
#
# Use the Visual C++ 2005 SP1 compiler (cl 14.00.50727.762) from its command prompt, run tools/setup.py first
# (the sources include generated data from gen/), then:
#
#   cmake -G "NMake Makefiles" -S . -B out/cmake
#   cmake --build out/cmake
cmake_minimum_required(VERSION 3.19)
project(IblisCodex CXX)

file(READ "${CMAKE_SOURCE_DIR}/build/config.json" _config)
file(READ "${CMAKE_SOURCE_DIR}/build/units.json" _units)

string(JSON _nbase LENGTH "${_config}" flags)
math(EXPR _last "${_nbase} - 1")
set(_base_flags "")
foreach(_i RANGE ${_last})
  string(JSON _f GET "${_config}" flags ${_i})
  if(NOT _f STREQUAL "/c" AND NOT _f STREQUAL "/nologo")
    list(APPEND _base_flags "${_f}")
  endif()
endforeach()

set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_BUILD_TYPE "")

string(JSON _n LENGTH "${_units}" units)
math(EXPR _last "${_n} - 1")
set(_sources "")
foreach(_i RANGE ${_last})
  string(JSON _file GET "${_units}" units ${_i} file)
  list(APPEND _sources "${_file}")
  string(JSON _uflags ERROR_VARIABLE _noflags GET "${_units}" units ${_i} flags)
  set(_opts "")
  string(REGEX REPLACE "^Source/([^/]+)/.*" "\\1" _modname "${_file}")
  string(JSON _mflags ERROR_VARIABLE _nomflags GET "${_config}" module_flags ${_modname})
  if(_noflags AND NOT _nomflags)
    string(JSON _m LENGTH "${_config}" module_flags ${_modname})
    math(EXPR _mlast "${_m} - 1")
    foreach(_k RANGE ${_mlast})
      string(JSON _f GET "${_config}" module_flags ${_modname} ${_k})
      if(NOT _f STREQUAL "/c" AND NOT _f STREQUAL "/nologo")
        list(APPEND _opts "${_f}")
      endif()
    endforeach()
  elseif(_noflags)
    set(_opts ${_base_flags})
  else()
    string(JSON _m LENGTH "${_units}" units ${_i} flags)
    math(EXPR _mlast "${_m} - 1")
    foreach(_k RANGE ${_mlast})
      string(JSON _f GET "${_units}" units ${_i} flags ${_k})
      if(NOT _f STREQUAL "/c" AND NOT _f STREQUAL "/nologo")
        list(APPEND _opts "${_f}")
      endif()
    endforeach()
  endif()
  string(JSON _ltcg ERROR_VARIABLE _noltcg GET "${_units}" units ${_i} ltcg)
  if(NOT _noltcg AND _ltcg)
    list(APPEND _opts "/GL")
  endif()
  string(REGEX MATCH "^Source/[^/]+" _module "${_file}")
  set_source_files_properties("${_file}" PROPERTIES COMPILE_OPTIONS "${_opts}"
    INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/${_module}")
endforeach()

add_library(codex OBJECT ${_sources})
target_include_directories(codex PRIVATE "${CMAKE_SOURCE_DIR}")
