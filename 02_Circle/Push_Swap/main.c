/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:10:32 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/09 10:37:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		size;
	int		*i;
	char	*sol;
	t_list	*a;

	if (ac < 2 || check_param(ac, av))
	{
		print_error();
		return (0);
	}
	i = make_num(ac, av, &size);
	a = make_stack(i, size);
	free(i);
	// sol = push_swap(a);
	return (0);
}
