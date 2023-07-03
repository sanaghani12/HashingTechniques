cmake_minimum_required(VERSION 3.21)
project(HASHTABLEPROJECT)

set(CMAKE_CXX_STANDARD 14)

add_executable(HASHTABLEPROJECT src/main.cpp src/AbstractHashTable.h src/LinearProbingHashing.cpp)
