cmake_minimum_required(VERSION 3.17)
project(Ch3Ex2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ch3Ex2
        bus.hpp
        car.hpp
        limousine.cpp
        limousine.hpp
        main.cpp
        metro.hpp
        private_vehicle.cpp
        private_vehicle.hpp
        public_vehicle.cpp
        public_vehicle.hpp
        shuttle.hpp
        taxi.cpp
        taxi.hpp
        vehicle.cpp
        vehicle.hpp public_vehicle.cpp taxi.cpp)