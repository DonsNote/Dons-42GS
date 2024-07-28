/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:42:58 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 14:39:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	action(t_list **a, int size)
{
	int	i;
	int	rev;
	t_list	*tmp;

	i = 0;
	rev = 0;
	while (i < size)
	{
		if (tmp->total > (*a)->total)
		{
			tmp = *a;
			if (i > (size / 2))
				rev = 1;
		}
		++i;
	}
	if (rev == 1)
		go_rtop(a, tmp->totop);
	else
		go_top(a, tmp->totop);
	return ;
}

void	go_top(t_list **a, int size)
{

}

void	go_rtop(t_list **a, int size)
{

}
