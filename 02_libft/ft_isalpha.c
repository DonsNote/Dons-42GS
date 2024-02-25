
int ft_isalpha(int c)
{
    if ((c >= 65 && c <= 95) || (c >= 97 && c <= 122))
        return (1);
    return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isalpha(97));
    printf("%d\n", isalpha(97));
    return (0);
}
*/