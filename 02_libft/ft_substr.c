/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:33:28 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/29 20:33:33 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sol;

	i = 0;
	j = 0;
	while (s[start] != '\0')
	{
		++start;
		++i;
	}
	sol = (char *)malloc(sizeof(char) * (i + 1));
	if (sol == 0)
		return (0);
	while (j < len && i > 0)
	{
		sol[j] = s[start];
		++j;
		++start;
		--i;
	}
	if (sol[j] != '\0')
		sol[j] = '\0';
	return (sol);
}
