/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:35:05 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 10:57:12 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		if (n == 1)
			return (0);
		++i;
		--n;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char a[] = "abcdef";
	char b[] = "abcefg";

	printf("%d\n", ft_strncmp(a, b, 2));
	printf("%d\n", strncmp(a, b, 2));
	return (0);
}
*/
