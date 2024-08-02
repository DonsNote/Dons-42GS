/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:30:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 22:02:51 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*make_img_src(t_src **src);

void	start_window(t_src **src)
{
	(*src)->mlx = mlx_init();
	(*src)->win = mlx_new_window((*src)->mlx, (*src)->hei * 32, (*src)->wid * 32, "DonsGame");
	make_img_src(src);
	mlx_key_hook((*src)->win, input_key, (void *)0);
	return ;
}

int	input_key(int key, void *param)
{
	
}

void	*make_img_src(t_src **src)
{
	int	xpm_x;
	int	xpm_y;

	(*src)->anya = mlx_xpm_file_to_image((*src)->mlx,
	"../../asset/anya.xpm", &xpm_x, &xpm_y);
	(*src)->papa = mlx_xpm_file_to_image((*src)->mlx,
	"../../asset/papa.xpm", &xpm_x, &xpm_y);
	(*src)->mama = mlx_xpm_file_to_image((*src)->mlx,
	"../../asset/mama.xpm", &xpm_x, &xpm_y);
	(*src)->wall = mlx_xpm_file_to_image((*src)->mlx,
	"../../asset/wall.xpm", &xpm_x, &xpm_y);
	(*src)->flow = mlx_xpm_file_to_image((*src)->mlx,
	"../../asset/flow.xpm", &xpm_x, &xpm_y);
	return ;
}

void	put_map(t_src **src)
{
	int	i;
	int	j;
	int	wid;
	int hei;

	i = 0;
	hei = 0;
	while ((*src)->map[i] != '\0')
	{
		j = 0;
		wid = 0;
		while ((*src)->map[i][j] != '\0')
		{
			if ((*src)->map[i][j] == '1')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->wall, wid, hei);
			else if ((*src)->map[i][j] == '0')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->flow, wid, hei);
			else if ((*src)->map[i][j] == 'P')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->anya, wid, hei);
			else if ((*src)->map[i][j] == 'E')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->papa, wid, hei);
			else if ((*src)->map[i][j] == 'C')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->mama, wid, hei);
			wid = wid + 32;
			++j;
		}
		hei = hei + 32;
		++i;
	}
	return ;
}