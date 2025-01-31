/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:09:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/29 23:25:44 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*temp;
	void	*content;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	tmp = lst;
	while (tmp != NULL)
	{
		content = f(tmp->content);
		temp = ft_lstnew(content);
		if (temp == NULL)
		{
			free(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		tmp = tmp->next;
	}
	return (new);
}
