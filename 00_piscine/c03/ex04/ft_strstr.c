/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:52:47 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/25 19:03:30 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_word(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] != to_find[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (check_word(str, to_find, i))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "ab";
	char b[] = "abcde";
	printf("%s ", ft_strstr(a, b));
	printf("%s ", strstr(a, b));
	return (0);
}
*/
