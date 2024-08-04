/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/04 23:33:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_src **src)
{
	int	i;

	i = 0;
	free((*src)->mlx);
	free((*src)->win);
	free((*src)->anya);
	free((*src)->mama);
	free((*src)->fafa);
	free((*src)->wall);
	free((*src)->flow);
	while (i < (*src)->hei)
	{
		free((*src)->map[i]);
		++i;
	}
	free((*src)->map);
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
	src->count = 0;
	if (map_size(&src, av[1]))
		return (0);
	if (map_check(&src))
		return (0);
	start_window(&src);
	free_all(&src);
	free(src);
	return (0);
}
