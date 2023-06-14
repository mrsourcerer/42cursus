# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 10:30:12 by danlopez          #+#    #+#              #
#    Updated: 2023/06/14 07:10:16 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_MAC = ./include/minilibx_mms_20191025_beta
C_MLX_MAC =  ./include/minilibx_mms_20191025_beta/libmlx.a

MLX_LINUX = ./include/minilibx-linux
C_MLX_LINUX = ./include/minilibx-linux/libmlx_Linux.a


OS = $(shell uname -s)
ifeq ($(OS), Darwin)
	MLX=$(MLX_MAC)
	C_MLX=$(C_MLX_MAC)
else
	MLX=$(MLX_LINUX)
	C_MLX=$(C_MLX_LINUX)
endif

LIBFT = ./include/libft
C_LIBFT = ./include/libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc

NAME = fractol
SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd $(MLX) && $(MAKE)
	cd $(LIBFT) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(C_LIBFT) $(C_MLX)

.PHONY: all, clean, fclean, re
clean:
	cd $(LIBFT) && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBFT) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
