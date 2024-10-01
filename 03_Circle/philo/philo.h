/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/01 12:58:57 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	pthread_mutex_t	mutex;
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
	long			start_time;
}	t_info;

typedef struct s_death
{
	pthread_mutex_t	mutex;
	int				check;
}	t_death;

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_t		thread;
	t_info			*info;
	t_death			*death;
	int				id;
	long			cnt_eat;
	long			time_eat;
	long			time_death;
	long			time_sleep;
	long			time_think;
}	t_data;

int		check_error(int i);
int		ft_atoi(const char *str);
t_data	*data_init(int c, char **av);
long	get_time(int start_time);
int		print(t_data *data);
int		think(t_data *data);
int		sleep(t_data *data);
int		dead(t_data *data);
int		dead_check(t_data *data);

#endif