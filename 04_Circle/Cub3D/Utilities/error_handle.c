/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/26 19:59:46 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	line_error_handle(t_src *src, char **str, char **str1);

void	error_handle(t_error_type type)
{
	static char	*error_msg[] = {"Allocate error",
		"File open error", "File read error", "Argument error",
		"Invalid map data"};

	printf("%s\n", error_msg[type]);
	exit(0);
}

void	line_error_handle(t_src *src, char **str, char **str1)
{
	int	i;

	i = 0;
	while (src->textures[i].path != NULL)
	{
		free(src->textures[i].path);
		++i;
	}
	free(src);
	if (str != NULL)
		free_split(str);
	if (str1 != NULL)
		free_split(str1);
	printf("Invalid map data\n");
	exit(0);
}

void	texture_error_handle(t_src *src)
{
	int	i;

	i = -1;
	while (++i < WALL_SIZE)
	{
		if (src->textures[i].img != NULL)
			mlx_destroy_image(src->canvas->mlx, src->textures[i].img);
		free(src->textures[i].path);
	}
	mlx_destroy_image(src->canvas->mlx, src->canvas->img.img);
	i = -1;
	while (++i < src->height)
		free(src->map[i]);
	free(src->map);
	mlx_destroy_window(src->canvas->mlx, src->canvas->win);
	mlx_destroy_display(src->canvas->mlx);
	free(src->canvas->mlx);
	free(src->canvas);
	free(src);
	printf("Invalid texture\n");
	exit(0);
}
