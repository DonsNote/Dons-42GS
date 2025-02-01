/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:04:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 20:57:18 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char *set);

char	*ft_strtrim(char *str, char *set)
{
	int		i;
	int		j;
	char	*sol;

	if (str == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(str));
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] != '\0' && check_set(str[i], set))
		++i;
	while (j >= i && check_set(str[j], set))
		--j;
	sol = ft_substr(str, i, (j - i + 1));
	if (sol == NULL)
		return (NULL);
	return (sol);
}

static int	check_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
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