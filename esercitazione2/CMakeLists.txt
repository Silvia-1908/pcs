cmake_minimum_required(VERSION 3.20)
project(myproject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall -Wshadow -Werror=vla")

set(SOURCE1 programma.cpp)
add_executable(programma ${SOURCE1})
set(SOURCE2 algoritmo.cpp)
add_executable(algoritmo ${SOURCE2})