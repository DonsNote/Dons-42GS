/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/21 16:46:33 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thd(void *time)
{
	t_time	*tmp;

	tmp = (t_time *)time;
	printf("philo : %d\n", tmp->number_of_philosophers);
	return ((void *)tmp);
}

t_time	*time_init(char **av)
{
	t_time	*sol;

	sol = (t_time *)malloc(sizeof(t_time) * 1);
	sol->number_of_philosophers = ft_atoi(av[1]);
	sol->time_to_die = ft_atoi(av[2]);
	sol->time_to_eat = ft_atoi(av[3]);
	sol->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		sol->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		sol->number_of_times_each_philosopher_must_eat = 0;
	return (sol);
}

int	main(int ac, char **av)
{
	pthread_t	aristo;
	t_time		*time;

	if (ac != 5 && ac != 6)
		return (-1);
	time = time_init(av);
	pthread_create(&aristo, NULL, start_thd, (void *)time);
	pthread_join(aristo, (t_time **)&time);
	return (0);
}
