/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:33:28 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 11:04:00 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sol;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len <= start)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s_len - start < len)
		len = s_len - start;
	sol = (char *)ft_calloc(len + 1, sizeof(char));
	if (sol == 0)
		return (0);
	while (i < len)
	{
		sol[i] = s[i + start];
		++i;
	}
	return (sol);
}
