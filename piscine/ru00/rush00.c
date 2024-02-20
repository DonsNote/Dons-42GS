/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:03:43 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/16 19:47:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	rush(int x, int y)
{
	int	w;
	int	h;

	w = 1;
	h = 1;
	while (w <= x && h <= y)
	{
		if (w == 1 && (h == 1 || h == y))
			ft_putchar('o');
		else if (w == x && (h == 1 || h == y))
			ft_putchar('o');
		else if (h == 1 || h == y)
			ft_putchar('-');
		else if (w == 1 || w == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
		w++;
		if (w == x + 1)
		{
			ft_putchar('\n');
			h++;
			w = 1;
		}
	}
}
