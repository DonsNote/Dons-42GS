/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:48 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/06 17:54:34 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_print(t_data *data, int i)
{
	if (i == 1)
	{
		usleep(100);
		pthread_mutex_lock(&(data->info->mutex));
		printf("%ld %d died\n", get_time(data->info->start_time), data->id);
		pthread_mutex_unlock(&(data->info->mutex));
		return (1);
	}
	pthread_mutex_lock(&(data->info->mutex));
	if (i == 2)
		printf("%ld %d is eating\n", get_time(data->info->start_time), data->id);
	if (i == 3)
		printf("%ld %d is sleeping\n", get_time(data->info->start_time),
			data->id);
	if (i == 4)
		printf("%ld %d is thinking\n", get_time(data->info->start_time),
			data->id);
	if (i == 5)
		printf("%ld %d has taken a fork\n", get_time(data->info->start_time),
			data->id);
	pthread_mutex_unlock(&(data->info->mutex));
	return (0);
}
