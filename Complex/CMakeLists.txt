cmake_minimum_required(VERSION 3.17)
project(complex)

set(CMAKE_CXX_STANDARD 11)

add_executable(complex main.cpp Complex.cpp Complex.h ComplexPolar.cpp ComplexPolar.h)