/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:40:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/17 14:34:04 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *av);
int	check_sign(char *av, int *i);
int	check_len(char *av, int *i);

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

int	check_num(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '\0')
		return (1);
	while (av[i] != '\0')
	{
		while (av[i] == 32 && av[i] != '\0')
			++i;
		if (av[i] == '-' || av[i] == '+')
		{
			if (check_sign(av, &i))
				return (1);
		}
		if (check_len(av, &i))
			return (1);
	}
	return (0);
}

int	check_sign(char *av, int *i)
{
	if (*i != 0 && av[*i - 1] != 32)
		return (1);
	if ((av[*i + 1] < '0' || av[*i + 1] > '9') || av[*i + 1] == '\0')
		return (1);
	++*i;
	return (0);
}

int	check_len(char *av, int *i)
{
	int	len;

	len = 0;
	while (av[*i] != 32 || av[*i] != '\0')
	{
		if (av[*i] < '0' || av[*i] > '9')
			return (1);
		++*i;
		++len;
	}
	if (len > 11)
		return (1);
	return (0);
}
