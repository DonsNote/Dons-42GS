/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 22:40:30 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int size)
{
	push_a(&a, &b);
	push_a(&a, &b);

	printf("Num(A) : %d\n", a->num);
	printf("Num(A) : %d\n", a->next->num);
	// for(int i = 0; i < size; ++i)
	// {
	// 	if (b == NULL)
	// 		break ;
	printf("Num(B) : %d\n", b->num);
	printf("Num(B) : %d\n", b->next->num);
	// 	b = b->next;
	// }
	return ;
}
