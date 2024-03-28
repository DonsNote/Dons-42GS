
#include "ft_printf.h"

static int ft_readdr_pf(unsigned long long addr, int *count)
{
    if (addr < 16)
    {
        if (ft_putchar_pf(LHEX[addr]) == -1)
            return (-1);
        return (0);
    }
    if (ft_readdr_pf(addr / 16, count) == -1)
        return (-1);
    if (ft_readdr_pf(addr % 16, count) == -1)
        return (-1);
    ++(*count);
    return (0);
}

int ft_putaddr_pf(unsigned long long addr)
{
    int count;

    count = 2;
    if ((write(1, "0x", 2)) == -1)
        return (-1);
    if (ft_readdr_pf(addr, &count) == -1)
        return (-1);
    return (count);
}