/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:19:15 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/20 16:26:48 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
    if (nb < 0)
		return (0);
    if (nb == 0)
		return (1);
    while (nb > 1)
	{
		i = i * nb;
		nb--;
	}
	return (i);
}
