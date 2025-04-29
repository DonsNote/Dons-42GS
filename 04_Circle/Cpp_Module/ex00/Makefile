# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 16:09:05 by dohyuki2          #+#    #+#              #
#    Updated: 2025/04/29 10:03:43 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $^

clean	:
		rm -f $(OBJS)

fclean	:
		make clean
		rm -f $(NAME)

re		:
		make fclean
		make all

.PHONY : all clean fclean re