/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:07:11 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/05 22:05:02 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	take_fork(t_data *data)
{
	if (data->id % 2 == 0)
	{
		usleep(100);
		pthread_mutex_lock(&data->fork[data->id - 1]);
		philo_print(data, 5);
		pthread_mutex_lock(&data->fork[data->id
			% data->info->number_of_philosophers]);
		philo_print(data, 5);
	}
	else
	{
		pthread_mutex_lock(&data->fork[data->id
			% data->info->number_of_philosophers]);
		philo_print(data, 5);
		pthread_mutex_lock(&data->fork[data->id - 1]);
		philo_print(data, 5);
	}
	return ;
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
	take_fork(data);
	data->time_eat = get_time(0);
	philo_print(data, 2);
	while (get_time(data->time_eat) < data->info->time_to_eat)
	{
		if (dead_check(data, 1))
		{
			down_fork(data);
			return (1);
		}
	}
	down_fork(data);
	if (philo_sleep(data))
		return (1);
	return (0);
}
