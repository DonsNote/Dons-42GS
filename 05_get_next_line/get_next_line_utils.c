/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:52 by don               #+#    #+#             */
/*   Updated: 2024/04/05 18:40:20 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*sol;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sol = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (sol == 0)
		return (0);
	while (s1[i] != '\0')
	{
		sol[i] = s1[i];
		++i;
	}
	while (s2[j] != '\0')
		sol[++i] = s2[++j];
	sol[i] = '\0';
	return (sol);
}

void	ft_next_line(char *sol, char *tmp)
{
	int		i;
	int		j;

	i = 0;
	while (sol[i] != '\n')
		++i;
	i = i + 1;
	j = i;
	while (sol[i] != '\0')
	{
		tmp[j] = sol[i];
		++i;
		++j;
	}
	tmp[j] = '\0';
	sol[i - j] = '\0';
}

int	ft_check_enter(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			return (0);
		++i;
	}
	return (1);
}