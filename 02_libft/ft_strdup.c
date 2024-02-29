/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:49:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/28 15:40:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*sol;

	i = 0;
	while (s[i] != '\0')
		++i;
	sol = (char *)malloc(sizeof(char) * (i + 1));
	if (sol == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		sol[i] = s[i];
		++i;
	}
	sol[i] = '\0';
	return (sol);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = "hello, world";
	char *a = ft_strdup(s);
	char *b = strdup(s);

	printf("%s\n", a);
	printf("%s\n", b);
	free(a);
	free(b);
	return (0);
}
*/