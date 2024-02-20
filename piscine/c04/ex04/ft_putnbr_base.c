/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:09:34 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/27 17:55:05 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] != base[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	print_nbr(long long nbr, long long b_len, char *base)
{
	if (nbr < b_len)
		write(1, &base[nbr], 1);
	else
	{
		print_nbr(nbr / b_len, b_len, base);
		print_nbr(nbr % b_len, b_len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	i;
	long long	n;

	n = (long long)nbr;
	i = check_base_len(base);
	if (i < 2)
		return ;
	if (check_base(base))
		return ;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	print_nbr(n, i, base);
}
/*
int main(void)
{
	char a[] = "01";
	ft_putnbr_base(8, a);
	return (0);
}
*/
