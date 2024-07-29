/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:35 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/30 07:47:26 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_aanal_util(t_list **a, t_list **b)
{
	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	return ;
}

void	push_banal_util(t_list **a, t_list **b)
{
	if ((*b)->prev == NULL)
	{
		(*b)->prev = *a;
		(*a)->prev = *b;
	}
	else
	{
		(*a)->prev = (*b)->prev;
		(*b)->prev->next = *a;
		(*b)->prev = *a;
	}
	if ((*b)->next == NULL)
	{
		(*b)->next = *a;
		(*a)->next = *b;
	}
	else
		(*a)->next = *b;
	return ;
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*btmp;

	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		tmp = NULL;
	else
	{
		tmp = (*b)->next;
		push_aanal_util(b, a);
	}
	btmp = *b;
	if (*a == NULL)
	{
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else
		push_banal_util(b, a);
	*b = tmp;
	*a = btmp;
	write(1, "pa\n", 3);
	return ;
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*btmp;

	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		tmp = NULL;
	else
	{
		tmp = (*a)->next;
		push_aanal_util(a, b);
	}
	btmp = *a;
	if (*b == NULL)
	{
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	else
		push_banal_util(a, b);
	*a = tmp;
	*b = btmp;
	write(1, "pb\n", 3);
	return ;
}
