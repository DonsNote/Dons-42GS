/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/27 20:06:25 by dohyuki2         ###   ########.fr       */
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
	if (checker(&a, size))
		return ;
	if (size <= 3)
	{
		make_ceed(&a, size);
		test_print(&a, &b, size);
		return ;
	}
	lmpush(&a, &b, &asize, &bsize);
	make_ceed(&a, asize);
	// destroid_stack(&a);
	return ;
}

void	test_print(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*a == NULL && *b == NULL)
			printf("A : %p | B : %p\n", a, b);
		else if (*a != NULL && *b == NULL)
		{
			printf("A : %d | B : %p\n", (*a)->num, b);
			*a = (*a)->next;
		}
		else if (*a == NULL && *b != NULL)
		{
			printf("A : %p | B : %d\n", a, (*b)->num);
			*b = (*b)->next;
		}
		else
		{
			printf("A : %d | B : %d\n", (*a)->num, (*b)->num);
			*a = (*a)->next;
			*b = (*b)->next;
		}
		++i;
	}
	return ;
}