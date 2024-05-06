/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:21 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/04/05 18:26:03 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd = open("./add", O_RDONLY);
    printf("buffer = %d\n", BUFFER_SIZE);
    printf("fd = %d\n", fd);

    char *line = get_next_line(fd);
    int i = 1;
    while (line)
    {
        printf("%d line : %s==\n",i,line);
        free (line);
        line = get_next_line(fd);
        i++;
    }
    printf("%d line : %s)\n",i,line);
    free (line);
    close(fd);
    return (0);
}