/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:35 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/26 09:36:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_util(t_list **a, t_list **b)
{
	if ((*b)->prev == NULL)
	{
		(*a)->prev = *b;
		(*b)->prev = *a;
	}
	else
	{
		(*a)->prev = (*b)->prev;
		(*b)->prev->next = *a;
	}
	(*a)->next = *b;
	(*b)->prev = *a;
	return ;
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*btmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	btmp = *a;
	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	if (*b == NULL)
	{
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	else
		push_util(a, b);
	*a = tmp;
	*b = btmp;
	write(1, "pa\n", 3);
	return ;
}