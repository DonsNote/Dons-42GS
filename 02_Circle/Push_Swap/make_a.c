/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/01 11:23:52 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_a(int ac, char **av)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (ac - 1));
	if (tmp == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		tmp[i] = ft_atoi(av[i]);
		++i;
	}
	return (tmp);
}