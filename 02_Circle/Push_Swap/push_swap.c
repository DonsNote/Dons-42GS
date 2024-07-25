/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 13:34:44 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int size)
{
	t_list	*tmp;

	tmp = push_a(a, &b);
	tmp = push_a(a, &b);
	for(int i = 0; i < size; ++i)
	{
		if (tmp == NULL)
			break ;
		printf("Num(A) : %d\n", tmp->num);
		tmp = tmp->next;
	}
	// for(int i = 0; i < size; ++i)
	// {
	// 	if (b == NULL)
	// 		break ;
	printf("Num(B) : %d\n", b->num);
	// 	b = b->next;
	// }
	return ;
}
