/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:04:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/06 11:22:15 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	re_put(long long n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd((char)n + 48, fd);
		return ;
	}
	re_put(n / 10, fd);
	ft_putchar_fd((char)((n % 10) + 48), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	re_put(nb, fd);
}
