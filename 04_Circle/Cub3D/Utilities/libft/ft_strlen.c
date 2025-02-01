/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:42:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 16:33:07 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char a[] = "hello";

	printf("%zu\n", ft_strlen(a));
	printf("%zu\n", strlen(a));
	return (0);
}
*/