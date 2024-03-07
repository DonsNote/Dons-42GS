/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:08:33 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/07 18:08:35 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *nlist;
    t_list  *temp;

    nlist = *lst;
    while (nlist)
    {
        temp = nlist->next;
        del(nlist->content);
        free(nlist);
        nlist = temp;
    }
    *lst = (t_list *)0;
}
