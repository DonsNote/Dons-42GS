/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:04:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/07 02:55:15 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*sol;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return ((char *)0);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && check_set((char)s1[i], set))
		++i;
	while (j >= i && check_set((char)s1[j], set))
		--j;
	sol = ft_substr(s1, i, (j - i + 1));
	if (sol == 0)
		return (0);
	return (sol);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char s[] = "lorem ipsum dolor sit amet";
	char set[] = "l ";
	char *sol = ft_strtrim(s, set);

	printf("%s\n", sol);
	free(sol);
	return (0);
}
*/