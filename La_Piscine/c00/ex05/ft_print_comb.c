/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:47:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/15 10:01:04 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comma(char a)
{
	if (a < '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	fst;
	char	snd;
	char	thd;

	fst = '0';
	snd = fst + 1;
	thd = snd + 1;
	while (fst <= '7')
	{
		write(1, &fst, 1);
		write(1, &snd, 1);
		write(1, &thd, 1);
		print_comma(fst);
		thd++;
		if (thd > '9')
		{
			snd++;
			if (snd > '8')
			{
				++fst;
				snd = fst + 1;
			}
			thd = snd + 1;
		}
	}
}
