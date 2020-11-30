cmake_minimum_required(VERSION 3.14)
project(VideoGamePlayer)

file(GLOB SOURCES
        *.hh
        *.cc
        )

set(CMAKE_CXX_STANDARD 11)

add_executable(ArcadePlayers ${SOURCE_FILES} ${SOURCES})