/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:37:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/01 14:57:48 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_info	*info_init(int ac, char **av)
{
	t_info			*sol;

	sol = (t_info *)malloc(sizeof(t_info));
	if (sol == NULL)
		return (NULL);
	sol->start_time = get_time(0);
	sol->number_of_philosophers = ft_atoi(av[1]);
	sol->time_to_die = ft_atoi(av[2]);
	sol->time_to_eat = ft_atoi(av[3]);
	sol->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		sol->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		sol->number_of_times_each_philosopher_must_eat = -1;
	return (sol);
}

pthread_mutex_t	*fork_init(int number_of_philosophers)
{
	int		i;
	pthread_mutex_t	*fork;

	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	if (fork == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&fork[i], NULL);
		++i;
	}
	return (fork);
}

void	souce_init(t_data *data)
{
	data->cnt_eat = 0;
	data->time_eat = 0;
	data->time_death = 0;
	data->time_sleep = 0;
	data->time_think = 0;
	return ;
}

t_death	*dead_init(void)
{
	t_death	*dead;

	dead = (t_death *)malloc(sizeof(t_death) * 1);
	if (dead = NULL)
		return (NULL);
	dead->check = 0;
	pthread_mutex_init(&(dead->mutex), NULL);
	return (dead);
}

t_data	*data_init(int ac, char **av)
{
	int		i;
	t_data	*sol;
	t_info	*info;
	t_death	*dead;
	pthread_mutex_t	*fork;

	info = info_init(ac, av);
	sol = (t_data *)malloc(sizeof(t_data) * info->number_of_philosophers);
	if (sol == NULL)
		return (NULL);
	fork = fork_init(info->number_of_philosophers);
	dead = dead_init();
	i = 0;
	while (i < info->number_of_philosophers)
	{
		sol[i].info = info;
		sol[i].fork = fork;
		sol[i].death = dead;
		sol[i].id = i;
		souce_init(&(sol[i]));
		++i;
	}
	return (sol);
}