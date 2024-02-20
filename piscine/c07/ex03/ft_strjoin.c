/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:39:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/31 20:28:49 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_total_len(int size, char **str, char *sep)
{
	int	sep_len;
	int	str_len;
	int	total_len;

	sep_len = check_len(sep) * (size - 1);
	str_len = 0;
	while (size > 0)
	{
		str_len = str_len + check_len(str[size - 1]);
		size--;
	}
	total_len = sep_len + str_len;
	return (total_len);
}

void	ft_strcpy(int size, char **str, char *sep, char *sol)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < size)
	{
		j = 0;
		while (str[k][j] != '\0')
			sol[i++] = str[k][j++];
		j = 0;
		if (k < size - 1)
		{
			while (sep[j] != '\0')
				sol[i++] = sep[j++];
		}
		k++;
	}
	sol[i] = '\0';
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*sol;
	int		total_len;

	if (size == 0)
	{
		sol = (char *)malloc(sizeof(char) * 1);
		sol[0] = 0;
		return (sol);
	}
	total_len = get_total_len(size, str, sep);
	sol = (char *)malloc(sizeof(char) * total_len + 1);
	if (sol == 0)
		return (0);
	ft_strcpy(size, str, sep, sol);
	return (sol);
}
/*
#include <stdio.h>

int main(void)
{
	char *s;
	char *a[] = {"123", "123", "123"};
	char b[] = ":";

	s = ft_strjoin(3, a, b);

	printf("%s", s);
	free(s);
	return (0);
}
*/
