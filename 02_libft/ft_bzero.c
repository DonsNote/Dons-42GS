/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:18:08 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 13:35:38 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		++i;
	}
}
/*
#include <strings.h>
#include <stdio.h>

int main(void)
{
	char a[] = "dddddddddd";
	char b[] = "dddddddddd";

	ft_bzero(a, 10);
	bzero(b, 10);

	printf("%s\n", a);
	printf("%s\n", b);
	return (0);
}
*/
