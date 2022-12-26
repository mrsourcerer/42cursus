cmake_minimum_required(VERSION 3.24)
project(next_line C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -D BUFFER_SIZE=42")

set(SOURCE_FILES ../../../get_next_line_no42git/get_next_line.c ../../../get_next_line_no42git/get_next_line_utils.c ../../../get_next_line_no42git/get_next_line.h)

add_executable(a.out ../get_main.c ${SOURCE_FILES})
