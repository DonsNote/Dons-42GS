
void    ft_putchar(char c);

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);
    int i;
    int j;
    char    c;

    i = 1;
    c = '\n';
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != 0)
        {
            ft_putchar(av[i][j]);
            j++;
        }
        ft_putchar(c);
        i++;
    }
    return (0);
}