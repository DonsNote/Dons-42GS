/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:45:41 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 14:51:56 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	go_atop(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		rotate_a(a);
		++i;
	}
	return ;
}

void	go_artop(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		reverse_a(a);
		++i;
	}
	return ;
}

void	go_btop(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		rotate_b(a);
		++i;
	}
	return ;
}

void	go_brtop(t_list **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		reverse_b(a);
		++i;
	}
	return ;
}