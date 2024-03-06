/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 10:49:03 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			temp = &((char *)s)[i];
		++i;
	}
	if (s[i] == (char)c)
		temp = &((char *)s)[i];
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
