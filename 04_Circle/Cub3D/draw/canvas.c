/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:00:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/22 01:04:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_pixel(t_canvas *this, int w, int h, int color);
void	canvas_show(t_canvas *this);
void	destroy_canvas(t_canvas **this_ref);

t_canvas	*init_canvas(int width, int height)
{
	t_canvas	*new;

	new = (t_canvas *)malloc(sizeof(t_canvas));
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

void	draw_pixel(t_canvas *this, int w, int h, int color)
{
	this->img.data[this->width * h + w] = color;
}

void	canvas_show(t_canvas *this)
{
	mlx_put_image_to_window(this->mlx, this->win, this->img.img, 0, 0);
}

void	destroy_canvas(t_canvas **this_ref)
{
	t_canvas	*this;

	this = *this_ref;
	mlx_destroy_image(this->mlx, this->img.img);
	free(this);
	*this_ref = NULL;
}
