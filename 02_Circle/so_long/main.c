/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 13:55:08 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**map;

	if (ac != 2)
		return (0);
	if (param_check(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	while (*map)
	{
		*map = get_next_line(fd);
		++*map;
	}
	
	return (0);
}
