/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:18 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:32:28 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	while (src[i] != '\0')
	{
		if (size == 1)
		{
			dest[i] = '\0';
			return (s_len);
		}
		dest[i] = src[i];
		++i;
		--size;
	}
	dest[i] = '\0';
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
