/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:40:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/02 12:09:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num_sp(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if ((av[i] < '0' || av[i] > '9') && av[i] != 32)
			return (1);
		++i;
	}
	if (av[i - 1] == 32)
		return (1);
	return (0);
}

int	check_num(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] < '0' && av[i] > '9')
			return (1);
		++i;
	}
	return (0);
}

int	check_param(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		if (check_num_sp(av[1]))
			return (1);
	}
	i = 1;
	while (i < ac)
	{
		if (av[i][1] != '\0')
			if (check_num_sp(av[i]))
				return (1);
		if (check_num(av[i]))
			return (1);
		++i;
	}
	return (0);
}
