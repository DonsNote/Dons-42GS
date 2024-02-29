
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sol;

	i = 0;
	while (s[len] != '\0')
	{
		++len;
		++i;
	}
	sol = (char *)malloc(sizeof(char) * (i + 1));
	if (sol == 0)
		return (0);
	
}