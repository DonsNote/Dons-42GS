/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:41:18 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 19:07:46 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str, char *compare)
{
	int	i;

	i = 0;
	if (str == NULL || compare == NULL)
		return (1);
	while (compare != NULL)
	{
		if (str[i] != compare[i] || str[i] == '\0')
			return (1);
		++i;
	}
	return (0);
}
