# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 10:30:12 by danlopez          #+#    #+#              #
#    Updated: 2023/06/13 06:56:54 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_MAC = ./include/minilibx_mms_20191025_beta
MINILIBX_LINUX = ./include/minilibx-linux

OS = $(shell uname -s)
ifeq ($(OS), Darwin)
	MINILIBX=$(MINILIBX_MAC)
else
	MINILIBX=$(MINILIBX_LINUX)
endif

LIBRARY = ./include/libft
C_LIBRARY = ./include/libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc

NAME = fractol
SRC = fractol.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) $(MINILIBX) -c $< -o $@

$(NAME): $(OBJ)
	cd $(MINILIBX) && $(MAKE)
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(C_LIBRARY)

.PHONY: all, clean, fclean, re
clean:
	cd $(LIBRARY) && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBRARY) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
