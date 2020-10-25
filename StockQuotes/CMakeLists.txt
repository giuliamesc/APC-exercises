cmake_minimum_required(VERSION 3.17)
project(stockquotes)

set(CMAKE_CXX_STANDARD 11)

add_executable(stockquotes main.cpp Stock_quote.cpp Stock_quote.h Stock_quote_archive.cpp Stock_quote_archive.h)