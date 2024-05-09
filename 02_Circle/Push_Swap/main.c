/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:10:32 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/09 14:09:58 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	a = make_stack(i);
	free(i);
	sol = push_swap(a);
	return (0);
}
