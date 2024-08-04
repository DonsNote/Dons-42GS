/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:54:59 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/04 16:47:50 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	out_line(t_src **src, t_check **flag);
int	src_check(char param, t_check **flag, t_src **src);

int	map_check(t_src **src)
{
	t_check	*flag;

	flag = (t_check *)malloc(sizeof(t_check) * 1);
	if (flag == NULL)
		return (1);
	if (out_line(src, &flag))
		return (1);
	free(flag);
	return (0);
}

int	out_line(t_src **src, t_check **flag)
{
	int	i;
	int	j;

	i = 0;
	while ((*src)->map[i] != NULL)
	{
		j = 0;
		while ((*src)->map[i][j] != '\0')
		{
			if ((i == 0  || i == ((*src)->hei - 1)) && (*src)->map[i][j] != '1')
				return (1);
			if ((j == 0 || j == ((*src)->wid - 1)) && (*src)->map[i][j] != '1')
				return (1);
			if (src_check((*src)->map[i][j], flag, src))
				return (1);
			++j;
		}
		if (j != ((*src)->wid))
			return (1);
		++i;
	}
	return (0);
}

int	src_check(char param, t_check **flag, t_src **src)
{
	if (param != 'P' && param != 'E' && param != 'C' && param != '1' && param != '0')
		return (1);
	if (param == 'P')
	{
		if ((*flag)->p_check == 1)
			return (1);
		(*flag)->p_check = 1;
	}
	if (param == 'E')
	{
		if ((*flag)->e_check == 1)
			return (1);
		(*flag)->e_check = 1;
	}
	if (param == 'C')
	{
		if ((*flag)->c_check == 0)
			(*flag)->c_check = 1;
		(*src)->food++;
	}
	return (0);
}