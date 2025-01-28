/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:37:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/23 15:14:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	input_num(long long n, int i, char *sol);
static char	*make_mem(long long *n, int *i, int *sign);
static int	check_len(long long n);

char	*ft_itoa(int n)
{
	int			i;
	int			sign;
	char		*sol;
	long long	nb;

	nb = (long long)n;
	i = check_len(nb);
	sign = 1;
	sol = make_mem(&nb, &i, &sign);
	if (sol == 0)
		return (0);
	if (sign < 0)
	{
		sol[0] = '-';
		input_num(nb, i, &sol[1]);
	}
	else
		input_num(nb, i, sol);
	return (sol);
}

static void	input_num(long long n, int i, char *sol)
{
	if (n < 10)
	{
		sol[i - 1] = n + 48;
		return ;
	}
	input_num(n / 10, i - 1, sol);
	sol[i - 1] = (n % 10) + 48;
}

static char	*make_mem(long long *n, int *i, int *sign)
{
	char	*sol;

	if (*n < 0)
	{
		*sign = *sign * -1;
		*n = *n * -1;
		sol = (char *)malloc(sizeof(char) * (*i + 2));
		sol[*i + 1] = '\0';
	}
	else
	{
		sol = (char *)malloc(sizeof(char) * (*i + 1));
		sol[*i] = '\0';
	}
	if (sol == 0)
		return (0);
	return (sol);
}

static int	check_len(long long n)
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
