/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:41:55 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/27 15:00:14 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	j = count_len(dest);
	d_len = count_len(dest);
	s_len = count_len(src);
	if (size < j)
		return (size + s_len);
	size = size - j;
	while (src[i] != '\0')
	{
		if (size <= 1)
			break ;
		dest[j] = src[i];
		j++;
		i++;
		size--;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>
int main(void)
{
	char a[] = "12345";
	char b[] = "adsf";
	printf("%d ", ft_strlcat(a, b, 7));
	return (0);
}
*/
