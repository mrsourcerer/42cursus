# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 10:30:12 by danlopez          #+#    #+#              #
#    Updated: 2023/06/15 07:25:47 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ACCENT	:= "\033[92;3;4;1m"
NONE	:= "\033[0m"

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
	LINK= -lXext -lX11
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
	@make -sC $(MLX)
	@make -sC $(LIBFT)
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

re: fclean all
