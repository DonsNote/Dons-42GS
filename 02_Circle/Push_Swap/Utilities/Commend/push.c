/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:35 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 14:18:50 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*push_a(t_list *a, t_list *b)
{
	t_list	*ptmp;
	t_list	*ntmp;

	ptmp = a->prev;
	ntmp = a->next;
	a->next->prev = ptmp;
	a->prev->next = ntmp;
	if (b == 0)
	{
		b = a;
		b->prev = 0;
		b->next = 0;
	}
	else
	{
		a->next = b;
		a->prev = b->prev;
		a->prev->next = a;
		b->prev = a;
		b = a;
	}
	write(1, "pa\n", 3);
	return (a->next);
}

t_list	*push_b(t_list *a, t_list *b)
{
	t_list	*ptmp;
	t_list	*ntmp;

	ptmp = a->prev;
	ntmp = a->next;
	a->next->prev = ptmp;
	a->prev->next = ntmp;
	if (b == 0)
	{
		b = a;
		b->prev = 0;
		b->next = 0;
	}
	else
	{
		a->next = b;
		a->prev = b->prev;
		a->prev->next = a;
		b->prev = a;
		b = a;
	}
	write(1, "pb\n", 3);
	return (a->next);
}