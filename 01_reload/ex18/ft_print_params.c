/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:45:41 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/22 15:48:13 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	c = '\n';
	if (ac < 2)
		return (0);
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
