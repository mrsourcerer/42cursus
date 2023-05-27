# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 07:17:15 by danlopez          #+#    #+#              #
#    Updated: 2023/02/24 06:25:37 by danlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = ./libft
C_LIBRARY = ./libft/libft.a
FLAGS = -Werror -Wall -Wextra
CC = gcc

NAME_SERVER = server 
SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

NAME_CLIENT = client
SRC_CLIENT = client.c 
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c
#	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -c $< -o $@
#	$(CC) $(FLAGS) -I$(LIBRARY) -c $< -o $@

$(NAME_SERVER): $(OBJ_SERVER)
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(C_LIBRARY)

$(NAME_CLIENT): $(OBJ_CLIENT)
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(C_LIBRARY)

.PHONY: all, clean, fclean, re
#all: $(NAME_SERVER) $(NAME_CLIENT)

clean:
	cd $(LIBRARY) && $(MAKE) clean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	cd $(LIBRARY) && $(MAKE) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
