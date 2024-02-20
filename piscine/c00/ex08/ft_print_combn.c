/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:55:31 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/25 17:20:10 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int *arr, int max)
{
	int		i;
	char	a;

	i = 0;
	while (arr[i] != 10)
	{
		a = arr[i] + 48;
		write(1, &a, 1);
		i++;
	}
	if (arr[0] != 10 - max)
	{
		write(1, ", ", 2);
	}
}

void	recursive(int *arr, int deep, int max, int index)
{
	int	i;

	i = index;
	if (deep == max)
	{
		print_num(arr, max);
		return ;
	}
	while (i < 10)
	{
		arr[deep] = i;
		recursive(arr, deep + 1, max, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[10];

	i = 0;
	while (i < 10)
	{
		arr[i] = 10;
		i++;
	}
	recursive(arr, 0, n, 0);
}
/*
int main(void)
{
	ft_print_combn(9);
	return (0);
}
*/
