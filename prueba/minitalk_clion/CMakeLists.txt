cmake_minimum_required(VERSION 3.24)
project(minitalk_clion C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g")

set(SOURCE_FILES main.c )

find_library(LIBFT_LIBRARY libft ./)

add_executable(a.out ${SOURCE_FILES})
target_link_libraries(a.out ${LIBFT_LIBRARY})
