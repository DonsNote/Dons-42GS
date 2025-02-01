/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:35:05 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:37:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		if (i + 1 == n)
			return (0);
		++i;
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
