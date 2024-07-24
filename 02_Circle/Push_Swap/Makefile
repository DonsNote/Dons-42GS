# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 08:06:57 by dohyuki2          #+#    #+#              #
#    Updated: 2024/07/24 13:24:27 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAG = -Wall -Wextra -Werror

INCS = push_swap.h

SRCS = main.c \
		./Utilities/Parsing/check_param.c \
		./Utilities/Parsing/print_error.c \
		./Utilities/Parsing/make_num_arr.c \
		./Utilities/Stack/make_stack.c \
		./Utilities/Commend/push.c \
		./Utilities/Commend/reverse.c \
		./Utilities/Commend/rotate.c \
		./Utilities/Commend/swap.c \
		push_swap.c

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
