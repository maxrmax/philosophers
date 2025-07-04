/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:43:42 by mring             #+#    #+#             */
/*   Updated: 2025/07/04 14:34:29 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// [ms][us] XXXXXXXXXYYY
// get current time in ms format including microseconds
long	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ph_usleep(long time, t_table *table)
{
	long	start_time;

	start_time = time_now();
	while (time_now() - start_time < time)
	{
		if (get_bool(&table->table_mtx, &table->end_sim))
			return ;
		usleep(100);
	}
}

void	cleanup(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		// pthread_mutex_destroy(&table->philos[i].philo_mtx); // on stack!
		pthread_mutex_destroy(&table->forks[i].fork);
	}
	// pthread_mutex_destroy(&table->table_mtx); // on stack!
	free(table->philos);
	free(table->forks);
}

void	write_philo_status(char *msg, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->table->table_mtx);
	time = time_now() - philo->table->sim_start;
	if (!philo->table->end_sim)
		printf("%-6ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->table->table_mtx);
}
