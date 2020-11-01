cmake_minimum_required(VERSION 3.17)
project(CHAPTER12)
set(CMAKE_CXX_STANDARD 14)
set(STR_BLOB ../common/source/StrBlob.cpp)
set(STR_BLOB_PTR ../common/source/StrBlobPtr.cpp)
set(TEXT_QUERY ../common/source/text_query.cpp ../common/source/text_query_result.cpp)
add_executable(12.1 12.1.cpp ${STR_BLOB})
add_executable(12.6 12.6.cpp)
add_executable(12.7 12.7.cpp)
add_executable(12.14 12.14.cpp)
add_executable(12.16 12.16.cpp)
add_executable(12.19 12.19.cpp ${STR_BLOB} ${STR_BLOB_PTR})
add_executable(12.22 12.22.cpp ${STR_BLOB} ${STR_BLOB_PTR})
add_executable(12.23 12.23.cpp)
add_executable(12.24 12.24.cpp)
add_executable(12.26 12.26.cpp)
add_executable(12.27 12.27.cpp ${TEXT_QUERY})
add_executable(12.28 12.28.cpp)
add_executable(12.30 12.30.cpp ${TEXT_QUERY})
add_executable(12.32 12.32.cpp ${TEXT_QUERY})
add_executable(12.33 12.33.cpp ${TEXT_QUERY} ${STR_BLOB} ${STR_BLOB_PTR})





