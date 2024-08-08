# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 12:48:12 by dohyuki2          #+#    #+#              #
#    Updated: 2024/08/08 17:33:25 by dohyuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

SERVER = server

CLIENT = client

CC = cc

CFLAG = -Wall -Wextra -Werror

FT_DIR = ./Libft/

INC = minitalk.h

S_SRCS = server.c

C_SRCS = client.c

S_OBJS = $(S_SRCS:.c=.o)

C_OBJS = $(C_SRCS:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(S_OBJS)
	make -C $(FT_DIR)
	$(CC) $(CFLAG) -g -o $(SERVER) $^ -L$(FT_DIR)

$(CLIENT) : $(C_OBJS)
	$(CC) $(CFLAG) -g -o $(CLIENT) $^ -L$(FT_DIR)

clean :
	rm -rf $(S_OBJS)
	rm -rf $(C_OBJS)

fclean :
	make clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	make -C $(FT_DIR) fclean

re :
	make fclean
	make all

.PHONY : all clean fclean re