/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:36:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 14:10:46 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

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
	const char src[] = "hello";
	char	a[] = "aaaaa";
	char	*b;

//	ft_memcpy(a, src, 5);
	b = memcpy(b, src, 6);

//	printf("%s\n", a);
	printf("%s\n", b);
	printf("%p\n", src);
	printf("%p\n", a);
	printf("%p\n", b);
	return (0);
}
*/