/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:48:30 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/22 15:52:06 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_swap(int i, char **av)
{
	char	*temp;

	temp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = temp;
}

void	ft_print_params(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	c = '\n';
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar(c);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		j = 1;
		while (j < ac - 1)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
				ft_swap(j, av);
			j++;
		}
		i++;
	}
	ft_print_params(ac, av);
	return (0);
}
