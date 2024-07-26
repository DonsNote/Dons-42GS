/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:34:00 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/26 16:01:24 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(t_list **a, int check)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next->prev = *a;
	tmp->next = *a;
	tmp->prev = (*a)->prev;
	(*a)->prev->next = tmp;
	(*a)->prev = tmp;
	*a = tmp;
	if (check == 1)
		return ;
	write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_list **a, int check)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next->prev = *a;
	tmp->next = *a;
	tmp->prev = (*a)->prev;
	(*a)->prev->next = tmp;
	(*a)->prev = tmp;
	*a = tmp;
	if (check == 1)
		return ;
	write(1, "sb\n", 3);
	return ;
}

void	swap_s(t_list **a, t_list **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	if ((*a)->next == NULL || (*b)->next == NULL)
		return ;
	swap_a(a, 1);
	swap_b(b, 1);
	write(1, "ss\n", 3);
	return ;
}
