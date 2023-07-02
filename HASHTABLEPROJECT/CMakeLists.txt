cmake_minimum_required(VERSION 3.21)
project(HASHTABLEPROJECT)

set(CMAKE_CXX_STANDARD 14)

add_executable(HASHTABLEPROJECT main.cpp AbstractHashTable.h LinearProbingHashing.cpp)
