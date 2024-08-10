/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:57:51 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/10 11:00:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bi(pid_t pid, char *av)
{
	int		i;
	int		j;
	int		num;

	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		num = (int)av[i];
		j = 0;
		while (j < 8)
		{
			if (num % 2 == 0)
				kill(pid, SIGUSR1);
			else if (num % 2 == 1)
				kill(pid, SIGUSR2);
			num = num / 2;
			++j;
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
