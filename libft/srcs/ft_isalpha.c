
int ft_isalpha(int i)
{
    if ((i >= 65 && i <= 95) || (i >= 97 && i <= 122))
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