/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/06 18:10:51 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int i)
{
	if (i == 1)
		ft_printf("Error\n");
	return ;
}

void	set_src(t_src **src)
{
	(*src)->wid = 0;
	(*src)->hei = 0;
	(*src)->food = 0;
	(*src)->count = 0;
}

void	free_all(t_src **src, int j)
{
	int	i;

	i = 0;
	if (j == 2)
	{
		free((*src));
		return ;
	}
	while (i < (*src)->hei + 1)
	{
		free((*src)->map[i]);
		++i;
	}
	free((*src)->map);
	if (j == 1)
	{
		mlx_destroy_window((*src)->mlx, (*src)->win);
		mlx_destroy_display((*src)->mlx);
		free((*src)->mlx);
	}
	free((*src));
	return ;
}

int	check_part(t_src **src, char **av)
{
	if (map_size(src, av[1]))
	{
		print_error(1);
		free_all(src, 2);
		return (1);
	}
	if (map_check(src))
	{
		print_error(1);
		free_all(src, 0);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_src	*src;

	if (ac != 2)
		return (0);
	if (param_check(av[1]))
	{
		print_error(1);
		return (0);
	}
	src = (t_src *)malloc(sizeof(t_src) * 1);
	if (src == NULL)
		return (0);
	set_src(&src);
	if (check_part(&src, av))
		return (0);
	start_window(&src);
	free_all(&src, 1);
	return (0);
}
