cmake_minimum_required(VERSION 3.24)
project(next_line_clion C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -D BUFFER_SIZE=1")

set(SOURCE_FILES get_main.c get_next_line.c get_next_line_utils.c)

add_executable(a.out ${SOURCE_FILES} )
