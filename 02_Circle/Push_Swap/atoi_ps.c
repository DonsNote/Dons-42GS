/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:43:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/13 12:54:18 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	atoi_ps(char *av, int *num, int *index)
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
		while (av[i] != 32 || av[i] != '\0')
		{
			sol = (sol * 10) + (av[i] - 48);
			++i;
		}
		num[*index] = ((int)sol * (int)sign);
		++index;
	}
	return ;
}

int	*make_num(int ac, char **av)
{
	int	i;
	int	index;
	int	*num;
	int	size;

	size = check_size(ac, av);
	num = (int *)malloc(sizeof(int) * size);
	if (num == 0)
		return (0);
	i = 1;
	index = 0;
	while (index < size)
	{
		atoi_ps(av[i], num, &index);
		++i;
	}
	return (num);
}
