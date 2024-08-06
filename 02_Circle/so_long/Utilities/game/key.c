/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:06:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/06 18:04:14 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	where_p(t_src **src, int *i, int *j);

int	input_x(void **param)
{
	t_src	**src;

	src = (t_src **)param;
	finish_window(src);
	return (0);
}

int	input_key(int key, void **param)
{
	int		i;
	int		j;
	t_src	**src;

	i = 0;
	j = 0;
	src = (t_src **)param;
	where_p(src, &i, &j);
	if (key == 65307)
		finish_window(src);
	else if (key == 119 || key == 65362)
		move_w(src, i, j);
	else if (key == 97 || key == 65361)
		move_a(src, i, j);
	else if (key == 115 || key == 65364)
		move_s(src, i, j);
	else if (key == 100 || key == 65363)
		move_d(src, i, j);
	return (0);
}

void	where_p(t_src **src, int *i, int *j)
{
	while (*i < ((*src)->hei))
	{
		*j = 0;
		while (*j < ((*src)->wid))
		{
			if ((*src)->map[*i][*j] == 'P')
				return ;
			++*j;
		}
		++*i;
	}
	return ;
}
