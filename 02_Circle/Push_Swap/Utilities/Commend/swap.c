/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:34:00 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 12:33:34 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*swap_a(t_list *a)
{
	t_list	*ptmp;
	t_list	*ntmp;

	ptmp = a->prev;
	ntmp = a->next;
	a->next = a->next->next;
	a->prev = a->next->prev;
	a->next->prev = ptmp;
	a->next->next = ntmp;
	write(1, "sa\n", 3);
	return (a->next);
}

t_list	*swap_b(t_list *a)
{
	t_list	*ptmp;
	t_list	*ntmp;

	ptmp = a->prev;
	ntmp = a->next;
	a->next = a->next->next;
	a->prev = a->next->prev;
	a->next->prev = ptmp;
	a->next->next = ntmp;
	write(1, "sb\n", 3);
	return (a->next);
}

t_list	*swap_s(t_list *a, t_list *b)
{
	
}
