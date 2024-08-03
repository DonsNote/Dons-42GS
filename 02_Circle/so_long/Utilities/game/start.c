/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:30:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/03 19:08:00 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	make_img_src(t_src **src);
void	put_map(t_src **src);
int		input_key(int key, void **param);
int		input_mouse(int key, void **src);

void	start_window(t_src **src)
{
	(*src)->mlx = mlx_init();
	(*src)->win = mlx_new_window((*src)->mlx, (*src)->wid * 32, (*src)->hei * 32, "DonsGame");
	make_img_src(src);
	put_map(src);
	mlx_key_hook((*src)->win, input_key, src);
	mlx_hook((*src)->win, 17, 0, input_x, src);
	mlx_loop((*src)->mlx);
}

int	input_key(int key, void **src)
{
	ft_printf("key = [%d]\n", key);
	return (0);
}

int	input_x(int key, void **src)
{
	ft_printf("test key = []\n");
	return (0);
}

void	make_img_src(t_src **src)
{
	int	xpm_x;
	int	xpm_y;

	(*src)->anya = mlx_xpm_file_to_image((*src)->mlx, "./asset/anya.xpm", &xpm_x, &xpm_y);
	(*src)->fafa = mlx_xpm_file_to_image((*src)->mlx, "./asset/fafa.xpm", &xpm_x, &xpm_y);
	(*src)->mama = mlx_xpm_file_to_image((*src)->mlx, "./asset/mama.xpm", &xpm_x, &xpm_y);
	(*src)->wall = mlx_xpm_file_to_image((*src)->mlx, "./asset/wall.xpm", &xpm_x, &xpm_y);
	(*src)->flow = mlx_xpm_file_to_image((*src)->mlx, "./asset/flow.xpm", &xpm_x, &xpm_y);
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
			if ((*src)->map[i][j] == '1')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->wall, hei, wid);
			else if ((*src)->map[i][j] == '0')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->flow, hei, wid);
			else if ((*src)->map[i][j] == 'P')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->anya, hei, wid);
			else if ((*src)->map[i][j] == 'E')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->fafa, hei, wid);
			else if ((*src)->map[i][j] == 'C')
				mlx_put_image_to_window((*src)->mlx, (*src)->win, (*src)->mama, hei, wid);
			hei = hei + 32;
			++j;
		}
		wid = wid + 32;
		++i;
	}
	return ;
}