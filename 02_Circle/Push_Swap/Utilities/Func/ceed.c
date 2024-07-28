/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceedset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:50:27 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 10:25:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	hpush(t_list **a, t_list **b, int *asize, int *bsize);
int		checker(t_list **a, int size);

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
	else if ((*a)->rank > (*a)->next->next->rank)
	{
		rotate_a(a);
		if (checker(a, 3))
			swap_a(a, 0);
	}
	else
		swap_a(a, 0);
	return ;
}

int	checker(t_list **a, int size)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = *a;
	while (i < size)
	{
		if (tmp->rank > tmp->next->rank)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
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
	hpush(a, b, asize, bsize);
	return ;
}

void	hpush(t_list **a, t_list **b, int *asize, int *bsize)
{
	while (*asize > 3)
	{
		push_b(a, b);
		--*asize;
		++*bsize;
	}
	return ;
}
