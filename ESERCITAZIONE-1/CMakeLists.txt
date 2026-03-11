cmake_minimum_required(VERSION 3.20)
project(esercitazione1_meteo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

set(SOURCES printargs.cpp esercizio1.cpp)

add_executable(esercitazione1_meteo ${SOURCES})