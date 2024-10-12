/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/09 20:37:55 by dohyuki2         ###   ########.fr       */
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
	int				philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat;
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
	pthread_mutex_t	mutex;
	pthread_mutex_t	cnt;
	pthread_t		thread;
	t_info			*info;
	t_death			*death;
	int				id;
	long			cnt_eat;
	long			time_eat;
	long			time_sleep;
	long			time_think;
}	t_data;

int		check_error(int ac, char **av);
int		error_print(int i);
int		ft_atoi(const char *str);
t_data	*data_init(int c, char **av);
long	get_time(long start_time);
void	philo_print(t_data *data, int i);
int		philo_eat(t_data *data);
int		philo_sleep(t_data *data);
int		dead_check(t_data *data);
void	moniter(t_data *data);
int		cnt_check(t_data *data);
int		take_fork(t_data *data);
void	down_fork(t_data *data);

#endif