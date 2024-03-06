/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:58:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 10:33:05 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	if (dest > src && n > 0)
	{
		n = n - 1;
		while (1)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			if (n == 0)
				break ;
			--n;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dest);
}
