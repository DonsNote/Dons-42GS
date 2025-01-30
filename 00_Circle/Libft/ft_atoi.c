/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:36:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/29 20:50:44 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sol;
	int	sign;

	if (str == NULL)
		return (NULL);
	i = 0;
	sol = 0;
	sign = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		++i;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		sol = (sol * 10) + (str[i] - 48);
		++i;
	}
	return (sol * sign);
}
/* test example
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char a[] = "    2147483647";
	printf("%d\n", ft_atoi(a));
	printf("%d\n", atoi(a));
	return (0);
}
*/
