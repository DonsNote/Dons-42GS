/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:49:28 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/23 14:06:37 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int	ft_check_enter(char *sol)
{
	int	i;

	i = 0;
	if (sol == NULL)
		return (1);
	while (sol[i] != '\0')
	{
		if (sol[i] == '\n')
			return (0);
		++i;
	}
	return (1);
}

void	ft_strcpy(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	return ;
}

char	*ft_strjoin(char *sol, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	if (sol == 0)
		return (buf);
	i = ft_strlen(sol);
	j = ft_strlen(buf);
	tmp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (tmp == 0)
		return (0);
	ft_strcpy(tmp, sol, 0);
	ft_strcpy(tmp, buf, i);
	free(sol);
	free(buf);
	tmp[i + j] = '\0';
	return (tmp);
}
