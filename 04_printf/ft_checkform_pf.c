/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkform_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:01 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/31 17:14:54 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

// static int	ft_checkpercent_pf(char *form, int *i)
// {
// 	int	check;

// 	check = 1;
// 	while (form[(*i)] == '%' && form[(*i)] != '\0')
// 	{
// 		++check;
// 		++(*i);
// 	}
// 	if (check % 2 == 1)
// 		return (-1);
// 	return (1);
// }

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
