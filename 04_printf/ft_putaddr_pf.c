/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:28:24 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/29 15:19:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recaddr_pf(unsigned long long addr, int *count)
{
	if (addr < 16)
	{
		if (ft_putchar_pf(LHEX[addr]) == -1)
			return (-1);
		++(*count);
		return (0);
	}
	if (ft_recaddr_pf(addr / 16, count) == -1)
		return (-1);
	if (ft_putchar_pf(LHEX[addr % 16]) == -1)
		return (-1);
	++(*count);
	return (0);
}

int	ft_putaddr_pf(unsigned long long addr)
{
	int	count;

	count = 2;
	if (addr == 0)
	{
		if ((write(1, "(nil)", 5) == -1))
			return (-1);
		return (5);
	}
	if ((write(1, "0x", 2)) == -1)
		return (-1);
	if (ft_recaddr_pf(addr, &count) == -1)
		return (-1);
	return (count);
}
