/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:24:53 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/26 16:05:15 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_a(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->prev == NULL)
		return ;
	tmp = (*a)->prev;
	*a = tmp;
	write(1, "rra\n", 4);
	return ;
}

void	reverse_b(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->prev == NULL)
		return ;
	tmp = (*a)->prev;
	*a = tmp;
	write(1, "rrb\n", 4);
	return ;
}

void	reverse_r(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*btmp;

	if (*a == NULL || *b == NULL)
		return ;
	if ((*a)->next == NULL || (*b)->next == NULL)
		return ;
	tmp = (*a)->prev;
	btmp = (*b)->prev;
	*a = tmp;
	*b = btmp;
	write(1, "rrr\n", 4);
	return ;
}
