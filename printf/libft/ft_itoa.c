/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyouhele <kyouhele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:51:57 by kyouhele          #+#    #+#             */
/*   Updated: 2024/03/06 03:56:49 by kyouhele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cnt_nb(int n);
static void		putnbr(char *nb, long int lnb, int len);

char	*ft_itoa(int n)
{
	size_t		len;
	long int	lnb;
	char		*nb;

	len = cnt_nb(n);
	lnb = n;
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	if (n < 0)
	{
		nb[0] = '-';
		putnbr(nb, -lnb, len);
	}
	else
		putnbr(nb, lnb, len);
	nb[len] = '\0';
	return (nb);
}

static int	cnt_nb(int n)
{
	int			len;
	long int	lnb;

	len = 0;
	lnb = n;
	if (lnb < 0)
	{
		lnb = -lnb;
		len++;
	}
	if (lnb == 0)
		len = 1;
	while (lnb > 0)
	{
		lnb = lnb / 10;
		len++;
	}
	return (len);
}

static void	putnbr(char *nb, long int lnb, int len)
{
	len--;
	if (lnb >= 10)
	{
		putnbr(nb, lnb / 10, len);
		lnb = lnb % 10;
	}
	nb[len] = lnb + '0';
}
