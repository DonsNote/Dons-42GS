/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:35 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/26 15:00:15 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_aanal_util(t_list **a, t_list **b)
{
	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
}

void	push_banal_util(t_list **a, t_list **b)
{
	if ((*b)->prev == NULL)
	{
		(*a)->prev = *b;
		(*b)->prev = *a;
	}
	else
	{
		(*b)->prev->next = *a;
		(*a)->prev = (*b)->prev;
	}
	(*a)->next = *b;
	(*b)->next = *a;
	return ;
}

void	push_a(t_list **a, t_list **b)
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
	if (*b == NULL)
	{
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	else
		push_banal_util(a, b);
	btmp = *a;
	*a = tmp;
	*b = btmp;
	write(1, "pb\n", 3);
	return ;
}
