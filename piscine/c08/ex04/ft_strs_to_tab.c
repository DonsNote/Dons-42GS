/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:42:40 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/03 17:54:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdupcpy(char *str)
{
	int		i;
	int		len;
	char	*sol;

	i = 0;
	len = ft_strlen(str);
	sol = (char *)malloc(sizeof(char) * (len + 1));
	if (sol == 0)
		return (0);
	while (str[i] != '\0')
	{
		sol[i] = str[i];
		i++;
	}
	sol[i] = '\0';
	return (sol);
}

void	sol_free(int i, t_stock_str *sol)
{
	if (i > 0)
	{
		i = i - 1;
		while (i >= 0)
		{
			free(sol[i].copy);
			i--;
		}
	}
	return ;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*sol;

	i = 0;
	sol = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (sol == 0)
		return (0);
	while (i < ac)
	{
		sol[i].size = ft_strlen(av[i]);
		sol[i].str = av[i];
		sol[i].copy = ft_strdupcpy(av[i]);
		if (sol[i].copy == 0)
		{
			sol_free(i, sol);
			return (0);
		}
		i++;
	}
	sol[i].str = 0;
	return (sol);
}
/*
#include <stdio.h>

int	main(void)
{
	char *a[] = {"hellow", "hi"};
	t_stock_str *sol;

	sol = ft_strs_to_tab(2, a);
	for (int i = 0; sol[i].str != 0; i++)
	{
		printf("%d\n", sol[i].size);
		printf("%s\n", sol[i].str);
		printf("%s\n", sol[i].copy);
	}
	return (0);
}
*/
