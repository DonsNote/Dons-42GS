/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:52:25 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/02/26 18:00:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char a = '\0';

	printf("%c\n", ft_toupper(a));
	printf("%c\n", toupper(a));
	return (0);
}
*/
