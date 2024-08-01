/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:28:06 by don               #+#    #+#             */
/*   Updated: 2024/03/29 01:55:46 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_recuhex_pf(unsigned long long n, int *count)
{
	if (n < 16)
	{
		if (ft_putchar_pf(UHEX[n]) == -1)
			return (-1);
		++(*count);
		return (0);
	}
	if (ft_recuhex_pf(n / 16, count) == -1)
		return (-1);
	if (ft_putchar_pf(UHEX[n % 16]) == -1)
		return (-1);
	++(*count);
	return (0);
}

int	ft_putuhex_pf(unsigned int n)
{
	int					count;
	unsigned long long	num;

	count = 0;
	num = n;
	if (ft_recuhex_pf(num, &count) == -1)
		return (-1);
	return (count);
}
