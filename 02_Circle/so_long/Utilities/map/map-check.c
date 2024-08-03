/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:02:42 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/03 20:31:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	input_map_arr(t_src **src, char *av);

int	map_size(t_src **src, char *av)
{
	int		fd;
	int		map_h;
	char	*line;

	map_h = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	(*src)->wid = strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++map_h;
	}
	free(line);
	close(fd);
	(*src)->hei = map_h;
	if ((*src)->hei > (*src)->wid)
		return (1);
	if (input_map_arr(src, av))
		return (1);
	return (0);
}

int	input_map_arr(t_src **src, char *av)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	(*src)->map = (char **)malloc(sizeof(char *) * ((*src)->hei + 1));
	if ((*src)->map == NULL)
		return (1);
	(*src)->map[(*src)->hei] = NULL;
	while (i < (*src)->hei)
	{
		(*src)->map[i] = get_next_line(fd);
		(*src)->map[i][(*src)->wid] = '\0';
		++i;
	}
	return (0);
}
