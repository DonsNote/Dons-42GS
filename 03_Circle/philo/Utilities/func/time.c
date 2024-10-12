/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:35:47 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/10 01:36:09 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	get_time(long start_time)
{
	struct timeval	now;
	long			sol;

	gettimeofday(&now, NULL);
	sol = ((now.tv_sec * 1000.0) + (now.tv_usec / 1000.0)) - start_time;
	return (sol);
}
