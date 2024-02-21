
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int i;
    int nbr;
    int *sol;

    i = 0;
    nbr = min;
    sol = (int *)malloc(sizeof(int) * (max - min + 1));
    if (nbr == 0)
        return (0);
    while (i <= (max - min))
    {
        sol[i] = nbr;
        nbr++;
        i++;
    }
    return (sol);
}
/*
#include <stdio.h>
int main(void)
{
    int a = 5;
    int b = 10;
    int *i;

    i = ft_range(a,b);

    for(int j = 0; j < 5; j++)
        printf("%d ", i[j]);
    free(i);
    return (0);
}
*/