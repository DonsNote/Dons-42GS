/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2024/04/05 18:41:52 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		size;
	char		*sol;
	char		*buf;
	static char	*tmp;

	if (BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)
		return (0);
	while (ft_check_enter(tmp))
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1 || size == 0)
			return (0);
		buf[BUFFER_SIZE] = '\0';
		sol = ft_strjoin(tmp, buf);
	}
	ft_next_line(sol, tmp);
	free(buf);
	return (sol);
}
