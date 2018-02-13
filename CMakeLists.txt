cmake_minimum_required(VERSION 3.9)
project(sortmeout)

set(CMAKE_CXX_STANDARD 17)

add_executable(sortmeout main.cpp sort.cpp sort.h cmake-build-debug/sequence.cpp cmake-build-debug/sequence.h Sequence.cpp Sequence.h)