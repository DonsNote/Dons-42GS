# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:09:29 by dohyuki2          #+#    #+#              #
#    Updated: 2025/01/23 13:17:40 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = c
CFLAGS = -Wall -Werror -Wextra

MLX_DIR = ./minilibx-linux/

INC = cub3D.h

SRCS = cub3D.c \
		./parse/check_map.c \
		./Utilities/utilities.c \
		./Utilities/error_print.c

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -g -o $(NAME) $^ -lft -L$(MLX_DIR) - lmlx_Linux - lXext - lx11 -lbsd

clean : 
		rm -f $(OBJS)

fclean : 
		make clean
		rm -f $(NAME)
		make -C $(MLX_DIR) clean

re : 
		make fclean
		make all

.PHONY : all clean fclean re