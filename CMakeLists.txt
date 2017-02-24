cmake_minimum_required (VERSION 2.6)

project (CHeat)
include_directories(include)
set(COMPILE_FLAGS "-Wall -std=c++11")
set(LINK_FLAGS "")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -pg")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

file(GLOB SOURCES "src/*.cpp")

add_executable(cheat ${SOURCES})
