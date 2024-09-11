/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/09/11 16:01:20 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	*time_init(int ac, char **av);
void	*start_thd(void *time);

int	main(int ac, char **av)
{
	int			i;
	pthread_t	aristo;
	t_data		*data;
	t_time		*time;

	if (ac != 5 && ac != 6)
		return (-1);
	if (ft_atoi(av[1]) < 2)
		return (-1);
	time = time_init(ac, av);
	i = 1;
	while (i <= ac)
	{
		data = data_init(time, i);
		if (time == NULL || data == NULL)
			return (-1);
		pthread_create(&aristo, NULL, start_thd, (void *)data);
	}
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

t_data	*data_init(t_time *time, int i)
{
	t_data	*sol;

	sol = (t_data *)malloc(sizeof(t_data) *1);
	if (sol == NULL)
		return (NULL);
	sol->fork = 0;
	sol->id = i;
	pthread_mutex_init(sol->fork, NULL);
	return (sol);	
}

void	*start_thd(void *data)
{
	printf("philo : %d\n", ((t_data *)data)->time->number_of_philosophers);
	return ((void *)data);

}
