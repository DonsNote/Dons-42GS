/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:43:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/23 11:31:56 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		make_size(int ac, char **av);
void	atoi_ps(char *av, long long *num, int *index);
void	make_sign(char sign, long long *sol);
int		*convert_num(long long *num, int *size);

int	*make_num(int ac, char **av, int *size)
{
	int			i;
	int			index;
	long long	*num;

	*size = make_size(ac, av);
	num = (long long *)malloc(sizeof(long long) * *size);
	if (num == 0)
		return (0);
	i = 1;
	index = 0;
	while (index < *size)
	{
		atoi_ps(av[i], num, &index);
		++i;
	}
	return (convert_num(num, size));
}

int	make_size(int ac, char **av)
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
			while (av[i][j] == 32 && av[i][j] != '\0')
				++j;
			if (av[i][j] != 32 && av[i][j] != '\0')
				++size;
			while (av[i][j] != 32 && av[i][j] != '\0')
				++j;
		}
		++i;
	}
	return (size);
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
			make_sign(av[i], &sign);
			++i;
		}
		while (av[i] >= '0' && av[i] <= '9')
		{
			sol = (sol * 10) + (av[i] - 48);
			++i;
		}
		num[*index] = (sol * sign);
		++*index;
		if (av[i] != '\0')
			return ;
	}
	return ;
}

void	make_sign(char sign, long long *sol)
{
	if (sign == '-')
		*sol = *sol * -1;
	return ;
}

int	*convert_num(long long *num, int *size)
{
	int			i;
	int			j;
	int			*nums;

	i = 0;
	nums = (int *)malloc(sizeof(int) * *size);
	if (nums == 0)
		return (0);
	while (i < *size)
	{
		j = i + 1;
		while (j < *size)
		{
			if (num[i] == num[j])
				return (0);
			++j;
		}
		if (num[i] < -2147483648 || num[i] > 2147483647)
			return (0);
		nums[i] = (int)num[i];
		++i;
	}
	free(num);
	return (nums);
}
