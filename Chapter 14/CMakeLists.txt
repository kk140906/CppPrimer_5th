cmake_minimum_required(VERSION 3.17)
project(CHAPTER14)
set(CMAKE_CXX_STANDARD 14)
add_executable(14.2 14.2.cpp "../common/header/Sales_data.h")
add_executable(14.7 14.7.cpp "../common/header/String.h" "../common/source/String.cpp")
add_executable(14.16 14.16.cpp
        "../common/header/StrBlobPtr.h"
        "../common/header/String.h"
        "../common/source/String.cpp"
        "../common/header/StrVec.h"
        "../common/source/StrVec.cpp")
add_executable(14.18 14.18.cpp
        "../common/header/StrBlobPtr.h"
        "../common/header/String.h"
        "../common/source/String.cpp"
        "../common/header/StrVec.h"
        "../common/source/StrVec.cpp")
add_executable(14.20 14.20.cpp "../common/header/Sales_data.h")
add_executable(14.23 14.23.cpp
        "../common/header/StrVec.h"
        "../common/source/StrVec.cpp")
add_executable(14.26 14.26.cpp
        "../common/header/StrBlobPtr.h"
        "../common/header/String.h"
        "../common/source/String.cpp"
        "../common/header/StrVec.h"
        "../common/source/StrVec.cpp")
add_executable(14.27 14.27.cpp
        "../common/header/StrBlobPtr.h")
add_executable(14.30 14.30.cpp
        "../common/header/StrBlobPtr.h")
add_executable(14.32 14.32.cpp
        "../common/header/StrBlobPtr.h")
add_executable(14.34 14.34.cpp)
add_executable(14.35 14.35.cpp)
add_executable(14.37 14.37.cpp)
add_executable(14.38 14.38.cpp)
add_executable(14.42 14.42.cpp)
add_executable(14.43 14.43.cpp)
add_executable(14.44 14.44.cpp)
