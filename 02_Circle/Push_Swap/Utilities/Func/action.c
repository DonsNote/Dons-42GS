/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:42:58 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/29 00:14:34 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	queue(t_list *s, t_list **a, t_list **b);
void	find_do(t_list **a, t_list **b, int *asize, int *bsize);
void	r_queue(t_list *s, t_list **a, t_list **b);

void	action(t_list **a, t_list **b, int *asize, int *bsize)
{
	int	i;

	i = 0;
	while (*bsize > 0)
	{
		reset_cost(a, *asize);
		reset_cost(b, *bsize);
		count_top(a, *asize);
		count_top(b, *bsize);
		count_total(a, b, asize, bsize);
		find_do(a, b, asize, bsize);
		push_a(a, b);
		--*bsize;
	}
	return ;
}

void	find_do(t_list **a, t_list **b, int *asize, int *bsize)
{
	int		i;
	int		left;
	t_list	*tmp;

	i = 0;
	tmp = *b;
	while (i < *bsize)
	{
		if (tmp->total > (*b)->total)
			tmp = *b;
		*b = (*b)->next;
		++i;
	}
	r_queue(tmp, a, b);
	return ;
}

void	r_queue(t_list *s, t_list **a, t_list **b)
{
	int	atotop;
	int	btotop;

	atotop = s->total - s->totop;
	btotop = s->totop;
	if (s->arev == 0 && s->brev == 0)
	{
		while (atotop > 0 && btotop > 0)
		{
			rotate_r(a, b);
			--atotop;
			--btotop;
		}
	}
	else if (s->arev == 1 && s->brev == 1)
	{
		while (atotop > 0 && btotop > 0)
		{
			reverse_r(a, b);
			--atotop;
			--btotop;
		}
	}
	queue(s, a, b);
	return ;
}

void	queue(t_list *s, t_list **a, t_list **b)
{
	int	left;

	left = (s->total - s->totop) - s->totop;
	if (left < 0)
	{
		left = left * -1;
		while (left > 0)
		{
			if (s->brev == 1)
				reverse_b(b);
			else
				rotate_b(b);
			--left;
		}
	}
	else
	{
		while (left > 0)
		{
			if (s->arev == 1)
				reverse_a(a);
			else
				rotate_a(a);
			--left;
		}
	}
	return ;
}
