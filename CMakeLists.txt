cmake_minimum_required(VERSION 3.0)
project(c_template C)

set(CMAKE_C_STANDARD 11)
aux_source_directory(src SRC)

add_executable(template ${SRC})
