/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:42:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/15 22:36:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;
	int	index;
	int	temp;

	count = 0;
	index = 0;
	temp = 0;
	while (count < size - 1)
	{
		while (index < size - 1)
		{
			if (tab[index] > tab[index + 1])
			{
				temp = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = temp;
			}
			index++;
		}
		index = 0;
		count++;
	}
}
