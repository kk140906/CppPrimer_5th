cmake_minimum_required(VERSION 3.17)
project(CHAPTER13)
set(CMAKE_CXX_STANDARD 14)
add_executable(13.5 13.5.cpp)
add_executable(13.8 13.8.cpp)
add_executable(13.11 13.11.cpp)
add_executable(13.13 13.13.cpp)
add_executable(13.17 13.17.cpp)
add_executable(13.18 13.18.cpp)
add_executable(13.26 13.26.cpp ../common/header/StrBlob.h)
add_executable(13.27 13.27.cpp)
add_executable(13.28 13.28.cpp)
add_executable(13.30 13.30.cpp)
add_executable(13.34 13.34.cpp ../common/header/Messages_Folders.h)
add_executable(13.39 13.39.cpp ../common/source/StrVec.cpp ../common/header/StrVec.h)
add_executable(13.42 13.42.cpp
        ../common/header/textquery.h
        ../common/header/textqueryresult.h
        ../common/header/StrVec.h
        ../common/source/StrVec.cpp)
add_executable(13.44 13.44.cpp ../common/source/String.cpp ../common/header/String.h)
add_executable(13.53 13.53.cpp)
add_executable(13.55 13.55.cpp ../common/header/StrBlob.h)
add_executable(13.56 13.56.cpp)
