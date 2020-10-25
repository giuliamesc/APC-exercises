cmake_minimum_required(VERSION 3.17)
project(poliroots)

set(CMAKE_CXX_STANDARD 11)

add_executable(poliroots main.cpp Function.cpp Function.h Methods.cpp Methods.h Rootfinding.h)