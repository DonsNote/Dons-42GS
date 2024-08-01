/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:47:04 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 00:38:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	param_check(char *param)
{
	int	i;

	i = ft_strlen(param);
	i = i - 1;
	if (param[i] != 'r')
		return (1);
	else if (param[i - 1] != 'e')
		return (1);
	else if (param[i - 2] != 'b')
		return (1);
	else if (param[i - 3] != '.')
		return (1);
	return (0);	
}