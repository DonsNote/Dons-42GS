NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc

GCH = ft_printf.h.gch

INCS = ft_printf.h

SRCS = ft_printf.c \
	ft_putchar_pf.c \
	ft_putstr_pf.c \
	ft_putaddr_pf.c \
	ft_putdecimal_pf.c \
	ft_putint_pf.c \
	ft_putuint_pf.c \
	ft_putlhex_pf.c \
	ft_putuhex_pf.c \
	ft_checkform_pf.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAG) $(INCS) -c $<

clean :
	rm -f $(OBJS)
	rm -f $(GCH)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re