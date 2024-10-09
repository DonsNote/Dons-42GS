/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:26:46 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/10 02:29:39 by dohyuki2         ###   ########.fr       */
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
	int				philos;
	int				must_eat;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
}	t_info;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	int				dflag;
	int				eflag;
}	t_mutex;

typedef struct s_data
{
	pthread_t		thread;
	t_info			*info;
	t_mutex			*mutex;
	int				id;
	int				cnt_eat;
	long			time_eat;
	long			time_sleep;
	long			time_think;
}	t_data;

t_data	*data_init(int ac, char **av);
t_mutex	*mutex_init(int philos);
int		check_error(int ac, char **av);
int		error_print(int i);
int		ft_atoi(const char *str);
long	get_time(long start_time);
void	philo_print(t_data *data, int i);
int		philo_eat(t_data *data);
int		philo_sleep(t_data *data);
int		dead_check(t_data *data);
void	moniter(t_data *data);

#endif