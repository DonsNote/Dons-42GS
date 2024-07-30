/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:57:17 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/30 16:58:56 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rank_bettle(t_list **a, t_list **b, int sol)
{
	int	i;
	int	j;
	int	bet;

	i = 0;
	j = 0;
	bet = (*a)->rank - (*b)->rank;
	if (sol < 0)
	{
		sol *= -1;
	}
	if (bet < 0)
		bet *= -1;
	if (sol >= bet)
		return (1);
	return (0);
}

void	reset_cost(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*a)->atotop = 0;
		(*a)->btotop = 0;
		(*a)->total = 0;
		(*a)->arev = 0;
		(*a)->brev = 0;
		*a = (*a)->next;
		++i;
	}
	return ;
}
