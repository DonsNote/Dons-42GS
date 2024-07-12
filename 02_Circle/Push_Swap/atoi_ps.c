/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:43:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/12 15:02:19 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_size(int ac, char **av)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == 32)
				++size;
			++j;
		}
		++i;
		++size;
	}
	return (size);
}

void	check_sign(char sign, long long *sol)
{
	if (sign == '-')
		*sol = *sol * -1;
	return ;
}

void	atoi_ps(char *av, long long *num, int *index)
{
	int			i;
	long long	sol;
	long long	sign;

	i = 0;
	while (av[i] != '\0')
	{
		sol = 0;
		sign = 1;
		while (av[i] == 32 && av[i] != '\0')
			++i;
		if (av[i] == '-' || av[i] == '+')
		{
			check_sign(av[i], &sign);
			++i;
		}
		while (av[i] != 32 && av[i] != '\0')
		{
			sol = (sol * 10) + (av[i] - 48);
			++i;
		}
		num[*index] = (sol * sign);
		++(*index);
	}
	return ;
}

int *check_num(long long *num, int *size)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	j = 0;
	nums = (int *)malloc(sizeof(int) * *size);
	while (i <= *size)
	{
		if (num[i] == num[i + 1])
			return (0);
		if (num[i] < -2147483648 || num[i] > 2147483647)
			return (0);
		++i;
	}
	while (j < *size)
	{
		
	}
}

int	*make_num(int ac, char **av, int *size)
{
	int			i;
	int			index;
	long long	*num;

	*size = check_size(ac, av);
	num = (long long *)malloc(sizeof(int) * *size);
	if (num == 0)
		return (0);
	i = 1;
	index = 0;
	while (index < *size)
	{
		atoi_ps(av[i], num, &index);
		++i;
	}
	return (check_num(num, *size));
}
