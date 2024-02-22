/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:31:05 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/01 22:17:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_set(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str, int size, int index)
{
	int		i;
	int		j;
	char	*sol;

	i = index - size;
	j = 0;
	sol = (char *)malloc(sizeof(char) * (size + 1));
	if (sol == 0)
		return (0);
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

int	check_vsize(char *str, char *charset, char **sol)
{
	int	i;
	int	j;
	int	vsize;

	i = 0;
	j = 0;
	vsize = 0;
	while (str[i] != '\0')
	{
		while (check_set(str[i], charset))
			i++;
		while (str[i] != '\0' && !check_set(str[i], charset))
		{
			i++;
			vsize++;
		}
		if (vsize > 0)
		{
			sol[j] = ft_strdup(str, vsize, i);
			vsize = 0;
			j++;
		}
	}
	return (0);
}

int	check_hsize(char *str, char *charset)
{
	int	i;
	int	check;
	int	hsize;

	i = 0;
	check = 0;
	hsize = 0;
	while (str[i] != '\0')
	{
		while (check_set(str[i], charset))
			i++;
		while (str[i] != '\0' && !check_set(str[i], charset))
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		h_size;
	char	**sol;

	i = 0;
	h_size = check_hsize(str, charset);
	sol = (char **)malloc(sizeof(char *) * (h_size + 1));
	if (sol == 0)
		return (0);
	sol[h_size] = 0;
	check_vsize(str, charset, sol);
	while (i < h_size)
	{
		if (sol[i] == 0)
			return (0);
		i++;
	}
	return (sol);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "aaa12aa123aaa33";
	char b[] = "a";
	char **result = ft_split(a, b);

	for (int i = 0; result[i] != 0; i++)
	{
		printf("%s\n", result[i]);
	}
	return (0);
}
*/
