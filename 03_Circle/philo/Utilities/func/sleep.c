/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:37:36 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/03 20:24:05 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_sleep(t_data *data)
{
	long	now;

	if (dead_check(data))
		return (1);
	printf("check : sleep\n");
	philo_print(data, 3);
	data->time_sleep = get_time(0);
	while (1)
	{
		if (get_time(now) - data->time_sleep >= data->info->time_to_sleep)
			break ;
		if (dead_check(data))
			return (1);
	}
	data->time_sleep = 0;
	data->time_think = get_time(0);
	philo_print(data, 4);
	return (0);
}