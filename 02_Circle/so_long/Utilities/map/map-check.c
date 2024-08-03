/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:02:42 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/03 12:24:17 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_cpy(t_src **src, char *line, int index)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		(*src)->map[index][i] = line[i];
		++i;
	}
	return (0);
}

int	input_map_arr(t_src **src, char *av)
{
	int		i;
	int		wid;
	int		fd;
	char	*line;

	i = 0;
	wid = (*src)->wid;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		(*src)->map[i] = (char *)malloc(sizeof(char) * (wid + 1));
		if ((*src)->map[i] == NULL)
			return (1);
		(*src)->map[i][wid] = '\0';
		if (map_cpy(src, line, i))
			return (1);
		++i;
		line = get_next_line(fd);
	}
	return (0);
}

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
		line = get_next_line(fd);
		++map_h;
	}
	close(fd);
	(*src)->hei = map_h;
	if ((*src)->hei > (*src)->wid)
		return (1);
	(*src)->map = (char **)malloc(sizeof(char *) * (map_h + 1));
	if ((*src)->map == NULL)
		return (1);
	(*src)->map[map_h] = NULL;
	if (input_map_arr(src, av))
		return (1);
	return (0);
}
