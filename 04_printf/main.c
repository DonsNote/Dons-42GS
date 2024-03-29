/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:33:00 by don               #+#    #+#             */
/*   Updated: 2024/03/29 17:23:02 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    char *c;

    c = "adbv";
//    char *c;
    char *d;

//    c = "wow";
    d = "no";
    a = ft_printf("%p %p", c, d);
    printf("\n");
    b = printf("%p %p", c, d);
    printf("\n");
    printf("%d\n%d\n", a, b);
    return (0);
}