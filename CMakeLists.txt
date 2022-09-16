cmake_minimum_required(VERSION 3.21)
project(datastruct C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
aux_source_directory(src DS_SRC)
add_executable(datastruct main.c ${DS_SRC})
