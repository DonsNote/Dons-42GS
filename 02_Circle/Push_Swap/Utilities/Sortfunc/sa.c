/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 05:15:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 06:29:19 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*sa(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	a->next->prev = tmp->prev;
	a->next->next = tmp->next;
	a->next = a->next->next;
	a->prev = a;
	return (a);
}
