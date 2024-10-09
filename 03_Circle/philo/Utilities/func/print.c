/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:48 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/09 17:31:02 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_print(t_data *data, int i)
{
	pthread_mutex_lock(&(data->info->mutex));
	if (i == 1)
	{
		printf("%ld %d died\n", get_time(data->info->start_time), data->id);
		pthread_mutex_unlock(&(data->info->mutex));
		return ;
	}
	if (i == 2)
		printf("%ld %d is eating\n", get_time(data->info->start_time), data->id);
	if (i == 3)
		printf("%ld %d is sleeping\n", get_time(data->info->start_time),
			data->id);
	if (i == 4)
		printf("%ld %d is thinking\n", get_time(data->info->start_time),
			data->id);
	if (i == 5)
	{
		printf("%ld %d has taken a fork\n", get_time(data->info->start_time),
			data->id);
		printf("%ld %d has taken a fork\n", get_time(data->info->start_time),
			data->id);
	}
	pthread_mutex_unlock(&(data->info->mutex));
	return ;
}
