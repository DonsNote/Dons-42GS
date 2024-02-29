
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*sol;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sol = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (sol == 0)
		return (0);
	while (s1[i] != '\0')
	{
		sol[i] = s1[i];
		++i;
	}
	while (s2[j] != '\0')
	{
		sol[i] = s2[j];
		++i;
		++j;
	}
	sol[i] = '\0';
	return (sol);
}