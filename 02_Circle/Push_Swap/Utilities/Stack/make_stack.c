/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 17:25:04 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*newlist(int *num, t_list *prev, int *index, int size);
int		make_rank(int *num, int *index, int size);
int		check_min(int *num, int *index, int size);

t_list	*make_stack(int *num, int size)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 0;
	head = newlist(num, NULL, &i, size);
	++i;
	tmp = head;
	while (i < size)
	{
		tmp->next = newlist(num, tmp, &i, size);
		tmp = tmp->next;
		++i;
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}

t_list	*newlist(int *num, t_list *prev, int *index, int size)
{
	t_list	*new;
	int		mncheck;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->num = num[*index];
	new->rank = make_rank(num, index, size);
	mncheck = check_min(num, index, size);
	if (mncheck == 1)
		new->min = 1;
	if (prev == NULL)
		new->prev = new;
	else
		new->min = 0;
	new->prev = prev;
	new->totop = 0;
	new->total = 0;
	new->next = NULL;
	return (new);
}

int	make_rank(int *num, int *index, int size)
{
	int	i;
	int	rank;

	i = 0;
	rank = 1;
	while (i < size)
	{
		if (num[*index] > num[i])
			++rank;
		++i;
	}
	return (rank);
}

int	check_min(int *num, int *index, int size)
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
	if (check == 0)
		return (1);
	return (0);
}
