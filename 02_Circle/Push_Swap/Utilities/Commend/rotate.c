/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:38 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 12:30:21 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*rotate_a(t_list *a)
{
	write(1, "ra\n", 3);
	return (a->next);
}

t_list	*rotate_b(t_list *a)
{
	write(1, "rb\n", 3);
	return (a->next);
}

t_list	*rotate_r(t_list *a, t_list *b)
{
	write(1, "rr\n", 3);
	b = b->next;
	return (a->next);
}
