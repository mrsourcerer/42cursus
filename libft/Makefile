# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 21:42:01 by danlopez          #+#    #+#              #
#    Updated: 2023/05/16 06:07:57 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
CC = gcc
NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_toupper.c \
		ft_tolower.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_power.c ft_freevoid.c \
		ft_argc_argv.c ft_strcmp.c ft_putnbrf.c ft_ftoa.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c ft_lstprintf.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

SRC_PRINTF = printf/ft_printf.c printf/ft_printf_charutils.c \
		printf/ft_printf_hexutils.c printf/ft_printf_intutils.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

SRC_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_GNL = $(SRC_GNL:.c=.o)

OBJ_ALL = $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#bonus incluided in main
$(NAME): $(OBJ_ALL)
	ar rcs $(NAME) $(OBJ_ALL)

.PHONY: all, clean, fclean, re, bonus
all: 	$(NAME)

clean:
	rm -f $(OBJ_ALL)

fclean: clean
	rm -f $(NAME)

re:		fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

