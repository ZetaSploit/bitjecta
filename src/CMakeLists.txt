cmake_minimum_required(VERSION 3.25) # C++23 support requires newer CMake versions
project(HexJecta LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hexjecta)

target_sources(hexjecta 
    PRIVATE 
        hexjecta.cc 
)
