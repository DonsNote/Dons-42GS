/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:59:20 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/28 13:48:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total;
	void	*sol;

	i = 0;
	total = nmemb * size;
	sol = (void *)malloc(total);
	if (sol == 0)
		return (0);
	while (i < total)
	{
		((unsigned char *)sol)[i] = 0;
		++i;
	}
	return (sol);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*a = calloc(5, sizeof(int));
	int *b = ft_calloc(5, sizeof(int));

	for(int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int j = 0; j < 5; j++)
		printf("%d ", b[j]);
	return (0);
}
*/
