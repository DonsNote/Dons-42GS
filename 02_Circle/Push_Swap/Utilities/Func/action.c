/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:42:58 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/30 08:35:06 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	queue(t_list **s, t_list **a, t_list **b);
void	find_do(t_list **a, t_list **b, int *asize, int *bsize);
void	r_queue(t_list **s, t_list **a, t_list **b);

void	action(t_list **a, t_list **b, int *asize, int *bsize)
{
	int	i;
	int	test;

	i = 0;
	test = 1;
	while (*bsize > 0)
	{
		reset_cost(a, *asize);
		reset_cost(b, *bsize);
		count_top_a(a, *asize);
		count_top_b(b, *bsize);
		count_total(a, b, asize, bsize);
		input_total(b, *bsize);
		find_do(a, b, asize, bsize);
		push_a(a, b);
		--*bsize;
		++*asize;
		--test;
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
		if ((tmp->total) > (*b)->total)
			tmp = *b;
		*b = (*b)->next;
		++i;
	}
	r_queue(&tmp, a, b);
	return ;
}

void	r_queue(t_list **s, t_list **a, t_list **b)
{
	if ((*s)->arev == 0 && (*s)->brev == 0)
	{
		while ((*s)->atotop > 0 && (*s)->btotop > 0)
		{
			rotate_r(a, b);
			--(*s)->atotop;
			--(*s)->btotop;
		}
	}
	else if ((*s)->arev == 1 && (*s)->brev == 1)
	{
		while ((*s)->atotop > 0 && (*s)->btotop > 0)
		{
			reverse_r(a, b);
			--(*s)->atotop;
			--(*s)->btotop;
		}
	}
	queue(s, a, b);
	return ;
}

void	queue(t_list **s, t_list **a, t_list **b)
{
	if ((*s)->atotop <= 0 && (*s)->btotop <= 0)
		return ;
	while ((*s)->atotop > 0)
	{
		if ((*s)->arev == 1)
			reverse_a(a);
		else
			rotate_a(a);
		--(*s)->atotop;
	}
	while ((*s)->btotop > 0)
	{
		if ((*s)->brev == 1)
			reverse_b(b);
		else
			rotate_b(b);
		--(*s)->btotop;
	}
	return ;
}
