/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:43:42 by mring             #+#    #+#             */
/*   Updated: 2025/05/21 13:58:41 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// get current time in ms format including us XXXXXXXXXYYY
long	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

// // exit strategies for usleep wrapper (death, timeout etc)
// void	ph_usleep(long time, t_table *table)
// {
// 	long	start_time;
// 	long	elapsed;

// 	start_time = time_now();
// 	while (1)
// 	{
// 		if (sim_end(table)) // TODO: sim_end -> get table->end_sim bool (MUTEX)
// 			return ;
// 		usleep(1000);
// 		elapsed = time_now() - start_time;
// 		if (elapsed > time)
// 			return ;
// 	}
// }

void	cleanup(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
		pthread_mutex_destroy(&table->forks[i].fork);
	free(table->philos);
	free(table->forks);
}
