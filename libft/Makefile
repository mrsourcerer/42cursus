# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 21:42:01 by danlopez          #+#    #+#              #
#    Updated: 2022/12/05 07:20:07 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libft.a
SRC = ft_isupper.c ft_islower.c ft_isalpha.c ft_isdigit.c ft_toupper.c \
		ft_tolower.c ft_isalnum.c ft_isascii.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: all, clean, fclean, re
all: 	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all

#bonus:

