/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkform_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/01 11:14:14 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_checkcurrent_pf(char c)
{
	int	i;

	i = 0;
	while (TYPE[i] != '\0')
	{
		if (c == TYPE[i])
			return (1);
		++i;
	}
	return (1);
}

int	ft_checkform_pf(char *form)
{
	int		i;

	i = 0;
	while (form[i] != '\0')
	{
		if (form[i] == '%')
		{
			if (ft_checkcurrent_pf(form[++i]) == -1)
				return (-1);
		}
		++i;
	}
	return (1);
}
