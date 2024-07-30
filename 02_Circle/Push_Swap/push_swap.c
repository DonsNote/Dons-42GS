/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/30 17:32:28 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print(t_list **a, t_list **b, int size);

void	push_swap(t_list *a, t_list *b, int size)
{
	int	asize;
	int	bsize;

	asize = size;
	bsize = 0;
	if (checker(&a, size) == 0)
	{
		destroid_stack(&a, &asize);
		return ;
	}
	if (size <= 3)
	{
		make_ceed(&a, size);
		destroid_stack(&a, &asize);
		return ;
	}
	if (size < 40)
		hpush(&a, &b, &asize, &bsize);
	else
		lmpush(&a, &b, &asize, &bsize);
	make_ceed(&a, asize);
	action(&a, &b, &asize, &bsize);
	destroid_stack(&a, &asize);
	return ;
}
