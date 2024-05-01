/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:40:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/01 11:09:10 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] < '0' || av[i] > '9')
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
		if (check_num(av[i]))
			return (1);
		++i;
	}
	return (0);
}
