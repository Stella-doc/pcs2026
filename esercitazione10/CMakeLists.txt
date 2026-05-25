cmake_minimum_required(VERSION 3.20)
project(gradiente_coniugato)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

find_package(Eigen3 CONFIG REQUIRED)

add_executable(test_gradiente test_gradiente_coniugato.cpp gradiente_coniugato.h)
target_link_libraries(test_gradiente PRIVATE Eigen3::Eigen)