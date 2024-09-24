/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/09/13 13:01:17 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_time
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_time;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				fork;
}	t_fork;

typedef struct s_data
{
	int		id;
	t_fork	*fork;
	t_time	*time;
}	t_data;


int	ft_atoi(const char *str);
int	check_error(int i);

#endif