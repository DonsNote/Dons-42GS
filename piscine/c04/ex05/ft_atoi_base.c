/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:28:55 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/02 12:40:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_index(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == a)
			break ;
		i++;
	}
	return (i);
}

int	make_sol(int i, int base_len, char *str, char *base)
{
	int	j;
	int	sol;

	sol = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				sol = sol * base_len + get_index(str[i], base);
				break ;
			}
			j++;
		}
		i++;
	}
	return (sol);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	sol;
	int	base_len;

	i = 0;
	sign = 1;
	sol = 0;
	base_len = check_len(base);
	if (base_len < 2)
		return (0);
	if (check_base(base) == 1)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	sol = make_sol(i, base_len, str, base);
	return (sol * sign);
}
/*
#include <stdio.h>
int	main(void)
{
	char *a = "0123456789";
	char *b = "   ++--123";

	printf("%d", ft_atoi_base(b, a));
}
*/
