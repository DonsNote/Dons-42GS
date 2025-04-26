/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:17:27 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/26 15:49:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_src	*init_src(void);
void	read_elems(t_src *src, int fd);
void	read_map(t_src *src, int fd);
void	check_side(t_src *src);

t_src	*check_init(char *av)
{
	t_src	*src;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_handle(e_open);
	src = init_src();
	read_elems(src, fd);
	read_map(src, fd);
	if (src->player.x == 0.f && src->player.y == 0.f)
		error_handle(e_map);
	close(fd);
	check_side(src);
	check_surround(src);
	return (src);
}

t_src	*init_src(void)
{
	t_src	*src;

	src = (t_src *)ft_calloc(1, sizeof(t_src));
	if (src == NULL)
		error_handle(e_allocate);
	return (src);
}

void	read_elems(t_src *src, int fd)
{
	char	*line;
	char	**str;
	int		num;
	int		i;

	i = 0;
	while (i < ELEMS)
	{
		line = get_next_line(fd);
		if (line == NULL)
			error_handle(e_map);
		str = ft_split(line, ' ');
		free(line);
		num = 0;
		while (str[num] != NULL)
			num++;
		if (num == 2)
		{
			inter_line(src, str);
			i++;
		}
		else if (num != 1 || str[0][0] != '\n')
			line_error_handle(src, str, NULL);
		free_split(str);
	}
}

void	read_map(t_src *src, int fd)
{
	t_lists	*lists;
	char	*line;
	int		width;

	lists = init_list();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line == '\n' && src->width == 0)
		{
			free(line);
			continue ;
		}
		width = ft_strlen(line) - 1;
		if (width > src->width)
			src->width = width;
		push_back(lists, (t_data){.str = line});
	}
	src->height = lists->size;
	if (src->height < 3 || src->width < 3)
		error_handle(e_map);
	set_map(src, lists);
	free_list(&lists);
}

void	check_side(t_src *src)
{
	int	pos_x;
	int	pos_y;

	pos_y = 0;
	while (pos_y < src->height)
	{
		pos_x = -1;
		while (++pos_x < src->width)
		{
			if (pos_y != 0 && pos_x != 0
				&& pos_y != src->height - 1 && pos_x != src->width - 1)
				continue ;
			if (src->map[pos_y][pos_x] != '1'
				&& src->map[pos_y][pos_x] != ' ')
				error_handle(e_map);
		}
		++pos_y;
	}
}
