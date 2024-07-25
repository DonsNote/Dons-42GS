/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:35 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 13:36:28 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*push_a(t_list *a, t_list **b)
{
	t_list	*tmp;

	tmp = a->next;
	tmp->prev = a->prev;
	a->prev->next = tmp;
	if (*b == NULL)
	{
		a->prev = NULL;
		a->next = NULL;
		*b = a;
	}
	else
	{
		a->next = *b;
		a->prev = (*b)->prev;
		(*b)->prev->next = a;
		(*b)->prev = a;
		*b = a;
	}
	write(1, "pa\n", 3);
	return (tmp);
}