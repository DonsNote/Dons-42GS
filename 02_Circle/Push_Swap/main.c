/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:10:32 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 00:56:11 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		size;
	int		*num_arr;
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (0);
	if (ac < 2 || check_param(ac, av))
	{
		print_error();
		return (0);
	}
	num_arr = make_num_arr(ac, av, &size);
	if (num_arr == 0)
	{
		print_error();
		return (0);
	}
	a = make_stack(num_arr, size);
	free(num_arr);
	b = NULL;
	push_swap(a, b, size);
	return (0);
}
