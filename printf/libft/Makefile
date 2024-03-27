# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyouhele <kyouhele@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 23:51:27 by kyouhele          #+#    #+#              #
#    Updated: 2024/03/22 18:59:51 by kyouhele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar cr
PARTONE = ft_itoa.c  ft_putchar_fd.c  ft_putnbr_fd.c  ft_putstr_fd.c  ft_strlen.c

SRCS = $(PARTONE) $(PARTTWO)
OBJS = ${SRCS:%.c=%.o}
SRCBNS = $(PARTBNS)
OBJBNS = ${SRCBNS:%.c=%.o}

ifdef WITHBNS
	OBJ = $(OBJS) $(OBJBNS)
else
	OBJ = $(OBJS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus :
	$(MAKE)	WITHBNS=1 all

clean :
	rm -f $(OBJS) $(OBJBNS)

fclean : clean
	rm -f $(NAME)


re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : clean fclean re bonus all
