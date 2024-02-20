/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:58:49 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/01/18 13:40:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	if (size == 0)
		return (count);
	while (src[i] != '\0')
	{
		if (size == 1)
		{
			dest[i] = '\0';
			break ;
		}
		dest[i] = src[i];
		i++;
		size--;
	}
	if (dest[i] != '\0')
		dest[i] = '\0';
	return (count);
}
