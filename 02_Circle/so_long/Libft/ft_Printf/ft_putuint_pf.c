/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:33:29 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/29 00:52:34 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recuint_pf(long long n, int *count)
{
	if (n < 10)
	{
		if (ft_putchar_pf((char)(n + 48)) == -1)
			return (-1);
		++(*count);
		return (0);
	}
	if (ft_recuint_pf(n / 10, count) == -1)
		return (-1);
	if (ft_putchar_pf((char)(n % 10 + 48)) == -1)
		return (-1);
	++(*count);
	return (0);
}

int	ft_putuint_pf(unsigned int n)
{
	int			count;
	long long	num;

	count = 0;
	num = n;
	if (ft_recuint_pf(num, &count) == -1)
		return (-1);
	return (count);
}
