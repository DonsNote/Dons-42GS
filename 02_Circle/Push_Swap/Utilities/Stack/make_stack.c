/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/23 15:51:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*newlist(int *num, t_list *prev, int *index, int size);
int		make_rank(int *num, int *index, int size);
int		check_minmax(int *num, int *index, int size);

t_list	*make_stack(int *num, int size)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 1;
	head = newlist(num, 0, 0, size);
	tmp = head;
	while (i < size)
	{
		tmp->next = newlist(num, tmp, &i, size);
		tmp = tmp->next;
		++i;
	}
	head->prev = tmp;
	return (head);
}

t_list	*newlist(int *num, t_list *prev, int *index, int size)
{
	t_list	*new;
	int		mncheck;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == 0)
		return (0);
	new->num = num[*index];
	new->rank = make_rank(num, index, size);
	if ((mncheck = check_minmax(num, index, size)))
	{
		if (mncheck == 1)
			new->min = 1;
		else if (mncheck == 2)
			new->max = 1;
	}
	if (prev == 0)
		new->prev = new;
	else
		new->prev = prev;
	new->next = 0;
	return (new);
}

int	make_rank(int *num, int *index, int size)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < size)
	{
		if (num[*index] > num[i])
			++rank;
		++i;
	}
	return (rank);
}

int	check_minmax(int *num, int *index, int size)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < size)
	{
		if (num[*index] > num[i])
			++check;
		++i;
	}
	if (check == size)
		return (2);
	if (check == 0)
		return (1);
	return (0);
}


