/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:30:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/06 18:12:12 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	make_img_src(t_src **src);
void	put_map(t_src **src);
void	put_img(t_src **src, char img, int wid, int hei);

void	start_window(t_src **src)
{
	(*src)->mlx = mlx_init();
	(*src)->win = mlx_new_window((*src)->mlx,
			(*src)->wid * 32, (*src)->hei * 32, "DonsGame");
	make_img_src(src);
	put_map(src);
	mlx_hook((*src)->win, KeyPress, KeyPressMask, input_key, src);
	mlx_hook((*src)->win, DestroyNotify, SubstructureNotifyMask, input_x, src);
	mlx_loop((*src)->mlx);
	return ;
}

void	finish_window(t_src **src)
{
	mlx_loop_end((*src)->mlx);
	mlx_destroy_image((*src)->mlx, (*src)->anya);
	mlx_destroy_image((*src)->mlx, (*src)->fafa);
	mlx_destroy_image((*src)->mlx, (*src)->mama);
	mlx_destroy_image((*src)->mlx, (*src)->flow);
	mlx_destroy_image((*src)->mlx, (*src)->wall);
	return ;
}

void	make_img_src(t_src **src)
{
	int	xpm_x;
	int	xpm_y;

	(*src)->anya = mlx_xpm_file_to_image((*src)->mlx,
			"./asset/anya.xpm", &xpm_x, &xpm_y);
	(*src)->fafa = mlx_xpm_file_to_image((*src)->mlx,
			"./asset/fafa.xpm", &xpm_x, &xpm_y);
	(*src)->mama = mlx_xpm_file_to_image((*src)->mlx,
			"./asset/mama.xpm", &xpm_x, &xpm_y);
	(*src)->wall = mlx_xpm_file_to_image((*src)->mlx,
			"./asset/wall.xpm", &xpm_x, &xpm_y);
	(*src)->flow = mlx_xpm_file_to_image((*src)->mlx,
			"./asset/flow.xpm", &xpm_x, &xpm_y);
	return ;
}

void	put_map(t_src **src)
{
	int	i;
	int	j;
	int	wid;
	int	hei;

	i = 0;
	wid = 0;
	while ((*src)->map[i] != NULL)
	{
		j = 0;
		hei = 0;
		while ((*src)->map[i][j] != '\0')
		{
			put_img(src, (*src)->map[i][j], wid, hei);
			hei = hei + 32;
			++j;
		}
		wid = wid + 32;
		++i;
	}
	return ;
}

void	put_img(t_src **src, char img, int wid, int hei)
{
	if (img == '1')
		mlx_put_image_to_window((*src)->mlx,
			(*src)->win, (*src)->wall, hei, wid);
	else if (img == '0')
		mlx_put_image_to_window((*src)->mlx,
			(*src)->win, (*src)->flow, hei, wid);
	else if (img == 'P')
		mlx_put_image_to_window((*src)->mlx,
			(*src)->win, (*src)->anya, hei, wid);
	else if (img == 'E')
		mlx_put_image_to_window((*src)->mlx,
			(*src)->win, (*src)->fafa, hei, wid);
	else if (img == 'C')
		mlx_put_image_to_window((*src)->mlx,
			(*src)->win, (*src)->mama, hei, wid);
	return ;
}
