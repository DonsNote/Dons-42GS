/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:33:07 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/22 16:08:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	c;

	c = '1';
	while (c <= '9')
	{
		ft_putchar(c);
		c++;
	}
}
/*
int main(void)
{
    ft_print_numbers();
    return (0);
}
*/
