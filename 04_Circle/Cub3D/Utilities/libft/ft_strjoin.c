/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:34:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:19:14 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*sol;

	i = ft_strlen(s1);
	sol = (char *)malloc(sizeof(char) * (i + ft_strlen(s2) + 1));
	if (sol == NULL)
		return (NULL);
	ft_strcpy(sol, s1, 0);
	ft_strcpy(sol, s2, i);
	return (sol);
}
