/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:21 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/23 14:12:54 by dohyuki2         ###   ########.fr       */
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
	printf("%d line : %s)\n", i, line);
	free (line);
	close(fd);
	return (0);
}
