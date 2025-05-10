/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:56 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/27 02:45:23 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	line_error_handle(t_src *src, char **str, char **str1);
void	texture_error_handle(t_src *src);
void	valid_error_handle(t_src *src, t_lists *lists, t_stack *stack);

void	error_handle(t_error_type type)
{
	static char	*error_msg[] = {"Allocate error",
		"File open error", "File read error", "Argument error",
		"Invalid map data"};

	printf("%s\n", error_msg[type]);
	exit(0);
}

void	line_error_handle(t_src *src, char **str, char **str1)
{
	int	i;

	i = 0;
	free_textures_path(src);
	free(src);
	if (str != NULL)
		free_split(str);
	if (str1 != NULL)
		free_split(str1);
	error_handle(e_map);
}

void	texture_error_handle(t_src *src)
{
	free_all_resources(src);
	error_handle(e_map);
}

void	valid_error_handle(t_src *src, t_lists *lists, t_stack *stack)
{
	int	i;

	if (lists != NULL)
		free_list(&lists);
	if (stack != NULL)
		free_stack(&stack);
	i = -1;
	free_textures_path(src);
	free_map(src);
	free(src);
	error_handle(e_map);
}
