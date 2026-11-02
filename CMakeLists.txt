cmake_minimum_required(VERSION 3.30)
project(TEMPLATE LANGUAGES CXX C VERSION 1.0.0)

# Initial Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Shared Directories
include_directories(
    "include"
    "libs"
)

# Main Program
add_executable(main
    src/main.cpp
    src/Container.cpp
)

# Name Changer
set_target_properties(main PROPERTIES OUTPUT_NAME "main")