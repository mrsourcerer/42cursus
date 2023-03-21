cmake_minimum_required(VERSION 3.24)
project(push_swap_clion C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g")

set(SOURCE push_swap.c ft_sort_min.c push_swap_operators.c push_swap_utils.c ft_sort_mid.c)

find_library(LIBFT_LIBRARY libft.a ./libft)

add_executable(push_swap ${SOURCE})

target_link_libraries(push_swap ${LIBFT_LIBRARY})
