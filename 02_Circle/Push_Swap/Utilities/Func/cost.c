/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:24:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/30 17:11:55 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	count_top_a(t_list **a, int size)
{
	int		i;
	int		mid;

	i = 0;
	mid = (size / 2);
	while (i <= mid)
	{
		(*a)->atotop = i;
		*a = (*a)->next;
		++i;
	}
	if (size % 2 == 1)
		i = i - 1;
	else
		i = i - 2;
	while (i > 0)
	{
		(*a)->atotop = i;
		*a = (*a)->next;
		--i;
	}
	return ;
}

void	count_top_b(t_list **a, int size)
{
	int		i;
	int		mid;

	i = 0;
	mid = (size / 2);
	while (i <= mid)
	{
		(*a)->btotop = i;
		*a = (*a)->next;
		++i;
	}
	if (size % 2 == 1)
		i = i - 1;
	else
		i = i - 2;
	while (i > 0)
	{
		(*a)->btotop = i;
		*a = (*a)->next;
		--i;
	}
	return ;
}

void	count_total(t_list **a, t_list **b, int *asize, int *bsize)
{
	int	i;
	int	j;
	int	sol;

	i = 0;
	while (i < *bsize)
	{
		j = 0;
		sol = (*a)->rank - (*b)->rank;
		while (j < *asize)
		{
			if (rank_bettle(a, b, sol))
			{
				fix_total(a, b, asize, j);
				sol = (*a)->rank - (*b)->rank;
			}
			*a = (*a)->next;
			++j;
		}
		if (i > 1 && i > (*bsize / 2))
			(*b)->brev = 1;
		*b = (*b)->next;
		++i;
	}
	return ;
}

void	fix_total(t_list **a, t_list **b, int *asize, int j)
{
	if ((*b)->rank > (*a)->rank)
	{
		(*b)->atotop = (*a)->next->atotop;
		if (j + 1 > (*asize / 2))
			(*b)->arev = 1;
	}
	else
		(*b)->atotop = (*a)->atotop;
	if (j > 1 && j > (*asize / 2))
		(*b)->arev = 1;
	return ;
}

void	input_total(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*a)->total = (*a)->atotop + (*a)->btotop;
		*a = (*a)->next;
		++i;
	}
	return ;
}
