/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:09:40 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/29 23:27:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		++i;
	}
	return (i);
}
