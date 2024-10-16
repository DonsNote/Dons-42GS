# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 14:23:02 by dohyuki2          #+#    #+#              #
#    Updated: 2024/10/16 09:14:41 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = philo.h

SRCS = philo.c \
		./Utilities/ft_atoi.c \
		./Utilities/check_error.c \
		./Utilities/init/init.c \
		./Utilities/init/mutex.c \
		./Utilities/func/dead.c \
		./Utilities/func/eat.c \
		./Utilities/func/print.c \
		./Utilities/func/sleep.c \
		./Utilities/func/time.c \
		./Utilities/func/moniter.c

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