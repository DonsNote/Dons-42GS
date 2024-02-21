
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char    *ft_strdup(char *src)
{
    int len;
    char *sol;

    len = ft_strlen(src);
    sol = (char *)malloc(sizeof(char) * len + 1);
    if (sol == 0)
        return (0);
    ft_strcpy(sol, src);
    return (sol);
}
/*
#include <stdio.h>
int main(void)
{
    char c[] = "abc";
    ft_strdup(c);
    printf("%s\n", ft_strdup(c));
    return(0);
}
*/