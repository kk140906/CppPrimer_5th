cmake_minimum_required(VERSION 3.17)
project(CHAPTER10)
set(CMAKE_CXX_STANDARD 14)

# Retrieve all cpp file
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
foreach(SRC IN LISTS SOURCES)
    string(REGEX REPLACE "(^.+)\\..+$" \\1 TARGET_NAME ${SRC})
    add_executable(${TARGET_NAME} ${SRC})
endforeach()
