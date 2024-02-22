NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
	
$(NAME) :
	$(CC) $(CFLAGS) -o $@ $(SRCS)

all : $(NAME)

clean :
	rm -f $(NAME)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re