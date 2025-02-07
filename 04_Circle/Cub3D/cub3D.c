/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:17:04 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/07 15:53:00 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_file_name(char *file_name);

int	main(int ac, char **av)
{
	int		map;
	t_asset	*asset;

	if (ac < 2 || check_file_name(av[1]))
		return (error_print(1));
	map = open(av[1], O_RDONLY);
	asset = init_aseet(asset);
	if (map == -1)
		return (error_print(2));
	if (check_init_map(map, asset))
		return (error_print(3));
	init_texture(map);
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

t_asset	*init_asset(t_asset *asset)
{
	t_asset	*tmp;

	tmp = (t_asset *)malloc(sizeof(t_asset) * 1);
	if (tmp = NULL)
		return (NULL);
	
}
