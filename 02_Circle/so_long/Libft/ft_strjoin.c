/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:34:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/29 20:34:54 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*sol;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sol = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (sol == 0)
		return (0);
	while (s1[i] != '\0')
	{
		sol[i] = s1[i];
		++i;
	}
	while (s2[j] != '\0')
		sol[i++] = s2[j++];
	sol[i] = '\0';
	return (sol);
}
