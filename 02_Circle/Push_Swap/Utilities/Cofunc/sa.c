/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 05:15:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/24 05:58:01 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*sa(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	a->next = a->next->next;
	a->prev = a->next;
	a->next->prev = tmp->prev;
	a->next->next = tmp->next;
	
}
