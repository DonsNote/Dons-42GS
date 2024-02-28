/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:57:39 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 19:17:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		++i;
	}
	if (s[i] == (char)c)
		return (((char *)s)[i]);
	return ((char *)0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s[] = "hello";

	char *a = ft_strchr(s, 108);
	char *b = strchr(s, 108);

	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
}
*/
