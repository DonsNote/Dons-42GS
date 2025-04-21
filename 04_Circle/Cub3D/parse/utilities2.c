/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:25:43 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/21 17:15:07 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_data	get_front(t_list *list);
void	check_valid(t_src *src, char c, t_vector pos);
void	free_list(t_list **list);

void	set_map(t_src *new, t_list *list)
{
	int		w;
	int		h;

	new->map = (char **)ft_calloc(new->height, sizeof(char *));
	if (new->map == NULL)
		error_handle(e_allocate);
	h = 0;
	while (h < new->height)
	{
		new->map[h] = (char *)malloc(new->width);
		if (new->map[h] == NULL)
			error_handle(e_allocate);
		ft_memset(new->map[h], ' ', new->width);
		w = 0;
		while (get_front(list).str[w] != '\n'
			&& get_front(list).str[w] != '\0')
		{
			check_valid(new, get_front(list).str[w], (t_vector){w, h});
			new->map[h][w] = get_front(list).str[w];
			++w;
		}
		pop_front(list);
		++h;
	}
}

t_data	get_front(t_list *list)
{
	return (list->head->data);
}

void	check_valid(t_src *src, char c, t_vector pos)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (src->player.x != 0 || src->player.y !=0)
			error_handle(e_map);
		src->player.x = pos.x + 0.5f;
		src->player.y = pos.y + 0.5f;
	}
	else if (c != '0' && c != '1' && c != ' ')
		error_handle(e_map);
	return ;
}

void	free_list(t_list **list)
{
	t_node	*cur;
	t_node	*next;

	if (list == NULL || *list == NULL)
		return ;
	cur = (*list)->head;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur->data.str);
		free(cur);
		cur = next;
	}
	free(*list);
	*list = NULL;
}
