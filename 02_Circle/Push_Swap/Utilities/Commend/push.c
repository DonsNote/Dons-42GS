/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:35 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 17:50:15 by dohyuki2         ###   ########.fr       */
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
		tmp = *b;
		a->next = tmp;
		a->prev = tmp->prev;
		tmp->prev->next = a;
		tmp->prev = a;
		*b = a;
		a = tmp;
	}
	write(1, "pa\n", 3);
	return (tmp);
}