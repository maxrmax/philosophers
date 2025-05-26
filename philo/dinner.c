/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/05/26 22:12:55 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



static void eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_philo_status("has taken a fork", philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_philo_status("has taken a fork", philo);
	set_long(&philo->philo_mtx, &philo->last_meal, time_now());
	philo->meals_counter++;
	write_philo_status("is eating", philo);
	ph_usleep(philo->table->eattime, philo->table);
	pthread_mutex_unlock(&philo->second_fork->fork);
	pthread_mutex_unlock(&philo->first_fork->fork);
	if (philo->table->meals > 0
		&& philo->meals_counter == philo->table->meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
}

static void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo);
	set_long(&philo->philo_mtx, &philo->last_meal, time_now());
	// increase_long(&philo->table->table_mtx, &philo->table->threads_running_nbr);
	de_sync_philo(philo);
	while (!get_bool(&philo->table->table_mtx, &philo->table->end_sim))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_philo_status("is sleeping", philo);
		ph_usleep(philo->table->sleeptime, philo->table);
		write_philo_status("is thinking", philo);
	}
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
	printf("time: %ld ---\n", table->sim_start);
	table->threads_ready = true;
	pthread_mutex_unlock(&table->table_mtx);
	// table->end_sim = false; // ???
	// monitor loop for the mainthread here
	monitor(table);
}
