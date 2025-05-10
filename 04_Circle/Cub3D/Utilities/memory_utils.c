/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:50:33 by hwasong           #+#    #+#             */
/*   Updated: 2025/05/06 17:50:36 by hwasong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_all_resources(t_src *src)
{
	free_textures(src);
	free_mlx(src);
	free_map(src);
	free(src);
}

void	free_textures(t_src *src)
{
	int	i;

	i = -1;
	while (++i < WALL_SIZE)
	{
		if (src->textures[i].img != NULL)
			mlx_destroy_image(src->canvas->mlx, src->textures[i].img);
	}
	free_textures_path(src);
}

void	free_mlx(t_src *src)
{
	if (src->canvas == NULL)
		return ;
	if (src->canvas->img.img != NULL)
		mlx_destroy_image(src->canvas->mlx, src->canvas->img.img);
	if (src->canvas->win != NULL)
		mlx_destroy_window(src->canvas->mlx, src->canvas->win);
	if (src->canvas->mlx != NULL)
	{
		mlx_destroy_display(src->canvas->mlx);
		free(src->canvas->mlx);
	}
	free(src->canvas);
}

void	free_map(t_src *src)
{
	int	i;

	i = -1;
	if (src->map != NULL)
	{
		while (++i < src->height && src->map[i] != NULL)
			free(src->map[i]);
		free(src->map);
	}
}

void	free_textures_path(t_src *src)
{
	int	i;

	i = -1;
	while (++i < WALL_SIZE)
	{
		if (src->textures[i].path != NULL)
			free(src->textures[i].path);
	}
}
