/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:06:48 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/07 18:06:51 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;

    temp = *lst;
    if (temp == (t_list *)0)
    {
        *lst = new;
        return ;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}
