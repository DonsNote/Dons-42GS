/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:52 by don               #+#    #+#             */
/*   Updated: 2025/02/03 09:50:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*gnl_join_free(char *sol, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(sol, buf);
	free(sol);
	free(buf);
	return (tmp);
}

char	*gnl_read_file(int fd)
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

char	*gnl_return_line(char *sol)
{
	int		i;
	char	*tmp;

	i = 0;
	if (sol == NULL || sol[0] == '\0')
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

char	*gnl_next_line(char *sol)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (sol[i] != '\n')
		++i;
	i = i + 1;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(sol) - i));
	if (tmp == NULL)
		return (NULL);
	j = 0;
	while (sol[i] != '\0')
	{
		tmp[j] = sol[i];
		++j;
		++i;
	}
	tmp[j] = '\0';
	free(sol);
	return (tmp);
}

int	gnl_check_enter(char *sol)
{
	int	i;

	i = 0;
	if (sol == NULL)
		return (1);
	while (sol[i] != '\0')
	{
		if (sol[i] == '\n')
			return (0);
		++i;
	}
	return (1);
}
