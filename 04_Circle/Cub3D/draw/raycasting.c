/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:10:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 19:32:23 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_dda	*init_dda(t_src *src, t_vector ray);
void	step(t_dda *dda);
_Bool	is_collided(t_src *src, t_dda *dda);

t_dda	*raycasting(t_src *src, t_vector ray)
{
	t_dda	*dda;

	dda = init_dda(src, ray);
	while (1)
	{
		step(dda);
		if (is_collided(src, dda))
		{
			dda->target = src->map[(int)dda->cur.y][(int)dda->cur.x];
			break ;
		}
	}
	if (dda->hit == FALSE)
		dda->w_dist
			= (dda->cur.x - src->player.x + (1 - dda->step.x) / 2) / ray.x;
	else
		dda->w_dist
			= (dda->cur.y - src->player.y + (1 - dda->step.y) / 2) / ray.y;
	dda->dist.y -= dda->inter.y;
	dda->dist.x -= dda->inter.x;
	return (dda);
}

t_dda	*init_dda(t_src *src, t_vector ray)
{
	t_dda	*dda;

	dda = (t_dda *)malloc(sizeof(t_dda));
	if (dda == NULL)
		error_handle(e_allocate);
	dda->ray = ray;
	dda->inter.x = sqrt(1 + (ray.y * ray.y) / (ray.x * ray.x));
	dda->inter.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y));
	dda->hit = FALSE;
	dda->w_dist = 0.f;
	dda->cur.x = (float)(int)src->player.x;
	dda->cur.y = (float)(int)src->player.y;
	dda->step.x = 1 - 2 * (ray.x < 0);
	dda->step.y = 1 - 2 * (ray.y < 0);
	if (ray.x < 0)
		dda->dist.x = (src->player.x - dda->cur.x) * dda->inter.x;
	else
		dda->dist.x = (dda->cur.x + 1.f - src->player.x) * dda->inter.x;
	if (ray.y < 0)
		dda->dist.y = (src->player.y - dda->cur.y) * dda->inter.y;
	else
		dda->dist.y = (dda->cur.y + 1.f - src->player.y) * dda->inter.y;
	return (dda);
}

void	step(t_dda *dda)
{
	if (dda->dist.x < dda->dist.y)
	{
		dda->dist.x += dda->inter.x;
		dda->cur.x += dda->step.x;
		dda->hit = FALSE;
	}
	else
	{
		dda->dist.y += dda->inter.y;
		dda->cur.y += dda->step.y;
		dda->hit = TRUE;
	}
	return ;
}

_Bool	is_collided(t_src *src, t_dda *dda)
{
	if (src->map[(int)dda->cur.y][(int)dda->cur.x] == '1'
		|| src->map[(int)dda->cur.y][(int)dda->cur.x] == '5')
		return (TRUE);
	return (FALSE);
}
