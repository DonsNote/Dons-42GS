/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 22:02:47 by dohyuki2         ###   ########.fr       */
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
		return ;
	if (size <= 3)
	{
		make_ceed(&a, size);
		return ;
	}
	lmpush(&a, &b, &asize, &bsize);
	make_ceed(&a, asize);
	action(&a, &b, &asize, &bsize);
	// test_print(&a, &b, size);
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
			printf("A : %d | B : %d\n", (*a)->totop, (*b)->totop);
			printf("\n");
			printf("A : %d | B : %d\n", (*a)->total, (*b)->total);
			printf("\n");

			*a = (*a)->next;
			*b = (*b)->next;
		}
		++i;
	}
	return ;
}