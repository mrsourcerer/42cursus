# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 10:30:12 by danlopez          #+#    #+#              #
#    Updated: 2023/10/03 06:36:10 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:= "\033[0;33m"
ACCENT	:= "\033[1;33m"
NONE	:= "\033[0m"

#MLX_MAC = ./include/minilibx_mms_20191025_beta
#C_MLX_MAC =  ./include/minilibx_mms_20191025_beta/libmlx.dylib
#MLX_NAME_MAC = libmlx.dylib

MLX_MAC = ./include/minilibx_opengl_20191021
C_MLX_MAC =  ./include/minilibx_opengl_20191021/libmlx.a
MLX_NAME_MAC = libmlx.a

MLX_LINUX = ./include/minilibx-linux
C_MLX_LINUX = ./include/minilibx-linux/libmlx_Linux.a
MLX_NAME_LINUX = libmlx_linux.a


OS = $(shell uname -s)
ifeq ($(OS), Darwin)
	MLX=$(MLX_MAC)
	C_MLX=$(C_MLX_MAC)
	LINK= -L$(MLX) -lm -Imlx -lmlx -framework OpenGL -framework AppKit
else
	MLX=$(MLX_LINUX)
	C_MLX=$(C_MLX_LINUX)
	LINK= -lXext -lX11 -lm -lz -L/usr/lib
	#LINK= -lXext -lX11 -lm -lz -L/usr/lib
endif

LIBFT = ./include/libft
C_LIBFT = ./include/libft/libft.a
FLAGS = -Werror -Wall -Wextra -g
CC = gcc

NAME = fractol
SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -I$(MLX) -c $< -o $@

$(NAME): $(OBJ)
	make -sC $(MLX) && cp $(C_MLX) ./
	@echo $(GREEN)"$(C_MLX) compiled ✅"$(NONE)
	make -sC $(LIBFT)
	@echo $(GREEN)"$(C_LIBFT) compiled ✅"$(NONE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(C_LIBFT) $(C_MLX) $(LINK)
	@echo $(ACCENT)"$(NAME) compiled ✅"$(NONE)

.PHONY: all, clean, fclean, re
clean:
	@make clean -sC $(MLX)
	@make clean -sC $(LIBFT)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -sC $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(MLX_NAME_MAC)
	@rm -f $(MLX_NAME_LINUX)

re: fclean all
