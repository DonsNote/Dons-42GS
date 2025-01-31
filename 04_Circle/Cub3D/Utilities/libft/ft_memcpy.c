/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/30 00:13:34 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int	i;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char *src = "hello";
	char	*a = "aaaaa";
	char	*b = "aaaaa";

	a = ft_memcpy(a, src,  5);
	b = memcpy(b, src, 5);

	printf("%s\n", a);
	printf("%s\n", b);
	printf("%p\n", src);
	printf("%p\n", a);
	printf("%p\n", b);
	return (0);
}
*/