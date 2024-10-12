/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:26 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/12 20:44:40 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_eat_done(t_data *data);

void	moniter(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->info->philos)
		{
			pthread_mutex_lock(&data[i].mutex->eat[i]);
			if (get_time(data[i].time_eat) > data[i].info->time_to_die)
			{
				pthread_mutex_unlock(&data[i].mutex->eat[i]);
				pthread_mutex_lock(&data[i].mutex->dead);
				data->mutex->dflag = 1;
				pthread_mutex_unlock(&data[i].mutex->dead);
				usleep(300);
				philo_print(&data[i], 1);
				return ;
			}
			pthread_mutex_unlock(&data[i].mutex->eat[i]);
			if (check_eat_done(&data[i]))
				return ;
			++i;
		}
		usleep(10);
	}
}

int	check_eat_done(t_data *data)
{
	if (data->info->must_eat == -1)
		return (0);
	pthread_mutex_lock(&data->mutex->eat_d);
	if (data->mutex->eat_done == data->info->philos)
	{
		pthread_mutex_unlock(&data->mutex->eat_d);
		pthread_mutex_lock(&data->mutex->dead);
		data->mutex->dflag = 1;
		pthread_mutex_unlock(&data->mutex->dead);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex->eat_d);
	return (0);
}
