/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:58:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 17:18:05 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		drawing(t_src *src);
void		draw_line(t_src *src, t_dda *dda, int i);
t_drawing	init_drawing(t_src *src, t_dda *dda, t_texture *texture);

int	draw(t_src *src)
{
	if (src->frame_conut % RENDER == 0)
		drawing(src);
	++src->frame_conut;
	return (0);
}

void	drawing(t_src *src)
{
	t_vector	ray;
	t_dda		*dda;
	float		ratio;
	int			i;

	i = -1;
	while (++i < WIDTH)
	{
		ratio = 2.f * (float)i / (float)WIDTH - 1.f;
		ray.x = src->dir.x + (src->plane.x * ratio);
		ray.y = src->dir.y + (src->plane.y * ratio);
		dda = raycasting(src, ray);
		draw_line(src, dda, i);
		src->buffer[i] = dda->w_dist;
		free(dda);
	}
	render_minimap(src);
	src->canvas->show(src->canvas);
	return ;
}

void	draw_line(t_src *src, t_dda *dda, int i)
{
	t_texture	texture;
	t_drawing	drawing;

	texture = src->textures[get_num(dda)];
	drawing = init_drawing(src, dda, &texture);
	while (drawing.pos < HEIGHT)
	{
		if (drawing.pos >= 0 && drawing.pos < drawing.line_s)
			src->canvas->draw_pixel(src->canvas,
				WIDTH - 1 - i, drawing.pos, src->c_color);
		else if (drawing.pos >= drawing.line_s
			&& drawing.pos < min(drawing.line_e, HEIGHT))
		{
			if (drawing.pos >= 0)
				src->canvas->draw_pixel(src->canvas, WIDTH - 1 - i,
					drawing.pos, get_pixel(&texture, texture.width - 1
						- drawing.t_pos.x, drawing.t_pos.y));
			drawing.t_pos.y += drawing.t_step;
		}
		else if (drawing.pos >= drawing.line_e)
			src->canvas->draw_pixel(src->canvas,
				WIDTH - 1 - i, drawing.pos, src->f_color);
		++drawing.pos;
	}
	return ;
}

t_drawing	init_drawing(t_src *src, t_dda *dda, t_texture *texture)
{
	t_drawing	drawing;

	drawing.line_h = (float)HEIGHT / dda->w_dist * 1.2;
	drawing.line_s = (float)HEIGHT / 2.f - (float)(drawing.line_h) / 2.f;
	drawing.line_e = (float)HEIGHT / 2.f + (float)(drawing.line_h) / 2.f;
	drawing.t_pos = (t_vector){get_tex(src, dda, texture), 0};
	drawing.t_step = (float)texture->height / (float)(drawing.line_h);
	drawing.pos = min(drawing.line_s, 0);
	return (drawing);
}
