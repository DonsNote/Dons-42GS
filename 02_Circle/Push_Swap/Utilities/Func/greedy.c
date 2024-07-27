/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:50:27 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/27 20:46:09 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	checker(t_list **a, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (i < size - 1)
	{
		if (tmp->rank > tmp->next->rank)
			return (0);
		tmp = tmp->next;
		++i;
	}
	return (1);
}

void	make_ceed(t_list **a, int size)
{
	if (size <= 2)
	{
		if (checker(a, size))
			rotate_a(a);
		return ;
	}
	if ((*a)->rank < (*a)->next->rank)
	{
		reverse_a(a);
		if (checker(a, 3))
			swap_a(a, 0);
	}
	else
	{
		rotate_a(a);
		if (checker(a, 3))
			swap_a(a, 0);
	}
	return ;
}

void	lmpush(t_list **a, t_list **b, int *asize, int *bsize)
{
	int	i;
	int	size;
	int	low;

	i = 0;
	size = *asize;
	low = (size / 3);
	while (i < size)
	{
		if ((*a)->rank < (low * 2))
		{
			push_b(a, b);
			--*asize;
			++*bsize;
			if ((*b)->next != NULL && (*b)->next->rank > low)
				rotate_b(b);
		}
		else
			rotate_a(a);
		++i;
	}
	return ;
}
