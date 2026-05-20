cmake_minimum_required(VERSION 3.20)
project(visita_grafi)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES algoritmi_ricerca.cpp)

add_executable(visita_grafi ${SOURCES})