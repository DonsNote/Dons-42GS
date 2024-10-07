/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:26 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/08 07:42:57 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	moniter(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data[i].mutex);
		if (time_check(&data[i]))
		{
			pthread_mutex_unlock(&data[i].mutex);
			usleep(100);
			philo_print(data, 1);
			break ;
		}
		pthread_mutex_unlock(&data[i].mutex);
		++i;
		if (i == (data[i].info->number_of_philosophers - 1))
			i = 0;
	}
	return ;
}
