/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:07:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/09 18:28:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_msg(int n)
{
	static int	sol;
	static int	count;
	static int	base;
	char		c;

	if (count == 8)
	{
		c = (int)sol;
		printf("%d\n", c);
		write(1, &c, 1);
		sol = 0;
		count = 0;
		base = 1;
	}
	if (base == 0)
		base = base + 1;
	if (n == SIGUSR1)
		sol = sol * base + 0;
	if (n == SIGUSR2)
		sol = sol * base + 1;
	++count;
	base = base * 2;
	return ;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (0);
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	signal(SIGUSR1, put_msg);
	signal(SIGUSR2, put_msg);
	while (1)
		sleep(1);
		// pause();
	return (0);
}