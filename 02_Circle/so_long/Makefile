# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 10:18:11 by dohyuki2          #+#    #+#              #
#    Updated: 2024/08/03 12:32:51 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAG = -Wall -Wextra -Werror

FT_DIR = ./Libft/

MLX_DIR = ./minilibx-linux/

INC = so_long.h

SRCS = main.c \
		./Utilities/map/param_check.c \
		./Utilities/map/map-check.c \
		./Utilities/game/start.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(FT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAG) -g -o $(NAME) $^ -L$(FT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lbsd

clean : 
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)
	make -C $(FT_DIR) fclean
	make -C $(MLX_DIR) clean

re :
	make fclean
	make all

.PHONY : all clean fclean re
