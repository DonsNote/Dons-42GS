/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:54:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:32:30 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	d_len;
	int	s_len;

	i = 0;
	j = ft_strlen(dest);
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size < j)
		return (size + s_len);
	size = size - j;
	while (src[i] != '\0')
	{
		if (size <= 1)
			break ;
		dest[j] = src[i];
		++j;
		++i;
		--size;
	}
	dest[j] = '\0';
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
