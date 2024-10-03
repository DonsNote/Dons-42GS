/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/03 15:13:50 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	dead(t_data *data)
{
	pthread_mutex_lock(&data->death->mutex);
	data->death->check = 1;
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}

int	dead_check(t_data *data)
{
	long	now;
	pthread_mutex_lock(&data->death->mutex);
	if (data->death->check == 1)
	{
		pthread_mutex_unlock(&data->death->mutex);
		return (1);
	}
	if ((get_time(now) - data->time_eat) > data->info->time_to_die || 
		(get_time(now) - data->time_sleep) > data->info->time_to_die ||
		(get_time(now) - data->time_think) > data->info->time_to_die)
	{
		pthread_mutex_unlock(&data->death->mutex);
		dead(data);
		usleep(100);
		print(data, 1);
		return (1);
	}
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}