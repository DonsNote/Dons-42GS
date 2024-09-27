/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/09/27 17:18:50 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*info_init(int ac, char **av);
t_data	*data_init(t_info *info);
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

t_info	*info_init(int ac, char **av)
{
	t_info	*sol;

	sol = (t_info *)malloc(sizeof(t_info));
	if (sol == NULL)
		return (NULL);
	gettimeofday(&sol->start_time, NULL);
	sol->number_of_philosophers = ft_atoi(av[1]);
	sol->time_to_die = ft_atoi(av[2]);
	sol->time_to_eat = ft_atoi(av[3]);
	sol->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		sol->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		sol->number_of_times_each_philosopher_must_eat = 0;
	return (sol);
}

t_fork	*fork_init(int number_of_philosophers)
{
	int		i;
	t_fork	*fork;

	if (number_of_philosophers == 0)
		return (NULL);
	fork = (t_fork *)malloc(sizeof(t_fork) * number_of_philosophers);
	if (fork == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&(fork[i].mutex), NULL);
		fork[i].fork = 0;
		++i;
	}
	return (fork);
}

t_data	*data_init(t_info *info)
{
	int		i;
	t_data	*sol;
	t_fork	*fork;

	sol = (t_data *)malloc(sizeof(t_data) * info->number_of_philosophers);
	if (sol == NULL)
		return (NULL);
	fork = fork_init(info->number_of_philosophers);
	i = 0;
	while (i < info->number_of_philosophers)
	{
		sol[i].id = i;
		sol[i].info = info;
		sol[i].fork = fork;
		pthread_mutex_init(&(sol[i].mutex), NULL);
		++i;
	}
	return (sol);
}

void	*start_thd(void *data)
{
	// pthread_mutex_lock(&((t_data *)data)->mutex);
	printf("philo %d : %d\n", ((t_data *)data)->id, ((t_data *)data)->info->number_of_philosophers);
	// pthread_mutex_unlock(&((t_data *)data)->mutex);
	return (0);
}
