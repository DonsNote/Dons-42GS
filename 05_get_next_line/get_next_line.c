/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2024/04/24 03:19:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_file(int *fd, ssize_t *size)
{
	char	*buf;

	if (*size == 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)
		return (0);
	buf[BUFFER_SIZE] = '\0';
	*size = read(*fd, buf, BUFFER_SIZE);
	return (buf);
}

int	ft_check_enter(char *sol)
{
	int		i;

	i = 0;
	if (!sol)
		return (1);
	while (sol[i] != '\0')
	{
		if (sol[i] == '\n')
			return (0);
		++i;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	ssize_t		size;
	int			flag;
	char		*re;
	char		*buf;
	static char	*sol;

	if (BUFFER_SIZE <= 0)
		return (0);
	while (ft_check_enter(sol))
	{
		buf = ft_read_file(&fd, &size);
		if (size <= 0)
		{
			if (flag == 1)
				return (0);
			re = ft_end_gnl(sol, buf, size, &flag);
			return (re);
		}
		sol = ft_strjoin(sol, buf);
	}
	re = ft_next_line(sol);
	free(buf);
	return (re);
}
