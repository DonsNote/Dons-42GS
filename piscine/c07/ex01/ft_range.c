/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:25:27 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/02 20:10:39 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*sol;

	i = 0;
	if (min >= max)
		return (0);
	sol = (int *)malloc(sizeof(int) * (max - min));
	if (sol == 0)
		return (0);
	while (min < max)
	{
		sol[i] = min;
		min++;
		i++;
	}
	return (sol);
}
/*
#include <stdio.h>

int main(void)
{
	int *j;

	j = ft_range(3, 9);
	for(int i = 0; i < 6; i++)
		printf("%d ",j[i]);
	free(j);
	return (0);
}
*/
