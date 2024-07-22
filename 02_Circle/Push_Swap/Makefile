# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 08:06:57 by dohyuki2          #+#    #+#              #
#    Updated: 2024/07/21 06:04:17 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAG = -Wall -Wextra -Werror

INCS = push_swap.h

SRCS = main.c \
		check_param.c \
		print_error.c \
		make_num.c \
		make_stack.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -g -o $(NAME) $^

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
