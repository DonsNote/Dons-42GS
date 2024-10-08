/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:37:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/08 23:31:07 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_info			*info_init(int ac, char **av);
pthread_mutex_t	*fork_init(int number_of_philosophers);
t_death			*dead_init(void);
void			souce_init(t_data *data);

t_data	*data_init(int ac, char **av)
{
	int				i;
	t_data			*sol;
	t_info			*info;
	t_death			*dead;
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
		sol[i].id = i + 1;
		pthread_mutex_init(&sol[i].mutex, NULL);
		pthread_mutex_init(&sol[i].cnt, NULL);
		souce_init(&(sol[i]));
		++i;
	}
	return (sol);
}

t_info	*info_init(int ac, char **av)
{
	t_info			*sol;

	sol = (t_info *)malloc(sizeof(t_info));
	if (sol == NULL)
		return (NULL);
	pthread_mutex_init(&(sol->mutex), NULL);
	sol->start_time = get_time(0);
	sol->number_of_philosophers = (long)ft_atoi(av[1]);
	sol->time_to_die = (long)ft_atoi(av[2]);
	sol->time_to_eat = (long)ft_atoi(av[3]);
	sol->time_to_sleep = (long)ft_atoi(av[4]);
	if (ac == 6)
		sol->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		sol->number_of_times_each_philosopher_must_eat = -1;
	return (sol);
}

pthread_mutex_t	*fork_init(int number_of_philosophers)
{
	int				i;
	pthread_mutex_t	*fork;

	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* number_of_philosophers);
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

t_death	*dead_init(void)
{
	t_death	*dead;

	dead = (t_death *)malloc(sizeof(t_death) * 1);
	if (dead == NULL)
		return (NULL);
	dead->check = 0;
	pthread_mutex_init(&(dead->mutex), NULL);
	return (dead);
}

void	souce_init(t_data *data)
{
	data->cnt_eat = 0;
	data->time_eat = get_time(0);
	data->time_sleep = get_time(0);
	data->time_think = get_time(0);
	return ;
}
