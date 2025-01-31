/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:04:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/23 16:11:32 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	re_put(long long n, int fd);

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
