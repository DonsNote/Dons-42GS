/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:56:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/01 11:14:35 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_reclhex_pf(unsigned long long n, int *count)
{
	if (n < 16)
	{
		if (ft_putchar_pf(LHEX[n]) == -1)
			return (-1);
		++(*count);
		return (0);
	}
	if (ft_reclhex_pf(n / 16, count) == -1)
		return (-1);
	if (ft_putchar_pf(LHEX[n % 16]) == -1)
		return (-1);
	++(*count);
	return (0);
}

int	ft_putlhex_pf(unsigned int n)
{
	int					count;
	unsigned long long	num;

	count = 0;
	num = n;
	if (ft_reclhex_pf(num, &count) == -1)
		return (-1);
	return (count);
}
