/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:26 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/08 17:09:05 by dohyuki2         ###   ########.fr       */
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
		if (get_time(data[i].time_eat) > data[i].info->time_to_die)
		{
			pthread_mutex_unlock(&data[i].mutex);
			pthread_mutex_lock(&data[i].death->mutex);
			data->death->check = 1;
			pthread_mutex_unlock(&data[i].death->mutex);
			philo_print(&data[i], 1);
			return ;
		}
		pthread_mutex_unlock(&data[i].mutex);
		if (i == (data[i].info->number_of_philosophers - 1))
			i = -1;
		++i;
		usleep(10);
	}
	return ;
}
