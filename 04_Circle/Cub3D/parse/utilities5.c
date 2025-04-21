/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:32:08 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/21 17:35:53 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		push(t_stack *stack, t_vector data);
t_vector	pop(t_stack *stack);
void		free_stack(t_stack **stack);

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		error_handle(e_allocate);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, t_vector data)
{
	t_node2	*node;

	node = (t_node2 *)malloc(sizeof(t_node2));
	if (node == NULL)
		error_handle(e_allocate);
	node->data = data;
	node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = node;
		node->prev = NULL;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	++(stack->size);
	return ;
}

t_vector	pop(t_stack *stack)
{
	t_node2		*tmp;
	t_vector	result;

	result = stack->top->data;
	tmp = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		stack->top->prev->next = NULL;
		stack->top = stack->top->prev;
	}
	free(tmp);
	--(stack->size);
	return (result);
}

void	free_stack(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	while ((*stack)->size > 0)
		pop(*stack);
	free(*stack);
	*stack = NULL;
	return ;
}
