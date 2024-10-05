/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:37:36 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/05 21:20:17 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo_sleep(t_data *data)
{
	philo_print(data, 3);
	while (get_time(data->time_last_eat) < data->info->time_to_sleep)
	{
		if (dead_check(data, 2))
			return (1);
	}
	philo_print(data, 4);
	return (0);
}
