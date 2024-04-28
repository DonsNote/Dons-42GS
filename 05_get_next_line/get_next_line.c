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

char	*ft_read_file(int *fd, ssize_t *size)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)
		return (0);
	*size = read(*fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	return (buf);
}

int	ft_check_enter(char *sol, int *i)
{
	if (!sol)
		return (1);
	*i = 0;
	while (sol[*i] != '\0')
	{
		if (sol[*i] == '\n')
			return (0);
		++*i;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	ssize_t		size;
	int			flag;
	int			i;
	char		*buf;
	static char	*sol;

	if (BUFFER_SIZE <= 0)
		return (0);
	while (ft_check_enter(sol, &i))
	{
		buf = ft_read_file(&fd, &size);
		if (size < 0)
			return (0);
		else if (size == 0)
			return (ft_end_gnl(sol, &flag));
		sol = ft_strjoin(sol, buf);
	}
	buf = ft_next_line(sol);
	sol = &(sol[i + 1]);
	return (buf);
}
