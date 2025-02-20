/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:17:04 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/20 14:16:30 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_file_name(char *file_name);

int	main(int ac, char **av)
{
	int		map;
	t_src	*src;

	if (ac < 2 || check_file_name(av[1]))
		return (error_print(1));
	map = open(av[1], O_RDONLY);
	if (map == -1)
		return (error_print(2));
	src = (t_src *)malloc(sizeof(t_src) * 1);
	if (src == NULL)
		return (error_print(4));
	if (check_init_map(map, src))
		return (error_print(3));
	return (0);
}

int	check_file_name(char *file_name)
{
	int		i;
	int		j;
	char	*cub;

	i = ft_strlen(file_name) - 4;
	j = 0;
	cub = ".cub";
	while (file_name[i] != '\0')
	{
		if (file_name[i] != cub[j])
			return (1);
		++i;
		++j;
	}
	return (0);
}

int	*init_src(t_src *src)
{
	tmp->no_texture = NULL;
	tmp->so_texture = NULL;
	tmp->we_texture = NULL;
	tmp->ea_texture = NULL;
	return (tmp);
}
