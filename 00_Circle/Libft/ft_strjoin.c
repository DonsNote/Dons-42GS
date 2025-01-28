/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:34:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/23 15:34:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcyp_for_join(char *dest, char *src, int i);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*sol;

	i = ft_strlen(s1);
	sol = (char *)malloc(sizeof(char) * (i + ft_strlen(s2) + 1));
	if (sol == NULL)
		return (NULL);
	ft_strcyp_for_join(sol, (char *)s1, 0);
	ft_strcyp_for_join(sol, (char *)s2, i);
	return (sol);
}

static void	ft_strcyp_for_join(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
}
