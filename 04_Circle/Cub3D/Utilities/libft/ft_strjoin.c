/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:34:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/31 19:56:23 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	ft_strcpy(sol, s1, 0);
	ft_strcpy(sol, s2, i);
	return (sol);
}
