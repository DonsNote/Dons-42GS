/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:07:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/10 07:04:58 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_msg(int n)
{
	static int	sol;
	static int	count;
	static int	base;
	char		c;

	if (base == 0)
		base = 1;
	if (n == SIGUSR1)
		sol = sol + 0 * base;
	if (n == SIGUSR2)
		sol = sol + 1 * base;
	++count;
	base = base * 2;
	if (count == 7)
	{
		c = (char)sol;
		write(1, &c, 1);
		sol = 0;
		count = 0;
		base = 1;
	}
	return ;
}

int	main(int ac, char **av)
{
	(void)av;
	pid_t	pid;

	if (ac != 1)
		return (0);
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	signal(SIGUSR1, put_msg);
	signal(SIGUSR2, put_msg);
	while (1)
		// sleep(1);
		pause();
	return (0);
}