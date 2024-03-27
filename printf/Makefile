# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyouhele <kyouhele@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 23:51:27 by kyouhele          #+#    #+#              #
#    Updated: 2024/03/22 19:00:19 by kyouhele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar cr

SRCS = ft_printf.c ft_printfhelper.c
OBJS = ${SRCS:%.c=%.o}

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) libft.a
	cp libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

libft.a :
	$(MAKE) -C ./libft all

clean :
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean


re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : clean fclean re bonus all
