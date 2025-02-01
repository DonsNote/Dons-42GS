/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:37:29 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:34:32 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *str, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*sol;

	if (str == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	sol = (char *)malloc(sizeof(char) * (len + 1));
	if (sol == NULL)
		return (NULL);
	sol[len] = '\0';
	while (i < len)
	{
		sol[i] = f(i, str[i]);
		++i;
	}
	return (sol);
}
