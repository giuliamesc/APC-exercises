cmake_minimum_required(VERSION 3.17)
project(Ch3Ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ch3Ex1 main.cpp Manager.hpp Developer.hpp Secretary.hpp Employee.hpp Manager.cpp Developer.cpp Secretary.cpp)