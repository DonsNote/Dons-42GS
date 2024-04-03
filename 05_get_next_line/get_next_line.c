/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:58:02 by don               #+#    #+#             */
/*   Updated: 2024/04/02 23:58:39 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	file;
	void	*buf; // 파일을 읽어 들일 버퍼
	size_t	BUFFER_SIZE; // 버퍼의 크기 컴파일 시 -D BUFFER_SIZE=n 로 define 함


	file = read(fd, buf, BUFFER_SIZE);
	if (file == -1)
		return (-1);

}
