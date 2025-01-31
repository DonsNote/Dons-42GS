# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:09:29 by dohyuki2          #+#    #+#              #
#    Updated: 2025/01/31 22:07:45 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = c
CFLAGS = -Wall -Werror -Wextra

MLX_DIR = ./minilibx-linux/
LIBFT_DIR = ./Utilities/libft/

INC = cub3D.h

SRCS = cub3D.c \
		./parse/check_map.c \
		./Utilities/error_print.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -g -o $(NAME) $^ -lft -L$(LIBFT_DIR) -L$(MLX_DIR) - lmlx_Linux - lXext - lx11 -lbsd

clean : 
		rm -f $(OBJS)
		make $(MLX_DIR) clean
		make $(LIBFT_DIR) clean

fclean : 
		make clean
		make -C $(MLX_DIR) fclean
		make -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re : 
		make fclean
		make all

.PHONY : all clean fclean re