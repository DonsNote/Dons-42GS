/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroid_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:46:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/29 12:31:58 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	destroid_stack(t_list **a, int *asize)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < *asize)
	{
		if ((*a)->next == NULL)
			return ;
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
		++i;
	}
	return ;
}
