/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:55 by don               #+#    #+#             */
/*   Updated: 2024/04/24 02:49:58 by dohyuki2         ###   ########.fr       */
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
int		ft_check_enter(char *sol);
char	*ft_read_file(int *fd, ssize_t *size);
char	*ft_strjoin(char *sol, char *buf);
int		ft_strlen(char *s);
void	ft_strcpy_gnl(char *sol, char *src, int i);
char	*ft_next_line(char *sol, int *i);
char	*ft_make_next(char *sol, int i);
char	*ft_end_gnl(char *sol, int *flag);

#endif