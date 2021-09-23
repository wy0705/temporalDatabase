cmake_minimum_required(VERSION 3.17)
project(temporalDatabase)

set(CMAKE_CXX_STANDARD 14)

add_executable(temporalDatabase main.cpp hash_map.h hash_map.cpp)