/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:51:51 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 14:54:42 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	m_move(int x, int y, t_src *src)
{
	(void)y;
	if (x < WIDTH / 2)
		rotate(KEY_LEFT, src);
	else
		rotate(KEY_RIGHT, src);
	mlx_mouse_move(src->canvas->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
