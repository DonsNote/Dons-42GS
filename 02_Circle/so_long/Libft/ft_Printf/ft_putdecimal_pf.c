/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:55:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/01 11:14:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_recdecimal_pf(long long n, int *count)
{
	if (n < 10)
	{
		if (ft_putchar_pf((char)(n + 48)) == -1)
			return (-1);
		++(*count);
		return (0);
	}
	if (ft_recdecimal_pf(n / 10, count) == -1)
		return (-1);
	if (ft_putchar_pf((char)(n % 10 + 48)) == -1)
		return (-1);
	++(*count);
	return (0);
}

int	ft_putdecimal_pf(int n)
{
	int			count;
	long long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		if (ft_putchar_pf('-') == -1)
			return (-1);
		num = num * -1;
		++count;
	}
	if (ft_recdecimal_pf(num, &count) == -1)
		return (-1);
	return (count);
}
