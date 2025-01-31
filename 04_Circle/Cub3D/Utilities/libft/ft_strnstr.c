/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:58:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/23 16:14:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_needle(const char *s, const char *n, size_t i, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (check_needle(haystack, needle, i, len))
				return (&((char *)haystack)[i]);
		}
		++i;
	}
	return ((char *)0);
}

static int	check_needle(const char *s, const char *n, size_t i, size_t len)
{
	size_t	j;
	size_t	n_len;

	j = 0;
	n_len = ft_strlen(n);
	while (n[j] != '\0' && s[i] == n[j])
	{
		++i;
		++j;
	}
	if (j == n_len && i <= len)
		return (1);
	return (0);
}
