# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 14:23:02 by dohyuki2          #+#    #+#              #
#    Updated: 2024/09/27 10:45:39 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = philo.h

SRCS = philo.c \
		./Utilities/ft_atoi.c \
		./Utilities/check_error.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -g -o $(NAME) $^

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re