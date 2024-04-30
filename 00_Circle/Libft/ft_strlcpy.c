/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:18 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 10:21:04 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	while (src[i] != '\0')
	{
		if (size == 1)
		{
			dst[i] = '\0';
			return (s_len);
		}
		dst[i] = src[i];
		++i;
		--size;
	}
	dst[i] = '\0';
	return (s_len);
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
