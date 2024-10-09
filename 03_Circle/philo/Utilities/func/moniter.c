/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:26 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/09 17:52:41 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	eat_check(t_data *data)
{
	long	i;
	long	cnt;

	i = 0;
	cnt = 0;
	while (i < data->info->philosophers)
	{
		if (data->info->must_eat == -1)
			return (0);
		if (dead_check(&data[i]))
			return (1);
		pthread_mutex_lock(&data[i].cnt);
		if (data[i].cnt_eat >= data->info->must_eat)
			cnt = cnt + 1;
		pthread_mutex_unlock(&data[i].cnt);
		if (cnt == data->info->philosophers)
		{
			pthread_mutex_lock(&data->death->mutex);
			data->death->check = 1;
			pthread_mutex_unlock(&data->death->mutex);
			return (1);
		}
		++i;
	}
	return (0);
}

void	moniter(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data[i].mutex);
		if (get_time(data[i].time_eat) >= data[i].info->time_to_die)
		{
			pthread_mutex_unlock(&data[i].mutex);
			pthread_mutex_lock(&data[i].death->mutex);
			data->death->check = 1;
			pthread_mutex_unlock(&data[i].death->mutex);
			philo_print(&data[i], 1);
			return ;
		}
		pthread_mutex_unlock(&data[i].mutex);
		if (i == (data[i].info->philosophers - 1))
			i = -1;
		++i;
		if (eat_check(data))
			return ;
	}
	return ;
}
