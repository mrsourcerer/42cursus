# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:54:22 by bde-mada          #+#    #+#              #
#    Updated: 2023/04/25 19:39:29 by bde-mada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# .SILENT:
# NOT PRINT THE EXECUTION MESSAGES

OS = $(shell uname -s)

SRC_DIR		= src/
OBJ_DIR		= obj/
INC			= -Iinclude 
LIBFT_DIR	= libft/
LIBFT_A		= libft.a

MLX_MACOS	= minilibx/
MLX_LINUX	= minilibx_linux/	
MLX_A		= libmlx.a

# SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
SRC_FILES 	= fractol.c \
				fractals.c \
				fractol_utils.c \
				fractol_exit.c \
				controls.c \
				draw_fractal.c
				
OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

LNK			= -L$(MLX_DIR)

ifeq ($(OS), Darwin)
	MLX_DIR=$(MLX_MACOS)
	LNK+= -Imlx -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR=$(MLX_LINUX)
	LNK+= -lXext -lX11 -lm -lz
endif
MLX=$(addprefix $(MLX_DIR), $(MLX_A))

DEBUG		= -O3
#-g3 -fsanitize=address

NONE		:= "\033[0m"
GREEN		:= "\033[32m"
YELLOW		:= "\033[1;33m"
GRAY		:= "\033[2;37m"
CURSIVE		:= "\033[3m"
RED			:= "\x1b[31m"
BLUE		:= "\033[1;34m"
CYAN 		:= "\033[1;36m"
ACCENT		:= "\033[92;3;4;1m"

all: make_libs obj $(NAME)

obj:
	@echo $(CURSIVE)$(GRAY) "		- Creating object directory..." $(NONE)
	@mkdir -p $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "		- Generating object files..." $(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(DEBUG) $(INC) -I$(LIBFT_DIR) -c $< -o $@
# -lm is used to compile with libm, where math.h is located

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "		- Compiling project $(NAME)..." $(NONE)
#	@cp $(MINILBX_DIR)/libmlx.a .
	$(CC) $(LNK) $(OBJS) $(DEBUG) $(LIBFT) -o $(NAME)
	@echo $(ACCENT)"✅ $(NAME) compiled ✅"$(NONE)

make_libs: make_libft make_mlx

make_libft:
	@make -sC $(LIBFT_DIR)

make_mlx:
	@make -sC $(MLX_DIR)


clean:
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@rm -Rf $(OBJ_DIR)
	@echo $(RED) Objects deleted!$(NONE) 🗑

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_DIR)
	@echo $(RED) "Objects & $(NAME) executable deleted!"$(NONE) 🗑❌

re: fclean all

norm:
	norminette src include libft

.phony: all clean fclean re norm funcs

#objdump -t obj/* | grep "*UND*" | awk '{print $3}' | sort -u