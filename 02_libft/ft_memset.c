
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		++i;
	}
	return (b);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char a[] = "dddddddddd";
	char *ft_sol = ft_memset(a, 65, 10);
	char *sol = memset(a, 65, 10);
	printf("%s\n", ft_sol);
	printf("%s\n", sol);
	return (0);
}