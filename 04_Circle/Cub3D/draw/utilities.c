/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:49:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 19:58:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_pixel(t_texture *texture, int x, int y);
int	get_tex(t_src *src, t_dda *dda, t_texture *texture);
int	max(int a, int b);
int	min(int a, int b);

int	get_num(t_dda *dda)
{
	if (dda->hit == TRUE)
	{
		if (dda->step.y > 0)
			return (NORTH);
		return (SOUTH);
	}
	else
	{
		if (dda->step.x > 0)
			return (WEST);
		return (EAST);
	}
}

int	get_pixel(t_texture *texture, int x, int y)
{
	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (OVERFLOW);
	return (*(int *)(texture->data
		+ (texture->size_line * y + x * texture->bits_pixel / 8)));
}

int	get_tex(t_src *src, t_dda *dda, t_texture *texture)
{
	int		tex_x;
	float	wall_x;

	if (!dda->hit)
		wall_x = src->player.y + dda->w_dist * dda->ray.y;
	else
		wall_x = src->player.x + dda->w_dist * dda->ray.x;
	wall_x -= floorf(wall_x);
	tex_x = wall_x * (float)texture->width;
	if ((!dda->hit && dda->ray.x > 0) || (dda->hit && dda->ray.y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
