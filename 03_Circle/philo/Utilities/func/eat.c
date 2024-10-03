/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:07:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/03 22:03:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_eat(t_data *data)
{
	usleep(100);
	pthread_mutex_lock(&data->fork[data->id - 1]);
	philo_print(data, 5);
	pthread_mutex_lock(&data->fork[data->id % data->info->number_of_philosophers]);
	philo_print(data, 5);
	data->time_think = 0;
	data->time_eat = get_time(0);
	philo_print(data, 2);
	while (1)
	{
		if (get_time(data->time_eat) >= data->info->time_to_eat)
			break ;
		if (dead_check(data))
		{
			pthread_mutex_unlock(&data->fork[data->id % data->info->number_of_philosophers]);
			pthread_mutex_unlock(&data->fork[data->id - 1]);
			return (1);
		}
	}
	printf("end\n");
	data->time_eat = get_time(0);
	pthread_mutex_unlock(&data->fork[data->id % data->info->number_of_philosophers]);
	pthread_mutex_unlock(&data->fork[data->id - 1]);
	if (philo_sleep(data) == 1)
		return (1);
	return (0);
}