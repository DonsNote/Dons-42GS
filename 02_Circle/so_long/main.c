/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/06 14:15:31 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_src(t_src **src)
{
	(*src)->wid = 0;
	(*src)->hei = 0;
	(*src)->food = 0;
	(*src)->count = 0;
}

void	free_all(t_src **src)
{
	int	i;

	i = 0;
	mlx_destroy_display((*src)->mlx);
	while (i < (*src)->hei + 1)
	{
		free((*src)->map[i]);
		++i;
	}
	free((*src)->map);
	free((*src)->mlx);
	return ;
}

int	main(int ac, char **av)
{
	t_src	*src;

	if (ac != 2)
		return (0);
	if (param_check(av[1]))
		return (0);
	src = (t_src *)malloc(sizeof(t_src) * 1);
	if (src == NULL)
		return (0);
	set_src(&src);
	if (map_size(&src, av[1]))
	{
		free_all(&src);
		return (0);
	}
	if (map_check(&src))
	{
		free_all(&src);
		return (0);
	}
	start_window(&src);
	free_all(&src);
	free(src);
	return (0);
}
