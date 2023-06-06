# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danlopez <danlopez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 07:17:15 by danlopez          #+#    #+#              #
#    Updated: 2023/06/06 06:19:12 by danlopez         ###   ########.fr        #
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

NAME_SERVER_BONUS = server_bonus 
SRC_SERVER_BONUS = server_bonus.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

NAME_CLIENT_BONUS = client_bonus
SRC_CLIENT_BONUS = client_bonus.c 
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

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

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME_SERVER_BONUS) $(OBJ_SERVER_BONUS) $(C_LIBRARY)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	cd $(LIBRARY) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME_CLIENT_BONUS) $(OBJ_CLIENT_BONUS) $(C_LIBRARY)

.PHONY: all, clean, fclean, re
#all: $(NAME_SERVER) $(NAME_CLIENT)

clean:
	cd $(LIBRARY) && $(MAKE) clean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	cd $(LIBRARY) && $(MAKE) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all
