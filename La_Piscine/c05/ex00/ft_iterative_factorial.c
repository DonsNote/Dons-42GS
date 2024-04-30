/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/26 09:59:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sol;

	sol = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		sol = sol * nb;
		nb--;
	}
	return (sol);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d", ft_iterative_factorial(4));
	return (0);
}
*/
