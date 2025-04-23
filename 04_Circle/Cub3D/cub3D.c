/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:17:04 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 17:21:07 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_file_name(char *file_name);

int	main(int ac, char **av)
{
	t_src	*src;

	if (ac != 2 || check_file_name(av[1]))
		error_handle(e_arg);
	src = check_init(av[1]);
	src->canvas = init_canvas(WIDTH, HEIGHT);
	check_texture(src);
	init_vectors(src);
	mlx_hook(src->canvas->win, EVENT_KEY_PRESS, 0, input_key, src);
	mlx_hook(src->canvas->win, EVENT_WINDOW_CLOSE, 0, input_exit, NULL);
	mlx_hook(src->canvas->win, EVENT_MOUSE_MOVE, 0, m_move, src);
	mlx_loop_hook(src->canvas->mlx, draw, src);
	// mlx_mouse_hide();
	mlx_loop(src->canvas->mlx);
	destroy_canvas(&src->canvas);
	destroy_src(src);
	return (0);
}

int	check_file_name(char *file_name)
{
	int		i;
	int		j;
	char	*cub;

	i = ft_strlen(file_name) - 4;
	if (i < 4)
		return (1);
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
