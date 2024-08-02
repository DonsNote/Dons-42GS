/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:02:42 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 21:24:50 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_size(t_src **src, char *av)
{
	int	fd;
	int map_h;
	int	line;

	map_h = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	(*src)->wid = strlen(line) - 1;
	while (line)
	{
		line = get_next_line(fd);
		++map_h;
	}
	close(fd);
	(*src)->hei = map_h;
	if ((*src)->hei > (*src)->wid)
		return (1);
	(*src)->map = (char **)malloc(sizeof(char *) * map_h);
	if ((*src)->map == NULL)
		return (1);
	return (0);
}

int	map_check(char *map)
{
	
}