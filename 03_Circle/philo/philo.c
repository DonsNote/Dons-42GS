/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/01 09:39:58 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thd(void *time);

int	main(int ac, char **av)
{
	int		i;
	t_data	*data;
	t_info	*info;

	if (ac != 5 && ac != 6)
		return (check_error(-1));
	if (ft_atoi(av[1]) < 1)
		return (check_error(-1));
	info = info_init(ac, av);
	data = data_init(info);
	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_create(&(data[i].thread), NULL, start_thd, (void *)&(data[i]));
		usleep(50);
		++i;
	}
	pthread_join(data->thread, (void *)data);
	return (0);
}

void	*start_thd(void *data)
{
	// pthread_mutex_lock(&((t_data *)data)->mutex);
	printf("philo %d : %d\n", ((t_data *)data)->id, ((t_data *)data)->info->number_of_philosophers);
	// pthread_mutex_unlock(&((t_data *)data)->mutex);
	return (0);
}
