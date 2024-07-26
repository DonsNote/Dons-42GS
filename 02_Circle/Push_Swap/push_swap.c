/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/26 21:28:39 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int size)
{
	// push_a(&a, &b);
	// push_a(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	// swap_a(&a, 0);
	// swap_b(&b, 0);
	// swap_s(&a, &b);
	// reverse_r(&a, &b);
	// rotate_r(&a, &b);

	// printf("Num(A) : %d\n", a->num);
	printf("Num(A) : %d | Num(B) : %d\n", a->num, b->num);
	// printf("Num(A) : %p | Num(B) : %p\n", a->next, b->next);
	return ;
}
