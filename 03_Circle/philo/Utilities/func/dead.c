/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:50 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/01 15:27:22 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	dead(t_data *data)
{
	pthread_mutex_lock(&data->death->mutex);
	data->death->check = 1;
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}

int	dead_check(t_data *data)
{
	pthread_mutex_lock(&data->death->mutex);
	if (data->death->check == 1)
	{
		pthread_mutex_unlock(&data->death->mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death->mutex);
	return (0);
}