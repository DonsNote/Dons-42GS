/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/21 01:26:10 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	error_handle(t_error_type type)
{
	static char	*error_msg[] = {"Allocate error",
		"File open error", "File read error", "Argument error",
		"Invalid map data"};

	printf("Error\n");
	printf("%s\n", error_msg[type]);
	exit(type);
}
