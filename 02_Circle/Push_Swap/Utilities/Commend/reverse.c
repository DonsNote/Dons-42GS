/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:24:53 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 12:30:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*reverse_a(t_list *a)
{
	write(1, "rra\n", 4);
	return (a->prev);
}

t_list	*reverse_b(t_list *a)
{
	write(1, "rrb\n", 4);
	return (a->prev);
}

t_list	*reverse_r(t_list *a, t_list *b)
{
	write(1, "rrr\n", 4);
	b = b->prev;
	return (a->prev);
}
