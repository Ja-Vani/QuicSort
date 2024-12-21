cmake_minimum_required(VERSION 3.29)
project(QuicSort)

set(CMAKE_CXX_STANDARD 23)

include_directories(Inc)
add_subdirectory(lib)
set(gtest_disable_pthreads on)

add_executable(QuicSort Src/main.cpp
        Src/my_sort.cpp)
