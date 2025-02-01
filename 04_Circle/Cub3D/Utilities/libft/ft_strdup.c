/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:49:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:23:55 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*sol;

	if (str == NULL)
		return (NULL);
	sol = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (sol == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		sol[i] = str[i];
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