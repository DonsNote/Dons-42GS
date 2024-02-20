/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:24:38 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/04 15:15:01 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

int	check_eq(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			break ;
		i++;
	}
	return (i);
}

long long	ft_atoi_base(char *nbr, char *base)
{
	int			i;
	long long	sign;
	long long	blen;
	long long	sol;

	i = 0;
	sign = 1;
	blen = (long long)ft_strlen(base);
	sol = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (check_eq(nbr[i], base))
	{
		if (!check_eq(nbr[i], base))
			break ;
		sol = sol * blen + get_index(nbr[i], base);
		i++;
	}
	return (sol * sign);
}

int	get_len(long long ten, char *base)
{
	int			i;
	long long	blen;

	i = 0;
	blen = (long long)ft_strlen(base);
	if (ten < 0)
		ten = ten * -1;
	while (ten > 0)
	{
		ten = ten / blen;
		i++;
		printf("%d\n", i);
	}
	return (i);
}

void	rev_sort(int s_len, char *sol, int sign)
{
	int	i;
	char temp;

	i = 0;
	if (sign == 1 && s_len == 3)
	{
		temp = sol[0];
		sol[0] = sol[1];
		sol[1] = temp;
		sol[s_len] = '\0';
		return ;
	}
	while (i < s_len / 2)
	{
		temp = sol[i];
		sol[i] = sol[s_len - i - 1];
		sol[s_len - i - 1] = temp;
		i++;
	}
	sol[s_len] = '\0';
}

void	ft_nbr_base(long long ten, char *base, char *sol, int s_len)
{
	int	i;
	int	sign;
	long long blen;

	i = 0;
	sign = 0;
	blen = (long long)ft_strlen(base);
	if (ten < 0)
	{
		sign = 1;
		ten = ten * -1;
	}
	while (i < s_len)
	{
		sol[i] = base[ten % blen];
		ten = ten / blen;
		i++;
	}
	if (sign == 1)
		sol[i] = '-';
	rev_sort(s_len, sol, sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (nbr[0] == '\0')
		return (0);
	if (base_check(base_from) || base_check(base_to))
		return (0);
	if ((ft_strlen(base_from) < 2) || (ft_strlen(base_to) < 2))
		return (0);
	long long	ten;
	int			sol_len;
	char		*sol;

	ten = ft_atoi_base(nbr, base_from);
	printf("%lld\n", ten);
	sol_len = get_len(ten, base_to);
	printf("solen : %d\n", sol_len);
	if (ten < 0)
		sol_len = sol_len + 1;
	sol = (char *)malloc(sizeof(char) * (sol_len + 1));
	if (sol == 0)
		return (0);
	ft_nbr_base(ten, base_to, sol, sol_len);
	return (sol);
}

int	main(void)
{
	char nbr[] = "A";
	char base_from[] = "AB";
	char base_to[] = "ab";
	char *sol = ft_convert_base(nbr, base_from, base_to);

	printf("%s", sol);
	return (0);
}
