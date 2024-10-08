/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:07:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/08 21:00:11 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	take_fork_r(t_data *data)
{
	if (data->id % 2 == 0)
		pthread_mutex_lock(&data->fork[data->id - 1]);
	else
		pthread_mutex_lock(&data->fork[data->id
			% data->info->number_of_philosophers]);
	if (dead_check(data))
	{
		if (data->id % 2 == 0)
			pthread_mutex_unlock(&data->fork[data->id - 1]);
		else
			pthread_mutex_unlock(&data->fork[data->id
				% data->info->number_of_philosophers]);
		return (1);
	}
	philo_print(data, 5);
	return (0);
}

int	take_fork_l(t_data *data)
{
	if (data->id % 2 == 0)
		pthread_mutex_lock(&data->fork[data->id
			% data->info->number_of_philosophers]);
	else
		pthread_mutex_lock(&data->fork[data->id - 1]);
	if (dead_check(data))
	{
		if (data->id % 2 == 0)
		{
			pthread_mutex_unlock(&data->fork[data->id
				% data->info->number_of_philosophers]);
			pthread_mutex_unlock(&data->fork[data->id - 1]);
		}
		else
		{
			pthread_mutex_unlock(&data->fork[data->id
				% data->info->number_of_philosophers]);
			pthread_mutex_unlock(&data->fork[data->id - 1]);
		}
		return (1);
	}
	philo_print(data, 5);
	return (0);
}

void	down_fork(t_data *data)
{
	if (data->id % 2 == 0)
	{
		pthread_mutex_unlock(&data->fork[data->id
			% data->info->number_of_philosophers]);
		pthread_mutex_unlock(&data->fork[data->id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&data->fork[data->id - 1]);
		pthread_mutex_unlock(&data->fork[data->id
			% data->info->number_of_philosophers]);
	}
	return ;
}

int	philo_eat(t_data *data)
{
	if (data->cnt_eat == data->info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&data->mutex);
		data->time_eat = get_time(0);
		pthread_mutex_unlock(&data->mutex);
		return (0);
	}
	if (take_fork_r(data))
		return (1);
	if (take_fork_l(data))
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
	data->cnt_eat += 1;
	if (philo_sleep(data))
		return (1);
	return (0);
}
