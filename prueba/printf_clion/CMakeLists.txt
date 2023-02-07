cmake_minimum_required(VERSION 3.24)
project(printf_clion C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g")

set(SOURCE_FILES main.c ft_printf.c ft_printf_charutils.c ft_printf_intutils.c ft_putnbr_u_fd.c ft_printf_hexutils.c)

find_library(FTPRINTF_LIBRARY ftprintf ./)

add_executable(a.out ${SOURCE_FILES})
target_link_libraries(a.out ${FTPRINTF_LIBRARY})
