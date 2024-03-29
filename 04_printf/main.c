/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:33:00 by don               #+#    #+#             */
/*   Updated: 2024/03/29 15:28:49 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    char *c;

    c = 0;
//    char *c;
//    char *d;

//    c = "wow";
//    d = "no";
    a = ft_printf("%s", c);
    printf("\n");
    b = printf("%s", c);
    printf("\n");
    printf("%d\n%d\n", a, b);
    return (0);
}