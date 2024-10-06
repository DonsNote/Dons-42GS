/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/06 08:07:51 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_dead(t_data *data)
{
	pthread_mutex_lock(&data->death->mutex);
	data->death->check = 1;
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}

int	dead_check(t_data *data)
{
	int	is_dead;

	is_dead = 0;
	pthread_mutex_lock(&data->death->mutex);
	if (data->death->check == 1)
		is_dead = 1;
	pthread_mutex_unlock(&data->death->mutex);
	if (is_dead == 1)
		return (1);
	if (get_time(data->time_eat) > data->info->time_to_die)
	{
		philo_dead(data);
		usleep(100);
		philo_print(data, 1);
		return (1);
	}
	return (0);
}
