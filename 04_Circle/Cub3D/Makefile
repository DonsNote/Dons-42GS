# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:09:29 by dohyuki2          #+#    #+#              #
#    Updated: 2025/04/21 17:11:53 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra

MLX_DIR = ./minilibx-linux/

LIBFT_DIR = ./Utilities/libft/

INC = cub3D.h \
		key_code.h

SRCS = cub3D.c \
		./parse/check_init.c \
		./parse/utilities.c \
		./parse/utilities2.c \
		./parse/utilities3.c \
		./Utilities/error_handle.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -g -o $(NAME) $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lbsd

clean	:
		rm -f $(OBJS)
		make -C $(LIBFT_DIR) clean
		make -C $(MLX_DIR) clean
fclean	:
		make clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)
		make clean -C $(MLX_DIR)

re		:
		make fclean
		make all

.PHONY : all clean fclean re