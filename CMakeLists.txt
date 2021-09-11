cmake_minimum_required(VERSION 3.19)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4
        PTA/PTA1001/ArraysAndLinkedLists.cpp
        PTA/PTA1002/StackOfHats.cpp
        PTA/PTA1003/PlaygroundExploration.cpp
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -lgtest_main")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgtest -lgtest_main")