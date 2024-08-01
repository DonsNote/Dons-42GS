/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:42:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 12:42:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
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