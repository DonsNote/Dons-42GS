
#include "ft_printf.h"

int ft_putstr_pf(char *str)
{
    int check;

    check = 0;
    if (str == 0)
    {
        if (write(1, "(null)", 6) == -1)
            return (-1);
        return (6);
    }
    while (str[check] != '\0')
    {
        if (ft_putchar_pf(str[check]) == -1)
            return (-1);
        ++check;
    }
    return (check);
}