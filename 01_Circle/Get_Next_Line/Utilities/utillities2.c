/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillities2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:52 by don               #+#    #+#             */
/*   Updated: 2025/01/23 14:06:49 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*ft_read_file(int fd)
{
	ssize_t	size;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[(int)size] = '\0';
	return (buf);
}

char	*ft_return_line(char *sol)
{
	int		i;
	char	*tmp;

	i = 0;
	if (sol[0] == '\0' || sol == NULL)
		return (NULL);
	while (sol[i] != '\n')
		++i;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (sol[i] != '\n')
	{
		tmp[i] = sol[i];
		++i;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	return (tmp);
}

char	*ft_next_line(char *sol)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (sol[i] != '\n')
		++i;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(sol) - i + 1));
	if (tmp == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
	while (sol[i] != '\0')
	{
		tmp[j] = sol[i];
		++j;
		++i;
	}
	free(sol);
	tmp[j] = '\0';
	return (tmp);
}
