/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 19:33:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	temp;

	i = 0;
	temp = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			temp = i;
		i++;
	}
	if (temp >= 0)
		return (&((char *)s)[temp]);
	return (0);
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
