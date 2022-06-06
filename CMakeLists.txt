cmake_minimum_required(VERSION 3.21)

# set clang compiler path
if((NOT APPLE) AND (NOT ANDROID))
    set(CMAKE_C_COMPILER "clang-13")
    set(CMAKE_CXX_COMPILER "clang++-13")
endif()

# project name
project(UPC C CXX)

# enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# -fPIC
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RELEASE)
endif()

#
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src)