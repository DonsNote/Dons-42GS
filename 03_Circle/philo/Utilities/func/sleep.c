/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:37:36 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/06 21:14:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_sleep(t_data *data)
{
	data->time_sleep = get_time(0);
	philo_print(data, 3);
	while (get_time(data->time_sleep) < data->info->time_to_sleep)
	{
		if (dead_check(data))
			return (1);
	}
	philo_print(data, 4);
	return (0);
}
