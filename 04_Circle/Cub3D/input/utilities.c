/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:38:57 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 14:46:07 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
