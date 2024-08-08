/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:45:18 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/01 11:14:39 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_pf(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[count] != '\0')
	{
		if (ft_putchar_pf(str[count]) == -1)
			return (-1);
		++count;
	}
	return (count);
}
