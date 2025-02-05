/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:17:27 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/05 16:38:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			check_line(char *line);
t_check_map	*init_check_map(void);

int	check_map(int map)
{
	char		*line;
	t_check_map	*check_direction;

	check_direction = init_check_map();
	line = get_next_line(map);
	while (line != NULL)
	{
		if (check_line(line))
			return (1);
		free(line);
	}
	return (0);
}

t_check_map	*init_check_map(void)
{
	t_check_map	*tmp;

	tmp = (t_check_map *)malloc(sizeof(t_check_map) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp->no = false;
	tmp->so = false;
	tmp->we = false;
	tmp->ea = false;
	return (tmp);
}

int	check_line(char *line)
{
	return (0);
}

int	check_path(char *line)
{
	return (0);
}
