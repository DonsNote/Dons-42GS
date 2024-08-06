/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 01:36:16 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/06 15:19:35 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**make_check_map(t_src **src)
{
	int		i;
	int		j;
	char	**check;

	i = 0;
	check = (char **)malloc(sizeof(char *) * ((*src)->hei + 1));
	if (check == NULL)
		return (0);
	check[(*src)->hei] = NULL;
	while (i < (*src)->hei)
	{
		check[i] = (char *)malloc(sizeof(char) * (*src)->wid + 1);
		if (check[i] == NULL)
			return (0);
		check[i][(*src)->wid] = '\0';
		j = 0;
		while (j < (*src)->wid)
		{
			check[i][j] = '0';
			++j;
		}
		++i;
	}
	return (check);
}

void	mark_map(t_src **src, char **check, int i, int j)
{
	if ((*src)->map[i + 1][j] != '1' && (*src)->map[i + 1][j] != 'E')
		check[i + 1][j] = '1';
	if ((*src)->map[i - 1][j] != '1' && (*src)->map[i - 1][j] != 'E')
		check[i - 1][j] = '1';
	if ((*src)->map[i][j + 1] != '1' && (*src)->map[i][j + 1] != 'E')
		check[i][j + 1] = '1';
	if ((*src)->map[i][j - 1] != '1' && (*src)->map[i][j - 1] != 'E')
		check[i][j - 1] = '1';
	return ;
}

void	scan_map(t_src **src, char **check)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k <= ((*src)->wid * (*src)->hei))
	{
		i = 0;
		while (check[i] != NULL)
		{
			j = 0;
			while (check[i][j] != '\0')
			{
				if (check[i][j] == '1')
					mark_map(src, check, i, j);
				++j;
			}
			++i;
		}
		++k;
	}
	return ;
}

void	free_map(t_src **src, char **check)
{
	int	i;

	i = 0;
	while (i < (*src)->hei + 1)
	{
		free(check[i]);
		++i;
	}
	free(check);
	return ;
}

int	bit_map(t_src **src, char **check)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < (*src)->hei)
	{
		j = 0;
		while (j < (*src)->wid)
		{
			if ((*src)->map[i][j] == 'C' && check[i][j] != '1')
				return (1);
			if ((*src)->map[i][j] == 'C' && check[i][j] == '1')
				++c;
			++j;
		}
		++i;
	}
	if ((*src)->food != c)
		return (1);
	free_map(src, check);
	return (0);
}
