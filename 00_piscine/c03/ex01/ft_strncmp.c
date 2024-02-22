/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:50:59 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/25 17:59:56 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (n == 0)
			return (0);
		if (s1[i] != s2[i])
			break ;
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "abcdeg";
	char b[] = "abcdef";

	printf("%d", ft_strncmp(a, b, 6));
	return (0);
}
*/
