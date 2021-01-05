cmake_minimum_required(VERSION 3.17)
project(Labo5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo5 main.cpp date.cpp date.h)