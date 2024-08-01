/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/01 19:08:21 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*map;
	void	*mlx_ptr;
	void	*win_ptr;

	// if (ac != 3)
	// 	return (0);
	// fd = open(av[2], O_RDONLY);
	// map = get_next_line(fd);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "So_long");
	mlx_loop(mlx_ptr);

	return (0);
}
