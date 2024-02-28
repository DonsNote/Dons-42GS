

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		
	}
}

#include <stdlib.h>