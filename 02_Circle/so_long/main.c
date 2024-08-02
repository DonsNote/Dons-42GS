/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 21:21:15 by dohyuki2         ###   ########.fr       */
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
	if (map_size(&src, av[1]));
		return (0);
	return (0);
}
