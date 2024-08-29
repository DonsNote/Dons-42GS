/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/27 16:34:31 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	*time_init(int ac, char **av);
void	*start_thd(void *time);

int	main(int ac, char **av)
{
	pthread_t	aristo;
	t_data		*data;

	if (ac != 5 && ac != 6)
		return (-1);
	if (ft_atoi(av[1]) < 2)
		return (-1);
	data = time_init(ac, av);
	if (data == NULL)
		return (-1);
	pthread_create(&aristo, NULL, start_thd, (void *)data);
	pthread_join(aristo, (void *)data);
	return (0);
}

t_time	*time_init(int ac, char **av)
{
	t_time	*sol;

	sol = (t_time *)malloc(sizeof(t_time) * 1);
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

void	*start_thd(void *data)
{
	printf("philo : %d\n", ((t_data *)data)->time->number_of_philosophers);
	return ((void *)data);
}
