/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2024/04/22 09:59:24 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char		*buf;
	char		*re;
	static char	*sol;

	if (BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)ft_next_line(sol);
	free(buf);
		return (0);
	while (ft_check_enter(sol))
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (size <= 0)
		{
			re = ft_end_gnl(sol, buf);
			return (re);
		}
		sol = ft_strjoin(sol, buf);
	}
	re = ft_next_line(sol);
	free(buf);
	return (re);
}
