/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:04:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/04 12:25:36 by dohyuki2         ###   ########.fr       */
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

static	char	*ft_dupcpy(char const *s, size_t size, size_t i)
{
	size_t	j;
	size_t	k;
	char	*sol;

	j = i - size;
	k = 0;
	sol = (char *)malloc(sizeof(char) * (size + 1));
	if (sol == 0)
		return (0);
	while (size > 0)
	{
		sol[k] = s[j];
		++k;
		++j;
		--size;
	}
	sol[k] = '\0';
	return (sol);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*sol;

	i = 0;
	size = 0;
	if (s1[i] == 0)
		return (0);
	if (set[i] == 0)
		return (ft_strdup(s1));
	while (check_set((char)s1[i], set))
		++i;
	while (s1[i] != '\0')
	{
		if (check_set((char)s1[i], set))
			break ;
		++size;
		++i;
	}
	sol = ft_dupcpy(s1, size, i);
	if (sol == 0)
		return (0);
	return (sol);
}
