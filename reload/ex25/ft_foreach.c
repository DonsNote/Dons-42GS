
#include <unistd.h>

void    ft_putnbr(int nbr)
{
    char    c;

    c = nbr + 48;
    write(1, &c, 1);
}

void    (*f)(int);
f = ft_putnbr;

void    ft_foreach(int *tab, int lengthm void (*f)(int))
{

}