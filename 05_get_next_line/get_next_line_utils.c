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

char	*ft_strjoin(char *sol, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	if (!sol)
		return (buf);
	i = (ft_strlen(sol) + ft_strlen(buf));
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (tmp == 0)
		return (0);
	i = -1;
	j = -1;
	while (sol[++i] != '\0')
		tmp[i] = sol[i];
	while (buf[++j] != '\0')
	{
		tmp[i] = buf[j];
		++i;
	}
	free(sol);
	free(buf);
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_return_line(char *sol)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (sol[i] != '\n')
		++i;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (tmp == 0)
		return (0);
	j = 0;
	while (sol[j] != '\n')
	{
		tmp[j] = sol[j];
		++j;
	}
	tmp[j] = '\n';
	tmp[j + 1] = '\0';
	return (tmp);
}

char	*ft_next_line(char *sol)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(sol);
	j = 0;
	while (sol[j] != '\n')
		++j;
	i = i - j;
	j = j + 1;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == 0)
		return (0);
	i = 0;
	while (sol[j] != '\0')
	{
		tmp[i] = sol[j];
		++i;
		++j;
	}
	tmp[i] = '\0';
	free(sol);
	return (tmp);
}
