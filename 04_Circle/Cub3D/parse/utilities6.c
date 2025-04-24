/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:10:00 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/24 14:34:20 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_texture(t_src *src)
{
	int	i;

	i = 0;
	while (i < WALL_SIZE)
	{
		src->textures[i].img = mlx_xpm_file_to_image(src->canvas->mlx,
				src->textures[i].path, &src->textures[i].width,
				&src->textures[i].height);
		if (src->textures[i].img == NULL)
			error_handle(e_map);
		src->textures[i].data = mlx_get_data_addr(src->textures[i].img,
				&src->textures[i].bits_pixel, &src->textures[i].size_line,
				&src->textures[i].endian);
		if (src->textures[i].data == NULL)
			error_handle(e_map);
		++i;
	}
	return ;
}
