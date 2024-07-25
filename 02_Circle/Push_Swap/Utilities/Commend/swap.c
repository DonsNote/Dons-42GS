/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:34:00 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 10:54:57 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*swap_a(t_list *a)
{
	t_list	*tmp;

	if (a == 0 || a->next == 0)
		return (a);
	tmp = a->next;
	a->next = tmp->next;
	tmp->next->prev = a;
	tmp->next = a;
	tmp->prev = a->prev;
	a->prev->next = tmp;
	a->prev = tmp;
	write(1, "sa\n", 3);
	return (tmp);
}

t_list	*swap_b(t_list *a)
{
	t_list	*tmp;

	if (a == 0 || a->next == 0)
		return (a);
	tmp = a->next;
	a->next = tmp->next;
	tmp->next->prev = a;
	tmp->next = a;
	tmp->prev = a->prev;
	a->prev->next = tmp;
	a->prev = tmp;
	write(1, "sb\n", 3);
	return (tmp);
}

t_list	*swap_s(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = b->next;
	a->next = tmp->next;
	tmp->next->prev = b;
	tmp->next = b;
	tmp->prev = b->prev;
	b->prev->next = tmp;
	a->prev = tmp;
	tmp = a->next;
	a->next = tmp->next;
	tmp->next->prev = a;
	tmp->next = a;
	tmp->prev = a->prev;
	a->prev->next = tmp;
	a->prev = tmp;
	write(1, "ss\n", 3);
	return (tmp);
}
