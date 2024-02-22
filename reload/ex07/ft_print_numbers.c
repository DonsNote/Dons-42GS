/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:33:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/22 15:33:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '1';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}
/*
int main(void)
{
    ft_print_numbers();
    return (0);
}
*/
