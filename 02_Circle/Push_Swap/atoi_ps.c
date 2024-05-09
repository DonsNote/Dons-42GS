/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:43:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/09 14:24:05 by dohyuki2         ###   ########.fr       */
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
	while (i <  ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == 32)
			{
				++j;
				++size;
			}
			++j;
		}
		++i;
		++size;
	}
	return (size);
}

int	atoi_ps(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == 32)
	}
}

int	*make_num(int ac, char **av)
{
	int	i;
	int	j;
	int	*num;
	int	size;

	size = check_size(ac, av);
	num = (int *)malloc(sizeof(int) * size);
	if (num == 0)
		return (0);
	i = 0;
	j = 1;
	while (i < ac)
	{
		num[i] = atoi_ps(av[j]);
	}
	return (num);
}