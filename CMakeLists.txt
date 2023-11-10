cmake_minimum_required(VERSION 3.21)
project(HASHTABLEPROJECT)

set(CMAKE_CXX_STANDARD 14)

add_executable(HASHTABLEPROJECT src/main.cpp src/AbstractLinearProbing.h src/LinearProbingHashing.cpp src/distribution.h src/HopscotchHashing.cpp src/AbstractHopscotchProbing.h)
