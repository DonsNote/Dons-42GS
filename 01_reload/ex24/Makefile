NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc

INCS = ./includes/
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
