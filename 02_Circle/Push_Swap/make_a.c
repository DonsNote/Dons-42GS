/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/05/02 12:01:05 by dohyuki2         ###   ########.fr       */
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
	new->prev = prev;
	new->next = 0;
	return (new);
}

t_list	*split_ps(char *av)
{
	size_t	i;
	size_t	h;
	t_list	*sol;

}

t_list	*make_a(int ac, char **av)
{
	t_list	*tmp;

	if (ac == 2)
	{
		tmp = split_ps(av[1]);
		if (tmp == 0)
			return (0);
		return (tmp);
	}
	tmp = 
	if (tmp == 0)
		return (0);
	return (tmp);
}
