/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:40:42 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/03 15:22:19 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*make_sol(char *str, int size, int index)
{
	int		i;
	int		j;
	char	*sol;

	i = index - size;
	j = 0;
	sol = (char *)malloc(sizeof(char) * (size + 1));
	while (size > 0)
	{
		sol[j] = str[i];
		j++;
		i++;
		size--;
	}
	sol[j] = '\0';
	return (sol);
}

int	check_h(char *str, char *set)
{
	int	i;
	int	hsize;
	int	check;

	i = 0;
	hsize = 0;
	check = 0;
	while (str[i] != '\0')
	{
		while (check_set(str[i], set))
			i++;
		while (str[i] != '\0' && !check_set(str[i], set))
		{
			i++;
			check++;
		}
		if (check > 0)
		{
			hsize++;
			check = 0;
		}
	}
	return (hsize);
}

void	check_v(char *str, char *set, char **sol)
{
	int	i;
	int	j;
	int	vsize;

	i = 0;
	j = 0;
	vsize = 0;
	while (str[i] != '\0')
	{
		while (check_set(str[i], set))
			i++;
		while (str[i] != '\0' && !check_set(str[i], set))
		{
			i++;
			vsize++;
		}
		if (vsize > 0)
		{
			sol[j] = make_sol(str, vsize, i);
			j++;
			vsize = 0;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		hsize;
	char	**sol;

	i = 0;
	hsize = check_h(str, charset);
	sol = (char **)malloc(sizeof(char *) * (hsize + 1));
	if (sol == 0)
		return (0);
	sol[hsize] = 0;
	check_v(str, charset, sol);
	while (i < hsize)
	{
		if (sol[i] == 0)
			return (0);
		i++;
	}
	return (sol);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[] = "accaccacca";
	char b[] = "a";
	char **sol = ft_split(a, b);

	for (int i = 0; sol[i] != 0; i++)
	{
		printf("%s\n", sol[i]);
	}
	return (0);
}
*/
