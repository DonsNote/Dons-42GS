/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:24:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 14:16:54 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	count_top(t_list **a, int size)
{
	int		i;
	int		mid;

	i = 0;
	mid = (size / 2);
	while (i <= mid)
	{
		(*a)->totop = i;
		*a = (*a)->next;
		++i;
	}
	while (i > 0)
	{
		(*a)->totop = i;
		*a = (*a)->next;
		--i;
	}
	return ;
}

void	count_total(t_list **a, t_list **b, int *asize)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = 0;
	j = (*b)->rank - (*a)->rank;
	if (j < 0)
		j = j * -1;
	tmp = *a;
	while (i < *asize)
	{
		k = (*b)->rank - (*a)->rank;
		if (k < 0)
			k = k * -1;
		if (j > k)
		{
			j = k;
			tmp = *a;
		}
		++i;
	}
	(*b)->total = tmp->totop + (*b)->totop;
	return ;
}

void	reset_cost(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*a)->totop = 0;
		(*a)->total = 0;
		*a = (*a)->next;
		++i;
	}
	return ;
}