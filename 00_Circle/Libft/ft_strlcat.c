/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:54:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 10:38:40 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	j = ft_strlen(dst);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size < j)
		return (size + s_len);
	size = size - j;
	while (src[i] != '\0')
	{
		if (size <= 1)
			break ;
		dst[j] = src[i];
		++j;
		++i;
		--size;
	}
	dst[j] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	const char a[] = "hello";
//	const char b[] = "hello";
	char c[] = "Don";
//	char d[] = "Don";

//	printf("%zu\n", strlcat(c, a, 10));
//	printf("%s\n", c);
	printf("%zu\n", ft_strlcat(c, a, 10));
	printf("%s\n", c);
	return (0);
}
*/
