/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:37:29 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/04 12:39:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*sol;

	i = 0;
	len = ft_strlen(s);
	sol = (char *)malloc(sizeof(char) * (len + 1));
	if (sol == 0)
		return (0);
	sol[len] = '\0';
	while (i < len)
	{
		sol[i] = f(i, s[i]);
		++i;
	}
	return (sol);
}
