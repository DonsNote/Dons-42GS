/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:48:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/02 13:22:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	print_time(int a, int b)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
	ft_putchar(32);
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	second;
	int	nano;

	second = 0;
	nano = second + 1;
	while (second <= 98)
	{
		print_time(second, nano);
		nano++;
		if (nano == 100)
		{
			second++;
			nano = second + 1;
		}
		if (second <= 98)
			write(1, ", ", 2);
	}
}

int main(void)
{
	ft_print_comb2();
	return (0);
}
