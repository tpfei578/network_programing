cmake_minimum_required(VERSION 2.6)

set (OUTPUT_PATH "${PROJECT_SOURCE_DIR}/output")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -fvisibility=hidden -g -fPIC -Wall  ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fvisibility=hidden -g -fPIC -Wall -Wno-reorder -Wno-attributes -fpermissive  ")

add_subdirectory(simple_tcp)
add_subdirectory(simple_udp)
