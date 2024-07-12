/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:40:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/12 15:02:20 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num_sp(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '\0' || av[i] == 32)
		return (1);
	while (av[i] != '\0')
	{
		if (av[i] == '-' || av[i] == '+')
		{
			if (i != 0 && av[i - 1] != 32)
				return (1);
			if ((av[i + 1] < '0' || av[i + 1] > '9') || av[i + 1] == '\0')
				return (1);
		}
		if (av[i] == 32 && av[i + 1] == 32)
			return (1);
		if ((av[i] < '0' || av[i] > '9')
			&& (av[i] != 32 && av[i] != '-' && av[i] != '+'))
			return (1);
		++i;
	}
	return (0);
}

int	check_param(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_num_sp(av[i]))
			return (1);
		++i;
	}
	return (0);
}
