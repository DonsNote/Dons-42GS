/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:07:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/09 20:40:51 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	down_fork(t_data *data)
{
	if (data->id % 2 == 0)
	{
		pthread_mutex_unlock(&data->fork[data->id % data->info->philosophers]);
		pthread_mutex_unlock(&data->fork[data->id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&data->fork[data->id - 1]);
		pthread_mutex_unlock(&data->fork[data->id % data->info->philosophers]);
	}
	return ;
}

int	take_fork(t_data *data)
{
	if (data->id % 2 == 0)
	{
		pthread_mutex_lock(&data->fork[data->id - 1]);
		pthread_mutex_lock(&data->fork[data->id % data->info->philosophers]);
	}
	else
	{
		pthread_mutex_lock(&data->fork[data->id % data->info->philosophers]);
		pthread_mutex_lock(&data->fork[data->id - 1]);
	}
	if (dead_check(data))
	{
		down_fork(data);
		return (1);
	}
	philo_print(data, 5);
	return (0);
}


int	cnt_check(t_data *data)
{
	pthread_mutex_lock(&data->cnt);
	if (data->cnt_eat == data->info->must_eat)
	{
		pthread_mutex_unlock(&data->cnt);
		while (dead_check(data) == 0)
		{
			pthread_mutex_lock(&data->mutex);
			data->time_eat = get_time(0);
			pthread_mutex_unlock(&data->mutex);
		}
		return (1);
	}
	pthread_mutex_unlock(&data->cnt);
	return (0);
}

int	philo_eat(t_data *data)
{
	if (cnt_check(data))
		return (1);
	if (take_fork(data))
		return (1);
	pthread_mutex_lock(&data->mutex);
	data->time_eat = get_time(0);
	pthread_mutex_unlock(&data->mutex);
	philo_print(data, 2);
	while (get_time(data->time_eat) < data->info->time_to_eat)
	{
		if (dead_check(data))
		{
			down_fork(data);
			return (1);
		}
	}
	down_fork(data);
	pthread_mutex_lock(&data->cnt);
	data->cnt_eat += 1;
	pthread_mutex_unlock(&data->cnt);
	if (philo_sleep(data))
		return (1);
	return (0);
}
