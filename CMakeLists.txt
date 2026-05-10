cmake_minimum_required(VERSION 3.22..4.2.0 FATAL_ERROR)
project(gmcl_libremidi
  VERSION 0.1.0
  DESCRIPTION "Realtime MIDI for Garry's Mod"
  LANGUAGES CXX
  HOMEPAGE_URL "https://github.com/inco-cc/gmcl_libremidi"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(LIBREMIDI_NO_WINUWP ON)
set(LIBREMIDI_NO_WINMIDI ON)
set(LIBREMIDI_NO_NETWORK ON)
set(LIBREMIDI_NO_KEYBOARD ON)
set(LIBREMIDI_NO_ANDROID ON)
set(LIBREMIDI_NO_KDMAPI ON)

add_subdirectory(thirdparty/gmod-module-base/include)
add_subdirectory(thirdparty/libremidi)

set(SOURCE_FILES
  src/main.cpp
  src/libraries/libremidi.cpp
)
set(HEADER_FILES
  include/gmcl_libremidi/common.hpp
  include/gmcl_libremidi/libraries/libremidi.hpp
)

add_library(gmcl_libremidi SHARED ${SOURCE_FILES} ${HEADER_FILES})

source_group(TREE ${CMAKE_SOURCE_DIR}/src PREFIX "Source Files" FILES ${SOURCE_FILES})
source_group(TREE ${CMAKE_SOURCE_DIR}/include/gmcl_libremidi PREFIX "Header Files" FILES ${HEADER_FILES})

target_include_directories(gmcl_libremidi PRIVATE include)
target_link_libraries(gmcl_libremidi PRIVATE gmod-module-base libremidi)

if(APPLE)
  set_target_properties(gmcl_libremidi PROPERTIES SUFFIX "_osx.dll")
elseif(UNIX)
  if(${CMAKE_SIZEOF_VOID_P} STREQUAL "4")
    set_target_properties(gmcl_libremidi PROPERTIES SUFFIX "_linux.dll")
  else()
    set_target_properties(gmcl_libremidi PROPERTIES SUFFIX "_linux64.dll")
  endif()
elseif(WIN32)
  if(${CMAKE_SIZEOF_VOID_P} STREQUAL "4")
    set_target_properties(gmcl_libremidi PROPERTIES SUFFIX "_win32.dll")
  else()
    set_target_properties(gmcl_libremidi PROPERTIES SUFFIX "_win64.dll")
  endif()
endif()
