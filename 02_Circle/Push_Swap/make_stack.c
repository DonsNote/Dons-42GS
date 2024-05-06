/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/06 11:34:35 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newlist(int n, t_list *prev)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == 0)
		return (0);
	new->num = n;
	if (prev == 0)
		new->prev = new;
	else
		new->prev = prev;
	new->next = 0;
	return (new);
}

t_list	*make_stack(int *i, int size)
{
	t_list	*head;
	t_list	*tmp;

	head = newlist(i[0], 0);
	tmp = head;
	while ()

	return (head);
}

