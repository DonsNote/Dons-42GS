/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:10:32 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/10 13:45:03 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		*i;
	char	*sol;
	t_list	*a;

	if (ac < 2 || check_param(ac, av))
	{
		print_error();
		return (0);
	}
	i = make_num(ac, av);
	for (int n = 0; n < 2; n++)
	{
		printf("%d", i[n]);
		printf("\n");
	}
//	a = make_stack(i);
	free(i);
//	sol = push_swap(a);
	return (0);
}
