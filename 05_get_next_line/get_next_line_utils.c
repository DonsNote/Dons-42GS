/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:52 by don               #+#    #+#             */
/*   Updated: 2024/04/04 23:13:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s, int n)
{
	int		i;
	char	*sol;

	i = 0;
	while (s[i] != '\0')
		++i;
	sol = (char *)malloc(sizeof(char) * (i + 1));
	if (sol == 0)
		return (0);
	i = 0;
	while (i <= n)
	{
		sol[i] = s[i];
		++i;
	}
	sol[i] = '\0';
	return (sol);
}

char	*ft_check_enter_gnl(char *tmp)
{
	int		i;
	char	*sol;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			sol = ft_strdup_gnl(tmp, i);
			if (sol == 0)
				return (0);
			tmp = &tmp[i];
			return (sol);
		}
		++i;
	}
}