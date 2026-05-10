cmake_minimum_required(VERSION 3.20)
project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SRC_graph unidirected_graph.hpp unidirected_edge.hpp)

add_executable(test_graph test_graph.cpp ${SRC_graph})
add_test(NAME test_graph COMMAND test_graph)

enable_testing()