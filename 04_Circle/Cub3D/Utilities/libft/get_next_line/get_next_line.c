/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2025/02/01 21:05:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sol;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (gnl_check_enter(sol))
	{
		buf = gnl_read_file(fd);
		if (buf == NULL)
		{
			buf = sol;
			sol = NULL;
			return (buf);
		}
		sol = gnl_join_free(sol, buf);
	}
	buf = gnl_return_line(sol);
	sol = gnl_next_line(sol);
	if (sol[0] == '\0' || sol == NULL)
	{
		free(sol);
		sol = NULL;
	}
	return (buf);
}

// int	main(void)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	i = 0;
// 	fd = open("./test", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf ("%d line : %s", i, line);
// 		free (line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free (line);
// 	close(fd);
// 	return (0);
// }
