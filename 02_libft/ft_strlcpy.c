/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:18 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 16:53:33 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen] != 0)
		++srclen;
	if (size == 0)
		return (srclen);
	while (i < size)
	{
		dst[i] = src[i];
		++i;
	}
	if (dst[i] != 0)
		dst[i] = 0;
	return (srclen);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	size_t	i;
	const char	a[] = "abcabc";
	char	b[] = "cdacda";

	i = strlcpy(b, a, 6);

	printf("%zu\n", ft_strlcpy(b, a, 6));
	printf("%s\n", b);
	printf("%zu\n", i);
	printf("%s\n", b);
	return (0);
}
*/
