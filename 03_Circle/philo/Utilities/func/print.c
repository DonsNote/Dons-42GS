/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:48 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/01 09:37:55 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	print(t_data *data)
{
	long	now;
	pthread_mutex_lock(&(data->info->mutex));
	if (data->time_death > data->info->time_to_die)
	{
		printf("%ld %d died", get_time(now) - data->info->start_time, data->id);
	}
}