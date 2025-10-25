cmake_minimum_required(VERSION 3.10)
project(DeFer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(DeFer
    src/main.cpp
    src/Module.cpp
    src/Net.cpp
    src/Floorplan.cpp
    src/EP.cpp
    src/Utils.cpp
)
