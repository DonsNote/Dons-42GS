/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2024/08/03 09:33:44 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int	ft_check_enter(char *sol)
{
	int	i;

	i = 0;
	if (sol == 0)
		return (1);
	while (sol[i] != '\0')
	{
		if (sol[i] == '\n')
			return (0);
		++i;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sol;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	while (ft_check_enter(sol))
	{
		buf = ft_read_file(fd);
		if (buf == 0)
		{
			buf = sol;
			sol = NULL;
			return (buf);
		}
		sol = ft_strjoin_gnl(sol, buf);
	}
	buf = ft_return_line(sol);
	sol = ft_next_line(sol);
	if (*sol == '\0')
	{
		free(sol);
		sol = NULL;
	}
	return (buf);
}
