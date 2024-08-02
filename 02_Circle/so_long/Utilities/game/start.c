/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:30:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 13:40:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*make_img_src(void **mlx, t_imgsrc **img_src);

void	start_window(int map_h, int map_w)
{
	void		*mlx;
	void		*win;
	t_imgsrc	*imgsrc;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map_h * TILE_SIZE, map_w * TILE_SIZE, "DonsNote");
	make_img_src(&mlx, &imgsrc);
	mlx_key_hook(win, input_key, (void *)0);
	
	return ;
}

int	input_key(int key, void *param)
{
	
}

void	*make_img_src(void **mlx, t_imgsrc **img_src)
{
	int	xpm_x;
	int	xpm_y;

	(*img_src)->anya = mlx_xpm_file_to_image(*mlx, "../../asset/anya.xpm", &xpm_x, &xpm_y);
	(*img_src)->papa = mlx_xpm_file_to_image(*mlx, "../../asset/papa.xpm", &xpm_x, &xpm_y);
	(*img_src)->mama = mlx_xpm_file_to_image(*mlx, "../../asset/mama.xpm", &xpm_x, &xpm_y);
	(*img_src)->wall = mlx_xpm_file_to_image(*mlx, "../../asset/wall.xpm", &xpm_x, &xpm_y);
	(*img_src)->flow = mlx_xpm_file_to_image(*mlx, "../../asset/flow.xpm", &xpm_x, &xpm_y);
	return ;
}

void	put_map(t_imgsrc *imgsrc, char **map, void *mlx, void *win)
{
	int	i;
	int	j;
	int	wid;
	int hig;

	i = 0;
	hig = 0;
	while (map[i] != '\0')
	{
		j = 0;
		wid = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, imgsrc->wall, wid, hig);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, imgsrc->flow, wid, hig);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, imgsrc->anya, wid, hig);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, imgsrc->papa, wid, hig);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, imgsrc->mama, wid, hig);
			wid = wid + 32;
			++j;
		}
		hig = hig + 32;
		++i;
	}
	return ;
}