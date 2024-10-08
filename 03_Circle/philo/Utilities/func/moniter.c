/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:26 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/09 00:21:06 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	eat_check(t_data *data)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < data->info->number_of_philosophers)
	{
		if (dead_check(&data[i]))
			return ;
		pthread_mutex_lock(&data[i].cnt);
		if (data->cnt_eat == data->info->number_of_times_each_philosopher_must_eat)
			cnt = cnt + 1;
		if (cnt == data->info->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&data->death->mutex);
			data->death->check = 1;
			pthread_mutex_unlock(&data->death->mutex);
			pthread_mutex_unlock(&data[i].cnt);
			return ;
		}
		++i;
	}
	pthread_mutex_unlock(&data[i].cnt);
	return ;
}

void	moniter(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		eat_check(data);
		pthread_mutex_lock(&data[i].mutex);
		if (get_time(data[i].time_eat) > data[i].info->time_to_die)
		{
			pthread_mutex_unlock(&data[i].mutex);
			pthread_mutex_lock(&data[i].death->mutex);
			data->death->check = 1;
			pthread_mutex_unlock(&data[i].death->mutex);
			philo_print(&data[i], 1);
			return ;
		}
		pthread_mutex_unlock(&data[i].mutex);
		if (i == (data[i].info->number_of_philosophers - 1))
			i = -1;
		++i;
		usleep(10);
	}
	return ;
}
