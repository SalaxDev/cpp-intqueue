cmake_minimum_required(VERSION 3.19)
project(IQUEUE LANGUAGES CXX VERSION 1.0.0)

# Options
option(BUILD_SHARED_LIBS "Shared Libs" ON)
option(CMAKE_CXX_EXTENSIONS "Cmake C++ Extension (std | gnu)" OFF)

# Initial Settings
set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ Standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Logs
message(STATUS "Shared Libs: ${BUILD_SHARED_LIBS}")
message(STATUS "C++ Version: ${CMAKE_CXX_STANDARD}")
message(STATUS "Generating Compile Command: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(STATUS "Cmake C++ Extension: ${CMAKE_CXX_EXTENSIONS}")


include(GNUInstallDirs)


if(BUILD_SHARED_LIBS)
    set(_iqueue_type SHARED)
else()
    set(_iqueue_type STATIC)
endif()

# IntQueue Library
add_library(iqueue ${_iqueue_type}
    "src/IntQueue.cpp"
    "include/IntQueue.hpp"
)

# Adding Static || Shared Definition
if(_iqueue_type STREQUAL "SHARED") # Shared Build
    target_compile_definitions(iqueue PRIVATE IQUEUE_EXPORTS)
else() # Static Build
    target_compile_definitions(iqueue PUBLIC IQUEUE_STATIC)
endif()

# Property Setter
set_target_properties(iqueue PROPERTIES PREFIX "" IMPORT_PREFIX "")

# Including Directories
target_include_directories(iqueue PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_include_directories(iqueue PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src" 
)

# Installation
install(TARGETS iqueue
    EXPORT iqueueTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    FILES_MATCHING PATTERN "*.hpp"
)

install(EXPORT iqueueTargets
    FILE iqueueTargets.cmake
    NAMESPACE iqueue::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/iqueue"
)

include(CMakePackageConfigHelpers)

write_basic_config_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/iqueueConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/iqueueConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/iqueueConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/iqueue"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/iqueueConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/iqueueConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/iqueue"
)

# License Installation
install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/licenses/iqueue"
)