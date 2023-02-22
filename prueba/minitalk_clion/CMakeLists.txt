cmake_minimum_required(VERSION 3.24)
project(minitalk_clion C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g")

set(SOURCE_CLIENT client.c)
set(SOURCE_SERVER server.c)

#set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /home/sourcerer/projects/42cursus/prueba/minitalk_clion/libft)

find_library(LIBFT_LIBRARY libft ./)

add_executable(server ${SOURCE_SERVER})
add_executable(client ${SOURCE_CLIENT})

#target_link_libraries(server ${LIBFT_LIBRARY})
#target_link_libraries(client ${LIBFT_LIBRARY})