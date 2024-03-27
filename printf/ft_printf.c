/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyouhele <kyouhele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:11:35 by kyouhele          #+#    #+#             */
/*   Updated: 2024/03/26 17:30:59 by kyouhele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_type_diu(char type, va_list ap);
static size_t	ft_type_xp(char type, va_list ap);
static size_t	type_choice(char type, va_list ap);
static void		justprint(size_t *i, size_t *len, char *str);

int	ft_printf(const char *str, ...)
{
	size_t	len;
	size_t	i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (correct_type(str[i + 1]) == 0)
				return (-1);
			len = len + type_choice(str[i + 1], ap);
			i += 2;
		}
		else
			justprint(&i, &len, (char *)str);
	}
	va_end(ap);
	return (len);
}

static void	justprint(size_t *i, size_t *len, char *str)
{
	ft_putchar_fd(str[*i], 1);
	(*i)++;
	(*len)++;
}

static size_t	type_choice(char type, va_list ap)
{
	size_t	len;
	char	*s;

	if (type == 'c')
	{
		ft_putchar_fd((unsigned char)va_arg(ap, int), 1);
		return (sizeof(char));
	}
	if (type == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	if (type == 'd' || type == 'u' || type == 'i' || type == '%')
		len = ft_type_diu(type, ap);
	if (type == 'x' || type == 'X' || type == 'p')
		len = ft_type_xp(type, ap);
	return (len);
}

static size_t	ft_type_diu(char type, va_list ap)
{
	size_t	len;
	size_t	n;
	char	*s;

	if (type == 'd' || type == 'i' || type == 'u')
	{
		n = va_arg(ap, int);
		if (type == 'u')
			s = ft_uitoa(n);
		else
			s = ft_itoa(n);
		ft_putstr_fd(s, 1);
		len = ft_strlen(s);
		free(s);
		return (len);
	}
	if (type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

static size_t	ft_type_xp(char type, va_list ap)
{
	size_t	len;
	size_t	n;
	char	*s;

	if (type == 'x' || type == 'X')
	{
		n = va_arg(ap, unsigned int);
		len = ft_putnbr_base(n, type);
		return (len);
	}
	if (type == 'p')
	{
		n = (size_t)va_arg(ap, void *);
		if (!n)
		{
			s = "(nil)";
			ft_putstr_fd(s, 1);
			return (ft_strlen(s));
		}
		ft_putstr_fd("0x", 1);
		len = 2 + ft_putnbr_base(n, type);
		return (len);
	}
	return (0);
}

/*
int main ()
{
	ft_printf("\n%d\n", ft_printf("%d", 10);x  %X  %p  %u  %u  %d",\
	 -214, -214, -214, -400, 400, 400));
	printf("\n%d\n", printf("%x  %X  %p  %u  %u  %d",\
	 -214, -214, -214, -400, 400, 400));
	return 0;
}
*/
