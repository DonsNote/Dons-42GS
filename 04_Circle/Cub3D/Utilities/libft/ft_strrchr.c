/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 20:49:36 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			temp = &str[i];
		++i;
	}
	if (str[i] == (char)c)
		temp = &str[i];
	return (temp);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char a[] = "hello";

	printf("%s\n", ft_strrchr(a, 108));
	printf("%s\n", strrchr(a, 108));
	return (0);
}
*/
