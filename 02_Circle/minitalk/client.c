/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:57:51 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/10 06:55:10 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bi(pid_t pid, char *av)
{
	int		i;
	int		num;

	i = 0;
	while (num != '\0')
	{
		num = (int)av[i];
		while (num > 0)
		{
			if (num % 2 == 0)
				kill(pid, SIGUSR1);
			else if (num % 2 == 1)
				kill(pid, SIGUSR2);
			num = num / 2;
			if (num == 0)
			{
				kill(pid, SIGUSR1);
				usleep(400);
				break ;
			}
			usleep(400);
		}
		++i;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		return (0);
	if (av[2] == NULL || av[2][0] == '\0')
		return (0);
	pid = (pid_t)ft_atoi(av[1]);
	send_bi(pid, av[2]);
	return (0);
}
