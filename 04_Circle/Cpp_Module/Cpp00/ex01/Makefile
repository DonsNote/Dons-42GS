# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 16:18:19 by dohyuki2          #+#    #+#              #
#    Updated: 2025/04/29 10:37:03 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= digit

CXX		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	= digit.cpp
OBJS	= $(SRCS:.cpp=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean	: 
		rm -f $(OBJS)

fclean	: 
		make clean
		rm -f $(NAME)

re		: 
		make fclean
		make all

.PHONY	: all clean fclean re