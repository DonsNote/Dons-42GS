/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:21:18 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/22 00:50:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	dfs(t_src *src, t_vector pos, t_stack *stack);
void	check_invalid(t_src *src, t_vector next_pos);

void	check_surround(t_src *src)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < src->height)
	{
		pos.x = 0;
		while (pos.x < src->width)
		{
			if (src->map[(int)pos.y][(int)pos.x] == ' ')
				dfs(src, pos, init_stack());
			++pos.x;
		}
		++pos.y;
	}
	return ;
}

void	dfs(t_src *src, t_vector pos, t_stack *stack)
{
	t_vector	next_pos;
	const int	direction[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	int			i;

	push(stack, pos);
	src->map[(int)pos.y][(int)pos.x] = 'X';
	while (stack->size > 0)
	{
		pos = pop(stack);
		i = -1;
		while (++i < 4)
		{
			next_pos = (t_vector){pos.x + direction[i][1],
				pos.y + direction[i][0]};
			if (next_pos.x < 0 || next_pos.y < 0
				|| next_pos.x >= src->width || next_pos.y >= src->height
				|| src->map[(int)next_pos.y][(int)next_pos.x] == '1'
				|| src->map[(int)next_pos.y][(int)next_pos.x] == 'X')
				continue ;
			check_invalid(src, next_pos);
			push(stack, next_pos);
			src->map[(int)next_pos.y][(int)next_pos.x] = 'X';
		}
	}
	free_stack(&stack);
}

void	check_invalid(t_src *src, t_vector next_pos)
{
	if (src->map[(int)next_pos.y][(int)next_pos.x] != '1'
		&& src->map[(int)next_pos.y][(int)next_pos.x] != ' ')
		error_handle(e_map);
}
