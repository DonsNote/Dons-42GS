/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/25 22:12:28 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sol;

	sol = 1;
	if (power < 0)
		return (0);
	while (power != 0)
	{
		sol = nb * sol;
		power--;
	}
	return (sol);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d",ft_iterative_power(3, 3));
	return (0);
}
*/
