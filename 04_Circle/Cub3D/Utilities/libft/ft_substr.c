/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:33:28 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 21:03:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	int		s_len;
	char	*sol;

	if (start < 0)
		return (NULL);
	i = 0;
	s_len = ft_strlen(str);
	if (s_len <= start)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s_len - start < len)
		len = s_len - start;
	sol = (char *)ft_calloc(len + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	while (i < len)
	{
		sol[i] = str[i + start];
		++i;
	}
	return (sol);
}
