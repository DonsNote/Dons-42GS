/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:37:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/04 12:41:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	input_num(int n, int i, char *sol)
{
	if (n < 10)
	{
		sol[i - 1] = n + 48;
		return ;
	}
	input_num(n / 10, i - 1, sol);
	sol[i - 1] = (n % 10) + 48;
}

static int	make_mem(int *n, int *i, int *sign, char **sol)
{
	if (*n < 0)
	{
		*sign = *sign * -1;
		*n = *n * -1;
		*sol = (char *)malloc(sizeof(char) * (*i + 2));
	}
	else
		*sol = (char *)malloc(sizeof(char) * (*i + 1));
	if (sol == 0)
		return (0);
	return (1);
}

static int	check_l(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	if (i == 0)
		++i;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*sol;

	i = check_l(n);
	sign = 1;
	sol = 0;
	if (make_mem(&n, &i, &sign, &sol) == 0)
		return (0);
	if (sign < 0)
	{
		sol[0] = '-';
		input_num(n, i, &sol[1]);
	}
	else
		input_num(n, i, sol);
	return (sol);
}
