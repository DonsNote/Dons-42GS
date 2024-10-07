/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/07 19:37:47 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_dead(t_data *data)
{
	pthread_mutex_lock(&data->death->mutex);
	if (data->death->check == 1)
	{
		pthread_mutex_unlock(&data->death->mutex);
		return (1);
	}
	data->death->check = 1;
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}

int	time_check(t_data *data)
{
	if (get_time(data->time_eat) > data->info->time_to_die)
		if (philo_dead(data))
			return (1);
	return (0);
}

int	dead_check(t_data *data)
{
	pthread_mutex_lock(&data->death->mutex);
	if (data->death->check == 1)
	{
		pthread_mutex_unlock(&data->death->mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}
