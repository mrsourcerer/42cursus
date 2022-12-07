# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 21:42:01 by danlopez          #+#    #+#              #
#    Updated: 2022/12/07 06:31:08 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libft.a
SRC = ft_isupper.c ft_islower.c ft_isalpha.c ft_isdigit.c ft_toupper.c \
		ft_tolower.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_strchr.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#%.o: %.c
#	$(CC) -c $(CFlAGS) $^

.PHONY: all, clean, fclean, re
all: 	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all

#bonus:

