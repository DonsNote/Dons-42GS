/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/26 00:32:35 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int size)
{
	push_a(&a, &b);
	push_a(&a, &b);

	printf("Num(B) : %d\n", b->num);
	// printf("Num(B) : %d\n", b->next->num);
	return ;
}
