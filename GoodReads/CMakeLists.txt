cmake_minimum_required(VERSION 3.16)
project(GoodReads)

set(CMAKE_CXX_STANDARD 11)

add_executable(GoodReads main.cpp Book.cpp Book.h Review.cpp Review.h GoodReads.cpp GoodReads.h)