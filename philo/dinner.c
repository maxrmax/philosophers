/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/06/02 17:55:50 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_philo_status("has taken first fork", philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_philo_status("has taken second fork", philo);
	set_long(&philo->philo_mtx, &philo->last_meal, time_now());
	// TODO: double check if mutex is necessary
	philo->meals_counter++;
	write_philo_status("is eating", philo);
	ph_usleep(philo->table->eattime, philo->table);
	pthread_mutex_unlock(&philo->second_fork->fork);
	write_philo_status("has put down second fork", philo);
	pthread_mutex_unlock(&philo->first_fork->fork);
	write_philo_status("has put down first fork", philo);
}

static void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo);
	set_long(&philo->philo_mtx, &philo->last_meal, time_now());
	de_sync_philo(philo);
	while (!get_bool(&philo->table->table_mtx, &philo->table->end_sim))
	{
		if (get_bool(&philo->table->table_mtx, &philo->table->all_full))
			break ;
		eat(philo);
		write_philo_status("is sleeping", philo);
		ph_usleep(philo->table->sleeptime, philo->table);
		write_philo_status("is thinking", philo);
	}
	printf("philo end: %ld, id: %d\n", time_now() - philo->table->sim_start,
		philo->id);
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->table_mtx);
	while (++i < table->philo_nbr)
	{
		pthread_create(&table->philos[i].thread_id, NULL, dinner_sim,
			&table->philos[i]);
		pthread_detach(table->philos[i].thread_id);
	}
	table->sim_start = time_now();
	table->threads_ready = true;
	pthread_mutex_unlock(&table->table_mtx);
	monitor(table);
}
