/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/01/29 09:24:23 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	error_print(int error)
{
	if (error == 1)
		write(1, "File Error\n", 11);
	if (error == 2)
		write(1, "File open Error\n", 16);
	if (error == 3)
		write(1, "Invalid Map\n", 12);
	return (1);
}
