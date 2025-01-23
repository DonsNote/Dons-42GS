# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 14:37:16 by dohyuki2          #+#    #+#              #
#    Updated: 2025/01/23 14:38:47 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_nex_line

CC = cc
CFLAG = -Wall -Wextra -Werror

INCS = get_next_line.h

SRCS = get_next_line.c \
		./Utilities/utilities.c \
		./Utilities/utilities2.c

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