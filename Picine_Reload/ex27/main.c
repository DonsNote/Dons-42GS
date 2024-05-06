/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:46:31 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/23 12:29:38 by dohyuki2         ###   ########.fr       */
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

void	ft_print(int file)
{
	int		i;
	char	buff[1024];

	while (1)
	{
		i = read (file, buff, 1024);
		if (i > 0)
			write(1, buff, i);
		else if (i < 0)
		{
			errmsg(3);
			break ;
		}
		else
			break ;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		file;

	i = 0;
	if (ac <= 1)
		errmsg(1);
	else if (ac > 2)
		errmsg(2);
	else if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		ft_print(file);
		close (file);
	}
	return (0);
}
