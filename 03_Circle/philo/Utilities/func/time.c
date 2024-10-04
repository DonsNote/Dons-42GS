/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:35:47 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/10/04 16:27:38 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	get_time(long start_time)
{
	struct timeval	now;
	long			sol;

	gettimeofday(&now, NULL);
	sol = ((now.tv_sec * 1000) + (now.tv_usec / 1000)) - start_time;
	return (sol);
}
