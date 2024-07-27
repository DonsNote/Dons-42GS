/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:38 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/27 23:16:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	*a = tmp;
	write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	*a = tmp;
	write(1, "rb\n", 3);
	return ;
}

void	rotate_r(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*btmp;

	if (*a == NULL || *b == NULL)
		return ;
	if ((*a)->next == NULL || (*b)->next == NULL)
		return ;
	tmp = (*a)->next;
	btmp = (*b)->next;
	*a = tmp;
	*b = btmp;
	write(1, "rr\n", 3);
	return ;
}
