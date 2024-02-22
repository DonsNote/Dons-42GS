/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:39:05 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/02 22:47:43 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_nbr(int nb)
{
	nb = nb + 48;
	write(1, &nb, 1);
}

void	print_nbr(long long nb)
{
	if (nb < 10)
	{
		put_nbr(nb);
		return ;
	}
	print_nbr(nb / 10);
	put_nbr(nb % 10);
}

void	ft_putnbr(int nbr)
{
	long long	nb;

	nb = (long long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	print_nbr(nb);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
