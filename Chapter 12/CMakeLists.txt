cmake_minimum_required(VERSION 3.17)
project(CHAPTER12)
set(CMAKE_CXX_STANDARD 14)

# add aux source directory and set relative target
aux_source_directory(../common/source/ AUX_COMMON_SRC)
set(AUX_COMMON_SRC_LIST 12.1 12.19 12.22 12.27 12.30 12.32 12.33)

# Retrieve all cpp file
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)


foreach(SRC IN LISTS SOURCES)
    string(REGEX REPLACE "(^.+)\\..+$" \\1 TARGET_NAME ${SRC})
    if(${TARGET_NAME} IN_LIST AUX_COMMON_SRC_LIST)
        add_executable(${TARGET_NAME} ${SRC} ${AUX_COMMON_SRC})
    else()
        add_executable(${TARGET_NAME} ${SRC})
    endif()
endforeach()

