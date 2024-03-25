
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		num;
	int		temp;

	i = 0;
	num = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			temp = convert(ap, format[i]);
			++i;
		}
		else
			temp = print_char(format[i]);
		if (temp == -1)
			return (-1);
		num += temp;
		++i;
	}
	va_end(ap);
	return (num);
}