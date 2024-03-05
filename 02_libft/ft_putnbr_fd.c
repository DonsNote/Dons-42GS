/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:04:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/05 21:04:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	re_put(int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd((char)n + 48, fd);
		return ;
	}
	re_put(n / 10, fd);
	ft_putchar_fd((char)(n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	re_put(n, fd);
}
