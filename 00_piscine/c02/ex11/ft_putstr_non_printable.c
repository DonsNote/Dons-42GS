/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:42:45 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/18 18:59:05 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	int				temp;
	char			*hex;
	unsigned char	chn;

	i = 0;
	temp = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		chn = str[i];
		if (chn < 32 || chn >= 127)
		{
			write(1, "\\", 1);
			temp = hex[chn / 16];
			write(1, &temp, 1);
			temp = hex[chn % 16];
			write(1, &temp, 1);
		}
		else
			write(1, &chn, 1);
		i++;
	}
}
