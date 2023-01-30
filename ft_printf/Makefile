# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 06:23:09 by danlopez          #+#    #+#              #
#    Updated: 2023/01/30 20:39:23 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = ./libft
C_LIBRARY = ./libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libftprintf.a
SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -c $< -o $@
#	$(CC) $(FLAGS) -I$(LIBRARY) -c $< -o $@

$(NAME): $(OBJ)
	cp $(C_LIBRARY) $(NAME)
	ar rcs $(NAME) $(OBJ)
#	ar rcs $(NAME) $(OBJ) $(C_LIBRARY)

.PHONY: all, clean, fclean, re
all: $(NAME)

clean:
	cd $(LIBRARY) && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBRARY) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
