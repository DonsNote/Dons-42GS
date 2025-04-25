/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:34:21 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/25 15:41:08 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int		get_color(t_src *src, char *color_data);
int		count_commas(char *str);
_Bool	is_color(char *arg);
void	free_split(char **str);

void	inter_line(t_src *src, char **str)
{
	int				i;
	static char		*type[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	static _Bool	set[] = {0, 0, 0, 0, 0, 0};
	const void		*elem[] = {&(src->textures[NORTH].path),
		&(src->textures[SOUTH].path), &(src->textures[WEST].path),
		&(src->textures[EAST].path), &(src->f_color), &(src->c_color)};

	i = -1;
	while (type[++i] != NULL)
	{
		if (ft_strncmp(str[0], type[i], -1) != 0)
			continue ;
		if (set[i])
			line_error_handle(src);
		if (i < WALL_SIZE)
			*(char **)elem[i] = ft_strdup(str[1]);
		else
			*(int *)elem[i] = get_color(src, str[1]);
		set[i] = 1;
		return ;
	}
	line_error_handle(src);
}

void	free_split(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp != NULL)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
}

_Bool	is_color(char *arg)
{
	int	base;
	int	sign;

	sign = 1;
	if (*arg == '-' || *arg == '+')
		sign = 1 - 2 * (*arg++ == '-');
	if (sign == -1 || *arg == '\0')
		return (0);
	base = 0;
	while (*arg != '\0' && *arg != '\n')
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		if (base > UCHAR_MAX / 10 || (base == UCHAR_MAX / 10 && *arg > '5'))
			return (0);
		base = base * 10 + (*arg - '0');
		arg++;
	}
	return (1);
}

int	get_color(t_src *src, char *color_data)
{
	char	**color_strs;
	int		num;
	int		color;

	if (count_commas(color_data) != 2)
		line_error_handle(src);
	color_strs = ft_split(color_data, ',');
	num = 0;
	while (color_strs[num] != NULL)
		num++;
	if (num != 3)
		line_error_handle(src);
	if (!is_color(color_strs[0]) || !is_color(color_strs[1])
		|| !is_color(color_strs[2]))
		line_error_handle(src);
	color = 0;
	color |= ft_atoi(color_strs[0]) << 16;
	color |= ft_atoi(color_strs[1]) << 8;
	color |= ft_atoi(color_strs[2]);
	free_split(color_strs);
	return (color);
}

int	count_commas(char *str)
{
	int		num_of_commas;
	char	*cur;

	num_of_commas = 0;
	cur = str;
	while (*cur != '\0')
		if (*(cur++) == ',')
			num_of_commas++;
	return (num_of_commas);
}
