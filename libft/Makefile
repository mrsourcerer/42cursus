# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 21:42:01 by danlopez          #+#    #+#              #
#    Updated: 2022/12/03 12:11:05 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libft.a
SRC = ft_isupper.c ft_islower.c ft_isalpha.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re
all: 	$(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re:		fclean all

#bonus:

