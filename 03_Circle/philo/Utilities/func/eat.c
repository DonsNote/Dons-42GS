/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:07:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/12 20:55:53 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int		take_fork(t_data *data);
void	down_fork(t_data *data);
void	eat_done(t_data *data);

int	philo_eat(t_data *data)
{
	if (take_fork(data))
		return (1);
	pthread_mutex_lock(&data->mutex->eat[data->id - 1]);
	data->time_eat = get_time(0);
	pthread_mutex_unlock(&data->mutex->eat[data->id - 1]);
	if (data->cnt_eat < data->info->must_eat || data->info->must_eat == -1)
		philo_print(data, 2);
	while (get_time(data->time_eat) < data->info->time_to_eat)
	{
		if (dead_check(data))
		{
			down_fork(data);
			return (1);
		}
		usleep(100);
	}
	down_fork(data);
	data->cnt_eat += 1;
	if (data->cnt_eat == data->info->must_eat)
		eat_done(data);
	return (0);
}

int	take_fork(t_data *data)
{
	if (data->id % 2 == 1)
	{
		usleep(100);
		pthread_mutex_lock(&data->mutex->fork[data->id - 1]);
		pthread_mutex_lock(&data->mutex->fork[data->id % data->info->philos]);
	}
	else
	{
		usleep(200);
		pthread_mutex_lock(&data->mutex->fork[data->id % data->info->philos]);
		pthread_mutex_lock(&data->mutex->fork[data->id - 1]);
	}
	if (dead_check(data))
	{
		down_fork(data);
		return (1);
	}
	philo_print(data, 5);
	return (0);
}

void	down_fork(t_data *data)
{
	if (data->id % 2 == 0)
	{
		pthread_mutex_unlock(&data->mutex->fork[data->id % data->info->philos]);
		pthread_mutex_unlock(&data->mutex->fork[data->id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&data->mutex->fork[data->id - 1]);
		pthread_mutex_unlock(&data->mutex->fork[data->id % data->info->philos]);
	}
	return ;
}

void	eat_done(t_data *data)
{
	pthread_mutex_lock(&data->mutex->eat_d);
	data->mutex->eat_done += 1;
	pthread_mutex_unlock(&data->mutex->eat_d);
	return ;
}
