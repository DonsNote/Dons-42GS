/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:43:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/06 14:38:56 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_size(int ac, char **av)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	j = 0;
	size = 0;
	while (i <  ac)
	{
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

int	*atoi_ps(int ac, char **av)
{
	int	*i;
	int	size;

	size = check_size(ac, av);
	i = (int *)malloc(sizeof(int) * size);
	if (i == 0)
		return (0);
	
	return (i);
}