/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:07:03 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/08 17:08:06 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	(void)ac;
	pid_t	pid;

	pid = getpid();
	printf("%d\n", pid);
	return (0);
}

// void	sig_func(sig)
// {

// }