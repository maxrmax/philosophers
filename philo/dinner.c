/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/05/20 17:46:50 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	wait_all_threads(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->table_mtx);
		if (philo->table->threads_ready)
		{
			pthread_mutex_unlock(&philo->table->table_mtx);
			break ;
		}
		pthread_mutex_unlock(&philo->table->table_mtx);
		usleep(1000);
	}
}

// do i need the full table data + every philo data here?
void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo); // TODO
	printf("waiting done\n");
	// have to mutex table time for access later
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->table_mtx);
	while (++i < table->philo_nbr) // create thread for each philo
	{
		// need a condition to make them all wait after creating.
		// do i need to pass the whole table (everything) or just a single philo?
		pthread_create(&table->philos[i].thread_id, NULL, dinner_sim,
			&table->philos[i]);
		// detach after automatic cleanup after they close/end (unless they run infinite)
		pthread_detach(table->philos[i].thread_id);
	}
	table->sim_start = time_now(); // have to mutex table time for access later
	table->threads_ready = true;
	printf("time: %ld ---\n", table->sim_start);
	pthread_mutex_unlock(&table->table_mtx);
	// table->end_sim = true; // ???
	// table->threads_ready = true; // now they should all start in sync
	// now all threads are made
	// set bool true for all ready
	sleep(2);
}
