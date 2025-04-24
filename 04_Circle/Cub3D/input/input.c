/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:06:24 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/24 18:36:02 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		rotate(int key, t_src *src);
void		move(int key, t_src *src);
int			input_exit(t_src *src);
t_vector	r_matrix(t_vector vec, float radian);

int	input_key(int key, t_src *src)
{
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(key, src);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(key, src);
	else if (key == KEY_ESC)
		input_exit(src);
	return (0);
}

void	rotate(int key, t_src *src)
{
	float		radian;

	radian = to_radian(ROTATE_DEGREE);
	if (key == KEY_LEFT)
		radian = -radian;
	src->dir = r_matrix(src->dir, radian);
	src->plane = r_matrix(src->plane, radian);
}

void	move(int key, t_src *src)
{
	t_vector	r_dir;
	t_vector	move;

	r_dir = r_matrix(src->dir, to_radian(90.f));
	move = get_move(key, src, r_dir);
	if (is_collid(key, src, r_dir, move))
		return ;
	src->player.x += move.x * MOVE_SPEED;
	src->player.y += move.y * MOVE_SPEED;
}

int	input_exit(t_src *src)
{
	int	i;

	i = -1;
	mlx_loop_end(src->canvas->mlx);
	while (++i < WALL_SIZE)
	{
		mlx_destroy_image(src->canvas->mlx, src->textures[i].img);
		free(src->textures[i].path);
	}
	mlx_destroy_image(src->canvas->mlx, src->canvas->img.img);
	src->canvas->img.data = NULL;
	free(src->canvas->img.data);
	i = -1;
	while (++i < src->height)
		free(src->map[i]);
	free(src->map);
	mlx_destroy_window(src->canvas->mlx, src->canvas->win);
	mlx_destroy_display(src->canvas->mlx);
	free(src->canvas->mlx);
	free(src->canvas);
	free(src);
	exit(0);
}

t_vector	r_matrix(t_vector vec, float radian)
{
	t_vector	r;

	r.x = vec.x * cosf(radian) - vec.y * sinf(radian);
	r.y = vec.x * sinf(radian) + vec.y * cosf(radian);
	return (r);
}
