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
	char	*tmp;

	if (!sol)
	{
		sol = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (sol == 0)
			return (0);
	}
	i = ft_strlen(sol);
	j = ft_strlen(buf);
	k = 0;
	tmp = (char *)malloc(sizeof(char) * (i + j) + 1);
	if (tmp == 0)
		return (0);
	ft_strcpy_gnl(tmp, sol, k);
	ft_strcpy_gnl(tmp, buf, i);
	tmp[i + j] = '\0';
	return (tmp);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
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
	*sol = sol[j + 1];
	re[j] = '\n';
	re[j + 1] = '\0';
	return (re);
}

char	*ft_end_gnl(char *sol, char *buf, ssize_t size)
{
	int		i;
	char	*tmp;

	if (size == -1)
		return (0);
	i = 0;
	while (sol[i] != '\0')
		++i;
	tmp = (char *)malloc(sizeof(char) * i + 2);
	if (tmp == 0)
		return (0);
	ft_strcpy_gnl(tmp, sol, 0);
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	*buf = '\0';
	free(sol);
	return (tmp);
}
