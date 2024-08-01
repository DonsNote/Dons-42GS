/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:52 by don               #+#    #+#             */
/*   Updated: 2024/08/01 10:44:53 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd)
{
	ssize_t	size;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
	{
		free(buf);
		return (0);
	}
	buf[(int)size] = '\0';
	return (buf);
}

void	ft_strcpy(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	return ;
}

char	*ft_strjoin_gnl(char *sol, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	if (sol == 0)
		return (buf);
	i = ft_strlen(sol);
	j = ft_strlen(buf);
	tmp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (tmp == 0)
		return (0);
	ft_strcpy(tmp, sol, 0);
	ft_strcpy(tmp, buf, i);
	free(sol);
	free(buf);
	tmp[i + j] = '\0';
	return (tmp);
}

char	*ft_return_line(char *sol)
{
	int		i;
	int		j;
	char	*tmp;

	if (*sol == '\0')
		return (0);
	i = 0;
	while (sol[i] != '\n')
		++i;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (tmp == 0)
		return (0);
	j = 0;
	while (sol[j] != '\n')
	{
		tmp[j] = sol[j];
		++j;
	}
	tmp[j] = '\n';
	tmp[j + 1] = '\0';
	return (tmp);
}

char	*ft_next_line(char *sol)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(sol);
	j = 0;
	while (sol[j] != '\n')
		++j;
	tmp = (char *)malloc(sizeof(char) * (i - j + 1));
	if (tmp == 0)
		return (0);
	i = 0;
	j = j + 1;
	while (sol[j] != '\0')
	{
		tmp[i] = sol[j];
		++j;
		++i;
	}
	free(sol);
	tmp[i] = '\0';
	return (tmp);
}
