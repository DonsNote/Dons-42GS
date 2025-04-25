/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/25 15:42:55 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	line_error_handle(t_src *src);

void	error_handle(t_error_type type)
{
	static char	*error_msg[] = {"Allocate error",
		"File open error", "File read error", "Argument error",
		"Invalid map data"};

	printf("%s\n", error_msg[type]);
	exit(0);
}

void	line_error_handle(t_src *src)
{
	int	i;

	i = 0;
	while (src->textures[i].path != NULL)
	{
		free(src->textures[i].path);
		++i;
	}
	free(src);
	printf("Invalid map data\n");
	exit(0);
}
