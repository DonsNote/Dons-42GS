/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:33:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/04 23:30:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_w(t_src **src, int i, int j)
{
	if ((*src)->map[i - 1][j] == '1')
		return ;
	else if ((*src)->map[i - 1][j] == 'E' && (*src)->food != 0)
		return ;
	else if ((*src)->map[i - 1][j] == 'E' && (*src)->food == 0)
	{
		finish_window(src);
		return ;
	}
	else if ((*src)->map[i - 1][j] == 'C')
		(*src)->food--;
	(*src)->map[i][j] = '0';
	(*src)->map[i - 1][j] = 'P';
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->flow, j * 32, i * 32);
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->anya, j * 32, (i - 1) * 32);
	return ;
}

void	move_a(t_src **src, int i, int j)
{
	if ((*src)->map[i][j - 1] == '1')
		return ;
	else if ((*src)->map[i][j - 1] == 'E' && (*src)->food != 0)
		return ;
	else if ((*src)->map[i][j - 1] == 'E' && (*src)->food == 0)
	{
		finish_window(src);
		return ;
	}
	else if ((*src)->map[i][j - 1] == 'C')
		(*src)->food--;
	(*src)->map[i][j] = '0';
	(*src)->map[i][j - 1] = 'P';
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->flow, j * 32, i * 32);
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->anya, (j - 1) * 32, i * 32);
	return ;
}

void	move_s(t_src **src, int i, int j)
{
	if ((*src)->map[i + 1][j] == '1')
		return ;
	else if ((*src)->map[i + 1][j] == 'E' && (*src)->food != 0)
		return ;
	else if ((*src)->map[i + 1][j] == 'E' && (*src)->food == 0)
	{
		finish_window(src);
		return ;
	}
	else if ((*src)->map[i][j - 1] == 'C')
		(*src)->food--;
	(*src)->map[i][j] = '0';
	(*src)->map[i + 1][j] = 'P';
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->flow, j * 32, i * 32);
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->anya, j * 32, (i + 1) * 32);
	return ;
}

void	move_d(t_src **src, int i, int j)
{
	if ((*src)->map[i][j + 1] == '1')
		return ;
	else if ((*src)->map[i][j + 1] == 'E' && (*src)->food != 0)
		return ;
	else if ((*src)->map[i][j + 1] == 'E' && (*src)->food == 0)
	{
		finish_window(src);
		return ;
	}
	else if ((*src)->map[i][j + 1] == 'C')
		(*src)->food--;
	(*src)->map[i][j] = '0';
	(*src)->map[i][j + 1] = 'P';
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->flow, j * 32, i * 32);
	mlx_put_image_to_window((*src)->mlx,
		(*src)->win, (*src)->anya, (j + 1) * 32, i * 32);
	return ;
}
