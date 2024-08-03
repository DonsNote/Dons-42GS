/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/03 19:19:43 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (map_size(&src, av[1]))
		return (0);
	start_window(&src);
	// free(src);
	return (0);
}
 