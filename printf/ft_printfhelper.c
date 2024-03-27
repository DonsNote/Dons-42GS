/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhelper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyouhele <kyouhele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:51:57 by kyouhele          #+#    #+#             */
/*   Updated: 2024/03/26 01:08:01 by kyouhele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	uputnbr(char *nb, long int lnb, int len);
size_t		ft_putnbr_base(unsigned long int nbr, char type);
int			correct_type(char next);

char	*ft_uitoa(unsigned int n)
{
	size_t			len;
	unsigned int	nbr;
	char			*nb;

	len = 0;
	nbr = n;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	uputnbr(nb, nbr, len);
	nb[len] = '\0';
	return (nb);
}

static void	uputnbr(char *nb, long int lnb, int len)
{
	len--;
	if (lnb >= 10)
	{
		uputnbr(nb, lnb / 10, len);
		lnb = lnb % 10;
	}
	nb[len] = lnb + '0';
}

size_t	ft_putnbr_base(unsigned long int nbr, char type)
{
	size_t		cnt;
	char		*base;

	cnt = 0;
	if (type == 'p' || type == 'x')
		base = LOWER;
	if (type == 'X')
		base = UPPER;
	if (nbr >= 16)
	{
		cnt += ft_putnbr_base(nbr / 16, type);
		nbr = nbr % 16;
	}
	if (nbr < 16)
	{
		cnt++;
		ft_putchar_fd(base[nbr], 1);
	}
	return (cnt);
}

int	correct_type(char next)
{
	char	*types;
	size_t	i;

	types = "cspdiuxX";
	i = 0;
	while (types[i])
	{
		if (next == types[i])
			return (1);
		i++;
	}
	if (next == '%')
		return (1);
	return (0);
}
