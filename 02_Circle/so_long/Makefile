# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 10:18:11 by dohyuki2          #+#    #+#              #
#    Updated: 2024/07/31 12:23:41 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAG = -Wall -Wextra -Werror

MLX = libmlx.a

INC = so_long.h

INCS = 

SRCS = main.c \
		so_ling .c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -g -o $(NAME) $^

clean : 
	rm -rf $(OBJS)

fclen :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
