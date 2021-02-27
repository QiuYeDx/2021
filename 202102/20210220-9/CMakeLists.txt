cmake_minimum_required(VERSION 3.17)
project(20210220_9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(20210220_9 main.cpp)