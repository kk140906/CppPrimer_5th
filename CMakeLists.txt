cmake_minimum_required(VERSION 3.17)
project(C___Primer_Exercise VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

foreach(CHAPTER_NUM RANGE 5 18)
    add_subdirectory("Chapter ${CHAPTER_NUM}")
endforeach()

add_executable(CXX_Primer_test main.cpp)