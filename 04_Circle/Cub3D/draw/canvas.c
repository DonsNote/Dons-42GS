/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:00:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/24 18:03:23 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_vector(t_src *src);
void	draw_pixel(t_draw *this, int w, int h, int color);
void	canvas_show(t_draw *this);

t_draw	*init_canvas(int width, int height)
{
	t_draw	*new;

	new = (t_draw *)malloc(sizeof(t_draw));
	if (new == NULL)
		error_handle(e_allocate);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, width, height, "cub3D");
	new->width = width;
	new->height = height;
	new->img.img = mlx_new_image(new->mlx, width, height);
	new->img.data = (int *)mlx_get_data_addr(new->img.img,
			&new->img.bits_pixel, &new->img.size_line, &new->img.endian);
	new->draw_pixel = draw_pixel;
	new->show = canvas_show;
	return (new);
}

void	init_vector(t_src *src)
{
	int			i;
	const char	dir[] = {'N', 'E', 'S', 'W'};
	const int	direction[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

	i = -1;
	while (++i < 4)
	{
		if (src->map[(int)src->player.y][(int)src->player.x]
			== dir[i])
			break ;
	}
	src->dir.x = direction[i][0];
	src->dir.y = direction[i][1];
	if (i == 0)
		i = 4;
	src->plane.x = direction[i - 1][0] * FOV;
	src->plane.y = direction[i - 1][1] * FOV;
}

void	draw_pixel(t_draw *this, int w, int h, int color)
{
	this->img.data[this->width * h + w] = color;
}

void	canvas_show(t_draw *this)
{
	mlx_put_image_to_window(this->mlx, this->win, this->img.img, 0, 0);
}
