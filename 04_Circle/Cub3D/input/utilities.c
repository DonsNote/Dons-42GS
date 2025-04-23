/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:38:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 19:34:44 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_vector	get_move(int key, t_src *src, t_vector r_dir);
_Bool		is_collid(int key, t_src *src, t_vector r_dir, t_vector m_dir);
t_vector	get_player_side(int key, t_src *src, t_vector r_dir, int side);

float	to_radian(float degree)
{
	return (degree * 3.14159265358979323846 / 180.f);
}

t_vector	get_move(int key, t_src *src, t_vector r_dir)
{
	t_vector	move;

	if (key == KEY_W)
		move = (t_vector){src->dir.x, src->dir.y};
	else if (key == KEY_S)
		move = (t_vector){-src->dir.x, -src->dir.y};
	else if (key == KEY_A)
		move = (t_vector){-r_dir.x, -r_dir.y};
	else
		move = (t_vector){r_dir.x, r_dir.y};
	return (move);
}

_Bool	is_collid(int key, t_src *src, t_vector r_dir, t_vector m_dir)
{
	t_vector	tmp_pos;
	t_dda		*l;
	t_dda		*r;

	l = NULL;
	r = NULL;
	tmp_pos = src->player;
	src->player = get_player_side(key, src, r_dir, LEFT);
	l = raycasting(src, m_dir);
	src->player = tmp_pos;
	src->player = get_player_side(key, src, r_dir, RIGHT);
	r = raycasting(src, m_dir);
	src->player = tmp_pos;
	if ((l->hit && l->dist.y <= MOVE_SPEED + FAT)
		|| (!l->hit && l->dist.x <= MOVE_SPEED + FAT)
		|| (r->hit && r->dist.y <= MOVE_SPEED + FAT)
		|| (!r->hit && r->dist.x <= MOVE_SPEED + FAT))
	{
		free(l);
		free(r);
		return (TRUE);
	}
	free(l);
	free(r);
	return (FALSE);
}

t_vector	get_player_side(int key, t_src *src, t_vector r_dir, int side)
{
	if (key == KEY_W)
		return ((t_vector){src->player.x + FAT * side * r_dir.x,
			src->player.y + FAT * side * r_dir.y});
	else if (key == KEY_S)
		return ((t_vector){src->player.x - FAT * side * r_dir.x,
			src->player.y - FAT * side * r_dir.y});
	else if (key == KEY_A)
		return ((t_vector){src->player.x + FAT * side * src->dir.x,
			src->player.y + FAT * side * src->dir.y});
	else
		return ((t_vector){src->player.x - FAT * side * src->dir.x,
			src->player.y - FAT * side * src->dir.y});
}
