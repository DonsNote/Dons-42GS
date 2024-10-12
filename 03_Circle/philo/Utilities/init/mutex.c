/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:08:15 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/12 20:44:12 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

pthread_mutex_t	*make_fork(int philos);
pthread_mutex_t	*make_eat(int philos);

t_mutex	*mutex_init(int philos)
{
	t_mutex	*sol;

	sol = (t_mutex *)malloc(sizeof(t_mutex));
	if (sol == NULL)
		return (NULL);
	sol->fork = make_fork(philos);
	if (sol->fork == NULL)
		return (NULL);
	sol->eat = make_eat(philos);
	if (sol->eat == NULL)
	{
		if (sol->fork != NULL)
			free(sol->fork);
		return (NULL);
	}
	pthread_mutex_init(&sol->dead, NULL);
	pthread_mutex_init(&sol->print, NULL);
	pthread_mutex_init(&sol->eat_d, NULL);
	sol->dflag = 0;
	sol->eat_done = 0;
	return (sol);
}

pthread_mutex_t	*make_fork(int philos)
{
	int				i;
	pthread_mutex_t	*sol;

	sol = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos);
	if (sol == NULL)
		return (NULL);
	i = 0;
	while (i < philos)
	{
		pthread_mutex_init(&sol[i], NULL);
		++i;
	}
	return (sol);
}

pthread_mutex_t	*make_eat(int philos)
{
	int				i;
	pthread_mutex_t	*sol;

	sol = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos);
	if (sol == NULL)
		return (NULL);
	i = 0;
	while (i < philos)
	{
		pthread_mutex_init(&sol[i], NULL);
		++i;
	}
	return (sol);
}
