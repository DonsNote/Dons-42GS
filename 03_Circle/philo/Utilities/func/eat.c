/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:07:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/03 16:08:12 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	eat(t_data *data)
{
	long	now;
	pthread_mutex_lock(&data->fork[data->id]);
	print(data, 5);
	pthread_mutex_lock(&data->fork[data->id % data->info->number_of_philosophers]);
	print(data, 5);
	data->time_think = 0;
	data->time_eat = get_time(0);
	print(data, 2);
	while (1)
	{
		if (get_time(now) - data->time_eat >= data->info->time_to_eat)
			break ;
		if (dead_check(data))
		{
			pthread_mutex_unlock(&data->fork[data->id]);
			pthread_mutex_unlock(&data->fork[data->id % data->info->number_of_philosophers]);
			return (1);
		}
	}
	data->time_eat = 0;
	pthread_mutex_unlock(&data->fork[data->id]);
	pthread_mutex_unlock(&data->fork[data->id % data->info->number_of_philosophers]);
	if (sleep(data) == 1)
		return (1);
	return (0);
}