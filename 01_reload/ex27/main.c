/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:46:31 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/23 10:27:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	errmsg(int i)
{
	if (i == 1)
		write (2, "File name missing.\n", 19);
	if (i == 2)
		write (2, "Too many arguments.\n", 20);
	if (i == 3)
		write(2, "Cannot read file.\n", 18);
}

int	main(int ac, char **av)
{
	int		i;
	int		file;
	char	buff[1024];

	i = 0;
	file = open(av[1], O_RDWR);
	if (ac <= 1)
		errmsg(1);
	else if (ac > 2)
		errmsg(2);
	else if (ac == 2)
	{
		if (file > 0)
		{
			read (file, buff, 1024);
			while (buff[i] != '\0')
				write (1, &buff[i++], 1);
			close (file);
		}
		else
			errmsg(3);
	}
	return (0);
}
/*
    fd = open(av[1], O_RDWR);
    while (read(fd, &c, 1) > 0)
        write (1, &c, 1);
*/
