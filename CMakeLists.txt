cmake_minimum_required(VERSION 3.6)
project(Reviiyot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include src)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

add_executable(Reviiyot ${SOURCES})