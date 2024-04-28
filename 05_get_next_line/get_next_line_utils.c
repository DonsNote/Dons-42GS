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
	char	*tmp;

	if (!sol)
		return (buf);
	i = ft_strlen(sol);
	j = ft_strlen(buf);
	tmp = (char *)malloc(sizeof(char) * (i + j) + 1);
	if (tmp == 0)
		return (0);
	ft_strcpy_gnl(tmp, sol, 0);
	ft_strcpy_gnl(tmp, buf, i);
	tmp[i + j] = '\0';
	return (tmp);
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

char	*ft_next_line(char *sol, int *i)
{
	int		j;
	char	*tmp;

	*i = 0;
	j = 0;
	while (sol[*i] != '\n')
		++*i;
	tmp = (char *)malloc(sizeof(char) * (*i + 1));
	if (tmp == 0)
		return (0);
	while (sol[j] != '\n')
	{
		tmp[j] = sol[j];
		++j;
	}
	tmp[j] = '\n';
	tmp[j + 1] = '\0';
	return (tmp);
}

char	*ft_end_gnl(char *sol, int *flag)
{
	int		i;
	char	*re;

	if (*flag == 1)
		return (0);
	i = 0;
	while (sol[i] != '\0')
		++i;
	re = (char *)malloc(sizeof(char) * i + 1);
	if (re == 0)
		return (0);
	ft_strcpy_gnl(re, sol, 0);
	re[i] = '\0';
	*flag = 1;
	return (re);
}
