
int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", isdigit(5));
	printf("%d\n", ft_isdigit(5));
	return (0);
}
*/