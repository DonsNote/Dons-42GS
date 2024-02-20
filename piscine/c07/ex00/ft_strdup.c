/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:07:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/30 11:27:50 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*sol;

	i = 0;
	while (src[i] != '\0')
		i++;
	sol = (char *)malloc(sizeof(char) * (i + 1));
	if (sol == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		sol[i] = src[i];
		i++;
	}
	sol[i] = '\0';
	return (sol);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "abcdef";

	char *sol = ft_strdup(src);
	printf("%s", sol);
	free(sol);
	return (0);
}
*/
