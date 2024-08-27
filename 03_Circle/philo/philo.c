/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/27 12:54:59 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data_init(int ac, char **av);
void	*start_thd(void *time);

int	main(int ac, char **av)
{
	pthread_t	aristo;
	t_data		*data;

	if (ac != 5 && ac != 6)
		return (-1);
	data = data_init(ac, av);
	if (data == NULL)
		return (-1);
	pthread_create(&aristo, NULL, start_thd, (void *)time);
	pthread_join(aristo, (void *)time);
	return (0);
}

t_data	*data_init(int ac, char **av)
{
	t_data	*sol;

	sol = (t_data *)malloc(sizeof(t_data) * 1);
	if (sol == NULL)
		return (NULL);
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

void	*start_thd(void *time)
{
	t_data	*tmp;

	tmp = (t_data *)time;
	printf("philo : %d\n", tmp->number_of_philosophers);
	return ((void *)tmp);
}
