/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 16:53:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int size)
{
	a = rotate_a(a);
	for(t_list *tmp = a; tmp != 0; tmp = tmp->next)
		printf("num(A) : %d\n", tmp->num);
	b = push_a(a, b);
	for(t_list *tmpb = b; tmpb != 0; tmpb = tmpb->next)
		printf("num(B) : %d\n", tmpb->num);
	return ;
}