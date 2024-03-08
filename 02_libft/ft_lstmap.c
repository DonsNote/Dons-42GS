/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:09:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/07 20:10:55 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nlist;
	t_list	*temp;
	void	*tcon;

	new = 0;
	nlist = lst;
	while (nlist)
	{
		tcon = f(nlist->content);
		temp = ft_lstnew(tcon);
		if (temp == 0)
		{
			free(tcon);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, temp);
		nlist = nlist->next;
	}
	return (new);
}
