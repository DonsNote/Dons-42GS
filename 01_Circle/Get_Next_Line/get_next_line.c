/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2025/01/23 14:40:30 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("./test", O_RDONLY);
	line = NULL;
	while (line)
	{
		line = get_next_line(fd);
		printf ("%d line : %s==\n", i, line);
		free (line);
		i++;
	}
	printf("%d line : %s\n", i, line);
	free (line);
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sol;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (ft_check_enter(sol))
	{
		buf = ft_read_file(fd);
		if (buf == NULL)
		{
			buf = sol;
			sol = NULL;
			return (buf);
		}
		sol = ft_strjoin(sol, buf);
	}
	buf = ft_return_line(sol);
	sol = ft_next_line(sol);
	if (sol[0] == '\0' || sol == NULL)
	{
		free(sol);
		sol = NULL;
	}
	return (buf);
}
