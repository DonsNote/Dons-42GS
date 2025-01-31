/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:08:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/29 23:13:12 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*temp;

	tmp = *lst;
	while (tmp != NULL)
	{
		temp = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = temp;
	}
	*lst = NULL;
	return ;
}
