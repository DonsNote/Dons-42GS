/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/04 23:18:23 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thd(void *time);
void	join(t_data *data);
void	destroid(t_data *data);

int	main(int ac, char **av)
{
	int		i;
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (check_error(-1));
	if (ft_atoi(av[1]) < 1)
		return (check_error(-1));
	data = data_init(ac, av);
	if (data == NULL)
		return (check_error(-1));
	i = 0;
	while (i < data->info->number_of_philosophers)
	{
		pthread_create(&(data[i].thread), NULL, start_thd, (void *)&(data[i]));
		usleep(100);
		++i;
	}
	join(data);
	// destroid(data);
	return (0);
}

void	destroid(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->death->mutex);
	free(data->death);
	while (i < data->info->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->fork[i]);
		++i;
	}
	free(data->fork);
	return ;
}

void	join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info->number_of_philosophers)
	{
		pthread_join((data[i].thread), NULL);
		++i;
	}
	free(data);
	return ;
}

void	*start_thd(void *data)
{
	while (1)
	{
		if (philo_eat((t_data *)data) == 1)
			break ;
		if (dead_check((t_data *)data, 3) == 1)
			break ;
	}
	return (0);
}
