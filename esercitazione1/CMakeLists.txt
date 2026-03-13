cmake_minimum_required(VERSION 3.20)
project(myproject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall")

set(SOURCE1 printargs.cpp)
add_executable(printargs ${SOURCE1})
set(SOURCE2 media_t.cpp)
add_executable(media_t ${SOURCE2})
