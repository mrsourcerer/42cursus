# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 06:23:09 by danlopez          #+#    #+#              #
#    Updated: 2023/01/30 07:17:23 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = libft
C_LIBRARY = libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libftprintf.a
SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -c -I$(LIBRARY) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: all, clean, fclean, re
all: $(NAME)

clean:
	cd $(LIBRARY) && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBRARY) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
