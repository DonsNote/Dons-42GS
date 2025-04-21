/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:07:13 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/21 17:11:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	push_back(t_list *list, t_data data);
void	push_front(t_list *list, t_data data);
void	pop_back(t_list *list);
void	pop_front(t_list *list);

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		error_handle(e_allocate);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	push_back(t_list *list, t_data data)
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

void	push_front(t_list *list, t_data data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		error_handle(e_allocate);
	node->data.str = NULL;
	node->data = data;
	node->next = NULL;
	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
		node->prev = NULL;
	}
	else
	{
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	++(list->size);
}

void	pop_back(t_list *list)
{
	t_node	*tmp;

	if (list->size == 0)
		return ;
	tmp = list->tail;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	}
	free(tmp->data.str);
	free(tmp);
	--(list->size);
}

void	pop_front(t_list *list)
{
	t_node	*tmp;

	if (list->size == 0)
		return ;
	tmp = list->head;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->head->next->prev = NULL;
		list->head = list->head->next;
	}
	free(tmp->data.str);
	free(tmp);
	--(list->size);
}
