# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 07:17:15 by danlopez          #+#    #+#              #
#    Updated: 2023/03/02 21:24:09 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = ./libft
C_LIBRARY = ./libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc

NAME = push_swap
SRC = push_swap.c ft_sort_min.c push_swap_operators.c push_swap_utils.c \
		ft_sort_mid.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(C_LIBRARY)

.PHONY: all, clean, fclean, re
clean:
	cd $(LIBRARY) && $(MAKE) clean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	cd $(LIBRARY) && $(MAKE) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
