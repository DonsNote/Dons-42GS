/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:54:22 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/10 02:24:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	error_print(int i)
{
	if (i == 1)
		printf("Invalied Param!\n");
	if (i == 2)
		printf("Allocate Fail!\n");
	if (i == 3)
		printf("Plz input Only Num!\n");
	if (i == 4)
		printf("Don`t input the Minus!\n");
	if (i == 5)
		printf("Anybody there?!\n");
	return (2);
}

int	check_num(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if ((av[i] < '0' || av[i] > '9') && (av[i] != '-' && av[i] != '+'))
		{
			error_print(3);
			return (1);
		}
		++i;
	}
	return (0);
}

int	check_error(int ac, char **av)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	if (ft_atoi(av[1]) == 0)
	{
		error_print(5);
		return (1);
	}
	while (i < ac)
	{
		if (check_num(av[i]))
			return (1);
		check = ft_atoi(av[i]);
		if (check < 0)
		{
			error_print(4);
			return (1);
		}
		++i;
	}
	return (0);
}
