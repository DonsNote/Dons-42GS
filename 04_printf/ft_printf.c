/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:40:29 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/27 22:54:31 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list ap, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_putchar_pf((char)va_arg(ap, int));
	else if (type == 's')
		count = ft_putstr_pf((va_arg(ap, char *)));
	
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		sol;
	int		count;

	i = 0;
	sol = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count = ft_convert(ap, format[++i]);
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
