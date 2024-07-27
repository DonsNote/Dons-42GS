/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:19:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/27 17:22:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int size)
{
	int	asize;
	int	bsize;

	asize = size;
	bsize = 0;

	if (checker(&a, size))
	{
		// destroid_stack(a);
		return ;
	}
	if (size <= 3)
	{
		make_ceed(&a);
		// destroid_stack(a);
		return ;
	}
	lmpush(&a, &b, &asize, &bsize);
	make_ceed(&a);
	return ;
}
