/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/08 16:12:43 by dohyuki2         ###   ########.fr       */
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
		++i;
	}
	moniter(data);
	join(data);
	destroid(data);
	return (0);
}

void	*start_thd(void *data)
{
	while (1)
	{
		if (philo_eat((t_data *)data))
			break ;
	}
	return (0);
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
	return ;
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
	free(data->info);
	free(data);
	return ;
}
