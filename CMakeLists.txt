cmake_minimum_required(VERSION 3.19)
project(iqueue LANGUAGES CXX VERSION 1.0.0)

option(BUILD_SHARED_LIBS "Shared Libs" ON)

# Initial Settings
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ Standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Compile Command")
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "Compiler Extension")

message(STATUS "Shared Libs: ${BUILD_SHARED_LIBS}")
message(STATUS "C++ Version: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compile Command: ${CMAKE_EXPORT_COMPILE_COMMANDS}")

# Shared Directories
include_directories(
    "include"
)

# Integer Queue Program
if (BUILD_SHARED_LIBS)
    add_library(iqueue SHARED
        include/Container.hpp
        src/Container.cpp
    )
else()
    add_library(iqueue STATIC
        include/Container.hpp
        src/Container.cpp
    )
endif()