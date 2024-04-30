/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:34:22 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/22 16:10:13 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	char	a;
	char	b;

	a = 'P';
	b = 'N';
	if (n < 0)
		ft_putchar(b);
	else
		ft_putchar(a);
}
/*
#include <stdlib.h>
int main(int ac, char **av)
{
    (void)ac;
    ft_is_negative(atoi(av[1]));
    return (0);
}
*/
