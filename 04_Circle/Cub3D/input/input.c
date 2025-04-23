/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:06:24 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 14:50:34 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		rotate(int key, t_src *src);
void		move(int key, t_src *src);
int			input_exit(void);
t_vector	r_matrix(t_vector vec, float radian);

int	input_key(int key, t_src *src)
{
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(key, src);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(key, KEY_ESC);
	else if (key == KEY_ESC)
		exit(0);
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
	if (is_col(key, src, r_dir, move))
		return ;
	src->player.x += move.x * MOVE_SPEED;
	src->player.y += move.y * MOVE_SPEED;
}

int	input_exit(void)
{
	exit(0);
	return (1);
}

t_vector	r_matrix(t_vector vec, float radian)
{
	t_vector	r;

	r.x = vec.x * cosf(radian) - vec.y * sinf(radian);
	r.y = vec.x * sinf(radian) + vec.y * cosf(radian);
	return (r);
}
