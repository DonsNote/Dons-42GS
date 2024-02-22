
int ft_count_if(char **tab, int (*f)(char*))
{
    int i;
    int sol;

    i = 0;
    sol = 0;
    while (tab[i] != '\0')
    {
        if (f(tab[i]) == 1)
            sol++;
        i++;
    }
    return (sol);
}