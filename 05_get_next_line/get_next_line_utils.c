/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:52 by don               #+#    #+#             */
/*   Updated: 2024/04/24 03:20:10 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *sol, char *buf)
{
	int		i;
	int		j;
	int		k;
	char	*re;

	if (!sol)
	{
		sol = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (sol == 0)
			return (0);
		sol[BUFFER_SIZE] = '\0';
	}
	i = ft_strlen(sol);
	j = ft_strlen(buf);
	k = 0;
	re = (char *)malloc(sizeof(char) * (i + j) + 1);
	if (re == 0)
		return (0);
	ft_strcpy_gnl(re, sol, k);
	ft_strcpy_gnl(re, buf, i);
	re[i + j] = '\0';
	return (re);
}

void	ft_strcpy_gnl(char *sol, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		sol[i] = src[j];
		++i;
		++j;
	}
}

char	*ft_make_next(char *sol, int i)
{
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	k = 0;
	while (sol[j] != '\0')
		++j;
	j = j - i;
	tmp = (char *)malloc(sizeof(char) * j + 1);
	if (tmp == 0)
		return (0);
	i = i + 1;
	while (sol[i] != '\0')
	{
		tmp[k] = sol[i];
		++k;
		++i;
	}
	tmp[k] = '\0';
	return (tmp);
}

char	*ft_next_line(char *sol)
{
	int		i;
	int		j;
	char	*re;

	i = 0;
	j = 0;
	while (sol[i] != '\n')
		++i;
	re = (char *)malloc(sizeof(char) * i + 1);
	if (re == 0)
		return (0);
	while (sol[j] != '\n')
	{
		re[j] = sol[j];
		++j;
	}
	sol = ft_make_next(sol, i);
	re[j] = '\n';
	re[j + 1] = '\0';
	return (re);
}

char	*ft_end_gnl(char *sol, char *buf)
{
	int		i;
	char	*re;

	if (ft_strlen(sol) == 0)
		return (0);
	i = 0;
	while (sol[i] != '\0')
		++i;
	re = (char *)malloc(sizeof(char) * i + 1);
	if (re == 0)
		return (0);
	sol = ft_strjoin(sol, buf);
	ft_strcpy_gnl(re, sol, 0);
	re[i] = '\0';
	free(buf);
	free(sol);
	sol = NULL;
	return (re);
}
