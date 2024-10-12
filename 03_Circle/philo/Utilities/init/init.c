/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:37:19 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/12 18:36:13 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_info	*info_init(int ac, char **av);
int		null_check(t_info *info, t_mutex *mutex, t_data *data);
void	souce_init(t_data *data);

t_data	*data_init(int ac, char **av)
{
	int		i;
	t_data	*sol;
	t_info	*info;
	t_mutex	*mutex;

	info = info_init(ac, av);
	mutex = mutex_init(info->philos);
	sol = (t_data *)malloc(sizeof(t_data) * info->philos);
	if (null_check(info, mutex, sol))
		return (NULL);
	i = 0;
	while (i < info->philos)
	{
		sol[i].info = info;
		sol[i].mutex = mutex;
		sol[i].id = i + 1;
		souce_init(&(sol[i]));
		++i;
	}
	return (sol);
}

t_info	*info_init(int ac, char **av)
{
	t_info	*sol;

	sol = (t_info *)malloc(sizeof(t_info));
	if (sol == NULL)
		return (NULL);
	sol->philos = (long)ft_atoi(av[1]);
	sol->time_to_die = (long)ft_atoi(av[2]);
	sol->time_to_eat = (long)ft_atoi(av[3]);
	sol->time_to_sleep = (long)ft_atoi(av[4]);
	sol->start_time = get_time(0);
	if (ac == 6)
		sol->must_eat = ft_atoi(av[5]);
	else
		sol->must_eat = -1;
	return (sol);
}

int	null_check(t_info *info, t_mutex *mutex, t_data *data)
{
	if (info != NULL && mutex != NULL, data != NULL)
		return (0);
	if (info != NULL)
	{
		if (mutex != NULL)
			free(mutex);
		free(info);
	}
	else
	{
		if (mutex != NULL)
			free(mutex);
	}
	return (1);
}

void	souce_init(t_data *data)
{
	data->cnt_eat = -1;
	data->time_eat = get_time(0);
	data->time_sleep = get_time(0);
	data->time_think = get_time(0);
	return ;
}
