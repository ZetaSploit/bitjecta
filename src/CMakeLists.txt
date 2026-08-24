cmake_minimum_required(VERSION 3.25) # C++23 support requires newer CMake versions
project(BitJecta LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bitjecta)

target_sources(bitjecta 
    PRIVATE 
        bitjecta.cc 
)
