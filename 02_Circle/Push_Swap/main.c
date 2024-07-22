/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:10:32 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/21 06:09:18 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (i == 0)
	{
		print_error();
		return (0);
	}
	a = make_stack(i, size);
	for(int l = 0; l < size; ++l)
		printf("%d \n", i[l]);
	free(i);
	// sol = push_swap(a);
	return (0);
}
