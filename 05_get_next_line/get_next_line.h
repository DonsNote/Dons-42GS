/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:55 by don               #+#    #+#             */
/*   Updated: 2024/04/24 01:37:20 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_next_line(char *sol);
int		ft_check_enter(char *sol);
int		ft_strlen(char *s);
char	*ft_strjoin(char *sol, char *buf);
void	ft_strcpy_gnl(char *sol, char *src, int i);
char	*ft_end_gnl(char *sol, char *buf);

#endif