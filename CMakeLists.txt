cmake_minimum_required(VERSION 2.8)
project(truco-cli)

IF(${CMAKE_CXX_COMPILER_ID} MATCHES "GNU|Clang")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
ELSE()
    MESSAGE(WARNING "Compiler unknown or unsupported")
ENDIF()


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(test)
