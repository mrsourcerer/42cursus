# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 06:23:09 by danlopez          #+#    #+#              #
#    Updated: 2023/02/19 12:30:06 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = ./libft
C_LIBRARY = ./libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libftprintf.a
SRC = ft_printf.c ft_printf_charutils.c ft_printf_intutils.c \
		ft_printf_hexutils.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd $(LIBRARY) && $(MAKE)
	cp $(C_LIBRARY) $(NAME)
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
