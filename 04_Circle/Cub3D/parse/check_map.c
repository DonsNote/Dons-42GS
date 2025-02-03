/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:17:27 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/03 10:07:14 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_line(char *line);

int	check_map(int map)
{
	char		*line;
	t_check_map	check;

	line = get_next_line(map);
	while (line != NULL)
	{
		if (check_line(line))
			return (1);
		free(line);
	}
	return (0);
}

int	check_line(char *line)
{
	return (0);
}
