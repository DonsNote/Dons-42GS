/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:45:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 19:56:16 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_background(t_src *src);
void	draw_minimap(t_src *src, t_vector start_pos);
int		set_color(t_src *src, t_vector cur);
void	big_draw(t_src *src, t_vector cur, t_vector start_pos, int color);

void	render_minimap(t_src *src)
{
	t_vector	start_pos;

	start_pos.x = MINI_POS + (CENTER - src->player.x) * CUB;
	start_pos.y = MINI_POS + (CENTER - src->player.y) * CUB;
	draw_background(src);
	draw_minimap(src, start_pos);
}

void	draw_background(t_src *src)
{
	int	row;
	int	col;
	int	color;

	row = MINI_POS;
	while (row < MINI_SIZE)
	{
		col = MINI_POS;
		while (col < MINI_SIZE)
		{
			if (row < MINI_POS + BORDER || col < MINI_POS + BORDER
				|| row > MINI_SIZE - BORDER || col > MINI_SIZE - BORDER)
				color = Y;
			else
				color = B;
			src->canvas->draw_pixel(src->canvas, col, row, color);
			++col;
		}
		++row;
	}
	return ;
}

void	draw_minimap(t_src *src, t_vector start_pos)
{
	int	row;
	int	col;
	int	color;

	row = 0;
	while (row < src->height)
	{
		col = 0;
		while (col < src->width)
		{
			color = set_color(src, (t_vector){col, row});
			if (color != -1)
				big_draw(src, (t_vector){col, row}, start_pos, color);
			++col;
		}
		++row;
	}
	big_draw(src, (t_vector){src->player.x - 0.5, src->player.y - 0.5},
		start_pos, BU);
}

int	set_color(t_src *src, t_vector cur)
{
	if (src->map[(int)cur.y][(int)cur.x] == '1')
		return (GR);
	else if (src->map[(int)cur.y][(int)cur.x] == '0'
		|| src->map[(int)cur.y][(int)cur.x] == 'N'
		|| src->map[(int)cur.y][(int)cur.x] == 'W'
		|| src->map[(int)cur.y][(int)cur.x] == 'E'
		|| src->map[(int)cur.y][(int)cur.x] == 'S')
		return (W);
	else if (src->map[(int)cur.y][(int)cur.x] == '4'
		|| src->map[(int)cur.y][(int)cur.x] == '5')
		return (G);
	else if (src->map[(int)cur.y][(int)cur.x] == '3')
		return (R);
	else
		return (-1);
}

void	big_draw(t_src *src, t_vector cur, t_vector start_pos, int color)
{
	int	row;
	int	col;

	row = 0;
	while (row < CUB)
	{
		col = -1;
		while (++col < CUB)
		{
			if (start_pos.x + col + cur.x * CUB < MINI_POS + BORDER
				|| start_pos.x + col + cur.x * CUB > MINI_SIZE - BORDER + 1
				|| start_pos.y + row + cur.y * CUB < MINI_POS + BORDER
				|| start_pos.y + row + cur.y * CUB > MINI_SIZE - BORDER + 1)
				continue ;
			src->canvas->draw_pixel(src->canvas
				, start_pos.x + col + cur.x * CUB
				, start_pos.y + row + cur.y * CUB, color);
		}
		++row;
	}
	return ;
}
