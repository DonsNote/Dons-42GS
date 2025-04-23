/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:07:13 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 18:53:02 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	push_back(t_lists *lists, t_data data);
void	push_front(t_lists *lists, t_data data);
void	pop_back(t_lists *lists);
void	pop_front(t_lists *lists);

t_lists	*init_list(void)
{
	t_lists	*lists;

	lists = (t_lists *)malloc(sizeof(t_lists));
	if (lists == NULL)
		error_handle(e_allocate);
	lists->head = NULL;
	lists->tail = NULL;
	lists->size = 0;
	return (lists);
}

void	push_back(t_lists *list, t_data data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		error_handle(e_allocate);
	new_node->data.str = NULL;
	new_node->data = data;
	new_node->next = NULL;
	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->prev = NULL;
	}
	else
	{
		list->tail->next = new_node;
		new_node->prev = list->tail;
		list->tail = new_node;
	}
	++(list->size);
}

void	push_front(t_lists *lists, t_data data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		error_handle(e_allocate);
	node->data.str = NULL;
	node->data = data;
	node->next = NULL;
	if (lists->size == 0)
	{
		lists->head = node;
		lists->tail = node;
		node->prev = NULL;
	}
	else
	{
		lists->head->prev = node;
		node->next = lists->head;
		lists->head = node;
	}
	++(lists->size);
}

void	pop_back(t_lists *lists)
{
	t_node	*tmp;

	if (lists->size == 0)
		return ;
	tmp = lists->tail;
	if (lists->size == 1)
	{
		lists->head = NULL;
		lists->tail = NULL;
	}
	else
	{
		lists->tail->prev->next = NULL;
		lists->tail = lists->tail->prev;
	}
	free(tmp->data.str);
	free(tmp);
	--(lists->size);
}

void	pop_front(t_lists *lists)
{
	t_node	*tmp;

	if (lists->size == 0)
		return ;
	tmp = lists->head;
	if (lists->size == 1)
	{
		lists->head = NULL;
		lists->tail = NULL;
	}
	else
	{
		lists->head->next->prev = NULL;
		lists->head = lists->head->next;
	}
	free(tmp->data.str);
	free(tmp);
	--(lists->size);
}
