/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:40:29 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/24 20:52:06 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list *ap, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_putchar_pf((char)va_arg(*ap, int));
	else if (type == 's')
		count = ft_putstr_pf(va_arg(*ap, char *));
	else if (type == 'p')
		count = ft_putaddr_pf(va_arg(*ap, unsigned long long));
	else if (type == 'd')
		count = ft_putdecimal_pf(va_arg(*ap, int));
	else if (type == 'i')
		count = ft_putint_pf(va_arg(*ap, int));
	else if (type == 'u')
		count = ft_putuint_pf(va_arg(*ap, unsigned int));
	else if (type == 'x')
		count = ft_putlhex_pf(va_arg(*ap, unsigned int));
	else if (type == 'X')
		count = ft_putuhex_pf(va_arg(*ap, unsigned int));
	else if (type == '%')
		count = ft_putchar_pf('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		sol;
	int		count;

	if (ft_checkform_pf((char *)format) == -1)
		return (-1);
	i = 0;
	sol = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count = ft_convert(&ap, format[++i]);
		else
			count = ft_putchar_pf(format[i]);
		if (count == -1)
			return (-1);
		sol = sol + count;
		++i;
	}
	va_end(ap);
	return (sol);
}
