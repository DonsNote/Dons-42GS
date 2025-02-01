/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:58:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 20:46:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_compare(char *str, char *word, int size);

char	*ft_strnstr(char *str, char *word, int size)
{
	int	i;
	int	n_len;

	i = 0;
	n_len = ft_strlen(word);
	if (n_len == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == word[0])
		{
			if (str_compare(&str[i], word, size))
				return (&str[i]);
		}
		++i;
	}
	return (NULL);
}

static int	str_compare(char *str, char *word, int size)
{
	int	i;

	i = 0;
	while (str[i] == word[i])
	{
		if (str[i] == '\0' && word[i] != '\0')
			return (0);
		if (word[i] == '\0' || size <= 0)
			return (1);
		++i;
		--size;
	}
	return (0);
}
