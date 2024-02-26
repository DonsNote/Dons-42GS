/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:38:30 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 12:50:25 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 95) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isalpha(97));
    printf("%d\n", isalpha(97));
    return (0);
}
*/
